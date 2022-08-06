#include <float.h>	// FLT_MAX

typedef struct testFixture_Assignment_t {
	float32 values[4];
	float32 expectedAnswer[4];
} testFixture_Assignment_t;

typedef struct testFixture_Length_t {
	float32	values[4];
	float32	expectedAnswerVec2;
	float32	expectedAnswerVec3;
	float32	expectedAnswerVec4;
} testFixture_Length_t;

typedef struct testFixture_Dot_t {
	float32	valuesLHS[4];
	float32	valuesRHS[4];
	float32	expectedAnswerVec2;
	float32	expectedAnswerVec3;
	float32	expectedAnswerVec4;
} testFixture_Dot_t;

typedef struct testFixture_Cross_t {
	float32	valuesLHS[4];
	float32	valuesRHS[4];
	float32	expectedAnswer[4];
} testFixture_Cross_t;

typedef struct testFixture_Angle_t {
	float32	valuesLHS[4];
	float32	valuesRHS[4];
	float32	expectedAnswer;
} testFixture_Angle_t;

typedef struct testFixture_Distance_t {
	float32	valuesLHS[4];
	float32	valuesRHS[4];
	float32	expectedAnswerVec2;
	float32	expectedAnswerVec3;
	float32	expectedAnswerVec4;
} testFixture_Distance_t;

typedef struct testFixture_Normalize_t {
	float32	valuesVec[4];
	float32	expectedAnswerVec2[4];
	float32	expectedAnswerVec3[4];
} testFixture_Normalize_t;

typedef struct testFixture_Pack_t {
	float32	unpacked[4];
	float32	packed;
} testFixture_Pack_t;

typedef struct testFixture_Swizzle_t {
	float32 values[4];
} testFixture_Swizzle_t;

typedef struct testFixture_QuatMul_t {
	float32	lhs[4];
	float32	rhs[4];
	float32	expectedAnswer[4];
} testFixture_QuatMul_t;

typedef struct testFixture_QuatNormalize_t {
	float32	values[4];
	float32	expectedAnswer[4];
} testFixture_QuatNormalize_t;

typedef struct testFixture_QuatConjugate_t {
	float32	values[4];
	float32	expectedAnswer[4];
} testFixture_QuatConjugate_t;

typedef struct testFixture_QuatInverse_t {
	float32	values[4];
	float32	expectedAnswer[4];
} testFixture_QuatInverse_t;

typedef struct testFixture_QuatRotate_t {
	float32	quat[4];
	float32	angleRadians;
	float32	axis[3];
	float32	expectedAnswer[3];
} testFixture_QuatRotate_t;

typedef struct testFixture_QuatToRotationMatrix_t {
	float32	quat[4];
	float32	expectedAnswer[16];
} testFixture_QuatToRotationMatrix_t;


static void Gen_GenerateTests_Length_Internal( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const char* funcName, const generatorStrings_t* strings, const generatorFlags_t flags, const testFixture_Length_t* fixtures, const u32 fixturesCount ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( funcName );
	assert( strings );
	assert( fixtures );
	assert( fixturesCount );

	if ( !Gen_TypeIsVector( typeInfo ) ) {
		return;
	}

	typeInfo_t floatingPointTypeScalar = {
		.type			= Gen_GetSupportedFloatingPointType( typeInfo->type ),
		.numRows		= 1,
		.numCols		= 1,
		.fullTypeName	= Gen_GetMemberTypeString( floatingPointTypeScalar.type )
	};

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.alsoGenerateSSE = Gen_TypeSupportsSIMD( typeInfo->type ),
		.returnType = &floatingPointTypeScalar,
		.funcName = funcName,
		.parmsCount = 1,
		.parms = (parametricTestDefinitionParm_t[]) {
			{ typeInfo, "vec" }
		}
	} );

	for ( u32 i = 0; i < fixturesCount; i++ ) {
		const testFixture_Length_t* fixture = &fixtures[i];

		parametricTestInvokationGenericParm_t parms[] = {
			{  typeInfo,                fixture->values },
			{ &floatingPointTypeScalar, NULL            }
		};

		switch ( typeInfo->numCols ) {
			case 2: parms[1].value = &fixture->expectedAnswerVec2; break;
			case 3: parms[1].value = &fixture->expectedAnswerVec3; break;
			case 4: parms[1].value = &fixture->expectedAnswerVec4; break;
		}

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, funcName, strings, flags, parms, GEN_COUNTOF( parms ) );
	}

	if ( Gen_TypeSupportsSIMD( typeInfo->type ) ) {
		for ( u32 i = 0; i < fixturesCount; i++ ) {
			const testFixture_Length_t* fixture = &fixtures[i];

			parametricTestInvokationGenericParm_t parms[] = {
				{  typeInfo,                fixture->values },
				{ &floatingPointTypeScalar, NULL            }
			};

			switch ( typeInfo->numCols ) {
				case 2: parms[1].value = &fixture->expectedAnswerVec2; break;
				case 3: parms[1].value = &fixture->expectedAnswerVec3; break;
				case 4: parms[1].value = &fixture->expectedAnswerVec4; break;
			}

			Gen_GenerateParametricTestInvokation_Generic_SSE( tempStorage, code, typeInfo, funcName, strings, flags, parms, GEN_COUNTOF( parms ) );
		}
	}
}

static void Gen_GenerateTests_Lengthsq( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	testFixture_Length_t fixtures[] = {
		{
			.values				= { 0.0f, 0.0f, 0.0f, 0.0f },
			.expectedAnswerVec2	= 0.0f,
			.expectedAnswerVec3	= 0.0f,
			.expectedAnswerVec4	= 0.0f
		},

		{
			.values				= { 1.0f, 1.0f, 1.0f, 1.0f },
			.expectedAnswerVec2	= 2.0f,
			.expectedAnswerVec3	= 3.0f,
			.expectedAnswerVec4	= 4.0f
		},

		{
			.values				= { 2.0f, 2.0f, 2.0f, 2.0f },
			.expectedAnswerVec2	= 8.0f,
			.expectedAnswerVec3	= 12.0f,
			.expectedAnswerVec4	= 16.0f
		}
	};

	Gen_GenerateTests_Length_Internal( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_LENGTHSQ, strings, flags, fixtures, GEN_COUNTOF( fixtures ) );
}

