#pragma once

#include "gen_common.h"

#include "string_builder.h"

class GeneratorVector {
public:
					GeneratorVector() {}
					~GeneratorVector() {}

	bool			Generate( const genType_t type, const u32 numComponents );

#ifdef _DEBUG
	void			PrintHeader() const;
	void			PrintInl() const;
#endif

private:
	stringBuilder_t	m_codeHeader;
	stringBuilder_t	m_codeInl;

	genType_t		m_type;
	u32				m_numComponents;

	char			m_fullTypeName[16];

	const char*		m_typeString;
	const char*		m_memberTypeString;

private:
	void			HeaderGenerateMembersStruct( const char componentNames[GEN_COMPONENT_COUNT_MAX] );

	void			GenerateConstructors();
	void			GenerateOperatorsAssignment();
	void			GenerateOperatorsArray();
	void			GenerateOperatorsEquality();
	void			GenerateSwizzleFuncs();

	void			GenerateDocStruct();
	void			GenerateDocCtorScalar();
	void			GenerateDocCtorDefault();
	void			GenerateDocCtorCopy();
	void			GenerateDocCtorMemberwise();
	void			GenerateDocOperatorAssignment();
	void			GenerateDocOperatorArray();
};
