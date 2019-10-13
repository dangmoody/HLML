#include "gen_funcs_vector_sse.h"

#include "gen_common_sse.h"

#include "gen_doc_vector_sse.h"

#include "string_builder.h"

void Gen_SSE_VectorNormalize( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
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

	char mulFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

	const char* rcpFuncStr = Gen_SSE_GetIntrinsicRcp( type );

	char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetFullTypeName( fullTypeName, sseTypeName );

	Doc_SSE_VectorNormalize( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline void normalize_sse( const %s* in, %s* out )\n", sseTypeName, sseTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\tassert( in );\n" );
	String_Appendf( sbHeader, "\tassert( out );\n" );
	String_Append(  sbHeader, "\n" );
	String_Appendf( sbHeader, "\t%s len;\n", registerName );
	String_Append(  sbHeader, "\tlength_sse( in, &len );\n" );
	String_Append(  sbHeader, "\n" );
	String_Appendf( sbHeader, "\t%s invlen = %s( len );\n", registerName, rcpFuncStr );
	String_Append(  sbHeader, "\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf( sbHeader, "\tout->%c = %s( in->%c, invlen );\n", componentStr, mulFuncStr, componentStr );
	}
	String_Append(  sbHeader, "}\n" );
	String_Append(  sbHeader, "\n" );
}

void Gen_SSE_VectorDot( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
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
	String_Appendf( sbHeader, "inline void dot_sse( const %s* lhs, const %s* rhs, %s* out_results )\n", sseTypeName, sseTypeName, registerName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\tassert( lhs );\n" );
	String_Appendf( sbHeader, "\tassert( rhs );\n" );
	String_Appendf( sbHeader, "\tassert( out_results );\n" );
	String_Append(  sbHeader, "\n" );
	switch ( numComponents ) {
		case 2:
			String_Appendf( sbHeader, "\t%s mul0 = %s( lhs->x, rhs->x );\n", registerName, mulFuncStr );
			String_Appendf( sbHeader, "\t%s mul1 = %s( lhs->y, rhs->y );\n", registerName, mulFuncStr );
			String_Append(  sbHeader, "\n" );
			String_Appendf( sbHeader, "\t*out_results = %s( mul0, mul1 );\n", addFuncStr );
			break;

		case 3:
			String_Appendf( sbHeader, "\t%s mul0 = %s( lhs->x, rhs->x );\n", registerName, mulFuncStr );
			String_Appendf( sbHeader, "\t%s mul1 = %s( lhs->y, rhs->y );\n", registerName, mulFuncStr );
			String_Appendf( sbHeader, "\t%s mul2 = %s( lhs->z, rhs->z );\n", registerName, mulFuncStr );
			String_Append(  sbHeader, "\n" );
			String_Appendf( sbHeader, "\t%s add0 = %s( mul0, mul1 );\n", registerName, addFuncStr );
			String_Append(  sbHeader, "\n" );
			String_Appendf( sbHeader, "\t*out_results = %s( add0, mul2 );\n", addFuncStr );
			break;

		case 4:
			String_Appendf( sbHeader, "\t%s mul_x = %s( lhs->x, rhs->x );\n", registerName, mulFuncStr );
			String_Appendf( sbHeader, "\t%s mul_y = %s( lhs->y, rhs->y );\n", registerName, mulFuncStr );
			String_Appendf( sbHeader, "\t%s mul_z = %s( lhs->z, rhs->z );\n", registerName, mulFuncStr );
			String_Appendf( sbHeader, "\t%s mul_w = %s( lhs->w, rhs->w );\n", registerName, mulFuncStr );
			String_Append(  sbHeader, "\n" );
			String_Appendf( sbHeader, "\t%s add0 = %s( mul_x, mul_y );\n", registerName, addFuncStr );
			String_Appendf( sbHeader, "\t%s add1 = %s( mul_z, mul_w );\n", registerName, addFuncStr );
			String_Append(  sbHeader, "\n" );
			String_Appendf( sbHeader, "\t*out_results = %s( add0, add1 );\n", addFuncStr );
			break;
	}
	String_Append(  sbHeader, "}\n" );
	String_Append(  sbHeader, "\n" );
}

void Gen_SSE_VectorCross( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
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

	String_Appendf( sbHeader, "inline void cross_sse( const %s* lhs, const %s* rhs, %s* out_results )\n", sseTypeName, sseTypeName, sseTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Append(  sbHeader, "\tassert( lhs );\n" );
	String_Append(  sbHeader, "\tassert( rhs );\n" );
	String_Append(  sbHeader, "\tassert( out_results );\n" );
	String_Append(  sbHeader, "\n" );
	String_Appendf( sbHeader, "\t%s xmula = %s( lhs->y, rhs->z );\n", registerName, mulFuncStr );
	String_Appendf( sbHeader, "\t%s xmulb = %s( lhs->z, rhs->y );\n", registerName, mulFuncStr );
	String_Appendf( sbHeader, "\tout_results->x = %s( xmula, xmulb );\n", subFuncStr );
	String_Append(  sbHeader, "\n" );
	String_Appendf( sbHeader, "\t%s ymula = %s( lhs->z, rhs->x );\n", registerName, mulFuncStr );
	String_Appendf( sbHeader, "\t%s ymulb = %s( lhs->x, rhs->z );\n", registerName, mulFuncStr );
	String_Appendf( sbHeader, "\tout_results->y = %s( ymula, ymulb );\n", subFuncStr );
	String_Append(  sbHeader, "\n" );
	String_Appendf( sbHeader, "\t%s zmula = %s( lhs->x, rhs->y );\n", registerName, mulFuncStr );
	String_Appendf( sbHeader, "\t%s zmulb = %s( lhs->y, rhs->x );\n", registerName, mulFuncStr );
	String_Appendf( sbHeader, "\tout_results->z = %s( zmula, zmulb );\n", subFuncStr );
	if ( numComponents > 3 ) {
		String_Append( sbHeader, "\n" );
		String_Append( sbHeader, "\tout_results->w = HLML_ZERO_SSE;\n" );
	}
	String_Append(  sbHeader, "}\n" );
	String_Append(  sbHeader, "\n" );
}

void Gen_SSE_VectorLength( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
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
		String_Appendf( sbHeader, "inline void lengthsq_sse( const %s* in, %s* out_results )\n", sseTypeName, registerName );
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\tassert( in );\n" );
		String_Appendf( sbHeader, "\tassert( out_results );\n" );
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\tdot_sse( in, in, out_results );\n" );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}

	// length
	{
		Doc_SSE_VectorLength( sbHeader, fullTypeName );
		String_Appendf( sbHeader, "inline void length_sse( const %s* in, %s* out_results )\n", sseTypeName, registerName );
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\tassert( in );\n" );
		String_Appendf( sbHeader, "\tassert( out_results );\n" );
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\tlengthsq_sse( in, out_results );\n" );
		String_Appendf( sbHeader, "\t*out_results = %s( *out_results );\n", sqrtFuncStr );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}
}

void Gen_SSE_VectorDistance( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
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
		String_Appendf( sbHeader, "inline void distancesq_sse( const %s* lhs, const %s* rhs, %s* out_results )\n", sseTypeName, sseTypeName, registerName );
		String_Append(  sbHeader, "{\n" );
		String_Append(  sbHeader, "\tassert( lhs );\n" );
		String_Append(  sbHeader, "\tassert( rhs );\n" );
		String_Append(  sbHeader, "\tassert( out_results );\n" );
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\t%s data;\n", sseTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Appendf( sbHeader, "\tdata.%c = %s( lhs->%c, rhs->%c );\n", componentStr, subFuncStr, componentStr, componentStr );
		}
		String_Append(  sbHeader, "\n" );
		String_Append(  sbHeader, "\tlengthsq_sse( &data, out_results );\n" );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}

	// distance
	{
		Doc_SSE_VectorDistance( sbHeader, fullTypeName );
		String_Appendf( sbHeader, "inline void distance_sse( const %s* lhs, const %s* rhs, %s* out_results )\n", sseTypeName, sseTypeName, registerName );
		String_Append(  sbHeader, "{\n" );
		String_Append(  sbHeader, "\tassert( lhs );\n" );
		String_Append(  sbHeader, "\tassert( rhs );\n" );
		String_Append(  sbHeader, "\tassert( out_results );\n" );
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\t%s data;\n", sseTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Appendf( sbHeader, "\tdata.%c = %s( lhs->%c, rhs->%c );\n", componentStr, subFuncStr, componentStr, componentStr );
		}
		String_Append(  sbHeader, "\n" );
		String_Append(  sbHeader, "\tlength_sse( &data, out_results );\n" );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}
}

