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
#include "gen_cpp.h"

#include "defines.h"

#include "gen_scalar_cpp.h"
#include "gen_vector_cpp.h"
#include "gen_matrix_cpp.h"

#include "gen_common.h"
#include "gen_common_sse.h"

#include "gen_doc_common.h"
#include "gen_doc_matrix.h"

#include "gen_funcs_vector.h"
#include "gen_funcs_vector_sse.h"
#include "gen_funcs_matrix.h"
#include "gen_funcs_matrix_sse.h"

#include "allocator.h"
#include "string_builder.h"
#include "file_io.h"
#include "timer.h"

static void GenerateVectorOperatorComponentWiseArithmeticScalar( const genType_t type, const u32 numComponents, const genOpArithmetic_t op, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char opStr = GEN_OPERATORS_ARITHMETIC[op];

	// main arithmetic func
	Doc_ComponentWiseArithmeticRhsType( sbFwdDec, fullTypeName, fullTypeName, op );
	String_Appendf( sbFwdDec, "inline %s operator%c( const %s& lhs, const %s scalar );\n", fullTypeName, opStr, fullTypeName, memberTypeString );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "%s operator%c( const %s& lhs, const %s scalar )\n", fullTypeName, opStr, fullTypeName, memberTypeString );
	String_Append(  sbImpl, "{\n" );
	String_Appendf( sbImpl, "\treturn %s(\n", fullTypeName );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbImpl, "\t\tlhs[%d] %c scalar", i, opStr, i );

		if ( i != numComponents - 1 ) {
			String_Append( sbImpl, "," );
		}

		String_Append( sbImpl, "\n" );
	}
	String_Append( sbImpl, "\t);\n" );
	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );

	// compound arithmetic func
	Doc_OperatorCompoundComponentWiseArithmeticRhsType( sbFwdDec, fullTypeName, fullTypeName, op );
	String_Appendf( sbFwdDec, "inline %s operator%c=( %s& lhs, const %s scalar );\n", fullTypeName, opStr, fullTypeName, memberTypeString );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "%s operator%c=( %s& lhs, const %s scalar )\n", fullTypeName, opStr, fullTypeName, memberTypeString );
	String_Append(  sbImpl, "{\n" );
	String_Appendf( sbImpl, "\treturn ( lhs = lhs %c scalar );\n", opStr );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );
}

static void GenerateVectorOperatorComponentWiseArithmeticRhsType( const genType_t type, const u32 numComponents, const genOpArithmetic_t op, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( GEN_LANGUAGE_CPP, type, 1, numComponents, parmTypeName );

	char opStr = GEN_OPERATORS_ARITHMETIC[op];

	// main arithmetic func
	Doc_ComponentWiseArithmeticRhsType( sbFwdDec, fullTypeName, fullTypeName, op );
	String_Appendf( sbFwdDec, "inline %s operator%c( const %s lhs, const %s rhs );\n", fullTypeName, opStr, parmTypeName, parmTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "%s operator%c( const %s lhs, const %s rhs )\n", fullTypeName, opStr, parmTypeName, parmTypeName );
	String_Append(  sbImpl, "{\n" );
	Gen_VectorGetCodeComponentWiseArithmeticRhsType( GEN_LANGUAGE_CPP, type, numComponents, op, sbImpl );
	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );

	// compound arithmetic func
	Doc_OperatorCompoundComponentWiseArithmeticRhsType( sbFwdDec, fullTypeName, fullTypeName, op );
	String_Appendf( sbFwdDec, "inline %s operator%c=( %s& lhs, const %s rhs );\n", fullTypeName, opStr, parmTypeName, parmTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "%s operator%c=( %s& lhs, const %s rhs )\n", fullTypeName, opStr, parmTypeName, parmTypeName );
	String_Append(  sbImpl, "{\n" );
	String_Appendf( sbImpl, "\treturn ( lhs = lhs %c rhs );\n", opStr );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );
}

