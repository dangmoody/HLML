static void GenerateFunction_QuaternionMulScalar( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const typeInfo_t* scalarType, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( scalarType );
	assert( scalarType->fullTypeName );
	assert( Gen_TypeIsScalar( scalarType ) );
	assert( code );
	assert( strings );

	if ( !Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
		return;
	}

	bool32 generateOperators = flags & GENERATOR_FLAG_GENERATE_OPERATORS;
	bool32 allowNameMangling = ( flags & GENERATOR_FLAG_NAME_MANGLING ) == 0;

	const char* mulQuaternionFuncStr = mulQuaternionFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_QUAT_MUL );

	if ( allowNameMangling ) {
		mulQuaternionFuncStr = String_TPrintf( tempStorage, "%ss", mulQuaternionFuncStr );
	}

	const char* typeString = Gen_GetTypeString( typeInfo->type );
	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	typeInfo_t imaginaryType = Gen_GetQuaternionImaginaryPartType( typeInfo, tempStorage );

	const char* cmulFuncStr = Gen_GetFuncName_VectorArithmeticScalar( tempStorage, &imaginaryType, GEN_OP_ARITHMETIC_MUL );

	StringBuilder_Append(  code, "// Performs a quaternion multiplication against the given scalar.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s lhs, const %s rhs )\n", typeInfo->fullTypeName, mulQuaternionFuncStr, typeInfo->fullTypeName, strings->parmPassByStr, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\t%s scalar = lhs%sw * rhs;\n", memberTypeString, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t%s3 imaginary = { lhs%sx, lhs%sy, lhs%sz };\n", typeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	if ( generateOperators ) {
		StringBuilder_Appendf( code, "\timaginary %s= rhs;\n", Gen_GetOperatorArithmetic( GEN_OP_ARITHMETIC_MUL ) );
	} else {
		StringBuilder_Appendf( code, "\timaginary = %s( %simaginary, rhs );\n", cmulFuncStr, strings->parmReferenceStr );
	}
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s ) { imaginary.x, imaginary.y, imaginary.z, scalar };\n", typeInfo->fullTypeName );
	StringBuilder_Append( code, "}\n\n" );
}

