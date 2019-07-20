#pragma once

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "int_types.h"

#include <stdint.h>
#include <assert.h>

#include <stdio.h>

#include <string.h>

#define BIT( x )							1ULL << x

#ifndef _countof
#define _countof( x )						( sizeof( (x) ) / sizeof( (x)[0] ) )
#endif

#define UNUSED( x )							( (void) (x) )

#define GEN_MIN( x, y )						( (x) < (y) ? (x) : (y) )
#define GEN_MAX( x, y )						( (x) > (y) ? (x) : (y) )

#define GEN_COMPONENT_COUNT_MIN				2
#define GEN_COMPONENT_COUNT_MAX				4

// filenames
#define GEN_OUT_FOLDER_PATH					"code/out/"
#define GEN_OUT_GEN_FOLDER_PATH				"code/out/gen/"
#define GEN_TESTS_FOLDER_PATH				"code/tests/"

#define GEN_HEADER_TYPES					"hlml_types.h"
#define GEN_HEADER_CONSTANTS				"hlml_constants.h"
#define GEN_HEADER_USER						"hlml_user.h"

#define GEN_FILENAME_OPERATORS_VECTOR		"hlml_operators_vector"
#define GEN_FILENAME_OPERATORS_MATRIX		"hlml_operators_matrix"

#define GEN_FILENAME_FUNCTIONS_SCALAR		"hlml_functions_scalar"
#define GEN_FILENAME_FUNCTIONS_SCALAR_SSE	"hlml_functions_scalar_sse"
#define GEN_FILENAME_FUNCTIONS_VECTOR		"hlml_functions_vector"
#define GEN_FILENAME_FUNCTIONS_VECTOR_SSE	"hlml_functions_vector_sse"
#define GEN_FILENAME_FUNCTIONS_MATRIX		"hlml_functions_matrix"

#define GEN_STRING_LENGTH_NUMERIC_LITERAL	16
#define GEN_STRING_LENGTH_TYPE_NAME			16
#define GEN_STRING_LENGTH_SSE_INPUT_NAME	32

#define GEN_STRING_LENGTH_PARM_LIST_VECTOR	64
#define GEN_STRING_LENGTH_PARM_LIST_MATRIX	256

#define GEN_STRING_LENGTH_TEST_NAME			64

struct stringBuilder_t;

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

enum genClipSpace_t {
	GEN_CLIP_SPACE_ZERO_TO_ONE				= 0,
	GEN_CLIP_SPACE_MINUS_ONE_TO_ONE,

