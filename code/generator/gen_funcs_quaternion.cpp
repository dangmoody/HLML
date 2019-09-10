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

void Gen_GetParmListQuaternion(const genType_t type, const float* values, char* outParmListStr) {
	assert(values);
	assert(outParmListStr);

	char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	int pos = 0;

	pos += snprintf(outParmListStr + pos, GEN_STRING_LENGTH_PARM_LIST_VECTOR, "( ");

	for (u32 i = 0; i < 4; i++) {
		const float value = values[i];

		Gen_GetNumericLiteral(type, value, valueStr);

		pos += snprintf(outParmListStr + pos, GEN_STRING_LENGTH_PARM_LIST_VECTOR, "%s", valueStr);

		if (i != 3) {
			pos += snprintf(outParmListStr + pos, GEN_STRING_LENGTH_PARM_LIST_VECTOR, ", ");
		}
	}

	pos += snprintf(outParmListStr + pos, GEN_STRING_LENGTH_PARM_LIST_VECTOR, " )");
}

void Gen_QuaternionMultiply(const genType_t type, stringBuilder_t* sbHeader, stringBuilder_t* sbInl) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString(type);

	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName(type, 1, 1, typeName);

	//Doc_VectorDot(sbHeader, type4Name);
	String_Appendf(sbHeader, "inline %s quaternion_mul( const %s4& lhs, const %s4& rhs );\n", returnTypeString, typeName, typeName);
	String_Append(sbHeader, "\n");

	String_Appendf(sbInl, "%s quaternion_mul( const %s4& lhs, const %s4& rhs )\n", returnTypeString, typeName, typeName);
	String_Append(sbInl, "{\n");

	String_Appendf(sbInl, "\t%s scalar = lhs.w * rhs.w - dot(%s3(lhs), %s3(rhs));\n", typeName, typeName, typeName);
	String_Appendf(sbInl, "\t%s3 imaginary = %s3(rhs) * lhs.w + %s3(lhs) * rhs.w + cross(%s3(lhs), %s3(rhs));\n", typeName, typeName, typeName, typeName, typeName);

	String_Appendf(sbInl, "\treturn %s4(imaginary.x, imaginary.y, imaginary.z, scalar.w);\n", typeName);

	String_Append(sbInl, "}\n");
	String_Append(sbInl, "\n");
}

void Gen_QuaternionMultiplyScalar(const genType_t type, stringBuilder_t* sbHeader, stringBuilder_t* sbInl) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString(type);

	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName(type, 1, 1, typeName);

	//Doc_VectorDot(sbHeader, type4Name);
	String_Appendf(sbHeader, "inline %s quaternion_mul( const %s4& lhs, const %s& rhs );\n", returnTypeString, typeName, typeName);
	String_Append(sbHeader, "\n");

	String_Appendf(sbInl, "%s quaternion_mul( const %s4& lhs, const %s& rhs )\n", returnTypeString, typeName, typeName);
	String_Append(sbInl, "{\n");

	String_Appendf(sbInl, "\t%s scalar = lhs.w * rhs;\n", typeName);
	String_Appendf(sbInl, "\t%s3 imaginary = %s3(lhs) * rhs;\n", typeName, typeName);

	String_Appendf(sbInl, "\treturn %s4(imaginary.x, imaginary.y, imaginary.z, scalar.w);\n", typeName);

	String_Append(sbInl, "}\n");
	String_Append(sbInl, "\n");
}

void Gen_QuaternionMagnitude(const genType_t type, stringBuilder_t* sbHeader, stringBuilder_t* sbInl) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString(type);

	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName(type, 1, 1, typeName);

	//Doc_VectorDot(sbHeader, type4Name);
	String_Appendf(sbHeader, "inline %s quaternion_magnitude( const %s4& quat );\n", returnTypeString, typeName);
	String_Append(sbHeader, "\n");

	String_Appendf(sbInl, "%s quaternion_magnitude( const %s4& quat )\n", returnTypeString, typeName);
	String_Append(sbInl, "{\n");

	String_Appendf(sbInl, "\treturn sqrt(", typeName);

	const int numComponents = 4;
	for (u32 i = 0; i < numComponents; i++) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf(sbInl, "( quat.%c * quat.%c )", componentName, componentName);

		if (i != numComponents - 1) {
			String_Append(sbInl, " + ");
		}
	}

	String_Append(sbInl, ");\n");

	String_Append(sbInl, "}\n");
	String_Append(sbInl, "\n");
}

void Gen_QuaternionNormalize(const genType_t type, stringBuilder_t* sbHeader, stringBuilder_t* sbInl) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString(type);

	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName(type, 1, 1, typeName);

	//Doc_VectorDot(sbHeader, type4Name);
	String_Appendf(sbHeader, "inline %s4 quaternion_normalize( const %s4& quat );\n", returnTypeString, typeName);
	String_Append(sbHeader, "\n");

	String_Appendf(sbInl, "%s4 quaternion_normalize( const %s4& quat )\n", returnTypeString, typeName);
	String_Append(sbInl, "{\n");

	String_Appendf(sbInl, "\t%s3 normV;\n", typeName);
	String_Appendf(sbInl, "\t%s normS;\n", typeName);
	String_Appendf(sbInl, "\t%s mag = quaternion_magnitude(quat);\n", typeName);
	String_Append(sbInl, "\tif (mag != 0)\n");
	String_Append(sbInl, "\t{\n");
	String_Appendf(sbInl, "\t\t%s magInverse = 1.0f / mag;\n", typeName);
	String_Appendf(sbInl, "\t\t%s3 normV *= magInverse;\n", typeName);
	String_Appendf(sbInl, "\t\t%s normS *= magInverse;\n", typeName);
	String_Append(sbInl, "\t}\n");

	String_Appendf(sbInl, "\treturn %s4(normV.x, normV.y, normV.z, normS);\n", typeName);

	String_Append(sbInl, "}\n");
	String_Append(sbInl, "\n");
}

void Gen_QuaternionConjugate(const genType_t type, stringBuilder_t* sbHeader, stringBuilder_t* sbInl) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString(type);
	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName(type, 1, 1, typeName);

	//Doc_VectorDot(sbHeader, type4Name);
	String_Appendf(sbHeader, "inline %s4 quaternion_conjugate( const %s4& quat );\n", returnTypeString, typeName);
	String_Append(sbHeader, "\n");

	String_Appendf(sbInl, "%s4 quaternion_conjugate( const %s4& quat )\n", returnTypeString, typeName);
	String_Append(sbInl, "{\n");

	String_Appendf(sbInl, "\t%s scalar = quat.w;\n", typeName);
	String_Appendf(sbInl, "\t%s3 imaginary = float3(", typeName);

	const int numComponents = 3;
	for (u32 i = 0; i < numComponents; i++) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf(sbInl, "( quat.%c * ( -1 ) )", componentName);

		if (i != numComponents - 1) {
			String_Append(sbInl, ", ");
		}
	}

	String_Append(sbInl, " );\n");

	String_Appendf(sbInl, "\treturn %s4(imaginary.x, imaginary.y, imaginary.z, scalar);\n", typeName);

	String_Append(sbInl, "}\n");
	String_Append(sbInl, "\n");
}