static void Gen_GenerateTests_Length( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	testFixture_Length_t fixtures[] = {
		{
			.values				= { 0.0f, 0.0f, 0.0f, 0.0f },
			.expectedAnswerVec2	= 0.0f,
			.expectedAnswerVec3	= 0.0f,
			.expectedAnswerVec4	= 0.0f
		},

		{
			.values				= { 1.0f, 1.0f, 1.0f, 1.0f },
			.expectedAnswerVec2	= 1.41421356237f,
			.expectedAnswerVec3	= 1.73205080757f,
			.expectedAnswerVec4	= 2.0f
		},

		{
			.values				= { 2.0f, 2.0f, 2.0f, 2.0f },
			.expectedAnswerVec2	= 2.82842712475f,
			.expectedAnswerVec3	= 3.46410161514f,
			.expectedAnswerVec4	= 4.0f
		}
	};

	Gen_GenerateTests_Length_Internal( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_LENGTH, strings, flags, fixtures, GEN_COUNTOF( fixtures ) );
}

static void Gen_GenerateTests_Dot( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	if ( !Gen_TypeIsVector( typeInfo ) ) {
		return;
	}

	typeInfo_t floatingPointTypeScalar = Gen_GetScalarType( typeInfo );

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.alsoGenerateSSE = Gen_TypeSupportsSIMD( typeInfo->type ),
		.returnType = &floatingPointTypeScalar,
		.funcName = GEN_FUNCTION_NAME_DOT,
		.parmsCount = 2,
		.parms = (parametricTestDefinitionParm_t[]) {
			{ typeInfo, "lhs" },
			{ typeInfo, "rhs" }
		}
	} );

	testFixture_Dot_t fixtures[] = {
		{
			.valuesLHS			= { 0.0f, 0.0f, 0.0f, 0.0f },
			.valuesRHS			= { 1.0f, 1.0f, 1.0f, 1.0f },
			.expectedAnswerVec2	= 0.0f,
			.expectedAnswerVec3	= 0.0f,
			.expectedAnswerVec4	= 0.0f
		},

		{
			.valuesLHS			= { 1.0f, 1.0f, 1.0f, 1.0f },
			.valuesRHS			= { 1.0f, 1.0f, 1.0f, 1.0f },
			.expectedAnswerVec2	= 2.0f,
			.expectedAnswerVec3	= 3.0f,
			.expectedAnswerVec4	= 4.0f
		},

		{
			.valuesLHS			= {  1.0f,  1.0f,  1.0f,  1.0f },
			.valuesRHS			= { -1.0f, -1.0f, -1.0f, -1.0f },
			.expectedAnswerVec2	= -2.0f,
			.expectedAnswerVec3	= -3.0f,
			.expectedAnswerVec4	= -4.0f
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_Dot_t* fixture = &fixtures[i];
		
		parametricTestInvokationGenericParm_t parms[] = {
			{  typeInfo,                fixture->valuesLHS },
			{  typeInfo,                fixture->valuesRHS },
			{ &floatingPointTypeScalar, NULL               }
		};

		switch ( typeInfo->numCols ) {
			case 2: parms[2].value = &fixture->expectedAnswerVec2; break;
			case 3: parms[2].value = &fixture->expectedAnswerVec3; break;
			case 4: parms[2].value = &fixture->expectedAnswerVec4; break;
		}

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_DOT, strings, flags, parms, GEN_COUNTOF( parms ) );
	}

	if ( Gen_TypeSupportsSIMD( typeInfo->type ) ) {
		for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
			const testFixture_Dot_t* fixture = &fixtures[i];

			parametricTestInvokationGenericParm_t parms[] = {
				{  typeInfo,                fixture->valuesLHS },
				{  typeInfo,                fixture->valuesRHS },
				{ &floatingPointTypeScalar, NULL               }
			};

			switch ( typeInfo->numCols ) {
				case 2: parms[2].value = &fixture->expectedAnswerVec2; break;
				case 3: parms[2].value = &fixture->expectedAnswerVec3; break;
				case 4: parms[2].value = &fixture->expectedAnswerVec4; break;
			}

			Gen_GenerateParametricTestInvokation_Generic_SSE( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_DOT, strings, flags, parms, GEN_COUNTOF( parms ) );
		}
	}
}

// DM: this test could be made into a component-wise test
// but I think a dedicated test is more appropriate
static void Gen_GenerateTests_Cross( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	if ( !Gen_TypeIsVector( typeInfo ) || !Gen_TypeIsFloatingPoint( typeInfo->type ) || typeInfo->numCols != 3 ) {
		return;
	}

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.alsoGenerateSSE = Gen_TypeSupportsSIMD( typeInfo->type ),
		.returnType = typeInfo,
		.funcName = GEN_FUNCTION_NAME_CROSS,
		.parmsCount = 2,
		.parms = (parametricTestDefinitionParm_t[]) {
			{ typeInfo, "lhs" },
			{ typeInfo, "rhs" }
		}
	} );

	testFixture_Cross_t fixtures[] = {
		{
			.valuesLHS		= { 1.0f, 0.0f, 0.0f, 0.0f },
			.valuesRHS		= { 0.0f, 1.0f, 0.0f, 0.0f },
			.expectedAnswer	= { 0.0f, 0.0f, 1.0f, 0.0f }
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		testFixture_Cross_t* fixture = &fixtures[i];

		parametricTestInvokationGenericParm_t parms[] = {
			{ typeInfo, fixture->valuesLHS      },
			{ typeInfo, fixture->valuesRHS      },
			{ typeInfo, fixture->expectedAnswer }
		};

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_CROSS, strings, flags, parms, GEN_COUNTOF( parms ) );

		if ( Gen_TypeSupportsSIMD( typeInfo->type ) ) {
			Gen_GenerateParametricTestInvokation_Generic_SSE( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_CROSS, strings, flags, parms, GEN_COUNTOF( parms ) );
		}
	}
}

