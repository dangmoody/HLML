/*
===========================================================================

HLML Generator.
Copyright (c) Dan Moody 2018 - Present.

This file is part of the HLML Generator.

The HLML Generator is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

The HLML Generator is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with The HLML Generator.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/
#pragma once

#include "gen_common.h"

#include "string_builder.h"

class GeneratorVectorTests {
public:
					GeneratorVectorTests() {}
					~GeneratorVectorTests() {}

	bool			Generate( const genType_t type, const u32 numComponents );

private:
	stringBuilder_t	m_codeTests;
	stringBuilder_t	m_codeSuite;

	genType_t		m_type;

	u32				m_numComponents;

	char			m_fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	const char*		m_typeString;
	const char*		m_memberTypeString;

	const char*		m_registerName;	// null for types that don't support SIMD

private:
	void			GenerateTestAssignment();
	void			GenerateTestArray();
	void			GenerateTestArithmetic();
	void			GenerateTestIncrement();
	void			GenerateTestRelational();
	void			GenerateTestBitwise();

	void			GenerateTestLength();
	void			GenerateTestNormalized();
	void			GenerateTestDot();
	void			GenerateTestCross();
	void			GenerateTestAngle();
	void			GenerateTestDistance();
	void			GenerateTestPacking();

	void			GenerateTestSaturate();
	void			GenerateTestLerp();

	void			GenerateTestStep();
	void			GenerateTestSmoothstep();
};