static void GenerateVectorOperatorsArithmetic( const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	for ( u32 opIndex = 0; opIndex < GEN_OP_ARITHMETIC_COUNT; opIndex++ ) {
		const genOpArithmetic_t op = (genOpArithmetic_t) opIndex;

		GenerateVectorOperatorComponentWiseArithmeticScalar( type, numComponents, op, sbFwdDec, sbImpl );
		GenerateVectorOperatorComponentWiseArithmeticRhsType( type, numComponents, op, sbFwdDec, sbImpl );
	}
}

static void GenerateVectorOperatorsBitwise( const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	if ( !Gen_TypeIsInteger( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	// do all except unary in order
	// unary requires separate parm lists etc. so handle it separately
	genOpBitwise_t ops[GEN_OP_BITWISE_COUNT - 1] = {
		GEN_OP_BITWISE_AND,
		GEN_OP_BITWISE_OR,
		GEN_OP_BITWISE_XOR,
		GEN_OP_BITWISE_SHIFT_LEFT,
		GEN_OP_BITWISE_SHIFT_RIGHT
	};

	genOpBitwise_t op;
	const char* opStr = NULL;

	for ( u32 opIndex = 0; opIndex < _countof( ops ); opIndex++ ) {
		op = (genOpBitwise_t) ops[opIndex];

		opStr = GEN_OPERATORS_BITWISE[op];

		// main bitwise operator
		Doc_OperatorBitwiseRhsType( sbFwdDec, fullTypeName, op );
		String_Appendf( sbFwdDec, "inline %s operator%s( const %s& lhs, const %s& rhs );\n", fullTypeName, opStr, fullTypeName, fullTypeName );
		String_Append(  sbFwdDec, "\n" );

		String_Appendf( sbImpl, "%s operator%s( const %s& lhs, const %s& rhs )\n", fullTypeName, opStr, fullTypeName, fullTypeName );
		String_Append(  sbImpl, "{\n" );
		Gen_VectorGetCodeComponentWiseBitwise( GEN_LANGUAGE_CPP, type, numComponents, op, sbImpl );
		String_Append(  sbImpl, "}\n" );
		String_Append(  sbImpl, "\n" );

		// compound bitwise operator
		Doc_OperatorCompoundBitwiseRhsType( sbFwdDec, fullTypeName, op );
		String_Appendf( sbFwdDec, "inline %s operator%s=( %s& lhs, const %s& rhs );\n", fullTypeName, opStr, fullTypeName, fullTypeName );
		String_Append(  sbFwdDec, "\n" );

		String_Appendf( sbImpl, "%s operator%s=( %s& lhs, const %s& rhs )\n", fullTypeName, opStr, fullTypeName, fullTypeName );
		String_Append(  sbImpl, "{\n" );
		String_Appendf( sbImpl, "\treturn ( lhs = lhs %s rhs );\n", opStr );
		String_Append(  sbImpl, "}\n" );
		String_Append(  sbImpl, "\n" );
	}

	// do unary separately
	// unary has no compound operator
	op = GEN_OP_BITWISE_UNARY;
	opStr = GEN_OPERATORS_BITWISE[op];

	Doc_OperatorBitwiseUnary( sbFwdDec, fullTypeName );
	String_Appendf( sbFwdDec, "inline %s operator%s( const %s& lhs );\n", fullTypeName, opStr, fullTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "%s operator%s( const %s& lhs )\n", fullTypeName, opStr, fullTypeName );
	String_Append(  sbImpl, "{\n" );
	Gen_VectorGetCodeComponentWiseBitwise( GEN_LANGUAGE_CPP, type, numComponents, op, sbImpl );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );
}

static void GenerateVectorOperatorsRelational( const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char boolTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( GEN_TYPE_BOOL, 1, numComponents, boolTypeName );

	for ( u32 opIndex = 0; opIndex < GEN_OP_RELATIONAL_COUNT; opIndex++ ) {
		const genOpRelational_t op = (genOpRelational_t) opIndex;

		const char* opStr = GEN_OPERATORS_RELATIONAL[op];

		Doc_ComponentWiseRelational( sbFwdDec, fullTypeName, 1, numComponents, op );
		String_Appendf( sbFwdDec, "inline %s operator%s( %s& lhs, const %s& rhs );\n", boolTypeName, opStr, fullTypeName, fullTypeName );
		String_Append(  sbFwdDec, "\n" );

		String_Appendf( sbImpl, "%s operator%s( %s& lhs, const %s& rhs )\n", boolTypeName, opStr, fullTypeName, fullTypeName );
		String_Append(  sbImpl, "{\n" );
		Gen_VectorGetCodeComponentWiseRelational( GEN_LANGUAGE_CPP, numComponents, op, sbImpl );
		String_Append(  sbImpl, "}\n" );
		String_Append(  sbImpl, "\n" );
	}
}

static void GenerateMatrixOperatorComponentWiseArithmeticScalar( const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char opStr = GEN_OPERATORS_ARITHMETIC[op];

	Doc_ComponentWiseArithmeticScalar( sbFwdDec, fullTypeName, op );
	String_Appendf( sbFwdDec, "inline %s operator%c( const %s& lhs, const %s scalar );\n", fullTypeName, opStr, fullTypeName, memberTypeString );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "%s operator%c( const %s& lhs, const %s scalar )\n", fullTypeName, opStr, fullTypeName, memberTypeString );
	String_Append(  sbImpl, "{\n" );
	Gen_MatrixGetCodeComponentWiseArithmeticScalar( GEN_LANGUAGE_CPP, type, numRows, numCols, op, sbImpl );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );
}

