#include "GeneratorScalarTests.h"

#include "FileIO.h"

/*
========================
GeneratorTestsScalar::Generate
========================
*/
bool GeneratorScalarTest::Generate( const genType_t type ) {
	m_codeTests = std::string();
	m_codeSuite = std::string();

	m_type = type;

	m_memberTypeString = Gen_GetMemberTypeString( type );

	std::string code = GEN_FILE_HEADER;

	code += "#define " GEN_DEFINE_UNDEF_SYSTEM_MIN_MAX "\n";
	code += std::string( "#include \"../../" ) + GEN_OUT_GEN_FOLDER_PATH + GEN_FILENAME_FUNCTIONS_SCALAR + ".h\"\n";
	code += "\n";

	code += "#include <temper/temper.h>\n";
	code += "\n";

	m_codeSuite += "TEMPER_SUITE( Test_" + m_memberTypeString + " )\n";
	m_codeSuite += "{\n";

	GenerateTestFloateq();

	GenerateTestSign();

	GenerateTestDegreesRadians();

	GenerateTestMinMax();

	GenerateTestClamp();

	GenerateTestSaturate();

	m_codeSuite += "}\n";

	code += m_codeTests;
	code += m_codeSuite;

	char filename[1024] = { 0 };
	sprintf( filename, "%stest_scalar_%s.cpp", GEN_TESTS_FOLDER_PATH, m_memberTypeString.c_str() );

	if ( !FS_WriteEntireFile( filename, code.c_str(), code.size() ) ) {
		printf( "Can't generate scalar test suite for %s.  That's rough man.\n", m_memberTypeString.c_str() );
		return false;
	}

	return true;
}

/*
========================
GeneratorTestsScalar::GenerateTestFloateq
========================
*/
void GeneratorScalarTest::GenerateTestFloateq() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	std::string testName = "TestFloateq_" + m_memberTypeString;

	float a = 5.0f;
	float b = 5.0f;
	float c = 5.00002f;
	float d = 5.0001f;

	std::string floateqStr = Gen_GetFuncNameFloateq( m_type );

	m_codeTests += "TEMPER_TEST( " + testName + " )\n";
	m_codeTests += "{\n";
	m_codeTests += "\t" + m_memberTypeString + " a =  " + Gen_GetNumericLiteral( m_type, a ) + ";\n";
	m_codeTests += "\t" + m_memberTypeString + " b =  " + Gen_GetNumericLiteral( m_type, b ) + ";\n";
	m_codeTests += "\t" + m_memberTypeString + " c =  " + Gen_GetNumericLiteral( m_type, c ) + ";\n";
	m_codeTests += "\t" + m_memberTypeString + " d =  " + Gen_GetNumericLiteral( m_type, d ) + ";\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( " + floateqStr + "( a, b ) );\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( !" + floateqStr + "( a, c ) );\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( !" + floateqStr + "( a, d ) );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";

	m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
}

/*
========================
GeneratorTestsScalar::GenerateTestSign
========================
*/
void GeneratorScalarTest::GenerateTestSign() {
	if ( m_type == GEN_TYPE_BOOL || m_type == GEN_TYPE_UINT ) {
		return;
	}

	std::string testName = "TestSign_" + m_memberTypeString;

	std::string valueSignedStr		= Gen_GetNumericLiteral( m_type, -5.0f );
	std::string valueUnsignedStr	= Gen_GetNumericLiteral( m_type,  9.0f );

	m_codeTests += "TEMPER_TEST( " + testName + " )\n";
	m_codeTests += "{\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( sign( " + valueSignedStr + " ) == -1 );\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( sign( " + valueUnsignedStr + " ) == 1 );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";

	m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
}

/*
========================
GeneratorTestsScalar::GenerateTestRadians
========================
*/
void GeneratorScalarTest::GenerateTestDegreesRadians() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	std::string testName = "TestDegreesRadians_" + m_memberTypeString;

	float degrees = 90.0f;

	std::string degreesStr = Gen_GetNumericLiteral( m_type, degrees );

	// DM: must be done this way to avoid floating-point imprecision
	std::string radiansStr = "1.57079637";
	if ( m_type == GEN_TYPE_FLOAT ) {
		radiansStr += "f";
	}

	std::string floateqStr = Gen_GetFuncNameFloateq( m_type );

	m_codeTests += "TEMPER_TEST( " + testName + " )\n";
	m_codeTests += "{\n";
	m_codeTests += "\t" + m_memberTypeString + " deg = " + degreesStr + ";\n";
	m_codeTests += "\t" + m_memberTypeString + " rad = " + radiansStr + ";\n";
	m_codeTests += "\n";
	m_codeTests += "\t" + m_memberTypeString + " answerRadians = radians( deg );\n";
	m_codeTests += "\t" + m_memberTypeString + " answerDegrees = degrees( rad );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( " + floateqStr + "( answerRadians, " + radiansStr + " ) );\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( " + floateqStr + "( answerDegrees, " + degreesStr + " ) );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";

	m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
}

