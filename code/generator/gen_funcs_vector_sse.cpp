#include "gen_funcs_vector_sse.h"

#include "gen_common_sse.h"

#include "gen_doc_vector_sse.h"

#include "string_builder.h"

void Gen_SSE_VectorNormalize( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1.0f, oneStr, 1 );

	const char* registerName = Gen_SSE_GetRegisterName( type );

//	const char* set1FuncStr = Gen_SSE_GetIntrinsicSet1( type );

	char mulFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

	const char* rcpFuncStr = Gen_SSE_GetIntrinsicRcp( type );

	char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetFullTypeName( fullTypeName, sseTypeName );
	
	Doc_SSE_VectorNormalize( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline void normalize_sse( const %s* in, %s* out );\n", sseTypeName, sseTypeName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void normalize_sse( const %s* in, %s* out )\n", sseTypeName, sseTypeName );
	String_Append(  sbInl, "{\n" );
	String_Appendf( sbInl, "\tassert( in );\n" );
	String_Appendf( sbInl, "\tassert( out );\n" );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s len;\n", registerName );
	String_Append(  sbInl, "\tlength_sse( in, &len );\n" );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s invlen = %s( len );\n", registerName, rcpFuncStr );
	String_Append(  sbInl, "\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbInl, "\tout->comp[%d] = %s( in->comp[%d], invlen );\n", i, mulFuncStr, i );
	}
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

