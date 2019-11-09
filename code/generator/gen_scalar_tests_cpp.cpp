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
#include "gen_scalar_cpp.h"

#include "defines.h"

#include "gen_common.h"
#include "gen_common_sse.h"

#include "string_builder.h"
#include "allocator.h"
#include "file_io.h"

static char g_degreesStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
static const char* g_radiansStr;

static void GenerateTestFloateq( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genType_t type, const char* memberTypeString ) {
	assert( codeTests );
	assert( codeSuite );
	assert( memberTypeString );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestFloateq_%s", memberTypeString );

	// numbers chosen at random
	char aStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char bStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char cStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char dStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, 5.0f, aStr, 1 );
	Gen_GetNumericLiteral( type, 5.0f, bStr, 1 );
	Gen_GetNumericLiteral( type, 5.00002f, cStr );
	Gen_GetNumericLiteral( type, 5.0001f, dStr );

	const char* floateqStr = Gen_GetFuncNameFloateq( type );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s a = %s;\n", memberTypeString, aStr );
	String_Appendf( codeTests, "\t%s b = %s;\n", memberTypeString, bStr );
	String_Appendf( codeTests, "\t%s c = %s;\n", memberTypeString, cStr );
	String_Appendf( codeTests, "\t%s d = %s;\n", memberTypeString, dStr );
	String_Append(  codeTests, "\n" );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE(  %s( a, b ) );\n", floateqStr );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( !%s( a, c ) );\n", floateqStr );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( !%s( a, d ) );\n", floateqStr );
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestSign( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genType_t type, const char* memberTypeString ) {
	assert( codeTests );
	assert( codeSuite );
	assert( memberTypeString );

	if ( type == GEN_TYPE_BOOL || type == GEN_TYPE_UINT ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestSign_%s", memberTypeString );

	const char* signFuncStr = Gen_GetFuncNameSign( type );

	char valueSignedStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, -5, valueSignedStr, 1 );

	char valueUnsignedStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 9, valueUnsignedStr, 1 );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( %s ) == -1 );\n", signFuncStr, valueSignedStr );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( %s ) ==  1 );\n", signFuncStr, valueUnsignedStr );
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestDegreesRadians( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genLanguage_t language, const genType_t type, const char* memberTypeString, const char* registerName ) {
	assert( codeTests );
	assert( codeSuite );
	assert( memberTypeString );
	assert( registerName );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestDegreesRadians_Scalar_%s", memberTypeString );

	const char* floateqStr = Gen_GetFuncNameFloateq( type );

	const char* radiansFuncStr = Gen_GetFuncNameRadians( type );
	const char* degreesFuncStr = Gen_GetFuncNameDegrees( type );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( %s( g_deg_%s ), %s ) );\n", floateqStr, radiansFuncStr, memberTypeString, g_radiansStr );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( %s( g_rad_%s ), %s ) );\n", floateqStr, degreesFuncStr, memberTypeString, g_degreesStr );
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );

	if ( Gen_TypeSupportsSSE( type ) ) {
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestDegreesRadians_SSE_%s", memberTypeString );

		const char* loadFuncStr		= Gen_SSE_GetIntrinsicLoad( type );
		const char* storeFuncStr	= Gen_SSE_GetIntrinsicStore( type );

		char radiansFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameRadians( language, type, radiansFuncStrSSE );

		char degreesFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameDegrees( language, type, degreesFuncStrSSE );

		String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  codeTests, "{\n" );
		String_Appendf( codeTests, "\t%s degs[4] = { g_deg_%s, g_deg_%s, g_deg_%s, g_deg_%s };\n", memberTypeString, memberTypeString, memberTypeString, memberTypeString, memberTypeString );
		String_Appendf( codeTests, "\t%s rads[4] = { g_rad_%s, g_rad_%s, g_rad_%s, g_rad_%s };\n", memberTypeString, memberTypeString, memberTypeString, memberTypeString, memberTypeString );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s results;\n", registerName );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\t// radians\n" );
		String_Appendf( codeTests, "\t%s inRadians = %s( degs );\n", registerName, loadFuncStr );
		String_Appendf( codeTests, "\t%s( inRadians, &results );\n", radiansFuncStrSSE );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s radiansResults[4];\n", memberTypeString );
		String_Appendf( codeTests, "\t%s( radiansResults, results );\n", storeFuncStr );
		String_Append(  codeTests, "\n" );
		for ( u32 i = 0; i < 4; i++ ) {
			String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( radiansResults[%d], %s ) );\n", floateqStr, i, g_radiansStr );
		}
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\t// degrees\n" );
		String_Appendf( codeTests, "\t%s inDegrees = %s( rads );\n", registerName, loadFuncStr );
		String_Appendf( codeTests, "\t%s( inDegrees, &results );\n", degreesFuncStrSSE );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s degreesResults[4];\n", memberTypeString );
		String_Appendf( codeTests, "\t%s( degreesResults, results );\n", storeFuncStr );
		String_Append(  codeTests, "\n" );
		for ( u32 i = 0; i < 4; i++ ) {
			String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( degreesResults[%d], %s ) );\n", floateqStr, i, g_degreesStr );
		}
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  codeTests, "}\n" );
		String_Append(  codeTests, "\n" );

		String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

