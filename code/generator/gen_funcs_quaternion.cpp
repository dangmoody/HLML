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

void Gen_QuaternionMultiply( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString(type);

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName(type, 1, 1, typeName);
	
	char mulQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionMultiplyQuaternion( language, type, mulQuaternionFuncStr );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 4, parmTypeName );
	
	String_Appendf( sbFwdDec, "inline %s4 %s( const %s lhs, const %s rhs );\n", returnTypeString, mulQuaternionFuncStr, parmTypeName, parmTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "inline %s4 %s( const %s lhs, const %s rhs )\n", returnTypeString, mulQuaternionFuncStr, parmTypeName, parmTypeName );
	String_Append(  sbImpl, "{\n" );

	String_Appendf( sbImpl, "\t%s4 quat;\n", typeName );
	String_Appendf( sbImpl, "\tquat.x = lhs%sx * rhs%sw + lhs%sy * rhs%sz - lhs%sz * rhs%sy + lhs%sw * rhs%sx;\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
	String_Appendf( sbImpl, "\tquat.y = -lhs%sx * rhs%sz + lhs%sy * rhs%sw + lhs%sz * rhs%sx + lhs%sw * rhs%sy;\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
	String_Appendf( sbImpl, "\tquat.z = lhs%sx * rhs%sy - lhs%sy * rhs%sx + lhs%sz * rhs%sw + lhs%sw * rhs%sz;\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
	String_Appendf( sbImpl, "\tquat.w = -lhs%sx * rhs%sx - lhs%sy * rhs%sy - lhs%sz * rhs%sz + lhs%sw * rhs%sw;\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr);

	String_Append( sbImpl, "\treturn quat;\n" );

	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );
}

void Gen_QuaternionMultiplyScalar( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString( type );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, 1, typeName );
	
	char mulQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionMultiplyScalar( language, type, mulQuaternionFuncStr );

	char lhsParmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 4, lhsParmTypeName );

	char rhsParmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 1, rhsParmTypeName );

	String_Appendf( sbFwdDec, "inline %s4 %s( const %s lhs, const %s rhs );\n", returnTypeString, mulQuaternionFuncStr, lhsParmTypeName, rhsParmTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "inline %s4 %s( const %s lhs, const %s rhs )\n", returnTypeString, mulQuaternionFuncStr, lhsParmTypeName, rhsParmTypeName );
	String_Append(  sbImpl, "{\n" );

	String_Appendf( sbImpl, "\t%s scalar = lhs%sw * rhs;\n", typeName, parmAccessStr );

	if ( language == GEN_LANGUAGE_C ) {		
		char compFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_GetFuncNameComponentWiseArithmeticScalar( language, type, 1, 3, GEN_OP_ARITHMETIC_MUL, compFuncStr );

		String_Appendf( sbImpl, "\t%s3 imaginary = (%s3) { lhs%sx, lhs%sy, lhs%sz };\n", typeName, typeName, parmAccessStr, parmAccessStr, parmAccessStr );
		String_Appendf( sbImpl, "\timaginary = %s( &imaginary, rhs );\n", compFuncStr);
	}
	else {
		String_Appendf( sbImpl, "\t%s3 imaginary = %s3( lhs ) * rhs;\n", typeName, typeName );
	}

	String_Appendf( sbImpl, "\treturn HLML_CONSTRUCT( %s4 ) { imaginary.x, imaginary.y, imaginary.z, scalar };\n", typeName );

	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );
}

void Gen_QuaternionLength( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString( type );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, 1, typeName );
	
	char lengthQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionLength( language, type, lengthQuaternionFuncStr );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 4, parmTypeName );
	
	String_Appendf( sbFwdDec, "inline %s %s( const %s quat );\n", returnTypeString, lengthQuaternionFuncStr, parmTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "inline %s %s( const %s quat )\n", returnTypeString, lengthQuaternionFuncStr, parmTypeName );
	String_Append(  sbImpl, "{\n" );

	String_Appendf( sbImpl, "\treturn %s( ", Gen_GetFuncNameSqrt( type ) );

	const int numComponents = 4;
	for (u32 i = 0; i < numComponents; i++) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf( sbImpl, "( quat%s%c * quat%s%c )", parmAccessStr, componentName, parmAccessStr, componentName );

		if (i != numComponents - 1) {
			String_Append( sbImpl, " + " );
		}
	}

	String_Append( sbImpl, " );\n" );

	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );
}

