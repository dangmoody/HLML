#include "GeneratorScalarTests.h"

#include "allocator.h"

#include "FileIO.h"

#include "gen_common_sse.h"

bool GeneratorScalarTest::Generate( const genType_t type ) {
	const u32 testsCodeBytes = 4 * KB_TO_BYTES;
	const u32 suiteCodeBytes = 2 * KB_TO_BYTES;

	m_codeTests = String_Create( testsCodeBytes );
	m_codeSuite = String_Create( suiteCodeBytes );

	m_type = type;

	m_memberTypeString = Gen_GetMemberTypeString( type );

	m_registerName = Gen_SSE_GetRegisterName( type );

	stringBuilder_t code = String_Create( testsCodeBytes + suiteCodeBytes );
	String_Append( &code, "#include \"../../" GEN_OUT_GEN_FOLDER_PATH GEN_FILENAME_FUNCTIONS_SCALAR ".h\"\n" );
	String_Append( &code, "\n" );

	String_Append( &code, "#include <temper/temper.h>\n" );
	String_Append( &code, "\n" );

	if ( m_type == GEN_TYPE_FLOAT ) {
		String_Append( &code, "#include \"../../" GEN_OUT_GEN_FOLDER_PATH GEN_FILENAME_FUNCTIONS_SCALAR_SSE ".h\"\n" );
		String_Append( &code, "\n" );
	}

	String_Appendf( &m_codeSuite, "TEMPER_SUITE( Test_%s )\n", m_memberTypeString );
	String_Append(  &m_codeSuite, "{\n" );

	GenerateTestFloateq();

	GenerateTestSign();

	GenerateTestDegreesRadians();

	GenerateTestMinMax();

	GenerateTestClamp();

	GenerateTestSaturate();

	GenerateTestLerp();

	String_Appendf( &m_codeSuite, "}\n" );

	String_Appendf( &code, m_codeTests.str );
	String_Appendf( &code, m_codeSuite.str );

	char filename[1024] = { 0 };
	snprintf( filename, 1024, GEN_TESTS_FOLDER_PATH "test_scalar_%s.cpp", m_memberTypeString );

	bool32 result = FS_WriteEntireFile( filename, code.str, code.length );

	if ( !result ) {
		printf( "Can't generate scalar test suite for %s.  That's rough man.\n", m_memberTypeString );
	}

	Mem_Reset();

	return result;
}