static void GenerateMatrixOperatorComponentWiseArithmeticRhsType( const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char opStr = GEN_OPERATORS_ARITHMETIC[op];

	Doc_ComponentWiseArithmeticRhsType( sbFwdDec, fullTypeName, fullTypeName, op );
	String_Appendf( sbFwdDec, "inline %s operator%c( const %s& lhs, const %s& rhs );\n", fullTypeName, opStr, fullTypeName, fullTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "%s operator%c( const %s& lhs, const %s& rhs )\n", fullTypeName, opStr, fullTypeName, fullTypeName );
	String_Append(  sbImpl, "{\n" );
	Gen_MatrixGetCodeComponentWiseArithmeticRhsType( GEN_LANGUAGE_CPP, type, numRows, numCols, op, sbImpl );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );
}

static void GenerateMatrixOperatorsArithmetic( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	GenerateMatrixOperatorComponentWiseArithmeticScalar( type, numRows, numCols, GEN_OP_ARITHMETIC_ADD, sbFwdDec, sbImpl );
	GenerateMatrixOperatorComponentWiseArithmeticRhsType( type, numRows, numCols, GEN_OP_ARITHMETIC_ADD, sbFwdDec, sbImpl );

	GenerateMatrixOperatorComponentWiseArithmeticScalar( type, numRows, numCols, GEN_OP_ARITHMETIC_SUB, sbFwdDec, sbImpl );
	GenerateMatrixOperatorComponentWiseArithmeticRhsType( type, numRows, numCols, GEN_OP_ARITHMETIC_SUB, sbFwdDec, sbImpl );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	{
		char rhsTypeName[GEN_STRING_LENGTH_TYPE_NAME];
		Gen_GetFullTypeName( type, numCols, numRows, rhsTypeName );

		char returnTypeName[GEN_STRING_LENGTH_TYPE_NAME];
		Gen_GetFullTypeName( type, numRows, numRows, returnTypeName );

		Doc_MatrixMultiplication( sbFwdDec, fullTypeName );
		String_Appendf( sbFwdDec, "inline %s operator*( const %s& lhs, const %s& rhs );\n", returnTypeName, fullTypeName, rhsTypeName );
		String_Append(  sbFwdDec, "\n" );

		String_Appendf( sbImpl, "%s operator*( const %s& lhs, const %s& rhs )\n", returnTypeName, fullTypeName, rhsTypeName );
		String_Append(  sbImpl, "{\n" );
		Gen_MatrixGetCodeMultiply( GEN_LANGUAGE_CPP, type, numRows, numCols, sbImpl );
		String_Append(  sbImpl, "}\n" );
		String_Append(  sbImpl, "\n" );

		// compound operator
		if ( numRows == numCols ) {
			String_Appendf( sbFwdDec, "inline %s operator*=( %s& lhs, const %s& rhs );\n", returnTypeName, fullTypeName, rhsTypeName );
			String_Append(  sbFwdDec, "\n" );

			String_Appendf( sbImpl, "%s operator*=( %s& lhs, const %s& rhs )\n", returnTypeName, fullTypeName, rhsTypeName );
			String_Append(  sbImpl, "{\n" );
			String_Append(  sbImpl, "\treturn ( lhs = lhs * rhs );\n" );
			String_Append(  sbImpl, "}\n" );
			String_Append(  sbImpl, "\n" );
		}
	}

	// vector 'division' (multiply by inverse)
	// TODO(DM): pseudo-inverse
	const bool32 isSquare = numRows == numCols;
	if ( isSquare && Gen_TypeIsFloatingPoint( type ) ) {
		char inverseFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_GetFuncNameInverse( GEN_LANGUAGE_CPP, type, numRows, numCols, inverseFuncStr );

		// main operator
		Doc_MatrixDivision( sbFwdDec, fullTypeName );
		String_Appendf( sbFwdDec, "inline %s operator/( const %s& lhs, const %s& rhs );\n", fullTypeName, fullTypeName, fullTypeName );
		String_Append(  sbFwdDec, "\n" );

		Doc_MatrixDivision( sbImpl, fullTypeName );
		String_Appendf( sbImpl, "inline %s operator/( const %s& lhs, const %s& rhs )\n", fullTypeName, fullTypeName, fullTypeName );
		String_Append(  sbImpl, "{\n" );
		String_Appendf( sbImpl, "\treturn lhs * %s( rhs );\n", inverseFuncStr );
		String_Append(  sbImpl, "}\n" );
		String_Append(  sbImpl, "\n" );

		// compound operator
		Doc_MatrixDivisionCompound( sbFwdDec, fullTypeName );
		String_Appendf( sbFwdDec, "inline %s operator/=( %s& lhs, const %s& rhs );\n", fullTypeName, fullTypeName, fullTypeName );
		String_Append(  sbFwdDec, "\n" );

		String_Appendf( sbImpl, "%s operator/=( %s& lhs, const %s& rhs )\n", fullTypeName, fullTypeName, fullTypeName );
		String_Append(  sbImpl, "{\n" );
		String_Append(  sbImpl, "\treturn ( lhs = lhs / rhs );\n" );
		String_Append(  sbImpl, "}\n" );
		String_Append(  sbImpl, "\n" );
	} else {
		GenerateMatrixOperatorComponentWiseArithmeticScalar( type, numRows, numCols, GEN_OP_ARITHMETIC_DIV, sbFwdDec, sbImpl );
		GenerateMatrixOperatorComponentWiseArithmeticRhsType( type, numRows, numCols, GEN_OP_ARITHMETIC_DIV, sbFwdDec, sbImpl );
	}

	// multiply-vector operator overload
	// supported only for square matrices
	if ( isSquare ) {
		char vectorTypeName[GEN_STRING_LENGTH_TYPE_NAME];
		Gen_GetFullTypeName( type, 1, numCols, vectorTypeName );

		// main arithmetic operator
		Doc_ComponentWiseArithmeticRhsType( sbFwdDec, vectorTypeName, fullTypeName, GEN_OP_ARITHMETIC_MUL );
		String_Appendf( sbFwdDec, "inline %s operator*( const %s& lhs, const %s& rhs );\n", vectorTypeName, fullTypeName, vectorTypeName );
		String_Append(  sbFwdDec, "\n" );

		String_Appendf( sbImpl, "%s operator*( const %s& lhs, const %s& rhs )\n", vectorTypeName, fullTypeName, vectorTypeName );
		String_Append(  sbImpl, "{\n" );
		Gen_MatrixGetCodeMultiplyVector( GEN_LANGUAGE_CPP, type, numRows, numCols, sbImpl );
		String_Append(  sbImpl, "}\n" );
		String_Append(  sbImpl, "\n" );

		// compound arithmetic operator
		Doc_OperatorCompoundComponentWiseArithmeticRhsType( sbFwdDec, vectorTypeName, fullTypeName, GEN_OP_ARITHMETIC_MUL );
		String_Appendf( sbFwdDec, "inline %s operator*=( %s& lhs, const %s& rhs );\n", vectorTypeName, vectorTypeName, fullTypeName );
		String_Append(  sbFwdDec, "\n" );

		String_Appendf( sbImpl, "%s operator*=( %s& lhs, const %s& rhs )\n", vectorTypeName, vectorTypeName, fullTypeName );
		String_Append(  sbImpl, "{\n" );
		String_Append(  sbImpl, "\treturn ( lhs = rhs * lhs );\n" );
		String_Append(  sbImpl, "}\n" );
		String_Append(  sbImpl, "\n" );
	}
}

