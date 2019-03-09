#include "TestsGeneratorMatrix.h"

#include "FileIO.h"

#include "../out/hlml_main.h"

#include <assert.h>

void TestsGeneratorMatrix::Generate( const genType_t type, const uint32_t numRows, const uint32_t numCols ) {
	m_code = std::string();

	m_type = type;

	m_numRows = numRows;
	m_numCols = numCols;

	m_numRowsStr = std::to_string( numRows );
	m_numColsStr = std::to_string( numCols );

	m_typeString = Gen_GetTypeString( type );
	m_memberTypeString = Gen_GetMemberTypeString( type );

	m_vectorTypeString = m_typeString + std::to_string( numCols );
	m_fullTypeName = m_typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	m_testPrefix = "Test_" + m_fullTypeName;

	m_code += GEN_FILE_HEADER;

	m_code += std::string( "#include \"../" ) + GEN_OUT_GEN_FOLDER_PATH + GEN_FILENAME_FUNCTIONS_MATRIX + ".h\"\n";
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
//		m_code += "\tTEMPER_RUN_TEST( TestArithmeticAddition_" + m_fullTypeName + " );\n";
//		m_code += "\tTEMPER_RUN_TEST( TestArithmeticSubtraction_" + m_fullTypeName + " );\n";
//		m_code += "\tTEMPER_SKIP_TEST( TestArithmeticMultiplication_" + m_fullTypeName + ", \"Give me a minute to think about how to structure this one.\" );\n";
//		m_code += "\tTEMPER_RUN_TEST( TestArithmeticDivision_" + m_fullTypeName + " );\n";
		m_code += "\n";
	}

	m_code += "\tTEMPER_RUN_TEST( TestArray_" + m_fullTypeName + " );\n";

	if ( m_type != GEN_TYPE_BOOL ) {
		m_code += "\tTEMPER_RUN_TEST( TestRelational_" + m_fullTypeName + " );\n";
	}

	m_code += "\n";
	m_code += "\tTEMPER_RUN_TEST( TestIdentity_" + m_fullTypeName + " );\n";
	m_code += "\tTEMPER_RUN_TEST( TestTranspose_" + m_fullTypeName + " );\n";

	if ( ( m_type != GEN_TYPE_BOOL && m_type != GEN_TYPE_UINT ) && m_numRows == m_numCols ) {
		m_code += "\tTEMPER_RUN_TEST( TestDeterminant_" + m_fullTypeName + " );\n";
	}

	if ( Gen_IsFloatingPointType( type ) && m_numRows == m_numCols ) {
		m_code += "\tTEMPER_RUN_TEST( TestInverse_" + m_fullTypeName + " );\n";
	}

	if ( m_type != GEN_TYPE_BOOL ) {
		m_code += "\n";

		if ( m_numRows >= 3 && m_numCols >= m_numRows ) {
			m_code += "\tTEMPER_RUN_TEST( TestTranslate_" + m_fullTypeName + " );\n";

			if ( Gen_IsFloatingPointType( m_type ) && m_numRows == m_numCols ) {
				m_code += "\tTEMPER_RUN_TEST( TestRotate_" + m_fullTypeName + " );\n";
			}

			m_code += "\tTEMPER_RUN_TEST( TestScale_" + m_fullTypeName + " );\n";
		}

		m_code += "\n";
		if ( Gen_IsFloatingPointType( m_type ) && ( m_numRows >= 4 && m_numCols >= 4 ) ) {
			m_code += "\tTEMPER_RUN_TEST( TestOrtho_" + m_fullTypeName + " );\n";
			m_code += "\tTEMPER_RUN_TEST( TestPerspective_" + m_fullTypeName + " );\n";
			m_code += "\tTEMPER_RUN_TEST( TestLookAt_" + m_fullTypeName + " );\n";
		}
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

	int32_t lhs[4][4] = {
		{ 6, 6, 6, 6 },
		{ 6, 6, 6, 6 },
		{ 6, 6, 6, 6 },
		{ 6, 6, 6, 6 },
	};

	int32_t rhs[4][4] = {
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

	std::string paramListIdentity = GetParmListIdentity();

	std::string paramListAnswers[GEN_OP_ARITHMETIC_COUNT];

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

		paramListAnswers[GEN_OP_ARITHMETIC_ADD] = paramList;
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

		paramListAnswers[GEN_OP_ARITHMETIC_SUB] = paramList;
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

		paramListAnswers[GEN_OP_ARITHMETIC_MUL] = paramList;
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

		paramListAnswers[GEN_OP_ARITHMETIC_DIV] = paramList;
	}

	std::string testSuffices[] = {
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

	// TODO(DM): I don't know how I want to structure these tests yet given the differences between each test
//	for ( uint32_t operatorIndex = 0; operatorIndex < _countof( operators ); operatorIndex++ ) {
//		m_code += "TEMPER_TEST( TestArithmetic" + testSuffices[operatorIndex] + "_" + m_fullTypeName + " ) {\n";
//		m_code += "\t" + m_fullTypeName + " a = " + m_fullTypeName + paramListLHS + ";\n";
//		m_code += "\t" + m_fullTypeName + " b = " + m_fullTypeName + paramListVarying + ";\n";
//		m_code += "\t" + m_fullTypeName + " c = a " + GEN_OPERATORS_ARITHMETIC[operatorIndex] + " b;\n";
//		m_code += "\n";
//		m_code += "\tTEMPER_EXPECT_TRUE( c == " + m_fullTypeName + paramListAnswers[operatorIndex] + " );\n";
//		m_code += "\n";
//		m_code += "\tTEMPER_PASS();\n";
//		m_code += "}\n";
//
//		m_code += "\n";
//	}

	// if matrix is square then division is multiplication of inverse, so test that equals identity
	// if matrix is non-square then division is just component-wise division
//	m_code += "TEMPER_TEST( TestArithmeticDivision_" + m_fullTypeName + " ) {\n";
//	m_code += "\t" + m_fullTypeName + " a = " + m_fullTypeName + paramListVarying + ";\n";
//	if ( m_numRows == m_numCols && Gen_IsFloatingPointType( m_type ) ) {
//		m_code += "\t" + m_fullTypeName + " b = a / a;\n";
//		m_code += "\t" + m_fullTypeName + " identity = " + m_fullTypeName + paramListIdentity + ";\n";
//		m_code += "\n";
//		m_code += "\tTEMPER_EXPECT_TRUE( b == identity );\n";
//	} else {
//		m_code += "\t" + m_fullTypeName + " b = " + m_fullTypeName + paramListLHS + ";\n";
//		m_code += "\t" + m_fullTypeName + " c = b / a;\n";
//		m_code += "\n";
//		m_code += "\tTEMPER_EXPECT_TRUE( c == " + m_fullTypeName + paramListAnswers[GEN_OP_ARITHMETIC_DIV] + " );\n";
//	}
//	m_code += "\n";
//	m_code += "\tTEMPER_PASS();\n";
//	m_code += "}\n";
//
//	m_code += "\n";
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

	std::string boolTypeName = "bool" + m_numRowsStr + "x" + m_numColsStr;

	std::string paramListTrue = GetParmListSingleValue( GEN_TYPE_BOOL, true );

	std::string parmLists[] = {
		GetParmListSingleValue( m_type, 1 ),
		GetParmListSingleValue( m_type, 2 ),
		GetParmListSingleValue( m_type, 3 ),
		GetParmListSingleValue( m_type, 4 ),
	};

	uint32_t numTestMats = 0;

	m_code += "TEMPER_TEST( TestRelational_" + m_fullTypeName + " ) {\n";
	for ( uint32_t parmListIndex = 0; parmListIndex < _countof( parmLists ); parmListIndex++ ) {
		m_code += "\t" + m_fullTypeName + " mat" + std::to_string( parmListIndex ) + " = " + m_fullTypeName + parmLists[parmListIndex] + ";\n";
	}
	m_code += "\n";
	for ( uint32_t parmListIndex = 0; parmListIndex < _countof( parmLists ); parmListIndex++ ) {
		std::string matString = "mat" + std::to_string( parmListIndex );

		m_code += "\t" + boolTypeName + " test" + std::to_string( numTestMats++ ) + " = " + matString + " <= " + matString + ";\n";
		m_code += "\t" + boolTypeName + " test" + std::to_string( numTestMats++ ) + " = " + matString + " >= " + matString + ";\n";
		if ( parmListIndex != _countof( parmLists ) - 1 ) {
			m_code += "\t" + boolTypeName + " test" + std::to_string( numTestMats++ ) + " = " + matString + " < mat" + std::to_string( parmListIndex + 1 ) + ";\n";
		}
		if ( parmListIndex > 0 ) {
			m_code += "\t" + boolTypeName + " test" + std::to_string( numTestMats++ ) + " = " + matString + " > mat" + std::to_string( parmListIndex - 1 ) + ";\n";
		}
		m_code += "\n";
	}
	for ( uint32_t i = 0; i < numTestMats; i++ ) {
		m_code += "\tTEMPER_EXPECT_TRUE( test" + std::to_string( i ) + " == " + boolTypeName + paramListTrue + " );\n";
		m_code += "\n";
	}
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestIdentity() {
	std::string zeroStr = Gen_GetNumericLiteral( m_type, 0 );
	std::string oneStr = Gen_GetNumericLiteral( m_type, 1 );

	std::string paramListIdentity = GetParmListIdentity();

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

	std::string transposeTypeName = m_typeString + m_numColsStr + "x" + m_numRowsStr;

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
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	if ( m_numRows != m_numCols ) {
		return;
	}

	// matrices chosen because they gave nice whole numbers for determinants
	int32_t mat2x2[4] {
		6, 2,
		2, 6
	};

	int32_t mat3x3[9] {
		6, 2, 3,
		2, 7, 2,
		3, 2, 6
	};

	int32_t mat4x4[16] {
		6, 2, 3, 4,
		2, 7, 5, 3,
		3, 5, 7, 2,
		4, 3, 2, 6
	};

	const int32_t* matrix = nullptr;
	switch ( m_numRows ) {
		case 2: matrix = mat2x2; break;
		case 3: matrix = mat3x3; break;
		case 4: matrix = mat4x4; break;
	}

	std::string paramList = "(\n";
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		paramList += "\t\t";

		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			uint32_t index = col + ( row * m_numCols );

			paramList += Gen_GetNumericLiteral( m_type, matrix[index] );

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

	m_code += "TEMPER_TEST( TestInverse_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " identityMatrix;\n";
	m_code += "\n";
	m_code += "\t" + m_fullTypeName + " mat = " + m_fullTypeName + paramList + ";\n";
	m_code += "\t" + m_fullTypeName + " matInverse = inverse( mat );\n";
	m_code += "\n";
	m_code += "\tTEMPER_EXPECT_TRUE( mat * matInverse == identityMatrix );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestDeterminant() {
	if ( m_type == GEN_TYPE_BOOL || m_type == GEN_TYPE_UINT ) {
		return;
	}

	if ( m_numRows != m_numCols ) {
		return;
	}

	// matrices chosen because they gave nice whole numbers for determinants
	int32_t mat2x2[4] {
		6, 2,
		2, 6
	};

	int32_t mat3x3[9] {
		6, 2, 3,
		2, 7, 2,
		3, 2, 6
	};

	int32_t mat4x4[16] {
		6, 2, 3, 4,
		2, 7, 5, 3,
		3, 5, 7, 2,
		4, 3, 2, 6
	};

	int32_t determinants[3] = {
		32,		// 2x2
		165,	// 3x3
		285		// 4x4
	};

	const int32_t* matrix = nullptr;
	switch ( m_numRows ) {
		case 2: matrix = mat2x2; break;
		case 3: matrix = mat3x3; break;
		case 4: matrix = mat4x4; break;
	}

	std::string paramList = "(\n";
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		paramList += "\t\t";

		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			uint32_t index = col + ( row * m_numCols );

			paramList += Gen_GetNumericLiteral( m_type, matrix[index] );

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

	std::string answerStr = Gen_GetNumericLiteral( m_type, determinants[m_numRows - 2] );

	m_code += "TEMPER_TEST( TestDeterminant_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " mat = " + m_fullTypeName + paramList + ";\n";
	m_code += "\t" + m_memberTypeString + " det = determinant( mat );\n";
	m_code += "\n";
	if ( Gen_IsFloatingPointType( m_type ) ) {
		m_code += "\tTEMPER_EXPECT_TRUE( floateq( det, " + answerStr + " ) );\n";
	} else {
		m_code += "\tTEMPER_EXPECT_TRUE( det == " + answerStr + " );\n";
	}
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestTranslate() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( m_numRows < 3 || m_numCols < m_numRows ) {
		return;
	}

	uint32_t baseNumber = 2;

	std::string translateVectorTypeString = m_typeString + std::to_string( m_numCols - 1 );

	std::string zeroStr = Gen_GetNumericLiteral( m_type, 0 );
	std::string oneStr = Gen_GetNumericLiteral( m_type, 1 );

	std::string parmListTranslateVector = "( ";
	for ( uint32_t col = 0; col < m_numCols - 1; col++ ) {
		parmListTranslateVector += Gen_GetNumericLiteral( m_type, col + baseNumber );

		if ( col != m_numCols - 2 ) {
			parmListTranslateVector += ", ";
		}
	}
	parmListTranslateVector += " )";

	std::string parmListTranslated = "(\n";
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		parmListTranslated += "\t\t";

		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			if ( row == col ) {
				parmListTranslated += oneStr;
			} else {
				if ( col == m_numCols - 1 ) {
					parmListTranslated += Gen_GetNumericLiteral( m_type, row + baseNumber );
				} else {
					parmListTranslated += zeroStr;
				}
			}

			if ( row + col != ( m_numRows - 1 ) + ( m_numCols - 1 ) ) {
				parmListTranslated += ",";
			}

			if ( col != m_numCols - 1 ) {
				parmListTranslated += " ";
			}
		}

		parmListTranslated += "\n";
	}
	parmListTranslated += "\t)";

	m_code += "TEMPER_TEST( TestTranslate_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " mat;\n";
	m_code += "\t" + m_fullTypeName + " translated = " + m_fullTypeName + parmListTranslated + ";\n";
	m_code += "\n";
	m_code += "\t" + translateVectorTypeString + " translation = " + translateVectorTypeString + parmListTranslateVector + ";\n";
	m_code += "\tmat = translate( mat, translation );\n";
	m_code += "\n";
	m_code += "\tTEMPER_EXPECT_TRUE( mat == translated );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestRotate() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	if ( m_numRows < 3 ) {
		return;
	}

	if ( m_numRows != m_numCols ) {
		return;
	}

	float rotDegrees = 45.0f;
	float rotRadians = radiansf( rotDegrees );

	float cosR = cosf( rotRadians );
	float sinR = sinf( rotRadians );

	float angleAxisVecYaw[3] = {
		0.0f, 1.0f, 0.0f
	};

	float angleAxisVecPitch[3] = {
		1.0f, 0.0f, 0.0f
	};

	float angleAxisVecRoll[3] = {
		0.0f, 0.0f, 1.0f
	};

	float rotMatYaw[4 * 4] = {
		 cosR, 0.0f, sinR, 0.0f,
		 0.0f, 1.0f, 0.0f, 0.0f,
		-sinR, 0.0f, cosR, 0.0f,
		 0.0f, 0.0f, 0.0f, 1.0f,
	};

	float rotMatPitch[4 * 4] = {
		1.0f, 0.0f,  0.0f, 0.0f,
		0.0f, cosR, -sinR, 0.0f,
		0.0f, sinR,  cosR, 0.0f,
		0.0f, 0.0f,  0.0f, 1.0f,
	};

	float rotMatRoll[4 * 4] = {
		cosR, -sinR, 0.0f, 0.0f,
		sinR,  cosR, 0.0f, 0.0f,
		0.0f,  0.0f, 1.0f, 0.0f,
		0.0f,  0.0f, 0.0f, 1.0f,
	};

	float rotMat3x3[3 * 3] = {
		cosR, -sinR, 0.0f,
		sinR,  cosR, 0.0f,
		0.0f,  0.0f, 1.0f,
	};

	float* matAnswerRoll = ( m_numCols > 3 ) ? rotMatRoll : rotMat3x3;

	uint32_t numRotMatRows = __min( m_numRows, 4 );
	uint32_t numRotMatCols = __min( m_numCols, 4 );

	uint32_t numRotateVectorComponents = m_numCols - 1;

	std::string rotDegreesStr = Gen_GetNumericLiteral( m_type, rotDegrees );

	std::string rotateVecTypeString = m_typeString + std::to_string( numRotateVectorComponents );

	std::string parmListVecYaw = GetParmListVector( m_type, numRotateVectorComponents, angleAxisVecYaw );
	std::string parmListVecPitch = GetParmListVector( m_type, numRotateVectorComponents, angleAxisVecPitch );
	std::string parmListVecRoll = GetParmListVector( m_type, numRotateVectorComponents, angleAxisVecRoll );

	std::string parmListMatYaw = GetParmListMatrix( m_type, numRotMatRows, numRotMatCols, rotMatYaw );
	std::string parmListMatPitch = GetParmListMatrix( m_type, numRotMatRows, numRotMatCols, rotMatPitch );
	std::string parmListMatRoll = GetParmListMatrix( m_type, numRotMatRows, numRotMatCols, matAnswerRoll );

	std::string radiansFuncStr = Gen_GetFuncNameRadians( m_type );

	// matrices where cols == 3 only have roll rotation support
	std::string parmListRotateRoll = "mat, " + radiansFuncStr + "( " + rotDegreesStr + " )";
	if ( m_numCols > 3 ) {
		parmListRotateRoll += ", " + rotateVecTypeString + parmListVecRoll;
	}

	m_code += "TEMPER_TEST( TestRotate_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " mat;\n";
	if ( m_numRows > 3 ) {
		m_code += "\t" + m_fullTypeName + " yaw = rotate( mat, " + radiansFuncStr + "( " + rotDegreesStr + " ), " + rotateVecTypeString + parmListVecYaw + " );\n";
		m_code += "\t" + m_fullTypeName + " pitch = rotate( mat, " + radiansFuncStr + "( " + rotDegreesStr + " ), " + rotateVecTypeString + parmListVecPitch + " );\n";
	}
	m_code += "\t" + m_fullTypeName + " roll = rotate( " + parmListRotateRoll + " );\n";
	m_code += "\n";
	if ( m_numRows > 3 ) {
		m_code += "\t" + m_fullTypeName + " answerYaw = " + m_fullTypeName + parmListMatYaw + ";\n";
		m_code += "\t" + m_fullTypeName + " answerPitch = " + m_fullTypeName + parmListMatPitch + ";\n";
	}
	m_code += "\t" + m_fullTypeName + " answerRoll = " + m_fullTypeName + parmListMatRoll + ";\n";
	m_code += "\n";
	if ( m_numRows > 3 ) {
		m_code += "\tTEMPER_EXPECT_TRUE( yaw == answerYaw );\n";
		m_code += "\tTEMPER_EXPECT_TRUE( pitch == answerPitch );\n";
	}
	m_code += "\tTEMPER_EXPECT_TRUE( roll == answerRoll );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestScale() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( m_numCols < 3 && m_numCols < m_numRows ) {
		return;
	}

	const uint32_t scaleCols = 3;

	float scaleMatDiagonal[] = { 2.0f, 2.0f, 2.0f, 1.0f };

	std::string parmListScaleVec = GetParmListVector( m_type, scaleCols, scaleMatDiagonal );
	std::string parmListScaleMat = GetParmListDiagonal( m_type, m_numRows, m_numCols, scaleMatDiagonal, _countof( scaleMatDiagonal ) );

	std::string scaleVecTypeString = m_typeString + std::to_string( scaleCols );

	m_code += "TEMPER_TEST( TestScale_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " mat;\n";
	m_code += "\t" + m_fullTypeName + " scaled = scale( mat, " + scaleVecTypeString + parmListScaleVec + " );\n";
	m_code += "\n";
	m_code += "\tTEMPER_EXPECT_TRUE( scaled == " + m_fullTypeName + parmListScaleMat + " );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestOrtho() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	if ( m_numRows < 4 || m_numCols < 4 ) {
		return;
	}

	// answer for 1280 x 720, ortho size 5, znear: -1, zfar: 100
	float answerOrtho[] = {
		0.112499997f,  0.0f,         0.0f,           0.0f,
		0.0f,         -0.200000003f, 0.0f,           0.0f,
		0.0f,          0.0f,         0.00990098994f, 0.00990098994f,
		0.0f,          0.0f,         0.0f,           1.0f
	};

	std::string parmListAnswerOrtho = GetParmListMatrix( m_type, 4, 4, answerOrtho );

	std::string minusOneStr = Gen_GetNumericLiteral( m_type, -1.0f );
	std::string oneHundredStr = Gen_GetNumericLiteral( m_type, 100.0f );

	m_code += "TEMPER_TEST( TestOrtho_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " answerOrtho = " + m_fullTypeName + parmListAnswerOrtho + ";\n";
	m_code += "\n";
	m_code += "\t" + m_typeString + " width = " + Gen_GetNumericLiteral( m_type, 1280.0f ) + ";\n";
	m_code += "\t" + m_typeString + " height = " + Gen_GetNumericLiteral( m_type, 720.0f ) + ";\n";
	m_code += "\t" + m_typeString + " aspect = width / height;\n";
	m_code += "\t" + m_typeString + " orthoSize = " + Gen_GetNumericLiteral( m_type, 5.0f ) + ";\n";
	m_code += "\n";
	m_code += "\t" + m_typeString + " left = -aspect * orthoSize;\n";
	m_code += "\t" + m_typeString + " right = aspect * orthoSize;\n";
	m_code += "\t" + m_typeString + " top = -orthoSize;\n";
	m_code += "\t" + m_typeString + " bottom = orthoSize;\n";
	m_code += "\n";
	m_code += "\t" + m_fullTypeName + " mat = ortho( left, right, top, bottom, " + minusOneStr + ", " + oneHundredStr +" );\n";
	m_code += "\n";
	m_code += "\tTEMPER_EXPECT_TRUE( mat == answerOrtho );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestPerspective() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	if ( m_numRows < 4 || m_numCols < 4 ) {
		return;
	}

	// answer for 1280 x 720, fov: 90 degrees, znear: 0.1, zfar: 100
	// clip space: 0 - 1, left handed
	float answerPerspective[] = {
		0.347270f, 0.0f,      0.0f,       0.0f,
		0.0f,      0.617370f, 0.0f,       0.0f,
		0.0f,      0.0f,      1.001001f, -0.100100f,
		0.0f,      0.0f,      1.000000f,  0.0f
	};

	std::string parmListPerspective = GetParmListMatrix( m_type, 4, 4, answerPerspective );

	std::string widthStr = Gen_GetNumericLiteral( m_type, 1280.0f );
	std::string heightStr = Gen_GetNumericLiteral( m_type, 720.0f );
	std::string fovStr = Gen_GetNumericLiteral( m_type, 90.0f );
	std::string znearStr = Gen_GetNumericLiteral( m_type, 0.1f );
	std::string zfarStr = Gen_GetNumericLiteral( m_type, 100.0f );

	m_code += "TEMPER_TEST( TestPerspective_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " answerPerspective = " + m_fullTypeName + parmListPerspective + ";\n";
	m_code += "\n";
	m_code += "\t" + m_typeString + " aspect = " + widthStr + " / " + heightStr + ";\n";
	m_code += "\t" + m_fullTypeName + " mat = perspective( " + fovStr + ", aspect, " + znearStr + ", " + zfarStr + " );\n";
	m_code += "\n";
	m_code += "\tTEMPER_EXPECT_TRUE( mat == answerPerspective );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestLookAt() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	if ( m_numRows < 4 || m_numCols < 4 ) {
		return;
	}

	float currentPos[]	= { 0.0f, 0.0f, 0.0f };
	float targetPos[]	= { 1.0f, 0.0f, 1.0f };
	float up[]			= { 0.0f, 1.0f, 0.0f };

	float answerLookAt[] = {
		0.707107f, 0.0f, -0.707107f, 0.0f,
		0.0f,      1.0f,  0.0f,      0.0f,
		0.707107f, 0.0f,  0.707107f, 0.0f,
		0.0f,      0.0f,  0.0f,      1.0f
	};

	std::string posVectorTypeName = m_typeString + std::to_string( 3 );

	std::string parmListCurrentPos = GetParmListVector( m_type, 3, currentPos );
	std::string parmListTargetPos = GetParmListVector( m_type, 3, targetPos );
	std::string parmListUp = GetParmListVector( m_type, 3, up );

	std::string parmListLookAt = GetParmListMatrix( m_type, 4, 4, answerLookAt );

	m_code += "TEMPER_TEST( TestLookAt_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " answerLookAt = " + m_fullTypeName + parmListLookAt + ";\n";
	m_code += "\n";
	m_code += "\t" + posVectorTypeName + " currentPos = " + posVectorTypeName + parmListCurrentPos + ";\n";
	m_code += "\t" + posVectorTypeName + " targetPos = " + posVectorTypeName + parmListTargetPos + ";\n";
	m_code += "\t" + posVectorTypeName + " up = " + posVectorTypeName + parmListUp + ";\n";
	m_code += "\t" + m_fullTypeName + " mat = lookat( currentPos, targetPos, up );\n";
	m_code += "\n";
	m_code += "\tTEMPER_EXPECT_TRUE( mat == answerLookAt );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

