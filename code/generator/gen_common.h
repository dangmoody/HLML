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
#pragma once

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "int_types.h"

#include <stdint.h>
#include <assert.h>

#include <stdio.h>

#include <string.h>


#define GEN_MIN( x, y )						( (x) < (y) ? (x) : (y) )
#define GEN_MAX( x, y )						( (x) > (y) ? (x) : (y) )

#define GEN_COMPONENT_COUNT_MIN				2
#define GEN_COMPONENT_COUNT_MAX				4

// filenames
// TODO(DM): sort these out so we have versions with and without "code"
#define GEN_OUT_FOLDER_PATH					"code/out/"
#define GEN_TESTS_FOLDER_PATH_ROOT			"code/tests/"

#define GEN_HEADER_MAIN						"hlml.h"
#define GEN_HEADER_TYPES					"hlml_types.h"
#define GEN_HEADER_CONSTANTS				"hlml_constants.h"
#define GEN_HEADER_CONSTANTS_SSE			"hlml_constants_sse.h"
#define GEN_HEADER_USER						"hlml_user.h"
#define GEN_HEADER_DEFINES					"hlml_defines.h"

#define GEN_FILENAME_OPERATORS_VECTOR		"hlml_operators_vector"
#define GEN_FILENAME_OPERATORS_MATRIX		"hlml_operators_matrix"

#define GEN_FILENAME_FUNCTIONS_SCALAR		"hlml_functions_scalar"
#define GEN_FILENAME_FUNCTIONS_VECTOR		"hlml_functions_vector"
#define GEN_FILENAME_FUNCTIONS_MATRIX		"hlml_functions_matrix"
#define GEN_FILENAME_FUNCTIONS_QUATERNION	"hlml_functions_quaternion"

#define GEN_FILENAME_FUNCTIONS_SCALAR_SSE	"hlml_functions_scalar_sse"
#define GEN_FILENAME_FUNCTIONS_VECTOR_SSE	"hlml_functions_vector_sse"
#define GEN_FILENAME_FUNCTIONS_MATRIX_SSE	"hlml_functions_matrix_sse"

#define GEN_STRING_LENGTH_NUMERIC_LITERAL	16
#define GEN_STRING_LENGTH_TYPE_NAME			16
#define GEN_STRING_LENGTH_FUNCTION_NAME		50
#define GEN_STRING_LENGTH_SSE_INPUT_NAME	34
#define GEN_STRING_LENGTH_SSE_INTRINSIC		32

#define GEN_STRING_LENGTH_PARM_LIST_VECTOR	64
#define GEN_STRING_LENGTH_PARM_LIST_MATRIX	256

#define GEN_STRING_LENGTH_TEST_NAME			64

typedef struct allocatorLinear_t allocatorLinear_t;
typedef struct stringBuilder_t stringBuilder_t;

enum genLanguage_t {
	GEN_LANGUAGE_C							= 0,
	GEN_LANGUAGE_CPP,

	GEN_LANGUAGE_COUNT
};

static const char* GEN_FOLDER_PATHS_OUT_GEN[GEN_LANGUAGE_COUNT] = {
	GEN_OUT_FOLDER_PATH "c/",
	GEN_OUT_FOLDER_PATH "cpp/"
};

static const char* GEN_FOLDER_PATHS_TESTS[GEN_LANGUAGE_COUNT] = {
	GEN_TESTS_FOLDER_PATH_ROOT "c/",
	GEN_TESTS_FOLDER_PATH_ROOT "cpp/"
};

static const char* GEN_SOURCE_FILE_EXTENSIONS[GEN_LANGUAGE_COUNT] = {
	"c",
	"cpp"
};

static const char GEN_TYPE_PARM_MODIFIERS[GEN_LANGUAGE_COUNT] = {
	'*',
	'&'
};

static const char* GEN_TYPE_PARM_REFERENCE_MODIFIERS[GEN_LANGUAGE_COUNT] = {
	"&",
	""
};

