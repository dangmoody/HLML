#include "TestsGeneratorMatrix.h"

#include "FileIO.h"

#include "gen_funcs_vector.h"
#include "gen_funcs_matrix.h"

#include <assert.h>
#include <vector>

#define _USE_MATH_DEFINES
#include <math.h>

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

	m_code += std::string( "#include \"../../" ) + GEN_OUT_GEN_FOLDER_PATH + GEN_FILENAME_FUNCTIONS_MATRIX + ".h\"\n";
	m_code += "\n";

	m_code += "#include <temper/temper.h>\n";
	m_code += "\n";

	GenerateTestAssignment();

	GenerateTestArithmetic();

	GenerateTestMultiplyVector();

	GenerateTestIncrement();

	GenerateTestRelational();

	GenerateTestArray();

	GenerateTestBitwise();

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

	m_code += "TEMPER_SUITE( " + m_testPrefix + " )\n";
	m_code += "{\n";
	m_code += "\tTEMPER_RUN_TEST( TestAssignment_" + m_fullTypeName + " );\n";

	if ( m_type != GEN_TYPE_BOOL ) {
		m_code += "\n";
		m_code += "\tTEMPER_RUN_TEST( TestArithmeticAddition_" + m_fullTypeName + " );\n";
		m_code += "\tTEMPER_RUN_TEST( TestArithmeticSubtraction_" + m_fullTypeName + " );\n";
		m_code += "\tTEMPER_RUN_TEST( TestArithmeticMultiplication_" + m_fullTypeName + " );\n";
		m_code += "\tTEMPER_RUN_TEST( TestArithmeticDivision_" + m_fullTypeName + " );\n";
		m_code += "\n";
		if ( m_numRows == m_numCols ) {
			m_code += "\tTEMPER_RUN_TEST( TestMultiplyVector_" + m_fullTypeName + " );\n";
			m_code += "\n";
		}
		m_code += "\tTEMPER_RUN_TEST( TestIncrement_" + m_fullTypeName + " );\n";
		m_code += "\tTEMPER_RUN_TEST( TestDecrement_" + m_fullTypeName + " );\n";
		m_code += "\n";
		m_code += "\tTEMPER_RUN_TEST( TestRelational_" + m_fullTypeName + " );\n";
		m_code += "\n";

		if ( Gen_IsIntegerType( m_type ) ) {
			m_code += "\tTEMPER_RUN_TEST( TestBitwiseAnd_" + m_fullTypeName + " );\n";
			m_code += "\tTEMPER_RUN_TEST( TestBitwiseOr_" + m_fullTypeName + " );\n";
			m_code += "\tTEMPER_RUN_TEST( TestBitwiseXor_" + m_fullTypeName + " );\n";
			m_code += "\tTEMPER_RUN_TEST( TestBitwiseUnary_" + m_fullTypeName + " );\n";
			m_code += "\tTEMPER_RUN_TEST( TestBitwiseShiftLeft_" + m_fullTypeName + " );\n";
			m_code += "\tTEMPER_RUN_TEST( TestBitwiseShiftRight_" + m_fullTypeName + " );\n";
		}
	}

	m_code += "\tTEMPER_RUN_TEST( TestArray_" + m_fullTypeName + " );\n";

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

	m_code += "TEMPER_TEST( TestAssignment_" + m_fullTypeName + " )\n";
	m_code += "{\n";
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

	float valuesLhs[4][4] = {
		{ 6.0f,  6.0f,  6.0f,  6.0f  },
		{ 6.0f,  6.0f,  6.0f,  6.0f  },
		{ 12.0f, 12.0f, 12.0f, 12.0f },
		{ 18.0f, 18.0f, 18.0f, 18.0f }
	};

	float valuesRhs[4][4] = {
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 2.0f, 2.0f, 2.0f, 2.0f },
		{ 3.0f, 3.0f, 3.0f, 3.0f },
		{ 6.0f, 6.0f, 6.0f, 6.0f }
	};

	float valuesDiv[4][4] = {
		{ 6.0f, 2.0f, 3.0f, 4.0f },
		{ 2.0f, 7.0f, 5.0f, 3.0f },
		{ 3.0f, 5.0f, 7.0f, 2.0f },
		{ 4.0f, 3.0f, 2.0f, 6.0f }
	};

	std::string suffices[] = {
		"Addition",
		"Subtraction",
		"Multiplication",
		"Division",
	};

	m_code += "TEMPER_TEST( TestArithmetic" + suffices[GEN_OP_ARITHMETIC_ADD] + "_" + m_fullTypeName + " )\n";
	m_code += "{\n";
	m_code += GetTestCodeArithmeticInternal( GEN_OP_ARITHMETIC_ADD, valuesLhs, valuesRhs );
	m_code += "}\n";
	m_code += "\n";

	m_code += "TEMPER_TEST( TestArithmetic" + suffices[GEN_OP_ARITHMETIC_SUB] + "_" + m_fullTypeName + " )\n";
	m_code += "{\n";
	m_code += GetTestCodeArithmeticInternal( GEN_OP_ARITHMETIC_SUB, valuesLhs, valuesRhs );
	m_code += "}\n";
	m_code += "\n";

	m_code += "TEMPER_TEST( TestArithmetic" + suffices[GEN_OP_ARITHMETIC_MUL] + "_" + m_fullTypeName + " )\n";
	m_code += "{\n";
	m_code += GetTestCodeArithmeticInternal( GEN_OP_ARITHMETIC_MUL, valuesLhs, valuesRhs );
	m_code += "}\n";
	m_code += "\n";

	// for division use different matrices that are invertible
	m_code += "TEMPER_TEST( TestArithmetic" + suffices[GEN_OP_ARITHMETIC_DIV] + "_" + m_fullTypeName + " )\n";
	m_code += "{\n";
	if ( m_numRows == m_numCols && Gen_IsFloatingPointType( m_type ) ) {
		m_code += GetTestCodeArithmeticInternal( GEN_OP_ARITHMETIC_DIV, valuesDiv, valuesDiv );
	} else {
		m_code += GetTestCodeArithmeticInternal( GEN_OP_ARITHMETIC_DIV, valuesLhs, valuesRhs );
	}
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestMultiplyVector() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( m_numRows != m_numCols ) {
		return;
	}

	float valuesMat[4][4] = {
		{ 1.0f,  2.0f,  3.0f,  4.0f  },
		{ 5.0f,  6.0f,  7.0f,  8.0f  },
		{ 9.0f,  10.0f, 11.0f, 12.0f },
		{ 13.0f, 14.0f, 15.0f, 16.0f }
	};

	float valuesVec[4] = {
		2.0f, 1.0f, 4.0f, 3.0f
	};

	std::string vectorTypeName = m_typeString + m_numColsStr;

	std::string parmListMat = Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, valuesMat );
	std::string parmListVec = Gen_GetParmListVector( m_type, m_numCols, valuesVec );

	std::string parmListVecAnswer = "( ";
	for ( uint32_t col = 0; col < m_numCols; col++ ) {
		// get the left-hand row
		std::vector<float> matRow( m_numCols );
		for ( size_t lhsComponent = 0; lhsComponent < matRow.size(); lhsComponent++ ) {
			matRow[lhsComponent] = valuesMat[col][lhsComponent];
		}

		// do the dot product procedurally
		std::vector<float> dots( m_numCols );
		for ( size_t i = 0; i < dots.size(); i++ ) {
			dots[i] = matRow[i] * valuesVec[i];
		}

		float dot = 0.0f;
		for ( size_t i = 0; i < dots.size(); i++ ) {
			dot += dots[i];
		}

		parmListVecAnswer += Gen_GetNumericLiteral( m_type, dot );

		if ( col != ( m_numCols - 1 ) ) {
			parmListVecAnswer += ", ";
		}
	}
	parmListVecAnswer += " )";

	m_code += "TEMPER_TEST( TestMultiplyVector_" + m_fullTypeName + " )\n";
	m_code += "{\n";
	m_code += "\t" + vectorTypeName + " answerVec = " + vectorTypeName + parmListVecAnswer + ";\n";
	m_code += "\n";
	m_code += "\t" + m_fullTypeName + " a = " + m_fullTypeName + parmListMat + ";\n";
	m_code += "\t" + vectorTypeName + " b = " + vectorTypeName + parmListVec + ";\n";
	m_code += "\t" + vectorTypeName + " c = a " + GEN_OPERATORS_ARITHMETIC[GEN_OP_ARITHMETIC_MUL] + " b;\n";
	m_code += "\n";
	m_code += "\tTEMPER_EXPECT_TRUE( c == answerVec );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestIncrement() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	std::string parmList0 = Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 0.0f );
	std::string parmList1 = Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 1.0f );

	std::string parmListVecs[] = {
		parmList0,
		parmList1,
	};

	std::string parmListAnswers[] = {
		parmList1,
		parmList0,
	};

	std::string suffices[GEN_OP_INCREMENT_COUNT] = {
		"Increment",
		"Decrement",
	};

	for ( uint32_t i = 0; i < GEN_OP_INCREMENT_COUNT; i++ ) {
		m_code += "TEMPER_TEST( Test" + suffices[i] + "_" + m_fullTypeName + " )\n";
		m_code += "{\n";
		m_code += "\t" + m_fullTypeName + " mat;\n";
		m_code += "\n";
		m_code += "\t// prefix\n";
		m_code += "\tmat = " + m_fullTypeName + parmListVecs[i] + ";\n";
		m_code += "\t" + GEN_OPERATORS_INCREMENT[i] + "mat;\n";
		m_code += "\tTEMPER_EXPECT_TRUE( mat == " + m_fullTypeName + parmListAnswers[i] + " );\n";
		m_code += "\n";
		m_code += "\t// postfix\n";
		m_code += "\tmat = " + m_fullTypeName + parmListVecs[i] + ";\n";
		m_code += "\tmat" + GEN_OPERATORS_INCREMENT[i] + ";\n";
		m_code += "\tTEMPER_EXPECT_TRUE( mat == " + m_fullTypeName + parmListAnswers[i] + " );\n";
		m_code += "\n";
		m_code += "\tTEMPER_PASS();\n";
		m_code += "}\n";
		m_code += "\n";
	}
}