static void GenerateTestMinMax( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genType_t type, const char* memberTypeString ) {
	assert( codeTests );
	assert( codeSuite );
	assert( memberTypeString );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestMinMax_%s", memberTypeString );

	// numbers picked at random
	char aStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char bStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, 5, aStr, 1 );
	Gen_GetNumericLiteral( type, 9, bStr, 1 );

	const char* floateqStr = Gen_GetFuncNameFloateq( type );

	const char* minFuncStr = Gen_GetFuncNameMin( type );
	const char* maxFuncStr = Gen_GetFuncNameMax( type );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s a = %s;\n", memberTypeString, aStr );
	String_Appendf( codeTests, "\t%s b = %s;\n", memberTypeString, bStr );
	String_Append(  codeTests, "\n" );
	if ( Gen_TypeIsFloatingPoint( type ) ) {
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( %s( a, b ), a ) );\n", floateqStr, minFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( %s( a, b ), b ) );\n", floateqStr, maxFuncStr );
	} else {
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( a, b ) == a );\n", minFuncStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( a, b ) == b );\n", maxFuncStr );
	}
	String_Append( codeTests, "\n" );
	String_Append( codeTests, "\tTEMPER_PASS();\n" );
	String_Append( codeTests, "}\n" );
	String_Append( codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestClamp( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genType_t type, const char* memberTypeString ) {
	assert( codeTests );
	assert( codeSuite );
	assert( memberTypeString );

	if ( type == GEN_TYPE_BOOL ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestClamp_%s", memberTypeString );

	// numbers picked at random
	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char elevenStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char lowStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char highStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, 0,  zeroStr, 1 );
	Gen_GetNumericLiteral( type, 11, elevenStr, 1 );
	Gen_GetNumericLiteral( type, 1,  lowStr, 1 );
	Gen_GetNumericLiteral( type, 10, highStr, 1 );

	const char* floateqStr = Gen_GetFuncNameFloateq( type );

	const char* clampFuncStr = Gen_GetFuncNameClamp( type );

	bool isFloatingPointType = Gen_TypeIsFloatingPoint( type );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s a;\n", memberTypeString );
	String_Appendf( codeTests, "\t%s low  = %s;\n", memberTypeString, lowStr );
	String_Appendf( codeTests, "\t%s high = %s;\n", memberTypeString, highStr );
	String_Append(  codeTests, "\n" );
	if ( isFloatingPointType ) {
		String_Appendf( codeTests, "\ta = %s( %s, low, high );\n", clampFuncStr, zeroStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( a, low ) );\n", floateqStr );
	} else {
		String_Appendf( codeTests, "\ta = (%s) %s( %s, low, high );\n", memberTypeString, clampFuncStr, zeroStr );
		String_Append( codeTests, "\tTEMPER_EXPECT_TRUE( a == low );\n" );
	}
	String_Append( codeTests, "\n" );
	if ( isFloatingPointType ) {
		String_Appendf( codeTests, "\ta = %s( %s, low, high );\n", clampFuncStr, elevenStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( a, high ) );\n", floateqStr );
	} else {
		String_Appendf( codeTests, "\ta = (%s) %s( %s, low, high );\n", memberTypeString, clampFuncStr, elevenStr );
		String_Append( codeTests, "\tTEMPER_EXPECT_TRUE( a == high );\n" );
	}
	String_Append( codeTests, "\n" );
	String_Append( codeTests, "\tTEMPER_PASS();\n" );
	String_Append( codeTests, "}\n" );
	String_Append( codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestSaturate( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genLanguage_t language, const genType_t type, const char* memberTypeString ) {
	assert( codeTests );
	assert( codeSuite );
	assert( memberTypeString );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestSaturate_%s", memberTypeString );

	char minusOneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char twoStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( type, -1, minusOneStr );
	Gen_GetNumericLiteral( type,  0, zeroStr );
	Gen_GetNumericLiteral( type,  1, oneStr );
	Gen_GetNumericLiteral( type,  2, twoStr );

	const char* floateqStr = Gen_GetFuncNameFloateq( type );

	char saturateFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameSaturate( language, type, 1, saturateFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s a;\n", memberTypeString );
	String_Append(  codeTests, "\n" );
	String_Appendf( codeTests, "\ta = %s( %s );\n", saturateFuncStr, minusOneStr );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( a, %s ) );\n", floateqStr, zeroStr );
	String_Append(  codeTests, "\n" );
	String_Appendf( codeTests, "\ta = %s( %s );\n", saturateFuncStr, twoStr );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( a, %s ) );\n", floateqStr, oneStr );
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

static void GenerateTestLerp( stringBuilder_t* codeTests, stringBuilder_t* codeSuite, const genLanguage_t language, const genType_t type, const char* memberTypeString, const char* registerName ) {
	assert( codeTests );
	assert( codeSuite );
	assert( memberTypeString );
	assert( registerName );

	if ( !Gen_TypeIsFloatingPoint( type ) ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestLerp_Scalar_%s", memberTypeString );

	// numbers chosen arbitrarily
	char aStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 1.0f, aStr, 1 );

	char bStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 3.0f, bStr, 1 );

	char halfStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 0.5f, halfStr, 1 );

	char answerStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( type, 2.0f, answerStr, 1 );

	const char* floateqStr = Gen_GetFuncNameFloateq( type );

	char lerpFuncStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameLerp( language, type, 1, lerpFuncStr );

	String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  codeTests, "{\n" );
	String_Appendf( codeTests, "\t%s a = %s;\n", memberTypeString, aStr );
	String_Appendf( codeTests, "\t%s b = %s;\n", memberTypeString, bStr );
	String_Append(  codeTests, "\n" );
	String_Appendf( codeTests, "\t%s answer = %s( a, b, %s );\n", memberTypeString, lerpFuncStr, halfStr );
	String_Append(  codeTests, "\n" );
	String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( answer, %s ) );\n", floateqStr, answerStr );
	String_Append(  codeTests, "\n" );
	String_Append(  codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  codeTests, "}\n" );
	String_Append(  codeTests, "\n" );

	String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );

	if ( Gen_TypeSupportsSSE( type ) ) {
		snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestLerp_SSE_%s", memberTypeString );

		char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetFullTypeName( type, 1, 1, sseTypeName );

		const char* loadFuncStr		= Gen_SSE_GetIntrinsicLoad( type );
		const char* storeFuncStr	= Gen_SSE_GetIntrinsicStore( type );

		char lerpFuncStrSSE[GEN_STRING_LENGTH_FUNCTION_NAME];
		Gen_SSE_GetFuncNameLerp( language, type, 1, lerpFuncStrSSE );

		String_Appendf( codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  codeTests, "{\n" );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s ones[4]   = { %s, %s, %s, %s };\n", memberTypeString, aStr, aStr, aStr, aStr );
		String_Appendf( codeTests, "\t%s threes[4] = { %s, %s, %s, %s };\n", memberTypeString, bStr, bStr, bStr, bStr );
		String_Appendf( codeTests, "\t%s halves[4] = { %s, %s, %s, %s };\n", memberTypeString, halfStr, halfStr, halfStr, halfStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s lhs = %s( ones );\n", registerName, loadFuncStr );
		String_Appendf( codeTests, "\t%s rhs = %s( threes );\n", registerName, loadFuncStr );
		String_Appendf( codeTests, "\t%s t   = %s( halves );\n", registerName, loadFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s results;\n", registerName );
		String_Appendf( codeTests, "\t%s( lhs, rhs, t, &results );\n", lerpFuncStrSSE );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\t%s lerpResults[4];\n", memberTypeString );
		String_Appendf( codeTests, "\t%s( lerpResults, results );\n", storeFuncStr );
		String_Append(  codeTests, "\n" );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( lerpResults[0], %s ) );\n", floateqStr, answerStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( lerpResults[1], %s ) );\n", floateqStr, answerStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( lerpResults[2], %s ) );\n", floateqStr, answerStr );
		String_Appendf( codeTests, "\tTEMPER_EXPECT_TRUE( %s( lerpResults[3], %s ) );\n", floateqStr, answerStr );
		String_Append(  codeTests, "\n" );
		String_Append(  codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  codeTests, "}\n" );
		String_Append(  codeTests, "\n" );

		String_Appendf( codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

void Gen_ScalarTests( const genLanguage_t language, const genType_t type ) {
	const u32 testsCodeBytes = 4 * KB_TO_BYTES;
	const u32 suiteCodeBytes = 2 * KB_TO_BYTES;

	stringBuilder_t codeTests = String_Create( testsCodeBytes );
	stringBuilder_t codeSuite = String_Create( suiteCodeBytes );

	const char* memberTypeString = Gen_GetMemberTypeString( type );
	const char* registerName = Gen_SSE_GetRegisterName( type );

	stringBuilder_t code = String_Create( testsCodeBytes + suiteCodeBytes );
	String_Append( &code, GEN_FILE_HEADER );

	if ( Gen_TypeIsFloatingPoint( type ) ) {
		Gen_GetNumericLiteral( type, 90.0f, g_degreesStr, 1 );

		// DM: must be done this way to avoid floating-point imprecision
		g_radiansStr = "1.57079637";
		if ( type == GEN_TYPE_FLOAT ) {
			g_radiansStr = "1.57079637f";
		}

		String_Appendf( &code, "static %s g_deg_%s = %s;\n", memberTypeString, memberTypeString, g_degreesStr );
		String_Appendf( &code, "static %s g_rad_%s = %s;\n", memberTypeString, memberTypeString, g_radiansStr );
		String_Append(  &code, "\n" );
	}

	String_Appendf( &codeSuite, "TEMPER_SUITE( Test_%s )\n", memberTypeString );
	String_Append(  &codeSuite, "{\n" );

	GenerateTestFloateq( &codeTests, &codeSuite, type, memberTypeString );

	GenerateTestSign( &codeTests, &codeSuite, type, memberTypeString );

	GenerateTestDegreesRadians( &codeTests, &codeSuite, language, type, memberTypeString, registerName );

	GenerateTestMinMax( &codeTests, &codeSuite, type, memberTypeString );

	GenerateTestClamp( &codeTests, &codeSuite, type, memberTypeString );

	GenerateTestSaturate( &codeTests, &codeSuite, language, type, memberTypeString );

	GenerateTestLerp( &codeTests, &codeSuite, language, type, memberTypeString, registerName );

	String_Appendf( &codeSuite, "}\n" );

	String_Appendf( &code, codeTests.str );
	String_Appendf( &code, codeSuite.str );

	char filename[1024] = { 0 };
	snprintf( filename, 1024, "%stest_scalar_%s.%s", GEN_FOLDER_PATHS_TESTS[language], memberTypeString, GEN_SOURCE_FILE_EXTENSIONS[language] );

	FS_WriteEntireFile( filename, code.str, code.length );

	Mem_Reset();
}
