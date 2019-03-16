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

#include "hlml_operators_vector.h"

// int2
int2 operator+( const int2& lhs, const int32_t rhs ) {
	return int2(
		lhs.x + rhs,
		lhs.y + rhs
	);
}

int2 operator+=( int2& lhs, const int32_t rhs ) {
	return ( lhs = lhs + rhs );
}

int2 operator+( const int2& lhs, const int2& rhs ) {
	return int2(
		lhs.x + rhs.x,
		lhs.y + rhs.y
	);
}

int2 operator+=( int2& lhs, const int2& rhs ) {
	return ( lhs = lhs + rhs );
}

int2 operator-( const int2& lhs, const int32_t rhs ) {
	return int2(
		lhs.x - rhs,
		lhs.y - rhs
	);
}

int2 operator-=( int2& lhs, const int32_t rhs ) {
	return ( lhs = lhs - rhs );
}

int2 operator-( const int2& lhs, const int2& rhs ) {
	return int2(
		lhs.x - rhs.x,
		lhs.y - rhs.y
	);
}

int2 operator-=( int2& lhs, const int2& rhs ) {
	return ( lhs = lhs - rhs );
}

int2 operator*( const int2& lhs, const int32_t rhs ) {
	return int2(
		lhs.x * rhs,
		lhs.y * rhs
	);
}

int2 operator*=( int2& lhs, const int32_t rhs ) {
	return ( lhs = lhs * rhs );
}

int2 operator*( const int2& lhs, const int2& rhs ) {
	return int2(
		lhs.x * rhs.x,
		lhs.y * rhs.y
	);
}

int2 operator*=( int2& lhs, const int2& rhs ) {
	return ( lhs = lhs * rhs );
}

int2 operator/( const int2& lhs, const int32_t rhs ) {
	return int2(
		lhs.x / rhs,
		lhs.y / rhs
	);
}

int2 operator/=( int2& lhs, const int32_t rhs ) {
	return ( lhs = lhs / rhs );
}

int2 operator/( const int2& lhs, const int2& rhs ) {
	return int2(
		lhs.x / rhs.x,
		lhs.y / rhs.y
	);
}

int2 operator/=( int2& lhs, const int2& rhs ) {
	return ( lhs = lhs / rhs );
}

bool2 operator<( const int2& lhs, const int2& rhs ) {
	return bool2(
		lhs.x < rhs.x,
		lhs.y < rhs.y
	);
}

bool2 operator<=( const int2& lhs, const int2& rhs ) {
	return bool2(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y
	);
}

bool2 operator>( const int2& lhs, const int2& rhs ) {
	return bool2(
		lhs.x > rhs.x,
		lhs.y > rhs.y
	);
}

bool2 operator>=( const int2& lhs, const int2& rhs ) {
	return bool2(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y
	);
}

int2 operator&( const int2& lhs, const int32_t& rhs ) {
	return int2(
		lhs.x & rhs,
		lhs.y & rhs
	);
}

int2 operator&=( int2& lhs, const int32_t& rhs ) {
	return ( lhs = lhs & rhs );
}

int2 operator&( const int2& lhs, const int2& rhs ) {
	return int2(
		lhs.x & rhs.x,
		lhs.y & rhs.y
	);
}

int2 operator&=( int2& lhs, const int2& rhs ) {
	return ( lhs = lhs & rhs );
}

int2 operator|( const int2& lhs, const int32_t& rhs ) {
	return int2(
		lhs.x | rhs,
		lhs.y | rhs
	);
}

int2 operator|=( int2& lhs, const int32_t& rhs ) {
	return ( lhs = lhs | rhs );
}

int2 operator|( const int2& lhs, const int2& rhs ) {
	return int2(
		lhs.x | rhs.x,
		lhs.y | rhs.y
	);
}

int2 operator|=( int2& lhs, const int2& rhs ) {
	return ( lhs = lhs | rhs );
}

int2 operator^( const int2& lhs, const int32_t& rhs ) {
	return int2(
		lhs.x ^ rhs,
		lhs.y ^ rhs
	);
}

int2 operator^=( int2& lhs, const int32_t& rhs ) {
	return ( lhs = lhs ^ rhs );
}

int2 operator^( const int2& lhs, const int2& rhs ) {
	return int2(
		lhs.x ^ rhs.x,
		lhs.y ^ rhs.y
	);
}

int2 operator^=( int2& lhs, const int2& rhs ) {
	return ( lhs = lhs ^ rhs );
}

int2 operator<<( const int2& lhs, const int32_t& rhs ) {
	return int2(
		lhs.x << rhs,
		lhs.y << rhs
	);
}

int2 operator<<=( int2& lhs, const int32_t& rhs ) {
	return ( lhs = lhs << rhs );
}

int2 operator<<( const int2& lhs, const int2& rhs ) {
	return int2(
		lhs.x << rhs.x,
		lhs.y << rhs.y
	);
}

int2 operator<<=( int2& lhs, const int2& rhs ) {
	return ( lhs = lhs << rhs );
}

int2 operator>>( const int2& lhs, const int32_t& rhs ) {
	return int2(
		lhs.x >> rhs,
		lhs.y >> rhs
	);
}

int2 operator>>=( int2& lhs, const int32_t& rhs ) {
	return ( lhs = lhs >> rhs );
}

int2 operator>>( const int2& lhs, const int2& rhs ) {
	return int2(
		lhs.x >> rhs.x,
		lhs.y >> rhs.y
	);
}

int2 operator>>=( int2& lhs, const int2& rhs ) {
	return ( lhs = lhs >> rhs );
}

int2 operator~( const int2& lhs ) {
	return int2(
		~lhs.x,
		~lhs.y
	);
}


// int3
int3 operator+( const int3& lhs, const int32_t rhs ) {
	return int3(
		lhs.x + rhs,
		lhs.y + rhs,
		lhs.z + rhs
	);
}

int3 operator+=( int3& lhs, const int32_t rhs ) {
	return ( lhs = lhs + rhs );
}

int3 operator+( const int3& lhs, const int3& rhs ) {
	return int3(
		lhs.x + rhs.x,
		lhs.y + rhs.y,
		lhs.z + rhs.z
	);
}

int3 operator+=( int3& lhs, const int3& rhs ) {
	return ( lhs = lhs + rhs );
}

int3 operator-( const int3& lhs, const int32_t rhs ) {
	return int3(
		lhs.x - rhs,
		lhs.y - rhs,
		lhs.z - rhs
	);
}

int3 operator-=( int3& lhs, const int32_t rhs ) {
	return ( lhs = lhs - rhs );
}

int3 operator-( const int3& lhs, const int3& rhs ) {
	return int3(
		lhs.x - rhs.x,
		lhs.y - rhs.y,
		lhs.z - rhs.z
	);
}

int3 operator-=( int3& lhs, const int3& rhs ) {
	return ( lhs = lhs - rhs );
}

