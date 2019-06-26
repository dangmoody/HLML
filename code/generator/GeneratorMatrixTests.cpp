#include "GeneratorMatrixTests.h"

#include "FileIO.h"

#include "gen_funcs_vector.h"
#include "gen_funcs_matrix.h"

#include "allocator.h"

#include <assert.h>
#include <string.h>

#define _USE_MATH_DEFINES	// for M_PI
#include <math.h>

bool GeneratorMatrixTests::Generate( const genType_t type, const u32 numRows, const u32 numCols ) {
	const u32 testsCodeBytes = 20 * KB_TO_BYTES;
	const u32 suiteCodeBytes = 12 * KB_TO_BYTES;

	m_codeTests = String_Create( testsCodeBytes );
	m_codeSuite = String_Create( suiteCodeBytes );

	m_type = type;

	m_numRows = numRows;
	m_numCols = numCols;

	m_typeString = Gen_GetTypeString( type );
	m_memberTypeString = Gen_GetMemberTypeString( type );

	snprintf( m_vectorTypeString, 32, "%s%d", m_typeString, numCols );
	snprintf( m_fullTypeName, 32, "%s%dx%d", m_typeString, numRows, numCols );

	stringBuilder_t code = String_Create( testsCodeBytes + suiteCodeBytes );

	String_Append( &code, GEN_FILE_HEADER );

	String_Append( &code, "#include \"../../" GEN_OUT_GEN_FOLDER_PATH GEN_FILENAME_FUNCTIONS_MATRIX ".h\"\n" );
	String_Append( &code, "\n" );

	String_Append( &code, "#include <temper/temper.h>\n" );
	String_Append( &code, "\n" );

	String_Appendf( &m_codeSuite, "TEMPER_SUITE( Test_%s )\n", m_fullTypeName );
	String_Append(  &m_codeSuite, "{\n" );

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

	String_Append( &m_codeSuite, "}\n" );

	String_Append( &code, m_codeTests.str );
	String_Append( &code, m_codeSuite.str );

	char filename[64] = { 0 };
	snprintf( filename, 64, GEN_TESTS_FOLDER_PATH "test_%s.cpp", m_fullTypeName );

	bool32 result = FS_WriteEntireFile( filename, code.str, code.length );

	if ( !result ) {
		printf( "Can't generate test suite for %s.  That's rough man.\n", m_fullTypeName );
	}

	Mem_Reset();

	return result;
}

void GeneratorMatrixTests::GenerateTestAssignment() {
	char testName[64] = { 0 };
	snprintf( testName, 64, "TestAssignment_%s", m_fullTypeName );

	// HACK(DM): this is not ideal for obvious reasons
	float fillValue = 999.0f;
	char fillValueStr[16];
	Gen_GetNumericLiteral( m_type, 999, fillValueStr );

	float valuesIdentity[4][4] = {
		{ fillValue, 0.0f,      0.0f,      0.0f      },
		{ 0.0f,      fillValue, 0.0f,      0.0f      },
		{ 0.0f,      0.0f,      fillValue, 0.0f      },
		{ 0.0f,      0.0f,      0.0f,      fillValue }
	};

	float values[4][4] = {
		{ 0.0f,  1.0f,  2.0f,  3.0f  },
		{ 4.0f,  5.0f,  6.0f,  7.0f  },
		{ 8.0f,  9.0f,  10.0f, 11.0f },
		{ 12.0f, 13.0f, 14.0f, 15.0f }
	};

	float valuesReversed[4][4] = {
		{ 16.0f, 15.0f, 14.0f, 13.0f },
		{ 12.0f, 11.0f, 10.0f, 9.0f  },
		{ 8.0f,  7.0f,  6.0f,  5.0f  },
		{ 4.0f,  3.0f,  2.0f,  1.0f  }
	};

	char parmListValues[256]			= { 0 };
	char parmListValuesReversed[256]	= { 0 };

	Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, values, parmListValues );
	Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, valuesReversed, parmListValuesReversed );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s mat;\n", m_fullTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\t// fill single value\n" );
	String_Appendf( &m_codeTests, "\tmat = %s( %s );\n", m_fullTypeName, fillValueStr );
	for ( u32 row = 0; row < m_numRows; row++ ) {
		char parmList[128] = { 0 };
		Gen_GetParmListVector( m_type, m_numCols, valuesIdentity[row], parmList );

		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat[%d] == %s%s );\n", row, m_vectorTypeString, parmList );
	}
	String_Append( &m_codeTests, "\n" );

	String_Append(  &m_codeTests, "\t// row filling\n" );
	String_Appendf( &m_codeTests, "\tmat = %s(\n", m_fullTypeName );
	for ( u32 row = 0; row < m_numRows; row++ ) {
		char parmList[128] = { 0 };
		Gen_GetParmListVector( m_type, m_numCols, values[row], parmList );

		String_Appendf( &m_codeTests, "\t\t%s%s", m_vectorTypeString, parmList );

		if ( row != m_numRows - 1 ) {
			String_Append( &m_codeTests, "," );
		}

		String_Append( &m_codeTests, "\n" );
	}
	String_Append( &m_codeTests, "\t);\n" );
	for ( u32 row = 0; row < m_numRows; row++ ) {
		char parmList[128] = { 0 };
		Gen_GetParmListVector( m_type, m_numCols, values[row], parmList );

		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat[%d] == %s%s );\n", row, m_vectorTypeString, parmList );
	}
	String_Append( &m_codeTests, "\n" );

	String_Append(  &m_codeTests, "\t// all values filled\n" );
	String_Appendf( &m_codeTests, "\tmat = %s%s;\n", m_fullTypeName, parmListValuesReversed );
	for ( u32 row = 0; row < m_numRows; row++ ) {
		char parmList[128] = { 0 };
		Gen_GetParmListVector( m_type, m_numCols, valuesReversed[row], parmList );

		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat[%d] == %s%s );\n", row, m_vectorTypeString, parmList );
	}
	String_Append( &m_codeTests, "\n" );

	String_Append( &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append( &m_codeTests, "}\n" );
	String_Append( &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorMatrixTests::GenerateTestArithmetic() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	const float valuesLhs[4][4] = {
		{ 6.0f,  6.0f,  6.0f,  6.0f  },
		{ 6.0f,  6.0f,  6.0f,  6.0f  },
		{ 12.0f, 12.0f, 12.0f, 12.0f },
		{ 18.0f, 18.0f, 18.0f, 18.0f }
	};

	const float valuesRhs[4][4] = {
		{ 1.0f, 1.0f, 1.0f, 1.0f },
		{ 2.0f, 2.0f, 2.0f, 2.0f },
		{ 3.0f, 3.0f, 3.0f, 3.0f },
		{ 6.0f, 6.0f, 6.0f, 6.0f }
	};

	const float valuesDiv[4][4] = {
		{ 6.0f, 2.0f, 3.0f, 4.0f },
		{ 2.0f, 7.0f, 5.0f, 3.0f },
		{ 3.0f, 5.0f, 7.0f, 2.0f },
		{ 4.0f, 3.0f, 2.0f, 6.0f }
	};

	const char* suffices[] = {
		"Addition",
		"Subtraction",
		"Multiplication",
		"Division",
	};

	char testNames[GEN_OP_ARITHMETIC_COUNT][64];
	for ( u32 i = 0; i < GEN_OP_ARITHMETIC_COUNT; i++ ) {
		snprintf( testNames[i], 64, "TestArithmetic%s_%s", suffices[i], m_fullTypeName );
	}

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testNames[GEN_OP_ARITHMETIC_ADD] );
	String_Append(  &m_codeTests, "{\n" );
	GetTestCodeArithmeticInternal( GEN_OP_ARITHMETIC_ADD, valuesLhs, valuesRhs, &m_codeTests );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testNames[GEN_OP_ARITHMETIC_SUB] );
	String_Append(  &m_codeTests, "{\n" );
	GetTestCodeArithmeticInternal( GEN_OP_ARITHMETIC_SUB, valuesLhs, valuesRhs, &m_codeTests );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testNames[GEN_OP_ARITHMETIC_MUL] );
	String_Append(  &m_codeTests, "{\n" );
	GetTestCodeArithmeticInternal( GEN_OP_ARITHMETIC_MUL, valuesLhs, valuesRhs, &m_codeTests );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	// for division use different matrices that are invertible
	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testNames[GEN_OP_ARITHMETIC_DIV] );
	String_Append(  &m_codeTests, "{\n" );
	if ( m_numRows == m_numCols && Gen_IsFloatingPointType( m_type ) ) {
		GetTestCodeArithmeticInternal( GEN_OP_ARITHMETIC_DIV, valuesDiv, valuesDiv, &m_codeTests );
	} else {
		GetTestCodeArithmeticInternal( GEN_OP_ARITHMETIC_DIV, valuesLhs, valuesRhs, &m_codeTests );
	}
	String_Append( &m_codeTests, "}\n" );
	String_Append( &m_codeTests, "\n" );

	for ( u32 i = 0; i < GEN_OP_ARITHMETIC_COUNT; i++ ) {
		String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testNames[i] );
	}
}

