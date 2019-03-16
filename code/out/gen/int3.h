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

struct int2;
struct int4;
struct float3;

/// \brief A vector of 3 int32_ts with components xyz and/or rgb.
/// Components are also stored as elements in an array via a union.
struct int3 {
	union {
		struct {
			int32_t x;
			int32_t y;
			int32_t z;
		};

		struct {
			int32_t r;
			int32_t g;
			int32_t b;
		};

		int32_t data[3] = { 0 };
	};

	/// Default constructor.  Initializes all values to zero.
	inline int3();

	/// Initializes all components of the vector to the given scalar value.
	inline explicit int3( const int32_t x );

	/// Sets the xyz members of the vector to the corresponding parameters.
	inline int3( const int32_t x, const int32_t y, const int32_t z );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline int3( const int2& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline int3( const int3& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline int3( const int4& other );

	~int3() {}

	/// Copies the elements of the given vector via a single memcpy.
	inline int3 operator=( const int2& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline int3 operator=( const int3& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline int3 operator=( const int4& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 2.
	inline const int32_t& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 2.
	inline int32_t& operator[]( const uint32_t index );
};

/// \relates int3
/// \brief Returns true if the all the components of the left-hand-side int3 match the other one, otherwise returns false.
inline bool operator==( const int3& lhs, const int3& rhs );

/// \relates int3
/// \brief Returns true if not all of the components of the left-hand-side int3 match the other one, otherwise returns false.
inline bool operator!=( const int3& lhs, const int3& rhs );

#include "int3.inl"