#include "GeneratorVectorTests.h"

#include "allocator.h"

#include "FileIO.h"

#include "gen_funcs_vector.h"

bool GeneratorVectorTests::Generate( const genType_t type, const u32 numComponents ) {
	const u32 testsCodeBytes = 12 * KB_TO_BYTES;
	const u32 suiteCodeBytes = 4 * KB_TO_BYTES;

	m_codeTests = String_Create( testsCodeBytes );
	m_codeSuite = String_Create( suiteCodeBytes );

	m_type = type;

	m_numComponents = numComponents;

	m_typeString = Gen_GetTypeString( type );
	m_memberTypeString = Gen_GetMemberTypeString( type );

	sprintf( m_fullTypeName, "%s%d", m_typeString, numComponents );

	stringBuilder_t code = String_Create( 10 * KB_TO_BYTES );

	String_Appendf( &code, GEN_FILE_HEADER );

	String_Append( &code, "#include \"../../" GEN_OUT_GEN_FOLDER_PATH GEN_FILENAME_FUNCTIONS_VECTOR ".h\"\n" );
	String_Append( &code, "\n" );

	String_Append( &code, "#include <temper/temper.h>\n" );
	String_Append( &code, "\n" );

	String_Appendf( &m_codeSuite, "TEMPER_SUITE( Test_%s )\n", m_fullTypeName );
	String_Append(  &m_codeSuite, "{\n" );

	GenerateTestAssignment();

	GenerateTestArray();

	GenerateTestArithmetic();

	GenerateTestIncrement();

	GenerateTestRelational();

	GenerateTestBitwise();

	GenerateTestLength();

	GenerateTestNormalized();

	GenerateTestDot();

	GenerateTestCross();

	GenerateTestAngle();

	GenerateTestDistance();

	GenerateTestSaturate();

	GenerateTestLerp();

	GenerateTestSmoothstep();

	GenerateTestPacking();

	String_Append( &m_codeSuite, "}\n" );

	String_Append( &code, m_codeTests.str );
	String_Append( &code, m_codeSuite.str );

	char filename[1024] = { 0 };
	snprintf( filename, 1024, "%stest_%s.cpp", GEN_TESTS_FOLDER_PATH, m_fullTypeName );

	bool32 result = FS_WriteEntireFile( filename, code.str, code.length );

	if ( !result ) {
		printf( "Can't generate test suite for %s.  That's rough man.\n", m_fullTypeName );
	}

	Mem_Reset();

	return result;
}

