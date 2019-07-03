#include "gen_common.h"

#include "gen_doc_common.h"

#include "string_builder.h"

#include <assert.h>

static void GenerateOperatorIncrementHeader( const genType_t type, const u32 numRows, const u32 numCols, const genOpIncrement_t op, stringBuilder_t* sb ) {
	assert( sb );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char* opStr = GEN_OPERATORS_INCREMENT[op];

	// prefix
	Gen_GetDocOperatorIncrementPrefix( sb, fullTypeName, op );
	String_Appendf( sb, "inline %s& operator%s( %s& lhs );\n", fullTypeName, opStr, fullTypeName );
	String_Append(  sb, "\n" );

	// postfix
	Gen_GetDocOperatorIncrementPostfix( sb, fullTypeName, op );
	String_Appendf( sb, "inline %s& operator%s( %s& lhs, const int );\n", fullTypeName, opStr, fullTypeName );
	String_Append(  sb, "\n" );
}

static void GenerateOperatorIncrementInl( const genType_t type, const u32 numRows, const u32 numCols, const genOpIncrement_t op, stringBuilder_t* sb ) {
	assert( sb );

	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char* opStr = GEN_OPERATORS_INCREMENT[op];

	// prefix
	String_Append(  sb, "// prefix\n" );
	String_Appendf( sb, "%s& operator%s( %s& lhs )\n", fullTypeName, opStr, fullTypeName );
	String_Append(  sb, "{\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sb, "\t%slhs[%d];\n", opStr, i );
	}
	String_Append( sb, "\treturn lhs;\n" );
	String_Append( sb, "}\n" );
	String_Append( sb, "\n" );

	// postfix
	String_Append(  sb, "// postfix\n" );
	String_Appendf( sb, "%s& operator%s( %s& lhs, const int )\n", fullTypeName, opStr, fullTypeName );
	String_Append(  sb, "{\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sb, "\tlhs[%d]%s;\n", i, opStr );
	}
	String_Append( sb, "\treturn lhs;\n" );
	String_Append( sb, "}\n" );
	String_Append( sb, "\n" );
}

static void HeaderGenerateOperatorRelational( const genType_t type, const u32 numRows, const u32 numCols, const genOpRelational_t op, stringBuilder_t* sb ) {
	assert( sb );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char boolReturnTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( GEN_TYPE_BOOL, numRows, numCols, boolReturnTypeName );

	Gen_GetDocOperatorRelational( sb, fullTypeName, numRows, numCols, op );
	String_Appendf( sb, "inline %s operator%s( const %s& lhs, const %s& rhs );\n", boolReturnTypeName, GEN_OPERATORS_RELATIONAL[op], fullTypeName, fullTypeName );
	String_Append(  sb, "\n" );
}

static void InlGenerateOperatorRelational( const genType_t type, const u32 numRows, const u32 numCols, const genOpRelational_t op, stringBuilder_t* sb ) {
	assert( sb );

	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char boolReturnTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( GEN_TYPE_BOOL, numRows, numCols, boolReturnTypeName );

	const char* opStr = GEN_OPERATORS_RELATIONAL[op];

	String_Appendf( sb, "%s operator%s( const %s& lhs, const %s& rhs )\n", boolReturnTypeName, opStr, fullTypeName, fullTypeName );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn %s(\n", boolReturnTypeName );

	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sb, "\t\tlhs[%d] %s rhs[%d]", i, opStr, i );

		if ( i != numComponents - 1 ) {
			String_Append( sb, "," );
		}

		String_Append( sb, "\n" );
	}
	String_Append( sb, "\t);\n" );
	String_Append( sb, "}\n" );
	String_Append( sb, "\n" );
}

static void HeaderGenerateOperatorBitwiseScalar( const genType_t type, const u32 numRows, const u32 numCols, const genOpBitwise_t op, stringBuilder_t* sb ) {
	assert( sb );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	const char* opStr = GEN_OPERATORS_BITWISE[op];

	Gen_GetDocOperatorBitwiseScalar( sb, fullTypeName, op );
	String_Appendf( sb, "inline %s operator%s( const %s& lhs, const %s& rhs );\n", fullTypeName, opStr, fullTypeName, memberTypeString );
	String_Append(  sb, "\n" );

	Gen_GetDocOperatorCompoundBitwiseScalar( sb, fullTypeName, op );
	String_Appendf( sb, "inline %s operator%s=( %s& lhs, const %s& rhs );\n", fullTypeName, opStr, fullTypeName, memberTypeString );
	String_Append(  sb, "\n" );
}

