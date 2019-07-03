#include "gen_funcs_vector.h"

#include "gen_doc_common.h"

#include <assert.h>

static void DocLengthSqr( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the magnitude of the vector squared.\n", fullTypeName );
}

static void DocLength( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the magnitude of the vector.\n", fullTypeName );
}

static void DocNormalize( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Normalizes the vector.\n", fullTypeName );
}

static void DocNormalized( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a normalized copy of the vector.\n", fullTypeName );
}

static void DocDot( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the dot product of the two vectors.\n", fullTypeName );
}

static void DocCross( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a vector perpendicular (normal) to the two vectors.\n", fullTypeName );
}

static void DocAngle( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the angle in degrees between the two vectors.\n", fullTypeName );
}

static void DocDistanceSq( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the squared distance between the two vectors.\n", fullTypeName );
}

static void DocDistance( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns the distance between the two vectors.\n", fullTypeName );
}

static void DocPack( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a 32 bit integer containing each component of the vector (starting with x) at each byte.\n", fullTypeName );
}

static void DocUnpack( stringBuilder_t* sb, const char* fullTypeName ) {
	String_Appendf( sb,
		"/// \\relates %s\n" \
		"/// \\brief Returns a 4-component integer vector containing each byte of the given integer.\n", fullTypeName );
}

void Gen_GetParmListVector( const genType_t type, const u32 numComponents, const float* values, char* outParmListStr ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( values );
	assert( outParmListStr );

	char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	int pos = 0;

	pos += snprintf( outParmListStr + pos, GEN_STRING_LENGTH_PARM_LIST_VECTOR, "( " );

	for ( u32 i = 0; i < numComponents; i++ ) {
		const float value = values[i];

		Gen_GetNumericLiteral( type, value, valueStr );

		pos += snprintf( outParmListStr + pos, GEN_STRING_LENGTH_PARM_LIST_VECTOR, "%s", valueStr );

		if ( i != numComponents - 1 ) {
			pos += snprintf( outParmListStr + pos, GEN_STRING_LENGTH_PARM_LIST_VECTOR, ", " );
		}
	}

	pos += snprintf( outParmListStr + pos, GEN_STRING_LENGTH_PARM_LIST_VECTOR, " )" );
}

void Gen_VectorOperatorsArithmetic( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( u32 opIndex = 0; opIndex < GEN_OP_ARITHMETIC_COUNT; opIndex++ ) {
		genOpArithmetic_t op = static_cast<genOpArithmetic_t>( opIndex );

		Gen_OperatorComponentWiseArithmeticScalar( type, 1, numComponents, op, sbHeader, sbInl );
		Gen_OperatorComponentWiseArithmeticRhsType( type, 1, numComponents, op, sbHeader, sbInl );
	}
}