void GeneratorVectorTests::GenerateTestAssignment() {
	char testName[32] = { 0 };
	snprintf( testName, 32, "TestAssignment_%s", m_fullTypeName );

	char oneStr[16];
	Gen_GetNumericLiteral( m_type, 1, oneStr );

	float values[] = { 0.0f, 1.0f, 2.0f, 3.0f };

	char parmListVarying[64] = { 0 };
	Gen_GetParmListVector( m_type, m_numComponents, values, parmListVarying );

	String_Append(  &m_codeTests, "// also tests equality operators\n" );
	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s a;\n", m_fullTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\ta = %s( %s );\n", m_fullTypeName, oneStr );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( a == %s( %s ) );\n", m_fullTypeName, oneStr );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( a != %s%s );\n", m_fullTypeName, parmListVarying );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\ta = %s%s;\n", m_fullTypeName, parmListVarying );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( a == %s%s );\n", m_fullTypeName, parmListVarying );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( a != %s( %s ) );\n", m_fullTypeName, oneStr );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorVectorTests::GenerateTestArray() {
	char testName[32] = { 0 };
	snprintf( testName, 32, "TestArray_%s", m_fullTypeName );

	float values[] = { 0.0f, 1.0f, 2.0f, 3.0f };

	char parmList[64];
	Gen_GetParmListVector( m_type, m_numComponents, values, parmList );

	char valuesStr[4][16];
	Gen_GetNumericLiteral( m_type, 0, valuesStr[0] );
	Gen_GetNumericLiteral( m_type, 1, valuesStr[1] );
	Gen_GetNumericLiteral( m_type, 2, valuesStr[2] );
	Gen_GetNumericLiteral( m_type, 3, valuesStr[3] );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s a = %s%s;\n", m_fullTypeName, m_fullTypeName, parmList );
	String_Append(  &m_codeTests, "\n" );
	for ( u32 i = 0; i < m_numComponents; i++ ) {
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( a[%d] == %s );\n", i, valuesStr[i] );
	}
	String_Append( &m_codeTests, "\n" );
	String_Append( &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append( &m_codeTests, "}\n" );
	String_Append( &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorVectorTests::GenerateTestArithmetic() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	// number picked at random
	char baseNumberStr[16];
	Gen_GetNumericLiteral( m_type, 6, baseNumberStr );

	float valuesAdd[]	= { 2.0f,  3.0f,  4.0f,  5.0f  };
	float valuesSub[]	= { 2.0f,  3.0f,  4.0f,  5.0f  };
	float valuesMul[]	= { 2.0f,  3.0f,  4.0f,  5.0f  };
	float valuesDiv[]	= { 2.0f,  2.0f,  3.0f,  6.0f  };

	float answersAdd[]	= { 8.0f,  9.0f,  10.0f, 11.0f };
	float answersSub[]	= { 4.0f,  3.0f,  2.0f,  1.0f  };
	float answersMul[]	= { 12.0f, 18.0f, 24.0f, 30.0f };
	float answersDiv[]	= { 3.0f,  3.0f,  2.0f,  1.0f  };

	char parmListValues[4][256];
	Gen_GetParmListVector( m_type, m_numComponents, valuesAdd, parmListValues[0] );
	Gen_GetParmListVector( m_type, m_numComponents, valuesSub, parmListValues[1] );
	Gen_GetParmListVector( m_type, m_numComponents, valuesMul, parmListValues[2] );
	Gen_GetParmListVector( m_type, m_numComponents, valuesDiv, parmListValues[3] );

	char parmListAnswers[4][256];
	Gen_GetParmListVector( m_type, m_numComponents, answersAdd, parmListAnswers[0] );
	Gen_GetParmListVector( m_type, m_numComponents, answersSub, parmListAnswers[1] );
	Gen_GetParmListVector( m_type, m_numComponents, answersMul, parmListAnswers[2] );
	Gen_GetParmListVector( m_type, m_numComponents, answersDiv, parmListAnswers[3] );

	const char* suffices[GEN_OP_ARITHMETIC_COUNT] = {
		"Addition",
		"Subtraction",
		"Multiplication",
		"Division",
	};

	for ( u32 i = 0; i < GEN_OP_ARITHMETIC_COUNT; i++ ) {
		char testName[64] = { 0 };
		snprintf( testName, 64, "TestArithmetic%s_%s", suffices[i], m_fullTypeName );

		String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  &m_codeTests, "{\n" );
		String_Appendf( &m_codeTests, "\t%s a = %s( %s );\n", m_fullTypeName, m_fullTypeName, baseNumberStr );
		String_Appendf( &m_codeTests, "\t%s b = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListValues[i] );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s c = a %c b;\n", m_fullTypeName, GEN_OPERATORS_ARITHMETIC[i] );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( c == %s%s );\n", m_fullTypeName, parmListAnswers[i] );
		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  &m_codeTests, "}\n" );
		String_Append(  &m_codeTests, "\n" );

		String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

void GeneratorVectorTests::GenerateTestIncrement() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	float values0[] = { 0.0f, 0.0f, 0.0f, 0.0f };
	float values1[] = { 1.0f, 1.0f, 1.0f, 1.0f };

	char parmListVecs[2][256];
	Gen_GetParmListVector( m_type, m_numComponents, values0, parmListVecs[0] );
	Gen_GetParmListVector( m_type, m_numComponents, values1, parmListVecs[1] );

	char parmListAnswers[2][256];
	Gen_GetParmListVector( m_type, m_numComponents, values1, parmListAnswers[0] );
	Gen_GetParmListVector( m_type, m_numComponents, values0, parmListAnswers[1] );

	const char* suffices[GEN_OP_INCREMENT_COUNT] = {
		"Increment",
		"Decrement",
	};

	for ( u32 i = 0; i < GEN_OP_INCREMENT_COUNT; i++ ) {
		char testName[32] = { 0 };
		snprintf( testName, 32, "Test%s_%s", suffices[i], m_fullTypeName );

		String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  &m_codeTests, "{\n" );
		String_Appendf( &m_codeTests, "\t%s vec;\n", m_fullTypeName );
		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\t// prefix\n" );
		String_Appendf( &m_codeTests, "\tvec = %s%s;\n", m_fullTypeName, parmListVecs[i] );
		String_Appendf( &m_codeTests, "\t%svec;\n", GEN_OPERATORS_INCREMENT[i] );
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( vec == %s%s );\n", m_fullTypeName, parmListAnswers[i] );
		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\t// postfix\n" );
		String_Appendf( &m_codeTests, "\tvec = %s%s;\n", m_fullTypeName, parmListVecs[i] );
		String_Appendf( &m_codeTests, "\tvec%s;\n", GEN_OPERATORS_INCREMENT[i] );
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( vec == %s%s );\n", m_fullTypeName, parmListAnswers[i] );
		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  &m_codeTests, "}\n" );
		String_Append(  &m_codeTests, "\n" );

		String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

