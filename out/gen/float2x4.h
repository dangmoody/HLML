/*
===========================================================================

hlml.
Copyright (c) Dan Moody 2019 - Present.

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

#include "float4.h"

struct float2x4 {
	float4 rows[2];

	inline float2x4();
	inline float2x4( const float diagonal );
	inline float2x4( const float4& diagonal );
	inline float2x4( const float4& row0, const float4& row1 );
	inline float2x4( const float4 rows[2] );
	inline float2x4( const float m00, const float m01, const float m02, const float m03, const float m10, const float m11, const float m12, const float m13 );
	inline float2x4( const float2x4& other );
	inline ~float2x4() {}

	inline float2x4 operator=( const float2x4& other );

	inline float2x4 operator+( const float rhs ) const;
	inline float2x4 operator+=( const float rhs );
	inline float2x4 operator+( const float2x4& rhs ) const;
	inline float2x4 operator+=( const float2x4& rhs );
	inline float2x4 operator-( const float rhs ) const;
	inline float2x4 operator-=( const float rhs );
	inline float2x4 operator-( const float2x4& rhs ) const;
	inline float2x4 operator-=( const float2x4& rhs );
	inline float2x4 operator*( const float rhs ) const;
	inline float2x4 operator*=( const float rhs );
	inline float2x4 operator*( const float2x4& rhs ) const;
	inline float2x4 operator*=( const float2x4& rhs );
	inline float2x4 operator/( const float rhs ) const;
	inline float2x4 operator/=( const float rhs );
	inline float2x4 operator/( const float2x4& rhs ) const;
	inline float2x4 operator/=( const float2x4& rhs );

	inline float4& operator[]( const uint32_t index );
	inline const float4& operator[]( const uint32_t index ) const;
};

inline bool operator==( const float2x4& lhs, const float2x4& rhs );
inline bool operator!=( const float2x4& lhs, const float2x4& rhs );

#include "float2x4.inl"