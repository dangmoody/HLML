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

#include "double3.h"

/// A matrix of 3 double3s.
struct double3x3 {
	double3 rows[3];

	/// Default constructor.  Sets the matrix to an identity matrix.
	inline double3x3();

	/// \brief Sets each of the diagonal values of the matrix to the given scalar value.
	/// Setting the scalar to 1 will give an identity matrix.
	inline double3x3( const double diagonal );

	/// \brief Sets the diagonal values of the matrix to the corresponding components of the given vector.
	/// Setting each component of the vector to 1 will give an identity matrix.
	inline double3x3( const double3& diagonal );

	/// Sets each row of the matrix to the given vectors.
	inline double3x3( const double3& row0, const double3& row1, const double3& row2 );

	/// Sets each row of the matrix to the corresponding vector in the array.
	inline double3x3( const double3 rows[3] );

	/// Sets each component of the vector to the corresponding scalar value (row major).
	inline double3x3( const double m00, const double m01, const double m02, const double m10, const double m11, const double m12, const double m20, const double m21, const double m22 );

	/// Copy constructor.  Sets each row of the matrix to the rows in the other matrix.
	inline double3x3( const double3x3& other );

	inline ~double3x3() {}

	/// Copies each row of the given matrix via a single memcpy.
	inline double3x3 operator=( const double3x3& other );

	/// \brief Returns the row at the given index of the matrix.
	/// Index CANNOT be lower than 0 or higher than 2.
	inline double3& operator[]( const uint32_t index );

	/// \brief Returns the row at the given index of the matrix.
	/// Index CANNOT be lower than 0 or higher than 2.
	inline const double3& operator[]( const uint32_t index ) const;
};

/// \relates double3x3
/// \brief Returns true if the all the components of the left-hand-side double3x3 match the other one, otherwise returns false.
inline bool operator==( const double3x3& lhs, const double3x3& rhs );

/// \relates double3x3
/// \brief Returns true if not all of the components of the left-hand-side double3x3 match the other one, otherwise returns false.
inline bool operator!=( const double3x3& lhs, const double3x3& rhs );

#include "double3x3.inl"