void Gen_QuaternionNormalize( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString( type );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, 1, typeName );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1, oneStr, 1 );
	
	char lengthQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionLength( language, type, lengthQuaternionFuncStr );
	
	char normalizeQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionNormalize( language, type, normalizeQuaternionFuncStr );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 4, parmTypeName );
	
	String_Appendf( sbFwdDec, "inline %s4 %s( const %s quat );\n", returnTypeString, normalizeQuaternionFuncStr, parmTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "inline %s4 %s( const %s quat )\n", returnTypeString, normalizeQuaternionFuncStr, parmTypeName );
	String_Append(  sbImpl, "{\n");

	String_Appendf( sbImpl, "\t%s3 normV = HLML_CONSTRUCT( %s3 ) { quat%sx, quat%sy, quat%sz };\n", typeName, typeName, parmAccessStr, parmAccessStr, parmAccessStr );
	String_Appendf( sbImpl, "\t%s normS = quat%sw;\n", typeName, parmAccessStr );
	String_Appendf( sbImpl, "\t%s mag = %s( quat );\n", typeName, lengthQuaternionFuncStr );
	String_Append(  sbImpl, "\tif ( mag >= 0 )\n" );
	String_Append(  sbImpl, "\t{\n" );
	String_Appendf( sbImpl, "\t\t%s magInverse = %s / mag;\n", typeName, oneStr );
	
	if ( language == GEN_LANGUAGE_C ) {		
		char compFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_GetFuncNameComponentWiseArithmeticScalar( language, type, 1, 3, GEN_OP_ARITHMETIC_MUL, compFuncStr );
		
		String_Appendf(  sbImpl, "\t\tnormV = %s( &normV, magInverse );\n", compFuncStr );
	}
	else {
		String_Append(  sbImpl, "\t\tnormV *= magInverse;\n" );
	}
	String_Append(  sbImpl, "\t\tnormS *= magInverse;\n" );
	String_Append(  sbImpl, "\t}\n" );

	String_Appendf( sbImpl, "\treturn HLML_CONSTRUCT( %s4 ) { normV.x, normV.y, normV.z, normS };\n", typeName );

	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );
}

void Gen_QuaternionConjugate( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString( type );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, 1, typeName );
	
	char conjugateQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionConjugate( language, type, conjugateQuaternionFuncStr );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 4, parmTypeName );
	
	String_Appendf( sbFwdDec, "inline %s4 %s( const %s quat );\n", returnTypeString, conjugateQuaternionFuncStr, parmTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "inline %s4 %s( const %s quat )\n", returnTypeString, conjugateQuaternionFuncStr, parmTypeName );
	String_Append(  sbImpl, "{\n" );

	String_Appendf( sbImpl, "\treturn HLML_CONSTRUCT (%s4) { ", typeName );

	const int numComponents = 3;
	for (u32 i = 0; i < numComponents; i++) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf( sbImpl, "( quat%s%c * ( -1 ) )", parmAccessStr, componentName );
		String_Append(  sbImpl, ", " );
	}

	String_Appendf( sbImpl, "quat%sw };\n", parmAccessStr );

	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );
}

void Gen_QuaternionInverse( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString( type );

	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, 1, typeName );
	
	char lengthQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionLength( language, type, lengthQuaternionFuncStr );
	
	char conjugateQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionConjugate( language, type, conjugateQuaternionFuncStr );
	
	char inverseQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionInverse( language, type, inverseQuaternionFuncStr );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 4, parmTypeName );
	
	String_Appendf( sbFwdDec, "inline %s4 %s( const %s quat );\n", returnTypeString, inverseQuaternionFuncStr, parmTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "inline %s4 %s( const %s quat )\n", returnTypeString, inverseQuaternionFuncStr, parmTypeName );
	String_Append(  sbImpl, "{\n");

	String_Appendf( sbImpl, "\t%s magnitude = %s( quat );\n", typeName, lengthQuaternionFuncStr );
	String_Append(  sbImpl, "\tmagnitude *= magnitude;\n" );
	String_Append(  sbImpl, "\tmagnitude = 1 / magnitude;\n" );

	String_Appendf( sbImpl, "\t%s4 conjugate = %s( quat );\n", typeName, conjugateQuaternionFuncStr );
	String_Appendf( sbImpl, "\t%s scalar = conjugate.w * magnitude;\n", typeName );
	String_Appendf( sbImpl, "\t%s3 imaginary = HLML_CONSTRUCT( %s3 ) { conjugate.x * magnitude, conjugate.y * magnitude, conjugate.z * magnitude };\n", typeName, typeName );
	String_Appendf( sbImpl, "\treturn HLML_CONSTRUCT (%s4) { imaginary.x, imaginary.y, imaginary.z, scalar };\n", typeName );

	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );
}

