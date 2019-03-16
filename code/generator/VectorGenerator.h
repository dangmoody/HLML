#pragma once

#include "gen_common.h"

class VectorGenerator {
public:
					VectorGenerator() {}
					~VectorGenerator() {}

	void			Generate( const genType_t type, const uint32_t numComponents );

	void			PrintHeader() const;
	void			PrintInl() const;

private:
	std::string		m_codeHeader;
	std::string		m_codeInl;

	std::string		m_fullTypeName;
	std::string		m_typeString;

	std::string		m_numComponentsStr;

	genType_t		m_type;
	uint32_t		m_numComponents;

private:
	void			GenerateHeader();
	void			GenerateInl();

private:
	void			HeaderGenerateForwardDeclarations();
	void			HeaderGenerateMembers();
	void			HeaderGenerateMembersStruct( const std::string& componentNames );

	void			HeaderGenerateConstructors();
	void			HeaderGenerateOperatorsAssignment();
	void			HeaderGenerateOperatorsArray();
	void			HeaderGenerateOperatorsEquality();

	void			InlGenerateConstructors();
	void			InlGenerateOperatorsAssignment();
	void			InlGenerateOperatorsArray();
	void			InlGenerateOperatorsEquality();

	std::string		GetDocStruct() const;
	std::string		GetDocScalar() const;
	std::string		GetDocCtorDefault() const;
	std::string		GetDocCtorCopy() const;
	std::string		GetDocCtorMemberwise() const;
	std::string		GetDocOperatorAssignment() const;

	std::string		GetDocOperatorArray() const;
};
