#include "GeneratorVectorTests.h"

#include "FileIO.h"

#include "gen_funcs_vector.h"

#include <vector>

bool GeneratorVectorTests::Generate( const genType_t type, const u32 numComponents ) {
	m_codeTests = std::string();
	m_codeSuite = std::string();

	m_type = type;

	m_numComponents = numComponents;

	m_numComponentsStr = std::to_string( numComponents );

	m_typeString = Gen_GetTypeString( type );
	m_memberTypeString = Gen_GetMemberTypeString( type );

	m_fullTypeName = m_typeString + std::to_string( numComponents );

	std::string code;

	code += GEN_FILE_HEADER;

	code += std::string( "#include \"../../" ) + GEN_OUT_GEN_FOLDER_PATH + GEN_FILENAME_FUNCTIONS_VECTOR + ".h\"\n";
	code += "\n";

	code += "#include <temper/temper.h>\n";
	code += "\n";

	m_codeSuite += "TEMPER_SUITE( Test_" + m_fullTypeName + " )\n";
	m_codeSuite += "{\n";

	GenerateTestAssignment();

	GenerateTestArray();

	GenerateTestArithmetic();

	GenerateTestIncrement();

	GenerateTestRelational();

	GenerateTestBitwise();

	GenerateTestLength();

	GenerateTestNormalized();

	GenerateTestDot();

	GenerateTestCross();

	GenerateTestAngle();

	GenerateTestDistance();

	GenerateTestSaturate();

	GenerateTestLerp();

	GenerateTestSmoothstep();

	GenerateTestPacking();

	m_codeSuite += "}\n";

	code += m_codeTests;
	code += m_codeSuite;

	char filename[1024] = { 0 };
	snprintf( filename, 1024, "%stest_%s.cpp", GEN_TESTS_FOLDER_PATH, m_fullTypeName.c_str() );

	if ( !FS_WriteEntireFile( filename, code.c_str(), code.size() ) ) {
		printf( "Can't generate test suite for %s.  That's rough man.\n", m_fullTypeName.c_str() );
		return false;
	}

	return true;
}

void GeneratorVectorTests::GenerateTestAssignment() {
	std::string oneStr = Gen_GetNumericLiteral( m_type, 1 );

	std::string paramListOne = "( " + oneStr + " )";

	float values[] = { 0.0f, 1.0f, 2.0f, 3.0f };
	std::string parmListVarying = Gen_GetParmListVector( m_type, m_numComponents, values );

	m_codeTests += "// also tests equality operators\n";
	m_codeTests += "TEMPER_TEST( TestAssignment_" + m_fullTypeName + " )\n";
	m_codeTests += "{\n";
	m_codeTests += "\t" + m_fullTypeName + " a;\n";
	m_codeTests += "\n";
	m_codeTests += "\ta = " + m_fullTypeName + paramListOne + ";\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( a == " + m_fullTypeName + paramListOne + " );\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( a != " + m_fullTypeName + parmListVarying + " );\n";
	m_codeTests += "\n";
	m_codeTests += "\ta = " + m_fullTypeName + parmListVarying + ";\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( a == " + m_fullTypeName + parmListVarying + " );\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( a != " + m_fullTypeName + paramListOne + " );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";

	m_codeSuite += "\tTEMPER_RUN_TEST( TestAssignment_" + m_fullTypeName + " );\n";
}

void GeneratorVectorTests::GenerateTestArray() {
	std::string testName = "TestArray_" + m_fullTypeName;

	float values[] = { 0.0f, 1.0f, 2.0f, 3.0f };
	std::string parmList = Gen_GetParmListVector( m_type, m_numComponents, values );

	m_codeTests += "TEMPER_TEST( " + testName + " )\n";
	m_codeTests += "{\n";
	m_codeTests += "\t" + m_fullTypeName + " a = " + m_fullTypeName + parmList + ";\n";
	m_codeTests += "\n";
	for ( u32 i = 0; i < m_numComponents; i++ ) {
		m_codeTests += "\tTEMPER_EXPECT_TRUE( a[" + std::to_string( i ) + "] == " + Gen_GetNumericLiteral( m_type, static_cast<float>( i ) ) + " );\n";
	}
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";

	m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
}

