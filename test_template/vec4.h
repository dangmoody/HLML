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
struct vec4 {
	union {
		struct {
			T					x, y, z, w;
		};

		T						data[4];
	};

	inline constexpr			vec4();
	inline constexpr explicit	vec4( const T number );
	inline constexpr			vec4( const T x, const T y, const T z, const T w );

	inline						~vec4() {}

	inline vec4<T>		operator=( const vec4<T>& other );

	inline vec4<T>		operator+( const T scale ) const;
	inline vec4<T>		operator+=( const T scale ) { return ( *this = *this + scale ); }
	inline vec4<T>		operator+( const vec4<T>& rhs ) const;
	inline vec4<T>		operator+=( const vec4<T>& rhs ) { return ( *this = *this + rhs ); }
	inline vec4<T>		operator-( const T scale ) const;
	inline vec4<T>		operator-=( const T scale ) { return ( *this = *this - scale ); }
	inline vec4<T>		operator-( const vec4<T>& rhs ) const;
	inline vec4<T>		operator-=( const vec4<T>& rhs ) { return ( *this = *this - rhs ); }
	inline vec4<T>		operator*( const T scale ) const;
	inline vec4<T>		operator*=( const T scale ) { return ( *this = *this * scale ); }
	inline vec4<T>		operator*( const vec4<T>& rhs ) const;
	inline vec4<T>		operator*=( const vec4<T>& rhs ) { return ( *this = *this * rhs ); }
	inline vec4<T>		operator/( const T scale ) const;
	inline vec4<T>		operator/=( const T scale ) { return ( *this = *this / scale ); }
	inline vec4<T>		operator/( const vec4<T>& rhs ) const;
	inline vec4<T>		operator/=( const vec4<T>& rhs ) { return ( *this = *this / rhs ); }

	inline constexpr T&	operator[]( const uint32_t index ) const;

	inline bool			operator==( const vec4<T>& rhs ) const;
	inline bool			operator!=( const vec4<T>& rhs ) const;
};

#include "vec4.inl"