void GeneratorVectorTests::GenerateTestRelational() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	char testName[32] = { 0 };
	snprintf( testName, 32, "TestRelational_%s", m_fullTypeName );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );

	char boolTypeName[6];
	snprintf( boolTypeName, 6, "bool%d", m_numComponents );

	char zeroStr[16];
	char oneStr[16];
	char twoStr[16];
	char threeStr[16];

	Gen_GetNumericLiteral( m_type, 0, zeroStr );
	Gen_GetNumericLiteral( m_type, 1, oneStr );
	Gen_GetNumericLiteral( m_type, 2, twoStr );
	Gen_GetNumericLiteral( m_type, 3, threeStr );

	char parmLists[4][64];
	snprintf( parmLists[0], 64, "( %s )", zeroStr );
	snprintf( parmLists[1], 64, "( %s )", oneStr );
	snprintf( parmLists[2], 64, "( %s )", twoStr );
	snprintf( parmLists[3], 64, "( %s )", threeStr );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s allTrue = %s( true );\n", boolTypeName, boolTypeName );
	String_Append(  &m_codeTests, "\n" );
	for ( u32 i = 0; i < 4; i++ ) {
		String_Appendf( &m_codeTests, "\t%s vec%d = %s%s;\n", m_fullTypeName, i, m_fullTypeName, parmLists[i] );
	}
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s test0  = vec0 <= vec0;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test1  = vec0 >= vec0;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test2  = vec0 <  vec1;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test3  = vec0 <  vec2;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test4  = vec0 <  vec3;\n", boolTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s test5  = vec1 >  vec0;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test6  = vec1 <= vec1;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test7  = vec1 >= vec1;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test8  = vec1 <  vec2;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test9  = vec1 <  vec3;\n", boolTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s test10 = vec2 >  vec0;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test11 = vec2 >  vec1;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test12 = vec2 <= vec2;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test13 = vec2 >= vec2;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test14 = vec2 <  vec3;\n", boolTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s test15 = vec3 >  vec0;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test16 = vec3 >  vec1;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test17 = vec3 >  vec2;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test18 = vec3 <= vec3;\n", boolTypeName );
	String_Appendf( &m_codeTests, "\t%s test19 = vec3 >= vec3;\n", boolTypeName );
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