static void Gen_GenerateTests_Angle( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	if ( !Gen_TypeIsVector( typeInfo ) || !Gen_TypeIsFloatingPoint( typeInfo->type ) || typeInfo->numCols > 3 ) {
		return;
	}

	typeInfo_t floatingPointTypeScalar = {
		.type			= Gen_GetSupportedFloatingPointType( typeInfo->type ),
		.numRows		= 1,
		.numCols		= 1,
		.fullTypeName	= Gen_GetMemberTypeString( floatingPointTypeScalar.type )
	};

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType = &floatingPointTypeScalar,
			.funcName = GEN_FUNCTION_NAME_ANGLE,
			.parmsCount = 2,
			.parms = (parametricTestDefinitionParm_t[]) {
			{ typeInfo, "lhs" },
			{ typeInfo, "rhs" }
		},
	} );

	testFixture_Angle_t fixtures[] = {
		{
			.valuesLHS		= { 1.0f, 0.0f, 0.0f, 0.0f },
			.valuesRHS		= { 0.0f, 1.0f, 0.0f, 0.0f },
			.expectedAnswer	= 90.0f
		},

		{
			.valuesLHS		= { 1.0f, 1.0f, 0.0f, 0.0f },
			.valuesRHS		= { 0.0f, 1.0f, 0.0f, 0.0f },
			.expectedAnswer	= 45.0f
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_Angle_t* fixture = &fixtures[i];

		parametricTestInvokationGenericParm_t parms[] = {
			{  typeInfo,                 fixture->valuesLHS      },
			{  typeInfo,                 fixture->valuesRHS      },
			{ &floatingPointTypeScalar, &fixture->expectedAnswer }
		};

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_ANGLE, strings, flags, parms, GEN_COUNTOF( parms ) );
	}
}

static void Gen_GenerateTests_Distance_Internal( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const char* funcName, const generatorStrings_t* strings, const generatorFlags_t flags, const testFixture_Distance_t* fixtures, const u32 fixturesCount ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( funcName );
	assert( strings );
	assert( fixtures );
	assert( fixturesCount );

	if ( typeInfo->type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( typeInfo->numCols > 3 ) {
		return;
	}

	typeInfo_t floatingPointTypeScalar = {
		.type			= Gen_GetSupportedFloatingPointType( typeInfo->type ),
		.numRows		= 1,
		.numCols		= 1,
		.fullTypeName	= Gen_GetMemberTypeString( floatingPointTypeScalar.type )
	};

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.alsoGenerateSSE = Gen_TypeSupportsSIMD( typeInfo->type ),
		.returnType = &floatingPointTypeScalar,
		.funcName = funcName,
		.parmsCount = 2,
		.parms = (parametricTestDefinitionParm_t[]) {
			{ typeInfo, "lhs" },
			{ typeInfo, "rhs" }
		}
	} );

	for ( u32 i = 0; i < fixturesCount; i++ ) {
		const testFixture_Distance_t* fixture = &fixtures[i];

		parametricTestInvokationGenericParm_t parms[] = {
			{  typeInfo,                fixture->valuesLHS },
			{  typeInfo,                fixture->valuesRHS },
			{ &floatingPointTypeScalar, NULL               }
		};

		switch ( typeInfo->numCols ) {
			case 2: parms[2].value = &fixture->expectedAnswerVec2; break;
			case 3: parms[2].value = &fixture->expectedAnswerVec3; break;
			case 4: parms[2].value = &fixture->expectedAnswerVec4; break;
		}

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, funcName, strings, flags, parms, GEN_COUNTOF( parms ) );
	}

	if ( Gen_TypeSupportsSIMD( typeInfo->type ) ) {
		for ( u32 i = 0; i < fixturesCount; i++ ) {
			const testFixture_Distance_t* fixture = &fixtures[i];

			parametricTestInvokationGenericParm_t parms[] = {
				{  typeInfo,                fixture->valuesLHS },
				{  typeInfo,                fixture->valuesRHS },
				{ &floatingPointTypeScalar, NULL               }
			};

			switch ( typeInfo->numCols ) {
				case 2: parms[2].value = &fixture->expectedAnswerVec2; break;
				case 3: parms[2].value = &fixture->expectedAnswerVec3; break;
				case 4: parms[2].value = &fixture->expectedAnswerVec4; break;
			}

			Gen_GenerateParametricTestInvokation_Generic_SSE( tempStorage, code, typeInfo, funcName, strings, flags, parms, GEN_COUNTOF( parms ) );
		}
	}
}

static void Gen_GenerateTests_Distancesq( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	testFixture_Distance_t fixtures[] = {
		{
			.valuesLHS			= { 0.0f, 0.0f, 0.0f, 0.0f },
			.valuesRHS			= { 0.0f, 0.0f, 0.0f, 0.0f },
			.expectedAnswerVec2	= 0.0f,
			.expectedAnswerVec3	= 0.0f,
			.expectedAnswerVec4	= 0.0f
		},

		{
			.valuesLHS			= { 0.0f, 0.0f, 0.0f, 0.0f },
			.valuesRHS			= { 1.0f, 1.0f, 1.0f, 1.0f },
			.expectedAnswerVec2	= 2.0f,
			.expectedAnswerVec3	= 3.0f,
			.expectedAnswerVec4	= 4.0f
		},

		{
			.valuesLHS			= { 0.0f, 0.0f, 0.0f, 0.0f },
			.valuesRHS			= { 2.0f, 2.0f, 2.0f, 2.0f },
			.expectedAnswerVec2	= 8.0f,
			.expectedAnswerVec3	= 12.0000026664f,
			.expectedAnswerVec4	= 8.0f
		}
	};

	Gen_GenerateTests_Distance_Internal( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_DISTANCESQ, strings, flags, fixtures, GEN_COUNTOF( fixtures ) );
}

static void Gen_GenerateTests_Distance( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	testFixture_Distance_t fixtures[] = {
		{
			.valuesLHS			= { 0.0f, 0.0f, 0.0f, 0.0f },
			.valuesRHS			= { 0.0f, 0.0f, 0.0f, 0.0f },
			.expectedAnswerVec2	= 0.0f,
			.expectedAnswerVec3	= 0.0f,
			.expectedAnswerVec4	= 0.0f
		},

		{
			.valuesLHS			= { 0.0f, 0.0f, 0.0f, 0.0f },
			.valuesRHS			= { 1.0f, 1.0f, 1.0f, 1.0f },
			.expectedAnswerVec2	= 1.41421356237f,
			.expectedAnswerVec3	= 1.73205080757f,
			.expectedAnswerVec4	= 2.0f
		},

		{
			.valuesLHS			= { 0.0f, 0.0f, 0.0f, 0.0f },
			.valuesRHS			= { 2.0f, 2.0f, 2.0f, 2.0f },
			.expectedAnswerVec2	= 2.82842712475f,
			.expectedAnswerVec3	= 3.46410161514f,
			.expectedAnswerVec4	= 4.0f
		}
	};

	Gen_GenerateTests_Distance_Internal( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_DISTANCE, strings, flags, fixtures, GEN_COUNTOF( fixtures ) );
}