void Gen_SSE_VectorDot( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetFullTypeName( fullTypeName, sseTypeName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	char addFuncStr[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	char mulFuncStr[GEN_STRING_LENGTH_SSE_INPUT_NAME];

	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_ADD, addFuncStr );
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

	Doc_SSE_VectorDot( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline void dot_sse( const %s* lhs, const %s* rhs, %s* out_results );\n", sseTypeName, sseTypeName, registerName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void dot_sse( const %s* lhs, const %s* rhs, %s* out_results )\n", sseTypeName, sseTypeName, registerName );
	String_Append(  sbInl, "{\n" );
	String_Appendf( sbInl, "\tassert( lhs );\n" );
	String_Appendf( sbInl, "\tassert( rhs );\n" );
	String_Appendf( sbInl, "\tassert( out_results );\n" );
	String_Append(  sbInl, "\n" );
	switch ( numComponents ) {
		case 2:
			String_Appendf( sbInl, "\t%s mul0 = %s( lhs->comp[0], rhs->comp[0] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul1 = %s( lhs->comp[1], rhs->comp[1] );\n", registerName, mulFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t*out_results = %s( mul0, mul1 );\n", addFuncStr );
			break;

		case 3:
			String_Appendf( sbInl, "\t%s mul0 = %s( lhs->comp[0], rhs->comp[0] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul1 = %s( lhs->comp[1], rhs->comp[1] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul2 = %s( lhs->comp[2], rhs->comp[2] );\n", registerName, mulFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t%s add0 = %s( mul0, mul1 );\n", registerName, addFuncStr );
			String_Append(  sbInl, "\n" );
			String_Appendf( sbInl, "\t*out_results = %s( add0, mul2 );\n", addFuncStr );
			break;

		case 4:
			String_Appendf( sbInl, "\t%s mul0 = %s( lhs->comp[0], rhs->comp[0] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul1 = %s( lhs->comp[1], rhs->comp[1] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul2 = %s( lhs->comp[2], rhs->comp[2] );\n", registerName, mulFuncStr );
			String_Appendf( sbInl, "\t%s mul3 = %s( lhs->comp[3], rhs->comp[3] );\n", registerName, mulFuncStr );
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

void Gen_SSE_VectorCross( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	if ( numComponents < 3 ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetFullTypeName( fullTypeName, sseTypeName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	char mulFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

	char subFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_SUB, subFuncStr );

	Doc_SSE_VectorCross( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline void cross_sse( const %s* lhs, const %s* rhs, %s* out_results );\n", sseTypeName, sseTypeName, sseTypeName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void cross_sse( const %s* lhs, const %s* rhs, %s* out_results )\n", sseTypeName, sseTypeName, sseTypeName );
	String_Append(  sbInl, "{\n" );
	String_Append(  sbInl, "\tassert( lhs );\n" );
	String_Append(  sbInl, "\tassert( rhs );\n" );
	String_Append(  sbInl, "\tassert( out_results );\n" );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s xmula = %s( lhs->comp[1], rhs->comp[2] );\n", registerName, mulFuncStr );
	String_Appendf( sbInl, "\t%s xmulb = %s( lhs->comp[2], rhs->comp[1] );\n", registerName, mulFuncStr );
	String_Appendf( sbInl, "\tout_results->comp[0] = %s( xmula, xmulb );\n", subFuncStr );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s ymula = %s( lhs->comp[2], rhs->comp[0] );\n", registerName, mulFuncStr );
	String_Appendf( sbInl, "\t%s ymulb = %s( lhs->comp[0], rhs->comp[2] );\n", registerName, mulFuncStr );
	String_Appendf( sbInl, "\tout_results->comp[1] = %s( ymula, ymulb );\n", subFuncStr );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s zmula = %s( lhs->comp[0], rhs->comp[1] );\n", registerName, mulFuncStr );
	String_Appendf( sbInl, "\t%s zmulb = %s( lhs->comp[1], rhs->comp[0] );\n", registerName, mulFuncStr );
	String_Appendf( sbInl, "\tout_results->comp[2] = %s( zmula, zmulb );\n", subFuncStr );
	if ( numComponents > 3 ) {
		String_Append( sbInl, "\n" );
		String_Append( sbInl, "\tout_results->comp[3] = HLML_ZERO_SSE;\n" );
	}
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

void Gen_SSE_VectorLength( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetFullTypeName( fullTypeName, sseTypeName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	const char* sqrtFuncStr = Gen_SSE_GetFuncStrSqrt( type );

	// lengthsq
	{
		Doc_SSE_VectorLengthsq( sbHeader, fullTypeName );
		String_Appendf( sbHeader, "inline void lengthsq_sse( const %s* in, %s* out_results );\n", sseTypeName, registerName );
		String_Append(  sbHeader, "\n" );

		String_Appendf( sbInl, "void lengthsq_sse( const %s* in, %s* out_results )\n", sseTypeName, registerName );
		String_Append(  sbInl, "{\n" );
		String_Appendf( sbInl, "\tassert( in );\n" );
		String_Appendf( sbInl, "\tassert( out_results );\n" );
		String_Append(  sbInl, "\n" );
		String_Appendf( sbInl, "\tdot_sse( in, in, out_results );\n" );
		String_Append(  sbInl, "}\n" );
		String_Append(  sbInl, "\n" );
	}

	// length
	{
		Doc_SSE_VectorLength( sbHeader, fullTypeName );
		String_Appendf( sbHeader, "inline void length_sse( const %s* in, %s* out_results );\n", sseTypeName, registerName );
		String_Append(  sbHeader, "\n" );

		String_Appendf( sbInl, "void length_sse( const %s* in, %s* out_results )\n", sseTypeName, registerName );
		String_Append(  sbInl, "{\n" );
		String_Appendf( sbInl, "\tassert( in );\n" );
		String_Appendf( sbInl, "\tassert( out_results );\n" );
		String_Append(  sbInl, "\n" );
		String_Appendf( sbInl, "\tlengthsq_sse( in, out_results );\n" );
		String_Appendf( sbInl, "\t*out_results = %s( *out_results );\n", sqrtFuncStr );
		String_Append(  sbInl, "}\n" );
		String_Append(  sbInl, "\n" );
	}
}

void Gen_SSE_VectorDistance( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetFullTypeName( fullTypeName, sseTypeName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	char subFuncStr[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_SUB, subFuncStr );

	// distancesq
	{
		Doc_SSE_VectorDistancesq( sbHeader, fullTypeName );
		String_Appendf( sbHeader, "inline void distancesq_sse( const %s* lhs, const %s* rhs, %s* out_results );\n", sseTypeName, sseTypeName, registerName );
		String_Append(  sbHeader, "\n" );

		String_Appendf( sbInl, "void distancesq_sse( const %s* lhs, const %s* rhs, %s* out_results )\n", sseTypeName, sseTypeName, registerName );
		String_Append(  sbInl, "{\n" );
		String_Append(  sbInl, "\tassert( lhs );\n" );
		String_Append(  sbInl, "\tassert( rhs );\n" );
		String_Append(  sbInl, "\tassert( out_results );\n" );
		String_Append(  sbInl, "\n" );
		String_Appendf( sbInl, "\t%s data;\n", sseTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			String_Appendf( sbInl, "\tdata.comp[%d] = %s( lhs->comp[%d], rhs->comp[%d] );\n", i, subFuncStr, i, i );
		}
		String_Append(  sbInl, "\n" );
		String_Append(  sbInl, "\tlengthsq_sse( &data, out_results );\n" );
		String_Append(  sbInl, "}\n" );
		String_Append(  sbInl, "\n" );
	}

	// distance
	{
		Doc_SSE_VectorDistance( sbHeader, fullTypeName );
		String_Appendf( sbHeader, "inline void distance_sse( const %s* lhs, const %s* rhs, %s* out_results );\n", sseTypeName, sseTypeName, registerName );
		String_Append(  sbHeader, "\n" );

		String_Appendf( sbInl, "void distance_sse( const %s* lhs, const %s* rhs, %s* out_results )\n", sseTypeName, sseTypeName, registerName );
		String_Append(  sbInl, "{\n" );
		String_Append(  sbInl, "\tassert( lhs );\n" );
		String_Append(  sbInl, "\tassert( rhs );\n" );
		String_Append(  sbInl, "\tassert( out_results );\n" );
		String_Append(  sbInl, "\n" );
		String_Appendf( sbInl, "\t%s data;\n", sseTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			String_Appendf( sbInl, "\tdata.comp[%d] = %s( lhs->comp[%d], rhs->comp[%d] );\n", i, subFuncStr, i, i );
		}
		String_Append(  sbInl, "\n" );
		String_Append(  sbInl, "\tlength_sse( &data, out_results );\n" );
		String_Append(  sbInl, "}\n" );
		String_Append(  sbInl, "\n" );
	}
}

#if 0
void Gen_SSE_VectorAngle( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char inputDataNameAngle[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataNameAngle( type, numComponents, inputDataNameAngle );

	char inputDataNameNormalize[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataName( type, 1, numComponents, "normalize", inputDataNameNormalize );

	char inputDataNameDot[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataName( type, 1, numComponents, "normalize", inputDataNameDot );

	char inputDataNameDegrees[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataName( type, 1, 1, "degrees" inputDataNameDegrees );

	const char* registerName	= Gen_SSE_GetRegisterName( type );
	const char* acosFuncStr		= Gen_SSE_GetFuncStrAcos( type );

	String_Appendf( sbHeader, "struct %s\n", inputDataNameAngle );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s lhs[%d];\n", registerName, numComponents );
	String_Appendf( sbHeader, "\t%s rhs[%d];\n", registerName, numComponents );
	String_Append(  sbHeader, "};\n" );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbHeader, "inline void angle_sse( const %s* in, %s* out_results );\n", inputDataNameAngle, registerName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void angle_sse( const %s* in, %s* out_results )\n", inputDataNameAngle, registerName );
	String_Append(  sbInl, "{\n" );
	String_Appendf( sbInl, "\tassert( in );\n" );
	String_Appendf( sbInl, "\tassert( out_results );\n" );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s resultsLHS[%d];\n", registerName, numComponents );
	String_Appendf( sbInl, "\t%s resultsRHS[%d];\n", registerName, numComponents );
	String_Appendf( sbInl, "\t%s resultsDot;\n", registerName );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s inNormalize;\n", inputDataNameNormalize );
	String_Append(  sbInl, "\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbInl, "\tinNormalize.comp[%d] = in->lhs[%d];\n", i, i );
	}
	String_Appendf( sbInl, "\tnormalize_sse( inNormalize, resultsLHS );\n" );
	String_Append(  sbInl, "\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbInl, "\tinNormalize.comp[%d] = in->rhs[%d];\n", i, i );
	}
	String_Append(  sbInl, "\tnormalize_sse( inNormalize, resultsRHS );\n" );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s inDot;\n", inputDataNameDot );
	String_Append(  sbInl, "\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbInl, "\tinDot.lhs[%d] = resultsLHS[%d];\n", i, i );
	}
	String_Append(  sbInl, "\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbInl, "\tinDot.rhs[%d] = resultsRHS[%d];\n", i, i );
	}
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\tdot_sse( &inDot, &resultsDot );\n" );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s resultsAcos = %s( resultsDot );\n", registerName, acosFuncStr );
	String_Append(  sbInl, "\n" );
	String_Appendf( sbInl, "\t%s inDegrees = { resultsAcos };\n", inputDataNameDegrees );
	String_Appendf( sbInl, "\tdegrees_sse( &inDegrees, out_results );\n", inputDataNameDegrees );
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}
#endif
