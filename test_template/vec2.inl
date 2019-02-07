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
vec2<T>::vec2
========================
*/
template<class T>
constexpr vec2<T>::vec2() {
	memset( data, 0, sizeof( vec2<T> ) );
}

/*
========================
vec2<T>::vec2
========================
*/
template<class T>
constexpr vec2<T>::vec2( const T number ) {
	x = y = number;
}

/*
========================
vec2<T>::vec2
========================
*/
template<class T>
constexpr vec2<T>::vec2( const T x, const T y ) {
	this->x = x;
	this->y = y;
}

/*
========================
vec2<T>::operator=
========================
*/
template<class T>
vec2<T> vec2<T>::operator=( const vec2<T>& other ) {
	memcpy( data, other.data, sizeof( vec2<T> ) );
	return *this;
}

/*
========================
vec2<T>::operator+
========================
*/
template<class T>
vec2<T> vec2<T>::operator+( const T scale ) const {
	return vec2<T>(
		x + scale,
		y + scale
		);
}

/*
========================
vec2<T>::operator-
========================
*/
template<class T>
vec2<T> vec2<T>::operator-( const T scale ) const {
	return vec2<T>(
		x - scale,
		y - scale
		);
}

/*
========================
vec2<T>::operator*
========================
*/
template<class T>
vec2<T> vec2<T>::operator*( const T scale ) const {
	return vec2<T>(
		x * scale,
		y * scale
		);
}

/*
========================
vec2<T>::operator/
========================
*/
template<class T>
vec2<T> vec2<T>::operator/( const T scale ) const {
	return vec2<T>(
		x / scale,
		y / scale
		);
}

/*
========================
vec2<T>::operator+
========================
*/
template<class T>
vec2<T> vec2<T>::operator+( const vec2<T>& rhs ) const {
	return vec2<T>(
		x + rhs.x,
		y + rhs.y
		);
}

/*
========================
vec2<T>::operator-
========================
*/
template<class T>
vec2<T> vec2<T>::operator-( const vec2<T>& rhs ) const {
	return vec2<T>(
		x - rhs.x,
		y - rhs.y
		);
}

/*
========================
vec2<T>::operator*
========================
*/
template<class T>
vec2<T> vec2<T>::operator*( const vec2<T>& rhs ) const {
	return vec2<T>(
		x * rhs.x,
		y * rhs.y
		);
}

/*
========================
vec2<T>::operator/
========================
*/
template<class T>
vec2<T> vec2<T>::operator/( const vec2<T>& rhs ) const {
	return vec2<T>(
		x / rhs.x,
		y / rhs.y
		);
}

/*
========================
vec2<T>::operator[]
========================
*/
template<class T>
constexpr T& vec2<T>::operator[]( const uint32_t index ) const {
	assert( index < 2 );
	return data[index];
}

/*
========================
vec2<T>::operator==
========================
*/
template<class T>
bool vec2<T>::operator==( const vec2<T>& other ) const {
	return x == other.x && y == other.y;
}

/*
========================
vec2<T>::operator!=
========================
*/
template<class T>
bool vec2<T>::operator!=( const vec2<T>& other ) const {
	return !( operator==( other ) );
}