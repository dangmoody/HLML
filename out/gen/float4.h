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

#include "bool4.h"

#include <stdint.h>

struct float2;
struct float3;
struct float3;

/// \brief A vector of 4 floats with components xyzw and/or rgba.
/// Components are also stored as elements in an array via a union.
struct float4 {
	union {
		struct {
			float x;
			float y;
			float z;
			float w;
		};

		struct {
			float r;
			float g;
			float b;
			float a;
		};

		float data[4] = { 0 };
	};

	/// Default constructor.  Initializes all values to zero.
	inline float4();

	/// Initializes all components of the vector to the given scalar value.
	inline explicit float4( const float x );

	/// Sets the xyzw members of the vector to the corresponding parameters.
	inline float4( const float x, const float y, const float z, const float w );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline float4( const float2& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline float4( const float3& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline float4( const float4& other );

	~float4() {}

	/// Copies the elements of the given vector via memcpy.
	inline float4 operator=( const float2& rhs );

	/// Copies the elements of the given vector via memcpy.
	inline float4 operator=( const float3& rhs );

	/// Copies the elements of the given vector via memcpy.
	inline float4 operator=( const float4& rhs );

	/// Returns a copy of the vector with each value added the given scalar value.
	inline float4 operator+( const float rhs ) const;
	/// Adds each component of the vector by the given scalar value.
	inline float4 operator+=( const float rhs );
	/// Returns a copy of the vector that has been component-wise added by the other vector.
	inline float4 operator+( const float4& rhs ) const;
	/// Component-wise adds each component of the vector by the other vector.
	inline float4 operator+=( const float4& rhs );
	/// Returns a copy of the vector with each value subtracted the given scalar value.
	inline float4 operator-( const float rhs ) const;
	/// Subtracts each component of the vector by the given scalar value.
	inline float4 operator-=( const float rhs );
	/// Returns a copy of the vector that has been component-wise subtracted by the other vector.
	inline float4 operator-( const float4& rhs ) const;
	/// Component-wise subtracts each component of the vector by the other vector.
	inline float4 operator-=( const float4& rhs );
	/// Returns a copy of the vector with each value multiplied the given scalar value.
	inline float4 operator*( const float rhs ) const;
	/// Multiplies each component of the vector by the given scalar value.
	inline float4 operator*=( const float rhs );
	/// Returns a copy of the vector that has been component-wise multiplied by the other vector.
	inline float4 operator*( const float4& rhs ) const;
	/// Component-wise multiplies each component of the vector by the other vector.
	inline float4 operator*=( const float4& rhs );
	/// Returns a copy of the vector with each value divided the given scalar value.
	inline float4 operator/( const float rhs ) const;
	/// Divides each component of the vector by the given scalar value.
	inline float4 operator/=( const float rhs );
	/// Returns a copy of the vector that has been component-wise divided by the other vector.
	inline float4 operator/( const float4& rhs ) const;
	/// Component-wise divides each component of the vector by the other vector.
	inline float4 operator/=( const float4& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline const float& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline float& operator[]( const uint32_t index );

};

/// \relates float4
/// \brief Returns true if the all the components of the left-hand-side float4 match the other one, otherwise returns false.
inline bool operator==( const float4& lhs, const float4& rhs );

/// \relates float4
/// \brief Returns true if not all of the components of the left-hand-side float4 match the other one, otherwise returns false.
inline bool operator!=( const float4& lhs, const float4& rhs );

	/// \relates float4
	/// \brief Returns a bool4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4 operator<( const float4& lhs, const float4& rhs );
	/// \relates float4
	/// \brief Returns a bool4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4 operator<=( const float4& lhs, const float4& rhs );
	/// \relates float4
	/// \brief Returns a bool4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4 operator>( const float4& lhs, const float4& rhs );
	/// \relates float4
	/// \brief Returns a bool4 where each component is true if the component of the left-hand vector is less than than the corresponding rhs-hand vector component.
inline bool4 operator>=( const float4& lhs, const float4& rhs );

#include "float4.inl"