void GeneratorVectorTests::GenerateTestArithmetic() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	// number picked at random
	const int32_t baseNumber = 6;
	std::string parmListBase = "( " + Gen_GetNumericLiteral( m_type, baseNumber ) + " )";

	float valuesAdd[]	= { 2.0f,  3.0f,  4.0f,  5.0f  };
	float valuesSub[]	= { 2.0f,  3.0f,  4.0f,  5.0f  };
	float valuesMul[]	= { 2.0f,  3.0f,  4.0f,  5.0f  };
	float valuesDiv[]	= { 2.0f,  2.0f,  3.0f,  6.0f  };

	float answersAdd[]	= { 8.0f,  9.0f,  10.0f, 11.0f };
	float answersSub[]	= { 4.0f,  3.0f,  2.0f,  1.0f  };
	float answersMul[]	= { 12.0f, 18.0f, 24.0f, 30.0f };
	float answersDiv[]	= { 3.0f,  3.0f,  2.0f,  1.0f  };

	std::string parmListValues[GEN_OP_ARITHMETIC_COUNT] = {
		Gen_GetParmListVector( m_type, m_numComponents, valuesAdd ),
		Gen_GetParmListVector( m_type, m_numComponents, valuesSub ),
		Gen_GetParmListVector( m_type, m_numComponents, valuesMul ),
		Gen_GetParmListVector( m_type, m_numComponents, valuesDiv ),
	};

	std::string parmListAnswers[GEN_OP_ARITHMETIC_COUNT] = {
		Gen_GetParmListVector( m_type, m_numComponents, answersAdd ),
		Gen_GetParmListVector( m_type, m_numComponents, answersSub ),
		Gen_GetParmListVector( m_type, m_numComponents, answersMul ),
		Gen_GetParmListVector( m_type, m_numComponents, answersDiv ),
	};

	std::string suffices[GEN_OP_ARITHMETIC_COUNT] = {
		"Addition",
		"Subtraction",
		"Multiplication",
		"Division",
	};

	for ( u32 i = 0; i < GEN_OP_ARITHMETIC_COUNT; i++ ) {
		std::string testName = "TestArithmetic" + suffices[i] + "_" + m_fullTypeName;

		m_codeTests += "TEMPER_TEST( " + testName + " )\n";
		m_codeTests += "{\n";
		m_codeTests += "\t" + m_fullTypeName + " a  = " + m_fullTypeName + parmListBase + ";\n";
		m_codeTests += "\t" + m_fullTypeName + " b  = " + m_fullTypeName + parmListValues[i] + ";\n";
		m_codeTests += "\n";
		m_codeTests += "\t" + m_fullTypeName + " c = a " + GEN_OPERATORS_ARITHMETIC[i] + " b;\n";
		m_codeTests += "\n";
		m_codeTests += "\tTEMPER_EXPECT_TRUE( c == " + m_fullTypeName + parmListAnswers[i] + " );\n";
		m_codeTests += "\n";
		m_codeTests += "\tTEMPER_PASS();\n";
		m_codeTests += "}\n";
		m_codeTests += "\n";

		m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
	}
}