void GeneratorVectorTests::GenerateTestBitwise() {
	if ( !Gen_IsIntegerType( m_type ) ) {
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
	snprintf( parmListAnswerUnary, 32, "(%s) -1", m_memberTypeString );

	// -1 to exclude unary, which is done separately because it takes no rhs parm
	char parmListLhs[GEN_OP_BITWISE_COUNT - 1][64];
	Gen_GetParmListVector( m_type, m_numComponents, values21, parmListLhs[0] );
	Gen_GetParmListVector( m_type, m_numComponents, values21, parmListLhs[1] );
	Gen_GetParmListVector( m_type, m_numComponents, values21, parmListLhs[2] );
	Gen_GetParmListVector( m_type, m_numComponents, values1 , parmListLhs[3] );
	Gen_GetParmListVector( m_type, m_numComponents, values16, parmListLhs[4] );

	char parmListRhs[GEN_OP_BITWISE_COUNT - 1][64];
	Gen_GetParmListVector( m_type, m_numComponents, values7, parmListRhs[0] );
	Gen_GetParmListVector( m_type, m_numComponents, values7, parmListRhs[1] );
	Gen_GetParmListVector( m_type, m_numComponents, values7, parmListRhs[2] );
	Gen_GetParmListVector( m_type, m_numComponents, values2, parmListRhs[3] );
	Gen_GetParmListVector( m_type, m_numComponents, values4, parmListRhs[4] );

	char parmListAnswers[GEN_OP_BITWISE_COUNT - 1][64];
	Gen_GetParmListVector( m_type, m_numComponents, answersAnd, parmListAnswers[0] );
	Gen_GetParmListVector( m_type, m_numComponents, answersOr, parmListAnswers[1] );
	Gen_GetParmListVector( m_type, m_numComponents, answersXor, parmListAnswers[2] );
	Gen_GetParmListVector( m_type, m_numComponents, answersShiftLeft, parmListAnswers[3] );
	Gen_GetParmListVector( m_type, m_numComponents, answersShiftRight, parmListAnswers[4] );

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
		snprintf( testName, 64, "TestBitwiseUnary_%s", m_fullTypeName );

		char parmList[128];
		Gen_GetParmListVector( m_type, m_numComponents, values0, parmList );

		String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
		String_Append(  &m_codeTests, "{\n" );
		String_Appendf( &m_codeTests, "\t%s a = %s%s;\n", m_fullTypeName, m_fullTypeName, parmList );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\t%s answer = %sa;\n", m_fullTypeName, GEN_OPERATORS_BITWISE[GEN_OP_BITWISE_UNARY] );
		String_Append(  &m_codeTests, "\n" );
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( answer == %s( %s ) );\n", m_fullTypeName, parmListAnswerUnary );
		String_Append(  &m_codeTests, "\n" );
		String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
		String_Append(  &m_codeTests, "}\n" );
		String_Append(  &m_codeTests, "\n" );

		String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
	}
}

