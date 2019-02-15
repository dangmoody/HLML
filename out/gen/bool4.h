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

struct bool2;
struct bool3;
struct float3;

struct bool4 {
	union {
		struct {
			bool x;
			bool y;
			bool z;
			bool w;
		};

		bool data[4] = { 0 };
	};

	inline bool4();
	inline explicit bool4( const bool x );
	inline bool4( const bool x, const bool y, const bool z, const bool w );
	inline bool4( const bool2& other );
	inline bool4( const bool3& other );
	inline bool4( const bool4& other );
	~bool4() {}

	inline bool4 operator=( const bool2& rhs );
	inline bool4 operator=( const bool3& rhs );
	inline bool4 operator=( const bool4& rhs );

	inline const bool& operator[]( const uint32_t index ) const;
	inline bool& operator[]( const uint32_t index );
};

inline bool operator==( const bool4& lhs, const bool4& rhs );
inline bool operator!=( const bool4& lhs, const bool4& rhs );

#include "bool4.inl"