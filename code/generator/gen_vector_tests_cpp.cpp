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
#include "gen_vector_cpp.h"

#include "gen_funcs_vector.h"
#include "gen_common_sse.h"

#include "defines.h"
#include "string_builder.h"
#include "allocator.h"
#include "file_io.h"

static void GenerateTestAssignment( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genType_t type, const u32 numComponents, const char* fullTypeName ) {
	assert( codeTests );
	assert( codeSuite );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestAssignment_%s", fullTypeName );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1, oneStr, 1 );

	float values[] = { 0.0f, 1.0f, 2.0f, 3.0f };

	char parmListVarying[64] = { 0 };
	Gen_GetParmListVector( type, numComponents, values, parmListVarying );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s vec;\n", fullTypeName );
	String_Append(  codeTests, "\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( codeTests, "\tvec.%c = %s;\n", GEN_COMPONENT_NAMES_VECTOR[i], oneStr );
	}
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( vec.%c == %s );\n", GEN_COMPONENT_NAMES_VECTOR[i], oneStr );
	}
	String_Append(  codeTests, "\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
		Gen_GetNumericLiteral( type, values[i], valueStr, 1 );

		String_Appendf( codeTests, "\tvec.%c = %s;\n", GEN_COMPONENT_NAMES_VECTOR[i], valueStr );
	}
	for ( u32 i = 0; i < numComponents; i++ ) {
		char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
		Gen_GetNumericLiteral( type, values[i], valueStr, 1 );

		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( vec.%c == %s );\n", GEN_COMPONENT_NAMES_VECTOR[i], valueStr );
	}
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

