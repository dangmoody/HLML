#include "gen_funcs_vector.h"

#include "gen_doc_common.h"

#include <assert.h>

// TODO(DM): move these functions into their own file
static std::string GetDocLengthSqr( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" + \
		"/// \\brief Returns the magnitude of the vector squared.\n";
}

static std::string GetDocLength( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" + \
		"/// \\brief Returns the magnitude of the vector.\n";
}

static std::string GetDocNormalize( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" + \
		"/// \\brief Normalizes the vector.\n";
}

static std::string GetDocNormalized( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" + \
		"/// \\brief Returns a normalized copy of the vector.\n";
}

static std::string GetDocDot( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" + \
		"/// \\brief Returns the dot product of the two vectors.\n";
}

static std::string GetDocCross( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" + \
		"/// \\brief Returns a vector perpendicular (normal) to the two vectors.\n";
}

static std::string GetDocAngle( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" + \
		"/// \\brief Returns the angle in degrees between the two vectors.\n";
}

static std::string GetDocSaturate( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" + \
		"/// \\brief Returns a copy of the vector with each component clamped between the range 0 and 1.\n";
}

static std::string GetDocLerp( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" + \
		"/// \\brief Returns a linearly interpolated vector between vectors \"a\" and \"b\".\n";
}

static std::string GetDocPack( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" + \
		"/// \\brief Returns a 32 bit integer containing each component of the vector (starting with x) at each byte.\n";
}

static std::string GetDocUnpack( const std::string& fullTypeName ) {
	return "/// \\relates " + fullTypeName + "\n" + \
		"/// \\brief Returns a 4-component integer vector containing each byte of the given integer.\n";
}

static std::string HeaderGetArithmeticFuncScalar( const genType_t type, const uint32_t numComponents, const genOpArithmetic_t op ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	std::string fullTypeName = Gen_GetTypeString( type ) + std::to_string( numComponents );
	std::string memberTypeString = Gen_GetMemberTypeString( type );

	char opStr = GEN_OPERATORS_ARITHMETIC[op];

	// TODO(DM): this is repeated here and in gen_funcs_matrix.cpp
	std::string code;

	code += Gen_GetDocOperatorArithmeticScalar( fullTypeName, op );
	code += "inline " + fullTypeName + " operator" + opStr + "( const " + fullTypeName + "& lhs, const " + memberTypeString + " rhs );\n";
	code += "\n";

	code += Gen_GetDocOperatorCompoundArithmeticScalar( fullTypeName, op );
	code += "inline " + fullTypeName + " operator" + opStr + "=( " + fullTypeName + "& lhs, const " + memberTypeString + " rhs );\n";
	code += "\n";

	return code;
}

static std::string InlGetArithmeticFuncScalar( const genType_t type, const uint32_t numComponents, const genOpArithmetic_t op ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	std::string fullTypeName = Gen_GetTypeString( type ) + std::to_string( numComponents );
	std::string memberTypeString = Gen_GetMemberTypeString( type );

	char opStr = GEN_OPERATORS_ARITHMETIC[op];

	std::string code;

	// main arithmetic func
	code += fullTypeName + " operator" + opStr + "( const " + fullTypeName + "& lhs, const " + memberTypeString + " rhs )\n";
	code += "\treturn " + fullTypeName + "(\n";
	for ( uint32_t componentIndex = 0; componentIndex < numComponents; componentIndex++ ) {
		code += std::string( "\t\tlhs." ) + GEN_COMPONENT_NAMES_VECTOR[componentIndex] + " " + opStr + " rhs";
		if ( componentIndex != numComponents - 1 ) {
			code += ",";
		}
		code += "\n";
	}
	code += "\t);\n";
	code += "}\n";
	code += "\n";

	// compound arithmetic func
	code += fullTypeName + " operator" + opStr + "=( " + fullTypeName + "& lhs, const " + memberTypeString + " rhs )\n";
	code += std::string( "\treturn ( lhs = lhs " ) + opStr + " rhs );\n";
	code += "}\n";
	code += "\n";

	return code;
}

std::string Gen_GetParmListVector( const genType_t type, const uint32_t numComponents, const float* values ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( values );

	std::string parmList = "( ";
	for ( uint32_t i = 0; i < numComponents; i++ ) {
		parmList += Gen_GetNumericLiteral( type, values[i] );

		if ( i != numComponents - 1 ) {
			parmList += ", ";
		}
	}
	parmList += " )";

	return parmList;
}

void Gen_VectorOperatorsArithmetic( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( uint32_t opIndex = 0; opIndex < GEN_OP_ARITHMETIC_COUNT; opIndex++ ) {
		genOpArithmetic_t op = static_cast<genOpArithmetic_t>( opIndex );

		Gen_OperatorComponentWiseArithmeticScalar( type, 1, numComponents, op, outHeader, outInl );
		Gen_OperatorComponentWiseArithmeticRhsType( type, 1, numComponents, op, outHeader, outInl );
	}
}

