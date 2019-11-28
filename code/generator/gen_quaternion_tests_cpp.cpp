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
#include "gen_quaternion_tests_cpp.h"
#include "defines.h"
#include "file_io.h"

#include "gen_funcs_vector.h"

#include "string_builder.h"
#include "allocator.h"

static void GenerateTestMultiplyScalar(  stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genType_t type, const char* fullTypeName, const char* baseTypeString ) {
	// number picked at random
	char scalar[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 6, scalar, 1 );

	char twoStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char threeStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char fourStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char fiveStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char twelveStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char eighteenStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char twentyFourStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char thirtyStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, 2, twoStr, 1 );
	Gen_GetNumericLiteral( type, 3, threeStr, 1 );
	Gen_GetNumericLiteral( type, 4, fourStr, 1 );
	Gen_GetNumericLiteral( type, 5, fiveStr, 1 );
	Gen_GetNumericLiteral( type, 12, twelveStr, 1 );
	Gen_GetNumericLiteral( type, 18, eighteenStr, 1 );
	Gen_GetNumericLiteral( type, 24, twentyFourStr, 1 );
	Gen_GetNumericLiteral( type, 30, thirtyStr, 1 );
	
	char parmListValues[4][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf( parmListValues[0], 64, "( %s )", twoStr );
	snprintf( parmListValues[1], 64, "( %s )", threeStr );
	snprintf( parmListValues[2], 64, "( %s )", fourStr );
	snprintf( parmListValues[3], 64, "( %s )", fiveStr );

	char parmListAnswers[4][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf( parmListAnswers[0], 64, "( %s )", twelveStr );
	snprintf( parmListAnswers[1], 64, "( %s )", eighteenStr );
	snprintf( parmListAnswers[2], 64, "( %s )", twentyFourStr );
	snprintf( parmListAnswers[3], 64, "( %s )", thirtyStr );

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestArithmetic%s_%s", "MultiplyScalar", fullTypeName );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append( codeTests, "{\n" );
	String_Appendf( codeTests, "\tconst %s a = %s( %s, %s, %s, %s );\n", fullTypeName, fullTypeName, parmListValues[0], parmListValues[1], parmListValues[2], parmListValues[3] );
	String_Appendf( codeTests, "\tconst %s b = %s;\n", baseTypeString, scalar );
	String_Append( codeTests, "\n" );
	String_Appendf( codeTests, "\t%s c = quaternion_mul(a, b);\n", fullTypeName );
	String_Append( codeTests, "\n" );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( c == %s( %s, %s, %s, %s ) );\n", fullTypeName, parmListAnswers[0], parmListAnswers[1], parmListAnswers[2], parmListAnswers[3] );
	String_Append( codeTests, "\n" );
	String_Append( codeTests, "\tTEMPER_PASS();\n" );
	String_Append( codeTests, "}\n" );
	String_Append( codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestMultiplyQuaternion(  stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genType_t type, const char* fullTypeName ) {
	// number picked at random
	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char twoStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char threeStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char fourStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char fiveStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char sevenStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char twentyTwoStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char thirtyStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char fiftySixStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, 1, oneStr, 1 );
	Gen_GetNumericLiteral( type, 2, twoStr, 1 );
	Gen_GetNumericLiteral( type, 3, threeStr, 1 );
	Gen_GetNumericLiteral( type, 4, fourStr, 1 );
	Gen_GetNumericLiteral( type, 5, fiveStr, 1 );
	Gen_GetNumericLiteral( type, 7, sevenStr, 1 );
	Gen_GetNumericLiteral( type, 22, twentyTwoStr, 1 );
	Gen_GetNumericLiteral( type, 30, thirtyStr, 1 );
	Gen_GetNumericLiteral( type, 56, fiftySixStr, 1 );

	char parmListRhsValues[4][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf( parmListRhsValues[0], 64, "( %s )", twoStr );
	snprintf( parmListRhsValues[1], 64, "( %s )", threeStr );
	snprintf( parmListRhsValues[2], 64, "( %s )", fourStr );
	snprintf( parmListRhsValues[3], 64, "( %s )", fiveStr );

	char parmListLhsValues[4][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf( parmListLhsValues[0], 64, "( %s )", oneStr );
	snprintf( parmListLhsValues[1], 64, "( %s )", threeStr );
	snprintf( parmListLhsValues[2], 64, "( %s )", fiveStr );
	snprintf( parmListLhsValues[3], 64, "( %s )", sevenStr );

	char parmListAnswers[4][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf( parmListAnswers[0], 64, "( %s )", twentyTwoStr );
	snprintf( parmListAnswers[1], 64, "( %s )", thirtyStr );
	snprintf( parmListAnswers[2], 64, "( %s )", fiftySixStr );
	snprintf( parmListAnswers[3], 64, "( %s )", fourStr );

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestArithmetic%s_%s", "Multiply", fullTypeName );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append( codeTests, "{\n" );
	String_Appendf( codeTests, "\tconst %s a = %s( %s, %s, %s, %s );\n", fullTypeName, fullTypeName, parmListRhsValues[0], parmListRhsValues[1], parmListRhsValues[2], parmListRhsValues[3] );
	String_Appendf( codeTests, "\tconst %s b = %s( %s, %s, %s, %s );\n", fullTypeName, fullTypeName, parmListLhsValues[0], parmListLhsValues[1], parmListLhsValues[2], parmListLhsValues[3] );
	String_Append( codeTests, "\n" );
	String_Appendf( codeTests, "\t%s c = quaternion_mul( a, b );\n", fullTypeName );
	String_Append( codeTests, "\n" );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( c == %s( %s, %s, %s, %s ) );\n", fullTypeName, parmListAnswers[0], parmListAnswers[1], parmListAnswers[2], parmListAnswers[3] );
	String_Append( codeTests, "\n" );
	String_Append( codeTests, "\tTEMPER_PASS();\n" );
	String_Append( codeTests, "}\n" );
	String_Append( codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestLength(  stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genType_t type, const char* fullTypeName, const char* baseTypeString ) {
	char twoStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char threeStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char fourStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char fiveStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char answerStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, 2, twoStr, 1 );
	Gen_GetNumericLiteral( type, 3, threeStr, 1 );
	Gen_GetNumericLiteral( type, 4, fourStr, 1 );
	Gen_GetNumericLiteral( type, 5, fiveStr, 1 );
	Gen_GetNumericLiteral( type, 7.34846922834f, answerStr, 11 );

	char parmListValues[4][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf( parmListValues[0], 64, "( %s )", twoStr );
	snprintf( parmListValues[1], 64, "( %s )", threeStr );
	snprintf( parmListValues[2], 64, "( %s )", fourStr );
	snprintf( parmListValues[3], 64, "( %s )", fiveStr );

	char parmListAnswer[GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf( parmListAnswer, 64, "( %s )", answerStr);

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestArithmetic%s_%s", "Length", fullTypeName );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append( codeTests, "{\n" );
	String_Appendf( codeTests, "\tconst %s a = %s( %s, %s, %s, %s );\n", fullTypeName, fullTypeName, parmListValues[0], parmListValues[1], parmListValues[2], parmListValues[3] );
	String_Append( codeTests, "\n" );
	String_Appendf( codeTests, "\t%s b = quaternion_length( a );\n", baseTypeString);
	String_Append( codeTests, "\n");
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s%s( b, %s ) );\n", baseTypeString, "eq", parmListAnswer );
	String_Append( codeTests, "\n" );
	String_Append( codeTests, "\tTEMPER_PASS();\n" );
	String_Append( codeTests, "}\n" );
	String_Append( codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestNormalize(  stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genType_t type, const char* fullTypeName ) {
	// number picked at random
	char twoStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char threeStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char fourStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char fiveStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char answerXStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char answerYStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char answerZStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char answerWStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, 2, twoStr, 1 );
	Gen_GetNumericLiteral( type, 3, threeStr, 1 );
	Gen_GetNumericLiteral( type, 4, fourStr, 1 );
	Gen_GetNumericLiteral( type, 5, fiveStr, 1 );
	Gen_GetNumericLiteral( type, 0.272166f, answerXStr, 6 );
	Gen_GetNumericLiteral( type, 0.408248f, answerYStr, 6 );
	Gen_GetNumericLiteral( type, 0.544331f, answerZStr, 6 );
	Gen_GetNumericLiteral( type, 0.680414f, answerWStr, 6 );

	char parmListRhsValues[4][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf( parmListRhsValues[0], 64, "( %s )", twoStr );
	snprintf( parmListRhsValues[1], 64, "( %s )", threeStr );
	snprintf( parmListRhsValues[2], 64, "( %s )", fourStr );
	snprintf( parmListRhsValues[3], 64, "( %s )", fiveStr );

	char parmListAnswers[4][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf( parmListAnswers[0], 64, "( %s )", answerXStr );
	snprintf( parmListAnswers[1], 64, "( %s )", answerYStr );
	snprintf( parmListAnswers[2], 64, "( %s )", answerZStr );
	snprintf( parmListAnswers[3], 64, "( %s )", answerWStr );

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestArithmetic%s_%s", "Normalize", fullTypeName );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append( codeTests, "{\n" );
	String_Appendf( codeTests, "\tconst %s a = %s( %s, %s, %s, %s );\n", fullTypeName, fullTypeName, parmListRhsValues[0], parmListRhsValues[1], parmListRhsValues[2], parmListRhsValues[3] );
	String_Append( codeTests, "\n" );
	String_Appendf( codeTests, "\t%s b = quaternion_normalize( a );\n", fullTypeName );
	String_Append( codeTests, "\n" );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( b == %s( %s, %s, %s, %s ) );\n", fullTypeName, parmListAnswers[0], parmListAnswers[1], parmListAnswers[2], parmListAnswers[3] );
	String_Append( codeTests, "\n" );
	String_Append( codeTests, "\tTEMPER_PASS();\n" );
	String_Append( codeTests, "}\n" );
	String_Append( codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestConjugate(  stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genType_t type, const char* fullTypeName ) {
	// number picked at random
	char twoStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char threeStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char fourStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char fiveStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char answerXStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char answerYStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char answerZStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char answerWStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, 2, twoStr, 1 );
	Gen_GetNumericLiteral( type, 3, threeStr, 1 );
	Gen_GetNumericLiteral( type, 4, fourStr, 1 );
	Gen_GetNumericLiteral( type, 5, fiveStr, 1 );
	Gen_GetNumericLiteral( type, -2, answerXStr, 6 );
	Gen_GetNumericLiteral( type, -3, answerYStr, 6 );
	Gen_GetNumericLiteral( type, -4, answerZStr, 6 );
	Gen_GetNumericLiteral( type, 5, answerWStr, 6 );

	char parmListRhsValues[4][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf( parmListRhsValues[0], 64, "( %s )", twoStr );
	snprintf( parmListRhsValues[1], 64, "( %s )", threeStr );
	snprintf( parmListRhsValues[2], 64, "( %s )", fourStr );
	snprintf( parmListRhsValues[3], 64, "( %s )", fiveStr );

	char parmListAnswers[4][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf( parmListAnswers[0], 64, "( %s )", answerXStr );
	snprintf( parmListAnswers[1], 64, "( %s )", answerYStr );
	snprintf( parmListAnswers[2], 64, "( %s )", answerZStr );
	snprintf( parmListAnswers[3], 64, "( %s )", answerWStr );

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestArithmetic%s_%s", "Conjugate", fullTypeName );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append( codeTests, "{\n" );
	String_Appendf( codeTests, "\tconst %s a = %s( %s, %s, %s, %s );\n", fullTypeName, fullTypeName, parmListRhsValues[0], parmListRhsValues[1], parmListRhsValues[2], parmListRhsValues[3] );
	String_Append( codeTests, "\n" );
	String_Appendf( codeTests, "\t%s b = quaternion_conjugate( a );\n", fullTypeName );
	String_Append( codeTests, "\n" );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( b == %s( %s, %s, %s, %s ) );\n", fullTypeName, parmListAnswers[0], parmListAnswers[1], parmListAnswers[2], parmListAnswers[3] );
	String_Append( codeTests, "\n" );
	String_Append( codeTests, "\tTEMPER_PASS();\n" );
	String_Append( codeTests, "}\n" );
	String_Append( codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestInverse(  stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genType_t type, const char* fullTypeName ) {
	// number picked at random
	char twoStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char threeStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char fourStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char fiveStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char answerXStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char answerYStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char answerZStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char answerWStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, 2, twoStr, 1 );
	Gen_GetNumericLiteral( type, 3, threeStr, 1 );
	Gen_GetNumericLiteral( type, 4, fourStr, 1 );
	Gen_GetNumericLiteral( type, 5, fiveStr, 1 );
	Gen_GetNumericLiteral( type, -0.037037f, answerXStr, 6 );
	Gen_GetNumericLiteral( type, -0.0555556f, answerYStr, 7 );
	Gen_GetNumericLiteral( type, -0.0740741f, answerZStr, 7 );
	Gen_GetNumericLiteral( type, 0.0925926f, answerWStr, 6 );

	char parmListRhsValues[4][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf( parmListRhsValues[0], 64, "( %s )", twoStr );
	snprintf( parmListRhsValues[1], 64, "( %s )", threeStr );
	snprintf( parmListRhsValues[2], 64, "( %s )", fourStr );
	snprintf( parmListRhsValues[3], 64, "( %s )", fiveStr );

	char parmListAnswers[4][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf( parmListAnswers[0], 64, "( %s )", answerXStr );
	snprintf( parmListAnswers[1], 64, "( %s )", answerYStr );
	snprintf( parmListAnswers[2], 64, "( %s )", answerZStr );
	snprintf( parmListAnswers[3], 64, "( %s )", answerWStr );

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestArithmetic%s_%s", "Inverse", fullTypeName );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append( codeTests, "{\n" );
	String_Appendf( codeTests, "\tconst %s a = %s( %s, %s, %s, %s );\n", fullTypeName, fullTypeName, parmListRhsValues[0], parmListRhsValues[1], parmListRhsValues[2], parmListRhsValues[3] );
	String_Append( codeTests, "\n" );
	String_Appendf( codeTests, "\t%s b = quaternion_inverse( a );\n", fullTypeName );
	String_Append( codeTests, "\n" );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( b == %s( %s, %s, %s, %s ) );\n", fullTypeName, parmListAnswers[0], parmListAnswers[1], parmListAnswers[2], parmListAnswers[3] );
	String_Append( codeTests, "\n" );
	String_Append( codeTests, "\tTEMPER_PASS();\n" );
	String_Append( codeTests, "}\n" );
	String_Append( codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestQuaternionVectorRotationByAngleAxis(  stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genType_t type, const char* fullTypeName, const char* baseTypeString ) {
	// number picked at random
	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char angleStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, 0, zeroStr, 1 );
	Gen_GetNumericLiteral( type, 1, oneStr, 1 );	
	Gen_GetNumericLiteral( type, 1.5708f, angleStr, 6 );

	char parmListAnswers[3][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf( parmListAnswers[0], 64, "( %s )", zeroStr );
	snprintf( parmListAnswers[1], 64, "( %s )", zeroStr );
	snprintf( parmListAnswers[2], 64, "( %s )", oneStr );

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestArithmetic%s_%s", "VectorRotationByAngleAxis", fullTypeName );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append( codeTests, "{\n" );
	String_Appendf( codeTests, "\tconst %s3 vector = %s3( %s, %s, %s );\n", baseTypeString, baseTypeString, zeroStr, oneStr, zeroStr );
	String_Appendf( codeTests, "\tconst %s3 axis = %s3( %s, %s, %s );\n", baseTypeString, baseTypeString, oneStr, zeroStr, zeroStr );
	String_Appendf( codeTests, "\tconst %s angle = %s;\n", baseTypeString, angleStr );
	String_Append( codeTests, "\n" );
	String_Appendf( codeTests, "\t%s3 rotated_vector = quaternion_rotate_vector_about_angle_axis( vector, angle, axis );\n", baseTypeString );
	String_Append( codeTests, "\n" );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( rotated_vector == %s3( %s, %s, %s ) );\n", baseTypeString, parmListAnswers[0], parmListAnswers[1], parmListAnswers[2] );
	String_Append( codeTests, "\n" );
	String_Append( codeTests, "\tTEMPER_PASS();\n" );
	String_Append( codeTests, "}\n" );
	String_Append( codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void Gen_QuaternionTests( const genLanguage_t language, const genType_t type ) {

	const u32 testsCodeBytes = 16 * KB_TO_BYTES;
	const u32 suiteCodeBytes = 2 * KB_TO_BYTES;
	
	stringBuilder_t codeTests = String_Create( testsCodeBytes );
	stringBuilder_t codeSuite = String_Create( suiteCodeBytes );

	const char* typeString = Gen_GetTypeString( type );
	
	char baseTypeString[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( baseTypeString, GEN_STRING_LENGTH_TYPE_NAME, "%s", typeString );
	
	char fullTypeString[GEN_STRING_LENGTH_TYPE_NAME];
	snprintf( fullTypeString, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", typeString, GEN_COMPONENT_COUNT_MAX );

	stringBuilder_t code = String_Create( testsCodeBytes + suiteCodeBytes );

	String_Appendf( &code, GEN_FILE_HEADER );

	// TODO: Need this?
	String_Append( &code, "#include <temper/temper.h>\n" );
	String_Append( &code, "\n" );

	String_Appendf( &codeSuite, "TEMPER_SUITE( Test_%s_%s )\n", "quaternion", fullTypeString );
	String_Append( &codeSuite, "{\n" );

	GenerateTestMultiplyScalar( &codeTests, &codeSuite, type, fullTypeString, typeString );
	GenerateTestMultiplyQuaternion( &codeTests, &codeSuite, type, fullTypeString );
	GenerateTestLength( &codeTests, &codeSuite, type, fullTypeString, typeString );
	GenerateTestNormalize( &codeTests, &codeSuite, type, fullTypeString );
	GenerateTestConjugate( &codeTests, &codeSuite, type, fullTypeString );
	GenerateTestInverse( &codeTests, &codeSuite, type, fullTypeString );
	GenerateTestQuaternionVectorRotationByAngleAxis( &codeTests, &codeSuite, type, fullTypeString, typeString );

	String_Append( &codeSuite, "}\n" );

	String_Append( &code, codeTests.str );
	String_Append( &code, codeSuite.str );

	const char* fileExtension = GEN_SOURCE_FILE_EXTENSIONS[language];

	char filename[1024] = { 0 };
	snprintf( filename, 1024, "%stest_quaternion_%s.%s", GEN_FOLDER_PATHS_TESTS[language], fullTypeString, fileExtension );

	FS_WriteEntireFile( filename, code.str, code.length );

	Mem_Reset();
}