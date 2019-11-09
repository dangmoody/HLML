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

class GeneratorMatrix {
public:
					GeneratorMatrix() {}
					~GeneratorMatrix() {}

	bool			Generate( const genType_t type, const u32 numRows, const u32 numCols );

private:
	stringBuilder_t	m_codeHeader;
	stringBuilder_t	m_codeInl;

	genType_t		m_type;
	u32				m_numRows, m_numCols;

	char			m_fullTypeName[GEN_STRING_LENGTH_TYPE_NAME];
	char			m_transposedTypeName[GEN_STRING_LENGTH_TYPE_NAME];

	char			m_vectorMemberTypeString[GEN_STRING_LENGTH_TYPE_NAME];

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
