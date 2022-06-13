typedef struct testFixture_Identity_t {
	float32	values[16];
	bool32	expectedAnswer;
} testFixture_Identity_t;

typedef struct testFixture_Transpose_t {
	float32	values[16];
	float32	expectedAnswer[16];
} testFixture_Transpose_t;

typedef struct testFixture_MatrixMulMatrix_t {
	float32	valuesLHS[16];
	float32	valuesRHS[16];
} testFixture_MatrixMulMatrix_t;

typedef struct testFixture_MatrixMulVector_t {
	float32	vector[4];
	float32	matrix[16];
} testFixture_MatrixMulVector_t;

typedef struct testFixture_Determinant_t {
	float32	values[16];
	float32	expectedAnswer2x2;
	float32	expectedAnswer3x3;
	float32	expectedAnswer4x4;
} testFixture_Determinant_t;

typedef struct testFixture_Inverse_t {
	float32	values[16];
	float32	expectedAnswer2x2[16];
	float32	expectedAnswer3x3[16];
	float32	expectedAnswer4x4[16];
} testFixture_Inverse_t;

typedef struct testFixture_Translate_t {
	float32	matrix[16];
	float32	translateVec[3];
	float32	expectedAnswer[16];
} testFixture_Translate_t;

typedef struct testFixture_Rotate_t {
	float32	matrix[16];
	float32	rotationDeg;
	float32	axisAngle[3];
	float32	expectedAnswer[16];
} testFixture_Rotate_t;

typedef struct testFixture_Scale_t {
	float32	matrix[16];
	float32	scaleVec[3];
	float32	expectedAnswer[16];
} testFixture_Scale_t;

typedef struct testFixture_Ortho_t {
	float32	width;
	float32	height;
	float32	orthoSize;
	float32	zNear;
	float32	zFar;
	float32	expectedAnswer[16];
} testFixture_Ortho_t;

typedef struct testFixture_Perspective_t {
	float32	width;
	float32	height;
	float32	fovDeg;
	float32	zNear;
	float32	zFar;
	float32	expectedAnswer[16];
} testFixture_Perspective_t;

typedef struct testFixture_LookAt_t {
	float32	eye[3];
	float32	target[3];
	float32	up[3];
	float32	expectedAnswer[16];
} testFixture_LookAt_t;

static void Gen_GenerateTests_Identity( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	typeInfo_t scalarTypeBool = {
		.type			= GEN_TYPE_BOOL,
		.numRows		= 1,
		.numCols		= 1,
		.fullTypeName	= Gen_GetTypeString( scalarTypeBool.type )
	};

	const char* actualFuncName = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_IDENTITY );
	const char* testName = Gen_GetTestName( tempStorage, typeInfo, GEN_FUNCTION_NAME_IDENTITY );

	const char* equalsFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_EQUALS );

	// identity function doesnt return anything and function to generate a parametric test definition assumes the function its testing actually returns something other than void
	// so were not using that function for identity
	StringBuilder_Appendf( code, "TEMPER_PARAMETRIC( %s, TEMPER_FLAG_SHOULD_RUN, const %s%s matrix, const bool expectedAnswer )\n", testName, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\t%s identityMat;\n", typeInfo->fullTypeName );
	StringBuilder_Appendf( code, "\t%s( %sidentityMat );\n", actualFuncName, strings->parmReferenceStr );
	if ( flags & GENERATOR_FLAG_GENERATE_OPERATORS ) {
		StringBuilder_Appendf( code, "\t%s isMatrixIdentity = ( identityMat == matrix );\n", scalarTypeBool.fullTypeName );
	} else {
		StringBuilder_Appendf( code, "\t%s isMatrixIdentity = %s( %sidentityMat, matrix );\n", scalarTypeBool.fullTypeName, equalsFuncStr, strings->parmReferenceStr );
	}
	StringBuilder_Appendf( code, "\tTEMPER_CHECK_TRUE( isMatrixIdentity == expectedAnswer );\n" );
	StringBuilder_Append(  code, "}\n\n" );

	testFixture_Identity_t fixtures[] = {
		{
			.values = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			},
			.expectedAnswer = true
		},

		{
			.values = {
				1.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			},
			.expectedAnswer = false
		},

		{
			.values = {
				1.0f, 0.0f, 0.0f, 0.0f,
				1.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			},
			.expectedAnswer = false
		},

		{
			.values = {
				1.0f, 1.0f, 0.0f, 0.0f,
				1.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			},
			.expectedAnswer = false
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_Identity_t* fixture = &fixtures[i];

		parametricTestInvokationGenericParm_t parms[] = {
			{  typeInfo,                         fixture->values         },
			{ &scalarTypeBool, (const float32*) &fixture->expectedAnswer }
		};

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_IDENTITY, strings, flags, parms, GEN_COUNTOF( parms ) );
	}
}