static void InlGenerateOperatorBitwiseScalar( const genType_t type, const u32 numRows, const u32 numCols, const genOpBitwise_t op, stringBuilder_t* sb ) {
	assert( sb );

	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	const char* opStr = GEN_OPERATORS_BITWISE[op];

	// main bitwise operator
	String_Appendf( sb, "%s operator%s( const %s& lhs, const %s& rhs )\n", fullTypeName, opStr, fullTypeName, memberTypeString );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn %s(\n", fullTypeName );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sb, "\t\tlhs[%d] %s rhs", i, opStr );

		if ( i != numComponents - 1 ) {
			String_Append( sb, "," );
		}

		String_Append( sb, "\n" );
	}
	String_Append( sb, "\t);\n" );
	String_Append( sb, "}\n" );
	String_Append( sb, "\n" );

	// compound bitwise operator
	String_Appendf( sb, "%s operator%s=( %s& lhs, const %s& rhs )\n", fullTypeName, opStr, fullTypeName, memberTypeString );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn ( lhs = lhs %s rhs );\n", opStr );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );
}

static void HeaderGenerateOperatorBitwiseRhsType( const genType_t type, const u32 numRows, const u32 numCols, const genOpBitwise_t op, stringBuilder_t* sb ) {
	assert( sb );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char* opStr = GEN_OPERATORS_BITWISE[op];

	Gen_GetDocOperatorBitwiseRhsType( sb, fullTypeName, op );
	String_Appendf( sb, "inline %s operator%s( const %s& lhs, const %s& rhs );\n", fullTypeName, opStr, fullTypeName, fullTypeName );
	String_Append(  sb, "\n" );

	Gen_GetDocOperatorCompoundBitwiseRhsType( sb, fullTypeName, op );
	String_Appendf( sb, "inline %s operator%s=( %s& lhs, const %s& rhs );\n", fullTypeName, opStr, fullTypeName, fullTypeName );
	String_Append(  sb, "\n" );
}

static void InlGenerateOperatorBitwiseRhsType( const genType_t type, const u32 numRows, const u32 numCols, const genOpBitwise_t op, stringBuilder_t* sb ) {
	assert( sb );

	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char* opStr = GEN_OPERATORS_BITWISE[op];

	// main bitwise operator
	String_Appendf( sb, "%s operator%s( const %s& lhs, const %s& rhs )\n", fullTypeName, opStr, fullTypeName, fullTypeName );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn %s(\n", fullTypeName );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sb, "\t\tlhs[%d] %s rhs[%d]", i, opStr, i );

		if ( i != numComponents - 1 ) {
			String_Append( sb, "," );
		}

		String_Append( sb, "\n" );
	}
	String_Append( sb, "\t);\n" );
	String_Append( sb, "}\n" );
	String_Append( sb, "\n" );

	// compound bitwise operator
	String_Appendf( sb, "%s operator%s=( %s& lhs, const %s& rhs )\n", fullTypeName, opStr, fullTypeName, fullTypeName );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn ( lhs = lhs %s rhs );\n", opStr );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );
}


void Gen_Floateq( const genType_t type, stringBuilder_t* sb ) {
	assert( sb );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	const char* floateqStr = Gen_GetFuncNameFloateq( type );

	const char* parmEpsilonStr = Gen_GetConstantNameEpsilon( type );

	Gen_DocFloateq( sb );
	String_Appendf( sb, "inline bool %s( const %s lhs, const %s rhs, const %s epsilon = %s )\n", floateqStr, typeString, typeString, typeString, parmEpsilonStr );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn %s( lhs - rhs ) < epsilon;\n", Gen_GetFuncNameFabs( type ) );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );
}

void Gen_Sign( const genType_t type, stringBuilder_t* sb ) {
	assert( sb );

	if ( type == GEN_TYPE_BOOL || type == GEN_TYPE_UINT ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( type );
	const char* intTypeString = Gen_GetMemberTypeString( GEN_TYPE_INT );

	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 0, zeroStr );

	Gen_DocSign( sb );
	String_Appendf( sb, "inline %s sign( const %s x )\n", intTypeString, memberTypeString );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn ( %s < x ) - ( x < %s );\n", zeroStr, zeroStr );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );
}