// DM!!! test all ctors
static void GenerateTestConstruct( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genType_t type, const u32 numComponents, const char* fullTypeName ) {
	assert( codeTests );
	assert( codeSuite );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestCtor_%s", fullTypeName );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1, oneStr, 1 );

	float values[] = { 0.0f, 1.0f, 2.0f, 3.0f };

	char parmListVarying[64] = { 0 };
	Gen_GetParmListVector( type, numComponents, values, parmListVarying );

	String_Append(  codeTests, "// also tests equality operators\n" );
	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s vec;\n", fullTypeName );
	String_Append(  codeTests, "\n" );
	String_Appendf( codeTests, "\tvec = %s( %s );\n", fullTypeName, oneStr );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( vec == %s( %s ) );\n", fullTypeName, oneStr );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( vec != %s( %s ) );\n", fullTypeName, parmListVarying );
	String_Append(  codeTests, "\n" );
	String_Appendf( codeTests, "\tvec = %s( %s );\n", fullTypeName, parmListVarying );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( vec == %s( %s ) );\n", fullTypeName, parmListVarying );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( vec != %s( %s ) );\n", fullTypeName, oneStr );
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestArray( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genType_t type, const u32 numComponents, const char* fullTypeName ) {
	assert( codeTests );
	assert( codeSuite );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestArray_%s", fullTypeName );

	float values[] = { 0.0f, 1.0f, 2.0f, 3.0f };

	char parmList[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numComponents, values, parmList );

	char valuesStr[4][GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 0, valuesStr[0], 1 );
	Gen_GetNumericLiteral( type, 1, valuesStr[1], 1 );
	Gen_GetNumericLiteral( type, 2, valuesStr[2], 1 );
	Gen_GetNumericLiteral( type, 3, valuesStr[3], 1 );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s a = %s( %s );\n", fullTypeName, fullTypeName, parmList );
	String_Append(  codeTests, "\n" );
	for ( u32 i = 0; i < numComponents; i++ ) {
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( a.%c == %s );\n", GEN_COMPONENT_NAMES_VECTOR[i], valuesStr[i] );
	}
	String_Append( codeTests, "\n" );
	String_Append( codeTests, "\tTEMPER_PASS();\n" );
	String_Append( codeTests, "}\n" );
	String_Append( codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestArithmetic( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genLanguage_t language, const genType_t type, const u32 numComponents, const char* fullTypeName ) {
	assert( codeTests );
	assert( codeSuite );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	// number picked at random
	float baseNumber = 6.0f;
	float valuesBaseNumber[] = { baseNumber, baseNumber, baseNumber, baseNumber };

	char baseNumberStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, baseNumber, baseNumberStr, 1 );

	float valuesArithmetic[GEN_OP_ARITHMETIC_COUNT][GEN_COMPONENT_COUNT_MAX] = {
		{ 2.0f,  3.0f,  4.0f,  5.0f  },
		{ 2.0f,  3.0f,  4.0f,  5.0f  },
		{ 2.0f,  3.0f,  4.0f,  5.0f  },
		{ 2.0f,  2.0f,  3.0f,  6.0f  }
	};

	float valuesAnswers[GEN_OP_ARITHMETIC_COUNT][GEN_COMPONENT_COUNT_MAX] = {
		{ 8.0f,  9.0f,  10.0f, 11.0f },
		{ 4.0f,  3.0f,  2.0f,  1.0f  },
		{ 12.0f, 18.0f, 24.0f, 30.0f },
		{ 3.0f,  3.0f,  2.0f,  1.0f  }
	};

	char parmListValues[GEN_OP_ARITHMETIC_COUNT][GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListVector( type, numComponents, valuesArithmetic[GEN_OP_ARITHMETIC_ADD], parmListValues[GEN_OP_ARITHMETIC_ADD] );
	Gen_GetParmListVector( type, numComponents, valuesArithmetic[GEN_OP_ARITHMETIC_SUB], parmListValues[GEN_OP_ARITHMETIC_SUB] );
	Gen_GetParmListVector( type, numComponents, valuesArithmetic[GEN_OP_ARITHMETIC_MUL], parmListValues[GEN_OP_ARITHMETIC_MUL] );
	Gen_GetParmListVector( type, numComponents, valuesArithmetic[GEN_OP_ARITHMETIC_DIV], parmListValues[GEN_OP_ARITHMETIC_DIV] );

	char parmListAnswers[GEN_OP_ARITHMETIC_COUNT][GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListVector( type, numComponents, valuesAnswers[GEN_OP_ARITHMETIC_ADD], parmListAnswers[GEN_OP_ARITHMETIC_ADD] );
	Gen_GetParmListVector( type, numComponents, valuesAnswers[GEN_OP_ARITHMETIC_SUB], parmListAnswers[GEN_OP_ARITHMETIC_SUB] );
	Gen_GetParmListVector( type, numComponents, valuesAnswers[GEN_OP_ARITHMETIC_MUL], parmListAnswers[GEN_OP_ARITHMETIC_MUL] );
	Gen_GetParmListVector( type, numComponents, valuesAnswers[GEN_OP_ARITHMETIC_DIV], parmListAnswers[GEN_OP_ARITHMETIC_DIV] );

	const char* suffices[GEN_OP_ARITHMETIC_COUNT] = {
		"Addition",
		"Subtraction",
		"Multiplication",
		"Division",
	};

	if ( language == GEN_LANGUAGE_C ) {
		for ( u32 i = 0; i < GEN_OP_ARITHMETIC_COUNT; i++ ) {
			const genOpArithmetic_t op = (genOpArithmetic_t) i;

			char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
			snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestArithmetic%s_%s", suffices[op], fullTypeName );

			char compFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
			Gen_GetFuncNameComponentWiseArithmeticVector( language, type, 1, numComponents, op, compFuncStr );

			String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
			String_Append(  codeTests, "{\n" );
			String_Appendf( codeTests, "\t%s a = (%s)", fullTypeName, fullTypeName );
			Gen_GetValuesArray1D( type, numComponents, valuesBaseNumber, codeTests );
			String_Append(  codeTests, ";\n" );
			String_Appendf( codeTests, "\t%s b = (%s)\t{ %s };\n", fullTypeName, fullTypeName, parmListValues[op] );
			String_Appendf( codeTests, "\t%s c = %s( &a, &b );\n", fullTypeName, compFuncStr );
			String_Append(  codeTests, "\n" );
			for ( u32 componentIndex = 0; componentIndex < numComponents; componentIndex++ ) {
				char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
				Gen_GetNumericLiteral( type, valuesAnswers[op][componentIndex], valueStr, 1 );

				String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( c.%c == %s );\n", GEN_COMPONENT_NAMES_VECTOR[componentIndex], valueStr );
			}
			String_Append(  codeTests, "\n" );
			String_Append(  codeTests, "\tTEMPER_PASS();\n" );
			String_Append(  codeTests, "}\n" );
			String_Append(  codeTests, "\n" );

			String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
		}
	} else {
		for ( u32 i = 0; i < GEN_OP_ARITHMETIC_COUNT; i++ ) {
			char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
			snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestArithmetic%s_%s", suffices[i], fullTypeName );

			String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
			String_Append(  codeTests, "{\n" );
			String_Appendf( codeTests, "\t%s a = %s( %s );\n", fullTypeName, fullTypeName, baseNumberStr );
			String_Appendf( codeTests, "\t%s b = %s( %s );\n", fullTypeName, fullTypeName, parmListValues[i] );
			String_Append(  codeTests, "\n" );
			String_Appendf( codeTests, "\t%s c = a %c b;\n", fullTypeName, GEN_OPERATORS_ARITHMETIC[i] );
			String_Append(  codeTests, "\n" );
			String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( c == %s( %s ) );\n", fullTypeName, parmListAnswers[i] );
			String_Append(  codeTests, "\n" );
			String_Append(  codeTests, "\tTEMPER_PASS();\n" );
			String_Append(  codeTests, "}\n" );
			String_Append(  codeTests, "\n" );

			String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
		}
	}
}

static void GenerateTestIncrement( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genType_t type, const u32 numComponents, const char* fullTypeName ) {
	assert( codeTests );
	assert( codeSuite );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	float values0[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	float values1[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	char parmListVecs[2][GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListVector( type, numComponents, values0, parmListVecs[0] );
	Gen_GetParmListVector( type, numComponents, values1, parmListVecs[1] );

	char parmListAnswers[2][GEN_STRING_LENGTH_PARM_LIST_MATRIX];
	Gen_GetParmListVector( type, numComponents, values1, parmListAnswers[0] );
	Gen_GetParmListVector( type, numComponents, values0, parmListAnswers[1] );

	const char* suffices[GEN_OP_INCREMENT_COUNT] = {
		"Increment",
		"Decrement",
	};

	for ( u32 i = 0; i < GEN_OP_INCREMENT_COUNT; i++ ) {
		char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "Test%s_%s", suffices[i], fullTypeName );

		String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  codeTests, "{\n" );
		String_Appendf( codeTests, "\t%s vec;\n", fullTypeName );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\t// prefix\n" );
		String_Appendf( codeTests, "\tvec = %s( %s );\n", fullTypeName, parmListVecs[i] );
		String_Appendf( codeTests, "\t%svec;\n", GEN_OPERATORS_INCREMENT[i] );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( vec == %s( %s ) );\n", fullTypeName, parmListAnswers[i] );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\t// postfix\n" );
		String_Appendf( codeTests, "\tvec = %s( %s );\n", fullTypeName, parmListVecs[i] );
		String_Appendf( codeTests, "\tvec%s;\n", GEN_OPERATORS_INCREMENT[i] );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( vec == %s( %s ) );\n", fullTypeName, parmListAnswers[i] );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  codeTests, "}\n" );
		String_Append(  codeTests, "\n" );

		String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

static void GenerateTestRelational( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genLanguage_t language, const genType_t type, const u32 numComponents, const char* fullTypeName ) {
	assert( codeTests );
	assert( codeSuite );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestRelational_%s", fullTypeName );

	char boolTypeName[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	snprintf( boolTypeName, GEN_STRING_LENGTH_NUMERIC_LITERAL, "bool%d", numComponents );

	float valuesAllTrue[GEN_COMPONENT_COUNT_MAX] = { 1.0f, 1.0f, 1.0f, 1.0f };

	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char twoStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char threeStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, 0, zeroStr, 1 );
	Gen_GetNumericLiteral( type, 1, oneStr, 1 );
	Gen_GetNumericLiteral( type, 2, twoStr, 1 );
	Gen_GetNumericLiteral( type, 3, threeStr, 1 );

	char parmLists[4][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf( parmLists[0], 64, "%s", zeroStr );
	snprintf( parmLists[1], 64, "%s", oneStr );
	snprintf( parmLists[2], 64, "%s", twoStr );
	snprintf( parmLists[3], 64, "%s", threeStr );

	char cmplFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameRelational( language, type, 1, numComponents, GEN_OP_RELATIONAL_LESS, cmplFuncStr );

	char cmpleFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameRelational( language, type, 1, numComponents, GEN_OP_RELATIONAL_LESS_EQUAL, cmpleFuncStr );

	char cmpgeFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameRelational( language, type, 1, numComponents, GEN_OP_RELATIONAL_GREATER_EQUAL, cmpgeFuncStr );

	char cmpgFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameRelational( language, type, 1, numComponents, GEN_OP_RELATIONAL_GREATER, cmpgFuncStr );

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, GEN_TYPE_BOOL, 1, numComponents, equalsFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s allTrue = (%s)", boolTypeName, boolTypeName );
		Gen_GetValuesArray1D( GEN_TYPE_BOOL, numComponents, valuesAllTrue, codeTests );
		String_Append( codeTests, ";\n" );
		String_Append( codeTests, "\n" );
		for ( u32 i = 0; i < 4; i++ ) {
			String_Appendf( codeTests, "\t%s vec%d = (%s)", fullTypeName, i, fullTypeName );

			float value = (float) i;
			float values[GEN_COMPONENT_COUNT_MAX] = { value, value, value, value };
			Gen_GetValuesArray1D( type, numComponents, values, codeTests );
			String_Append( codeTests, ";\n" );
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s test0  = %s( &vec0, &vec0 );\n", boolTypeName, cmpleFuncStr );
		String_Appendf( codeTests, "\t%s test1  = %s( &vec0, &vec0 );\n", boolTypeName, cmpgeFuncStr );
		String_Appendf( codeTests, "\t%s test2  = %s( &vec0, &vec1 );\n", boolTypeName, cmplFuncStr );
		String_Appendf( codeTests, "\t%s test3  = %s( &vec0, &vec2 );\n", boolTypeName, cmplFuncStr );
		String_Appendf( codeTests, "\t%s test4  = %s( &vec0, &vec3 );\n", boolTypeName, cmplFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s test5  = %s( &vec1, &vec0 );\n", boolTypeName, cmpgFuncStr );
		String_Appendf( codeTests, "\t%s test6  = %s( &vec1, &vec1 );\n", boolTypeName, cmpleFuncStr );
		String_Appendf( codeTests, "\t%s test7  = %s( &vec1, &vec1 );\n", boolTypeName, cmpgeFuncStr );
		String_Appendf( codeTests, "\t%s test8  = %s( &vec1, &vec2 );\n", boolTypeName, cmplFuncStr );
		String_Appendf( codeTests, "\t%s test9  = %s( &vec1, &vec3 );\n", boolTypeName, cmplFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s test10 = %s( &vec2, &vec0 );\n", boolTypeName, cmpgFuncStr );
		String_Appendf( codeTests, "\t%s test11 = %s( &vec2, &vec1 );\n", boolTypeName, cmpgFuncStr );
		String_Appendf( codeTests, "\t%s test12 = %s( &vec2, &vec2 );\n", boolTypeName, cmpleFuncStr );
		String_Appendf( codeTests, "\t%s test13 = %s( &vec2, &vec2 );\n", boolTypeName, cmpgeFuncStr );
		String_Appendf( codeTests, "\t%s test14 = %s( &vec2, &vec3 );\n", boolTypeName, cmplFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s test15 = %s( &vec3, &vec0 );\n", boolTypeName, cmpgFuncStr );
		String_Appendf( codeTests, "\t%s test16 = %s( &vec3, &vec1 );\n", boolTypeName, cmpgFuncStr );
		String_Appendf( codeTests, "\t%s test17 = %s( &vec3, &vec2 );\n", boolTypeName, cmpgFuncStr );
		String_Appendf( codeTests, "\t%s test18 = %s( &vec3, &vec3 );\n", boolTypeName, cmpleFuncStr );
		String_Appendf( codeTests, "\t%s test19 = %s( &vec3, &vec3 );\n", boolTypeName, cmpgeFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test0,  &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test1,  &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test2,  &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test3,  &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test4,  &allTrue ) );\n", equalsFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test5,  &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test6,  &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test7,  &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test8,  &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test9,  &allTrue ) );\n", equalsFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test10, &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test11, &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test12, &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test13, &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test14, &allTrue ) );\n", equalsFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test15, &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test16, &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test17, &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test18, &allTrue ) );\n", equalsFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &test19, &allTrue ) );\n", equalsFuncStr );
	} else {
		String_Appendf( codeTests, "\t%s allTrue = %s( true );\n", boolTypeName, boolTypeName );
		String_Append(  codeTests, "\n" );
		for ( u32 i = 0; i < 4; i++ ) {
			String_Appendf( codeTests, "\t%s vec%d = %s( %s );\n", fullTypeName, i, fullTypeName, parmLists[i] );
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s test0  = vec0 <= vec0;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test1  = vec0 >= vec0;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test2  = vec0 <  vec1;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test3  = vec0 <  vec2;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test4  = vec0 <  vec3;\n", boolTypeName );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s test5  = vec1 >  vec0;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test6  = vec1 <= vec1;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test7  = vec1 >= vec1;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test8  = vec1 <  vec2;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test9  = vec1 <  vec3;\n", boolTypeName );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s test10 = vec2 >  vec0;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test11 = vec2 >  vec1;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test12 = vec2 <= vec2;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test13 = vec2 >= vec2;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test14 = vec2 <  vec3;\n", boolTypeName );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s test15 = vec3 >  vec0;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test16 = vec3 >  vec1;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test17 = vec3 >  vec2;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test18 = vec3 <= vec3;\n", boolTypeName );
		String_Appendf( codeTests, "\t%s test19 = vec3 >= vec3;\n", boolTypeName );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test0  == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test1  == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test2  == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test3  == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test4  == allTrue );\n" );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test5  == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test6  == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test7  == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test8  == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test9  == allTrue );\n" );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test10 == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test11 == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test12 == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test13 == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test14 == allTrue );\n" );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test15 == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test16 == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test17 == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test18 == allTrue );\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( test19 == allTrue );\n" );
	}
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestBitwise( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genLanguage_t language, const genType_t type, const u32 numComponents, const char* fullTypeName, const char* memberTypeString ) {
	assert( codeTests );
	assert( codeSuite );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	if ( !Gen_TypeIsInteger( type ) ) {
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

	char parmListAnswerUnary[32];
	snprintf( parmListAnswerUnary, 32, "(%s) -1", memberTypeString );

	// -1 to exclude unary, which is done separately because it takes no rhs parm
	char parmListLhs[GEN_OP_BITWISE_COUNT - 1][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numComponents, values21, parmListLhs[0] );
	Gen_GetParmListVector( type, numComponents, values21, parmListLhs[1] );
	Gen_GetParmListVector( type, numComponents, values21, parmListLhs[2] );
	Gen_GetParmListVector( type, numComponents, values1 , parmListLhs[3] );
	Gen_GetParmListVector( type, numComponents, values16, parmListLhs[4] );

	char parmListRhs[GEN_OP_BITWISE_COUNT - 1][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numComponents, values7, parmListRhs[0] );
	Gen_GetParmListVector( type, numComponents, values7, parmListRhs[1] );
	Gen_GetParmListVector( type, numComponents, values7, parmListRhs[2] );
	Gen_GetParmListVector( type, numComponents, values2, parmListRhs[3] );
	Gen_GetParmListVector( type, numComponents, values4, parmListRhs[4] );

	char parmListAnswers[GEN_OP_BITWISE_COUNT - 1][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numComponents, answersAnd, parmListAnswers[0] );
	Gen_GetParmListVector( type, numComponents, answersOr, parmListAnswers[1] );
	Gen_GetParmListVector( type, numComponents, answersXor, parmListAnswers[2] );
	Gen_GetParmListVector( type, numComponents, answersShiftLeft, parmListAnswers[3] );
	Gen_GetParmListVector( type, numComponents, answersShiftRight, parmListAnswers[4] );

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

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, 1, numComponents, equalsFuncStr );

	for ( u32 i = 0; i < _countof( ops ); i++ ) {
		genOpBitwise_t op = ops[i];

		char bitwiseFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_GetFuncNameBitwise( language, type, 1, numComponents, op, bitwiseFuncStr );

		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestBitwise_%s_%s", suffices[i], fullTypeName );

		String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  codeTests, "{\n" );
		if ( language == GEN_LANGUAGE_C ) {
			String_Appendf( codeTests, "\t%s answer = (%s) { ", fullTypeName, fullTypeName );
			String_Append( codeTests, parmListAnswers[i] );
			String_Append(  codeTests, " };\n" );
			String_Append(  codeTests, "\n" );

			String_Appendf( codeTests, "\t%s a = (%s) { ", fullTypeName, fullTypeName );
			String_Append( codeTests, parmListLhs[i] );
			String_Append(  codeTests, " };\n" );
			String_Appendf( codeTests, "\t%s b = (%s) { ", fullTypeName, fullTypeName );
			String_Append( codeTests, parmListRhs[i] );
			String_Append(  codeTests, " };\n" );
			String_Append(  codeTests, "\n" );

			String_Appendf( codeTests, "\t%s c = %s( &a, &b );\n", fullTypeName, bitwiseFuncStr );
			String_Append(  codeTests, "\n" );
			String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &c, &answer ) );\n", equalsFuncStr );
		} else {
			String_Appendf( codeTests, "\t%s a  = %s( %s );\n", fullTypeName, fullTypeName, parmListLhs[i] );
			String_Appendf( codeTests, "\t%s b  = %s( %s );\n", fullTypeName, fullTypeName, parmListRhs[i] );
			String_Append(  codeTests, "\n" );
			String_Appendf( codeTests, "\t%s answer = a %s b;\n", fullTypeName, GEN_OPERATORS_BITWISE[op] );
			String_Append(  codeTests, "\n" );
			String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( answer == %s( %s ) );\n", fullTypeName, parmListAnswers[i] );
		}
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  codeTests, "}\n" );
		String_Append(  codeTests, "\n" );

		String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}

	// unary
	{
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestBitwise_Unary_%s", fullTypeName );

		char parmList[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
		Gen_GetParmListVector( type, numComponents, values0, parmList );

		char unaryFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_GetFuncNameBitwise( language, type, 1, numComponents, GEN_OP_BITWISE_UNARY, unaryFuncStr );

		String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  codeTests, "{\n" );
		if ( language == GEN_LANGUAGE_C ) {
			String_Appendf( codeTests, "\t%s answer = (%s) { ", fullTypeName, fullTypeName );
			for ( u32 i = 0; i < numComponents; i++ ) {
				String_Append(  codeTests, parmListAnswerUnary );

				if ( i != numComponents - 1 ) {
					String_Append(  codeTests, ", " );
				}
			}
			
			String_Append(  codeTests, " };\n" );
			String_Append(  codeTests, "\n" );

			String_Appendf( codeTests, "\t%s a = (%s) { ", fullTypeName, fullTypeName );
			String_Append(  codeTests, parmList );
			String_Append(  codeTests, " };\n" );
			String_Append(  codeTests, "\n" );

			String_Appendf( codeTests, "\t%s b = %s( &a );\n", fullTypeName, unaryFuncStr, GEN_OPERATORS_BITWISE[GEN_OP_BITWISE_UNARY] );
			String_Append(  codeTests, "\n" );

			String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &b, &answer ) );\n", equalsFuncStr );
		} else {
			String_Appendf( codeTests, "\t%s a = %s( %s );\n", fullTypeName, fullTypeName, parmList );
			String_Append(  codeTests, "\n" );
			String_Appendf( codeTests, "\t%s answer = %sa;\n", fullTypeName, GEN_OPERATORS_BITWISE[GEN_OP_BITWISE_UNARY] );
			String_Append(  codeTests, "\n" );
			String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( answer == %s( %s ) );\n", fullTypeName, parmListAnswerUnary );
		}
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  codeTests, "}\n" );
		String_Append(  codeTests, "\n" );

		String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

