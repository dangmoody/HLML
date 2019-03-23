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

/// \brief A vector of 3 doubles with components xyz and/or rgb.
/// Components are also stored as elements in an array via a union.
struct double3
{
	union
	{
		struct
		{
			double x;
			double y;
			double z;
		};

		struct
		{
			double r;
			double g;
			double b;
		};

		double data[3] = { 0 };
	};

	/// Default constructor.  Initializes all values to zero.
	inline double3();

	/// Initializes all components of the vector to the given scalar value.
	inline explicit double3( const double x );

	/// Sets the xyz members of the vector to the corresponding parameters.
	inline double3( const double x, const double y, const double z );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline double3( const double2& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline double3( const double3& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline double3( const double4& other );

	~double3() {}

	/// Copies the elements of the given vector via a single memcpy.
	inline double3 operator=( const double2& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline double3 operator=( const double3& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline double3 operator=( const double4& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 2.
	inline const double& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 2.
	inline double& operator[]( const uint32_t index );

	// swizzle funcs
	inline double2 xx() const { return double2( x, x ); }
	inline double2 yx() const { return double2( y, x ); }
	inline double2 xy() const { return double2( x, y ); }
	inline double2 yy() const { return double2( y, y ); }

	inline double3 xxx() const { return double3( x, x, x ); }
	inline double3 yxx() const { return double3( y, x, x ); }
	inline double3 zxx() const { return double3( z, x, x ); }
	inline double3 xyx() const { return double3( x, y, x ); }
	inline double3 yyx() const { return double3( y, y, x ); }
	inline double3 zyx() const { return double3( z, y, x ); }
	inline double3 xzx() const { return double3( x, z, x ); }
	inline double3 yzx() const { return double3( y, z, x ); }
	inline double3 zzx() const { return double3( z, z, x ); }
	inline double3 xxy() const { return double3( x, x, y ); }
	inline double3 yxy() const { return double3( y, x, y ); }
	inline double3 zxy() const { return double3( z, x, y ); }
	inline double3 xyy() const { return double3( x, y, y ); }
	inline double3 yyy() const { return double3( y, y, y ); }
	inline double3 zyy() const { return double3( z, y, y ); }
	inline double3 xzy() const { return double3( x, z, y ); }
	inline double3 yzy() const { return double3( y, z, y ); }
	inline double3 zzy() const { return double3( z, z, y ); }
	inline double3 xxz() const { return double3( x, x, z ); }
	inline double3 yxz() const { return double3( y, x, z ); }
	inline double3 zxz() const { return double3( z, x, z ); }
	inline double3 xyz() const { return double3( x, y, z ); }
	inline double3 yyz() const { return double3( y, y, z ); }
	inline double3 zyz() const { return double3( z, y, z ); }
	inline double3 xzz() const { return double3( x, z, z ); }
	inline double3 yzz() const { return double3( y, z, z ); }
	inline double3 zzz() const { return double3( z, z, z ); }

};

/// \relates double3
/// \brief Returns true if the all the components of the left-hand-side double3 match the other one, otherwise returns false.
inline bool operator==( const double3& lhs, const double3& rhs );

/// \relates double3
/// \brief Returns true if not all of the components of the left-hand-side double3 match the other one, otherwise returns false.
inline bool operator!=( const double3& lhs, const double3& rhs );

#include "double3.inl"