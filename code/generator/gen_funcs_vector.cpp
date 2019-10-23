/*
===========================================================================

HLML Generator.
Copyright (c) Dan Moody 2018 - Present.

This file is part of the HLML Generator.

The HLML Generator is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

The HLML Generator is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with The HLML Generator.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/
#include "gen_funcs_vector.h"

#include "gen_doc_common.h"
#include "gen_doc_vector.h"

#include <assert.h>

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

void Gen_VectorOperatorsArithmetic( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	for ( u32 opIndex = 0; opIndex < GEN_OP_ARITHMETIC_COUNT; opIndex++ ) {
		genOpArithmetic_t op = (genOpArithmetic_t) opIndex;

		Gen_OperatorComponentWiseArithmeticScalar( type, 1, numComponents, op, sbHeader );
		Gen_OperatorComponentWiseArithmeticRhsType( type, 1, numComponents, op, sbHeader );
	}
}

void Gen_VectorLength( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
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

	Doc_VectorLengthSqr( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s lengthsqr( const %s& vec )\n", returnTypeString, fullTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Append(  sbHeader, "\treturn " );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		String_Appendf( sbHeader, "(%s)( ", returnTypeString );
	}

	for ( u32 i = 0; i < numComponents; i++ ) {
		char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf( sbHeader, "( vec.%c * vec.%c )", componentName, componentName );

		if ( i != numComponents - 1 ) {
			String_Append( sbHeader, " + " );
		}
	}

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		String_Append( sbHeader, " )" );
	}

	String_Append( sbHeader, ";\n" );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );

	Doc_VectorLength( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s length( const %s& vec )\n", returnTypeString, fullTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\treturn %s( lengthsqr( vec ) );\n", sqrtFuncStr );
	String_Append(  sbHeader, "}\n" );
	String_Append(  sbHeader, "\n" );
}

void Gen_VectorNormalize( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1, oneStr, 1 );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	Doc_VectorNormalize( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline void normalize( %s& vec )\n", fullTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s invlen = %s / length( vec );\n", typeString, oneStr );
	String_Append(  sbHeader, "\tvec *= invlen;\n" );
	String_Append(  sbHeader, "}\n" );
	String_Append(  sbHeader, "\n" );

	Doc_VectorNormalized( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s normalized( const %s& vec )\n", fullTypeName, fullTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\t%s invlen = %s / length( vec );\n", typeString, oneStr );
	String_Appendf( sbHeader, "\treturn (%s)( vec * invlen );\n", fullTypeName );
	String_Append(  sbHeader, "}\n" );
	String_Append(  sbHeader, "\n" );
}

void Gen_VectorDot( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
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

	Doc_VectorDot( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s dot( const %s& lhs, const %s& rhs )\n", returnTypeString, fullTypeName, fullTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Append(  sbHeader, "\treturn " );

	if ( shouldTypeCast ) {
		String_Appendf( sbHeader, "(%s)( ", returnTypeString );
	}

	for ( u32 i = 0; i < numComponents; i++ ) {
		char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf( sbHeader, "( lhs.%c * rhs.%c )", componentName, componentName );

		if ( i != numComponents - 1 ) {
			String_Append( sbHeader, " + " );
		}
	}

	if ( shouldTypeCast ) {
		String_Append( sbHeader, " )" );
	}

	String_Append( sbHeader, ";\n" );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

void Gen_VectorCross( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	if ( numComponents < 3 ) {
		return;
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	Doc_VectorCross( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s cross( const %s& lhs, const %s& rhs )\n", fullTypeName, fullTypeName, fullTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\treturn %s(\n", fullTypeName );
	String_Append(  sbHeader, "\t\t( lhs.y * rhs.z ) - ( lhs.z * rhs.y ),\n" );
	String_Append(  sbHeader, "\t\t( lhs.z * rhs.x ) - ( lhs.x * rhs.z ),\n" );
	String_Append(  sbHeader, "\t\t( lhs.x * rhs.y ) - ( lhs.y * rhs.x )" );
	if ( numComponents > 3 ) {
		String_Appendf( sbHeader, ",\n\t\t%s\n", Gen_GetDefaultLiteralValue( type ) );
	} else {
		String_Append( sbHeader, "\n" );
	}
	String_Append( sbHeader, "\t);\n" );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

void Gen_VectorAngle( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( type );

	const char* returnTypeString = Gen_GetTypeString( floatingPointType );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, numComponents, fullTypeName );

	const char* degreesFuncStr = Gen_GetFuncNameDegrees( type );

	const char* acosString = Gen_GetFuncNameAcos( floatingPointType );

	Doc_VectorAngle( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s angle( const %s& lhs, const %s& rhs )\n", returnTypeString, fullTypeName, fullTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\treturn %s( %s( dot( normalized( lhs ), normalized( rhs ) ) ) );\n", degreesFuncStr, acosString );
	String_Append(  sbHeader, "}\n" );
	String_Append(  sbHeader, "\n" );
}

void Gen_VectorDistance( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
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
		Doc_VectorDistanceSq( sbHeader, fullTypeName );
		String_Appendf( sbHeader, "inline %s distancesqr( const %s& lhs, const %s& rhs )\n", returnTypeString, fullTypeName, fullTypeName );
		String_Append(  sbHeader, "{\n" );
		String_Append(  sbHeader, "\treturn lengthsqr( lhs - rhs );\n" );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}

	// distance
	{
		Doc_VectorDistance( sbHeader, fullTypeName );
		String_Appendf( sbHeader, "inline %s distance( const %s& lhs, const %s& rhs )\n", returnTypeString, fullTypeName, fullTypeName );
		String_Append(  sbHeader, "{\n" );
		String_Append(  sbHeader, "\treturn length( lhs - rhs );\n" );
		String_Append(  sbHeader, "}\n" );
		String_Append(  sbHeader, "\n" );
	}
}

void Gen_VectorPack( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
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

	Doc_VectorPack( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s pack( const %s& vec )\n", memberTypeString, fullTypeName );
	String_Append(  sbHeader, "{\n" );
	String_Append(  sbHeader, "\treturn " );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbHeader, "( vec.%c << %d )", GEN_COMPONENT_NAMES_VECTOR[i], shiftVals[i] );

		if ( i != numComponents - 1 ) {
			String_Append( sbHeader, " | " );
		}
	}
	String_Append( sbHeader, ";\n" );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}

void Gen_VectorUnpack( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader ) {
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

	Doc_VectorUnpack( sbHeader, fullTypeName );
	String_Appendf( sbHeader, "inline %s unpack( const %s x )\n", fullTypeName, memberTypeString );
	String_Append(  sbHeader, "{\n" );
	String_Appendf( sbHeader, "\treturn %s(\n", fullTypeName );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( sbHeader, "\t\t( x >> %d ) & 0xFF", shiftVals[i] );

		if ( i != numComponents - 1 ) {
			String_Append( sbHeader, "," );
		}

		String_Append( sbHeader, "\n" );
	}
	String_Append( sbHeader, "\t);\n" );
	String_Append( sbHeader, "}\n" );
	String_Append( sbHeader, "\n" );
}
