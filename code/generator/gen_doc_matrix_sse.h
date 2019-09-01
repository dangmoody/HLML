#pragma once

#include "gen_common.h"
#include "string_builder.h"

inline void Doc_SSE_MatrixIdentity( stringBuilder_t* sb, const char* fullTypeName, const char* registerName ) {
	assert( fullTypeName );

	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Sets a matrix of %s registers to identity.\n", fullTypeName, registerName
	);
}

inline void Doc_SSE_MatrixTranspose( stringBuilder_t* sb, const char* fullTypeName, const u32 numRows, const u32 numCols, const char* registerName ) {
	assert( fullTypeName );

	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Stores a transposed matrix of %d x %d %s registers in the output given the input %d x %d register matrix.\n", fullTypeName, numCols, numRows, registerName, numRows, numCols
	);
}

inline void Doc_SSE_MatrixArithmeticComponentWise( stringBuilder_t* sb, const char* fullTypeName, const char* registerName, const genOpArithmetic_t op ) {
	assert( fullTypeName );

	const char* verb = NULL;
	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD:
			verb = "addition";
			break;

		case GEN_OP_ARITHMETIC_SUB:
			verb = "subtraction";
			break;

		case GEN_OP_ARITHMETIC_MUL:
			verb = "multiplication";
			break;

		case GEN_OP_ARITHMETIC_DIV:
			verb = "division";
			break;

		case GEN_OP_ARITHMETIC_COUNT:
		default:
			printf( "ERROR: Bad genOpArtihmetic_t passed into %s.\n", __FUNCTION__ );
			verb = "ERROR";
			break;
	}

	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Stores a matrix that is the result of the component-wise %s between the lhs and rhs %s registers of the input.\n", fullTypeName, verb, registerName
	);
}

inline void Doc_SSE_MatrixTranslate( stringBuilder_t* sb, const char* fullTypeName, const char* registerName ) {
	assert( fullTypeName );

	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Stores a last matrix column that has been translated by the given %s register vector in the input.\n", fullTypeName, registerName
	);
}

inline void Doc_SSE_MatrixScale( stringBuilder_t* sb, const char* fullTypeName ) {
	assert( fullTypeName );

	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Stores an array of %s diagonals that have been scaled by the given vector in the input.\n", fullTypeName, fullTypeName
	);
}