static void Gen_GenerateTests_Normalize( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	if ( !Gen_TypeIsVector( typeInfo ) || !Gen_TypeIsFloatingPoint( typeInfo->type ) || typeInfo->numCols > 3 ) {
		return;
	}

	const char* actualFuncName = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_NORMALIZE );
	const char* testName = Gen_GetTestName( tempStorage, typeInfo, GEN_FUNCTION_NAME_NORMALIZE );

	const char* equalsFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_EQUALS );

	const char* floateqStr = Gen_GetFuncName_Floateq( typeInfo->type );
	const char* lengthFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_LENGTH );

	const genType_t floatingPointType = Gen_GetSupportedFloatingPointType( typeInfo->type );

	const char* oneStr = Gen_GetNumericLiteral( tempStorage, floatingPointType, 1.0f, 1 );

	StringBuilder_Appendf( code, "TEMPER_PARAMETRIC( %s, TEMPER_FLAG_SHOULD_RUN, const %s%s vec, const %s%s expectedAnswer )\n", testName, typeInfo->fullTypeName, strings->parmPassByStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Appendf( code, "{\n" );
	StringBuilder_Appendf( code, "\t%s vecNormalized = %svec;\n", typeInfo->fullTypeName, strings->parmDereferenceStr );
	StringBuilder_Appendf( code, "\t%s( %svecNormalized );\n", actualFuncName, strings->parmReferenceStr );
	if ( flags & GENERATOR_FLAG_GENERATE_OPERATORS ) {
		StringBuilder_Append(  code, "\tTEMPER_CHECK_TRUE( vecNormalized == expectedAnswer );\n" );
	} else {
		StringBuilder_Appendf( code, "\tTEMPER_CHECK_TRUE( %s( %svecNormalized, expectedAnswer ) );\n", equalsFuncStr, strings->parmReferenceStr );
	}
	StringBuilder_Appendf( code, "\tTEMPER_CHECK_TRUE( %s( %s( %svecNormalized ), %s ) );\n", floateqStr, lengthFuncStr, strings->parmReferenceStr, oneStr );
	StringBuilder_Appendf( code, "}\n\n" );

	if ( Gen_TypeSupportsSIMD( typeInfo->type ) ) {
		Gen_GenerateParametricTestDefinition_Generic_SSE( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
			.returnType = typeInfo,
			.funcName = GEN_FUNCTION_NAME_NORMALIZE,
			.parmsCount = 1,
			.parms = (parametricTestDefinitionParm_t[]) {
				{ typeInfo, "vec" }
			}
		} );
	}

	testFixture_Normalize_t fixtures[] = {
		{
			.valuesVec			= { 1.0f,        2.0f,         3.0f,       },
			.expectedAnswerVec2	= { 0.44721f,    0.89443f,    -1.0f        },
			.expectedAnswerVec3	= { 0.26726124f, 0.53452248f,  0.80178373f }
		},

		{
			.valuesVec			= { 5.0f,        4.0f,         3.0f,       },
			.expectedAnswerVec2	= { 0.78087f,    0.6247f,     -1.0f        },
			.expectedAnswerVec3	= { 0.70710678f, 0.56568542f,  0.42426407f }
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_Normalize_t* fixture = &fixtures[i];

		parametricTestInvokationGenericParm_t parms[] = {
			{ typeInfo, fixture->valuesVec },
			{ typeInfo, NULL               }
		};

		switch ( typeInfo->numCols ) {
			case 2: parms[1].value = fixture->expectedAnswerVec2; break;
			case 3: parms[1].value = fixture->expectedAnswerVec3; break;
			case 4: parms[1].value = fixture->expectedAnswerVec3; break;
		}

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_NORMALIZE, strings, flags, parms, GEN_COUNTOF( parms ) );
	}

	if ( Gen_TypeSupportsSIMD( typeInfo->type ) ) {
		for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
			const testFixture_Normalize_t* fixture = &fixtures[i];

			parametricTestInvokationGenericParm_t parms[] = {
				{ typeInfo, fixture->valuesVec },
				{ typeInfo, NULL               }
			};

			switch ( typeInfo->numCols ) {
				case 2: parms[1].value = fixture->expectedAnswerVec2; break;
				case 3: parms[1].value = fixture->expectedAnswerVec3; break;
				case 4: parms[1].value = fixture->expectedAnswerVec3; break;
			}

			Gen_GenerateParametricTestInvokation_Generic_SSE( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_NORMALIZE, strings, flags, parms, GEN_COUNTOF( parms ) );
		}
	}
}

static void Gen_GenerateTests_Pack( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	if ( !Gen_TypeIsVector( typeInfo ) || typeInfo->type != GEN_TYPE_UINT || typeInfo->numCols != 4 ) {
		return;
	}

	typeInfo_t scalarType = {
		.type			= typeInfo->type,
		.numRows		= 1,
		.numCols		= 1,
		.fullTypeName	= Gen_GetMemberTypeString( scalarType.type )
	};

	testFixture_Pack_t fixtures[] = {
		{
			{ 0.0f, 0.0f, 0.0f, 0.0f },
			(float32) 0x00000000
		},

		{
			{ 0.0f, 0.0f, 0.0f, 255.0f },
			(float32) 0x000000FF
		},

		{
			{ 0.0f, 255.0f, 0.0f, 255.0f },
			(float32) 0x00FF00FF
		},

		{
			{ 255.0f, 0.0f, 255.0f, 0.0f },
			(float32) 0xFF00FF00
		},

		// TODO(DM): re-add these
		// {
		// 	{ 255.0f, 0.0f, 255.0f, 255.0f },
		// 	0xFF00FFFF
		// },

		// {
		// 	{ 255.0f, 255.0f, 255.0f, 255.0f },
		// 	0xFFFFFFFF
		// }
	};

	// pack
	{
		Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
			.returnType = &scalarType,
			.funcName = GEN_FUNCTION_NAME_PACK,
			.parmsCount = 1,
			.parms = (parametricTestDefinitionParm_t[]) {
				{ typeInfo, "unpacked" }
			},
		} );

		for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
			const testFixture_Pack_t* fixture = &fixtures[i];

			parametricTestInvokationGenericParm_t parms[] = {
				{  typeInfo,                     fixture->unpacked },
				{ &scalarType, (const float32*) &fixture->packed   }
			};

			Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_PACK, strings, flags, parms, GEN_COUNTOF( parms ) );
		}
	}

	// unpack
	{
		Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
			.returnType = typeInfo,
			.funcName = GEN_FUNCTION_NAME_UNPACK,
			.parmsCount = 1,
			.parms = (parametricTestDefinitionParm_t[]) {
				{ &scalarType, "packed" }
			},
		} );

		for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
			const testFixture_Pack_t* fixture = &fixtures[i];

			parametricTestInvokationGenericParm_t parms[] = {
				{ &scalarType, (const float32*) &fixture->packed   },
				{  typeInfo,                     fixture->unpacked }
			};

			Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_UNPACK, strings, flags, parms, GEN_COUNTOF( parms ) );
		}
	}
}