static const char* GEN_TYPE_PARM_DEREFERENCE_MODIFIERS[GEN_LANGUAGE_COUNT] = {
	"*",
	""
};

static const char* GEN_TYPE_ACCESS_OPERATORS[GEN_LANGUAGE_COUNT] = {
	"->",
	"."
};

enum genType_t {
	GEN_TYPE_BOOL							= 0,
	GEN_TYPE_INT,
	GEN_TYPE_UINT,
	GEN_TYPE_FLOAT,
	GEN_TYPE_DOUBLE,

	GEN_TYPE_COUNT,
};

enum genHand_t {
	GEN_HAND_LEFT							= 0,
	GEN_HAND_RIGHT,

	GEN_HAND_COUNT
};

static const char* GEN_HAND_SPECIFIERS[GEN_HAND_COUNT] = {
	"lh",
	"rh"
};

enum genClipSpace_t {
	GEN_CLIP_SPACE_ZERO_TO_ONE				= 0,
	GEN_CLIP_SPACE_MINUS_ONE_TO_ONE,

	GEN_CLIP_SPACE_COUNT
};

static const char* GEN_CLIP_SPACE_SPECIFIERS[GEN_HAND_COUNT] = {
	"zo",
	"no",
};

enum genOpArithmetic_t {
	GEN_OP_ARITHMETIC_ADD					= 0,
	GEN_OP_ARITHMETIC_SUB,
	GEN_OP_ARITHMETIC_MUL,
	GEN_OP_ARITHMETIC_DIV,

	GEN_OP_ARITHMETIC_COUNT
};

enum genOpIncrement_t {
	GEN_OP_INCREMENT_INCREMENT				= 0,
	GEN_OP_INCREMENT_DECREMENT,

	GEN_OP_INCREMENT_COUNT
};

enum genOpRelational_t {
	GEN_OP_RELATIONAL_LESS					= 0,
	GEN_OP_RELATIONAL_LESS_EQUAL,
	GEN_OP_RELATIONAL_GREATER,
	GEN_OP_RELATIONAL_GREATER_EQUAL,

	GEN_OP_RELATIONAL_COUNT
};

enum genOpBitwise_t {
	GEN_OP_BITWISE_AND						= 0,
	GEN_OP_BITWISE_OR,
	GEN_OP_BITWISE_XOR,
	GEN_OP_BITWISE_UNARY,
	GEN_OP_BITWISE_SHIFT_LEFT,
	GEN_OP_BITWISE_SHIFT_RIGHT,

	GEN_OP_BITWISE_COUNT
};


static const char* GEN_FILE_HEADER =
"/*\n"
"===========================================================================\n"
"\n"
"HLML.\n"
"\n"
"MIT License\n"
"\n"
"Copyright (c) 2019 Dan Moody\n"
"\n"
"Permission is hereby granted, free of charge, to any person obtaining a copy\n"
"of this software and associated documentation files (the \"Software\"), to deal\n"
"in the Software without restriction, including without limitation the rights\n"
"to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n"
"copies of the Software, and to permit persons to whom the Software is\n"
"furnished to do so, subject to the following conditions:\n"
"\n"
"The above copyright notice and this permission notice shall be included in all\n"
"copies or substantial portions of the Software.\n"
"\n"
"THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n"
"IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n"
"FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n"
"AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n"
"LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n"
"OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n"
"SOFTWARE.\n"
"\n"
"===========================================================================\n"
"*/\n"
"\n"
"// THIS FILE WAS AUTOMATICALLY GENERATED BY A TOOL.\n"
"// EDITING THIS FILE MAY CAUSE SIDE EFFECTS.\n"
"// DO SO AT YOUR OWN RISK.\n"
"\n";

static const char* GEN_COMPONENT_NAMES_VECTOR	= "xyzw";
static const char* GEN_COMPONENT_NAMES_COLOR	= "rgba";
static const char* GEN_OPERATORS_ARITHMETIC		= "+-*/";

