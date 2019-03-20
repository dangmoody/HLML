#pragma once

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdint.h>
#include <assert.h>

#include <string>

#define BIT( x )						1ULL << x

#ifndef _countof
#define _countof( x )					( sizeof( (x) ) / sizeof( (x)[0] ) )
#endif

#define UNUSED( x )						( (void) (x) )

#define GEN_COMPONENT_COUNT_MIN			2
#define GEN_COMPONENT_COUNT_MAX			4

#define GEN_OUT_FOLDER_PATH				"code/out/"
#define GEN_OUT_GEN_FOLDER_PATH			"code/out/gen/"
#define GEN_TESTS_FOLDER_PATH			"code/tests/"

#define GEN_HEADER_MAIN					"hlml_main.h"
#define GEN_HEADER_USER					"hlml_user.h"

#define GEN_HEADER_VECTOR				"hlml_vector.h"
#define GEN_HEADER_MATRIX				"hlml_matrix.h"

#define GEN_FILENAME_OPERATORS_VECTOR	"hlml_operators_vector"
#define GEN_FILENAME_OPERATORS_MATRIX	"hlml_operators_matrix"

#define GEN_FILENAME_FUNCTIONS_VECTOR	"hlml_functions_vector"
#define GEN_FILENAME_FUNCTIONS_MATRIX	"hlml_functions_matrix"

enum genType_t {
	GEN_TYPE_BOOL						= 0,
	GEN_TYPE_INT,
	GEN_TYPE_UINT,
	GEN_TYPE_FLOAT,
	GEN_TYPE_DOUBLE,

	GEN_TYPE_COUNT,
};

enum genHand_t {
	GEN_HAND_LEFT						= 0,
	GEN_HAND_RIGHT,

	GEN_HAND_COUNT
};

enum genOpArithmetic_t {
	GEN_OP_ARITHMETIC_ADD				= 0,
	GEN_OP_ARITHMETIC_SUB,
	GEN_OP_ARITHMETIC_MUL,
	GEN_OP_ARITHMETIC_DIV,

	GEN_OP_ARITHMETIC_COUNT
};

enum genOpIncrement_t {
	GEN_OP_INCREMENT_INCREMENT			= 0,
	GEN_OP_INCREMENT_DECREMENT,

	GEN_OP_INCREMENT_COUNT
};

enum genOpRelational_t {
	GEN_OP_RELATIONAL_LESS				= 0,
	GEN_OP_RELATIONAL_LESS_EQUAL,
	GEN_OP_RELATIONAL_GREATER,
	GEN_OP_RELATIONAL_GREATER_EQUAL,

	GEN_OP_RELATIONAL_COUNT
};

enum genOpBitwise_t {
	GEN_OP_BITWISE_AND					= 0,
	GEN_OP_BITWISE_OR,
	GEN_OP_BITWISE_XOR,
	GEN_OP_BITWISE_UNARY,
	GEN_OP_BITWISE_SHIFT_LEFT,
	GEN_OP_BITWISE_SHIFT_RIGHT,

	GEN_OP_BITWISE_COUNT
};


const std::string GEN_FILE_HEADER = \
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

const std::string GEN_COMPONENT_NAMES_VECTOR	= "xyzw";
const std::string GEN_COMPONENT_NAMES_COLOR		= "rgba";
const std::string GEN_OPERATORS_ARITHMETIC		= "+-*/";

const std::string GEN_OPERATORS_INCREMENT[GEN_OP_INCREMENT_COUNT] = {
	"++",
	"--",
};

const std::string GEN_OPERATORS_RELATIONAL[GEN_OP_RELATIONAL_COUNT] = {
	"<",
	"<=",
	">",
	">=",
};

const std::string GEN_OPERATORS_BITWISE[GEN_OP_BITWISE_COUNT] = {
	"&",
	"|",
	"^",
	"~",
	"<<",
	">>"
};

inline std::string	Gen_GetTypeString( const genType_t type );
inline std::string	Gen_GetMemberTypeString( const genType_t type );
inline std::string	Gen_GetFullTypeName( const genType_t type, const uint32_t numRows, const uint32_t numCols );

inline std::string	Gen_GetDefaultLiteralValue( const genType_t type );
inline std::string	Gen_GetNumericLiteral( const genType_t type, const float value );

inline genType_t	Gen_GetSupportedFloatingPointType( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? GEN_TYPE_DOUBLE : GEN_TYPE_FLOAT; }
inline bool			Gen_IsFloatingPointType( const genType_t type ) { return type == GEN_TYPE_FLOAT || type == GEN_TYPE_DOUBLE; }

// built in functions
inline std::string	Gen_GetFuncNameSin( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "sin" : "sinf"; }
inline std::string	Gen_GetFuncNameCos( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "cos" : "cosf"; }
inline std::string	Gen_GetFuncNameAcos( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "acos" : "acosf"; }
inline std::string	Gen_GetFuncNameTan( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "tan" : "tanf"; }
inline std::string	Gen_GetFuncNameSqrt( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "sqrt" : "sqrtf"; }

// hlml functions
inline std::string	Gen_GetFuncNameFloateq( const genType_t type ) { return ( type == GEN_TYPE_DOUBLE ) ? "doubleeq" : "floateq"; }

// functions that are guaranteed to be the same across vectors and matrices
extern void			Gen_OperatorsIncrement( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );
extern void			Gen_OperatorsRelational( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );
extern void			Gen_OperatorsBitwise( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );

extern void			Gen_OperatorComponentWiseArithmeticScalar( const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpArithmetic_t op,
						std::string& outHeader, std::string& outInl );
extern void			Gen_OperatorComponentWiseArithmeticRhsType( const genType_t type, const uint32_t numRows, const uint32_t numCols, const genOpArithmetic_t op,
						std::string& outHeader, std::string& outInl );

extern void			Gen_OperatorNotEquals( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );

std::string Gen_GetTypeString( const genType_t type ) {
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

std::string Gen_GetMemberTypeString( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_BOOL:		return "bool";
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

std::string Gen_GetFullTypeName( const genType_t type, const uint32_t numRows, const uint32_t numCols ) {
	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( numRows == 1 ) {
		return Gen_GetTypeString( type ) + std::to_string( numCols );
	} else {
		return Gen_GetTypeString( type ) + std::to_string( numRows ) + "x" + std::to_string( numCols );
	}
}

std::string Gen_GetDefaultLiteralValue( const genType_t type ) {
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

std::string Gen_GetNumericLiteral( const genType_t type, const float value ) {
	switch ( type ) {
		case GEN_TYPE_BOOL:		return ( value != 0.0f ) ? "true" : "false";
		case GEN_TYPE_INT:		return std::to_string( static_cast<int32_t>( value ) );
		case GEN_TYPE_UINT:		return std::to_string( static_cast<uint32_t>( value ) );
		case GEN_TYPE_FLOAT:	return std::to_string( static_cast<float>( value ) ) + "f";
		case GEN_TYPE_DOUBLE:	return std::to_string( static_cast<double>( value ) );

		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad type_t passed through to %s.  Fix it!\n", __FUNCTION__ );
			return "ERROR";
	}
}