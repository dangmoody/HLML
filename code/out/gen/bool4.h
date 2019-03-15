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

#include <stdint.h>

struct bool2;
struct bool3;
struct float3;

/// \brief A vector of 4 bools with components xyzw.
/// Components are also stored as elements in an array via a union.
struct bool4 {
	union {
		struct {
			bool x;
			bool y;
			bool z;
			bool w;
		};

		bool data[4] = { 0 };
	};

	/// Default constructor.  Initializes all values to zero.
	inline bool4();

	/// Initializes all components of the vector to the given scalar value.
	inline explicit bool4( const bool x );

	/// Sets the xyzw members of the vector to the corresponding parameters.
	inline bool4( const bool x, const bool y, const bool z, const bool w );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline bool4( const bool2& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline bool4( const bool3& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline bool4( const bool4& other );

	~bool4() {}

	/// Copies the elements of the given vector via memcpy.
	inline bool4 operator=( const bool2& rhs );

	/// Copies the elements of the given vector via memcpy.
	inline bool4 operator=( const bool3& rhs );

	/// Copies the elements of the given vector via memcpy.
	inline bool4 operator=( const bool4& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline const bool& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline bool& operator[]( const uint32_t index );

};

/// \relates bool4
/// \brief Returns true if the all the components of the left-hand-side bool4 match the other one, otherwise returns false.
inline bool operator==( const bool4& lhs, const bool4& rhs );

/// \relates bool4
/// \brief Returns true if not all of the components of the left-hand-side bool4 match the other one, otherwise returns false.
inline bool operator!=( const bool4& lhs, const bool4& rhs );

#include "bool4.inl"