static void Gen_GenerateTests_Transpose( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	typeInfo_t transposedType = {
		.type = typeInfo->type,
		.numRows = typeInfo->numCols,
		.numCols = typeInfo->numRows,
		.fullTypeName = String_TPrintf( tempStorage, "%s%dx%d", Gen_GetTypeString( typeInfo->type ), typeInfo->numCols, typeInfo->numRows )
	};

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType = &transposedType,
		.funcName = GEN_FUNCTION_NAME_TRANSPOSE,
		.parmsCount = 1,
		.parms = (parametricTestDefinitionParm_t[]) {
			{ typeInfo, "matrix" }
		}
	} );

	testFixture_Transpose_t fixtures[] = {
		{
			.values = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			},
			.expectedAnswer = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			}
		},

		{
			.values = {
				0.0f,  1.0f,  2.0f,  3.0f,
				4.0f,  5.0f,  6.0f,  7.0f,
				8.0f,  9.0f,  10.0f, 11.0f,
				12.0f, 13.0f, 14.0f, 15.0f
			},
			.expectedAnswer = {
				0.0f, 4.0f, 8.0f,  12.0f,
				1.0f, 5.0f, 9.0f,  13.0f,
				2.0f, 6.0f, 10.0f, 14.0f,
				3.0f, 7.0f, 11.0f, 15.0f
			}
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_Transpose_t* fixture = &fixtures[i];

		parametricTestInvokationGenericParm_t parms[] = {
			{  typeInfo,       fixture->values         },
			{ &transposedType, fixture->expectedAnswer }
		};

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_TRANSPOSE, strings, flags, parms, GEN_COUNTOF( parms ) );
	}
}

static void Gen_GenerateTests_MatrixMulMatrix( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	if ( typeInfo->type == GEN_TYPE_BOOL ) {
		return;
	}

	typeInfo_t rhsType = {
		.type = typeInfo->type,
		.numRows = typeInfo->numCols,
		.numCols = typeInfo->numRows,
		.fullTypeName = String_TPrintf( tempStorage, "%s%dx%d", Gen_GetTypeString( rhsType.type ), rhsType.numRows, rhsType.numCols )
	};

	typeInfo_t mulReturnType = {
		.type = typeInfo->type,
		.numRows = typeInfo->numRows,
		.numCols = rhsType.numCols,
		.fullTypeName = String_TPrintf( tempStorage, "%s%dx%d", Gen_GetTypeString( mulReturnType.type ), mulReturnType.numRows, mulReturnType.numCols )
	};

	const char* funcName = GEN_FUNCTION_NAME_MUL;
	const char* funcNameUnique = String_TPrintf( tempStorage, "%sm", funcName );
	if ( ( flags & GENERATOR_FLAG_NAME_MANGLING ) == 0 ) {
		funcName = funcNameUnique;
	}

	const char* testName = Gen_GetTestName( tempStorage, typeInfo, funcNameUnique );

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType = &mulReturnType,
		.funcName = funcName,
		.testNameOverride = testName,
		.parmsCount = 2,
		.parms = (parametricTestDefinitionParm_t[]) {
			{  typeInfo, "lhs" },
			{ &rhsType,  "rhs" }
		}
	} );

	// TODO(DM): include tests for:
	// 	- multiply matrix by its inverse to produce identity
	testFixture_MatrixMulMatrix_t fixtures[] = {
		{
			.valuesLHS = {
				2.0f, 2.0f, 2.0f, 2.0f,
				2.0f, 2.0f, 2.0f, 2.0f,
				2.0f, 2.0f, 2.0f, 2.0f,
				2.0f, 2.0f, 2.0f, 2.0f
			},
			.valuesRHS = {
				4.0f, 4.0f, 4.0f, 4.0f,
				4.0f, 4.0f, 4.0f, 4.0f,
				4.0f, 4.0f, 4.0f, 4.0f,
				4.0f, 4.0f, 4.0f, 4.0f
			}
		},

		{
			.valuesLHS = {
				2.0f, 2.0f, 2.0f, 2.0f,
				2.0f, 2.0f, 2.0f, 2.0f,
				2.0f, 2.0f, 2.0f, 2.0f,
				2.0f, 2.0f, 2.0f, 2.0f
			},
			.valuesRHS = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			}
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_MatrixMulMatrix_t* fixture = &fixtures[i];

		stringBuilder_t* parmListLHS = Gen_GetConstructor( tempStorage, typeInfo, fixture->valuesLHS, strings, flags );
		stringBuilder_t* parmListRHS = Gen_GetConstructor( tempStorage, &rhsType, fixture->valuesRHS, strings, flags );
		stringBuilder_t* parmListExpectedAnswer = Gen_GetParmList_MatrixMultiply( tempStorage, typeInfo, &rhsType, fixture->valuesLHS, fixture->valuesRHS );

		StringBuilder_Appendf( code, "TEMPER_INVOKE_PARAMETRIC_TEST( %s,\n", testName );
		StringBuilder_Appendf( code, "%s,\n", parmListLHS->str );
		StringBuilder_Appendf( code, "%s,\n", parmListRHS->str );
		if ( flags & GENERATOR_FLAG_GENERATE_CONSTRUCTORS ) {
			StringBuilder_Appendf( code, "\t%s(\n", mulReturnType.fullTypeName );
		} else {
			StringBuilder_Appendf( code, "\t&(%s)\n", mulReturnType.fullTypeName );
			StringBuilder_Append(  code, "\t{\n" );
		}
		StringBuilder_Appendf( code, "%s", parmListExpectedAnswer->str );
		if ( flags & GENERATOR_FLAG_GENERATE_CONSTRUCTORS ) {
			StringBuilder_Append(  code, "\t)\n" );
		} else {
			StringBuilder_Append(  code, "\t}\n" );
		}
		StringBuilder_Append(  code, ");\n\n" );
	}
}

