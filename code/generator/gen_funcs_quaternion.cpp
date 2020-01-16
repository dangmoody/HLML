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
#include "gen_doc_quaternion.h"

#include <assert.h>

void Gen_QuaternionMultiply( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	if ( Gen_TypeIsFloatingPoint( type ) == false ) {
		return;
	}

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, 4, fullTypeName );
	
	char mulQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionMultiplyQuaternion( language, type, mulQuaternionFuncStr );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 4, parmTypeName );
	
	Doc_QuaternionMultiplyRhsType( sbFwdDec, fullTypeName );
	String_Appendf( sbFwdDec, "inline %s %s( const %s lhs, const %s rhs );\n", fullTypeName, mulQuaternionFuncStr, parmTypeName, parmTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "inline %s %s( const %s lhs, const %s rhs )\n", fullTypeName, mulQuaternionFuncStr, parmTypeName, parmTypeName );
	String_Append(  sbImpl, "{\n" );

	String_Appendf( sbImpl, "\t%s quat;\n", fullTypeName );
	String_Appendf( sbImpl, "\tquat.x = lhs%sx * rhs%sw + lhs%sy * rhs%sz - lhs%sz * rhs%sy + lhs%sw * rhs%sx;\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
	String_Appendf( sbImpl, "\tquat.y = -lhs%sx * rhs%sz + lhs%sy * rhs%sw + lhs%sz * rhs%sx + lhs%sw * rhs%sy;\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
	String_Appendf( sbImpl, "\tquat.z = lhs%sx * rhs%sy - lhs%sy * rhs%sx + lhs%sz * rhs%sw + lhs%sw * rhs%sz;\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr );
	String_Appendf( sbImpl, "\tquat.w = -lhs%sx * rhs%sx - lhs%sy * rhs%sy - lhs%sz * rhs%sz + lhs%sw * rhs%sw;\n", parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr, parmAccessStr);

	String_Append( sbImpl, "\treturn quat;\n" );

	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );
}

void Gen_QuaternionMultiplyScalar( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	if ( Gen_TypeIsFloatingPoint( type ) == false ) {
		return;
	}

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	const char* typeString = Gen_GetTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, 4, fullTypeName );
	
	char mulQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionMultiplyScalar( language, type, mulQuaternionFuncStr );

	char lhsParmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 4, lhsParmTypeName );

	char rhsParmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 1, rhsParmTypeName );

	Doc_QuaternionMultiplyScalar( sbFwdDec, fullTypeName );
	String_Appendf( sbFwdDec, "inline %s %s( const %s lhs, const %s rhs );\n", fullTypeName, mulQuaternionFuncStr, lhsParmTypeName, rhsParmTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "inline %s %s( const %s lhs, const %s rhs )\n", fullTypeName, mulQuaternionFuncStr, lhsParmTypeName, rhsParmTypeName );
	String_Append(  sbImpl, "{\n" );

	String_Appendf( sbImpl, "\t%s scalar = lhs%sw * rhs;\n", typeString, parmAccessStr );

	if ( language == GEN_LANGUAGE_C ) {
		char compFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_GetFuncNameComponentWiseArithmeticScalar( language, type, 1, 3, GEN_OP_ARITHMETIC_MUL, compFuncStr );

		String_Appendf( sbImpl, "\t%s3 imaginary = (%s3) { lhs%sx, lhs%sy, lhs%sz };\n", typeString, typeString, parmAccessStr, parmAccessStr, parmAccessStr );
		String_Appendf( sbImpl, "\timaginary = %s( &imaginary, rhs );\n", compFuncStr);
	}
	else {
		String_Appendf( sbImpl, "\t%s3 imaginary = %s3( lhs.x, lhs.y, lhs.z ) * rhs;\n", typeString, typeString );
	}

	String_Appendf( sbImpl, "\treturn HLML_CONSTRUCT( %s ) { imaginary.x, imaginary.y, imaginary.z, scalar };\n", fullTypeName );

	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );
}

