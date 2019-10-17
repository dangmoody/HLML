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
#include "GeneratorQuaternionTests.h"
#include "FileIO.h"

#include "gen_funcs_vector.h"

#include "allocator.h"

bool GeneratorQuaternionTests::Generate( const genType_t type ) {
	const u32 testsCodeBytes = 16 * KB_TO_BYTES;
	const u32 suiteCodeBytes = 2 * KB_TO_BYTES;

	m_codeTests = String_Create(testsCodeBytes);
	m_codeSuite = String_Create(suiteCodeBytes);

	m_type = type;

	m_typeString = Gen_GetTypeString(type);
	m_memberTypeString = Gen_GetMemberTypeString(type);

	snprintf(m_baseTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s", m_typeString);
	snprintf(m_fullTypeName, GEN_STRING_LENGTH_TYPE_NAME, "%s%d", m_typeString, GEN_COMPONENT_COUNT_MAX);

	stringBuilder_t code = String_Create(testsCodeBytes + suiteCodeBytes);

	String_Appendf(&code, GEN_FILE_HEADER);

	// TODO(DM): if we do end up using this as our final include solution, make the filename a constant
	String_Append(&code, "#include \"hlml.h\"\n");

	String_Append(&code, "#include <temper/temper.h>\n");
	String_Append(&code, "\n");

	String_Appendf(&m_codeSuite, "TEMPER_SUITE( Test_%s_%s )\n", "quaternion", m_fullTypeName);
	String_Append(&m_codeSuite, "{\n");

	GenerateTestMultiplyScalarQuaternion();
	GenerateTestMultiplyQuaternion();

	String_Append(&m_codeSuite, "}\n");

	String_Append(&code, m_codeTests.str);
	String_Append(&code, m_codeSuite.str);

	char filename[1024] = { 0 };
	snprintf(filename, 1024, "%stest_quaternion_%s.cpp", GEN_TESTS_FOLDER_PATH, m_fullTypeName);

	bool32 result = FS_WriteEntireFile(filename, code.str, code.length);

	if (!result) {
		printf("Can't generate test suite for %s.  That's rough man.\n", m_fullTypeName);
	}

	Mem_Reset();

	return result;
}

void GeneratorQuaternionTests::GenerateTestMultiplyScalarQuaternion() {
	if (Gen_TypeIsFloatingPoint(m_type) == false) {
		return;
	}

	// number picked at random
	char scalar[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	Gen_GetNumericLiteral(m_type, 6, scalar, 1);

	char twoStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char threeStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char fourStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char fiveStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char twelveStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char eighteenStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char twentyFourStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];
	char thirtyStr[GEN_STRING_LENGTH_NUMERIC_LITERAL];

	Gen_GetNumericLiteral(m_type, 2, twoStr, 1);
	Gen_GetNumericLiteral(m_type, 3, threeStr, 1);
	Gen_GetNumericLiteral(m_type, 4, fourStr, 1);
	Gen_GetNumericLiteral(m_type, 5, fiveStr, 1);
	Gen_GetNumericLiteral(m_type, 12, twelveStr, 1);
	Gen_GetNumericLiteral(m_type, 18, eighteenStr, 1);
	Gen_GetNumericLiteral(m_type, 24, twentyFourStr, 1);
	Gen_GetNumericLiteral(m_type, 30, thirtyStr, 1);
	
	char parmListValues[4][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf(parmListValues[0], 64, "( %s )", twoStr);
	snprintf(parmListValues[1], 64, "( %s )", threeStr);
	snprintf(parmListValues[2], 64, "( %s )", fourStr);
	snprintf(parmListValues[3], 64, "( %s )", fiveStr);

	char parmListAnswers[4][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf(parmListAnswers[0], 64, "( %s )", twelveStr);
	snprintf(parmListAnswers[1], 64, "( %s )", eighteenStr);
	snprintf(parmListAnswers[2], 64, "( %s )", twentyFourStr);
	snprintf(parmListAnswers[3], 64, "( %s )", thirtyStr);

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf(testName, GEN_STRING_LENGTH_TEST_NAME, "TestArithmetic%s_%s", "MultiplyScalar", m_fullTypeName);

	String_Appendf(&m_codeTests, "TEMPER_TEST( %s )\n", testName);
	String_Append(&m_codeTests, "{\n");
	String_Appendf(&m_codeTests, "\tconst %s a = %s( %s, %s, %s, %s );\n", m_fullTypeName, m_fullTypeName, parmListValues[0], parmListValues[1], parmListValues[2], parmListValues[3]);
	String_Appendf(&m_codeTests, "\tconst %s b = %s;\n", m_baseTypeName, scalar);
	String_Append(&m_codeTests, "\n");
	String_Appendf(&m_codeTests, "\t%s c = quaternion_mul(a, b);\n", m_fullTypeName);
	String_Append(&m_codeTests, "\n");
	String_Appendf(&m_codeTests, "\tTEMPER_EXPECT_TRUE( c == %s( %s, %s, %s, %s ) );\n", m_fullTypeName, parmListAnswers[0], parmListAnswers[1], parmListAnswers[2], parmListAnswers[3]);
	String_Append(&m_codeTests, "\n");
	String_Append(&m_codeTests, "\tTEMPER_PASS();\n");
	String_Append(&m_codeTests, "}\n");
	String_Append(&m_codeTests, "\n");

	String_Appendf(&m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName);
}

void GeneratorQuaternionTests::GenerateTestMultiplyQuaternion() {
	if (Gen_TypeIsFloatingPoint(m_type) == false) {
		return;
	}

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

	Gen_GetNumericLiteral(m_type, 1, oneStr, 1);
	Gen_GetNumericLiteral(m_type, 2, twoStr, 1);
	Gen_GetNumericLiteral(m_type, 3, threeStr, 1);
	Gen_GetNumericLiteral(m_type, 4, fourStr, 1);
	Gen_GetNumericLiteral(m_type, 5, fiveStr, 1);
	Gen_GetNumericLiteral(m_type, 7, sevenStr, 1);
	Gen_GetNumericLiteral(m_type, 22, twentyTwoStr, 1);
	Gen_GetNumericLiteral(m_type, 30, thirtyStr, 1);
	Gen_GetNumericLiteral(m_type, 56, fiftySixStr, 1);

	char parmListRhsValues[4][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf(parmListRhsValues[0], 64, "( %s )", twoStr);
	snprintf(parmListRhsValues[1], 64, "( %s )", threeStr);
	snprintf(parmListRhsValues[2], 64, "( %s )", fourStr);
	snprintf(parmListRhsValues[3], 64, "( %s )", fiveStr);

	char parmListLhsValues[4][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf(parmListLhsValues[0], 64, "( %s )", oneStr);
	snprintf(parmListLhsValues[1], 64, "( %s )", threeStr);
	snprintf(parmListLhsValues[2], 64, "( %s )", fiveStr);
	snprintf(parmListLhsValues[3], 64, "( %s )", sevenStr);

	char parmListAnswers[4][GEN_STRING_LENGTH_PARM_LIST_VECTOR];
	snprintf(parmListAnswers[0], 64, "( %s )", twentyTwoStr);
	snprintf(parmListAnswers[1], 64, "( %s )", thirtyStr);
	snprintf(parmListAnswers[2], 64, "( %s )", fiftySixStr);
	snprintf(parmListAnswers[3], 64, "( %s )", fourStr);

	char testName[GEN_STRING_LENGTH_TEST_NAME] = { 0 };
	snprintf(testName, GEN_STRING_LENGTH_TEST_NAME, "TestArithmetic%s_%s", "Multiply", m_fullTypeName);

	String_Appendf(&m_codeTests, "TEMPER_TEST( %s )\n", testName);
	String_Append(&m_codeTests, "{\n");
	String_Appendf(&m_codeTests, "\tconst %s a = %s( %s, %s, %s, %s );\n", m_fullTypeName, m_fullTypeName, parmListRhsValues[0], parmListRhsValues[1], parmListRhsValues[2], parmListRhsValues[3]);
	String_Appendf(&m_codeTests, "\tconst %s b = %s( %s, %s, %s, %s );\n", m_fullTypeName, m_fullTypeName, parmListLhsValues[0], parmListLhsValues[1], parmListLhsValues[2], parmListLhsValues[3]);
	String_Append(&m_codeTests, "\n");
	String_Appendf(&m_codeTests, "\t%s c = quaternion_mul(a, b);\n", m_fullTypeName);
	String_Append(&m_codeTests, "\n");
	String_Appendf(&m_codeTests, "\tTEMPER_EXPECT_TRUE( c == %s( %s, %s, %s, %s ) );\n", m_fullTypeName, parmListAnswers[0], parmListAnswers[1], parmListAnswers[2], parmListAnswers[3]);
	String_Append(&m_codeTests, "\n");
	String_Append(&m_codeTests, "\tTEMPER_PASS();\n");
	String_Append(&m_codeTests, "}\n");
	String_Append(&m_codeTests, "\n");

	String_Appendf(&m_codeSuite, "\tTEMPER_RUN_TEST( %s );\n", testName);
}