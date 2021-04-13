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

#include "gen_common.h"
#include "string_builder.h"

inline void Doc_SSE_MatrixIdentity( stringBuilder_t* sb, const char* registerName ) {
	String_Appendf( sb,
		"// Sets a matrix of %s registers to identity.\n", registerName
	);
}

inline void Doc_SSE_MatrixTranspose( stringBuilder_t* sb, const u32 numRows, const u32 numCols, const char* registerName ) {
	assert( sb );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( registerName );

	String_Appendf( sb,
		"// Stores a transposed matrix of %d x %d %s registers in the output given the input %d x %d register matrix.\n", numCols, numRows, registerName, numRows, numCols
	);
}

inline void Doc_SSE_MatrixInverse( stringBuilder_t* sb, const u32 numRows, const u32 numCols, const char* registerName ) {
	assert( sb );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( registerName );

	String_Appendf( sb,
		"// Stores an inverted matrix of %d x %d %s registers.\n", numRows, numCols, registerName
	);
}

inline void Doc_SSE_MatrixDeterminant( stringBuilder_t* sb, const u32 numRows, const u32 numCols, const char* registerName ) {
	assert( sb );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( registerName );

	String_Appendf( sb,
		"// Stores the determinants of a matrix of %d x %d %s registers.\n", numRows, numCols, registerName
	);
}

inline void Doc_SSE_MatrixArithmeticComponentWise( stringBuilder_t* sb, const char* registerName, const genOpArithmetic_t op ) {
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
		"// Stores a matrix that is the result of the component-wise %s between the lhs and rhs %s registers of the input.\n", verb, registerName
	);
}

inline void Doc_SSE_MatrixTranslate( stringBuilder_t* sb, const char* registerName ) {
	String_Appendf( sb,
		"// Stores a last matrix column that has been translated by the given %s register vector in the input.\n", registerName
	);
}

inline void Doc_SSE_MatrixScale( stringBuilder_t* sb, const char* fullTypeName ) {
	assert( fullTypeName );

	String_Appendf( sb,
		"// Stores an array of %s diagonals that have been scaled by the given vector in the input.\n", fullTypeName
	);
}

inline void Doc_SSE_MatrixMul( stringBuilder_t* sb, const char* registerName ) {
	String_Appendf( sb,
		"// Performs a matrix-multiplication of 2 matrices of %s registers.\n", registerName
	);
}