static const char* GEN_OPERATORS_INCREMENT[GEN_OP_INCREMENT_COUNT] = {
	"++",
	"--",
};

static const char* GEN_OPERATORS_RELATIONAL[GEN_OP_RELATIONAL_COUNT] = {
	"<",
	"<=",
	">",
	">=",
};

static const char* GEN_OPERATORS_BITWISE[GEN_OP_BITWISE_COUNT] = {
	"&",
	"|",
	"^",
	"~",
	"<<",
	">>"
};

static const char* GEN_OPERATOR_STRINGS_ARITHMETIC[GEN_OP_ARITHMETIC_COUNT] = {
	"add",
	"sub",
	"mul",
	"div"
};


// type helper functions
inline genType_t	Gen_GetSupportedFloatingPointType( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? GEN_TYPE_DOUBLE : GEN_TYPE_FLOAT; }
inline bool			Gen_TypeIsFloatingPoint( const genType_t type ) { return type == GEN_TYPE_FLOAT || type == GEN_TYPE_DOUBLE; }
inline bool			Gen_TypeIsInteger( const genType_t type ) { return type == GEN_TYPE_INT || type == GEN_TYPE_UINT; }

// built-in functions
inline const char*	Gen_GetFuncNameSin( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "sin" : "sinf"; }
inline const char*	Gen_GetFuncNameCos( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "cos" : "cosf"; }
inline const char*	Gen_GetFuncNameAcos( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "acos" : "acosf"; }
inline const char*	Gen_GetFuncNameTan( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "tan" : "tanf"; }
inline const char*	Gen_GetFuncNameSqrt( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "sqrt" : "sqrtf"; }
inline const char*	Gen_GetFuncNameFabs( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "fabs" : "fabsf"; }

// hlml functions
inline const char*	Gen_GetFuncNameFloateq( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "doubleeq" : "floateq"; }
inline const char*	Gen_GetFuncNameFloateqeps( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "doubleeq_eps" : "floateq_eps"; }
inline const char*	Gen_GetFuncNameRadians( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "radians" : "radiansf"; }
inline const char*	Gen_GetFuncNameDegrees( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "degrees" : "degreesf"; }

// hlml constants
inline const char*	Gen_GetConstantNamePi( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "HLML_PI" : "(float)( HLML_PI )"; }
inline const char*	Gen_GetConstantNameEpsilon( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "HLML_EPSILON" : "(float)( HLML_EPSILON )"; }


// generic helper functions

// generates the primary include header (hlml.h)
void				Gen_HeaderMain( allocatorLinear_t* allocator, const genLanguage_t language );

// generate the files containing the arithmetic functions for each type
void				Gen_FunctionsScalar( allocatorLinear_t* allocator, const genLanguage_t language );
void				Gen_FunctionsVector( allocatorLinear_t* allocator, const genLanguage_t language );
void				Gen_FunctionsMatrix( allocatorLinear_t* allocator, const genLanguage_t language );
void				Gen_FunctionsQuaternion( allocatorLinear_t* allocator, const genLanguage_t language );

// generate the files containing the SSE functions for each type
void				Gen_FunctionsScalarSSE( allocatorLinear_t* allocator, const genLanguage_t language );
void				Gen_FunctionsVectorSSE( allocatorLinear_t* allocator, const genLanguage_t language );
void				Gen_FunctionsMatrixSSE( allocatorLinear_t* allocator, const genLanguage_t language );

// generates the tests for the specified language
void				Gen_Tests( allocatorLinear_t* allocator, const genLanguage_t language );

// generates the tests "main" file
void				Gen_TestsMain( allocatorLinear_t* allocator, const genLanguage_t language );

// parm list/array helpers
// TODO(DM): allow specify prefix for each initialiser list
void				Gen_GetValuesArray1D( const genType_t type, const u32 numValues, const float* values, stringBuilder_t* sb );
void				Gen_GetValuesArray2D( const genType_t type, const u32 rows, const u32 cols, const float* values, stringBuilder_t* sb );

