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
#include "../hlml_types.h"

struct float2;
struct float4;
struct float3;

// ignore prohibition of anymous structs for GCC
#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#elif defined( _MSC_VER )
#pragma warning( push )
#pragma warning( disable : 4201 ) // C4201 - nonstandard extension used : nameless struct/union
#endif

/// \brief A vector of 3 floats with components xyz and/or rgb.
/// Components are also stored as elements in an array via a union.
struct float3
{
	union
	{
		struct
		{
			float x;
			float y;
			float z;
		};

		struct
		{
			float r;
			float g;
			float b;
		};

		float data[3] = { 0 };
	};

	/// Default constructor.  Initializes all values to zero.
	inline float3();

	/// Initializes all components of the vector to the given scalar value.
	inline explicit float3( const float x );

	/// Sets the xyz members of the vector to the corresponding parameters.
	inline float3( const float x, const float y, const float z );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline float3( const float2& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline float3( const float3& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline float3( const float4& other );

	~float3() {}

	/// Copies the elements of the given vector via a single memcpy.
	inline float3 operator=( const float2& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline float3 operator=( const float3& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline float3 operator=( const float4& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 2.
	inline const float& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 2.
	inline float& operator[]( const uint32_t index );

	// swizzle funcs
	inline float2 xx() const { return float2( x, x ); }
	inline float2 yx() const { return float2( y, x ); }
	inline float2 xy() const { return float2( x, y ); }
	inline float2 yy() const { return float2( y, y ); }

	inline float3 xxx() const { return float3( x, x, x ); }
	inline float3 yxx() const { return float3( y, x, x ); }
	inline float3 zxx() const { return float3( z, x, x ); }
	inline float3 xyx() const { return float3( x, y, x ); }
	inline float3 yyx() const { return float3( y, y, x ); }
	inline float3 zyx() const { return float3( z, y, x ); }
	inline float3 xzx() const { return float3( x, z, x ); }
	inline float3 yzx() const { return float3( y, z, x ); }
	inline float3 zzx() const { return float3( z, z, x ); }
	inline float3 xxy() const { return float3( x, x, y ); }
	inline float3 yxy() const { return float3( y, x, y ); }
	inline float3 zxy() const { return float3( z, x, y ); }
	inline float3 xyy() const { return float3( x, y, y ); }
	inline float3 yyy() const { return float3( y, y, y ); }
	inline float3 zyy() const { return float3( z, y, y ); }
	inline float3 xzy() const { return float3( x, z, y ); }
	inline float3 yzy() const { return float3( y, z, y ); }
	inline float3 zzy() const { return float3( z, z, y ); }
	inline float3 xxz() const { return float3( x, x, z ); }
	inline float3 yxz() const { return float3( y, x, z ); }
	inline float3 zxz() const { return float3( z, x, z ); }
	inline float3 xyz() const { return float3( x, y, z ); }
	inline float3 yyz() const { return float3( y, y, z ); }
	inline float3 zyz() const { return float3( z, y, z ); }
	inline float3 xzz() const { return float3( x, z, z ); }
	inline float3 yzz() const { return float3( y, z, z ); }
	inline float3 zzz() const { return float3( z, z, z ); }

};

#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic pop
#elif defined( _MSC_VER )
#pragma warning( pop )
#endif

/// \relates float3
/// \brief Returns true if the all the components of the left-hand-side float3 match the other one, otherwise returns false.
inline bool operator==( const float3& lhs, const float3& rhs );

/// \relates float3
/// \brief Returns true if not all of the components of the left-hand-side float3 match the other one, otherwise returns false.
inline bool operator!=( const float3& lhs, const float3& rhs );

#include "float3.inl"
