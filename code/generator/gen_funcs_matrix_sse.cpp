#include "gen_funcs_matrix_sse.h"

#include "gen_common_sse.h"

#include "gen_doc_matrix_sse.h"

#include "string_builder.h"

void Gen_SSE_MatrixIdentity( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	const char* registerName = Gen_SSE_GetRegisterName( type );

	const char* set1FuncStr = Gen_SSE_GetFuncStrSet1( type );

	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 0.0f, zeroStr, 1 );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1.0f, oneStr, 1 );

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

	char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataName( type, numRows, numCols, "transpose", inputDataName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	String_Appendf( sbHeader, "struct %s\n", inputDataName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s m[%d][%d];\n", registerName, numRows, numCols );
	String_Append(  sbHeader, "};\n" );
	String_Append(  sbHeader, "\n" );

	Doc_SSE_MatrixTranspose( sbHeader, type, numRows, numCols, registerName );
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

void Gen_SSE_MatrixArithmeticComponentWise( const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	const char* opStr = GEN_OPERATOR_STRINGS_ARITHMETIC[op];

	char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataName( type, numRows, numCols, opStr, inputDataName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	char intrinsicStr[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetIntrinsicArithmeticStr( type, op, intrinsicStr );

	String_Appendf( sbHeader, "struct %s\n", inputDataName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s lhs[%d][%d];\n", registerName, numRows, numCols );
	String_Appendf( sbHeader, "\t%s rhs[%d][%d];\n", registerName, numRows, numCols );
	String_Append(  sbHeader, "};\n" );
	String_Append(  sbHeader, "\n" );

	Doc_SSE_MatrixArithmeticComponentWise( sbHeader, type, numRows, numCols, registerName, op );
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

	char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataName( type, numRows, numCols, "translate", inputDataName );

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

	Doc_SSE_MatrixTranslate( sbHeader, type, numRows, numCols, registerName );
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

	char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataName( type, numRows, numCols, "scale", inputDataName );

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

	Doc_SSE_MatrixScale( sbHeader, type, numRows, numCols );
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