void GeneratorScalarTest::GenerateTestFloateq() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestFloateq_%s", m_memberTypeString );

	// numbers chosen at random
	char aStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char bStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char cStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char dStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( m_type, 5.0f, aStr, 1 );
	Gen_GetNumericLiteral( m_type, 5.0f, bStr, 1 );
	Gen_GetNumericLiteral( m_type, 5.00002f, cStr );
	Gen_GetNumericLiteral( m_type, 5.0001f, dStr );

	const char* floateqStr = Gen_GetFuncNameFloateq( m_type );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s a = %s;\n", m_memberTypeString, aStr );
	String_Appendf( &m_codeTests, "\t%s b = %s;\n", m_memberTypeString, bStr );
	String_Appendf( &m_codeTests, "\t%s c = %s;\n", m_memberTypeString, cStr );
	String_Appendf( &m_codeTests, "\t%s d = %s;\n", m_memberTypeString, dStr );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE(  %s( a, b ) );\n", floateqStr );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( !%s( a, c ) );\n", floateqStr );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( !%s( a, d ) );\n", floateqStr );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorScalarTest::GenerateTestSign() {
	if ( m_type == GEN_TYPE_BOOL || m_type == GEN_TYPE_UINT ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestSign_%s", m_memberTypeString );

	char valueSignedStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char valueUnsignedStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( m_type, -5, valueSignedStr, 1 );
	Gen_GetNumericLiteral( m_type, 9, valueUnsignedStr, 1 );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( sign( %s ) == -1 );\n", valueSignedStr );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( sign( %s ) ==  1 );\n", valueUnsignedStr );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorScalarTest::GenerateTestDegreesRadians() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestDegreesRadians_%s", m_memberTypeString );

	char degreesStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral( m_type, 90.0f, degreesStr, 1 );

	// DM: must be done this way to avoid floating-point imprecision
	const char* radiansStr = "1.57079637";
	if ( m_type == GEN_TYPE_FLOAT ) {
		radiansStr = "1.57079637f";
	}

	const char* floateqStr = Gen_GetFuncNameFloateq( m_type );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Append( &m_codeTests, "\t// scalar\n" );
	String_Appendf( &m_codeTests, "\t%s deg = %s;\n", m_memberTypeString, degreesStr );
	String_Appendf( &m_codeTests, "\t%s rad = %s;\n", m_memberTypeString, radiansStr );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( radians( deg ), %s ) );\n", floateqStr, radiansStr );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( degrees( rad ), %s ) );\n", floateqStr, degreesStr );

	if ( Gen_TypeSupportsSSE( m_type ) ) {
		const char* loadFuncStr		= Gen_SSE_GetFuncStrLoad( m_type );
		const char* storeFuncStr	= Gen_SSE_GetFuncStrStore( m_type );

		char inputDataNameRadians[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetInputDataNameRadians( m_type, inputDataNameRadians );

		char inputDataNameDegrees[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetInputDataNameDegrees( m_type, inputDataNameDegrees );

		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\t// SSE\n" );
		String_Appendf( &m_codeTests, "\t%s degs[4] = { deg, deg, deg, deg };\n", m_memberTypeString );
		String_Appendf( &m_codeTests, "\t%s rads[4] = { rad, rad, rad, rad };\n", m_memberTypeString );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s results;\n", m_registerName );
		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\t// radians\n" );
		String_Appendf( &m_codeTests, "\t%s inRadians;\n", inputDataNameRadians );
		String_Appendf( &m_codeTests, "\tinRadians.deg = %s( degs );\n", loadFuncStr );
		String_Appendf( &m_codeTests, "\tradians_sse( inRadians, &results );\n" );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s radiansResults[4];\n", m_memberTypeString );
		String_Appendf( &m_codeTests, "\t%s( radiansResults, results );\n", storeFuncStr );
		String_Append(  &m_codeTests, "\n" );
		for ( u32 i = 0; i < 4; i++ ) {
			String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( radiansResults[%d], %s ) );\n", floateqStr, i, radiansStr );
		}
		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\t// degrees\n" );
		String_Appendf( &m_codeTests, "\t%s inDegrees;\n", inputDataNameDegrees );
		String_Appendf( &m_codeTests, "\tinDegrees.rad = %s( rads );\n", loadFuncStr );
		String_Appendf( &m_codeTests, "\tdegrees_sse( inDegrees, &results );\n" );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s degreesResults[4];\n", m_memberTypeString );
		String_Appendf( &m_codeTests, "\t%s( degreesResults, results );\n", storeFuncStr );
		String_Append(  &m_codeTests, "\n" );
		for ( u32 i = 0; i < 4; i++ ) {
			String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( degreesResults[%d], %s ) );\n", floateqStr, i, degreesStr );
		}
	}

	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorScalarTest::GenerateTestMinMax() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestMinMax_%s", m_memberTypeString );

	// numbers picked at random
	char aStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char bStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( m_type, 5, aStr, 1 );
	Gen_GetNumericLiteral( m_type, 9, bStr, 1 );

	const char* floateqStr = Gen_GetFuncNameFloateq( m_type );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s a = %s;\n", m_memberTypeString, aStr );
	String_Appendf( &m_codeTests, "\t%s b = %s;\n", m_memberTypeString, bStr );
	String_Append(  &m_codeTests, "\n" );
	if ( Gen_IsFloatingPointType( m_type ) ) {
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( min( a, b ), a ) );\n", floateqStr );
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( max( a, b ), b ) );\n", floateqStr );
	} else {
		String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( min( a, b ) == a );\n" );
		String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( max( a, b ) == b );\n" );
	}
	String_Append( &m_codeTests, "\n" );
	String_Append( &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append( &m_codeTests, "}\n" );
	String_Append( &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorScalarTest::GenerateTestClamp() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestClamp_%s", m_memberTypeString );

	// numbers picked at random
	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char elevenStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char lowStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char highStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( m_type, 0,  zeroStr, 1 );
	Gen_GetNumericLiteral( m_type, 11, elevenStr, 1 );
	Gen_GetNumericLiteral( m_type, 1,  lowStr, 1 );
	Gen_GetNumericLiteral( m_type, 10, highStr, 1 );

	const char* floateqStr = Gen_GetFuncNameFloateq( m_type );

	bool isFloatingPointType = Gen_IsFloatingPointType( m_type );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s a;\n", m_memberTypeString );
	String_Appendf( &m_codeTests, "\t%s low  = %s;\n", m_memberTypeString, lowStr );
	String_Appendf( &m_codeTests, "\t%s high = %s;\n", m_memberTypeString, highStr );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\ta = clamp( %s, low, high );\n", zeroStr );
	if ( isFloatingPointType ) {
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( a, low ) );\n", floateqStr );
	} else {
		String_Append( &m_codeTests, "\tTEMPER_EXPECT_TRUE( a == low );\n" );
	}
	String_Append( &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\ta = clamp( %s, low, high );\n", elevenStr );
		if ( isFloatingPointType ) {
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( a, high ) );\n", floateqStr );
	} else {
		String_Append( &m_codeTests, "\tTEMPER_EXPECT_TRUE( a == high );\n" );
	}
	String_Append( &m_codeTests, "\n" );
	String_Append( &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append( &m_codeTests, "}\n" );
	String_Append( &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorScalarTest::GenerateTestSaturate() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, GEN_STRING_LENGTH_TEST_NAME, "TestSaturate_%s", m_memberTypeString );

	char minusOneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char zeroStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char oneStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char twoStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( m_type, -1, minusOneStr );
	Gen_GetNumericLiteral( m_type,  0, zeroStr );
	Gen_GetNumericLiteral( m_type,  1, oneStr );
	Gen_GetNumericLiteral( m_type,  2, twoStr );

	const char* floateqStr = Gen_GetFuncNameFloateq( m_type );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s a;\n", m_memberTypeString );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\ta = saturate( %s );\n", minusOneStr );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( a, %s ) );\n", floateqStr, zeroStr );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\ta = saturate( %s );\n", twoStr );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( a, %s ) );\n", floateqStr, oneStr );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorScalarTest::GenerateTestLerp() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf( testName, 32, "TestLerp_%s", m_memberTypeString );

	// numbers chosen arbitrarily
	char aStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char bStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char halfStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char answerStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral( m_type, 1.0f, aStr, 1 );
	Gen_GetNumericLiteral( m_type, 3.0f, bStr, 1 );
	Gen_GetNumericLiteral( m_type, 0.5f, halfStr, 1 );
	Gen_GetNumericLiteral( m_type, 2.0f, answerStr, 1 );

	const char* floateqStr = Gen_GetFuncNameFloateq( m_type );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Append(  &m_codeTests, "\t// scalar\n" );
	String_Appendf( &m_codeTests, "\t%s a = %s;\n", m_memberTypeString, aStr );
	String_Appendf( &m_codeTests, "\t%s b = %s;\n", m_memberTypeString, bStr );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s answer = lerp( a, b, %s );\n", m_memberTypeString, halfStr );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( answer, %s ) );\n", floateqStr, answerStr );

	if ( m_type == GEN_TYPE_FLOAT ) {
		char inputDataName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_SSE_GetInputDataNameLerp( m_type, 1, inputDataName );

		const char* loadFuncStr		= Gen_SSE_GetFuncStrLoad( m_type );
		const char* storeFuncStr	= Gen_SSE_GetFuncStrStore( m_type );

		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\t// SSE\n" );
		String_Appendf( &m_codeTests, "\t%s ones[4]   = { %s, %s, %s, %s };\n", m_memberTypeString, aStr, aStr, aStr, aStr );
		String_Appendf( &m_codeTests, "\t%s threes[4] = { %s, %s, %s, %s };\n", m_memberTypeString, bStr, bStr, bStr, bStr );
		String_Appendf( &m_codeTests, "\t%s halves[4] = { %s, %s, %s, %s };\n", m_memberTypeString, halfStr, halfStr, halfStr, halfStr );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s in;\n", inputDataName );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\tin.lhs = %s( ones );\n", loadFuncStr );
		String_Appendf( &m_codeTests, "\tin.rhs = %s( threes );\n", loadFuncStr );
		String_Appendf( &m_codeTests, "\tin.t   = %s( halves );\n", loadFuncStr );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s results;\n", m_registerName );
		String_Append(  &m_codeTests, "\tlerp_sse( in, &results );\n" );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s lerpResults[4];\n", m_memberTypeString );
		String_Appendf( &m_codeTests, "\t%s( lerpResults, results );\n", storeFuncStr );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( lerpResults[0], %s ) );\n", floateqStr, answerStr );
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( lerpResults[1], %s ) );\n", floateqStr, answerStr );
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( lerpResults[2], %s ) );\n", floateqStr, answerStr );
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( lerpResults[3], %s ) );\n", floateqStr, answerStr );
	}

	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}
