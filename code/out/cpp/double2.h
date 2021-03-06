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

#include "bool2.h"

#include <stdint.h>
#include "../hlml_types.h"

struct double3;
struct double4;

// ignore prohibition of anymous structs for GCC
#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#elif defined( _MSC_VER )
#pragma warning( push )
#pragma warning( disable : 4201 ) // C4201 - nonstandard extension used : nameless struct/union
#endif

// A vector of 2 doubles with components xy.
// Components are also stored as elements in an array via a union.
struct double2
{
	union
	{
		struct
		{
			double x;
			double y;
		};

		struct
		{
			double r;
			double g;
		};

		double data[2];
	};


	// Default constructor.  Initializes all values to zero.
	inline double2() {}

	// Initializes all components of the vector to the given scalar value.
	inline explicit double2( const double x );

	// Sets the xy members of the vector to the corresponding parameters.
	inline double2( const double x, const double y );

	// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline double2( const double2& other );

	// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline double2( const double3& other );

	// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline double2( const double4& other );

	~double2() {}

	// Copies the elements of the given vector via a single memcpy.
	inline double2 operator=( const double2& rhs );

	// Copies the elements of the given vector via a single memcpy.
	inline double2 operator=( const double3& rhs );

	// Copies the elements of the given vector via a single memcpy.
	inline double2 operator=( const double4& rhs );

	// Returns the vector component at the given index.
	// Index CANNOT be lower than 0 or higher than 1.
	inline const double& operator[]( const uint32_t index ) const;

	// Returns the vector component at the given index.
	// Index CANNOT be lower than 0 or higher than 1.
	inline double& operator[]( const uint32_t index );

	// swizzle funcs
	inline double2 xx() const;
	inline double2 yx() const;
	inline double2 xy() const;
	inline double2 yy() const;
};

#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic pop
#elif defined( _MSC_VER )
#pragma warning( pop )
#endif