int3 operator*( const int3& lhs, const int32_t rhs ) {
	return int3(
		lhs.x * rhs,
		lhs.y * rhs,
		lhs.z * rhs
	);
}

int3 operator*=( int3& lhs, const int32_t rhs ) {
	return ( lhs = lhs * rhs );
}

int3 operator*( const int3& lhs, const int3& rhs ) {
	return int3(
		lhs.x * rhs.x,
		lhs.y * rhs.y,
		lhs.z * rhs.z
	);
}

int3 operator*=( int3& lhs, const int3& rhs ) {
	return ( lhs = lhs * rhs );
}

int3 operator/( const int3& lhs, const int32_t rhs ) {
	return int3(
		lhs.x / rhs,
		lhs.y / rhs,
		lhs.z / rhs
	);
}

int3 operator/=( int3& lhs, const int32_t rhs ) {
	return ( lhs = lhs / rhs );
}

int3 operator/( const int3& lhs, const int3& rhs ) {
	return int3(
		lhs.x / rhs.x,
		lhs.y / rhs.y,
		lhs.z / rhs.z
	);
}

int3 operator/=( int3& lhs, const int3& rhs ) {
	return ( lhs = lhs / rhs );
}

bool3 operator<( const int3& lhs, const int3& rhs ) {
	return bool3(
		lhs.x < rhs.x,
		lhs.y < rhs.y,
		lhs.z < rhs.z
	);
}

bool3 operator<=( const int3& lhs, const int3& rhs ) {
	return bool3(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y,
		lhs.z <= rhs.z
	);
}

bool3 operator>( const int3& lhs, const int3& rhs ) {
	return bool3(
		lhs.x > rhs.x,
		lhs.y > rhs.y,
		lhs.z > rhs.z
	);
}

bool3 operator>=( const int3& lhs, const int3& rhs ) {
	return bool3(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y,
		lhs.z >= rhs.z
	);
}

int3 operator&( const int3& lhs, const int32_t& rhs ) {
	return int3(
		lhs.x & rhs,
		lhs.y & rhs,
		lhs.z & rhs
	);
}

int3 operator&=( int3& lhs, const int32_t& rhs ) {
	return ( lhs = lhs & rhs );
}

int3 operator&( const int3& lhs, const int3& rhs ) {
	return int3(
		lhs.x & rhs.x,
		lhs.y & rhs.y,
		lhs.z & rhs.z
	);
}

int3 operator&=( int3& lhs, const int3& rhs ) {
	return ( lhs = lhs & rhs );
}

int3 operator|( const int3& lhs, const int32_t& rhs ) {
	return int3(
		lhs.x | rhs,
		lhs.y | rhs,
		lhs.z | rhs
	);
}

int3 operator|=( int3& lhs, const int32_t& rhs ) {
	return ( lhs = lhs | rhs );
}

int3 operator|( const int3& lhs, const int3& rhs ) {
	return int3(
		lhs.x | rhs.x,
		lhs.y | rhs.y,
		lhs.z | rhs.z
	);
}

int3 operator|=( int3& lhs, const int3& rhs ) {
	return ( lhs = lhs | rhs );
}

int3 operator^( const int3& lhs, const int32_t& rhs ) {
	return int3(
		lhs.x ^ rhs,
		lhs.y ^ rhs,
		lhs.z ^ rhs
	);
}

int3 operator^=( int3& lhs, const int32_t& rhs ) {
	return ( lhs = lhs ^ rhs );
}

int3 operator^( const int3& lhs, const int3& rhs ) {
	return int3(
		lhs.x ^ rhs.x,
		lhs.y ^ rhs.y,
		lhs.z ^ rhs.z
	);
}

int3 operator^=( int3& lhs, const int3& rhs ) {
	return ( lhs = lhs ^ rhs );
}

int3 operator<<( const int3& lhs, const int32_t& rhs ) {
	return int3(
		lhs.x << rhs,
		lhs.y << rhs,
		lhs.z << rhs
	);
}

int3 operator<<=( int3& lhs, const int32_t& rhs ) {
	return ( lhs = lhs << rhs );
}

int3 operator<<( const int3& lhs, const int3& rhs ) {
	return int3(
		lhs.x << rhs.x,
		lhs.y << rhs.y,
		lhs.z << rhs.z
	);
}

int3 operator<<=( int3& lhs, const int3& rhs ) {
	return ( lhs = lhs << rhs );
}

int3 operator>>( const int3& lhs, const int32_t& rhs ) {
	return int3(
		lhs.x >> rhs,
		lhs.y >> rhs,
		lhs.z >> rhs
	);
}

int3 operator>>=( int3& lhs, const int32_t& rhs ) {
	return ( lhs = lhs >> rhs );
}

int3 operator>>( const int3& lhs, const int3& rhs ) {
	return int3(
		lhs.x >> rhs.x,
		lhs.y >> rhs.y,
		lhs.z >> rhs.z
	);
}

int3 operator>>=( int3& lhs, const int3& rhs ) {
	return ( lhs = lhs >> rhs );
}

int3 operator~( const int3& lhs ) {
	return int3(
		~lhs.x,
		~lhs.y,
		~lhs.z
	);
}


// int4
int4 operator+( const int4& lhs, const int32_t rhs ) {
	return int4(
		lhs.x + rhs,
		lhs.y + rhs,
		lhs.z + rhs,
		lhs.w + rhs
	);
}

int4 operator+=( int4& lhs, const int32_t rhs ) {
	return ( lhs = lhs + rhs );
}

int4 operator+( const int4& lhs, const int4& rhs ) {
	return int4(
		lhs.x + rhs.x,
		lhs.y + rhs.y,
		lhs.z + rhs.z,
		lhs.w + rhs.w
	);
}

int4 operator+=( int4& lhs, const int4& rhs ) {
	return ( lhs = lhs + rhs );
}

int4 operator-( const int4& lhs, const int32_t rhs ) {
	return int4(
		lhs.x - rhs,
		lhs.y - rhs,
		lhs.z - rhs,
		lhs.w - rhs
	);
}

int4 operator-=( int4& lhs, const int32_t rhs ) {
	return ( lhs = lhs - rhs );
}

int4 operator-( const int4& lhs, const int4& rhs ) {
	return int4(
		lhs.x - rhs.x,
		lhs.y - rhs.y,
		lhs.z - rhs.z,
		lhs.w - rhs.w
	);
}

int4 operator-=( int4& lhs, const int4& rhs ) {
	return ( lhs = lhs - rhs );
}

int4 operator*( const int4& lhs, const int32_t rhs ) {
	return int4(
		lhs.x * rhs,
		lhs.y * rhs,
		lhs.z * rhs,
		lhs.w * rhs
	);
}

int4 operator*=( int4& lhs, const int32_t rhs ) {
	return ( lhs = lhs * rhs );
}

int4 operator*( const int4& lhs, const int4& rhs ) {
	return int4(
		lhs.x * rhs.x,
		lhs.y * rhs.y,
		lhs.z * rhs.z,
		lhs.w * rhs.w
	);
}