static void GenerateTestLength( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genLanguage_t language, const genType_t type, const u32 numComponents, const char* fullTypeName, const char* memberTypeString, const char* registerName ) {
	assert( codeTests );
	assert( codeSuite );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestLength_Scalar_%s", fullTypeName );

	char twoStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 2, twoStr, 1 );

	// values are strings otherwise compiler truncates floating point bits and screws with the test
	const char* squaredLengths[] = {
		"8.0",
		"12.0",
		"16.0",
	};

	const char* lengths[] = {
		"2.82842712475",
		"3.46410161514",
		"4.0",
	};

	const char* squaredLengthStr	= squaredLengths[numComponents - 2];
	const char* lengthStr			= lengths[numComponents - 2];

	const char* floateqStr = Gen_GetFuncNameFloateq( type );
	const char* fSpecifier = ( type != GEN_TYPE_DOUBLE ) ? "f" : "";

	char lengthsqrFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameLengthsqr( language, type, numComponents, lengthsqrFuncStr );

	char lengthFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameLength( language, type, numComponents, lengthFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s vec = (%s) { ", fullTypeName, fullTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			String_Append( codeTests, twoStr );

			if ( i != numComponents - 1 ) {
				String_Append(  codeTests, ", " );
			}
		}
		String_Appendf( codeTests, " };\n", fullTypeName, fullTypeName, twoStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( %s( &vec ), %s%s ) );\n", floateqStr, lengthsqrFuncStr, squaredLengthStr, fSpecifier );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( %s( &vec ), %s%s ) );\n", floateqStr, lengthFuncStr, lengthStr, fSpecifier );
	} else {
		String_Appendf( codeTests, "\t%s vec = %s( %s );\n", fullTypeName, fullTypeName, twoStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( %s( vec ), %s%s ) );\n", floateqStr, lengthsqrFuncStr, squaredLengthStr, fSpecifier );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( %s( vec ), %s%s ) );\n", floateqStr, lengthFuncStr, lengthStr, fSpecifier );
	}
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );

	if ( Gen_TypeSupportsSSE( type ) ) {
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestLength_SSE_%s", fullTypeName );

		char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( type, 1, numComponents, sseTypeName );

		const char* sseLoadStr = Gen_SSE_GetIntrinsicLoad( type );
		const char* sseStoreStr = Gen_SSE_GetIntrinsicStore( type );

		float values[4][4] = {
			{ 2.0f, 2.0f, 2.0f, 2.0f },	// x
			{ 2.0f, 2.0f, 2.0f, 2.0f },	// y
			{ 2.0f, 2.0f, 2.0f, 2.0f },	// z
			{ 2.0f, 2.0f, 2.0f, 2.0f }	// w
		};

		char lengthsqFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameLengthsq( language, type, numComponents, lengthsqFuncStrSSE );

		char lengthFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameLength( language, type, numComponents, lengthFuncStrSSE );

		String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  codeTests, "{\n" );
		String_Appendf( codeTests, "\t%s components[%d][4] =\n", memberTypeString, numComponents );
		Gen_GetValuesArray2D( type, numComponents, 4, *values, codeTests );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s in;\n", sseTypeName );
		String_Append(  codeTests, "\n" );
		for ( u32 i = 0; i < numComponents; i++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Appendf( codeTests, "\tin.%c = %s( components[%d] );\n", componentStr, sseLoadStr, i );
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s results;\n", registerName );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\t// lengthsq\n" );
		String_Appendf( codeTests, "\t%s( &in, &results );\n", lengthsqFuncStrSSE );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s squaredLengthResults[4];\n", memberTypeString );
		String_Appendf( codeTests, "\t%s( squaredLengthResults, results );\n", sseStoreStr );
		String_Append(  codeTests, "\n" );
		for ( u32 i = 0; i < 4; i++ ) {
			String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( squaredLengthResults[%d], %sf ) );\n", floateqStr, i, squaredLengthStr );
		}
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\t// length\n" );
		String_Appendf( codeTests, "\t%s( &in, &results );\n", lengthFuncStrSSE );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s lengthResults[4];\n", memberTypeString );
		String_Appendf( codeTests, "\t%s( lengthResults, results );\n", sseStoreStr );
		String_Append(  codeTests, "\n" );
		for ( u32 i = 0; i < 4; i++ ) {
			String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( lengthResults[%d], %sf ) );\n", floateqStr, i, lengthStr );
		}
		String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  codeTests, "}\n" );
		String_Append(  codeTests, "\n" );

		String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

