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

struct uint2;
struct uint4;
struct float3;

// ignore prohibition of anymous structs for GCC
#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

/// \brief A vector of 3 uint32_ts with components xyz and/or rgb.
/// Components are also stored as elements in an array via a union.
struct uint3
{
	union
	{
		struct
		{
			uint32_t x;
			uint32_t y;
			uint32_t z;
		};

		struct
		{
			uint32_t r;
			uint32_t g;
			uint32_t b;
		};

		uint32_t data[3] = { 0 };
	};

	/// Default constructor.  Initializes all values to zero.
	inline uint3();

	/// Initializes all components of the vector to the given scalar value.
	inline explicit uint3( const uint32_t x );

	/// Sets the xyz members of the vector to the corresponding parameters.
	inline uint3( const uint32_t x, const uint32_t y, const uint32_t z );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline uint3( const uint2& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline uint3( const uint3& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline uint3( const uint4& other );

	~uint3() {}

	/// Copies the elements of the given vector via a single memcpy.
	inline uint3 operator=( const uint2& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline uint3 operator=( const uint3& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline uint3 operator=( const uint4& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 2.
	inline const uint32_t& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 2.
	inline uint32_t& operator[]( const uint32_t index );

	// swizzle funcs
	inline uint2 xx() const { return uint2( x, x ); }
	inline uint2 yx() const { return uint2( y, x ); }
	inline uint2 xy() const { return uint2( x, y ); }
	inline uint2 yy() const { return uint2( y, y ); }

	inline uint3 xxx() const { return uint3( x, x, x ); }
	inline uint3 yxx() const { return uint3( y, x, x ); }
	inline uint3 zxx() const { return uint3( z, x, x ); }
	inline uint3 xyx() const { return uint3( x, y, x ); }
	inline uint3 yyx() const { return uint3( y, y, x ); }
	inline uint3 zyx() const { return uint3( z, y, x ); }
	inline uint3 xzx() const { return uint3( x, z, x ); }
	inline uint3 yzx() const { return uint3( y, z, x ); }
	inline uint3 zzx() const { return uint3( z, z, x ); }
	inline uint3 xxy() const { return uint3( x, x, y ); }
	inline uint3 yxy() const { return uint3( y, x, y ); }
	inline uint3 zxy() const { return uint3( z, x, y ); }
	inline uint3 xyy() const { return uint3( x, y, y ); }
	inline uint3 yyy() const { return uint3( y, y, y ); }
	inline uint3 zyy() const { return uint3( z, y, y ); }
	inline uint3 xzy() const { return uint3( x, z, y ); }
	inline uint3 yzy() const { return uint3( y, z, y ); }
	inline uint3 zzy() const { return uint3( z, z, y ); }
	inline uint3 xxz() const { return uint3( x, x, z ); }
	inline uint3 yxz() const { return uint3( y, x, z ); }
	inline uint3 zxz() const { return uint3( z, x, z ); }
	inline uint3 xyz() const { return uint3( x, y, z ); }
	inline uint3 yyz() const { return uint3( y, y, z ); }
	inline uint3 zyz() const { return uint3( z, y, z ); }
	inline uint3 xzz() const { return uint3( x, z, z ); }
	inline uint3 yzz() const { return uint3( y, z, z ); }
	inline uint3 zzz() const { return uint3( z, z, z ); }

};

#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/// \relates uint3
/// \brief Returns true if the all the components of the left-hand-side uint3 match the other one, otherwise returns false.
inline bool operator==( const uint3& lhs, const uint3& rhs );

/// \relates uint3
/// \brief Returns true if not all of the components of the left-hand-side uint3 match the other one, otherwise returns false.
inline bool operator!=( const uint3& lhs, const uint3& rhs );

#include "uint3.inl"
