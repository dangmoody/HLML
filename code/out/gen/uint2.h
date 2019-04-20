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

struct uint3;
struct uint4;

// ignore prohibition of anymous structs for GCC
#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

/// \brief A vector of 2 uint32_ts with components xy and/or rg.
/// Components are also stored as elements in an array via a union.
struct uint2
{
	union
	{
		struct
		{
			uint32_t x;
			uint32_t y;
		};

		struct
		{
			uint32_t r;
			uint32_t g;
		};

		uint32_t data[2] = { 0 };
	};

	/// Default constructor.  Initializes all values to zero.
	inline uint2();

	/// Initializes all components of the vector to the given scalar value.
	inline explicit uint2( const uint32_t x );

	/// Sets the xy members of the vector to the corresponding parameters.
	inline uint2( const uint32_t x, const uint32_t y );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline uint2( const uint2& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline uint2( const uint3& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline uint2( const uint4& other );

	~uint2() {}

	/// Copies the elements of the given vector via a single memcpy.
	inline uint2 operator=( const uint2& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline uint2 operator=( const uint3& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline uint2 operator=( const uint4& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 1.
	inline const uint32_t& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 1.
	inline uint32_t& operator[]( const uint32_t index );

	// swizzle funcs
	inline uint2 xx() const { return uint2( x, x ); }
	inline uint2 yx() const { return uint2( y, x ); }
	inline uint2 xy() const { return uint2( x, y ); }
	inline uint2 yy() const { return uint2( y, y ); }

};

#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/// \relates uint2
/// \brief Returns true if the all the components of the left-hand-side uint2 match the other one, otherwise returns false.
inline bool operator==( const uint2& lhs, const uint2& rhs );

/// \relates uint2
/// \brief Returns true if not all of the components of the left-hand-side uint2 match the other one, otherwise returns false.
inline bool operator!=( const uint2& lhs, const uint2& rhs );

#include "uint2.inl"