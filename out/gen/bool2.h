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

#include <stdint.h>

struct bool3;
struct bool4;

struct bool2 {
	union {
		struct {
			bool x;
			bool y;
		};

		bool data[2] = { 0 };
	};

	inline bool2();
	inline explicit bool2( const bool x );
	inline bool2( const bool x, const bool y );
	inline bool2( const bool2& other );
	inline bool2( const bool3& other );
	inline bool2( const bool4& other );
	~bool2() {}

	inline bool2 operator=( const bool2& rhs );
	inline bool2 operator=( const bool3& rhs );
	inline bool2 operator=( const bool4& rhs );

	inline const bool& operator[]( const uint32_t index ) const;
	inline bool& operator[]( const uint32_t index );
};

inline bool operator==( const bool2& lhs, const bool2& rhs );
inline bool operator!=( const bool2& lhs, const bool2& rhs );

#include "bool2.inl"