static void GenerateSwizzleFunc_Test( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags, const u32 numSwizzleComponents, const char* swizzleStr ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( Gen_TypeIsVector( typeInfo ) );
	assert( strings );
	assert( numSwizzleComponents );
	assert( swizzleStr );

	const char* typeString = Gen_GetTypeString( typeInfo->type );

	typeInfo_t swizzleTypeInfo = {
		.type			= typeInfo->type,
		.numRows		= typeInfo->numRows,
		.numCols		= numSwizzleComponents,
		.fullTypeName	= String_TPrintf( tempStorage, "%s%d", typeString, numSwizzleComponents )
	};

	const char* funcName = String_TPrintf( tempStorage, "Swizzle_%s", swizzleStr );

	StringBuilder_Appendf( code, "TEMPER_PARAMETRIC( Test_%s_%s, TEMPER_FLAG_SHOULD_RUN, const %s%s vec, const %s%s expectedAnswer )\n", typeInfo->fullTypeName, funcName, typeInfo->fullTypeName, strings->parmPassByStr, swizzleTypeInfo.fullTypeName, strings->parmPassByStr );
	StringBuilder_Appendf( code, "{\n" );
	StringBuilder_Appendf( code, "\t%s vecSwizzled = vec.%s;\n", swizzleTypeInfo.fullTypeName, swizzleStr );
	StringBuilder_Append(  code, "\tTEMPER_CHECK_TRUE( vecSwizzled == expectedAnswer );\n" );
	StringBuilder_Appendf( code, "}\n\n" );

	testFixture_Swizzle_t fixtures[] = {
		{ 0.0f,  0.0f,   0.0f,   0.0f   },
		{ 0.0f,  1.0f,   2.0f,   3.0f   },
		{ 3.0f,  2.0f,   1.0f,   0.0f   },
		{ 10.0f, 10.0f,  20.0f,  20.0f  },
		{ 20.0f, 20.0f,  10.0f,  10.0f  },
		{ 69.0f, 420.0f, 666.0f, 616.0f }
	};

	for ( u32 fixtureIndex = 0; fixtureIndex < GEN_COUNTOF( fixtures ); fixtureIndex++ ) {
		const testFixture_Swizzle_t* fixture = &fixtures[fixtureIndex];

		float32 expectedAnswer[4] = { 0 };

		for ( u32 i = 0; i < numSwizzleComponents; i++ ) {
			u32 swizzleComponentIndex = Gen_GetComponentIndex( swizzleStr[i] );

			expectedAnswer[i] = fixture->values[swizzleComponentIndex];
		}

		parametricTestInvokationGenericParm_t parms[] = {
			{ typeInfo,         fixture->values },
			{ &swizzleTypeInfo, expectedAnswer  }
		};

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, funcName, strings, flags, parms, GEN_COUNTOF( parms ) );
	}
}

