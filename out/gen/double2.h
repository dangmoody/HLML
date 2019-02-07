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

// GENERATED FILE.  DO NOT EDIT.

#pragma once

#include "bool2.h"

struct double3;
struct double4;

struct double2 {
	union {
		struct {
			double x;
			double y;
		};

		struct {
			double r;
			double g;
		};

		double data[2] = { 0 };
	};

	inline double2();
	inline explicit double2( const double x );
	inline double2( const double x, const double y );
	inline double2( const double2& other );
	inline double2( const double3& other );
	inline double2( const double4& other );
	~double2() {}

	inline double2 operator=( const double2& rhs );
	inline double2 operator=( const double3& rhs );
	inline double2 operator=( const double4& rhs );

	inline double2 operator+( const double rhs ) const;
	inline double2 operator+=( const double rhs );
	inline double2 operator+( const double2& rhs ) const;
	inline double2 operator+=( const double2& rhs );
	inline double2 operator-( const double rhs ) const;
	inline double2 operator-=( const double rhs );
	inline double2 operator-( const double2& rhs ) const;
	inline double2 operator-=( const double2& rhs );
	inline double2 operator*( const double rhs ) const;
	inline double2 operator*=( const double rhs );
	inline double2 operator*( const double2& rhs ) const;
	inline double2 operator*=( const double2& rhs );
	inline double2 operator/( const double rhs ) const;
	inline double2 operator/=( const double rhs );
	inline double2 operator/( const double2& rhs ) const;
	inline double2 operator/=( const double2& rhs );

	inline const double& operator[]( const uint32_t index ) const;
	inline double& operator[]( const uint32_t index );
};

inline bool operator==( const double2& lhs, const double2& rhs );
inline bool operator!=( const double2& lhs, const double2& rhs );

inline bool2 operator<( const double2& lhs, const double2& rhs );
inline bool2 operator<=( const double2& lhs, const double2& rhs );
inline bool2 operator>( const double2& lhs, const double2& rhs );
inline bool2 operator>=( const double2& lhs, const double2& rhs );

#include "double2.inl"