void GeneratorMatrixTests::GenerateTestMultiplyVector() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( m_numRows != m_numCols ) {
		return;
	}

	char testName[64] = { 0 };
	snprintf( testName, 64, "TestMultiplyVector_%s", m_fullTypeName );

	float valuesMat[4][4] = {
		{ 1.0f,  2.0f,  3.0f,  4.0f  },
		{ 5.0f,  6.0f,  7.0f,  8.0f  },
		{ 9.0f,  10.0f, 11.0f, 12.0f },
		{ 13.0f, 14.0f, 15.0f, 16.0f }
	};

	float valuesVec[4] = {
		2.0f, 1.0f, 4.0f, 3.0f
	};

	char parmListMat[256]	= { 0 };
	char parmListVec[64]	= { 0 };

	Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, valuesMat, parmListMat );
	Gen_GetParmListVector( m_type, m_numCols, valuesVec, parmListVec );

	char parmListVecAnswer[64] = { 0 };
	int pos = 0;

	pos += sprintf( parmListVecAnswer + pos, "( " );
	for ( u32 col = 0; col < m_numCols; col++ ) {
		// get the left-hand row
		float matRow[GEN_COMPONENT_COUNT_MAX];
		for ( size_t lhsComponent = 0; lhsComponent < m_numCols; lhsComponent++ ) {
			matRow[lhsComponent] = valuesMat[col][lhsComponent];
		}

		// do the dot product procedurally
		float dots[GEN_COMPONENT_COUNT_MAX];
		for ( size_t i = 0; i < m_numCols; i++ ) {
			dots[i] = matRow[i] * valuesVec[i];
		}

		float dot = 0.0f;
		for ( size_t i = 0; i < m_numCols; i++ ) {
			dot += dots[i];
		}

		char dotStr[16];
		Gen_GetNumericLiteral( m_type, dot, dotStr );

		pos += sprintf( parmListVecAnswer + pos, "%s", dotStr );

		if ( col != ( m_numCols - 1 ) ) {
			pos += sprintf( parmListVecAnswer + pos, ", " );
		}
	}
	pos += sprintf( parmListVecAnswer + pos, " )" );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s answerVec = %s%s;\n", m_vectorTypeString, m_vectorTypeString, parmListVecAnswer );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s a = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListMat );
	String_Appendf( &m_codeTests, "\t%s b = %s%s;\n", m_vectorTypeString, m_vectorTypeString, parmListVec );
	String_Appendf( &m_codeTests, "\t%s c = a %c b;\n", m_vectorTypeString, GEN_OPERATORS_ARITHMETIC[GEN_OP_ARITHMETIC_MUL] );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( c == answerVec );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorMatrixTests::GenerateTestIncrement() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	char parmList0[256] = { 0 };
	char parmList1[256] = { 0 };

	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 0.0f, parmList0 );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 1.0f, parmList1 );

	const char* parmListVecs[] = {
		parmList0,
		parmList1,
	};

	const char* parmListAnswers[] = {
		parmList1,
		parmList0,
	};

	const char* suffices[GEN_OP_INCREMENT_COUNT] = {
		"Increment",
		"Decrement",
	};

	for ( u32 i = 0; i < GEN_OP_INCREMENT_COUNT; i++ ) {
		char testName[64] = { 0 };
		snprintf( testName, 64, "Test%s_%s", suffices[i], m_fullTypeName );

		String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  &m_codeTests, "{\n" );
		String_Appendf( &m_codeTests, "\t%s mat;\n", m_fullTypeName );
		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\t// prefix\n" );
		String_Appendf( &m_codeTests, "\tmat = %s%s;\n", m_fullTypeName, parmListVecs[i] );
		String_Appendf( &m_codeTests, "\t%smat;\n", GEN_OPERATORS_INCREMENT[i] );
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat == %s%s );\n", m_fullTypeName, parmListAnswers[i] );
		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\t// postfix\n" );
		String_Appendf( &m_codeTests, "\tmat = %s%s;\n", m_fullTypeName, parmListVecs[i] );
		String_Appendf( &m_codeTests, "\tmat%s;\n", GEN_OPERATORS_INCREMENT[i] );
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat == %s%s );\n", m_fullTypeName, parmListAnswers[i] );
		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  &m_codeTests, "}\n" );
		String_Append(  &m_codeTests, "\n" );

		String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

