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

/// A matrix of 4 bool4s.
struct bool4x4
{
	bool4 rows[4];

	/// Default constructor.  Sets the matrix to an identity matrix.
	inline bool4x4();

	/// \brief Sets each of the diagonal values of the matrix to the given scalar value.
	/// Setting the scalar to 1 will give an identity matrix.
	inline bool4x4( const bool diagonal );

	/// \brief Sets the diagonal values of the matrix to the corresponding components of the given vector.
	/// Setting each component of the vector to 1 will give an identity matrix.
	inline bool4x4( const bool4& diagonal );

	/// Sets each row of the matrix to the given vectors.
	inline bool4x4( const bool4& row0, const bool4& row1, const bool4& row2, const bool4& row3 );

	/// Sets each row of the matrix to the corresponding vector in the array.
	inline bool4x4( const bool4 rows[4] );

	/// Sets each component of the vector to the corresponding scalar value (row major).
	inline bool4x4( const bool m00, const bool m01, const bool m02, const bool m03, const bool m10, const bool m11, const bool m12, const bool m13, const bool m20, const bool m21, const bool m22, const bool m23, const bool m30, const bool m31, const bool m32, const bool m33 );

	/// Copy constructor.  Sets each row of the matrix to the rows in the other matrix.
	inline bool4x4( const bool4x4& other );

	inline ~bool4x4() {}

	/// Copies each row of the given matrix via a single memcpy.
	inline bool4x4 operator=( const bool4x4& other );

	/// \brief Returns the row at the given index of the matrix.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline bool4& operator[]( const uint32_t index );

	/// \brief Returns the row at the given index of the matrix.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline const bool4& operator[]( const uint32_t index ) const;
};

/// \relates bool4x4
/// \brief Returns true if the all the components of the left-hand-side bool4x4 match the other one, otherwise returns false.
inline bool operator==( const bool4x4& lhs, const bool4x4& rhs );

/// \relates bool4x4
/// \brief Returns true if not all of the components of the left-hand-side bool4x4 match the other one, otherwise returns false.
inline bool operator!=( const bool4x4& lhs, const bool4x4& rhs );

#include "bool4x4.inl"