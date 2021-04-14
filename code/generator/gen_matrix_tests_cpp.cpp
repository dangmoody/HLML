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
#include "gen_matrix_cpp.h"

#include "defines.h"

#include "file_io.h"

#include "gen_funcs_vector.h"
#include "gen_funcs_matrix.h"

#include "string_builder.h"
#include "allocator.h"
#include "file_io.h"

#include "gen_common_sse.h"

#include <assert.h>
#include <string.h>

#define _USE_MATH_DEFINES	// for PI
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

static void GetParmListComponentWiseArithmeticAnswer( const genType_t type, const u32 numRows, const u32 numCols,
	const genOpArithmetic_t op, const float valuesLhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], const float valuesRhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], char* outString ) {
	assert( op >= 0 );
	assert( op < GEN_OP_ARITHMETIC_COUNT );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( valuesLhs );
	assert( valuesRhs );
	assert( outString );

	char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	int pos = 0;

	for ( u32 row = 0; row < numRows; row++ ) {
		pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "\t\t" );

		for ( u32 col = 0; col < numCols; col++ ) {
			float lhs = valuesLhs[row][col];
			float rhs = valuesRhs[row][col];

			switch ( op ) {
				case GEN_OP_ARITHMETIC_ADD:
					Gen_GetNumericLiteral( type, lhs + rhs, valueStr );
					break;

				case GEN_OP_ARITHMETIC_SUB:
					Gen_GetNumericLiteral( type, lhs - rhs, valueStr );
					break;

				case GEN_OP_ARITHMETIC_MUL:
					Gen_GetNumericLiteral( type, lhs * rhs, valueStr );
					break;

				case GEN_OP_ARITHMETIC_DIV:
					Gen_GetNumericLiteral( type, lhs / rhs, valueStr );
					break;

				case GEN_OP_ARITHMETIC_COUNT:
				default:
					printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
						break;
			}

			pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "%s", valueStr );

			if ( row + col != ( numRows - 1 ) + ( numCols - 1 ) ) {
				pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "," );
			}

			if ( col != numCols - 1 ) {
				pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, " " );
			}
		}

		pos += snprintf( outString + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "\n" );
	}
}

// scalar here means "non-SSE"
// TODO(DM): can we think of a better way distinguishing between "SSE" and "non-SSE"?
static void GetTestCodeComponentWiseArithmeticInternalScalar( stringBuilder_t* code, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const char* fullTypeName,
	const genOpArithmetic_t op, const float valuesLhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], const float valuesRhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX] ) {
	assert( code );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( op >= 0 );
	assert( op < GEN_OP_ARITHMETIC_COUNT );
	assert( valuesLhs );
	assert( valuesRhs );

	char parmListLhs[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrix( type, numRows, numCols, valuesLhs, parmListLhs );

	char parmListRhs[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrix( type, numRows, numCols, valuesRhs, parmListRhs );

	char parmListAnswer[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	GetParmListComponentWiseArithmeticAnswer( type, numRows, numCols, op, valuesLhs, valuesRhs, parmListAnswer );

	char compFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameComponentWiseArithmeticMatrix( language, type, numRows, numCols, op, compFuncStr );

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, numRows, numCols, equalsFuncStr );

	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( code, "\t%s answer = (%s) {\n", fullTypeName, fullTypeName, parmListAnswer );
		String_Append(  code, parmListAnswer );
		String_Append(  code, "\t};\n" );
		String_Append(  code, "\n" );
		String_Appendf( code, "\t%s a = (%s) {\n", fullTypeName, fullTypeName, parmListLhs );
		String_Append(  code, parmListLhs );
		String_Append(  code, "\t};\n" );
		String_Append(  code, "\n" );
		String_Appendf( code, "\t%s b = (%s) {\n", fullTypeName, fullTypeName, parmListRhs );
		String_Append(  code, parmListRhs );
		String_Append(  code, "\t};\n" );
		String_Append(  code, "\n" );
		String_Appendf( code, "\t%s c = %s( &a, &b );\n", fullTypeName, compFuncStr );
		String_Append(  code, "\n" );
		String_Appendf( code, "\tTEMPER_CHECK_TRUE( %s( &c, &answer ) );\n", equalsFuncStr );
	} else {
		String_Appendf( code, "\t%s answer = %s(\n", fullTypeName, fullTypeName );
		String_Append(  code, parmListAnswer );
		String_Append(  code, "\t);\n" );
		String_Append(  code, "\n" );
		String_Appendf( code, "\t%s a = %s(\n", fullTypeName, fullTypeName );
		String_Append(  code, parmListLhs );
		String_Append(  code, "\t);\n" );
		String_Append(  code, "\n" );
		String_Appendf( code, "\t%s b = %s(\n", fullTypeName, fullTypeName );
		String_Append(  code, parmListRhs );
		String_Append(  code, "\t);\n" );
		String_Append(  code, "\n" );
		String_Appendf( code, "\t%s c = %s( a, b );\n", fullTypeName, compFuncStr );
		String_Append(  code, "\n" );
		String_Append(  code, "\tTEMPER_CHECK_TRUE( c == answer );\n" );
	}
}

static void GetTestCodeOperatorArithmeticInternalSSE( stringBuilder_t* code, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const char* fullTypeName, const char* memberTypeString,
	const genOpArithmetic_t op, const float valuesLhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], const float valuesRhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX] ) {
	assert( code );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( op >= 0 );
	assert( op < GEN_OP_ARITHMETIC_COUNT );
	assert( valuesLhs );
	assert( valuesRhs );

	if ( !Gen_TypeSupportsSSE( type ) ) {
		return;
	}

	char funcStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_SSE_GetFuncNameComponentWiseArithmeticMatrix( language, type, numRows, numCols, op, funcStr );

	char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
	Gen_SSE_GetFullTypeName( type, numRows, numCols, sseTypeName );

	const char* loadFuncStr = Gen_SSE_GetIntrinsicLoad( type );
	const char* storeFuncStr = Gen_SSE_GetIntrinsicStore( type );

	const char* floateqStr = Gen_GetFuncNameFloateq( type );

	for ( u32 row = 0; row < numRows; row++ ) {
		for ( u32 col = 0; col < numCols; col++ ) {
			float value = valuesLhs[row][col];
			float values[4] = { value, value, value, value };

			String_Appendf( code, "\t%s a%d%d[4] =", memberTypeString, row, col );
			Gen_GetValuesArray1D( type, 4, values, code );
			String_Append(  code, ";\n" );
		}
	}
	String_Append(  code, "\n" );
	for ( u32 row = 0; row < numRows; row++ ) {
		for ( u32 col = 0; col < numCols; col++ ) {
			float value = valuesRhs[row][col];
			float values[4] = { value, value, value, value };

			String_Appendf( code, "\t%s b%d%d[4] =", memberTypeString, row, col );
			Gen_GetValuesArray1D( type, 4, values, code );
			String_Append(  code, ";\n" );
		}
	}
	String_Append(  code, "\n" );
	String_Appendf( code, "\t%s results;\n", sseTypeName );
	String_Appendf( code, "\t%s lhs;\n", sseTypeName );
	String_Appendf( code, "\t%s rhs;\n", sseTypeName );
	for ( u32 row = 0; row < numRows; row++ ) {
		for ( u32 col = 0; col < numCols; col++ ) {
			String_Appendf( code, "\tlhs.m[%d][%d] = %s( a%d%d );\n", row, col, loadFuncStr, row, col );
		}
	}
	String_Append(  code, "\n" );
	for ( u32 row = 0; row < numRows; row++ ) {
		for ( u32 col = 0; col < numCols; col++ ) {
			String_Appendf( code, "\trhs.m[%d][%d] = %s( b%d%d );\n", row, col, loadFuncStr, row, col );
		}
	}
	String_Append(  code, "\n" );
	String_Appendf( code, "\t%s( &lhs, &rhs, &results );\n", funcStr );
	String_Append(  code, "\n" );
	String_Appendf( code, "\t%s arithmeticResults[4];\n", memberTypeString );
	String_Append(  code, "\n" );
	for ( u32 row = 0; row < numRows; row++ ) {
		for ( u32 col = 0; col < numCols; col++ ) {
			char answerStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
			switch ( op ) {
				case GEN_OP_ARITHMETIC_ADD:
					Gen_GetNumericLiteral( type, valuesLhs[row][col] + valuesRhs[row][col], answerStr );
					break;

				case GEN_OP_ARITHMETIC_SUB:
					Gen_GetNumericLiteral( type, valuesLhs[row][col] - valuesRhs[row][col], answerStr );
					break;

				case GEN_OP_ARITHMETIC_MUL:
					Gen_GetNumericLiteral( type, valuesLhs[row][col] * valuesRhs[row][col], answerStr );
					break;

				case GEN_OP_ARITHMETIC_DIV:
					Gen_GetNumericLiteral( type, valuesLhs[row][col] / valuesRhs[row][col], answerStr );
					break;

				case GEN_OP_ARITHMETIC_COUNT:
				default:
					printf( "ERROR: Bad genOpArithmetic_t enum passed into %s.\n", __FUNCTION__ );
					break;
			}

			String_Appendf( code, "\t%s( arithmeticResults, results.m[%d][%d] );\n", storeFuncStr, row, col );

			for ( u32 componentIndex = 0; componentIndex < 4; componentIndex++ ) {
				String_Appendf( code, "\tTEMPER_CHECK_TRUE( %s( arithmeticResults[%d], %s ) );\n", floateqStr, componentIndex, answerStr );
			}

			String_Append( code, "\n" );
		}
	}
}

static void GetParmListMatrixMultiply( const genType_t type, const u32 numCols, const u32 returnTypeRows, const u32 returnTypeCols,
	const float valuesLhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], const float valuesRhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX],
	char* outString ) {
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( returnTypeRows >= GEN_COMPONENT_COUNT_MIN );
	assert( returnTypeRows <= GEN_COMPONENT_COUNT_MAX );
	assert( returnTypeCols >= GEN_COMPONENT_COUNT_MIN );
	assert( returnTypeCols <= GEN_COMPONENT_COUNT_MAX );
	assert( valuesLhs );
	assert( valuesRhs );
	assert( outString );

	char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	int pos = 0;

	for ( u32 row = 0; row < returnTypeRows; row++ ) {
		pos += snprintf( outString + pos, GEN_STRING_LENGTH_NUMERIC_LITERAL, "\t\t" );

		for ( u32 col = 0; col < returnTypeCols; col++ ) {
			// get the left-hand row
			float lhsRow[4];
			for ( size_t lhsComponent = 0; lhsComponent < numCols; lhsComponent++ ) {
				lhsRow[lhsComponent] = valuesLhs[row][lhsComponent];
			}

			// get the right-hand column
			float rhsCol[4];
			for ( size_t rhsComponent = 0; rhsComponent < numCols; rhsComponent++ ) {
				rhsCol[rhsComponent] = valuesRhs[rhsComponent][col];
			}

			// do the dot product procedurally
			float dots[4];
			for ( size_t i = 0; i < numCols; i++ ) {
				dots[i] = lhsRow[i] * rhsCol[i];
			}

			float dot = 0.0f;
			for ( size_t i = 0; i < numCols; i++ ) {
				dot += dots[i];
			}

			Gen_GetNumericLiteral( type, dot, valueStr );

			pos += snprintf( outString + pos, GEN_STRING_LENGTH_NUMERIC_LITERAL, "%s", valueStr );

			if ( row + col != ( returnTypeRows - 1 ) + ( returnTypeCols - 1 ) ) {
				pos += snprintf( outString + pos, GEN_STRING_LENGTH_NUMERIC_LITERAL, "," );
			}

			if ( col != returnTypeCols - 1 ) {
				pos += snprintf( outString + pos, GEN_STRING_LENGTH_NUMERIC_LITERAL, " " );
			}
		}

		pos += snprintf( outString + pos, GEN_STRING_LENGTH_NUMERIC_LITERAL, "\n" );
	}
}