static void GenerateMatrixOperatorsBitwise( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	if ( !Gen_TypeIsInteger( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	// do all except unary in order
	// unary requires separate parm lists etc. so handle it separately
	genOpBitwise_t ops[GEN_OP_BITWISE_COUNT - 1] = {
		GEN_OP_BITWISE_AND,
		GEN_OP_BITWISE_OR,
		GEN_OP_BITWISE_XOR,
		GEN_OP_BITWISE_SHIFT_LEFT,
		GEN_OP_BITWISE_SHIFT_RIGHT
	};

	genOpBitwise_t op;
	const char* opStr = NULL;

	for ( u32 i = 0; i < _countof( ops ); i++ ) {
		op = ops[i];
		opStr = GEN_OPERATORS_BITWISE[op];

		// main bitwise operator
		Doc_OperatorBitwiseRhsType( sbFwdDec, fullTypeName, op );
		String_Appendf( sbFwdDec, "inline %s operator%s( %s& lhs, const %s& rhs );\n", fullTypeName, opStr, fullTypeName, fullTypeName );
		String_Append(  sbFwdDec, "\n" );

		String_Appendf( sbImpl, "%s operator%s( %s& lhs, const %s& rhs )\n", fullTypeName, opStr, fullTypeName, fullTypeName );
		String_Append(  sbImpl, "{\n" );
		Gen_MatrixGetCodeComponentWiseBitwise( GEN_LANGUAGE_CPP, type, numRows, numCols, op, sbImpl );
		String_Append(  sbImpl, "}\n" );
		String_Append(  sbImpl, "\n" );

		// compound bitwise operator
		Doc_OperatorCompoundBitwiseRhsType( sbFwdDec, fullTypeName, op );
		String_Appendf( sbFwdDec, "inline %s operator%s=( %s& lhs, const %s& rhs );\n", fullTypeName, opStr, fullTypeName, fullTypeName );
		String_Append(  sbFwdDec, "\n" );

		String_Appendf( sbImpl, "%s operator%s=( %s& lhs, const %s& rhs )\n", fullTypeName, opStr, fullTypeName, fullTypeName );
		String_Append(  sbImpl, "{\n" );
		String_Appendf( sbImpl, "\treturn ( lhs = lhs %s rhs );\n", opStr );
		String_Append(  sbImpl, "}\n" );
		String_Append(  sbImpl, "\n" );
	}

	// do unary separately
	// unary has no compound operator
	op = GEN_OP_BITWISE_UNARY;
	opStr = GEN_OPERATORS_BITWISE[op];

	Doc_OperatorBitwiseUnary( sbFwdDec, fullTypeName );
	String_Appendf( sbFwdDec, "inline %s operator%s( %s& lhs );\n", fullTypeName, opStr, fullTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "%s operator%s( %s& lhs )\n", fullTypeName, opStr, fullTypeName );
	String_Append(  sbImpl, "{\n" );
	Gen_MatrixGetCodeComponentWiseBitwise( GEN_LANGUAGE_CPP, type, numRows, numCols, op, sbImpl );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );
}

static void GenerateMatrixOperatorsRelational( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( sbFwdDec );
	assert( sbImpl );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char boolTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( GEN_TYPE_BOOL, numRows, numCols, boolTypeName );

	for ( u32 opIndex = 0; opIndex < GEN_OP_RELATIONAL_COUNT; opIndex++ ) {
		const genOpRelational_t op = (genOpRelational_t) opIndex;

		const char* opStr = GEN_OPERATORS_RELATIONAL[op];

		// main relational operator
		Doc_ComponentWiseRelational( sbFwdDec, fullTypeName, numRows, numRows, op );
		String_Appendf( sbFwdDec, "inline %s operator%s( const %s& lhs, const %s& rhs );\n", boolTypeName, opStr, fullTypeName, fullTypeName );
		String_Append(  sbFwdDec, "\n" );

		String_Appendf( sbImpl, "%s operator%s( const %s& lhs, const %s& rhs )\n", boolTypeName, opStr, fullTypeName, fullTypeName );
		String_Append(  sbImpl, "{\n" );
		Gen_MatrixGetCodeComponentWiseRelational( GEN_LANGUAGE_CPP, type, numRows, numCols, op, sbImpl );
		String_Append(  sbImpl, "}\n" );
		String_Append(  sbImpl, "\n" );
	}
}


void Gen_Vectors_CPP( void ) {
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			printf( "Generating %s%d...", typeString, componentIndex );

			Gen_VectorType_CPP( type, componentIndex );

			printf( "OK.\n" );
		}
	}
}

