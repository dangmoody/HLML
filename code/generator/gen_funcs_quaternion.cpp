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
#include "gen_funcs_quaternion.h"

#include "gen_doc_common.h"
#include "gen_doc_vector.h"

#include <assert.h>

void Gen_QuaternionMultiply(const genType_t type, stringBuilder_t* sbHeader) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString(type);

	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName(type, 1, 1, typeName);

	String_Appendf(sbHeader, "inline %s4 quaternion_mul( const %s4& lhs, const %s4& rhs )\n", returnTypeString, typeName, typeName);
	String_Append(sbHeader, "{\n");

	String_Appendf(sbHeader, "\t%s scalar = lhs.w * rhs.w - dot( %s3( lhs ), %s3( rhs ) );\n", typeName, typeName, typeName);
	String_Appendf(sbHeader, "\t%s3 imaginary = %s3( rhs ) * lhs.w + %s3( lhs ) * rhs.w + cross( %s3( lhs ), %s3( rhs ) );\n", typeName, typeName, typeName, typeName, typeName);

	String_Appendf(sbHeader, "\treturn %s4( imaginary.x, imaginary.y, imaginary.z, scalar );\n", typeName);

	String_Append(sbHeader, "}\n");
	String_Append(sbHeader, "\n");
}

void Gen_QuaternionMultiplyScalar(const genType_t type, stringBuilder_t* sbHeader) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString(type);

	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName(type, 1, 1, typeName);

	String_Appendf(sbHeader, "inline %s4 quaternion_mul( const %s4& lhs, const %s& rhs )\n", returnTypeString, typeName, typeName);
	String_Append(sbHeader, "{\n");

	String_Appendf(sbHeader, "\t%s scalar = lhs.w * rhs;\n", typeName);
	String_Appendf(sbHeader, "\t%s3 imaginary = %s3( lhs ) * rhs;\n", typeName, typeName);

	String_Appendf(sbHeader, "\treturn %s4( imaginary.x, imaginary.y, imaginary.z, scalar );\n", typeName);

	String_Append(sbHeader, "}\n");
	String_Append(sbHeader, "\n");
}

void Gen_QuaternionLength(const genType_t type, stringBuilder_t* sbHeader) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString(type);

	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName(type, 1, 1, typeName);

	String_Appendf(sbHeader, "inline %s quaternion_length( const %s4& quat )\n", returnTypeString, typeName);
	String_Append(sbHeader, "{\n");

	String_Appendf( sbHeader, "\treturn %s( ", Gen_GetFuncNameSqrt( type ) );

	const int numComponents = 4;
	for (u32 i = 0; i < numComponents; i++) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf(sbHeader, "( quat.%c * quat.%c )", componentName, componentName);

		if (i != numComponents - 1) {
			String_Append(sbHeader, " + ");
		}
	}

	String_Append(sbHeader, " );\n");

	String_Append(sbHeader, "}\n");
	String_Append(sbHeader, "\n");
}

void Gen_QuaternionNormalize(const genType_t type, stringBuilder_t* sbHeader) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString(type);

	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName(type, 1, 1, typeName);

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral(type, 1, oneStr, 1);

	String_Appendf(sbHeader, "inline %s4 quaternion_normalize( const %s4& quat )\n", returnTypeString, typeName);
	String_Append(sbHeader, "{\n");

	String_Appendf(sbHeader, "\t%s3 normV = %s3( quat.x, quat.y, quat.z );\n", typeName, typeName);
	String_Appendf(sbHeader, "\t%s normS = quat.w;\n", typeName);
	String_Appendf(sbHeader, "\t%s mag = quaternion_length( quat );\n", typeName);
	String_Append(sbHeader, "\tif ( mag >= 0 )\n");
	String_Append(sbHeader, "\t{\n");
	String_Appendf(sbHeader, "\t\t%s magInverse = %s / mag;\n", typeName, oneStr );
	String_Append(sbHeader, "\t\tnormV *= magInverse;\n");
	String_Append(sbHeader, "\t\tnormS *= magInverse;\n");
	String_Append(sbHeader, "\t}\n");

	String_Appendf(sbHeader, "\treturn %s4( normV.x, normV.y, normV.z, normS );\n", typeName);

	String_Append(sbHeader, "}\n");
	String_Append(sbHeader, "\n");
}