static void GenerateFunction_QuaternionMulQuaternion( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( !Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
		return;
	}

	const char* mulQuaternionFuncStr = mulQuaternionFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_QUAT_MUL );

	if ( ( flags & GENERATOR_FLAG_NAME_MANGLING ) == 0 ) {
		mulQuaternionFuncStr = String_TPrintf( tempStorage, "%sq", mulQuaternionFuncStr );
	}

	StringBuilder_Append(  code, "// Performs a quaternion multiplication against the other quaternion.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s lhs, const %s%s rhs )\n", typeInfo->fullTypeName, mulQuaternionFuncStr, typeInfo->fullTypeName, strings->parmPassByStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\t%s quat;\n", typeInfo->fullTypeName );
	StringBuilder_Appendf( code, "\tquat.x =  lhs%sx * rhs%sw + lhs%sy * rhs%sz - lhs%sz * rhs%sy + lhs%sw * rhs%sx;\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\tquat.y = -lhs%sx * rhs%sz + lhs%sy * rhs%sw + lhs%sz * rhs%sx + lhs%sw * rhs%sy;\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\tquat.z =  lhs%sx * rhs%sy - lhs%sy * rhs%sx + lhs%sz * rhs%sw + lhs%sw * rhs%sz;\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\tquat.w = -lhs%sx * rhs%sx - lhs%sy * rhs%sy - lhs%sz * rhs%sz + lhs%sw * rhs%sw;\n", strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Append(  code, "\treturn quat;\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_QuaternionLength( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( !Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
		return;
	}

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	// const char* quatLengthFuncStr = C_GetFuncName_Quaternion( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_LENGTH );
	const char* quatLengthFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_QUAT_LENGTH );

	StringBuilder_Append(  code, "// Returns the magnitude of the quaternion.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s quat )\n", memberTypeString, quatLengthFuncStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn %s( ", Gen_GetBuiltinFunction( tempStorage, typeInfo->type, GEN_BUILTIN_FUNCTION_NAME_SQRT ) );
	for ( u32 i = 0; i < typeInfo->numCols; i++ ) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		StringBuilder_Appendf( code, "( quat%s%c * quat%s%c )", strings->parmAccessOperatorStr, componentName, strings->parmAccessOperatorStr, componentName );

		if (i != typeInfo->numCols - 1) {
			StringBuilder_Append( code, " + " );
		}
	}

	StringBuilder_Append( code, " );\n" );
	StringBuilder_Append( code, "}\n\n" );
}

static void GenerateFunction_QuaternionNormalize( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( !Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( typeInfo->type );
	const char* memberTypeString = Gen_GetTypeString( typeInfo->type );

	const char* normalizeQuaternionFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_QUAT_NORMALIZE );
	const char* lengthQuaternionFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_QUAT_LENGTH );

	typeInfo_t imaginaryType = Gen_GetQuaternionImaginaryPartType( typeInfo, tempStorage );

	const char* zeroStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.0f, 1 );
	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );

	const char* cmulFuncStr = Gen_GetFuncName_VectorArithmeticScalar( tempStorage, &imaginaryType, GEN_OP_ARITHMETIC_MUL );

	StringBuilder_Append(  code, "// Normalizes the quaternion.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s quat )\n", typeInfo->fullTypeName, normalizeQuaternionFuncStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n");
	StringBuilder_Appendf( code, "\t%s3 normV = { quat%sx, quat%sy, quat%sz };\n", typeString, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t%s normS = quat%sw;\n", memberTypeString, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t%s mag = %s( quat );\n", memberTypeString, lengthQuaternionFuncStr );
	StringBuilder_Appendf( code, "\tif ( mag >= %s )\n", zeroStr );
	StringBuilder_Append(  code, "\t{\n" );
	StringBuilder_Appendf( code, "\t\t%s magInverse = %s / mag;\n", typeString, oneStr );
	if ( flags & GENERATOR_FLAG_GENERATE_OPERATORS ) {
		StringBuilder_Appendf( code, "\t\tnormV = normV %s magInverse;\n", Gen_GetOperatorArithmetic( GEN_OP_ARITHMETIC_MUL ) );
	} else {
		StringBuilder_Appendf( code, "\t\tnormV = %s( %snormV, magInverse );\n", cmulFuncStr, strings->parmReferenceStr );
	}
	StringBuilder_Append(  code, "\t\tnormS *= magInverse;\n" );
	StringBuilder_Append(  code, "\t}\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s ) { normV.x, normV.y, normV.z, normS };\n", typeInfo->fullTypeName );
	StringBuilder_Append( code, "}\n\n" );
}

static void GenerateFunction_QuaternionConjugate( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( !Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
		return;
	}

	const char* conjugateQuaternionFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_QUAT_CONJUGATE );

	const char* minusOneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, -1.0f, 1 );

	StringBuilder_Append(  code, "// Returns the conjugate of the quaternion.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s quat )\n", typeInfo->fullTypeName, conjugateQuaternionFuncStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", typeInfo->fullTypeName );
	StringBuilder_Append(  code, "\t{\n" );

	const int numCols = 3;
	for (u32 i = 0; i < numCols; i++) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		StringBuilder_Appendf( code, "\t\t( quat%s%c * ( %s ) )", strings->parmAccessOperatorStr, componentName, minusOneStr );
		StringBuilder_Append(  code, ",\n" );
	}

	StringBuilder_Appendf( code, "\t\tquat%sw\n", strings->parmAccessOperatorStr );
	StringBuilder_Append(  code, "\t};\n}\n\n" );
}

