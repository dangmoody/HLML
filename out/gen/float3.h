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

#include "bool3.h"

struct float2;
struct float4;
struct float3;

struct float3 {
	union {
		struct {
			float x;
			float y;
			float z;
		};

		struct {
			float r;
			float g;
			float b;
		};

		float data[3] = { 0 };
	};

	inline float3();
	inline explicit float3( const float x );
	inline float3( const float x, const float y, const float z );
	inline float3( const float2& other );
	inline float3( const float3& other );
	inline float3( const float4& other );
	~float3() {}

	inline float3 operator=( const float2& rhs );
	inline float3 operator=( const float3& rhs );
	inline float3 operator=( const float4& rhs );

	inline float3 operator+( const float rhs ) const;
	inline float3 operator+=( const float rhs );
	inline float3 operator+( const float3& rhs ) const;
	inline float3 operator+=( const float3& rhs );
	inline float3 operator-( const float rhs ) const;
	inline float3 operator-=( const float rhs );
	inline float3 operator-( const float3& rhs ) const;
	inline float3 operator-=( const float3& rhs );
	inline float3 operator*( const float rhs ) const;
	inline float3 operator*=( const float rhs );
	inline float3 operator*( const float3& rhs ) const;
	inline float3 operator*=( const float3& rhs );
	inline float3 operator/( const float rhs ) const;
	inline float3 operator/=( const float rhs );
	inline float3 operator/( const float3& rhs ) const;
	inline float3 operator/=( const float3& rhs );

	inline const float& operator[]( const uint32_t index ) const;
	inline float& operator[]( const uint32_t index );
};

inline bool operator==( const float3& lhs, const float3& rhs );
inline bool operator!=( const float3& lhs, const float3& rhs );

inline bool3 operator<( const float3& lhs, const float3& rhs );
inline bool3 operator<=( const float3& lhs, const float3& rhs );
inline bool3 operator>( const float3& lhs, const float3& rhs );
inline bool3 operator>=( const float3& lhs, const float3& rhs );

#include "float3.inl"