static void GenerateTestAssignment( stringBuilder_t* codeTests, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols,
	const char* fullTypeName, const char* vectorTypeString ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( vectorTypeString );

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestAssignment_%s", fullTypeName );

	float fillValue = 999.0f;

	float valuesIdentity[4][4] = {
		{ fillValue, 0.0f,      0.0f,      0.0f      },
		{ 0.0f,      fillValue, 0.0f,      0.0f      },
		{ 0.0f,      0.0f,      fillValue, 0.0f      },
		{ 0.0f,      0.0f,      0.0f,      fillValue }
	};

	String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s mat;\n", fullTypeName );
	String_Append(  codeTests, "\n" );
	if ( language == GEN_LANGUAGE_C ) {
		for ( u32 row = 0; row < numRows; row++ ) {
			char parmListRow[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
			Gen_GetParmListVector( type, numCols, valuesIdentity[row], parmListRow );

			String_Appendf( codeTests, "\tmat.rows[%d] = (%s) { %s };\n", row, vectorTypeString, parmListRow );
		}
	} else {
		for ( u32 row = 0; row < numRows; row++ ) {
			char parmListRow[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
			Gen_GetParmListVector( type, numCols, valuesIdentity[row], parmListRow );

			String_Appendf( codeTests, "\tmat.rows[%d] = %s( %s );\n", row, vectorTypeString, parmListRow );
		}
	}
	String_Append( codeTests, "\n" );
	for ( u32 row = 0; row < numRows; row++ ) {
		for ( u32 col = 0; col < numCols; col++ ) {
			char componentStr = GEN_COMPONENT_NAMES_VECTOR[col];

			char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
			Gen_GetNumericLiteral( type, valuesIdentity[row][col], valueStr, 1 );

			String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( mat.rows[%d].%c == %s );\n", row, componentStr, valueStr );
		}
	}
	String_Append( codeTests, "}\n" );
	String_Append( codeTests, "\n" );
}

// DM!!! test all ctors
static void GenerateTestCtor( stringBuilder_t* codeTests, const genType_t type, const u32 numRows, const u32 numCols,
	const char* fullTypeName, const char* vectorTypeString ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( vectorTypeString );

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestCtor_%s", fullTypeName );

	// HACK(DM): this is not ideal for obvious reasons
	float fillValue = 999.0f;
	char fillValueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 999, fillValueStr, 1 );

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
	Gen_GetParmListMatrix( type, numRows, numCols, values, parmListValues );

	char parmListValuesReversed[GEN_STRING_LENGTH_PARM_LIST_MATRIX]	= { 0 };
	Gen_GetParmListMatrix( type, numRows, numCols, valuesReversed, parmListValuesReversed );

	String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s mat;\n", fullTypeName );
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\t// fill single value\n" );
	String_Appendf( codeTests, "\tmat = %s( %s );\n", fullTypeName, fillValueStr );
	for ( u32 row = 0; row < numRows; row++ ) {
		char parmList[GEN_STRING_LENGTH_PARM_LIST_VECTOR] = { 0 };
		Gen_GetParmListVector( type, numCols, valuesIdentity[row], parmList );

		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( mat[%d] == %s( %s ) );\n", row, vectorTypeString, parmList );
	}
	String_Append( codeTests, "\n" );

	String_Append(  codeTests, "\t// row filling\n" );
	String_Appendf( codeTests, "\tmat = %s(\n", fullTypeName );
	for ( u32 row = 0; row < numRows; row++ ) {
		char parmList[GEN_STRING_LENGTH_PARM_LIST_VECTOR] = { 0 };
		Gen_GetParmListVector( type, numCols, values[row], parmList );

		String_Appendf( codeTests, "\t\t%s( %s )", vectorTypeString, parmList );

		if ( row != numRows - 1 ) {
			String_Append( codeTests, "," );
		}

		String_Append( codeTests, "\n" );
	}
	String_Append( codeTests, "\t);\n" );
	for ( u32 row = 0; row < numRows; row++ ) {
		char parmList[GEN_STRING_LENGTH_PARM_LIST_VECTOR] = { 0 };
		Gen_GetParmListVector( type, numCols, values[row], parmList );

		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( mat[%d] == %s( %s ) );\n", row, vectorTypeString, parmList );
	}
	String_Append( codeTests, "\n" );

	String_Append(  codeTests, "\t// all values filled\n" );
	String_Appendf( codeTests, "\tmat = %s(\n", fullTypeName );
	String_Appendf( codeTests, "%s", parmListValuesReversed );
	String_Append(  codeTests, "\t);\n" );
	for ( u32 row = 0; row < numRows; row++ ) {
		char parmList[GEN_STRING_LENGTH_PARM_LIST_VECTOR] = { 0 };
		Gen_GetParmListVector( type, numCols, valuesReversed[row], parmList );

		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( mat[%d] == %s( %s ) );\n", row, vectorTypeString, parmList );
	}
	String_Append( codeTests, "}\n" );
	String_Append( codeTests, "\n" );
}

static void GenerateTestComponentWiseArithmetic( stringBuilder_t* codeTests, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols,
	const char* fullTypeName, const char* memberTypeString ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( memberTypeString );

	if ( type == GEN_TYPE_BOOL ) {
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
		snprintf( testNames[i], 64, "TestComponentWiseArithmetic_Scalar_%s_%s", suffices[i], fullTypeName );

		genOpArithmetic_t op = (genOpArithmetic_t) i;

		String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testNames[op] );
		String_Append(  codeTests, "{\n" );
		GetTestCodeComponentWiseArithmeticInternalScalar( codeTests, language, type, numRows, numCols, fullTypeName, op, valuesLhs, valuesRhs );
		String_Append( codeTests, "}\n" );
		String_Append( codeTests, "\n" );
	}

	if ( Gen_TypeSupportsSSE( type ) ) {
		for ( u32 i = 0; i < GEN_OP_ARITHMETIC_COUNT; i++ ) {
			snprintf( testNames[i], 64, "TestComponentWiseArithmetic_SSE_%s_%s", suffices[i], fullTypeName );

			genOpArithmetic_t op = (genOpArithmetic_t) i;

			String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testNames[op] );
			String_Append( codeTests, "{\n" );
			GetTestCodeOperatorArithmeticInternalSSE( codeTests, language, type, numRows, numCols, fullTypeName, memberTypeString, op, valuesLhs, valuesRhs );
			String_Append( codeTests, "}\n" );
			String_Append( codeTests, "\n" );
		}
	}
}

static void GenerateTestMultiplyVector( stringBuilder_t* codeTests, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols,
	const char* fullTypeName, const char* vectorTypeString ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( vectorTypeString );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( numRows != numCols ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestMultiplyVector_%s", fullTypeName );

	float valuesMat[4][4] = {
		{ 1.0f,  2.0f,  3.0f,  4.0f  },
		{ 5.0f,  6.0f,  7.0f,  8.0f  },
		{ 9.0f,  10.0f, 11.0f, 12.0f },
		{ 13.0f, 14.0f, 15.0f, 16.0f }
	};

	float valuesVec[4] = {
		2.0f, 1.0f, 4.0f, 3.0f
	};

	char parmListMat[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrix( type, numRows, numCols, valuesMat, parmListMat );

	char parmListVec[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numCols, valuesVec, parmListVec );

	char parmListVecAnswer[GEN_STRING_LENGTH_PARM_LIST_VECTOR];

	int pos = 0;

	for ( u32 col = 0; col < numCols; col++ ) {
		// get the left-hand row
		float matRow[GEN_COMPONENT_COUNT_MAX];
		for ( size_t lhsComponent = 0; lhsComponent < numCols; lhsComponent++ ) {
			matRow[lhsComponent] = valuesMat[col][lhsComponent];
		}

		// do the dot product procedurally
		float dots[GEN_COMPONENT_COUNT_MAX];
		for ( size_t i = 0; i < numCols; i++ ) {
			dots[i] = matRow[i] * valuesVec[i];
		}

		float dot = 0.0f;
		for ( size_t i = 0; i < numCols; i++ ) {
			dot += dots[i];
		}

		char dotStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
		Gen_GetNumericLiteral( type, dot, dotStr );

		pos += snprintf( parmListVecAnswer + pos, GEN_STRING_LENGTH_NUMERIC_LITERAL, "%s", dotStr );

		if ( col != ( numCols - 1 ) ) {
			pos += snprintf( parmListVecAnswer + pos, GEN_STRING_LENGTH_NUMERIC_LITERAL, ", " );
		}
	}

	char mulVectorFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameMatrixMultiplyVector( language, type, numRows, numCols, mulVectorFuncStr );

	char equalsVectorFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, 1, numCols, equalsVectorFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s answerVec = { %s };\n", vectorTypeString, parmListVecAnswer );
	String_Append(  codeTests, "\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s a = (%s) {\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListMat );
		String_Append(  codeTests, "\t};\n" );
		String_Appendf( codeTests, "\t%s b = { %s };\n", vectorTypeString, parmListVec );
		String_Appendf( codeTests, "\t%s c = %s( &a, &b );\n", vectorTypeString, mulVectorFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &c, &answerVec ) );\n", equalsVectorFuncStr );
	} else {
		String_Appendf( codeTests, "\t%s a = %s(\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListMat );
		String_Append(  codeTests, "\t);\n" );
		String_Appendf( codeTests, "\t%s b = { %s };\n", vectorTypeString, parmListVec );
		String_Appendf( codeTests, "\t%s c = a %c b;\n", vectorTypeString, GEN_OPERATORS_ARITHMETIC[GEN_OP_ARITHMETIC_MUL] );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( c == answerVec );\n" );
	}
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );
}

static void GenerateTestMultiplyMatrix( stringBuilder_t* codeTests, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols,
	const char* fullTypeName, const char* typeString, const char* memberTypeString ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( typeString );
	assert( memberTypeString );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestMultiplyMatrix_Scalar_%s", fullTypeName );

	u32 rhsRows = numCols;
	u32 rhsCols = numRows;

	u32 returnTypeRows = numRows;
	u32 returnTypeCols = numRows;

	const char* lhsTypeName = fullTypeName;

	char rhsTypeName[GEN_STRING_LENGTH_TYPE_NAME] = { 0 };
	char returnTypeName[GEN_STRING_LENGTH_TYPE_NAME] = { 0 };

	snprintf( rhsTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numCols, numRows );
	snprintf( returnTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numRows, numRows );

	const char* floateqStr = Gen_GetFuncNameFloateq( type );

	char mulFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameMatrixMultiply( language, type, numRows, numCols, mulFuncStr );

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, returnTypeRows, returnTypeCols, equalsFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s answer = g_matrixMulAnswer_%s;\n", returnTypeName, fullTypeName );
	String_Append(  codeTests, "\n" );
	String_Appendf( codeTests, "\t%s a = g_matrixMulLHS_%s;\n", lhsTypeName, fullTypeName );
	String_Appendf( codeTests, "\t%s b = g_matrixMulRHS_%s;\n", rhsTypeName, fullTypeName );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s c = %s( &a, &b );\n", returnTypeName, mulFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &c, &answer ) );\n", equalsFuncStr );
	} else {
		String_Appendf( codeTests, "\t%s c = a %c b;\n", returnTypeName, GEN_OPERATORS_ARITHMETIC[GEN_OP_ARITHMETIC_MUL] );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( c == answer );\n" );
	}
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	if ( Gen_TypeSupportsSSE( type ) ) {
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestMultiplyMatrix_SSE_%s", fullTypeName );

		char sseLHSName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( type, numRows, numCols, sseLHSName );

		char sseRHSName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( type, numCols, numRows, sseRHSName );

		char sseReturnName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( type, numRows, numRows, sseReturnName );

		const char* loadFuncStr = Gen_SSE_GetIntrinsicLoad( type );
		const char* storeFuncStr = Gen_SSE_GetIntrinsicStore( type );

		char mulFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameMatrixMultiply( language, type, numRows, numCols, mulFuncStrSSE );

		String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
		String_Append(  codeTests, "{\n" );
		for ( u32 row = 0; row < numRows; row++ ) {
			for ( u32 col = 0; col < numCols; col++ ) {
				float value = g_matrixMultiplyTestLHS[row][col];
				float values[4] = { value, value, value, value };

				String_Appendf( codeTests, "\t%s a%d%d[4] =", memberTypeString, row, col );
				Gen_GetValuesArray1D( type, 4, values, codeTests );
				String_Append(  codeTests, ";\n" );
			}
		}
		String_Append(  codeTests, "\n" );
		for ( u32 row = 0; row < rhsRows; row++ ) {
			for ( u32 col = 0; col < rhsCols; col++ ) {
				float value = g_matrixMultiplyTestRHS[row][col];
				float values[4] = { value, value, value, value };

				String_Appendf( codeTests, "\t%s b%d%d[4] =", memberTypeString, row, col );
				Gen_GetValuesArray1D( type, 4, values, codeTests );
				String_Append(  codeTests, ";\n" );
			}
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s results;\n", sseReturnName );
		String_Appendf( codeTests, "\t%s lhs;\n", sseLHSName );
		String_Appendf( codeTests, "\t%s rhs;\n", sseRHSName );
		for ( u32 row = 0; row < numRows; row++ ) {
			for ( u32 col = 0; col < numCols; col++ ) {
				String_Appendf( codeTests, "\tlhs.m[%d][%d] = %s( a%d%d );\n", row, col, loadFuncStr, row, col );
			}
		}
		String_Append(  codeTests, "\n" );
		for ( u32 row = 0; row < rhsRows; row++ ) {
			for ( u32 col = 0; col < rhsCols; col++ ) {
				String_Appendf( codeTests, "\trhs.m[%d][%d] = %s( b%d%d );\n", row, col, loadFuncStr, row, col );
			}
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s( &lhs, &rhs, &results );\n", mulFuncStrSSE );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s mulResults[4];\n", memberTypeString );
		String_Append(  codeTests, "\n" );
		for ( u32 row = 0; row < returnTypeRows; row++ ) {
			for ( u32 col = 0; col < returnTypeCols; col++ ) {
				String_Appendf( codeTests, "\t%s( mulResults, results.m[%d][%d] );\n", storeFuncStr, row, col );

				for ( u32 componentIndex = 0; componentIndex < 4; componentIndex++ ) {
					char componentStr = GEN_COMPONENT_NAMES_VECTOR[col];

					String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( mulResults[%d], g_matrixMulAnswer_%s.rows[%d].%c ) );\n", floateqStr, componentIndex, fullTypeName, row, componentStr );
				}

				String_Append( codeTests, "\n" );
			}
		}
		String_Append(  codeTests, "}\n" );
		String_Append(  codeTests, "\n" );
	}
}