static void Gen_GenerateTests_MatrixMulVector( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	if ( typeInfo->type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( typeInfo->numRows != typeInfo->numCols ) {
		return;
	}

	bool32 generateConstructors = flags & GENERATOR_FLAG_GENERATE_CONSTRUCTORS;
	bool32 allowNameMangling = flags & GENERATOR_FLAG_NAME_MANGLING;

	typeInfo_t memberType = {
		.type			= typeInfo->type,
		.numRows		= 1,
		.numCols		= typeInfo->numCols,
		.fullTypeName	= String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( memberType.type ), memberType.numCols )
	};

	const char* funcName = GEN_FUNCTION_NAME_MUL;
	const char* funcNameUnique = String_TPrintf( tempStorage, "%sv", funcName );

	if ( !allowNameMangling ) {
		funcName = funcNameUnique;
	}

	const char* testName = Gen_GetTestName( tempStorage, typeInfo, funcNameUnique );

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType = &memberType,
		.funcName = funcName,
		.testNameOverride = testName,
		.parmsCount = 2,
		.parms = (parametricTestDefinitionParm_t[]) {
			{ &memberType, "vec" },
			{  typeInfo,   "mat" }
		}
	} );

	testFixture_MatrixMulVector_t fixtures[] = {
		{
			.vector = { 0.0f, 0.0f, 0.0f, 0.0f },
			.matrix = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			}
		},

		{
			.vector = { 2.0f, 1.0f, 4.0f, 3.0f },
			.matrix = {
				1.0f,  2.0f,  3.0f,  4.0f,
				5.0f,  6.0f,  7.0f,  8.0f,
				9.0f,  10.0f, 11.0f, 12.0f,
				13.0f, 14.0f, 15.0f, 16.0f
			}
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_MatrixMulVector_t* fixture = &fixtures[i];

		stringBuilder_t* parmListVector = Gen_GetConstructor( tempStorage, &memberType, fixture->vector, strings, flags );
		stringBuilder_t* parmListMatrix = Gen_GetConstructor( tempStorage, typeInfo, fixture->matrix, strings, flags );
		stringBuilder_t* parmListExpectedAnswer = Gen_GetParmList_MatrixMultiply( tempStorage, &memberType, typeInfo, fixture->vector, fixture->matrix );

		StringBuilder_Appendf( code, "TEMPER_INVOKE_PARAMETRIC_TEST( %s,\n", testName );
		StringBuilder_Appendf( code, "%s,\n", parmListVector->str );
		StringBuilder_Appendf( code, "%s,\n", parmListMatrix->str );
		if ( generateConstructors ) {
			StringBuilder_Appendf( code, "\t%s(\n", memberType.fullTypeName );
		} else {
			StringBuilder_Appendf( code, "\t&(%s) { ", memberType.fullTypeName );
		}
		StringBuilder_Appendf( code, "%s", parmListExpectedAnswer->str );
		if ( generateConstructors ) {
			StringBuilder_Append(  code, "\t)\n" );
		} else {
			StringBuilder_Append(  code, " }\n" );
		}
		StringBuilder_Append(  code, ");\n\n" );
	}
}

static void Gen_GenerateTests_Determinant( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	if ( typeInfo->type == GEN_TYPE_BOOL || typeInfo->type == GEN_TYPE_UINT ) {
		return;
	}

	if ( typeInfo->numRows != typeInfo->numCols ) {
		return;
	}

	typeInfo_t scalarType = {
		.type			= typeInfo->type,
		.numRows		= 1,
		.numCols		= 1,
		.fullTypeName	= Gen_GetMemberTypeString( scalarType.type )
	};

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType = &scalarType,
		.funcName = GEN_FUNCTION_NAME_DETERMINANT,
		.parmsCount = 1,
		.parms = (parametricTestDefinitionParm_t[]) {
			{ typeInfo, "matrix" }
		}
	} );

	testFixture_Determinant_t fixtures[] = {
		{
			.values = {
				6.0f, 2.0f, 3.0f, 4.0f,
				2.0f, 7.0f, 5.0f, 3.0f,
				3.0f, 5.0f, 7.0f, 2.0f,
				4.0f, 3.0f, 2.0f, 6.0f
			},
			.expectedAnswer2x2 = 38.0f,
			.expectedAnswer3x3 = 113.0f,
			.expectedAnswer4x4 = 285.0f
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_Determinant_t* fixture = &fixtures[i];

		parametricTestInvokationGenericParm_t parms[] = {
			{  typeInfo,   fixture->values },
			{ &scalarType, NULL            }
		};

		switch ( typeInfo->numRows ) {
			case 2: parms[1].value = &fixture->expectedAnswer2x2; break;
			case 3: parms[1].value = &fixture->expectedAnswer3x3; break;
			case 4: parms[1].value = &fixture->expectedAnswer4x4; break;
		}

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_DETERMINANT, strings, flags, parms, GEN_COUNTOF( parms ) );
	}
}

