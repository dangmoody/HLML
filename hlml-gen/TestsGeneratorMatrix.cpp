#include "TestsGeneratorMatrix.h"

#include "FileIO.h"

void TestsGeneratorMatrix::Generate( const genType_t type, const uint32_t numRows, const uint32_t numCols ) {
	m_code = std::string();

	m_type = type;

	m_numRows = numRows;
	m_numCols = numCols;

	m_typeString = Gen_GetTypeString( type );
	m_memberTypeString = Gen_GetMemberTypeString( type );

	m_fullTypeName = m_typeString + std::to_string( numRows ) + "x" + std::to_string( numCols );

	m_testPrefix = "Test_" + m_fullTypeName;

	m_code += GEN_COPYRIGHT_HEADER;
	m_code += "\n";
	m_code += GEN_GENERATED_WARNING;
	m_code += "\n";

	m_code += std::string( "#include \"../" ) + GEN_OUT_GEN_FOLDER_PATH + GEN_HEADER_FUNCTIONS_MATRIX + ".h\"\n";
	m_code += "\n";

	m_code += "#include <temper.h>\n";
	m_code += "\n";

	GenerateTestAssignment();

	GenerateTestArithmetic();

	GenerateTestArray();

	GenerateTestRelational();

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

	m_code += "TEMPER_SUITE( " + m_testPrefix + " ) {\n";
	m_code += "\tTEMPER_SKIP_TEST( TestAssignment_" + m_fullTypeName + ", \"TODO\" );\n";
	if ( m_type != GEN_TYPE_BOOL ) {
		m_code += "\tTEMPER_SKIP_TEST( TestArithmetic_" + m_fullTypeName + ", \"TODO\" );\n";
	}
	m_code += "\tTEMPER_SKIP_TEST( TestArray_" + m_fullTypeName + ", \"TODO\" );\n";
	if ( m_type != GEN_TYPE_BOOL ) {
		m_code += "\tTEMPER_SKIP_TEST( TestRelational_" + m_fullTypeName + ", \"TODO\" );\n";
	}
	m_code += "\n";
	m_code += "\tTEMPER_RUN_TEST( TestIdentity_" + m_fullTypeName + " );\n";
	m_code += "\tTEMPER_SKIP_TEST( TestTranspose_" + m_fullTypeName + ", \"TODO\" );\n";
	if ( m_type != GEN_TYPE_BOOL ) {
		m_code += "\n";
		m_code += "\tTEMPER_SKIP_TEST( TestInverse_" + m_fullTypeName + ", \"TODO\" );\n";
		m_code += "\tTEMPER_SKIP_TEST( TestDeterminant_" + m_fullTypeName + ", \"TODO\" );\n";
		m_code += "\n";
		m_code += "\tTEMPER_SKIP_TEST( TestTranslate_" + m_fullTypeName + ", \"TODO\" );\n";
		m_code += "\tTEMPER_SKIP_TEST( TestRotate_" + m_fullTypeName + ", \"TODO\" );\n";
		m_code += "\tTEMPER_SKIP_TEST( TestScale_" + m_fullTypeName + ", \"TODO\" );\n";
		m_code += "\n";
		m_code += "\tTEMPER_SKIP_TEST( TestOrtho_" + m_fullTypeName + ", \"TODO\" );\n";
		m_code += "\tTEMPER_SKIP_TEST( TestPerspective_" + m_fullTypeName + ", \"TODO\" );\n";
		m_code += "\tTEMPER_SKIP_TEST( TestLookAt_" + m_fullTypeName + ", \"TODO\" );\n";
	}
	m_code += "};\n";

	char filename[1024] = { 0 };
	snprintf( filename, 1024, "%stest_%s.cpp", GEN_TESTS_FOLDER_PATH, m_fullTypeName.c_str() );

	if ( !FS_WriteToFile( filename, m_code.c_str(), m_code.size() ) ) {
		printf( "Can't generate test suite for %s.  That's rough man.\n", m_fullTypeName.c_str() );
	}
}

void TestsGeneratorMatrix::GenerateTestAssignment() {
	m_code += "TEMPER_TEST( TestAssignment_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestArithmetic() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestArithmetic_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestArray() {
	m_code += "TEMPER_TEST( TestArray_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestRelational() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestRelational_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestIdentity() {
	std::string zeroStr = Gen_GetNumericLiteral( m_type, 0 );
	std::string oneStr = Gen_GetNumericLiteral( m_type, 1 );

	std::string paramListIdentity = "(\n";
	
	for ( uint32_t row = 0; row < m_numRows; row++ ) {
		paramListIdentity += "\t\t";

		for ( uint32_t col = 0; col < m_numCols; col++ ) {
			paramListIdentity += ( row == col ) ? oneStr : zeroStr;

			if ( row + col != ( m_numRows - 1 ) + ( m_numCols - 1 ) ) {
				paramListIdentity += ",";
			}

			if ( col != m_numCols - 1 ) {
				paramListIdentity += " ";
			}
		}

		paramListIdentity += "\n";
	}
	paramListIdentity += "\t)";

	m_code += "TEMPER_TEST( TestIdentity_" + m_fullTypeName + " ) {\n";
	m_code += "\t" + m_fullTypeName + " id = " + m_fullTypeName + paramListIdentity + ";\n";
	m_code += "\n";
	m_code += "\t" + m_fullTypeName + " mat;\n";
	m_code += "\tTEMPER_EXPECT_TRUE( mat == id );\n";
	m_code += "\n";
	m_code += "\tidentity( mat );\n";
	m_code += "\tTEMPER_EXPECT_TRUE( mat == id );\n";
	m_code += "\n";
	m_code += "\tTEMPER_PASS();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestTranspose() {
	m_code += "TEMPER_TEST( TestTranspose_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestInverse() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestInverse_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestDeterminant() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestDeterminant_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestTranslate() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestTranslate_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestRotate() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestRotate_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestScale() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestScale_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestOrtho() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestOrtho_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestPerspective() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestPerspective_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}

void TestsGeneratorMatrix::GenerateTestLookAt() {
	if ( m_type == GEN_TYPE_BOOL ) {
		return;
	}

	m_code += "TEMPER_TEST( TestLookAt_" + m_fullTypeName + " ) {\n";
	m_code += "\tTEMPER_FAIL();\n";
	m_code += "}\n";
	m_code += "\n";
}