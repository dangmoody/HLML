/*
===========================================================================

hlml.
Copyright (c) Dan Moody 2018 - Present.

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
#include "uint2.h"
#include "uint3.h"

#include "../hlml_main.h"

// others
#include <math.h>

uint4::uint4() {
	memset( data, 0, 4 * sizeof( uint32_t ) );
}

uint4::uint4( const uint32_t x ) {
	this->x = this->y = this->z = this->w = x;
}

uint4::uint4( const uint32_t x, const uint32_t y, const uint32_t z, const uint32_t w ) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

uint4::uint4( const uint2& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

uint4::uint4( const uint3& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

uint4::uint4( const uint4& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

uint4 uint4::operator=( const uint2& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

uint4 uint4::operator=( const uint3& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

uint4 uint4::operator=( const uint4& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

uint4 uint4::operator+( const uint32_t rhs ) const {
	return uint4(
		x + rhs,
		y + rhs,
		z + rhs,
		w + rhs
	);
}

uint4 uint4::operator+=( const uint32_t rhs ) {
	return ( *this = *this + rhs );
}

uint4 uint4::operator+( const uint4& rhs ) const {
	return uint4(
		x + rhs.x,
		y + rhs.y,
		z + rhs.z,
		w + rhs.w
	);
}

uint4 uint4::operator+=( const uint4& rhs ) {
	return ( *this = *this + rhs );
}

uint4 uint4::operator-( const uint32_t rhs ) const {
	return uint4(
		x - rhs,
		y - rhs,
		z - rhs,
		w - rhs
	);
}

uint4 uint4::operator-=( const uint32_t rhs ) {
	return ( *this = *this - rhs );
}

uint4 uint4::operator-( const uint4& rhs ) const {
	return uint4(
		x - rhs.x,
		y - rhs.y,
		z - rhs.z,
		w - rhs.w
	);
}

uint4 uint4::operator-=( const uint4& rhs ) {
	return ( *this = *this - rhs );
}

uint4 uint4::operator*( const uint32_t rhs ) const {
	return uint4(
		x * rhs,
		y * rhs,
		z * rhs,
		w * rhs
	);
}

uint4 uint4::operator*=( const uint32_t rhs ) {
	return ( *this = *this * rhs );
}

uint4 uint4::operator*( const uint4& rhs ) const {
	return uint4(
		x * rhs.x,
		y * rhs.y,
		z * rhs.z,
		w * rhs.w
	);
}

uint4 uint4::operator*=( const uint4& rhs ) {
	return ( *this = *this * rhs );
}

uint4 uint4::operator/( const uint32_t rhs ) const {
	return uint4(
		x / rhs,
		y / rhs,
		z / rhs,
		w / rhs
	);
}

uint4 uint4::operator/=( const uint32_t rhs ) {
	return ( *this = *this / rhs );
}

uint4 uint4::operator/( const uint4& rhs ) const {
	return uint4(
		x / rhs.x,
		y / rhs.y,
		z / rhs.z,
		w / rhs.w
	);
}

uint4 uint4::operator/=( const uint4& rhs ) {
	return ( *this = *this / rhs );
}

const uint32_t& uint4::operator[]( const uint32_t index ) const {
	assert( index < 4 );
	return data[index];
}

uint32_t& uint4::operator[]( const uint32_t index ) {
	assert( index < 4 );
	return data[index];
}

bool operator==( const uint4& lhs, const uint4& rhs ) {
	return floateq( lhs.x, rhs. x ) && floateq( lhs.y, rhs. y ) && floateq( lhs.z, rhs. z ) && floateq( lhs.w, rhs. w );
}

bool operator!=( const uint4& lhs, const uint4& rhs ) {
	return !( operator==( lhs, rhs ) );
}

bool4 operator<( const uint4& lhs, const uint4& rhs ) {
	return bool4(
		lhs.x < rhs.x,
		lhs.y < rhs.y,
		lhs.z < rhs.z,
		lhs.w < rhs.w
	);
}

bool4 operator<=( const uint4& lhs, const uint4& rhs ) {
	return bool4(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y,
		lhs.z <= rhs.z,
		lhs.w <= rhs.w
	);
}

bool4 operator>( const uint4& lhs, const uint4& rhs ) {
	return bool4(
		lhs.x > rhs.x,
		lhs.y > rhs.y,
		lhs.z > rhs.z,
		lhs.w > rhs.w
	);
}

bool4 operator>=( const uint4& lhs, const uint4& rhs ) {
	return bool4(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y,
		lhs.z >= rhs.z,
		lhs.w >= rhs.w
	);
}