void Gen_QuaternionLength( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	if ( Gen_TypeIsFloatingPoint( type ) == false ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, 4, fullTypeName );
	
	char lengthQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionLength( language, type, lengthQuaternionFuncStr );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 4, parmTypeName );
	
	Doc_QuaternionLength( sbFwdDec, fullTypeName );
	String_Appendf( sbFwdDec, "inline %s %s( const %s quat );\n", typeString, lengthQuaternionFuncStr, parmTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "inline %s %s( const %s quat )\n", typeString, lengthQuaternionFuncStr, parmTypeName );
	String_Append(  sbImpl, "{\n" );

	String_Appendf( sbImpl, "\treturn %s( ", Gen_GetFuncNameSqrt( type ) );

	const int numComponents = 4;
	for ( u32 i = 0; i < numComponents; i++ ) {
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
	if ( Gen_TypeIsFloatingPoint( type ) == false ) {
		return;
	}

	const char* returnTypeString = Gen_GetMemberTypeString( type );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	const char* typeString = Gen_GetTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, 4, fullTypeName );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1, oneStr, 1 );
	
	char lengthQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionLength( language, type, lengthQuaternionFuncStr );
	
	char normalizeQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionNormalize( language, type, normalizeQuaternionFuncStr );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 4, parmTypeName );
	
	Doc_QuaternionNormalize( sbFwdDec, fullTypeName );
	String_Appendf( sbFwdDec, "inline %s4 %s( const %s quat );\n", returnTypeString, normalizeQuaternionFuncStr, parmTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "inline %s4 %s( const %s quat )\n", returnTypeString, normalizeQuaternionFuncStr, parmTypeName );
	String_Append(  sbImpl, "{\n");

	String_Appendf( sbImpl, "\t%s3 normV = HLML_CONSTRUCT( %s3 ) { quat%sx, quat%sy, quat%sz };\n", typeString, typeString, parmAccessStr, parmAccessStr, parmAccessStr );
	String_Appendf( sbImpl, "\t%s normS = quat%sw;\n", typeString, parmAccessStr );
	String_Appendf( sbImpl, "\t%s mag = %s( quat );\n", typeString, lengthQuaternionFuncStr );
	String_Append(  sbImpl, "\tif ( mag >= 0 )\n" );
	String_Append(  sbImpl, "\t{\n" );
	String_Appendf( sbImpl, "\t\t%s magInverse = %s / mag;\n", typeString, oneStr );
	
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

	String_Appendf( sbImpl, "\treturn HLML_CONSTRUCT( %s ) { normV.x, normV.y, normV.z, normS };\n", fullTypeName );

	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );
}

void Gen_QuaternionConjugate( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	if ( Gen_TypeIsFloatingPoint( type ) == false ) {
		return;
	}

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, 4, fullTypeName );
	
	char conjugateQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionConjugate( language, type, conjugateQuaternionFuncStr );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 4, parmTypeName );
	
	Doc_QuaternionConjugate( sbFwdDec, fullTypeName );
	String_Appendf( sbFwdDec, "inline %s %s( const %s quat );\n", fullTypeName, conjugateQuaternionFuncStr, parmTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "inline %s %s( const %s quat )\n", fullTypeName, conjugateQuaternionFuncStr, parmTypeName );
	String_Append(  sbImpl, "{\n" );

	String_Appendf( sbImpl, "\treturn HLML_CONSTRUCT( %s ) { ", fullTypeName );

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
	if ( Gen_TypeIsFloatingPoint( type ) == false ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, 4, fullTypeName );
	
	char lengthQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionLength( language, type, lengthQuaternionFuncStr );
	
	char conjugateQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionConjugate( language, type, conjugateQuaternionFuncStr );
	
	char inverseQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionInverse( language, type, inverseQuaternionFuncStr );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 4, parmTypeName );
	
	Doc_QuaternionInverse( sbFwdDec, fullTypeName );
	String_Appendf( sbFwdDec, "inline %s %s( const %s quat );\n", fullTypeName, inverseQuaternionFuncStr, parmTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "inline %s %s( const %s quat )\n", fullTypeName, inverseQuaternionFuncStr, parmTypeName );
	String_Append(  sbImpl, "{\n");

	String_Appendf( sbImpl, "\t%s magnitude = %s( quat );\n", typeString, lengthQuaternionFuncStr );
	String_Append(  sbImpl, "\tmagnitude *= magnitude;\n" );
	String_Append(  sbImpl, "\tmagnitude = 1 / magnitude;\n" );

	String_Appendf( sbImpl, "\t%s conjugate = %s( quat );\n", fullTypeName, conjugateQuaternionFuncStr );
	String_Appendf( sbImpl, "\t%s scalar = conjugate.w * magnitude;\n", typeString );
	String_Appendf( sbImpl, "\t%s3 imaginary = HLML_CONSTRUCT( %s3 ) { conjugate.x * magnitude, conjugate.y * magnitude, conjugate.z * magnitude };\n", typeString, typeString );
	String_Appendf( sbImpl, "\treturn HLML_CONSTRUCT( %s ) { imaginary.x, imaginary.y, imaginary.z, scalar };\n", fullTypeName );
	String_Append(  sbImpl, "}\n" );
	String_Append(  sbImpl, "\n" );
}

