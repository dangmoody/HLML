#include "TestsGeneratorVector.h"

#include "FileIO.h"

#include <vector>

void TestsGeneratorVector::Generate( const genType_t type, const uint32_t numComponents ) {
	m_code = std::string();

	m_type = type;

	m_numComponents = numComponents;

	m_typeString = Gen_GetTypeString( type );
	m_memberTypeString = Gen_GetMemberTypeString( type );

	m_fullTypeName = m_typeString + std::to_string( numComponents );

	m_testPrefix = "Test_" + m_fullTypeName;

	m_code += GEN_COPYRIGHT_HEADER;
	m_code += "\n";
	m_code += GEN_GENERATED_WARNING;
	m_code += "\n";

	m_code += std::string( "#include \"../" ) + GEN_OUT_FOLDER_PATH + m_fullTypeName + ".h\"\n";
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
		m_code += "\tTEMPER_SKIP_TEST( TestLength_" + m_fullTypeName + ", \"TODO\" );\n";
		m_code += "\tTEMPER_SKIP_TEST( TestNormalized_" + m_fullTypeName + ", \"TODO\" );\n";
		m_code += "\tTEMPER_SKIP_TEST( TestDot_" + m_fullTypeName + ", \"TODO\" );\n";
		m_code += "\tTEMPER_SKIP_TEST( TestCross_" + m_fullTypeName + ", \"TODO\" );\n";
		m_code += "\tTEMPER_SKIP_TEST( TestAngle_" + m_fullTypeName + ", \"TODO\" );\n";
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

	std::string paramListVarying = "( ";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		paramListVarying += Gen_GetNumericLiteral( m_type, i );

		if ( i != m_numComponents - 1 ) {
			paramListVarying += ", ";
		}
	}
	paramListVarying += " )";

	m_code += "// also tests equality operators\n";
	m_code += "TEMPER_TEST( TestAssignment_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " a;\n";
	m_code += "\n";
	m_code += "\ta = " + m_fullTypeName + paramListOne + ";\n";
	m_code += "\tTEMPER_EXPECT_TRUE( a == " + m_fullTypeName + paramListOne + " );\n";
	m_code += "\tTEMPER_EXPECT_TRUE( a != " + m_fullTypeName + paramListVarying + " );\n";
	m_code += "\n";
	m_code += "\ta = " + m_fullTypeName + paramListVarying + ";\n";
	m_code += "\tTEMPER_EXPECT_TRUE( a == " + m_fullTypeName + paramListVarying + " );\n";
	m_code += "\tTEMPER_EXPECT_TRUE( a != " + m_fullTypeName + paramListOne + " );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorVector::GenerateTestArray() {
	std::string paramList = "( ";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		paramList += Gen_GetNumericLiteral( m_type, i );

		if ( i != m_numComponents - 1 ) {
			paramList += ", ";
		}
	}
	paramList += " )";

	m_code += "TEMPER_TEST( TestArray_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " a = " + m_fullTypeName + paramList + ";\n";
	m_code += "\n";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		m_code += "\tTEMPER_EXPECT_TRUE( a[" + std::to_string( i ) + "] == " + Gen_GetNumericLiteral( m_type, i ) + " );\n";
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
	const uint32_t baseNumber = 2;

	std::string paramListOne = "( " + Gen_GetNumericLiteral( m_type, baseNumber ) + " )";
	std::string paramListVarying = "( ";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		paramListVarying += Gen_GetNumericLiteral( m_type, i + baseNumber );

		if ( i != m_numComponents - 1 ) {
			paramListVarying += ", ";
		}
	}
	paramListVarying += " )";

	std::vector<std::string> paramListAnswers( _countof( GEN_OPERATORS_ARITHMETIC ) );

	// addition
	{
		std::string paramListAnswerAddition = "( ";
		for ( uint32_t i = 0; i < m_numComponents; i++ ) {
			paramListAnswerAddition += Gen_GetNumericLiteral( m_type, baseNumber + ( i + baseNumber ) );

			if ( i != m_numComponents - 1 ) {
				paramListAnswerAddition += ", ";
			}
		}
		paramListAnswerAddition += " )";

		paramListAnswers[0] = paramListAnswerAddition;
	}

	// subtraction
	{
		std::string paramListAnswerAddition = "( ";
		for ( uint32_t i = 0; i < m_numComponents; i++ ) {
			paramListAnswerAddition += Gen_GetNumericLiteral( m_type, baseNumber - ( i + baseNumber ) );

			if ( i != m_numComponents - 1 ) {
				paramListAnswerAddition += ", ";
			}
		}
		paramListAnswerAddition += " )";

		paramListAnswers[1] = paramListAnswerAddition;
	}

	// multiplication
	{
		std::string paramListAnswerAddition = "( ";
		for ( uint32_t i = 0; i < m_numComponents; i++ ) {
			paramListAnswerAddition += Gen_GetNumericLiteral( m_type, baseNumber * ( i + baseNumber ) );

			if ( i != m_numComponents - 1 ) {
				paramListAnswerAddition += ", ";
			}
		}
		paramListAnswerAddition += " )";

		paramListAnswers[2] = paramListAnswerAddition;
	}

	// division
	{
		std::string paramListAnswerAddition = "( ";
		for ( uint32_t i = 0; i < m_numComponents; i++ ) {
			if ( Gen_IsFloatingPointType( m_type ) ) {
				if ( m_type == GEN_TYPE_FLOAT ) {
					paramListAnswerAddition += std::to_string( (float) baseNumber / (float)( i + baseNumber ) );
				} else {
					paramListAnswerAddition += std::to_string( (double) baseNumber / (double) ( i + baseNumber ) );
				}
			} else {
				paramListAnswerAddition += Gen_GetNumericLiteral( m_type, 1 / ( i + 1 ) );
			}

			if ( i != m_numComponents - 1 ) {
				paramListAnswerAddition += ", ";
			}
		}
		paramListAnswerAddition += " )";

		paramListAnswers[3] = paramListAnswerAddition;
	}

	std::vector<std::string> testSuffices = {
		"Addition",
		"Subtraction",
		"Multiplication",
		"Division",
	};

	for ( uint32_t operatorIndex = 0; operatorIndex < _countof( GEN_OPERATORS_ARITHMETIC ); operatorIndex++ ) {
		m_code += "TEMPER_TEST( TestArithmetic" + testSuffices[operatorIndex] + "_" + m_fullTypeName + " ) {\n";
		m_code += "\t" + m_fullTypeName + " a = " + m_fullTypeName + paramListOne + ";\n";
		m_code += "\t" + m_fullTypeName + " b = " + m_fullTypeName + paramListVarying + ";\n";
		m_code += "\t" + m_fullTypeName + " c = a " + GEN_OPERATORS_ARITHMETIC[operatorIndex] + " b;\n";
		m_code += "\n";
		m_code += "\tTEMPER_EXPECT_TRUE( c == " + m_fullTypeName + paramListAnswers[operatorIndex] + " );\n";
		m_code += "\n";
		m_code += "\tTEMPER_PASS();\n";
		m_code += "}\n";
		m_code += "\n";
	}
}

void TestsGeneratorVector::GenerateTestRelational() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	std::vector<std::string> valueStrings( m_numComponents );
	std::vector<std::string> paramLists( m_numComponents );

	std::string boolTypeName = "bool" + std::to_string( m_numComponents );

	uint32_t numTestVectors = 0;

	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		valueStrings[i] = Gen_GetNumericLiteral( m_type, i );
	}

	for ( uint32_t componentIndex = 0; componentIndex < m_numComponents; componentIndex++ ) {
		std::string& paramList = paramLists[componentIndex];

		paramList = "( ";
		for ( uint32_t paramIndex = 0; paramIndex < m_numComponents; paramIndex++ ) {
			paramList += Gen_GetNumericLiteral( m_type, componentIndex );

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
		m_code += "\tTEMPER_EXPECT_TRUE( test" + std::to_string( i ) + " == " + boolTypeName + "( true )" + " );\n";
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

	m_code += "TEMPER_TEST( TestLength_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorVector::GenerateTestNormalized() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestNormalized_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorVector::GenerateTestDot() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestDot_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorVector::GenerateTestCross() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestCross_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorVector::GenerateTestAngle() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestAngle_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}