static void Gen_GenerateTests_Inverse( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	if ( typeInfo->numRows != typeInfo->numCols ) {
		return;
	}

	bool32 generateOperators = flags & GENERATOR_FLAG_GENERATE_OPERATORS;

	const char* actualFuncName = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_INVERSE );
	const char* testName = Gen_GetTestName( tempStorage, typeInfo, GEN_FUNCTION_NAME_INVERSE );

	const char* equalsFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_EQUALS );
	const char* identityFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_IDENTITY );
	const char* mulFuncStr = Gen_GetFuncName_MatrixMul( tempStorage, typeInfo, typeInfo, flags );

	StringBuilder_Appendf( code, "TEMPER_PARAMETRIC( %s, TEMPER_FLAG_SHOULD_RUN, const %s%s mat, const %s%s expectedAnswer )\n", testName, typeInfo->fullTypeName, strings->parmPassByStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\t%s inversed = %s( mat );\n", typeInfo->fullTypeName, actualFuncName );
	if ( generateOperators ) {
		StringBuilder_Append( code, "\tTEMPER_CHECK_TRUE( inversed == expectedAnswer );\n" );
	} else {
		StringBuilder_Appendf( code, "\tTEMPER_CHECK_TRUE( %s( %sinversed, expectedAnswer ) );\n", equalsFuncStr, strings->parmReferenceStr );
	}
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Append(  code, "\t// test inversed matrix multiplied by the original equals identity\n" );
	StringBuilder_Appendf( code, "\t%s identityMat;\n", typeInfo->fullTypeName );
	StringBuilder_Appendf( code, "\t%s( %sidentityMat );\n", identityFuncStr, strings->parmReferenceStr );
	StringBuilder_Append(  code, "\n" );
	StringBuilder_Appendf( code, "\t%s matMultipliedByItsInverse = %s( mat, %sinversed );\n", typeInfo->fullTypeName, mulFuncStr, strings->parmReferenceStr );
	if ( generateOperators ) {
		StringBuilder_Append( code, "\tTEMPER_CHECK_TRUE( matMultipliedByItsInverse == identityMat );\n" );
	} else {
		StringBuilder_Appendf( code, "\tTEMPER_CHECK_TRUE( %s( %smatMultipliedByItsInverse, %sidentityMat ) );\n", equalsFuncStr, strings->parmReferenceStr, strings->parmReferenceStr );
	}
	StringBuilder_Append(  code, "}\n\n" );

	testFixture_Inverse_t fixtures[] = {
		// only useful for 4x4 matrices, but definitely a more common case
		{
		 	.values = {
		 		1.0f, 0.0f, 0.0f, 3.0f,
		 		0.0f, 1.0f, 0.0f, 2.0f,
		 		0.0f, 0.0f, 1.0f, 1.0f,
		 		0.0f, 0.0f, 0.0f, 1.0f
		 	},
			.expectedAnswer2x2 = {
				 1.0f,    0.0f,   -999.0f, -999.0f,
				 0.0f,    1.0f,   -999.0f, -999.0f,
				-999.0f, -999.0f, -999.0f, -999.0f,
				-999.0f, -999.0f, -999.0f, -999.0f
			},
			.expectedAnswer3x3 = {
				 1.0f,    0.0f,    0.0f,   -999.0f,
				 0.0f,    1.0f,    0.0f,   -999.0f,
				 0.0f,    0.0f,    1.0f,   -999.0f,
				-999.0f, -999.0f, -999.0f, -999.0f
			},
		 	.expectedAnswer4x4 = {
		 		1.0f, 0.0f, 0.0f, -3.0f,
		 		0.0f, 1.0f, 0.0f, -2.0f,
		 		0.0f, 0.0f, 1.0f, -1.0f,
		 		0.0f, 0.0f, 0.0f,  1.0f
		 	}
		},
		{
			.values = {
				6.0f, 2.0f, 3.0f, 4.0f,
				2.0f, 7.0f, 5.0f, 3.0f,
				3.0f, 5.0f, 7.0f, 2.0f,
				4.0f, 3.0f, 2.0f, 6.0f
			},
				.expectedAnswer2x2 = {
				 0.184210526316f,  -0.0526315789474f, -999.0f, -999.0f,
				-0.0526315789474f,  0.157894736842f,  -999.0f, -999.0f,
				-999.0f,           -999.0f,           -999.0f, -999.0f,
				-999.0f,           -999.0f,           -999.0f, -999.0f
			},
				.expectedAnswer3x3 = {
				 0.212389380531f,    0.00884955752212f, -0.0973451327434f, -999.0f,
				 0.00884955752212f,  0.29203539823f,    -0.212389380531f,  -999.0f,
				-0.0973451327434f,  -0.212389380531f,    0.336283185841f,  -999.0f,
				-999.0f,            -999.0f,            -999.0f,           -999.0f
			},
				.expectedAnswer4x4 = {
				 0.39649122807017543856f,  0.14035087719298245611f, -0.19298245614035087717f, -0.27017543859649122805f,
				 0.14035087719298245611f,  0.38596491228070175434f, -0.28070175438596491225f, -0.19298245614035087718f,
				-0.19298245614035087718f, -0.28070175438596491225f,  0.38596491228070175436f,  0.14035087719298245612f,
				-0.27017543859649122805f, -0.19298245614035087717f,  0.14035087719298245612f,  0.39649122807017543859f
			}
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_Inverse_t* fixture = &fixtures[i];

		parametricTestInvokationGenericParm_t parms[] = {
			{ typeInfo, fixture->values },
			{ typeInfo, NULL            }
		};

		switch ( typeInfo->numRows ) {
			case 2: parms[1].value = fixture->expectedAnswer2x2; break;
			case 3: parms[1].value = fixture->expectedAnswer3x3; break;
			case 4: parms[1].value = fixture->expectedAnswer4x4; break;
		}

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_INVERSE, strings, flags, parms, GEN_COUNTOF( parms ) );
	}
}

