#include "TestsGeneratorVector.h"

#include "FileIO.h"

#include "gen_funcs_vector.h"

#include <vector>

void TestsGeneratorVector::Generate( const genType_t type, const uint32_t numComponents ) {
	m_code = std::string();

	m_type = type;

	m_numComponents = numComponents;

	m_numComponentsStr = std::to_string( numComponents );

	m_typeString = Gen_GetTypeString( type );
	m_memberTypeString = Gen_GetMemberTypeString( type );

	m_fullTypeName = m_typeString + std::to_string( numComponents );

	m_testPrefix = "Test_" + m_fullTypeName;

	m_code += GEN_FILE_HEADER;

	m_code += std::string( "#include \"../" ) + GEN_OUT_GEN_FOLDER_PATH + GEN_FILENAME_FUNCTIONS_VECTOR + ".h\"\n";
	m_code += "\n";

	m_code += "#include <temper.h>\n";
	m_code += "\n";

	GenerateTestAssignment();

	GenerateTestArithmetic();

	GenerateTestArray();

	GenerateTestRelational();

	GenerateTestLength();

	GenerateTestNormalized();

	GenerateTestDot();

	GenerateTestCross();

	GenerateTestAngle();

	m_code += "TEMPER_SUITE( " + m_testPrefix + " ) {\n";
	m_code += "\tTEMPER_RUN_TEST( TestAssignment_" + m_fullTypeName + " );\n";
	m_code += "\tTEMPER_RUN_TEST( TestArray_" + m_fullTypeName + " );\n";
	if ( m_type != GEN_TYPE_BOOL ) {
		m_code += "\n";
		m_code += "\tTEMPER_RUN_TEST( TestArithmeticAddition_" + m_fullTypeName + " );\n";
		m_code += "\tTEMPER_RUN_TEST( TestArithmeticSubtraction_" + m_fullTypeName + " );\n";
		m_code += "\tTEMPER_RUN_TEST( TestArithmeticMultiplication_" + m_fullTypeName + " );\n";
		m_code += "\tTEMPER_RUN_TEST( TestArithmeticDivision_" + m_fullTypeName + " );\n";
		m_code += "\n";
		m_code += "\tTEMPER_RUN_TEST( TestRelational_" + m_fullTypeName + " );\n";
		m_code += "\n";
		m_code += "\tTEMPER_RUN_TEST( TestLength_" + m_fullTypeName + " );\n";
	}
	if ( Gen_IsFloatingPointType( m_type ) ) {
		m_code += "\tTEMPER_RUN_TEST( TestNormalized_" + m_fullTypeName + " );\n";
	}
	if ( m_type != GEN_TYPE_BOOL && m_type != GEN_TYPE_UINT ) {
		m_code += "\tTEMPER_RUN_TEST( TestDot_" + m_fullTypeName + " );\n";
	}
	if ( Gen_IsFloatingPointType( m_type ) ) {
		if ( m_numComponents >= 3 ) {
			m_code += "\tTEMPER_RUN_TEST( TestCross_" + m_fullTypeName + " );\n";
		}
		m_code += "\tTEMPER_RUN_TEST( TestAngle_" + m_fullTypeName + " );\n";

		m_code += "\tTEMPER_RUN_TEST( TestSaturate_" + m_fullTypeName + " );\n";
	}
	m_code += "};\n";

	char filename[1024] = { 0 };
	snprintf( filename, 1024, "%stest_%s.cpp", GEN_TESTS_FOLDER_PATH, m_fullTypeName.c_str() );

	if ( !FS_WriteToFile( filename, m_code.c_str(), m_code.size() ) ) {
		printf( "Can't generate test suite for %s.  That's rough man.\n", m_fullTypeName.c_str() );
	}
}

