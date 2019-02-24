#include "TestsGeneratorMatrix.h"

#include "FileIO.h"

#include <vector>

void TestsGeneratorMatrix::Generate( const genType_t type, const uint32_t numRows, const uint32_t numCols ) {
	m_code = std::string();

	m_type = type;

	m_numRows = numRows;
	m_numCols = numCols;

	m_typeString = Gen_GetTypeString( type );
	m_memberTypeString = Gen_GetMemberTypeString( type );

	m_vectorTypeString = m_typeString + std::to_string( numCols );
	m_fullTypeName = m_typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	m_testPrefix = "Test_" + m_fullTypeName;

	m_code += GEN_COPYRIGHT_HEADER;
	m_code += "\n";
	m_code += GEN_GENERATED_WARNING;
	m_code += "\n";

	m_code += std::string( "#include \"../" ) + GEN_OUT_GEN_FOLDER_PATH + GEN_HEADER_FUNCTIONS_MATRIX + ".h\"\n";
	m_code += "\n";

	m_code += "#include <temper.h>\n";
	m_code += "\n";

	GenerateTestAssignment();

	GenerateTestArithmetic();

	GenerateTestArray();

	GenerateTestRelational();

	GenerateTestIdentity();

	GenerateTestTranspose();

	GenerateTestInverse();

	GenerateTestDeterminant();

	GenerateTestTranslate();

	GenerateTestRotate();

	GenerateTestScale();

	GenerateTestOrtho();

	GenerateTestPerspective();

	GenerateTestLookAt();

	m_code += "TEMPER_SUITE( " + m_testPrefix + " ) {\n";
	m_code += "\tTEMPER_RUN_TEST( TestAssignment_" + m_fullTypeName + " );\n";
	if ( m_type != GEN_TYPE_BOOL ) {
		m_code += "\n";
		m_code += "\tTEMPER_RUN_TEST( TestArithmeticAddition_" + m_fullTypeName + " );\n";
		m_code += "\tTEMPER_RUN_TEST( TestArithmeticSubtraction_" + m_fullTypeName + " );\n";
		m_code += "\tTEMPER_SKIP_TEST( TestArithmeticMultiplication_" + m_fullTypeName + ", \"Give me a minute to think about how to structure this one.\" );\n";
		m_code += "\tTEMPER_RUN_TEST( TestArithmeticDivision_" + m_fullTypeName + " );\n";
		m_code += "\n";
	}
	m_code += "\tTEMPER_RUN_TEST( TestArray_" + m_fullTypeName + " );\n";
	if ( m_type != GEN_TYPE_BOOL ) {
		m_code += "\tTEMPER_SKIP_TEST( TestRelational_" + m_fullTypeName + ", \"TODO\" );\n";
	}
	m_code += "\n";
	m_code += "\tTEMPER_RUN_TEST( TestIdentity_" + m_fullTypeName + " );\n";
	m_code += "\tTEMPER_RUN_TEST( TestTranspose_" + m_fullTypeName + " );\n";
	if ( Gen_IsFloatingPointType( type ) ) {
		m_code += "\tTEMPER_SKIP_TEST( TestInverse_" + m_fullTypeName + ", \"TODO\" );\n";
	}
	if ( m_type != GEN_TYPE_BOOL ) {
		m_code += "\tTEMPER_SKIP_TEST( TestDeterminant_" + m_fullTypeName + ", \"TODO\" );\n";
		m_code += "\n";
		m_code += "\tTEMPER_SKIP_TEST( TestTranslate_" + m_fullTypeName + ", \"TODO\" );\n";
		m_code += "\tTEMPER_SKIP_TEST( TestRotate_" + m_fullTypeName + ", \"TODO\" );\n";
		m_code += "\tTEMPER_SKIP_TEST( TestScale_" + m_fullTypeName + ", \"TODO\" );\n";
		m_code += "\n";
		m_code += "\tTEMPER_SKIP_TEST( TestOrtho_" + m_fullTypeName + ", \"TODO\" );\n";
		m_code += "\tTEMPER_SKIP_TEST( TestPerspective_" + m_fullTypeName + ", \"TODO\" );\n";
		m_code += "\tTEMPER_SKIP_TEST( TestLookAt_" + m_fullTypeName + ", \"TODO\" );\n";
	}
	m_code += "};\n";

	char filename[1024] = { 0 };
	snprintf( filename, 1024, "%stest_%s.cpp", GEN_TESTS_FOLDER_PATH, m_fullTypeName.c_str() );

	if ( !FS_WriteToFile( filename, m_code.c_str(), m_code.size() ) ) {
		printf( "Can't generate test suite for %s.  That's rough man.\n", m_fullTypeName.c_str() );
	}
}

