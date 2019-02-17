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

#include "bool4.h"

#include <stdint.h>

struct float2;
struct float3;
struct float3;

struct float4 {
	union {
		struct {
			float x;
			float y;
			float z;
			float w;
		};


		struct {
			float r;
			float g;
			float b;
			float a;
		};


		float data[4] = { 0 };
	};

	inline float4();
	inline explicit float4( const float x );
	inline float4( const float x, const float y, const float z, const float w );
	inline float4( const float2& other );
	inline float4( const float3& other );
	inline float4( const float4& other );
	~float4() {}

	inline float4 operator=( const float2& rhs );
	inline float4 operator=( const float3& rhs );
	inline float4 operator=( const float4& rhs );

	inline float4 operator+( const float rhs ) const;
	inline float4 operator+=( const float rhs );
	inline float4 operator+( const float4& rhs ) const;
	inline float4 operator+=( const float4& rhs );
	inline float4 operator-( const float rhs ) const;
	inline float4 operator-=( const float rhs );
	inline float4 operator-( const float4& rhs ) const;
	inline float4 operator-=( const float4& rhs );
	inline float4 operator*( const float rhs ) const;
	inline float4 operator*=( const float rhs );
	inline float4 operator*( const float4& rhs ) const;
	inline float4 operator*=( const float4& rhs );
	inline float4 operator/( const float rhs ) const;
	inline float4 operator/=( const float rhs );
	inline float4 operator/( const float4& rhs ) const;
	inline float4 operator/=( const float4& rhs );

	inline const float& operator[]( const uint32_t index ) const;
	inline float& operator[]( const uint32_t index );
};

inline bool operator==( const float4& lhs, const float4& rhs );
inline bool operator!=( const float4& lhs, const float4& rhs );

inline bool4 operator<( const float4& lhs, const float4& rhs );
inline bool4 operator<=( const float4& lhs, const float4& rhs );
inline bool4 operator>( const float4& lhs, const float4& rhs );
inline bool4 operator>=( const float4& lhs, const float4& rhs );

#include "float4.inl"