static void GenerateTestNormalized( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genLanguage_t language, const genType_t type, const u32 numComponents, const char* fullTypeName, const char* memberTypeString, const char* registerName ) {
	assert( codeTests );
	assert( codeSuite );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestNormalized_Scalar_%s", fullTypeName );

	float values[] = { 5.0f, 4.0f, 3.0f, 2.0f };

	char parmList[GEN_STRING_LENGTH_PARM_LIST_VECTOR] = { 0 };
	Gen_GetParmListVector( type, numComponents, values, parmList );

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( type );

	const char* floateqStr = Gen_GetFuncNameFloateq( floatingPointType );

	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( floatingPointType, 1, oneStr, 1 );

	char normalizedFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameNormalized( language, type, numComponents, normalizedFuncStr );

	char lengthFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameLength( language, type, numComponents, lengthFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s vec = (%s) { %s };\n", fullTypeName, fullTypeName, parmList );
		String_Appendf( codeTests, "\tvec = %s( &vec );\n", normalizedFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s veclen = %s( &vec );\n", memberTypeString, lengthFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( veclen, %s ) );\n", floateqStr, oneStr );
	} else {
		String_Appendf( codeTests, "\t%s vec = %s( %s );\n", fullTypeName, fullTypeName, parmList );
		String_Append(  codeTests, "\tvec = normalized( vec );\n" );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( length( vec ), %s ) );\n", floateqStr, oneStr );
	}
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );

	if ( Gen_TypeSupportsSSE( type ) ) {
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestNormalized_SSE_%s", fullTypeName );

		floateqStr = Gen_GetFuncNameFloateqeps( type );

		const char* set1FuncStr		= Gen_SSE_GetIntrinsicSet1( type );
		const char* storeFuncStr	= Gen_SSE_GetIntrinsicStore( type );

		char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( type, 1, numComponents, sseTypeName );

		char epsilonStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
		Gen_GetNumericLiteral( type, 0.0001f, epsilonStr );

		char normalizeFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameNormalize( language, type, numComponents, normalizeFuncStrSSE );

		char lengthFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameLength( language, type, numComponents, lengthFuncStrSSE );

		String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  codeTests, "{\n" );
		String_Appendf( codeTests, "\t%s results;\n", registerName );
		String_Appendf( codeTests, "\t%s in;\n", sseTypeName );
		String_Appendf( codeTests, "\t%s in_normalised;\n", sseTypeName );
		String_Append(  codeTests, "\n" );
		for ( u32 i = 0; i < numComponents; i++ ) {
			char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
			Gen_GetNumericLiteral( type, values[i], valueStr, 1 );

			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Appendf( codeTests, "\tin.%c = %s( %s );\n", componentStr, set1FuncStr, valueStr );
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s( &in, &in_normalised );\n", normalizeFuncStrSSE );
		String_Appendf( codeTests, "\t%s( &in_normalised, &results );\n", lengthFuncStrSSE );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s normalizeResults[4];\n", memberTypeString );
		String_Appendf( codeTests, "\t%s( normalizeResults, results );\n", storeFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tconst %s epsilon = %s;\n", memberTypeString, epsilonStr );
		for ( u32 i = 0; i < 4; i++ ) {
			String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( normalizeResults[%d], %s, epsilon ) );\n", floateqStr, i, oneStr );
		}
		String_Append(  codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  codeTests, "}\n" );
		String_Append(  codeTests, "\n" );

		String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

static void GenerateTestDot( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genLanguage_t language, const genType_t type, const u32 numComponents, const char* fullTypeName, const char* memberTypeString, const char* registerName ) {
	assert( codeTests );
	assert( codeSuite );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	if ( type == GEN_TYPE_BOOL || type == GEN_TYPE_UINT ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME];
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestDot_Scalar_%s", fullTypeName );

	genType_t dotReturnType = ( type == GEN_TYPE_UINT ) ? GEN_TYPE_INT : type;

	char minusOneStrDotAnswer[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( dotReturnType, -1, minusOneStrDotAnswer, 1 );

	char minusOneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, -1.0f, minusOneStr, 1 );
	Gen_GetNumericLiteral( type,  0.0f, zeroStr, 1 );
	Gen_GetNumericLiteral( type,  1.0f, oneStr, 1 );

	float valuesA[4] = { 0.0f,  1.0f, 0.0f, 0.0f };
	float valuesB[4] = { 0.0f, -1.0f, 0.0f, 0.0f };

	char parmListA[GEN_STRING_LENGTH_PARM_LIST_VECTOR] = { 0 };
	char parmListB[GEN_STRING_LENGTH_PARM_LIST_VECTOR] = { 0 };

	Gen_GetParmListVector( type, numComponents, valuesA, parmListA );
	Gen_GetParmListVector( type, numComponents, valuesB, parmListB );

	const char* floateqStr = Gen_GetFuncNameFloateq( type );

	char dotFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameDot( language, type, numComponents, dotFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s a = (%s) { %s };\n", fullTypeName, fullTypeName, parmListA );
		String_Appendf( codeTests, "\t%s b = (%s) { %s };\n", fullTypeName, fullTypeName, parmListB );
		String_Append(  codeTests, "\n" );
		if ( Gen_TypeIsFloatingPoint( type ) ) {
			String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( %s( &a, &b ), %s ) );\n", floateqStr, dotFuncStr, minusOneStrDotAnswer );
		} else {
			String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &a, &b ) == %s );\n", dotFuncStr, minusOneStrDotAnswer );
		}
	} else {
		String_Appendf( codeTests, "\t%s a = %s( %s );\n", fullTypeName, fullTypeName, parmListA );
		String_Appendf( codeTests, "\t%s b = %s( %s );\n", fullTypeName, fullTypeName, parmListB );
		String_Append(  codeTests, "\n" );
		if ( Gen_TypeIsFloatingPoint( type ) ) {
			String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( %s( a, b ), %s ) );\n", floateqStr, dotFuncStr, minusOneStrDotAnswer );
		} else {
			String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( a, b ) == %s );\n", dotFuncStr, minusOneStrDotAnswer );
		}
	}
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );

	if ( Gen_TypeSupportsSSE( type ) ) {
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestDot_SSE_%s", fullTypeName );

		char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( type, 1, numComponents, sseTypeName );

		const char* sseLoadStr = Gen_SSE_GetIntrinsicLoad( type );
		const char* sseStoreStr = Gen_SSE_GetIntrinsicStore( type );

		float valuesLHS[4][4] = {
			{ 0.0f, 0.0f, 0.0f, 0.0f },	// x
			{ 1.0f, 1.0f, 1.0f, 1.0f },	// y
			{ 0.0f, 0.0f, 0.0f, 0.0f },	// z
			{ 0.0f, 0.0f, 0.0f, 0.0f }	// w
		};

		float valuesRHS[4][4] = {
			{  0.0f,  0.0f,  0.0f,  0.0f },	// x
			{ -1.0f, -1.0f, -1.0f, -1.0f },	// y
			{  0.0f,  0.0f,  0.0f,  0.0f },	// z
			{  0.0f,  0.0f,  0.0f,  0.0f }	// w
		};

		char dotFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameDot( language, type, numComponents, dotFuncStrSSE );

		String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  codeTests, "{\n" );
		String_Appendf( codeTests, "\t%s componentsLHS[%d][4] =\n", memberTypeString, numComponents );
		Gen_GetValuesArray2D( type, numComponents, 4, *valuesLHS, codeTests );
		String_Append(  codeTests, "\n" );

		String_Appendf( codeTests, "\t%s componentsRHS[%d][4] =\n", memberTypeString, numComponents );
		Gen_GetValuesArray2D( type, numComponents, 4, *valuesRHS, codeTests );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s lhs;\n", sseTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Appendf( codeTests, "\tlhs.%c = %s( componentsLHS[%d] );\n", componentStr, sseLoadStr, i );
		}
		String_Append( codeTests, "\n" );
		String_Appendf( codeTests, "\t%s rhs;\n", sseTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Appendf( codeTests, "\trhs.%c = %s( componentsRHS[%d] );\n", componentStr, sseLoadStr, i );
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s results;\n", registerName );
		String_Appendf( codeTests, "\t%s( &lhs, &rhs, &results );\n", dotFuncStrSSE );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s dotResults[4];\n", memberTypeString );
		String_Appendf( codeTests, "\t%s( dotResults, results );\n", sseStoreStr );
		String_Append(  codeTests, "\n" );
		for ( u32 i = 0; i < 4; i++ ) {
			if ( Gen_TypeIsFloatingPoint( type ) ) {
				String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( dotResults[%d], %s ) );\n", floateqStr, i, minusOneStr );
			} else {
				String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( dotResults[%d] == %s );\n", i, minusOneStr );
			}
		}
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  codeTests, "}\n" );
		String_Append(  codeTests, "\n" );

		String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

