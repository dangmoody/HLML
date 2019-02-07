#pragma once

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
struct vec3 {
	union {
		struct {
			T					x, y, z;
		};

		T						data[3];
	};

	inline constexpr			vec3<T>();
	inline constexpr explicit	vec3<T>( const T number );
	inline constexpr			vec3<T>( const T x, const T y, const T z );

	inline						~vec3<T>() {}

	inline vec3<T>		operator=( const vec3<T>& other );

	inline vec3<T>		operator+( const T scale ) const;
	inline vec3<T>		operator+=( const T scale ) { return ( *this = *this + scale ); }
	inline vec3<T>		operator+( const vec3<T>& rhs ) const;
	inline vec3<T>		operator+=( const vec3<T>& rhs ) { return ( *this = *this + scale ); }
	inline vec3<T>		operator-( const T scale ) const;
	inline vec3<T>		operator-=( const T scale ) { return ( *this = *this - scale ); }
	inline vec3<T>		operator-( const vec3<T>& rhs ) const;
	inline vec3<T>		operator-=( const vec3<T>& rhs ) { return ( *this = *this - scale ); }
	inline vec3<T>		operator*( const T scale ) const;
	inline vec3<T>		operator*=( const T scale ) { return ( *this = *this * scale ); }
	inline vec3<T>		operator*( const vec3<T>& rhs ) const;
	inline vec3<T>		operator*=( const vec3<T>& rhs ) { return ( *this = *this * scale ); }
	inline vec3<T>		operator/( const T scale ) const;
	inline vec3<T>		operator/=( const T scale ) { return ( *this = *this / scale ); }
	inline vec3<T>		operator/( const vec3<T>& rhs ) const;
	inline vec3<T>		operator/=( const vec3<T>& rhs ) { return ( *this = *this / scale ); }

	inline constexpr T&	operator[]( const uint32_t index ) const;

	inline bool			operator==( const vec3<T>& rhs ) const;
	inline bool			operator!=( const vec3<T>& rhs ) const;
};

#include "vec3.inl"