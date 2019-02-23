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

#include "double2.h"

struct double3x2 {
	double2 rows[3];

	inline double3x2();
	inline double3x2( const double diagonal );
	inline double3x2( const double2& diagonal );
	inline double3x2( const double2& row0, const double2& row1, const double2& row2 );
	inline double3x2( const double2 rows[3] );
	inline double3x2( const double m00, const double m01, const double m10, const double m11, const double m20, const double m21 );
	inline double3x2( const double3x2& other );
	inline ~double3x2() {}

	inline double3x2 operator=( const double3x2& other );
	inline double3x2 operator+( const double rhs ) const;
	inline double3x2 operator+=( const double rhs );
	inline double3x2 operator+( const double3x2& rhs ) const;
	inline double3x2 operator+=( const double3x2& rhs );
	inline double3x2 operator-( const double rhs ) const;
	inline double3x2 operator-=( const double rhs );
	inline double3x2 operator-( const double3x2& rhs ) const;
	inline double3x2 operator-=( const double3x2& rhs );
	inline double3x2 operator*( const double rhs ) const;
	inline double3x2 operator*=( const double rhs );
	inline double3x2 operator*( const double3x2& rhs ) const;
	inline double3x2 operator*=( const double3x2& rhs );
	inline double3x2 operator/( const double rhs ) const;
	inline double3x2 operator/=( const double rhs );
	inline double3x2 operator/( const double3x2& rhs ) const;
	inline double3x2 operator/=( const double3x2& rhs );

	inline double2& operator[]( const uint32_t index );
	inline const double2& operator[]( const uint32_t index ) const;
};

inline bool operator==( const double3x2& lhs, const double3x2& rhs );
inline bool operator!=( const double3x2& lhs, const double3x2& rhs );

inline bool3x2 operator<( const double3x2& lhs, const double3x2& rhs );
inline bool3x2 operator<=( const double3x2& lhs, const double3x2& rhs );
inline bool3x2 operator>( const double3x2& lhs, const double3x2& rhs );
inline bool3x2 operator>=( const double3x2& lhs, const double3x2& rhs );

#include "double3x2.inl"