// scalar functions
void				Gen_Floateq( const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
void				Gen_Sign( const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );

void				Gen_Radians( const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
void				Gen_Degrees( const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
void				Gen_MinMax( const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
void				Gen_Clamp( const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );

// scalar/vector functions
void				Gen_Saturate( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
void				Gen_Lerp( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
void				Gen_Step( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
void				Gen_Smoothstep( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );

// vector/matrix common functions
void				Gen_FunctionAll( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );

// C++ operator overloads for vectors and matrices
void				Gen_OperatorsEquality( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
void				Gen_OperatorsIncrement( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );

void				Gen_NotEquals( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );


// type-to-string functions
inline const char* Gen_GetTypeString( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_BOOL:		return "bool";
		case GEN_TYPE_INT:		return "int";
		case GEN_TYPE_UINT:		return "uint";
		case GEN_TYPE_FLOAT:	return "float";
		case GEN_TYPE_DOUBLE:	return "double";

		case GEN_TYPE_COUNT:
		default:
			printf( "Bad genType_t specified when calling %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

inline const char* Gen_GetMemberTypeString( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_BOOL:		return "bool32_t";
		case GEN_TYPE_INT:		return "int32_t";
		case GEN_TYPE_UINT:		return "uint32_t";
		case GEN_TYPE_FLOAT:	return "float";
		case GEN_TYPE_DOUBLE:	return "double";

		case GEN_TYPE_COUNT:
		default:
			printf( "Bad genType_t specified when calling %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

inline void Gen_GetFullTypeName( const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= 1 );	// 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= 1 );	// 1 for straight scalar types
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	const char* typeString = Gen_GetTypeString( type );

	int len = 0;

	if ( numRows == 1 ) {
		if ( numCols > 1 ) {
			len = snprintf( outString, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, numCols );
		} else {
			// here if passed something like "float1", so really just a "float"
			len = snprintf( outString, GEN_STRING_LENGTH_TYPE_NAME, "%s", Gen_GetMemberTypeString( type ) );
		}
	} else {
		len = snprintf( outString, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numRows, numCols );
	}

	if ( len >= GEN_STRING_LENGTH_TYPE_NAME ) {
		printf( "ERROR: Attempted to write a typename greater than %d characters.\n", GEN_STRING_LENGTH_TYPE_NAME );
		assert( false );
	}
}

inline void Gen_GetParmTypeName( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= 1 );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= 1 );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	if ( numCols == 1 ) {
		// scalar
		const char* memberTypeString = Gen_GetMemberTypeString( type );
		strncpy( outString, memberTypeString, GEN_STRING_LENGTH_TYPE_NAME );
	} else {
		// vector of some kind
		char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
		Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

		int length = snprintf( outString, GEN_STRING_LENGTH_TYPE_NAME, "%s%c", fullTypeName, GEN_TYPE_PARM_MODIFIERS[language] );
		assert( length < GEN_STRING_LENGTH_TYPE_NAME && "Type name string length constant needs to be increased." );
	}
}

inline const char* Gen_GetDefaultLiteralValue( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_BOOL:		return "false";
		case GEN_TYPE_INT:		return "0";
		case GEN_TYPE_UINT:		return "0";
		case GEN_TYPE_FLOAT:	return "0.0f";
		case GEN_TYPE_DOUBLE:	return "0.0";

		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad type_t passed through to %s.  Fix it!\n", __FUNCTION__ );
			return "ERROR";
	}
}

inline void Gen_GetNumericLiteral( const genType_t type, const float x, char* outStr, const u32 decimalPlaces = 0 ) {
	int length = 0;

	switch ( type ) {
		case GEN_TYPE_BOOL:
			length = snprintf( outStr, GEN_STRING_LENGTH_NUMERIC_LITERAL, "%s", ( x != 0 ) ? "true" : "false" );
			break;

		case GEN_TYPE_INT:
			length = snprintf( outStr, GEN_STRING_LENGTH_NUMERIC_LITERAL, "%d", (s32) x );
			break;

		case GEN_TYPE_UINT:
			length = snprintf( outStr, GEN_STRING_LENGTH_NUMERIC_LITERAL, "%uU", (u32) x );
			break;

		case GEN_TYPE_FLOAT:
			if ( decimalPlaces == 0 ) {
				length = snprintf( outStr, GEN_STRING_LENGTH_NUMERIC_LITERAL, "%ff", (float) x );
			} else {
				length = snprintf( outStr, GEN_STRING_LENGTH_NUMERIC_LITERAL, "%.*ff", decimalPlaces, (float) x );
			}
			break;

		case GEN_TYPE_DOUBLE:
			if ( decimalPlaces == 0 ) {
				length = snprintf( outStr, GEN_STRING_LENGTH_NUMERIC_LITERAL, "%f", (double) x );
			} else {
				length = snprintf( outStr, GEN_STRING_LENGTH_NUMERIC_LITERAL, "%.*f", decimalPlaces, (double) x );
			}
			break;

		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad genType_t enum passed through to: %s.\n", __FUNCTION__ );
			length = snprintf( outStr, GEN_STRING_LENGTH_NUMERIC_LITERAL, "ERROR" );
			break;
	}

	assert( length < GEN_STRING_LENGTH_NUMERIC_LITERAL && "Numeric literal string length constant needs to be increased." );
}

inline const char* Gen_GetHandString( const genHand_t hand ) {
	switch ( hand ) {
		case GEN_HAND_LEFT:		return "left";
		case GEN_HAND_RIGHT:	return "right";

		case GEN_HAND_COUNT:
		default:
			printf( "ERROR: Bad genHand_t enum passed into %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

inline const char* Gen_GetClipSpaceRangeString( const genClipSpace_t range ) {
	switch ( range ) {
		case GEN_CLIP_SPACE_ZERO_TO_ONE:		return "zero to one";
		case GEN_CLIP_SPACE_MINUS_ONE_TO_ONE:	return "minus-one to one";

		case GEN_CLIP_SPACE_COUNT:
		default:
			printf( "ERROR: Bad genClipSpace_t enum passed into %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

// hlml functions
inline const char* Gen_GetFuncNameSign( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_INT:		return "signi";
		case GEN_TYPE_FLOAT:	return "signf";
		case GEN_TYPE_DOUBLE:	return "signd";

		case GEN_TYPE_BOOL:
		case GEN_TYPE_UINT:
		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad genType_t passed into %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

inline const char* Gen_GetFuncNameMin( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_INT:		return "mini";
		case GEN_TYPE_UINT:		return "minu";
		case GEN_TYPE_FLOAT:	return "minf";
		case GEN_TYPE_DOUBLE:	return "mind";

		case GEN_TYPE_BOOL:
		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad genType_t passed into %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

inline const char* Gen_GetFuncNameMax( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_INT:		return "maxi";
		case GEN_TYPE_UINT:		return "maxu";
		case GEN_TYPE_FLOAT:	return "maxf";
		case GEN_TYPE_DOUBLE:	return "maxd";

		case GEN_TYPE_BOOL:
		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad genType_t passed into %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

inline const char* Gen_GetFuncNameClamp( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_INT:		return "clampi";
		case GEN_TYPE_UINT:		return "clampu";
		case GEN_TYPE_FLOAT:	return "clampf";
		case GEN_TYPE_DOUBLE:	return "clampd";

		case GEN_TYPE_BOOL:
		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad genType_t passed into %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

// to get a function name don't call this directly
// use one of the wrapper functions below
// the only other function that is allowed to call this is Gen_SSE_GetFuncNameInternal
inline void Gen_GetFuncNameInternal( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const char* funcName, char* outString ) {
	// 1 rows and 1 cols for scalar
	// 1 rows and M cols for vector
	// N rows and M cols for matrix
	assert( numRows >= 1 );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= 1 );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	if ( numCols > 1 ) {
		// assert( numRows != 1 );
		if ( language == GEN_LANGUAGE_C ) {
			char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
			Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

			snprintf( outString, GEN_STRING_LENGTH_FUNCTION_NAME, "%s_%s", fullTypeName, funcName );
		} else {
			strncpy( outString, funcName, GEN_STRING_LENGTH_FUNCTION_NAME );
		}
	} else {
		assert( numCols == 1 );
		assert( numRows == 1 );

		const char* modifier = ( type == GEN_TYPE_FLOAT ) ? "f" : "";
		snprintf( outString, GEN_STRING_LENGTH_FUNCTION_NAME, "%s%s", funcName, modifier );
	}
}

inline void Gen_GetFuncNameAll( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= 1 );	// 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, numRows, numCols, "all", outString );
}

inline void Gen_GetFuncNameEquals( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= 1 );	// 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, numRows, numCols, "cmpe", outString );
}

inline void Gen_GetFuncNameNotEquals( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= 1 );	// 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, numRows, numCols, "cmpne", outString );
}

inline void Gen_GetFuncNameComponentWiseArithmeticScalar( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, char* outString ) {
	assert( numRows >= 1 );	// 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	char prefix[GEN_STRING_LENGTH_FUNCTION_NAME];
	snprintf( prefix, GEN_STRING_LENGTH_FUNCTION_NAME, "comp_%ss", GEN_OPERATOR_STRINGS_ARITHMETIC[op] );

	Gen_GetFuncNameInternal( language, type, numRows, numCols, prefix, outString );
}

inline void Gen_GetFuncNameComponentWiseArithmeticVector( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, char* outString ) {
	assert( numRows >= 1 );	// 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	char prefix[GEN_STRING_LENGTH_FUNCTION_NAME];
	snprintf( prefix, GEN_STRING_LENGTH_FUNCTION_NAME, "comp_%sv", GEN_OPERATOR_STRINGS_ARITHMETIC[op] );

	Gen_GetFuncNameInternal( language, type, numRows, numCols, prefix, outString );
}

inline void Gen_GetFuncNameComponentWiseArithmeticMatrix( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	char prefix[GEN_STRING_LENGTH_FUNCTION_NAME];
	snprintf( prefix, GEN_STRING_LENGTH_FUNCTION_NAME, "comp_%sm", GEN_OPERATOR_STRINGS_ARITHMETIC[op] );

	Gen_GetFuncNameInternal( language, type, numRows, numCols, prefix, outString );
}

inline void Gen_GetFuncNameBitwise( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const genOpBitwise_t op, char* outString ) {
	assert( numRows >= 1 );	// 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	const char* opStr = NULL;
	switch ( op ) {
		case GEN_OP_BITWISE_AND:			opStr = "and";			break;
		case GEN_OP_BITWISE_OR:				opStr = "or";			break;
		case GEN_OP_BITWISE_XOR:			opStr = "xor";			break;
		case GEN_OP_BITWISE_UNARY:			opStr = "unary";		break;
		case GEN_OP_BITWISE_SHIFT_LEFT:		opStr = "shift_left";	break;
		case GEN_OP_BITWISE_SHIFT_RIGHT:	opStr = "shift_right";	break;

		case GEN_OP_BITWISE_COUNT:
		default:
			assert( false && "Bad genOpBitwise_t passed." );
			break;
	}

	char prefix[GEN_STRING_LENGTH_FUNCTION_NAME];
	snprintf( prefix, GEN_STRING_LENGTH_FUNCTION_NAME, "comp_%s", opStr );

	Gen_GetFuncNameInternal( language, type, numRows, numCols, prefix, outString );
}

inline void Gen_GetFuncNameRelational( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const genOpRelational_t op, char* outString ) {
	assert( numRows >= 1 );	// 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	const char* opStr = NULL;
	switch ( op ) {
		case GEN_OP_RELATIONAL_LESS:			opStr = "l";	break;
		case GEN_OP_RELATIONAL_LESS_EQUAL:		opStr = "le";	break;
		case GEN_OP_RELATIONAL_GREATER_EQUAL:	opStr = "ge";	break;
		case GEN_OP_RELATIONAL_GREATER:			opStr = "g";	break;

		case GEN_OP_RELATIONAL_COUNT:
		default:
			assert( false && "Bad genOpRelational_t passed." );
			break;
	}

	char funcName[GEN_STRING_LENGTH_FUNCTION_NAME];
	snprintf( funcName, GEN_STRING_LENGTH_FUNCTION_NAME, "cmp%s", opStr );

	Gen_GetFuncNameInternal( language, type, numRows, numCols, funcName, outString );
}

inline void Gen_GetFuncNameSaturate( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	Gen_GetFuncNameInternal( language, type, 1, numComponents, "saturate", outString );
}

inline void Gen_GetFuncNameLerp( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	Gen_GetFuncNameInternal( language, type, 1, numComponents, "lerp", outString );
}

inline void Gen_GetFuncNameStep( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	Gen_GetFuncNameInternal( language, type, 1, numComponents, "step", outString );
}

inline void Gen_GetFuncNameSmoothstep( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	Gen_GetFuncNameInternal( language, type, 1, numComponents, "smoothstep", outString );
}

inline void Gen_GetFuncNameSmootherstep( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	Gen_GetFuncNameInternal( language, type, 1, numComponents, "smootherstep", outString );
}

inline void Gen_GetFuncNameLengthsqr( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, 1, numComponents, "lengthsqr", outString );
}

inline void Gen_GetFuncNameLength( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, 1, numComponents, "length", outString );
}

inline void Gen_GetFuncNameDot( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, 1, numComponents, "dot", outString );
}

inline void Gen_GetFuncNameCross( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, 1, numComponents, "cross", outString );
}

inline void Gen_GetFuncNameDistancesqr( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, 1, numComponents, "distancesqr", outString );
}

inline void Gen_GetFuncNameAngle( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, 1, numComponents, "angle", outString );
}

inline void Gen_GetFuncNameDistance( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, 1, numComponents, "distance", outString );
}

inline void Gen_GetFuncNameNormalize( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, 1, numComponents, "normalize", outString );
}

inline void Gen_GetFuncNameNormalized( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, 1, numComponents, "normalized", outString );
}

// matrices
inline void Gen_GetFuncNameIdentity( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, numRows, numCols, "identity", outString );
}

inline void Gen_GetFuncNameTranspose( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, numRows, numCols, "transpose", outString );
}

inline void Gen_GetFuncNameDeterminant( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, numRows, numCols, "determinant", outString );
}

inline void Gen_GetFuncNameInverse( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, numRows, numCols, "inverse", outString );
}

inline void Gen_GetFuncNameTranslate( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, numRows, numCols, "translate", outString );
}

