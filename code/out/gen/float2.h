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

struct float3;
struct float4;

// ignore prohibition of anymous structs for GCC
#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#elif defined( _MSC_VER )
#pragma warning( push )
#pragma warning( disable : 4201 ) // C4201 - nonstandard extension used : nameless struct/union
#endif

/// \brief A vector of 2 floats with components xy and/or rg.
/// Components are also stored as elements in an array via a union.
struct float2
{
	union
	{
		struct
		{
			float x;
			float y;
		};

		struct
		{
			float r;
			float g;
		};

		float data[2] = { 0 };
	};

	/// Default constructor.  Initializes all values to zero.
	inline float2();

	/// Initializes all components of the vector to the given scalar value.
	inline explicit float2( const float x );

	/// Sets the xy members of the vector to the corresponding parameters.
	inline float2( const float x, const float y );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline float2( const float2& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline float2( const float3& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline float2( const float4& other );

	~float2() {}

	/// Copies the elements of the given vector via a single memcpy.
	inline float2 operator=( const float2& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline float2 operator=( const float3& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline float2 operator=( const float4& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 1.
	inline const float& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 1.
	inline float& operator[]( const uint32_t index );

	// swizzle funcs
	inline float2 xx() const { return float2( x, x ); }
	inline float2 yx() const { return float2( y, x ); }
	inline float2 xy() const { return float2( x, y ); }
	inline float2 yy() const { return float2( y, y ); }

};

#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic pop
#elif defined( _MSC_VER )
#pragma warning( pop )
#endif

/// \relates float2
/// \brief Returns true if the all the components of the left-hand-side float2 match the other one, otherwise returns false.
inline bool operator==( const float2& lhs, const float2& rhs );

/// \relates float2
/// \brief Returns true if not all of the components of the left-hand-side float2 match the other one, otherwise returns false.
inline bool operator!=( const float2& lhs, const float2& rhs );

#include "float2.inl"