void GeneratorVectorTests::GenerateTestLength() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	char testName[32] = { 0 };
	snprintf( testName, 32, "TestLength_%s", m_fullTypeName );

	char twoStr[16];
	Gen_GetNumericLiteral( m_type, 2, twoStr );

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

	const char* squaredLengthStr	= squaredLengths[m_numComponents - 2];
	const char* lengthStr			= lengths[m_numComponents - 2];

	const char* floateqStr = Gen_GetFuncNameFloateq( m_type );
	const char* fSpecifier = ( m_type != GEN_TYPE_DOUBLE ) ? "f" : "";

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s vec = %s( %s );\n", m_fullTypeName, m_fullTypeName, twoStr );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( lengthsqr( vec ), %s%s ) );\n", floateqStr, squaredLengthStr, fSpecifier );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( length( vec ), %s%s ) );\n", floateqStr, lengthStr, fSpecifier );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorVectorTests::GenerateTestNormalized() {
	if ( m_type != GEN_TYPE_FLOAT && m_type != GEN_TYPE_DOUBLE ) {
		return;
	}

	char testName[32] = { 0 };
	snprintf( testName, 32, "TestNormalized_%s", m_fullTypeName );

	float values[] = { 2.0f, 3.0f, 4.0f, 5.0f };

	char parmList[32] = { 0 };
	Gen_GetParmListVector( m_type, m_numComponents, values, parmList );

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( m_type );

	char oneStr[16];
	Gen_GetNumericLiteral( floatingPointType, 1, oneStr );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s vec = %s%s;\n", m_fullTypeName, m_fullTypeName, parmList );
	String_Append(  &m_codeTests, "\tvec = normalized( vec );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( length( vec ) == %s );\n", oneStr );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorVectorTests::GenerateTestDot() {
	if ( m_type == GEN_TYPE_BOOL || m_type == GEN_TYPE_UINT ) {
		return;
	}

	char testName[64];
	snprintf( testName, 64, "TestDot_%s", m_fullTypeName );

	genType_t dotReturnType = ( m_type == GEN_TYPE_UINT ) ? GEN_TYPE_INT : m_type;

	char minusOneStrDotAnswer[16];
	Gen_GetNumericLiteral( dotReturnType, -1, minusOneStrDotAnswer );

	char minusOneStr[16];
	char zeroStr[16];
	char oneStr[16];

	Gen_GetNumericLiteral( m_type, -1, minusOneStr );
	Gen_GetNumericLiteral( m_type,  0, zeroStr );
	Gen_GetNumericLiteral( m_type,  1, oneStr );

	float valuesA[4] = { 0.0f,  1.0f, 0.0f, 0.0f };
	float valuesB[4] = { 0.0f, -1.0f, 0.0f, 0.0f };

	char parmListA[64] = { 0 };
	char parmListB[64] = { 0 };

	Gen_GetParmListVector( m_type, m_numComponents, valuesA, parmListA );
	Gen_GetParmListVector( m_type, m_numComponents, valuesB, parmListB );

	const char* floateqStr = Gen_GetFuncNameFloateq( m_type );

	String_Appendf( &m_codeTests, "TEMPER_TEST( TestDot_%s )\n", m_fullTypeName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s a = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListA );
	String_Appendf( &m_codeTests, "\t%s b = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListB );
	String_Append(  &m_codeTests, "\n" );
	if ( Gen_IsFloatingPointType( m_type ) ) {
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( dot( a, b ), %s ) );\n", floateqStr, minusOneStrDotAnswer );
	} else {
		String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( dot( a, b ) == %s );\n", minusOneStrDotAnswer );
	}
	String_Append( &m_codeTests, "\n" );
	String_Append( &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append( &m_codeTests, "}\n" );
	String_Append( &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorVectorTests::GenerateTestCross() {
	if ( m_type != GEN_TYPE_FLOAT && m_type != GEN_TYPE_DOUBLE ) {
		return;
	}

	char testName[32] = { 0 };
	snprintf( testName, 32, "TestCross_%s", m_fullTypeName );

	if ( m_numComponents < 3 ) {
		return;
	}

	float left[]	= { -1.0f, 0.0f, 0.0f, 0.0f };
	float up[]		= {  0.0f, 1.0f, 0.0f, 0.0f };
	float forward[]	= {  0.0f, 0.0f, 1.0f, 0.0f };

	char parmListLeft[64]		= { 0 };
	char parmListUp[64]			= { 0 };
	char parmListForward[64]	= { 0 };

	Gen_GetParmListVector( m_type, m_numComponents, left, parmListLeft );
	Gen_GetParmListVector( m_type, m_numComponents, up, parmListUp );
	Gen_GetParmListVector( m_type, m_numComponents, forward, parmListForward );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Appendf( &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s left = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListLeft );
	String_Appendf( &m_codeTests, "\t%s forward = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListForward );
	String_Appendf( &m_codeTests, "\t%s up = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListUp );
	String_Appendf( &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( cross( left, forward ) == up );\n" );
	String_Appendf( &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Appendf( &m_codeTests, "}\n" );
	String_Appendf( &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorVectorTests::GenerateTestAngle() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	char testName[32] = { 0 };
	snprintf( testName, 32, "TestAngle_%s", m_fullTypeName );

	float right[]	= { 1.0f, 0.0f, 0.0f, 0.0f };
	float up[]		= { 0.0f, 1.0f, 0.0f, 0.0f };

	char parmListRight[128]	= { 0 };
	char parmListUp[128]	= { 0 };

	Gen_GetParmListVector( m_type, m_numComponents, right, parmListRight );
	Gen_GetParmListVector( m_type, m_numComponents, up, parmListUp );

	const genType_t floatingPointType = Gen_GetSupportedFloatingPointType( m_type );

	char ninetyStr[16];
	Gen_GetNumericLiteral( floatingPointType, 90, ninetyStr );

	const char* floateqStr = Gen_GetFuncNameFloateq( m_type );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s right = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListRight );
	String_Appendf( &m_codeTests, "\t%s up =    %s%s;\n", m_fullTypeName, m_fullTypeName, parmListUp );
	String_Appendf( &m_codeTests, "\t%s answer = angle( up, right );\n", m_typeString );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( answer, %s ) );\n", floateqStr, ninetyStr );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorVectorTests::GenerateTestDistance() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	if ( m_numComponents > 3 ) {
		return;
	}

	char testName[32] = { 0 };
	snprintf( testName, 32, "TestDistance_%s", m_fullTypeName );

	genType_t floatingPointType = Gen_GetSupportedFloatingPointType( m_type );
	const char* floatingPointStr = Gen_GetTypeString( floatingPointType );

	// numbers picked at random
	// default w to 0 because distance isn't allowed for 4d vectors
	float values0[] = { 7.0f,  4.0f, 3.0f, 0.0f };
	float values1[] = { 17.0f, 6.0f, 2.0f, 0.0f };

	char answerDistanceSqrStr[16];
	char answerDistanceStr[16];

	switch ( m_numComponents ) {
		case 2:
			Gen_GetNumericLiteral( floatingPointType, 104.0f, answerDistanceSqrStr );
			Gen_GetNumericLiteral( floatingPointType, 10.198039f, answerDistanceStr );
			break;

		case 3:
			Gen_GetNumericLiteral( floatingPointType, 105.0f, answerDistanceSqrStr );
			Gen_GetNumericLiteral( floatingPointType, 10.246951f, answerDistanceStr );
			break;
	}

	char parmList0[64];
	char parmList1[64];

	Gen_GetParmListVector( m_type, m_numComponents, values0, parmList0 );
	Gen_GetParmListVector( m_type, m_numComponents, values1, parmList1 );

	const char* floateqStr = Gen_GetFuncNameFloateq( m_type );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s answerDistanceSqr = %s;\n", floatingPointStr, answerDistanceSqrStr );
	String_Appendf( &m_codeTests, "\t%s answerDistance    = %s;\n", floatingPointStr, answerDistanceStr );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s a = %s%s;\n", m_fullTypeName, m_fullTypeName, parmList0 );
	String_Appendf( &m_codeTests, "\t%s b = %s%s;\n", m_fullTypeName, m_fullTypeName, parmList1 );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s distSqr = distancesqr( a, b );\n", floatingPointStr );
	String_Appendf( &m_codeTests, "\t%s dist    = distance( a, b );\n", floatingPointStr );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( distSqr, answerDistanceSqr ) );\n", floateqStr );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( %s( dist, answerDistance ) );\n", floateqStr );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorVectorTests::GenerateTestPacking() {
	if ( m_type != GEN_TYPE_UINT ) {
		return;
	}

	if ( m_numComponents != 4 ) {
		return;
	}

	char testName[64] = { 0 };
	snprintf( testName, 64, "TestPacking_%s", m_fullTypeName );

	float values[] = { 255, 255, 0, 255 };	// magenta

	char parmListAnswerUnpacked[16] = { 0 };
	Gen_GetParmListVector( m_type, m_numComponents, values, parmListAnswerUnpacked );

	const char* answerPackedStr = "0xFFFF00FF";

	// tests pack and unpack
	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s answerPacked = %s;\n", m_memberTypeString, answerPackedStr );
	String_Appendf( &m_codeTests, "\t%s answerUnpacked = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListAnswerUnpacked );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s vec = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListAnswerUnpacked );	// we can use the same parm list here, it's fine
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s packed = pack( vec );\n", m_memberTypeString );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( packed == answerPacked );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s unpacked = unpack( packed );\n", m_fullTypeName );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( unpacked == answerUnpacked );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorVectorTests::GenerateTestSaturate() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	char testName[32] = { 0 };
	snprintf( testName, 32, "TestSaturate_%s", m_fullTypeName );

	float values[]			= { -1.0f, 2.0f, 4.0f, 6.0f };
	float valuesAnswer[]	= {  0.0f, 1.0f, 1.0f, 1.0f };

	char parmList[64]		= { 0 };
	char parmListAnswer[64]	= { 0 };

	Gen_GetParmListVector( m_type, m_numComponents, values, parmList );
	Gen_GetParmListVector( m_type, m_numComponents, valuesAnswer, parmListAnswer );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s answer = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListAnswer );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s vec = %s%s;\n", m_fullTypeName, m_fullTypeName, parmList );
	String_Appendf( &m_codeTests, "\t%s clamped = saturate( vec );\n", m_fullTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tTEMPER_EXPECT_TRUE( clamped == answer );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorVectorTests::GenerateTestLerp() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	char testName[32] = { 0 };
	snprintf( testName, 32, "TestLerp_%s", m_fullTypeName );

	float valuesA[]			= { 0.0f, 1.0f, 0.0f, 0.0f };
	float valuesB[]			= { 1.0f, 0.0f, 0.0f, 0.0f };
	float valuesAnswer[]	= { 0.5f, 0.5f, 0.0f, 0.0f };

	char parmListA[128]			= { 0 };
	char parmListB[128]			= { 0 };
	char parmListAnswer[128]	= { 0 };

	Gen_GetParmListVector( m_type, m_numComponents, valuesA, parmListA );
	Gen_GetParmListVector( m_type, m_numComponents, valuesB, parmListB );
	Gen_GetParmListVector( m_type, m_numComponents, valuesAnswer, parmListAnswer );

	char lerpValStr[16];
	Gen_GetNumericLiteral( m_type, 0.5, lerpValStr );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s answer = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListAnswer );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s a = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListA );
	String_Appendf( &m_codeTests, "\t%s b = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListB );
	String_Appendf( &m_codeTests, "\t%s lerped = lerp( a, b, %s );\n", m_fullTypeName, lerpValStr );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( lerped == answer );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}

void GeneratorVectorTests::GenerateTestSmoothstep() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	char testName[32] = { 0 };
	snprintf( testName, 32, "TestSmoothstep_%s", m_fullTypeName );

	float valuesLow[]						= { 0.0f, 0.0f, 0.0f, 0.0f };
	float valuesHigh[]						= { 1.0f, 1.0f, 1.0f, 1.0f };

	float valuesInput0[]					= { 0.2f, 0.2f, 0.2f, 0.2f };
	float valuesInput1[]					= { 1.2f, 1.2f, 1.2f, 1.2f };

	float valuesAnswerInRangeSmoothstep[]	= { 0.104f, 0.104f, 0.104f, 0.104f };
	float valuesAnswerClampedSmoothstep[]	= { 1.0f,   1.0f,   1.0f,   1.0f   };

	float valuesAnswerInRangeSmootherstep[]	= { 0.057920f, 0.057920f, 0.057920f, 0.057920f };
	float valuesAnswerClampedSmootherstep[]	= { 1.0f,      1.0f,      1.0f,      1.0f      };

	char parmListLow[128]						= { 0 };
	char parmListHigh[128]						= { 0 };

	char parmListInput0[128]					= { 0 };
	char parmListInput1[128]					= { 0 };

	char parmListAnswerInRangeSmoothstep[128]	= { 0 };
	char parmListAnswerClampedSmoothstep[128]	= { 0 };

	char parmListAnswerInRangeSmootherstep[128]	= { 0 };
	char parmListAnswerClampedSmootherstep[128]	= { 0 };

	Gen_GetParmListVector( m_type, m_numComponents, valuesLow, parmListLow );
	Gen_GetParmListVector( m_type, m_numComponents, valuesHigh, parmListHigh );

	Gen_GetParmListVector( m_type, m_numComponents, valuesInput0, parmListInput0 );
	Gen_GetParmListVector( m_type, m_numComponents, valuesInput1, parmListInput1 );

	Gen_GetParmListVector( m_type, m_numComponents, valuesAnswerInRangeSmoothstep, parmListAnswerInRangeSmoothstep );
	Gen_GetParmListVector( m_type, m_numComponents, valuesAnswerClampedSmoothstep, parmListAnswerClampedSmoothstep );

	Gen_GetParmListVector( m_type, m_numComponents, valuesAnswerInRangeSmootherstep, parmListAnswerInRangeSmootherstep );
	Gen_GetParmListVector( m_type, m_numComponents, valuesAnswerClampedSmootherstep, parmListAnswerClampedSmootherstep );

	String_Appendf( &m_codeTests, "TEMPER_TEST( %s )\n", testName );
	String_Append(  &m_codeTests, "{\n" );
	String_Appendf( &m_codeTests, "\t%s answerInRangeSmoothstep   = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListAnswerInRangeSmoothstep );
	String_Appendf( &m_codeTests, "\t%s answerClampedSmoothstep   = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListAnswerClampedSmoothstep );
	String_Appendf( &m_codeTests, "\t%s answerInRangeSmootherstep = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListAnswerInRangeSmootherstep );
	String_Appendf( &m_codeTests, "\t%s answerClampedSmootherstep = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListAnswerClampedSmootherstep );
	String_Appendf( &m_codeTests, "\t%s answer;\n", m_fullTypeName );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\t%s low  = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListLow );
	String_Appendf( &m_codeTests, "\t%s high = %s%s;\n", m_fullTypeName, m_fullTypeName, parmListHigh );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tanswer = smoothstep( low, high, %s%s );\n", m_fullTypeName, parmListInput0 );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( answer == answerInRangeSmoothstep );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tanswer = smoothstep( low, high, %s%s );\n", m_fullTypeName, parmListInput1 );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( answer == answerClampedSmoothstep );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tanswer = smootherstep( low, high, %s%s );\n", m_fullTypeName, parmListInput0 );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( answer == answerInRangeSmootherstep );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Appendf( &m_codeTests, "\tanswer = smootherstep( low, high, %s%s );\n", m_fullTypeName, parmListInput1 );
	String_Append(  &m_codeTests, "\tTEMPER_EXPECT_TRUE( answer == answerClampedSmootherstep );\n" );
	String_Append(  &m_codeTests, "\n" );
	String_Append(  &m_codeTests, "\tTEMPER_PASS();\n" );
	String_Append(  &m_codeTests, "}\n" );
	String_Append(  &m_codeTests, "\n" );

	String_Appendf( &m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName );
}