inline void Gen_GetFuncNameRotate( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, numRows, numCols, "rotate", outString );
}

inline void Gen_GetFuncNameScale( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	Gen_GetFuncNameInternal( language, type, numRows, numCols, "scale", outString );
}

inline void Gen_GetFuncNameOrtho( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const genHand_t hand, const genClipSpace_t clipSpace, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	const char* handStr = GEN_HAND_SPECIFIERS[hand];
	const char* clipSpaceStr = GEN_CLIP_SPACE_SPECIFIERS[clipSpace];

	char funcName[GEN_STRING_LENGTH_FUNCTION_NAME];
	snprintf( funcName, GEN_STRING_LENGTH_FUNCTION_NAME, "ortho_%s_%s", handStr, clipSpaceStr );

	Gen_GetFuncNameInternal( language, type, numRows, numCols, funcName, outString );
}

inline void Gen_GetFuncNamePerspective( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const genHand_t hand, const genClipSpace_t clipSpace, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	const char* handStr = GEN_HAND_SPECIFIERS[hand];
	const char* clipSpaceStr = GEN_CLIP_SPACE_SPECIFIERS[clipSpace];

	char funcName[GEN_STRING_LENGTH_FUNCTION_NAME];
	snprintf( funcName, GEN_STRING_LENGTH_FUNCTION_NAME, "perspective_%s_%s", handStr, clipSpaceStr );

	Gen_GetFuncNameInternal( language, type, numRows, numCols, funcName, outString );
}

