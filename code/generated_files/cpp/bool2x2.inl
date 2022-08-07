/*
===========================================================================

HLML
v2.2.0

MIT License:

Copyright (c) 2019 Dan Moody (daniel.guy.moody@gmail.com).

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

===========================================================================
*/

// THIS FILE WAS AUTOMATICALLY GENERATED BY A TOOL.
// EDITING THIS FILE MAY CAUSE SIDE EFFECTS.
// DO SO AT YOUR OWN RISK.

#pragma once

#include "bool2x2.h"
#include "bool2.inl"

bool2x2::bool2x2( const bool32_t diagonal )
{
	rows[0][0] = diagonal;
	rows[1][1] = diagonal;
}

bool2x2::bool2x2( const bool2& diagonal )
{
	rows[0][0] = diagonal[0];
	rows[1][1] = diagonal[1];
}

// Sets each row of the matrix to the corresponding vector.
bool2x2::bool2x2( const bool2& row0, const bool2& row1 )
{
	rows[0] = row0;
	rows[1] = row1;
}

// Sets each component of the matrix to the corresponding scalar value.
bool2x2::bool2x2( const bool32_t m00, const bool32_t m01,
					const bool32_t m10, const bool32_t m11 )
{
	rows[0] = bool2( m00, m01 );
	rows[1] = bool2( m10, m11 );
}

bool2x2::bool2x2( const bool2x2& mat )
{
	rows[0] = mat[0];
	rows[1] = mat[1];
}

bool2x2::bool2x2( const int2x2& mat )
{
	rows[0] = bool2( mat[0] );
	rows[1] = bool2( mat[1] );
}

bool2x2::bool2x2( const uint2x2& mat )
{
	rows[0] = bool2( mat[0] );
	rows[1] = bool2( mat[1] );
}

bool2x2::bool2x2( const float2x2& mat )
{
	rows[0] = bool2( mat[0] );
	rows[1] = bool2( mat[1] );
}

bool2x2::bool2x2( const double2x2& mat )
{
	rows[0] = bool2( mat[0] );
	rows[1] = bool2( mat[1] );
}

bool2x2 bool2x2::operator=( const bool2x2& other )
{
	rows[0] = other[0];
	rows[1] = other[1];

	return *this;
}

bool2& bool2x2::operator[]( const int32_t index )
{
	HLML_ASSERT( index >= 0 && index < 2 );
	return rows[index];
}

const bool2& bool2x2::operator[]( const int32_t index ) const
{
	HLML_ASSERT( index >= 0 && index < 2 );
	return rows[index];
}
