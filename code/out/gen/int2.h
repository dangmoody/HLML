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
#include "../hlml_types.h"

struct int3;
struct int4;

// ignore prohibition of anymous structs for GCC
#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#elif defined( _MSC_VER )
#pragma warning( push )
#pragma warning( disable : 4201 ) // C4201 - nonstandard extension used : nameless struct/union
#endif

/// \brief A vector of 2 int32_ts with components xy.
/// Components are also stored as elements in an array via a union.
struct int2
{
	union
	{
		struct
		{
			int32_t x;
			int32_t y;
		};

		struct
		{
			int32_t r;
			int32_t g;
		};

		int32_t data[2] = { 0 };
	};

	/// Default constructor.  Initializes all values to zero.
	inline int2();

	/// Initializes all components of the vector to the given scalar value.
	inline explicit int2( const int32_t x );

	/// Sets the xy members of the vector to the corresponding parameters.
	inline int2( const int32_t x, const int32_t y );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline int2( const int2& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline int2( const int3& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline int2( const int4& other );

	~int2() {}

	/// Copies the elements of the given vector via a single memcpy.
	inline int2 operator=( const int2& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline int2 operator=( const int3& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline int2 operator=( const int4& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 1.
	inline const int32_t& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 1.
	inline int32_t& operator[]( const uint32_t index );

	// swizzle funcs
	inline int2 xx() const { return int2( x, x ); }
	inline int2 yx() const { return int2( y, x ); }
	inline int2 xy() const { return int2( x, y ); }
	inline int2 yy() const { return int2( y, y ); }

};

#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic pop
#elif defined( _MSC_VER )
#pragma warning( pop )
#endif

/// \relates int2
/// \brief Returns true if the all the components of the left-hand-side int2 match the other one, otherwise returns false.
inline bool operator==( const int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Returns true if not all of the components of the left-hand-side int2 match the other one, otherwise returns false.
inline bool operator!=( const int2& lhs, const int2& rhs );

#include "int2.inl"
