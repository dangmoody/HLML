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

#include "int3.h"
#include "int4x4.h"
#include "int3x4.h"

/// A matrix of 4 int3s.
struct int4x3
{
	int3 rows[4];

	/// Default constructor.  Sets the matrix to an identity matrix.
	inline int4x3();

	/// \brief Sets each of the diagonal values of the matrix to the given scalar value.
	/// Setting the scalar to 1 will give an identity matrix.
	inline int4x3( const int32_t diagonal );

	/// \brief Sets the diagonal values of the matrix to the corresponding components of the given vector.
	/// Setting each component of the vector to 1 will give an identity matrix.
	inline int4x3( const int3& diagonal );

	/// Sets each row of the matrix to the given vectors.
	inline int4x3( const int3& row0, const int3& row1, const int3& row2, const int3& row3 );

	/// Sets each row of the matrix to the corresponding vector in the array.
	inline int4x3( const int3 rows[4] );

	/// Sets each component of the vector to the corresponding scalar value (row major).
	inline int4x3( const int32_t m00, const int32_t m01, const int32_t m02, const int32_t m10, const int32_t m11, const int32_t m12, const int32_t m20, const int32_t m21, const int32_t m22, const int32_t m30, const int32_t m31, const int32_t m32 );

	/// Copy constructor.  Sets each row of the matrix to the rows in the other matrix.
	inline int4x3( const int4x3& other );

	inline ~int4x3() {}

	/// Copies each row of the given matrix via a single memcpy.
	inline int4x3 operator=( const int4x3& other );

	/// \brief Returns the row at the given index of the matrix.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline int3& operator[]( const uint32_t index );

	/// \brief Returns the row at the given index of the matrix.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline const int3& operator[]( const uint32_t index ) const;
};

/// \relates int4x3
/// \brief Returns true if the all the components of the left-hand-side int4x3 match the other one, otherwise returns false.
inline bool operator==( const int4x3& lhs, const int4x3& rhs );

/// \relates int4x3
/// \brief Returns true if not all of the components of the left-hand-side int4x3 match the other one, otherwise returns false.
inline bool operator!=( const int4x3& lhs, const int4x3& rhs );

#include "int4x3.inl"
