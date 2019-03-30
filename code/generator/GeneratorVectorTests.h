#pragma once

#include "gen_common.h"

#include <string>

class GeneratorVectorTests {
public:
				GeneratorVectorTests() {}
				~GeneratorVectorTests() {}

	bool		Generate( const genType_t type, const uint32_t numComponents );

private:
	std::string	m_codeTests;
	std::string	m_codeSuite;

	std::string	m_fullTypeName;
	std::string	m_typeString;
	std::string	m_memberTypeString;

	std::string	m_numComponentsStr;

	genType_t	m_type;

	uint32_t	m_numComponents;

private:
	void		GenerateTestAssignment();
	void		GenerateTestArray();
	void		GenerateTestArithmetic();
	void		GenerateTestIncrement();
	void		GenerateTestRelational();
	void		GenerateTestBitwise();

	void		GenerateTestLength();
	void		GenerateTestNormalized();
	void		GenerateTestDot();
	void		GenerateTestCross();
	void		GenerateTestAngle();
	void		GenerateTestDistance();
	void		GenerateTestPacking();

	void		GenerateTestSaturate();
	void		GenerateTestLerp();
	void		GenerateTestSmoothstep();
};