void TestsGeneratorMatrix::GenerateTestAssignment() {
	std::string zeroStr = Gen_GetNumericLiteral( m_type, 0 );
	std::string fillValue = Gen_GetNumericLiteral( m_type, 999 );

	std::string paramListRows = "(\n";
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		paramListRows += "\t\t" + m_vectorTypeString + "( ";

		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			uint32_t index = col + ( row * m_numCols );

			paramListRows += std::to_string( index );

			if ( col != m_numCols - 1 ) {
				paramListRows += ", ";
			}
		}

		paramListRows += " )";

		if ( row != m_numRows - 1 ) {
			paramListRows += ",";
		}

		paramListRows += "\n";
	}
	paramListRows += "\t)";

	std::string paramListReversed = "(\n";
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		paramListReversed += "\t\t";

		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			uint32_t index = col + ( row * m_numCols );

			paramListReversed += std::to_string( ( m_numRows * m_numCols ) - index );

			if ( row + col != ( m_numRows - 1 ) + ( m_numCols - 1 ) ) {
				paramListReversed += ", ";
			}
		}

		paramListReversed += "\n";
	}
	paramListReversed += "\t)";

	m_code += "TEMPER_TEST( TestAssignment_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " mat;\n";
	m_code += "\n";

	m_code += "\t// fill single value\n";
	m_code += "\tmat = " + m_fullTypeName + "( " + fillValue + " );\n";
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		m_code += "\tTEMPER_EXPECT_TRUE( mat[" + std::to_string( row ) + "] == " + m_vectorTypeString + "( ";

		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			m_code += ( row == col ) ? fillValue : zeroStr;

			if ( col != m_numCols - 1 ) {
				m_code += ", ";
			}
		}
		m_code += " ) );\n";
	}
	m_code += "\n";

	m_code += "\t// row filling\n";
	m_code += "\tmat = " + m_fullTypeName + paramListRows + ";\n";
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		m_code += "\tTEMPER_EXPECT_TRUE( mat[" + std::to_string( row ) + "] == " + m_vectorTypeString + "( ";

		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			uint32_t index = col + ( row * m_numCols );

			m_code += std::to_string( index );

			if ( col != m_numCols - 1 ) {
				m_code += ", ";
			}
		}
		m_code += " ) );\n";
	}
	m_code += "\n";

	m_code += "\t// all values filled\n";
	m_code += "\tmat = " + m_fullTypeName + paramListReversed + ";\n";
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		m_code += "\tTEMPER_EXPECT_TRUE( mat[" + std::to_string( row ) + "] == " + m_vectorTypeString + "( ";

		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			uint32_t index = col + ( row * m_numCols );

			m_code += std::to_string( ( m_numRows * m_numCols ) - index );

			if ( col != m_numCols - 1 ) {
				m_code += ", ";
			}
		}
		m_code += " ) );\n";
	}
	m_code += "\n";

	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestArithmetic() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	uint32_t lhs[4][4] = {
		{ 6, 6, 6, 6 },
		{ 6, 6, 6, 6 },
		{ 6, 6, 6, 6 },
		{ 6, 6, 6, 6 },
	};

	uint32_t rhs[4][4] = {
		{ 2,  3,  4,  4  },
		{ 6,  6,  8,  8  },
		{ 10, 10, 12, 12 },
		{ 18, 18, 24, 24 },
	};