static void Gen_GenerateTests_QuatMulScalar( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const typeInfo_t* scalarType, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( scalarType );
	assert( scalarType->fullTypeName );
	assert( strings );

	if ( !Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
		return;
	}

	bool32 allowNameMangling = flags & GENERATOR_FLAG_NAME_MANGLING;

	const char* suffix = allowNameMangling ? "" : "s";

	const char* funcToCall = GEN_FUNCTION_NAME_QUAT_MUL;
	if ( !allowNameMangling ) {
		funcToCall = String_TPrintf( tempStorage, "%s_%s%s", typeInfo->fullTypeName, GEN_FUNCTION_NAME_QUAT_MUL, suffix );
	}

	const char* testName = String_TPrintf( tempStorage, "Test_%s_%ss", typeInfo->fullTypeName, GEN_FUNCTION_NAME_QUAT_MUL, suffix );

	StringBuilder_Appendf( code, "TEMPER_PARAMETRIC( %s, TEMPER_FLAG_SHOULD_RUN, const %s%s quat, const %s scalar, const %s%s expectedAnswer )\n", testName, typeInfo->fullTypeName, strings->parmPassByStr, scalarType->fullTypeName, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\t%s actualAnswer = %s( quat, scalar );\n", typeInfo->fullTypeName, funcToCall );
	if ( flags & GENERATOR_FLAG_GENERATE_OPERATORS ) {
		StringBuilder_Append(  code, "\tTEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );\n" );
	} else {
		const char* equalsFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_EQUALS );

		StringBuilder_Appendf( code, "\tTEMPER_CHECK_TRUE( %s( %sactualAnswer, expectedAnswer ) );\n", equalsFuncStr, strings->parmReferenceStr );
	}
	StringBuilder_Append(  code, "}\n\n" );

	testFixture_QuatMul_t fixtures[] = {
		{
			.lhs			= { 0.0f, 0.0f, 0.0f, 0.0f },
			.rhs			= { 0.0f },
			.expectedAnswer = { 0.0f, 0.0f, 0.0f, 0.0f }
		},

		{
			.lhs			= { 0.0f, 0.0f, 0.0f, 0.0f },
			.rhs			= { 1.0f },
			.expectedAnswer = { 0.0f, 0.0f, 0.0f, 0.0f }
		},

		{
			.lhs			= { 1.0f, 1.0f, 1.0f, 1.0f },
			.rhs			= { 0.0f },
			.expectedAnswer = { 0.0f, 0.0f, 0.0f, 0.0f }
		},

		{
			.lhs			= { 1.0f, 1.0f, 1.0f, 1.0f },
			.rhs			= { 1.0f },
			.expectedAnswer = { 1.0f, 1.0f, 1.0f, 1.0f }
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_QuatMul_t* fixture = &fixtures[i];

		stringBuilder_t* ctorLHS = Gen_GetConstructor( tempStorage, typeInfo, fixture->lhs, strings, flags );
		stringBuilder_t* ctorRHS = Gen_GetConstructor( tempStorage, scalarType, fixture->rhs, strings, flags );
		stringBuilder_t* ctorExpectedAnswer = Gen_GetConstructor( tempStorage, typeInfo, fixture->expectedAnswer, strings, flags );

		StringBuilder_Appendf( code, "TEMPER_INVOKE_PARAMETRIC_TEST( %s,\n", testName );
		StringBuilder_Appendf( code, "\t%s,\n", ctorLHS->str );
		StringBuilder_Appendf( code, "\t%s,\n", ctorRHS->str );
		StringBuilder_Appendf( code, "\t%s\n",  ctorExpectedAnswer->str );
		StringBuilder_Append(  code, ");\n" );
	}
}

static void Gen_GenerateTests_QuatMulQuat( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	if ( !Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
		return;
	}

	bool32 allowNameMangling = flags & GENERATOR_FLAG_NAME_MANGLING;

	const char* suffix = allowNameMangling ? "" : "q";

	const char* funcToCall = GEN_FUNCTION_NAME_QUAT_MUL;
	if ( !allowNameMangling ) {
		funcToCall = String_TPrintf( tempStorage, "%s_%s%s", typeInfo->fullTypeName, funcToCall, suffix );
	}

	const char* testName = String_TPrintf( tempStorage, "Test_%s_%sq", typeInfo->fullTypeName, GEN_FUNCTION_NAME_QUAT_MUL, suffix );

	StringBuilder_Appendf( code, "TEMPER_PARAMETRIC( %s, TEMPER_FLAG_SHOULD_RUN, const %s%s lhs, const %s%s rhs, const %s%s expectedAnswer )\n", testName, typeInfo->fullTypeName, strings->parmPassByStr, typeInfo->fullTypeName, strings->parmPassByStr, typeInfo->fullTypeName, strings->parmPassByStr );
	StringBuilder_Append(  code, "{\n" );
	StringBuilder_Appendf( code, "\t%s actualAnswer = %s( lhs, rhs );\n", typeInfo->fullTypeName, funcToCall );
	if ( flags & GENERATOR_FLAG_GENERATE_OPERATORS ) {
		StringBuilder_Append(  code, "\tTEMPER_CHECK_TRUE( actualAnswer == expectedAnswer );\n" );
	} else {
		const char* equalsFuncStr = Gen_GetFuncName_Vector( tempStorage, typeInfo, flags, GEN_FUNCTION_NAME_EQUALS );

		StringBuilder_Appendf( code, "\tTEMPER_CHECK_TRUE( %s( %sactualAnswer, expectedAnswer ) );\n", equalsFuncStr, strings->parmReferenceStr );
	}
	StringBuilder_Append(  code, "}\n\n" );

	testFixture_QuatMul_t fixtures[] = {
		{
			.lhs			= { 0.0f, 0.0f, 0.0f, 0.0f },
			.rhs			= { 0.0f, 0.0f, 0.0f, 0.0f },
			.expectedAnswer = { 0.0f, 0.0f, 0.0f, 0.0f }
		},

		{
			.lhs			= { 0.0f, 0.0f, 0.0f, 0.0f },
			.rhs			= { 1.0f, 1.0f, 1.0f, 1.0f },
			.expectedAnswer = { 0.0f, 0.0f, 0.0f, 0.0f }
		},

		{
			.lhs			= { 1.0f, 1.0f, 1.0f, 1.0f },
			.rhs			= { 0.0f, 0.0f, 0.0f, 0.0f },
			.expectedAnswer = { 0.0f, 0.0f, 0.0f, 0.0f }
		},

		{
			.lhs			= { 1.0f, 1.0f, 1.0f,  1.0f },
			.rhs			= { 1.0f, 1.0f, 1.0f,  1.0f },
			.expectedAnswer = { 2.0f, 2.0f, 2.0f, -2.0f }
		},

		{
			.lhs			= { 2.0f,  3.0f,  4.0f,  5.0f },
			.rhs			= { 1.0f,  3.0f,  5.0f,  7.0f },
			.expectedAnswer = { 22.0f, 30.0f, 56.0f, 4.0f }
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_QuatMul_t* fixture = &fixtures[i];

		stringBuilder_t* ctorLHS = Gen_GetConstructor( tempStorage, typeInfo, fixture->lhs, strings, flags );
		stringBuilder_t* ctorRHS = Gen_GetConstructor( tempStorage, typeInfo, fixture->rhs, strings, flags );
		stringBuilder_t* ctorExpectedAnswer = Gen_GetConstructor( tempStorage, typeInfo, fixture->expectedAnswer, strings, flags );

		StringBuilder_Appendf( code, "TEMPER_INVOKE_PARAMETRIC_TEST( %s,\n", testName );
		StringBuilder_Appendf( code, "\t%s,\n", ctorLHS->str );
		StringBuilder_Appendf( code, "\t%s,\n", ctorRHS->str );
		StringBuilder_Appendf( code, "\t%s\n",  ctorExpectedAnswer->str );
		StringBuilder_Append(  code, ");\n" );
	}
}

static void Gen_GenerateTests_QuatNormalize( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	if ( !Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
		return;
	}

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType = typeInfo,
			.funcName = GEN_FUNCTION_NAME_QUAT_NORMALIZE,
			.parmsCount = 1,
			.parms = (parametricTestDefinitionParm_t[]) {
			{ typeInfo, "quat" }
		},
	} );

	testFixture_QuatNormalize_t fixtures[] = {
		{
			.values			= { 2.0f,      3.0f,      4.0f,      5.0f      },
			.expectedAnswer	= { 0.272166f, 0.408248f, 0.544331f, 0.680414f }
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_QuatNormalize_t* fixture = &fixtures[i];

		parametricTestInvokationGenericParm_t parms[] = {
			{ typeInfo, fixture->values         },
			{ typeInfo, fixture->expectedAnswer }
		};

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_QUAT_NORMALIZE, strings, flags, parms, GEN_COUNTOF( parms ) );
	}
}

static void Gen_GenerateTests_QuatConjugate( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );

	if ( !Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
		return;
	}

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType = typeInfo,
			.funcName = GEN_FUNCTION_NAME_QUAT_CONJUGATE,
			.parmsCount = 1,
			.parms = (parametricTestDefinitionParm_t[]) {
			{ typeInfo, "quat" }
		},
	} );

	// DM: I REALLY wish we could component-wise this test!
	testFixture_QuatConjugate_t fixtures[] = {
		{
			.values			= {  1.0f,  1.0f,  1.0f, 1.0f },
			.expectedAnswer	= { -1.0f, -1.0f, -1.0f, 1.0f }
		},

		{
			.values			= {  2.0f,  2.0f,  2.0f, 2.0f },
			.expectedAnswer	= { -2.0f, -2.0f, -2.0f, 2.0f }
		},

		{
			.values			= {  3.0f,  3.0f,  3.0f, 3.0f },
			.expectedAnswer	= { -3.0f, -3.0f, -3.0f, 3.0f }
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_QuatConjugate_t* fixture = &fixtures[i];

		parametricTestInvokationGenericParm_t parms[] = {
			{ typeInfo, fixture->values         },
			{ typeInfo, fixture->expectedAnswer }
		};

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_QUAT_CONJUGATE, strings, flags, parms, GEN_COUNTOF( parms ) );
	}
}

