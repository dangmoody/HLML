#include "gen_common_sse.h"

#include "string_builder.h"

void Gen_SSE_Radians( const genType_t type, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataName( type, 1, 1, "radians", inputDataName );

	const char* registerName	= Gen_SSE_GetRegisterName( type );

	char mulFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	Gen_SSE_GetIntrinsicArithmeticStr( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

	String_Appendf( sbHeader, "struct %s\n", inputDataName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s deg;\n", registerName );
	String_Append(  sbHeader, "};\n" );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbHeader, "inline void radians_sse( const %s* in, %s* out_results );\n", inputDataName, registerName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void radians_sse( const %s* in, %s* out_results )\n", inputDataName, registerName );
	String_Append(  sbInl, "{\n" );
	String_Append(  sbInl, "\tassert( in );\n" );
	String_Append(  sbInl, "\tassert( out_results );\n" );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t*out_results = %s( in->deg, HLML_DEG_TO_RAD_SSE );\n", mulFuncStr );
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

void Gen_SSE_Degrees( const genType_t type, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataName( type, 1, 1, "degrees", inputDataName );

	const char* registerName	= Gen_SSE_GetRegisterName( type );

	char mulFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	Gen_SSE_GetIntrinsicArithmeticStr( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

	String_Appendf( sbHeader, "struct %s\n", inputDataName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s rad;\n", registerName );
	String_Append(  sbHeader, "};\n" );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbHeader, "inline void degrees_sse( const %s* in, %s* out_results );\n", inputDataName, registerName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void degrees_sse( const %s* in, %s* out_results )\n", inputDataName, registerName );
	String_Append(  sbInl, "{\n" );
	String_Append(  sbInl, "\tassert( in );\n" );
	String_Append(  sbInl, "\tassert( out_results );\n" );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t*out_results = %s( in->rad, HLML_RAD_TO_DEG_SSE );\n", mulFuncStr );
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

void Gen_SSE_Lerp( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= 1 );	// 1 for non-vector types
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1.0f, oneStr, 1 );

	const char* registerName	= Gen_SSE_GetRegisterName( type );
	const char* set1FuncStr		= Gen_SSE_GetFuncStrSet1( type );

	char addFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	char subFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	char mulFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];

	Gen_SSE_GetIntrinsicArithmeticStr( type, GEN_OP_ARITHMETIC_ADD, addFuncStr );
	Gen_SSE_GetIntrinsicArithmeticStr( type, GEN_OP_ARITHMETIC_SUB, subFuncStr );
	Gen_SSE_GetIntrinsicArithmeticStr( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

	char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataName( type, 1, numComponents, "lerp", inputDataName );

	String_Appendf( sbHeader, "struct %s\n", inputDataName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s lhs;\n", registerName );
	String_Appendf( sbHeader, "\t%s rhs;\n", registerName );
	String_Appendf( sbHeader, "\t%s t;\n", registerName );
	String_Append(  sbHeader, "};\n" );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbHeader, "inline void lerp_sse( const %s* in, %s* out_results );\n", inputDataName, registerName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void lerp_sse( const %s* in, %s* out_results )\n", inputDataName, registerName );
	String_Append(  sbInl, "{\n" );
	String_Append(  sbInl, "\tassert( in );\n" );
	String_Append(  sbInl, "\tassert( out_results );\n" );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s one = %s( %s );\n", registerName, set1FuncStr, oneStr );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s sub0 = %s( one, in->t );\n", registerName, subFuncStr );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s mul0 = %s( sub0, in->lhs );\n", registerName, mulFuncStr );
	String_Appendf( sbInl, "\t%s mul1 = %s( in->t, in->rhs );\n", registerName, mulFuncStr );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t*out_results = %s( mul0, mul1 );\n", addFuncStr );
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}
