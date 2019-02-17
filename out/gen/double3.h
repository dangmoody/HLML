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

#include "bool3.h"

#include <stdint.h>

struct double2;
struct double4;
struct float3;

struct double3 {
	union {
		struct {
			double x;
			double y;
			double z;
		};


		struct {
			double r;
			double g;
			double b;
		};


		double data[3] = { 0 };
	};

	inline double3();
	inline explicit double3( const double x );
	inline double3( const double x, const double y, const double z );
	inline double3( const double2& other );
	inline double3( const double3& other );
	inline double3( const double4& other );
	~double3() {}

	inline double3 operator=( const double2& rhs );
	inline double3 operator=( const double3& rhs );
	inline double3 operator=( const double4& rhs );

	inline double3 operator+( const double rhs ) const;
	inline double3 operator+=( const double rhs );
	inline double3 operator+( const double3& rhs ) const;
	inline double3 operator+=( const double3& rhs );
	inline double3 operator-( const double rhs ) const;
	inline double3 operator-=( const double rhs );
	inline double3 operator-( const double3& rhs ) const;
	inline double3 operator-=( const double3& rhs );
	inline double3 operator*( const double rhs ) const;
	inline double3 operator*=( const double rhs );
	inline double3 operator*( const double3& rhs ) const;
	inline double3 operator*=( const double3& rhs );
	inline double3 operator/( const double rhs ) const;
	inline double3 operator/=( const double rhs );
	inline double3 operator/( const double3& rhs ) const;
	inline double3 operator/=( const double3& rhs );

	inline const double& operator[]( const uint32_t index ) const;
	inline double& operator[]( const uint32_t index );
};

inline bool operator==( const double3& lhs, const double3& rhs );
inline bool operator!=( const double3& lhs, const double3& rhs );

inline bool3 operator<( const double3& lhs, const double3& rhs );
inline bool3 operator<=( const double3& lhs, const double3& rhs );
inline bool3 operator>( const double3& lhs, const double3& rhs );
inline bool3 operator>=( const double3& lhs, const double3& rhs );

#include "double3.inl"