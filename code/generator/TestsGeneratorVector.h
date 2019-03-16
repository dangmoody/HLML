#pragma once

#include "gen_common.h"

#include <string>

class TestsGeneratorVector {
public:
				TestsGeneratorVector() {}
				~TestsGeneratorVector() {}

	void		Generate( const genType_t type, const uint32_t numComponents );

private:
	std::string	m_code;

	std::string	m_testPrefix;

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
	void		GenerateTestRelational();

	void		GenerateTestLength();
	void		GenerateTestNormalized();
	void		GenerateTestDot();
	void		GenerateTestCross();
	void		GenerateTestAngle();

	void		GenerateTestSaturate();

	void		GenerateTestLerp();

	void		GenerateTestPacking();
};