/*
===========================================================================

HLML Generator.
Copyright (c) Dan Moody 2018 - Present.

This file is part of the HLML Generator.

The HLML Generator is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

The HLML Generator is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with The HLML Generator.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/
#include "GeneratorMatrixTests.h"

#include "defines.h"

#include "FileIO.h"

#include "gen_funcs_vector.h"
#include "gen_funcs_matrix.h"

#include "allocator.h"

#include "gen_common_sse.h"

#include <assert.h>
#include <string.h>

#define _USE_MATH_DEFINES	// for M_PI
#include <math.h>

static const float g_matrixMultiplyTestLHS[4][4] = {
	{ 6.0f,  6.0f,  6.0f,  6.0f  },
	{ 6.0f,  6.0f,  6.0f,  6.0f  },
	{ 12.0f, 12.0f, 12.0f, 12.0f },
	{ 18.0f, 18.0f, 18.0f, 18.0f }
};

static const float g_matrixMultiplyTestRHS[4][4] = {
	{ 1.0f, 1.0f, 1.0f, 1.0f },
	{ 2.0f, 2.0f, 2.0f, 2.0f },
	{ 3.0f, 3.0f, 3.0f, 3.0f },
	{ 6.0f, 6.0f, 6.0f, 6.0f }
};

static char g_matrixMultiplyParmListLHS[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
static char g_matrixMultiplyParmListRHS[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
static char g_matrixMultiplyParmListAnswer[GEN_STRING_LENGTH_PARM_LIST_MATRIX];

bool GeneratorMatrixTests::Generate( const genType_t type, const u32 numRows, const u32 numCols ) {
	const u32 testsCodeBytes = 90 * KB_TO_BYTES;
	const u32 suiteCodeBytes = 12 * KB_TO_BYTES;

	m_codeTests = String_Create( testsCodeBytes );
	m_codeSuite = String_Create( suiteCodeBytes );

	m_type = type;

	m_numRows = numRows;
	m_numCols = numCols;

	m_typeString = Gen_GetTypeString( type );
	m_memberTypeString = Gen_GetMemberTypeString( type );

	snprintf( m_vectorTypeString, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", m_typeString, numCols );
	snprintf( m_fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", m_typeString, numRows, numCols );

	Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, g_matrixMultiplyTestLHS, g_matrixMultiplyParmListLHS );
	Gen_GetParmListMatrix( m_type, m_numCols, m_numRows, g_matrixMultiplyTestRHS, g_matrixMultiplyParmListRHS );
	GetParmListMatrixMultiply( m_numRows, m_numRows, g_matrixMultiplyTestLHS, g_matrixMultiplyTestRHS, g_matrixMultiplyParmListAnswer );

	stringBuilder_t code = String_Create( testsCodeBytes + suiteCodeBytes );

	String_Append(  &code, GEN_FILE_HEADER );

	// TODO(DM): if we do end up using this as our final include solution, make the filename a constant
	String_Append( &code, "#include \"hlml.h\"\n" );

	String_Append(  &code, "\n" );
	String_Append(  &code, "#include <temper/temper.h>\n" );
	String_Append(  &code, "\n" );

	{
		char mulTypeNameRHS[GEN_STRING_LENGTH_TYPE_NAME];
		Gen_GetFullTypeName( m_type, m_numCols, m_numRows, mulTypeNameRHS );

		char mulTypeNameReturn[GEN_STRING_LENGTH_TYPE_NAME];
		Gen_GetFullTypeName( m_type, m_numRows, m_numRows, mulTypeNameReturn );

		String_Appendf( &code, "static %s g_identityMatrix_%s;\n", m_fullTypeName, m_fullTypeName );
		String_Append(  &code, "\n" );
		String_Appendf( &code, "static %s g_matrixMulLHS_%s    = %s%s;\n", m_fullTypeName, m_fullTypeName, m_fullTypeName, g_matrixMultiplyParmListLHS );
		String_Appendf( &code, "static %s g_matrixMulRHS_%s    = %s%s;\n", mulTypeNameRHS, m_fullTypeName, mulTypeNameRHS, g_matrixMultiplyParmListRHS );
		String_Appendf( &code, "static %s g_matrixMulAnswer_%s = %s%s;\n", mulTypeNameReturn, m_fullTypeName, mulTypeNameReturn, g_matrixMultiplyParmListAnswer );
		String_Append(  &code, "\n" );
	}

	String_Appendf( &m_codeSuite, "TEMPER_SUITE( Test_%s )\n", m_fullTypeName );
	String_Append(  &m_codeSuite, "{\n" );

	GenerateTestAssignment();

	GenerateTestComponentWiseArithmetic();

	GenerateTestMultiplyMatrix();

	GenerateTestMultiplyVector();

	GenerateTestDivideMatrix();

	GenerateTestIncrement();

	GenerateTestRelational();

	GenerateTestArray();

	GenerateTestBitwise();

	GenerateTestIdentity();

	GenerateTestTranspose();

	GenerateTestDeterminant();

	GenerateTestInverse();

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
	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestAssignment_%s", m_fullTypeName );

	// HACK(DM): this is not ideal for obvious reasons
	float fillValue = 999.0f;
	char fillValueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( m_type, 999, fillValueStr, 1 );

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

	char parmListValues[GEN_STRING_LENGTH_PARM_LIST_MATRIX]			= { 0 };
	char parmListValuesReversed[GEN_STRING_LENGTH_PARM_LIST_MATRIX]	= { 0 };

	Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, values, parmListValues );
	Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, valuesReversed, parmListValuesReversed );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s mat;\n", m_fullTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\t// fill single value\n" );
	String_Appendf( &m_codeTests, "\tmat = %s( %s );\n", m_fullTypeName, fillValueStr );
	for ( u32 row = 0; row < m_numRows; row++ ) {
		char parmList[GEN_STRING_LENGTH_PARM_LIST_VECTOR] = { 0 };
		Gen_GetParmListVector( m_type, m_numCols, valuesIdentity[row], parmList );

		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat[%d] == %s%s );\n", row, m_vectorTypeString, parmList );
	}
	String_Append( &m_codeTests, "\n" );

	String_Append(  &m_codeTests, "\t// row filling\n" );
	String_Appendf( &m_codeTests, "\tmat = %s(\n", m_fullTypeName );
	for ( u32 row = 0; row < m_numRows; row++ ) {
		char parmList[GEN_STRING_LENGTH_PARM_LIST_VECTOR] = { 0 };
		Gen_GetParmListVector( m_type, m_numCols, values[row], parmList );

		String_Appendf( &m_codeTests, "\t\t%s%s", m_vectorTypeString, parmList );

		if ( row != m_numRows - 1 ) {
			String_Append( &m_codeTests, "," );
		}

		String_Append( &m_codeTests, "\n" );
	}
	String_Append( &m_codeTests, "\t);\n" );
	for ( u32 row = 0; row < m_numRows; row++ ) {
		char parmList[GEN_STRING_LENGTH_PARM_LIST_VECTOR] = { 0 };
		Gen_GetParmListVector( m_type, m_numCols, values[row], parmList );

		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat[%d] == %s%s );\n", row, m_vectorTypeString, parmList );
	}
	String_Append( &m_codeTests, "\n" );

	String_Append(  &m_codeTests, "\t// all values filled\n" );
	String_Appendf( &m_codeTests, "\tmat = %s%s;\n", m_fullTypeName, parmListValuesReversed );
	for ( u32 row = 0; row < m_numRows; row++ ) {
		char parmList[GEN_STRING_LENGTH_PARM_LIST_VECTOR] = { 0 };
		Gen_GetParmListVector( m_type, m_numCols, valuesReversed[row], parmList );

		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat[%d] == %s%s );\n", row, m_vectorTypeString, parmList );
	}
	String_Append( &m_codeTests, "\n" );

	String_Append( &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append( &m_codeTests, "}\n" );
	String_Append( &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorMatrixTests::GenerateTestComponentWiseArithmetic() {
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

	const char* suffices[] = {
		"Addition",
		"Subtraction",
		"Multiplication",
		"Division",
	};

	char testNames[GEN_OP_ARITHMETIC_COUNT][GEN_STRING_LENGTH_TEST_NAME];

	for ( u32 i = 0; i < GEN_OP_ARITHMETIC_COUNT; i++ ) {
		snprintf( testNames[i], 64, "TestComponentWiseArithmetic_Scalar_%s_%s", suffices[i], m_fullTypeName );

		genOpArithmetic_t op = (genOpArithmetic_t) i;

		String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testNames[op] );
		String_Append(  &m_codeTests, "{\n" );
		GetTestCodeOperatorArithmeticInternalScalar( op, valuesLhs, valuesRhs, &m_codeTests );
		String_Append( &m_codeTests, "}\n" );
		String_Append( &m_codeTests, "\n" );

		String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testNames[i] );
	}

	if ( Gen_TypeSupportsSSE( m_type ) ) {
		for ( u32 i = 0; i < GEN_OP_ARITHMETIC_COUNT; i++ ) {
			snprintf( testNames[i], 64, "TestComponentWiseArithmetic_SSE_%s_%s", suffices[i], m_fullTypeName );

			genOpArithmetic_t op = (genOpArithmetic_t) i;

			String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testNames[op] );
			String_Append( &m_codeTests, "{\n" );
			GetTestCodeOperatorArithmeticInternalSSE( op, valuesLhs, valuesRhs, &m_codeTests );
			String_Append( &m_codeTests, "}\n" );
			String_Append( &m_codeTests, "\n" );

			String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testNames[i] );
		}
	}
}

void GeneratorMatrixTests::GenerateTestMultiplyVector() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( m_numRows != m_numCols ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestMultiplyVector_%s", m_fullTypeName );

	float valuesMat[4][4] = {
		{ 1.0f,  2.0f,  3.0f,  4.0f  },
		{ 5.0f,  6.0f,  7.0f,  8.0f  },
		{ 9.0f,  10.0f, 11.0f, 12.0f },
		{ 13.0f, 14.0f, 15.0f, 16.0f }
	};

	float valuesVec[4] = {
		2.0f, 1.0f, 4.0f, 3.0f
	};

	char parmListMat[GEN_STRING_LENGTH_PARM_LIST_MATRIX]		= { 0 };
	char parmListVec[GEN_STRING_LENGTH_PARM_LIST_VECTOR]		= { 0 };

	char parmListVecAnswer[GEN_STRING_LENGTH_PARM_LIST_VECTOR]	= { 0 };

	Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, valuesMat, parmListMat );
	Gen_GetParmListVector( m_type, m_numCols, valuesVec, parmListVec );

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

		char dotStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
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

void GeneratorMatrixTests::GenerateTestMultiplyMatrix() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestMultiplyMatrix_Scalar_%s", m_fullTypeName );

	u32 rhsRows = m_numCols;
	u32 rhsCols = m_numRows;

	u32 returnTypeRows = m_numRows;
	u32 returnTypeCols = m_numRows;

	const char* lhsTypeName = m_fullTypeName;

	char rhsTypeName[GEN_STRING_LENGTH_TYPE_NAME] = { 0 };
	char returnTypeName[GEN_STRING_LENGTH_TYPE_NAME] = { 0 };

	snprintf( rhsTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", m_typeString, m_numCols, m_numRows );
	snprintf( returnTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", m_typeString, m_numRows, m_numRows );

	const char* floateqStr = Gen_GetFuncNameFloateq( m_type );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s answer = g_matrixMulAnswer_%s;\n", returnTypeName, m_fullTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s a = g_matrixMulLHS_%s;\n", lhsTypeName, m_fullTypeName );
	String_Appendf( &m_codeTests, "\t%s b = g_matrixMulRHS_%s;\n", rhsTypeName, m_fullTypeName );
	String_Appendf( &m_codeTests, "\t%s c = a %c b;\n", returnTypeName, GEN_OPERATORS_ARITHMETIC[GEN_OP_ARITHMETIC_MUL] );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( c == answer );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );

	if ( Gen_TypeSupportsSSE( m_type ) ) {
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestMultiplyMatrix_SSE_%s", m_fullTypeName );

		char sseLHSName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		char sseRHSName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		char sseReturnName[GEN_STRING_LENGTH_SSE_INPUT_NAME];

		Gen_SSE_GetFullTypeName( m_fullTypeName, sseLHSName );
		Gen_SSE_GetFullTypeName( rhsTypeName, sseRHSName );
		Gen_SSE_GetFullTypeName( returnTypeName, sseReturnName );

		const char* loadFuncStr = Gen_SSE_GetIntrinsicLoad( m_type );
		const char* storeFuncStr = Gen_SSE_GetIntrinsicStore( m_type );

		String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  &m_codeTests, "{\n" );
		for ( u32 row = 0; row < m_numRows; row++ ) {
			for ( u32 col = 0; col < m_numCols; col++ ) {
				float value = g_matrixMultiplyTestLHS[row][col];
				float values[4] = { value, value, value, value };

				String_Appendf( &m_codeTests, "\t%s a%d%d[4] =", m_memberTypeString, row, col );
				Gen_GetValuesArray1D( m_type, 4, values, &m_codeTests );
				String_Append(  &m_codeTests, ";\n" );
			}
		}
		String_Append(  &m_codeTests, "\n" );
		for ( u32 row = 0; row < rhsRows; row++ ) {
			for ( u32 col = 0; col < rhsCols; col++ ) {
				float value = g_matrixMultiplyTestRHS[row][col];
				float values[4] = { value, value, value, value };

				String_Appendf( &m_codeTests, "\t%s b%d%d[4] =", m_memberTypeString, row, col );
				Gen_GetValuesArray1D( m_type, 4, values, &m_codeTests );
				String_Append(  &m_codeTests, ";\n" );
			}
		}
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s results;\n", sseReturnName );
		String_Appendf( &m_codeTests, "\t%s lhs;\n", sseLHSName );
		String_Appendf( &m_codeTests, "\t%s rhs;\n", sseRHSName );
		for ( u32 row = 0; row < m_numRows; row++ ) {
			for ( u32 col = 0; col < m_numCols; col++ ) {
				String_Appendf( &m_codeTests, "\tlhs.m[%d][%d] = %s( a%d%d );\n", row, col, loadFuncStr, row, col );
			}
		}
		String_Append(  &m_codeTests, "\n" );
		for ( u32 row = 0; row < rhsRows; row++ ) {
			for ( u32 col = 0; col < rhsCols; col++ ) {
				String_Appendf( &m_codeTests, "\trhs.m[%d][%d] = %s( b%d%d );\n", row, col, loadFuncStr, row, col );
			}
		}
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\tmul_sse( &lhs, &rhs, &results );\n" );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s mulResults[4];\n", m_memberTypeString );
		String_Append(  &m_codeTests, "\n" );
		for ( u32 row = 0; row < returnTypeRows; row++ ) {
			for ( u32 col = 0; col < returnTypeCols; col++ ) {
				String_Appendf( &m_codeTests, "\t%s( mulResults, results.m[%d][%d] );\n", storeFuncStr, row, col );

				for ( u32 componentIndex = 0; componentIndex < 4; componentIndex++ ) {
					String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( mulResults[%d], g_matrixMulAnswer_%s[%d][%d] ) );\n", floateqStr, componentIndex, m_fullTypeName, row, col );
				}

				String_Append( &m_codeTests, "\n" );
			}
		}
		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  &m_codeTests, "}\n" );
		String_Append(  &m_codeTests, "\n" );

		String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

void GeneratorMatrixTests::GenerateTestDivideMatrix() {
	if ( m_numRows != m_numCols || !Gen_TypeIsFloatingPoint( m_type ) ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestDivideMatrix_%s", m_fullTypeName );

	const float valuesDiv[4][4] = {
		{ 6.0f, 2.0f, 3.0f, 4.0f },
		{ 2.0f, 7.0f, 5.0f, 3.0f },
		{ 3.0f, 5.0f, 7.0f, 2.0f },
		{ 4.0f, 3.0f, 2.0f, 6.0f }
	};

	char parmListLhs[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	char parmListRhs[GEN_STRING_LENGTH_PARM_LIST_MATRIX];

	Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, valuesDiv, parmListLhs );
	Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, valuesDiv, parmListRhs );

	char parmListAnswer[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrixIdentity( m_type, m_numRows, m_numCols, parmListAnswer );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s answer = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListAnswer );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s a = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListLhs );
	String_Appendf( &m_codeTests, "\t%s b = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListRhs );
	String_Appendf( &m_codeTests, "\t%s c = a %c b;\n", m_fullTypeName, GEN_OPERATORS_ARITHMETIC[GEN_OP_ARITHMETIC_DIV] );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( c == answer );\n" );
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

	char parmList0[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };
	char parmList1[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };

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
		char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "Test%s_%s", suffices[i], m_fullTypeName );

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

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestRelational_%s", m_fullTypeName );

	char boolTypeName[GEN_STRING_LENGTH_TYPE_NAME] = { 0 };
	snprintf( boolTypeName, GEN_STRING_LENGTH_TYPE_NAME, "bool%dx%d", m_numRows, m_numCols );

	char parmListTrue[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };
	Gen_GetParmListMatrixSingleValue( GEN_TYPE_BOOL, m_numRows, m_numCols, true, parmListTrue );

	char parmLists[4][GEN_STRING_LENGTH_PARM_LIST_MATRIX];
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
	if ( !Gen_TypeIsInteger( m_type ) ) {
		return;
	}

	char unaryValueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL] = { 0 };
	snprintf( unaryValueStr, GEN_STRING_LENGTH_NUMERIC_LITERAL, "(%s) -1", m_memberTypeString );

	char parmStr[32];
	snprintf( parmStr, 32, "(%s) -1", m_memberTypeString );

	char parmListAnswerUnary[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrixSingleValueStr( m_numRows, m_numCols, parmStr, parmListAnswerUnary );

	// values must be integers
	char parmListLhs[GEN_OP_BITWISE_COUNT - 1][GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 21.0f, parmListLhs[0] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 21.0f, parmListLhs[1] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 21.0f, parmListLhs[2] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 1.0f , parmListLhs[3] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 16.0f, parmListLhs[4] );

	char parmListRhs[GEN_OP_BITWISE_COUNT - 1][GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 7.0f, parmListRhs[0] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 7.0f, parmListRhs[1] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 7.0f, parmListRhs[2] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 2.0f, parmListRhs[3] );
	Gen_GetParmListMatrixSingleValue( m_type, m_numRows, m_numCols, 4.0f, parmListRhs[4] );

	char parmListAnswers[GEN_OP_BITWISE_COUNT - 1][GEN_STRING_LENGTH_PARM_LIST_MATRIX];
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

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };

	for ( u32 i = 0; i < _countof( ops ); i++ ) {
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestBitwise_%s_%s", suffices[i], m_fullTypeName );

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
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestBitwise_Unary_%s", m_fullTypeName );

		char parmList[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
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
	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( m_type, 0, zeroStr, 1 );
	Gen_GetNumericLiteral( m_type, 1, oneStr, 1 );

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestArray_%s", m_fullTypeName );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s mat;\n", m_fullTypeName );
	String_Append(  &m_codeTests, "\n" );
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
	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestIdentity_Scalar_%s", m_fullTypeName );

	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( m_type, 0, zeroStr, 1 );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( m_type, 1, oneStr, 1 );

	char parmListIdentity[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };
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
	String_Append( &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append( &m_codeTests, "}\n" );
	String_Append( &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );

	if ( Gen_TypeSupportsSSE( m_type ) ) {
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestIdentity_SSE_%s", m_fullTypeName );

		char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( m_fullTypeName, sseTypeName );

		const char* storeFuncStr = Gen_SSE_GetIntrinsicStore( m_type );

		String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  &m_codeTests, "{\n" );
		String_Appendf( &m_codeTests, "\t%s matSSE;\n", sseTypeName );
		String_Append(  &m_codeTests, "\tidentity_sse( &matSSE );\n" );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s identityResults[4];\n", m_memberTypeString );
		for ( u32 row = 0; row < m_numRows; row++ ) {
			for ( u32 col = 0; col < m_numCols; col++ ) {
				const char* valueStr = ( row == col ) ? oneStr : zeroStr;

				String_Appendf( &m_codeTests, "\t%s( identityResults, matSSE.m[%d][%d] );\n", storeFuncStr, row, col );
				for ( u32 componentIndex = 0; componentIndex < 4; componentIndex++ ) {
					String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( identityResults[%d] == %s );\n", componentIndex, valueStr );
				}

				String_Append(  &m_codeTests, "\n" );
			}
		}
		String_Append( &m_codeTests, "\tTEMPER_PASS();\n" );
		String_Append( &m_codeTests, "}\n" );
		String_Append( &m_codeTests, "\n" );

		String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

void GeneratorMatrixTests::GenerateTestTranspose() {
	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestTranspose_Scalar_%s", m_fullTypeName );

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

	char parmListNormal[GEN_STRING_LENGTH_PARM_LIST_MATRIX]		= { 0 };
	char parmListTransposed[GEN_STRING_LENGTH_PARM_LIST_MATRIX]	= { 0 };

	Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, valuesNormal, parmListNormal );
	Gen_GetParmListMatrix( m_type, m_numCols, m_numRows, valuesTransposed, parmListTransposed );

	char transposeTypeName[GEN_STRING_LENGTH_TYPE_NAME] = { 0 };
	snprintf( transposeTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", m_typeString, m_numCols, m_numRows );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s mat = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListNormal );
	String_Appendf( &m_codeTests, "\t%s trans = transpose( mat );\n", transposeTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( trans == %s%s );\n", transposeTypeName, parmListTransposed );
	String_Append(  &m_codeTests, "\n" );
	String_Append( &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append( &m_codeTests, "}\n" );
	String_Append( &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );

	if ( Gen_TypeSupportsSSE( m_type ) ) {
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestTranspose_SSE_%s", m_fullTypeName );

		char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		char sseTransposedName[GEN_STRING_LENGTH_SSE_INPUT_NAME];

		Gen_SSE_GetFullTypeName( m_fullTypeName, sseTypeName );
		Gen_SSE_GetFullTypeName( transposeTypeName, sseTransposedName );

		const char* set1FuncStr		= Gen_SSE_GetIntrinsicSet1( m_type );
		const char* storeFuncStr	= Gen_SSE_GetIntrinsicStore( m_type );

		const char* floateqStr = Gen_GetFuncNameFloateq( m_type );

		String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  &m_codeTests, "{\n" );
		String_Appendf( &m_codeTests, "\t%s results;\n", sseTransposedName );
		String_Appendf( &m_codeTests, "\t%s in;\n", sseTypeName );
		String_Append(  &m_codeTests, "\n" );
		for ( u32 row = 0; row < m_numRows; row++ ) {
			String_Appendf( &m_codeTests, "\t// row %d\n", row );
			for ( u32 col = 0; col < m_numCols; col++ ) {
				char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
				Gen_GetNumericLiteral( m_type, valuesNormal[row][col], valueStr, 1 );

				String_Appendf( &m_codeTests, "\tin.m[%d][%d] = %s( %s );\n", row, col, set1FuncStr, valueStr );
			}

			String_Appendf( &m_codeTests, "\n" );
		}
		String_Appendf( &m_codeTests, "\ttranspose_sse( &in, &results );\n" );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s transposeResults[4];\n", m_memberTypeString );

		for ( u32 col = 0; col < m_numCols; col++ ) {
			for ( u32 row = 0; row < m_numRows; row++ ) {
				char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
				Gen_GetNumericLiteral( m_type, valuesTransposed[col][row], valueStr );

				String_Appendf( &m_codeTests, "\t%s( transposeResults, results.m[%d][%d] );\n", storeFuncStr, col, row );

				for ( u32 i = 0; i < 4; i++ ) {
					String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( transposeResults[%d], %s ) );\n", floateqStr, i, valueStr );
				}

				String_Append( &m_codeTests, "\n" );
			}
		}

		String_Append( &m_codeTests, "\tTEMPER_PASS();\n" );
		String_Append( &m_codeTests, "}\n" );
		String_Append( &m_codeTests, "\n" );

		String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

void GeneratorMatrixTests::GenerateTestDeterminant() {
	if ( m_type == GEN_TYPE_BOOL || m_type == GEN_TYPE_UINT ) {
		return;
	}

	if ( m_numRows != m_numCols ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestDeterminant_Scalar_%s", m_fullTypeName );

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

	char answerStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( m_type, determinants[m_numRows - 2], answerStr, 1 );

	const char* floateqStr = Gen_GetFuncNameFloateq( m_type );

	char parmList[GEN_STRING_LENGTH_PARM_LIST_MATRIX];

	// DM: this looks ugly but but I understand this is the correct way to get a ptr to a 2D array
	// I don't know of a better way of doing this
	float (*valuesMat)[4] = NULL;

	switch ( m_numRows ) {
		case 2:
			valuesMat = mat2x2;
			break;

		case 3:
			valuesMat = mat3x3;
			break;

		case 4:
			valuesMat = mat4x4;
			break;
	}

	Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, valuesMat, parmList );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s mat = %s%s;\n", m_fullTypeName, m_fullTypeName, parmList );
	String_Appendf( &m_codeTests, "\t%s det = determinant( mat );\n", m_memberTypeString );
	String_Append(  &m_codeTests, "\n" );
	if ( Gen_TypeIsFloatingPoint( m_type ) ) {
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( det, %s ) );\n", floateqStr, answerStr );
	} else {
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( det == %s );\n", answerStr );
	}

	String_Append( &m_codeTests, "\n" );
	String_Append( &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append( &m_codeTests, "}\n" );
	String_Append( &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );

	if ( Gen_TypeSupportsSSE( m_type ) ) {
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestDeterminant_SSE_%s", m_fullTypeName );

		char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( m_fullTypeName, sseTypeName );

		const char* registerName = Gen_SSE_GetRegisterName( m_type );

		const char* loadFuncStr		= Gen_SSE_GetIntrinsicLoad( m_type );
		const char* storeFuncStr	= Gen_SSE_GetIntrinsicStore( m_type );

		String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  &m_codeTests, "{\n" );
		for ( u32 row = 0; row < m_numRows; row++ ) {
			for ( u32 col = 0; col < m_numCols; col++ ) {
				float value = valuesMat[row][col];
				float values[4] = { value, value, value, value };

				String_Appendf( &m_codeTests, "\t%s m%d%d[4] =", m_memberTypeString, row, col );
				Gen_GetValuesArray1D( m_type, 4, values, &m_codeTests );
				String_Append(  &m_codeTests, ";\n" );
			}
		}
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s results;\n", registerName );
		String_Appendf( &m_codeTests, "\t%s in;\n", sseTypeName );
		for ( u32 row = 0; row < m_numRows; row++ ) {
			for ( u32 col = 0; col < m_numCols; col++ ) {
				String_Appendf( &m_codeTests, "\tin.m[%d][%d] = %s( m%d%d );\n", row, col, loadFuncStr, row, col );
			}
		}
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\tdeterminant_sse( &in, &results );\n" );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s determinantResults[4];\n", m_memberTypeString );
		String_Appendf( &m_codeTests, "\t%s( determinantResults, results );\n", storeFuncStr );
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( determinantResults[0], %s ) );\n", floateqStr, answerStr );
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( determinantResults[1], %s ) );\n", floateqStr, answerStr );
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( determinantResults[2], %s ) );\n", floateqStr, answerStr );
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( determinantResults[3], %s ) );\n", floateqStr, answerStr );
		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  &m_codeTests, "}\n" );
		String_Append(  &m_codeTests, "\n" );

		String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

void GeneratorMatrixTests::GenerateTestInverse() {
	if ( !Gen_TypeIsFloatingPoint( m_type ) ) {
		return;
	}

	if ( m_numRows != m_numCols ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestInverse_Scalar_%s", m_fullTypeName );

	// matrices chosen because they gave nice whole numbers for determinants and easy to tell when properly inverted
	float mat2x2[4][4] = {
		{  2.0f,  4.0f, -1.0f, -1.0f },
		{  6.0f,  8.0f, -1.0f, -1.0f },
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
#if 0	// TODO(DM): add this matrix as just another test case
		{ 6.0f, 2.0f, 3.0f, 4.0f },
		{ 2.0f, 7.0f, 5.0f, 3.0f },
		{ 3.0f, 5.0f, 7.0f, 2.0f },
		{ 4.0f, 3.0f, 2.0f, 6.0f }
#else
		{ 1.0f, 0.0f, 0.0f, 1.0f },
		{ 0.0f, 2.0f, 1.0f, 2.0f },
		{ 2.0f, 1.0f, 0.0f, 1.0f },
		{ 2.0f, 0.0f, 1.0f, 4.0f }
#endif
	};

	char parmList[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };

	// DM: this looks ugly but but I understand this is the correct way to get a ptr to a 2D array
	// I don't know of a better way of doing this
	float (*valuesMat)[4] = NULL;

	switch ( m_numRows ) {
		case 2:
			valuesMat = mat2x2;
			break;

		case 3:
			valuesMat = mat3x3;
			break;

		case 4:
			valuesMat = mat4x4;
			break;
	}

	Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, valuesMat, parmList );

	float epsilon = 0.001f;
	char epsilonStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( m_type, epsilon, epsilonStr );

	const char* floateqStr = Gen_GetFuncNameFloateq( m_type );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s mat = %s%s;\n", m_fullTypeName, m_fullTypeName, parmList );
	String_Appendf( &m_codeTests, "\t%s matInverse = inverse( mat );\n", m_fullTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat * matInverse == g_identityMatrix_%s );\n", m_fullTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );

	if ( Gen_TypeSupportsSSE( m_type ) ) {
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestInverse_SSE_%s", m_fullTypeName );

		char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( m_fullTypeName, sseTypeName );

		const char* loadFuncStr = Gen_SSE_GetIntrinsicLoad( m_type );
		const char* storeFuncStr = Gen_SSE_GetIntrinsicStore( m_type );

		String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  &m_codeTests, "{\n" );
		for ( u32 row = 0; row < m_numRows; row++ ) {
			for ( u32 col = 0; col < m_numCols; col++ ) {
				float value = valuesMat[row][col];
				float values[4] = { value, value, value, value };

				String_Appendf( &m_codeTests, "\t%s m%d%d[4] =", m_memberTypeString, row, col );
				Gen_GetValuesArray1D( m_type, 4, values, &m_codeTests );
				String_Append(  &m_codeTests, ";\n" );
			}
		}
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s results;\n", sseTypeName );
		String_Appendf( &m_codeTests, "\t%s inverted;\n", sseTypeName );
		String_Appendf( &m_codeTests, "\t%s in;\n", sseTypeName );
		for ( u32 row = 0; row < m_numRows; row++ ) {
			for ( u32 col = 0; col < m_numCols; col++ ) {
				String_Appendf( &m_codeTests, "\tin.m[%d][%d] = %s( m%d%d );\n", row, col, loadFuncStr, row, col );
			}
		}
		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\tinverse_sse( &in, &inverted );\n" );
		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\tmul_sse( &in, &inverted, &results );\n" );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s inverseResults[4];\n", m_memberTypeString );
		String_Append(  &m_codeTests, "\n" );
		for ( u32 row = 0; row < m_numRows; row++ ) {
			for ( u32 col = 0; col < m_numCols; col++ ) {
				String_Appendf( &m_codeTests, "\t%s( inverseResults, results.m[%d][%d] );\n", storeFuncStr, row, col );

				for ( u32 componentIndex = 0; componentIndex < 4; componentIndex++ ) {
					String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( inverseResults[%d], g_identityMatrix_%s[%d][%d], %s ) );\n", floateqStr, componentIndex, m_fullTypeName, row, col, epsilonStr );
				}

				String_Append( &m_codeTests, "\n" );
			}
		}
		String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  &m_codeTests, "}\n" );
		String_Append(  &m_codeTests, "\n" );

		String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

void GeneratorMatrixTests::GenerateTestTranslate() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( m_numRows < 3 || m_numCols < m_numRows ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestTranslate_Scalar_%s", m_fullTypeName );

	char translateVectorTypeString[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( translateVectorTypeString, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", m_typeString, m_numCols - 1 );

	u32 translateVecComponents = m_numCols - 1;

	float valuesTranslateVec[GEN_COMPONENT_COUNT_MAX - 1] = {
		2.0f, 3.0f, 4.0f
	};

	char parmListTranslated[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( m_type, translateVecComponents, valuesTranslateVec, parmListTranslated );

	const char* floateqStr = Gen_GetFuncNameFloateq( m_type );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s mat;\n", m_fullTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s translation = %s%s;\n", translateVectorTypeString, translateVectorTypeString, parmListTranslated );
	String_Appendf( &m_codeTests, "\tmat = translate( mat, translation );\n" );
	String_Append(  &m_codeTests, "\n" );
	for ( u32 i = 0; i < translateVecComponents; i++ ) {
		char translateValueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
		Gen_GetNumericLiteral( m_type, valuesTranslateVec[i], translateValueStr, 1 );

		if ( Gen_TypeIsFloatingPoint( m_type ) ) {
			String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( mat[%d][%d], %s ) );\n", floateqStr, i, translateVecComponents, translateValueStr );
		} else {
			String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( mat[%d][%d] == %s );\n", i, translateVecComponents, translateValueStr );
		}
	}
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );

	if ( Gen_TypeSupportsSSE( m_type ) ) {
		// rules for generating SSE versions of translate() and scale() function are different from the scalar implementation
		if ( m_numCols < 3 || m_numRows != m_numCols ) {
			return;
		}

		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestTranslate_SSE_%s", m_fullTypeName );

		char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( m_fullTypeName, sseTypeName );

		char translateVecTypeName[GEN_STRING_LENGTH_TYPE_NAME];
		Gen_GetFullTypeName( m_type, 1, translateVecComponents, translateVecTypeName );

		char sseTranslateVecName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( translateVecTypeName, sseTranslateVecName );

		const char* loadFuncStr = Gen_SSE_GetIntrinsicLoad( m_type );
		const char* storeFuncStr = Gen_SSE_GetIntrinsicStore( m_type );

		String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  &m_codeTests, "{\n" );
		String_Appendf( &m_codeTests, "\t%s translateVecComponents[%d][4] =\n", m_memberTypeString, translateVecComponents );
		String_Append(  &m_codeTests, "\t{\n" );
		for ( u32 i = 0; i < translateVecComponents; i++ ) {
			float value = valuesTranslateVec[i];
			float values[4] = { value, value, value, value };

			String_Append(  &m_codeTests, "\t" );
			Gen_GetValuesArray1D( m_type, 4, values, &m_codeTests );

			if ( i != translateVecComponents - 1 ) {
				String_Append(  &m_codeTests, "," );
			}

			String_Appendf( &m_codeTests, "\t// 4 %c components\n", GEN_COMPONENT_NAMES_VECTOR[i] );
		}
		String_Append(  &m_codeTests, "\t};\n" );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s pos;\n", sseTranslateVecName );
		String_Appendf( &m_codeTests, "\tmemset( &pos, 0, %d * sizeof( __m128 ) );\n", translateVecComponents );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s translation;\n", sseTranslateVecName );
		for ( u32 i = 0; i < translateVecComponents; i++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Appendf( &m_codeTests, "\ttranslation.%c = %s( translateVecComponents[%d] );\n", componentStr, loadFuncStr, i );
		}
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\ttranslate_sse( &pos, &translation, &pos );\n" );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s translateResults[4];\n", m_memberTypeString );
		String_Append(  &m_codeTests, "\n" );
		for ( u32 componentIndex = 0; componentIndex < translateVecComponents; componentIndex++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[componentIndex];

			String_Appendf( &m_codeTests, "\t%s( translateResults, pos.%c );\n", storeFuncStr, componentStr );
			for ( u32 i = 0; i < 4; i++ ) {
				char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
				Gen_GetNumericLiteral( m_type, valuesTranslateVec[componentIndex], valueStr );

				if ( Gen_TypeIsFloatingPoint( m_type ) ) {
					String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( translateResults[%d], %s ) );\n", floateqStr, i, valueStr );
				} else {
					String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( translateResults[%d] == %s );\n", floateqStr, i, valueStr );
				}
			}
			String_Append(  &m_codeTests, "\n" );
		}
		String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  &m_codeTests, "}\n" );
		String_Append(  &m_codeTests, "\n" );

		String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

void GeneratorMatrixTests::GenerateTestRotate() {
	if ( !Gen_TypeIsFloatingPoint( m_type ) ) {
		return;
	}

	if ( m_numRows < 3 ) {
		return;
	}

	if ( m_numRows != m_numCols ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestRotate_%s", m_fullTypeName );

	float rotDegrees = 45.0f;
	float rotRadians = rotDegrees * (float)( M_PI ) / 180.0f;

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

	char rotDegreesStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( m_type, rotDegrees, rotDegreesStr, 1 );

	char rotateVecTypeString[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( rotateVecTypeString, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", m_typeString, numRotateVectorComponents );

	char parmListVecYaw[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	char parmListVecPitch[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	char parmListVecRoll[GEN_STRING_LENGTH_PARM_LIST_VECTOR];

	char parmListMatYaw[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	char parmListMatPitch[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	char parmListMatRoll[GEN_STRING_LENGTH_PARM_LIST_MATRIX];

	Gen_GetParmListVector( m_type, numRotateVectorComponents, angleAxisVecYaw, parmListVecYaw );
	Gen_GetParmListVector( m_type, numRotateVectorComponents, angleAxisVecPitch, parmListVecPitch );
	Gen_GetParmListVector( m_type, numRotateVectorComponents, angleAxisVecRoll, parmListVecRoll );

	Gen_GetParmListMatrix( m_type, numRotMatRows, numRotMatCols, rotMatYaw, parmListMatYaw );
	Gen_GetParmListMatrix( m_type, numRotMatRows, numRotMatCols, rotMatPitch, parmListMatPitch );
	Gen_GetParmListMatrix( m_type, numRotMatRows, numRotMatCols, rotMatRoll, parmListMatRoll );

	// matrices where cols == 3 only have roll rotation support
	char parmListRotateRoll[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };
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

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestScale_Scalar_%s", m_fullTypeName );

	// const u32 scaleCols = 3;
	u32 scaleCols = GEN_MIN( m_numRows, m_numCols );
	scaleCols = GEN_MAX( scaleCols - 1, 2 );

	float scaleMatDiagonal[] = { 2.0f, 2.0f, 2.0f, 1.0f };

	char parmListScaleVec[GEN_STRING_LENGTH_PARM_LIST_VECTOR]	= { 0 };
	char parmListscaleMat[GEN_STRING_LENGTH_PARM_LIST_MATRIX]	= { 0 };

	Gen_GetParmListVector( m_type, scaleCols, scaleMatDiagonal, parmListScaleVec );
	Gen_GetParmListMatrixDiagonal( m_type, m_numRows, m_numCols, scaleMatDiagonal, _countof( scaleMatDiagonal ), parmListscaleMat );

	char scaleVecTypeString[GEN_STRING_LENGTH_TYPE_NAME] = { 0 };
	snprintf( scaleVecTypeString, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", m_typeString, scaleCols );

	const char* floateqStr = Gen_GetFuncNameFloateq( m_type );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s mat;\n", m_fullTypeName );
	String_Appendf( &m_codeTests, "\t%s scaled = scale( mat, %s%s );\n", m_fullTypeName, scaleVecTypeString, parmListScaleVec );
	String_Append(  &m_codeTests, "\n" );
	for ( u32 i = 0; i < scaleCols; i++ ) {
		char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
		Gen_GetNumericLiteral( m_type, scaleMatDiagonal[i], valueStr );

		if ( Gen_TypeIsFloatingPoint( m_type ) ) {
			String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( scaled[%d][%d], %s ) );\n", floateqStr, i, i, valueStr );
		} else {
			String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( scaled[%d][%d] == %s );\n", i, i, valueStr );
		}
	}
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );

	if ( Gen_TypeSupportsSSE( m_type ) ) {
		// rules for generating SSE versions of translate() and scale() function are different from the scalar implementation
		if ( m_numCols < 3 || m_numRows != m_numCols ) {
			return;
		}

		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestScale_SSE_%s", m_fullTypeName );

		char sseScaleVecName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( scaleVecTypeString, sseScaleVecName );

		const char* set1FuncStr = Gen_SSE_GetIntrinsicSet1( m_type );
		const char* loadFuncStr = Gen_SSE_GetIntrinsicLoad( m_type );
		const char* storeFuncStr = Gen_SSE_GetIntrinsicStore( m_type );

		String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  &m_codeTests, "{\n" );
		String_Appendf( &m_codeTests, "\t%s scaleVecComponents[%d][4] =\n", m_memberTypeString, scaleCols );
		String_Append(  &m_codeTests, "\t{\n" );
		for ( u32 i = 0; i < scaleCols; i++ ) {
			float value = scaleMatDiagonal[i];
			float values[4] = { value, value, value, value };

			String_Append(  &m_codeTests, "\t" );
			Gen_GetValuesArray1D( m_type, 4, values, &m_codeTests );

			if ( i < scaleCols - 1 ) {
				String_Append(  &m_codeTests, "," );
			}

			String_Appendf( &m_codeTests, "\t// 4 %c components\n", GEN_COMPONENT_NAMES_VECTOR[i] );
		}
		String_Append(  &m_codeTests, "\t};\n" );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s diagonal;\n", sseScaleVecName );
		for ( u32 i = 0; i < scaleCols; i++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Appendf( &m_codeTests, "\tdiagonal.%c = %s( 1 );\n", componentStr, set1FuncStr );
		}
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s scale;\n", sseScaleVecName );
		for ( u32 i = 0; i < scaleCols; i++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Appendf( &m_codeTests, "\tscale.%c = %s( scaleVecComponents[%d] );\n", componentStr, loadFuncStr, i );
		}
		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\tscale_sse( &diagonal, &scale, &diagonal );\n" );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s scaleResults[4];\n", m_memberTypeString );
		for ( u32 componentIndex = 0; componentIndex < scaleCols; componentIndex++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[componentIndex];

			String_Appendf( &m_codeTests, "\t%s( scaleResults, diagonal.%c );\n", storeFuncStr, componentStr );

			for ( u32 i = 0; i < 4; i++ ) {
				char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
				Gen_GetNumericLiteral( m_type, scaleMatDiagonal[componentIndex], valueStr );

				if ( Gen_TypeIsFloatingPoint( m_type ) ) {
					String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( scaleResults[%d], %s ) );\n", floateqStr, i, valueStr );
				} else {
					String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( scaleResults[%d] == %s );\n", i, valueStr );
				}
			}
			String_Append(  &m_codeTests, "\n" );
		}
		String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  &m_codeTests, "}\n" );
		String_Append(  &m_codeTests, "\n" );

		String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

void GeneratorMatrixTests::GenerateTestOrtho() {
	if ( !Gen_TypeIsFloatingPoint( m_type ) ) {
		return;
	}

	if ( m_numRows < 4 || m_numCols < 4 ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestOrtho_%s", m_fullTypeName );

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

	char parmListAnswerOrtho_LH_ZO[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };
	char parmListAnswerOrtho_LH_NO[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };
	char parmListAnswerOrtho_RH_ZO[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };
	char parmListAnswerOrtho_RH_NO[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };

	Gen_GetParmListMatrix( m_type, 4, 4, answerOrtho_LH_ZO, parmListAnswerOrtho_LH_ZO );
	Gen_GetParmListMatrix( m_type, 4, 4, answerOrtho_LH_NO, parmListAnswerOrtho_LH_NO );
	Gen_GetParmListMatrix( m_type, 4, 4, answerOrtho_RH_ZO, parmListAnswerOrtho_RH_ZO );
	Gen_GetParmListMatrix( m_type, 4, 4, answerOrtho_RH_NO, parmListAnswerOrtho_RH_NO );

	char minusOneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char fiveStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char oneHundredStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	char widthStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char heightStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( m_type, -1.0f,   minusOneStr, 1 );
	Gen_GetNumericLiteral( m_type,  5.0f,   fiveStr, 1 );
	Gen_GetNumericLiteral( m_type,  100.0f, oneHundredStr, 1 );

	Gen_GetNumericLiteral( m_type, 1280.0f, widthStr, 1 );
	Gen_GetNumericLiteral( m_type, 720.0f,  heightStr, 1 );

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
	if ( !Gen_TypeIsFloatingPoint( m_type ) ) {
		return;
	}

	if ( m_numRows < 4 || m_numCols < 4 ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestPerspective_%s", m_fullTypeName );

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

	char parmListPerspective_LH_ZO[GEN_STRING_LENGTH_PARM_LIST_MATRIX]	= { 0 };
	char parmListPerspective_LH_NO[GEN_STRING_LENGTH_PARM_LIST_MATRIX]	= { 0 };
	char parmListPerspective_RH_ZO[GEN_STRING_LENGTH_PARM_LIST_MATRIX]	= { 0 };
	char parmListPerspective_RH_NO[GEN_STRING_LENGTH_PARM_LIST_MATRIX]	= { 0 };

	Gen_GetParmListMatrix( m_type, 4, 4, answerPerspective_LH_ZO, parmListPerspective_LH_ZO );
	Gen_GetParmListMatrix( m_type, 4, 4, answerPerspective_LH_NO, parmListPerspective_LH_NO );
	Gen_GetParmListMatrix( m_type, 4, 4, answerPerspective_RH_ZO, parmListPerspective_RH_ZO );
	Gen_GetParmListMatrix( m_type, 4, 4, answerPerspective_RH_NO, parmListPerspective_RH_NO );

	char widthStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char heightStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	char fovStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char znearStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char zfarStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( m_type, 1280.0f, widthStr, 1 );
	Gen_GetNumericLiteral( m_type, 720.0f, heightStr, 1 );

	Gen_GetNumericLiteral( m_type, 90.0f, fovStr, 1 );
	Gen_GetNumericLiteral( m_type, 0.1f, znearStr, 1 );
	Gen_GetNumericLiteral( m_type, 100.0f, zfarStr, 1 );

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
	if ( !Gen_TypeIsFloatingPoint( m_type ) ) {
		return;
	}

	if ( m_numRows < 4 || m_numCols < 4 ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestLookAt_%s", m_fullTypeName );

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

	char posVectorTypeName[GEN_STRING_LENGTH_TYPE_NAME] = { 0 };
	snprintf( posVectorTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", m_typeString, numTranslateVecComponents );

	char parmListCurrentPos[GEN_STRING_LENGTH_PARM_LIST_VECTOR]	= { 0 };
	char parmListTargetPos[GEN_STRING_LENGTH_PARM_LIST_VECTOR]	= { 0 };
	char parmListUp[GEN_STRING_LENGTH_PARM_LIST_VECTOR]			= { 0 };

	Gen_GetParmListVector( m_type, numTranslateVecComponents, currentPos, parmListCurrentPos );
	Gen_GetParmListVector( m_type, numTranslateVecComponents, targetPos, parmListTargetPos );
	Gen_GetParmListVector( m_type, numTranslateVecComponents, up, parmListUp );

	char parmListLookAt_LH[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };
	char parmListLookAt_RH[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };

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

void GeneratorMatrixTests::GetTestCodeOperatorArithmeticInternalScalar( const genOpArithmetic_t op,
	const float valuesLhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], const float valuesRhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], stringBuilder_t* sb ) const {
	assert( op >= 0 );
	assert( op < GEN_OP_ARITHMETIC_COUNT );
	assert( valuesLhs );
	assert( valuesRhs );

	char parmListLhs[GEN_STRING_LENGTH_PARM_LIST_MATRIX]	= { 0 };
	char parmListRhs[GEN_STRING_LENGTH_PARM_LIST_MATRIX]	= { 0 };

	Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, valuesLhs, parmListLhs );
	Gen_GetParmListMatrix( m_type, m_numRows, m_numCols, valuesRhs, parmListRhs );

	char parmListAnswer[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };
	GetParmListComponentWiseArithmeticAnswer( op, m_numRows, m_numCols, valuesLhs, valuesRhs, parmListAnswer );

	const char* opStr = GEN_OPERATOR_STRINGS_ARITHMETIC[op];

	String_Appendf( sb, "\t%s answer = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListAnswer );
	String_Append(  sb, "\n" );
	String_Appendf( sb, "\t%s a = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListLhs );
	String_Appendf( sb, "\t%s b = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListRhs );
	// DM: not great, we only have comp_mul and comp_div for matrices atm (no comp_add or comp_sub)
	// will we ever need them?
	if ( op == GEN_OP_ARITHMETIC_MUL || op == GEN_OP_ARITHMETIC_DIV ) {
		String_Appendf( sb, "\t%s c = comp_%s( a, b );\n", m_fullTypeName, opStr );
	} else {
		String_Appendf( sb, "\t%s c = a %c b;\n", m_fullTypeName, GEN_OPERATORS_ARITHMETIC[op] );
	}
	String_Append(  sb, "\n" );
	String_Append(  sb, "\tTEMPER_EXPECT_TRUE( c == answer );\n" );
	String_Append(  sb, "\n" );
	String_Append(  sb, "\tTEMPER_PASS();\n" );
}

void GeneratorMatrixTests::GetTestCodeOperatorArithmeticInternalSSE( const genOpArithmetic_t op,
	const float valuesLhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], const float valuesRhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], stringBuilder_t* sb ) const {
	assert( op >= 0 );
	assert( op < GEN_OP_ARITHMETIC_COUNT );
	assert( valuesLhs );
	assert( valuesRhs );

	if ( !Gen_TypeSupportsSSE( m_type ) ) {
		return;
	}

	const char* opStr = GEN_OPERATOR_STRINGS_ARITHMETIC[op];

	char function[32];
	snprintf( function, 32, "comp_%s", opStr );

	char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetFullTypeName( m_fullTypeName, sseTypeName );

	const char* loadFuncStr = Gen_SSE_GetIntrinsicLoad( m_type );
	const char* storeFuncStr = Gen_SSE_GetIntrinsicStore( m_type );

	const char* floateqStr = Gen_GetFuncNameFloateq( m_type );

	for ( u32 row = 0; row < m_numRows; row++ ) {
		for ( u32 col = 0; col < m_numCols; col++ ) {
			float value = valuesLhs[row][col];
			float values[4] = { value, value, value, value };

			String_Appendf( sb, "\t%s a%d%d[4] =", m_memberTypeString, row, col );
			Gen_GetValuesArray1D( m_type, 4, values, sb );
			String_Append(  sb, ";\n" );
		}
	}
	String_Append(  sb, "\n" );
	for ( u32 row = 0; row < m_numRows; row++ ) {
		for ( u32 col = 0; col < m_numCols; col++ ) {
			float value = valuesRhs[row][col];
			float values[4] = { value, value, value, value };

			String_Appendf( sb, "\t%s b%d%d[4] =", m_memberTypeString, row, col );
			Gen_GetValuesArray1D( m_type, 4, values, sb );
			String_Append(  sb, ";\n" );
		}
	}
	String_Append(  sb, "\n" );
	String_Appendf( sb, "\t%s results;\n", sseTypeName );
	String_Appendf( sb, "\t%s lhs;\n", sseTypeName );
	String_Appendf( sb, "\t%s rhs;\n", sseTypeName );
	for ( u32 row = 0; row < m_numRows; row++ ) {
		for ( u32 col = 0; col < m_numCols; col++ ) {
			String_Appendf( sb, "\tlhs.m[%d][%d] = %s( a%d%d );\n", row, col, loadFuncStr, row, col );
		}
	}
	String_Append(  sb, "\n" );
	for ( u32 row = 0; row < m_numRows; row++ ) {
		for ( u32 col = 0; col < m_numCols; col++ ) {
			String_Appendf( sb, "\trhs.m[%d][%d] = %s( b%d%d );\n", row, col, loadFuncStr, row, col );
		}
	}
	String_Append(  sb, "\n" );
	String_Appendf( sb, "\tcomp_%s_sse( &lhs, &rhs, &results );\n", opStr );
	String_Append(  sb, "\n" );
	String_Appendf( sb, "\t%s arithmeticResults[4];\n", m_memberTypeString );
	String_Append(  sb, "\n" );
	for ( u32 row = 0; row < m_numRows; row++ ) {
		for ( u32 col = 0; col < m_numCols; col++ ) {
			char answerStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
			switch ( op ) {
				case GEN_OP_ARITHMETIC_ADD:
					Gen_GetNumericLiteral( m_type, valuesLhs[row][col] + valuesRhs[row][col], answerStr );
					break;

				case GEN_OP_ARITHMETIC_SUB:
					Gen_GetNumericLiteral( m_type, valuesLhs[row][col] - valuesRhs[row][col], answerStr );
					break;

				case GEN_OP_ARITHMETIC_MUL:
					Gen_GetNumericLiteral( m_type, valuesLhs[row][col] * valuesRhs[row][col], answerStr );
					break;

				case GEN_OP_ARITHMETIC_DIV:
					Gen_GetNumericLiteral( m_type, valuesLhs[row][col] / valuesRhs[row][col], answerStr );
					break;

				case GEN_OP_ARITHMETIC_COUNT:
				default:
					printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
					break;
			}

			String_Appendf( sb, "\t%s( arithmeticResults, results.m[%d][%d] );\n", storeFuncStr, row, col );

			for ( u32 componentIndex = 0; componentIndex < 4; componentIndex++ ) {
				String_Appendf( sb, "\tTEMPER_EXPECT_TRUE( %s( arithmeticResults[%d], %s ) );\n", floateqStr, componentIndex, answerStr );
			}

			String_Append( sb, "\n" );
		}
	}
	String_Append(  sb, "\tTEMPER_PASS();\n" );
}

void GeneratorMatrixTests::GetParmListComponentWiseArithmeticAnswer( const genOpArithmetic_t op, const u32 numRows, const u32 numCols,
	const float valuesLhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], const float valuesRhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], char* outString ) const {
	assert( op >= 0 );
	assert( op < GEN_OP_ARITHMETIC_COUNT );

	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	assert( valuesLhs );
	assert( valuesRhs );

	char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	int pos = 0;

	pos += sprintf( outString + pos, "(\n" );

	for ( u32 row = 0; row < numRows; row++ ) {
		pos += sprintf( outString + pos, "\t\t" );

		for ( u32 col = 0; col < numCols; col++ ) {
			float lhs = valuesLhs[row][col];
			float rhs = valuesRhs[row][col];

			switch ( op ) {
				case GEN_OP_ARITHMETIC_ADD:
					Gen_GetNumericLiteral( m_type, lhs + rhs, valueStr );
					break;

				case GEN_OP_ARITHMETIC_SUB:
					Gen_GetNumericLiteral( m_type, lhs - rhs, valueStr );
					break;

				case GEN_OP_ARITHMETIC_MUL:
					Gen_GetNumericLiteral( m_type, lhs * rhs, valueStr );
					break;

				case GEN_OP_ARITHMETIC_DIV:
					Gen_GetNumericLiteral( m_type, lhs / rhs, valueStr );
					break;

				case GEN_OP_ARITHMETIC_COUNT:
				default:
					printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
						break;
			}

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

	pos += sprintf( outString + pos, "\t)" );
}

void GeneratorMatrixTests::GetParmListMatrixMultiply( const u32 returnTypeRows, const u32 returnTypeCols,
	const float valuesLhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], const float valuesRhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX],
	char* outString ) const {
	assert( returnTypeRows >= GEN_COMPONENT_COUNT_MIN );
	assert( returnTypeRows <= GEN_COMPONENT_COUNT_MAX );
	assert( returnTypeCols >= GEN_COMPONENT_COUNT_MIN );
	assert( returnTypeCols <= GEN_COMPONENT_COUNT_MAX );

	assert( valuesLhs );
	assert( valuesRhs );

	char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	int pos = 0;

	pos += sprintf( outString + pos, "(\n" );

	for ( u32 row = 0; row < returnTypeRows; row++ ) {
		pos += sprintf( outString + pos, "\t\t" );

		for ( u32 col = 0; col < returnTypeCols; col++ ) {
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

			if ( row + col != ( returnTypeRows - 1 ) + ( returnTypeCols - 1 ) ) {
				pos += sprintf( outString + pos, "," );
			}

			if ( col != returnTypeCols - 1 ) {
				pos += sprintf( outString + pos, " " );
			}
		}

		pos += sprintf( outString + pos, "\n" );
	}

	pos += sprintf( outString + pos, "\t)" );
}