void Gen_Radians( const genType_t type, stringBuilder_t* sb ) {
	assert( sb );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	char oneHundredEightyStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 180, oneHundredEightyStr );

	const char* piStr = Gen_GetConstantNamePi( type );

	Gen_DocRadians( sb );
	String_Appendf( sb, "inline %s radians( const %s deg )\n", typeString, typeString );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn deg * %s / %s;\n", piStr, oneHundredEightyStr );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );
}

void Gen_Degrees( const genType_t type, stringBuilder_t* sb ) {
	assert( sb );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	char oneHundredEightyStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 180, oneHundredEightyStr );

	const char* piStr = Gen_GetConstantNamePi( type );

	Gen_DocDegrees( sb );
	String_Appendf( sb, "inline %s degrees( const %s rad )\n", typeString, typeString );
	String_Append(  sb, "{\n" );
	String_Appendf( sb, "\treturn rad * %s / %s;\n", oneHundredEightyStr, piStr );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );
}

void Gen_MinMax( const genType_t type, stringBuilder_t* sb ) {
	assert( sb );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	// min
	Gen_DocMin( sb );
	String_Appendf( sb, "inline %s min( const %s& x, const %s& y )\n", memberTypeString, memberTypeString, memberTypeString );
	String_Append(  sb, "{\n" );
	String_Append(  sb, "\treturn ( x < y ) ? x : y;\n" );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );

	// max
	Gen_DocMax( sb );
	String_Appendf( sb, "inline %s max( const %s& x, const %s& y )\n", memberTypeString, memberTypeString, memberTypeString );
	String_Append(  sb, "{\n" );
	String_Append(  sb, "\treturn ( x > y ) ? x : y;\n" );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );
}

void Gen_Clamp( const genType_t type, stringBuilder_t* sb ) {
	assert( sb );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	Gen_DocClamp( sb );
	String_Appendf( sb, "inline %s clamp( const %s& x, const %s& low, const %s& high )\n", memberTypeString, memberTypeString, memberTypeString, memberTypeString );
	String_Append(  sb, "{\n" );
	String_Append(  sb, "\treturn min( max( x, low ), high );\n" );
	String_Append(  sb, "}\n" );
	String_Append(  sb, "\n" );
}