void Gen_QuaternionRotationAxis( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString( type );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, 1, typeName );

	char halfStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 0.5f, halfStr, 1 );

	char inverseQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionInverse( language, type, inverseQuaternionFuncStr );

	char mulQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionMultiplyQuaternion( language, type, mulQuaternionFuncStr );
	
	char rotateQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionRotateVectorAngleAxis( language, type, rotateQuaternionFuncStr );

	char normVectorFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameNormalize( language, type, 3, normVectorFuncStr );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 3, parmTypeName );
	
	String_Appendf( sbFwdDec, "inline %s3 %s( const %s vect, const %s angle, const %s axis );\n", returnTypeString, rotateQuaternionFuncStr, parmTypeName, typeName, parmTypeName );
	String_Append(  sbFwdDec, "\n" );

	const char* sinFunc = Gen_GetFuncNameSin( type );
	const char* cosFunc = Gen_GetFuncNameCos( type );

	String_Appendf( sbImpl, "inline %s3 %s( const %s vect, const %s angle, const %s axis )\n", returnTypeString, rotateQuaternionFuncStr, parmTypeName, typeName, parmTypeName );
	String_Append(  sbImpl, "{\n" );

	String_Appendf( sbImpl, "\t%s4 pureQuat = HLML_CONSTRUCT( %s4 ) { vect%sx, vect%sy, vect%sz, 0 };\n", typeName, typeName, parmAccessStr, parmAccessStr, parmAccessStr );

	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( sbImpl, "\t%s3 normalizedAxis = *axis;\n", typeName );
		String_Appendf( sbImpl, "\t%s( &normalizedAxis );\n", normVectorFuncStr );
	}
	else {
		String_Appendf( sbImpl, "\t%s3 normalizedAxis = axis;\n", typeName );
		String_Appendf( sbImpl, "\t%s( normalizedAxis );\n", normVectorFuncStr );
	}

	String_Appendf( sbImpl, "\t%s4 realQuat = HLML_CONSTRUCT( %s4 ) { normalizedAxis.x, normalizedAxis.y, normalizedAxis.z, angle };\n", typeName, typeName );
	String_Append(  sbImpl, "\n" );

	// Converts the quaternion into its unit-norm format
	String_Appendf( sbImpl, "\t%s3 imaginary = HLML_CONSTRUCT( %s3 ) { realQuat.x, realQuat.y, realQuat.z };\n", typeName, typeName );
	String_Appendf( sbImpl, "\t%s3 normalizedImaginary = imaginary;\n", typeName );

	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( sbImpl, "\t%s( &normalizedImaginary );\n", normVectorFuncStr );
	}
	else {
		String_Appendf( sbImpl, "\t%s( normalizedImaginary );\n", normVectorFuncStr );
	}

	String_Appendf( sbImpl, "\t%s unitNormScalar = %s( realQuat.w * %s );\n", typeName, cosFunc, halfStr );

	if ( language == GEN_LANGUAGE_C ) {
		char compFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_GetFuncNameComponentWiseArithmeticScalar( language, type, 1, 3, GEN_OP_ARITHMETIC_MUL, compFuncStr );
		
		String_Appendf( sbImpl, "\t%s sinResult = %s( realQuat.w * %s );\n", typeName, sinFunc, halfStr );
		String_Appendf( sbImpl, "\t%s3 unitNormImaginary = %s( &normalizedImaginary, sinResult );\n", typeName, compFuncStr );
	}
	else {
		String_Appendf( sbImpl, "\t%s3 unitNormImaginary = normalizedImaginary * %s( realQuat.w * %s );\n", typeName, sinFunc, halfStr );
	}

	String_Appendf( sbImpl, "\t%s4 unitNormQuat = HLML_CONSTRUCT( %s4 ) { unitNormImaginary.x, unitNormImaginary.y, unitNormImaginary.z, unitNormScalar };\n", typeName, typeName );
	String_Append(  sbImpl, "\n" );
	
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( sbImpl, "\t%s4 inverseQuat = %s( &unitNormQuat );\n", typeName, inverseQuaternionFuncStr );
		String_Appendf( sbImpl, "\t%s4 rotatedVector = %s( &unitNormQuat, &pureQuat );\n", typeName, mulQuaternionFuncStr );
		String_Appendf( sbImpl, "\trotatedVector = %s( &rotatedVector, &inverseQuat );\n", mulQuaternionFuncStr );
	}
	else {
		String_Appendf( sbImpl, "\t%s4 inverseQuat = %s( unitNormQuat );\n", typeName, inverseQuaternionFuncStr );
		String_Appendf( sbImpl, "\t%s4 rotatedVector = %s( %s( unitNormQuat, pureQuat ), inverseQuat );\n", typeName, mulQuaternionFuncStr, mulQuaternionFuncStr );
	}
	String_Appendf( sbImpl, "\treturn HLML_CONSTRUCT( %s3 ) { rotatedVector.x, rotatedVector.y, rotatedVector.z };\n", typeName );

	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );
}

