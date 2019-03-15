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

/// \brief A vector of 2 floats with components xy and/or rg.
/// Components are also stored as elements in an array via a union.
struct float2 {
	union {
		struct {
			float x;
			float y;
		};

		struct {
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

	/// Copies the elements of the given vector via memcpy.
	inline float2 operator=( const float2& rhs );

	/// Copies the elements of the given vector via memcpy.
	inline float2 operator=( const float3& rhs );

	/// Copies the elements of the given vector via memcpy.
	inline float2 operator=( const float4& rhs );

	/// Returns a copy of the vector with each value added the given scalar value.
	inline float2 operator+( const float rhs ) const;

	/// \relates float2
	/// \brief Adds each component by the given scalar value.
	inline float2 operator+=( const float rhs );

	/// Returns a copy of the vector that has been component-wise added by the other vector.
	inline float2 operator+( const float2& rhs ) const;

	/// Component-wise adds each component of the vector by the other vector.
	inline float2 operator+=( const float2& rhs );

	/// Returns a copy of the vector with each value subtracted the given scalar value.
	inline float2 operator-( const float rhs ) const;

	/// \relates float2
	/// \brief Subtracts each component by the given scalar value.
	inline float2 operator-=( const float rhs );

	/// Returns a copy of the vector that has been component-wise subtracted by the other vector.
	inline float2 operator-( const float2& rhs ) const;

	/// Component-wise subtracts each component of the vector by the other vector.
	inline float2 operator-=( const float2& rhs );

	/// Returns a copy of the vector with each value multiplied the given scalar value.
	inline float2 operator*( const float rhs ) const;

	/// \relates float2
	/// \brief Multiplies each component by the given scalar value.
	inline float2 operator*=( const float rhs );

	/// Returns a copy of the vector that has been component-wise multiplied by the other vector.
	inline float2 operator*( const float2& rhs ) const;

	/// Component-wise multiplies each component of the vector by the other vector.
	inline float2 operator*=( const float2& rhs );

	/// Returns a copy of the vector with each value divided the given scalar value.
	inline float2 operator/( const float rhs ) const;

	/// \relates float2
	/// \brief Divides each component by the given scalar value.
	inline float2 operator/=( const float rhs );

	/// Returns a copy of the vector that has been component-wise divided by the other vector.
	inline float2 operator/( const float2& rhs ) const;

	/// Component-wise divides each component of the vector by the other vector.
	inline float2 operator/=( const float2& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 1.
	inline const float& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 1.
	inline float& operator[]( const uint32_t index );
};

/// \relates float2
/// \brief Returns true if the all the components of the left-hand-side float2 match the other one, otherwise returns false.
inline bool operator==( const float2& lhs, const float2& rhs );

/// \relates float2
/// \brief Returns true if not all of the components of the left-hand-side float2 match the other one, otherwise returns false.
inline bool operator!=( const float2& lhs, const float2& rhs );

/// \relates float2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is less than the corresponding right-hand type component.
inline bool2 operator<( const float2& lhs, const float2& rhs );

/// \relates float2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is less than or equal to the corresponding right-hand type component.
inline bool2 operator<=( const float2& lhs, const float2& rhs );

/// \relates float2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is greater than the corresponding right-hand type component.
inline bool2 operator>( const float2& lhs, const float2& rhs );

/// \relates float2
/// \brief Returns a bool2 where each component is true if the component of the left-hand type is greater than or equal to the corresponding right-hand type component.
inline bool2 operator>=( const float2& lhs, const float2& rhs );


#include "float2.inl"