void Gen_Saturate( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( sbHeader );

	assert( numComponents >= 1 );	// we allow scalar types for this function
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, 0.0f, zeroStr );
	Gen_GetNumericLiteral( type, 1.0f, oneStr );

	bool isVector = numComponents > 1;
	if ( isVector ) {
		assert( sbInl );	// only don't output to an .inl file for scalar impls
	}

	Gen_DocSaturate( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s saturate( const %s& x )", fullTypeName, fullTypeName );
	if ( isVector ) {
		String_Append( sbHeader, ";\n" );
		String_Append( sbHeader, "\n" );

		String_Appendf( sbInl, "%s saturate( const %s& x )\n", fullTypeName, fullTypeName );
		String_Append(  sbInl, "{\n" );
		String_Appendf( sbInl, "\treturn %s(\n", fullTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			String_Appendf( sbInl, "\t\tclamp( x[%d], %s, %s )", i, zeroStr, oneStr );

			if ( i != numComponents - 1 ) {
				String_Append( sbInl, "," );
			}

			String_Append( sbInl, "\n" );
		}

		String_Append( sbInl, "\t);\n" );
		String_Append( sbInl, "}\n" );
		String_Append( sbInl, "\n" );
	} else {
		String_Append(  sbHeader, "\n" );
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\treturn clamp( x, %s, %s );\n", zeroStr, oneStr );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}
}

void Gen_Lerp( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( sbHeader );

	assert( numComponents >= 1 );	// we allow scalar types for this function
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1.0f, oneStr );

	bool isVector = numComponents > 1;
	if ( isVector ) {
		assert( sbInl );	// only don't output to an .inl file for scalar impls
	}

	Gen_GetDocLerp( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s lerp( const %s& a, const %s& b, const %s t )", fullTypeName, fullTypeName, fullTypeName, typeString );
	if ( isVector ) {
		String_Append( sbHeader, ";\n" );
		String_Append( sbHeader, "\n" );

		String_Appendf( sbInl, "%s lerp( const %s& a, const %s& b, const %s t )\n", fullTypeName, fullTypeName, fullTypeName, typeString );
		String_Append(  sbInl, "{\n" );
		String_Appendf( sbInl, "\treturn %s(\n", fullTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			String_Appendf( sbInl, "\t\tlerp( a[%d], b[%d], t )", i, i );

			if ( i != numComponents - 1 ) {
				String_Append( sbInl, "," );
			}

			String_Append( sbInl, "\n" );
		}

		String_Append( sbInl, "\t);\n" );
		String_Append( sbInl, "}\n" );
		String_Append( sbInl, "\n" );
	} else {
		String_Append(  sbHeader, "\n" );
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\treturn ( %s - t ) * a + t * b;\n", oneStr );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}
}

void Gen_Step( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( sbHeader );

	assert( numComponents >= 1 );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, 0.0f, zeroStr );
	Gen_GetNumericLiteral( type, 1.0f, oneStr );

	String_Appendf( sbHeader, "inline %s step( const %s& x, const %s& y )", fullTypeName, fullTypeName, fullTypeName );
	if ( numComponents > 1 ) {
		assert( sbInl );

		String_Append( sbHeader, ";\n" );
		String_Append( sbHeader, "\n" );

		String_Appendf( sbInl, "%s step( const %s& x, const %s& y )\n", fullTypeName, fullTypeName, fullTypeName );
		String_Append(  sbInl, "{\n" );
		String_Appendf( sbInl, "\treturn %s(\n", fullTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
				String_Appendf( sbInl, "\t\tstep( x[%d], y[%d] )", i, i );

				if ( i != numComponents - 1 ) {
					String_Append( sbInl, "," );
				}

				String_Append( sbInl, "\n" );
		}
		String_Appendf( sbInl, "\t);\n" );
		String_Append(  sbInl, "}\n" );
		String_Append(  sbInl, "\n" );
	} else {
		String_Append(  sbHeader, "\n" );
		String_Append(  sbHeader, "{\n" );
		String_Appendf( sbHeader, "\treturn ( y > x ? %s : %s );\n", oneStr, zeroStr );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}
}

void Gen_Smoothstep( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( sbHeader );

	assert( numComponents >= 1 );	// we allow scalar types for this function
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	char twoStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char threeStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char sixStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char tenStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char fifteenStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, 2.0f,  twoStr );
	Gen_GetNumericLiteral( type, 3.0f,  threeStr );
	Gen_GetNumericLiteral( type, 6.0f,  sixStr );
	Gen_GetNumericLiteral( type, 10.0f, tenStr );
	Gen_GetNumericLiteral( type, 15.0f, fifteenStr );

	bool isVector = numComponents > 1;
	if ( isVector ) {
		assert( sbInl );	// only don't output to an .inl file for scalar impls
	}

	// smoothstep
	{
		Gen_GetDocSmoothstep( sbHeader, fullTypeName );
		String_Appendf( sbHeader, "inline %s smoothstep( const %s& low, const %s& high, const %s& x )", fullTypeName, fullTypeName, fullTypeName, fullTypeName );
		if ( isVector ) {
			String_Append( sbHeader, ";\n" );
			String_Append( sbHeader, "\n" );

			String_Appendf( sbInl, "%s smoothstep( const %s& low, const %s& high, const %s& x )\n", fullTypeName, fullTypeName, fullTypeName, fullTypeName );
			String_Append(  sbInl, "{\n" );
			String_Appendf( sbInl, "\treturn %s(\n", fullTypeName );
			for ( u32 i = 0; i < numComponents; i++ ) {
				String_Appendf( sbInl, "\t\tsmoothstep( low[%d], high[%d], x[%d] )", i, i, i );

				if ( i != numComponents - 1 ) {
					String_Append( sbInl, "," );
				}

				String_Append( sbInl, "\n" );
			}
			String_Append( sbInl, "\t);\n" );
			String_Append( sbInl, "}\n" );
			String_Append( sbInl, "\n" );
		} else {
			String_Append(  sbHeader, "\n" );
			String_Append(  sbHeader, "{\n" );
			String_Appendf( sbHeader, "\t%s t = saturate( ( x - low ) / ( high - low ) );\n", fullTypeName );
			String_Appendf( sbHeader, "\treturn t * t * ( %s - %s * t );\n", threeStr, twoStr );
			String_Append(  sbHeader, "}\n" );
			String_Append(  sbHeader, "\n" );
		}
	}

	// smootherstep
	{
		Gen_GetDocSmootherstep( sbHeader, fullTypeName );
		String_Appendf( sbHeader, "inline %s smootherstep( const %s& low, const %s& high, const %s& x )", fullTypeName, fullTypeName, fullTypeName, fullTypeName );
		if ( isVector ) {
			String_Append( sbHeader, ";\n" );
			String_Append( sbHeader, "\n" );

			String_Appendf( sbInl, "%s smootherstep( const %s& low, const %s& high, const %s& x )\n", fullTypeName, fullTypeName, fullTypeName, fullTypeName );
			String_Append(  sbInl, "{\n" );
			String_Appendf( sbInl, "\treturn %s(\n", fullTypeName );
			for ( u32 i = 0; i < numComponents; i++ ) {
				String_Appendf( sbInl, "\t\tsmootherstep( low[%d], high[%d], x[%d] )", i, i, i );

				if ( i != numComponents - 1 ) {
					String_Append( sbInl, "," );
				}

				String_Append( sbInl, "\n" );
			}
			String_Append( sbInl, "\t);\n" );
			String_Append( sbInl, "}\n" );
			String_Append( sbInl, "\n" );
		} else {
			String_Append(  sbHeader, "\n" );
			String_Append(  sbHeader, "{\n" );
			String_Appendf( sbHeader, "\t%s t = saturate( ( x - low ) / ( high - low ) );\n", fullTypeName );
			String_Appendf( sbHeader, "\treturn t * t * t * ( t * ( t * %s - %s ) + %s );\n", sixStr, fifteenStr, tenStr );
			String_Append(  sbHeader, "}\n" );
			String_Append(  sbHeader, "\n" );
		}
	}
}

