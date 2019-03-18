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

#include "float3.h"
#include "float2x2.h"
#include "float3x2.h"

/// A matrix of 2 float3s.
struct float2x3
{
	float3 rows[2];

	/// Default constructor.  Sets the matrix to an identity matrix.
	inline float2x3();

	/// \brief Sets each of the diagonal values of the matrix to the given scalar value.
	/// Setting the scalar to 1 will give an identity matrix.
	inline float2x3( const float diagonal );

	/// \brief Sets the diagonal values of the matrix to the corresponding components of the given vector.
	/// Setting each component of the vector to 1 will give an identity matrix.
	inline float2x3( const float3& diagonal );

	/// Sets each row of the matrix to the given vectors.
	inline float2x3( const float3& row0, const float3& row1 );

	/// Sets each row of the matrix to the corresponding vector in the array.
	inline float2x3( const float3 rows[2] );

	/// Sets each component of the vector to the corresponding scalar value (row major).
	inline float2x3( const float m00, const float m01, const float m02, const float m10, const float m11, const float m12 );

	/// Copy constructor.  Sets each row of the matrix to the rows in the other matrix.
	inline float2x3( const float2x3& other );

	inline ~float2x3() {}

	/// Copies each row of the given matrix via a single memcpy.
	inline float2x3 operator=( const float2x3& other );

	/// \brief Returns the row at the given index of the matrix.
	/// Index CANNOT be lower than 0 or higher than 1.
	inline float3& operator[]( const uint32_t index );

	/// \brief Returns the row at the given index of the matrix.
	/// Index CANNOT be lower than 0 or higher than 1.
	inline const float3& operator[]( const uint32_t index ) const;
};

/// \relates float2x3
/// \brief Returns true if the all the components of the left-hand-side float2x3 match the other one, otherwise returns false.
inline bool operator==( const float2x3& lhs, const float2x3& rhs );

/// \relates float2x3
/// \brief Returns true if not all of the components of the left-hand-side float2x3 match the other one, otherwise returns false.
inline bool operator!=( const float2x3& lhs, const float2x3& rhs );

#include "float2x3.inl"