#if 0
void Gen_SSE_VectorAngle( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
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

	String_Appendf( sbHeader, "inline void angle_sse( const %s* in, %s* out_results )\n", inputDataNameAngle, registerName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\tassert( in );\n" );
	String_Appendf( sbHeader, "\tassert( out_results );\n" );
	String_Append(  sbHeader, "\n" );
	String_Appendf( sbHeader, "\t%s resultsLHS[%d];\n", registerName, numComponents );
	String_Appendf( sbHeader, "\t%s resultsRHS[%d];\n", registerName, numComponents );
	String_Appendf( sbHeader, "\t%s resultsDot;\n", registerName );
	String_Append(  sbHeader, "\n" );
	String_Appendf( sbHeader, "\t%s inNormalize;\n", inputDataNameNormalize );
	String_Append(  sbHeader, "\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbHeader, "\tinNormalize.%c = in->lhs[%d];\n", i, i );
	}
	String_Appendf( sbHeader, "\tnormalize_sse( inNormalize, resultsLHS );\n" );
	String_Append(  sbHeader, "\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbHeader, "\tinNormalize.%c = in->rhs[%d];\n", i, i );
	}
	String_Append(  sbHeader, "\tnormalize_sse( inNormalize, resultsRHS );\n" );
	String_Append(  sbHeader, "\n" );
	String_Appendf( sbHeader, "\t%s inDot;\n", inputDataNameDot );
	String_Append(  sbHeader, "\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbHeader, "\tinDot.lhs[%d] = resultsLHS[%d];\n", i, i );
	}
	String_Append(  sbHeader, "\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbHeader, "\tinDot.rhs[%d] = resultsRHS[%d];\n", i, i );
	}
	String_Append(  sbHeader, "\n" );
	String_Appendf( sbHeader, "\tdot_sse( &inDot, &resultsDot );\n" );
	String_Append(  sbHeader, "\n" );
	String_Appendf( sbHeader, "\t%s resultsAcos = %s( resultsDot );\n", registerName, acosFuncStr );
	String_Append(  sbHeader, "\n" );
	String_Appendf( sbHeader, "\t%s inDegrees = { resultsAcos };\n", inputDataNameDegrees );
	String_Appendf( sbHeader, "\tdegrees_sse( &inDegrees, out_results );\n", inputDataNameDegrees );
	String_Append(  sbHeader, "}\n" );
	String_Append(  sbHeader, "\n" );
}
#endif