static void Gen_GenerateTests_QuatInverse( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	if ( !Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
		return;
	}

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType = typeInfo,
		.funcName = GEN_FUNCTION_NAME_QUAT_INVERSE,
		.parmsCount = 1,
		.parms = (parametricTestDefinitionParm_t[]) {
			{ typeInfo, "quat" }
		},
	} );

	// DM: I REALLY wish we could component-wise this test!
	testFixture_QuatInverse_t fixtures[] = {
		{
			.values			= {  1.0f,   1.0f,   1.0f,  1.0f  },
			.expectedAnswer	= { -0.25f, -0.25f, -0.25f, 0.25f }
		},

		{
			.values			= {  2.0f,    2.0f,    2.0f,   2.0f   },
			.expectedAnswer	= { -0.125f, -0.125f, -0.125f, 0.125f }
		},

		{
			.values			= {  3.0f,        3.0f,        3.0f,       3.0f       },
			.expectedAnswer	= { -0.0833333f, -0.0833333f, -0.0833333f, 0.0833333f }
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_QuatInverse_t* fixture = &fixtures[i];

		parametricTestInvokationGenericParm_t parms[] = {
			{ typeInfo, fixture->values         },
			{ typeInfo, fixture->expectedAnswer }
		};

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_QUAT_INVERSE, strings, flags, parms, GEN_COUNTOF( parms ) );
	}
}

static void Gen_GenerateTests_QuatRotate( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	if ( !Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
		return;
	}

	typeInfo_t scalarType = {
		.type			= typeInfo->type,
		.numRows		= 1,
		.numCols		= 1,
		.fullTypeName	= Gen_GetMemberTypeString( scalarType.type )
	};

	typeInfo_t imaginaryType = Gen_GetQuaternionImaginaryPartType( typeInfo, tempStorage );

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType = &imaginaryType,
		.funcName = GEN_FUNCTION_NAME_QUAT_ROTATE,
		.parmsCount = 3,
		.parms = (parametricTestDefinitionParm_t[]) {
			{  typeInfo,      "quat"  },
			{ &scalarType,    "angleRadians" },
			{ &imaginaryType, "axis"  }
		},
	} );

	testFixture_QuatRotate_t fixtures[] = {
		{
			.quat			= { 0.0f, 1.0f, 0.0f, 0.0f },
			.angleRadians	= 1.5708f,
			.axis			= { 1.0f, 0.0f, 0.0f },
			.expectedAnswer	= { 0.0f, 0.0f, 1.0f }
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_QuatRotate_t* fixture = &fixtures[i];

		parametricTestInvokationGenericParm_t parms[] = {
			{  typeInfo,       fixture->quat           },
			{ &scalarType,    &fixture->angleRadians   },
			{ &imaginaryType,  fixture->axis           },
			{ &imaginaryType,  fixture->expectedAnswer }
		};

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_QUAT_ROTATE, strings, flags, parms, GEN_COUNTOF( parms ) );
	}
}

static void Gen_GenerateTests_QuatToRotationMatrix( allocatorLinear_t* tempStorage, stringBuilder_t* code, const typeInfo_t* typeInfo, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( code );
	assert( typeInfo );
	assert( typeInfo->fullTypeName );
	assert( strings );

	if ( !Gen_VectorQualifiesAsQuaternion( typeInfo ) ) {
		return;
	}

	typeInfo_t matrixReturnType = {
		.type			= typeInfo->type,
		.numRows		= typeInfo->numCols,
		.numCols		= typeInfo->numCols,
		.fullTypeName	= String_TPrintf( tempStorage, "%s%dx%d", Gen_GetTypeString( matrixReturnType.type ), matrixReturnType.numRows, matrixReturnType.numCols )
	};

	Gen_GenerateParametricTestDefinition_Generic( tempStorage, code, typeInfo, strings, flags, &(parametricTestDefinition_t) {
		.returnType = &matrixReturnType,
		.funcName = GEN_FUNCTION_NAME_QUAT_TO_ROTATION_MATRIX,
		.parmsCount = 1,
		.parms = (parametricTestDefinitionParm_t[]) {
			{ typeInfo, "quat" }
		},
	} );

	testFixture_QuatToRotationMatrix_t fixtures[] = {
		{
			.quat			= { 0.0f, 0.0f, 0.0f, 1.0f },
			.expectedAnswer	= {
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
			}
		},

		{
			.quat			= { 0.3826834f, 0.0f, 0.0f, 0.9238795f },
			.expectedAnswer	= {
				1.0f, 0.0f,        0.0f,       0.0f,
				0.0f, 0.7071068f, -0.7071068f, 0.0f,
				0.0f, 0.7071068f,  0.7071068f, 0.0f,
				0.0f, 0.0f,        0.0f,       1.0f
			}
		},

		{
			.quat			= { 0.0f, 0.3826834f, 0.0f, 0.9238795f },
			.expectedAnswer	= {
				0.7071068f,  0.0f,  0.7071068f, 0.0f,
				0.0f,        1.0f,  0.0f,       0.0f,
				-0.7071068f,  0.0f,  0.7071068f, 0.0f,
				0.0f,        0.0f,  0.0f,       1.0f
			}
		},

		{
			.quat			= { 0.0f, 0.0f, 0.3826834f, 0.9238795f },
			.expectedAnswer	= {
				0.7071068f, -0.7071068f, 0.0f, 0.0f,
				0.7071068f,  0.7071068f, 0.0f, 0.0f,
				0.0f,        0.0f,       1.0f, 0.0f,
				0.0f,        0.0f,       0.0f, 1.0f
			}
		}
	};

	for ( u32 i = 0; i < GEN_COUNTOF( fixtures ); i++ ) {
		const testFixture_QuatToRotationMatrix_t* fixture = &fixtures[i];

		parametricTestInvokationGenericParm_t parms[] = {
			{  typeInfo,         fixture->quat           },
			{ &matrixReturnType, fixture->expectedAnswer }
		};

		Gen_GenerateParametricTestInvokation_Generic( tempStorage, code, typeInfo, GEN_FUNCTION_NAME_QUAT_TO_ROTATION_MATRIX, strings, flags, parms, GEN_COUNTOF( parms ) );
	}
}