static void Gen_GenerateTests_Translate( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	if ( typeInfo->type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( typeInfo->numRows < 4 || typeInfo->numCols < typeInfo->numRows ) {
		return;
	}

	typeInfo_t translateVecType = {
		.type = typeInfo->type,
		.numRows = 1,
		.numCols = 3,
		.fullTypeName = String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( typeInfo->type ), translateVecType.numCols )
	};

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType = typeInfo,
		.funcName = GEN_FUNCTION_NAME_TRANSLATE,
		.parmsCount = 2,
		.parms = (parametricTestDefinitionParm_t[]) {
			{  typeInfo,         "startMatrix"  },
			{ &translateVecType, "translateVec" }
		},
	} );

	testFixture_Translate_t fixtures[] = {
		{
			.matrix = {
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f
			},
			.translateVec = { 1.0f, 0.0f, 0.0f },
			.expectedAnswer = {
				0.0f, 0.0f, 0.0f, 1.0f,
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f
			}
		},

		{
			.matrix = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			},
			.translateVec = { 3.0f, 2.0f, 1.0f },
			.expectedAnswer = {
				1.0f, 0.0f, 0.0f, 3.0f,
				0.0f, 1.0f, 0.0f, 2.0f,
				0.0f, 0.0f, 1.0f, 1.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			}
		},

		{
			.matrix = {
				0.0f,  1.0f,  2.0f,  3.0f,
				4.0f,  5.0f,  6.0f,  7.0f,
				8.0f,  9.0f,  10.0f, 11.0f,
				12.0f, 13.0f, 14.0f, 15.0f
			},
			.translateVec = { 10.0f, 20.0f, 30.0f },
			.expectedAnswer = {
				0.0f,  1.0f,  2.0f,  13.0f,
				4.0f,  5.0f,  6.0f,  27.0f,
				8.0f,  9.0f,  10.0f, 41.0f,
				12.0f, 13.0f, 14.0f, 15.0f
			}
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_Translate_t* fixture = &fixtures[i];

		parametricTestInvokationGenericParm_t parms[] = {
			{  typeInfo,         fixture->matrix         },
			{ &translateVecType, fixture->translateVec   },
			{ typeInfo,          fixture->expectedAnswer }
		};

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_TRANSLATE, strings, flags, parms, GEN_COUNTOF( parms ) );
	}
}

static void Gen_GenerateTests_Rotate( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	if ( typeInfo->numRows < 4 || typeInfo->numRows != typeInfo->numCols ) {
		return;
	}

	typeInfo_t scalarType = Gen_GetScalarType( typeInfo );

	typeInfo_t rotateVectorType = {
		.type			= typeInfo->type,
		.numRows		= 1,
		.numCols		= 3,
		.fullTypeName	= String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( rotateVectorType.type ), rotateVectorType.numCols )
	};

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType = typeInfo,
		.funcName = GEN_FUNCTION_NAME_ROTATE,
		.parmsCount = 3,
		.parms = (parametricTestDefinitionParm_t[]) {
			{  typeInfo,         "startMatrix"     },
			{ &scalarType,       "rotationDegrees" },
			{ &rotateVectorType, "axisAngle"       }
		},
	} );

	float32 deg2Rad_45 = 0.7853982f;

	testFixture_Rotate_t fixtures[] = {
		{
			.matrix = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			},
			.rotationDeg	= deg2Rad_45,
			.axisAngle		= { 1.0f, 0.0f, 0.0f },
			.expectedAnswer	= {
				1.0f, 0.0f,        0.0f,       0.0f,
				0.0f, 0.7071068f, -0.7071068f, 0.0f,
				0.0f, 0.7071068f,  0.7071068f, 0.0f,
				0.0f, 0.0f,        0.0f,       1.0f
			}
		},

		{
			.matrix = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			},
			.rotationDeg	= deg2Rad_45,
			.axisAngle		= { 0.0f, 1.0f, 0.0f },
			.expectedAnswer	= {
				 0.7071068f, 0.0f, 0.7071068f, 0.0f,
				 0.0f,       1.0f, 0.0f,       0.0f,
				-0.7071068f, 0.0f, 0.7071068f, 0.0f,
				 0.0f,       0.0f, 0.0f,       1.0f
			}
		},

		{
			.matrix = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			},
			.rotationDeg	= deg2Rad_45,
			.axisAngle		= { 0.0f, 0.0f, 1.0f },
			.expectedAnswer	= {
				0.7071068f, -0.7071068f, 0.0f, 0.0f,
				0.7071068f,  0.7071068f, 0.0f, 0.0f,
				0.0f,        0.0f,       1.0f, 0.0f,
				0.0f,        0.0f,       0.0f, 1.0f
			}
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_Rotate_t* fixture = &fixtures[i];

		parametricTestInvokationGenericParm_t parms[] = {
			{  typeInfo,          fixture->matrix         },
			{ &scalarType,       &fixture->rotationDeg    },
			{ &rotateVectorType,  fixture->axisAngle      },
			{ typeInfo,           fixture->expectedAnswer }
		};

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_ROTATE, strings, flags, parms, GEN_COUNTOF( parms ) );
	}
}

