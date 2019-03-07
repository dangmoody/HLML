#pragma once

#include "gen_common.h"

class TestsGeneratorMatrix {
public:
				TestsGeneratorMatrix() {}
				~TestsGeneratorMatrix() {}

	void		Generate( const genType_t type, const uint32_t numRows, const uint32_t numCols );

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
	void		GenerateTestArray();
	void		GenerateTestRelational();

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

	// TODO(DM): move these to gen_common.h as inline functions
	std::string	GetParmListIdentity() const;
	std::string	GetParmListDiagonal( const genType_t type, const uint32_t numRows, const uint32_t numCols, const float* values, const uint32_t numValues ) const;
	std::string	GetParmListSingleValue( const genType_t type, const int32_t value ) const;

	std::string	GetParmListVector( const genType_t type, const uint32_t numComponents, const float* values ) const;
	std::string	GetParmListMatrix( const genType_t type, const uint32_t numRows, const uint32_t numCols, const float* values ) const;
};