/*
========================
GeneratorTestsScalar::GenerateTestTestMin
========================
*/
void GeneratorScalarTest::GenerateTestMinMax() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	std::string testName = "TestMinMax_" + m_memberTypeString;

	// numbers picked at random
	std::string aStr = Gen_GetNumericLiteral( m_type, 5 );
	std::string bStr = Gen_GetNumericLiteral( m_type, 9 );

	std::string floateqStr = Gen_GetFuncNameFloateq( m_type );

	m_codeTests += "TEMPER_TEST( " + testName + " )\n";
	m_codeTests += "{\n";
	m_codeTests += "\t" + m_memberTypeString + " a = " + aStr + ";\n";
	m_codeTests += "\t" + m_memberTypeString + " b = " + bStr + ";\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( " + floateqStr + "( min( a, b ), a ) );\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( " + floateqStr + "( max( a, b ), b ) );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";

	m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
}

/*
========================
GeneratorTestsScalar::GenerateTestClamp
========================
*/
void GeneratorScalarTest::GenerateTestClamp() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	std::string testName = "TestClamp_" + m_memberTypeString;

	std::string zeroStr		= Gen_GetNumericLiteral( m_type, 0 );
	std::string elevenStr	= Gen_GetNumericLiteral( m_type, 11 );

	std::string lowStr		= Gen_GetNumericLiteral( m_type, 1 );
	std::string highStr		= Gen_GetNumericLiteral( m_type, 10 );

	std::string floateqStr = Gen_GetFuncNameFloateq( m_type );

	bool isFloatingPointType = Gen_IsFloatingPointType( m_type );

	m_codeTests += "TEMPER_TEST( " + testName + " )\n";
	m_codeTests += "{\n";
	m_codeTests += "\t" + m_memberTypeString + " a;\n";
	m_codeTests += "\t" + m_memberTypeString + " low  = " + lowStr + ";\n";
	m_codeTests += "\t" + m_memberTypeString + " high = " + highStr + ";\n";
	m_codeTests += "\n";
	m_codeTests += "\ta = clamp( " + zeroStr + ", low, high );\n";
	if ( isFloatingPointType ) {
		m_codeTests += "\tTEMPER_EXPECT_TRUE( " + floateqStr + "( a, low ) );\n";
	} else {
		m_codeTests += "\tTEMPER_EXPECT_TRUE( a == low );\n";
	}
	m_codeTests += "\n";
	m_codeTests += "\ta = clamp( " + elevenStr + ", low, high );\n";
		if ( isFloatingPointType ) {
		m_codeTests += "\tTEMPER_EXPECT_TRUE( " + floateqStr + "( a, high ) );\n";
	} else {
		m_codeTests += "\tTEMPER_EXPECT_TRUE( a == high );\n";
	}
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";

	m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
}

/*
========================
GeneratorTestsScalar::GenerateTestSaturate
========================
*/
void GeneratorScalarTest::GenerateTestSaturate() {
	if ( !Gen_IsFloatingPointType( m_type ) ) {
		return;
	}

	std::string testName = "TestSaturate_" + m_memberTypeString;

	std::string minusOneStr	= Gen_GetNumericLiteral( m_type, -1.0f );
	std::string zeroStr		= Gen_GetNumericLiteral( m_type,  0.0f );
	std::string oneStr		= Gen_GetNumericLiteral( m_type,  1.0f );
	std::string twoStr		= Gen_GetNumericLiteral( m_type,  2.0f );

	std::string floateqStr = Gen_GetFuncNameFloateq( m_type );

	m_codeTests += "TEMPER_TEST( " + testName + " )\n";
	m_codeTests += "{\n";
	m_codeTests += "\t" + m_memberTypeString + " a;\n";
	m_codeTests += "\n";
	m_codeTests += "\ta = saturate( " + minusOneStr + " );\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( " + floateqStr + "( a, " + zeroStr + " ) );\n";
	m_codeTests += "\n";
	m_codeTests += "\ta = saturate( " + twoStr + " );\n";
	m_codeTests += "\tTEMPER_EXPECT_TRUE( " + floateqStr + "( a, " + oneStr + " ) );\n";
	m_codeTests += "\n";
	m_codeTests += "\tTEMPER_PASS();\n";
	m_codeTests += "}\n";
	m_codeTests += "\n";

	m_codeSuite += "\tTEMPER_RUN_TEST( " + testName + " );\n";
}
