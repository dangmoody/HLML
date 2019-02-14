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

#include "bool2.h"

struct bool3x2 {
	bool2 rows[3];

	inline bool3x2();
	inline bool3x2( const bool diagonal );
	inline bool3x2( const bool2& diagonal );
	inline bool3x2( const bool2& row0, const bool2& row1, const bool2& row2 );
	inline bool3x2( const bool2 rows[3] );
	inline bool3x2( const bool m00, const bool m01, const bool m10, const bool m11, const bool m20, const bool m21 );
	inline bool3x2( const bool3x2& other );
	inline ~bool3x2() {}

	inline bool3x2 operator=( const bool3x2& other );

	inline bool2& operator[]( const uint32_t index );
	inline const bool2& operator[]( const uint32_t index ) const;
};

inline bool operator==( const bool3x2& lhs, const bool3x2& rhs );
inline bool operator!=( const bool3x2& lhs, const bool3x2& rhs );

#include "bool3x2.inl"