void Gen_VectorLength( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( type );

	std::string typeString = Gen_GetTypeString( type );
	std::string returnTypeString = Gen_GetTypeString( floatingPointType );
	std::string fullTypeName = typeString + std::to_string( numComponents );

	std::string sqrtFuncStr = Gen_GetFuncNameSqrt( type );

	outHeader += GetDocLengthSqr( fullTypeName );
	outHeader += "inline " + returnTypeString + " lengthsqr( const " + fullTypeName + "& vec );\n";
	outHeader += "\n";

	outHeader += GetDocLength( fullTypeName );
	outHeader += "inline " + returnTypeString + " length( const " + fullTypeName + "& vec );\n";
	outHeader += "\n";

	outInl += returnTypeString + " lengthsqr( const " + fullTypeName + "& vec )\n";
	outInl += "{\n";
	outInl += "\treturn ";
	for ( uint32_t i = 0; i < numComponents; i++ ) {
		char componentName = GEN_COMPONENT_NAMES_VECTOR[i];
		outInl += std::string( "( vec." ) + componentName + " * vec." + componentName + " )";

		if ( i != numComponents - 1 ) {
			outInl += " + ";
		}
	}
	outInl += ";\n";
	outInl += "}\n";
	outInl += "\n";

	outInl += returnTypeString + " length( const " + fullTypeName + "& vec )\n";
	outInl += "{\n";
	outInl += "\treturn " + sqrtFuncStr + "( lengthsqr( vec ) );\n";
	outInl += "}\n";
	outInl += "\n";
}

void Gen_VectorNormalize( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = typeString + std::to_string( numComponents );

	std::string oneStr = Gen_GetNumericLiteral( type, 1 );

	outHeader += GetDocNormalize( fullTypeName );
	outHeader += "inline void normalize( " + fullTypeName + "& vec );\n";
	outHeader += "\n";

	outHeader += GetDocNormalized( fullTypeName );
	outHeader += "inline " + fullTypeName + " normalized( const " + fullTypeName + "& vec );\n";
	outHeader += "\n";

	outInl += "void normalize( " + fullTypeName + "& vec )\n";
	outInl += "{\n";
	outInl += "\t" + typeString + " invlen = " + oneStr + " / length( vec );\n";
	outInl += "\tvec *= invlen;\n";
	outInl += "}\n";
	outInl += "\n";

	outInl += fullTypeName + " normalized( const " + fullTypeName + "& vec )\n";
	outInl += "{\n";
	outInl += "\t" + typeString + " invlen = " + oneStr + " / length( vec );\n";
	outInl += "\treturn (" + fullTypeName + ") vec * invlen;\n";
	outInl += "}\n";
	outInl += "\n";
}

void Gen_VectorDot( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string returnTypeString = Gen_GetTypeString( Gen_GetSupportedFloatingPointType( type ) );
	std::string fullTypeName = typeString + std::to_string( numComponents );

	outHeader += GetDocDot( fullTypeName );
	outHeader += "inline " + returnTypeString + " dot( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";
	outHeader += "\n";

	outInl += returnTypeString + " dot( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs )\n";
	outInl += "{\n";
	outInl += "\treturn ";
	for ( uint32_t i = 0; i < numComponents; i++ ) {
		outInl += "( " + std::string( "lhs." ) + GEN_COMPONENT_NAMES_VECTOR[i] + std::string( " * " ) + std::string( "rhs." ) + GEN_COMPONENT_NAMES_VECTOR[i] + " )";

		if ( i != numComponents - 1 ) {
			outInl += " + ";
		}
	}
	outInl += ";\n";
	outInl += "}\n";
	outInl += "\n";
}