static void GenerateTestDivideMatrix( stringBuilder_t* codeTests, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const char* fullTypeName ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	// matrix division is only a thing in C++ land because it's multiplying by a matrix's inverse
	// in C land you just call x = mul( inverse( x ) ) and it does the same thing
	if ( language != GEN_LANGUAGE_CPP ) {
		return;
	}

	if ( numRows != numCols || !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestDivideMatrix_%s", fullTypeName );

	const float valuesDiv[4][4] = {
		{ 6.0f, 2.0f, 3.0f, 4.0f },
		{ 2.0f, 7.0f, 5.0f, 3.0f },
		{ 3.0f, 5.0f, 7.0f, 2.0f },
		{ 4.0f, 3.0f, 2.0f, 6.0f }
	};

	char parmListLhs[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrix( type, numRows, numCols, valuesDiv, parmListLhs );

	char parmListRhs[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrix( type, numRows, numCols, valuesDiv, parmListRhs );

	char parmListAnswer[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrixIdentity( type, numRows, numCols, parmListAnswer );

	char mulFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameMatrixMultiply( language, type, numRows, numCols, mulFuncStr );

	char inverseFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameInverse( language, type, numRows, numCols, inverseFuncStr );

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, numRows, numCols, equalsFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s answer = %s( %s );\n", fullTypeName, fullTypeName, parmListAnswer );
	String_Append(  codeTests, "\n" );
	String_Appendf( codeTests, "\t%s a = %s( %s );\n", fullTypeName, fullTypeName, parmListLhs );
	String_Appendf( codeTests, "\t%s b = %s( %s );\n", fullTypeName, fullTypeName, parmListRhs );
	String_Appendf( codeTests, "\t%s c = a %c b;\n", fullTypeName, GEN_OPERATORS_ARITHMETIC[GEN_OP_ARITHMETIC_DIV] );
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( c == answer );\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );
}

static void GenerateTestIncrement( stringBuilder_t* codeTests, const genType_t type, const u32 numRows, const u32 numCols, const char* fullTypeName ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	char parmList0[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };
	char parmList1[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };

	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 0.0f, parmList0 );
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 1.0f, parmList1 );

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
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "Test%s_%s", suffices[i], fullTypeName );

		String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
		String_Append(  codeTests, "{\n" );
		String_Appendf( codeTests, "\t%s answer;\n", fullTypeName );
		String_Appendf( codeTests, "\t%s mat;\n", fullTypeName );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\t// prefix\n" );
		String_Appendf( codeTests, "\tanswer = %s(\n", fullTypeName );
		String_Appendf( codeTests, "%s", parmListAnswers[i] );
		String_Append(  codeTests, "\t);\n" );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tmat = %s(\n", fullTypeName );
		String_Appendf( codeTests, "%s\n", parmListVecs[i] );
		String_Append(  codeTests, "\t);\n" );
		String_Appendf( codeTests, "\t%smat;\n", GEN_OPERATORS_INCREMENT[i] );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( mat == answer );\n", fullTypeName, parmListAnswers[i] );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\t// postfix\n" );
		String_Appendf( codeTests, "\tanswer = %s(\n", fullTypeName );
		String_Appendf( codeTests, "%s", parmListAnswers[i] );
		String_Append(  codeTests, "\t);\n" );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tmat = %s(\n", fullTypeName );
		String_Appendf( codeTests, "%s\n", parmListVecs[i] );
		String_Append(  codeTests, "\t);\n" );
		String_Appendf( codeTests, "\tmat%s;\n", GEN_OPERATORS_INCREMENT[i] );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( mat == answer );\n", fullTypeName, parmListAnswers[i] );
		String_Append(  codeTests, "}\n" );
		String_Append(  codeTests, "\n" );
	}
}

static void GenerateTestRelational( stringBuilder_t* codeTests, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const char* fullTypeName ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	UNUSED( language );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestRelational_%s", fullTypeName );

	char boolTypeName[GEN_STRING_LENGTH_TYPE_NAME] = { 0 };
	snprintf( boolTypeName, GEN_STRING_LENGTH_TYPE_NAME, "bool%dx%d", numRows, numCols );

	char parmListTrue[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };
	Gen_GetParmListMatrixSingleValue( GEN_TYPE_BOOL, numRows, numCols, true, parmListTrue );

	char parmLists[4][GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 1, parmLists[0] );
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 2, parmLists[1] );
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 3, parmLists[2] );
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 4, parmLists[3] );

	char cmplFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameRelational( language, type, numRows, numCols, GEN_OP_RELATIONAL_LESS, cmplFuncStr );

	char cmpleFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameRelational( language, type, numRows, numCols, GEN_OP_RELATIONAL_LESS_EQUAL, cmpleFuncStr );

	char cmpgFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameRelational( language, type, numRows, numCols, GEN_OP_RELATIONAL_GREATER, cmpgFuncStr );

	char cmpgeFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameRelational( language, type, numRows, numCols, GEN_OP_RELATIONAL_GREATER_EQUAL, cmpgeFuncStr );

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, GEN_TYPE_BOOL, numRows, numCols, equalsFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s allTrue = { %s };\n", boolTypeName, parmListTrue );
	String_Append(  codeTests, "\n" );
	if ( language == GEN_LANGUAGE_C ) {
		for ( u32 i = 0; i < 4; i++ ) {
			String_Appendf( codeTests, "\t%s mat%d = (%s) { %s };\n", fullTypeName, i, fullTypeName, parmLists[i] );
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s test0  = %s( &mat0, &mat0 );\n", boolTypeName, cmpleFuncStr );
		String_Appendf( codeTests, "\t%s test1  = %s( &mat0, &mat0 );\n", boolTypeName, cmpgeFuncStr );
		String_Appendf( codeTests, "\t%s test2  = %s( &mat0, &mat1 );\n", boolTypeName, cmplFuncStr );
		String_Appendf( codeTests, "\t%s test3  = %s( &mat0, &mat2 );\n", boolTypeName, cmplFuncStr );
		String_Appendf( codeTests, "\t%s test4  = %s( &mat0, &mat3 );\n", boolTypeName, cmplFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s test5  = %s( &mat1, &mat0 );\n", boolTypeName, cmpgFuncStr );
		String_Appendf( codeTests, "\t%s test6  = %s( &mat1, &mat1 );\n", boolTypeName, cmpleFuncStr );
		String_Appendf( codeTests, "\t%s test7  = %s( &mat1, &mat1 );\n", boolTypeName, cmpgeFuncStr );
		String_Appendf( codeTests, "\t%s test8  = %s( &mat1, &mat2 );\n", boolTypeName, cmplFuncStr );
		String_Appendf( codeTests, "\t%s test9  = %s( &mat1, &mat3 );\n", boolTypeName, cmplFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s test10 = %s( &mat2, &mat0 );\n", boolTypeName, cmpgFuncStr );
		String_Appendf( codeTests, "\t%s test11 = %s( &mat2, &mat1 );\n", boolTypeName, cmpgFuncStr );
		String_Appendf( codeTests, "\t%s test12 = %s( &mat2, &mat2 );\n", boolTypeName, cmpleFuncStr );
		String_Appendf( codeTests, "\t%s test13 = %s( &mat2, &mat2 );\n", boolTypeName, cmpgeFuncStr );
		String_Appendf( codeTests, "\t%s test14 = %s( &mat2, &mat3 );\n", boolTypeName, cmplFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s test15 = %s( &mat3, &mat0 );\n", boolTypeName, cmpgFuncStr );
		String_Appendf( codeTests, "\t%s test16 = %s( &mat3, &mat1 );\n", boolTypeName, cmpgFuncStr );
		String_Appendf( codeTests, "\t%s test17 = %s( &mat3, &mat2 );\n", boolTypeName, cmpgFuncStr );
		String_Appendf( codeTests, "\t%s test18 = %s( &mat3, &mat3 );\n", boolTypeName, cmpleFuncStr );
		String_Appendf( codeTests, "\t%s test19 = %s( &mat3, &mat3 );\n", boolTypeName, cmpgeFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test0,  &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test1,  &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test2,  &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test3,  &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test4,  &allTrue ) );\n", equalsFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test5,  &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test6,  &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test7,  &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test8,  &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test9,  &allTrue ) );\n", equalsFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test10, &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test11, &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test12, &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test13, &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test14, &allTrue ) );\n", equalsFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test15, &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test16, &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test17, &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test18, &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &test19, &allTrue ) );\n", equalsFuncStr );
	} else {
		for ( u32 i = 0; i < 4; i++ ) {
			String_Appendf( codeTests, "\t%s mat%d = %s( %s );\n", fullTypeName, i, fullTypeName, parmLists[i] );
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s test0  = mat0 <= mat0;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test1  = mat0 >= mat0;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test2  = mat0 <  mat1;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test3  = mat0 <  mat2;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test4  = mat0 <  mat3;\n", boolTypeName );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s test5  = mat1 >  mat0;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test6  = mat1 <= mat1;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test7  = mat1 >= mat1;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test8  = mat1 <  mat2;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test9  = mat1 <  mat3;\n", boolTypeName );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s test10 = mat2 >  mat0;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test11 = mat2 >  mat1;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test12 = mat2 <= mat2;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test13 = mat2 >= mat2;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test14 = mat2 <  mat3;\n", boolTypeName );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s test15 = mat3 >  mat0;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test16 = mat3 >  mat1;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test17 = mat3 >  mat2;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test18 = mat3 <= mat3;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test19 = mat3 >= mat3;\n", boolTypeName );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test0  == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test1  == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test2  == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test3  == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test4  == allTrue );\n" );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test5  == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test6  == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test7  == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test8  == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test9  == allTrue );\n" );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test10 == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test11 == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test12 == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test13 == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test14 == allTrue );\n" );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test15 == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test16 == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test17 == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test18 == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( test19 == allTrue );\n" );
	}
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );
}

