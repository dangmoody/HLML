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

#include "double4.h"

struct double2x4 {
	double4 rows[2];

	inline double2x4();
	inline double2x4( const double diagonal );
	inline double2x4( const double4& diagonal );
	inline double2x4( const double4& row0, const double4& row1 );
	inline double2x4( const double4 rows[2] );
	inline double2x4( const double m00, const double m01, const double m02, const double m03, const double m10, const double m11, const double m12, const double m13 );
	inline double2x4( const double2x4& other );
	inline ~double2x4() {}

	inline double2x4 operator=( const double2x4& other );
	inline double2x4 operator+( const double rhs ) const;
	inline double2x4 operator+=( const double rhs );
	inline double2x4 operator+( const double2x4& rhs ) const;
	inline double2x4 operator+=( const double2x4& rhs );
	inline double2x4 operator-( const double rhs ) const;
	inline double2x4 operator-=( const double rhs );
	inline double2x4 operator-( const double2x4& rhs ) const;
	inline double2x4 operator-=( const double2x4& rhs );
	inline double2x4 operator*( const double rhs ) const;
	inline double2x4 operator*=( const double rhs );
	inline double2x4 operator*( const double2x4& rhs ) const;
	inline double2x4 operator*=( const double2x4& rhs );
	inline double2x4 operator/( const double rhs ) const;
	inline double2x4 operator/=( const double rhs );
	inline double2x4 operator/( const double2x4& rhs ) const;
	inline double2x4 operator/=( const double2x4& rhs );

	inline double4& operator[]( const uint32_t index );
	inline const double4& operator[]( const uint32_t index ) const;
};

inline bool operator==( const double2x4& lhs, const double2x4& rhs );
inline bool operator!=( const double2x4& lhs, const double2x4& rhs );

inline bool2x4 operator<( const double2x4& lhs, const double2x4& rhs );
inline bool2x4 operator<=( const double2x4& lhs, const double2x4& rhs );
inline bool2x4 operator>( const double2x4& lhs, const double2x4& rhs );
inline bool2x4 operator>=( const double2x4& lhs, const double2x4& rhs );

#include "double2x4.inl"