void GeneratorVectorTests::GenerateTestIncrement() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	float values0[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	float values1[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	std::string parmListVecs[] = {
		Gen_GetParmListVector( m_type, m_numComponents, values0 ),
		Gen_GetParmListVector( m_type, m_numComponents, values1 ),
	};

	std::string parmListAnswers[] = {
		Gen_GetParmListVector( m_type, m_numComponents, values1 ),
		Gen_GetParmListVector( m_type, m_numComponents, values0 ),
	};

	std::string suffices[GEN_OP_INCREMENT_COUNT] = {
		"Increment",
		"Decrement",
	};

	for ( u32 i = 0; i < GEN_OP_INCREMENT_COUNT; i++ ) {
		std::string testName = "Test" + suffices[i] + "_" + m_fullTypeName;

		m_codeTests += "TEMPER_TEST( " + testName + " )\n";
		m_codeTests += "{\n";
		m_codeTests += "\t" + m_fullTypeName + " vec;\n";
		m_codeTests += "\n";
		m_codeTests += "\t// prefix\n";
		m_codeTests += "\tvec = " + m_fullTypeName + parmListVecs[i] + ";\n";
		m_codeTests += "\t" + GEN_OPERATORS_INCREMENT[i] + "vec;\n";
		m_codeTests += "\tTEMPER_EXPECT_TRUE( vec == " + m_fullTypeName + parmListAnswers[i] + " );\n";
		m_codeTests += "\n";
		m_codeTests += "\t// postfix\n";
		m_codeTests += "\tvec = " + m_fullTypeName + parmListVecs[i] + ";\n";
		m_codeTests += "\tvec" + GEN_OPERATORS_INCREMENT[i] + ";\n";
		m_codeTests += "\tTEMPER_EXPECT_TRUE( vec == " + m_fullTypeName + parmListAnswers[i] + " );\n";
		m_codeTests += "\n";
		m_codeTests += "\tTEMPER_PASS();\n";
		m_codeTests += "}\n";
		m_codeTests += "\n";

		m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
	}
}

// TODO(DM): make this one the same as matrix equivalent
void GeneratorVectorTests::GenerateTestRelational() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	std::string testName = "TestRelational_" + m_fullTypeName;

	m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";

	std::vector<std::string> paramLists( m_numComponents );

	std::string boolTypeName = "bool" + m_numComponentsStr;

	u32 numTestVectors = 0;

	for ( u32 componentIndex = 0; componentIndex < m_numComponents; componentIndex++ ) {
		std::string& paramList = paramLists[componentIndex];

		paramList = "( ";
		for ( u32 paramIndex = 0; paramIndex < m_numComponents; paramIndex++ ) {
			paramList += Gen_GetNumericLiteral( m_type, static_cast<float>( componentIndex ) );

			if ( paramIndex != m_numComponents - 1 ) {
				paramList += ", ";
			}
		}
		paramList += " )";
	}

	m_codeTests += "TEMPER_TEST( " + testName + " )\n";
	m_codeTests += "{\n";
	for ( u32 i = 0; i < m_numComponents; i++ ) {
		m_codeTests += "\t" + m_fullTypeName + " vec" + std::to_string( i ) + " = " + m_fullTypeName + paramLists[i] + ";\n";
	}
	m_codeTests += "\n";
	for ( u32 i = 0; i < m_numComponents; i++ ) {
		std::string indexStr = std::to_string( i );

		std::string vecString = "vec" + indexStr;

		m_codeTests += "\t" + boolTypeName + " test" + std::to_string( numTestVectors++ ) + " = " + vecString + " <= " + vecString + ";\n";
		m_codeTests += "\t" + boolTypeName + " test" + std::to_string( numTestVectors++ ) + " = " + vecString + " >= " + vecString + ";\n";
		if ( i < m_numComponents - 1 ) {
			m_codeTests += "\t" + boolTypeName + " test" + std::to_string( numTestVectors++ ) + " = " + vecString + " < vec" + std::to_string( i + 1 ) + ";\n";
		}
		if ( i > 0 ) {
			m_codeTests += "\t" + boolTypeName + " test" + std::to_string( numTestVectors++ ) + " = " + vecString + " > vec" + std::to_string( i - 1 ) + ";\n";
		}
		m_codeTests += "\n";
	}
	for ( u32 i = 0; i < numTestVectors; i++ ) {
		m_codeTests += "\tTEMPER_EXPECT_TRUE( test" + std::to_string( i ) + " == " + boolTypeName + "( true ) );\n";
	}
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";
}