static void GenerateTestBitwise( stringBuilder_t* codeTests, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const char* fullTypeName, const char* memberTypeString ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( memberTypeString );

	if ( !Gen_TypeIsInteger( type ) ) {
		return;
	}

	char unaryValueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL] = { 0 };
	snprintf( unaryValueStr, GEN_STRING_LENGTH_NUMERIC_LITERAL, "(%s) -1", memberTypeString );

	char parmStr[32];
	snprintf( parmStr, 32, "(%s) -1", memberTypeString );

	char parmListAnswerUnary[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrixSingleValueStr( numRows, numCols, parmStr, parmListAnswerUnary );

	// values must be integers
	char parmListLhs[GEN_OP_BITWISE_COUNT - 1][GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 21.0f, parmListLhs[0] );
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 21.0f, parmListLhs[1] );
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 21.0f, parmListLhs[2] );
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 1.0f , parmListLhs[3] );
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 16.0f, parmListLhs[4] );

	char parmListRhs[GEN_OP_BITWISE_COUNT - 1][GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 7.0f, parmListRhs[0] );
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 7.0f, parmListRhs[1] );
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 7.0f, parmListRhs[2] );
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 2.0f, parmListRhs[3] );
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 4.0f, parmListRhs[4] );

	char parmListAnswers[GEN_OP_BITWISE_COUNT - 1][GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 5.0f,  parmListAnswers[0] );	// 21 & 7
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 23.0f, parmListAnswers[1] );	// 21 | 7
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 18.0f, parmListAnswers[2] );	// 21 ^ 7
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 4.0f,  parmListAnswers[3] );	// 1  << 2
	Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 1.0f,  parmListAnswers[4] );	// 16 >> 4

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

	char testName[GEN_STRING_LENGTH_TEST_NAME];

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, numRows, numCols, equalsFuncStr );

	if ( language == GEN_LANGUAGE_C ) {
		for ( u32 i = 0; i < _countof( ops ); i++ ) {
			const genOpBitwise_t op = ops[i];

			snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestBitwise_%s_%s", suffices[i], fullTypeName );

			char funcStr[GEN_STRING_LENGTH_FUNCTION_NAME];
			Gen_GetFuncNameBitwise( language, type, numRows, numCols, op, funcStr );

			String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
			String_Append(  codeTests, "{\n" );
			String_Appendf( codeTests, "\t%s answer  = (%s) {\n", fullTypeName, fullTypeName );
			String_Appendf( codeTests, "%s", parmListAnswers[i] );
			String_Append(  codeTests, "\t};\n" );
			String_Appendf( codeTests, "\t%s a = (%s) {\n", fullTypeName, fullTypeName );
			String_Appendf( codeTests, "%s", parmListLhs[i] );
			String_Append(  codeTests, "\t};\n" );
			String_Appendf( codeTests, "\t%s b = (%s) {\n", fullTypeName, fullTypeName );
			String_Appendf( codeTests, "%s", parmListRhs[i] );
			String_Append(  codeTests, "\t};\n" );
			String_Appendf( codeTests, "\t%s c = %s( &a, &b );\n", fullTypeName, funcStr );
			String_Append(  codeTests, "\n" );
			String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &c, &answer ) );\n", equalsFuncStr, parmListAnswers[i] );
			String_Append(  codeTests, "}\n" );
			String_Append(  codeTests, "\n" );
		}
	} else {
		for ( u32 i = 0; i < _countof( ops ); i++ ) {
			const genOpBitwise_t op = ops[i];

			snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestBitwise_%s_%s", suffices[i], fullTypeName );

			String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
			String_Append(  codeTests, "{\n" );
			String_Appendf( codeTests, "\t%s answer = %s(\n", fullTypeName, fullTypeName );
			String_Appendf( codeTests, "%s", parmListAnswers[i] );
			String_Append(  codeTests, "\t);\n" );
			String_Appendf( codeTests, "\t%s a = %s(\n", fullTypeName, fullTypeName );
			String_Appendf( codeTests, "%s", parmListLhs[i] );
			String_Append(  codeTests, "\t);\n" );
			String_Appendf( codeTests, "\t%s b = %s(\n", fullTypeName, fullTypeName );
			String_Appendf( codeTests, "%s", parmListRhs[i] );
			String_Append(  codeTests, "\t);\n" );
			String_Append(  codeTests, "\n" );
			String_Appendf( codeTests, "\t%s c = a %s b;\n", fullTypeName, GEN_OPERATORS_BITWISE[op] );
			String_Append(  codeTests, "\n" );
			String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( c == answer );\n" );
			String_Append(  codeTests, "}\n" );
			String_Append(  codeTests, "\n" );
		}
	}

	// unary
	{
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestBitwise_Unary_%s", fullTypeName );

		char parmList[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
		Gen_GetParmListMatrixSingleValue( type, numRows, numCols, 0.0f, parmList );

		char unaryFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_GetFuncNameBitwise( language, type, numRows, numCols, GEN_OP_BITWISE_UNARY, unaryFuncStr );

		String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
		String_Append(  codeTests, "{\n" );
		if ( language == GEN_LANGUAGE_C ) {
			String_Appendf( codeTests, "\t%s answer = (%s) {\n", fullTypeName, fullTypeName );
			String_Appendf( codeTests, "%s", parmListAnswerUnary );
			String_Append(  codeTests, "\t};\n" );
			String_Appendf( codeTests, "\t%s a = (%s) {\n", fullTypeName, fullTypeName );
			String_Appendf( codeTests, "%s", parmList );
			String_Append(  codeTests, "\t};\n" );
			String_Append(  codeTests, "\n" );
			String_Appendf( codeTests, "\t%s b = %s( &a );\n", fullTypeName, unaryFuncStr );
			String_Append(  codeTests, "\n" );
			String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &b, &answer ) );\n", equalsFuncStr );
		} else {
			String_Appendf( codeTests, "\t%s answer = %s(\n", fullTypeName, fullTypeName );
			String_Appendf( codeTests, "%s", parmListAnswerUnary );
			String_Append(  codeTests, "\t);\n" );
			String_Appendf( codeTests, "\t%s a = %s(\n", fullTypeName, fullTypeName );
			String_Appendf( codeTests, "%s", parmList );
			String_Append(  codeTests, "\t);\n" );
			String_Append(  codeTests, "\n" );
			String_Appendf( codeTests, "\t%s b = %sa;\n", fullTypeName, GEN_OPERATORS_BITWISE[GEN_OP_BITWISE_UNARY] );
			String_Append(  codeTests, "\n" );
			String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( b == answer );\n" );
		}
		String_Append(  codeTests, "}\n" );
		String_Append(  codeTests, "\n" );
	}
}

static void GenerateTestArray( stringBuilder_t* codeTests, const genType_t type, const u32 numRows, const u32 numCols, const char* fullTypeName, const char* vectorTypeString ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( vectorTypeString );

	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, 0, zeroStr, 1 );
	Gen_GetNumericLiteral( type, 1, oneStr, 1 );

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestArray_%s", fullTypeName );

	char identityFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameIdentity( GEN_LANGUAGE_CPP, type, numRows, numCols, identityFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s mat;\n", fullTypeName );
	String_Appendf( codeTests, "\t%s( mat );\n", identityFuncStr );
	String_Append(  codeTests, "\n" );
	for ( u32 row = 0; row < numRows; row++ ) {
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( mat[%d] == %s( ", row, vectorTypeString );

		for ( u32 col = 0; col < numCols; col++ ) {
			String_Appendf( codeTests, "%s", ( row == col ) ? oneStr : zeroStr );

			if ( col != numCols - 1 ) {
				String_Append( codeTests, ", " );
			}
		}

		String_Append( codeTests, " ) );\n" );
	}
	String_Append( codeTests, "}\n" );
	String_Append( codeTests, "\n" );
}

static void GenerateTestIdentity( stringBuilder_t* codeTests, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols,
	const char* fullTypeName, const char* vectorTypeName, const char* memberTypeString ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( memberTypeString );

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestIdentity_Scalar_%s", fullTypeName );

	float valuesIdentity[4][4] = {
		{ 1.0f, 0.0f, 0.0f, 0.0f },
		{ 0.0f, 1.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f, 1.0f }
	};

	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 0, zeroStr, 1 );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1, oneStr, 1 );

	char parmListIdentity[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };
	Gen_GetParmListMatrixIdentity( type, numRows, numCols, parmListIdentity );

	char identityFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameIdentity( language, type, numRows, numCols, identityFuncStr );

	char cmpeFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, numRows, numCols, cmpeFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s id;\n", fullTypeName, fullTypeName, parmListIdentity );
	if ( language == GEN_LANGUAGE_C ) {
		for ( u32 row = 0; row < numRows; row++ ) {
			char parmListRow[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
			Gen_GetParmListVector( type, numCols, valuesIdentity[row], parmListRow );

			String_Appendf( codeTests, "\tid.rows[%d] = (%s) { %s };\n", row, vectorTypeName, parmListRow );
		}
	} else {
		for ( u32 row = 0; row < numRows; row++ ) {
			char parmListRow[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
			Gen_GetParmListVector( type, numCols, valuesIdentity[row], parmListRow );

			String_Appendf( codeTests, "\tid[%d] = %s( %s );\n", row, vectorTypeName, parmListRow );
		}
	}
	String_Append(  codeTests, "\n" );
	String_Appendf( codeTests, "\t%s mat;\n", fullTypeName );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s( &mat );\n", identityFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &mat, &id ) );\n", cmpeFuncStr );
	} else {
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s( mat );\n", identityFuncStr );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( mat == id );\n" );
	}
	String_Append( codeTests, "}\n" );
	String_Append( codeTests, "\n" );

	if ( Gen_TypeSupportsSSE( type ) ) {
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestIdentity_SSE_%s", fullTypeName );

		char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( type, numRows, numCols, sseTypeName );

		const char* storeFuncStr = Gen_SSE_GetIntrinsicStore( type );

		char identityFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameIdentity( language, type, numRows, numCols, identityFuncStrSSE );

		String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
		String_Append(  codeTests, "{\n" );
		String_Appendf( codeTests, "\t%s matSSE;\n", sseTypeName );
		String_Appendf( codeTests, "\t%s( &matSSE );\n", identityFuncStrSSE );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s identityResults[4];\n", memberTypeString );
		for ( u32 row = 0; row < numRows; row++ ) {
			for ( u32 col = 0; col < numCols; col++ ) {
				const char* valueStr = ( row == col ) ? oneStr : zeroStr;

				String_Appendf( codeTests, "\t%s( identityResults, matSSE.m[%d][%d] );\n", storeFuncStr, row, col );
				for ( u32 componentIndex = 0; componentIndex < 4; componentIndex++ ) {
					String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( identityResults[%d] == %s );\n", componentIndex, valueStr );
				}

				String_Append(  codeTests, "\n" );
			}
		}
		String_Append( codeTests, "}\n" );
		String_Append( codeTests, "\n" );
	}
}

static void GenerateTestTranspose( stringBuilder_t* codeTests, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols,
	const char* fullTypeName, const char* vectorTypeName, const char* typeString, const char* memberTypeString ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( vectorTypeName );
	assert( typeString );
	assert( memberTypeString );

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestTranspose_Scalar_%s", fullTypeName );

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

	char parmListNormal[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrix( type, numRows, numCols, valuesNormal, parmListNormal );

	u32 transposeTypeRows = numCols;
	u32 transposeTypeCols = numRows;

	char parmListTransposed[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrix( type, transposeTypeRows, transposeTypeCols, valuesTransposed, parmListTransposed );

	char transposeTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( transposeTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, transposeTypeRows, transposeTypeCols );

	char transposeTypeVectorTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( transposeTypeVectorTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, transposeTypeCols );

	char transposeFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameTranspose( language, type, numRows, numCols, transposeFuncStr );

	char cmpeFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, transposeTypeRows, transposeTypeCols, cmpeFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
	String_Append(  codeTests, "{\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s answerTransposed = (%s) {\n", transposeTypeName, transposeTypeName );
		String_Appendf( codeTests, "%s", parmListTransposed );
		String_Append(  codeTests, "\t};\n" );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s mat = (%s) {\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListNormal );
		String_Append(  codeTests, "\t};\n" );
		String_Appendf( codeTests, "\t%s trans = %s( &mat );\n", transposeTypeName, transposeFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &trans, &answerTransposed ) );\n", cmpeFuncStr );
	} else {
		String_Appendf( codeTests, "\t%s answerTransposed = %s(\n", transposeTypeName, transposeTypeName );
		String_Appendf( codeTests, "%s", parmListTransposed );
		String_Append(  codeTests, "\t);\n" );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s mat = %s(\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListNormal );
		String_Append(  codeTests, "\t);\n" );
		String_Appendf( codeTests, "\t%s trans = %s( mat );\n", transposeTypeName, transposeFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( trans == answerTransposed );\n", transposeTypeName, parmListTransposed );
	}
	String_Append( codeTests, "}\n" );
	String_Append( codeTests, "\n" );

	if ( Gen_TypeSupportsSSE( type ) ) {
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestTranspose_SSE_%s", fullTypeName );

		char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( type, numRows, numCols, sseTypeName );

		char sseTransposedName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( type, numCols, numRows, sseTransposedName );

		const char* set1FuncStr		= Gen_SSE_GetIntrinsicSet1( type );
		const char* storeFuncStr	= Gen_SSE_GetIntrinsicStore( type );

		const char* floateqStr = Gen_GetFuncNameFloateq( type );

		char transposeFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameTranspose( language, type, numRows, numCols, transposeFuncStrSSE );

		String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
		String_Append(  codeTests, "{\n" );
		String_Appendf( codeTests, "\t%s results;\n", sseTransposedName );
		String_Appendf( codeTests, "\t%s in;\n", sseTypeName );
		String_Append(  codeTests, "\n" );
		for ( u32 row = 0; row < numRows; row++ ) {
			String_Appendf( codeTests, "\t// row %d\n", row );
			for ( u32 col = 0; col < numCols; col++ ) {
				char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
				Gen_GetNumericLiteral( type, valuesNormal[row][col], valueStr, 1 );

				String_Appendf( codeTests, "\tin.m[%d][%d] = %s( %s );\n", row, col, set1FuncStr, valueStr );
			}

			String_Appendf( codeTests, "\n" );
		}
		String_Appendf( codeTests, "\t%s( &in, &results );\n", transposeFuncStrSSE );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s transposeResults[4];\n", memberTypeString );

		for ( u32 col = 0; col < numCols; col++ ) {
			for ( u32 row = 0; row < numRows; row++ ) {
				char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
				Gen_GetNumericLiteral( type, valuesTransposed[col][row], valueStr );

				String_Appendf( codeTests, "\t%s( transposeResults, results.m[%d][%d] );\n", storeFuncStr, col, row );

				for ( u32 i = 0; i < 4; i++ ) {
					String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( transposeResults[%d], %s ) );\n", floateqStr, i, valueStr );
				}

				String_Append( codeTests, "\n" );
			}
		}

		String_Append( codeTests, "}\n" );
		String_Append( codeTests, "\n" );
	}
}