void Gen_Matrices_CPP( void ) {
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( u32 col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				printf( "Generating %s%dx%d...", typeString, row, col );

				Gen_MatrixType_CPP( type, row, col );

				printf( "OK.\n" );
			}
		}
	}
}

void Gen_OperatorsVector( void ) {
	char filePathHeader[64] = { 0 };
	snprintf( filePathHeader, 64, "%s%s.h", GEN_FOLDER_PATHS_OUT_GEN[GEN_LANGUAGE_CPP], GEN_FILENAME_OPERATORS_VECTOR );

	stringBuilder_t contentFwdDec = String_Create( 128 * KB_TO_BYTES );
	stringBuilder_t contentImpl = String_Create( 128 * KB_TO_BYTES );

	stringBuilder_t content = String_Create( contentFwdDec.alloc + contentImpl.alloc );

	String_Append( &contentFwdDec, GEN_FILE_HEADER );
	String_Append( &contentFwdDec,
		"#pragma once\n"
		"\n"
	);

	// includes
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			String_Appendf( &contentFwdDec, "#include \"%s%d.h\"\n", typeString, componentIndex );
		}

		String_Append( &contentFwdDec, "\n" );
	}

	String_Append( &contentFwdDec, "#include \"" GEN_FILENAME_FUNCTIONS_VECTOR ".h\"\n" );
	String_Append( &contentFwdDec, "\n" );

	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		for ( u32 componentIndex = GEN_COMPONENT_COUNT_MIN; componentIndex <= GEN_COMPONENT_COUNT_MAX; componentIndex++ ) {
			char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
			Gen_GetFullTypeName( type, 1, componentIndex, fullTypeName );

			printf( "Vector operators %s...", fullTypeName );

			String_Appendf( &contentFwdDec, "// %s\n", fullTypeName );

			Gen_OperatorsEquality( type, 1, componentIndex, &contentFwdDec, &contentImpl );

			GenerateVectorOperatorsArithmetic( type, componentIndex, &contentFwdDec, &contentImpl );
			Gen_OperatorsIncrement( type, 1, componentIndex, &contentFwdDec, &contentImpl );
			GenerateVectorOperatorsBitwise( type, componentIndex, &contentFwdDec, &contentImpl );
			GenerateVectorOperatorsRelational( type, componentIndex, &contentFwdDec, &contentImpl );

			String_Append( &contentFwdDec, "\n" );

			printf( "OK.\n" );
		}
	}

	String_Append( &content, contentFwdDec.str );
	String_Append( &content, contentImpl.str );

	FS_WriteEntireFile( filePathHeader, content.str, content.length );

	Mem_Reset();
}