	GEN_CLIP_SPACE_COUNT
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


static const char* GEN_FILE_HEADER = \
"/*\n" \
"===========================================================================\n" \
"\n" \
"hlml.\n" \
"Copyright (c) Dan Moody 2019 - Present.\n" \
"\n" \
"This file is part of hlml.\n" \
"\n" \
"hlml is free software: you can redistribute it and/or modify\n" \
"it under the terms of the GNU General Public License as published by\n" \
"the Free Software Foundation, either version 3 of the License, or\n" \
"(at your option) any later version.\n" \
"\n" \
"hlml is distributed in the hope that it will be useful,\n" \
"but WITHOUT ANY WARRANTY; without even the implied warranty of\n" \
"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n" \
"GNU General Public License for more details.\n" \
"\n" \
"You should have received a copy of the GNU General Public License\n" \
"along with hlml.  If not, see <http://www.gnu.org/licenses/>.\n" \
"\n" \
"===========================================================================\n" \
"*/\n" \
"\n" \
"// GENERATED FILE.  DO NOT EDIT.\n" \
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

// type-to-string functions
inline const char*	Gen_GetTypeString( const genType_t type );
inline const char*	Gen_GetMemberTypeString( const genType_t type );
inline void			Gen_GetFullTypeName( const genType_t type, const u32 numRows, const u32 numCols, char* outString );
inline void			Gen_GetParmTypeName( const genType_t type, const u32 numComponents, char* outString );

inline const char*	Gen_GetDefaultLiteralValue( const genType_t type );
inline void			Gen_GetNumericLiteral( const genType_t type, const float value, char* outString, const u32 decimalPlaces = 0 );

inline const char*	Gen_GetHandString( const genHand_t hand );
inline const char*	Gen_GetClipSpaceRangeString( const genClipSpace_t range );

// type helper functions
inline genType_t	Gen_GetSupportedFloatingPointType( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? GEN_TYPE_DOUBLE : GEN_TYPE_FLOAT; }
inline bool			Gen_IsFloatingPointType( const genType_t type ) { return type == GEN_TYPE_FLOAT || type == GEN_TYPE_DOUBLE; }
inline bool			Gen_IsIntegerType( const genType_t type ) { return type == GEN_TYPE_INT || type == GEN_TYPE_UINT; }

// built-in functions
inline const char*	Gen_GetFuncNameSin( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "sin" : "sinf"; }
inline const char*	Gen_GetFuncNameCos( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "cos" : "cosf"; }
inline const char*	Gen_GetFuncNameAcos( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "acos" : "acosf"; }
inline const char*	Gen_GetFuncNameTan( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "tan" : "tanf"; }
inline const char*	Gen_GetFuncNameSqrt( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "sqrt" : "sqrtf"; }
inline const char*	Gen_GetFuncNameFabs( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "fabs" : "fabsf"; }

// hlml functions
inline const char*	Gen_GetFuncNameFloateq( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "doubleeq" : "floateq"; }

// hlml constants
inline const char*	Gen_GetConstantNamePi( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "HLML_PI" : "static_cast<float>( HLML_PI )"; }
inline const char*	Gen_GetConstantNameEpsilon( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "HLML_EPSILON" : "static_cast<float>( HLML_EPSILON )"; }

// generic helper functions that are typical of maths libraries
extern void			Gen_Floateq( const genType_t type, stringBuilder_t* sb );
extern void			Gen_Sign( const genType_t type, stringBuilder_t* sb );

extern void			Gen_Radians( const genType_t type, stringBuilder_t* sb );
extern void			Gen_Degrees( const genType_t type, stringBuilder_t* sb );
extern void			Gen_MinMax( const genType_t type, stringBuilder_t* sb );
extern void			Gen_Clamp( const genType_t type, stringBuilder_t* sb );

extern void			Gen_Saturate( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
extern void			Gen_Lerp( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
extern void			Gen_Step( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
extern void			Gen_Smoothstep( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );

// functions that are guaranteed to be the same across vectors and matrices
extern void			Gen_OperatorsIncrement( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
extern void			Gen_OperatorsRelational( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
extern void			Gen_OperatorsBitwise( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );

extern void			Gen_OperatorComponentWiseArithmeticScalar( const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op,
						stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
extern void			Gen_OperatorComponentWiseArithmeticRhsType( const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op,
						stringBuilder_t* sbHeader, stringBuilder_t* sbInl );

extern void			Gen_OperatorNotEquals( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );


const char* Gen_GetTypeString( const genType_t type ) {
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

const char* Gen_GetMemberTypeString( const genType_t type ) {
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

void Gen_GetFullTypeName( const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
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

void Gen_GetParmTypeName( const genType_t type, const u32 numComponents, char* outString ) {
	if ( numComponents == 1 ) {
		const char* memberTypeString = Gen_GetMemberTypeString( type );

		strncpy( outString, memberTypeString, GEN_STRING_LENGTH_TYPE_NAME );
	} else {
		const char* typeString = Gen_GetTypeString( type );

		snprintf( outString, GEN_STRING_LENGTH_TYPE_NAME, "%s%d&", typeString, numComponents );
	}
}

const char* Gen_GetDefaultLiteralValue( const genType_t type ) {
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

void Gen_GetNumericLiteral( const genType_t type, const float x, char* outStr, const u32 decimalPlaces ) {
	switch ( type ) {
		case GEN_TYPE_BOOL:
			snprintf( outStr, GEN_STRING_LENGTH_NUMERIC_LITERAL, "%s", ( x != 0 ) ? "true" : "false" );
			break;

		case GEN_TYPE_INT:
			snprintf( outStr, GEN_STRING_LENGTH_NUMERIC_LITERAL, "%d", (s32) x );
			break;

		case GEN_TYPE_UINT:
			snprintf( outStr, GEN_STRING_LENGTH_NUMERIC_LITERAL, "%uU", (u32) x );
			break;

		case GEN_TYPE_FLOAT:
			if ( decimalPlaces == 0 ) {
				snprintf( outStr, GEN_STRING_LENGTH_NUMERIC_LITERAL, "%ff", (float) x );
			} else {
				snprintf( outStr, GEN_STRING_LENGTH_NUMERIC_LITERAL, "%.*ff", decimalPlaces, (float) x );
			}
			break;

		case GEN_TYPE_DOUBLE:
			if ( decimalPlaces == 0 ) {
				snprintf( outStr, GEN_STRING_LENGTH_NUMERIC_LITERAL, "%f", (double) x );
			} else {
				snprintf( outStr, GEN_STRING_LENGTH_NUMERIC_LITERAL, "%.*f", decimalPlaces, (double) x );
			}
			break;

		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad genType_t enum passed through to: %s.\n", __FUNCTION__ );
			snprintf( outStr, GEN_STRING_LENGTH_NUMERIC_LITERAL, "ERROR" );
			break;
	}
}

const char* Gen_GetHandString( const genHand_t hand ) {
	switch ( hand ) {
		case GEN_HAND_LEFT:
			return "left";
			break;

		case GEN_HAND_RIGHT:
			return "right";
			break;

		case GEN_HAND_COUNT:
		default:
			printf( "ERROR: Bad genHand_t enum passed into %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

const char* Gen_GetClipSpaceRangeString( const genClipSpace_t range ) {
	switch ( range ) {
		case GEN_CLIP_SPACE_ZERO_TO_ONE:
			return "zero to one";
			break;

		case GEN_CLIP_SPACE_MINUS_ONE_TO_ONE:
			return "minus-one to one";
			break;

		case GEN_CLIP_SPACE_COUNT:
		default:
			printf( "ERROR: Bad genClipSpace_t enum passed into %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}
