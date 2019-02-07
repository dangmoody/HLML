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

/*
========================
vec4<T>::vec4
========================
*/
template<class T>
constexpr vec4<T>::vec4( void ) {
	memset( data, 0, sizeof( vec4<T> ) );
}

/*
========================
vec4<T>::vec4
========================
*/
template<class T>
constexpr vec4<T>::vec4( const T number ) {
	x = y = z = w = number;
}

/*
========================
vec4<T>::vec4
========================
*/
template<class T>
constexpr vec4<T>::vec4( const T x, const T y, const T z, const T w ) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

/*
========================
vec4<T>::operator=
========================
*/
template<class T>
vec4<T> vec4<T>::operator=( const vec4<T>& vec ) {
	memcpy( data, vec.data, sizeof( vec4<T> ) );
	return *this;
}

/*
========================
vec4<T>::operator+
========================
*/
template<class T>
vec4<T> vec4<T>::operator+( const T scale ) const {
	return vec4<T>(
		x + scale,
		y + scale,
		z + scale,
		w + scale
		);
}

/*
========================
vec4<T>::operator-
========================
*/
template<class T>
vec4<T> vec4<T>::operator-( const T scale ) const {
	return vec4<T>(
		x - scale,
		y - scale,
		z - scale,
		w - scale
		);
}

/*
========================
vec4<T>::operator*
========================
*/
template<class T>
vec4<T> vec4<T>::operator*( const T scale ) const {
	return vec4<T>(
		x * scale,
		y * scale,
		z * scale,
		w * scale
		);
}

/*
========================
vec4<T>::operator/
========================
*/
template<class T>
vec4<T> vec4<T>::operator/( const T scale ) const {
	return vec4<T>(
		x / scale,
		y / scale,
		z / scale,
		w / scale
		);
}

/*
========================
vec4<T>::operator+
========================
*/
template<class T>
vec4<T> vec4<T>::operator+( const vec4<T>& rhs ) const {
	return vec4<T>(
		x + rhs.x,
		y + rhs.y,
		z + rhs.z,
		w + rhs.w
		);
}

/*
========================
vec4<T>::operator-
========================
*/
template<class T>
vec4<T> vec4<T>::operator-( const vec4<T>& rhs ) const {
	return vec4<T>(
		x - rhs.x,
		y - rhs.y,
		z - rhs.z,
		w - rhs.w
		);
}

/*
========================
vec4<T>::operator*
========================
*/
template<class T>
vec4<T> vec4<T>::operator*( const vec4<T>& rhs ) const {
	return vec4<T>(
		x * rhs.x,
		y * rhs.y,
		z * rhs.z,
		w * rhs.w
		);
}

/*
========================
vec4<T>::operator/
========================
*/
template<class T>
vec4<T> vec4<T>::operator/( const vec4<T>& rhs ) const {
	return vec4<T>(
		x / rhs.x,
		y / rhs.y,
		z / rhs.z,
		w / rhs.w
		);
}

/*
========================
vec4<T>::operator[]
========================
*/
template<class T>
constexpr T& vec4<T>::operator[]( const uint32_t index ) const {
	assert( index < 4 );
	return data[index];
}

/*
========================
vec4<T>::operator==
========================
*/
template<class T>
bool vec4<T>::operator==( const vec4<T>& rhs ) const {
	return x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w;
}

/*
========================
vec4<T>::operator!=
========================
*/
template<class T>
bool vec4<T>::operator!=( const vec4<T>& rhs ) const {
	return !( operator==( rhs ) );
}