static void GenerateTestCross( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genLanguage_t language, const genType_t type, const u32 numComponents, const char* fullTypeName, const char* memberTypeString ) {
	assert( codeTests );
	assert( codeSuite );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestCross_Scalar_%s", fullTypeName );

	if ( numComponents < 3 ) {
		return;
	}

	float left[]	= { -1.0f, 0.0f, 0.0f, 0.0f };
	float up[]		= {  0.0f, 1.0f, 0.0f, 0.0f };
	float forward[]	= {  0.0f, 0.0f, 1.0f, 0.0f };

	char parmListLeft[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numComponents, left, parmListLeft );

	char parmListUp[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numComponents, up, parmListUp );

	char parmListForward[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numComponents, forward, parmListForward );

	char crossFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameCross( language, type, numComponents, crossFuncStr );

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, 1, numComponents, equalsFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s left    = (%s) { %s };\n", fullTypeName, fullTypeName, parmListLeft );
		String_Appendf( codeTests, "\t%s forward = (%s) { %s };\n", fullTypeName, fullTypeName, parmListForward );
		String_Appendf( codeTests, "\t%s up      = (%s) { %s };\n", fullTypeName, fullTypeName, parmListUp );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s vecCross = %s( &left, &forward );\n", fullTypeName, crossFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &vecCross, &up ) );\n", equalsFuncStr );
	} else {
		String_Appendf( codeTests, "\t%s left    = %s( %s );\n", fullTypeName, fullTypeName, parmListLeft );
		String_Appendf( codeTests, "\t%s forward = %s( %s );\n", fullTypeName, fullTypeName, parmListForward );
		String_Appendf( codeTests, "\t%s up      = %s( %s );\n", fullTypeName, fullTypeName, parmListUp );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( cross( left, forward ) == up );\n" );
	}
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );

	if ( Gen_TypeSupportsSSE( type ) ) {
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestCross_SSE_%s", fullTypeName );

		char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( type, 1, numComponents, sseTypeName );

		const char* floateqStr = Gen_GetFuncNameFloateq( type );

		const char* loadFuncStr		= Gen_SSE_GetIntrinsicLoad( type );
		const char* storeFuncStr	= Gen_SSE_GetIntrinsicStore( type );

		char crossFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameCross( language, type, numComponents, crossFuncStrSSE );

		String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  codeTests, "{\n" );
		String_Appendf( codeTests, "\t%s componentsLeft[%d][4] =\n", memberTypeString, numComponents );
		String_Append(  codeTests, "\t{\n" );
		for ( u32 componentIndex = 0; componentIndex < numComponents; componentIndex++ ) {
			float value = left[componentIndex];
			float values[4] = { value, value, value, value };

			String_Append( codeTests, "\t" );
			Gen_GetValuesArray1D( type, 4, values, codeTests );

			if ( componentIndex != numComponents - 1 ) {
				String_Append( codeTests, "," );
			}

			String_Appendf( codeTests, "\t// 4 %c components\n", GEN_COMPONENT_NAMES_VECTOR[componentIndex] );
		}
		String_Append(  codeTests, "\t};\n" );
		String_Append(  codeTests, "\n" );

		String_Appendf( codeTests, "\t%s componentsForward[%d][4] =\n", memberTypeString, numComponents );
		String_Append(  codeTests, "\t{\n" );
		for ( u32 componentIndex = 0; componentIndex < numComponents; componentIndex++ ) {
			float value = forward[componentIndex];
			float values[4] = { value, value, value, value };

			String_Append( codeTests, "\t" );
			Gen_GetValuesArray1D( type, 4, values, codeTests );

			if ( componentIndex != numComponents - 1 ) {
				String_Append( codeTests, "," );
			}

			String_Appendf( codeTests, "\t// 4 %c components\n", GEN_COMPONENT_NAMES_VECTOR[componentIndex] );
		}
		String_Append(  codeTests, "\t};\n" );
		String_Append(  codeTests, "\n" );
		
		String_Appendf( codeTests, "\t%s left;\n", sseTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Appendf( codeTests, "\tleft.%c = %s( componentsLeft[%d] );\n", componentStr, loadFuncStr, i );
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s forward;\n", sseTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Appendf( codeTests, "\tforward.%c = %s( componentsForward[%d] );\n", componentStr, loadFuncStr, i );
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s up;\n", sseTypeName );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s( &left, &forward, &up );\n", crossFuncStrSSE );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s crossResults[4];\n", memberTypeString );
		for ( u32 componentIndex = 0; componentIndex < numComponents; componentIndex++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[componentIndex];

			String_Appendf( codeTests, "\t%s( crossResults, up.%c );\n", storeFuncStr, componentStr );

			for ( u32 i = 0; i < 4; i++ ) {
				char valueStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
				Gen_GetNumericLiteral( type, up[componentIndex], valueStr );

				if ( Gen_TypeIsFloatingPoint( type ) ) {
					String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( crossResults[%d], %s ) );\n", floateqStr, i, valueStr );
				} else {
					String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( crossResults[%d] == %s );\n", i, valueStr );
				}
			}

			String_Append(  codeTests, "\n" );
		}
		String_Append(  codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  codeTests, "}\n" );
		String_Append(  codeTests, "\n" );

		String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

