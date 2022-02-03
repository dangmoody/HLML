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

struct bool2x3
{
	bool3 rows[2];

	// Default constructor.
	HLML_INLINE bool2x3() {}

	// Sets each diagonal component of the matrix to the given scalar.
	HLML_INLINE explicit bool2x3( const bool32_t diagonal );

	// Sets each diagonal component of the matrix to the corresponding vector component.
	bool2x3( const bool3& diagonal );

	// Sets each row of the matrix to the corresponding vector.
	bool2x3( const bool3& row0, const bool3& row1 );

	// Sets each component of the matrix to the corresponding scalar value.
	HLML_INLINE bool2x3( const bool32_t m00, const bool32_t m01, const bool32_t m02,
					const bool32_t m10, const bool32_t m11, const bool32_t m12 );

	// Copy constructor.
	HLML_INLINE bool2x3( const bool2x3& other );

	HLML_INLINE ~bool2x3() {}

	// Sets each row of the matrix to be the same as the parameter.
	HLML_INLINE bool2x3 operator=( const bool2x3& other );

	// Returns the row vector at the given index of the matrix.
	// Index CANNOT be lower than 0 or higher than 2.
	HLML_INLINE bool3& operator[]( const int32_t index );

	// Returns the row vector at the given index of the matrix.
	// Index CANNOT be lower than 0 or higher than 2.
	HLML_INLINE const bool3& operator[]( const int32_t index ) const;
};