void GeneratorVectorTests::GenerateTestBitwise() {
	if ( !Gen_IsIntegerType( m_type ) ) {
		return;
	}

	// values must be integers
	float values0[]				= { 0.0f,  0.0f,  0.0f,  0.0f  };	// 0b000000
	float values1[]				= { 1.0f,  1.0f,  1.0f,  1.0f  };	// 0b000001
	float values2[]				= { 2.0f,  2.0f,  2.0f,  2.0f  };	// 0b000010
	float values4[]				= { 4.0f,  4.0f,  4.0f,  4.0f  };	// 0b000100
	float values7[]				= { 7.0f,  7.0f,  7.0f,  7.0f  };	// 0b000111
	float values21[]			= { 21.0f, 21.0f, 21.0f, 21.0f };	// 0b010101
	float values16[]			= { 16.0f, 16.0f, 16.0f, 16.0f };	// 0b010000

	float answersAnd[]			= { 5.0f,  5.0f,  5.0f,  5.0f  };	// 21 & 7
	float answersOr[]			= { 23.0f, 23.0f, 23.0f, 23.0f };	// 21 | 7
	float answersXor[]			= { 18.0f, 18.0f, 18.0f, 18.0f };	// 21 ^ 7
	float answersShiftLeft[]	= { 4.0f,  4.0f,  4.0f,  4.0f  };	// 1  << 2
	float answersShiftRight[]	= { 1.0f,  1.0f,  1.0f,  1.0f  };	// 16 >> 4

	std::string parmListAnswerUnary = "( ";
	for ( u32 i = 0; i < m_numComponents; i++ ) {
		parmListAnswerUnary += "(" + m_memberTypeString + ") -1";

		if ( i != m_numComponents - 1 ) {
			parmListAnswerUnary += ", ";
		}
	}
	parmListAnswerUnary += " )";

	std::string parmListLhs[GEN_OP_BITWISE_COUNT] = {
		Gen_GetParmListVector( m_type, m_numComponents, values21 ),
		Gen_GetParmListVector( m_type, m_numComponents, values21 ),
		Gen_GetParmListVector( m_type, m_numComponents, values21 ),
		Gen_GetParmListVector( m_type, m_numComponents, values1  ),
		Gen_GetParmListVector( m_type, m_numComponents, values16 ),
	};

	std::string parmListRhs[GEN_OP_BITWISE_COUNT] = {
		Gen_GetParmListVector( m_type, m_numComponents, values7 ),
		Gen_GetParmListVector( m_type, m_numComponents, values7 ),
		Gen_GetParmListVector( m_type, m_numComponents, values7 ),
		Gen_GetParmListVector( m_type, m_numComponents, values2 ),
		Gen_GetParmListVector( m_type, m_numComponents, values4 ),
	};

	std::string parmListAnswers[GEN_OP_BITWISE_COUNT] = {
		Gen_GetParmListVector( m_type, m_numComponents, answersAnd ),
		Gen_GetParmListVector( m_type, m_numComponents, answersOr ),
		Gen_GetParmListVector( m_type, m_numComponents, answersXor ),
		Gen_GetParmListVector( m_type, m_numComponents, answersShiftLeft ),
		Gen_GetParmListVector( m_type, m_numComponents, answersShiftRight ),
	};

	// do unary separately because it takes no rhs parm
	std::string suffices[GEN_OP_BITWISE_COUNT] = {
		"And",
		"Or",
		"Xor",
		"ShiftLeft",
		"ShiftRight",
	};

	genOpBitwise_t ops[] = {
		GEN_OP_BITWISE_AND,
		GEN_OP_BITWISE_OR,
		GEN_OP_BITWISE_XOR,
		GEN_OP_BITWISE_SHIFT_LEFT,
		GEN_OP_BITWISE_SHIFT_RIGHT,
	};

	std::string testName;

	for ( u32 i = 0; i < _countof( ops ); i++ ) {
		testName = "TestBitwise_" + suffices[i] + "_" + m_fullTypeName;

		m_codeTests += "TEMPER_TEST( " + testName + " )\n";
		m_codeTests += "{\n";
		m_codeTests += "\t" + m_fullTypeName + " a  = " + m_fullTypeName + parmListLhs[i] + ";\n";
		m_codeTests += "\t" + m_fullTypeName + " b  = " + m_fullTypeName + parmListRhs[i] + ";\n";
		m_codeTests += "\n";
		m_codeTests += "\t" + m_fullTypeName + " answer = a " + GEN_OPERATORS_BITWISE[ops[i]] + " b;\n";
		m_codeTests += "\n";
		m_codeTests += "\tTEMPER_EXPECT_TRUE( answer == " + m_fullTypeName + parmListAnswers[i] + " );\n";
		m_codeTests += "\n";
		m_codeTests += "\tTEMPER_PASS();\n";
		m_codeTests += "}\n";
		m_codeTests += "\n";

		m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
	}

	// unary
	{
		testName = "TestBitwiseUnary_" + m_fullTypeName;

		m_codeTests += "TEMPER_TEST( " + testName + " )\n";
		m_codeTests += "{\n";
		m_codeTests += "\t" + m_fullTypeName + " a = " + m_fullTypeName + Gen_GetParmListVector( m_type, m_numComponents, values0 ) + ";\n";
		m_codeTests += "\n";
		m_codeTests += "\t" + m_fullTypeName + " answer = " + GEN_OPERATORS_BITWISE[GEN_OP_BITWISE_UNARY] + "a;\n";
		m_codeTests += "\n";
		m_codeTests += "\tTEMPER_EXPECT_TRUE( answer == " + m_fullTypeName + parmListAnswerUnary + " );\n";
		m_codeTests += "\n";
		m_codeTests += "\tTEMPER_PASS();\n";
		m_codeTests += "}\n";
		m_codeTests += "\n";

		m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
	}
}

