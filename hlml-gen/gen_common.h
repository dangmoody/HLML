#pragma once

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdint.h>
#include <string>

#define BIT( x )					1ULL << x	// TODO(DM): move this somewhere more generic?

#ifndef _countof
#define _countof( x )				( sizeof( (x) ) / sizeof( (x)[0] ) )
#endif

#define UNUSED( x )					( (void) (x) )

#define GEN_COMPONENT_COUNT_MIN		2
#define GEN_COMPONENT_COUNT_MAX		4

#define GEN_OUT_FOLDER_PATH			"out/gen/"
#define GEN_TESTS_FOLDER_PATH		"hlml-gen-test/"

#define GEN_HEADER_MAIN				"hlml_main.h"
#define GEN_HEADER_USER				"hlml_user.h"

#define GEN_HEADER_VECTOR			"hlml_vector.h"
#define GEN_HEADER_MATRIX			"hlml_matrix.h"

#define GEN_HEADER_FUNCTIONS_VECTOR	"hlml_functions_vector"
#define GEN_HEADER_FUNCTIONS_MATRIX	"hlml_functions_matrix"

#define GEN_TEST_SUITES_HEADER		"suites.h"

enum genType_t {
	GEN_TYPE_BOOL					= 0,
	GEN_TYPE_INT,
	GEN_TYPE_UINT,
	GEN_TYPE_FLOAT,
	GEN_TYPE_DOUBLE,

	GEN_TYPE_COUNT,
};

enum genFlagBits_t {
	GEN_FLAGS_BIT_NONE				= 0,

	GEN_FLAGS_BIT_COLOR				= BIT( 0 ),

	GEN_FLAGS_BIT_ARITHMETIC		= BIT( 1 ),
	GEN_FLAGS_BIT_ARRAY				= BIT( 2 ),
	GEN_FLAGS_BIT_EQUALITY			= BIT( 3 ),
	GEN_FLAGS_BIT_RELATIONAL		= BIT( 4 ),

	GEN_FLAGS_BIT_ALL				= UINT32_MAX
};
typedef uint32_t					genFlags_t;

enum hand_t {
	GEN_HAND_LEFT					= 0,
	GEN_HAND_RIGHT,

	GEN_HAND_COUNT
};


extern const std::string			GEN_COPYRIGHT_HEADER;

extern const std::string			GEN_GENERATED_WARNING;

extern const std::string			GEN_COMPONENT_NAMES_VECTOR;
extern const std::string			GEN_COMPONENT_NAMES_COLOR;
extern const std::string			GEN_OPERATORS_ARITHMETIC[4];
extern const std::string			GEN_OPERATORS_EQUALITY[4];

inline std::string					Gen_GetTypeString( const genType_t type );
inline std::string					Gen_GetMemberTypeString( const genType_t type );

inline std::string					Gen_GetDefaultLiteralValue( const genType_t type );
inline std::string					Gen_GetNumericLiteral( const genType_t type, const int32_t value );

inline genType_t					Gen_GetSupportedFloatingPointType( const genType_t type );
inline bool							Gen_IsFloatingPointType( const genType_t type );

extern void							Gen_VectorLength( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl );
extern void							Gen_VectorNormalize( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl );
extern void							Gen_VectorDot( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl );
extern void							Gen_VectorCross( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl );
extern void							Gen_VectorAngle( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl );

extern void							Gen_MatrixIdentity( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );
extern void							Gen_MatrixTranspose( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );
extern void							Gen_MatrixInverse( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );
extern void							Gen_MatrixDeterminant( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );

extern void							Gen_MatrixTranslate( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );
extern void							Gen_MatrixRotate( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );
extern void							Gen_MatrixScale( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );

extern void							Gen_MatrixOrtho( const hand_t hand, const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );
extern void							Gen_MatrixPerspective( const hand_t hand, const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );
extern void							Gen_MatrixLookAt( const hand_t hand, const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );


std::string Gen_GetTypeString( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_BOOL:		return "bool";
		case GEN_TYPE_INT:		return "int";
		case GEN_TYPE_UINT:		return "uint";
		case GEN_TYPE_FLOAT:	return "float";
		case GEN_TYPE_DOUBLE:	return "double";

		default:
			printf( "Bad genType_t specified when calling %s.\n", __FUNCTION__ );
			return std::string();
	}
}

std::string Gen_GetMemberTypeString( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_BOOL:		return "bool";
		case GEN_TYPE_INT:		return "int32_t";
		case GEN_TYPE_UINT:		return "uint32_t";
		case GEN_TYPE_FLOAT:	return "float";
		case GEN_TYPE_DOUBLE:	return "double";

		default:
			printf( "Bad genType_t specified when calling %s.\n", __FUNCTION__ );
			return std::string();
	}
}

std::string Gen_GetDefaultLiteralValue( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_BOOL:		return "false";
		case GEN_TYPE_INT:		return "0";
		case GEN_TYPE_UINT:		return "0";
		case GEN_TYPE_FLOAT:	return "0.0f";
		case GEN_TYPE_DOUBLE:	return "0.0";

		default:
			printf( "ERROR: Bad type_t passed through to %s.  Fix it!\n", __FUNCTION__ );
			return "?????";
	}
}

std::string Gen_GetNumericLiteral( const genType_t type, const int32_t value ) {
	switch ( type ) {
		case GEN_TYPE_BOOL:		return ( value != 0 ) ? "true" : "false";
		case GEN_TYPE_INT:		return std::to_string( value );
		case GEN_TYPE_UINT:		return std::to_string( value );
		case GEN_TYPE_FLOAT:	return std::to_string( value ) + ".0f";
		case GEN_TYPE_DOUBLE:	return std::to_string( value ) + ".0";

		default:
			printf( "ERROR: Bad type_t passed through to %s.  Fix it!\n", __FUNCTION__ );
			return "?????";
	}
}

genType_t Gen_GetSupportedFloatingPointType( const genType_t type ) {
	return ( type == GEN_TYPE_DOUBLE ) ? GEN_TYPE_DOUBLE : GEN_TYPE_FLOAT;
}

bool Gen_IsFloatingPointType( const genType_t type ) {
	return type == GEN_TYPE_FLOAT || type == GEN_TYPE_DOUBLE;
}