static void GenerateFunction_QuaternionInverse( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( !Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
		return;
	}

	const char* inverseQuaternionFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_QUAT_INVERSE );
	const char* lengthQuaternionFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_QUAT_LENGTH );
	const char* conjugateQuaternionFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_QUAT_CONJUGATE );

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );
	const char* typeString = Gen_GetTypeString( typeInfo->type );

	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );

	StringBuilder_Append(  code, "// Returns the inverse of the quaternion.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s quat )\n", typeInfo->fullTypeName, inverseQuaternionFuncStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n");
	StringBuilder_Appendf( code, "\t%s magnitude = %s( quat );\n", memberTypeString, lengthQuaternionFuncStr );
	StringBuilder_Append(  code, "\tmagnitude *= magnitude;\n" );
	StringBuilder_Appendf( code, "\tmagnitude = %s / magnitude;\n", oneStr );
	StringBuilder_Appendf( code, "\t%s conjugate = %s( quat );\n", typeInfo->fullTypeName, conjugateQuaternionFuncStr );
	StringBuilder_Appendf( code, "\t%s scalar = conjugate.w * magnitude;\n", memberTypeString );
	StringBuilder_Appendf( code, "\t%s3 imaginary = HLML_CONSTRUCT( %s3 ) { conjugate.x * magnitude, conjugate.y * magnitude, conjugate.z * magnitude };\n", typeString, typeString );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s ) { imaginary.x, imaginary.y, imaginary.z, scalar };\n", typeInfo->fullTypeName );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateFunction_QuaternionRotationAxis( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( !Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
		return;
	}

	typeInfo_t imaginaryPartType = Gen_GetQuaternionImaginaryPartType( typeInfo, tempStorage );

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* rotateQuaternionFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_QUAT_ROTATE );
	const char* inverseQuaternionFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_QUAT_INVERSE );

	const char* quatMulQuatFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_QUAT_MUL );
	if ( ( flags & GENERATOR_FLAG_NAME_MANGLING ) == 0 ) {
		quatMulQuatFuncStr = String_TPrintf( tempStorage, "%sq", quatMulQuatFuncStr );
	}

	const char* normalizeVectorFuncStr = Gen_GetFuncName_Vector( tempStorage, &imaginaryPartType, flags, GEN_FUNCTION_NAME_NORMALIZE );

	const char* cosFuncStr = Gen_GetBuiltinFunction( tempStorage, typeInfo->type, GEN_BUILTIN_FUNCTION_NAME_COS );
	const char* sinFuncStr = Gen_GetBuiltinFunction( tempStorage, typeInfo->type, GEN_BUILTIN_FUNCTION_NAME_SIN );

	const char* zeroStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.0f, 1 );
	const char* halfStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.5f, 1 );

	StringBuilder_Append(  code, "// Performs a rotation on the quaternion by the given axis-angle and angle (in radians).\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s vect, const %s angle, const %s3%s axis )\n", imaginaryPartType.fullTypeName, rotateQuaternionFuncStr, typeInfo->fullTypeName, strings->parmPassByStr, memberTypeString, memberTypeString, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\t%s pureQuat = HLML_CONSTRUCT( %s ) { vect%sx, vect%sy, vect%sz, %s };\n", typeInfo->fullTypeName, typeInfo->fullTypeName, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, zeroStr );
	StringBuilder_Appendf( code, "\t%s normalizedAxis = %saxis;\n", imaginaryPartType.fullTypeName, strings->parmDereferenceStr );
	StringBuilder_Appendf( code, "\t%s( %snormalizedAxis );\n", normalizeVectorFuncStr, strings->parmReferenceStr );
	StringBuilder_Appendf( code, "\t%s realQuat = HLML_CONSTRUCT( %s ) { normalizedAxis.x, normalizedAxis.y, normalizedAxis.z, angle };\n", typeInfo->fullTypeName, typeInfo->fullTypeName );
	StringBuilder_Append(  code, "\n" );
	// Converts the quaternion into its unit-norm format
	StringBuilder_Appendf( code, "\t%s imaginary = { realQuat.x, realQuat.y, realQuat.z };\n", imaginaryPartType.fullTypeName );
	StringBuilder_Appendf( code, "\t%s normalizedImaginary = imaginary;\n", imaginaryPartType.fullTypeName );
	StringBuilder_Appendf( code, "\t%s( %snormalizedImaginary );\n", normalizeVectorFuncStr, strings->parmReferenceStr );
	StringBuilder_Appendf( code, "\t%s unitNormScalar = %s( realQuat.w * %s );\n", memberTypeString, cosFuncStr, halfStr );
	StringBuilder_Appendf( code, "\t%s sinResult = %s( realQuat.w * %s );\n", memberTypeString, sinFuncStr, halfStr );
	if ( flags & GENERATOR_FLAG_GENERATE_OPERATORS ) {
		StringBuilder_Appendf( code, "\t%s unitNormImaginary = normalizedImaginary * sinResult;\n", imaginaryPartType.fullTypeName, strings->parmReferenceStr );
	} else {
		const char* cmulFuncStr = Gen_GetFuncName_VectorArithmeticScalar( tempStorage, &imaginaryPartType, GEN_OP_ARITHMETIC_MUL );

		StringBuilder_Appendf( code, "\t%s unitNormImaginary = %s( %snormalizedImaginary, sinResult );\n", imaginaryPartType.fullTypeName, cmulFuncStr, strings->parmReferenceStr );
	}
	StringBuilder_Appendf( code, "\t%s unitNormQuat = { unitNormImaginary.x, unitNormImaginary.y, unitNormImaginary.z, unitNormScalar };\n", typeInfo->fullTypeName );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\t%s inverseQuat = %s( %sunitNormQuat );\n", typeInfo->fullTypeName, inverseQuaternionFuncStr, strings->parmReferenceStr );
	StringBuilder_Appendf( code, "\t%s rotatedVector = %s( %sunitNormQuat, %spureQuat );\n", typeInfo->fullTypeName, quatMulQuatFuncStr, strings->parmReferenceStr, strings->parmReferenceStr );
	StringBuilder_Appendf( code, "\trotatedVector = %s( %srotatedVector, %sinverseQuat );\n", quatMulQuatFuncStr, strings->parmReferenceStr, strings->parmReferenceStr );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s ) { rotatedVector.x, rotatedVector.y, rotatedVector.z };\n", imaginaryPartType.fullTypeName );
	StringBuilder_Append( code, "}\n\n" );
}