static void GenerateTestAngle( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genLanguage_t language, const genType_t type, const u32 numComponents, const char* fullTypeName, const char* memberTypeString ) {
	assert( codeTests );
	assert( codeSuite );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );
	assert( memberTypeString );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestAngle_Scalar_%s", fullTypeName );

	float right[]	= { 1.0f, 0.0f, 0.0f, 0.0f };
	float up[]		= { 0.0f, 1.0f, 0.0f, 0.0f };

	char parmListRight[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numComponents, right, parmListRight );

	char parmListUp[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numComponents, up, parmListUp );

	const genType_t floatingPointType = Gen_GetSupportedFloatingPointType( type );

	char ninetyStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( floatingPointType, 90.0f, ninetyStr, 1 );

	const char* floateqStr = Gen_GetFuncNameFloateq( type );

	char angleFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameAngle( language, type, numComponents, angleFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s right = (%s) { %s };\n", fullTypeName, fullTypeName, parmListRight );
		String_Appendf( codeTests, "\t%s up    = (%s) { %s };\n", fullTypeName, fullTypeName, parmListUp );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "%s angleDeg = %s( &up, &right );\n", memberTypeString, angleFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( angleDeg, %s ) );\n", floateqStr, ninetyStr );
	} else {
		String_Appendf( codeTests, "\t%s right = %s( %s );\n", fullTypeName, fullTypeName, parmListRight );
		String_Appendf( codeTests, "\t%s up    = %s( %s );\n", fullTypeName, fullTypeName, parmListUp );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( angle( up, right ), %s ) );\n", floateqStr, ninetyStr );
	}
	String_Append( codeTests, "\n" );
	String_Append( codeTests, "\tTEMPER_PASS();\n" );
	String_Append( codeTests, "}\n" );
	String_Append( codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestDistance( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genLanguage_t language, const genType_t type, const u32 numComponents, const char* fullTypeName, const char* memberTypeString, const char* registerName ) {
	assert( codeTests );
	assert( codeSuite );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( numComponents > 3 ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestDistance_Scalar_%s", fullTypeName );

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( type );
	const char* floatingPointStr = Gen_GetTypeString( floatingPointType );

	// numbers picked at random
	// default w to 0 because distance isn't allowed for 4d vectors
	float values0[] = { 7.0f,  4.0f, 3.0f, 0.0f };
	float values1[] = { 17.0f, 6.0f, 2.0f, 0.0f };

	char answerDistanceSqrStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char answerDistanceStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	switch ( numComponents ) {
		case 2:
			Gen_GetNumericLiteral( floatingPointType, 104.0f, answerDistanceSqrStr, 1 );
			Gen_GetNumericLiteral( floatingPointType, 10.198039f, answerDistanceStr );
			break;

		case 3:
			Gen_GetNumericLiteral( floatingPointType, 105.0f, answerDistanceSqrStr, 1 );
			Gen_GetNumericLiteral( floatingPointType, 10.246951f, answerDistanceStr );
			break;
	}

	char parmList0[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	char parmList1[GEN_STRING_LENGTH_PARM_LIST_VECTOR];

	Gen_GetParmListVector( type, numComponents, values0, parmList0 );
	Gen_GetParmListVector( type, numComponents, values1, parmList1 );

	const char* floateqStr = Gen_GetFuncNameFloateq( type );

	char distancesqrFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameDistancesqr( language, type, numComponents, distancesqrFuncStr );

	char distanceFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameDistance( language, type, numComponents, distanceFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s answerDistanceSqr = %s;\n", floatingPointStr, answerDistanceSqrStr );
	String_Appendf( codeTests, "\t%s answerDistance    = %s;\n", floatingPointStr, answerDistanceStr );
	String_Append(  codeTests, "\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s a = (%s) { %s };\n", fullTypeName, fullTypeName, parmList0 );
		String_Appendf( codeTests, "\t%s b = (%s) { %s };\n", fullTypeName, fullTypeName, parmList1 );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s distSqr = %s( &a, &b );\n", floatingPointStr, distancesqrFuncStr );
		String_Appendf( codeTests, "\t%s dist    = %s( &a, &b );\n", floatingPointStr, distanceFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( distSqr, answerDistanceSqr ) );\n", floateqStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( dist, answerDistance ) );\n", floateqStr );
	} else {
		String_Appendf( codeTests, "\t%s a = %s( %s );\n", fullTypeName, fullTypeName, parmList0 );
		String_Appendf( codeTests, "\t%s b = %s( %s );\n", fullTypeName, fullTypeName, parmList1 );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s distSqr = %s( a, b );\n", floatingPointStr, distancesqrFuncStr );
		String_Appendf( codeTests, "\t%s dist    = %s( a, b );\n", floatingPointStr, distanceFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( distSqr, answerDistanceSqr ) );\n", floateqStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( dist, answerDistance ) );\n", floateqStr );
	}
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );

	if ( Gen_TypeSupportsSSE( type ) ) {
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestDistance_SSE_%s", fullTypeName );

		char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( type, 1, numComponents, sseTypeName );

		const char* sseLoadStr = Gen_SSE_GetIntrinsicLoad( type );
		const char* sseStoreStr = Gen_SSE_GetIntrinsicStore( type );

		float valuesLHS[4][4] = {
			{ 7.0f, 7.0f, 7.0f, 7.0f },	// x
			{ 4.0f, 4.0f, 4.0f, 4.0f },	// y
			{ 3.0f, 3.0f, 3.0f, 3.0f },	// z
			{ 0.0f, 0.0f, 0.0f, 0.0f },	// w
		};

		float valuesRHS[4][4] = {
			{ 17.0f, 17.0f, 17.0f, 17.0f },	// x
			{ 6.0f,  6.0f,  6.0f,  6.0f  },	// y
			{ 2.0f,  2.0f,  2.0f,  2.0f  },	// z
			{ 0.0f,  0.0f,  0.0f,  0.0f  },	// w
		};

		char distancesqFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameDistancesq( language, type, numComponents, distancesqFuncStrSSE );

		char distanceFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameDistance( language, type, numComponents, distanceFuncStrSSE );

		String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  codeTests, "{\n" );
		String_Appendf( codeTests, "\t%s componentsLHS[%d][4] =\n", memberTypeString, numComponents );
		Gen_GetValuesArray2D( type, numComponents, 4, *valuesLHS, codeTests );
		String_Append(  codeTests, "\n" );

		String_Appendf( codeTests, "\t%s componentsRHS[%d][4] =\n", memberTypeString, numComponents );
		Gen_GetValuesArray2D( type, numComponents, 4, *valuesRHS, codeTests );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s lhs;\n", sseTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Appendf( codeTests, "\tlhs.%c = %s( componentsLHS[%d] );\n", componentStr, sseLoadStr, i );
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s rhs;\n", sseTypeName );
		for ( u32 i = 0; i < numComponents; i++ ) {
			const char componentStr = GEN_COMPONENT_NAMES_VECTOR[i];

			String_Appendf( codeTests, "\trhs.%c = %s( componentsRHS[%d] );\n", componentStr, sseLoadStr, i );
		}
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s results;\n", registerName );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\t// distancesq\n" );
		String_Appendf( codeTests, "\t%s( &lhs, &rhs, &results );\n", distancesqFuncStrSSE );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s squaredDistanceResults[4];\n", memberTypeString );
		String_Appendf( codeTests, "\t%s( squaredDistanceResults, results );\n", sseStoreStr );
		String_Append(  codeTests, "\n" );
		for ( u32 i = 0; i < 4; i++ ) {
			String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( squaredDistanceResults[%d], %s ) );\n", floateqStr, i, answerDistanceSqrStr );
		}
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\t// distance\n" );
		String_Appendf( codeTests, "\t%s( &lhs, &rhs, &results );\n", distanceFuncStrSSE );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s distanceResults[4];\n", memberTypeString );
		String_Appendf( codeTests, "\t%s( distanceResults, results );\n", sseStoreStr );
		String_Append(  codeTests, "\n" );
		for ( u32 i = 0; i < 4; i++ ) {
			String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( distanceResults[%d], %s ) );\n", floateqStr, i, answerDistanceStr );
		}
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  codeTests, "}\n" );
		String_Append(  codeTests, "\n" );

		String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

