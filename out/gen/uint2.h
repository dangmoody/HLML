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

// GENERATED FILE.  DO NOT EDIT.

#pragma once

#include "bool2.h"

struct uint3;
struct uint4;

struct uint2 {
	union {
		struct {
			uint32_t x;
			uint32_t y;
		};

		struct {
			uint32_t r;
			uint32_t g;
		};

		uint32_t data[2] = { 0 };
	};

	inline uint2();
	inline explicit uint2( const uint32_t x );
	inline uint2( const uint32_t x, const uint32_t y );
	inline uint2( const uint2& other );
	inline uint2( const uint3& other );
	inline uint2( const uint4& other );
	~uint2() {}

	inline uint2 operator=( const uint2& rhs );
	inline uint2 operator=( const uint3& rhs );
	inline uint2 operator=( const uint4& rhs );

	inline uint2 operator+( const uint32_t rhs ) const;
	inline uint2 operator+=( const uint32_t rhs );
	inline uint2 operator+( const uint2& rhs ) const;
	inline uint2 operator+=( const uint2& rhs );
	inline uint2 operator-( const uint32_t rhs ) const;
	inline uint2 operator-=( const uint32_t rhs );
	inline uint2 operator-( const uint2& rhs ) const;
	inline uint2 operator-=( const uint2& rhs );
	inline uint2 operator*( const uint32_t rhs ) const;
	inline uint2 operator*=( const uint32_t rhs );
	inline uint2 operator*( const uint2& rhs ) const;
	inline uint2 operator*=( const uint2& rhs );
	inline uint2 operator/( const uint32_t rhs ) const;
	inline uint2 operator/=( const uint32_t rhs );
	inline uint2 operator/( const uint2& rhs ) const;
	inline uint2 operator/=( const uint2& rhs );

	inline const uint32_t& operator[]( const uint32_t index ) const;
	inline uint32_t& operator[]( const uint32_t index );
};

inline bool operator==( const uint2& lhs, const uint2& rhs );
inline bool operator!=( const uint2& lhs, const uint2& rhs );

inline bool2 operator<( const uint2& lhs, const uint2& rhs );
inline bool2 operator<=( const uint2& lhs, const uint2& rhs );
inline bool2 operator>( const uint2& lhs, const uint2& rhs );
inline bool2 operator>=( const uint2& lhs, const uint2& rhs );

#include "uint2.inl"