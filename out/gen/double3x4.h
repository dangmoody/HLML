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

#include "double4.h"

struct double3x4 {
	double4 rows[3];

	inline double3x4();
	inline double3x4( const double diagonal );
	inline double3x4( const double4& diagonal );
	inline double3x4( const double4& row0, const double4& row1, const double4& row2 );
	inline double3x4( const double4 rows[3] );
	inline double3x4( const double m00, const double m01, const double m02, const double m03, const double m10, const double m11, const double m12, const double m13, const double m20, const double m21, const double m22, const double m23 );
	inline double3x4( const double3x4& other );
	inline ~double3x4() {}

	inline double3x4 operator=( const double3x4& other );
	inline double3x4 operator+( const double rhs ) const;
	inline double3x4 operator+=( const double rhs );
	inline double3x4 operator+( const double3x4& rhs ) const;
	inline double3x4 operator+=( const double3x4& rhs );
	inline double3x4 operator-( const double rhs ) const;
	inline double3x4 operator-=( const double rhs );
	inline double3x4 operator-( const double3x4& rhs ) const;
	inline double3x4 operator-=( const double3x4& rhs );
	inline double3x4 operator*( const double rhs ) const;
	inline double3x4 operator*=( const double rhs );
	inline double3x4 operator*( const double3x4& rhs ) const;
	inline double3x4 operator*=( const double3x4& rhs );
	inline double3x4 operator/( const double rhs ) const;
	inline double3x4 operator/=( const double rhs );
	inline double3x4 operator/( const double3x4& rhs ) const;
	inline double3x4 operator/=( const double3x4& rhs );

	inline double4& operator[]( const uint32_t index );
	inline const double4& operator[]( const uint32_t index ) const;
};

inline bool operator==( const double3x4& lhs, const double3x4& rhs );
inline bool operator!=( const double3x4& lhs, const double3x4& rhs );

#include "double3x4.inl"