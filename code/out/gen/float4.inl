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
#include "float2.h"
#include "float3.h"

#include "../hlml_main.h"

// others
#include <math.h>
#include <memory.h>
#include <assert.h>

float4::float4() {
	memset( data, 0, 4 * sizeof( float ) );
}

float4::float4( const float x ) {
	this->x = this->y = this->z = this->w = x;
}

float4::float4( const float x, const float y, const float z, const float w ) {
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

float4::float4( const float2& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

float4::float4( const float3& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

float4::float4( const float4& other ) {
	memcpy( data, other.data, sizeof( other.data ) );
}

float4 float4::operator=( const float2& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

float4 float4::operator=( const float3& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

float4 float4::operator=( const float4& rhs ) {
	memcpy( data, rhs.data, sizeof( rhs.data ) );
	return *this;
}

const float& float4::operator[]( const uint32_t index ) const {
	assert( index < 4 );
	return data[index];
}

float& float4::operator[]( const uint32_t index ) {
	assert( index < 4 );
	return data[index];
}

bool operator==( const float4& lhs, const float4& rhs ) {
	return floateq( lhs.x, rhs. x ) && floateq( lhs.y, rhs. y ) && floateq( lhs.z, rhs. z ) && floateq( lhs.w, rhs. w );
}

bool operator!=( const float4& lhs, const float4& rhs ) {
	return !( operator==( lhs, rhs ) );
}

