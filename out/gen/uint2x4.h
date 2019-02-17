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

#include "uint4.h"

struct uint2x4 {
	uint4 rows[2];

	inline uint2x4();
	inline uint2x4( const uint32_t diagonal );
	inline uint2x4( const uint4& diagonal );
	inline uint2x4( const uint4& row0, const uint4& row1 );
	inline uint2x4( const uint4 rows[2] );
	inline uint2x4( const uint32_t m00, const uint32_t m01, const uint32_t m02, const uint32_t m03, const uint32_t m10, const uint32_t m11, const uint32_t m12, const uint32_t m13 );
	inline uint2x4( const uint2x4& other );
	inline ~uint2x4() {}

	inline uint2x4 operator=( const uint2x4& other );
	inline uint2x4 operator+( const uint32_t rhs ) const;
	inline uint2x4 operator+=( const uint32_t rhs );
	inline uint2x4 operator+( const uint2x4& rhs ) const;
	inline uint2x4 operator+=( const uint2x4& rhs );
	inline uint2x4 operator-( const uint32_t rhs ) const;
	inline uint2x4 operator-=( const uint32_t rhs );
	inline uint2x4 operator-( const uint2x4& rhs ) const;
	inline uint2x4 operator-=( const uint2x4& rhs );
	inline uint2x4 operator*( const uint32_t rhs ) const;
	inline uint2x4 operator*=( const uint32_t rhs );
	inline uint2x4 operator*( const uint2x4& rhs ) const;
	inline uint2x4 operator*=( const uint2x4& rhs );
	inline uint2x4 operator/( const uint32_t rhs ) const;
	inline uint2x4 operator/=( const uint32_t rhs );
	inline uint2x4 operator/( const uint2x4& rhs ) const;
	inline uint2x4 operator/=( const uint2x4& rhs );

	inline uint4& operator[]( const uint32_t index );
	inline const uint4& operator[]( const uint32_t index ) const;
};

inline bool operator==( const uint2x4& lhs, const uint2x4& rhs );
inline bool operator!=( const uint2x4& lhs, const uint2x4& rhs );

#include "uint2x4.inl"