void Gen_QuaternionRotationAxis( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	if ( Gen_TypeIsFloatingPoint( type ) == false ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, 4, fullTypeName );

	char halfStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 0.5f, halfStr, 1 );

	char inverseQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionInverse( language, type, inverseQuaternionFuncStr );

	char mulQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionMultiplyQuaternion( language, type, mulQuaternionFuncStr );
	
	char rotateQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionRotate( language, type, rotateQuaternionFuncStr );

	char normVectorFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameNormalize( language, type, 3, normVectorFuncStr );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 3, parmTypeName );

	const char* sinFunc = Gen_GetFuncNameSin( type );
	const char* cosFunc = Gen_GetFuncNameCos( type );

	Doc_QuaternionRotateAxis( sbFwdDec, fullTypeName );
	String_Appendf( sbFwdDec, "inline %s3 %s( const %s vect, const %s angle, const %s axis );\n", typeString, rotateQuaternionFuncStr, parmTypeName, typeString, parmTypeName );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "inline %s3 %s( const %s vect, const %s angle, const %s axis )\n", typeString, rotateQuaternionFuncStr, parmTypeName, typeString, parmTypeName );
	String_Append(  sbImpl, "{\n" );

	String_Appendf( sbImpl, "\t%s pureQuat = HLML_CONSTRUCT( %s ) { vect%sx, vect%sy, vect%sz, 0 };\n", fullTypeName, fullTypeName, parmAccessStr, parmAccessStr, parmAccessStr );

	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( sbImpl, "\t%s3 normalizedAxis = *axis;\n", typeString );
		String_Appendf( sbImpl, "\t%s( &normalizedAxis );\n", normVectorFuncStr );
	}
	else {
		String_Appendf( sbImpl, "\t%s3 normalizedAxis = axis;\n", typeString );
		String_Appendf( sbImpl, "\t%s( normalizedAxis );\n", normVectorFuncStr );
	}

	String_Appendf( sbImpl, "\t%s realQuat = HLML_CONSTRUCT( %s ) { normalizedAxis.x, normalizedAxis.y, normalizedAxis.z, angle };\n", fullTypeName, fullTypeName );
	String_Append(  sbImpl, "\n" );

	// Converts the quaternion into its unit-norm format
	String_Appendf( sbImpl, "\t%s3 imaginary = HLML_CONSTRUCT( %s3 ) { realQuat.x, realQuat.y, realQuat.z };\n", typeString, typeString );
	String_Appendf( sbImpl, "\t%s3 normalizedImaginary = imaginary;\n", typeString );

	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( sbImpl, "\t%s( &normalizedImaginary );\n", normVectorFuncStr );
	}
	else {
		String_Appendf( sbImpl, "\t%s( normalizedImaginary );\n", normVectorFuncStr );
	}

	String_Appendf( sbImpl, "\t%s unitNormScalar = %s( realQuat.w * %s );\n", typeString, cosFunc, halfStr );

	if ( language == GEN_LANGUAGE_C ) {
		char compFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_GetFuncNameComponentWiseArithmeticScalar( language, type, 1, 3, GEN_OP_ARITHMETIC_MUL, compFuncStr );
		
		String_Appendf( sbImpl, "\t%s sinResult = %s( realQuat.w * %s );\n", typeString, sinFunc, halfStr );
		String_Appendf( sbImpl, "\t%s3 unitNormImaginary = %s( &normalizedImaginary, sinResult );\n", typeString, compFuncStr );
	}
	else {
		String_Appendf( sbImpl, "\t%s3 unitNormImaginary = normalizedImaginary * %s( realQuat.w * %s );\n", typeString, sinFunc, halfStr );
	}

	String_Appendf( sbImpl, "\t%s unitNormQuat = HLML_CONSTRUCT( %s ) { unitNormImaginary.x, unitNormImaginary.y, unitNormImaginary.z, unitNormScalar };\n", fullTypeName, fullTypeName );
	String_Append(  sbImpl, "\n" );
	
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( sbImpl, "\t%s inverseQuat = %s( &unitNormQuat );\n", fullTypeName, inverseQuaternionFuncStr );
		String_Appendf( sbImpl, "\t%s rotatedVector = %s( &unitNormQuat, &pureQuat );\n", fullTypeName, mulQuaternionFuncStr );
		String_Appendf( sbImpl, "\trotatedVector = %s( &rotatedVector, &inverseQuat );\n", mulQuaternionFuncStr );
	}
	else {
		String_Appendf( sbImpl, "\t%s inverseQuat = %s( unitNormQuat );\n", fullTypeName, inverseQuaternionFuncStr );
		String_Appendf( sbImpl, "\t%s rotatedVector = %s( %s( unitNormQuat, pureQuat ), inverseQuat );\n", fullTypeName, mulQuaternionFuncStr, mulQuaternionFuncStr );
	}
	String_Appendf( sbImpl, "\treturn HLML_CONSTRUCT( %s3 ) { rotatedVector.x, rotatedVector.y, rotatedVector.z };\n", typeString );

	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );
}