static void GenerateTestPacking( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genLanguage_t language, const genType_t type, const u32 numComponents, const char* fullTypeName, const char* memberTypeString ) {
	assert( codeTests );
	assert( codeSuite );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	if ( type != GEN_TYPE_UINT ) {
		return;
	}

	if ( numComponents != 4 ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestPacking_%s", fullTypeName );

	float values[] = { 255, 255, 0, 255 };	// magenta

	char parmListAnswerUnpacked[64] = { 0 };
	Gen_GetParmListVector( type, numComponents, values, parmListAnswerUnpacked );

	const char* answerPackedStr = "0xFFFF00FF";

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, 1, numComponents, equalsFuncStr );

	// tests pack and unpack
	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s answerPacked = %s;\n", memberTypeString, answerPackedStr );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s vec = (%s) { %s };\n", fullTypeName, fullTypeName, parmListAnswerUnpacked );
		String_Appendf( codeTests, "\t%s packed = pack( &vec );\n", memberTypeString );
	} else {
		String_Appendf( codeTests, "\t%s vec = %s( %s );\n", fullTypeName, fullTypeName, parmListAnswerUnpacked );
		String_Appendf( codeTests, "\t%s packed = pack( vec );\n", memberTypeString );
	}
	String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( packed == answerPacked );\n" );
	String_Append(  codeTests, "\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s answerUnpacked = (%s) { %s };\n", fullTypeName, fullTypeName, parmListAnswerUnpacked );
		String_Appendf( codeTests, "\t%s unpacked = unpack( packed );\n", fullTypeName );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &unpacked, &answerUnpacked ) );\n", equalsFuncStr );
	} else {
		String_Appendf( codeTests, "\t%s answerUnpacked = %s( %s );\n", fullTypeName, fullTypeName, parmListAnswerUnpacked );
		String_Appendf( codeTests, "\t%s unpacked = unpack( packed );\n", fullTypeName );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( unpacked == answerUnpacked );\n" );
	}
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestSaturate( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genLanguage_t language, const genType_t type, const u32 numComponents, const char* fullTypeName ) {
	assert( codeTests );
	assert( codeSuite );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestSaturate_%s", fullTypeName );

	float values[]			= { -1.0f, 2.0f, 4.0f, 6.0f };
	float valuesAnswer[]	= {  0.0f, 1.0f, 1.0f, 1.0f };

	char parmList[GEN_STRING_LENGTH_PARM_LIST_VECTOR]		= { 0 };
	char parmListAnswer[GEN_STRING_LENGTH_PARM_LIST_VECTOR]	= { 0 };

	Gen_GetParmListVector( type, numComponents, values, parmList );
	Gen_GetParmListVector( type, numComponents, valuesAnswer, parmListAnswer );

	char saturateFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameSaturate( language, type, numComponents, saturateFuncStr );

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, 1, numComponents, equalsFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s answer = (%s) { %s };\n", fullTypeName, fullTypeName, parmListAnswer );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s vec = (%s) { %s };\n", fullTypeName, fullTypeName, parmList );
		String_Appendf( codeTests, "\t%s clamped = %s( &vec );\n", fullTypeName, saturateFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &clamped, &answer ) );\n", equalsFuncStr );
	} else {
		String_Appendf( codeTests, "\t%s answer = %s( %s );\n", fullTypeName, fullTypeName, parmListAnswer );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s vec = %s( %s );\n", fullTypeName, fullTypeName, parmList );
		String_Appendf( codeTests, "\t%s clamped = %s( vec );\n", fullTypeName, saturateFuncStr );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( clamped == answer );\n" );
	}
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestLerp( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genLanguage_t language, const genType_t type, const u32 numComponents, const char* fullTypeName ) {
	assert( codeTests );
	assert( codeSuite );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestLerp_%s", fullTypeName );

	float valuesA[]			= { 0.0f, 1.0f, 0.0f, 0.0f };
	float valuesB[]			= { 1.0f, 0.0f, 0.0f, 0.0f };
	float valuesAnswer[]	= { 0.5f, 0.5f, 0.0f, 0.0f };

	char parmListA[GEN_STRING_LENGTH_PARM_LIST_VECTOR]		= { 0 };
	char parmListB[GEN_STRING_LENGTH_PARM_LIST_VECTOR]		= { 0 };
	char parmListAnswer[GEN_STRING_LENGTH_PARM_LIST_VECTOR]	= { 0 };

	Gen_GetParmListVector( type, numComponents, valuesA, parmListA );
	Gen_GetParmListVector( type, numComponents, valuesB, parmListB );
	Gen_GetParmListVector( type, numComponents, valuesAnswer, parmListAnswer );

	char lerpValStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 0.5f, lerpValStr, 1 );

	char lerpFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameLerp( language, type, numComponents, lerpFuncStr );

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, 1, numComponents, equalsFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s answer = (%s) { %s };\n", fullTypeName, fullTypeName, parmListAnswer );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s a = (%s) { %s };\n", fullTypeName, fullTypeName, parmListA );
		String_Appendf( codeTests, "\t%s b = (%s) { %s };\n", fullTypeName, fullTypeName, parmListB );
		String_Appendf( codeTests, "\t%s lerped = %s( &a, &b, %s );\n", fullTypeName, lerpFuncStr, lerpValStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &lerped, &answer ) );\n", equalsFuncStr );
	} else {
		String_Appendf( codeTests, "\t%s answer = %s( %s );\n", fullTypeName, fullTypeName, parmListAnswer );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s a = %s( %s );\n", fullTypeName, fullTypeName, parmListA );
		String_Appendf( codeTests, "\t%s b = %s( %s );\n", fullTypeName, fullTypeName, parmListB );
		String_Appendf( codeTests, "\t%s lerped = %s( a, b, %s );\n", fullTypeName, lerpFuncStr, lerpValStr );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( lerped == answer );\n" );
	}
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestStep( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genLanguage_t language, const genType_t type, const u32 numComponents, const char* fullTypeName ) {
	assert( codeTests );
	assert( codeSuite );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestStep_%s", fullTypeName );

	// numbers chosen at random
	float valuesA[]			= { 1.0f, 2.0f, 3.0f, 4.0f };
	float valuesB[]			= { 4.0f, 3.0f, 2.0f, 1.0f };
	float valuesAnswer[]	= { 1.0f, 1.0f, 0.0f, 0.0f };

	char parmListA[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	char parmListB[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	char parmListAnswer[GEN_STRING_LENGTH_PARM_LIST_VECTOR];

	Gen_GetParmListVector( type, numComponents, valuesA, parmListA );
	Gen_GetParmListVector( type, numComponents, valuesB, parmListB );
	Gen_GetParmListVector( type, numComponents, valuesAnswer, parmListAnswer );

	char stepFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameStep( language, type, numComponents, stepFuncStr );

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, 1, numComponents, equalsFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s answer = (%s) { %s };\n", fullTypeName, fullTypeName, parmListAnswer );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s a = (%s) { %s };\n", fullTypeName, fullTypeName, parmListA );
		String_Appendf( codeTests, "\t%s b = (%s) { %s };\n", fullTypeName, fullTypeName, parmListB );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s answerStep = %s( &a, &b );\n", fullTypeName, stepFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &answerStep, &answer ) );\n", equalsFuncStr );
	} else {
		String_Appendf( codeTests, "\t%s answer = %s( %s );\n", fullTypeName, fullTypeName, parmListAnswer );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s a = %s( %s );\n", fullTypeName, fullTypeName, parmListA );
		String_Appendf( codeTests, "\t%s b = %s( %s );\n", fullTypeName, fullTypeName, parmListB );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( a, b ) == answer );\n", stepFuncStr );
	}
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestSmoothstep( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genLanguage_t language, const genType_t type, const u32 numComponents, const char* fullTypeName ) {
	assert( codeTests );
	assert( codeSuite );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( fullTypeName );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME];
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestSmoothstep_%s", fullTypeName );

	float valuesLow[]						= { 0.0f, 0.0f, 0.0f, 0.0f };
	float valuesHigh[]						= { 1.0f, 1.0f, 1.0f, 1.0f };

	float valuesInput0[]					= { 0.2f, 0.2f, 0.2f, 0.2f };
	float valuesInput1[]					= { 1.2f, 1.2f, 1.2f, 1.2f };

	float valuesAnswerInRangeSmoothstep[]	= { 0.104f, 0.104f, 0.104f, 0.104f };
	float valuesAnswerClampedSmoothstep[]	= { 1.0f,   1.0f,   1.0f,   1.0f   };

	float valuesAnswerInRangeSmootherstep[]	= { 0.057920f, 0.057920f, 0.057920f, 0.057920f };
	float valuesAnswerClampedSmootherstep[]	= { 1.0f,      1.0f,      1.0f,      1.0f      };

	char parmListLow[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numComponents, valuesLow, parmListLow );

	char parmListHigh[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numComponents, valuesHigh, parmListHigh );

	char parmListInput0[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numComponents, valuesInput0, parmListInput0 );

	char parmListInput1[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numComponents, valuesInput1, parmListInput1 );

	char parmListAnswerInRangeSmoothstep[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numComponents, valuesAnswerInRangeSmoothstep, parmListAnswerInRangeSmoothstep );

	char parmListAnswerClampedSmoothstep[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numComponents, valuesAnswerClampedSmoothstep, parmListAnswerClampedSmoothstep );

	char parmListAnswerInRangeSmootherstep[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numComponents, valuesAnswerInRangeSmootherstep, parmListAnswerInRangeSmootherstep );

	char parmListAnswerClampedSmootherstep[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	Gen_GetParmListVector( type, numComponents, valuesAnswerClampedSmootherstep, parmListAnswerClampedSmootherstep );

	char smoothstepFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameSmoothstep( language, type, numComponents, smoothstepFuncStr );

	char smootherstepFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameSmootherstep( language, type, numComponents, smootherstepFuncStr );

	char equalsFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameEquals( language, type, 1, numComponents, equalsFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	if ( language == GEN_LANGUAGE_C ) {
		String_Appendf( codeTests, "\t%s answerInRangeSmoothstep   = (%s) { %s };\n", fullTypeName, fullTypeName, parmListAnswerInRangeSmoothstep );
		String_Appendf( codeTests, "\t%s answerClampedSmoothstep   = (%s) { %s };\n", fullTypeName, fullTypeName, parmListAnswerClampedSmoothstep );
		String_Appendf( codeTests, "\t%s answerInRangeSmootherstep = (%s) { %s };\n", fullTypeName, fullTypeName, parmListAnswerInRangeSmootherstep );
		String_Appendf( codeTests, "\t%s answerClampedSmootherstep = (%s) { %s };\n", fullTypeName, fullTypeName, parmListAnswerClampedSmootherstep );
		String_Appendf( codeTests, "\t%s answer;\n", fullTypeName );
		String_Appendf( codeTests, "\t%s vec;\n", fullTypeName );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s low  = (%s) { %s };\n", fullTypeName, fullTypeName, parmListLow );
		String_Appendf( codeTests, "\t%s high = (%s) { %s };\n", fullTypeName, fullTypeName, parmListHigh );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tvec = (%s) { %s };\n", fullTypeName, parmListInput0 );
		String_Appendf( codeTests, "\tanswer = %s( &low, &high, &vec );\n", smoothstepFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &answer, &answerInRangeSmoothstep ) );\n", equalsFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tvec = (%s) { %s };\n", fullTypeName, parmListInput1 );
		String_Appendf( codeTests, "\tanswer = %s( &low, &high, &vec );\n", smoothstepFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &answer, &answerClampedSmoothstep ) );\n", equalsFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tvec = (%s) { %s };\n", fullTypeName, parmListInput0 );
		String_Appendf( codeTests, "\tanswer = %s( &low, &high, &vec );\n", smootherstepFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &answer, &answerInRangeSmootherstep ) );\n", equalsFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tvec = (%s) { %s };\n", fullTypeName, parmListInput1 );
		String_Appendf( codeTests, "\tanswer = %s( &low, &high, &vec );\n", smootherstepFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( &answer, &answerClampedSmootherstep ) );\n", equalsFuncStr );
	} else {
		String_Appendf( codeTests, "\t%s answerInRangeSmoothstep   = %s( %s );\n", fullTypeName, fullTypeName, parmListAnswerInRangeSmoothstep );
		String_Appendf( codeTests, "\t%s answerClampedSmoothstep   = %s( %s );\n", fullTypeName, fullTypeName, parmListAnswerClampedSmoothstep );
		String_Appendf( codeTests, "\t%s answerInRangeSmootherstep = %s( %s );\n", fullTypeName, fullTypeName, parmListAnswerInRangeSmootherstep );
		String_Appendf( codeTests, "\t%s answerClampedSmootherstep = %s( %s );\n", fullTypeName, fullTypeName, parmListAnswerClampedSmootherstep );
		String_Appendf( codeTests, "\t%s answer;\n", fullTypeName );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s low  = %s( %s );\n", fullTypeName, fullTypeName, parmListLow );
		String_Appendf( codeTests, "\t%s high = %s( %s );\n", fullTypeName, fullTypeName, parmListHigh );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tanswer = %s( low, high, %s( %s ) );\n", smoothstepFuncStr, fullTypeName, parmListInput0 );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( answer == answerInRangeSmoothstep );\n" );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tanswer = %s( low, high, %s( %s ) );\n", smoothstepFuncStr, fullTypeName, parmListInput1 );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( answer == answerClampedSmoothstep );\n" );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tanswer = %s( low, high, %s( %s ) );\n", smootherstepFuncStr, fullTypeName, parmListInput0 );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( answer == answerInRangeSmootherstep );\n" );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tanswer = %s( low, high, %s( %s ) );\n", smootherstepFuncStr, fullTypeName, parmListInput1 );
		String_Append(  codeTests, "\tTEMPER_EXPECT_TRUE( answer == answerClampedSmootherstep );\n" );
	}
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void Gen_VectorTests( const genLanguage_t language, const genType_t type, const u32 numComponents ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );

	const u32 testsCodeBytes = 16 * KB_TO_BYTES;
	const u32 suiteCodeBytes = 2 * KB_TO_BYTES;

	stringBuilder_t codeTests = String_Create( testsCodeBytes );
	stringBuilder_t codeSuite = String_Create( suiteCodeBytes );

	const char* typeString = Gen_GetTypeString( type );
	const char* memberTypeString = Gen_GetMemberTypeString( type );
	const char* registerName = NULL;
	if ( Gen_TypeSupportsSSE( type ) ) {
		registerName = Gen_SSE_GetRegisterName( type );
	}

	char fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, numComponents );

	stringBuilder_t code = String_Create( testsCodeBytes + suiteCodeBytes );

	String_Appendf( &code, GEN_FILE_HEADER );

	String_Appendf( &codeSuite, "TEMPER_SUITE( Test_%s )\n", fullTypeName );
	String_Append(  &codeSuite, "{\n" );

	GenerateTestAssignment( &codeTests, &codeSuite, type, numComponents, fullTypeName );

	if ( language == GEN_LANGUAGE_CPP ) {
		GenerateTestConstruct( &codeTests, &codeSuite, type, numComponents, fullTypeName );

		GenerateTestArray( &codeTests, &codeSuite, type, numComponents, fullTypeName );

		GenerateTestIncrement( &codeTests, &codeSuite, type, numComponents, fullTypeName );
	}

	GenerateTestArithmetic( &codeTests, &codeSuite, language, type, numComponents, fullTypeName );

	GenerateTestRelational( &codeTests, &codeSuite, language, type, numComponents, fullTypeName );

	GenerateTestBitwise( &codeTests, &codeSuite, language, type, numComponents, fullTypeName, memberTypeString );

	GenerateTestLength( &codeTests, &codeSuite, language, type, numComponents, fullTypeName, memberTypeString, registerName );

	GenerateTestNormalized( &codeTests, &codeSuite, language, type, numComponents, fullTypeName, memberTypeString, registerName );

	GenerateTestDot( &codeTests, &codeSuite, language, type, numComponents, fullTypeName, memberTypeString, registerName );

	GenerateTestCross( &codeTests, &codeSuite, language, type, numComponents, fullTypeName, memberTypeString );

	GenerateTestAngle( &codeTests, &codeSuite, language, type, numComponents, fullTypeName, memberTypeString );

	GenerateTestDistance( &codeTests, &codeSuite, language, type, numComponents, fullTypeName, memberTypeString, registerName );

	GenerateTestSaturate( &codeTests, &codeSuite, language, type, numComponents, fullTypeName );

	GenerateTestLerp( &codeTests, &codeSuite, language, type, numComponents, fullTypeName );

	GenerateTestStep( &codeTests, &codeSuite, language, type, numComponents, fullTypeName );

	GenerateTestSmoothstep( &codeTests, &codeSuite, language, type, numComponents, fullTypeName );

	GenerateTestPacking( &codeTests, &codeSuite, language, type, numComponents, fullTypeName, memberTypeString );

	String_Append( &codeSuite, "}\n" );

	String_Append( &code, codeTests.str );
	String_Append( &code, codeSuite.str );

	char filename[1024] = { 0 };
	snprintf( filename, 1024, "%stest_%s.%s", GEN_FOLDER_PATHS_TESTS[language], fullTypeName, GEN_SOURCE_FILE_EXTENSIONS[language] );

	FS_WriteEntireFile( filename, code.str, code.length );

	Mem_Reset();
}
