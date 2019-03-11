#pragma once

#include "gen_common.h"

class MatrixGenerator {
public:
				MatrixGenerator() {}
				~MatrixGenerator() {}

	void		Generate( const genType_t type, const uint32_t numRows, const uint32_t numCols );

	void		PrintHeader() const;
	void		PrintInl() const;

private:
	std::string	m_codeHeader;
	std::string	m_codeInl;

	std::string	m_fullTypeName;
	std::string	m_transposedTypeName;

	std::string	m_typeString;
	std::string	m_memberTypeString;

	std::string	m_vectorMemberTypeString;

	std::string	m_numRowsStr, m_numColsStr;

	genType_t	m_type;
	uint32_t	m_numRows, m_numCols;

private:
	void		GenerateHeader();
	void		GenerateInl();

private:
	void		HeaderGenerateMembers();

	void		HeaderGenerateConstructors();
	void		HeaderGenerateOperatorsAssignment();
	void		HeaderGenerateOperatorsArray();
	void		HeaderGenerateOperatorsEquality();

	void		InlGenerateConstructors();
	void		InlGenerateOperatorsAssignment();
	void		InlGenerateOperatorsArray();
	void		InlGenerateOperatorsEquality();
};