inline void Gen_GetFuncNameLookAt( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const genHand_t hand, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	char funcName[GEN_STRING_LENGTH_FUNCTION_NAME];
	snprintf( funcName, GEN_STRING_LENGTH_FUNCTION_NAME, "lookat_%s", GEN_HAND_SPECIFIERS[hand] );

	Gen_GetFuncNameInternal( language, type, numRows, numCols, funcName, outString );
}

inline void Gen_GetFuncNameMatrixMultiply( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	if ( language == GEN_LANGUAGE_C ) {
		Gen_GetFuncNameInternal( language, type, numRows, numCols, "mulm", outString );
	} else {
		Gen_GetFuncNameInternal( language, type, numRows, numCols, "mul", outString );
	}
}

inline void Gen_GetFuncNameMatrixMultiplyVector( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	if ( language == GEN_LANGUAGE_C ) {
		Gen_GetFuncNameInternal( language, type, numRows, numCols, "mulv", outString );
	} else {
		Gen_GetFuncNameInternal( language, type, numRows, numCols, "mul", outString );
	}
}

inline void Gen_GetFuncNameQuaternionMultiplyQuaternion( const genLanguage_t language, const genType_t type, char* outString ) {
	assert( outString );
	
	if ( language == GEN_LANGUAGE_C ) {
		Gen_GetFuncNameInternal( language, type, 1, 4, "quaternion_mulq", outString );
	} else {
		Gen_GetFuncNameInternal( language, type, 1, 4, "quaternion_mul", outString );
	}
}

