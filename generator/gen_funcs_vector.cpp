#include "gen_funcs_vector.h"

#include <assert.h>

std::string Gen_GetParmListVector( const genType_t type, const uint32_t numComponents, const float* values ) {
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

	std::string sqrtString = ( floatingPointType == GEN_TYPE_DOUBLE ) ? "sqrt" : "sqrtf";

	outHeader += "inline " + returnTypeString + " lengthsqr( const " + fullTypeName + "& vec );\n";
	outHeader += "inline " + returnTypeString + " length( const " + fullTypeName + "& vec );\n";
	outHeader += "\n";

	outInl += returnTypeString + " lengthsqr( const " + fullTypeName + "& vec ) {\n";
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

	outInl += returnTypeString + " length( const " + fullTypeName + "& vec ) {\n";
	outInl += "\treturn " + sqrtString + "( lengthsqr( vec ) );\n";
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

	outHeader += "inline void normalize( " + fullTypeName + "& vec );\n";
	outHeader += "inline " + fullTypeName + " normalized( const " + fullTypeName + "& vec );\n";
	outHeader += "\n";

	outInl += "void normalize( " + fullTypeName + "& vec ) {\n";
	outInl += "\t" + typeString + " invlen = " + oneStr + " / length( vec );\n";
	outInl += "\tvec *= invlen;\n";
	outInl += "}\n";
	outInl += "\n";

	outInl += fullTypeName + " normalized( const " + fullTypeName + "& vec ) {\n";
	outInl += "\t" + typeString + " invlen = " + oneStr + " / length( vec );\n";
	outInl += "\treturn (" + fullTypeName + ") vec * invlen;\n";
	outInl += "}\n";
	outInl += "\n";
}

void Gen_VectorDot( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL || type == GEN_TYPE_UINT ) {
		return;
	}

	std::string typeString = Gen_GetTypeString( type );
	std::string returnTypeString = Gen_GetTypeString( Gen_GetSupportedFloatingPointType( type ) );
	std::string fullTypeName = typeString + std::to_string( numComponents );

	outHeader += "inline " + returnTypeString + " dot( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";
	outHeader += "\n";

	outInl += returnTypeString + " dot( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs ) {\n";
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

	outHeader += "inline " + fullTypeName + " cross( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";
	outHeader += "\n";

	outInl += fullTypeName + " cross( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs ) {\n";
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

	std::string acosString = ( floatingPointType == GEN_TYPE_DOUBLE ) ? "acos" : "acosf";

	std::string degreesFuncStr = Gen_GetFuncNameDegrees( type );

	outHeader += "inline " + returnTypeString + " angle( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs );\n";
	outHeader += "\n";

	outInl += returnTypeString + " angle( const " + fullTypeName + "& lhs, const " + fullTypeName + "& rhs ) {\n";
	outInl += "\treturn " + degreesFuncStr + "( " + acosString + "( dot( normalized( lhs ), normalized( rhs ) ) ) );\n";
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
	std::string saturateFuncStr = Gen_GetFuncNameSaturate( type );

	outHeader += "inline " + fullTypeName + " saturate( const " + fullTypeName + "& vec );\n";
	outHeader += "\n";

	outInl += fullTypeName + " saturate( const " + fullTypeName + "& vec ) {\n";
	outInl += "\treturn " + fullTypeName + "(\n";
	for ( uint32_t i = 0; i < numComponents; i++ ) {
		outInl += "\t\t" + saturateFuncStr + "( vec." + GEN_COMPONENT_NAMES_VECTOR[i] + " )";

		if ( i != numComponents - 1 ) {
			outInl += ",";
		}

		outInl += "\n";
	}
	outInl += "\t);\n";
	outInl += "}\n";
	outInl += "\n";
}