void GeneratorVectorTests::GenerateTestLength() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	std::string testName = "TestLength_" + m_fullTypeName;

	std::string squaredLengths[] = {
		"8.0",
		"12.0",
		"16.0",
	};

	std::string lengths[] = {
		"2.82842712475",
		"3.46410161514",
		"4.0",
	};

	std::string squaredLength = squaredLengths[m_numComponents - 2];
	std::string length = lengths[m_numComponents - 2];

	std::string floateqStr = Gen_GetFuncNameFloateq( m_type );

	if ( m_type != GEN_TYPE_DOUBLE ) {
		squaredLength += "f";
		length += "f";
	}

	m_codeTests += "TEMPER_TEST( " + testName + " )\n";
	m_codeTests += "{\n";
	m_codeTests += "\t" + m_fullTypeName + " vec = " + m_fullTypeName + "( " + Gen_GetNumericLiteral( m_type, 2 ) + " );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( " + floateqStr + "( lengthsqr( vec ), " + squaredLength + " ) );\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( " + floateqStr + "( length( vec ), " + length + " ) );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";

	m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
}

void GeneratorVectorTests::GenerateTestNormalized() {
	if ( m_type != GEN_TYPE_FLOAT && m_type != GEN_TYPE_DOUBLE ) {
		return;
	}

	std::string testName = "TestNormalized_" + m_fullTypeName;

	float values[] = { 2.0f, 3.0f, 4.0f, 5.0f };
	std::string parmList = Gen_GetParmListVector( m_type, m_numComponents, values );

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( m_type );
	std::string oneStr = Gen_GetNumericLiteral( floatingPointType, 1 );

	m_codeTests += "TEMPER_TEST( " + testName + " )\n";
	m_codeTests += "{\n";
	m_codeTests += "\t" + m_fullTypeName + " vec = " + m_fullTypeName + parmList + ";\n";
	m_codeTests += "\tvec = normalized( vec );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( length( vec ) == " + oneStr + " );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";

	m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
}

void GeneratorVectorTests::GenerateTestDot() {
	if ( m_type == GEN_TYPE_BOOL || m_type == GEN_TYPE_UINT ) {
		return;
	}

	std::string testName = "TestDot_" + m_fullTypeName;

	genType_t dotReturnType = ( m_type == GEN_TYPE_UINT ) ? GEN_TYPE_INT : m_type;
	std::string minusOneStr = Gen_GetNumericLiteral( dotReturnType, -1.0f );

	std::string paramListA = "( ";
	for ( u32 i = 0; i < m_numComponents; i++ ) {
		paramListA += ( i == m_numComponents - 1 ) ? Gen_GetNumericLiteral( m_type, 1 ) : Gen_GetNumericLiteral( m_type, 0 );

		if ( i != m_numComponents - 1 ) {
			paramListA += ", ";
		}
	}
	paramListA += " )";

	std::string paramListB = "( ";
	for ( u32 i = 0; i < m_numComponents; i++ ) {
		paramListB += ( i == m_numComponents - 1 ) ? Gen_GetNumericLiteral( m_type, -1 ) : Gen_GetNumericLiteral( m_type, 0 );

		if ( i != m_numComponents - 1 ) {
			paramListB += ", ";
		}
	}
	paramListB += " )";

	std::string floateqStr = Gen_GetFuncNameFloateq( m_type );

	m_codeTests += "TEMPER_TEST( TestDot_" + m_fullTypeName + " )\n";
	m_codeTests += "{\n";
	m_codeTests += "\t" + m_fullTypeName + " a = " + m_fullTypeName + paramListA + ";\n";
	m_codeTests += "\t" + m_fullTypeName + " b = " + m_fullTypeName + paramListB + ";\n";
	m_codeTests += "\n";
	if ( Gen_IsFloatingPointType( m_type ) ) {
		m_codeTests += "\tTEMPER_EXPECT_TRUE( " + floateqStr + "( dot( a, b ), " + minusOneStr + " ) );\n";
	} else {
		m_codeTests += "\tTEMPER_EXPECT_TRUE( dot( a, b ) == " + minusOneStr + " );\n";
	}
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";

	m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
}

