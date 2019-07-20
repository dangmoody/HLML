#include "gen_funcs_vector_sse.h"

#include "gen_common_sse.h"

#include "string_builder.h"

void Gen_SSE_GetInputDataNameNormalize( const genType_t type, const u32 numComponents, char* outString ) {
	const char* typeString = Gen_GetTypeString( type );

	snprintf( outString, GEN_STRING_LENGTH_SSE_INPUT_NAME, "sse_input_normalize_%s%d_t", typeString, numComponents );
}

void Gen_SSE_VectorNormalize( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1.0f, oneStr, 1 );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	const char* set1FuncStr = Gen_SSE_GetFuncStrSet1( type );

	const char* mulFuncStr = Gen_SSE_GetFuncStrMul( type );
	const char* divFuncStr = Gen_SSE_GetFuncStrDiv( type );

	char inputDataNameNormalize[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataNameNormalize( type, numComponents, inputDataNameNormalize );

	char inputDataNameLength[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataNameLength( type, numComponents, inputDataNameLength );

	String_Appendf( sbHeader, "struct %s\n", inputDataNameNormalize );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s comp[%d];\n", registerName, numComponents );
	String_Append(  sbHeader, "};\n" );
	String_Append(  sbHeader, "\n" );
	
	String_Appendf( sbHeader, "inline void normalize_sse( const %s& in, %s out_results[%d] );\n", inputDataNameNormalize, registerName, numComponents );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void normalize_sse( const %s& in, %s out_results[%d] )\n", inputDataNameNormalize, registerName, numComponents );
	String_Append(  sbInl, "{\n" );
	String_Appendf( sbInl, "\t%s one = %s( %s );\n", registerName, set1FuncStr, oneStr );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s len;\n", registerName );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s inLength;\n", inputDataNameLength );
	String_Appendf( sbInl, "\tmemcpy( inLength.comp, in.comp, %d * sizeof( __m128 ) );\n", numComponents );
	String_Append(  sbInl, "\tlength_sse( inLength, &len );\n" );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s invlen = %s( one, len );\n", registerName, divFuncStr );
	String_Append(  sbInl, "\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbInl, "\tout_results[%d] = %s( in.comp[%d], invlen );\n", i, mulFuncStr, i );
	}
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

void Gen_SSE_GetInputDataNameDot( const genType_t type, const u32 numComponents, char* outString ) {
	const char* typeString = Gen_GetTypeString( type );

	snprintf( outString, GEN_STRING_LENGTH_SSE_INPUT_NAME, "sse_input_dot_%s%d_t", typeString, numComponents );
}

void Gen_SSE_VectorDot( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeSupportsSSE( type ) ) {
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

	if ( !Gen_TypeSupportsSSE( type ) ) {
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

void Gen_SSE_GetInputDataNameDistance( const genType_t type, const u32 numComponents, char* outString ) {
	const char* typeString = Gen_GetTypeString( type );

	snprintf( outString, GEN_STRING_LENGTH_SSE_INPUT_NAME, "sse_input_distance_%s%d_t", typeString, numComponents );
}

void Gen_SSE_VectorDistance( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataNameDistance( type, numComponents, inputDataName );

	char lengthDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataNameLength( type, numComponents, lengthDataName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	const char* subFuncStr = Gen_SSE_GetFuncStrSub( type );

	String_Appendf( sbHeader, "struct %s\n", inputDataName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s lhs[%d];\n", registerName, numComponents );
	String_Appendf( sbHeader, "\t%s rhs[%d];\n", registerName, numComponents );
	String_Append(  sbHeader, "};\n" );
	String_Append(  sbHeader, "\n" );

	// distancesq
	{
		String_Appendf( sbHeader, "inline void distancesq_sse( const %s& in, %s* out_results );\n", inputDataName, registerName );
		String_Append(  sbHeader, "\n" );

		String_Appendf( sbInl, "void distancesq_sse( const %s& in, %s* out_results )\n", inputDataName, registerName );
		String_Append(  sbInl, "{\n" );
		String_Appendf( sbInl, "\t%s data;\n", lengthDataName );
		String_Append(  sbInl, "\n" );
		for ( u32 i = 0; i < numComponents; i++ ) {
			String_Appendf( sbInl, "\tdata.comp[%d] = %s( in.lhs[%d], in.rhs[%d] );\n", i, subFuncStr, i, i );
		}
		String_Append(  sbInl, "\n" );
		String_Append(  sbInl, "\tlengthsq_sse( data, out_results );\n" );
		String_Append(  sbInl, "}\n" );
		String_Append(  sbInl, "\n" );
	}

	// distance
	{
		String_Appendf( sbHeader, "inline void distance_sse( const %s& in, %s* out_results );\n", inputDataName, registerName );
		String_Append(  sbHeader, "\n" );

		String_Appendf( sbInl, "void distance_sse( const %s& in, %s* out_results )\n", inputDataName, registerName );
		String_Append(  sbInl, "{\n" );
		String_Appendf( sbInl, "\t%s data;\n", lengthDataName );
		String_Append(  sbInl, "\n" );
		for ( u32 i = 0; i < numComponents; i++ ) {
			String_Appendf( sbInl, "\tdata.comp[%d] = %s( in.lhs[%d], in.rhs[%d] );\n", i, subFuncStr, i, i );
		}
		String_Append(  sbInl, "\n" );
		String_Append(  sbInl, "\tlength_sse( data, out_results );\n" );
		String_Append(  sbInl, "}\n" );
		String_Append(  sbInl, "\n" );
	}
}
