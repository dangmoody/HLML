typedef struct parametricTestDefinitionParm_t {
	const typeInfo_t*						typeInfo;
	const char*								parmName;
} parametricTestDefinitionParm_t;

typedef struct parametricTestDefinition_t {
	const typeInfo_t*						returnType;
	const parametricTestDefinitionParm_t*	parms;
	u32										parmsCount;
	bool32									alsoGenerateSSE;
	const char*								funcName;
	const char*								testNameOverride;	// if NULL then generator will pick its own test name
} parametricTestDefinition_t;

typedef struct testValues_t {
	float32*		values;
} testValues_t;

typedef struct componentWiseTestsData_t {
	u32								numTests;
	u32								parmDefsCount;
	parametricTestDefinitionParm_t*	parmDefs;
	testValues_t*					inputs;
	const typeInfo_t*				outputType;
	testValues_t*					outputs;
	bool32							generateSSE;	// if true will generate an SSE test definition as well as the standard one
} componentWiseTestsData_t;

typedef struct testFixtureOperator_t {
	const typeInfo_t*	lhsType;
	const typeInfo_t*	rhsType;
	const typeInfo_t*	returnType;
	const float32*		lhsValues;
	const float32*		rhsValues;
	const float32*		outputValues;
	u32					numTests;
} testFixtureOperator_t;

typedef struct testFixtureOperatorSingleParm_t {
	float32*	inputValues;
	float32*	outputValues;
	u32			numTests;
} testFixtureOperatorSingleParm_t;

typedef struct parametricTestInvokationGenericParm_t {
	const typeInfo_t*	typeInfo;
	const float32*		value;
} parametricTestInvokationGenericParm_t;

typedef struct testFixture_All_t {
	bool32	values[16];
	bool32	expectedAnswer;
} testFixture_All_t;

typedef struct testFixture_Any_t {
	bool32	values[16];
	bool32	expectedAnswer;
} testFixture_Any_t;

static const char* Gen_GetTestName( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const char* funcName ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( funcName );

	return String_TPrintf( tempStorage, "Test_%s_%s", typeInfo->fullTypeName, funcName );
}

static const char* Gen_GetTestName_SSE( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const char* funcName ) {
	assert( tempStorage );
	assert( typeInfo );
	assert( funcName );

	const char* testName = Gen_GetTestName( tempStorage, typeInfo, funcName );

	return String_TPrintf( tempStorage, "%s_sse", testName );
}

static void Gen_GenerateParametricTestDefinition_Operator( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* lhsType, const typeInfo_t* rhsType, const typeInfo_t* returnType, const char* opName, const char* opStr, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( lhsType );
	assert( lhsType->fullTypeName );
	assert( !Gen_TypeIsScalar( lhsType ) );
	assert( rhsType );
	assert( rhsType->fullTypeName );
	assert( returnType );
	assert( returnType->fullTypeName );
	assert( opName );
	assert( opStr );
	assert( strings );
	assert( flags & GENERATOR_FLAG_GENERATE_OPERATORS );

	const char* testName = Gen_GetTestName( tempStorage, lhsType, opName );

	StringBuilder_Appendf( code, "TEMPER_PARAMETRIC( %s, TEMPER_FLAG_SHOULD_RUN, const %s%s lhs, const %s%s rhs, const %s%s expectedAnswer )\n", testName, lhsType->fullTypeName, strings->parmPassByStr, rhsType->fullTypeName, strings->parmPassByStr, returnType->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\t%s actualResult = lhs %s rhs;\n", returnType->fullTypeName, opStr );
	StringBuilder_Append(  code, "\tTEMPER_CHECK_TRUE( actualResult == expectedAnswer );\n" );
	StringBuilder_Append(  code, "}\n\n" );
}

static void Gen_GenerateParametricTestDefinition_Generic_SSE( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags, parametricTestDefinition_t* def ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );
	assert( def );
	assert( def->parms );
	assert( def->parmsCount );
	assert( def->returnType );
	assert( def->funcName );

	bool32 generateOperators = flags & GENERATOR_FLAG_GENERATE_OPERATORS;

	const char* funcToCall = Gen_GetFuncName_Vector_SSE( tempStorage, typeInfo, flags, def->funcName );
	const char* testName = def->testNameOverride ? def->testNameOverride : Gen_GetTestName_SSE( tempStorage, typeInfo, def->funcName );

	const char* floateqFuncStr = Gen_GetFuncName_Floateq( def->returnType->type );
	const char* equalsFuncStr = NULL;
	const char* returnPassByStr = NULL;
	const char* referenceStr = NULL;

	bool32 returnScalar = Gen_TypeIsScalar( def->returnType );
	bool32 returnScalarFloatingPoint = returnScalar && Gen_TypeIsFloatingPoint( def->returnType->type );

	if ( returnScalar ) {
		equalsFuncStr = floateqFuncStr;
		returnPassByStr = "";
		referenceStr = "";
	} else {
		equalsFuncStr = Gen_GetFuncName_Vector( tempStorage, def->returnType, flags, GEN_FUNCTION_NAME_EQUALS );
		returnPassByStr = strings->parmPassByStr;
		referenceStr = strings->parmReferenceStr;
	}

	StringBuilder_Appendf( code, "TEMPER_PARAMETRIC( %s, TEMPER_FLAG_SHOULD_RUN", testName );

	for ( u32 i = 0; i < def->parmsCount; i++ ) {
		const parametricTestDefinitionParm_t* parm = &def->parms[i];
		const typeInfo_t* parmTypeInfo = parm->typeInfo;
		const char* parmPointerStr = Gen_TypeIsScalar( parmTypeInfo ) ? "" : strings->parmPassByStr;

		StringBuilder_Appendf( code, ", const %s%s %s", parmTypeInfo->fullTypeName, parmPointerStr, parm->parmName );
	}

	StringBuilder_Appendf( code, ", const %s%s expectedAnswer )\n", def->returnType->fullTypeName, returnPassByStr );
	StringBuilder_Append(  code, "{\n" );

	for ( u32 parmIndex = 0; parmIndex < def->parmsCount; parmIndex++ ) {
		const parametricTestDefinitionParm_t* parm = &def->parms[parmIndex];

		assert( !Gen_TypeIsMatrix( parm->typeInfo ) );

		if ( Gen_TypeIsScalar( parm->typeInfo ) ) {
			StringBuilder_Appendf( code, "\t__m128 reg_%s = _mm_set1_ps( %s );\n", parm->parmName, parm->parmName );
		} else {
			for ( u32 componentIndex = 0; componentIndex < parm->typeInfo->numCols; componentIndex++ ) {
				const char componentStr = GEN_COMPONENT_NAMES_VECTOR[componentIndex];
				StringBuilder_Appendf( code, "\t__m128 reg_%s_%c = _mm_set1_ps( %s%s%c );\n", parm->parmName, componentStr, parm->parmName, strings->parmAccessOperatorStr, componentStr );
			}
		}

		StringBuilder_Append( code, "\n" );
	}

	if ( returnScalar ) {
		StringBuilder_Appendf( code, "\t__m128 reg_actualAnswer = " );
	} else {
		for ( u32 componentIndex = 0; componentIndex < def->returnType->numCols; componentIndex++ ) {
			StringBuilder_Appendf( code, "\t__m128 reg_actualAnswer_%c;\n", GEN_COMPONENT_NAMES_VECTOR[componentIndex] );
		}
		StringBuilder_Append( code, "\n\t" );
	}

	StringBuilder_Appendf( code, "%s( ", funcToCall );

	for ( u32 parmIndex = 0; parmIndex < def->parmsCount; parmIndex++ ) {
		const parametricTestDefinitionParm_t* parm = &def->parms[parmIndex];

		if ( Gen_TypeIsScalar( typeInfo ) ) {
			StringBuilder_Appendf( code, "reg_%s", parm->parmName );
		} else {
			for ( u32 componentIndex = 0; componentIndex < parm->typeInfo->numCols; componentIndex++ ) {
				StringBuilder_Appendf( code, "reg_%s_%c", parm->parmName, GEN_COMPONENT_NAMES_VECTOR[componentIndex] );

				if ( componentIndex < parm->typeInfo->numCols - 1 ) {
					StringBuilder_Append( code, ", " );
				}
			}
		}

		if ( parmIndex < def->parmsCount - 1 ) {
			StringBuilder_Append( code, ", " );
		}
	}

	if ( !returnScalar ) {
		for ( u32 componentIndex = 0; componentIndex < def->returnType->numCols; componentIndex++ ) {
			StringBuilder_Appendf( code, ", %sreg_actualAnswer_%c", strings->parmReferenceStr, GEN_COMPONENT_NAMES_VECTOR[componentIndex] );
		}
	}

	StringBuilder_Append( code, " );\n\n" );

	StringBuilder_Append( code, "\tfloat actualAnswer[4];\n" );

	if ( returnScalar ) {
		StringBuilder_Append( code, "\t_mm_store_ps( actualAnswer, reg_actualAnswer );\n\n" );

		if ( returnScalarFloatingPoint || ( !returnScalar && !generateOperators ) ) {
			StringBuilder_Appendf( code,
				"\tTEMPER_CHECK_TRUE( %s( %sactualAnswer[0], expectedAnswer ) );\n"
				"\tTEMPER_CHECK_TRUE( %s( %sactualAnswer[1], expectedAnswer ) );\n"
				"\tTEMPER_CHECK_TRUE( %s( %sactualAnswer[2], expectedAnswer ) );\n"
				"\tTEMPER_CHECK_TRUE( %s( %sactualAnswer[3], expectedAnswer ) );\n"
				, equalsFuncStr, referenceStr
				, equalsFuncStr, referenceStr
				, equalsFuncStr, referenceStr
				, equalsFuncStr, referenceStr
			);
		} else {
			StringBuilder_Append( code,
				"\tTEMPER_CHECK_TRUE( actualAnswer[0] == expectedAnswer );\n"
				"\tTEMPER_CHECK_TRUE( actualAnswer[1] == expectedAnswer );\n"
				"\tTEMPER_CHECK_TRUE( actualAnswer[2] == expectedAnswer );\n"
				"\tTEMPER_CHECK_TRUE( actualAnswer[3] == expectedAnswer );\n"
			);
		}
	} else {
		for ( u32 componentIndex = 0; componentIndex < def->returnType->numCols; componentIndex++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[componentIndex];

			StringBuilder_Appendf( code, "\t_mm_store_ps( actualAnswer, reg_actualAnswer_%c );\n", componentStr );

			StringBuilder_Appendf( code, "\tTEMPER_CHECK_ALMOST_EQUAL( actualAnswer[0], expectedAnswer%s%c, 1e-3f );\n", strings->parmAccessOperatorStr, componentStr );
			StringBuilder_Appendf( code, "\tTEMPER_CHECK_ALMOST_EQUAL( actualAnswer[1], expectedAnswer%s%c, 1e-3f );\n", strings->parmAccessOperatorStr, componentStr );
			StringBuilder_Appendf( code, "\tTEMPER_CHECK_ALMOST_EQUAL( actualAnswer[2], expectedAnswer%s%c, 1e-3f );\n", strings->parmAccessOperatorStr, componentStr );
			StringBuilder_Appendf( code, "\tTEMPER_CHECK_ALMOST_EQUAL( actualAnswer[3], expectedAnswer%s%c, 1e-3f );\n", strings->parmAccessOperatorStr, componentStr );

			StringBuilder_Appendf( code, "\n" );
		}
	}

	StringBuilder_Append( code, "}\n\n" );
}

