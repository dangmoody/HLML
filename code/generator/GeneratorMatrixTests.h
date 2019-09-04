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

class GeneratorMatrixTests {
public:
					GeneratorMatrixTests() {}
					~GeneratorMatrixTests() {}

	bool			Generate( const genType_t type, const u32 numRows, const u32 numCols );

private:
	stringBuilder_t	m_codeTests;
	stringBuilder_t	m_codeSuite;

	genType_t		m_type;

	u32				m_numRows;
	u32				m_numCols;

	char			m_vectorTypeString[GEN_STRING_LENGTH_TYPE_NAME];
	char			m_fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	const char*		m_typeString;
	const char*		m_memberTypeString;

private:
	void			GenerateTestAssignment();
	void			GenerateTestComponentWiseArithmetic();
	void			GenerateTestMultiplyVector();
	void			GenerateTestMultiplyMatrix();
	void			GenerateTestDivideMatrix();
	void			GenerateTestIncrement();
	void			GenerateTestRelational();
	void			GenerateTestBitwise();
	void			GenerateTestArray();

	void			GenerateTestIdentity();
	void			GenerateTestTranspose();
	void			GenerateTestInverse();
	void			GenerateTestDeterminant();
	void			GenerateTestCompMulDiv();
	void			GenerateTestTranslate();
	void			GenerateTestRotate();
	void			GenerateTestScale();
	void			GenerateTestOrtho();
	void			GenerateTestPerspective();
	void			GenerateTestLookAt();

	void			GetTestCodeOperatorArithmeticInternal( const genOpArithmetic_t op, const float valuesLhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX],
						const float valuesRhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], stringBuilder_t* sb ) const;

	// DM: does this want to live with the other generic matrix gen functions?
	void			GetParmListComponentWiseArithmeticAnswer( const genOpArithmetic_t op, const u32 numRows, const u32 numCols,
						const float valuesLhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], const float valuesRhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX],
						char* outString ) const;

	void			GetParmListMatrixMultiply( const u32 returnTypeRows, const u32 returnTypeCols,
						const float valuesLhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], const float valuesRhs[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX],
						char* outString ) const;
};
