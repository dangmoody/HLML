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

#include "bool4.h"

struct bool4x4 {
	bool4 rows[4];

	inline bool4x4();
	inline bool4x4( const bool diagonal );
	inline bool4x4( const bool4& diagonal );
	inline bool4x4( const bool4& row0, const bool4& row1, const bool4& row2, const bool4& row3 );
	inline bool4x4( const bool4 rows[4] );
	inline bool4x4( const bool m00, const bool m01, const bool m02, const bool m03, const bool m10, const bool m11, const bool m12, const bool m13, const bool m20, const bool m21, const bool m22, const bool m23, const bool m30, const bool m31, const bool m32, const bool m33 );
	inline bool4x4( const bool4x4& other );
	inline ~bool4x4() {}

	inline bool4x4 operator=( const bool4x4& other );

	inline bool4& operator[]( const uint32_t index );
	inline const bool4& operator[]( const uint32_t index ) const;
};

inline bool operator==( const bool4x4& lhs, const bool4x4& rhs );
inline bool operator!=( const bool4x4& lhs, const bool4x4& rhs );

#include "bool4x4.inl"