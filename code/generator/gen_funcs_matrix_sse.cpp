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
#include "gen_funcs_matrix_sse.h"

#include "gen_common_sse.h"

#include "gen_doc_matrix_sse.h"

#include "defines.h"

#include "string_builder.h"

void Gen_SSE_MatrixIdentity( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	const char* set1FuncStr = Gen_SSE_GetFuncStrSet1( type );

	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 0.0f, zeroStr, 1 );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1.0f, oneStr, 1 );

	Doc_SSE_MatrixIdentity( sbHeader, fullTypeName, registerName );
	String_Appendf( sbHeader, "inline void identity_sse( %s out_results[%d][%d] );\n", registerName, numRows, numCols );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void identity_sse( %s out_results[%d][%d] )\n", registerName, numRows, numCols );
	String_Append(  sbInl, "{\n" );
	for ( u32 row = 0; row < numRows; row++ ) {
		String_Appendf( sbInl, "\t// row %d\n", row );

		for ( u32 col = 0; col < numCols; col++ ) {
			const char* valueStr = ( row == col ) ? oneStr : zeroStr;

			String_Appendf( sbInl, "\tout_results[%d][%d] = %s( %s );\n", row, col, set1FuncStr, valueStr );
		}

		if ( row != numRows - 1 ) {
			String_Append( sbInl, "\n" );
		}
	}
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