void TestsGeneratorMatrix::GenerateTestRelational() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	std::string boolTypeName = "bool" + m_numRowsStr + "x" + m_numColsStr;
	std::string parmListTrue = Gen_GetParmListMatrixSingleValue( GEN_TYPE_BOOL, m_numRows, m_numCols, true );

	std::string parmLists[] = {
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 1 ),
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 2 ),
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 3 ),
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 4 ),
	};

	uint32_t numTestMats = 0;

	m_code += "TEMPER_TEST( TestRelational_" + m_fullTypeName + " )\n";
	m_code += "{\n";
	m_code += "\t" + boolTypeName + " allTrue = " + boolTypeName + parmListTrue + ";\n";
	m_code += "\n";
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
		m_code += "\tTEMPER_EXPECT_TRUE( test" + std::to_string( i ) + " == allTrue );\n";
	}
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestBitwise() {
	if ( !Gen_IsIntegerType( m_type ) ) {
		return;
	}

	std::string parmListAnswerUnary = "( ";
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			parmListAnswerUnary += "(" + m_memberTypeString + ") -1";

			if ( row + col != ( m_numRows - 1 ) + ( m_numCols - 1 ) ) {
				parmListAnswerUnary += ",";
			}

			if ( col != m_numCols - 1 ) {
				parmListAnswerUnary += " ";
			}
		}

		parmListAnswerUnary += "\n";
	}
	parmListAnswerUnary += " )";

	// values must be integers
	std::string parmListLhs[GEN_OP_BITWISE_COUNT] = {
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 21.0f ),
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 21.0f ),
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 21.0f ),
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 1.0f  ),
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 16.0f ),
	};

	std::string parmListRhs[GEN_OP_BITWISE_COUNT] = {
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 7.0f ),
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 7.0f ),
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 7.0f ),
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 2.0f ),
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 4.0f ),
	};

	std::string parmListAnswers[GEN_OP_BITWISE_COUNT] = {
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 5.0f  ),	// 21 & 7
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 23.0f ),	// 21 | 7
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 18.0f ),	// 21 ^ 7
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 4.0f  ),	// 1  << 2
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 1.0f  ),	// 16 >> 4
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

	for ( uint32_t i = 0; i < _countof( ops ); i++ ) {
		m_code += "TEMPER_TEST( TestBitwise" + suffices[i] + "_" + m_fullTypeName + " )\n";
		m_code += "{\n";
		m_code += "\t" + m_fullTypeName + " a  = " + m_fullTypeName + parmListLhs[i] + ";\n";
		m_code += "\t" + m_fullTypeName + " b  = " + m_fullTypeName + parmListRhs[i] + ";\n";
		m_code += "\n";
		m_code += "\t" + m_fullTypeName + " answer = a " + GEN_OPERATORS_BITWISE[ops[i]] + " b;\n";
		m_code += "\n";
		m_code += "\tTEMPER_EXPECT_TRUE( answer == " + m_fullTypeName + parmListAnswers[i] + " );\n";
		m_code += "\n";
		m_code += "\tTEMPER_PASS();\n";
		m_code += "}\n";
		m_code += "\n";
	}

	// unary
	m_code += "TEMPER_TEST( TestBitwiseUnary_" + m_fullTypeName + " )\n";
	m_code += "{\n";
	m_code += "\t" + m_fullTypeName + " a = " + m_fullTypeName + Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 0.0f ) + ";\n";
	m_code += "\n";
	m_code += "\t" + m_fullTypeName + " answer = " + GEN_OPERATORS_BITWISE[GEN_OP_BITWISE_UNARY] + "a;\n";
	m_code += "\n";
	m_code += "\tTEMPER_EXPECT_TRUE( answer == " + m_fullTypeName + parmListAnswerUnary + " );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestArray() {
	std::string zeroStr = Gen_GetNumericLiteral( m_type, 0 );
	std::string oneStr = Gen_GetNumericLiteral( m_type, 1 );

	m_code += "TEMPER_TEST( TestArray_" + m_fullTypeName + " )\n";
	m_code += "{\n";
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

