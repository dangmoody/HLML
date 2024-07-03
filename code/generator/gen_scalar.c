/*
===========================================================================

HLML Generator.
Copyright (c) Dan Moody 2018 - Present.

This file is part of the HLML Generator.

The HLML Generator is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

The HLML Generator is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with The HLML Generator.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/

static const char* Gen_GetConstantName( allocatorLinear_t* tempStorage, const genType_t type, const char* constantName ) {
	assert( tempStorage );
	assert( type != GEN_TYPE_COUNT );
	assert( constantName );

	if ( type == GEN_TYPE_FLOAT ) {
		return String_TPrintf( tempStorage, "(float)( %s )", constantName );
	} else {
		return String_TPrintf( tempStorage, "( %s )", constantName );
	}
}

// TODO(DM): rewrite to use Christer Ericson's method
static void GenerateFunction_Floateq( allocatorLinear_t* tempStorage, const genType_t type, stringBuilder_t* code, const char* memberTypeString ) {
	assert( tempStorage );
	assert( code );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char* floateqStr = Gen_GetFuncName_Floateq( type );
	const char* floateqepsStr = Gen_GetFuncName_Floateq_eps( type );

	const char* parmEpsilonStr = Gen_GetConstantName( tempStorage, type, GEN_CONSTANT_NAME_EPSILON );

	// floateq_eps
	StringBuilder_Append(  code, "// Returns true if the two given floating-point numbers are close enough to each other within a user-specified margin of error to be considered equal.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE bool %s( const %s lhs, const %s rhs, const %s epsilon )\n", floateqepsStr, memberTypeString, memberTypeString, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn %s( lhs - rhs ) < epsilon;\n", Gen_GetBuiltinFunction( tempStorage, type, GEN_BUILTIN_FUNCTION_NAME_FABS ) );
	StringBuilder_Append(  code, "}\n\n" );

	// floateq
	StringBuilder_Appendf( code, "// Returns true if the two given floating-point numbers are close enough to each other within margin of error `%s` to be considered equal.\n", parmEpsilonStr );
	StringBuilder_Appendf( code, "HLML_INLINE bool %s( const %s lhs, const %s rhs )\n", floateqStr, memberTypeString, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn %s( lhs, rhs, %s );\n", floateqepsStr, parmEpsilonStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Sign_Scalar( allocatorLinear_t* tempStorage, const genType_t type, stringBuilder_t* code, const char* memberTypeString, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( memberTypeString );

	if ( type == GEN_TYPE_BOOL || type == GEN_TYPE_UINT ) {
		return;
	}

	const char* intTypeString = Gen_GetMemberTypeString( GEN_TYPE_INT );

	const char* signFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_SIGN );

	const char* zeroStr = Gen_GetNumericLiteral( tempStorage, type, 0, 1 );

	StringBuilder_Append(  code, "// Returns -1 if 'x' is < 0, 0 if 'x' == 0, or 1 if 'x' > 1.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s x )\n", intTypeString, signFuncStr, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn ( %s < x ) - ( x < %s );\n", zeroStr, zeroStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Radians( allocatorLinear_t* tempStorage, const genType_t type, stringBuilder_t* code, const char* memberTypeString, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char* radiansFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_RADIANS );

	const char* oneHundredEightyStr = Gen_GetNumericLiteral( tempStorage, type, 180, 1 );

	const char* piStr = Gen_GetConstantName( tempStorage, type, GEN_CONSTANT_NAME_PI );

	StringBuilder_Append(  code, "// Returns the given degrees to radians.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s deg )\n", memberTypeString, radiansFuncStr, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn deg * %s / %s;\n", piStr, oneHundredEightyStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Degrees( allocatorLinear_t* tempStorage, const genType_t type, stringBuilder_t* code, const char* memberTypeString, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char* degreesFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_DEGREES );

	const char* oneHundredEightyStr = Gen_GetNumericLiteral( tempStorage, type, 180, 1 );

	const char* piStr = Gen_GetConstantName( tempStorage, type, GEN_CONSTANT_NAME_PI );

	StringBuilder_Append(  code, "// Returns the given radians to degrees.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s rad )\n", memberTypeString, degreesFuncStr, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn rad * %s / %s;\n", oneHundredEightyStr, piStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_MinMax_Scalar( allocatorLinear_t* tempStorage, const genType_t type, stringBuilder_t* code, const char* memberTypeString, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	const char* minFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_MIN );
	const char* maxFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_MAX );

	// min
	StringBuilder_Append(  code, "// Returns 'x' if it's smaller than 'y', otherwise returns 'y'.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s x, const %s y )\n", memberTypeString, minFuncStr, memberTypeString, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Append(  code, "\treturn ( x < y ) ? x : y;\n" );
	StringBuilder_Append(  code, "}\n\n" );

	// max
	StringBuilder_Append(  code, "// Returns x if it's larger than 'y', otherwise returns 'y'.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s x, const %s y )\n", memberTypeString, maxFuncStr, memberTypeString, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Append(  code, "\treturn ( x > y ) ? x : y;\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Clamp( allocatorLinear_t* tempStorage, const genType_t type, stringBuilder_t* code, const char* memberTypeString, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	const char* clampFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_CLAMP );
	const char* minFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_MIN );
	const char* maxFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_MAX );

	StringBuilder_Append(  code, "// If 'x' is lower than 'low' or higher than 'high' then returns 'low' or 'high' respectively, otherwise returns 'x'.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s x, const %s low, const %s high )\n", memberTypeString, clampFuncStr, memberTypeString, memberTypeString, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn %s( %s( x, low ), high );\n", minFuncStr, maxFuncStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Saturate( allocatorLinear_t* tempStorage, const genType_t type, stringBuilder_t* code, const char* memberTypeString, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	const char* saturateFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_SATURATE );
	const char* clampFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_CLAMP );

	const char* zeroStr = Gen_GetNumericLiteral( tempStorage, type, 0.0f, 1 );
	const char* oneStr = Gen_GetNumericLiteral( tempStorage, type, 1.0f, 1 );

	StringBuilder_Append(  code, "// Returns a copy of 'x' that has been clamped between the range 0 and 1.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s x )\n", memberTypeString, saturateFuncStr, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn %s( x, %s, %s );\n", clampFuncStr, zeroStr, oneStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Lerp( allocatorLinear_t* tempStorage, const genType_t type, stringBuilder_t* code, const char* memberTypeString, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char* lerpFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_LERP );

	const char* oneStr = Gen_GetNumericLiteral( tempStorage, type, 1.0f, 1 );

	StringBuilder_Append(  code, "// Returns a linearly interpolated float between 'a' and 'b', where 't' is the percentage (between 0 and 1) to interpolate by.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s a, const %s b, const %s t )\n", memberTypeString, lerpFuncStr, memberTypeString, memberTypeString, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn ( %s - t ) * a + t * b;\n", oneStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Step( allocatorLinear_t* tempStorage, const genType_t type, stringBuilder_t* code, const char* memberTypeString, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	const char* stepFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_STEP );

	const char* zeroStr = Gen_GetNumericLiteral( tempStorage, type, 0.0f, 1 );
	const char* oneStr = Gen_GetNumericLiteral( tempStorage, type, 1.0f, 1 );

	StringBuilder_Append(  code, "// Returns 1 if 'y' is greater than 'x', otherwise returns 0.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s x, const %s y )\n", memberTypeString, stepFuncStr, memberTypeString, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn ( y > x ? %s : %s );\n", oneStr, zeroStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Smoothstep( allocatorLinear_t* tempStorage, const genType_t type, stringBuilder_t* code, const char* memberTypeString, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char* smoothstepFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_SMOOTHSTEP );
	const char* saturateFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_SATURATE );

	const char* threeStr = Gen_GetNumericLiteral( tempStorage, type, 3.0f, 1 );
	const char* twoStr = Gen_GetNumericLiteral( tempStorage, type, 2.0f, 1 );

	StringBuilder_Append(  code, "// Performs a sigmoid-like interpolation and clamp.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s low, const %s high, const %s x )\n", memberTypeString, smoothstepFuncStr, memberTypeString, memberTypeString, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\t%s t = %s( ( x - low ) / ( high - low ) );\n", memberTypeString, saturateFuncStr );
	StringBuilder_Appendf( code, "\treturn t * t * ( %s - %s * t );\n", threeStr, twoStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_Smootherstep( allocatorLinear_t* tempStorage, const genType_t type, stringBuilder_t* code, const char* memberTypeString, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char* smootherstepFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_SMOOTHERSTEP );
	const char* saturateFuncStr = Gen_GetFuncName_Scalar( tempStorage, type, flags, GEN_FUNCTION_NAME_SATURATE );

	const char* sixStr = Gen_GetNumericLiteral( tempStorage, type, 6.0f, 1 );
	const char* fifteenStr = Gen_GetNumericLiteral( tempStorage, type, 15.0f, 1 );
	const char* tenStr = Gen_GetNumericLiteral( tempStorage, type, 10.0f, 1 );

	StringBuilder_Append(  code,
		"// Performs a 'smoother' version of smoothstep, as design by Ken Perlin.\n"
		"// https://en.wikipedia.org/wiki/Smoothstep#Variations\n"
	);
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s low, const %s high, const %s x )\n", memberTypeString, smootherstepFuncStr, memberTypeString, memberTypeString, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\t%s t = %s( ( x - low ) / ( high - low ) );\n", memberTypeString, saturateFuncStr );
	StringBuilder_Appendf( code, "\treturn t * t * t * ( t * ( t * %s - %s ) + %s );\n", sixStr, fifteenStr, tenStr );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateScalarFiles( allocatorLinear_t* tempStorage, const char* generatedCodePath, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( generatedCodePath );

	bool32 cLinkage = flags & GENERATOR_FLAG_C_LINKAGE;

	stringBuilder_t* code = StringBuilder_Create( tempStorage, KILOBYTES( 12 ) );

	StringBuilder_Append( code,
		GEN_FILE_HEADER
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

	StringBuilder_Append( code,
		"#include \"" GEN_HEADER_CONSTANTS "\"\n"
		"#include \"" GEN_HEADER_DEFINES "\"\n"
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

	if ( !cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef HLML_NAMESPACE\n"
			"namespace hlml\n"
			"{\n"
			"#endif\n"
			"\n"
		);
	}

	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		const char* memberTypeString = Gen_GetMemberTypeString( type );

		printf( "Scalar functions %s...", memberTypeString );

		StringBuilder_Appendf( code, "// %s\n", memberTypeString );

		GenerateFunction_Floateq( tempStorage, type, code, memberTypeString );
		GenerateFunction_Radians( tempStorage, type, code, memberTypeString, flags );
		GenerateFunction_Degrees( tempStorage, type, code, memberTypeString, flags );
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

	if ( !cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef HLML_NAMESPACE\n"
			"}\n"
			"#endif\n"
		);
	}

	const char* fileNameHeader = String_TPrintf( tempStorage, "%s/%s.h", generatedCodePath, GEN_FILENAME_FUNCTIONS_SCALAR );

	FS_WriteEntireFile( fileNameHeader, code->str, code->length );

	Mem_Reset( tempStorage );
}