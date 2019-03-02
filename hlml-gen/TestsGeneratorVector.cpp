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

	m_code += GEN_FILE_HEADER;

	m_code += std::string( "#include \"../" ) + GEN_OUT_GEN_FOLDER_PATH + GEN_HEADER_FUNCTIONS_VECTOR + ".h\"\n";
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
	if ( m_type == GEN_TYPE_FLOAT || m_type == GEN_TYPE_DOUBLE ) {
		m_code += "\tTEMPER_RUN_TEST( TestNormalized_" + m_fullTypeName + " );\n";
	}
	if ( m_type != GEN_TYPE_BOOL && m_type != GEN_TYPE_UINT ) {
		m_code += "\tTEMPER_RUN_TEST( TestDot_" + m_fullTypeName + " );\n";
	}
	if ( m_type == GEN_TYPE_FLOAT || m_type == GEN_TYPE_DOUBLE ) {
		if ( m_numComponents >= 3 ) {
			m_code += "\tTEMPER_RUN_TEST( TestCross_" + m_fullTypeName + " );\n";
		}
		m_code += "\tTEMPER_RUN_TEST( TestAngle_" + m_fullTypeName + " );\n";
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
	const int32_t baseNumber = 2;

	std::string paramListOne = "( " + Gen_GetNumericLiteral( m_type, baseNumber ) + " )";
	std::string paramListVarying = "( ";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		paramListVarying += Gen_GetNumericLiteral( m_type, i + baseNumber );

		if ( i != m_numComponents - 1 ) {
			paramListVarying += ", ";
		}
	}
	paramListVarying += " )";

	std::vector<std::string> paramListAnswers( GEN_ARITHMETIC_OP_COUNT );

	// addition
	{
		std::string paramList = "( ";
		for ( uint32_t i = 0; i < m_numComponents; i++ ) {
			paramList += Gen_GetNumericLiteral( m_type, baseNumber + ( (int32_t) i + baseNumber ) );

			if ( i != m_numComponents - 1 ) {
				paramList += ", ";
			}
		}
		paramList += " )";

		paramListAnswers[0] = paramList;
	}

	// subtraction
	{
		std::string paramList = "( ";
		for ( uint32_t i = 0; i < m_numComponents; i++ ) {
			paramList += Gen_GetNumericLiteral( m_type, baseNumber - ( (int32_t) i + baseNumber ) );

			if ( i != m_numComponents - 1 ) {
				paramList += ", ";
			}
		}
		paramList += " )";

		paramListAnswers[1] = paramList;
	}

	// multiplication
	{
		std::string paramList = "( ";
		for ( uint32_t i = 0; i < m_numComponents; i++ ) {
			paramList += Gen_GetNumericLiteral( m_type, baseNumber * ( (int32_t) i + baseNumber ) );

			if ( i != m_numComponents - 1 ) {
				paramList += ", ";
			}
		}
		paramList += " )";

		paramListAnswers[2] = paramList;
	}

	// division
	{
		std::string paramList = "( ";
		for ( uint32_t i = 0; i < m_numComponents; i++ ) {
			if ( Gen_IsFloatingPointType( m_type ) ) {
				// TODO(DM): find a better way of representing this
				if ( m_type == GEN_TYPE_FLOAT ) {
					paramList += std::to_string( (float) baseNumber / (float)( i + baseNumber ) );
				} else {
					paramList += std::to_string( (double) baseNumber / (double) ( i + baseNumber ) );
				}
			} else {
				paramList += Gen_GetNumericLiteral( m_type, baseNumber / ( i + baseNumber ) );
			}

			if ( i != m_numComponents - 1 ) {
				paramList += ", ";
			}
		}
		paramList += " )";

		paramListAnswers[3] = paramList;
	}

	std::vector<std::string> testSuffices = {
		"Addition",
		"Subtraction",
		"Multiplication",
		"Division",
	};

	for ( uint32_t operatorIndex = 0; operatorIndex < GEN_ARITHMETIC_OP_COUNT; operatorIndex++ ) {
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

// TODO(DM): make this one the same as matrix equivalent
void TestsGeneratorVector::GenerateTestRelational() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	std::vector<std::string> paramLists( m_numComponents );

	std::string boolTypeName = "bool" + std::to_string( m_numComponents );

	uint32_t numTestVectors = 0;

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

	std::string paramListVarying = "( ";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		paramListVarying += Gen_GetNumericLiteral( m_type, i + 2 );

		if ( i != m_numComponents - 1 ) {
			paramListVarying += ", ";
		}
	}
	paramListVarying += " )";

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( m_type );
	std::string oneStr = Gen_GetNumericLiteral( floatingPointType, 1 );

	m_code += "TEMPER_TEST( TestNormalized_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " vec = " + m_fullTypeName + paramListVarying + ";\n";
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

	std::string zeroStr = Gen_GetNumericLiteral( m_type, 0 );
	std::string oneStr = Gen_GetNumericLiteral( m_type, 1 );
	std::string minusOneStr = Gen_GetNumericLiteral( m_type, -1 );

	std::string paramListLeft = "( ";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		paramListLeft += ( i == 0 ) ? minusOneStr : zeroStr;

		if ( i != m_numComponents - 1 ) {
			paramListLeft += ", ";
		}
	}
	paramListLeft += " )";

	std::string paramListUp = "( ";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		paramListUp += ( i == 1 ) ? oneStr : zeroStr;

		if ( i != m_numComponents - 1 ) {
			paramListUp += ", ";
		}
	}
	paramListUp += " )";

	std::string paramListForward = "( ";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		paramListForward += ( i == 2 ) ? oneStr : zeroStr;

		if ( i != m_numComponents - 1 ) {
			paramListForward += ", ";
		}
	}
	paramListForward += " )";

	m_code += "TEMPER_TEST( TestCross_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " left = " + m_fullTypeName + paramListLeft + ";\n";
	m_code += "\t" + m_fullTypeName + " forward = " + m_fullTypeName + paramListForward + ";\n";
	m_code += "\t" + m_fullTypeName + " up = " + m_fullTypeName + paramListUp + ";\n";
	m_code += "\n";
	m_code += "\tTEMPER_EXPECT_TRUE( cross( left, forward ) == up );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorVector::GenerateTestAngle() {
	if ( m_type != GEN_TYPE_FLOAT && m_type != GEN_TYPE_DOUBLE ) {
		return;
	}

	std::string zeroStr = Gen_GetNumericLiteral( m_type, 0 );
	std::string oneStr = Gen_GetNumericLiteral( m_type, 1 );
	std::string ninetyStr = Gen_GetNumericLiteral( Gen_GetSupportedFloatingPointType( m_type ), 90 );

	std::string paramListRight = "( ";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		paramListRight += ( i == 0 ) ? oneStr : zeroStr;

		if ( i != m_numComponents - 1 ) {
			paramListRight += ", ";
		}
	}
	paramListRight += " )";

	std::string paramListUp = "( ";
	for ( uint32_t i = 0; i < m_numComponents; i++ ) {
		paramListUp += ( i == 1 ) ? oneStr : zeroStr;

		if ( i != m_numComponents - 1 ) {
			paramListUp += ", ";
		}
	}
	paramListUp += " )";

	m_code += "TEMPER_TEST( TestAngle_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " right = " + m_fullTypeName + paramListRight + ";\n";
	m_code += "\t" + m_fullTypeName + " up = " + m_fullTypeName + paramListUp + ";\n";
	m_code += "\t" + m_typeString + " answer = angle( up, right );\n";
	m_code += "\n";
	m_code += "\tTEMPER_EXPECT_TRUE( floateq( answer, " + ninetyStr + " ) );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}