void Gen_VectorLength( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( type );

	const char* returnTypeString = Gen_GetTypeString( floatingPointType );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	const char* sqrtFuncStr = Gen_GetFuncNameSqrt( type );

	DocLengthSqr( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s lengthsqr( const %s& vec );\n", returnTypeString, fullTypeName );
	String_Append(  sbHeader, "\n" );

	DocLength( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s length( const %s& vec );\n", returnTypeString, fullTypeName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "%s lengthsqr( const %s& vec )\n", returnTypeString, fullTypeName );
	String_Append(  sbInl, "{\n" );
	String_Append(  sbInl, "\treturn " );

	if ( !Gen_IsFloatingPointType( type ) ) {
		String_Appendf( sbInl, "(%s)( ", returnTypeString );
	}

	for ( u32 i = 0; i < numComponents; i++ ) {
		char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf( sbInl, "( vec.%c * vec.%c )", componentName, componentName );

		if ( i != numComponents - 1 ) {
			String_Append( sbInl, " + " );
		}
	}

	if ( !Gen_IsFloatingPointType( type ) ) {
		String_Append( sbInl, " )" );
	}

	String_Append( sbInl, ";\n" );
	String_Append( sbInl, "}\n" );
	String_Append( sbInl, "\n" );

	String_Appendf( sbInl, "%s length( const %s& vec )\n", returnTypeString, fullTypeName );
	String_Append(  sbInl, "{\n" );
	String_Appendf( sbInl, "\treturn %s( lengthsqr( vec ) );\n", sqrtFuncStr );
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

void Gen_VectorNormalize( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1, oneStr );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	DocNormalize( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline void normalize( %s& vec );\n", fullTypeName );
	String_Append(  sbHeader, "\n" );

	DocNormalized( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s normalized( const %s& vec );\n", fullTypeName, fullTypeName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "void normalize( %s& vec )\n", fullTypeName );
	String_Append(  sbInl, "{\n" );
	String_Appendf( sbInl, "\t%s invlen = %s / length( vec );\n", typeString, oneStr );
	String_Append(  sbInl, "\tvec *= invlen;\n" );
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );

	String_Appendf( sbInl, "%s normalized( const %s& vec )\n", fullTypeName, fullTypeName );
	String_Append(  sbInl, "{\n" );
	String_Appendf( sbInl, "\t%s invlen = %s / length( vec );\n", typeString, oneStr );
	String_Appendf( sbInl, "\treturn (%s)( vec * invlen );\n", fullTypeName );
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

void Gen_VectorDot( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	// dot can return negative values, so uint vectors have to return signed int
	bool shouldTypeCast = type == GEN_TYPE_UINT;

	genType_t returnType = shouldTypeCast ? GEN_TYPE_INT : type;
	const char* returnTypeString = Gen_GetMemberTypeString( returnType );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	DocDot( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s dot( const %s& lhs, const %s& rhs );\n", returnTypeString, fullTypeName, fullTypeName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "%s dot( const %s& lhs, const %s& rhs )\n", returnTypeString, fullTypeName, fullTypeName );
	String_Append(  sbInl, "{\n" );
	String_Append(  sbInl, "\treturn " );

	if ( shouldTypeCast ) {
		String_Appendf( sbInl, "(%s)( ", returnTypeString );
	}

	for ( u32 i = 0; i < numComponents; i++ ) {
		char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf( sbInl, "( lhs.%c * rhs.%c )", componentName, componentName );

		if ( i != numComponents - 1 ) {
			String_Append( sbInl, " + " );
		}
	}

	if ( shouldTypeCast ) {
		String_Append( sbInl, " )" );
	}

	String_Append( sbInl, ";\n" );
	String_Append( sbInl, "}\n" );
	String_Append( sbInl, "\n" );
}

void Gen_VectorCross( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	if ( numComponents < 3 ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	DocCross( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s cross( const %s& lhs, const %s& rhs );\n", fullTypeName, fullTypeName, fullTypeName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "%s cross( const %s& lhs, const %s& rhs )\n", fullTypeName, fullTypeName, fullTypeName );
	String_Append(  sbInl, "{\n" );
	String_Appendf( sbInl, "\treturn %s(\n", fullTypeName );
	String_Append(  sbInl, "\t\t( lhs.y * rhs.z ) - ( lhs.z * rhs.y ),\n" );
	String_Append(  sbInl, "\t\t( lhs.z * rhs.x ) - ( lhs.x * rhs.z ),\n" );
	String_Append(  sbInl, "\t\t( lhs.x * rhs.y ) - ( lhs.y * rhs.x )" );
	if ( numComponents > 3 ) {
		String_Appendf( sbInl, ",\n\t\t%s\n", Gen_GetDefaultLiteralValue( type ) );
	} else {
		String_Append( sbInl, "\n" );
	}
	String_Append( sbInl, "\t);\n" );
	String_Append( sbInl, "}\n" );
	String_Append( sbInl, "\n" );
}

void Gen_VectorAngle( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( type );

	const char* returnTypeString = Gen_GetTypeString( floatingPointType );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	const char* acosString = Gen_GetFuncNameAcos( floatingPointType );

	DocAngle( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s angle( const %s& lhs, const %s& rhs );\n", returnTypeString, fullTypeName, fullTypeName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "%s angle( const %s& lhs, const %s& rhs )\n", returnTypeString, fullTypeName, fullTypeName );
	String_Append(  sbInl, "{\n" );
	String_Appendf( sbInl, "\treturn degrees( %s( dot( normalized( lhs ), normalized( rhs ) ) ) );\n", acosString );
	String_Append(  sbInl, "}\n" );
	String_Append(  sbInl, "\n" );
}

void Gen_VectorDistance( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( numComponents > 3 ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	const char* returnTypeString = Gen_GetTypeString( Gen_GetSupportedFloatingPointType( type ) );

	// distancesq
	{
		DocDistanceSq( sbHeader, fullTypeName );
		String_Appendf( sbHeader, "inline %s distancesqr( const %s& lhs, const %s& rhs );\n", returnTypeString, fullTypeName, fullTypeName );
		String_Append(  sbHeader, "\n" );

		String_Appendf( sbInl, "%s distancesqr( const %s& lhs, const %s& rhs )\n", returnTypeString, fullTypeName, fullTypeName );
		String_Append(  sbInl, "{\n" );
		String_Append(  sbInl, "\treturn lengthsqr( lhs - rhs );\n" );
		String_Append(  sbInl, "}\n" );
		String_Append(  sbInl, "\n" );
	}

	// distance
	{
		DocDistance( sbHeader, fullTypeName );
		String_Appendf( sbHeader, "inline %s distance( const %s& lhs, const %s& rhs );\n", returnTypeString, fullTypeName, fullTypeName );
		String_Append(  sbHeader, "\n" );

		String_Appendf( sbInl, "%s distance( const %s& lhs, const %s& rhs )\n", returnTypeString, fullTypeName, fullTypeName );
		String_Append(  sbInl, "{\n" );
		String_Append(  sbInl, "\treturn length( lhs - rhs );\n" );
		String_Append(  sbInl, "}\n" );
		String_Append(  sbInl, "\n" );
	}
}

void Gen_VectorPack( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type != GEN_TYPE_UINT ) {
		return;
	}

	if ( numComponents != 4 ) {
		return;
	}

	u32 shiftVals[] = {
		24, 16, 8, 0
	};

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	DocPack( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s pack( const %s& vec );\n", memberTypeString, fullTypeName );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "%s pack( const %s& vec )\n", memberTypeString, fullTypeName );
	String_Append(  sbInl, "{\n" );
	String_Append(  sbInl, "\treturn " );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbInl, "( vec.%c << %d )", GEN_COMPONENT_NAMES_VECTOR[i], shiftVals[i] );

		if ( i != numComponents - 1 ) {
			String_Append( sbInl, " | " );
		}
	}
	String_Append( sbInl, ";\n" );
	String_Append( sbInl, "}\n" );
	String_Append( sbInl, "\n" );
}

void Gen_VectorUnpack( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type != GEN_TYPE_UINT ) {
		return;
	}

	if ( numComponents != 4 ) {
		return;
	}

	u32 shiftVals[] = {
		24, 16, 8, 0
	};

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	const char* memberTypeString = Gen_GetMemberTypeString( type );

	DocUnpack( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s unpack( const %s x );\n", fullTypeName, memberTypeString );
	String_Append(  sbHeader, "\n" );

	String_Appendf( sbInl, "%s unpack( const %s x )\n", fullTypeName, memberTypeString );
	String_Append(  sbInl, "{\n" );
	String_Appendf( sbInl, "\treturn %s(\n", fullTypeName );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbInl, "\t\t( x >> %d ) & 0xFF", shiftVals[i] );

		if ( i != numComponents - 1 ) {
			String_Append( sbInl, "," );
		}

		String_Append( sbInl, "\n" );
	}
	String_Append( sbInl, "\t);\n" );
	String_Append( sbInl, "}\n" );
	String_Append( sbInl, "\n" );
}