void TestsGeneratorMatrix::GenerateTestIdentity() {
	std::string zeroStr = Gen_GetNumericLiteral( m_type, 0 );
	std::string oneStr = Gen_GetNumericLiteral( m_type, 1 );

	std::string paramListIdentity = Gen_GetParmListMatrixIdentity( m_type, m_numRows, m_numCols );

	m_code += "TEMPER_TEST( TestIdentity_" + m_fullTypeName + " )\n";
	m_code += "{\n";
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
			int32_t index = static_cast<int32_t>( col + ( row * m_numCols ) );

			paramListNormal += Gen_GetNumericLiteral( m_type, static_cast<float>( index ) );

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
			int32_t index = static_cast<int32_t>( col + ( row * m_numCols ) );

			paramListTransposed += Gen_GetNumericLiteral( m_type, static_cast<float>( index ) );

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

	m_code += "TEMPER_TEST( TestTranspose_" + m_fullTypeName + " )\n";
	m_code += "{\n";
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
	float mat2x2[4] {
		6.0f, 2.0f,
		2.0f, 6.0f
	};

	float mat3x3[9] {
		6.0f, 2.0f, 3.0f,
		2.0f, 7.0f, 2.0f,
		3.0f, 2.0f, 6.0f
	};

	float mat4x4[16] {
		6.0f, 2.0f, 3.0f, 4.0f,
		2.0f, 7.0f, 5.0f, 3.0f,
		3.0f, 5.0f, 7.0f, 2.0f,
		4.0f, 3.0f, 2.0f, 6.0f
	};

	const float* matrix = nullptr;
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

	m_code += "TEMPER_TEST( TestInverse_" + m_fullTypeName + " )\n";
	m_code += "{\n";
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
	float mat2x2[4] {
		6.0f, 2.0f,
		2.0f, 6.0f
	};

	float mat3x3[9] {
		6.0f, 2.0f, 3.0f,
		2.0f, 7.0f, 2.0f,
		3.0f, 2.0f, 6.0f
	};

	float mat4x4[16] {
		6.0f, 2.0f, 3.0f, 4.0f,
		2.0f, 7.0f, 5.0f, 3.0f,
		3.0f, 5.0f, 7.0f, 2.0f,
		4.0f, 3.0f, 2.0f, 6.0f
	};

	float determinants[3] = {
		32.0f,	// 2x2
		165.0f,	// 3x3
		285.0f	// 4x4
	};

	const float* matrix = nullptr;
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

	m_code += "TEMPER_TEST( TestDeterminant_" + m_fullTypeName + " )\n";
	m_code += "{\n";
	m_code += "\t" + m_fullTypeName + " mat = " + m_fullTypeName + paramList + ";\n";
	m_code += "\t" + m_memberTypeString + " det = determinant( mat );\n";
	m_code += "\n";
	if ( Gen_IsFloatingPointType( m_type ) ) {
		std::string floateqStr = Gen_GetFuncNameFloateq( m_type );

		m_code += "\tTEMPER_EXPECT_TRUE( " + floateqStr + "( det, " + answerStr + " ) );\n";
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
		float number = static_cast<float>( col + baseNumber );

		parmListTranslateVector += Gen_GetNumericLiteral( m_type, number );

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
					float number = static_cast<float>( row + baseNumber );
					parmListTranslated += Gen_GetNumericLiteral( m_type, number );
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

	m_code += "TEMPER_TEST( TestTranslate_" + m_fullTypeName + " )\n";
	m_code += "{\n";
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
	float rotRadians = rotDegrees * static_cast<float>( M_PI ) / 180.0f;

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

	float rotMatYaw[4][4] = {
		{  cosR, 0.0f, sinR, 0.0f },
		{  0.0f, 1.0f, 0.0f, 0.0f },
		{ -sinR, 0.0f, cosR, 0.0f },
		{  0.0f, 0.0f, 0.0f, 1.0f },
	};

	float rotMatPitch[4][4] = {
		{ 1.0f, 0.0f,  0.0f, 0.0f },
		{ 0.0f, cosR, -sinR, 0.0f },
		{ 0.0f, sinR,  cosR, 0.0f },
		{ 0.0f, 0.0f,  0.0f, 1.0f },
	};

	float rotMatRoll[4][4] = {
		{ cosR, -sinR, 0.0f, 0.0f },
		{ sinR,  cosR, 0.0f, 0.0f },
		{ 0.0f,  0.0f, 1.0f, 0.0f },
		{ 0.0f,  0.0f, 0.0f, 1.0f },
	};

	uint32_t numRotMatRows = __min( m_numRows, 4 );
	uint32_t numRotMatCols = __min( m_numCols, 4 );

	uint32_t numRotateVectorComponents = m_numCols - 1;

	std::string rotDegreesStr = Gen_GetNumericLiteral( m_type, rotDegrees );

	std::string rotateVecTypeString = m_typeString + std::to_string( numRotateVectorComponents );

	std::string parmListVecYaw = Gen_GetParmListVector( m_type, numRotateVectorComponents, angleAxisVecYaw );
	std::string parmListVecPitch = Gen_GetParmListVector( m_type, numRotateVectorComponents, angleAxisVecPitch );
	std::string parmListVecRoll = Gen_GetParmListVector( m_type, numRotateVectorComponents, angleAxisVecRoll );

	std::string parmListMatYaw = Gen_GetParmListMatrix( m_type, numRotMatRows, numRotMatCols, rotMatYaw );
	std::string parmListMatPitch = Gen_GetParmListMatrix( m_type, numRotMatRows, numRotMatCols, rotMatPitch );
	std::string parmListMatRoll = Gen_GetParmListMatrix( m_type, numRotMatRows, numRotMatCols, rotMatRoll );

	// matrices where cols == 3 only have roll rotation support
	std::string parmListRotateRoll = "mat, radians( " + rotDegreesStr + " )";
	if ( m_numCols > 3 ) {
		parmListRotateRoll += ", " + rotateVecTypeString + parmListVecRoll;
	}

	m_code += "TEMPER_TEST( TestRotate_" + m_fullTypeName + " )\n";
	m_code += "{\n";
	m_code += "\t" + m_fullTypeName + " mat;\n";
	if ( m_numRows > 3 ) {
		m_code += "\t" + m_fullTypeName + " yaw = rotate( mat, radians( " + rotDegreesStr + " ), " + rotateVecTypeString + parmListVecYaw + " );\n";
		m_code += "\t" + m_fullTypeName + " pitch = rotate( mat, radians( " + rotDegreesStr + " ), " + rotateVecTypeString + parmListVecPitch + " );\n";
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

	std::string parmListScaleVec = Gen_GetParmListVector( m_type, scaleCols, scaleMatDiagonal );
	std::string parmListScaleMat = Gen_GetParmListMatrixDiagonal( m_type, m_numRows, m_numCols, scaleMatDiagonal, _countof( scaleMatDiagonal ) );

	std::string scaleVecTypeString = m_typeString + std::to_string( scaleCols );

	m_code += "TEMPER_TEST( TestScale_" + m_fullTypeName + " )\n";
	m_code += "{\n";
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

	// all answers for 1280 x 720, ortho size 5, znear: -1, zfar: 100

	// left-handed (0 - 1)
	float answerOrtho_LH_ZO[4][4] = {
		{ 0.112499997f,  0.0f,         0.0f,           0.0f           },
		{ 0.0f,         -0.200000003f, 0.0f,           0.0f           },
		{ 0.0f,          0.0f,         0.00990098994f, 0.00990098994f },
		{ 0.0f,          0.0f,         0.0f,           1.0f           }
	};

	// left-handed (-1 - 1)
	float answerOrtho_LH_NO[4][4] = {
		{ 0.11250f,  0.0f, 0.0f,      -0.0f      },
		{ 0.0f,     -0.2f, 0.0f,       0.0f      },
		{ 0.0f,      0.0f, 0.019802f, -0.980198f },
		{ 0.0f,      0.0f, 0.0f,       1.0f      }
	};

	// right-handed (0 - 1)
	float answerOrtho_RH_ZO[4][4] = {
		{ 0.1125f,  0.0f,  0.0f,      -0.0f      },
		{ 0.0f,    -0.2f,  0.0f,       0.0f      },
		{ 0.0f,     0.0f, -0.009901f,  0.009901f },
		{ 0.0f,     0.0f,  0.0f,       1.0f      }
	};

	// right-handed (-1 - 1)
	float answerOrtho_RH_NO[4][4] = {
		{ 0.112500f,  0.0f,  0.0f,      -0.0f      },
		{ 0.0f,      -0.2f,  0.0f,       0.0f      },
		{ 0.0f,       0.0f, -0.019802f, -0.980198f },
		{ 0.0f,       0.0f,  0.0f,       1.0f      }
	};

	std::string parmListAnswerOrtho_LH_ZO = Gen_GetParmListMatrix( m_type, 4, 4, answerOrtho_LH_ZO );
	std::string parmListAnswerOrtho_LH_NO = Gen_GetParmListMatrix( m_type, 4, 4, answerOrtho_LH_NO );
	std::string parmListAnswerOrtho_RH_ZO = Gen_GetParmListMatrix( m_type, 4, 4, answerOrtho_RH_ZO );
	std::string parmListAnswerOrtho_RH_NO = Gen_GetParmListMatrix( m_type, 4, 4, answerOrtho_RH_NO );

	std::string minusOneStr		= Gen_GetNumericLiteral( m_type, -1.0f );
	std::string oneHundredStr	= Gen_GetNumericLiteral( m_type, 100.0f );

	// left-handed, zero to one
	{
		m_code += "TEMPER_TEST( TestOrtho_" + m_fullTypeName + " )\n";
		m_code += "{\n";
		m_code += "\t" + m_fullTypeName + " answerOrtho_LH_ZO = " + m_fullTypeName + parmListAnswerOrtho_LH_ZO + ";\n";
		m_code += "\t" + m_fullTypeName + " answerOrtho_LH_NO = " + m_fullTypeName + parmListAnswerOrtho_LH_NO + ";\n";
		m_code += "\t" + m_fullTypeName + " answerOrtho_RH_ZO = " + m_fullTypeName + parmListAnswerOrtho_RH_ZO + ";\n";
		m_code += "\t" + m_fullTypeName + " answerOrtho_RH_NO = " + m_fullTypeName + parmListAnswerOrtho_RH_NO + ";\n";
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
		m_code += "\t" + m_fullTypeName + " mat_LH_ZO = ortho_lh_zo( left, right, top, bottom, " + minusOneStr + ", " + oneHundredStr + " );\n";
		m_code += "\t" + m_fullTypeName + " mat_LH_NO = ortho_lh_no( left, right, top, bottom, " + minusOneStr + ", " + oneHundredStr + " );\n";
		m_code += "\t" + m_fullTypeName + " mat_RH_ZO = ortho_rh_zo( left, right, top, bottom, " + minusOneStr + ", " + oneHundredStr + " );\n";
		m_code += "\t" + m_fullTypeName + " mat_RH_NO = ortho_rh_no( left, right, top, bottom, " + minusOneStr + ", " + oneHundredStr + " );\n";
		m_code += "\n";
		m_code += "\tTEMPER_EXPECT_TRUE( mat_LH_ZO == answerOrtho_LH_ZO );\n";
		m_code += "\tTEMPER_EXPECT_TRUE( mat_LH_NO == answerOrtho_LH_NO );\n";
		m_code += "\tTEMPER_EXPECT_TRUE( mat_RH_ZO == answerOrtho_RH_ZO );\n";
		m_code += "\tTEMPER_EXPECT_TRUE( mat_RH_NO == answerOrtho_RH_NO );\n";
		m_code += "\n";
		m_code += "\tTEMPER_PASS();\n";
		m_code += "}\n";
		m_code += "\n";
	}
}

void TestsGeneratorMatrix::GenerateTestPerspective() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	if ( m_numRows < 4 || m_numCols < 4 ) {
		return;
	}

	// all answers for 1280 x 720, fov: 90 degrees, znear: 0.1, zfar: 100

	// left-handed (0 - 1)
	float answerPerspective_LH_ZO[4][4] = {
		{ 0.347270f, 0.0f,      0.0f,       0.0f      },
		{ 0.0f,      0.617370f, 0.0f,       0.0f      },
		{ 0.0f,      0.0f,      1.001001f, -0.100100f },
		{ 0.0f,      0.0f,      1.000000f,  0.0f      }
	};

	// left handed (-1 - 1)
	float answerPerspective_LH_NO[4][4] = {
		{ 0.347270f, 0.0f,      0.0f,       0.0f      },
		{ 0.0f,      0.617370f, 0.0f,       0.0f      },
		{ 0.0f,      0.0f,      1.002002f, -0.200200f },
		{ 0.0f,      0.0f,      1.0f,       0.0f      }
	};

	// right handed (0 - 1)
	float answerPerspective_RH_ZO[4][4] = {
		{ 0.347270f, 0.0f,       0.0f,      0.0f       },
		{ 0.0f,      0.617370f,  0.0f,      0.0f       },
		{ 0.0f,      0.0f,      -1.001001f, -0.100100f },
		{ 0.0f,      0.0f,      -1.0f,      0.0f       }
	};

	// right handed (-1 - 1)
	float answerPerspective_RH_NO[4][4] = {
		{ 0.347270f, 0.0f,       0.0f,       0.0f      },
		{ 0.0f,      0.617370f,  0.0f,       0.0f      },
		{ 0.0f,      0.0f,      -1.002002f, -0.200200f },
		{ 0.0f,      0.0f,      -1.0f,       0.0f      }
	};

	std::string parmListPerspective_LH_ZO = Gen_GetParmListMatrix( m_type, 4, 4, answerPerspective_LH_ZO );
	std::string parmListPerspective_LH_NO = Gen_GetParmListMatrix( m_type, 4, 4, answerPerspective_LH_NO );
	std::string parmListPerspective_RH_ZO = Gen_GetParmListMatrix( m_type, 4, 4, answerPerspective_RH_ZO );
	std::string parmListPerspective_RH_NO = Gen_GetParmListMatrix( m_type, 4, 4, answerPerspective_RH_NO );

	std::string widthStr	= Gen_GetNumericLiteral( m_type, 1280.0f );
	std::string heightStr	= Gen_GetNumericLiteral( m_type, 720.0f );
	std::string fovStr		= Gen_GetNumericLiteral( m_type, 90.0f );
	std::string znearStr	= Gen_GetNumericLiteral( m_type, 0.1f );
	std::string zfarStr		= Gen_GetNumericLiteral( m_type, 100.0f );

	m_code += "TEMPER_TEST( TestPerspective_" + m_fullTypeName + " )\n";
	m_code += "{\n";
	m_code += "\t" + m_fullTypeName + " answerPerspective_LH_ZO = " + m_fullTypeName + parmListPerspective_LH_ZO + ";\n";
	m_code += "\t" + m_fullTypeName + " answerPerspective_LH_NO = " + m_fullTypeName + parmListPerspective_LH_NO + ";\n";
	m_code += "\t" + m_fullTypeName + " answerPerspective_RH_ZO = " + m_fullTypeName + parmListPerspective_RH_ZO + ";\n";
	m_code += "\t" + m_fullTypeName + " answerPerspective_RH_NO = " + m_fullTypeName + parmListPerspective_RH_NO + ";\n";
	m_code += "\n";
	m_code += "\t" + m_typeString + " aspect = " + widthStr + " / " + heightStr + ";\n";
	m_code += "\t" + m_fullTypeName + " mat_LH_ZO = perspective_lh_zo( " + fovStr + ", aspect, " + znearStr + ", " + zfarStr + " );\n";
	m_code += "\t" + m_fullTypeName + " mat_LH_NO = perspective_lh_no( " + fovStr + ", aspect, " + znearStr + ", " + zfarStr + " );\n";
	m_code += "\t" + m_fullTypeName + " mat_RH_ZO = perspective_rh_zo( " + fovStr + ", aspect, " + znearStr + ", " + zfarStr + " );\n";
	m_code += "\t" + m_fullTypeName + " mat_RH_NO = perspective_rh_no( " + fovStr + ", aspect, " + znearStr + ", " + zfarStr + " );\n";
	m_code += "\n";
	m_code += "\tTEMPER_EXPECT_TRUE( mat_LH_ZO == answerPerspective_LH_ZO );\n";
	m_code += "\tTEMPER_EXPECT_TRUE( mat_LH_NO == answerPerspective_LH_NO );\n";
	m_code += "\tTEMPER_EXPECT_TRUE( mat_RH_ZO == answerPerspective_RH_ZO );\n";
	m_code += "\tTEMPER_EXPECT_TRUE( mat_RH_NO == answerPerspective_RH_NO );\n";
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

	float answerLookAt_LH[4][4] = {
		{ 0.707107f, 0.0f, -0.707107f, 0.0f },
		{ 0.0f,      1.0f,  0.0f,      0.0f },
		{ 0.707107f, 0.0f,  0.707107f, 0.0f },
		{ 0.0f,      0.0f,  0.0f,      1.0f }
	};

	float answerLookAt_RH[4][4] = {
		{ -0.707107f, 0.0f,  0.707107f, 0.0f },
		{  0.0f,      1.0f,  0.0f,      0.0f },
		{ -0.707107f, 0.0f, -0.707107f, 0.0f },
		{  0.0f,      0.0f,  0.0f,      1.0f }
	};

	uint32_t numTranslateVecComponents = 3;

	std::string posVectorTypeName = m_typeString + std::to_string( numTranslateVecComponents );

	std::string parmListCurrentPos	= Gen_GetParmListVector( m_type, numTranslateVecComponents, currentPos );
	std::string parmListTargetPos	= Gen_GetParmListVector( m_type, numTranslateVecComponents, targetPos );
	std::string parmListUp			= Gen_GetParmListVector( m_type, numTranslateVecComponents, up );

	std::string parmListLookAt_LH	= Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, answerLookAt_LH );
	std::string parmListLookAt_RH	= Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, answerLookAt_RH );

	m_code += "TEMPER_TEST( TestLookAt_" + m_fullTypeName + " )\n";
	m_code += "{\n";
	m_code += "\t" + m_fullTypeName + " answerLookAt_LH = " + m_fullTypeName + parmListLookAt_LH + ";\n";
	m_code += "\t" + m_fullTypeName + " answerLookAt_RH = " + m_fullTypeName + parmListLookAt_RH + ";\n";
	m_code += "\n";
	m_code += "\t" + posVectorTypeName + " currentPos = " + posVectorTypeName + parmListCurrentPos + ";\n";
	m_code += "\t" + posVectorTypeName + " targetPos = " + posVectorTypeName + parmListTargetPos + ";\n";
	m_code += "\t" + posVectorTypeName + " up = " + posVectorTypeName + parmListUp + ";\n";
	m_code += "\n";
	m_code += "\t" + m_fullTypeName + " mat_LH = lookat_lh( currentPos, targetPos, up );\n";
	m_code += "\t" + m_fullTypeName + " mat_RH = lookat_rh( currentPos, targetPos, up );\n";
	m_code += "\n";
	m_code += "\tTEMPER_EXPECT_TRUE( mat_LH == answerLookAt_LH );\n";
	m_code += "\tTEMPER_EXPECT_TRUE( mat_RH == answerLookAt_RH );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

