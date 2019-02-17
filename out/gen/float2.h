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

// GENERATED FILE.  DO NOT EDIT.

#pragma once

#include "bool2.h"

#include <stdint.h>

struct float3;
struct float4;

struct float2 {
	union {
		struct {
			float x;
			float y;
		};


		struct {
			float r;
			float g;
		};


		float data[2] = { 0 };
	};

	inline float2();
	inline explicit float2( const float x );
	inline float2( const float x, const float y );
	inline float2( const float2& other );
	inline float2( const float3& other );
	inline float2( const float4& other );
	~float2() {}

	inline float2 operator=( const float2& rhs );
	inline float2 operator=( const float3& rhs );
	inline float2 operator=( const float4& rhs );

	inline float2 operator+( const float rhs ) const;
	inline float2 operator+=( const float rhs );
	inline float2 operator+( const float2& rhs ) const;
	inline float2 operator+=( const float2& rhs );
	inline float2 operator-( const float rhs ) const;
	inline float2 operator-=( const float rhs );
	inline float2 operator-( const float2& rhs ) const;
	inline float2 operator-=( const float2& rhs );
	inline float2 operator*( const float rhs ) const;
	inline float2 operator*=( const float rhs );
	inline float2 operator*( const float2& rhs ) const;
	inline float2 operator*=( const float2& rhs );
	inline float2 operator/( const float rhs ) const;
	inline float2 operator/=( const float rhs );
	inline float2 operator/( const float2& rhs ) const;
	inline float2 operator/=( const float2& rhs );

	inline const float& operator[]( const uint32_t index ) const;
	inline float& operator[]( const uint32_t index );
};

inline bool operator==( const float2& lhs, const float2& rhs );
inline bool operator!=( const float2& lhs, const float2& rhs );

inline bool2 operator<( const float2& lhs, const float2& rhs );
inline bool2 operator<=( const float2& lhs, const float2& rhs );
inline bool2 operator>( const float2& lhs, const float2& rhs );
inline bool2 operator>=( const float2& lhs, const float2& rhs );

#include "float2.inl"