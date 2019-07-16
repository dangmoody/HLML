#include "gen_funcs_vector_sse.h"

#include "string_builder.h"

void Gen_SSE_GetInputDataNameDot( const genType_t type, const u32 numComponents, char* outString ) {
	const char* typeString = Gen_GetTypeString( type );

	snprintf( outString, GEN_STRING_LENGTH_SSE_INPUT_NAME, "sse_input_dot_%s%d_t", typeString, numComponents );
}

void Gen_SSE_VectorDot( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type != GEN_TYPE_FLOAT ) {
		return;
	}

	char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataNameDot( type, numComponents, inputDataName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	const char* mulFuncStr = Gen_SSE_GetFuncStrMul( type );
	const char* addFuncStr = Gen_SSE_GetFuncStrAdd( type );

	String_Appendf( sbHeader, "struct %s\n", inputDataName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s lhs[%d];\n", registerName, numComponents );
	String_Appendf( sbHeader, "\t%s rhs[%d];\n", registerName, numComponents );
	String_Append(  sbHeader, "};\n" );
	String_Append(  sbHeader, "\n" );
	String_Appendf( sbHeader, "inline void dot_sse( const %s& in, %s* out_results );\n", inputDataName, registerName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void dot_sse( const %s& in, %s* out_results )\n", inputDataName, registerName );
	String_Append(  sbInl, "{\n" );
	switch ( numComponents ) {
		case 2:
			String_Appendf( sbInl, "\t%s mul0 = %s( in.lhs[0], in.rhs[0] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul1 = %s( in.lhs[1], in.rhs[1] );\n", registerName, mulFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t*out_results = %s( mul0, mul1 );\n", addFuncStr );
			break;

		case 3:
			String_Appendf( sbInl, "\t%s mul0 = %s( in.lhs[0], in.rhs[0] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul1 = %s( in.lhs[1], in.rhs[1] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul2 = %s( in.lhs[2], in.rhs[2] );\n", registerName, mulFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s add0 = %s( mul0, mul1 );\n", registerName, addFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t*out_results = %s( add0, mul2 );\n", addFuncStr );
			break;

		case 4:
			String_Appendf( sbInl, "\t%s mul0 = %s( in.lhs[0], in.rhs[0] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul1 = %s( in.lhs[1], in.rhs[1] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul2 = %s( in.lhs[2], in.rhs[2] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul3 = %s( in.lhs[3], in.rhs[3] );\n", registerName, mulFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s add0 = %s( mul0, mul1 );\n", registerName, addFuncStr );
			String_Appendf( sbInl, "\t%s add1 = %s( mul2, mul3 );\n", registerName, addFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t*out_results = %s( add0, add1 );\n", addFuncStr );
			break;
	}
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

void Gen_SSE_GetInputDataNameLength( const genType_t type, const u32 numComponents, char* outString ) {
	const char* typeString = Gen_GetTypeString( type );

	snprintf( outString, GEN_STRING_LENGTH_SSE_INPUT_NAME, "sse_input_length_%s%d_t", typeString, numComponents );
}

void Gen_SSE_VectorLength( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type != GEN_TYPE_FLOAT ) {
		return;
	}

	char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataNameLength( type, numComponents, inputDataName );

	char dotInputName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataNameDot( type, numComponents, dotInputName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	const char* sqrtFuncStr = Gen_SSE_GetFuncStrSqrt( type );

	String_Appendf( sbHeader, "struct %s\n", inputDataName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s comp[%d];\n", registerName, numComponents );
	String_Append(  sbHeader, "};\n" );
	String_Append(  sbHeader, "\n" );

	// lengthsq
	{
		String_Appendf( sbHeader, "inline void lengthsq_sse( const %s& in, %s* out_results );\n", inputDataName, registerName );
		String_Append(  sbHeader, "\n" );

		String_Appendf( sbInl, "void lengthsq_sse( const %s& in, %s* out_results )\n", inputDataName, registerName );
		String_Append(  sbInl, "{\n" );
		String_Appendf( sbInl, "\t%s data;\n", dotInputName );
		String_Append(  sbInl, "\n" );
		for ( u32 i = 0; i < numComponents; i++ ) {
			String_Appendf( sbInl, "\tdata.lhs[%d] = in.comp[%d];\n", i, i );
		}
		String_Append(  sbInl, "\n" );
		for ( u32 i = 0; i < numComponents; i++ ) {
			String_Appendf( sbInl, "\tdata.rhs[%d] = in.comp[%d];\n", i, i );
		}
		String_Append(  sbInl, "\n" );
		String_Appendf( sbInl, "\tdot_sse( data, out_results );\n" );
		String_Append(  sbInl, "}\n" );
		String_Append(  sbInl, "\n" );
	}

	// length
	{
		String_Appendf( sbHeader, "inline void length_sse( const %s& in, %s* out_results );\n", inputDataName, registerName );
		String_Append(  sbHeader, "\n" );

		String_Appendf( sbInl, "void length_sse( const %s& in, %s* out_results )\n", inputDataName, registerName );
		String_Append(  sbInl, "{\n" );
		String_Appendf( sbInl, "\tlengthsq_sse( in, out_results );\n" );
		String_Appendf( sbInl, "\t*out_results = %s( *out_results );\n", sqrtFuncStr );
		String_Append(  sbInl, "}\n" );
		String_Append(  sbInl, "\n" );
	}
}