std::string TestsGeneratorMatrix::GetTestCodeArithmeticInternal( const genOpArithmetic_t op,
	const float valuesLhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], const float valuesRhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX] ) const {
	assert( op >= 0 );
	assert( op < GEN_OP_ARITHMETIC_COUNT );
	assert( valuesLhs );
	assert( valuesRhs );

	uint32_t rhsRows = m_numRows;
	uint32_t rhsCols = m_numCols;

	uint32_t returnTypeRows = m_numRows;
	uint32_t returnTypeCols = m_numCols;

	std::string lhsTypeName = m_fullTypeName;
	std::string rhsTypeName;
	std::string returnTypeName;

	// for non-square matrices you can only do proper multiply and divide by the transposed type
	if ( op == GEN_OP_ARITHMETIC_MUL ) {
		rhsRows = m_numCols;
		rhsCols = m_numRows;

		returnTypeRows = m_numRows;
		returnTypeCols = m_numRows;

		rhsTypeName = m_typeString + m_numColsStr + "x" + m_numRowsStr;
		returnTypeName = m_typeString + m_numRowsStr + "x" + m_numRowsStr;
	} else {
		returnTypeName = rhsTypeName = lhsTypeName;
	}

	std::string parmListLhs = Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, valuesLhs );
	std::string parmListRhs = Gen_GetParmListMatrix( m_type, rhsRows, rhsCols, valuesRhs );

	// for division, just divide a matrix by itself and check it equals identity
	std::string parmListAnswer;
	if ( op == GEN_OP_ARITHMETIC_DIV && ( m_numRows == m_numCols && Gen_IsFloatingPointType( m_type ) ) ) {
		parmListAnswer = Gen_GetParmListMatrixIdentity( m_type, m_numRows, m_numCols );
	} else {
		parmListAnswer = GetParmListArithmeticAnswer( op, returnTypeRows, returnTypeCols, valuesLhs, valuesRhs );
	}

	std::string code;

	code += "\t" + returnTypeName + " answer = " + returnTypeName + parmListAnswer + ";\n";
	code += "\n";
	code += "\t" + m_fullTypeName + " a = " + m_fullTypeName + parmListLhs + ";\n";
	code += "\t" + rhsTypeName    + " b = " + rhsTypeName + parmListRhs + ";\n";
	code += "\t" + returnTypeName + " c = a " + GEN_OPERATORS_ARITHMETIC[op] + " b;\n";
	code += "\n";
	code += "\tTEMPER_EXPECT_TRUE( c == answer );\n";
	code += "\n";
	code += "\tTEMPER_PASS();\n";

	return code;
}