static void Gen_GenerateTests_Scale( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	if ( typeInfo->type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( typeInfo->numRows < 4 ) {
		return;
	}

	if ( typeInfo->numRows != typeInfo->numCols ) {
		return;
	}

	typeInfo_t scaleVecType = {
		.type = typeInfo->type,
		.numRows = 1,
		.numCols = 3,
		.fullTypeName = String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( scaleVecType.type ), scaleVecType.numCols )
	};

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType = typeInfo,
		.funcName = GEN_FUNCTION_NAME_SCALE,
		.parmsCount = 2,
		.parms = (parametricTestDefinitionParm_t[]) {
			{  typeInfo,     "startMatrix" },
			{ &scaleVecType, "scaleVec"    }
		},
	} );

	testFixture_Scale_t fixtures[] = {
		{
			.matrix = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			},
			.scaleVec		= { 0.0f, 0.0f, 0.0f },
			.expectedAnswer	= {
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			}
		},

		{
			.matrix = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			},
			.scaleVec		= { 1.0f, 1.0f, 1.0f },
			.expectedAnswer	= {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			}
		},

		{
			.matrix = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			},
			.scaleVec		= { 2.0f, 2.0f, 2.0f },
			.expectedAnswer	= {
				2.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 2.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 2.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			}
		},

		{
			.matrix = {
				1.0f,  2.0f,  3.0f,  4.0f,
				5.0f,  6.0f,  7.0f,  8.0f,
				9.0f,  10.0f, 11.0f, 12.0f,
				13.0f, 14.0f, 15.0f, 16.0f
			},
			.scaleVec		= { 1.0f, 2.0f, 3.0f },
			.expectedAnswer	= {
				1.0f,  2.0f,  3.0f,  4.0f,
				5.0f,  12.0f, 7.0f,  8.0f,
				9.0f,  10.0f, 33.0f, 12.0f,
				13.0f, 14.0f, 15.0f, 16.0f
			}
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_Scale_t* fixture = &fixtures[i];

		parametricTestInvokationGenericParm_t parms[] = {
			{  typeInfo,     fixture->matrix         },
			{ &scaleVecType, fixture->scaleVec       },
			{ typeInfo,      fixture->expectedAnswer }
		};

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_SCALE, strings, flags, parms, GEN_COUNTOF( parms ) );
	}
}

static void Gen_GenerateTests_Ortho_Internal( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const char* funcName, const generatorStrings_t* strings, const generatorFlags_t flags, const testFixture_Ortho_t* fixtures, const u32 fixturesCount ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( funcName );
	assert( strings );
	assert( fixtures );
	assert( fixturesCount );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	if ( typeInfo->numRows < 4 ) {
		return;
	}

	if ( typeInfo->numRows != typeInfo->numCols ) {
		return;
	}

	typeInfo_t scalarType = Gen_GetScalarType( typeInfo );

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType = typeInfo,
		.funcName = funcName,
		.parmsCount = 6,
		.parms = (parametricTestDefinitionParm_t[]) {
			{ &scalarType, "left"   },
			{ &scalarType, "right"  },
			{ &scalarType, "top"    },
			{ &scalarType, "bottom" },
			{ &scalarType, "znear"  },
			{ &scalarType, "zfar"   }
		},
	} );

	for ( u32 i = 0; i < fixturesCount; i++ ) {
		const testFixture_Ortho_t* fixture = &fixtures[i];

		const float32 testAspect = fixture->width / fixture->height;

		const float32 testLeft =	-testAspect * fixture->orthoSize;
		const float32 testRight =	 testAspect * fixture->orthoSize;
		const float32 testTop =		-fixture->orthoSize;
		const float32 testBottom =	 fixture->orthoSize;

		parametricTestInvokationGenericParm_t parms[] = {
			{ &scalarType, &testLeft                },
			{ &scalarType, &testRight               },
			{ &scalarType, &testTop                 },
			{ &scalarType, &testBottom              },
			{ &scalarType, &fixture->zNear          },
			{ &scalarType, &fixture->zFar           },
			{  typeInfo,    fixture->expectedAnswer }
		};

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, funcName, strings, flags, parms, GEN_COUNTOF( parms ) );
	}
}

static void Gen_GenerateTests_Ortho_LH_ZO( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	testFixture_Ortho_t fixtures[] = {
		{
			.width = 1280.0f, .height = 720.0f, .orthoSize = 5.0f, .zNear = -1.0f, .zFar = 100.0f,
			.expectedAnswer = {
				0.112499997f,  0.0f,         0.0f,           0.0f,
				0.0f,         -0.200000003f, 0.0f,           0.0f,
				0.0f,          0.0f,         0.00990098994f, 0.00990098994f,
				0.0f,          0.0f,         0.0f,           1.0f
			}
		}
	};

	Gen_GenerateTests_Ortho_Internal( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_ORTHO_LH_ZO, strings, flags, fixtures, GEN_COUNTOF( fixtures ) );
}

static void Gen_GenerateTests_Ortho_LH_NO( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	testFixture_Ortho_t fixtures[] = {
		{
			.width = 1280.0f, .height = 720.0f, .orthoSize = 5.0f, .zNear = -1.0f, .zFar = 100.0f,
			.expectedAnswer = {
				0.11250f,  0.0f, 0.0f,      -0.0f,
				0.0f,     -0.2f, 0.0f,       0.0f,
				0.0f,      0.0f, 0.019802f, -0.980198f,
				0.0f,      0.0f, 0.0f,       1.0f
			}
		}
	};

	Gen_GenerateTests_Ortho_Internal( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_ORTHO_LH_NO, strings, flags, fixtures, GEN_COUNTOF( fixtures ) );
}

static void Gen_GenerateTests_Ortho_RH_ZO( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	testFixture_Ortho_t fixtures[] = {
		{
			.width = 1280.0f, .height = 720.0f, .orthoSize = 5.0f, .zNear = -1.0f, .zFar = 100.0f,
			.expectedAnswer = {
				0.1125f,  0.0f,  0.0f,      -0.0f,
				0.0f,    -0.2f,  0.0f,       0.0f,
				0.0f,     0.0f, -0.009901f,  0.009901f,
				0.0f,     0.0f,  0.0f,       1.0f
			}
		}
	};

	Gen_GenerateTests_Ortho_Internal( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_ORTHO_RH_ZO, strings, flags, fixtures, GEN_COUNTOF( fixtures ) );
}