void GeneratorVectorTests::GenerateTestCross() {
	if ( m_type != GEN_TYPE_FLOAT && m_type != GEN_TYPE_DOUBLE ) {
		return;
	}

	std::string testName = "TestCross_" + m_fullTypeName;

	if ( m_numComponents < 3 ) {
		return;
	}

	float left[]	= { -1.0f, 0.0f, 0.0f, 0.0f };
	float up[]		= {  0.0f, 1.0f, 0.0f, 0.0f };
	float forward[]	= {  0.0f, 0.0f, 1.0f, 0.0f };

	std::string parmListLeft	= Gen_GetParmListVector( m_type, m_numComponents, left );
	std::string parmListUp		= Gen_GetParmListVector( m_type, m_numComponents, up );
	std::string parmListForward	= Gen_GetParmListVector( m_type, m_numComponents, forward );

	m_codeTests += "TEMPER_TEST( TestCross_" + m_fullTypeName + " )\n";
	m_codeTests += "{\n";
	m_codeTests += "\t" + m_fullTypeName + " left = " + m_fullTypeName + parmListLeft + ";\n";
	m_codeTests += "\t" + m_fullTypeName + " forward = " + m_fullTypeName + parmListForward + ";\n";
	m_codeTests += "\t" + m_fullTypeName + " up = " + m_fullTypeName + parmListUp + ";\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( cross( left, forward ) == up );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";

	m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
}

void GeneratorVectorTests::GenerateTestAngle() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	std::string testName = "TestAngle_" + m_fullTypeName;

	float right[]	= { 1.0f, 0.0f, 0.0f, 0.0f };
	float up[]		= { 0.0f, 1.0f, 0.0f, 0.0f };

	std::string parmListRight	= Gen_GetParmListVector( m_type, m_numComponents, right );
	std::string parmListUp		= Gen_GetParmListVector( m_type, m_numComponents, up );

	std::string ninetyStr = Gen_GetNumericLiteral( Gen_GetSupportedFloatingPointType( m_type ), 90 );

	std::string floateqStr = Gen_GetFuncNameFloateq( m_type );

	m_codeTests += "TEMPER_TEST( " + testName + " )\n";
	m_codeTests += "{\n";
	m_codeTests += "\t" + m_fullTypeName + " right = " + m_fullTypeName + parmListRight + ";\n";
	m_codeTests += "\t" + m_fullTypeName + " up = " + m_fullTypeName + parmListUp + ";\n";
	m_codeTests += "\t" + m_typeString + " answer = angle( up, right );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( " + floateqStr + "( answer, " + ninetyStr + " ) );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";

	m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
}

void GeneratorVectorTests::GenerateTestDistance() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( m_numComponents > 3 ) {
		return;
	}

	std::string testName = "TestDistance_" + m_fullTypeName;

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( m_type );
	std::string floatingPointStr = Gen_GetTypeString( floatingPointType );

	// numbers picked at random
	// default w to 0 because distance isn't allowed for 4d vectors
	float values0[] = { 7.0f,  4.0f, 3.0f, 0.0f };
	float values1[] = { 17.0f, 6.0f, 2.0f, 0.0f };

	std::string answerDistanceSqrStr, answerDistanceStr;
	switch ( m_numComponents ) {
		case 2:
			answerDistanceSqrStr = Gen_GetNumericLiteral( floatingPointType, 104.0f );
			answerDistanceStr = Gen_GetNumericLiteral( floatingPointType, 10.198039f );
			break;

		case 3:
			answerDistanceSqrStr = Gen_GetNumericLiteral( floatingPointType, 105.0f );
			answerDistanceStr = Gen_GetNumericLiteral( floatingPointType, 10.246951f );
			break;
	}

	std::string parmList0 = Gen_GetParmListVector( m_type, m_numComponents, values0 );
	std::string parmList1 = Gen_GetParmListVector( m_type, m_numComponents, values1 );

	std::string floateqStr = Gen_GetFuncNameFloateq( m_type );

	m_codeTests += "TEMPER_TEST( " + testName + " )\n";
	m_codeTests += "{\n";
	m_codeTests += "\t" + floatingPointStr + " answerDistanceSqr = " + answerDistanceSqrStr + ";\n";
	m_codeTests += "\t" + floatingPointStr + " answerDistance    = " + answerDistanceStr + ";\n";
	m_codeTests += "\n";
	m_codeTests += "\t" + m_fullTypeName + " a = " + m_fullTypeName + parmList0 + ";\n";
	m_codeTests += "\t" + m_fullTypeName + " b = " + m_fullTypeName + parmList1 + ";\n";
	m_codeTests += "\n";
	m_codeTests += "\t" + floatingPointStr + " distSqr = distancesqr( a, b );\n";
	m_codeTests += "\t" + floatingPointStr + " dist    = distance( a, b );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( " + floateqStr + "( distSqr, answerDistanceSqr ) );\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( " + floateqStr + "( dist, answerDistance ) );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";

	m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
}