void TestsGeneratorVector::GenerateTestAssignment() {
	std::string oneStr = Gen_GetNumericLiteral( m_type, 1 );

	std::string paramListOne = "( " + oneStr + " )";

	float values[] = { 0.0f, 1.0f, 2.0f, 3.0f };
	std::string parmListVarying = Gen_GetParmListVector( m_type, m_numComponents, values );

	m_code += "// also tests equality operators\n";
	m_code += "TEMPER_TEST( TestAssignment_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " a;\n";
	m_code += "\n";
	m_code += "\ta = " + m_fullTypeName + paramListOne + ";\n";
	m_code += "\tTEMPER_EXPECT_TRUE( a == " + m_fullTypeName + paramListOne + " );\n";
	m_code += "\tTEMPER_EXPECT_TRUE( a != " + m_fullTypeName + parmListVarying + " );\n";
	m_code += "\n";
	m_code += "\ta = " + m_fullTypeName + parmListVarying + ";\n";
	m_code += "\tTEMPER_EXPECT_TRUE( a == " + m_fullTypeName + parmListVarying + " );\n";
	m_code += "\tTEMPER_EXPECT_TRUE( a != " + m_fullTypeName + paramListOne + " );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorVector::GenerateTestArray() {
	float values[] = { 0.0f, 1.0f, 2.0f, 3.0f };
	std::string parmList = Gen_GetParmListVector( m_type, m_numComponents, values );

	m_code += "TEMPER_TEST( TestArray_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " a = " + m_fullTypeName + parmList + ";\n";
	m_code += "\n";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		m_code += "\tTEMPER_EXPECT_TRUE( a[" + std::to_string( i ) + "] == " + Gen_GetNumericLiteral( m_type, static_cast<float>( i ) ) + " );\n";
	}
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorVector::GenerateTestArithmetic() {
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

	for ( uint32_t i = 0; i < GEN_OP_ARITHMETIC_COUNT; i++ ) {
		m_code += "TEMPER_TEST( TestArithmetic" + suffices[i] + "_" + m_fullTypeName + " ) {\n";
		m_code += "\t" + m_fullTypeName + " a  = " + m_fullTypeName + parmListBase + ";\n";
		m_code += "\t" + m_fullTypeName + " b  = " + m_fullTypeName + parmListValues[i] + ";\n";
		m_code += "\n";
		m_code += "\t" + m_fullTypeName + " c = a " + GEN_OPERATORS_ARITHMETIC[i] + " b;\n";
		m_code += "\n";
		m_code += "\tTEMPER_EXPECT_TRUE( c == " + m_fullTypeName + parmListAnswers[i] + " );\n";
		m_code += "\n";
		m_code += "\tTEMPER_PASS();\n";
		m_code += "}\n";
		m_code += "\n";
	}
}

