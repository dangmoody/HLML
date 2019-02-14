#include "TestsGenerator.h"

#include "FileIO.h"

void TestsGenerator::Generate( const genType_t type, const uint32_t numRows, const uint32_t numCols ) {
	m_code = std::string();

	m_type = type;

	m_numRows = numRows;
	m_numCols = numCols;

	m_typeString = Gen_GetTypeString( type );
	m_memberTypeString = Gen_GetMemberTypeString( type );

	m_fullTypeName = m_typeString;
	if ( numRows > 1 ) {
		m_fullTypeName += std::to_string( numRows ) + "x";
	}
	m_fullTypeName += std::to_string( numCols );

	m_testPrefix = "Test_" + m_fullTypeName;

	m_code += GEN_COPYRIGHT_HEADER;
	m_code += "\n";
	m_code += GEN_GENERATED_WARNING;
	m_code += "\n";

	m_code += "#include <temper.h>\n";
	m_code += "\n";

//	m_code += "#include \"suites.h\"\n";
//	m_code += "\n";

	GenerateTestAssignment();

	GenerateTestArithmetic();

	GenerateTestArray();

	GenerateTestEquality();

	GenerateTestRelational();

	GenerateTestLength();

	GenerateTestNormalized();

	GenerateTestDot();

	GenerateTestCross();

	GenerateTestAngle();

	m_code += "TEMPER_SUITE( " + m_testPrefix + " ) {\n";
	m_code += "\tTEMPER_RUN_TEST( TestAssignment_" + m_fullTypeName + " );\n";
	m_code += "\tTEMPER_RUN_TEST( TestArithmetic_" + m_fullTypeName + " );\n";
	m_code += "\tTEMPER_RUN_TEST( TestArray_" + m_fullTypeName + " );\n";
	m_code += "\tTEMPER_RUN_TEST( TestEquality_" + m_fullTypeName + " );\n";
	m_code += "\tTEMPER_RUN_TEST( TestRelational_" + m_fullTypeName + " );\n";
	m_code += "\n";
	m_code += "\tTEMPER_RUN_TEST( TestLength_" + m_fullTypeName + " );\n";
	m_code += "\tTEMPER_RUN_TEST( TestNormalized_" + m_fullTypeName + " );\n";
	m_code += "\tTEMPER_RUN_TEST( TestDot_" + m_fullTypeName + " );\n";
	m_code += "\tTEMPER_RUN_TEST( TestCross_" + m_fullTypeName + " );\n";
	m_code += "\tTEMPER_RUN_TEST( TestAngle_" + m_fullTypeName + " );\n";
	m_code += "};\n";

	char filename[1024] = { 0 };
	snprintf( filename, 1024, "%stest_%s.cpp", GEN_TESTS_FOLDER_PATH, m_fullTypeName.c_str() );

	if ( !FS_WriteToFile( filename, m_code.c_str(), m_code.size() ) ) {
		printf( "Can't generate test suite for %s.  That's rough man.\n", m_fullTypeName.c_str() );
	}
}

void TestsGenerator::GenerateTestAssignment() {
	m_code += "TEMPER_TEST( TestAssignment_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGenerator::GenerateTestArithmetic() {
	m_code += "TEMPER_TEST( TestArithmetic_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGenerator::GenerateTestArray() {
	m_code += "TEMPER_TEST( TestArray_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGenerator::GenerateTestEquality() {
	m_code += "TEMPER_TEST( TestEquality_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGenerator::GenerateTestRelational() {
	m_code += "TEMPER_TEST( TestRelational_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGenerator::GenerateTestLength() {
	m_code += "TEMPER_TEST( TestLength_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGenerator::GenerateTestNormalized() {
	m_code += "TEMPER_TEST( TestNormalized_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGenerator::GenerateTestDot() {
	m_code += "TEMPER_TEST( TestDot_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGenerator::GenerateTestCross() {
	m_code += "TEMPER_TEST( TestCross_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGenerator::GenerateTestAngle() {
	m_code += "TEMPER_TEST( TestAngle_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}