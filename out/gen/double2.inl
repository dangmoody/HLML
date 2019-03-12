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
#include "double3.h"
#include "double4.h"

#include "../hlml_main.h"

// others
#include <math.h>
#include <memory.h>
#include <assert.h>

double2::double2() {
	memset( data, 0, 2 * sizeof( double ) );
}

double2::double2( const double x ) {
	this->x = this->y = x;
}

double2::double2( const double x, const double y ) {
	this->x = x;
	this->y = y;
}

double2::double2( const double2& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

double2::double2( const double3& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

double2::double2( const double4& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

double2 double2::operator=( const double2& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

double2 double2::operator=( const double3& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

double2 double2::operator=( const double4& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

double2 double2::operator+( const double rhs ) const {
	return double2(
		x + rhs,
		y + rhs
	);
}

double2 double2::operator+=( const double rhs ) {
	return ( *this = *this + rhs );
}

double2 double2::operator+( const double2& rhs ) const {
	return double2(
		x + rhs.x,
		y + rhs.y
	);
}

double2 double2::operator+=( const double2& rhs ) {
	return ( *this = *this + rhs );
}

double2 double2::operator-( const double rhs ) const {
	return double2(
		x - rhs,
		y - rhs
	);
}

double2 double2::operator-=( const double rhs ) {
	return ( *this = *this - rhs );
}

double2 double2::operator-( const double2& rhs ) const {
	return double2(
		x - rhs.x,
		y - rhs.y
	);
}

double2 double2::operator-=( const double2& rhs ) {
	return ( *this = *this - rhs );
}

double2 double2::operator*( const double rhs ) const {
	return double2(
		x * rhs,
		y * rhs
	);
}

double2 double2::operator*=( const double rhs ) {
	return ( *this = *this * rhs );
}

double2 double2::operator*( const double2& rhs ) const {
	return double2(
		x * rhs.x,
		y * rhs.y
	);
}

double2 double2::operator*=( const double2& rhs ) {
	return ( *this = *this * rhs );
}

double2 double2::operator/( const double rhs ) const {
	return double2(
		x / rhs,
		y / rhs
	);
}

double2 double2::operator/=( const double rhs ) {
	return ( *this = *this / rhs );
}

double2 double2::operator/( const double2& rhs ) const {
	return double2(
		x / rhs.x,
		y / rhs.y
	);
}

double2 double2::operator/=( const double2& rhs ) {
	return ( *this = *this / rhs );
}

const double& double2::operator[]( const uint32_t index ) const {
	assert( index < 2 );
	return data[index];
}

double& double2::operator[]( const uint32_t index ) {
	assert( index < 2 );
	return data[index];
}

bool operator==( const double2& lhs, const double2& rhs ) {
	return doubleeq( lhs.x, rhs. x ) && doubleeq( lhs.y, rhs. y );
}

bool operator!=( const double2& lhs, const double2& rhs ) {
	return !( operator==( lhs, rhs ) );
}

bool2 operator<( const double2& lhs, const double2& rhs ) {
	return bool2(
		lhs.x < rhs.x,
		lhs.y < rhs.y
	);
}

bool2 operator<=( const double2& lhs, const double2& rhs ) {
	return bool2(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y
	);
}

bool2 operator>( const double2& lhs, const double2& rhs ) {
	return bool2(
		lhs.x > rhs.x,
		lhs.y > rhs.y
	);
}

bool2 operator>=( const double2& lhs, const double2& rhs ) {
	return bool2(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y
	);
}