void Gen_QuaternionConjugate(const genType_t type, stringBuilder_t* sbHeader) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString(type);
	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName(type, 1, 1, typeName);

	String_Appendf(sbHeader, "inline %s4 quaternion_conjugate( const %s4& quat )\n", returnTypeString, typeName);
	String_Append(sbHeader, "{\n");

	String_Appendf(sbHeader, "\treturn %s4( ", typeName);

	const int numComponents = 3;
	for (u32 i = 0; i < numComponents; i++) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf(sbHeader, "( quat.%c * ( -1 ) )", componentName);
		String_Append(sbHeader, ", ");
	}

	String_Appendf(sbHeader, "quat.w );\n");

	String_Append(sbHeader, "}\n");
	String_Append(sbHeader, "\n");
}

void Gen_QuaternionInverse(const genType_t type, stringBuilder_t* sbHeader) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString(type);
	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName(type, 1, 1, typeName);

	String_Appendf(sbHeader, "inline %s4 quaternion_inverse( const %s4& quat )\n", returnTypeString, typeName);
	String_Append(sbHeader, "{\n");

	String_Appendf(sbHeader, "\t%s magnitude = quaternion_length( quat );\n", typeName);
	String_Append(sbHeader, "\tmagnitude *= magnitude;\n");
	String_Append(sbHeader, "\tmagnitude = 1 / magnitude;\n");

	String_Appendf(sbHeader, "\t%s4 conjugate = quaternion_conjugate( quat );\n", typeName);
	String_Appendf(sbHeader, "\t%s scalar = conjugate.w * magnitude;\n", typeName);
	String_Appendf(sbHeader, "\t%s3 imaginary = %s3( conjugate.x * magnitude, conjugate.y * magnitude, conjugate.z * magnitude );\n", typeName, typeName);
	String_Appendf(sbHeader, "\treturn %s4( imaginary.x, imaginary.y, imaginary.z, scalar );\n", typeName);

	String_Append(sbHeader, "}\n");
	String_Append(sbHeader, "\n");
}

void Gen_QuaternionRotationAxis(const genType_t type, stringBuilder_t* sbHeader) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString(type);
	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName(type, 1, 1, typeName);

	char halfStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral(type, 0.5f, halfStr, 1);

	const char* sinFunc = Gen_GetFuncNameSin( type );
	const char* cosFunc = Gen_GetFuncNameCos( type );

	String_Appendf(sbHeader, "inline %s3 quaternion_rotate_axis( const %s4& quat, const %s angle, const %s3 axis )\n", returnTypeString, typeName, typeName, typeName);
	String_Append(sbHeader, "{\n");

	String_Appendf(sbHeader, "\t%s4 pureQuat = %s4( quat.x, quat.y, quat.z, 0 );\n", typeName, typeName);
	String_Appendf(sbHeader, "\t%s3 normalizedAxis = axis;\n", typeName );
	String_Append(sbHeader, "\tnormalize(normalizedAxis);\n");
	String_Appendf(sbHeader, "\t%s4 realQuat = %s4( normalizedAxis.x, normalizedAxis.y, normalizedAxis.z, angle );\n", typeName, typeName);
	String_Append(sbHeader, "\n");

	// Converts the quaternion into its unit-norm format
	String_Appendf(sbHeader, "\t%s3 imaginary = %s3( realQuat.x, realQuat.y, realQuat.z );\n", typeName, typeName);
	String_Appendf(sbHeader, "\t%s3 normalizedImaginary = imaginary;\n", typeName);
	String_Append(sbHeader, "\tnormalize(normalizedImaginary);\n");
	String_Appendf(sbHeader, "\t%s unitNormScalar = %s( realQuat.w * %s );\n", typeName, cosFunc, halfStr);
	String_Appendf(sbHeader, "\t%s3 unitNormImaginary = normalizedImaginary * %s( quat.w * %s );\n", typeName, sinFunc, halfStr);
	String_Appendf(sbHeader, "\t%s4 unitNormQuat = %s4( unitNormImaginary.x, unitNormImaginary.y, unitNormImaginary.z, unitNormScalar );\n", typeName, typeName);
	String_Append(sbHeader, "\n");
	
	String_Appendf(sbHeader, "\t%s4 inverseQuat = quaternion_inverse( unitNormQuat );\n", typeName);
	String_Appendf(sbHeader, "\t%s4 rotatedVector = unitNormQuat * pureQuat * inverseQuat;\n", typeName);
	String_Appendf(sbHeader, "\treturn %s3( rotatedVector.x, rotatedVector.y, rotatedVector.z );\n", typeName);

	String_Append(sbHeader, "}\n");
	String_Append(sbHeader, "\n");
}