static void Gen_GenerateParametricTestDefinition_Generic( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags, parametricTestDefinition_t* def ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );
	assert( def );
	assert( def->parms );
	assert( def->parmsCount );
	assert( def->returnType );
	assert( def->funcName );

	bool32 generateOperators = flags & GENERATOR_FLAG_GENERATE_OPERATORS;
	bool32 allowNameMangling = flags & GENERATOR_FLAG_NAME_MANGLING;

	const char* funcToCall = def->funcName;
	if ( !allowNameMangling ) {
		// HACK(DM): floateq doesnt follow the same naming convention as the other scalar functions
		// so we have to check for that specifically
		if ( !String_Equals( def->funcName, Gen_GetFuncName_Floateq( typeInfo->type ) ) ) {
			if ( Gen_TypeIsScalar( typeInfo ) ) {
				funcToCall = Gen_GetFuncName_Scalar( tempStorage, typeInfo->type, flags, def->funcName );
			} else {
				funcToCall = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, def->funcName );
			}
		}
	}

	const char* testName = def->testNameOverride ? def->testNameOverride : Gen_GetTestName( tempStorage, typeInfo, def->funcName );

	const char* equalsFuncStr = NULL;
	const char* passByStr = NULL;
	const char* referenceStr = NULL;

	bool32 returnScalar = Gen_TypeIsScalar( def->returnType );
	bool32 returnScalarFloatingPoint = returnScalar && Gen_TypeIsFloatingPoint( def->returnType->type );

	if ( returnScalar ) {
		equalsFuncStr = Gen_GetFuncName_Floateq( def->returnType->type );
		passByStr = "";
		referenceStr = "";
	} else {
		equalsFuncStr = Gen_GetFuncName_Vector( tempStorage, def->returnType, flags, GEN_FUNCTION_NAME_EQUALS );
		passByStr = strings->parmPassByStr;
		referenceStr = strings->parmReferenceStr;
	}

	StringBuilder_Appendf( code, "TEMPER_PARAMETRIC( %s, TEMPER_FLAG_SHOULD_RUN", testName );

	for ( u32 i = 0; i < def->parmsCount; i++ ) {
		const parametricTestDefinitionParm_t* parm = &def->parms[i];
		const typeInfo_t* parmTypeInfo = parm->typeInfo;
		const char* parmPointerStr = Gen_TypeIsScalar( parmTypeInfo ) ? "" : strings->parmPassByStr;

		StringBuilder_Appendf( code, ", const %s%s %s", parmTypeInfo->fullTypeName, parmPointerStr, parm->parmName );
	}

	StringBuilder_Appendf( code, ", const %s%s expectedAnswer )\n", def->returnType->fullTypeName, passByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\t%s actualResult = %s( ", def->returnType->fullTypeName, funcToCall );

	for ( u32 i = 0; i < def->parmsCount; i++ ) {
		StringBuilder_Appendf( code, "%s", def->parms[i].parmName );

		if ( i != def->parmsCount - 1 ) {
			StringBuilder_Append( code, ", " );
		}
	}

	StringBuilder_Append( code, " );\n" );
	if ( returnScalarFloatingPoint || ( !returnScalar && !generateOperators ) ) {
		StringBuilder_Appendf( code, "\tTEMPER_CHECK_TRUE( %s( %sactualResult, expectedAnswer ) );\n", equalsFuncStr, referenceStr );
	} else {
		StringBuilder_Append( code, "\tTEMPER_CHECK_TRUE( actualResult == expectedAnswer );\n" );
	}
	StringBuilder_Append( code, "}\n\n" );

	if ( def->alsoGenerateSSE ) {
		Gen_GenerateParametricTestDefinition_Generic_SSE( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
			.returnType = def->returnType,
			.funcName = def->funcName,
			.parmsCount = def->parmsCount,
			.parms = def->parms
		} );
	}
}

