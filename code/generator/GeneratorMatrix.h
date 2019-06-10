#pragma once

#include "gen_common.h"

class GeneratorMatrix {
public:
					GeneratorMatrix() {}
					~GeneratorMatrix() {}

	bool			Generate( const genType_t type, const u32 numRows, const u32 numCols );

#ifdef _DEBUG
	void			PrintHeader() const;
	void			PrintInl() const;
#endif

private:
	std::string		m_codeHeader;
	std::string		m_codeInl;

	std::string		m_fullTypeName;
	std::string		m_transposedTypeName;

	std::string		m_typeString;
	std::string		m_memberTypeString;

	std::string		m_vectorMemberTypeString;

	std::string		m_numRowsStr, m_numColsStr;

	genType_t		m_type;
	u32		m_numRows, m_numCols;

private:
	void			GenerateConstructors();
	void			GenerateOperatorsAssignment();
	void			GenerateOperatorsArray();
	void			GenerateOperatorsEquality();

	std::string		GetDocStruct() const;
	std::string		GetDocCtorDefault() const;
	std::string		GetDocCtorDiagonalScalar() const;
	std::string		GetDocCtorDiagonalVector() const;
	std::string		GetDocCtorRow() const;
	std::string		GetDocCtorRowArray() const;
	std::string		GetDocCtorRowsAndCols() const;
	std::string		GetDocCtorCopy() const;

	std::string		GetDocOperatorAssignment() const;
	std::string		GetDocOperatorArray() const;
};