void GeneratorMatrixTests::GenerateTestRelational() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	char testName[64] = { 0 };
	snprintf( testName, 64, "TestRelational_%s", m_fullTypeName );

	char boolTypeName[16] = { 0 };
	snprintf( boolTypeName, 16, "bool%dx%d", m_numRows, m_numCols );

	char parmListTrue[256] = { 0 };
	Gen_GetParmListMatrixSingleValue( GEN_TYPE_BOOL, m_numRows, m_numCols, true, parmListTrue );

	char parmLists[4][256];
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 1, parmLists[0] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 2, parmLists[1] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 3, parmLists[2] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 4, parmLists[3] );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s allTrue = %s%s;\n", boolTypeName, boolTypeName, parmListTrue );
	String_Append(  &m_codeTests, "\n" );
	for ( u32 i = 0; i < 4; i++ ) {
		String_Appendf( &m_codeTests, "\t%s mat%d = %s%s;\n", m_fullTypeName, i, m_fullTypeName, parmLists[i] );
	}
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s test0  = mat0 <= mat0;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test1  = mat0 >= mat0;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test2  = mat0 <  mat1;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test3  = mat0 <  mat2;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test4  = mat0 <  mat3;\n", boolTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s test5  = mat1 >  mat0;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test6  = mat1 <= mat1;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test7  = mat1 >= mat1;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test8  = mat1 <  mat2;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test9  = mat1 <  mat3;\n", boolTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s test10 = mat2 >  mat0;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test11 = mat2 >  mat1;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test12 = mat2 <= mat2;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test13 = mat2 >= mat2;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test14 = mat2 <  mat3;\n", boolTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s test15 = mat3 >  mat0;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test16 = mat3 >  mat1;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test17 = mat3 >  mat2;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test18 = mat3 <= mat3;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test19 = mat3 >= mat3;\n", boolTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test0  == allTrue );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test1  == allTrue );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test2  == allTrue );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test3  == allTrue );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test4  == allTrue );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test5  == allTrue );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test6  == allTrue );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test7  == allTrue );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test8  == allTrue );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test9  == allTrue );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test10 == allTrue );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test11 == allTrue );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test12 == allTrue );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test13 == allTrue );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test14 == allTrue );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test15 == allTrue );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test16 == allTrue );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test17 == allTrue );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test18 == allTrue );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( test19 == allTrue );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorMatrixTests::GenerateTestBitwise() {
	if ( !Gen_IsIntegerType( m_type ) ) {
		return;
	}

	char unaryValueStr[32] = { 0 };
	snprintf( unaryValueStr, 32, "(%s) -1", m_memberTypeString );

	char parmStr[16];
	snprintf( parmStr, 16, "(%s) -1", m_memberTypeString );

	char parmListAnswerUnary[256];
	Gen_GetParmListMatrixSingleValueStr( m_numRows, m_numCols, parmStr, parmListAnswerUnary );

	// values must be integers
	char parmListLhs[GEN_OP_BITWISE_COUNT - 1][256];
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 21.0f, parmListLhs[0] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 21.0f, parmListLhs[1] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 21.0f, parmListLhs[2] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 1.0f , parmListLhs[3] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 16.0f, parmListLhs[4] );

	char parmListRhs[GEN_OP_BITWISE_COUNT - 1][256];
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 7.0f, parmListRhs[0] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 7.0f, parmListRhs[1] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 7.0f, parmListRhs[2] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 2.0f, parmListRhs[3] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 4.0f, parmListRhs[4] );

	char parmListAnswers[GEN_OP_BITWISE_COUNT - 1][256];
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 5.0f,  parmListAnswers[0] );	// 21 & 7
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 23.0f, parmListAnswers[1] );	// 21 | 7
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 18.0f, parmListAnswers[2] );	// 21 ^ 7
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 4.0f,  parmListAnswers[3] );	// 1  << 2
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 1.0f,  parmListAnswers[4] );	// 16 >> 4

	// do unary separately because it takes no rhs parm
	const char* suffices[GEN_OP_BITWISE_COUNT - 1] = {
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

	char testName[64] = { 0 };

	for ( u32 i = 0; i < _countof( ops ); i++ ) {
		snprintf( testName, 64, "TestBitwise_%s_%s", suffices[i], m_fullTypeName );

		String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  &m_codeTests, "{\n" );
		String_Appendf( &m_codeTests, "\t%s a  = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListLhs[i] );
		String_Appendf( &m_codeTests, "\t%s b  = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListRhs[i] );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s answer = a %s b;\n", m_fullTypeName, GEN_OPERATORS_BITWISE[ops[i]] );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( answer == %s%s );\n", m_fullTypeName, parmListAnswers[i] );
		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  &m_codeTests, "}\n" );
		String_Append(  &m_codeTests, "\n" );

		String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}

	// unary
	{
		snprintf( testName, 64, "TestBitwise_Unary_%s", m_fullTypeName );

		char parmList[256];
		Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 0.0f, parmList );

		String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  &m_codeTests, "{\n" );
		String_Appendf( &m_codeTests, "\t%s a = %s%s;\n", m_fullTypeName, m_fullTypeName, parmList );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s answer = %sa;\n", m_fullTypeName, GEN_OPERATORS_BITWISE[GEN_OP_BITWISE_UNARY] );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( answer == %s%s );\n", m_fullTypeName, parmListAnswerUnary );
		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  &m_codeTests, "}\n" );
		String_Append(  &m_codeTests, "\n" );

		String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