void Gen_VectorCross( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	if ( numComponents < 3 ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = typeString + std::to_string( numComponents );

	outHeader += GetDocCross( fullTypeName );
	outHeader += "inline " + fullTypeName + " cross( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";
	outHeader += "\n";

	outInl += fullTypeName + " cross( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs )\n";
	outInl += "{\n";
	outInl += "\treturn " + fullTypeName + "(\n";
	outInl += "\t\t( lhs.y * rhs.z ) - ( lhs.z * rhs.y ),\n";
	outInl += "\t\t( lhs.z * rhs.x ) - ( lhs.x * rhs.z ),\n";
	outInl += "\t\t( lhs.x * rhs.y ) - ( lhs.y * rhs.x )";
	if ( numComponents > 3 ) {
		outInl += ",\n\t\t" + Gen_GetDefaultLiteralValue( type ) + "\n";
	} else {
		outInl += "\n";
	}
	outInl += "\t);\n";
	outInl += "}\n";
	outInl += "\n";
}

void Gen_VectorAngle( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( type );

	std::string typeString = Gen_GetTypeString( type );
	std::string returnTypeString = Gen_GetTypeString( floatingPointType );
	std::string fullTypeName = typeString + std::to_string( numComponents );

	std::string acosString = Gen_GetFuncNameAcos( floatingPointType );

	outHeader += GetDocAngle( fullTypeName );
	outHeader += "inline " + returnTypeString + " angle( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";
	outHeader += "\n";

	outInl += returnTypeString + " angle( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs )\n";
	outInl += "{\n";
	outInl += "\treturn degrees( " + acosString + "( dot( normalized( lhs ), normalized( rhs ) ) ) );\n";
	outInl += "}\n";
	outInl += "\n";
}

void Gen_VectorSaturate( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = typeString + std::to_string( numComponents );

	std::string zeroStr = Gen_GetNumericLiteral( type, 0.0f );
	std::string oneStr = Gen_GetNumericLiteral( type, 1.0f );

	outHeader += GetDocSaturate( fullTypeName );
	outHeader += "inline " + fullTypeName + " saturate( const " + fullTypeName + "& vec );\n";
	outHeader += "\n";

	outInl += fullTypeName + " saturate( const " + fullTypeName + "& vec )\n";
	outInl += "{\n";
	outInl += "\treturn " + fullTypeName + "(\n";
	for ( uint32_t i = 0; i < numComponents; i++ ) {
		outInl += std::string( "\t\tsaturate( vec." ) + GEN_COMPONENT_NAMES_VECTOR[i] + " )";

		if ( i != numComponents - 1 ) {
			outInl += ",";
		}

		outInl += "\n";
	}
	outInl += "\t);\n";
	outInl += "}\n";
	outInl += "\n";
}

void Gen_VectorLerp( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl ) {
	if ( !Gen_IsFloatingPointType( type ) ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = typeString + std::to_string( numComponents );

	outHeader += GetDocLerp( fullTypeName );
	outHeader += "inline " + fullTypeName + " lerp( const " + fullTypeName + "& a, const " + fullTypeName + "& b, const " + typeString + " t );\n";
	outHeader += "\n";

	outInl += fullTypeName + " lerp( const " + fullTypeName + "& a, const " + fullTypeName + "& b, const " + typeString + " t )\n";
	outInl += "{\n";
	outInl += "\treturn " + fullTypeName + "(\n";
	for ( uint32_t i = 0; i < numComponents; i++ ) {
		char component = GEN_COMPONENT_NAMES_VECTOR[i];

		outInl += std::string( "\t\tlerp( a." ) + component + ", b." + component + ", t )";

		if ( i != numComponents - 1 ) {
			outInl += ",";
		}

		outInl += "\n";
	}
	outInl += "\t);\n";
	outInl += "}\n";
	outInl += "\n";
}

void Gen_VectorPack( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsIntegerType( type ) ) {
		return;
	}

	if ( numComponents != 4 ) {
		return;
	}

	uint32_t shiftVals[] = {
		24, 16, 8, 0
	};

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = typeString + std::to_string( numComponents );

	std::string memberTypeString = Gen_GetMemberTypeString( type );

	outHeader += GetDocPack( fullTypeName );
	outHeader += "inline " + memberTypeString + " pack( const " + fullTypeName + "& vec );\n";
	outHeader += "\n";

	outInl += memberTypeString + " pack( const " + fullTypeName + "& vec )\n";
	outInl += "{\n";
	outInl += "\treturn ";
	for ( uint32_t i = 0; i < numComponents; i++ ) {
		outInl += std::string( "( vec." ) + GEN_COMPONENT_NAMES_VECTOR[i] + " << " + std::to_string( shiftVals[i] ) + " )";

		if ( i != numComponents - 1 ) {
			outInl += " | ";
		}
	}
	outInl += ";\n";
	outInl += "}\n";
	outInl += "\n";
}

void Gen_VectorUnpack( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_IsIntegerType( type ) ) {
		return;
	}

	if ( numComponents != 4 ) {
		return;
	}

	uint32_t shiftVals[] = {
		24, 16, 8, 0
	};

	std::string typeString = Gen_GetTypeString( type );
	std::string fullTypeName = typeString + std::to_string( numComponents );

	std::string memberTypeString = Gen_GetMemberTypeString( type );

	outHeader += GetDocUnpack( fullTypeName );
	outHeader += "inline " + fullTypeName + " unpack( const " + memberTypeString + " x );\n";
	outHeader += "\n";

	outInl += fullTypeName + " unpack( const " + memberTypeString + " x )\n";
	outInl += "{\n";
	outInl += "\treturn " + fullTypeName + "(\n";
	for ( uint32_t i = 0; i < numComponents; i++ ) {
		outInl += "\t\t( x >> " + std::to_string( shiftVals[i] ) + " ) & 0xFF";

		if ( i != numComponents - 1 ) {
			outInl += ",";
		}

		outInl += "\n";
	}
	outInl += "\t);\n";
	outInl += "}\n";
	outInl += "\n";
}