void Gen_QuaternionLerp(const genType_t type, stringBuilder_t* sbHeader) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString(type);
	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName(type, 1, 1, typeName);

	String_Appendf(sbHeader, "inline %s4 quaternion_lerp( const %s4& lhs, const %s4 rhs, const %s percent )\n", returnTypeString, typeName, typeName, typeName);
	String_Append(sbHeader, "{\n");

	String_Appendf(sbHeader, "\t%s4 quat;\n", typeName, typeName);
	String_Appendf(sbHeader, "\t%s t = 1 - percent;\n", typeName);
	
	for (u32 i = 0; i < GEN_COMPONENT_COUNT_MAX; i++) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf(sbHeader, "\tquat.%c = t * lhs.%c + percent * rhs.%c;\n", componentName, componentName, componentName);
	}

	String_Appendf(sbHeader, "\treturn quaternion_normalize( quat );\n", typeName);

	String_Append(sbHeader, "}\n");
	String_Append(sbHeader, "\n");
}

void Gen_QuaternionSlerp(const genType_t type, stringBuilder_t* sbHeader) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString(type);
	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName(type, 1, 1, typeName);

	const char* sinFunc = Gen_GetFuncNameSin( type );

	String_Appendf(sbHeader, "inline %s4 quaternion_slerp( const %s4& lhs, const %s4 rhs, const %s percent )\n", returnTypeString, typeName, typeName, typeName);
	String_Append(sbHeader, "{\n");

	String_Appendf(sbHeader, "\t%s4 quat;\n", typeName, typeName);
	String_Appendf(sbHeader, "\t%s t = 1 - percent;\n", typeName);

	String_Appendf(sbHeader, "\t%s theta = %s( ", typeName, Gen_GetFuncNameAcos( type ));

	const int numComponents = GEN_COMPONENT_COUNT_MAX;
	for (u32 i = 0; i < numComponents; i++) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf(sbHeader, "( lhs.%c * rhs.%c )", componentName, componentName);

		if (i != numComponents - 1) {
			String_Append(sbHeader, " + ");
		}
	}

	String_Append(sbHeader, " );\n");
	String_Appendf(sbHeader, "\t%s sn = %s( theta );\n", typeName, sinFunc);

	String_Appendf(sbHeader, "\t%s Wa = %s( t * theta ) / sn;\n", typeName, sinFunc);
	String_Appendf(sbHeader, "\t%s Wb = %s( percent * theta ) / sn;\n", typeName, sinFunc);

	for (u32 i = 0; i < numComponents; i++) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf(sbHeader, "\tquat.%c = Wa * rhs.%c + Wb * lhs.%c;\n", componentName, componentName, componentName);
	}

	String_Appendf(sbHeader, "\treturn quaternion_normalize( quat );\n", typeName);

	String_Append(sbHeader, "}\n");
	String_Append(sbHeader, "\n");
}