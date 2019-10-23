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

#include <stdint.h>
#include "../hlml_types.h"

struct bool3;
struct bool4;

// ignore prohibition of anymous structs for GCC
#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#elif defined( _MSC_VER )
#pragma warning( push )
#pragma warning( disable : 4201 ) // C4201 - nonstandard extension used : nameless struct/union
#endif

/// \brief A vector of 2 bool32_ts with components xy.
/// Components are also stored as elements in an array via a union.
struct bool2
{
	union
	{
		struct
		{
			bool32_t x;
			bool32_t y;
		};

		bool32_t data[2] = { 0 };
	};

	/// Default constructor.  Initializes all values to zero.
	inline bool2();

	/// Initializes all components of the vector to the given scalar value.
	inline explicit bool2( const bool32_t x );

	/// Sets the xy members of the vector to the corresponding parameters.
	inline bool2( const bool32_t x, const bool32_t y );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline bool2( const bool2& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline bool2( const bool3& other );

	/// Copy constructor.  Copies the elements of the given vector via memcpy.
	inline bool2( const bool4& other );

	~bool2() {}

	/// Copies the elements of the given vector via a single memcpy.
	inline bool2 operator=( const bool2& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline bool2 operator=( const bool3& rhs );

	/// Copies the elements of the given vector via a single memcpy.
	inline bool2 operator=( const bool4& rhs );

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 1.
	inline const bool32_t& operator[]( const uint32_t index ) const;

	/// \brief Returns the vector component at the given index.
	/// Index CANNOT be lower than 0 or higher than 1.
	inline bool32_t& operator[]( const uint32_t index );

	// swizzle funcs
	inline bool2 xx() const;
	inline bool2 yx() const;
	inline bool2 xy() const;
	inline bool2 yy() const;
};

#if defined( __clang__ ) || defined( __GNUC__ )
#pragma GCC diagnostic pop
#elif defined( _MSC_VER )
#pragma warning( pop )
#endif

/// \relates bool2
/// \brief Returns true if the all the components of the left-hand-side bool2 match the other one, otherwise returns false.
inline bool operator==( const bool2& lhs, const bool2& rhs );

/// \relates bool2
/// \brief Returns true if not all of the components of the left-hand-side bool2 match the other one, otherwise returns false.
inline bool operator!=( const bool2& lhs, const bool2& rhs );

