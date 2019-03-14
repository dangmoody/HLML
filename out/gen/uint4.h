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

struct uint2;
struct uint3;
struct float3;

/// \brief A vector of 4 uint32_ts with components xyzw and/or rgba.
/// Components are also stored as elements in an array via a union.
struct uint4 {
	union {
		struct {
			uint32_t x;
			uint32_t y;
			uint32_t z;
			uint32_t w;
		};

		struct {
			uint32_t r;
			uint32_t g;
			uint32_t b;
			uint32_t a;
		};

		uint32_t data[4] = { 0 };
	};

	/// Default constructor.  Initializes all values to zero.
	inline uint4();

	/// Initializes all components of the vector to the given scalar value.
	inline explicit uint4( const uint32_t x );

	/// Sets the xyzw members of the vector to the corresponding parameters.
	inline uint4( const uint32_t x, const uint32_t y, const uint32_t z, const uint32_t w );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline uint4( const uint2& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline uint4( const uint3& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline uint4( const uint4& other );

	~uint4() {}

	/// Copies the elements of the given vector via memcpy.
	inline uint4 operator=( const uint2& rhs );

	/// Copies the elements of the given vector via memcpy.
	inline uint4 operator=( const uint3& rhs );

	/// Copies the elements of the given vector via memcpy.
	inline uint4 operator=( const uint4& rhs );

	/// Returns a copy of the vector with each value added the given scalar value.
	inline uint4 operator+( const uint32_t rhs ) const;
	/// Adds each component of the vector by the given scalar value.
	inline uint4 operator+=( const uint32_t rhs );
	/// Returns a copy of the vector that has been component-wise added by the other vector.
	inline uint4 operator+( const uint4& rhs ) const;
	/// Component-wise adds each component of the vector by the other vector.
	inline uint4 operator+=( const uint4& rhs );
	/// Returns a copy of the vector with each value subtracted the given scalar value.
	inline uint4 operator-( const uint32_t rhs ) const;
	/// Subtracts each component of the vector by the given scalar value.
	inline uint4 operator-=( const uint32_t rhs );
	/// Returns a copy of the vector that has been component-wise subtracted by the other vector.
	inline uint4 operator-( const uint4& rhs ) const;
	/// Component-wise subtracts each component of the vector by the other vector.
	inline uint4 operator-=( const uint4& rhs );
	/// Returns a copy of the vector with each value multiplied the given scalar value.
	inline uint4 operator*( const uint32_t rhs ) const;
	/// Multiplies each component of the vector by the given scalar value.
	inline uint4 operator*=( const uint32_t rhs );
	/// Returns a copy of the vector that has been component-wise multiplied by the other vector.
	inline uint4 operator*( const uint4& rhs ) const;
	/// Component-wise multiplies each component of the vector by the other vector.
	inline uint4 operator*=( const uint4& rhs );
	/// Returns a copy of the vector with each value divided the given scalar value.
	inline uint4 operator/( const uint32_t rhs ) const;
	/// Divides each component of the vector by the given scalar value.
	inline uint4 operator/=( const uint32_t rhs );
	/// Returns a copy of the vector that has been component-wise divided by the other vector.
	inline uint4 operator/( const uint4& rhs ) const;
	/// Component-wise divides each component of the vector by the other vector.
	inline uint4 operator/=( const uint4& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline const uint32_t& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline uint32_t& operator[]( const uint32_t index );

};

/// \relates uint4
/// \brief Returns true if the all the components of the left-hand-side uint4 match the other one, otherwise returns false.
inline bool operator==( const uint4& lhs, const uint4& rhs );

/// \relates uint4
/// \brief Returns true if not all of the components of the left-hand-side uint4 match the other one, otherwise returns false.
inline bool operator!=( const uint4& lhs, const uint4& rhs );

inline bool4 operator<( const uint4& lhs, const uint4& rhs );
inline bool4 operator<=( const uint4& lhs, const uint4& rhs );
inline bool4 operator>( const uint4& lhs, const uint4& rhs );
inline bool4 operator>=( const uint4& lhs, const uint4& rhs );

#include "uint4.inl"