std::string TestsGeneratorMatrix::GetParmListIdentity() const {
	std::string zeroStr = Gen_GetNumericLiteral( m_type, 0.0f );
	std::string oneStr = Gen_GetNumericLiteral( m_type, 1.0f );

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

std::string TestsGeneratorMatrix::GetParmListDiagonal( const genType_t type, const uint32_t numRows, const uint32_t numCols, const float* values, const uint32_t numValues ) const {
	assert( numValues <= 4 );

	std::string zeroStr = Gen_GetNumericLiteral( type, 0.0f );

	uint32_t valueIndex = 0;

	std::string paramList = "(\n";
	for ( uint32_t row = 0; row < numRows; row++ ) {
		paramList += "\t\t";

		for ( uint32_t col = 0; col < numCols; col++ ) {
			if ( row == col ) {
				paramList += Gen_GetNumericLiteral( m_type, values[valueIndex++] );
			} else {
				paramList += zeroStr;
			}

			if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
				paramList += ",";
			}

			if ( col != numCols - 1 ) {
				paramList += " ";
			}
		}

		paramList += "\n";
	}
	paramList += "\t)";

	return paramList;
}

std::string TestsGeneratorMatrix::GetParmListSingleValue( const genType_t type, const int32_t value ) const {
	std::string valueStr = Gen_GetNumericLiteral( type, value );

	std::string paramList = "(\n";
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		paramList += "\t\t";

		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			paramList += valueStr;

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

	return paramList;
}

std::string TestsGeneratorMatrix::GetParmListVector( const genType_t type, const uint32_t numComponents, const float* values ) const {
	std::string parmList = "( ";
	for ( uint32_t i = 0; i < numComponents; i++ ) {
		parmList += Gen_GetNumericLiteral( type, values[i] );

		if ( i != numComponents - 1 ) {
			parmList += ", ";
		}
	}
	parmList += " )";

	return parmList;
}

std::string TestsGeneratorMatrix::GetParmListMatrix( const genType_t type, const uint32_t numRows, const uint32_t numCols, const float* values ) const {
	std::string parmList = "(\n";
	for ( uint32_t row = 0; row < numRows; row++ ) {
		parmList += "\t\t";

		for ( uint32_t col = 0; col < numCols; col++ ) {
			uint32_t index = col + ( row * numCols );

			parmList += Gen_GetNumericLiteral( type, values[index] );

			if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
				parmList += ",";
			}

			if ( col != numCols - 1 ) {
				parmList += " ";
			}
		}

		parmList += "\n";
	}
	parmList += "\t)";

	return parmList;
}