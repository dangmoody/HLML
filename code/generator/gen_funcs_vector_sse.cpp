#include "gen_funcs_vector_sse.h"

#include "gen_common_sse.h"

#include "string_builder.h"

void Gen_SSE_VectorNormalize( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1.0f, oneStr, 1 );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	char mulFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

	const char* rcpFuncStr = Gen_SSE_GetIntrinsicRcp( type );

	char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetFullTypeName( type, 1, numComponents, sseTypeName );

	char normalizeFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_SSE_GetFuncNameNormalize( language, type, numComponents, normalizeFuncStr );

	char lengthFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_SSE_GetFuncNameLength( language, type, numComponents, lengthFuncStr );

	String_Appendf( sbHeader, "// Normalizes each input array element and stores the normalized result in the corresponding element in the output.\n" );
	String_Appendf( sbHeader, "inline static void %s( const %s* in, %s* out )\n", normalizeFuncStr, sseTypeName, sseTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\tassert( in );\n" );
	String_Appendf( sbHeader, "\tassert( out );\n" );
	String_Append(  sbHeader, "\n" );
	String_Appendf( sbHeader, "\t%s len;\n", registerName );
	String_Appendf( sbHeader, "\t%s( in, &len );\n", lengthFuncStr );
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

void Gen_SSE_VectorDot( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetFullTypeName( type, 1, numComponents, sseTypeName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	char addFuncStr[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_ADD, addFuncStr );

	char mulFuncStr[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

	char dotFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_SSE_GetFuncNameDot( language, type, numComponents, dotFuncStr );

	String_Appendf( sbHeader, "// Performs a dot-product on each index of the left-hand-side and right-hand-side registers, respectively, and stores the result in its respective component in the output register.\n" );
	String_Appendf( sbHeader, "inline static void %s( const %s* lhs, const %s* rhs, %s* out_results )\n", dotFuncStr, sseTypeName, sseTypeName, registerName );
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

void Gen_SSE_VectorCross( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	if ( numComponents < 3 ) {
		return;
	}

	char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetFullTypeName( type, 1, numComponents, sseTypeName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	char mulFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_MUL, mulFuncStr );

	char subFuncStr[GEN_STRING_LENGTH_SSE_INTRINSIC];
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_SUB, subFuncStr );

	char crossFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_SSE_GetFuncNameCross( language, type, numComponents, crossFuncStr );

	String_Appendf( sbHeader, "// Stores the cross product of register vectors lhs and rhs into out_results.\n" );
	String_Appendf( sbHeader, "inline static void %s( const %s* lhs, const %s* rhs, %s* out_results )\n", crossFuncStr, sseTypeName, sseTypeName, sseTypeName );
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

void Gen_SSE_VectorLength( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetFullTypeName( type, 1, numComponents, sseTypeName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	const char* sqrtIntrinsic = Gen_SSE_GetIntrinsicSqrt( type );

	char lengthsqFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_SSE_GetFuncNameLengthsq( language, type, numComponents, lengthsqFuncStr );

	// lengthsq
	{
		char dotFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameDot( language, type, numComponents, dotFuncStr );

		String_Appendf( sbHeader, "// Finds the squared length of each input vector and stores it in its respective component in the output register.\n" );
		String_Appendf( sbHeader, "inline static void %s( const %s* in, %s* out_results )\n", lengthsqFuncStr, sseTypeName, registerName );
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\tassert( in );\n" );
		String_Appendf( sbHeader, "\tassert( out_results );\n" );
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\t%s( in, in, out_results );\n", dotFuncStr );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}

	// length
	{
		char lengthFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameLength( language, type, numComponents, lengthFuncStr );

		String_Appendf( sbHeader, "// Finds the length of each input vector and stores it in its respective component in the output register.\n" );
		String_Appendf( sbHeader, "inline static void %s( const %s* in, %s* out_results )\n", lengthFuncStr, sseTypeName, registerName );
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\tassert( in );\n" );
		String_Appendf( sbHeader, "\tassert( out_results );\n" );
		String_Append(  sbHeader, "\n" );
		String_Appendf( sbHeader, "\t%s( in, out_results );\n", lengthsqFuncStr );
		String_Appendf( sbHeader, "\t*out_results = %s( *out_results );\n", sqrtIntrinsic );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}
}

void Gen_SSE_VectorDistance( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetFullTypeName( type, 1, numComponents, sseTypeName );

	const char* registerName = Gen_SSE_GetRegisterName( type );

	char subFuncStr[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetIntrinsicArithmetic( type, GEN_OP_ARITHMETIC_SUB, subFuncStr );

	// distancesq
	{
		char distancesqFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameDistancesq( language, type, numComponents, distancesqFuncStr );

		char lengthsqFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameLengthsq( language, type, numComponents, lengthsqFuncStr );

		String_Appendf( sbHeader, "// Finds the squared distance between each vector and stores the result in its respective component in the output register.\n" );
		String_Appendf( sbHeader, "inline static void %s( const %s* lhs, const %s* rhs, %s* out_results )\n", distancesqFuncStr, sseTypeName, sseTypeName, registerName );
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
		String_Appendf( sbHeader, "\t%s( &data, out_results );\n", lengthsqFuncStr );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}

	// distance
	{
		char distanceFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameDistance( language, type, numComponents, distanceFuncStr );

		char lengthFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameLength( language, type, numComponents, lengthFuncStr );

		String_Appendf( sbHeader, "// Finds the distance between each vector and stores the result in its respective component in the output register.\n" );
		String_Appendf( sbHeader, "inline static void %s( const %s* lhs, const %s* rhs, %s* out_results )\n", distanceFuncStr, sseTypeName, sseTypeName, registerName );
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
		String_Appendf( sbHeader, "\t%s( &data, out_results );\n", lengthFuncStr );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}
}