#if 0
	uint32_t m2x2[2][2] = {

	};

	uint32_t m2x3[2][3] = {

	};

	uint32_t m3x2[3][2] = {

	};

	uint32_t m3x4[3][4] = {

	};

	uint32_t m4x3[4][3] = {

	};

	uint32_t m4x4[4][4] = {

	};
#endif

	std::string paramListLHS = "(\n";
	for ( uint32_t col = 0; col < m_numCols; col++ ) {
		paramListLHS += "\t\t";

		for ( uint32_t row = 0; row < m_numRows; row++ ) {
			paramListLHS += Gen_GetNumericLiteral( m_type, lhs[row][col] );

			if ( row + col != ( m_numRows - 1 ) + ( m_numCols - 1 ) ) {
				paramListLHS += ",";
			}

			if ( col != m_numCols - 1 ) {
				paramListLHS += " ";
			}
		}

		paramListLHS += "\n";
	}
	paramListLHS += "\t)";

	std::string paramListVarying = "(\n";
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		paramListVarying += "\t\t";

		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			paramListVarying += Gen_GetNumericLiteral( m_type, rhs[row][col] );

			if ( row + col != ( m_numRows - 1 ) + ( m_numCols - 1 ) ) {
				paramListVarying += ",";
			}

			if ( col != m_numCols - 1 ) {
				paramListVarying += " ";
			}
		}

		paramListVarying += "\n";
	}
	paramListVarying += "\t)";

	std::string paramListIdentity = GetParamListIdentity();

	std::vector<std::string> paramListAnswers( GEN_ARITHMETIC_OP_COUNT );

	// addition
	{
		std::string paramList = "(\n";
		for ( uint32_t row = 0; row < m_numRows; row++ ) {
			paramList += "\t\t";

			for ( uint32_t col = 0; col < m_numCols; col++ ) {
				paramList += Gen_GetNumericLiteral( m_type, lhs[row][col] + rhs[row][col] );

				if ( row + col != ( m_numRows - 1 ) + ( m_numCols - 1 ) ) {
					paramList += ",";
				}

				if ( col != m_numCols - 1 ) {
					paramList += " ";
				}
			}

			paramList += "\n";
		}
		paramList += "\t)";

		paramListAnswers[GEN_ARITHMETIC_OP_ADDITION] = paramList;
	}

	// subtraction
	{
		std::string paramList = "(\n";
		for ( uint32_t row = 0; row < m_numRows; row++ ) {
			paramList += "\t\t";

			for ( uint32_t col = 0; col < m_numCols; col++ ) {
				paramList += Gen_GetNumericLiteral( m_type, lhs[row][col] - rhs[row][col] );

				if ( row + col != ( m_numRows - 1 ) + ( m_numCols - 1 ) ) {
					paramList += ",";
				}

				if ( col != m_numCols - 1 ) {
					paramList += " ";
				}
			}

			paramList += "\n";
		}
		paramList += "\t)";

		paramListAnswers[GEN_ARITHMETIC_OP_SUBTRACTION] = paramList;
	}

	// multiplication
	{
		std::string paramList = "(\n";
		for ( uint32_t row = 0; row < m_numRows; row++ ) {
			paramList += "\t\t";

			for ( uint32_t col = 0; col < m_numCols; col++ ) {
				// DM!!! wrong!
				int32_t matrixValue = row + col;

				paramList += Gen_GetNumericLiteral( m_type, matrixValue );

				if ( row + col != ( m_numRows - 1 ) + ( m_numCols - 1 ) ) {
					paramList += ",";
				}

				if ( col != m_numCols - 1 ) {
					paramList += " ";
				}
			}

			paramList += "\n";
		}
		paramList += "\t)";

		paramListAnswers[GEN_ARITHMETIC_OP_MULTIPLICATION] = paramList;
	}

	// division
	{
		std::string paramList = "(\n";
		
		for ( uint32_t row = 0; row < m_numRows; row++ ) {
			paramList += "\t\t";

			for ( uint32_t col = 0; col < m_numCols; col++ ) {
				// TODO(DM): find a better way of representing this
				if ( Gen_IsFloatingPointType( m_type ) ) {
					float value = static_cast<float>( lhs[row][col] ) / static_cast<float>( rhs[row][col] );

					if ( m_type == GEN_TYPE_FLOAT ) {
						paramList += std::to_string( value ) + "f";
					} else {
						paramList += std::to_string( value );
					}
				} else {
					paramList += Gen_GetNumericLiteral( m_type, lhs[row][col] / rhs[row][col] );
				}

				if ( row + col != ( m_numRows - 1 ) + ( m_numCols - 1 ) ) {
					paramList += ",";
				}

				if ( col != m_numCols - 1 ) {
					paramList += " ";
				}
			}

			paramList += "\n";
		}
		paramList += "\t)";

		paramListAnswers[GEN_ARITHMETIC_OP_DIVISION] = paramList;
	}

	std::vector<std::string> testSuffices = {
		"Addition",
		"Subtraction",
		"Multiplication",
		"Division",
	};

	// handle division separately
	std::string operators[] = {
		"+",
		"-",
		"*",
	};

	for ( uint32_t operatorIndex = 0; operatorIndex < _countof( operators ); operatorIndex++ ) {
		m_code += "TEMPER_TEST( TestArithmetic" + testSuffices[operatorIndex] + "_" + m_fullTypeName + " ) {\n";
		m_code += "\t" + m_fullTypeName + " a = " + m_fullTypeName + paramListLHS + ";\n";
		m_code += "\t" + m_fullTypeName + " b = " + m_fullTypeName + paramListVarying + ";\n";
		m_code += "\t" + m_fullTypeName + " c = a " + GEN_OPERATORS_ARITHMETIC[operatorIndex] + " b;\n";
		m_code += "\n";
		m_code += "\tTEMPER_EXPECT_TRUE( c == " + m_fullTypeName + paramListAnswers[operatorIndex] + " );\n";
		m_code += "\n";
		m_code += "\tTEMPER_PASS();\n";
		m_code += "}\n";

		m_code += "\n";
	}

	// if matrix is square then division is multiplication of inverse, so test that equals identity
	// if matrix is non-square then division is just component-wise division
	m_code += "TEMPER_TEST( TestArithmeticDivision_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " a = " + m_fullTypeName + paramListVarying + ";\n";
	if ( m_numRows == m_numCols && Gen_IsFloatingPointType( m_type ) ) {
		m_code += "\t" + m_fullTypeName + " b = a / a;\n";
		m_code += "\t" + m_fullTypeName + " identity = " + m_fullTypeName + paramListIdentity + ";\n";
		m_code += "\n";
		m_code += "\tTEMPER_EXPECT_TRUE( b == identity );\n";
	} else {
		m_code += "\t" + m_fullTypeName + " b = " + m_fullTypeName + paramListLHS + ";\n";
		m_code += "\t" + m_fullTypeName + " c = b / a;\n";
		m_code += "\n";
		m_code += "\tTEMPER_EXPECT_TRUE( c == " + m_fullTypeName + paramListAnswers[GEN_ARITHMETIC_OP_DIVISION] + " );\n";
	}
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";

	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestArray() {
	std::string zeroStr = Gen_GetNumericLiteral( m_type, 0 );
	std::string oneStr = Gen_GetNumericLiteral( m_type, 1 );

	m_code += "TEMPER_TEST( TestArray_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " mat;\n";
	m_code += "\n";
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		m_code += "\tTEMPER_EXPECT_TRUE( mat[" + std::to_string( row ) + "] == " + m_vectorTypeString + "( ";

		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			m_code += ( row == col ) ? oneStr : zeroStr;

			if ( col != m_numCols - 1 ) {
				m_code += ", ";
			}
		}

		m_code += " ) );\n";
	}
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestRelational() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestRelational_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestIdentity() {
	std::string zeroStr = Gen_GetNumericLiteral( m_type, 0 );
	std::string oneStr = Gen_GetNumericLiteral( m_type, 1 );

	std::string paramListIdentity = GetParamListIdentity();

	m_code += "TEMPER_TEST( TestIdentity_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " id = " + m_fullTypeName + paramListIdentity + ";\n";
	m_code += "\n";
	m_code += "\t" + m_fullTypeName + " mat;\n";
	m_code += "\tTEMPER_EXPECT_TRUE( mat == id );\n";
	m_code += "\n";
	m_code += "\tidentity( mat );\n";
	m_code += "\tTEMPER_EXPECT_TRUE( mat == id );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestTranspose() {
	std::string paramListNormal = "(\n";
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		paramListNormal += "\t\t";

		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			int32_t index = col + ( row * m_numCols );

			paramListNormal += Gen_GetNumericLiteral( m_type, index );

			if ( row + col != ( m_numRows - 1 ) + ( m_numCols - 1 ) ) {
				paramListNormal += ",";
			}

			if ( col != m_numCols - 1 ) {
				paramListNormal += " ";
			}
		}

		paramListNormal += "\n";
	}
	paramListNormal += "\t)";

	std::string paramListTransposed = "(\n";
	for ( uint32_t col = 0; col < m_numCols; col++ ) {
		paramListTransposed += "\t\t";

		for ( uint32_t row = 0; row < m_numRows; row++ ) {
//			int32_t index = row + ( col * m_numRows );
			int32_t index = col + ( row * m_numCols );

			paramListTransposed += Gen_GetNumericLiteral( m_type, index );

			if ( row + col != ( m_numRows - 1 ) + ( m_numCols - 1 ) ) {
				paramListTransposed += ",";
			}

			if ( row != m_numRows - 1 ) {
				paramListTransposed += " ";
			}
		}

		paramListTransposed += "\n";
	}
	paramListTransposed += "\t)";

	std::string transposeTypeName = m_typeString + std::to_string( m_numCols ) + "x" + std::to_string( m_numRows );

	m_code += "TEMPER_TEST( TestTranspose_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " mat = " + m_fullTypeName + paramListNormal + ";\n";
	m_code += "\t" + transposeTypeName + " trans = transpose( mat );\n";
	m_code += "\n";
	m_code += "\tTEMPER_EXPECT_TRUE( trans == " + transposeTypeName + paramListTransposed + " );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestInverse() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestInverse_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestDeterminant() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestDeterminant_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestTranslate() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestTranslate_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestRotate() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestRotate_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestScale() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestScale_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestOrtho() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestOrtho_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestPerspective() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestPerspective_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestLookAt() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestLookAt_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

std::string TestsGeneratorMatrix::GetParamListIdentity() const {
	std::string zeroStr = Gen_GetNumericLiteral( m_type, 0 );
	std::string oneStr = Gen_GetNumericLiteral( m_type, 1 );

	std::string paramListIdentity = "(\n";
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		paramListIdentity += "\t\t";

		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			paramListIdentity += ( row == col ) ? oneStr : zeroStr;

			if ( row + col != ( m_numRows - 1 ) + ( m_numCols - 1 ) ) {
				paramListIdentity += ",";
			}

			if ( col != m_numCols - 1 ) {
				paramListIdentity += " ";
			}
		}

		paramListIdentity += "\n";
	}
	paramListIdentity += "\t)";

	return paramListIdentity;
}