static void GenerateTestDeterminant( stringBuilder_t* codeTests, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const char* fullTypeName, const char* memberTypeString ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( memberTypeString );

	UNUSED( language );

	if ( type == GEN_TYPE_BOOL || type == GEN_TYPE_UINT ) {
		return;
	}

	if ( numRows != numCols ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestDeterminant_Scalar_%s", fullTypeName );

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
	Gen_GetNumericLiteral( type, determinants[numRows - 2], answerStr, 1 );

	const char* floateqStr = Gen_GetFuncNameFloateq( type );

	char parmList[GEN_STRING_LENGTH_PARM_LIST_MATRIX];

	// DM: this looks ugly but but I understand this is the correct way to get a ptr to a 2D array
	// I don't know of a better way of doing this
	float (*valuesMat)[4] = NULL;

	switch ( numRows ) {
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

	Gen_GetParmListMatrix( type, numRows, numCols, valuesMat, parmList );

	char determinantFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameDeterminant( language, type, numRows, numCols, determinantFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
	String_Append(  codeTests, "{\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s mat = (%s) {\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmList );
		String_Append(  codeTests, "\t};\n" );
		String_Appendf( codeTests, "\t%s det = %s( &mat );\n", memberTypeString, determinantFuncStr );
		String_Append(  codeTests, "\n" );
		if ( Gen_TypeIsFloatingPoint( type ) ) {
			String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( det, %s ) );\n", floateqStr, answerStr );
		} else {
			String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( det == %s );\n", answerStr );
		}
	} else {
		String_Appendf( codeTests, "\t%s mat = %s(\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmList );
		String_Append(  codeTests, "\t);\n" );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s det = determinant( mat );\n", memberTypeString );
		String_Append(  codeTests, "\n" );
		if ( Gen_TypeIsFloatingPoint( type ) ) {
			String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( det, %s ) );\n", floateqStr, answerStr );
		} else {
			String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( det == %s );\n", answerStr );
		}
	}
	String_Append( codeTests, "}\n" );
	String_Append( codeTests, "\n" );

	if ( Gen_TypeSupportsSSE( type ) ) {
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestDeterminant_SSE_%s", fullTypeName );

		char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( type, numRows, numCols, sseTypeName );

		const char* registerName = Gen_SSE_GetRegisterName( type );

		const char* loadFuncStr		= Gen_SSE_GetIntrinsicLoad( type );
		const char* storeFuncStr	= Gen_SSE_GetIntrinsicStore( type );

		char determinantFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameDeterminant( language, type, numRows, numCols, determinantFuncStrSSE );

		String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
		String_Append(  codeTests, "{\n" );
		for ( u32 row = 0; row < numRows; row++ ) {
			for ( u32 col = 0; col < numCols; col++ ) {
				float value = valuesMat[row][col];
				float values[4] = { value, value, value, value };

				String_Appendf( codeTests, "\t%s m%d%d[4] =", memberTypeString, row, col );
				Gen_GetValuesArray1D( type, 4, values, codeTests );
				String_Append(  codeTests, ";\n" );
			}
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s results;\n", registerName );
		String_Appendf( codeTests, "\t%s in;\n", sseTypeName );
		for ( u32 row = 0; row < numRows; row++ ) {
			for ( u32 col = 0; col < numCols; col++ ) {
				String_Appendf( codeTests, "\tin.m[%d][%d] = %s( m%d%d );\n", row, col, loadFuncStr, row, col );
			}
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s( &in, &results );\n", determinantFuncStrSSE );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s determinantResults[4];\n", memberTypeString );
		String_Appendf( codeTests, "\t%s( determinantResults, results );\n", storeFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( determinantResults[0], %s ) );\n", floateqStr, answerStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( determinantResults[1], %s ) );\n", floateqStr, answerStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( determinantResults[2], %s ) );\n", floateqStr, answerStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( determinantResults[3], %s ) );\n", floateqStr, answerStr );
		String_Append(  codeTests, "}\n" );
		String_Append(  codeTests, "\n" );
	}
}

static void GenerateTestInverse( stringBuilder_t* codeTests, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols,
	const char* fullTypeName, const char* memberTypeString ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( memberTypeString );

	UNUSED( language );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	if ( numRows != numCols ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestInverse_Scalar_%s", fullTypeName );

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

	switch ( numRows ) {
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

	Gen_GetParmListMatrix( type, numRows, numCols, valuesMat, parmList );

	float epsilon = 0.001f;
	char epsilonStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, epsilon, epsilonStr );

	const char* parmRefStr = GEN_TYPE_PARM_REFERENCE_MODIFIERS[language];

	char identityFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameIdentity( language, type, numRows, numCols, identityFuncStr );

	char inverseFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameInverse( language, type, numRows, numCols, inverseFuncStr );

	char mulFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameMatrixMultiply( language, type, numRows, numCols, mulFuncStr );

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, numRows, numCols, equalsFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s id;\n", fullTypeName );
	String_Appendf( codeTests, "\t%s( %sid );\n", identityFuncStr, parmRefStr );
	String_Append(  codeTests, "\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s mat = (%s) {\n", fullTypeName, fullTypeName );
		String_Append(  codeTests, parmList );
		String_Append(  codeTests, "\t};\n" );
		String_Appendf( codeTests, "\t%s matInverse = %s( &mat );\n", fullTypeName, inverseFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s shouldBeIdentity = %s( &mat, &matInverse );\n", fullTypeName, mulFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &shouldBeIdentity, &id ) );\n", equalsFuncStr, fullTypeName );
	} else {
		String_Appendf( codeTests, "\t%s mat = %s(\n", fullTypeName, fullTypeName );
		String_Append(  codeTests, parmList );
		String_Append(  codeTests, "\t);\n" );
		String_Appendf( codeTests, "\t%s matInverse = inverse( mat );\n", fullTypeName );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( mat * matInverse == id );\n", fullTypeName );
	}
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	if ( Gen_TypeSupportsSSE( type ) ) {
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestInverse_SSE_%s", fullTypeName );

		char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( type, numRows, numCols, sseTypeName );

		const char* loadFuncStr = Gen_SSE_GetIntrinsicLoad( type );
		const char* storeFuncStr = Gen_SSE_GetIntrinsicStore( type );

		const char* floateqepsStr = Gen_GetFuncNameFloateqeps( type );

		char inverseFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameInverse( language, type, numRows, numCols, inverseFuncStrSSE );

		char mulFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameMatrixMultiply( language, type, numRows, numCols, mulFuncStrSSE );

		String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
		String_Append(  codeTests, "{\n" );
		String_Appendf( codeTests, "\t%s id;\n", fullTypeName );
		String_Appendf( codeTests, "\t%s( %sid );\n", identityFuncStr, parmRefStr );
		String_Append(  codeTests, "\n" );
		for ( u32 row = 0; row < numRows; row++ ) {
			for ( u32 col = 0; col < numCols; col++ ) {
				float value = valuesMat[row][col];
				float values[4] = { value, value, value, value };

				String_Appendf( codeTests, "\t%s m%d%d[4] =", memberTypeString, row, col );
				Gen_GetValuesArray1D( type, 4, values, codeTests );
				String_Append(  codeTests, ";\n" );
			}
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s results;\n", sseTypeName );
		String_Appendf( codeTests, "\t%s inverted;\n", sseTypeName );
		String_Appendf( codeTests, "\t%s in;\n", sseTypeName );
		for ( u32 row = 0; row < numRows; row++ ) {
			for ( u32 col = 0; col < numCols; col++ ) {
				String_Appendf( codeTests, "\tin.m[%d][%d] = %s( m%d%d );\n", row, col, loadFuncStr, row, col );
			}
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s( &in, &inverted );\n", inverseFuncStrSSE );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s( &in, &inverted, &results );\n", mulFuncStrSSE );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s inverseResults[4];\n", memberTypeString );
		String_Append(  codeTests, "\n" );
		for ( u32 row = 0; row < numRows; row++ ) {
			for ( u32 col = 0; col < numCols; col++ ) {
				String_Appendf( codeTests, "\t%s( inverseResults, results.m[%d][%d] );\n", storeFuncStr, row, col );

				for ( u32 componentIndex = 0; componentIndex < 4; componentIndex++ ) {
					char componentStr = GEN_COMPONENT_NAMES_VECTOR[col];

					String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( inverseResults[%d], id.rows[%d].%c, %s ) );\n", floateqepsStr, componentIndex, row, componentStr, epsilonStr );
				}

				String_Append( codeTests, "\n" );
			}
		}
		String_Append(  codeTests, "}\n" );
		String_Append(  codeTests, "\n" );
	}
}

static void GenerateTestTranslate( stringBuilder_t* codeTests, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols,
	const char* fullTypeName, const char* typeString, const char* memberTypeString ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( typeString );
	assert( memberTypeString );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( numRows < 3 || numCols < numRows ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestTranslate_Scalar_%s", fullTypeName );

	char translateVectorTypeString[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( translateVectorTypeString, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, numCols - 1 );

	u32 translateVecComponents = numCols - 1;

	float valuesTranslateVec[GEN_COMPONENT_COUNT_MAX - 1] = {
		2.0f, 3.0f, 4.0f
	};

	char parmListTranslateVec[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, translateVecComponents, valuesTranslateVec, parmListTranslateVec );

	const char* floateqStr = Gen_GetFuncNameFloateq( type );

	char translateComponentStr = GEN_COMPONENT_NAMES_VECTOR[translateVecComponents];

	char translateVecStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameTranslate( language, type, numRows, numCols, translateVecStr );

	char identityFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameIdentity( language, type, numRows, numCols, identityFuncStr );

	const char* parmRefStr = GEN_TYPE_PARM_REFERENCE_MODIFIERS[language];

	String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s mat;\n", fullTypeName );
	String_Appendf( codeTests, "\t%s( %smat );\n", identityFuncStr, parmRefStr );
	String_Append(  codeTests, "\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s translation = { %s };\n", translateVectorTypeString, parmListTranslateVec );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tmat = %s( &mat, &translation );\n", translateVecStr );
	} else {
		String_Appendf( codeTests, "\t%s translation = %s( %s );\n", translateVectorTypeString, translateVectorTypeString, parmListTranslateVec );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tmat = %s( mat, translation );\n", translateVecStr );
	}
	String_Append(  codeTests, "\n" );
	if ( Gen_TypeIsFloatingPoint( type ) ) {
		for ( u32 i = 0; i < translateVecComponents; i++ ) {
			char translateValueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
			Gen_GetNumericLiteral( type, valuesTranslateVec[i], translateValueStr, 1 );

			String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( mat.rows[%d].%c, %s ) );\n", floateqStr, i, translateComponentStr, translateValueStr );
		}
	} else {
		for ( u32 i = 0; i < translateVecComponents; i++ ) {
			char translateValueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
			Gen_GetNumericLiteral( type, valuesTranslateVec[i], translateValueStr, 1 );

			String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( mat.rows[%d].%c == %s );\n", i, translateComponentStr, translateValueStr );
		}
	}
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	if ( Gen_TypeSupportsSSE( type ) ) {
		// rules for generating SSE versions of translate() and scale() function are different from the scalar implementation
		if ( numCols < 3 || numRows != numCols ) {
			return;
		}

		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestTranslate_SSE_%s", fullTypeName );

		char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( type, numRows, numCols, sseTypeName );

		char translateVecTypeName[GEN_STRING_LENGTH_TYPE_NAME];
		Gen_GetFullTypeName( type, 1, translateVecComponents, translateVecTypeName );

		char sseTranslateVecName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( type, 1, translateVecComponents, sseTranslateVecName );

		const char* loadFuncStr = Gen_SSE_GetIntrinsicLoad( type );
		const char* storeFuncStr = Gen_SSE_GetIntrinsicStore( type );

		char translateFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameTranslate( language, type, numRows, numCols, translateFuncStrSSE );

		String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
		String_Append(  codeTests, "{\n" );
		String_Appendf( codeTests, "\t%s translateVecComponents[%d][4] =\n", memberTypeString, translateVecComponents );
		String_Append(  codeTests, "\t{\n" );
		for ( u32 i = 0; i < translateVecComponents; i++ ) {
			float value = valuesTranslateVec[i];
			float values[4] = { value, value, value, value };

			String_Append(  codeTests, "\t" );
			Gen_GetValuesArray1D( type, 4, values, codeTests );

			if ( i != translateVecComponents - 1 ) {
				String_Append(  codeTests, "," );
			}

			String_Appendf( codeTests, "\t// 4 %c components\n", GEN_COMPONENT_NAMES_VECTOR[i] );
		}
		String_Append(  codeTests, "\t};\n" );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s pos;\n", sseTranslateVecName );
		String_Appendf( codeTests, "\tmemset( &pos, 0, %d * sizeof( __m128 ) );\n", translateVecComponents );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s translation;\n", sseTranslateVecName );
		for ( u32 i = 0; i < translateVecComponents; i++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Appendf( codeTests, "\ttranslation.%c = %s( translateVecComponents[%d] );\n", componentStr, loadFuncStr, i );
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s( &pos, &translation, &pos );\n", translateFuncStrSSE );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s translateResults[4];\n", memberTypeString );
		String_Append(  codeTests, "\n" );
		for ( u32 componentIndex = 0; componentIndex < translateVecComponents; componentIndex++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[componentIndex];

			String_Appendf( codeTests, "\t%s( translateResults, pos.%c );\n", storeFuncStr, componentStr );
			for ( u32 i = 0; i < 4; i++ ) {
				char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
				Gen_GetNumericLiteral( type, valuesTranslateVec[componentIndex], valueStr );

				if ( Gen_TypeIsFloatingPoint( type ) ) {
					String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( translateResults[%d], %s ) );\n", floateqStr, i, valueStr );
				} else {
					String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( translateResults[%d] == %s );\n", floateqStr, i, valueStr );
				}
			}
			String_Append(  codeTests, "\n" );
		}
		String_Append(  codeTests, "}\n" );
		String_Append(  codeTests, "\n" );
	}
}