void GeneratorMatrixTests::GenerateTestArray() {
	char zeroStr[16];
	char oneStr[16];

	Gen_GetNumericLiteral( m_type, 0, zeroStr );
	Gen_GetNumericLiteral( m_type, 1, oneStr );

	char testName[64] = { 0 };
	snprintf( testName, 64, "TestArray_%s", m_fullTypeName );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Appendf( &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s mat;\n", m_fullTypeName );
	String_Appendf( &m_codeTests, "\n" );
	for ( u32 row = 0; row < m_numRows; row++ ) {
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat[%d] == %s( ", row, m_vectorTypeString );

		for ( u32 col = 0; col < m_numCols; col++ ) {
			String_Appendf( &m_codeTests, "%s", ( row == col ) ? oneStr : zeroStr );

			if ( col != m_numCols - 1 ) {
				String_Append( &m_codeTests, ", " );
			}
		}

		String_Append( &m_codeTests, " ) );\n" );
	}
	String_Append( &m_codeTests, "\n" );
	String_Append( &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append( &m_codeTests, "}\n" );
	String_Append( &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorMatrixTests::GenerateTestIdentity() {
	char testName[64] = { 0 };
	snprintf( testName, 64, "TestIdentity_%s", m_fullTypeName );

	char zeroStr[16];
	char oneStr[16];

	Gen_GetNumericLiteral( m_type, 0, zeroStr );
	Gen_GetNumericLiteral( m_type, 1, oneStr );

	char parmListIdentity[256] = { 0 };
	Gen_GetParmListMatrixIdentity( m_type, m_numRows, m_numCols, parmListIdentity );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s id = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListIdentity );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s mat;\n", m_fullTypeName );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat == id );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tidentity( mat );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat == id );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorMatrixTests::GenerateTestTranspose() {
	char testName[64] = { 0 };
	snprintf( testName, 64, "TestTranspose_%s", m_fullTypeName );

	float valuesNormal[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX] = {
		{ 0.0f,  1.0f,  2.0f,  3.0f  },
		{ 4.0f,  5.0f,  6.0f,  7.0f  },
		{ 8.0f,  9.0f,  10.0f, 11.0f },
		{ 12.0f, 13.0f, 14.0f, 15.0f }
	};

	float valuesTransposed[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX] = {
		{ 0.0f, 4.0f, 8.0f,  12.0f },
		{ 1.0f, 5.0f, 9.0f,  13.0f },
		{ 2.0f, 6.0f, 10.0f, 14.0f },
		{ 3.0f, 7.0f, 11.0f, 15.0f }
	};

	char parmListNormal[256]		= { 0 };
	char parmListTransposed[256]	= { 0 };

	Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, valuesNormal, parmListNormal );
	Gen_GetParmListMatrix( m_type, m_numCols, m_numRows, valuesTransposed, parmListTransposed );

	char transposeTypeName[32] = { 0 };
	snprintf( transposeTypeName, 32, "%s%dx%d", m_typeString, m_numCols, m_numRows );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s mat = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListNormal );
	String_Appendf( &m_codeTests, "\t%s trans = transpose( mat );\n", transposeTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( trans == %s%s );\n", transposeTypeName, parmListTransposed );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorMatrixTests::GenerateTestInverse() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	if ( m_numRows != m_numCols ) {
		return;
	}

	char testName[64] = { 0 };
	snprintf( testName, 64, "TestInverse_%s", m_fullTypeName );

	// matrices chosen because they gave nice whole numbers for determinants
	float mat2x2[4][4] = {
		{  6.0f,  2.0f, -1.0f, -1.0f },
		{  2.0f,  6.0f, -1.0f, -1.0f },
		{ -1.0f, -1.0f, -1.0f, -1.0f },
		{ -1.0f, -1.0f, -1.0f, -1.0f },
	};

	float mat3x3[4][4] = {
		{  6.0f,  2.0f,  3.0f, -1.0f },
		{  2.0f,  7.0f,  2.0f, -1.0f },
		{  3.0f,  2.0f,  6.0f, -1.0f },
		{ -1.0f, -1.0f, -1.0f, -1.0f },
	};

	float mat4x4[4][4] = {
		{ 6.0f, 2.0f, 3.0f, 4.0f },
		{ 2.0f, 7.0f, 5.0f, 3.0f },
		{ 3.0f, 5.0f, 7.0f, 2.0f },
		{ 4.0f, 3.0f, 2.0f, 6.0f }
	};

	char parmList[256] = { 0 };

	switch ( m_numRows ) {
		case 2:
			Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, mat2x2, parmList );
			break;

		case 3:
			Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, mat3x3, parmList );
			break;

		case 4:
			Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, mat4x4, parmList );
			break;
	}

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s identityMatrix;\n", m_fullTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s mat = %s%s;\n", m_fullTypeName, m_fullTypeName, parmList );
	String_Appendf( &m_codeTests, "\t%s matInverse = inverse( mat );\n", m_fullTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat * matInverse == identityMatrix );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorMatrixTests::GenerateTestDeterminant() {
	if ( m_type == GEN_TYPE_BOOL || m_type == GEN_TYPE_UINT ) {
		return;
	}

	if ( m_numRows != m_numCols ) {
		return;
	}

	char testName[64] = { 0 };
	snprintf( testName, 64, "TestDeterminant_%s", m_fullTypeName );

	// matrices chosen because they gave nice whole numbers for determinants
	float mat2x2[4][4] = {
		{  6.0f,  2.0f, -1.0f, -1.0f },
		{  2.0f,  6.0f, -1.0f, -1.0f },
		{ -1.0f, -1.0f, -1.0f, -1.0f },
		{ -1.0f, -1.0f, -1.0f, -1.0f },
	};

	float mat3x3[4][4] = {
		{  6.0f,  2.0f,  3.0f, -1.0f },
		{  2.0f,  7.0f,  2.0f, -1.0f },
		{  3.0f,  2.0f,  6.0f, -1.0f },
		{ -1.0f, -1.0f, -1.0f, -1.0f },
	};

	float mat4x4[4][4] = {
		{ 6.0f, 2.0f, 3.0f, 4.0f },
		{ 2.0f, 7.0f, 5.0f, 3.0f },
		{ 3.0f, 5.0f, 7.0f, 2.0f },
		{ 4.0f, 3.0f, 2.0f, 6.0f }
	};

	float determinants[3] = {
		32.0f,	// 2x2
		165.0f,	// 3x3
		285.0f	// 4x4
	};

	char answerStr[16];
	Gen_GetNumericLiteral( m_type, determinants[m_numRows - 2], answerStr );

	char parmList[256];

	switch ( m_numRows ) {
		case 2:
			Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, mat2x2, parmList );
			break;

		case 3:
			Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, mat3x3, parmList );
			break;

		case 4:
			Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, mat4x4, parmList );
			break;
	}

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Appendf( &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s mat = %s%s;\n", m_fullTypeName, m_fullTypeName, parmList );
	String_Appendf( &m_codeTests, "\t%s det = determinant( mat );\n", m_memberTypeString );
	String_Appendf( &m_codeTests, "\n" );
	if ( Gen_IsFloatingPointType( m_type ) ) {
		const char* floateqStr = Gen_GetFuncNameFloateq( m_type );

		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( det, %s ) );\n", floateqStr, answerStr );
	} else {
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( det == %s );\n", answerStr );
	}
	String_Append( &m_codeTests, "\n" );
	String_Append( &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append( &m_codeTests, "}\n" );
	String_Append( &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorMatrixTests::GenerateTestTranslate() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( m_numRows < 3 || m_numCols < m_numRows ) {
		return;
	}

	char testName[64] = { 0 };
	snprintf( testName, 64, "TestTranslate_%s", m_fullTypeName );

	char valueStr[16];

	u32 baseNumber = 2;

	char translateVectorTypeString[16];
	snprintf( translateVectorTypeString, 16, "%s%d", m_typeString, m_numCols - 1 );

	char parmListTranslateVector[64] = { 0 };
	int pos = 0;

	pos += sprintf( parmListTranslateVector + pos, "( " );
	for ( u32 col = 0; col < m_numCols - 1; col++ ) {
		float number = static_cast<float>( col + baseNumber );

		Gen_GetNumericLiteral( m_type, number, valueStr );

		pos += sprintf( parmListTranslateVector + pos, "%s", valueStr );

		if ( col != m_numCols - 2 ) {
			pos += sprintf( parmListTranslateVector + pos, ", " );
		}
	}
	pos += sprintf( parmListTranslateVector + pos, " )" );

	char parmListTranslated[256] = { 0 };
	pos = 0;

	pos += sprintf( parmListTranslated + pos, "(\n" );
	for ( u32 row = 0; row < m_numRows; row++ ) {
		pos += sprintf( parmListTranslated + pos, "\t\t" );

		for ( u32 col = 0; col < m_numCols; col++ ) {
			if ( row == col ) {
				Gen_GetNumericLiteral( m_type, 1, valueStr );

				pos += sprintf( parmListTranslated + pos, "%s", valueStr );
			} else {
				if ( col == m_numCols - 1 ) {
					float number = static_cast<float>( row + baseNumber );

					Gen_GetNumericLiteral( m_type, number, valueStr );

					pos += sprintf( parmListTranslated + pos, "%s", valueStr );
				} else {
					Gen_GetNumericLiteral( m_type, 0.0f, valueStr );
					pos += sprintf( parmListTranslated + pos, "%s", valueStr );
				}
			}

			if ( row + col != ( m_numRows - 1 ) + ( m_numCols - 1 ) ) {
				pos += sprintf( parmListTranslated + pos, "," );
			}

			if ( col != m_numCols - 1 ) {
				pos += sprintf( parmListTranslated + pos, " " );
			}
		}

		pos += sprintf( parmListTranslated + pos, "\n" );
	}
	pos += sprintf( parmListTranslated + pos, "\t)" );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s mat;\n", m_fullTypeName );
	String_Appendf( &m_codeTests, "\t%s translated = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListTranslated );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s translation = %s%s;\n", translateVectorTypeString, translateVectorTypeString, parmListTranslateVector );
	String_Appendf( &m_codeTests, "\tmat = translate( mat, translation );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat == translated );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorMatrixTests::GenerateTestRotate() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	if ( m_numRows < 3 ) {
		return;
	}

	if ( m_numRows != m_numCols ) {
		return;
	}

	char testName[64] = { 0 };
	snprintf( testName, 64, "TestRotate_%s", m_fullTypeName );

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

	u32 numRotMatRows = GEN_MIN( m_numRows, 4 );
	u32 numRotMatCols = GEN_MIN( m_numCols, 4 );

	u32 numRotateVectorComponents = m_numCols - 1;

	char rotDegreesStr[16];
	Gen_GetNumericLiteral( m_type, rotDegrees, rotDegreesStr );

	char rotateVecTypeString[16];
	snprintf( rotateVecTypeString, 16, "%s%d", m_typeString, numRotateVectorComponents );

	char parmListVecYaw[64];
	char parmListVecPitch[64];
	char parmListVecRoll[64];

	char parmListMatYaw[256];
	char parmListMatPitch[256];
	char parmListMatRoll[256];

	Gen_GetParmListVector( m_type, numRotateVectorComponents, angleAxisVecYaw, parmListVecYaw );
	Gen_GetParmListVector( m_type, numRotateVectorComponents, angleAxisVecPitch, parmListVecPitch );
	Gen_GetParmListVector( m_type, numRotateVectorComponents, angleAxisVecRoll, parmListVecRoll );

	Gen_GetParmListMatrix( m_type, numRotMatRows, numRotMatCols, rotMatYaw, parmListMatYaw );
	Gen_GetParmListMatrix( m_type, numRotMatRows, numRotMatCols, rotMatPitch, parmListMatPitch );
	Gen_GetParmListMatrix( m_type, numRotMatRows, numRotMatCols, rotMatRoll, parmListMatRoll );

	// matrices where cols == 3 only have roll rotation support
	char parmListRotateRoll[256] = { 0 };
	int pos = 0;
	pos += sprintf( parmListRotateRoll + pos, "mat, radians( %s )", rotDegreesStr );
	if ( m_numCols > 3 ) {
		pos += sprintf( parmListRotateRoll + pos, ", %s%s", rotateVecTypeString, parmListVecRoll );
	}

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s mat;\n", m_fullTypeName );
	if ( m_numRows > 3 ) {
		String_Appendf( &m_codeTests, "\t%s yaw = rotate( mat, radians( %s ), %s%s );\n", m_fullTypeName, rotDegreesStr, rotateVecTypeString, parmListVecYaw );
		String_Appendf( &m_codeTests, "\t%s pitch = rotate( mat, radians( %s ), %s%s );\n", m_fullTypeName, rotDegreesStr, rotateVecTypeString, parmListVecPitch );
	}
	String_Appendf( &m_codeTests, "\t%s roll = rotate( %s );\n", m_fullTypeName, parmListRotateRoll );
	String_Append(  &m_codeTests, "\n" );
	if ( m_numRows > 3 ) {
		String_Appendf( &m_codeTests, "\t%s answerYaw = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListMatYaw );
		String_Appendf( &m_codeTests, "\t%s answerPitch = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListMatPitch );
	}
	String_Appendf( &m_codeTests, "\t%s answerRoll = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListMatRoll );
	String_Append(  &m_codeTests, "\n" );
	if ( m_numRows > 3 ) {
		String_Append( &m_codeTests, "\tTEMPER_EXPECT_TRUE( yaw == answerYaw );\n" );
		String_Append( &m_codeTests, "\tTEMPER_EXPECT_TRUE( pitch == answerPitch );\n" );
	}
	String_Append( &m_codeTests, "\tTEMPER_EXPECT_TRUE( roll == answerRoll );\n" );
	String_Append( &m_codeTests, "\n" );
	String_Append( &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append( &m_codeTests, "}\n" );
	String_Append( &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorMatrixTests::GenerateTestScale() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( m_numCols < 3 && m_numCols < m_numRows ) {
		return;
	}

	char testName[64] = { 0 };
	snprintf( testName, 64, "TestScale_%s", m_fullTypeName );

	const u32 scaleCols = 3;

	float scaleMatDiagonal[] = { 2.0f, 2.0f, 2.0f, 1.0f };

	char parmListScaleVec[64]	= { 0 };
	char parmListscaleMat[256]	= { 0 };

	Gen_GetParmListVector( m_type, scaleCols, scaleMatDiagonal, parmListScaleVec );
	Gen_GetParmListMatrixDiagonal( m_type, m_numRows, m_numCols, scaleMatDiagonal, _countof( scaleMatDiagonal ), parmListscaleMat );

	char scaleVecTypeString[32] = { 0 };
	snprintf( scaleVecTypeString, 32, "%s%d", m_typeString, scaleCols );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s mat;\n", m_fullTypeName );
	String_Appendf( &m_codeTests, "\t%s scaled = scale( mat, %s%s );\n", m_fullTypeName, scaleVecTypeString, parmListScaleVec );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( scaled == %s%s );\n", m_fullTypeName, parmListscaleMat );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorMatrixTests::GenerateTestOrtho() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	if ( m_numRows < 4 || m_numCols < 4 ) {
		return;
	}

	char testName[64] = { 0 };
	snprintf( testName, 64, "TestOrtho_%s", m_fullTypeName );

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

	char parmListAnswerOrtho_LH_ZO[256] = { 0 };
	char parmListAnswerOrtho_LH_NO[256] = { 0 };
	char parmListAnswerOrtho_RH_ZO[256] = { 0 };
	char parmListAnswerOrtho_RH_NO[256] = { 0 };

	Gen_GetParmListMatrix( m_type, 4, 4, answerOrtho_LH_ZO, parmListAnswerOrtho_LH_ZO );
	Gen_GetParmListMatrix( m_type, 4, 4, answerOrtho_LH_NO, parmListAnswerOrtho_LH_NO );
	Gen_GetParmListMatrix( m_type, 4, 4, answerOrtho_RH_ZO, parmListAnswerOrtho_RH_ZO );
	Gen_GetParmListMatrix( m_type, 4, 4, answerOrtho_RH_NO, parmListAnswerOrtho_RH_NO );

	char minusOneStr[16];
	char fiveStr[16];
	char oneHundredStr[16];

	char widthStr[16];
	char heightStr[16];

	Gen_GetNumericLiteral( m_type, -1.0f,   minusOneStr );
	Gen_GetNumericLiteral( m_type,  5.0f,   fiveStr );
	Gen_GetNumericLiteral( m_type,  100.0f, oneHundredStr );

	Gen_GetNumericLiteral( m_type, 1280.0f, widthStr );
	Gen_GetNumericLiteral( m_type, 720.0f,  heightStr );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s answerOrtho_LH_ZO = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListAnswerOrtho_LH_ZO );
	String_Appendf( &m_codeTests, "\t%s answerOrtho_LH_NO = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListAnswerOrtho_LH_NO );
	String_Appendf( &m_codeTests, "\t%s answerOrtho_RH_ZO = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListAnswerOrtho_RH_ZO );
	String_Appendf( &m_codeTests, "\t%s answerOrtho_RH_NO = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListAnswerOrtho_RH_NO );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s width     = %s;\n", m_typeString, widthStr );
	String_Appendf( &m_codeTests, "\t%s height    = %s;\n", m_typeString, heightStr );
	String_Appendf( &m_codeTests, "\t%s aspect    = width / height;\n", m_typeString );
	String_Appendf( &m_codeTests, "\t%s orthoSize = %s;\n", m_typeString, fiveStr );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s left   = -aspect * orthoSize;\n", m_typeString );
	String_Appendf( &m_codeTests, "\t%s right  =  aspect * orthoSize;\n", m_typeString );
	String_Appendf( &m_codeTests, "\t%s top    = -orthoSize;\n", m_typeString );
	String_Appendf( &m_codeTests, "\t%s bottom =  orthoSize;\n", m_typeString );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s mat_LH_ZO = ortho_lh_zo( left, right, top, bottom, %s, %s );\n", m_fullTypeName, minusOneStr, oneHundredStr );
	String_Appendf( &m_codeTests, "\t%s mat_LH_NO = ortho_lh_no( left, right, top, bottom, %s, %s );\n", m_fullTypeName, minusOneStr, oneHundredStr );
	String_Appendf( &m_codeTests, "\t%s mat_RH_ZO = ortho_rh_zo( left, right, top, bottom, %s, %s );\n", m_fullTypeName, minusOneStr, oneHundredStr );
	String_Appendf( &m_codeTests, "\t%s mat_RH_NO = ortho_rh_no( left, right, top, bottom, %s, %s );\n", m_fullTypeName, minusOneStr, oneHundredStr );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat_LH_ZO == answerOrtho_LH_ZO );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat_LH_NO == answerOrtho_LH_NO );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat_RH_ZO == answerOrtho_RH_ZO );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat_RH_NO == answerOrtho_RH_NO );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorMatrixTests::GenerateTestPerspective() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	if ( m_numRows < 4 || m_numCols < 4 ) {
		return;
	}

	char testName[64] = { 0 };
	snprintf( testName, 64, "TestPerspective_%s", m_fullTypeName );

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

	char parmListPerspective_LH_ZO[256] = { 0 };
	char parmListPerspective_LH_NO[256] = { 0 };
	char parmListPerspective_RH_ZO[256] = { 0 };
	char parmListPerspective_RH_NO[256] = { 0 };

	Gen_GetParmListMatrix( m_type, 4, 4, answerPerspective_LH_ZO, parmListPerspective_LH_ZO );
	Gen_GetParmListMatrix( m_type, 4, 4, answerPerspective_LH_NO, parmListPerspective_LH_NO );
	Gen_GetParmListMatrix( m_type, 4, 4, answerPerspective_RH_ZO, parmListPerspective_RH_ZO );
	Gen_GetParmListMatrix( m_type, 4, 4, answerPerspective_RH_NO, parmListPerspective_RH_NO );

	char widthStr[16];
	char heightStr[16];

	char fovStr[16];
	char znearStr[16];
	char zfarStr[16];

	Gen_GetNumericLiteral( m_type, 1280.0f, widthStr );
	Gen_GetNumericLiteral( m_type, 720.0f, heightStr );

	Gen_GetNumericLiteral( m_type, 90.0f, fovStr );
	Gen_GetNumericLiteral( m_type, 0.1f, znearStr );
	Gen_GetNumericLiteral( m_type, 100.0f, zfarStr );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s answerPerspective_LH_ZO = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListPerspective_LH_ZO );
	String_Appendf( &m_codeTests, "\t%s answerPerspective_LH_NO = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListPerspective_LH_NO );
	String_Appendf( &m_codeTests, "\t%s answerPerspective_RH_ZO = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListPerspective_RH_ZO );
	String_Appendf( &m_codeTests, "\t%s answerPerspective_RH_NO = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListPerspective_RH_NO );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s aspect = %s / %s;\n", m_typeString, widthStr, heightStr );
	String_Appendf( &m_codeTests, "\t%s mat_LH_ZO = perspective_lh_zo( %s, aspect, %s, %s );\n", m_fullTypeName, fovStr, znearStr, zfarStr );
	String_Appendf( &m_codeTests, "\t%s mat_LH_NO = perspective_lh_no( %s, aspect, %s, %s );\n", m_fullTypeName, fovStr, znearStr, zfarStr );
	String_Appendf( &m_codeTests, "\t%s mat_RH_ZO = perspective_rh_zo( %s, aspect, %s, %s );\n", m_fullTypeName, fovStr, znearStr, zfarStr );
	String_Appendf( &m_codeTests, "\t%s mat_RH_NO = perspective_rh_no( %s, aspect, %s, %s );\n", m_fullTypeName, fovStr, znearStr, zfarStr );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat_LH_ZO == answerPerspective_LH_ZO );\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat_LH_NO == answerPerspective_LH_NO );\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat_RH_ZO == answerPerspective_RH_ZO );\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat_RH_NO == answerPerspective_RH_NO );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorMatrixTests::GenerateTestLookAt() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	if ( m_numRows < 4 || m_numCols < 4 ) {
		return;
	}

	char testName[64] = { 0 };
	snprintf( testName, 64, "TestLookAt_%s", m_fullTypeName );

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

	u32 numTranslateVecComponents = 3;

	char posVectorTypeName[32] = { 0 };
	snprintf( posVectorTypeName, 32, "%s%d", m_typeString, numTranslateVecComponents );

	char parmListCurrentPos[64]		= { 0 };
	char parmListTargetPos[64]		= { 0 };
	char parmListUp[64]				= { 0 };

	Gen_GetParmListVector( m_type, numTranslateVecComponents, currentPos, parmListCurrentPos );
	Gen_GetParmListVector( m_type, numTranslateVecComponents, targetPos, parmListTargetPos );
	Gen_GetParmListVector( m_type, numTranslateVecComponents, up, parmListUp );

	char parmListLookAt_LH[256] = { 0 };
	char parmListLookAt_RH[256] = { 0 };

	Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, answerLookAt_LH, parmListLookAt_LH );
	Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, answerLookAt_RH, parmListLookAt_RH );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s answerLookAt_LH = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListLookAt_LH );
	String_Appendf( &m_codeTests, "\t%s answerLookAt_RH = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListLookAt_RH );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s currentPos = %s%s;\n", posVectorTypeName, posVectorTypeName, parmListCurrentPos );
	String_Appendf( &m_codeTests, "\t%s targetPos = %s%s;\n", posVectorTypeName, posVectorTypeName, parmListTargetPos );
	String_Appendf( &m_codeTests, "\t%s up = %s%s;\n", posVectorTypeName, posVectorTypeName, parmListUp );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s mat_LH = lookat_lh( currentPos, targetPos, up );\n", m_fullTypeName );
	String_Appendf( &m_codeTests, "\t%s mat_RH = lookat_rh( currentPos, targetPos, up );\n", m_fullTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat_LH == answerLookAt_LH );\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat_RH == answerLookAt_RH );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorMatrixTests::GetTestCodeArithmeticInternal( const genOpArithmetic_t op,
	const float valuesLhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], const float valuesRhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], stringBuilder_t* sb ) const {
	assert( op >= 0 );
	assert( op < GEN_OP_ARITHMETIC_COUNT );
	assert( valuesLhs );
	assert( valuesRhs );

	u32 rhsRows = m_numRows;
	u32 rhsCols = m_numCols;

	u32 returnTypeRows = m_numRows;
	u32 returnTypeCols = m_numCols;

	const char* lhsTypeName = m_fullTypeName;
	char rhsTypeName[16] = { 0 };
	char returnTypeName[16] = { 0 };

	// for non-square matrices you can only do proper multiply and divide by the transposed type
	if ( op == GEN_OP_ARITHMETIC_MUL ) {
		rhsRows = m_numCols;
		rhsCols = m_numRows;

		returnTypeRows = m_numRows;
		returnTypeCols = m_numRows;

		snprintf( rhsTypeName, 16, "%s%dx%d", m_typeString, m_numCols, m_numRows );
		snprintf( returnTypeName, 16, "%s%dx%d", m_typeString, m_numRows, m_numRows );
	} else {
		size_t len = strlen( lhsTypeName );

		strncpy( returnTypeName, lhsTypeName, len );
		strncpy( rhsTypeName, lhsTypeName, len );
	}

	char parmListLhs[256]	= { 0 };
	char parmListRhs[256]	= { 0 };

	Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, valuesLhs, parmListLhs );
	Gen_GetParmListMatrix( m_type, rhsRows, rhsCols, valuesRhs, parmListRhs );

	// for division, just divide a matrix by itself and check it equals identity
	char parmListAnswer[256] = { 0 };
	if ( op == GEN_OP_ARITHMETIC_DIV && ( m_numRows == m_numCols && Gen_IsFloatingPointType( m_type ) ) ) {
		Gen_GetParmListMatrixIdentity( m_type, m_numRows, m_numCols, parmListAnswer );
	} else {
		GetParmListArithmeticAnswer( op, returnTypeRows, returnTypeCols, valuesLhs, valuesRhs, parmListAnswer );
	}

	String_Appendf( sb, "\t%s answer = %s%s;\n", returnTypeName, returnTypeName, parmListAnswer );
	String_Append(  sb, "\n" );
	String_Appendf( sb, "\t%s a = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListLhs );
	String_Appendf( sb, "\t%s b = %s%s;\n", rhsTypeName, rhsTypeName, parmListRhs );
	String_Appendf( sb, "\t%s c = a %c b;\n", returnTypeName, GEN_OPERATORS_ARITHMETIC[op] );
	String_Append(  sb, "\n" );
	String_Append(  sb, "\tTEMPER_EXPECT_TRUE( c == answer );\n" );
	String_Append(  sb, "\n" );
	String_Append(  sb, "\tTEMPER_PASS();\n" );
}

