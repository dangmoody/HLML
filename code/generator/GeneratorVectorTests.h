#pragma once

#include "gen_common.h"

#include "string_builder.h"

class GeneratorVectorTests {
public:
					GeneratorVectorTests() {}
					~GeneratorVectorTests() {}

	bool			Generate( const genType_t type, const u32 numComponents );

private:
	stringBuilder_t	m_codeTests;
	stringBuilder_t	m_codeSuite;

	genType_t		m_type;

	u32				m_numComponents;

	char			m_fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	const char*		m_typeString;
	const char*		m_memberTypeString;

private:
	void			GenerateTestAssignment();
	void			GenerateTestArray();
	void			GenerateTestArithmetic();
	void			GenerateTestIncrement();
	void			GenerateTestRelational();
	void			GenerateTestBitwise();

	void			GenerateTestLength();
	void			GenerateTestNormalized();
	void			GenerateTestDot();
	void			GenerateTestCross();
	void			GenerateTestAngle();
	void			GenerateTestDistance();
	void			GenerateTestPacking();

	void			GenerateTestSaturate();
	void			GenerateTestLerp();
	void			GenerateTestSmoothstep();
};
