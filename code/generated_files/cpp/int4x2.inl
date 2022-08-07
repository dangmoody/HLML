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

#include "int4x2.h"
#include "int2.inl"

int4x2::int4x2( const int32_t diagonal )
{
	rows[0][0] = diagonal;
	rows[1][1] = diagonal;
	rows[2][2] = diagonal;
	rows[3][3] = diagonal;
}

int4x2::int4x2( const int2& diagonal )
{
	rows[0][0] = diagonal[0];
	rows[1][1] = diagonal[1];
	rows[2][2] = diagonal[2];
	rows[3][3] = diagonal[3];
}

// Sets each row of the matrix to the corresponding vector.
int4x2::int4x2( const int2& row0, const int2& row1, const int2& row2, const int2& row3 )
{
	rows[0] = row0;
	rows[1] = row1;
	rows[2] = row2;
	rows[3] = row3;
}

// Sets each component of the matrix to the corresponding scalar value.
int4x2::int4x2( const int32_t m00, const int32_t m01,
					const int32_t m10, const int32_t m11,
					const int32_t m20, const int32_t m21,
					const int32_t m30, const int32_t m31 )
{
	rows[0] = int2( m00, m01 );
	rows[1] = int2( m10, m11 );
	rows[2] = int2( m20, m21 );
	rows[3] = int2( m30, m31 );
}

int4x2::int4x2( const int4x2& mat )
{
	rows[0] = mat[0];
	rows[1] = mat[1];
	rows[2] = mat[2];
	rows[3] = mat[3];
}

int4x2::int4x2( const bool4x2& mat )
{
	rows[0] = int2( mat[0] );
	rows[1] = int2( mat[1] );
	rows[2] = int2( mat[2] );
	rows[3] = int2( mat[3] );
}

int4x2::int4x2( const uint4x2& mat )
{
	rows[0] = int2( mat[0] );
	rows[1] = int2( mat[1] );
	rows[2] = int2( mat[2] );
	rows[3] = int2( mat[3] );
}

int4x2::int4x2( const float4x2& mat )
{
	rows[0] = int2( mat[0] );
	rows[1] = int2( mat[1] );
	rows[2] = int2( mat[2] );
	rows[3] = int2( mat[3] );
}

int4x2::int4x2( const double4x2& mat )
{
	rows[0] = int2( mat[0] );
	rows[1] = int2( mat[1] );
	rows[2] = int2( mat[2] );
	rows[3] = int2( mat[3] );
}

int4x2 int4x2::operator=( const int4x2& other )
{
	rows[0] = other[0];
	rows[1] = other[1];
	rows[2] = other[2];
	rows[3] = other[3];

	return *this;
}

int2& int4x2::operator[]( const int32_t index )
{
	HLML_ASSERT( index >= 0 && index < 4 );
	return rows[index];
}

const int2& int4x2::operator[]( const int32_t index ) const
{
	HLML_ASSERT( index >= 0 && index < 4 );
	return rows[index];
}