static void Gen_GenerateParametricTestDefinition_ComponentWise_SSE( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags, const parametricTestDefinition_t* def ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( Gen_TypeSupportsSIMD( typeInfo->type ) );
	assert( strings );
	assert( def );
	assert( def->parms );
	assert( def->parmsCount );
	assert( def->returnType );
	assert( def->funcName );

	bool32 generateOperators = flags & GENERATOR_FLAG_GENERATE_OPERATORS;
	//bool32 allowNameMangling = flags & GENERATOR_FLAG_NAME_MANGLING;

	const char* funcToCall = def->funcName;
	//if ( !allowNameMangling )
	{
		// HACK(DM): floateq doesnt follow the same naming convention as the other scalar functions
		// so we have to check for that specifically
		if ( !String_Equals( def->funcName, Gen_GetFuncName_Floateq( typeInfo->type ) ) ) {
			if ( Gen_TypeIsScalar( typeInfo ) ) {
				funcToCall = Gen_GetFuncName_Scalar_SSE( tempStorage, typeInfo->type, flags, def->funcName );
			} else {
				funcToCall = Gen_GetFuncName_Vector_SSE( tempStorage, typeInfo, flags, def->funcName );
			}
		}
	}

	const char* testName = Gen_GetTestName_SSE( tempStorage, typeInfo, def->funcName );

	const char* equalsFuncStr = NULL;
	const char* passByStr = NULL;
	// const char* referenceStr = NULL;

	bool32 returnScalar = Gen_TypeIsScalar( def->returnType );
	bool32 returnScalarFloatingPoint = returnScalar && Gen_TypeIsFloatingPoint( def->returnType->type );

	if ( returnScalar ) {
		equalsFuncStr = Gen_GetFuncName_Floateq( def->returnType->type );
		passByStr = "";
		// referenceStr = "";
	} else {
		equalsFuncStr = Gen_GetFuncName_Vector( tempStorage, def->returnType, flags, GEN_FUNCTION_NAME_EQUALS );
		passByStr = strings->parmPassByStr;
		// referenceStr = strings->parmReferenceStr;
	}

	StringBuilder_Appendf( code, "TEMPER_PARAMETRIC( %s, TEMPER_FLAG_SHOULD_RUN", testName );

	for ( u32 i = 0; i < def->parmsCount; i++ ) {
		const parametricTestDefinitionParm_t* parm = &def->parms[i];
		const typeInfo_t* parmTypeInfo = parm->typeInfo;
		const char* parmPointerStr = Gen_TypeIsScalar( parmTypeInfo ) ? "" : strings->parmPassByStr;

		StringBuilder_Appendf( code, ", const %s%s %s", parmTypeInfo->fullTypeName, parmPointerStr, parm->parmName );
	}

	StringBuilder_Appendf( code, ", const %s%s expectedAnswer )\n", def->returnType->fullTypeName, passByStr );
	StringBuilder_Append(  code, "{\n" );

	for ( u32 i = 0; i < def->parmsCount; i++ ) {
		const parametricTestDefinitionParm_t* parm = &def->parms[i];

		StringBuilder_Appendf( code, "\t__m128 reg_%s = _mm_set1_ps( %s );\n", parm->parmName, parm->parmName );
	}

	StringBuilder_Appendf( code, "\n\t__m128 reg_actualAnswer = %s( ", funcToCall );

	for ( u32 i = 0; i < def->parmsCount; i++ ) {
		StringBuilder_Appendf( code, "reg_%s", def->parms[i].parmName );

		if ( i != def->parmsCount - 1 ) {
			StringBuilder_Append( code, ", " );
		}
	}

	StringBuilder_Append( code, " );\n\n" );

	StringBuilder_Append( code,
		"\tfloat actualAnswer[4];\n"
		"\t_mm_store_ps( actualAnswer, reg_actualAnswer );\n\n"
	);

	if ( returnScalarFloatingPoint || ( !returnScalar && !generateOperators ) ) {
		StringBuilder_Appendf( code,
			"\tTEMPER_CHECK_TRUE( %s( actualAnswer[0], expectedAnswer ) );\n"
			"\tTEMPER_CHECK_TRUE( %s( actualAnswer[1], expectedAnswer ) );\n"
			"\tTEMPER_CHECK_TRUE( %s( actualAnswer[2], expectedAnswer ) );\n"
			"\tTEMPER_CHECK_TRUE( %s( actualAnswer[3], expectedAnswer ) );\n"
			, equalsFuncStr
			, equalsFuncStr
			, equalsFuncStr
			, equalsFuncStr
		);
	} else {
		StringBuilder_Appendf( code,
			"\tTEMPER_CHECK_TRUE( actualAnswer[0] == expectedAnswer );\n"
			"\tTEMPER_CHECK_TRUE( actualAnswer[1] == expectedAnswer );\n"
			"\tTEMPER_CHECK_TRUE( actualAnswer[2] == expectedAnswer );\n"
			"\tTEMPER_CHECK_TRUE( actualAnswer[3] == expectedAnswer );\n"
		);
	}

	StringBuilder_Append( code, "}\n\n" );
}

static void Gen_GenerateParametricTestInvokations_ComponentWise( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const char* funcName, const char* testName, const generatorStrings_t* strings, const generatorFlags_t flags, const componentWiseTestsData_t* testData ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( funcName );
	assert( testName );
	assert( strings );
	assert( testData );
	assert( testData->parmDefs );
	assert( testData->parmDefsCount );
	assert( testData->numTests );
	assert( testData->inputs );
	assert( testData->outputType );
	assert( testData->outputType->fullTypeName );
	assert( testData->outputs );

	if ( Gen_TypeIsScalar( typeInfo ) ) {
		for ( u32 testIndex = 0; testIndex < testData->numTests; testIndex++ ) {
			StringBuilder_Appendf( code, "TEMPER_INVOKE_PARAMETRIC_TEST( %s", testName );

			testValues_t* input = &testData->inputs[testIndex];

			for ( u32 componentIndex = 0; componentIndex < testData->parmDefsCount; componentIndex++ ) {
				const char* numericLiteral = Gen_GetNumericLiteral( tempStorage, typeInfo->type, input->values[componentIndex], 0 );

				StringBuilder_Appendf( code, ", %s", numericLiteral );
			}

			testValues_t* output = &testData->outputs[testIndex];

			for ( u32 componentIndex = 0; componentIndex < testData->outputType->numCols; componentIndex++ ) {
				const char* numericLiteral = Gen_GetNumericLiteral( tempStorage, testData->outputType->type, output->values[componentIndex], 0 );

				StringBuilder_Appendf( code, ", %s", numericLiteral );
			}

			StringBuilder_Append( code, " );\n\n" );
		}
	} else {
		for ( u32 testIndex = 0; testIndex < testData->numTests; testIndex++ ) {
			StringBuilder_Appendf( code, "TEMPER_INVOKE_PARAMETRIC_TEST( %s,\n", testName );

			testValues_t* input = &testData->inputs[testIndex];

			for ( u32 componentIndex = 0; componentIndex < testData->parmDefsCount; componentIndex++ ) {
				parametricTestDefinitionParm_t* parmDef = &testData->parmDefs[componentIndex];

				assert( parmDef );

				float32 inputVal = input->values[componentIndex];
				float32 values[] = {
					inputVal, inputVal, inputVal, inputVal,
					inputVal, inputVal, inputVal, inputVal,
					inputVal, inputVal, inputVal, inputVal,
					inputVal, inputVal, inputVal, inputVal
				};

				stringBuilder_t* ctor = Gen_GetConstructor( tempStorage, parmDef->typeInfo, values, strings, flags );

				StringBuilder_Append( code, ctor->str );
				StringBuilder_Append( code, ",\n" );
			}

			float32 outputVal = testData->outputs[testIndex].values[0];
			float32 values[] = {
				outputVal, outputVal, outputVal, outputVal,
				outputVal, outputVal, outputVal, outputVal,
				outputVal, outputVal, outputVal, outputVal,
				outputVal, outputVal, outputVal, outputVal
			};

			stringBuilder_t* ctor = Gen_GetConstructor( tempStorage, testData->outputType, values, strings, flags );

			StringBuilder_Append( code, ctor->str );
			StringBuilder_Append( code, "\n);\n\n" );
		}
	}
}