std::string TestsGeneratorMatrix::GetParmListArithmeticAnswer( const genOpArithmetic_t op, const uint32_t numRows, const uint32_t numCols,
	const float valuesLhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], const float valuesRhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX] ) const {
	assert( op >= 0 );
	assert( op < GEN_OP_ARITHMETIC_COUNT );

	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	assert( valuesLhs );
	assert( valuesRhs );

	std::string parmList = "(\n";

	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD: {
			for ( uint32_t row = 0; row < numRows; row++ ) {
				parmList += "\t\t";

				for ( uint32_t col = 0; col < numCols; col++ ) {
					float lhs = valuesLhs[row][col];
					float rhs = valuesRhs[row][col];

					parmList += Gen_GetNumericLiteral( m_type, lhs + rhs );

					if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
						parmList += ",";
					}

					if ( col != numCols - 1 ) {
						parmList += " ";
					}
				}

				parmList += "\n";
			}

			break;
		}

		case GEN_OP_ARITHMETIC_SUB: {
			for ( uint32_t row = 0; row < numRows; row++ ) {
				parmList += "\t\t";

				for ( uint32_t col = 0; col < numCols; col++ ) {
					float lhs = valuesLhs[row][col];
					float rhs = valuesRhs[row][col];

					parmList += Gen_GetNumericLiteral( m_type, lhs - rhs );

					if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
						parmList += ",";
					}

					if ( col != numCols - 1 ) {
						parmList += " ";
					}
				}

				parmList += "\n";
			}

			break;
		}

		case GEN_OP_ARITHMETIC_MUL: {
			for ( uint32_t row = 0; row < numRows; row++ ) {
				parmList += "\t\t";

				for ( uint32_t col = 0; col < numCols; col++ ) {
					// get the left-hand row
					std::vector<float> lhsRow( m_numCols );
					for ( size_t lhsComponent = 0; lhsComponent < lhsRow.size(); lhsComponent++ ) {
						lhsRow[lhsComponent] = valuesLhs[row][lhsComponent];
					}

					// get the right-hand column
					std::vector<float> rhsCol( m_numCols );
					for ( size_t rhsComponent = 0; rhsComponent < rhsCol.size(); rhsComponent++ ) {
						rhsCol[rhsComponent] = valuesRhs[rhsComponent][col];
					}

					// do the dot product procedurally
					std::vector<float> dots( m_numCols );
					for ( size_t i = 0; i < dots.size(); i++ ) {
						dots[i] = lhsRow[i] * rhsCol[i];
					}

					float dot = 0.0f;
					for ( size_t i = 0; i < dots.size(); i++ ) {
						dot += dots[i];
					}

					parmList += Gen_GetNumericLiteral( m_type, dot );

					if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
						parmList += ",";
					}

					if ( col != numCols - 1 ) {
						parmList += " ";
					}
				}

				parmList += "\n";
			}

			break;
		}

		case GEN_OP_ARITHMETIC_DIV: {
			// otherwise just do component-wise division
			for ( uint32_t row = 0; row < numRows; row++ ) {
				parmList += "\t\t";

				for ( uint32_t col = 0; col < numCols; col++ ) {
					float lhs = valuesLhs[row][col];
					float rhs = valuesRhs[row][col];

					parmList += Gen_GetNumericLiteral( m_type, lhs / rhs );

					if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
						parmList += ",";
					}

					if ( col != numCols - 1 ) {
						parmList += " ";
					}
				}

				parmList += "\n";
			}

			break;
		}

		case GEN_OP_ARITHMETIC_COUNT:
		default:
			printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
			break;
	}

	parmList += "\t)";

	return parmList;
}