void Gen_QuaternionLerp( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString( type );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, 1, typeName );
	
	char normQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionNormalize( language, type, normQuaternionFuncStr );

	char lerpQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionLerp( language, type, lerpQuaternionFuncStr );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 4, parmTypeName );
	
	String_Appendf( sbFwdDec, "inline %s4 %s( const %s lhs, const %s rhs, const %s percent );\n", returnTypeString, lerpQuaternionFuncStr, parmTypeName, parmTypeName, typeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "inline %s4 %s( const %s lhs, const %s rhs, const %s percent )\n", returnTypeString, lerpQuaternionFuncStr, parmTypeName, parmTypeName, typeName );
	String_Append(  sbImpl, "{\n" );

	String_Appendf( sbImpl, "\t%s4 quat;\n", typeName, typeName );
	String_Appendf( sbImpl, "\t%s t = 1 - percent;\n", typeName );
	
	for (u32 i = 0; i < GEN_COMPONENT_COUNT_MAX; i++) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf( sbImpl, "\tquat.%c = t * lhs%s%c + percent * rhs%s%c;\n", componentName, parmAccessStr, componentName, parmAccessStr, componentName );
	}

	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( sbImpl, "\treturn %s( &quat );\n", normQuaternionFuncStr );
	}
	else {
		String_Appendf( sbImpl, "\treturn %s( quat );\n", normQuaternionFuncStr );
	}

	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );
}

void Gen_QuaternionSlerp( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString(type);

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char typeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName(type, 1, 1, typeName);

	char normQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionNormalize( language, type, normQuaternionFuncStr );
	
	char slerpQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionSlerp( language, type, slerpQuaternionFuncStr );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 4, parmTypeName );
	
	String_Appendf( sbFwdDec, "inline %s4 %s( const %s lhs, const %s rhs, const %s percent );\n", returnTypeString, slerpQuaternionFuncStr, parmTypeName, parmTypeName, typeName );
	String_Append(  sbFwdDec, "\n" );

	const char* sinFunc = Gen_GetFuncNameSin( type );

	String_Appendf( sbImpl, "inline %s4 %s( const %s lhs, const %s rhs, const %s percent )\n", returnTypeString, slerpQuaternionFuncStr, parmTypeName, parmTypeName, typeName );
	String_Append(  sbImpl, "{\n" );

	String_Appendf( sbImpl, "\t%s4 quat;\n", typeName, typeName );
	String_Appendf( sbImpl, "\t%s t = 1 - percent;\n", typeName );

	String_Appendf( sbImpl, "\t%s theta = %s( ", typeName, Gen_GetFuncNameAcos( type ) );

	const int numComponents = GEN_COMPONENT_COUNT_MAX;
	for (u32 i = 0; i < numComponents; i++) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf( sbImpl, "( lhs%s%c * rhs%s%c )", parmAccessStr, componentName, parmAccessStr, componentName );

		if (i != numComponents - 1) {
			String_Append( sbImpl, " + " );
		}
	}

	String_Append(  sbImpl, " );\n" );
	String_Appendf( sbImpl, "\t%s sn = %s( theta );\n", typeName, sinFunc );

	String_Appendf( sbImpl, "\t%s Wa = %s( t * theta ) / sn;\n", typeName, sinFunc );
	String_Appendf( sbImpl, "\t%s Wb = %s( percent * theta ) / sn;\n", typeName, sinFunc );

	for (u32 i = 0; i < numComponents; i++) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf( sbImpl, "\tquat.%c = Wa * rhs%s%c + Wb * lhs%s%c;\n", componentName, parmAccessStr, componentName, parmAccessStr, componentName );
	}
	
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( sbImpl, "\treturn %s( &quat );\n", normQuaternionFuncStr );
	}
	else {
		String_Appendf( sbImpl, "\treturn %s( quat );\n", normQuaternionFuncStr );
	}

	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );
}