static void Gen_GenerateParametricTestsCode_ComponentWise( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const char* funcName, const generatorStrings_t* strings, const generatorFlags_t flags, const componentWiseTestsData_t* testData ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( funcName );
	assert( strings );
	assert( testData );
	assert( testData->parmDefs );
	assert( testData->parmDefsCount );
	assert( testData->numTests );
	assert( testData->inputs );
	assert( testData->outputType );
	assert( testData->outputType->fullTypeName );
	assert( testData->outputs );

	const char* testName = Gen_GetTestName( tempStorage, typeInfo, funcName );

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType	= testData->outputType,
		.funcName	= funcName,
		.parmsCount	= testData->parmDefsCount,
		.parms		= testData->parmDefs
	} );

	Gen_GenerateParametricTestInvokations_ComponentWise( tempStorage, code, typeInfo, funcName, testName, strings, flags, testData );

	if ( testData->generateSSE ) {
		assert( Gen_TypeSupportsSIMD( typeInfo->type ) );

		const char* testNameSSE = Gen_GetTestName_SSE( tempStorage, typeInfo, funcName );

		Gen_GenerateParametricTestDefinition_ComponentWise_SSE( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
			.returnType	= testData->outputType,
			.funcName	= funcName,
			.parmsCount	= testData->parmDefsCount,
			.parms		= testData->parmDefs
		} );

		Gen_GenerateParametricTestInvokations_ComponentWise( tempStorage, code, typeInfo, funcName, testNameSSE, strings, flags, testData );
	}
}

static void Gen_GenerateParametricTestsCode_Operator( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const char* opName, const char* opStr, const generatorStrings_t* strings, const generatorFlags_t flags, const testFixtureOperator_t* fixture ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( opName );
	assert( opStr );
	assert( strings );
	assert( fixture );
	assert( fixture->lhsType );
	assert( fixture->rhsType );
	assert( fixture->returnType );
	assert( fixture->lhsValues );
	assert( fixture->rhsValues );
	assert( fixture->outputValues );
	assert( fixture->numTests );

	const char* testName = Gen_GetTestName( tempStorage, typeInfo, opName );

	if ( flags & GENERATOR_FLAG_GENERATE_OPERATORS ) {
		Gen_GenerateParametricTestDefinition_Operator( tempStorage, code, fixture->lhsType, fixture->rhsType, fixture->returnType, opName, opStr, strings, flags );
	} else {
		Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
			.returnType = fixture->returnType,
			.funcName = opName,
			.parmsCount = 2,
			.parms = (parametricTestDefinitionParm_t[]) {
				{ fixture->lhsType, "lhs" },
				{ fixture->rhsType, "rhs" }
			}
		} );
	}

	for ( u32 testIndex = 0; testIndex < fixture->numTests; testIndex++ ) {
		StringBuilder_Appendf( code, "TEMPER_INVOKE_PARAMETRIC_TEST( %s,\n", testName );

		// lhs
		{
			float32 lhsValue = fixture->lhsValues[testIndex];
			float32 lhsValues[] = {
				lhsValue, lhsValue, lhsValue, lhsValue,
				lhsValue, lhsValue, lhsValue, lhsValue,
				lhsValue, lhsValue, lhsValue, lhsValue,
				lhsValue, lhsValue, lhsValue, lhsValue
			};

			stringBuilder_t* ctor = Gen_GetConstructor( tempStorage, fixture->lhsType, lhsValues, strings, flags );

			StringBuilder_Append( code, ctor->str );
			StringBuilder_Append( code, ",\n" );
		}

		// rhs
		{
			float32 rhsValue = fixture->rhsValues[testIndex];
			float32 rhsValues[] = {
				rhsValue, rhsValue, rhsValue, rhsValue,
				rhsValue, rhsValue, rhsValue, rhsValue,
				rhsValue, rhsValue, rhsValue, rhsValue,
				rhsValue, rhsValue, rhsValue, rhsValue
			};

			stringBuilder_t* ctor = Gen_GetConstructor( tempStorage, fixture->rhsType, rhsValues, strings, flags );

			StringBuilder_Append( code, ctor->str );
			StringBuilder_Append( code, ",\n" );
		}

		// return type
		{
			float32 outputVal = fixture->outputValues[testIndex];
			float32 outputValues[] = {
				outputVal, outputVal, outputVal, outputVal,
				outputVal, outputVal, outputVal, outputVal,
				outputVal, outputVal, outputVal, outputVal,
				outputVal, outputVal, outputVal, outputVal
			};

			stringBuilder_t* ctor = Gen_GetConstructor( tempStorage, fixture->returnType, outputValues, strings, flags );
			StringBuilder_Appendf( code, "%s\n", ctor->str );
		}

		StringBuilder_Append( code, ");\n\n" );
	}
}

static void Gen_GenerateParametricTestCode_OperatorSingleParm( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const char* opName, const char* opStr, const generatorStrings_t* strings, const generatorFlags_t flags, const operatorSingleParmType_t type, const testFixtureOperatorSingleParm_t* fixture ) {
	assert( tempStorage );
	assert( code );
	assert( opName );
	assert( opStr );
	assert( strings );
	assert( fixture );
	assert( fixture->inputValues );
	assert( fixture->outputValues );
	assert( fixture->numTests );

	bool32 generateOperators = flags & GENERATOR_FLAG_GENERATE_OPERATORS;

	bool32 isPrefix = type == OPERATOR_SINGLE_PARM_TYPE_PREFIX;

	const char* operatorTypeStr = ( isPrefix ) ? "prefix" : "postfix";

	const char* testNameSuffix = String_TPrintf( tempStorage, "%s_%s", opName, operatorTypeStr );

	const char* testName = Gen_GetTestName( tempStorage, typeInfo, testNameSuffix );

	StringBuilder_Appendf( code, "TEMPER_PARAMETRIC( %s, TEMPER_FLAG_SHOULD_RUN, const %s%s x, const %s%s expectedAnswer )\n", testName, typeInfo->fullTypeName, strings->parmPassByStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Append(  code, "\t// make local copy of x and use that because we cant do increment or decrement operations on a const reference\n" );
	StringBuilder_Append(  code, "\t// and MSVC throws warnings if we just make the parameter a non-const reference\n" );
	if ( generateOperators ) {
		StringBuilder_Appendf( code, "\t%s xlocal = (%s) x;\n", typeInfo->fullTypeName, typeInfo->fullTypeName );
		if ( isPrefix ) {
			StringBuilder_Appendf( code, "\t%s actualAnswer = %sxlocal;\n", typeInfo->fullTypeName, opStr );
		} else {
			StringBuilder_Appendf( code, "\t%s actualAnswer = xlocal%s;\n", typeInfo->fullTypeName, opStr );
		}
		StringBuilder_Append( code, "\tTEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );\n" );
	} else {
		const char* funcName = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, opName );
		const char* equalsFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_EQUALS );

		StringBuilder_Appendf( code, "\t%s* xlocal = (%s*) x;\n", typeInfo->fullTypeName, typeInfo->fullTypeName );
		StringBuilder_Appendf( code, "\t%s actualAnswer = %s( xlocal );\n", typeInfo->fullTypeName, funcName );
		StringBuilder_Appendf( code, "\tTEMPER_CHECK_TRUE( %s( %sactualAnswer, expectedAnswer ) );\n", equalsFuncStr, strings->parmReferenceStr );
	}
	StringBuilder_Append( code, "}\n\n" );

	for ( u32 i = 0; i < fixture->numTests; i++ ) {
		StringBuilder_Appendf( code, "TEMPER_INVOKE_PARAMETRIC_TEST( %s,\n", testName );

		// input
		{
			float32 inputVal = fixture->inputValues[i];
			float32 inputValues[] = {
				inputVal, inputVal, inputVal, inputVal,
				inputVal, inputVal, inputVal, inputVal,
				inputVal, inputVal, inputVal, inputVal,
				inputVal, inputVal, inputVal, inputVal
			};

			stringBuilder_t* ctor = Gen_GetConstructor( tempStorage, typeInfo, inputValues, strings, flags );
			StringBuilder_Appendf( code, "%s,\n", ctor->str );
		}

		// output
		{
			float32 outputVal = fixture->outputValues[i];
			float32 outputValues[] = {
				outputVal, outputVal, outputVal, outputVal,
				outputVal, outputVal, outputVal, outputVal,
				outputVal, outputVal, outputVal, outputVal,
				outputVal, outputVal, outputVal, outputVal
			};

			stringBuilder_t* ctor = Gen_GetConstructor( tempStorage, typeInfo, outputValues, strings, flags );
			StringBuilder_Appendf( code, "%s\n", ctor->str );
		}

		StringBuilder_Append( code, ");\n\n" );
	}
}

