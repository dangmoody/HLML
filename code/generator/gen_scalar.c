/*
===========================================================================

HLML

Copyright (c) Dan Moody 2018 - Present.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

===========================================================================
*/

#include "gen_shared.h"

#include "linear_allocator.h"
#include "string_builder.h"
#include "string_helpers.h"
#include "common_names.h"
#include "defines.h"
#include "file_io.h"

#include <stdio.h>
#include <assert.h>

static const char *Gen_GetConstantName( allocatorLinear_t *tempStorage, const genType_t type, const generatorStrings_t *strings, const char *constantName ) {
	assert( tempStorage );
	assert( type != GEN_TYPE_COUNT );
	assert( strings );
	assert( strings->constantsPrefix );
	assert( constantName );

	if ( type == GEN_TYPE_FLOAT ) {
		return String_TPrintf( tempStorage, "(float)( %s%s )", strings->constantsPrefix, constantName );
	} else {
		return String_TPrintf( tempStorage, "( %s%s )", strings->constantsPrefix, constantName );
	}
}

// TODO(DM): rewrite to use Christer Ericson's method
static void GenerateFunction_Floateq( allocatorLinear_t *tempStorage, const genType_t type, stringBuilder_t *code, const char *memberTypeString, const generatorStrings_t *strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( strings );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char *floateqStr = Gen_GetFuncName_Floateq( type );
	const char *floateqepsStr = Gen_GetFuncName_Floateq_eps( type );

	const char *parmEpsilonStr = Gen_GetConstantName( tempStorage, type, strings, GEN_CONSTANT_NAME_EPSILON );

	// floateq_eps
	StringBuilder_Append(  code, "// Returns true if the two given floating-point numbers are close enough to each other within a user-specified margin of error to be considered equal.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE bool %s( const %s lhs, const %s rhs, const %s epsilon )\n", floateqepsStr, memberTypeString, memberTypeString, memberTypeString );
	Gen_AppendOpenBrace( code, flags, "" );
	StringBuilder_Appendf( code, "\treturn %s( lhs - rhs ) < epsilon;\n", Gen_GetBuiltinFunction( tempStorage, type, GEN_BUILTIN_FUNCTION_NAME_FABS ) );
	StringBuilder_Append(  code, "}\n\n" );

	// floateq
	StringBuilder_Appendf( code, "// Returns true if the two given floating-point numbers are close enough to each other within margin of error `%s` to be considered equal.\n", parmEpsilonStr );
	StringBuilder_Appendf( code, "HLML_INLINE bool %s( const %s lhs, const %s rhs )\n", floateqStr, memberTypeString, memberTypeString );
	Gen_AppendOpenBrace( code, flags, "" );
	StringBuilder_Appendf( code, "\treturn %s( lhs, rhs, %s );\n", floateqepsStr, parmEpsilonStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Sign_Scalar( allocatorLinear_t *tempStorage, const genType_t type, stringBuilder_t *code, const char *memberTypeString, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( memberTypeString );

	if ( type == GEN_TYPE_BOOL || type == GEN_TYPE_UINT ) {
		return;
	}

	const char *intTypeString = Gen_GetMemberTypeString( GEN_TYPE_INT );

	const char *signFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_SIGN );

	const char *zeroStr = Gen_GetNumericLiteral( tempStorage, type, 0, 1 );

	StringBuilder_Append(  code, "// Returns -1 if 'x' is < 0, 0 if 'x' == 0, or 1 if 'x' > 1.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s x )\n", intTypeString, signFuncStr, memberTypeString );
	Gen_AppendOpenBrace( code, flags, "" );
	StringBuilder_Appendf( code, "\treturn ( %s < x ) - ( x < %s );\n", zeroStr, zeroStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Radians( allocatorLinear_t *tempStorage, const genType_t type, stringBuilder_t *code, const char *memberTypeString, const generatorStrings_t *strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( strings );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char *radiansFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_RADIANS );

	const char *oneHundredEightyStr = Gen_GetNumericLiteral( tempStorage, type, 180, 1 );

	const char *piStr = Gen_GetConstantName( tempStorage, type, strings, GEN_CONSTANT_NAME_PI );

	StringBuilder_Append(  code, "// Returns the given degrees to radians.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s deg )\n", memberTypeString, radiansFuncStr, memberTypeString );
	Gen_AppendOpenBrace( code, flags, "" );
	StringBuilder_Appendf( code, "\treturn deg * %s / %s;\n", piStr, oneHundredEightyStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Degrees( allocatorLinear_t *tempStorage, const genType_t type, stringBuilder_t *code, const char *memberTypeString, const generatorStrings_t *strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( strings );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char *degreesFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_DEGREES );

	const char *oneHundredEightyStr = Gen_GetNumericLiteral( tempStorage, type, 180, 1 );

	const char *piStr = Gen_GetConstantName( tempStorage, type, strings, GEN_CONSTANT_NAME_PI );

	StringBuilder_Append(  code, "// Returns the given radians to degrees.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s rad )\n", memberTypeString, degreesFuncStr, memberTypeString );
	Gen_AppendOpenBrace( code, flags, "" );
	StringBuilder_Appendf( code, "\treturn rad * %s / %s;\n", oneHundredEightyStr, piStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_MinMax_Scalar( allocatorLinear_t *tempStorage, const genType_t type, stringBuilder_t *code, const char *memberTypeString, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	const char *minFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_MIN );
	const char *maxFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_MAX );

	// min
	StringBuilder_Append(  code, "// Returns 'x' if it's smaller than 'y', otherwise returns 'y'.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s x, const %s y )\n", memberTypeString, minFuncStr, memberTypeString, memberTypeString );
	Gen_AppendOpenBrace( code, flags, "" );
	StringBuilder_Append(  code, "\treturn ( x < y ) ? x : y;\n" );
	StringBuilder_Append(  code, "}\n\n" );

	// max
	StringBuilder_Append(  code, "// Returns x if it's larger than 'y', otherwise returns 'y'.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s x, const %s y )\n", memberTypeString, maxFuncStr, memberTypeString, memberTypeString );
	Gen_AppendOpenBrace( code, flags, "" );
	StringBuilder_Append(  code, "\treturn ( x > y ) ? x : y;\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Clamp( allocatorLinear_t *tempStorage, const genType_t type, stringBuilder_t *code, const char *memberTypeString, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	const char *clampFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_CLAMP );
	const char *minFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_MIN );
	const char *maxFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_MAX );

	StringBuilder_Append(  code, "// If 'x' is lower than 'low' or higher than 'high' then returns 'low' or 'high' respectively, otherwise returns 'x'.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s x, const %s low, const %s high )\n", memberTypeString, clampFuncStr, memberTypeString, memberTypeString, memberTypeString );
	Gen_AppendOpenBrace( code, flags, "" );
	StringBuilder_Appendf( code, "\treturn %s( %s( x, low ), high );\n", minFuncStr, maxFuncStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Saturate( allocatorLinear_t *tempStorage, const genType_t type, stringBuilder_t *code, const char *memberTypeString, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	const char *saturateFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_SATURATE );
	const char *clampFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_CLAMP );

	const char *zeroStr = Gen_GetNumericLiteral( tempStorage, type, 0.0f, 1 );
	const char *oneStr = Gen_GetNumericLiteral( tempStorage, type, 1.0f, 1 );

	StringBuilder_Append(  code, "// Returns a copy of 'x' that has been clamped between the range 0 and 1.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s x )\n", memberTypeString, saturateFuncStr, memberTypeString );
	Gen_AppendOpenBrace( code, flags, "" );
	StringBuilder_Appendf( code, "\treturn %s( x, %s, %s );\n", clampFuncStr, zeroStr, oneStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Lerp( allocatorLinear_t *tempStorage, const genType_t type, stringBuilder_t *code, const char *memberTypeString, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char *lerpFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_LERP );

	const char *oneStr = Gen_GetNumericLiteral( tempStorage, type, 1.0f, 1 );

	StringBuilder_Append(  code, "// Returns a linearly interpolated float between 'a' and 'b', where 't' is the percentage (between 0 and 1) to interpolate by.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s a, const %s b, const %s t )\n", memberTypeString, lerpFuncStr, memberTypeString, memberTypeString, memberTypeString );
	Gen_AppendOpenBrace( code, flags, "" );
	StringBuilder_Appendf( code, "\treturn ( %s - t ) * a + t * b;\n", oneStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Step( allocatorLinear_t *tempStorage, const genType_t type, stringBuilder_t *code, const char *memberTypeString, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	const char *stepFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_STEP );

	const char *zeroStr = Gen_GetNumericLiteral( tempStorage, type, 0.0f, 1 );
	const char *oneStr = Gen_GetNumericLiteral( tempStorage, type, 1.0f, 1 );

	StringBuilder_Append(  code, "// Returns 1 if 'y' is greater than 'x', otherwise returns 0.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s x, const %s y )\n", memberTypeString, stepFuncStr, memberTypeString, memberTypeString );
	Gen_AppendOpenBrace( code, flags, "" );
	StringBuilder_Appendf( code, "\treturn ( y > x ? %s : %s );\n", oneStr, zeroStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Smoothstep( allocatorLinear_t *tempStorage, const genType_t type, stringBuilder_t *code, const char *memberTypeString, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char *smoothstepFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_SMOOTHSTEP );
	const char *saturateFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_SATURATE );

	const char *threeStr = Gen_GetNumericLiteral( tempStorage, type, 3.0f, 1 );
	const char *twoStr = Gen_GetNumericLiteral( tempStorage, type, 2.0f, 1 );

	StringBuilder_Append(  code, "// Performs a sigmoid-like interpolation and clamp.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s low, const %s high, const %s x )\n", memberTypeString, smoothstepFuncStr, memberTypeString, memberTypeString, memberTypeString );
	Gen_AppendOpenBrace( code, flags, "" );
	StringBuilder_Appendf( code, "\t%s t = %s( ( x - low ) / ( high - low ) );\n", memberTypeString, saturateFuncStr );
	StringBuilder_Appendf( code, "\treturn t * t * ( %s - %s * t );\n", threeStr, twoStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Smootherstep( allocatorLinear_t *tempStorage, const genType_t type, stringBuilder_t *code, const char *memberTypeString, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char *smootherstepFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_SMOOTHERSTEP );
	const char *saturateFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_SATURATE );

	const char *sixStr = Gen_GetNumericLiteral( tempStorage, type, 6.0f, 1 );
	const char *fifteenStr = Gen_GetNumericLiteral( tempStorage, type, 15.0f, 1 );
	const char *tenStr = Gen_GetNumericLiteral( tempStorage, type, 10.0f, 1 );

	StringBuilder_Append(  code,
		"// Performs a 'smoother' version of smoothstep, as design by Ken Perlin.\n"
		"// https://en.wikipedia.org/wiki/Smoothstep#Variations\n"
	);
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s low, const %s high, const %s x )\n", memberTypeString, smootherstepFuncStr, memberTypeString, memberTypeString, memberTypeString );
	Gen_AppendOpenBrace( code, flags, "" );
	StringBuilder_Appendf( code, "\t%s t = %s( ( x - low ) / ( high - low ) );\n", memberTypeString, saturateFuncStr );
	StringBuilder_Appendf( code, "\treturn t * t * t * ( t * ( t * %s - %s ) + %s );\n", sixStr, fifteenStr, tenStr );
	StringBuilder_Append(  code, "}\n\n" );
}

void GenerateScalarFiles( allocatorLinear_t *tempStorage, const char *generatedCodePath, const generatorStrings_t *strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( generatedCodePath );
	assert( strings );

	bool32 cLinkage = flags & GENERATOR_FLAG_C_LINKAGE;
	bool32 allowNamespace = flags & GENERATOR_FLAG_ALLOW_NAMESPACE;

	stringBuilder_t *code = StringBuilder_Create( tempStorage, KILOBYTES( 12 ) );

	Gen_AppendGeneratedHeaderComment( code, flags );

	StringBuilder_Append( code,
		"#pragma once\n"
		"\n"
	);

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef __cplusplus\n"
			"extern \"C\" {\n"
			"#endif\n"
			"\n"
		);
	}

	StringBuilder_Appendf( code, "#include \"%s\"\n", Gen_GetPrefixedFilename( tempStorage, strings, GEN_FILENAME_SUFFIX_CONSTANTS ) );
	StringBuilder_Appendf( code, "#include \"%s\"\n", Gen_GetPrefixedFilename( tempStorage, strings, GEN_FILENAME_SUFFIX_DEFINES ) );
	StringBuilder_Append( code,
		"\n"
		"#include <math.h>\n"
		"#include <stdint.h>\n"
		"\n"
	);

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifndef __cplusplus\n"
			"#include <stdbool.h>\n"
			"#endif\n"
			"\n"
		);
	}

	if ( allowNamespace ) {
		StringBuilder_Append( code, "#ifdef HLML_NAMESPACE\n" "namespace hlml\n" );
		Gen_AppendOpenBrace( code, flags, "" );
		StringBuilder_Append( code,
			"#endif\n"
			"\n"
		);
	}

	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		const char *memberTypeString = Gen_GetMemberTypeString( type );

		printf( "Scalar functions %s...", memberTypeString );

		StringBuilder_Appendf( code, "// %s\n", memberTypeString );

		GenerateFunction_Floateq( tempStorage, type, code, memberTypeString, strings, flags );
		GenerateFunction_Radians( tempStorage, type, code, memberTypeString, strings, flags );
		GenerateFunction_Degrees( tempStorage, type, code, memberTypeString, strings, flags );
		GenerateFunction_Sign_Scalar( tempStorage, type, code, memberTypeString, flags );
		GenerateFunction_MinMax_Scalar( tempStorage, type, code, memberTypeString, flags );
		GenerateFunction_Clamp( tempStorage, type, code, memberTypeString, flags );
		GenerateFunction_Saturate( tempStorage, type, code, memberTypeString, flags );
		GenerateFunction_Lerp( tempStorage, type, code, memberTypeString, flags );
		GenerateFunction_Step( tempStorage, type, code, memberTypeString, flags );
		GenerateFunction_Smoothstep( tempStorage, type, code, memberTypeString, flags );
		GenerateFunction_Smootherstep( tempStorage, type, code, memberTypeString, flags );

		printf( "OK.\n" );
	}

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n"
		);
	}

	if ( allowNamespace ) {
		StringBuilder_Append( code,
			"#ifdef HLML_NAMESPACE\n"
			"}\n"
			"#endif\n"
		);
	}

	const char *fileNameHeader = String_TPrintf( tempStorage, "%s/%s.h", generatedCodePath, Gen_GetPrefixedFilename( tempStorage, strings, GEN_FILENAME_SUFFIX_FUNCTIONS_SCALAR ) );

	FS_WriteEntireFile( fileNameHeader, code->str, code->length );

	Mem_Reset( tempStorage );
}
