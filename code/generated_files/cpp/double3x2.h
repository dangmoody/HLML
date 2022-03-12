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

#include "double2.h"

struct double3x2
{
	double2 rows[3];

	// Default constructor.
	HLML_INLINE double3x2() {}

	// Sets each diagonal component of the matrix to the given scalar.
	HLML_INLINE explicit double3x2( const double diagonal );

	// Sets each diagonal component of the matrix to the corresponding vector component.
	HLML_INLINE double3x2( const double2& diagonal );

	// Sets each row of the matrix to the corresponding vector.
	HLML_INLINE double3x2( const double2& row0, const double2& row1, const double2& row2 );

	// Sets each component of the matrix to the corresponding scalar value.
	HLML_INLINE double3x2( const double m00, const double m01,
					const double m10, const double m11,
					const double m20, const double m21 );

	// Copy constructor.
	HLML_INLINE double3x2( const double3x2& other );

	HLML_INLINE ~double3x2() {}

	// Sets each row of the matrix to be the same as the parameter.
	HLML_INLINE double3x2 operator=( const double3x2& other );

	// Returns the row vector at the given index of the matrix.
	// Index CANNOT be lower than 0 or higher than 3.
	HLML_INLINE double2& operator[]( const int32_t index );

	// Returns the row vector at the given index of the matrix.
	// Index CANNOT be lower than 0 or higher than 3.
	HLML_INLINE const double2& operator[]( const int32_t index ) const;
};
