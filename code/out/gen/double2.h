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

#include "bool2.h"

#include <stdint.h>

struct double3;
struct double4;

/// \brief A vector of 2 doubles with components xy and/or rg.
/// Components are also stored as elements in an array via a union.
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

	/// Default constructor.  Initializes all values to zero.
	inline double2();

	/// Initializes all components of the vector to the given scalar value.
	inline explicit double2( const double x );

	/// Sets the xy members of the vector to the corresponding parameters.
	inline double2( const double x, const double y );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline double2( const double2& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline double2( const double3& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline double2( const double4& other );

	~double2() {}

	/// Copies the elements of the given vector via a single memcpy.
	inline double2 operator=( const double2& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline double2 operator=( const double3& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline double2 operator=( const double4& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 1.
	inline const double& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 1.
	inline double& operator[]( const uint32_t index );
};

/// \relates double2
/// \brief Returns true if the all the components of the left-hand-side double2 match the other one, otherwise returns false.
inline bool operator==( const double2& lhs, const double2& rhs );

/// \relates double2
/// \brief Returns true if not all of the components of the left-hand-side double2 match the other one, otherwise returns false.
inline bool operator!=( const double2& lhs, const double2& rhs );

#include "double2.inl"