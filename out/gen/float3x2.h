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

#include "float2.h"
#include "float3x3.h"
#include "float2x3.h"

/// A matrix of 3 float2s.
struct float3x2 {
	float2 rows[3];

	/// Default constructor.  Sets the matrix to an identity matrix.
	inline float3x2();

	/// \brief Sets each of the diagonal values of the matrix to the given scalar value.
	/// Setting the scalar to 1 will give an identity matrix.
	inline float3x2( const float diagonal );

	/// \brief Sets the diagonal values of the matrix to the corresponding components of the given vector.
	/// Setting each component of the vector to 1 will give an identity matrix.
	inline float3x2( const float2& diagonal );

	/// Sets each row of the matrix to the given vectors.
	inline float3x2( const float2& row0, const float2& row1, const float2& row2 );

	/// Sets each row of the matrix to the corresponding vector in the array.
	inline float3x2( const float2 rows[3] );

	/// Sets each component of the vector to the corresponding scalar value (row major).
	inline float3x2( const float m00, const float m01, const float m10, const float m11, const float m20, const float m21 );

	/// Copy constructor.  Sets each row of the matrix to the rows in the other matrix.
	inline float3x2( const float3x2& other );

	inline ~float3x2() {}

	/// Copies each row of the given matrix via a single memcpy.
	inline float3x2 operator=( const float3x2& other );

	/// \brief Returns the row at the given index of the matrix.
	/// Index CANNOT be lower than 0 or higher than 2.
	inline float2& operator[]( const uint32_t index );

	/// \brief Returns the row at the given index of the matrix.
	/// Index CANNOT be lower than 0 or higher than 2.
	inline const float2& operator[]( const uint32_t index ) const;
};

/// \relates float3x2
/// \brief Returns true if the all the components of the left-hand-side float3x2 match the other one, otherwise returns false.
inline bool operator==( const float3x2& lhs, const float3x2& rhs );

/// \relates float3x2
/// \brief Returns true if not all of the components of the left-hand-side float3x2 match the other one, otherwise returns false.
inline bool operator!=( const float3x2& lhs, const float3x2& rhs );

#include "float3x2.inl"