static void Gen_GenerateParametricTestInvokation_Generic( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const char* funcName, const generatorStrings_t* strings, const generatorFlags_t flags, const parametricTestInvokationGenericParm_t* parms, const u32 parmsCount ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( funcName );
	assert( strings );
	assert( parms );
	assert( parmsCount );

	const char* testName = Gen_GetTestName( tempStorage, typeInfo, funcName );

	StringBuilder_Appendf( code, "TEMPER_INVOKE_PARAMETRIC_TEST( %s,\n", testName );

	for ( u32 i = 0; i < parmsCount; i++ ) {
		const parametricTestInvokationGenericParm_t* parm = &parms[i];

		stringBuilder_t* ctor = Gen_GetConstructor( tempStorage, parm->typeInfo, parm->value, strings, flags );
		StringBuilder_Append( code, ctor->str );

		if ( i != parmsCount - 1 ) {
			StringBuilder_Append( code, "," );
		}

		StringBuilder_Append( code, "\n" );
	}

	StringBuilder_Append( code, ");\n\n" );
}

static void Gen_GenerateParametricTestInvokation_Generic_SSE( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const char* funcName, const generatorStrings_t* strings, const generatorFlags_t flags, const parametricTestInvokationGenericParm_t* parms, const u32 parmsCount ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( funcName );
	assert( strings );
	assert( parms );
	assert( parmsCount );

	const char* testName = Gen_GetTestName_SSE( tempStorage, typeInfo, funcName );

	StringBuilder_Appendf( code, "TEMPER_INVOKE_PARAMETRIC_TEST( %s,\n", testName );

	for ( u32 i = 0; i < parmsCount; i++ ) {
		const parametricTestInvokationGenericParm_t* parm = &parms[i];

		stringBuilder_t* ctor = Gen_GetConstructor( tempStorage, parm->typeInfo, parm->value, strings, flags );
		StringBuilder_Append( code, ctor->str );

		if ( i != parmsCount - 1 ) {
			StringBuilder_Append( code, "," );
		}

		StringBuilder_Append( code, "\n" );
	}

	StringBuilder_Append( code, ");\n\n" );
}


static void Gen_GenerateTests_All( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const typeInfo_t* scalarType, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( scalarType );
	assert( scalarType->fullTypeName );
	assert( strings );

	if ( Gen_TypeIsScalar( typeInfo ) || typeInfo->type != GEN_TYPE_BOOL ) {
		return;
	}

	testFixture_All_t fixtures[] = {
		{
			{
				true, true, true, true,
				true, true, true, true,
				true, true, true, true,
				true, true, true, true
			},
			true,
		},

		{
			{
				true,  false, false, false,
				false, false, false, false,
				false, false, false, false,
				false, false, false, false
			},
			false
		},

		{
			{
				false, true, true, true,
				true,  true, true, true,
				true,  true, true, true,
				true,  true, true, true
			},
			false
		},

		{
			{
				false, true,  false, true,
				true,  false, true,  false,
				false, true,  false, true,
				true,  false, true,  false
			},
			false
		},

		{
			{
				false, false, false, false,
				false, false, false, false,
				false, false, false, false,
				false, false, false, false
			},
			false
		}
	};

	const char* funcName = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_ALL );

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType = scalarType,
		.funcName = funcName,
		.parmsCount = 1,
		.parms = (parametricTestDefinitionParm_t[]) {
			{ typeInfo, "x" }
		}
	} );

	if ( Gen_TypeIsVector( typeInfo ) ) {
		for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
			testFixture_All_t* fixture = &fixtures[i];

			parametricTestInvokationGenericParm_t parms[] = {
				{ typeInfo,   (const float32*)  fixture->values         },
				{ scalarType, (const float32*) &fixture->expectedAnswer }
			};

			Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, funcName, strings, flags, parms, GEN_COUNTOF( parms ) );
		}
	} else {
		for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
			testFixture_All_t* fixture = &fixtures[i];

			parametricTestInvokationGenericParm_t parms[] = {
				{ typeInfo,   (const float32*)  fixture->values         },
				{ scalarType, (const float32*) &fixture->expectedAnswer }
			};

			Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, funcName, strings, flags, parms, GEN_COUNTOF( parms ) );
		}
	}
}

static void Gen_GenerateTests_Any( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const typeInfo_t* scalarType, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( scalarType );
	assert( scalarType->fullTypeName );
	assert( strings );

	if ( Gen_TypeIsScalar( typeInfo ) || typeInfo->type != GEN_TYPE_BOOL ) {
		return;
	}

	testFixture_Any_t fixtures[] = {
		{
			{
				true, true, true, true,
				true, true, true, true,
				true, true, true, true,
				true, true, true, true
			},
			true,
		},

		{
			{
				true,  false, false, false,
				false, false, false, false,
				false, false, false, false,
				false, false, false, false
			},
			true
		},

		{
			{
				false, true, true, true,
				true,  true, true, true,
				true,  true, true, true,
				true,  true, true, true
			},
			true
		},

		{
			{
				false, true,  false, true,
				true,  false, true,  false,
				false, true,  false, true,
				true,  false, true,  false
			},
			true
		},

		{
			{
				false, false, false, false,
				false, false, false, false,
				false, false, false, false,
				false, false, false, false
			},
			false
		}
	};

	const char* funcName = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_ANY );
	//const char* testName = Gen_GetTestName( tempStorage, typeInfo, funcName );

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType = scalarType,
		.funcName = funcName,
		.parmsCount = 1,
		.parms = (parametricTestDefinitionParm_t[]) {
			{ typeInfo, "x" }
		}
	} );

	if ( Gen_TypeIsVector( typeInfo ) ) {
		for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
			testFixture_Any_t* fixture = &fixtures[i];

			parametricTestInvokationGenericParm_t parms[] = {
				{ typeInfo,   (const float32*)  fixture->values         },
				{ scalarType, (const float32*) &fixture->expectedAnswer }
			};

			Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, funcName, strings, flags, parms, GEN_COUNTOF( parms ) );
		}
	} else {
		for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
			testFixture_Any_t* fixture = &fixtures[i];

			parametricTestInvokationGenericParm_t parms[] = {
				{ typeInfo,   (const float32*)  fixture->values         },
				{ scalarType, (const float32*) &fixture->expectedAnswer }
			};

			Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, funcName, strings, flags, parms, GEN_COUNTOF( parms ) );
		}
	}
}

