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

#include "uint4.h"

struct uint4x4 {
	uint4 rows[4];

	inline uint4x4();
	inline uint4x4( const uint32_t diagonal );
	inline uint4x4( const uint4& diagonal );
	inline uint4x4( const uint4& row0, const uint4& row1, const uint4& row2, const uint4& row3 );
	inline uint4x4( const uint4 rows[4] );
	inline uint4x4( const uint32_t m00, const uint32_t m01, const uint32_t m02, const uint32_t m03, const uint32_t m10, const uint32_t m11, const uint32_t m12, const uint32_t m13, const uint32_t m20, const uint32_t m21, const uint32_t m22, const uint32_t m23, const uint32_t m30, const uint32_t m31, const uint32_t m32, const uint32_t m33 );
	inline uint4x4( const uint4x4& other );
	inline ~uint4x4() {}

	inline uint4x4 operator=( const uint4x4& other );

	inline uint4& operator[]( const uint32_t index );
	inline const uint4& operator[]( const uint32_t index ) const;
};

inline bool operator==( const uint4x4& lhs, const uint4x4& rhs );
inline bool operator!=( const uint4x4& lhs, const uint4x4& rhs );

#include "uint4x4.inl"