void GeneratorMatrixTests::GetParmListArithmeticAnswer( const genOpArithmetic_t op, const u32 numRows, const u32 numCols,
	const float valuesLhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], const float valuesRhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], char* outString ) const {
	assert( op >= 0 );
	assert( op < GEN_OP_ARITHMETIC_COUNT );

	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	assert( valuesLhs );
	assert( valuesRhs );

	char valueStr[16];

	int pos = 0;

	pos += sprintf( outString + pos, "(\n" );

	switch ( op ) {
		case GEN_OP_ARITHMETIC_ADD: {
			for ( u32 row = 0; row < numRows; row++ ) {
				pos += sprintf( outString + pos, "\t\t" );

				for ( u32 col = 0; col < numCols; col++ ) {
					float lhs = valuesLhs[row][col];
					float rhs = valuesRhs[row][col];

					Gen_GetNumericLiteral( m_type, lhs + rhs, valueStr );

					pos += sprintf( outString + pos, "%s", valueStr );

					if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
						pos += sprintf( outString + pos, "," );
					}

					if ( col != numCols - 1 ) {
						pos += sprintf( outString + pos, " " );
					}
				}

				pos += sprintf( outString + pos, "\n" );
			}

			break;
		}

		case GEN_OP_ARITHMETIC_SUB: {
			for ( u32 row = 0; row < numRows; row++ ) {
				pos += sprintf( outString + pos, "\t\t" );

				for ( u32 col = 0; col < numCols; col++ ) {
					float lhs = valuesLhs[row][col];
					float rhs = valuesRhs[row][col];

					Gen_GetNumericLiteral( m_type, lhs - rhs, valueStr );

					pos += sprintf( outString + pos, "%s", valueStr );

					if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
						pos += sprintf( outString + pos, "," );
					}

					if ( col != numCols - 1 ) {
						pos += sprintf( outString + pos, " " );
					}
				}

				pos += sprintf( outString + pos, "\n" );
			}

			break;
		}

		case GEN_OP_ARITHMETIC_MUL: {
			for ( u32 row = 0; row < numRows; row++ ) {
				pos += sprintf( outString + pos, "\t\t" );

				for ( u32 col = 0; col < numCols; col++ ) {
					// get the left-hand row
					float lhsRow[4];
					for ( size_t lhsComponent = 0; lhsComponent < m_numCols; lhsComponent++ ) {
						lhsRow[lhsComponent] = valuesLhs[row][lhsComponent];
					}

					// get the right-hand column
					float rhsCol[4];
					for ( size_t rhsComponent = 0; rhsComponent < m_numCols; rhsComponent++ ) {
						rhsCol[rhsComponent] = valuesRhs[rhsComponent][col];
					}

					// do the dot product procedurally
					float dots[4];
					for ( size_t i = 0; i < m_numCols; i++ ) {
						dots[i] = lhsRow[i] * rhsCol[i];
					}

					float dot = 0.0f;
					for ( size_t i = 0; i < m_numCols; i++ ) {
						dot += dots[i];
					}

					Gen_GetNumericLiteral( m_type, dot, valueStr );

					pos += sprintf( outString + pos, "%s", valueStr );

					if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
						pos += sprintf( outString + pos, "," );
					}

					if ( col != numCols - 1 ) {
						pos += sprintf( outString + pos, " " );
					}
				}

				pos += sprintf( outString + pos, "\n" );
			}

			break;
		}

		case GEN_OP_ARITHMETIC_DIV: {
			// otherwise just do component-wise division
			for ( u32 row = 0; row < numRows; row++ ) {
				pos += sprintf( outString + pos, "\t\t" );

				for ( u32 col = 0; col < numCols; col++ ) {
					float lhs = valuesLhs[row][col];
					float rhs = valuesRhs[row][col];

					Gen_GetNumericLiteral( m_type, lhs / rhs, valueStr );

					pos += sprintf( outString + pos, "%s", valueStr );

					if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
						pos += sprintf( outString + pos, "," );
					}

					if ( col != numCols - 1 ) {
						pos += sprintf( outString + pos, " " );
					}
				}

				pos += sprintf( outString + pos, "\n" );
			}

			break;
		}

		case GEN_OP_ARITHMETIC_COUNT:
		default:
			printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
			break;
	}

	pos += sprintf( outString + pos, "\t)" );
}
