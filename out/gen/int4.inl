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

// hlml includes
#include "int2.h"
#include "int3.h"

#include "../hlml_main.h"

// others
#include <math.h>
#include <memory.h>
#include <assert.h>

int4::int4() {
	memset( data, 0, 4 * sizeof( int32_t ) );
}

int4::int4( const int32_t x ) {
	this->x = this->y = this->z = this->w = x;
}

int4::int4( const int32_t x, const int32_t y, const int32_t z, const int32_t w ) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

int4::int4( const int2& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

int4::int4( const int3& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

int4::int4( const int4& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

int4 int4::operator=( const int2& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

int4 int4::operator=( const int3& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

int4 int4::operator=( const int4& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

int4 int4::operator+( const int32_t rhs ) const {
	return int4(
		x + rhs,
		y + rhs,
		z + rhs,
		w + rhs,
	);
}

int4 int4::operator+=( const int32_t rhs ) {
	return ( *this = *this + rhs );
}

int4 int4::operator+( const int4& rhs ) const {
	return int4(
		x + rhs.x,
		y + rhs.y,
		z + rhs.z,
		w + rhs.w,
	);
}

int4 int4::operator+=( const int4& rhs ) {
	return ( *this = *this + rhs );
}

int4 int4::operator-( const int32_t rhs ) const {
	return int4(
		x - rhs,
		y - rhs,
		z - rhs,
		w - rhs,
	);
}

int4 int4::operator-=( const int32_t rhs ) {
	return ( *this = *this - rhs );
}

int4 int4::operator-( const int4& rhs ) const {
	return int4(
		x - rhs.x,
		y - rhs.y,
		z - rhs.z,
		w - rhs.w,
	);
}

int4 int4::operator-=( const int4& rhs ) {
	return ( *this = *this - rhs );
}

int4 int4::operator*( const int32_t rhs ) const {
	return int4(
		x * rhs,
		y * rhs,
		z * rhs,
		w * rhs,
	);
}

int4 int4::operator*=( const int32_t rhs ) {
	return ( *this = *this * rhs );
}

int4 int4::operator*( const int4& rhs ) const {
	return int4(
		x * rhs.x,
		y * rhs.y,
		z * rhs.z,
		w * rhs.w,
	);
}

int4 int4::operator*=( const int4& rhs ) {
	return ( *this = *this * rhs );
}

int4 int4::operator/( const int32_t rhs ) const {
	return int4(
		x / rhs
		y / rhs
		z / rhs
		w / rhs
	);
}

int4 int4::operator/=( const int32_t rhs ) {
	return ( *this = *this / rhs );
}

int4 int4::operator/( const int4& rhs ) const {
	return int4(
		x / rhs.x
		y / rhs.y
		z / rhs.z
		w / rhs.w
	);
}

int4 int4::operator/=( const int4& rhs ) {
	return ( *this = *this / rhs );
}

const int32_t& int4::operator[]( const uint32_t index ) const {
	assert( index < 4 );
	return data[index];
}

int32_t& int4::operator[]( const uint32_t index ) {
	assert( index < 4 );
	return data[index];
}

bool operator==( const int4& lhs, const int4& rhs ) {
	return ( lhs.x == rhs.x ) && ( lhs.y == rhs.y ) && ( lhs.z == rhs.z ) && ( lhs.w == rhs.w );
}

bool operator!=( const int4& lhs, const int4& rhs ) {
	return !( operator==( lhs, rhs ) );
}

bool4 operator<( const int4& lhs, const int4& rhs ) {
	return bool4(
		lhs.x < rhs.x,
		lhs.y < rhs.y,
		lhs.z < rhs.z,
		lhs.w < rhs.w
	);
}

bool4 operator<=( const int4& lhs, const int4& rhs ) {
	return bool4(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y,
		lhs.z <= rhs.z,
		lhs.w <= rhs.w
	);
}

bool4 operator>( const int4& lhs, const int4& rhs ) {
	return bool4(
		lhs.x > rhs.x,
		lhs.y > rhs.y,
		lhs.z > rhs.z,
		lhs.w > rhs.w
	);
}

bool4 operator>=( const int4& lhs, const int4& rhs ) {
	return bool4(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y,
		lhs.z >= rhs.z,
		lhs.w >= rhs.w
	);
}