static void Gen_GenerateTests_Ortho_RH_NO( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	testFixture_Ortho_t fixtures[] = {
		{
			.width = 1280.0f, .height = 720.0f, .orthoSize = 5.0f, .zNear = -1.0f, .zFar = 100.0f,
			.expectedAnswer = {
				0.112500f,  0.0f,  0.0f,      -0.0f,
				0.0f,      -0.2f,  0.0f,       0.0f,
				0.0f,       0.0f, -0.019802f, -0.980198f,
				0.0f,       0.0f,  0.0f,       1.0f
			}
		}
	};

	Gen_GenerateTests_Ortho_Internal( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_ORTHO_RH_NO, strings, flags, fixtures, GEN_COUNTOF( fixtures ) );
}

static void Gen_GenerateTests_Perspective_Internal( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const char* funcName, const generatorStrings_t* strings, const generatorFlags_t flags, const testFixture_Perspective_t* fixtures, const u32 fixturesCount ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( funcName );
	assert( fixtures );
	assert( fixturesCount );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	if ( typeInfo->numRows < 4 ) {
		return;
	}

	if ( typeInfo->numRows != typeInfo->numCols ) {
		return;
	}

	typeInfo_t scalarType = {
		.type			= typeInfo->type,
		.numRows		= 1,
		.numCols		= 1,
		.fullTypeName	= Gen_GetMemberTypeString( scalarType.type )
	};

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType = typeInfo,
		.funcName = funcName,
		.parmsCount = 4,
		.parms = (parametricTestDefinitionParm_t[]) {
			{ &scalarType, "fov"    },
			{ &scalarType, "aspect" },
			{ &scalarType, "znear"  },
			{ &scalarType, "zfar"   }
		}
	} );

	for ( u32 i = 0; i < fixturesCount; i++ ) {
		const testFixture_Perspective_t* fixture = &fixtures[i];

		const float32 testAspect = fixture->width / fixture->height;

		parametricTestInvokationGenericParm_t parms[] = {
			{ &scalarType, &fixture->fovDeg         },
			{ &scalarType, &testAspect              },
			{ &scalarType, &fixture->zNear          },
			{ &scalarType, &fixture->zFar           },
			{  typeInfo,    fixture->expectedAnswer }
		};

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, funcName, strings, flags, parms, GEN_COUNTOF( parms ) );
	}
}

static void Gen_GenerateTests_Perspective_LH_ZO( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	testFixture_Perspective_t fixtures[] = {
		{
			.width = 1280.0f, .height = 720.0f, .fovDeg = 90.0f, .zNear = 0.1f, .zFar = 100.0f,
			.expectedAnswer = {
				0.347270f, 0.0f,      0.0f,       0.0f,
				0.0f,      0.617370f, 0.0f,       0.0f,
				0.0f,      0.0f,      1.001001f, -0.100100f,
				0.0f,      0.0f,      1.0f,       0.0f
			}
		}
	};

	Gen_GenerateTests_Perspective_Internal( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_PERSPECTIVE_LH_ZO, strings, flags, fixtures, GEN_COUNTOF( fixtures ) );
}

static void Gen_GenerateTests_Perspective_LH_NO( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	testFixture_Perspective_t fixtures[] = {
		{
			.width = 1280.0f, .height = 720.0f, .fovDeg = 90.0f, .zNear = 0.1f, .zFar = 100.0f,
			.expectedAnswer = {
				0.347270f, 0.0f,      0.0f,       0.0f,
				0.0f,      0.617370f, 0.0f,       0.0f,
				0.0f,      0.0f,      1.002002f, -0.200200f,
				0.0f,      0.0f,      1.0f,       0.0f
			}
		}
	};

	Gen_GenerateTests_Perspective_Internal( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_PERSPECTIVE_LH_NO, strings, flags, fixtures, GEN_COUNTOF( fixtures ) );
}

static void Gen_GenerateTests_Perspective_RH_ZO( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	testFixture_Perspective_t fixtures[] = {
		{
			.width = 1280.0f, .height = 720.0f, .fovDeg = 90.0f, .zNear = 0.1f, .zFar = 100.0f,
			.expectedAnswer = {
				0.347270f, 0.0f,       0.0f,       0.0f,
				0.0f,      0.617370f,  0.0f,       0.0f,
				0.0f,      0.0f,      -1.001001f, -0.100100f,
				0.0f,      0.0f,      -1.0f,       0.0f
			}
		}
	};

	Gen_GenerateTests_Perspective_Internal( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_PERSPECTIVE_RH_ZO, strings, flags, fixtures, GEN_COUNTOF( fixtures ) );
}

static void Gen_GenerateTests_Perspective_RH_NO( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	testFixture_Perspective_t fixtures[] = {
		{
			.width = 1280.0f, .height = 720.0f, .fovDeg = 90.0f, .zNear = 0.1f, .zFar = 100.0f,
			.expectedAnswer = {
				0.347270f, 0.0f,       0.0f,       0.0f,
				0.0f,      0.617370f,  0.0f,       0.0f,
				0.0f,      0.0f,      -1.002002f, -0.200200f,
				0.0f,      0.0f,      -1.0f,       0.0f
			}
		}
	};

	Gen_GenerateTests_Perspective_Internal( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_PERSPECTIVE_RH_NO, strings, flags, fixtures, GEN_COUNTOF( fixtures ) );
}