void GeneratorVectorTests::GenerateTestPacking() {
	if ( m_type != GEN_TYPE_UINT ) {
		return;
	}

	if ( m_numComponents != 4 ) {
		return;
	}

	std::string testName = "TestPacking_" + m_fullTypeName;

	float values[] = { 255, 255, 0, 255 };	// magenta
	std::string parmListAnswerUnpacked = Gen_GetParmListVector( m_type, m_numComponents, values );

	std::string answerPackedStr = "0xFFFF00FF";

	// tests pack and unpack
	m_codeTests += "TEMPER_TEST( " + testName + " )\n";
	m_codeTests += "{\n";
	m_codeTests += "\t" + m_memberTypeString + " answerPacked = " + answerPackedStr + ";\n";
	m_codeTests += "\t" + m_fullTypeName + " answerUnpacked = " + m_fullTypeName + parmListAnswerUnpacked + ";\n";
	m_codeTests += "\n";
	m_codeTests += "\t" + m_fullTypeName + " vec = " + m_fullTypeName + parmListAnswerUnpacked + ";\n";	// we can use the same parm list here, it's fine
	m_codeTests += "\n";
	m_codeTests += "\t" + m_memberTypeString + " packed = pack( vec );\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( packed == answerPacked );\n";
	m_codeTests += "\n";
	m_codeTests += "\t" + m_fullTypeName + " unpacked = unpack( packed );\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( unpacked == answerUnpacked );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";

	m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
}

void GeneratorVectorTests::GenerateTestSaturate() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	std::string testName = "TestSaturate_" + m_fullTypeName;

	float values[]			= { -1.0f, 2.0f, 4.0f, 6.0f };
	float valuesAnswer[]	= {  0.0f, 1.0f, 1.0f, 1.0f };

	std::string parmList		= Gen_GetParmListVector( m_type, m_numComponents, values );
	std::string parmListAnswer	= Gen_GetParmListVector( m_type, m_numComponents, valuesAnswer );

	m_codeTests += "TEMPER_TEST( " + testName + " )\n";
	m_codeTests += "{\n";
	m_codeTests += "\t" + m_fullTypeName + " answer = " + m_fullTypeName + parmListAnswer + ";\n";
	m_codeTests += "\n";
	m_codeTests += "\t" + m_fullTypeName + " vec = " + m_fullTypeName + parmList + ";\n";
	m_codeTests += "\t" + m_fullTypeName + " clamped = saturate( vec );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( clamped == answer );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";

	m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
}

void GeneratorVectorTests::GenerateTestLerp() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	std::string testName = "TestLerp_" + m_fullTypeName;

	float valuesA[]			= { 0.0f, 1.0f, 0.0f, 0.0f };
	float valuesB[]			= { 1.0f, 0.0f, 0.0f, 0.0f };
	float valuesAnswer[]	= { 0.5f, 0.5f, 0.0f, 0.0f };

	std::string parmListA		= Gen_GetParmListVector( m_type, m_numComponents, valuesA );
	std::string parmListB		= Gen_GetParmListVector( m_type, m_numComponents, valuesB );
	std::string parmListAnswer	= Gen_GetParmListVector( m_type, m_numComponents, valuesAnswer );

	std::string lerpValStr = Gen_GetNumericLiteral( m_type, 0.5f );

	m_codeTests += "TEMPER_TEST( " + testName + " )\n";
	m_codeTests += "{\n";
	m_codeTests += "\t" + m_fullTypeName + " answer = " + m_fullTypeName + parmListAnswer + ";\n";
	m_codeTests += "\n";
	m_codeTests += "\t" + m_fullTypeName + " a = " + m_fullTypeName + parmListA + ";\n";
	m_codeTests += "\t" + m_fullTypeName + " b = " + m_fullTypeName + parmListB + ";\n";
	m_codeTests += "\t" + m_fullTypeName + " lerped = lerp( a, b, " + lerpValStr + " );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( lerped == answer );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";

	m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
}

