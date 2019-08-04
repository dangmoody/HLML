#include "gen_common_sse.h"

#include "string_builder.h"

void Gen_GetValuesArray1D( const genType_t type, const u32 numValues, const float* values, stringBuilder_t* sb ) {
	String_Append(  sb, "\t{ " );
	for ( u32 componentIndex = 0; componentIndex < numValues; componentIndex++ ) {
		char componentStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
		Gen_GetNumericLiteral( type, values[componentIndex], componentStr );

		String_Appendf( sb, "%s", componentStr );

		if ( componentIndex != numValues - 1 ) {
			String_Append( sb, ", " );
		}
	}
	String_Append(  sb, " }" );
}

void Gen_GetValuesArray2D( const genType_t type, const u32 rows, const u32 cols, const float* values, stringBuilder_t* sb ) {
	String_Append( sb, "\t{\n" );
	for ( u32 row = 0; row < rows; row++ ) {
		String_Append( sb, "\t\t{ " );
		for ( u32 col = 0; col < cols; col++ ) {
			const float* value = values + ( row * cols );

			char componentStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
			Gen_GetNumericLiteral( type, *value, componentStr );
			
			String_Appendf( sb, "%s", componentStr );

			if ( col != cols - 1 ) {
				String_Append( sb, ", " );
			}
		}
		String_Append( sb, " }" );

		if ( row != rows - 1 ) {
			String_Append( sb, "," );
		}

		String_Append( sb, "\n" );
	}
	String_Append( sb, "\t};\n" );
}

void Gen_SSE_GetInputDataNameRadians( const genType_t type, char* outString ) {
	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	snprintf( outString, GEN_STRING_LENGTH_SSE_INPUT_NAME, "sse_input_radians_%s_t", memberTypeString );
}

void Gen_SSE_Radians( const genType_t type, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataNameRadians( type, inputDataName );

	const char* registerName	= Gen_SSE_GetRegisterName( type );

	const char* mulFuncStr		= Gen_SSE_GetFuncStrMul( type );

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

void Gen_SSE_GetInputDataNameDegrees( const genType_t type, char* outString ) {
	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	snprintf( outString, GEN_STRING_LENGTH_SSE_INPUT_NAME, "sse_input_degrees_%s_t", memberTypeString );
}

void Gen_SSE_Degrees( const genType_t type, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataNameDegrees( type, inputDataName );

	const char* registerName	= Gen_SSE_GetRegisterName( type );

	const char* mulFuncStr		= Gen_SSE_GetFuncStrMul( type );

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

void Gen_SSE_GetInputDataNameLerp( const genType_t type, const u32 numComponents, char* outString ) {
	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	if ( numComponents == 1 ) {
		const char* memberTypeString = Gen_GetMemberTypeString( type );

		snprintf( outString, GEN_STRING_LENGTH_SSE_INPUT_NAME, "sse_input_lerp_%s_t", memberTypeString );
	} else {
		const char* typeString = Gen_GetTypeString( type );

		snprintf( outString, GEN_STRING_LENGTH_SSE_INPUT_NAME, "sse_input_lerp_%s%d_t", typeString, numComponents );
	}
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

	const char* addFuncStr		= Gen_SSE_GetFuncStrAdd( type );
	const char* subFuncStr		= Gen_SSE_GetFuncStrSub( type );
	const char* mulFuncStr		= Gen_SSE_GetFuncStrMul( type );
	const char* set1FuncStr		= Gen_SSE_GetFuncStrSet1( type );

	char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetInputDataNameLerp( type, numComponents, inputDataName );

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