static void GenerateVectorTests( allocatorLinear_t* tempStorage, const char* generatedTestsPath, const char* languageName, const typeInfo_t* vectorTypeInfos, const u32 vectorTypeInfosCount, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( languageName );
	assert( generatedTestsPath );
	assert( vectorTypeInfos );
	assert( vectorTypeInfosCount );
	assert( strings );

	for ( u32 i = 0; i < vectorTypeInfosCount; i++ ) {
		const typeInfo_t* typeInfo = &vectorTypeInfos[i];

		typeInfo_t scalarType = Gen_GetScalarType( typeInfo );

		typeInfo_t scalarTypeFloatingPoint = {
			.type			= Gen_GetSupportedFloatingPointType( typeInfo->type ),
			.numRows		= 1,
			.numCols		= 1,
			.fullTypeName	= Gen_GetTypeString( scalarTypeFloatingPoint.type )
		};

		assert( typeInfo->fullTypeName );
		assert( scalarType.fullTypeName );
		assert( scalarTypeFloatingPoint.fullTypeName );

		printf( "Generating test_%s.%s...", typeInfo->fullTypeName, languageName );

		stringBuilder_t* code = StringBuilder_Create( tempStorage, KILOBYTES( 512 ) );

		StringBuilder_Append( code, GEN_FILE_HEADER );

		GenerateComponentWiseTests( tempStorage, code, typeInfo, &scalarType, &scalarTypeFloatingPoint, strings, flags );

		GenerateTests_CtorConversion( tempStorage, code, typeInfo, strings, flags );

		Gen_GenerateTests_Lengthsq( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Length( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Dot( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Cross( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Angle( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Distancesq( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Distance( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Normalize( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_Pack( tempStorage, code, typeInfo, strings, flags );

		const char* fileNameHeader = String_TPrintf( tempStorage, "%s/test_%s.%s", generatedTestsPath, typeInfo->fullTypeName, languageName );
		FS_WriteEntireFile( fileNameHeader, code->str, code->length );

		printf( "OK.\n" );

		Mem_Reset( tempStorage );
	}

	// generate swizzle tests separately because theres so many
	if ( flags & GENERATOR_FLAG_VECTOR_SWIZZLES ) {
		for ( u32 i = 0; i < vectorTypeInfosCount; i++ ) {
			const typeInfo_t* typeInfo = &vectorTypeInfos[i];

			printf( "Generating test_%s_swizzle_%s.%s...", typeInfo->fullTypeName, GEN_COMPONENT_NAMES_VECTOR, languageName );

			stringBuilder_t* code = StringBuilder_Create( tempStorage, MEGABYTES( 8 ) );

			StringBuilder_Append( code, GEN_FILE_HEADER );

			GenerateSwizzleFunctions( tempStorage, code, typeInfo, strings, flags, GEN_COMPONENT_NAMES_VECTOR, GenerateSwizzleFunc_Test );

			const char* fileNameHeader = String_TPrintf( tempStorage, "%s/test_%s_swizzle_%s.%s", generatedTestsPath, typeInfo->fullTypeName, GEN_COMPONENT_NAMES_VECTOR, languageName );
			FS_WriteEntireFile( fileNameHeader, code->str, code->length );

			printf( "OK.\n" );

			Mem_Reset( tempStorage );
		}

		for ( u32 i = 0; i < vectorTypeInfosCount; i++ ) {
			const typeInfo_t* typeInfo = &vectorTypeInfos[i];

			printf( "Generating test_%s_swizzle_%s.%s...", typeInfo->fullTypeName, GEN_COMPONENT_NAMES_COLOR, languageName );

			stringBuilder_t* code = StringBuilder_Create( tempStorage, MEGABYTES( 8 ) );

			StringBuilder_Append( code, GEN_FILE_HEADER );

			GenerateSwizzleFunctions( tempStorage, code, typeInfo, strings, flags, GEN_COMPONENT_NAMES_COLOR, GenerateSwizzleFunc_Test );

			const char* fileNameHeader = String_TPrintf( tempStorage, "%s/test_%s_swizzle_%s.%s", generatedTestsPath, typeInfo->fullTypeName, GEN_COMPONENT_NAMES_COLOR, languageName );
			FS_WriteEntireFile( fileNameHeader, code->str, code->length );

			printf( "OK.\n" );

			Mem_Reset( tempStorage );
		}
	}
}

static void GenerateQuaternionTests( allocatorLinear_t* tempStorage, const char* generatedTestsPath, const char* languageName, const typeInfo_t* quaternionTypeInfos, const u32 quaternionTypeInfosCount, const generatorStrings_t* strings, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( generatedTestsPath );
	assert( languageName );
	assert( quaternionTypeInfos );
	assert( quaternionTypeInfosCount );
	assert( strings );

	for ( u32 typeInfoIndex = 0; typeInfoIndex < quaternionTypeInfosCount; typeInfoIndex++ ) {
		const typeInfo_t* typeInfo = &quaternionTypeInfos[typeInfoIndex];

		typeInfo_t scalarType = Gen_GetScalarType( typeInfo );

		assert( typeInfo->fullTypeName );
		assert( scalarType.fullTypeName );

		printf( "Generating test_quat_%s.%s...", typeInfo->fullTypeName, languageName );

		stringBuilder_t* code = StringBuilder_Create( tempStorage, KILOBYTES( 64 ) );

		StringBuilder_Append( code, GEN_FILE_HEADER );

		Gen_GenerateTests_QuatMulScalar( tempStorage, code, typeInfo, &scalarType, strings, flags );
		Gen_GenerateTests_QuatMulQuat( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_QuatNormalize( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_QuatConjugate( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_QuatInverse( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_QuatRotate( tempStorage, code, typeInfo, strings, flags );
		Gen_GenerateTests_QuatToRotationMatrix( tempStorage, code, typeInfo, strings, flags );

		const char* fileNameHeader = String_TPrintf( tempStorage, "%s/test_quat_%s.%s", generatedTestsPath, typeInfo->fullTypeName, languageName );
		FS_WriteEntireFile( fileNameHeader, code->str, code->length );

		printf( "OK.\n" );

		Mem_Reset( tempStorage );
	}
}