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

struct float2x2
{
	float2 rows[2];

	// Default constructor.
	HLML_INLINE float2x2() {}

	// Sets each diagonal component of the matrix to the given scalar.
	HLML_INLINE explicit float2x2( const float diagonal );

	// Sets each diagonal component of the matrix to the corresponding vector component.
	float2x2( const float2& diagonal );

	// Sets each row of the matrix to the corresponding vector.
	float2x2( const float2& row0, const float2& row1 );

	// Sets each component of the matrix to the corresponding scalar value.
	HLML_INLINE float2x2( const float m00, const float m01,
					const float m10, const float m11 );

	// Copy constructor.
	HLML_INLINE float2x2( const float2x2& other );

	HLML_INLINE ~float2x2() {}

	// Sets each row of the matrix to be the same as the parameter.
	HLML_INLINE float2x2 operator=( const float2x2& other );

	// Returns the row vector at the given index of the matrix.
	// Index CANNOT be lower than 0 or higher than 2.
	HLML_INLINE float2& operator[]( const int32_t index );

	// Returns the row vector at the given index of the matrix.
	// Index CANNOT be lower than 0 or higher than 2.
	HLML_INLINE const float2& operator[]( const int32_t index ) const;
};
