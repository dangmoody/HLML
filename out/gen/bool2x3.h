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

#include "bool3.h"

struct bool2x3 {
	bool3 rows[2];

	inline bool2x3();
	inline bool2x3( const bool diagonal );
	inline bool2x3( const bool3& diagonal );
	inline bool2x3( const bool3& row0, const bool3& row1 );
	inline bool2x3( const bool3 rows[2] );
	inline bool2x3( const bool m00, const bool m01, const bool m02, const bool m10, const bool m11, const bool m12 );
	inline bool2x3( const bool2x3& other );
	inline ~bool2x3() {}

	inline bool2x3 operator=( const bool2x3& other );

	inline bool3& operator[]( const uint32_t index );
	inline const bool3& operator[]( const uint32_t index ) const;
};

inline bool operator==( const bool2x3& lhs, const bool2x3& rhs );
inline bool operator!=( const bool2x3& lhs, const bool2x3& rhs );

#include "bool2x3.inl"