void Gen_OperatorsIncrement( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( sbHeader );
	assert( sbInl );

	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( u32 opIndex = 0; opIndex < GEN_OP_INCREMENT_COUNT; opIndex++ ) {
		genOpIncrement_t op = static_cast<genOpIncrement_t>( opIndex );

		GenerateOperatorIncrementHeader( type, numRows, numCols, op, sbHeader );
		GenerateOperatorIncrementInl( type, numRows, numCols, op, sbInl );
	}
}

void Gen_OperatorsRelational( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( sbHeader );
	assert( sbInl );

	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( u32 opIndex = 0; opIndex < GEN_OP_RELATIONAL_COUNT; opIndex++ ) {
		genOpRelational_t op = static_cast<genOpRelational_t>( opIndex );

		HeaderGenerateOperatorRelational( type, numRows, numCols, op, sbHeader );
		InlGenerateOperatorRelational( type, numRows, numCols, op, sbInl );
	}
}

void Gen_OperatorsBitwise( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( sbHeader );
	assert( sbInl );

	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type != GEN_TYPE_BOOL && !Gen_IsIntegerType( type ) ) {
		return;
	}

	// do all except unary operator
	// unary doesn't take rhs type, so do that one separately
	genOpBitwise_t ops[] = {
		GEN_OP_BITWISE_AND,
		GEN_OP_BITWISE_OR,
		GEN_OP_BITWISE_XOR,
		GEN_OP_BITWISE_SHIFT_LEFT,
		GEN_OP_BITWISE_SHIFT_RIGHT
	};

	for ( genOpBitwise_t op : ops ) {
		HeaderGenerateOperatorBitwiseScalar( type, numRows, numCols, op, sbHeader );
		HeaderGenerateOperatorBitwiseRhsType( type, numRows, numCols, op, sbHeader );

		InlGenerateOperatorBitwiseScalar( type, numRows, numCols, op, sbInl );
		InlGenerateOperatorBitwiseRhsType( type, numRows, numCols, op, sbInl );
	}

	// unary operator
	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;
	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	Gen_GetDocOperatorBitwiseUnary( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s operator~( const %s& lhs );\n", fullTypeName, fullTypeName );
	String_Append( sbHeader, "\n" );

	String_Appendf( sbInl, "%s operator~( const %s& lhs )\n", fullTypeName, fullTypeName );
	String_Append( sbInl, "{\n" );
	String_Appendf( sbInl, "\treturn %s(\n", fullTypeName );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbInl, "\t\t~lhs[%d]", i );

		if ( i != numComponents - 1 ) {
			String_Append( sbInl, "," );
		}

		String_Append( sbInl, "\n" );
	}
	String_Append( sbInl, "\t);\n" );
	String_Append( sbInl, "}\n" );
	String_Append( sbInl, "\n" );
}

