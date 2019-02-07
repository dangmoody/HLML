/*
===========================================================================

hlml.
Copyright (c) Dan Moody 2018 - Present.

This file is part of hlml.

hlml is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

hlml is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with hlml.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/

#pragma once

#include "float2.h"

struct float4x2 {
	float2 rows[4];

	inline float4x2();
	inline float4x2( const float diagonal );
	inline float4x2( const float2& diagonal );
	inline float4x2( const float2& row0, const float2& row1, const float2& row2, const float2& row3 );
	inline float4x2( const float2 rows[4] );
	inline float4x2( const float m00, const float m01, const float m10, const float m11, const float m20, const float m21, const float m30, const float m31 );
	inline float4x2( const float4x2& other );
	inline ~float4x2() {}

	inline float4x2 operator=( const float4x2& other );

	inline float4x2 operator+( const float rhs ) const;
	inline float4x2 operator+=( const float rhs );
	inline float4x2 operator+( const float4x2& rhs ) const;
	inline float4x2 operator+=( const float4x2& rhs );
	inline float4x2 operator-( const float rhs ) const;
	inline float4x2 operator-=( const float rhs );
	inline float4x2 operator-( const float4x2& rhs ) const;
	inline float4x2 operator-=( const float4x2& rhs );
	inline float4x2 operator*( const float rhs ) const;
	inline float4x2 operator*=( const float rhs );
	inline float4x2 operator*( const float4x2& rhs ) const;
	inline float4x2 operator*=( const float4x2& rhs );
	inline float4x2 operator/( const float rhs ) const;
	inline float4x2 operator/=( const float rhs );
	inline float4x2 operator/( const float4x2& rhs ) const;
	inline float4x2 operator/=( const float4x2& rhs );

	inline float2& operator[]( const uint32_t index );
	inline const float2& operator[]( const uint32_t index ) const;
};

inline bool operator==( const float4x2& lhs, const float4x2& rhs );
inline bool operator!=( const float4x2& lhs, const float4x2& rhs );

#include "float4x2.inl"