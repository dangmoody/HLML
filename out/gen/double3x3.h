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

#include "double3.h"

struct double3x3 {
	double3 rows[3];

	inline double3x3();
	inline double3x3( const double diagonal );
	inline double3x3( const double3& diagonal );
	inline double3x3( const double3& row0, const double3& row1, const double3& row2 );
	inline double3x3( const double3 rows[3] );
	inline double3x3( const double m00, const double m01, const double m02, const double m10, const double m11, const double m12, const double m20, const double m21, const double m22 );
	inline double3x3( const double3x3& other );
	inline ~double3x3() {}

	inline double3x3 operator=( const double3x3& other );

	inline double3& operator[]( const uint32_t index );
	inline const double3& operator[]( const uint32_t index ) const;
};

inline bool operator==( const double3x3& lhs, const double3x3& rhs );
inline bool operator!=( const double3x3& lhs, const double3x3& rhs );

#include "double3x3.inl"