void Gen_OperatorComponentWiseArithmeticScalar( const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( sbHeader );
	assert( sbInl );

	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	char opStr = GEN_OPERATORS_ARITHMETIC[op];

	Gen_GetDocOperatorArithmeticScalar( sbHeader, fullTypeName, op );
	String_Appendf( sbHeader, "inline %s operator%c( const %s& lhs, const %s rhs );\n", fullTypeName, opStr, fullTypeName, memberTypeString );
	String_Append(  sbHeader, "\n" );

	Gen_GetDocOperatorCompoundArithmeticScalar( sbHeader, fullTypeName, op );
	String_Appendf( sbHeader, "inline %s operator%c=( %s& lhs, const %s rhs );\n", fullTypeName, opStr, fullTypeName, memberTypeString );
	String_Append(  sbHeader, "\n" );

	// main arithmetic func
	String_Appendf( sbInl, "%s operator%c( const %s& lhs, const %s rhs )\n", fullTypeName, opStr, fullTypeName, memberTypeString );
	String_Append(  sbInl, "{\n" );
	String_Appendf( sbInl, "\treturn %s(\n", fullTypeName );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbInl, "\t\tlhs[%d] %c rhs", i, opStr );

		if ( i != numComponents - 1 ) {
			String_Append( sbInl, "," );
		}

		String_Append( sbInl, "\n" );
	}
	String_Append( sbInl, "\t);\n" );
	String_Append( sbInl, "}\n" );
	String_Append( sbInl, "\n" );

	// compound arithmetic func
	String_Appendf( sbInl, "%s operator%c=( %s& lhs, const %s rhs )\n", fullTypeName, opStr, fullTypeName, memberTypeString );
	String_Append(  sbInl, "{\n" );
	String_Appendf( sbInl, "\treturn ( lhs = lhs %c rhs );\n", opStr );
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

void Gen_OperatorComponentWiseArithmeticRhsType( const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( sbHeader );
	assert( sbInl );

	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	// don't generate compound arithmetic func on mul/div ops for non-square matrices
	bool canGenerateCompound = true;
	if ( op == GEN_OP_ARITHMETIC_MUL || op == GEN_OP_ARITHMETIC_DIV ) {
		if ( numRows > 1 && numRows != numCols ) {
			canGenerateCompound = false;
		}
	}

	u32 numComponents = ( numRows == 1 ) ? numCols : numRows;

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	char opStr = GEN_OPERATORS_ARITHMETIC[op];

	Gen_DocOperatorComponentWiseArithmeticRhsType( sbHeader, fullTypeName, fullTypeName, op );
	String_Appendf( sbHeader, "inline %s operator%c( const %s& lhs, const %s& rhs );\n", fullTypeName, opStr, fullTypeName, fullTypeName );
	String_Append(  sbHeader, "\n" );

	if ( canGenerateCompound ) {
		Gen_DocOperatorCompoundComponentWiseArithmeticRhsType( sbHeader, fullTypeName, fullTypeName, op );
		String_Appendf( sbHeader, "inline %s operator%c=( %s& lhs, const %s& rhs );\n", fullTypeName, opStr, fullTypeName, fullTypeName );
		String_Append(  sbHeader, "\n" );
	}

	// main arithmetic func
	String_Appendf( sbInl, "%s operator%c( const %s& lhs, const %s& rhs )\n", fullTypeName, opStr, fullTypeName, fullTypeName );
	String_Append(  sbInl, "{\n" );
	String_Appendf( sbInl, "\treturn %s(\n", fullTypeName );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbInl, "\t\tlhs[%d] %c rhs[%d]", i, opStr, i );

		if ( i != numComponents - 1 ) {
			String_Append( sbInl, "," );
		}

		String_Append( sbInl, "\n" );
	}
	String_Append( sbInl, "\t);\n" );
	String_Append( sbInl, "}\n" );
	String_Append( sbInl, "\n" );

	// compound arithmetic func
	if ( canGenerateCompound ) {
		String_Appendf( sbInl, "%s operator%c=( %s& lhs, const %s& rhs )\n", fullTypeName, opStr, fullTypeName, fullTypeName );
		String_Append(  sbInl, "{\n" );
		String_Appendf( sbInl, "\treturn ( lhs = lhs %c rhs );\n", opStr );
		String_Append(  sbInl, "}\n" );
		String_Append(  sbInl, "\n" );
	}
}

void Gen_OperatorNotEquals( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( sbHeader );
	assert( sbInl );

	assert( numRows >= 1 );	// pass through 1 for vectors
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

	Gen_DocOperatorNotEquals( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline bool operator!=( const %s& lhs, const %s& rhs );\n", fullTypeName, fullTypeName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "bool operator!=( const %s& lhs, const %s& rhs )\n", fullTypeName, fullTypeName );
	String_Append(  sbInl, "{\n" );
	String_Append(  sbInl, "\treturn !( operator==( lhs, rhs ) );\n" );
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}
