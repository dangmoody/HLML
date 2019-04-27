#pragma once

#include "gen_common.h"

class GeneratorMatrixTests {
public:
				GeneratorMatrixTests() {}
				~GeneratorMatrixTests() {}

	bool		Generate( const genType_t type, const uint32_t numRows, const uint32_t numCols );

private:
	std::string	m_code;

	std::string	m_testPrefix;

	std::string	m_fullTypeName;
	std::string	m_typeString;
	std::string	m_memberTypeString;
	std::string	m_vectorTypeString;

	std::string	m_numRowsStr, m_numColsStr;

	genType_t	m_type;

	uint32_t	m_numRows;
	uint32_t	m_numCols;

private:
	void		GenerateTestAssignment();
	void		GenerateTestArithmetic();
	void		GenerateTestMultiplyVector();
	void		GenerateTestIncrement();
	void		GenerateTestRelational();
	void		GenerateTestBitwise();
	void		GenerateTestArray();

	void		GenerateTestIdentity();
	void		GenerateTestTranspose();
	void		GenerateTestInverse();
	void		GenerateTestDeterminant();
	void		GenerateTestTranslate();
	void		GenerateTestRotate();
	void		GenerateTestScale();
	void		GenerateTestOrtho();
	void		GenerateTestPerspective();
	void		GenerateTestLookAt();

	std::string	GetTestCodeArithmeticInternal( const genOpArithmetic_t op, const float valuesLhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX],
					const float valuesRhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX] ) const;

	// DM: does this want to live with the other generic matrix gen functions?
	std::string	GetParmListArithmeticAnswer( const genOpArithmetic_t op, const uint32_t numRows, const uint32_t numCols,
					const float valuesLhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], const float valuesRhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX] ) const;
};