// TODO(DM): make this one the same as matrix equivalent
void TestsGeneratorVector::GenerateTestRelational() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	std::vector<std::string> paramLists( m_numComponents );

	std::string boolTypeName = "bool" + m_numComponentsStr;

	uint32_t numTestVectors = 0;

	for ( uint32_t componentIndex = 0; componentIndex < m_numComponents; componentIndex++ ) {
		std::string& paramList = paramLists[componentIndex];

		paramList = "( ";
		for ( uint32_t paramIndex = 0; paramIndex < m_numComponents; paramIndex++ ) {
			paramList += Gen_GetNumericLiteral( m_type, static_cast<float>( componentIndex ) );

			if ( paramIndex != m_numComponents - 1 ) {
				paramList += ", ";
			}
		}
		paramList += " )";
	}

	m_code += "TEMPER_TEST( TestRelational_" + m_fullTypeName + " ) {\n";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		m_code += "\t" + m_fullTypeName + " vec" + std::to_string( i ) + " = " + m_fullTypeName + paramLists[i] + ";\n";
	}
	m_code += "\n";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		std::string indexStr = std::to_string( i );

		std::string vecString = "vec" + indexStr;

		m_code += "\t" + boolTypeName + " test" + std::to_string( numTestVectors++ ) + " = " + vecString + " <= " + vecString + ";\n";
		m_code += "\t" + boolTypeName + " test" + std::to_string( numTestVectors++ ) + " = " + vecString + " >= " + vecString + ";\n";
		if ( i < m_numComponents - 1 ) {
			m_code += "\t" + boolTypeName + " test" + std::to_string( numTestVectors++ ) + " = " + vecString + " < vec" + std::to_string( i + 1 ) + ";\n";
		}
		if ( i > 0 ) {
			m_code += "\t" + boolTypeName + " test" + std::to_string( numTestVectors++ ) + " = " + vecString + " > vec" + std::to_string( i - 1 ) + ";\n";
		}
		m_code += "\n";
	}
	for ( uint32_t i = 0; i < numTestVectors; i++ ) {
		m_code += "\tTEMPER_EXPECT_TRUE( test" + std::to_string( i ) + " == " + boolTypeName + "( true ) );\n";
	}
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorVector::GenerateTestLength() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

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

	if ( m_type != GEN_TYPE_DOUBLE ) {
		squaredLength += "f";
		length += "f";
	}

	m_code += "TEMPER_TEST( TestLength_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " vec = " + m_fullTypeName + "( " + Gen_GetNumericLiteral( m_type, 2 ) + " );\n";
	m_code += "\n";
	m_code += "\tTEMPER_EXPECT_TRUE( floateq( lengthsqr( vec ), " + squaredLength + " ) );\n";
	m_code += "\tTEMPER_EXPECT_TRUE( floateq( length( vec ), " + length + " ) );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorVector::GenerateTestNormalized() {
	if ( m_type != GEN_TYPE_FLOAT && m_type != GEN_TYPE_DOUBLE ) {
		return;
	}

	float values[] = { 2.0f, 3.0f, 4.0f, 5.0f };
	std::string parmList = Gen_GetParmListVector( m_type, m_numComponents, values );

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( m_type );
	std::string oneStr = Gen_GetNumericLiteral( floatingPointType, 1 );

	m_code += "TEMPER_TEST( TestNormalized_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " vec = " + m_fullTypeName + parmList + ";\n";
	m_code += "\tvec = normalized( vec );\n";
	m_code += "\n";
	m_code += "\tTEMPER_EXPECT_TRUE( length( vec ) == " + oneStr + " );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorVector::GenerateTestDot() {
	if ( m_type == GEN_TYPE_BOOL || m_type == GEN_TYPE_UINT ) {
		return;
	}

	std::string minusOneFloatStr;
	if ( m_type == GEN_TYPE_DOUBLE ) {
		minusOneFloatStr = "-1.0";
	} else {
		minusOneFloatStr = "-1.0f";
	}

	std::string paramListA = "( ";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		paramListA += ( i == m_numComponents - 1 ) ? Gen_GetNumericLiteral( m_type, 1 ) : Gen_GetNumericLiteral( m_type, 0 );

		if ( i != m_numComponents - 1 ) {
			paramListA += ", ";
		}
	}
	paramListA += " )";

	std::string paramListB = "( ";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		paramListB += ( i == m_numComponents - 1 ) ? Gen_GetNumericLiteral( m_type, -1 ) : Gen_GetNumericLiteral( m_type, 0 );

		if ( i != m_numComponents - 1 ) {
			paramListB += ", ";
		}
	}
	paramListB += " )";

	m_code += "TEMPER_TEST( TestDot_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " a = " + m_fullTypeName + paramListA + ";\n";
	m_code += "\t" + m_fullTypeName + " b = " + m_fullTypeName + paramListB + ";\n";
	m_code += "\n";
	m_code += "\tTEMPER_EXPECT_TRUE( dot( a, b ) == " + minusOneFloatStr + " );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorVector::GenerateTestCross() {
	if ( m_type != GEN_TYPE_FLOAT && m_type != GEN_TYPE_DOUBLE ) {
		return;
	}

	if ( m_numComponents < 3 ) {
		return;
	}

	float left[]	= { -1.0f, 0.0f, 0.0f, 0.0f };
	float up[]		= {  0.0f, 1.0f, 0.0f, 0.0f };
	float forward[]	= {  0.0f, 0.0f, 1.0f, 0.0f };

	std::string parmListLeft	= Gen_GetParmListVector( m_type, m_numComponents, left );
	std::string parmListUp		= Gen_GetParmListVector( m_type, m_numComponents, up );
	std::string parmListForward	= Gen_GetParmListVector( m_type, m_numComponents, forward );

	m_code += "TEMPER_TEST( TestCross_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " left = " + m_fullTypeName + parmListLeft + ";\n";
	m_code += "\t" + m_fullTypeName + " forward = " + m_fullTypeName + parmListForward + ";\n";
	m_code += "\t" + m_fullTypeName + " up = " + m_fullTypeName + parmListUp + ";\n";
	m_code += "\n";
	m_code += "\tTEMPER_EXPECT_TRUE( cross( left, forward ) == up );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorVector::GenerateTestAngle() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	float right[]	= { 1.0f, 0.0f, 0.0f, 0.0f };
	float up[]		= { 0.0f, 1.0f, 0.0f, 0.0f };

	std::string parmListRight	= Gen_GetParmListVector( m_type, m_numComponents, right );
	std::string parmListUp		= Gen_GetParmListVector( m_type, m_numComponents, up );

	std::string ninetyStr = Gen_GetNumericLiteral( Gen_GetSupportedFloatingPointType( m_type ), 90 );

	m_code += "TEMPER_TEST( TestAngle_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " right = " + m_fullTypeName + parmListRight + ";\n";
	m_code += "\t" + m_fullTypeName + " up = " + m_fullTypeName + parmListUp + ";\n";
	m_code += "\t" + m_typeString + " answer = angle( up, right );\n";
	m_code += "\n";
	m_code += "\tTEMPER_EXPECT_TRUE( floateq( answer, " + ninetyStr + " ) );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}