static void GenerateTestRotate( stringBuilder_t* codeTests, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const char* fullTypeName, const char* typeString ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( typeString );

	UNUSED( language );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	if ( numRows < 3 ) {
		return;
	}

	if ( numRows != numCols ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestRotate_%s", fullTypeName );

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

	u32 numRotMatRows = GEN_MIN( numRows, 4 );
	u32 numRotMatCols = GEN_MIN( numCols, 4 );

	u32 numRotateVectorComponents = numCols - 1;

	char rotDegreesStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, rotDegrees, rotDegreesStr, 1 );

	char rotateVecTypeString[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( rotateVecTypeString, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, numRotateVectorComponents );

	char parmListVecYaw[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numRotateVectorComponents, angleAxisVecYaw, parmListVecYaw );

	char parmListVecPitch[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numRotateVectorComponents, angleAxisVecPitch, parmListVecPitch );

	char parmListVecRoll[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numRotateVectorComponents, angleAxisVecRoll, parmListVecRoll );

	char parmListMatYaw[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrix( type, numRotMatRows, numRotMatCols, rotMatYaw, parmListMatYaw );

	char parmListMatPitch[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrix( type, numRotMatRows, numRotMatCols, rotMatPitch, parmListMatPitch );

	char parmListMatRoll[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrix( type, numRotMatRows, numRotMatCols, rotMatRoll, parmListMatRoll );

	const char* radiansFuncStr = Gen_GetFuncNameRadians( type );

	const char* parmRefStr = GEN_TYPE_PARM_REFERENCE_MODIFIERS[language];

	// matrices where cols == 3 only have roll rotation support
	char parmListRotateRoll[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };
	int pos = 0;
	pos += snprintf( parmListRotateRoll + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, "%smat, %s( %s )", parmRefStr, radiansFuncStr, rotDegreesStr );
	if ( numCols > 3 ) {
		pos += snprintf( parmListRotateRoll + pos, GEN_STRING_LENGTH_PARM_LIST_MATRIX, ", %srollVec", parmRefStr );
	}

	char identityFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameIdentity( language, type, numRows, numCols, identityFuncStr );

	char rotateFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameRotate( language, type, numRows, numCols, rotateFuncStr );

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, numRows, numCols, equalsFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s mat;\n", fullTypeName );
	String_Appendf( codeTests, "\t%s( %smat );\n", identityFuncStr, parmRefStr );
	String_Append(  codeTests, "\n" );
	if ( numRows > 3 ) {
		String_Appendf( codeTests, "\t%s rollVec = { %s };\n", rotateVecTypeString, parmListVecRoll );
	}
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s roll = %s( %s );\n", fullTypeName, rotateFuncStr, parmListRotateRoll );
		String_Appendf( codeTests, "\t%s answerRoll = (%s) {\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListMatRoll );
		String_Append(  codeTests, "\t};\n" );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &roll, &answerRoll ) );\n", equalsFuncStr );
		String_Append(  codeTests, "\n" );
		if ( numRows > 3 ) {
			String_Appendf( codeTests, "\t%s( &mat ); // reset the matrix\n", identityFuncStr );
			String_Appendf( codeTests, "\t%s yawVec = { %s };\n", rotateVecTypeString, parmListVecYaw );
			String_Appendf( codeTests, "\t%s yaw = %s( &mat, %s( %s ), &yawVec );\n", fullTypeName, rotateFuncStr, radiansFuncStr, rotDegreesStr );
			String_Appendf( codeTests, "\t%s answerYaw = (%s) {\n", fullTypeName, fullTypeName, parmListMatYaw );
			String_Appendf( codeTests, "%s", parmListMatYaw );
			String_Append(  codeTests, "\t};\n" );
			String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &yaw, &answerYaw ) );\n", equalsFuncStr );
			String_Append(  codeTests, "\n" );
			String_Appendf( codeTests, "\t%s( &mat ); // reset the matrix\n", identityFuncStr );
			String_Appendf( codeTests, "\t%s pitchVec = { %s };\n", rotateVecTypeString, parmListVecPitch );
			String_Appendf( codeTests, "\t%s pitch = %s( &mat, %s( %s ), &pitchVec );\n", fullTypeName, rotateFuncStr, radiansFuncStr, rotDegreesStr );
			String_Appendf( codeTests, "\t%s answerPitch = (%s) {\n", fullTypeName, fullTypeName );
			String_Appendf( codeTests, "%s", parmListMatPitch );
			String_Append(  codeTests, "\t};\n" );
			String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &pitch, &answerPitch ) );\n", equalsFuncStr );
		}
	} else {
		String_Appendf( codeTests, "\t%s roll = rotate( %s );\n", fullTypeName, parmListRotateRoll );
		String_Appendf( codeTests, "\t%s answerRoll = %s(\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListMatRoll );
		String_Append(  codeTests, "\t);\n" );
		String_Append(  codeTests, "\n" );
		if ( numRows > 3 ) {
			String_Appendf( codeTests, "\t%s yaw = %s( mat, %s( %s ), %s( %s ) );\n", fullTypeName, rotateFuncStr, radiansFuncStr, rotDegreesStr, rotateVecTypeString, parmListVecYaw );
			String_Appendf( codeTests, "\t%s answerYaw = %s( %s );\n", fullTypeName, fullTypeName, parmListMatYaw );
			String_Append( codeTests, "\tTEMPER_CHECK_TRUE( yaw == answerYaw );\n" );
			String_Append( codeTests, "\n" );
			String_Appendf( codeTests, "\t%s pitch = %s( mat, %s( %s ), %s( %s ) );\n", fullTypeName, rotateFuncStr, radiansFuncStr, rotDegreesStr, rotateVecTypeString, parmListVecPitch );
			String_Appendf( codeTests, "\t%s answerPitch = %s( %s );\n", fullTypeName, fullTypeName, parmListMatPitch );
			String_Append( codeTests, "\tTEMPER_CHECK_TRUE( pitch == answerPitch );\n" );
		}
		String_Append( codeTests, "\tTEMPER_CHECK_TRUE( roll == answerRoll );\n" );
	}
	String_Append( codeTests, "}\n" );
	String_Append( codeTests, "\n" );
}