inline void Gen_GetFuncNameQuaternionMultiplyScalar( const genLanguage_t language, const genType_t type, char* outString ) {
	assert( outString );
	
	if ( language == GEN_LANGUAGE_C ) {
		Gen_GetFuncNameInternal( language, type, 1, 4, "quaternion_mul", outString );
	} else {
		Gen_GetFuncNameInternal( language, type, 1, 4, "quaternion_mul", outString );
	}
}

inline void Gen_GetFuncNameQuaternionLength( const genLanguage_t language, const genType_t type, char* outString ) {
	assert( outString );
	
	Gen_GetFuncNameInternal( language, type, 1, 4, "quaternion_length", outString );
}

inline void Gen_GetFuncNameQuaternionNormalize( const genLanguage_t language, const genType_t type, char* outString ) {
	assert( outString );
	
	Gen_GetFuncNameInternal( language, type, 1, 4, "quaternion_normalize", outString );
}

inline void Gen_GetFuncNameQuaternionConjugate( const genLanguage_t language, const genType_t type, char* outString ) {
	assert( outString );
	
	Gen_GetFuncNameInternal( language, type, 1, 4, "quaternion_conjugate", outString );
}

inline void Gen_GetFuncNameQuaternionInverse( const genLanguage_t language, const genType_t type, char* outString ) {
	assert( outString );
	
	Gen_GetFuncNameInternal( language, type, 1, 4, "quaternion_inverse", outString );
}

inline void Gen_GetFuncNameQuaternionRotate( const genLanguage_t language, const genType_t type, char* outString ) {
	assert( outString );
	
	Gen_GetFuncNameInternal( language, type, 1, 4, "quaternion_rotate", outString );
}

inline void Gen_GetFuncNameQuaternionLerp( const genLanguage_t language, const genType_t type, char* outString ) {
	assert( outString );
	
	Gen_GetFuncNameInternal( language, type, 1, 4, "quaternion_lerp", outString );
}

inline void Gen_GetFuncNameQuaternionSlerp( const genLanguage_t language, const genType_t type, char* outString ) {
	assert( outString );
	
	Gen_GetFuncNameInternal( language, type, 1, 4, "quaternion_slerp", outString );
}
