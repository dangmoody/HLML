#pragma once

#include "gen_common.h"

#include <string>

class TestsGenerator {
public:
				TestsGenerator() {}
				~TestsGenerator() {}

	void		Generate( const genType_t type, const uint32_t numRows, const uint32_t numCols );

private:
	std::string	m_code;

	std::string	m_testPrefix;

	std::string	m_fullTypeName;
	std::string	m_typeString;
	std::string	m_memberTypeString;

	genType_t	m_type;

	uint32_t	m_numRows;
	uint32_t	m_numCols;

private:
	void		GenerateTestAssignment();
	void		GenerateTestArithmetic();
	void		GenerateTestArray();
	void		GenerateTestEquality();
	void		GenerateTestRelational();

	void		GenerateTestLength();
	void		GenerateTestNormalized();
	void		GenerateTestDot();
	void		GenerateTestCross();
	void		GenerateTestAngle();
};