void GeneratorVectorTests::GenerateTestSmoothstep() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	std::string testName = "TestSmoothstep_" + m_fullTypeName;

	float valuesLow[]						= { 0.0f, 0.0f, 0.0f, 0.0f };
	float valuesHigh[]						= { 1.0f, 1.0f, 1.0f, 1.0f };

	float valuesInput0[]					= { 0.2f, 0.2f, 0.2f, 0.2f };
	float valuesInput1[]					= { 1.2f, 1.2f, 1.2f, 1.2f };

	float valuesAnswerInRangeSmoothstep[]	= { 0.104f, 0.104f, 0.104f, 0.104f };
	float valuesAnswerClampedSmoothstep[]	= { 1.0f,   1.0f,   1.0f,   1.0f   };

	float valuesAnswerInRangeSmootherstep[]	= { 0.057920f, 0.057920f, 0.057920f, 0.057920f };
	float valuesAnswerClampedSmootherstep[]	= { 1.0f,      1.0f,      1.0f,      1.0f      };

	std::string parmListLow							= Gen_GetParmListVector( m_type, m_numComponents, valuesLow );
	std::string parmListHigh						= Gen_GetParmListVector( m_type, m_numComponents, valuesHigh );

	std::string parmListInput0						= Gen_GetParmListVector( m_type, m_numComponents, valuesInput0 );
	std::string parmListInput1						= Gen_GetParmListVector( m_type, m_numComponents, valuesInput1 );

	std::string parmListAnswerInRangeSmoothstep		= Gen_GetParmListVector( m_type, m_numComponents, valuesAnswerInRangeSmoothstep );
	std::string parmListAnswerClampedSmoothstep		= Gen_GetParmListVector( m_type, m_numComponents, valuesAnswerClampedSmoothstep );

	std::string parmListAnswerInRangeSmootherstep	= Gen_GetParmListVector( m_type, m_numComponents, valuesAnswerInRangeSmootherstep );
	std::string parmListAnswerClampedSmootherstep	= Gen_GetParmListVector( m_type, m_numComponents, valuesAnswerClampedSmootherstep );

	m_codeTests += "TEMPER_TEST( " + testName + " )\n";
	m_codeTests += "{\n";
	m_codeTests += "\t" + m_fullTypeName + " answerInRangeSmoothstep   = " + m_fullTypeName + parmListAnswerInRangeSmoothstep + ";\n";
	m_codeTests += "\t" + m_fullTypeName + " answerClampedSmoothstep   = " + m_fullTypeName + parmListAnswerClampedSmoothstep + ";\n";
	m_codeTests += "\t" + m_fullTypeName + " answerInRangeSmootherstep = " + m_fullTypeName + parmListAnswerInRangeSmootherstep + ";\n";
	m_codeTests += "\t" + m_fullTypeName + " answerClampedSmootherstep = " + m_fullTypeName + parmListAnswerClampedSmootherstep + ";\n";
	m_codeTests += "\t" + m_fullTypeName + " answer;\n";
	m_codeTests += "\n";
	m_codeTests += "\t" + m_fullTypeName + " low  = " + m_fullTypeName + parmListLow + ";\n";
	m_codeTests += "\t" + m_fullTypeName + " high = " + m_fullTypeName + parmListHigh + ";\n";
	m_codeTests += "\n";
	m_codeTests += "\tanswer = smoothstep( low, high, " + m_fullTypeName + parmListInput0 + " );\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( answer == answerInRangeSmoothstep );\n";
	m_codeTests += "\n";
	m_codeTests += "\tanswer = smoothstep( low, high, " + m_fullTypeName + parmListInput1 + " );\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( answer == answerClampedSmoothstep );\n";
	m_codeTests += "\n";
	m_codeTests += "\tanswer = smootherstep( low, high, " + m_fullTypeName + parmListInput0 + " );\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( answer == answerInRangeSmootherstep );\n";
	m_codeTests += "\n";
	m_codeTests += "\tanswer = smootherstep( low, high, " + m_fullTypeName + parmListInput1 + " );\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( answer == answerClampedSmootherstep );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";

	m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
}