static void GenerateOperatorTests( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const typeInfo_t* scalarType, const typeInfo_t* boolTypeVector, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( scalarType );
	assert( boolTypeVector );
	assert( strings );

	if ( Gen_TypeIsScalar( typeInfo ) ) {
		return;
	}

	if ( typeInfo->type == GEN_TYPE_BOOL ) {
		return;
	}

	float32 relationalLHS[4] = { 0.0f, 0.0f, 1.0f, 1.0f };
	float32 relationalRHS[4] = { 0.0f, 1.0f, 1.0f, 0.0f };

	float32 relationalExpectedAnswers[GEN_OP_RELATIONAL_COUNT][4] = {
		{ false, true,  false, false },	// less than
		{ true,  true,  true,  false },	// less than equal
		{ false, false, false, true  },	// greater than
		{ true,  false, true,  true  }	// greater than equal
	};

	// relational
	for ( u32 opIndex = 0; opIndex < GEN_OP_RELATIONAL_COUNT; opIndex++ ) {
		genOpRelational_t op = (genOpRelational_t) opIndex;

		const char* opFuncName = Gen_GetRelationalName( op );
		const char* opStr = Gen_GetOperatorRelational( op );

		Gen_GenerateParametricTestsCode_Operator( tempStorage, code, typeInfo, opFuncName, opStr, strings, flags, &(testFixtureOperator_t) {
			.numTests = 4,

			.lhsType = typeInfo,
			.rhsType = typeInfo,
			.returnType = boolTypeVector,

			.lhsValues = relationalLHS,
			.rhsValues = relationalRHS,

			.outputValues = relationalExpectedAnswers[opIndex]
		} );
	}

	float32 arithmeticLHS[4] = { 1.0f, 2.0f, 4.0f, 8.0f };
	float32 arithmeticRHS[4] = { 1.0f, 2.0f, 2.0f, 4.0f };

	float32 arithmeticExpectedAnswers[GEN_OP_ARITHMETIC_COUNT][4] = {
		{ 2.0f, 4.0f, 6.0f, 12.0f },	// add
		{ 0.0f, 0.0f, 2.0f, 4.0f  },	// sub
		{ 1.0f, 4.0f, 8.0f, 32.0f },	// mul
		{ 1.0f, 1.0f, 2.0f, 2.0f  }		// div
	};

	// arithmetic
	{
		for ( u32 opIndex = 0; opIndex < GEN_OP_ARITHMETIC_COUNT; opIndex++ ) {
			genOpArithmetic_t op = (genOpArithmetic_t) opIndex;

			const char* opFuncName = String_TPrintf( tempStorage, "c%ss", Gen_GetArithmeticName( op ) );
			const char* opStr = Gen_GetOperatorArithmetic( op );

			Gen_GenerateParametricTestsCode_Operator( tempStorage, code, typeInfo, opFuncName, opStr, strings, flags, &(testFixtureOperator_t) {
				.numTests = 4,

				.lhsType = typeInfo,
				.rhsType = scalarType,
				.returnType = typeInfo,

				.lhsValues = arithmeticLHS,
				.rhsValues = arithmeticRHS,

				.outputValues = arithmeticExpectedAnswers[opIndex]
			} );
		}

		for ( u32 opIndex = 0; opIndex < GEN_OP_ARITHMETIC_COUNT; opIndex++ ) {
			genOpArithmetic_t op = (genOpArithmetic_t) opIndex;

			const char* opFuncName = NULL;

			if ( Gen_TypeIsMatrix( typeInfo ) ) {
				opFuncName = String_TPrintf( tempStorage, "c%sm", Gen_GetArithmeticName( op ) );
			} else {
				opFuncName = String_TPrintf( tempStorage, "c%sv", Gen_GetArithmeticName( op ) );
			}

			const char* opStr = Gen_GetOperatorArithmetic( op );

			Gen_GenerateParametricTestsCode_Operator( tempStorage, code, typeInfo, opFuncName, opStr, strings, flags, &(testFixtureOperator_t) {
				.numTests = 4,

				.lhsType = typeInfo,
				.rhsType = typeInfo,
				.returnType = typeInfo,

				.lhsValues = arithmeticLHS,
				.rhsValues = arithmeticRHS,

				.outputValues = arithmeticExpectedAnswers[opIndex]
			} );
		}
	}

	// increment/decrement
	if ( flags & GENERATOR_FLAG_GENERATE_OPERATORS ) {
		StringBuilder_Appendf( code,
			"#if defined( __GNUC__ ) || defined( __clang__ )\n"
			"#pragma GCC diagnostic push\n"
			"#pragma GCC diagnostic ignored \"-Wcast-qual\"\n"
			"#endif\n\n"
		);

		float32 inputValues[] = { 1.0f, 2.0f, 3.0f, 4.0f };
		float32 outputValues[GEN_OP_INCREMENT_COUNT][4] = {
			{ 2.0f, 3.0f, 4.0f, 5.0f },	// increment
			{ 0.0f, 1.0f, 2.0f, 3.0f }	// decrement
		};

		for ( u32 opIndex = 0; opIndex < GEN_OP_INCREMENT_COUNT; opIndex++ ) {
			genOpIncrement_t op = (genOpIncrement_t) opIndex;

			const char* opName = Gen_GetIncrementName( op );
			const char* opStr = Gen_GetOperatorIncrement( op );

			Gen_GenerateParametricTestCode_OperatorSingleParm( tempStorage, code, typeInfo, opName, opStr, strings, flags, OPERATOR_SINGLE_PARM_TYPE_PREFIX, &(testFixtureOperatorSingleParm_t) {
				.numTests = 4,
				.inputValues = inputValues,
				.outputValues = outputValues[op]
			} );

			Gen_GenerateParametricTestCode_OperatorSingleParm( tempStorage, code, typeInfo, opName, opStr, strings, flags, OPERATOR_SINGLE_PARM_TYPE_POSTFIX, &(testFixtureOperatorSingleParm_t) {
				.numTests = 4,
				.inputValues = inputValues,
				.outputValues = outputValues[op]
			} );
		}

		StringBuilder_Appendf( code,
			"#if defined( __GNUC__ ) || defined( __clang__ )\n"
			"#pragma GCC diagnostic pop\n"
			"#endif\n" );
	}

	// negate
	{
		StringBuilder_Appendf( code,
			"#if defined( __GNUC__ ) || defined( __clang__ )\n"
			"#pragma GCC diagnostic push\n"
			"#pragma GCC diagnostic ignored \"-Wcast-qual\"\n"
			"#endif\n"
		);

		float32 inputValues[]           = {  0.0f,  1.0f,  2.0f,  3.0f,  10.0f };
		float32 negateExpectedAnswers[] = { -0.0f, -1.0f, -2.0f, -3.0f, -10.0f };

		Gen_GenerateParametricTestCode_OperatorSingleParm( tempStorage, code, typeInfo, "negate", "-", strings, flags, OPERATOR_SINGLE_PARM_TYPE_PREFIX, &(testFixtureOperatorSingleParm_t) {
			.numTests = 4,
			.inputValues = inputValues,
			.outputValues = negateExpectedAnswers
		} );

		StringBuilder_Append( code,
			"#if defined( __GNUC__ ) || defined( __clang__ )\n"
			"#pragma GCC diagnostic pop\n"
			"#endif\n\n"
		);
	}

	// bitwise
	if ( Gen_TypeIsInteger( typeInfo->type ) ) {
		// unary
		{
			StringBuilder_Append( code,
				"#if defined( __GNUC__ ) || defined( __clang__ )\n"
				"#pragma GCC diagnostic push\n"
				"#pragma GCC diagnostic ignored \"-Wcast-qual\"\n"
				"#endif\n"
			);

			const char* opFuncName = Gen_GetBitwiseName( GEN_OP_BITWISE_UNARY );
			const char* opStr = Gen_GetOperatorBitwise( GEN_OP_BITWISE_UNARY );

			Gen_GenerateParametricTestCode_OperatorSingleParm( tempStorage, code, typeInfo, opFuncName, opStr, strings, flags, OPERATOR_SINGLE_PARM_TYPE_PREFIX, &(testFixtureOperatorSingleParm_t) {
				.numTests = 1,
				.inputValues =  (float32[]) {  1 },
				.outputValues = (float32[]) { ~1 }
			} );

			StringBuilder_Appendf( code,
				"#if defined( __GNUC__ ) || defined( __clang__ )\n"
				"#pragma GCC diagnostic pop\n"
				"#endif\n\n"
			);
		}

		// all others
		{
			float32 bitwiseLHS[] = { 0.0f, 2.0f, 1.0f, 1.0f };
			float32 bitwiseRHS[] = { 0.0f, 1.0f, 0.0f, 1.0f };

			float32 bitwiseExpectedAnswers[5][4] = {
				{ 0.0f, 0.0f, 0.0f, 1.0f },	// and
				{ 0.0f, 3.0f, 1.0f, 1.0f },	// or
				{ 0.0f, 3.0f, 1.0f, 0.0f },	// xor
				{ 0.0f, 4.0f, 1.0f, 2.0f },	// shift left
				{ 0.0f, 1.0f, 1.0f, 0.0f }	// shift right
			};

			// exclude unary, which is different
			genOpBitwise_t ops[] = {
				GEN_OP_BITWISE_AND,
				GEN_OP_BITWISE_OR,
				GEN_OP_BITWISE_XOR,
				GEN_OP_BITWISE_SHIFT_LEFT,
				GEN_OP_BITWISE_SHIFT_RIGHT
			};

			for ( u32 opIndex = 0; opIndex < GEN_COUNTOF( ops ); opIndex++ ) {
				genOpBitwise_t op = ops[opIndex];

				if ( op == GEN_OP_BITWISE_UNARY ) {
					continue;
				}

				const char* opFuncName = String_TPrintf( tempStorage, "c%ss", Gen_GetBitwiseName( op ) );
				const char* opStr = Gen_GetOperatorBitwise( op );

				Gen_GenerateParametricTestsCode_Operator( tempStorage, code, typeInfo, opFuncName, opStr, strings, flags, &(testFixtureOperator_t) {
					.numTests = 4,

					.lhsType = typeInfo,
					.rhsType = scalarType,
					.returnType = typeInfo,

					.lhsValues = bitwiseLHS,
					.rhsValues = bitwiseRHS,

					.outputValues = bitwiseExpectedAnswers[opIndex]
				} );
			}

			for ( u32 opIndex = 0; opIndex < GEN_COUNTOF( ops ); opIndex++ ) {
				genOpBitwise_t op = ops[opIndex];

				if ( op == GEN_OP_BITWISE_UNARY ) {
					continue;
				}

				const char* opFuncName = NULL;

				if ( Gen_TypeIsMatrix( typeInfo ) ) {
					opFuncName = String_TPrintf( tempStorage, "c%sm", Gen_GetBitwiseName( op ) );
				} else {
					opFuncName = String_TPrintf( tempStorage, "c%sv", Gen_GetBitwiseName( op ) );
				}

				const char* opStr = Gen_GetOperatorBitwise( op );

				Gen_GenerateParametricTestsCode_Operator( tempStorage, code, typeInfo, opFuncName, opStr, strings, flags, &(testFixtureOperator_t) {
					.numTests = 4,

					.lhsType = typeInfo,
					.rhsType = typeInfo,
					.returnType = typeInfo,

					.lhsValues = bitwiseLHS,
					.rhsValues = bitwiseRHS,

					.outputValues = bitwiseExpectedAnswers[opIndex]
				} );
			}
		}
	}
}

