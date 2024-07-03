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

#include "float4x3.h"
#include "float3.inl"

#ifdef HLML_NAMESPACE
namespace hlml
{
#endif

float4x3::float4x3( const float diagonal )
{
	rows[0][0] = diagonal;
	rows[1][1] = diagonal;
	rows[2][2] = diagonal;
	rows[3][3] = diagonal;
}

float4x3::float4x3( const float3& diagonal )
{
	rows[0][0] = diagonal[0];
	rows[1][1] = diagonal[1];
	rows[2][2] = diagonal[2];
	rows[3][3] = diagonal[3];
}

// Sets each row of the matrix to the corresponding vector.
float4x3::float4x3( const float3& row0, const float3& row1, const float3& row2, const float3& row3 )
{
	rows[0] = row0;
	rows[1] = row1;
	rows[2] = row2;
	rows[3] = row3;
}

// Sets each component of the matrix to the corresponding scalar value.
float4x3::float4x3( const float m00, const float m01, const float m02,
					const float m10, const float m11, const float m12,
					const float m20, const float m21, const float m22,
					const float m30, const float m31, const float m32 )
{
	rows[0] = float3( m00, m01, m02 );
	rows[1] = float3( m10, m11, m12 );
	rows[2] = float3( m20, m21, m22 );
	rows[3] = float3( m30, m31, m32 );
}

float4x3::float4x3( const float4x3& mat )
{
	rows[0] = mat[0];
	rows[1] = mat[1];
	rows[2] = mat[2];
	rows[3] = mat[3];
}

float4x3::float4x3( const bool4x3& mat )
{
	rows[0] = float3( mat[0] );
	rows[1] = float3( mat[1] );
	rows[2] = float3( mat[2] );
	rows[3] = float3( mat[3] );
}

float4x3::float4x3( const int4x3& mat )
{
	rows[0] = float3( mat[0] );
	rows[1] = float3( mat[1] );
	rows[2] = float3( mat[2] );
	rows[3] = float3( mat[3] );
}

float4x3::float4x3( const uint4x3& mat )
{
	rows[0] = float3( mat[0] );
	rows[1] = float3( mat[1] );
	rows[2] = float3( mat[2] );
	rows[3] = float3( mat[3] );
}

float4x3::float4x3( const double4x3& mat )
{
	rows[0] = float3( mat[0] );
	rows[1] = float3( mat[1] );
	rows[2] = float3( mat[2] );
	rows[3] = float3( mat[3] );
}

float4x3 float4x3::operator=( const float4x3& other )
{
	rows[0] = other[0];
	rows[1] = other[1];
	rows[2] = other[2];
	rows[3] = other[3];

	return *this;
}

float3& float4x3::operator[]( const int32_t index )
{
	HLML_ASSERT( index >= 0 && index < 4 );
	return rows[index];
}

const float3& float4x3::operator[]( const int32_t index ) const
{
	HLML_ASSERT( index >= 0 && index < 4 );
	return rows[index];
}

#ifdef HLML_NAMESPACE
}
#endif
