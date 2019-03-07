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

#include "int3.h"
#include "int2x2.h"
#include "int3x2.h"

struct int2x3 {
	int3 rows[2];

	inline int2x3();
	inline int2x3( const int32_t diagonal );
	inline int2x3( const int3& diagonal );
	inline int2x3( const int3& row0, const int3& row1 );
	inline int2x3( const int3 rows[2] );
	inline int2x3( const int32_t m00, const int32_t m01, const int32_t m02, const int32_t m10, const int32_t m11, const int32_t m12 );
	inline int2x3( const int2x3& other );
	inline ~int2x3() {}

	inline int2x3 operator=( const int2x3& other );

	inline int3& operator[]( const uint32_t index );
	inline const int3& operator[]( const uint32_t index ) const;
};

inline bool operator==( const int2x3& lhs, const int2x3& rhs );
inline bool operator!=( const int2x3& lhs, const int2x3& rhs );

#include "int2x3.inl"