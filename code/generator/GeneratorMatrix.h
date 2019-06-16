#pragma once

#include "gen_common.h"

#include "string_builder.h"

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
	stringBuilder_t	m_codeHeader;
	stringBuilder_t	m_codeInl;

	genType_t		m_type;
	u32				m_numRows, m_numCols;

	char			m_fullTypeName[16];
	char			m_transposedTypeName[16];

	char			m_vectorMemberTypeString[16];

	const char*		m_typeString;
	const char*		m_memberTypeString;

private:
	void			GenerateConstructors();
	void			GenerateOperatorsAssignment();
	void			GenerateOperatorsArray();
	void			GenerateOperatorsEquality();

	void			GenerateDocStruct();
	void			GenerateDocCtorDefault();
	void			GenerateDocCtorDiagonalScalar();
	void			GenerateDocCtorDiagonalVector();
	void			GenerateDocCtorRow();
	void			GenerateDocCtorRowArray();
	void			GenerateDocCtorRowsAndCols();
	void			GenerateDocCtorCopy();

	void			GenerateDocOperatorAssignment();
	void			GenerateDocOperatorArray();
};