int4 operator*=( int4& lhs, const int4& rhs ) {
	return ( lhs = lhs * rhs );
}

int4 operator/( const int4& lhs, const int32_t rhs ) {
	return int4(
		lhs.x / rhs,
		lhs.y / rhs,
		lhs.z / rhs,
		lhs.w / rhs
	);
}

int4 operator/=( int4& lhs, const int32_t rhs ) {
	return ( lhs = lhs / rhs );
}

int4 operator/( const int4& lhs, const int4& rhs ) {
	return int4(
		lhs.x / rhs.x,
		lhs.y / rhs.y,
		lhs.z / rhs.z,
		lhs.w / rhs.w
	);
}

int4 operator/=( int4& lhs, const int4& rhs ) {
	return ( lhs = lhs / rhs );
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

int4 operator&( const int4& lhs, const int32_t& rhs ) {
	return int4(
		lhs.x & rhs,
		lhs.y & rhs,
		lhs.z & rhs,
		lhs.w & rhs
	);
}

int4 operator&=( int4& lhs, const int32_t& rhs ) {
	return ( lhs = lhs & rhs );
}

int4 operator&( const int4& lhs, const int4& rhs ) {
	return int4(
		lhs.x & rhs.x,
		lhs.y & rhs.y,
		lhs.z & rhs.z,
		lhs.w & rhs.w
	);
}

int4 operator&=( int4& lhs, const int4& rhs ) {
	return ( lhs = lhs & rhs );
}

int4 operator|( const int4& lhs, const int32_t& rhs ) {
	return int4(
		lhs.x | rhs,
		lhs.y | rhs,
		lhs.z | rhs,
		lhs.w | rhs
	);
}

int4 operator|=( int4& lhs, const int32_t& rhs ) {
	return ( lhs = lhs | rhs );
}

int4 operator|( const int4& lhs, const int4& rhs ) {
	return int4(
		lhs.x | rhs.x,
		lhs.y | rhs.y,
		lhs.z | rhs.z,
		lhs.w | rhs.w
	);
}

int4 operator|=( int4& lhs, const int4& rhs ) {
	return ( lhs = lhs | rhs );
}

int4 operator^( const int4& lhs, const int32_t& rhs ) {
	return int4(
		lhs.x ^ rhs,
		lhs.y ^ rhs,
		lhs.z ^ rhs,
		lhs.w ^ rhs
	);
}

int4 operator^=( int4& lhs, const int32_t& rhs ) {
	return ( lhs = lhs ^ rhs );
}

int4 operator^( const int4& lhs, const int4& rhs ) {
	return int4(
		lhs.x ^ rhs.x,
		lhs.y ^ rhs.y,
		lhs.z ^ rhs.z,
		lhs.w ^ rhs.w
	);
}

int4 operator^=( int4& lhs, const int4& rhs ) {
	return ( lhs = lhs ^ rhs );
}

int4 operator<<( const int4& lhs, const int32_t& rhs ) {
	return int4(
		lhs.x << rhs,
		lhs.y << rhs,
		lhs.z << rhs,
		lhs.w << rhs
	);
}

int4 operator<<=( int4& lhs, const int32_t& rhs ) {
	return ( lhs = lhs << rhs );
}

int4 operator<<( const int4& lhs, const int4& rhs ) {
	return int4(
		lhs.x << rhs.x,
		lhs.y << rhs.y,
		lhs.z << rhs.z,
		lhs.w << rhs.w
	);
}

int4 operator<<=( int4& lhs, const int4& rhs ) {
	return ( lhs = lhs << rhs );
}

int4 operator>>( const int4& lhs, const int32_t& rhs ) {
	return int4(
		lhs.x >> rhs,
		lhs.y >> rhs,
		lhs.z >> rhs,
		lhs.w >> rhs
	);
}

int4 operator>>=( int4& lhs, const int32_t& rhs ) {
	return ( lhs = lhs >> rhs );
}

int4 operator>>( const int4& lhs, const int4& rhs ) {
	return int4(
		lhs.x >> rhs.x,
		lhs.y >> rhs.y,
		lhs.z >> rhs.z,
		lhs.w >> rhs.w
	);
}

int4 operator>>=( int4& lhs, const int4& rhs ) {
	return ( lhs = lhs >> rhs );
}

int4 operator~( const int4& lhs ) {
	return int4(
		~lhs.x,
		~lhs.y,
		~lhs.z,
		~lhs.w
	);
}


// uint2
uint2 operator+( const uint2& lhs, const uint32_t rhs ) {
	return uint2(
		lhs.x + rhs,
		lhs.y + rhs
	);
}

uint2 operator+=( uint2& lhs, const uint32_t rhs ) {
	return ( lhs = lhs + rhs );
}

uint2 operator+( const uint2& lhs, const uint2& rhs ) {
	return uint2(
		lhs.x + rhs.x,
		lhs.y + rhs.y
	);
}

uint2 operator+=( uint2& lhs, const uint2& rhs ) {
	return ( lhs = lhs + rhs );
}

uint2 operator-( const uint2& lhs, const uint32_t rhs ) {
	return uint2(
		lhs.x - rhs,
		lhs.y - rhs
	);
}

uint2 operator-=( uint2& lhs, const uint32_t rhs ) {
	return ( lhs = lhs - rhs );
}

uint2 operator-( const uint2& lhs, const uint2& rhs ) {
	return uint2(
		lhs.x - rhs.x,
		lhs.y - rhs.y
	);
}

uint2 operator-=( uint2& lhs, const uint2& rhs ) {
	return ( lhs = lhs - rhs );
}

uint2 operator*( const uint2& lhs, const uint32_t rhs ) {
	return uint2(
		lhs.x * rhs,
		lhs.y * rhs
	);
}

uint2 operator*=( uint2& lhs, const uint32_t rhs ) {
	return ( lhs = lhs * rhs );
}

uint2 operator*( const uint2& lhs, const uint2& rhs ) {
	return uint2(
		lhs.x * rhs.x,
		lhs.y * rhs.y
	);
}

uint2 operator*=( uint2& lhs, const uint2& rhs ) {
	return ( lhs = lhs * rhs );
}

uint2 operator/( const uint2& lhs, const uint32_t rhs ) {
	return uint2(
		lhs.x / rhs,
		lhs.y / rhs
	);
}

uint2 operator/=( uint2& lhs, const uint32_t rhs ) {
	return ( lhs = lhs / rhs );
}

uint2 operator/( const uint2& lhs, const uint2& rhs ) {
	return uint2(
		lhs.x / rhs.x,
		lhs.y / rhs.y
	);
}

uint2 operator/=( uint2& lhs, const uint2& rhs ) {
	return ( lhs = lhs / rhs );
}

bool2 operator<( const uint2& lhs, const uint2& rhs ) {
	return bool2(
		lhs.x < rhs.x,
		lhs.y < rhs.y
	);
}

bool2 operator<=( const uint2& lhs, const uint2& rhs ) {
	return bool2(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y
	);
}

bool2 operator>( const uint2& lhs, const uint2& rhs ) {
	return bool2(
		lhs.x > rhs.x,
		lhs.y > rhs.y
	);
}

bool2 operator>=( const uint2& lhs, const uint2& rhs ) {
	return bool2(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y
	);
}

uint2 operator&( const uint2& lhs, const uint32_t& rhs ) {
	return uint2(
		lhs.x & rhs,
		lhs.y & rhs
	);
}

uint2 operator&=( uint2& lhs, const uint32_t& rhs ) {
	return ( lhs = lhs & rhs );
}

uint2 operator&( const uint2& lhs, const uint2& rhs ) {
	return uint2(
		lhs.x & rhs.x,
		lhs.y & rhs.y
	);
}

uint2 operator&=( uint2& lhs, const uint2& rhs ) {
	return ( lhs = lhs & rhs );
}

uint2 operator|( const uint2& lhs, const uint32_t& rhs ) {
	return uint2(
		lhs.x | rhs,
		lhs.y | rhs
	);
}

uint2 operator|=( uint2& lhs, const uint32_t& rhs ) {
	return ( lhs = lhs | rhs );
}

uint2 operator|( const uint2& lhs, const uint2& rhs ) {
	return uint2(
		lhs.x | rhs.x,
		lhs.y | rhs.y
	);
}

uint2 operator|=( uint2& lhs, const uint2& rhs ) {
	return ( lhs = lhs | rhs );
}

uint2 operator^( const uint2& lhs, const uint32_t& rhs ) {
	return uint2(
		lhs.x ^ rhs,
		lhs.y ^ rhs
	);
}

uint2 operator^=( uint2& lhs, const uint32_t& rhs ) {
	return ( lhs = lhs ^ rhs );
}

uint2 operator^( const uint2& lhs, const uint2& rhs ) {
	return uint2(
		lhs.x ^ rhs.x,
		lhs.y ^ rhs.y
	);
}

uint2 operator^=( uint2& lhs, const uint2& rhs ) {
	return ( lhs = lhs ^ rhs );
}

uint2 operator<<( const uint2& lhs, const uint32_t& rhs ) {
	return uint2(
		lhs.x << rhs,
		lhs.y << rhs
	);
}

uint2 operator<<=( uint2& lhs, const uint32_t& rhs ) {
	return ( lhs = lhs << rhs );
}

uint2 operator<<( const uint2& lhs, const uint2& rhs ) {
	return uint2(
		lhs.x << rhs.x,
		lhs.y << rhs.y
	);
}

uint2 operator<<=( uint2& lhs, const uint2& rhs ) {
	return ( lhs = lhs << rhs );
}

uint2 operator>>( const uint2& lhs, const uint32_t& rhs ) {
	return uint2(
		lhs.x >> rhs,
		lhs.y >> rhs
	);
}

uint2 operator>>=( uint2& lhs, const uint32_t& rhs ) {
	return ( lhs = lhs >> rhs );
}

uint2 operator>>( const uint2& lhs, const uint2& rhs ) {
	return uint2(
		lhs.x >> rhs.x,
		lhs.y >> rhs.y
	);
}

uint2 operator>>=( uint2& lhs, const uint2& rhs ) {
	return ( lhs = lhs >> rhs );
}

uint2 operator~( const uint2& lhs ) {
	return uint2(
		~lhs.x,
		~lhs.y
	);
}


// uint3
uint3 operator+( const uint3& lhs, const uint32_t rhs ) {
	return uint3(
		lhs.x + rhs,
		lhs.y + rhs,
		lhs.z + rhs
	);
}

uint3 operator+=( uint3& lhs, const uint32_t rhs ) {
	return ( lhs = lhs + rhs );
}

uint3 operator+( const uint3& lhs, const uint3& rhs ) {
	return uint3(
		lhs.x + rhs.x,
		lhs.y + rhs.y,
		lhs.z + rhs.z
	);
}

uint3 operator+=( uint3& lhs, const uint3& rhs ) {
	return ( lhs = lhs + rhs );
}

uint3 operator-( const uint3& lhs, const uint32_t rhs ) {
	return uint3(
		lhs.x - rhs,
		lhs.y - rhs,
		lhs.z - rhs
	);
}

uint3 operator-=( uint3& lhs, const uint32_t rhs ) {
	return ( lhs = lhs - rhs );
}

uint3 operator-( const uint3& lhs, const uint3& rhs ) {
	return uint3(
		lhs.x - rhs.x,
		lhs.y - rhs.y,
		lhs.z - rhs.z
	);
}

uint3 operator-=( uint3& lhs, const uint3& rhs ) {
	return ( lhs = lhs - rhs );
}

uint3 operator*( const uint3& lhs, const uint32_t rhs ) {
	return uint3(
		lhs.x * rhs,
		lhs.y * rhs,
		lhs.z * rhs
	);
}

uint3 operator*=( uint3& lhs, const uint32_t rhs ) {
	return ( lhs = lhs * rhs );
}

uint3 operator*( const uint3& lhs, const uint3& rhs ) {
	return uint3(
		lhs.x * rhs.x,
		lhs.y * rhs.y,
		lhs.z * rhs.z
	);
}

uint3 operator*=( uint3& lhs, const uint3& rhs ) {
	return ( lhs = lhs * rhs );
}

uint3 operator/( const uint3& lhs, const uint32_t rhs ) {
	return uint3(
		lhs.x / rhs,
		lhs.y / rhs,
		lhs.z / rhs
	);
}

uint3 operator/=( uint3& lhs, const uint32_t rhs ) {
	return ( lhs = lhs / rhs );
}

uint3 operator/( const uint3& lhs, const uint3& rhs ) {
	return uint3(
		lhs.x / rhs.x,
		lhs.y / rhs.y,
		lhs.z / rhs.z
	);
}

uint3 operator/=( uint3& lhs, const uint3& rhs ) {
	return ( lhs = lhs / rhs );
}

bool3 operator<( const uint3& lhs, const uint3& rhs ) {
	return bool3(
		lhs.x < rhs.x,
		lhs.y < rhs.y,
		lhs.z < rhs.z
	);
}

bool3 operator<=( const uint3& lhs, const uint3& rhs ) {
	return bool3(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y,
		lhs.z <= rhs.z
	);
}

bool3 operator>( const uint3& lhs, const uint3& rhs ) {
	return bool3(
		lhs.x > rhs.x,
		lhs.y > rhs.y,
		lhs.z > rhs.z
	);
}

bool3 operator>=( const uint3& lhs, const uint3& rhs ) {
	return bool3(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y,
		lhs.z >= rhs.z
	);
}

uint3 operator&( const uint3& lhs, const uint32_t& rhs ) {
	return uint3(
		lhs.x & rhs,
		lhs.y & rhs,
		lhs.z & rhs
	);
}

uint3 operator&=( uint3& lhs, const uint32_t& rhs ) {
	return ( lhs = lhs & rhs );
}

uint3 operator&( const uint3& lhs, const uint3& rhs ) {
	return uint3(
		lhs.x & rhs.x,
		lhs.y & rhs.y,
		lhs.z & rhs.z
	);
}

uint3 operator&=( uint3& lhs, const uint3& rhs ) {
	return ( lhs = lhs & rhs );
}

uint3 operator|( const uint3& lhs, const uint32_t& rhs ) {
	return uint3(
		lhs.x | rhs,
		lhs.y | rhs,
		lhs.z | rhs
	);
}

uint3 operator|=( uint3& lhs, const uint32_t& rhs ) {
	return ( lhs = lhs | rhs );
}

uint3 operator|( const uint3& lhs, const uint3& rhs ) {
	return uint3(
		lhs.x | rhs.x,
		lhs.y | rhs.y,
		lhs.z | rhs.z
	);
}

uint3 operator|=( uint3& lhs, const uint3& rhs ) {
	return ( lhs = lhs | rhs );
}

uint3 operator^( const uint3& lhs, const uint32_t& rhs ) {
	return uint3(
		lhs.x ^ rhs,
		lhs.y ^ rhs,
		lhs.z ^ rhs
	);
}

uint3 operator^=( uint3& lhs, const uint32_t& rhs ) {
	return ( lhs = lhs ^ rhs );
}

uint3 operator^( const uint3& lhs, const uint3& rhs ) {
	return uint3(
		lhs.x ^ rhs.x,
		lhs.y ^ rhs.y,
		lhs.z ^ rhs.z
	);
}

uint3 operator^=( uint3& lhs, const uint3& rhs ) {
	return ( lhs = lhs ^ rhs );
}

uint3 operator<<( const uint3& lhs, const uint32_t& rhs ) {
	return uint3(
		lhs.x << rhs,
		lhs.y << rhs,
		lhs.z << rhs
	);
}

uint3 operator<<=( uint3& lhs, const uint32_t& rhs ) {
	return ( lhs = lhs << rhs );
}

uint3 operator<<( const uint3& lhs, const uint3& rhs ) {
	return uint3(
		lhs.x << rhs.x,
		lhs.y << rhs.y,
		lhs.z << rhs.z
	);
}

uint3 operator<<=( uint3& lhs, const uint3& rhs ) {
	return ( lhs = lhs << rhs );
}

uint3 operator>>( const uint3& lhs, const uint32_t& rhs ) {
	return uint3(
		lhs.x >> rhs,
		lhs.y >> rhs,
		lhs.z >> rhs
	);
}

uint3 operator>>=( uint3& lhs, const uint32_t& rhs ) {
	return ( lhs = lhs >> rhs );
}

uint3 operator>>( const uint3& lhs, const uint3& rhs ) {
	return uint3(
		lhs.x >> rhs.x,
		lhs.y >> rhs.y,
		lhs.z >> rhs.z
	);
}

uint3 operator>>=( uint3& lhs, const uint3& rhs ) {
	return ( lhs = lhs >> rhs );
}

uint3 operator~( const uint3& lhs ) {
	return uint3(
		~lhs.x,
		~lhs.y,
		~lhs.z
	);
}


// uint4
uint4 operator+( const uint4& lhs, const uint32_t rhs ) {
	return uint4(
		lhs.x + rhs,
		lhs.y + rhs,
		lhs.z + rhs,
		lhs.w + rhs
	);
}

uint4 operator+=( uint4& lhs, const uint32_t rhs ) {
	return ( lhs = lhs + rhs );
}

uint4 operator+( const uint4& lhs, const uint4& rhs ) {
	return uint4(
		lhs.x + rhs.x,
		lhs.y + rhs.y,
		lhs.z + rhs.z,
		lhs.w + rhs.w
	);
}

uint4 operator+=( uint4& lhs, const uint4& rhs ) {
	return ( lhs = lhs + rhs );
}

uint4 operator-( const uint4& lhs, const uint32_t rhs ) {
	return uint4(
		lhs.x - rhs,
		lhs.y - rhs,
		lhs.z - rhs,
		lhs.w - rhs
	);
}

uint4 operator-=( uint4& lhs, const uint32_t rhs ) {
	return ( lhs = lhs - rhs );
}

uint4 operator-( const uint4& lhs, const uint4& rhs ) {
	return uint4(
		lhs.x - rhs.x,
		lhs.y - rhs.y,
		lhs.z - rhs.z,
		lhs.w - rhs.w
	);
}

uint4 operator-=( uint4& lhs, const uint4& rhs ) {
	return ( lhs = lhs - rhs );
}

uint4 operator*( const uint4& lhs, const uint32_t rhs ) {
	return uint4(
		lhs.x * rhs,
		lhs.y * rhs,
		lhs.z * rhs,
		lhs.w * rhs
	);
}

uint4 operator*=( uint4& lhs, const uint32_t rhs ) {
	return ( lhs = lhs * rhs );
}

uint4 operator*( const uint4& lhs, const uint4& rhs ) {
	return uint4(
		lhs.x * rhs.x,
		lhs.y * rhs.y,
		lhs.z * rhs.z,
		lhs.w * rhs.w
	);
}

uint4 operator*=( uint4& lhs, const uint4& rhs ) {
	return ( lhs = lhs * rhs );
}

uint4 operator/( const uint4& lhs, const uint32_t rhs ) {
	return uint4(
		lhs.x / rhs,
		lhs.y / rhs,
		lhs.z / rhs,
		lhs.w / rhs
	);
}

uint4 operator/=( uint4& lhs, const uint32_t rhs ) {
	return ( lhs = lhs / rhs );
}

uint4 operator/( const uint4& lhs, const uint4& rhs ) {
	return uint4(
		lhs.x / rhs.x,
		lhs.y / rhs.y,
		lhs.z / rhs.z,
		lhs.w / rhs.w
	);
}

uint4 operator/=( uint4& lhs, const uint4& rhs ) {
	return ( lhs = lhs / rhs );
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

uint4 operator&( const uint4& lhs, const uint32_t& rhs ) {
	return uint4(
		lhs.x & rhs,
		lhs.y & rhs,
		lhs.z & rhs,
		lhs.w & rhs
	);
}

uint4 operator&=( uint4& lhs, const uint32_t& rhs ) {
	return ( lhs = lhs & rhs );
}

uint4 operator&( const uint4& lhs, const uint4& rhs ) {
	return uint4(
		lhs.x & rhs.x,
		lhs.y & rhs.y,
		lhs.z & rhs.z,
		lhs.w & rhs.w
	);
}

uint4 operator&=( uint4& lhs, const uint4& rhs ) {
	return ( lhs = lhs & rhs );
}

uint4 operator|( const uint4& lhs, const uint32_t& rhs ) {
	return uint4(
		lhs.x | rhs,
		lhs.y | rhs,
		lhs.z | rhs,
		lhs.w | rhs
	);
}

uint4 operator|=( uint4& lhs, const uint32_t& rhs ) {
	return ( lhs = lhs | rhs );
}

uint4 operator|( const uint4& lhs, const uint4& rhs ) {
	return uint4(
		lhs.x | rhs.x,
		lhs.y | rhs.y,
		lhs.z | rhs.z,
		lhs.w | rhs.w
	);
}

uint4 operator|=( uint4& lhs, const uint4& rhs ) {
	return ( lhs = lhs | rhs );
}

uint4 operator^( const uint4& lhs, const uint32_t& rhs ) {
	return uint4(
		lhs.x ^ rhs,
		lhs.y ^ rhs,
		lhs.z ^ rhs,
		lhs.w ^ rhs
	);
}

uint4 operator^=( uint4& lhs, const uint32_t& rhs ) {
	return ( lhs = lhs ^ rhs );
}

uint4 operator^( const uint4& lhs, const uint4& rhs ) {
	return uint4(
		lhs.x ^ rhs.x,
		lhs.y ^ rhs.y,
		lhs.z ^ rhs.z,
		lhs.w ^ rhs.w
	);
}

uint4 operator^=( uint4& lhs, const uint4& rhs ) {
	return ( lhs = lhs ^ rhs );
}

uint4 operator<<( const uint4& lhs, const uint32_t& rhs ) {
	return uint4(
		lhs.x << rhs,
		lhs.y << rhs,
		lhs.z << rhs,
		lhs.w << rhs
	);
}

uint4 operator<<=( uint4& lhs, const uint32_t& rhs ) {
	return ( lhs = lhs << rhs );
}

uint4 operator<<( const uint4& lhs, const uint4& rhs ) {
	return uint4(
		lhs.x << rhs.x,
		lhs.y << rhs.y,
		lhs.z << rhs.z,
		lhs.w << rhs.w
	);
}

uint4 operator<<=( uint4& lhs, const uint4& rhs ) {
	return ( lhs = lhs << rhs );
}

uint4 operator>>( const uint4& lhs, const uint32_t& rhs ) {
	return uint4(
		lhs.x >> rhs,
		lhs.y >> rhs,
		lhs.z >> rhs,
		lhs.w >> rhs
	);
}

uint4 operator>>=( uint4& lhs, const uint32_t& rhs ) {
	return ( lhs = lhs >> rhs );
}

uint4 operator>>( const uint4& lhs, const uint4& rhs ) {
	return uint4(
		lhs.x >> rhs.x,
		lhs.y >> rhs.y,
		lhs.z >> rhs.z,
		lhs.w >> rhs.w
	);
}

uint4 operator>>=( uint4& lhs, const uint4& rhs ) {
	return ( lhs = lhs >> rhs );
}

uint4 operator~( const uint4& lhs ) {
	return uint4(
		~lhs.x,
		~lhs.y,
		~lhs.z,
		~lhs.w
	);
}


// float2
float2 operator+( const float2& lhs, const float rhs ) {
	return float2(
		lhs.x + rhs,
		lhs.y + rhs
	);
}

float2 operator+=( float2& lhs, const float rhs ) {
	return ( lhs = lhs + rhs );
}

float2 operator+( const float2& lhs, const float2& rhs ) {
	return float2(
		lhs.x + rhs.x,
		lhs.y + rhs.y
	);
}

float2 operator+=( float2& lhs, const float2& rhs ) {
	return ( lhs = lhs + rhs );
}

float2 operator-( const float2& lhs, const float rhs ) {
	return float2(
		lhs.x - rhs,
		lhs.y - rhs
	);
}

float2 operator-=( float2& lhs, const float rhs ) {
	return ( lhs = lhs - rhs );
}

float2 operator-( const float2& lhs, const float2& rhs ) {
	return float2(
		lhs.x - rhs.x,
		lhs.y - rhs.y
	);
}

float2 operator-=( float2& lhs, const float2& rhs ) {
	return ( lhs = lhs - rhs );
}

float2 operator*( const float2& lhs, const float rhs ) {
	return float2(
		lhs.x * rhs,
		lhs.y * rhs
	);
}

float2 operator*=( float2& lhs, const float rhs ) {
	return ( lhs = lhs * rhs );
}

float2 operator*( const float2& lhs, const float2& rhs ) {
	return float2(
		lhs.x * rhs.x,
		lhs.y * rhs.y
	);
}

float2 operator*=( float2& lhs, const float2& rhs ) {
	return ( lhs = lhs * rhs );
}

float2 operator/( const float2& lhs, const float rhs ) {
	return float2(
		lhs.x / rhs,
		lhs.y / rhs
	);
}

float2 operator/=( float2& lhs, const float rhs ) {
	return ( lhs = lhs / rhs );
}

float2 operator/( const float2& lhs, const float2& rhs ) {
	return float2(
		lhs.x / rhs.x,
		lhs.y / rhs.y
	);
}

float2 operator/=( float2& lhs, const float2& rhs ) {
	return ( lhs = lhs / rhs );
}

bool2 operator<( const float2& lhs, const float2& rhs ) {
	return bool2(
		lhs.x < rhs.x,
		lhs.y < rhs.y
	);
}

bool2 operator<=( const float2& lhs, const float2& rhs ) {
	return bool2(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y
	);
}

bool2 operator>( const float2& lhs, const float2& rhs ) {
	return bool2(
		lhs.x > rhs.x,
		lhs.y > rhs.y
	);
}

bool2 operator>=( const float2& lhs, const float2& rhs ) {
	return bool2(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y
	);
}


// float3
float3 operator+( const float3& lhs, const float rhs ) {
	return float3(
		lhs.x + rhs,
		lhs.y + rhs,
		lhs.z + rhs
	);
}

float3 operator+=( float3& lhs, const float rhs ) {
	return ( lhs = lhs + rhs );
}

float3 operator+( const float3& lhs, const float3& rhs ) {
	return float3(
		lhs.x + rhs.x,
		lhs.y + rhs.y,
		lhs.z + rhs.z
	);
}

float3 operator+=( float3& lhs, const float3& rhs ) {
	return ( lhs = lhs + rhs );
}

float3 operator-( const float3& lhs, const float rhs ) {
	return float3(
		lhs.x - rhs,
		lhs.y - rhs,
		lhs.z - rhs
	);
}

float3 operator-=( float3& lhs, const float rhs ) {
	return ( lhs = lhs - rhs );
}

float3 operator-( const float3& lhs, const float3& rhs ) {
	return float3(
		lhs.x - rhs.x,
		lhs.y - rhs.y,
		lhs.z - rhs.z
	);
}

float3 operator-=( float3& lhs, const float3& rhs ) {
	return ( lhs = lhs - rhs );
}

float3 operator*( const float3& lhs, const float rhs ) {
	return float3(
		lhs.x * rhs,
		lhs.y * rhs,
		lhs.z * rhs
	);
}

float3 operator*=( float3& lhs, const float rhs ) {
	return ( lhs = lhs * rhs );
}

float3 operator*( const float3& lhs, const float3& rhs ) {
	return float3(
		lhs.x * rhs.x,
		lhs.y * rhs.y,
		lhs.z * rhs.z
	);
}

float3 operator*=( float3& lhs, const float3& rhs ) {
	return ( lhs = lhs * rhs );
}

float3 operator/( const float3& lhs, const float rhs ) {
	return float3(
		lhs.x / rhs,
		lhs.y / rhs,
		lhs.z / rhs
	);
}

float3 operator/=( float3& lhs, const float rhs ) {
	return ( lhs = lhs / rhs );
}

float3 operator/( const float3& lhs, const float3& rhs ) {
	return float3(
		lhs.x / rhs.x,
		lhs.y / rhs.y,
		lhs.z / rhs.z
	);
}

float3 operator/=( float3& lhs, const float3& rhs ) {
	return ( lhs = lhs / rhs );
}

bool3 operator<( const float3& lhs, const float3& rhs ) {
	return bool3(
		lhs.x < rhs.x,
		lhs.y < rhs.y,
		lhs.z < rhs.z
	);
}

bool3 operator<=( const float3& lhs, const float3& rhs ) {
	return bool3(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y,
		lhs.z <= rhs.z
	);
}

bool3 operator>( const float3& lhs, const float3& rhs ) {
	return bool3(
		lhs.x > rhs.x,
		lhs.y > rhs.y,
		lhs.z > rhs.z
	);
}

bool3 operator>=( const float3& lhs, const float3& rhs ) {
	return bool3(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y,
		lhs.z >= rhs.z
	);
}


// float4
float4 operator+( const float4& lhs, const float rhs ) {
	return float4(
		lhs.x + rhs,
		lhs.y + rhs,
		lhs.z + rhs,
		lhs.w + rhs
	);
}

float4 operator+=( float4& lhs, const float rhs ) {
	return ( lhs = lhs + rhs );
}

float4 operator+( const float4& lhs, const float4& rhs ) {
	return float4(
		lhs.x + rhs.x,
		lhs.y + rhs.y,
		lhs.z + rhs.z,
		lhs.w + rhs.w
	);
}

float4 operator+=( float4& lhs, const float4& rhs ) {
	return ( lhs = lhs + rhs );
}

float4 operator-( const float4& lhs, const float rhs ) {
	return float4(
		lhs.x - rhs,
		lhs.y - rhs,
		lhs.z - rhs,
		lhs.w - rhs
	);
}

float4 operator-=( float4& lhs, const float rhs ) {
	return ( lhs = lhs - rhs );
}

float4 operator-( const float4& lhs, const float4& rhs ) {
	return float4(
		lhs.x - rhs.x,
		lhs.y - rhs.y,
		lhs.z - rhs.z,
		lhs.w - rhs.w
	);
}

float4 operator-=( float4& lhs, const float4& rhs ) {
	return ( lhs = lhs - rhs );
}

float4 operator*( const float4& lhs, const float rhs ) {
	return float4(
		lhs.x * rhs,
		lhs.y * rhs,
		lhs.z * rhs,
		lhs.w * rhs
	);
}

float4 operator*=( float4& lhs, const float rhs ) {
	return ( lhs = lhs * rhs );
}

float4 operator*( const float4& lhs, const float4& rhs ) {
	return float4(
		lhs.x * rhs.x,
		lhs.y * rhs.y,
		lhs.z * rhs.z,
		lhs.w * rhs.w
	);
}

float4 operator*=( float4& lhs, const float4& rhs ) {
	return ( lhs = lhs * rhs );
}

float4 operator/( const float4& lhs, const float rhs ) {
	return float4(
		lhs.x / rhs,
		lhs.y / rhs,
		lhs.z / rhs,
		lhs.w / rhs
	);
}

float4 operator/=( float4& lhs, const float rhs ) {
	return ( lhs = lhs / rhs );
}

float4 operator/( const float4& lhs, const float4& rhs ) {
	return float4(
		lhs.x / rhs.x,
		lhs.y / rhs.y,
		lhs.z / rhs.z,
		lhs.w / rhs.w
	);
}

float4 operator/=( float4& lhs, const float4& rhs ) {
	return ( lhs = lhs / rhs );
}

bool4 operator<( const float4& lhs, const float4& rhs ) {
	return bool4(
		lhs.x < rhs.x,
		lhs.y < rhs.y,
		lhs.z < rhs.z,
		lhs.w < rhs.w
	);
}

bool4 operator<=( const float4& lhs, const float4& rhs ) {
	return bool4(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y,
		lhs.z <= rhs.z,
		lhs.w <= rhs.w
	);
}

bool4 operator>( const float4& lhs, const float4& rhs ) {
	return bool4(
		lhs.x > rhs.x,
		lhs.y > rhs.y,
		lhs.z > rhs.z,
		lhs.w > rhs.w
	);
}

bool4 operator>=( const float4& lhs, const float4& rhs ) {
	return bool4(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y,
		lhs.z >= rhs.z,
		lhs.w >= rhs.w
	);
}


// double2
double2 operator+( const double2& lhs, const double rhs ) {
	return double2(
		lhs.x + rhs,
		lhs.y + rhs
	);
}

double2 operator+=( double2& lhs, const double rhs ) {
	return ( lhs = lhs + rhs );
}

double2 operator+( const double2& lhs, const double2& rhs ) {
	return double2(
		lhs.x + rhs.x,
		lhs.y + rhs.y
	);
}

double2 operator+=( double2& lhs, const double2& rhs ) {
	return ( lhs = lhs + rhs );
}

double2 operator-( const double2& lhs, const double rhs ) {
	return double2(
		lhs.x - rhs,
		lhs.y - rhs
	);
}

double2 operator-=( double2& lhs, const double rhs ) {
	return ( lhs = lhs - rhs );
}

double2 operator-( const double2& lhs, const double2& rhs ) {
	return double2(
		lhs.x - rhs.x,
		lhs.y - rhs.y
	);
}

double2 operator-=( double2& lhs, const double2& rhs ) {
	return ( lhs = lhs - rhs );
}

double2 operator*( const double2& lhs, const double rhs ) {
	return double2(
		lhs.x * rhs,
		lhs.y * rhs
	);
}

double2 operator*=( double2& lhs, const double rhs ) {
	return ( lhs = lhs * rhs );
}

double2 operator*( const double2& lhs, const double2& rhs ) {
	return double2(
		lhs.x * rhs.x,
		lhs.y * rhs.y
	);
}

double2 operator*=( double2& lhs, const double2& rhs ) {
	return ( lhs = lhs * rhs );
}

double2 operator/( const double2& lhs, const double rhs ) {
	return double2(
		lhs.x / rhs,
		lhs.y / rhs
	);
}

double2 operator/=( double2& lhs, const double rhs ) {
	return ( lhs = lhs / rhs );
}

double2 operator/( const double2& lhs, const double2& rhs ) {
	return double2(
		lhs.x / rhs.x,
		lhs.y / rhs.y
	);
}

double2 operator/=( double2& lhs, const double2& rhs ) {
	return ( lhs = lhs / rhs );
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


// double3
double3 operator+( const double3& lhs, const double rhs ) {
	return double3(
		lhs.x + rhs,
		lhs.y + rhs,
		lhs.z + rhs
	);
}

double3 operator+=( double3& lhs, const double rhs ) {
	return ( lhs = lhs + rhs );
}

double3 operator+( const double3& lhs, const double3& rhs ) {
	return double3(
		lhs.x + rhs.x,
		lhs.y + rhs.y,
		lhs.z + rhs.z
	);
}

double3 operator+=( double3& lhs, const double3& rhs ) {
	return ( lhs = lhs + rhs );
}

double3 operator-( const double3& lhs, const double rhs ) {
	return double3(
		lhs.x - rhs,
		lhs.y - rhs,
		lhs.z - rhs
	);
}

double3 operator-=( double3& lhs, const double rhs ) {
	return ( lhs = lhs - rhs );
}

double3 operator-( const double3& lhs, const double3& rhs ) {
	return double3(
		lhs.x - rhs.x,
		lhs.y - rhs.y,
		lhs.z - rhs.z
	);
}

double3 operator-=( double3& lhs, const double3& rhs ) {
	return ( lhs = lhs - rhs );
}

double3 operator*( const double3& lhs, const double rhs ) {
	return double3(
		lhs.x * rhs,
		lhs.y * rhs,
		lhs.z * rhs
	);
}

double3 operator*=( double3& lhs, const double rhs ) {
	return ( lhs = lhs * rhs );
}

double3 operator*( const double3& lhs, const double3& rhs ) {
	return double3(
		lhs.x * rhs.x,
		lhs.y * rhs.y,
		lhs.z * rhs.z
	);
}

double3 operator*=( double3& lhs, const double3& rhs ) {
	return ( lhs = lhs * rhs );
}

double3 operator/( const double3& lhs, const double rhs ) {
	return double3(
		lhs.x / rhs,
		lhs.y / rhs,
		lhs.z / rhs
	);
}

double3 operator/=( double3& lhs, const double rhs ) {
	return ( lhs = lhs / rhs );
}

double3 operator/( const double3& lhs, const double3& rhs ) {
	return double3(
		lhs.x / rhs.x,
		lhs.y / rhs.y,
		lhs.z / rhs.z
	);
}

double3 operator/=( double3& lhs, const double3& rhs ) {
	return ( lhs = lhs / rhs );
}

bool3 operator<( const double3& lhs, const double3& rhs ) {
	return bool3(
		lhs.x < rhs.x,
		lhs.y < rhs.y,
		lhs.z < rhs.z
	);
}

bool3 operator<=( const double3& lhs, const double3& rhs ) {
	return bool3(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y,
		lhs.z <= rhs.z
	);
}

bool3 operator>( const double3& lhs, const double3& rhs ) {
	return bool3(
		lhs.x > rhs.x,
		lhs.y > rhs.y,
		lhs.z > rhs.z
	);
}

bool3 operator>=( const double3& lhs, const double3& rhs ) {
	return bool3(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y,
		lhs.z >= rhs.z
	);
}


// double4
double4 operator+( const double4& lhs, const double rhs ) {
	return double4(
		lhs.x + rhs,
		lhs.y + rhs,
		lhs.z + rhs,
		lhs.w + rhs
	);
}

double4 operator+=( double4& lhs, const double rhs ) {
	return ( lhs = lhs + rhs );
}

double4 operator+( const double4& lhs, const double4& rhs ) {
	return double4(
		lhs.x + rhs.x,
		lhs.y + rhs.y,
		lhs.z + rhs.z,
		lhs.w + rhs.w
	);
}

double4 operator+=( double4& lhs, const double4& rhs ) {
	return ( lhs = lhs + rhs );
}

double4 operator-( const double4& lhs, const double rhs ) {
	return double4(
		lhs.x - rhs,
		lhs.y - rhs,
		lhs.z - rhs,
		lhs.w - rhs
	);
}

double4 operator-=( double4& lhs, const double rhs ) {
	return ( lhs = lhs - rhs );
}

double4 operator-( const double4& lhs, const double4& rhs ) {
	return double4(
		lhs.x - rhs.x,
		lhs.y - rhs.y,
		lhs.z - rhs.z,
		lhs.w - rhs.w
	);
}

double4 operator-=( double4& lhs, const double4& rhs ) {
	return ( lhs = lhs - rhs );
}

double4 operator*( const double4& lhs, const double rhs ) {
	return double4(
		lhs.x * rhs,
		lhs.y * rhs,
		lhs.z * rhs,
		lhs.w * rhs
	);
}

double4 operator*=( double4& lhs, const double rhs ) {
	return ( lhs = lhs * rhs );
}

double4 operator*( const double4& lhs, const double4& rhs ) {
	return double4(
		lhs.x * rhs.x,
		lhs.y * rhs.y,
		lhs.z * rhs.z,
		lhs.w * rhs.w
	);
}

double4 operator*=( double4& lhs, const double4& rhs ) {
	return ( lhs = lhs * rhs );
}

double4 operator/( const double4& lhs, const double rhs ) {
	return double4(
		lhs.x / rhs,
		lhs.y / rhs,
		lhs.z / rhs,
		lhs.w / rhs
	);
}

double4 operator/=( double4& lhs, const double rhs ) {
	return ( lhs = lhs / rhs );
}

double4 operator/( const double4& lhs, const double4& rhs ) {
	return double4(
		lhs.x / rhs.x,
		lhs.y / rhs.y,
		lhs.z / rhs.z,
		lhs.w / rhs.w
	);
}

double4 operator/=( double4& lhs, const double4& rhs ) {
	return ( lhs = lhs / rhs );
}

bool4 operator<( const double4& lhs, const double4& rhs ) {
	return bool4(
		lhs.x < rhs.x,
		lhs.y < rhs.y,
		lhs.z < rhs.z,
		lhs.w < rhs.w
	);
}

bool4 operator<=( const double4& lhs, const double4& rhs ) {
	return bool4(
		lhs.x <= rhs.x,
		lhs.y <= rhs.y,
		lhs.z <= rhs.z,
		lhs.w <= rhs.w
	);
}

bool4 operator>( const double4& lhs, const double4& rhs ) {
	return bool4(
		lhs.x > rhs.x,
		lhs.y > rhs.y,
		lhs.z > rhs.z,
		lhs.w > rhs.w
	);
}

bool4 operator>=( const double4& lhs, const double4& rhs ) {
	return bool4(
		lhs.x >= rhs.x,
		lhs.y >= rhs.y,
		lhs.z >= rhs.z,
		lhs.w >= rhs.w
	);
}