void Gen_SSE_MatrixTranspose( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataName( fullTypeName, "transpose", inputDataName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	String_Appendf( sbHeader, "struct %s\n", inputDataName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s m[%d][%d];\n", registerName, numRows, numCols );
	String_Append(  sbHeader, "};\n" );
	String_Append(  sbHeader, "\n" );

	Doc_SSE_MatrixTranspose( sbHeader, fullTypeName, numRows, numCols, registerName );
	String_Appendf( sbHeader, "inline void transpose_sse( const %s* in, %s out_results[%d][%d] );\n", inputDataName, registerName, numCols, numRows );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void transpose_sse( const %s* in, %s out_results[%d][%d] )\n", inputDataName, registerName, numCols, numRows );
	String_Append(  sbInl, "{\n" );
	String_Append(  sbInl, "\tassert( in );\n" );
	String_Append(  sbInl, "\n" );
	for ( u32 row = 0; row < numRows; row++ ) {
		for ( u32 col = 0; col < numCols; col++ ) {
			String_Appendf( sbInl, "\tout_results[%d][%d] = in->m[%d][%d];\n", col, row, row, col );
		}

		if ( row != numRows - 1 ) {
			String_Append( sbInl, "\n" );
		}
	}
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

void Gen_SSE_MatrixInverse( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	if ( numRows != numCols ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char inputDataNameInverse[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataName( fullTypeName, "inverse", inputDataNameInverse );

	char inputDataNameDeterminant[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataName( fullTypeName, "determinant", inputDataNameDeterminant );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	const char* rcpFuncStr = Gen_SSE_GetFuncStrRcp( type );
	const char* xorFuncStr = Gen_SSE_GetFuncStrXor( type );

	char subFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	char mulFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];

	Gen_SSE_GetIntrinsicArithmeticStr( type, GEN_OP_ARITHMETIC_SUB, subFuncStr );
	Gen_SSE_GetIntrinsicArithmeticStr( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

	String_Appendf( sbHeader, "struct %s\n", inputDataNameInverse );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s m[%d][%d];\n", registerName, numRows, numCols );
	String_Append(  sbHeader, "};\n" );
	String_Append(  sbHeader, "\n" );

	Doc_SSE_MatrixInverse( sbHeader, fullTypeName, numRows, numCols, registerName );
	String_Appendf( sbHeader, "inline void inverse_sse( const %s* in, %s out_results[%d][%d] );\n", inputDataNameInverse, registerName, numRows, numCols );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void inverse_sse( const %s* in, %s out_results[%d][%d] )\n", inputDataNameInverse, registerName, numRows, numCols );
	String_Append(  sbInl, "{\n" );
	String_Append(  sbInl, "\tassert( in );\n" );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s in_det;\n", inputDataNameDeterminant );
	String_Append(  sbInl, "\tmemcpy( in_det.m, in->m, sizeof( in->m ) );\n" );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s determinants;\n", registerName );
	String_Append(  sbInl, "\tdeterminant_sse( &in_det, &determinants );\n" );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\tdeterminants = %s( determinants );\n", rcpFuncStr );
	String_Append(  sbInl, "\n" );
	switch ( numRows ) {
		case 2:
			/*
			 mat[1][1] * invdet, -mat[0][1] * invdet,
			-mat[1][0] * invdet,  mat[0][0] * invdet
			*/
			String_Appendf( sbInl, "\t%s neg0 = %s( in->m[0][1], HLML_ZERO_SSE );\n", registerName, xorFuncStr );
			String_Appendf( sbInl, "\t%s neg1 = %s( in->m[1][0], HLML_ZERO_SSE );\n", registerName, xorFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\tout_results[0][0] = %s( in->m[1][1], determinants );\n", mulFuncStr );
			String_Appendf( sbInl, "\tout_results[0][1] = %s( neg0, determinants );\n", mulFuncStr );
			String_Appendf( sbInl, "\tout_results[1][0] = %s( neg1, determinants );\n", mulFuncStr );
			String_Appendf( sbInl, "\tout_results[1][1] = %s( in->m[0][0], determinants );\n", mulFuncStr );
			break;

		case 3:
			/*
			 ( mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1] ) * invdet,
			-( mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1] ) * invdet,
			 ( mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1] ) * invdet,

			-( mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0] ) * invdet,
			 ( mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0] ) * invdet,
			-( mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0] ) * invdet,

			 ( mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0] ) * invdet,
			-( mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0] ) * invdet,
			 ( mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0] ) * invdet
			*/
			String_Append(  sbInl, "\t// row 0\n" );
			String_Appendf( sbInl, "\t%s mul00a = %s( in->m[1][1], in->m[2][2] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul00b = %s( in->m[1][2], in->m[2][1] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul01a = %s( in->m[0][1], in->m[2][2] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul01b = %s( in->m[0][2], in->m[2][1] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul02a = %s( in->m[0][1], in->m[1][2] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul02b = %s( in->m[0][2], in->m[1][1] );\n", registerName, mulFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s sub00 = %s( mul00a, mul00b );\n", registerName, subFuncStr );
			String_Appendf( sbInl, "\t%s sub01 = %s( mul01a, mul01b );\n", registerName, subFuncStr );
			String_Appendf( sbInl, "\t%s sub02 = %s( mul02a, mul02b );\n", registerName, subFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\tsub00 = %s( sub00, determinants );\n", mulFuncStr );
			String_Appendf( sbInl, "\tsub01 = %s( sub01, determinants );\n", mulFuncStr );
			String_Appendf( sbInl, "\tsub02 = %s( sub02, determinants );\n", mulFuncStr );
			String_Appendf( sbInl, "\tsub01 = %s( sub01, HLML_ZERO_SSE );\n", xorFuncStr );
			String_Append(  sbInl, "\n" );
			String_Append(  sbInl, "\t// row 1\n" );
			String_Appendf( sbInl, "\t%s mul10a = %s( in->m[1][0], in->m[2][2] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul10b = %s( in->m[1][2], in->m[2][0] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul11a = %s( in->m[0][0], in->m[2][2] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul11b = %s( in->m[0][2], in->m[2][0] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul12a = %s( in->m[0][0], in->m[1][2] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul12b = %s( in->m[0][2], in->m[1][0] );\n", registerName, mulFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s sub10 = %s( mul10a, mul10b );\n", registerName, subFuncStr );
			String_Appendf( sbInl, "\t%s sub11 = %s( mul11a, mul11b );\n", registerName, subFuncStr );
			String_Appendf( sbInl, "\t%s sub12 = %s( mul12a, mul12b );\n", registerName, subFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\tsub10 = %s( sub10, determinants );\n", mulFuncStr );
			String_Appendf( sbInl, "\tsub11 = %s( sub11, determinants );\n", mulFuncStr );
			String_Appendf( sbInl, "\tsub12 = %s( sub12, determinants );\n", mulFuncStr );
			String_Appendf( sbInl, "\tsub10 = %s( sub10, HLML_ZERO_SSE );\n", xorFuncStr );
			String_Appendf( sbInl, "\tsub12 = %s( sub12, HLML_ZERO_SSE );\n", xorFuncStr );
			String_Append(  sbInl, "\n" );
			String_Append(  sbInl, "\t// row 2\n" );
			String_Appendf( sbInl, "\t%s mul20a = %s( in->m[1][0], in->m[2][1] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul20b = %s( in->m[1][1], in->m[2][0] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul21a = %s( in->m[0][0], in->m[2][1] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul21b = %s( in->m[0][1], in->m[2][0] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul22a = %s( in->m[0][0], in->m[1][1] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul22b = %s( in->m[0][1], in->m[1][0] );\n", registerName, mulFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s sub20 = %s( mul20a, mul20b );\n", registerName, subFuncStr );
			String_Appendf( sbInl, "\t%s sub21 = %s( mul21a, mul21b );\n", registerName, subFuncStr );
			String_Appendf( sbInl, "\t%s sub22 = %s( mul22a, mul22b );\n", registerName, subFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\tsub20 = %s( sub20, determinants );\n", mulFuncStr );
			String_Appendf( sbInl, "\tsub21 = %s( sub21, determinants );\n", mulFuncStr );
			String_Appendf( sbInl, "\tsub22 = %s( sub22, determinants );\n", mulFuncStr );
			String_Appendf( sbInl, "\tsub21 = %s( sub21, HLML_ZERO_SSE );\n", xorFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\tout_results[0][0] = sub00;\n" );
			String_Appendf( sbInl, "\tout_results[0][1] = sub01;\n" );
			String_Appendf( sbInl, "\tout_results[0][2] = sub02;\n" );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\tout_results[1][0] = sub10;\n" );
			String_Appendf( sbInl, "\tout_results[1][1] = sub11;\n" );
			String_Appendf( sbInl, "\tout_results[1][2] = sub12;\n" );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\tout_results[2][0] = sub20;\n" );
			String_Appendf( sbInl, "\tout_results[2][1] = sub21;\n" );
			String_Appendf( sbInl, "\tout_results[2][2] = sub22;\n" );
			break;

		case 4:
			String_Append(  sbInl, "\t// TODO(DM): this\n" );
			String_Append(  sbInl, "\t( (void) out_results ); // unused\n" );
			break;
	}
	
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

void Gen_SSE_MatrixDeterminant( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	if ( numRows != numCols ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataName( fullTypeName, "determinant", inputDataName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	char addFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	char subFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	char mulFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];

	Gen_SSE_GetIntrinsicArithmeticStr( type, GEN_OP_ARITHMETIC_ADD, addFuncStr );
	Gen_SSE_GetIntrinsicArithmeticStr( type, GEN_OP_ARITHMETIC_SUB, subFuncStr );
	Gen_SSE_GetIntrinsicArithmeticStr( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

	String_Appendf( sbHeader, "struct %s\n", inputDataName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s m[%d][%d];\n", registerName, numRows, numCols );
	String_Append(  sbHeader, "};\n" );
	String_Append(  sbHeader, "\n" );

	Doc_SSE_MatrixDeterminant( sbHeader, fullTypeName, numRows, numCols, registerName );
	String_Appendf( sbHeader, "inline void determinant_sse( const %s* in, %s* out_result );\n", inputDataName, registerName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void determinant_sse( const %s* in, %s* out_result )\n", inputDataName, registerName );
	String_Append(  sbInl, "{\n" );
	String_Append(  sbInl, "\tassert( in );\n" );
	String_Append(  sbInl, "\tassert( out_result );\n" );
	String_Append(  sbInl, "\n" );

	switch ( numRows ) {
		case 2:
			// mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1]
			String_Appendf( sbInl, "\t%s mul0 = %s( in->m[0][0], in->m[1][1] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul1 = %s( in->m[1][0], in->m[0][1] );\n", registerName, mulFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t*out_result = %s( mul0, mul1 );\n", subFuncStr );
			break;

		case 3:
			/*
			+ mat[0][0] * ( mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2] )
			- mat[0][1] * ( mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2] )
			+ mat[0][2] * ( mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1] )
			*/
			String_Appendf( sbInl, "\t%s mul0a = %s( in->m[1][1], in->m[2][2] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul0b = %s( in->m[2][1], in->m[1][2] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s sub0  = %s( mul0a, mul0b );\n",             registerName, subFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s mul1a = %s( in->m[1][0], in->m[2][2] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul1b = %s( in->m[2][0], in->m[1][2] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s sub1  = %s( mul1a, mul1b );\n",             registerName, subFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s mul2a = %s( in->m[1][0], in->m[2][1] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul2b = %s( in->m[2][0], in->m[1][1] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s sub2  = %s( mul2a, mul2b );\n",             registerName, subFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s mul0  = %s( in->m[0][0], sub0 );\n",        registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul1  = %s( in->m[0][1], sub1 );\n",        registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul2  = %s( in->m[0][2], sub2 );\n",        registerName, mulFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s add0  = %s( mul0, mul1 );\n",               registerName, subFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t*out_result = %s( add0, mul2 );\n",            addFuncStr );
			break;

		case 4:
			/*
			sub00 = mat[2][2] * mat[3][3] - mat[3][2] * mat[2][3]
			sub01 = mat[2][1] * mat[3][3] - mat[2][3] * mat[3][1]
			sub02 = mat[2][1] * mat[3][2] - mat[3][1] * mat[2][2]
			sub03 = mat[2][0] * mat[3][3] - mat[3][0] * mat[2][3]
			sub04 = mat[2][0] * mat[3][2] - mat[3][0] * mat[2][2]
			sub05 = mat[2][0] * mat[3][1] - mat[3][0] * mat[2][1]

			cofactor = {
				 ( mat[1][1] * sub00 - mat[1][2] * sub01 + mat[1][3] * sub02 ),
				-( mat[1][0] * sub00 - mat[1][2] * sub03 + mat[1][3] * sub04 ),
				 ( mat[1][0] * sub01 - mat[1][1] * sub03 + mat[1][3] * sub05 ),
				-( mat[1][0] * sub02 - mat[1][1] * sub04 + mat[1][2] * sub05 )
			}

			return
				mat[0][0] * cofactor.x + mat[0][1] * cofactor.y +
				mat[0][2] * cofactor.z + mat[0][3] * cofactor.w
			*/
			String_Appendf( sbInl, "\t%s submul0a      = %s( in->m[2][2], in->m[3][3] );\n",     registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s submul0b      = %s( in->m[3][2], in->m[2][3] );\n",     registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s sub0          = %s( submul0a, submul0b );\n",           registerName, subFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s submul1a      = %s( in->m[2][1], in->m[3][3] );\n",     registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s submul1b      = %s( in->m[2][3], in->m[3][1] );\n",     registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s sub1          = %s( submul1a, submul1b );\n",           registerName, subFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s submul2a      = %s( in->m[2][1], in->m[3][2] );\n",     registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s submul2b      = %s( in->m[3][1], in->m[2][2] );\n",     registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s sub2          = %s( submul2a, submul2b );\n",           registerName, subFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s submul3a      = %s( in->m[2][0], in->m[3][3] );\n",     registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s submul3b      = %s( in->m[3][0], in->m[2][3] );\n",     registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s sub3          = %s( submul3a, submul3b );\n",           registerName, subFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s submul4a      = %s( in->m[2][0], in->m[3][2] );\n",     registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s submul4b      = %s( in->m[3][0], in->m[2][2] );\n",     registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s sub4          = %s( submul4a, submul4b );\n",           registerName, subFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s submul5a      = %s( in->m[2][0], in->m[3][1] );\n",     registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s submul5b      = %s( in->m[3][0], in->m[2][1] );\n",     registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s sub5          = %s( submul5a, submul5b );\n",           registerName, subFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s cofactor0mul0 = %s( in->m[1][1], sub0 );\n",            registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s cofactor0mul1 = %s( in->m[1][2], sub1 );\n",            registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s cofactor0mul2 = %s( in->m[1][3], sub2 );\n",            registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s cofactor0sub  = %s( cofactor0mul0, cofactor0mul1 );\n", registerName, subFuncStr );
			String_Appendf( sbInl, "\t%s cofactor0     = %s( cofactor0sub, cofactor0mul2 );\n",  registerName, addFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s cofactor1mul0 = %s( in->m[1][0], sub0 );\n",            registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s cofactor1mul1 = %s( in->m[1][2], sub3 );\n",            registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s cofactor1mul2 = %s( in->m[1][3], sub4 );\n",            registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s cofactor1sub  = %s( cofactor1mul0, cofactor1mul1 );\n", registerName, subFuncStr );
			String_Appendf( sbInl, "\t%s cofactor1     = %s( cofactor1sub, cofactor1mul2 );\n",  registerName, addFuncStr );
			String_Appendf( sbInl, "\tcofactor1 = %s( HLML_ZERO_SSE, cofactor1 );\n",            subFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s cofactor2mul0 = %s( in->m[1][0], sub1 );\n",            registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s cofactor2mul1 = %s( in->m[1][1], sub3 );\n",            registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s cofactor2mul2 = %s( in->m[1][3], sub5 );\n",            registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s cofactor2sub  = %s( cofactor2mul0, cofactor2mul1 );\n", registerName, subFuncStr );
			String_Appendf( sbInl, "\t%s cofactor2     = %s( cofactor2sub, cofactor2mul2 );\n",  registerName, addFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s cofactor3mul0 = %s( in->m[1][0], sub2 );\n",            registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s cofactor3mul1 = %s( in->m[1][1], sub4 );\n",            registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s cofactor3mul2 = %s( in->m[1][2], sub5 );\n",            registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s cofactor3sub  = %s( cofactor3mul0, cofactor3mul1 );\n", registerName, subFuncStr );
			String_Appendf( sbInl, "\t%s cofactor3     = %s( cofactor3sub, cofactor3mul2 );\n",  registerName, addFuncStr );
			String_Appendf( sbInl, "\tcofactor3 = %s( HLML_ZERO_SSE, cofactor3 );\n",            subFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s finalmul0     = %s( in->m[0][0], cofactor0 );\n",       registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s finalmul1     = %s( in->m[0][1], cofactor1 );\n",       registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s finalmul2     = %s( in->m[0][2], cofactor2 );\n",       registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s finalmul3     = %s( in->m[0][3], cofactor3 );\n",       registerName, mulFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s final0        = %s( finalmul0, finalmul1 );\n",         registerName, addFuncStr );
			String_Appendf( sbInl, "\t%s final1        = %s( finalmul2, finalmul3 );\n",         registerName, addFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t*out_result = %s( final0, final1 );\n",                    addFuncStr );
			break;
	}

	String_Append( sbInl, "}\n" );
	String_Append( sbInl, "\n" );
}

void Gen_SSE_MatrixArithmeticComponentWise( const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TEST_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char* opStr = GEN_OPERATOR_STRINGS_ARITHMETIC[op];

	char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataName( fullTypeName, opStr, inputDataName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	char intrinsicStr[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetIntrinsicArithmeticStr( type, op, intrinsicStr );

	String_Appendf( sbHeader, "struct %s\n", inputDataName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s lhs[%d][%d];\n", registerName, numRows, numCols );
	String_Appendf( sbHeader, "\t%s rhs[%d][%d];\n", registerName, numRows, numCols );
	String_Append(  sbHeader, "};\n" );
	String_Append(  sbHeader, "\n" );

	Doc_SSE_MatrixArithmeticComponentWise( sbHeader, fullTypeName, registerName, op );
	String_Appendf( sbHeader, "inline void comp_%s_sse( const %s* in, %s out_results[%d][%d] );\n", opStr, inputDataName, registerName, numRows, numCols );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void comp_%s_sse( const %s* in, %s out_results[%d][%d] )\n", opStr, inputDataName, registerName, numRows, numCols );
	String_Append(  sbInl, "{\n" );
	String_Append(  sbInl, "\tassert( in );\n" );
	String_Append(  sbInl, "\n" );
	for ( u32 row = 0; row < numRows; row++ ) {
		String_Appendf( sbInl, "\t// row %d\n", row );

		for ( u32 col = 0; col < numCols; col++ ) {
			String_Appendf( sbInl, "\tout_results[%d][%d] = %s( in->lhs[%d][%d], in->rhs[%d][%d] );\n", row, col, intrinsicStr, row, col, row, col );
		}

		if ( row != numRows - 1 ) {
			String_Append( sbInl, "\n" );
		}
	}
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

void Gen_SSE_MatrixTranslate( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	if ( numRows < 3 && numCols < 3 ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataName( fullTypeName, "translate", inputDataName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	const u32 translateVecComponents = numCols - 1;

	char addFuncStr[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetIntrinsicArithmeticStr( type, GEN_OP_ARITHMETIC_ADD, addFuncStr );

	String_Appendf( sbHeader, "struct %s\n", inputDataName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s column[%d];\n", registerName, translateVecComponents );
	String_Appendf( sbHeader, "\t%s vec[%d];\n", registerName, translateVecComponents );
	String_Append(  sbHeader, "};\n" );
	String_Append(  sbHeader, "\n" );

	Doc_SSE_MatrixTranslate( sbHeader, fullTypeName, registerName );
	String_Appendf( sbHeader, "inline void translate_sse( const %s* in, %s out_results[%d] );\n", inputDataName, registerName, translateVecComponents );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void translate_sse( const %s* in, %s out_results[%d] )\n", inputDataName, registerName, translateVecComponents );
	String_Append(  sbInl, "{\n" );
	String_Append(  sbInl, "\tassert( in );\n" );
	String_Append(  sbInl, "\n" );
	for ( u32 i = 0; i < translateVecComponents; i++ ) {
		String_Appendf( sbInl, "\tout_results[%d] = %s( in->column[%d], in->vec[%d] );\n", i, addFuncStr, i, i );
	}
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

void Gen_SSE_MatrixScale( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataName( fullTypeName, "scale", inputDataName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	const u32 numScaleComponents = GEN_MIN( numRows, numCols );

	char mulFuncStr[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetIntrinsicArithmeticStr( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

	String_Appendf( sbHeader, "struct %s\n", inputDataName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s diagonal[%d];\n", registerName, numScaleComponents );
	String_Appendf( sbHeader, "\t%s scale[%d];\n", registerName, numScaleComponents );
	String_Append(  sbHeader, "};\n" );
	String_Append(  sbHeader, "\n" );

	Doc_SSE_MatrixScale( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline void scale_sse( const %s* in, %s out_results[%d] );\n", inputDataName, registerName, numScaleComponents );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void scale_sse( const %s* in, %s out_results[%d] )\n", inputDataName, registerName, numScaleComponents );
	String_Append(  sbInl, "{\n" );
	String_Append(  sbInl, "\tassert( in );\n" );
	String_Append(  sbInl, "\n" );
	for ( u32 i = 0; i < numScaleComponents; i++ ) {
		String_Appendf( sbInl, "\tout_results[%d] = %s( in->diagonal[%d], in->scale[%d] );\n", i, mulFuncStr, i, i );
	}
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}