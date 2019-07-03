#pragma once

#include "gen_common.h"

#include "string_builder.h"

class GeneratorScalarTest {
public:
					GeneratorScalarTest() {}
					~GeneratorScalarTest() {}

	bool			Generate( const genType_t type );

private:
	stringBuilder_t	m_codeTests;
	stringBuilder_t	m_codeSuite;

	const char*		m_memberTypeString;

	genType_t		m_type;

private:
	void			GenerateTestFloateq();
	void			GenerateTestSign();
	void			GenerateTestDegreesRadians();
	void			GenerateTestMinMax();
	void			GenerateTestClamp();
	void			GenerateTestSaturate();
};