void Gen_QuaternionLerp( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	if ( Gen_TypeIsFloatingPoint( type ) == false ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( type );

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];
		
	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1, oneStr, 1 );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, 4, fullTypeName );
	
	char normQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionNormalize( language, type, normQuaternionFuncStr );

	char lerpQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionLerp( language, type, lerpQuaternionFuncStr );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 4, parmTypeName );

	Doc_Lerp( sbFwdDec, fullTypeName );
	String_Appendf( sbFwdDec, "inline %s %s( const %s lhs, const %s rhs, const %s percent );\n", fullTypeName, lerpQuaternionFuncStr, parmTypeName, parmTypeName, typeString );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "inline %s %s( const %s lhs, const %s rhs, const %s percent )\n", fullTypeName, lerpQuaternionFuncStr, parmTypeName, parmTypeName, typeString );
	String_Append(  sbImpl, "{\n" );

	String_Appendf( sbImpl, "\t%s quat;\n", fullTypeName );
	String_Appendf( sbImpl, "\t%s t = %s - percent;\n", typeString, oneStr );
	
	for ( u32 i = 0; i < GEN_COMPONENT_COUNT_MAX; i++ ) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf( sbImpl, "\tquat.%c = t * lhs%s%c + percent * rhs%s%c;\n", componentName, parmAccessStr, componentName, parmAccessStr, componentName );
	}

	String_Append( sbImpl, "\treturn quat;\n" );
	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );
}

void Gen_QuaternionSlerp( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl ) {
	if (Gen_TypeIsFloatingPoint(type) == false) {
		return;
	}

	const char* typeString = Gen_GetTypeString(type);

	const char* parmAccessStr = GEN_TYPE_ACCESS_OPERATORS[language];
	
	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1, oneStr, 1 );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetFullTypeName( type, 1, 4, fullTypeName );

	char normQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionNormalize( language, type, normQuaternionFuncStr );
	
	char slerpQuaternionFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameQuaternionSlerp( language, type, slerpQuaternionFuncStr );

	char parmTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	Gen_GetParmTypeName( language, type, 1, 4, parmTypeName );

	const char* sinFunc = Gen_GetFuncNameSin( type );

	Doc_QuaternionSlerp( sbFwdDec, fullTypeName );
	String_Appendf( sbFwdDec, "inline %s %s( const %s lhs, const %s rhs, const %s percent );\n", fullTypeName, slerpQuaternionFuncStr, parmTypeName, parmTypeName, typeString );
	String_Append(  sbFwdDec, "\n" );

	String_Appendf( sbImpl, "inline %s %s( const %s lhs, const %s rhs, const %s percent )\n", fullTypeName, slerpQuaternionFuncStr, parmTypeName, parmTypeName, typeString );
	String_Append(  sbImpl, "{\n" );

	String_Appendf( sbImpl, "\t%s quat;\n", fullTypeName );
	String_Appendf( sbImpl, "\t%s t = %s - percent;\n", typeString, oneStr );
	
	String_Appendf( sbImpl, "\t%s cosTheta = ", typeString );

	const int numComponents = GEN_COMPONENT_COUNT_MAX;
	for (u32 i = 0; i < numComponents; i++) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf( sbImpl, "( lhs%s%c * rhs%s%c )", parmAccessStr, componentName, parmAccessStr, componentName );

		if (i != numComponents - 1) {
			String_Append( sbImpl, " + " );
		}
	}

	String_Append(  sbImpl, ";\n" );
	String_Appendf( sbImpl, "\tif ( cosTheta >= %s )\n", oneStr );
	String_Append(  sbImpl, "\t{\n" );
	String_Append(  sbImpl, "\t\treturn lhs;\n" );
	String_Append(  sbImpl, "\t}\n" );

	String_Appendf( sbImpl, "\t%s theta = %s( cosTheta );\n", typeString, Gen_GetFuncNameAcos( type ) );
	String_Appendf( sbImpl, "\t%s sn = %s( %s - cosTheta * cosTheta );\n", typeString, Gen_GetFuncNameSqrt( type ), oneStr );

	String_Appendf( sbImpl, "\t%s Wa = %s( t * theta ) / sn;\n", typeString, sinFunc );
	String_Appendf( sbImpl, "\t%s Wb = %s( percent * theta ) / sn;\n", typeString, sinFunc );

	for (u32 i = 0; i < numComponents; i++) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		String_Appendf( sbImpl, "\tquat.%c = Wa * rhs%s%c + Wb * lhs%s%c;\n", componentName, parmAccessStr, componentName, parmAccessStr, componentName );
	}
	
	String_Append( sbImpl, "\treturn quat;\n" );
	String_Append( sbImpl, "}\n" );
	String_Append( sbImpl, "\n" );
}