static void GenerateTestScale( stringBuilder_t* codeTests, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols,
	const char* fullTypeName, const char* typeString, const char* memberTypeString ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( typeString );
	assert( memberTypeString );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( numCols < 3 ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestScale_Scalar_%s", fullTypeName );

	// const u32 scaleCols = 3;
	u32 scaleCols = GEN_MIN( numRows, numCols );
	scaleCols = GEN_MAX( scaleCols - 1, 2 );

	float scaleMatDiagonal[] = { 2.0f, 2.0f, 2.0f, 1.0f };

	char parmListScaleVec[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, scaleCols, scaleMatDiagonal, parmListScaleVec );

	char parmListscaleMat[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListMatrixDiagonal( type, numRows, numCols, scaleMatDiagonal, _countof( scaleMatDiagonal ), parmListscaleMat );

	char scaleVecTypeString[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( scaleVecTypeString, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, scaleCols );

	const char* floateqStr = Gen_GetFuncNameFloateq( type );

	const char* parmRefStr = GEN_TYPE_PARM_REFERENCE_MODIFIERS[language];

	char scaleFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameScale( language, type, numRows, numCols, scaleFuncStr );

	char identityFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameIdentity( language, type, numRows, numCols, identityFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s scaleVec = { %s };\n", scaleVecTypeString, parmListScaleVec );
	String_Appendf( codeTests, "\t%s mat;\n", fullTypeName );
	String_Appendf( codeTests, "\t%s( %smat );\n", identityFuncStr, parmRefStr );
	String_Append(  codeTests, "\n" );
	String_Appendf( codeTests, "\t%s scaled = %s( %smat, %sscaleVec );\n", fullTypeName, scaleFuncStr, parmRefStr, parmRefStr );
	String_Append(  codeTests, "\n" );
	if ( Gen_TypeIsFloatingPoint( type ) ) {
		for ( u32 i = 0; i < scaleCols; i++ ) {
			char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
			Gen_GetNumericLiteral( type, scaleMatDiagonal[i], valueStr );

			String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( scaled.rows[%d].%c, %s ) );\n", floateqStr, i, GEN_COMPONENT_NAMES_VECTOR[i], valueStr );
		}
	} else {
		for ( u32 i = 0; i < scaleCols; i++ ) {
			char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
			Gen_GetNumericLiteral( type, scaleMatDiagonal[i], valueStr );

			String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( scaled.rows[%d].%c == %s );\n", i, GEN_COMPONENT_NAMES_VECTOR[i], valueStr );
		}
	}
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	if ( Gen_TypeSupportsSSE( type ) ) {
		// rules for generating SSE versions of translate() and scale() function are different from the scalar implementation
		if ( numCols < 3 || numRows != numCols ) {
			return;
		}

		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestScale_SSE_%s", fullTypeName );

		char sseScaleVecName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( type, 1, scaleCols, sseScaleVecName );

		const char* set1FuncStr = Gen_SSE_GetIntrinsicSet1( type );
		const char* loadFuncStr = Gen_SSE_GetIntrinsicLoad( type );
		const char* storeFuncStr = Gen_SSE_GetIntrinsicStore( type );

		char scaleFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameScale( language, type, numRows, numCols, scaleFuncStrSSE );

		String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
		String_Append(  codeTests, "{\n" );
		String_Appendf( codeTests, "\t%s scaleVecComponents[%d][4] =\n", memberTypeString, scaleCols );
		String_Append(  codeTests, "\t{\n" );
		for ( u32 i = 0; i < scaleCols; i++ ) {
			float value = scaleMatDiagonal[i];
			float values[4] = { value, value, value, value };

			String_Append(  codeTests, "\t" );
			Gen_GetValuesArray1D( type, 4, values, codeTests );

			if ( i < scaleCols - 1 ) {
				String_Append(  codeTests, "," );
			}

			String_Appendf( codeTests, "\t// 4 %c components\n", GEN_COMPONENT_NAMES_VECTOR[i] );
		}
		String_Append(  codeTests, "\t};\n" );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s diagonal;\n", sseScaleVecName );
		for ( u32 i = 0; i < scaleCols; i++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Appendf( codeTests, "\tdiagonal.%c = %s( 1 );\n", componentStr, set1FuncStr );
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s scale;\n", sseScaleVecName );
		for ( u32 i = 0; i < scaleCols; i++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Appendf( codeTests, "\tscale.%c = %s( scaleVecComponents[%d] );\n", componentStr, loadFuncStr, i );
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s( &diagonal, &scale, &diagonal );\n", scaleFuncStrSSE );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s scaleResults[4];\n", memberTypeString );
		for ( u32 componentIndex = 0; componentIndex < scaleCols; componentIndex++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[componentIndex];

			String_Appendf( codeTests, "\t%s( scaleResults, diagonal.%c );\n", storeFuncStr, componentStr );

			for ( u32 i = 0; i < 4; i++ ) {
				char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
				Gen_GetNumericLiteral( type, scaleMatDiagonal[componentIndex], valueStr );

				if ( Gen_TypeIsFloatingPoint( type ) ) {
					String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( scaleResults[%d], %s ) );\n", floateqStr, i, valueStr );
				} else {
					String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( scaleResults[%d] == %s );\n", i, valueStr );
				}
			}
			String_Append(  codeTests, "\n" );
		}
		String_Append(  codeTests, "}\n" );
		String_Append(  codeTests, "\n" );
	}
}

static void GenerateTestOrtho( stringBuilder_t* codeTests, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const char* fullTypeName, const char* typeString ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( typeString );

	UNUSED( language );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	if ( numRows < 4 || numCols < 4 ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestOrtho_%s", fullTypeName );

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

	Gen_GetParmListMatrix( type, 4, 4, answerOrtho_LH_ZO, parmListAnswerOrtho_LH_ZO );
	Gen_GetParmListMatrix( type, 4, 4, answerOrtho_LH_NO, parmListAnswerOrtho_LH_NO );
	Gen_GetParmListMatrix( type, 4, 4, answerOrtho_RH_ZO, parmListAnswerOrtho_RH_ZO );
	Gen_GetParmListMatrix( type, 4, 4, answerOrtho_RH_NO, parmListAnswerOrtho_RH_NO );

	char minusOneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char fiveStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char oneHundredStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	char widthStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char heightStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, -1.0f,   minusOneStr, 1 );
	Gen_GetNumericLiteral( type,  5.0f,   fiveStr, 1 );
	Gen_GetNumericLiteral( type,  100.0f, oneHundredStr, 1 );

	Gen_GetNumericLiteral( type, 1280.0f, widthStr, 1 );
	Gen_GetNumericLiteral( type, 720.0f,  heightStr, 1 );

	char orthoFuncStr_LH_ZO[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameOrtho( language, type, numRows, numCols, GEN_HAND_LEFT, GEN_CLIP_SPACE_ZERO_TO_ONE, orthoFuncStr_LH_ZO );

	char orthoFuncStr_LH_NO[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameOrtho( language, type, numRows, numCols, GEN_HAND_LEFT, GEN_CLIP_SPACE_MINUS_ONE_TO_ONE, orthoFuncStr_LH_NO );

	char orthoFuncStr_RH_ZO[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameOrtho( language, type, numRows, numCols, GEN_HAND_RIGHT, GEN_CLIP_SPACE_ZERO_TO_ONE, orthoFuncStr_RH_ZO );

	char orthoFuncStr_RH_NO[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameOrtho( language, type, numRows, numCols, GEN_HAND_RIGHT, GEN_CLIP_SPACE_MINUS_ONE_TO_ONE, orthoFuncStr_RH_NO );

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, numRows, numCols, equalsFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
	String_Append(  codeTests, "{\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s answerOrtho_LH_ZO = (%s) {\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListAnswerOrtho_LH_ZO );
		String_Append(  codeTests, "\t};\n" );
		String_Appendf( codeTests, "\t%s answerOrtho_LH_NO = (%s) {\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListAnswerOrtho_LH_NO );
		String_Append(  codeTests, "\t};\n" );
		String_Appendf( codeTests, "\t%s answerOrtho_RH_ZO = (%s) {\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListAnswerOrtho_RH_ZO );
		String_Append(  codeTests, "\t};\n" );
		String_Appendf( codeTests, "\t%s answerOrtho_RH_NO = (%s) {\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListAnswerOrtho_RH_NO );
		String_Append(  codeTests, "\t};\n" );
	} else {
		String_Appendf( codeTests, "\t%s answerOrtho_LH_ZO = %s(\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListAnswerOrtho_LH_ZO );
		String_Append(  codeTests, "\t);\n" );
		String_Appendf( codeTests, "\t%s answerOrtho_LH_NO = %s(\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListAnswerOrtho_LH_NO );
		String_Append(  codeTests, "\t);\n" );
		String_Appendf( codeTests, "\t%s answerOrtho_RH_ZO = %s(\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListAnswerOrtho_RH_ZO );
		String_Append(  codeTests, "\t);\n" );
		String_Appendf( codeTests, "\t%s answerOrtho_RH_NO = %s(\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListAnswerOrtho_RH_NO );
		String_Append(  codeTests, "\t);\n" );
	}
	String_Append(  codeTests, "\n" );
	String_Appendf( codeTests, "\t%s width     = %s;\n", typeString, widthStr );
	String_Appendf( codeTests, "\t%s height    = %s;\n", typeString, heightStr );
	String_Appendf( codeTests, "\t%s aspect    = width / height;\n", typeString );
	String_Appendf( codeTests, "\t%s orthoSize = %s;\n", typeString, fiveStr );
	String_Append(  codeTests, "\n" );
	String_Appendf( codeTests, "\t%s left   = -aspect * orthoSize;\n", typeString );
	String_Appendf( codeTests, "\t%s right  =  aspect * orthoSize;\n", typeString );
	String_Appendf( codeTests, "\t%s top    = -orthoSize;\n", typeString );
	String_Appendf( codeTests, "\t%s bottom =  orthoSize;\n", typeString );
	String_Append(  codeTests, "\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s mat_LH_ZO = %s( left, right, top, bottom, %s, %s );\n", fullTypeName, orthoFuncStr_LH_ZO, minusOneStr, oneHundredStr );
		String_Appendf( codeTests, "\t%s mat_LH_NO = %s( left, right, top, bottom, %s, %s );\n", fullTypeName, orthoFuncStr_LH_NO, minusOneStr, oneHundredStr );
		String_Appendf( codeTests, "\t%s mat_RH_ZO = %s( left, right, top, bottom, %s, %s );\n", fullTypeName, orthoFuncStr_RH_ZO, minusOneStr, oneHundredStr );
		String_Appendf( codeTests, "\t%s mat_RH_NO = %s( left, right, top, bottom, %s, %s );\n", fullTypeName, orthoFuncStr_RH_NO, minusOneStr, oneHundredStr );
		String_Append(  codeTests, "\n" );
		String_Appendf(  codeTests, "\tTEMPER_CHECK_TRUE( %s( &mat_LH_ZO, &answerOrtho_LH_ZO ) );\n", equalsFuncStr );
		String_Appendf(  codeTests, "\tTEMPER_CHECK_TRUE( %s( &mat_LH_NO, &answerOrtho_LH_NO ) );\n", equalsFuncStr );
		String_Appendf(  codeTests, "\tTEMPER_CHECK_TRUE( %s( &mat_RH_ZO, &answerOrtho_RH_ZO ) );\n", equalsFuncStr );
		String_Appendf(  codeTests, "\tTEMPER_CHECK_TRUE( %s( &mat_RH_NO, &answerOrtho_RH_NO ) );\n", equalsFuncStr );
	} else {
		String_Appendf( codeTests, "\t%s mat_LH_ZO = %s( left, right, top, bottom, %s, %s );\n", fullTypeName, orthoFuncStr_LH_ZO, minusOneStr, oneHundredStr );
		String_Appendf( codeTests, "\t%s mat_LH_NO = %s( left, right, top, bottom, %s, %s );\n", fullTypeName, orthoFuncStr_LH_NO, minusOneStr, oneHundredStr );
		String_Appendf( codeTests, "\t%s mat_RH_ZO = %s( left, right, top, bottom, %s, %s );\n", fullTypeName, orthoFuncStr_RH_ZO, minusOneStr, oneHundredStr );
		String_Appendf( codeTests, "\t%s mat_RH_NO = %s( left, right, top, bottom, %s, %s );\n", fullTypeName, orthoFuncStr_RH_NO, minusOneStr, oneHundredStr );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( mat_LH_ZO == answerOrtho_LH_ZO );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( mat_LH_NO == answerOrtho_LH_NO );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( mat_RH_ZO == answerOrtho_RH_ZO );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( mat_RH_NO == answerOrtho_RH_NO );\n" );
	}
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );
}

static void GenerateTestPerspective( stringBuilder_t* codeTests, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const char* fullTypeName, const char* typeString ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( typeString );

	UNUSED( language );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	if ( numRows < 4 || numCols < 4 ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestPerspective_%s", fullTypeName );

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

	Gen_GetParmListMatrix( type, 4, 4, answerPerspective_LH_ZO, parmListPerspective_LH_ZO );
	Gen_GetParmListMatrix( type, 4, 4, answerPerspective_LH_NO, parmListPerspective_LH_NO );
	Gen_GetParmListMatrix( type, 4, 4, answerPerspective_RH_ZO, parmListPerspective_RH_ZO );
	Gen_GetParmListMatrix( type, 4, 4, answerPerspective_RH_NO, parmListPerspective_RH_NO );

	char widthStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char heightStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	char fovStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char znearStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char zfarStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, 1280.0f, widthStr, 1 );
	Gen_GetNumericLiteral( type, 720.0f, heightStr, 1 );

	Gen_GetNumericLiteral( type, 90.0f, fovStr, 1 );
	Gen_GetNumericLiteral( type, 0.1f, znearStr, 1 );
	Gen_GetNumericLiteral( type, 100.0f, zfarStr, 1 );

	char perspectiveFuncStr_LH_ZO[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNamePerspective( language, type, numRows, numCols, GEN_HAND_LEFT, GEN_CLIP_SPACE_ZERO_TO_ONE, perspectiveFuncStr_LH_ZO );

	char perspectiveFuncStr_LH_NO[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNamePerspective( language, type, numRows, numCols, GEN_HAND_LEFT, GEN_CLIP_SPACE_MINUS_ONE_TO_ONE, perspectiveFuncStr_LH_NO );

	char perspectiveFuncStr_RH_ZO[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNamePerspective( language, type, numRows, numCols, GEN_HAND_RIGHT, GEN_CLIP_SPACE_ZERO_TO_ONE, perspectiveFuncStr_RH_ZO );

	char perspectiveFuncStr_RH_NO[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNamePerspective( language, type, numRows, numCols, GEN_HAND_RIGHT, GEN_CLIP_SPACE_MINUS_ONE_TO_ONE, perspectiveFuncStr_RH_NO );

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, numRows, numCols, equalsFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
	String_Append(  codeTests, "{\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s answerPerspective_LH_ZO = (%s) {\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListPerspective_LH_ZO );
		String_Append(  codeTests, "\t};\n" );
		String_Appendf( codeTests, "\t%s answerPerspective_LH_NO = (%s) {\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListPerspective_LH_NO );
		String_Append(  codeTests, "\t};\n" );
		String_Appendf( codeTests, "\t%s answerPerspective_RH_ZO = (%s) {\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListPerspective_RH_ZO );
		String_Append(  codeTests, "\t};\n" );
		String_Appendf( codeTests, "\t%s answerPerspective_RH_NO = (%s) {\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListPerspective_RH_NO );
		String_Append(  codeTests, "\t};\n" );
	} else {
		String_Appendf( codeTests, "\t%s answerPerspective_LH_ZO = %s(\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListPerspective_LH_ZO );
		String_Append(  codeTests, "\t);\n" );
		String_Appendf( codeTests, "\t%s answerPerspective_LH_NO = %s(\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListPerspective_LH_NO );
		String_Append(  codeTests, "\t);\n" );
		String_Appendf( codeTests, "\t%s answerPerspective_RH_ZO = %s(\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListPerspective_RH_ZO );
		String_Append(  codeTests, "\t);\n" );
		String_Appendf( codeTests, "\t%s answerPerspective_RH_NO = %s(\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListPerspective_RH_NO );
		String_Append(  codeTests, "\t);\n" );
	}
	String_Append(  codeTests, "\n" );
	String_Appendf( codeTests, "\t%s aspect = %s / %s;\n", typeString, widthStr, heightStr );
	String_Append(  codeTests, "\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s mat_LH_ZO = %s( %s, aspect, %s, %s );\n", fullTypeName, perspectiveFuncStr_LH_ZO, fovStr, znearStr, zfarStr );
		String_Appendf( codeTests, "\t%s mat_LH_NO = %s( %s, aspect, %s, %s );\n", fullTypeName, perspectiveFuncStr_LH_NO, fovStr, znearStr, zfarStr );
		String_Appendf( codeTests, "\t%s mat_RH_ZO = %s( %s, aspect, %s, %s );\n", fullTypeName, perspectiveFuncStr_RH_ZO, fovStr, znearStr, zfarStr );
		String_Appendf( codeTests, "\t%s mat_RH_NO = %s( %s, aspect, %s, %s );\n", fullTypeName, perspectiveFuncStr_RH_NO, fovStr, znearStr, zfarStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &mat_LH_ZO, &answerPerspective_LH_ZO ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &mat_LH_NO, &answerPerspective_LH_NO ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &mat_RH_ZO, &answerPerspective_RH_ZO ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &mat_RH_NO, &answerPerspective_RH_NO ) );\n", equalsFuncStr );
	} else {
		String_Appendf( codeTests, "\t%s mat_LH_ZO = %s( %s, aspect, %s, %s );\n", fullTypeName, perspectiveFuncStr_LH_ZO, fovStr, znearStr, zfarStr );
		String_Appendf( codeTests, "\t%s mat_LH_NO = %s( %s, aspect, %s, %s );\n", fullTypeName, perspectiveFuncStr_LH_NO, fovStr, znearStr, zfarStr );
		String_Appendf( codeTests, "\t%s mat_RH_ZO = %s( %s, aspect, %s, %s );\n", fullTypeName, perspectiveFuncStr_RH_ZO, fovStr, znearStr, zfarStr );
		String_Appendf( codeTests, "\t%s mat_RH_NO = %s( %s, aspect, %s, %s );\n", fullTypeName, perspectiveFuncStr_RH_NO, fovStr, znearStr, zfarStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( mat_LH_ZO == answerPerspective_LH_ZO );\n" );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( mat_LH_NO == answerPerspective_LH_NO );\n" );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( mat_RH_ZO == answerPerspective_RH_ZO );\n" );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( mat_RH_NO == answerPerspective_RH_NO );\n" );
	}
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );
}

static void GenerateTestLookAt( stringBuilder_t* codeTests, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const char* fullTypeName, const char* typeString ) {
	assert( codeTests );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( typeString );

	UNUSED( language );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	if ( numRows < 4 || numCols < 4 ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestLookAt_%s", fullTypeName );

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
	snprintf( posVectorTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, numTranslateVecComponents );

	char parmListCurrentPos[GEN_STRING_LENGTH_PARM_LIST_VECTOR]	= { 0 };
	char parmListTargetPos[GEN_STRING_LENGTH_PARM_LIST_VECTOR]	= { 0 };
	char parmListUp[GEN_STRING_LENGTH_PARM_LIST_VECTOR]			= { 0 };

	Gen_GetParmListVector( type, numTranslateVecComponents, currentPos, parmListCurrentPos );
	Gen_GetParmListVector( type, numTranslateVecComponents, targetPos, parmListTargetPos );
	Gen_GetParmListVector( type, numTranslateVecComponents, up, parmListUp );

	char parmListLookAt_LH[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };
	Gen_GetParmListMatrix( type, numRows, numCols, answerLookAt_LH, parmListLookAt_LH );

	char parmListLookAt_RH[GEN_STRING_LENGTH_PARM_LIST_MATRIX] = { 0 };
	Gen_GetParmListMatrix( type, numRows, numCols, answerLookAt_RH, parmListLookAt_RH );

	char lookAtFuncStr_LH[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameLookAt( language, type, numRows, numCols, GEN_HAND_LEFT, lookAtFuncStr_LH );

	char lookAtFuncStr_RH[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameLookAt( language, type, numRows, numCols, GEN_HAND_RIGHT, lookAtFuncStr_RH );

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, numRows, numCols, equalsFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s, TEMPER_FLAG_SHOULD_RUN )\n", testName );
	String_Append(  codeTests, "{\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s answerLookAt_LH = (%s) {\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListLookAt_LH );
		String_Append(  codeTests, "\t};\n" );
		String_Appendf( codeTests, "\t%s answerLookAt_RH = (%s) {\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListLookAt_RH );
		String_Append(  codeTests, "\t};\n" );
	} else {
		String_Appendf( codeTests, "\t%s answerLookAt_LH = %s(\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListLookAt_LH );
		String_Append(  codeTests, "\t);\n" );
		String_Appendf( codeTests, "\t%s answerLookAt_RH = %s(\n", fullTypeName, fullTypeName );
		String_Appendf( codeTests, "%s", parmListLookAt_RH );
		String_Append(  codeTests, "\t);\n" );
	}
	String_Append(  codeTests, "\n" );
	String_Appendf( codeTests, "\t%s currentPos = { %s };\n", posVectorTypeName, parmListCurrentPos );
	String_Appendf( codeTests, "\t%s targetPos = { %s };\n", posVectorTypeName, parmListTargetPos );
	String_Appendf( codeTests, "\t%s up = { %s };\n", posVectorTypeName, parmListUp );
	String_Append(  codeTests, "\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s mat_LH = %s( &currentPos, &targetPos, &up );\n", fullTypeName, lookAtFuncStr_LH );
		String_Appendf( codeTests, "\t%s mat_RH = %s( &currentPos, &targetPos, &up );\n", fullTypeName, lookAtFuncStr_RH );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &mat_LH, &answerLookAt_LH ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_CHECK_TRUE( %s( &mat_RH, &answerLookAt_RH ) );\n", equalsFuncStr );
	} else {
		String_Appendf( codeTests, "\t%s mat_LH = %s( currentPos, targetPos, up );\n", fullTypeName, lookAtFuncStr_LH );
		String_Appendf( codeTests, "\t%s mat_RH = %s( currentPos, targetPos, up );\n", fullTypeName, lookAtFuncStr_RH );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( mat_LH == answerLookAt_LH );\n" );
		String_Append(  codeTests, "\tTEMPER_CHECK_TRUE( mat_RH == answerLookAt_RH );\n" );
	}
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );
}

void Gen_MatrixTests( allocatorLinear_t* allocator, const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols ) {
	assert( allocator );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	const u32 testsCodeBytes = 90 * KB_TO_BYTES;
	const u32 suiteCodeBytes = 12 * KB_TO_BYTES;

	stringBuilder_t codeTests = String_Create( allocator, testsCodeBytes );

	const char* typeString = Gen_GetTypeString( type );
	const char* memberTypeString = Gen_GetMemberTypeString( type );

	char vectorTypeString[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( vectorTypeString, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, numCols );

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%dx%d", typeString, numRows, numCols );

	stringBuilder_t code = String_Create( allocator, testsCodeBytes + suiteCodeBytes );

	String_Append(  &code, GEN_FILE_HEADER );

	if ( type != GEN_TYPE_BOOL ) {
		char mulTypeNameRHS[GEN_STRING_LENGTH_TYPE_NAME];
		Gen_GetFullTypeName( type, numCols, numRows, mulTypeNameRHS );

		char mulTypeNameReturn[GEN_STRING_LENGTH_TYPE_NAME];
		Gen_GetFullTypeName( type, numRows, numRows, mulTypeNameReturn );

		static char matrixMultiplyParmListLHS[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
		Gen_GetParmListMatrix( type, numRows, numCols, g_matrixMultiplyTestLHS, matrixMultiplyParmListLHS );

		static char matrixMultiplyParmListRHS[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
		Gen_GetParmListMatrix( type, numCols, numRows, g_matrixMultiplyTestRHS, matrixMultiplyParmListRHS );

		static char matrixMultiplyParmListAnswer[GEN_STRING_LENGTH_PARM_LIST_MATRIX];
		GetParmListMatrixMultiply( type, numCols, numRows, numRows, g_matrixMultiplyTestLHS, g_matrixMultiplyTestRHS, matrixMultiplyParmListAnswer );

		if ( language == GEN_LANGUAGE_C ) {
			String_Appendf( &code, "static %s g_matrixMulLHS_%s    = {\n", fullTypeName, fullTypeName, fullTypeName );
			String_Appendf( &code, "%s", matrixMultiplyParmListLHS );
			String_Appendf( &code, "};\n" );
			String_Appendf( &code, "\n" );
			String_Appendf( &code, "static %s g_matrixMulRHS_%s    = {\n", mulTypeNameRHS, fullTypeName, mulTypeNameRHS );
			String_Appendf( &code, "%s", matrixMultiplyParmListRHS );
			String_Appendf( &code, "};\n" );
			String_Appendf( &code, "\n" );
			String_Appendf( &code, "static %s g_matrixMulAnswer_%s = {\n", mulTypeNameReturn, fullTypeName, mulTypeNameReturn );
			String_Appendf( &code, "%s", matrixMultiplyParmListAnswer );
			String_Appendf( &code, "};\n" );
			String_Appendf( &code, "\n" );
		} else {
			String_Appendf( &code, "static %s g_matrixMulLHS_%s    = %s( %s );\n\n", fullTypeName, fullTypeName, fullTypeName, matrixMultiplyParmListLHS );
			String_Appendf( &code, "static %s g_matrixMulRHS_%s    = %s( %s );\n\n", mulTypeNameRHS, fullTypeName, mulTypeNameRHS, matrixMultiplyParmListRHS );
			String_Appendf( &code, "static %s g_matrixMulAnswer_%s = %s( %s );\n\n", mulTypeNameReturn, fullTypeName, mulTypeNameReturn, matrixMultiplyParmListAnswer );
		}
		String_Append(  &code, "\n" );
	}

	GenerateTestAssignment( &codeTests, language, type, numRows, numCols, fullTypeName, vectorTypeString );
	if ( language == GEN_LANGUAGE_CPP ) {
		GenerateTestCtor( &codeTests, type, numRows, numCols, fullTypeName, vectorTypeString );
		GenerateTestArray( &codeTests, type, numRows, numCols, fullTypeName, vectorTypeString );
		GenerateTestIncrement( &codeTests, type, numRows, numCols, fullTypeName );
	}
	GenerateTestComponentWiseArithmetic( &codeTests, language, type, numRows, numCols, fullTypeName, memberTypeString );
	GenerateTestMultiplyMatrix( &codeTests, language, type, numRows, numCols, fullTypeName, typeString, memberTypeString );
	GenerateTestMultiplyVector( &codeTests, language, type, numRows, numCols, fullTypeName, vectorTypeString );
	GenerateTestDivideMatrix( &codeTests, language, type, numRows, numCols, fullTypeName );
	GenerateTestRelational( &codeTests, language, type, numRows, numCols, fullTypeName );
	GenerateTestBitwise( &codeTests, language, type, numRows, numCols, fullTypeName, memberTypeString );
	GenerateTestIdentity( &codeTests, language, type, numRows, numCols, fullTypeName, vectorTypeString, memberTypeString );
	GenerateTestTranspose( &codeTests, language, type, numRows, numCols, fullTypeName, vectorTypeString, typeString, memberTypeString );
	GenerateTestDeterminant( &codeTests, language, type, numRows, numCols, fullTypeName, memberTypeString );
	GenerateTestInverse( &codeTests, language, type, numRows, numCols, fullTypeName, memberTypeString );
	GenerateTestTranslate( &codeTests, language, type, numRows, numCols, fullTypeName, typeString, memberTypeString );
	GenerateTestRotate( &codeTests, language, type, numRows, numCols, fullTypeName, typeString );
	GenerateTestScale( &codeTests, language, type, numRows, numCols, fullTypeName, typeString, memberTypeString );
	GenerateTestOrtho( &codeTests, language, type, numRows, numCols, fullTypeName, typeString );
	GenerateTestPerspective( &codeTests, language, type, numRows, numCols, fullTypeName, typeString );
	GenerateTestLookAt( &codeTests, language, type, numRows, numCols, fullTypeName, typeString );

	String_Append( &code, codeTests.str );

	char filename[64] = { 0 };
	snprintf( filename, 64, "%stest_%s.%s", GEN_FOLDER_PATHS_TESTS[language], fullTypeName, GEN_SOURCE_FILE_EXTENSIONS[language] );

	FS_WriteEntireFile( filename, code.str, code.length );

	Mem_Reset( allocator );
}