static void GenerateFunction_QuaternionLerp( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( !Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
		return;
	}

	const char* lerpQuaternionFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_QUAT_LERP );

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );

	StringBuilder_Append(  code, "// Returns a linearly interpolated float4 quaternion between 'a' and 'b' where 'percent' is the percentage (between 0 and 1) to interpolate by.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s lhs, const %s%s rhs, const %s percent )\n", typeInfo->fullTypeName, lerpQuaternionFuncStr, typeInfo->fullTypeName, strings->parmPassByStr, typeInfo->fullTypeName, strings->parmPassByStr, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\t%s quat;\n", typeInfo->fullTypeName );
	StringBuilder_Appendf( code, "\t%s t = %s - percent;\n", memberTypeString, oneStr );

	for ( u32 i = 0; i < 4; i++ ) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		StringBuilder_Appendf( code, "\tquat.%c = t * lhs%s%c + percent * rhs%s%c;\n", componentName, strings->parmAccessOperatorStr, componentName, strings->parmAccessOperatorStr, componentName );
	}

	StringBuilder_Append( code, "\treturn quat;\n" );
	StringBuilder_Append( code, "}\n\n" );
}

static void GenerateFunction_QuaternionSlerp( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( !Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
		return;
	}

	const char* slerpQuaternionFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_QUAT_SLERP );

	const char* memberTypeString = Gen_GetMemberTypeString( typeInfo->type );

	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );

	const char* acosFuncStr = Gen_GetBuiltinFunction( tempStorage, typeInfo->type, GEN_BUILTIN_FUNCTION_NAME_ACOS );
	const char* sqrtFuncStr = Gen_GetBuiltinFunction( tempStorage, typeInfo->type, GEN_BUILTIN_FUNCTION_NAME_SQRT );
	const char* sinFuncStr = Gen_GetBuiltinFunction( tempStorage, typeInfo->type, GEN_BUILTIN_FUNCTION_NAME_SIN );

	StringBuilder_Append(  code, "// Returns a spherically interpolated float4 between 'a' and 'b' where 'percent' is the percentage (between 0 and 1) to interpolate by.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s lhs, const %s%s rhs, const %s percent )\n", typeInfo->fullTypeName, slerpQuaternionFuncStr, typeInfo->fullTypeName, strings->parmPassByStr, typeInfo->fullTypeName, strings->parmPassByStr, memberTypeString );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\t%s quat;\n", typeInfo->fullTypeName );
	StringBuilder_Appendf( code, "\t%s t = %s - percent;\n", memberTypeString, oneStr );
	StringBuilder_Appendf( code, "\t%s cosTheta = ", memberTypeString );

	for (u32 i = 0; i < typeInfo->numCols; i++) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		StringBuilder_Appendf( code, "( lhs%s%c * rhs%s%c )", strings->parmAccessOperatorStr, componentName, strings->parmAccessOperatorStr, componentName );

		if (i != typeInfo->numCols - 1) {
			StringBuilder_Append( code, " + " );
		}
	}

	StringBuilder_Append(  code, ";\n" );
	StringBuilder_Appendf( code, "\tif ( cosTheta >= %s )\n", oneStr );
	StringBuilder_Append(  code, "\t{\n" );
	StringBuilder_Appendf( code, "\t\treturn HLML_CONSTRUCT( %s ) { ", typeInfo->fullTypeName );
	for (u32 i = 0; i < typeInfo->numCols; i++) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		StringBuilder_Appendf( code, "lhs%s%c", strings->parmAccessOperatorStr, componentName );

		if (i != typeInfo->numCols - 1) {
			StringBuilder_Append( code, ", " );
		}
	}
	StringBuilder_Append(  code, " };\n" );
	StringBuilder_Append(  code, "\t}\n" );
	StringBuilder_Appendf( code, "\t%s theta = %s( cosTheta );\n", memberTypeString, acosFuncStr );
	StringBuilder_Appendf( code, "\t%s sn = %s( %s - cosTheta * cosTheta );\n", memberTypeString, sqrtFuncStr, oneStr );
	StringBuilder_Appendf( code, "\t%s Wa = %s( t * theta ) / sn;\n", memberTypeString, sinFuncStr );
	StringBuilder_Appendf( code, "\t%s Wb = %s( percent * theta ) / sn;\n", memberTypeString, sinFuncStr );

	for (u32 i = 0; i < typeInfo->numCols; i++) {
		const char componentName = GEN_COMPONENT_NAMES_VECTOR[i];

		StringBuilder_Appendf( code, "\tquat.%c = Wa * rhs%s%c + Wb * lhs%s%c;\n", componentName, strings->parmAccessOperatorStr, componentName, strings->parmAccessOperatorStr, componentName );
	}

	StringBuilder_Append( code, "\treturn quat;\n" );
	StringBuilder_Append( code, "}\n\n" );
}