void Gen_OperatorsMatrix( void ) {
	char filePathHeader[64];
	snprintf( filePathHeader, 64, "%s%s.h", GEN_FOLDER_PATHS_OUT_GEN[GEN_LANGUAGE_CPP], GEN_FILENAME_OPERATORS_MATRIX );

	stringBuilder_t contentFwdDec = String_Create( 512 * KB_TO_BYTES );
	stringBuilder_t contentImpl = String_Create( 512 * KB_TO_BYTES );

	stringBuilder_t content = String_Create( contentFwdDec.alloc + contentImpl.alloc );	

	String_Append( &contentFwdDec, GEN_FILE_HEADER );
	String_Append( &contentFwdDec, "#pragma once\n" );
	String_Append( &contentFwdDec, "\n" );

	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		const char* typeString = Gen_GetTypeString( type );

		for ( u32 row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( u32 col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				String_Appendf( &contentFwdDec, "#include \"%s%dx%d.h\"\n", typeString, row, col );
			}
		}

		String_Append( &contentFwdDec, "\n" );
	}

	String_Append( &contentFwdDec, "#include \"" GEN_FILENAME_FUNCTIONS_VECTOR ".h\"\n" );
	String_Append( &contentFwdDec, "#include \"" GEN_FILENAME_FUNCTIONS_MATRIX ".h\"\n" );
	String_Append( &contentFwdDec, "\n" );

	// header and inl code
	for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
		genType_t type = (genType_t) typeIndex;

		for ( u32 row = GEN_COMPONENT_COUNT_MIN; row <= GEN_COMPONENT_COUNT_MAX; row++ ) {
			for ( u32 col = GEN_COMPONENT_COUNT_MIN; col <= GEN_COMPONENT_COUNT_MAX; col++ ) {
				char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
				Gen_GetFullTypeName( type, row, col, fullTypeName );

				printf( "Matrix operators %s...", fullTypeName );

				String_Appendf( &contentFwdDec, "// %s\n", fullTypeName );

				Gen_OperatorsEquality( type, row, col, &contentFwdDec, &contentImpl );

				GenerateMatrixOperatorsArithmetic( type, row, col, &contentFwdDec, &contentImpl );
				Gen_OperatorsIncrement( type, row, col, &contentFwdDec, &contentImpl );
				GenerateMatrixOperatorsBitwise( type, row, col, &contentFwdDec, &contentImpl );
				GenerateMatrixOperatorsRelational( type, row, col, &contentFwdDec, &contentImpl );

				String_Append( &contentFwdDec, "\n" );

				printf( "OK.\n" );
			}
		}
	}

	String_Append( &content, contentFwdDec.str );
	String_Append( &content, contentImpl.str );

	FS_WriteEntireFile( filePathHeader, content.str, content.length );

	Mem_Reset();
}