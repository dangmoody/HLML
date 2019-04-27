#pragma once

#include "gen_common.h"

class GeneratorScalarTest {
public:
				GeneratorScalarTest() {}
				~GeneratorScalarTest() {}

	bool		Generate( const genType_t type );

private:
	std::string	m_codeTests;
	std::string	m_codeSuite;

	std::string	m_memberTypeString;

	genType_t	m_type;

private:
	void		GenerateTestFloateq();
	void		GenerateTestSign();
	void		GenerateTestDegreesRadians();
	void		GenerateTestMinMax();
	void		GenerateTestClamp();
	void		GenerateTestSaturate();
};