static void GenerateFunction_QuaternionToRotationMatrix( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, stringBuilder_t* code, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( code );
	assert( strings );

	if ( !Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
		return;
	}

	const char* typeString = Gen_GetTypeString( typeInfo->type );

	const char* returnTypeName = String_TPrintf( tempStorage, "%s%dx%d", typeString, typeInfo->numCols, typeInfo->numCols );

	const char* funcName = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_QUAT_TO_ROTATION_MATRIX );

	const char* zeroStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 0.0f, 1 );
	const char* oneStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 1.0f, 1 );
	const char* twoStr = Gen_GetNumericLiteral( tempStorage, typeInfo->type, 2.0f, 1 );

	StringBuilder_Appendf( code, "// Converts the quaternion into a rotation matrix and returns the result.\n" );
	StringBuilder_Appendf( code, "HLML_INLINE %s %s( const %s%s quat )\n", returnTypeName, funcName, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\treturn HLML_CONSTRUCT( %s )\n", returnTypeName );
	StringBuilder_Append(  code, "\t{\n" );
	StringBuilder_Appendf( code, "\t\t%s - ( %s * ( quat%sy * quat%sy ) ) - ( %s * ( quat%sz * quat%sz ) ),\n", oneStr, twoStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, twoStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\t( %s * ( quat%sx * quat%sy ) ) - ( %s * ( quat%sw * quat%sz ) ),\n", twoStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, twoStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\t( %s * ( quat%sx * quat%sz ) ) + ( %s * ( quat%sw * quat%sy ) ),\n", twoStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, twoStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\t%s,\n", zeroStr );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\t\t( %s * ( quat%sx * quat%sy ) ) + ( %s * ( quat%sw * quat%sz ) ),\n", twoStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, twoStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\t%s - ( %s * ( quat%sx * quat%sx ) ) - ( %s * ( quat%sz * quat%sz ) ),\n", oneStr, twoStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, twoStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\t( %s * ( quat%sy * quat%sz ) ) - ( %s * ( quat%sw * quat%sx ) ),\n", twoStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, twoStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\t%s,\n", zeroStr );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\t\t( %s * ( quat%sx * quat%sz ) ) - ( %s * ( quat%sw * quat%sy ) ),\n", twoStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, twoStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\t( %s * ( quat%sy * quat%sz ) ) + ( %s * ( quat%sw * quat%sx ) ),\n", twoStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, twoStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\t%s - ( %s * ( quat%sx * quat%sx ) ) - ( %s * ( quat%sy * quat%sy ) ),\n", oneStr, twoStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr, twoStr, strings->parmAccessOperatorStr, strings->parmAccessOperatorStr );
	StringBuilder_Appendf( code, "\t\t%s,\n", zeroStr );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\t\t%s,\n", zeroStr );
	StringBuilder_Appendf( code, "\t\t%s,\n", zeroStr );
	StringBuilder_Appendf( code, "\t\t%s,\n", zeroStr );
	StringBuilder_Appendf( code, "\t\t%s\n", oneStr );
	StringBuilder_Append(  code, "\t};\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void GenerateQuaternionFiles( allocatorLinear_t* tempStorage, const char* generatedCodePath, const typeInfo_t* typeInfos, const u32 typeInfosCount, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( generatedCodePath );
	assert( typeInfos );
	assert( typeInfosCount );
	assert( strings );

	bool32 cLinkage = flags & GENERATOR_FLAG_C_LINKAGE;

	// quaternion functions
	stringBuilder_t* code = StringBuilder_Create( tempStorage, KILOBYTES( 64 ) );

	StringBuilder_Append( code,
		GEN_FILE_HEADER
		"#pragma once\n"
		"\n"
	);

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef __cplusplus\n"
			"extern \"C\" {\n"
			"#endif\n"
			"\n"
		);
	}

	for ( u32 i = 0; i < typeInfosCount; i++ ) {
		const typeInfo_t* typeInfo = &typeInfos[i];

		if ( !Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
			return;
		}

		typeInfo_t scalarMemberType = Gen_GetScalarType( typeInfo );

		printf( "Quaternion functions %s...", typeInfo->fullTypeName );

		StringBuilder_Appendf( code, "// %s\n", typeInfo->fullTypeName );

		GenerateFunction_QuaternionMulScalar( tempStorage, typeInfo, &scalarMemberType, code, strings, flags );
		GenerateFunction_QuaternionMulQuaternion( tempStorage, typeInfo, code, strings, flags );
		GenerateFunction_QuaternionLength( tempStorage, typeInfo, code, strings, flags );
		GenerateFunction_QuaternionNormalize( tempStorage, typeInfo, code, strings, flags );
		GenerateFunction_QuaternionConjugate( tempStorage, typeInfo, code, strings, flags );
		GenerateFunction_QuaternionInverse( tempStorage, typeInfo, code, strings, flags );
		GenerateFunction_QuaternionRotationAxis( tempStorage, typeInfo, code, strings, flags );
		GenerateFunction_QuaternionLerp( tempStorage, typeInfo, code, strings, flags );
		GenerateFunction_QuaternionSlerp( tempStorage, typeInfo, code, strings, flags );
		GenerateFunction_QuaternionToRotationMatrix( tempStorage, typeInfo, code, strings, flags );

		printf( "OK.\n" );
	}

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n"
		);
	}

	const char* fileNameHeader = String_TPrintf( tempStorage, "%s/%s.h", generatedCodePath, GEN_FILENAME_FUNCTIONS_QUATERNION );

	FS_WriteEntireFile( fileNameHeader, code->str, code->length );

	Mem_Reset( tempStorage );
}