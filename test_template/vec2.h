/*
===========================================================================

neon.
Copyright (c) Yeti Massive 2018 - Present.

This file is part of neon.

neon is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

neon is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with neon.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/
#pragma once

template<class T>
struct vec2 {
	union {
		struct {
			T					x, y;
		};

		T						data[2];
	};

	inline constexpr			vec2();
	inline constexpr explicit	vec2( const T number );
	inline constexpr			vec2( const T x, const T y );

	inline						~vec2() {}

	inline vec2<T>		operator=( const vec2<T>& other );

	inline vec2<T>		operator+( const T scale ) const;
	inline vec2<T>		operator+=( const T scale ) { return ( *this = *this + scale ); }
	inline vec2<T>		operator+( const vec2<T>& rhs ) const;
	inline vec2<T>		operator+=( const vec2<T>& rhs ) { return ( *this = *this + rhs ); }
	inline vec2<T>		operator-( const T scale ) const;
	inline vec2<T>		operator-=( const T scale ) { return ( *this = *this - scale ); }
	inline vec2<T>		operator-( const vec2<T>& rhs ) const;
	inline vec2<T>		operator-=( const vec2<T>& rhs ) { return ( *this = *this - rhs ); }
	inline vec2<T>		operator*( const T scale ) const;
	inline vec2<T>		operator*=( const T scale ) { return ( *this = *this * scale ); }
	inline vec2<T>		operator*( const vec2<T>& rhs ) const;
	inline vec2<T>		operator*=( const vec2<T>& rhs ) { return ( *this = *this * rhs ); }
	inline vec2<T>		operator/( const T scale ) const;
	inline vec2<T>		operator/=( const T scale ) { return ( *this = *this / scale ); }
	inline vec2<T>		operator/( const vec2<T>& rhs ) const;
	inline vec2<T>		operator/=( const vec2<T>& rhs ) { return ( *this = *this / rhs ); }

	inline constexpr T&	operator[]( const uint32_t index ) const;

	inline bool			operator==( const vec2<T>& other ) const;
	inline bool			operator!=( const vec2<T>& other ) const;
};

#include "vec2.inl"