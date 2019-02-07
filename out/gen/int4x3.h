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

#include "int3.h"

struct int4x3 {
	int3 rows[4];

	inline int4x3();
	inline int4x3( const int32_t diagonal );
	inline int4x3( const int3& diagonal );
	inline int4x3( const int3& row0, const int3& row1, const int3& row2, const int3& row3 );
	inline int4x3( const int3 rows[4] );
	inline int4x3( const int32_t m00, const int32_t m01, const int32_t m02, const int32_t m10, const int32_t m11, const int32_t m12, const int32_t m20, const int32_t m21, const int32_t m22, const int32_t m30, const int32_t m31, const int32_t m32 );
	inline int4x3( const int4x3& other );
	inline ~int4x3() {}

	inline int4x3 operator=( const int4x3& other );

	inline int4x3 operator+( const int32_t rhs ) const;
	inline int4x3 operator+=( const int32_t rhs );
	inline int4x3 operator+( const int4x3& rhs ) const;
	inline int4x3 operator+=( const int4x3& rhs );
	inline int4x3 operator-( const int32_t rhs ) const;
	inline int4x3 operator-=( const int32_t rhs );
	inline int4x3 operator-( const int4x3& rhs ) const;
	inline int4x3 operator-=( const int4x3& rhs );
	inline int4x3 operator*( const int32_t rhs ) const;
	inline int4x3 operator*=( const int32_t rhs );
	inline int4x3 operator*( const int4x3& rhs ) const;
	inline int4x3 operator*=( const int4x3& rhs );
	inline int4x3 operator/( const int32_t rhs ) const;
	inline int4x3 operator/=( const int32_t rhs );
	inline int4x3 operator/( const int4x3& rhs ) const;
	inline int4x3 operator/=( const int4x3& rhs );

	inline int3& operator[]( const uint32_t index );
	inline const int3& operator[]( const uint32_t index ) const;
};

inline bool operator==( const int4x3& lhs, const int4x3& rhs );
inline bool operator!=( const int4x3& lhs, const int4x3& rhs );

#include "int4x3.inl"