static void GenerateComponentWiseTests( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const typeInfo_t* scalarType, const typeInfo_t* scalarTypeFloatingPoint, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( scalarType );
	assert( scalarType->fullTypeName );
	assert( scalarTypeFloatingPoint );
	assert( scalarTypeFloatingPoint->fullTypeName );
	assert( strings );

	typeInfo_t boolReturnTypeScalar = {
		.type			= GEN_TYPE_BOOL,
		.numRows		= 1,
		.numCols		= 1,
		.fullTypeName	= Gen_GetTypeString( boolReturnTypeScalar.type )
	};

	typeInfo_t boolType = {
		.type			= GEN_TYPE_BOOL,
		.numRows		= typeInfo->numRows,
		.numCols		= typeInfo->numCols
	};

	if ( Gen_TypeIsVector( typeInfo ) ) {
		boolType.fullTypeName = String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( boolType.type ), boolType.numCols );
	} else if ( Gen_TypeIsMatrix( typeInfo ) ) {
		boolType.fullTypeName = String_TPrintf( tempStorage, "%s%dx%d", Gen_GetTypeString( boolType.type ), boolType.numRows, boolType.numCols );
	} else {
		boolType.fullTypeName = Gen_GetMemberTypeString( boolType.type );
	}

	typeInfo_t floatingPointTypeVector = {
		.type			= Gen_GetSupportedFloatingPointType( typeInfo->type ),
		.numRows		= typeInfo->numRows,
		.numCols		= typeInfo->numCols
	};

	if ( Gen_TypeIsVector( typeInfo ) ) {
		floatingPointTypeVector.fullTypeName = String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( floatingPointTypeVector.type ), floatingPointTypeVector.numCols );
	} else if ( Gen_TypeIsMatrix( typeInfo ) ) {
		floatingPointTypeVector.fullTypeName = String_TPrintf( tempStorage, "%s%dx%d", Gen_GetTypeString( floatingPointTypeVector.type ), floatingPointTypeVector.numRows, floatingPointTypeVector.numCols );
	} else {
		floatingPointTypeVector.fullTypeName = Gen_GetMemberTypeString( floatingPointTypeVector.type );
	}

	GenerateOperatorTests( tempStorage, code, typeInfo, scalarType, &boolType, strings, flags );

	Gen_GenerateTests_All( tempStorage, code, typeInfo, scalarType, strings, flags );
	Gen_GenerateTests_Any( tempStorage, code, typeInfo, scalarType, strings, flags );

	if ( typeInfo->type != GEN_TYPE_BOOL ) {
		// min
		Gen_GenerateParametricTestsCode_ComponentWise( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_MIN, strings, flags, &(componentWiseTestsData_t) {
			.parmDefsCount = 2,
			.parmDefs = (parametricTestDefinitionParm_t[]) {
				{ typeInfo, "lhs" },
				{ typeInfo, "rhs" }
			},

			.numTests = 2,

			.inputs = (testValues_t[]) {
				{ (float32[]) { 0.0f, 1.0f } },
				{ (float32[]) { 1.0f, 2.0f } }
			},

			.outputType = typeInfo,
			.outputs = (testValues_t[]) {
				{ (float32[]) { 0.0f } },
				{ (float32[]) { 1.0f } }
			}
		} );

		// max
		Gen_GenerateParametricTestsCode_ComponentWise( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_MAX, strings, flags, &(componentWiseTestsData_t) {
			.parmDefsCount = 2,
			.parmDefs = (parametricTestDefinitionParm_t[]) {
				{ typeInfo, "lhs" },
				{ typeInfo, "rhs" }
			},

			.numTests = 2,

			.inputs = (testValues_t[]) {
				{ (float32[]) { 1.0f, 0.0f } },
				{ (float32[]) { 2.0f, 1.0f } }
			},

			.outputType = typeInfo,
			.outputs = (testValues_t[]) {
				{ (float32[]) { 1.0f } },
				{ (float32[]) { 2.0f } }
			}
		} );

		// saturate
		Gen_GenerateParametricTestsCode_ComponentWise( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_SATURATE, strings, flags, &(componentWiseTestsData_t) {
			.parmDefsCount = 1,
			.parmDefs = (parametricTestDefinitionParm_t[]) {
				{ typeInfo, "x" },
			},

			.numTests = 5,

			.inputs = (testValues_t[]) {
				{ (float32[]) { 0.0f  } },
				{ (float32[]) { 1.0f  } },
				{ (float32[]) { 2.0f  } },
				{ (float32[]) { 3.0f  } },
				{ (float32[]) { 10.0f } }
			},

			.outputType = typeInfo,
			.outputs = (testValues_t[]) {
				{ (float32[]) { 0.0f } },
				{ (float32[]) { 1.0f } },
				{ (float32[]) { 1.0f } },
				{ (float32[]) { 1.0f } },
				{ (float32[]) { 1.0f } }
			}
		} );
	}

	if ( typeInfo->type != GEN_TYPE_BOOL && typeInfo->type != GEN_TYPE_UINT ) {
		// sign
		typeInfo_t returnType = {
			.type			= GEN_TYPE_INT,
			.numRows		= typeInfo->numRows,
			.numCols		= typeInfo->numCols
		};

		// DM: this is ugly and stupid
		// if this ends up being done a lot then we're gonna need a generic function =(
		if ( Gen_TypeIsScalar( &returnType ) ) {
			returnType.fullTypeName = Gen_GetMemberTypeString( returnType.type );
		} else if ( Gen_TypeIsVector( &returnType ) ) {
			returnType.fullTypeName = String_TPrintf( tempStorage, "%s%d", Gen_GetTypeString( returnType.type ), typeInfo->numCols );
		} else {
			returnType.fullTypeName = String_TPrintf( tempStorage, "%s%dx%d", Gen_GetTypeString( returnType.type ), typeInfo->numRows, typeInfo->numCols );
		}

		Gen_GenerateParametricTestsCode_ComponentWise( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_SIGN, strings, flags, &(componentWiseTestsData_t) {
			.parmDefsCount = 1,
			.parmDefs = (parametricTestDefinitionParm_t[]) {
				{ typeInfo, "x" },
			},

			.numTests = 7,

			.inputs = (testValues_t[]) {
				{ (float32[]) {  0.0f } },
				{ (float32[]) {  1.0f } },
				{ (float32[]) {  2.0f } },
				{ (float32[]) {  3.0f } },
				{ (float32[]) { -1.0f } },
				{ (float32[]) { -2.0f } },
				{ (float32[]) { -3.0f } }
			},

			.outputType = &returnType,
			.outputs = (testValues_t[]) {
				{ (float32[]) {  0.0f } },
				{ (float32[]) {  1.0f } },
				{ (float32[]) {  1.0f } },
				{ (float32[]) {  1.0f } },
				{ (float32[]) { -1.0f } },
				{ (float32[]) { -1.0f } },
				{ (float32[]) { -1.0f } }
			}
		} );
	}

	if ( Gen_TypeIsFloatingPoint( typeInfo->type ) ) {
		if ( Gen_TypeIsScalar( typeInfo ) ) {
			// floateq
			Gen_GenerateParametricTestsCode_ComponentWise( tempStorage, code, typeInfo, Gen_GetFuncName_Floateq( typeInfo->type ), strings, flags, &(componentWiseTestsData_t) {
				.parmDefsCount = 2,
				.parmDefs = (parametricTestDefinitionParm_t[]) {
					{ typeInfo, "lhs" },
					{ typeInfo, "rhs" }
				},

				.numTests = 7,

				.inputs = (testValues_t[]) {
					{ (float32[]) { 0.0f, 0.0f      } },
					{ (float32[]) { 1.0f, 1.0f      } },
					{ (float32[]) { 1.0f, 2.0f      } },
					{ (float32[]) { 0.0f, 0.5f      } },
					{ (float32[]) { 0.0f, 0.25f     } },
					{ (float32[]) { 0.0f, 0.1f      } },
					{ (float32[]) { 0.0f, 0.000001f } }
				},

				.outputType = &boolReturnTypeScalar,
				.outputs = (testValues_t[]) {
					{ (float32[]) { true  } },
					{ (float32[]) { true  } },
					{ (float32[]) { false } },
					{ (float32[]) { false } },
					{ (float32[]) { false } },
					{ (float32[]) { false } },
					{ (float32[]) { true  } }
				}
			} );

			// degrees
			Gen_GenerateParametricTestsCode_ComponentWise( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_DEGREES, strings, flags, &(componentWiseTestsData_t) {
				.generateSSE = Gen_TypeIsScalar( typeInfo ) && Gen_TypeSupportsSIMD( typeInfo->type ),
				.parmDefsCount = 1,
				.parmDefs = (parametricTestDefinitionParm_t[]) {
					{ typeInfo, "x" }
				},

				.numTests = 1,

				.inputs = (testValues_t[]) {
					{ (float32[]) { 1.0f } }
				},

				.outputType = typeInfo,
				.outputs = (testValues_t[]) {
					{ (float32[]) { 57.295779513f } }
				}
			} );

			// radians
			Gen_GenerateParametricTestsCode_ComponentWise( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_RADIANS, strings, flags, &(componentWiseTestsData_t) {
				.generateSSE = Gen_TypeIsScalar( typeInfo ) && Gen_TypeSupportsSIMD( typeInfo->type ),
				.parmDefsCount = 1,
				.parmDefs = (parametricTestDefinitionParm_t[]) {
					{ typeInfo, "x" }
				},

				.numTests = 1,

				.inputs = (testValues_t[]) {
					{ (float32[]) { 57.295779513f } }
				},

				.outputType = typeInfo,
				.outputs = (testValues_t[]) {
					{ (float32[]) { 1.0f } }
				}
			} );
		}

		// lerp
		Gen_GenerateParametricTestsCode_ComponentWise( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_LERP, strings, flags, &(componentWiseTestsData_t) {
			.generateSSE = Gen_TypeIsScalar( typeInfo ) && Gen_TypeSupportsSIMD( typeInfo->type ),
			.parmDefsCount = 3,
			.parmDefs = (parametricTestDefinitionParm_t[]) {
				{ typeInfo,   "lhs" },
				{ typeInfo,   "rhs" },
				{ scalarType, "t"   }
			},

			.numTests = 2,

			.inputs = (testValues_t[]) {
				{ (float32[]) { 0.0f, 1.0f, 0.5f } },
				{ (float32[]) { 1.0f, 3.0f, 0.5f } }
			},

			.outputType = typeInfo,
			.outputs = (testValues_t[]) {
				{ (float32[]) { 0.5f } },
				{ (float32[]) { 2.0f } }
			}
		} );
	}

	if ( Gen_TypeIsVector( typeInfo ) && Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
		Gen_GenerateParametricTestsCode_ComponentWise( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_QUAT_LENGTH, strings, flags, &(componentWiseTestsData_t) {
			.parmDefsCount = 1,
			.parmDefs = (parametricTestDefinitionParm_t[]) {
				{ typeInfo, "quat" }
			},

			.numTests = 5,

			.inputs = (testValues_t[]) {
				{ (float32[]) { 0.0f } },
				{ (float32[]) { 1.0f } },
				{ (float32[]) { 2.0f } },
				{ (float32[]) { 3.0f } },
				{ (float32[]) { 4.0f } }
			},

			.outputType = scalarType,
			.outputs = (testValues_t[]) {
				{ (float32[]) { 0.0f } },
				{ (float32[]) { 2.0f } },
				{ (float32[]) { 4.0f } },
				{ (float32[]) { 6.0f } },
				{ (float32[]) { 8.0f } }
			}
		} );

		Gen_GenerateParametricTestsCode_ComponentWise( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_QUAT_LERP, strings, flags, &(componentWiseTestsData_t) {
			.parmDefsCount = 3,
			.parmDefs = (parametricTestDefinitionParm_t[]) {
				{ typeInfo,   "lhs" },
				{ typeInfo,   "rhs" },
				{ scalarType, "t"   }
			},

			.numTests = 3,

			.inputs = (testValues_t[]) {
				{ (float32[]) { 0.0f, 1.0f, 0.5f  } },
				{ (float32[]) { 0.0f, 1.0f, 0.25f } },
				{ (float32[]) { 0.0f, 1.0f, 0.75f } },
			},

			.outputType = typeInfo,
			.outputs = (testValues_t[]) {
				{ (float32[]) { 0.5f  } },
				{ (float32[]) { 0.25f } },
				{ (float32[]) { 0.75f } }
			}
		} );

		Gen_GenerateParametricTestsCode_ComponentWise( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_QUAT_SLERP, strings, flags, &(componentWiseTestsData_t) {
			.parmDefsCount = 3,
			.parmDefs = (parametricTestDefinitionParm_t[]) {
				{ typeInfo,   "lhs" },
				{ typeInfo,   "rhs" },
				{ scalarType, "t"   }
			},

			.numTests = 1,

			.inputs = (testValues_t[]) {
				{ (float32[]) { 0.0f, 1.0f, 0.5f } }
			},

			.outputType = typeInfo,
			.outputs = (testValues_t[]) {
				{ (float32[]) { 0.707106781f } }
			}
		} );
	}
}