static void Gen_GenerateTests_LookAt_Internal( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const char* funcName, const generatorStrings_t* strings, const generatorFlags_t flags, const testFixture_LookAt_t* fixtures, const u32 fixturesCount ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( funcName );
	assert( fixtures );
	assert( fixturesCount );

	if ( !Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		return;
	}

	if ( typeInfo->numRows < 4 ) {
		return;
	}

	if ( typeInfo->numRows != typeInfo->numCols ) {
		return;
	}

	typeInfo_t vectorType = {
		.type = typeInfo->type,
		.numRows = 1,
		.numCols = 3,
		.fullTypeName = String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( vectorType.type ), vectorType.numCols )
	};

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType = typeInfo,
		.funcName = funcName,
		.parmsCount = 3,
		.parms = (parametricTestDefinitionParm_t[]) {
			{ &vectorType, "eye"    },
			{ &vectorType, "target" },
			{ &vectorType, "up"     }
		}
	} );

	for ( u32 i = 0; i < fixturesCount; i++ ) {
		const testFixture_LookAt_t* fixture = &fixtures[i];

		parametricTestInvokationGenericParm_t parms[] = {
			{ &vectorType, fixture->eye            },
			{ &vectorType, fixture->target         },
			{ &vectorType, fixture->up             },
			{  typeInfo,   fixture->expectedAnswer }
		};

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, funcName, strings, flags, parms, GEN_COUNTOF( parms ) );
	}
}

static void Gen_GenerateTests_LookAt_LH( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	testFixture_LookAt_t fixtures[] = {
		{
			.eye =		{ 0.0f, 0.0f, 0.0f },
			.target =	{ 0.0f, 0.0f, 1.0f },
			.up =		{ 0.0f, 1.0f, 0.0f },
			.expectedAnswer = {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			}
		}
	};

	Gen_GenerateTests_LookAt_Internal( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_LOOK_AT_LH, strings, flags, fixtures, GEN_COUNTOF( fixtures ) );
}

static void Gen_GenerateTests_LookAt_RH( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	testFixture_LookAt_t fixtures[] = {
		{
			.eye =		{ 0.0f, 0.0f, 0.0f },
			.target =	{ 0.0f, 0.0f, 1.0f },
			.up =		{ 0.0f, 1.0f, 0.0f },
			.expectedAnswer = {
				-1.0f, 0.0f,  0.0f, 0.0f,
				 0.0f, 1.0f,  0.0f, 0.0f,
				 0.0f, 0.0f, -1.0f, 0.0f,
				 0.0f, 0.0f,  0.0f, 1.0f
			}
		}
	};

	Gen_GenerateTests_LookAt_Internal( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_LOOK_AT_RH, strings, flags, fixtures, GEN_COUNTOF( fixtures ) );
}

static void GenerateMatrixTests( allocatorLinear_t* tempStorage, const char* generatedTestsPath, const char* languageName, const typeInfo_t* matrixTypeInfos, const u32 matrixTypeInfosCount, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( generatedTestsPath );
	assert( languageName );
	assert( matrixTypeInfos );
	assert( matrixTypeInfosCount );
	assert( strings );

	for ( u32 typeInfoIndex = 0; typeInfoIndex < matrixTypeInfosCount; typeInfoIndex++ ) {
		const typeInfo_t* typeInfo = &matrixTypeInfos[typeInfoIndex];

		typeInfo_t scalarType = {
			.type			= typeInfo->type,
			.numRows		= 1,
			.numCols		= 1,
			.fullTypeName	= Gen_GetMemberTypeString( scalarType.type )
		};

		typeInfo_t scalarTypeFloatingPoint = {
			.type			= Gen_GetSupportedFloatingPointType( typeInfo->type ),
			.numRows		= 1,
			.numCols		= 1,
			.fullTypeName	= Gen_GetTypeString( scalarTypeFloatingPoint.type )
		};

		typeInfo_t memberType = {
			.type			= typeInfo->type,
			.numRows		= 1,
			.numCols		= typeInfo->numCols,
			.fullTypeName	= String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( memberType.type ), memberType.numCols )
		};

		assert( typeInfo->fullTypeName );
		assert( scalarType.fullTypeName );
		assert( scalarTypeFloatingPoint.fullTypeName );
		assert( memberType.fullTypeName );

		printf( "Generating test_%s.%s...", typeInfo->fullTypeName, languageName );

		stringBuilder_t* code = StringBuilder_Create( tempStorage, 4 * MB_TO_BYTES );

		StringBuilder_Append( code, GEN_FILE_HEADER );

		GenerateComponentWiseTests( tempStorage, code, typeInfo, &scalarType, &scalarTypeFloatingPoint, strings, flags );

		Gen_GenerateTests_Identity( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Transpose( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_MatrixMulMatrix( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_MatrixMulVector( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Determinant( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Inverse( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Translate( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Rotate( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Scale( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Ortho_LH_ZO( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Ortho_LH_NO( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Ortho_RH_ZO( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Ortho_RH_NO( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Perspective_LH_ZO( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Perspective_LH_NO( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Perspective_RH_ZO( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Perspective_RH_NO( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_LookAt_LH( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_LookAt_RH( tempStorage, code, typeInfo, strings, flags );

		const char* fileNameHeader = String_TPrintf( tempStorage, "%s/test_%s.%s", generatedTestsPath, typeInfo->fullTypeName, languageName );
		FS_WriteEntireFile( fileNameHeader, code->str, code->length );

		printf( "OK.\n" );

		Mem_Reset( tempStorage );
	}
}