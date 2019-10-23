/*
===========================================================================

HLML.

MIT License

Copyright (c) 2019 Dan Moody

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

===========================================================================
*/

// THIS FILE WAS AUTOMATICALLY GENERATED BY A TOOL.
// EDITING THIS FILE MAY CAUSE SIDE EFFECTS.
// DO SO AT YOUR OWN RISK.

#pragma once

#include "uint2.h"
#include "uint4x4.h"
#include "uint2x4.h"

/// A matrix of 4 uint2s.
struct uint4x2
{
	uint2 rows[4];

	/// Default constructor.  Sets the matrix to an identity matrix.
	inline uint4x2();

	/// \brief Sets each of the diagonal values of the matrix to the given scalar value.
	/// Setting the scalar to 1 will give an identity matrix.
	inline uint4x2( const uint32_t diagonal );

	/// \brief Sets the diagonal values of the matrix to the corresponding components of the given vector.
	/// Setting each component of the vector to 1 will give an identity matrix.
	inline uint4x2( const uint2& diagonal );

	/// Sets each row of the matrix to the given vectors.
	inline uint4x2( const uint2& row0, const uint2& row1, const uint2& row2, const uint2& row3 );

	/// Sets each row of the matrix to the corresponding vector in the array.
	inline uint4x2( const uint2 rows[4] );

	/// Sets each component of the vector to the corresponding scalar value (row major).
	inline uint4x2( const uint32_t m00, const uint32_t m01, const uint32_t m10, const uint32_t m11, const uint32_t m20, const uint32_t m21, const uint32_t m30, const uint32_t m31 );

	/// Copy constructor.  Sets each row of the matrix to the rows in the other matrix.
	inline uint4x2( const uint4x2& other );

	inline ~uint4x2() {}

	/// Copies each row of the given matrix via a single memcpy.
	inline uint4x2 operator=( const uint4x2& other );

	/// \brief Returns the row at the given index of the matrix.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline uint2& operator[]( const uint32_t index );

	/// \brief Returns the row at the given index of the matrix.
	/// Index CANNOT be lower than 0 or higher than 3.
	inline const uint2& operator[]( const uint32_t index ) const;
};

/// \relates uint4x2
/// \brief Returns true if the all the components of the left-hand-side uint4x2 match the other one, otherwise returns false.
inline bool operator==( const uint4x2& lhs, const uint4x2& rhs );

/// \relates uint4x2
/// \brief Returns true if not all of the components of the left-hand-side uint4x2 match the other one, otherwise returns false.
inline bool operator!=( const uint4x2& lhs, const uint4x2& rhs );

