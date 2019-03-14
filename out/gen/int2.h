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

struct int3;
struct int4;

/// \brief A vector of 2 int32_ts with components xy and/or rg.
/// Components are also stored as elements in an array via a union.
struct int2 {
	union {
		struct {
			int32_t x;
			int32_t y;
		};

		struct {
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

	/// Copies the elements of the given vector via memcpy.
	inline int2 operator=( const int2& rhs );

	/// Copies the elements of the given vector via memcpy.
	inline int2 operator=( const int3& rhs );

	/// Copies the elements of the given vector via memcpy.
	inline int2 operator=( const int4& rhs );

	/// Returns a copy of the vector with each value added the given scalar value.
	inline int2 operator+( const int32_t rhs ) const;
	/// Adds each component of the vector by the given scalar value.
	inline int2 operator+=( const int32_t rhs );
	/// Returns a copy of the vector that has been component-wise added by the other vector.
	inline int2 operator+( const int2& rhs ) const;
	/// Component-wise adds each component of the vector by the other vector.
	inline int2 operator+=( const int2& rhs );
	/// Returns a copy of the vector with each value subtracted the given scalar value.
	inline int2 operator-( const int32_t rhs ) const;
	/// Subtracts each component of the vector by the given scalar value.
	inline int2 operator-=( const int32_t rhs );
	/// Returns a copy of the vector that has been component-wise subtracted by the other vector.
	inline int2 operator-( const int2& rhs ) const;
	/// Component-wise subtracts each component of the vector by the other vector.
	inline int2 operator-=( const int2& rhs );
	/// Returns a copy of the vector with each value multiplied the given scalar value.
	inline int2 operator*( const int32_t rhs ) const;
	/// Multiplies each component of the vector by the given scalar value.
	inline int2 operator*=( const int32_t rhs );
	/// Returns a copy of the vector that has been component-wise multiplied by the other vector.
	inline int2 operator*( const int2& rhs ) const;
	/// Component-wise multiplies each component of the vector by the other vector.
	inline int2 operator*=( const int2& rhs );
	/// Returns a copy of the vector with each value divided the given scalar value.
	inline int2 operator/( const int32_t rhs ) const;
	/// Divides each component of the vector by the given scalar value.
	inline int2 operator/=( const int32_t rhs );
	/// Returns a copy of the vector that has been component-wise divided by the other vector.
	inline int2 operator/( const int2& rhs ) const;
	/// Component-wise divides each component of the vector by the other vector.
	inline int2 operator/=( const int2& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 1.
	inline const int32_t& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 1.
	inline int32_t& operator[]( const uint32_t index );

};

/// \relates int2
/// \brief Returns true if the all the components of the left-hand-side int2 match the other one, otherwise returns false.
inline bool operator==( const int2& lhs, const int2& rhs );

/// \relates int2
/// \brief Returns true if not all of the components of the left-hand-side int2 match the other one, otherwise returns false.
inline bool operator!=( const int2& lhs, const int2& rhs );

inline bool2 operator<( const int2& lhs, const int2& rhs );
inline bool2 operator<=( const int2& lhs, const int2& rhs );
inline bool2 operator>( const int2& lhs, const int2& rhs );
inline bool2 operator>=( const int2& lhs, const int2& rhs );

#include "int2.inl"