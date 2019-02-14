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

struct uint2;
struct uint3;
struct float3;

struct uint4 {
	union {
		struct {
			uint32_t x;
			uint32_t y;
			uint32_t z;
			uint32_t w;
		};

		struct {
			uint32_t r;
			uint32_t g;
			uint32_t b;
			uint32_t a;
		};

		uint32_t data[4] = { 0 };
	};

	inline uint4();
	inline explicit uint4( const uint32_t x );
	inline uint4( const uint32_t x, const uint32_t y, const uint32_t z, const uint32_t w );
	inline uint4( const uint2& other );
	inline uint4( const uint3& other );
	inline uint4( const uint4& other );
	~uint4() {}

	inline uint4 operator=( const uint2& rhs );
	inline uint4 operator=( const uint3& rhs );
	inline uint4 operator=( const uint4& rhs );

	inline uint4 operator+( const uint32_t rhs ) const;
	inline uint4 operator+=( const uint32_t rhs );
	inline uint4 operator+( const uint4& rhs ) const;
	inline uint4 operator+=( const uint4& rhs );
	inline uint4 operator-( const uint32_t rhs ) const;
	inline uint4 operator-=( const uint32_t rhs );
	inline uint4 operator-( const uint4& rhs ) const;
	inline uint4 operator-=( const uint4& rhs );
	inline uint4 operator*( const uint32_t rhs ) const;
	inline uint4 operator*=( const uint32_t rhs );
	inline uint4 operator*( const uint4& rhs ) const;
	inline uint4 operator*=( const uint4& rhs );
	inline uint4 operator/( const uint32_t rhs ) const;
	inline uint4 operator/=( const uint32_t rhs );
	inline uint4 operator/( const uint4& rhs ) const;
	inline uint4 operator/=( const uint4& rhs );

	inline const uint32_t& operator[]( const uint32_t index ) const;
	inline uint32_t& operator[]( const uint32_t index );
};

inline bool operator==( const uint4& lhs, const uint4& rhs );
inline bool operator!=( const uint4& lhs, const uint4& rhs );

inline bool4 operator<( const uint4& lhs, const uint4& rhs );
inline bool4 operator<=( const uint4& lhs, const uint4& rhs );
inline bool4 operator>( const uint4& lhs, const uint4& rhs );
inline bool4 operator>=( const uint4& lhs, const uint4& rhs );

#include "uint4.inl"