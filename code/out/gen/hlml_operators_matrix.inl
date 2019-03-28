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

#include "hlml_operators_matrix.h"

// int2x2
int2x2 operator+( const int2x2& lhs, const int32_t rhs )
{
	return int2x2(
		lhs[0] + rhs,
		lhs[1] + rhs
	);
}

int2x2 operator+=( int2x2& lhs, const int32_t rhs )
{
	return ( lhs = lhs + rhs );
}

int2x2 operator+( const int2x2& lhs, const int2x2& rhs )
{
	return int2x2(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1]
	);
}

int2x2 operator+=( int2x2& lhs, const int2x2& rhs )
{
	return ( lhs = lhs + rhs );
}

int2x2 operator-( const int2x2& lhs, const int32_t rhs )
{
	return int2x2(
		lhs[0] - rhs,
		lhs[1] - rhs
	);
}

int2x2 operator-=( int2x2& lhs, const int32_t rhs )
{
	return ( lhs = lhs - rhs );
}

int2x2 operator-( const int2x2& lhs, const int2x2& rhs )
{
	return int2x2(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1]
	);
}

int2x2 operator-=( int2x2& lhs, const int2x2& rhs )
{
	return ( lhs = lhs - rhs );
}

int2x2 operator*( const int2x2& lhs, const int32_t rhs )
{
	return int2x2(
		lhs[0] * rhs,
		lhs[1] * rhs
	);
}

int2x2 operator*=( int2x2& lhs, const int32_t rhs )
{
	return ( lhs = lhs * rhs );
}

int2x2 operator*( const int2x2& lhs, const int2x2& rhs )
{
	int2 row0 = lhs[0];
	int2 row1 = lhs[1];

	int2 col0 = { rhs[0].x, rhs[1].x };
	int2 col1 = { rhs[0].y, rhs[1].y };

	return int2x2(
		row0.x * col0.x + row0.y * col0.y,
		row0.x * col1.x + row0.y * col1.y,

		row1.x * col0.x + row1.y * col0.y,
		row1.x * col1.x + row1.y * col1.y
	);
}

int2x2 operator*=( int2x2& lhs, const int2x2& rhs )
{
	return ( lhs = lhs * rhs );
}

int2x2 operator/( const int2x2& lhs, const int32_t rhs )
{
	return int2x2(
		lhs[0] / rhs,
		lhs[1] / rhs
	);
}

int2x2 operator/=( int2x2& lhs, const int32_t rhs )
{
	return ( lhs = lhs / rhs );
}

int2x2 operator/( const int2x2& lhs, const int2x2& rhs )
{
	return int2x2(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1]
	);
}

int2x2 operator/=( int2x2& lhs, const int2x2& rhs )
{
	return ( lhs = lhs / rhs );
}

int2 operator*( const int2x2& lhs, const int2& rhs )
{
	return int2(
		(int32_t) dot( lhs[0], rhs ),
		(int32_t) dot( lhs[1], rhs )
	);
}

int2 operator*=( int2& lhs, const int2x2& rhs )
{
	return ( lhs = rhs * lhs );
}

// prefix
int2x2& operator++( int2x2& lhs )
{
	++lhs[0];
	++lhs[1];
	return lhs;
}

// postfix
int2x2& operator++( int2x2& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	return lhs;
}

// prefix
int2x2& operator--( int2x2& lhs )
{
	--lhs[0];
	--lhs[1];
	return lhs;
}

// postfix
int2x2& operator--( int2x2& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	return lhs;
}

bool2x2 operator<( const int2x2& lhs, const int2x2& rhs )
{
	return bool2x2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2x2 operator<=( const int2x2& lhs, const int2x2& rhs )
{
	return bool2x2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2x2 operator>( const int2x2& lhs, const int2x2& rhs )
{
	return bool2x2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2x2 operator>=( const int2x2& lhs, const int2x2& rhs )
{
	return bool2x2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}

int2x2 operator&( const int2x2& lhs, const int32_t& rhs )
{
	return int2x2(
		lhs[0] & rhs,
		lhs[1] & rhs
	);
}

int2x2 operator&=( int2x2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

int2x2 operator&( const int2x2& lhs, const int2x2& rhs )
{
	return int2x2(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1]
	);
}

int2x2 operator&=( int2x2& lhs, const int2x2& rhs )
{
	return ( lhs = lhs & rhs );
}

int2x2 operator|( const int2x2& lhs, const int32_t& rhs )
{
	return int2x2(
		lhs[0] | rhs,
		lhs[1] | rhs
	);
}

int2x2 operator|=( int2x2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

int2x2 operator|( const int2x2& lhs, const int2x2& rhs )
{
	return int2x2(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1]
	);
}

int2x2 operator|=( int2x2& lhs, const int2x2& rhs )
{
	return ( lhs = lhs | rhs );
}

int2x2 operator^( const int2x2& lhs, const int32_t& rhs )
{
	return int2x2(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs
	);
}

int2x2 operator^=( int2x2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int2x2 operator^( const int2x2& lhs, const int2x2& rhs )
{
	return int2x2(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1]
	);
}

int2x2 operator^=( int2x2& lhs, const int2x2& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int2x2 operator<<( const int2x2& lhs, const int32_t& rhs )
{
	return int2x2(
		lhs[0] << rhs,
		lhs[1] << rhs
	);
}

int2x2 operator<<=( int2x2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

int2x2 operator<<( const int2x2& lhs, const int2x2& rhs )
{
	return int2x2(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1]
	);
}

int2x2 operator<<=( int2x2& lhs, const int2x2& rhs )
{
	return ( lhs = lhs << rhs );
}

int2x2 operator>>( const int2x2& lhs, const int32_t& rhs )
{
	return int2x2(
		lhs[0] >> rhs,
		lhs[1] >> rhs
	);
}

int2x2 operator>>=( int2x2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

int2x2 operator>>( const int2x2& lhs, const int2x2& rhs )
{
	return int2x2(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1]
	);
}

int2x2 operator>>=( int2x2& lhs, const int2x2& rhs )
{
	return ( lhs = lhs >> rhs );
}

int2x2 operator~( const int2x2& lhs )
{
	return int2x2(
		~lhs[0],
		~lhs[1]
	);
}


// int2x3
int2x3 operator+( const int2x3& lhs, const int32_t rhs )
{
	return int2x3(
		lhs[0] + rhs,
		lhs[1] + rhs
	);
}

int2x3 operator+=( int2x3& lhs, const int32_t rhs )
{
	return ( lhs = lhs + rhs );
}

int2x3 operator+( const int2x3& lhs, const int2x3& rhs )
{
	return int2x3(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1]
	);
}

int2x3 operator+=( int2x3& lhs, const int2x3& rhs )
{
	return ( lhs = lhs + rhs );
}

int2x3 operator-( const int2x3& lhs, const int32_t rhs )
{
	return int2x3(
		lhs[0] - rhs,
		lhs[1] - rhs
	);
}

int2x3 operator-=( int2x3& lhs, const int32_t rhs )
{
	return ( lhs = lhs - rhs );
}

int2x3 operator-( const int2x3& lhs, const int2x3& rhs )
{
	return int2x3(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1]
	);
}

int2x3 operator-=( int2x3& lhs, const int2x3& rhs )
{
	return ( lhs = lhs - rhs );
}

int2x3 operator*( const int2x3& lhs, const int32_t rhs )
{
	return int2x3(
		lhs[0] * rhs,
		lhs[1] * rhs
	);
}

int2x3 operator*=( int2x3& lhs, const int32_t rhs )
{
	return ( lhs = lhs * rhs );
}

int2x2 operator*( const int2x3& lhs, const int3x2& rhs )
{
	int3 row0 = lhs[0];
	int3 row1 = lhs[1];

	int3 col0 = { rhs[0].x, rhs[1].x, rhs[2].x };
	int3 col1 = { rhs[0].y, rhs[1].y, rhs[2].y };

	return int2x2(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z
	);
}

int2x3 operator/( const int2x3& lhs, const int32_t rhs )
{
	return int2x3(
		lhs[0] / rhs,
		lhs[1] / rhs
	);
}

int2x3 operator/=( int2x3& lhs, const int32_t rhs )
{
	return ( lhs = lhs / rhs );
}

int2x3 operator/( const int2x3& lhs, const int2x3& rhs )
{
	return int2x3(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1]
	);
}

// prefix
int2x3& operator++( int2x3& lhs )
{
	++lhs[0];
	++lhs[1];
	return lhs;
}

// postfix
int2x3& operator++( int2x3& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	return lhs;
}

// prefix
int2x3& operator--( int2x3& lhs )
{
	--lhs[0];
	--lhs[1];
	return lhs;
}

// postfix
int2x3& operator--( int2x3& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	return lhs;
}

bool2x3 operator<( const int2x3& lhs, const int2x3& rhs )
{
	return bool2x3(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2x3 operator<=( const int2x3& lhs, const int2x3& rhs )
{
	return bool2x3(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2x3 operator>( const int2x3& lhs, const int2x3& rhs )
{
	return bool2x3(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2x3 operator>=( const int2x3& lhs, const int2x3& rhs )
{
	return bool2x3(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}

int2x3 operator&( const int2x3& lhs, const int32_t& rhs )
{
	return int2x3(
		lhs[0] & rhs,
		lhs[1] & rhs
	);
}

int2x3 operator&=( int2x3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

int2x3 operator&( const int2x3& lhs, const int2x3& rhs )
{
	return int2x3(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1]
	);
}

int2x3 operator&=( int2x3& lhs, const int2x3& rhs )
{
	return ( lhs = lhs & rhs );
}

int2x3 operator|( const int2x3& lhs, const int32_t& rhs )
{
	return int2x3(
		lhs[0] | rhs,
		lhs[1] | rhs
	);
}

int2x3 operator|=( int2x3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

int2x3 operator|( const int2x3& lhs, const int2x3& rhs )
{
	return int2x3(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1]
	);
}

int2x3 operator|=( int2x3& lhs, const int2x3& rhs )
{
	return ( lhs = lhs | rhs );
}

int2x3 operator^( const int2x3& lhs, const int32_t& rhs )
{
	return int2x3(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs
	);
}

int2x3 operator^=( int2x3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int2x3 operator^( const int2x3& lhs, const int2x3& rhs )
{
	return int2x3(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1]
	);
}

int2x3 operator^=( int2x3& lhs, const int2x3& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int2x3 operator<<( const int2x3& lhs, const int32_t& rhs )
{
	return int2x3(
		lhs[0] << rhs,
		lhs[1] << rhs
	);
}

int2x3 operator<<=( int2x3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

int2x3 operator<<( const int2x3& lhs, const int2x3& rhs )
{
	return int2x3(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1]
	);
}

int2x3 operator<<=( int2x3& lhs, const int2x3& rhs )
{
	return ( lhs = lhs << rhs );
}

int2x3 operator>>( const int2x3& lhs, const int32_t& rhs )
{
	return int2x3(
		lhs[0] >> rhs,
		lhs[1] >> rhs
	);
}

int2x3 operator>>=( int2x3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

int2x3 operator>>( const int2x3& lhs, const int2x3& rhs )
{
	return int2x3(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1]
	);
}

int2x3 operator>>=( int2x3& lhs, const int2x3& rhs )
{
	return ( lhs = lhs >> rhs );
}

int2x3 operator~( const int2x3& lhs )
{
	return int2x3(
		~lhs[0],
		~lhs[1]
	);
}


// int2x4
int2x4 operator+( const int2x4& lhs, const int32_t rhs )
{
	return int2x4(
		lhs[0] + rhs,
		lhs[1] + rhs
	);
}

int2x4 operator+=( int2x4& lhs, const int32_t rhs )
{
	return ( lhs = lhs + rhs );
}

int2x4 operator+( const int2x4& lhs, const int2x4& rhs )
{
	return int2x4(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1]
	);
}

int2x4 operator+=( int2x4& lhs, const int2x4& rhs )
{
	return ( lhs = lhs + rhs );
}

int2x4 operator-( const int2x4& lhs, const int32_t rhs )
{
	return int2x4(
		lhs[0] - rhs,
		lhs[1] - rhs
	);
}

int2x4 operator-=( int2x4& lhs, const int32_t rhs )
{
	return ( lhs = lhs - rhs );
}

int2x4 operator-( const int2x4& lhs, const int2x4& rhs )
{
	return int2x4(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1]
	);
}

int2x4 operator-=( int2x4& lhs, const int2x4& rhs )
{
	return ( lhs = lhs - rhs );
}

int2x4 operator*( const int2x4& lhs, const int32_t rhs )
{
	return int2x4(
		lhs[0] * rhs,
		lhs[1] * rhs
	);
}

int2x4 operator*=( int2x4& lhs, const int32_t rhs )
{
	return ( lhs = lhs * rhs );
}

int2x2 operator*( const int2x4& lhs, const int4x2& rhs )
{
	int4 row0 = lhs[0];
	int4 row1 = lhs[1];

	int4 col0 = { rhs[0].x, rhs[1].x, rhs[2].x, rhs[3].x };
	int4 col1 = { rhs[0].y, rhs[1].y, rhs[2].y, rhs[3].y };

	return int2x2(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z + row0.w * col0.w,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z + row0.w * col1.w,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z + row1.w * col0.w,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z + row1.w * col1.w
	);
}

int2x4 operator/( const int2x4& lhs, const int32_t rhs )
{
	return int2x4(
		lhs[0] / rhs,
		lhs[1] / rhs
	);
}

int2x4 operator/=( int2x4& lhs, const int32_t rhs )
{
	return ( lhs = lhs / rhs );
}

int2x4 operator/( const int2x4& lhs, const int2x4& rhs )
{
	return int2x4(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1]
	);
}

// prefix
int2x4& operator++( int2x4& lhs )
{
	++lhs[0];
	++lhs[1];
	return lhs;
}

// postfix
int2x4& operator++( int2x4& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	return lhs;
}

// prefix
int2x4& operator--( int2x4& lhs )
{
	--lhs[0];
	--lhs[1];
	return lhs;
}

// postfix
int2x4& operator--( int2x4& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	return lhs;
}

bool2x4 operator<( const int2x4& lhs, const int2x4& rhs )
{
	return bool2x4(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2x4 operator<=( const int2x4& lhs, const int2x4& rhs )
{
	return bool2x4(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2x4 operator>( const int2x4& lhs, const int2x4& rhs )
{
	return bool2x4(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2x4 operator>=( const int2x4& lhs, const int2x4& rhs )
{
	return bool2x4(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}

int2x4 operator&( const int2x4& lhs, const int32_t& rhs )
{
	return int2x4(
		lhs[0] & rhs,
		lhs[1] & rhs
	);
}

int2x4 operator&=( int2x4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

int2x4 operator&( const int2x4& lhs, const int2x4& rhs )
{
	return int2x4(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1]
	);
}

int2x4 operator&=( int2x4& lhs, const int2x4& rhs )
{
	return ( lhs = lhs & rhs );
}

int2x4 operator|( const int2x4& lhs, const int32_t& rhs )
{
	return int2x4(
		lhs[0] | rhs,
		lhs[1] | rhs
	);
}

int2x4 operator|=( int2x4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

int2x4 operator|( const int2x4& lhs, const int2x4& rhs )
{
	return int2x4(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1]
	);
}

int2x4 operator|=( int2x4& lhs, const int2x4& rhs )
{
	return ( lhs = lhs | rhs );
}

int2x4 operator^( const int2x4& lhs, const int32_t& rhs )
{
	return int2x4(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs
	);
}

int2x4 operator^=( int2x4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int2x4 operator^( const int2x4& lhs, const int2x4& rhs )
{
	return int2x4(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1]
	);
}

int2x4 operator^=( int2x4& lhs, const int2x4& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int2x4 operator<<( const int2x4& lhs, const int32_t& rhs )
{
	return int2x4(
		lhs[0] << rhs,
		lhs[1] << rhs
	);
}

int2x4 operator<<=( int2x4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

int2x4 operator<<( const int2x4& lhs, const int2x4& rhs )
{
	return int2x4(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1]
	);
}

int2x4 operator<<=( int2x4& lhs, const int2x4& rhs )
{
	return ( lhs = lhs << rhs );
}

int2x4 operator>>( const int2x4& lhs, const int32_t& rhs )
{
	return int2x4(
		lhs[0] >> rhs,
		lhs[1] >> rhs
	);
}

int2x4 operator>>=( int2x4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

int2x4 operator>>( const int2x4& lhs, const int2x4& rhs )
{
	return int2x4(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1]
	);
}

int2x4 operator>>=( int2x4& lhs, const int2x4& rhs )
{
	return ( lhs = lhs >> rhs );
}

int2x4 operator~( const int2x4& lhs )
{
	return int2x4(
		~lhs[0],
		~lhs[1]
	);
}


// int3x2
int3x2 operator+( const int3x2& lhs, const int32_t rhs )
{
	return int3x2(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs
	);
}

int3x2 operator+=( int3x2& lhs, const int32_t rhs )
{
	return ( lhs = lhs + rhs );
}

int3x2 operator+( const int3x2& lhs, const int3x2& rhs )
{
	return int3x2(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2]
	);
}

int3x2 operator+=( int3x2& lhs, const int3x2& rhs )
{
	return ( lhs = lhs + rhs );
}

int3x2 operator-( const int3x2& lhs, const int32_t rhs )
{
	return int3x2(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs
	);
}

int3x2 operator-=( int3x2& lhs, const int32_t rhs )
{
	return ( lhs = lhs - rhs );
}

int3x2 operator-( const int3x2& lhs, const int3x2& rhs )
{
	return int3x2(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2]
	);
}

int3x2 operator-=( int3x2& lhs, const int3x2& rhs )
{
	return ( lhs = lhs - rhs );
}

int3x2 operator*( const int3x2& lhs, const int32_t rhs )
{
	return int3x2(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs
	);
}

int3x2 operator*=( int3x2& lhs, const int32_t rhs )
{
	return ( lhs = lhs * rhs );
}

int3x3 operator*( const int3x2& lhs, const int2x3& rhs )
{
	int2 row0 = lhs[0];
	int2 row1 = lhs[1];
	int2 row2 = lhs[2];

	int2 col0 = { rhs[0].x, rhs[1].x };
	int2 col1 = { rhs[0].y, rhs[1].y };
	int2 col2 = { rhs[0].z, rhs[1].z };

	return int3x3(
		row0.x * col0.x + row0.y * col0.y,
		row0.x * col1.x + row0.y * col1.y,
		row0.x * col2.x + row0.y * col2.y,

		row1.x * col0.x + row1.y * col0.y,
		row1.x * col1.x + row1.y * col1.y,
		row1.x * col2.x + row1.y * col2.y,

		row2.x * col0.x + row2.y * col0.y,
		row2.x * col1.x + row2.y * col1.y,
		row2.x * col2.x + row2.y * col2.y
	);
}

int3x2 operator/( const int3x2& lhs, const int32_t rhs )
{
	return int3x2(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs
	);
}

int3x2 operator/=( int3x2& lhs, const int32_t rhs )
{
	return ( lhs = lhs / rhs );
}

int3x2 operator/( const int3x2& lhs, const int3x2& rhs )
{
	return int3x2(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2]
	);
}

// prefix
int3x2& operator++( int3x2& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	return lhs;
}

// postfix
int3x2& operator++( int3x2& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	return lhs;
}

// prefix
int3x2& operator--( int3x2& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	return lhs;
}

// postfix
int3x2& operator--( int3x2& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	return lhs;
}

bool3x2 operator<( const int3x2& lhs, const int3x2& rhs )
{
	return bool3x2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2]
	);
}

bool3x2 operator<=( const int3x2& lhs, const int3x2& rhs )
{
	return bool3x2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2]
	);
}

bool3x2 operator>( const int3x2& lhs, const int3x2& rhs )
{
	return bool3x2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2]
	);
}

bool3x2 operator>=( const int3x2& lhs, const int3x2& rhs )
{
	return bool3x2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2]
	);
}

int3x2 operator&( const int3x2& lhs, const int32_t& rhs )
{
	return int3x2(
		lhs[0] & rhs,
		lhs[1] & rhs,
		lhs[2] & rhs
	);
}

int3x2 operator&=( int3x2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

int3x2 operator&( const int3x2& lhs, const int3x2& rhs )
{
	return int3x2(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1],
		lhs[2] & rhs[2]
	);
}

int3x2 operator&=( int3x2& lhs, const int3x2& rhs )
{
	return ( lhs = lhs & rhs );
}

int3x2 operator|( const int3x2& lhs, const int32_t& rhs )
{
	return int3x2(
		lhs[0] | rhs,
		lhs[1] | rhs,
		lhs[2] | rhs
	);
}

int3x2 operator|=( int3x2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

int3x2 operator|( const int3x2& lhs, const int3x2& rhs )
{
	return int3x2(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1],
		lhs[2] | rhs[2]
	);
}

int3x2 operator|=( int3x2& lhs, const int3x2& rhs )
{
	return ( lhs = lhs | rhs );
}

int3x2 operator^( const int3x2& lhs, const int32_t& rhs )
{
	return int3x2(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs,
		lhs[2] ^ rhs
	);
}

int3x2 operator^=( int3x2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int3x2 operator^( const int3x2& lhs, const int3x2& rhs )
{
	return int3x2(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1],
		lhs[2] ^ rhs[2]
	);
}

int3x2 operator^=( int3x2& lhs, const int3x2& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int3x2 operator<<( const int3x2& lhs, const int32_t& rhs )
{
	return int3x2(
		lhs[0] << rhs,
		lhs[1] << rhs,
		lhs[2] << rhs
	);
}

int3x2 operator<<=( int3x2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

int3x2 operator<<( const int3x2& lhs, const int3x2& rhs )
{
	return int3x2(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1],
		lhs[2] << rhs[2]
	);
}

int3x2 operator<<=( int3x2& lhs, const int3x2& rhs )
{
	return ( lhs = lhs << rhs );
}

int3x2 operator>>( const int3x2& lhs, const int32_t& rhs )
{
	return int3x2(
		lhs[0] >> rhs,
		lhs[1] >> rhs,
		lhs[2] >> rhs
	);
}

int3x2 operator>>=( int3x2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

int3x2 operator>>( const int3x2& lhs, const int3x2& rhs )
{
	return int3x2(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1],
		lhs[2] >> rhs[2]
	);
}

int3x2 operator>>=( int3x2& lhs, const int3x2& rhs )
{
	return ( lhs = lhs >> rhs );
}

int3x2 operator~( const int3x2& lhs )
{
	return int3x2(
		~lhs[0],
		~lhs[1],
		~lhs[2]
	);
}


// int3x3
int3x3 operator+( const int3x3& lhs, const int32_t rhs )
{
	return int3x3(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs
	);
}

int3x3 operator+=( int3x3& lhs, const int32_t rhs )
{
	return ( lhs = lhs + rhs );
}

int3x3 operator+( const int3x3& lhs, const int3x3& rhs )
{
	return int3x3(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2]
	);
}

int3x3 operator+=( int3x3& lhs, const int3x3& rhs )
{
	return ( lhs = lhs + rhs );
}

int3x3 operator-( const int3x3& lhs, const int32_t rhs )
{
	return int3x3(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs
	);
}

int3x3 operator-=( int3x3& lhs, const int32_t rhs )
{
	return ( lhs = lhs - rhs );
}

int3x3 operator-( const int3x3& lhs, const int3x3& rhs )
{
	return int3x3(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2]
	);
}

int3x3 operator-=( int3x3& lhs, const int3x3& rhs )
{
	return ( lhs = lhs - rhs );
}

int3x3 operator*( const int3x3& lhs, const int32_t rhs )
{
	return int3x3(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs
	);
}

int3x3 operator*=( int3x3& lhs, const int32_t rhs )
{
	return ( lhs = lhs * rhs );
}

int3x3 operator*( const int3x3& lhs, const int3x3& rhs )
{
	int3 row0 = lhs[0];
	int3 row1 = lhs[1];
	int3 row2 = lhs[2];

	int3 col0 = { rhs[0].x, rhs[1].x, rhs[2].x };
	int3 col1 = { rhs[0].y, rhs[1].y, rhs[2].y };
	int3 col2 = { rhs[0].z, rhs[1].z, rhs[2].z };

	return int3x3(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z
	);
}

int3x3 operator*=( int3x3& lhs, const int3x3& rhs )
{
	return ( lhs = lhs * rhs );
}

int3x3 operator/( const int3x3& lhs, const int32_t rhs )
{
	return int3x3(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs
	);
}

int3x3 operator/=( int3x3& lhs, const int32_t rhs )
{
	return ( lhs = lhs / rhs );
}

int3x3 operator/( const int3x3& lhs, const int3x3& rhs )
{
	return int3x3(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2]
	);
}

int3x3 operator/=( int3x3& lhs, const int3x3& rhs )
{
	return ( lhs = lhs / rhs );
}

int3 operator*( const int3x3& lhs, const int3& rhs )
{
	return int3(
		(int32_t) dot( lhs[0], rhs ),
		(int32_t) dot( lhs[1], rhs ),
		(int32_t) dot( lhs[2], rhs )
	);
}

int3 operator*=( int3& lhs, const int3x3& rhs )
{
	return ( lhs = rhs * lhs );
}

// prefix
int3x3& operator++( int3x3& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	return lhs;
}

// postfix
int3x3& operator++( int3x3& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	return lhs;
}

// prefix
int3x3& operator--( int3x3& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	return lhs;
}

// postfix
int3x3& operator--( int3x3& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	return lhs;
}

bool3x3 operator<( const int3x3& lhs, const int3x3& rhs )
{
	return bool3x3(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2]
	);
}

bool3x3 operator<=( const int3x3& lhs, const int3x3& rhs )
{
	return bool3x3(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2]
	);
}

bool3x3 operator>( const int3x3& lhs, const int3x3& rhs )
{
	return bool3x3(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2]
	);
}

bool3x3 operator>=( const int3x3& lhs, const int3x3& rhs )
{
	return bool3x3(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2]
	);
}

int3x3 operator&( const int3x3& lhs, const int32_t& rhs )
{
	return int3x3(
		lhs[0] & rhs,
		lhs[1] & rhs,
		lhs[2] & rhs
	);
}

int3x3 operator&=( int3x3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

int3x3 operator&( const int3x3& lhs, const int3x3& rhs )
{
	return int3x3(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1],
		lhs[2] & rhs[2]
	);
}

int3x3 operator&=( int3x3& lhs, const int3x3& rhs )
{
	return ( lhs = lhs & rhs );
}

int3x3 operator|( const int3x3& lhs, const int32_t& rhs )
{
	return int3x3(
		lhs[0] | rhs,
		lhs[1] | rhs,
		lhs[2] | rhs
	);
}

int3x3 operator|=( int3x3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

int3x3 operator|( const int3x3& lhs, const int3x3& rhs )
{
	return int3x3(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1],
		lhs[2] | rhs[2]
	);
}

int3x3 operator|=( int3x3& lhs, const int3x3& rhs )
{
	return ( lhs = lhs | rhs );
}

int3x3 operator^( const int3x3& lhs, const int32_t& rhs )
{
	return int3x3(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs,
		lhs[2] ^ rhs
	);
}

int3x3 operator^=( int3x3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int3x3 operator^( const int3x3& lhs, const int3x3& rhs )
{
	return int3x3(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1],
		lhs[2] ^ rhs[2]
	);
}

int3x3 operator^=( int3x3& lhs, const int3x3& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int3x3 operator<<( const int3x3& lhs, const int32_t& rhs )
{
	return int3x3(
		lhs[0] << rhs,
		lhs[1] << rhs,
		lhs[2] << rhs
	);
}

int3x3 operator<<=( int3x3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

int3x3 operator<<( const int3x3& lhs, const int3x3& rhs )
{
	return int3x3(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1],
		lhs[2] << rhs[2]
	);
}

int3x3 operator<<=( int3x3& lhs, const int3x3& rhs )
{
	return ( lhs = lhs << rhs );
}

int3x3 operator>>( const int3x3& lhs, const int32_t& rhs )
{
	return int3x3(
		lhs[0] >> rhs,
		lhs[1] >> rhs,
		lhs[2] >> rhs
	);
}

int3x3 operator>>=( int3x3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

int3x3 operator>>( const int3x3& lhs, const int3x3& rhs )
{
	return int3x3(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1],
		lhs[2] >> rhs[2]
	);
}

int3x3 operator>>=( int3x3& lhs, const int3x3& rhs )
{
	return ( lhs = lhs >> rhs );
}

int3x3 operator~( const int3x3& lhs )
{
	return int3x3(
		~lhs[0],
		~lhs[1],
		~lhs[2]
	);
}


// int3x4
int3x4 operator+( const int3x4& lhs, const int32_t rhs )
{
	return int3x4(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs
	);
}

int3x4 operator+=( int3x4& lhs, const int32_t rhs )
{
	return ( lhs = lhs + rhs );
}

int3x4 operator+( const int3x4& lhs, const int3x4& rhs )
{
	return int3x4(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2]
	);
}

int3x4 operator+=( int3x4& lhs, const int3x4& rhs )
{
	return ( lhs = lhs + rhs );
}

int3x4 operator-( const int3x4& lhs, const int32_t rhs )
{
	return int3x4(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs
	);
}

int3x4 operator-=( int3x4& lhs, const int32_t rhs )
{
	return ( lhs = lhs - rhs );
}

int3x4 operator-( const int3x4& lhs, const int3x4& rhs )
{
	return int3x4(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2]
	);
}

int3x4 operator-=( int3x4& lhs, const int3x4& rhs )
{
	return ( lhs = lhs - rhs );
}

int3x4 operator*( const int3x4& lhs, const int32_t rhs )
{
	return int3x4(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs
	);
}

int3x4 operator*=( int3x4& lhs, const int32_t rhs )
{
	return ( lhs = lhs * rhs );
}

int3x3 operator*( const int3x4& lhs, const int4x3& rhs )
{
	int4 row0 = lhs[0];
	int4 row1 = lhs[1];
	int4 row2 = lhs[2];

	int4 col0 = { rhs[0].x, rhs[1].x, rhs[2].x, rhs[3].x };
	int4 col1 = { rhs[0].y, rhs[1].y, rhs[2].y, rhs[3].y };
	int4 col2 = { rhs[0].z, rhs[1].z, rhs[2].z, rhs[3].z };

	return int3x3(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z + row0.w * col0.w,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z + row0.w * col1.w,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z + row0.w * col2.w,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z + row1.w * col0.w,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z + row1.w * col1.w,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z + row1.w * col2.w,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z + row2.w * col0.w,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z + row2.w * col1.w,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z + row2.w * col2.w
	);
}

int3x4 operator/( const int3x4& lhs, const int32_t rhs )
{
	return int3x4(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs
	);
}

int3x4 operator/=( int3x4& lhs, const int32_t rhs )
{
	return ( lhs = lhs / rhs );
}

int3x4 operator/( const int3x4& lhs, const int3x4& rhs )
{
	return int3x4(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2]
	);
}

// prefix
int3x4& operator++( int3x4& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	return lhs;
}

// postfix
int3x4& operator++( int3x4& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	return lhs;
}

// prefix
int3x4& operator--( int3x4& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	return lhs;
}

// postfix
int3x4& operator--( int3x4& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	return lhs;
}

bool3x4 operator<( const int3x4& lhs, const int3x4& rhs )
{
	return bool3x4(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2]
	);
}

bool3x4 operator<=( const int3x4& lhs, const int3x4& rhs )
{
	return bool3x4(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2]
	);
}

bool3x4 operator>( const int3x4& lhs, const int3x4& rhs )
{
	return bool3x4(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2]
	);
}

bool3x4 operator>=( const int3x4& lhs, const int3x4& rhs )
{
	return bool3x4(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2]
	);
}

int3x4 operator&( const int3x4& lhs, const int32_t& rhs )
{
	return int3x4(
		lhs[0] & rhs,
		lhs[1] & rhs,
		lhs[2] & rhs
	);
}

int3x4 operator&=( int3x4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

int3x4 operator&( const int3x4& lhs, const int3x4& rhs )
{
	return int3x4(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1],
		lhs[2] & rhs[2]
	);
}

int3x4 operator&=( int3x4& lhs, const int3x4& rhs )
{
	return ( lhs = lhs & rhs );
}

int3x4 operator|( const int3x4& lhs, const int32_t& rhs )
{
	return int3x4(
		lhs[0] | rhs,
		lhs[1] | rhs,
		lhs[2] | rhs
	);
}

int3x4 operator|=( int3x4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

int3x4 operator|( const int3x4& lhs, const int3x4& rhs )
{
	return int3x4(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1],
		lhs[2] | rhs[2]
	);
}

int3x4 operator|=( int3x4& lhs, const int3x4& rhs )
{
	return ( lhs = lhs | rhs );
}

int3x4 operator^( const int3x4& lhs, const int32_t& rhs )
{
	return int3x4(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs,
		lhs[2] ^ rhs
	);
}

int3x4 operator^=( int3x4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int3x4 operator^( const int3x4& lhs, const int3x4& rhs )
{
	return int3x4(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1],
		lhs[2] ^ rhs[2]
	);
}

int3x4 operator^=( int3x4& lhs, const int3x4& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int3x4 operator<<( const int3x4& lhs, const int32_t& rhs )
{
	return int3x4(
		lhs[0] << rhs,
		lhs[1] << rhs,
		lhs[2] << rhs
	);
}

int3x4 operator<<=( int3x4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

int3x4 operator<<( const int3x4& lhs, const int3x4& rhs )
{
	return int3x4(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1],
		lhs[2] << rhs[2]
	);
}

int3x4 operator<<=( int3x4& lhs, const int3x4& rhs )
{
	return ( lhs = lhs << rhs );
}

int3x4 operator>>( const int3x4& lhs, const int32_t& rhs )
{
	return int3x4(
		lhs[0] >> rhs,
		lhs[1] >> rhs,
		lhs[2] >> rhs
	);
}

int3x4 operator>>=( int3x4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

int3x4 operator>>( const int3x4& lhs, const int3x4& rhs )
{
	return int3x4(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1],
		lhs[2] >> rhs[2]
	);
}

int3x4 operator>>=( int3x4& lhs, const int3x4& rhs )
{
	return ( lhs = lhs >> rhs );
}

int3x4 operator~( const int3x4& lhs )
{
	return int3x4(
		~lhs[0],
		~lhs[1],
		~lhs[2]
	);
}


// int4x2
int4x2 operator+( const int4x2& lhs, const int32_t rhs )
{
	return int4x2(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs,
		lhs[3] + rhs
	);
}

int4x2 operator+=( int4x2& lhs, const int32_t rhs )
{
	return ( lhs = lhs + rhs );
}

int4x2 operator+( const int4x2& lhs, const int4x2& rhs )
{
	return int4x2(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2],
		lhs[3] + rhs[3]
	);
}

int4x2 operator+=( int4x2& lhs, const int4x2& rhs )
{
	return ( lhs = lhs + rhs );
}

int4x2 operator-( const int4x2& lhs, const int32_t rhs )
{
	return int4x2(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs,
		lhs[3] - rhs
	);
}

int4x2 operator-=( int4x2& lhs, const int32_t rhs )
{
	return ( lhs = lhs - rhs );
}

int4x2 operator-( const int4x2& lhs, const int4x2& rhs )
{
	return int4x2(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2],
		lhs[3] - rhs[3]
	);
}

int4x2 operator-=( int4x2& lhs, const int4x2& rhs )
{
	return ( lhs = lhs - rhs );
}

int4x2 operator*( const int4x2& lhs, const int32_t rhs )
{
	return int4x2(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs,
		lhs[3] * rhs
	);
}

int4x2 operator*=( int4x2& lhs, const int32_t rhs )
{
	return ( lhs = lhs * rhs );
}

int4x4 operator*( const int4x2& lhs, const int2x4& rhs )
{
	int2 row0 = lhs[0];
	int2 row1 = lhs[1];
	int2 row2 = lhs[2];
	int2 row3 = lhs[3];

	int2 col0 = { rhs[0].x, rhs[1].x };
	int2 col1 = { rhs[0].y, rhs[1].y };
	int2 col2 = { rhs[0].z, rhs[1].z };
	int2 col3 = { rhs[0].w, rhs[1].w };

	return int4x4(
		row0.x * col0.x + row0.y * col0.y,
		row0.x * col1.x + row0.y * col1.y,
		row0.x * col2.x + row0.y * col2.y,
		row0.x * col3.x + row0.y * col3.y,

		row1.x * col0.x + row1.y * col0.y,
		row1.x * col1.x + row1.y * col1.y,
		row1.x * col2.x + row1.y * col2.y,
		row1.x * col3.x + row1.y * col3.y,

		row2.x * col0.x + row2.y * col0.y,
		row2.x * col1.x + row2.y * col1.y,
		row2.x * col2.x + row2.y * col2.y,
		row2.x * col3.x + row2.y * col3.y,

		row3.x * col0.x + row3.y * col0.y,
		row3.x * col1.x + row3.y * col1.y,
		row3.x * col2.x + row3.y * col2.y,
		row3.x * col3.x + row3.y * col3.y
	);
}

int4x2 operator/( const int4x2& lhs, const int32_t rhs )
{
	return int4x2(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs,
		lhs[3] / rhs
	);
}

int4x2 operator/=( int4x2& lhs, const int32_t rhs )
{
	return ( lhs = lhs / rhs );
}

int4x2 operator/( const int4x2& lhs, const int4x2& rhs )
{
	return int4x2(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2],
		lhs[3] / rhs[3]
	);
}

// prefix
int4x2& operator++( int4x2& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	++lhs[3];
	return lhs;
}

// postfix
int4x2& operator++( int4x2& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	lhs[3]++;
	return lhs;
}

// prefix
int4x2& operator--( int4x2& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	--lhs[3];
	return lhs;
}

// postfix
int4x2& operator--( int4x2& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	lhs[3]--;
	return lhs;
}

bool4x2 operator<( const int4x2& lhs, const int4x2& rhs )
{
	return bool4x2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2],
		lhs[3] < rhs[3]
	);
}

bool4x2 operator<=( const int4x2& lhs, const int4x2& rhs )
{
	return bool4x2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2],
		lhs[3] <= rhs[3]
	);
}

bool4x2 operator>( const int4x2& lhs, const int4x2& rhs )
{
	return bool4x2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2],
		lhs[3] > rhs[3]
	);
}

bool4x2 operator>=( const int4x2& lhs, const int4x2& rhs )
{
	return bool4x2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2],
		lhs[3] >= rhs[3]
	);
}

int4x2 operator&( const int4x2& lhs, const int32_t& rhs )
{
	return int4x2(
		lhs[0] & rhs,
		lhs[1] & rhs,
		lhs[2] & rhs,
		lhs[3] & rhs
	);
}

int4x2 operator&=( int4x2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

int4x2 operator&( const int4x2& lhs, const int4x2& rhs )
{
	return int4x2(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1],
		lhs[2] & rhs[2],
		lhs[3] & rhs[3]
	);
}

int4x2 operator&=( int4x2& lhs, const int4x2& rhs )
{
	return ( lhs = lhs & rhs );
}

int4x2 operator|( const int4x2& lhs, const int32_t& rhs )
{
	return int4x2(
		lhs[0] | rhs,
		lhs[1] | rhs,
		lhs[2] | rhs,
		lhs[3] | rhs
	);
}

int4x2 operator|=( int4x2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

int4x2 operator|( const int4x2& lhs, const int4x2& rhs )
{
	return int4x2(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1],
		lhs[2] | rhs[2],
		lhs[3] | rhs[3]
	);
}

int4x2 operator|=( int4x2& lhs, const int4x2& rhs )
{
	return ( lhs = lhs | rhs );
}

int4x2 operator^( const int4x2& lhs, const int32_t& rhs )
{
	return int4x2(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs,
		lhs[2] ^ rhs,
		lhs[3] ^ rhs
	);
}

int4x2 operator^=( int4x2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int4x2 operator^( const int4x2& lhs, const int4x2& rhs )
{
	return int4x2(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1],
		lhs[2] ^ rhs[2],
		lhs[3] ^ rhs[3]
	);
}

int4x2 operator^=( int4x2& lhs, const int4x2& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int4x2 operator<<( const int4x2& lhs, const int32_t& rhs )
{
	return int4x2(
		lhs[0] << rhs,
		lhs[1] << rhs,
		lhs[2] << rhs,
		lhs[3] << rhs
	);
}

int4x2 operator<<=( int4x2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

int4x2 operator<<( const int4x2& lhs, const int4x2& rhs )
{
	return int4x2(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1],
		lhs[2] << rhs[2],
		lhs[3] << rhs[3]
	);
}

int4x2 operator<<=( int4x2& lhs, const int4x2& rhs )
{
	return ( lhs = lhs << rhs );
}

int4x2 operator>>( const int4x2& lhs, const int32_t& rhs )
{
	return int4x2(
		lhs[0] >> rhs,
		lhs[1] >> rhs,
		lhs[2] >> rhs,
		lhs[3] >> rhs
	);
}

int4x2 operator>>=( int4x2& lhs, const int32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

int4x2 operator>>( const int4x2& lhs, const int4x2& rhs )
{
	return int4x2(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1],
		lhs[2] >> rhs[2],
		lhs[3] >> rhs[3]
	);
}

int4x2 operator>>=( int4x2& lhs, const int4x2& rhs )
{
	return ( lhs = lhs >> rhs );
}

int4x2 operator~( const int4x2& lhs )
{
	return int4x2(
		~lhs[0],
		~lhs[1],
		~lhs[2],
		~lhs[3]
	);
}


// int4x3
int4x3 operator+( const int4x3& lhs, const int32_t rhs )
{
	return int4x3(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs,
		lhs[3] + rhs
	);
}

int4x3 operator+=( int4x3& lhs, const int32_t rhs )
{
	return ( lhs = lhs + rhs );
}

int4x3 operator+( const int4x3& lhs, const int4x3& rhs )
{
	return int4x3(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2],
		lhs[3] + rhs[3]
	);
}

int4x3 operator+=( int4x3& lhs, const int4x3& rhs )
{
	return ( lhs = lhs + rhs );
}

int4x3 operator-( const int4x3& lhs, const int32_t rhs )
{
	return int4x3(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs,
		lhs[3] - rhs
	);
}

int4x3 operator-=( int4x3& lhs, const int32_t rhs )
{
	return ( lhs = lhs - rhs );
}

int4x3 operator-( const int4x3& lhs, const int4x3& rhs )
{
	return int4x3(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2],
		lhs[3] - rhs[3]
	);
}

int4x3 operator-=( int4x3& lhs, const int4x3& rhs )
{
	return ( lhs = lhs - rhs );
}

int4x3 operator*( const int4x3& lhs, const int32_t rhs )
{
	return int4x3(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs,
		lhs[3] * rhs
	);
}

int4x3 operator*=( int4x3& lhs, const int32_t rhs )
{
	return ( lhs = lhs * rhs );
}

int4x4 operator*( const int4x3& lhs, const int3x4& rhs )
{
	int3 row0 = lhs[0];
	int3 row1 = lhs[1];
	int3 row2 = lhs[2];
	int3 row3 = lhs[3];

	int3 col0 = { rhs[0].x, rhs[1].x, rhs[2].x };
	int3 col1 = { rhs[0].y, rhs[1].y, rhs[2].y };
	int3 col2 = { rhs[0].z, rhs[1].z, rhs[2].z };
	int3 col3 = { rhs[0].w, rhs[1].w, rhs[2].w };

	return int4x4(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z,
		row0.x * col3.x + row0.y * col3.y + row0.z * col3.z,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z,
		row1.x * col3.x + row1.y * col3.y + row1.z * col3.z,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z,
		row2.x * col3.x + row2.y * col3.y + row2.z * col3.z,

		row3.x * col0.x + row3.y * col0.y + row3.z * col0.z,
		row3.x * col1.x + row3.y * col1.y + row3.z * col1.z,
		row3.x * col2.x + row3.y * col2.y + row3.z * col2.z,
		row3.x * col3.x + row3.y * col3.y + row3.z * col3.z
	);
}

int4x3 operator/( const int4x3& lhs, const int32_t rhs )
{
	return int4x3(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs,
		lhs[3] / rhs
	);
}

int4x3 operator/=( int4x3& lhs, const int32_t rhs )
{
	return ( lhs = lhs / rhs );
}

int4x3 operator/( const int4x3& lhs, const int4x3& rhs )
{
	return int4x3(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2],
		lhs[3] / rhs[3]
	);
}

// prefix
int4x3& operator++( int4x3& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	++lhs[3];
	return lhs;
}

// postfix
int4x3& operator++( int4x3& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	lhs[3]++;
	return lhs;
}

// prefix
int4x3& operator--( int4x3& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	--lhs[3];
	return lhs;
}

// postfix
int4x3& operator--( int4x3& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	lhs[3]--;
	return lhs;
}

bool4x3 operator<( const int4x3& lhs, const int4x3& rhs )
{
	return bool4x3(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2],
		lhs[3] < rhs[3]
	);
}

bool4x3 operator<=( const int4x3& lhs, const int4x3& rhs )
{
	return bool4x3(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2],
		lhs[3] <= rhs[3]
	);
}

bool4x3 operator>( const int4x3& lhs, const int4x3& rhs )
{
	return bool4x3(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2],
		lhs[3] > rhs[3]
	);
}

bool4x3 operator>=( const int4x3& lhs, const int4x3& rhs )
{
	return bool4x3(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2],
		lhs[3] >= rhs[3]
	);
}

int4x3 operator&( const int4x3& lhs, const int32_t& rhs )
{
	return int4x3(
		lhs[0] & rhs,
		lhs[1] & rhs,
		lhs[2] & rhs,
		lhs[3] & rhs
	);
}

int4x3 operator&=( int4x3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

int4x3 operator&( const int4x3& lhs, const int4x3& rhs )
{
	return int4x3(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1],
		lhs[2] & rhs[2],
		lhs[3] & rhs[3]
	);
}

int4x3 operator&=( int4x3& lhs, const int4x3& rhs )
{
	return ( lhs = lhs & rhs );
}

int4x3 operator|( const int4x3& lhs, const int32_t& rhs )
{
	return int4x3(
		lhs[0] | rhs,
		lhs[1] | rhs,
		lhs[2] | rhs,
		lhs[3] | rhs
	);
}

int4x3 operator|=( int4x3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

int4x3 operator|( const int4x3& lhs, const int4x3& rhs )
{
	return int4x3(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1],
		lhs[2] | rhs[2],
		lhs[3] | rhs[3]
	);
}

int4x3 operator|=( int4x3& lhs, const int4x3& rhs )
{
	return ( lhs = lhs | rhs );
}

int4x3 operator^( const int4x3& lhs, const int32_t& rhs )
{
	return int4x3(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs,
		lhs[2] ^ rhs,
		lhs[3] ^ rhs
	);
}

int4x3 operator^=( int4x3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int4x3 operator^( const int4x3& lhs, const int4x3& rhs )
{
	return int4x3(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1],
		lhs[2] ^ rhs[2],
		lhs[3] ^ rhs[3]
	);
}

int4x3 operator^=( int4x3& lhs, const int4x3& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int4x3 operator<<( const int4x3& lhs, const int32_t& rhs )
{
	return int4x3(
		lhs[0] << rhs,
		lhs[1] << rhs,
		lhs[2] << rhs,
		lhs[3] << rhs
	);
}

int4x3 operator<<=( int4x3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

int4x3 operator<<( const int4x3& lhs, const int4x3& rhs )
{
	return int4x3(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1],
		lhs[2] << rhs[2],
		lhs[3] << rhs[3]
	);
}

int4x3 operator<<=( int4x3& lhs, const int4x3& rhs )
{
	return ( lhs = lhs << rhs );
}

int4x3 operator>>( const int4x3& lhs, const int32_t& rhs )
{
	return int4x3(
		lhs[0] >> rhs,
		lhs[1] >> rhs,
		lhs[2] >> rhs,
		lhs[3] >> rhs
	);
}

int4x3 operator>>=( int4x3& lhs, const int32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

int4x3 operator>>( const int4x3& lhs, const int4x3& rhs )
{
	return int4x3(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1],
		lhs[2] >> rhs[2],
		lhs[3] >> rhs[3]
	);
}

int4x3 operator>>=( int4x3& lhs, const int4x3& rhs )
{
	return ( lhs = lhs >> rhs );
}

int4x3 operator~( const int4x3& lhs )
{
	return int4x3(
		~lhs[0],
		~lhs[1],
		~lhs[2],
		~lhs[3]
	);
}


// int4x4
int4x4 operator+( const int4x4& lhs, const int32_t rhs )
{
	return int4x4(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs,
		lhs[3] + rhs
	);
}

int4x4 operator+=( int4x4& lhs, const int32_t rhs )
{
	return ( lhs = lhs + rhs );
}

int4x4 operator+( const int4x4& lhs, const int4x4& rhs )
{
	return int4x4(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2],
		lhs[3] + rhs[3]
	);
}

int4x4 operator+=( int4x4& lhs, const int4x4& rhs )
{
	return ( lhs = lhs + rhs );
}

int4x4 operator-( const int4x4& lhs, const int32_t rhs )
{
	return int4x4(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs,
		lhs[3] - rhs
	);
}

int4x4 operator-=( int4x4& lhs, const int32_t rhs )
{
	return ( lhs = lhs - rhs );
}

int4x4 operator-( const int4x4& lhs, const int4x4& rhs )
{
	return int4x4(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2],
		lhs[3] - rhs[3]
	);
}

int4x4 operator-=( int4x4& lhs, const int4x4& rhs )
{
	return ( lhs = lhs - rhs );
}

int4x4 operator*( const int4x4& lhs, const int32_t rhs )
{
	return int4x4(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs,
		lhs[3] * rhs
	);
}

int4x4 operator*=( int4x4& lhs, const int32_t rhs )
{
	return ( lhs = lhs * rhs );
}

int4x4 operator*( const int4x4& lhs, const int4x4& rhs )
{
	int4 row0 = lhs[0];
	int4 row1 = lhs[1];
	int4 row2 = lhs[2];
	int4 row3 = lhs[3];

	int4 col0 = { rhs[0].x, rhs[1].x, rhs[2].x, rhs[3].x };
	int4 col1 = { rhs[0].y, rhs[1].y, rhs[2].y, rhs[3].y };
	int4 col2 = { rhs[0].z, rhs[1].z, rhs[2].z, rhs[3].z };
	int4 col3 = { rhs[0].w, rhs[1].w, rhs[2].w, rhs[3].w };

	return int4x4(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z + row0.w * col0.w,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z + row0.w * col1.w,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z + row0.w * col2.w,
		row0.x * col3.x + row0.y * col3.y + row0.z * col3.z + row0.w * col3.w,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z + row1.w * col0.w,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z + row1.w * col1.w,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z + row1.w * col2.w,
		row1.x * col3.x + row1.y * col3.y + row1.z * col3.z + row1.w * col3.w,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z + row2.w * col0.w,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z + row2.w * col1.w,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z + row2.w * col2.w,
		row2.x * col3.x + row2.y * col3.y + row2.z * col3.z + row2.w * col3.w,

		row3.x * col0.x + row3.y * col0.y + row3.z * col0.z + row3.w * col0.w,
		row3.x * col1.x + row3.y * col1.y + row3.z * col1.z + row3.w * col1.w,
		row3.x * col2.x + row3.y * col2.y + row3.z * col2.z + row3.w * col2.w,
		row3.x * col3.x + row3.y * col3.y + row3.z * col3.z + row3.w * col3.w
	);
}

int4x4 operator*=( int4x4& lhs, const int4x4& rhs )
{
	return ( lhs = lhs * rhs );
}

int4x4 operator/( const int4x4& lhs, const int32_t rhs )
{
	return int4x4(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs,
		lhs[3] / rhs
	);
}

int4x4 operator/=( int4x4& lhs, const int32_t rhs )
{
	return ( lhs = lhs / rhs );
}

int4x4 operator/( const int4x4& lhs, const int4x4& rhs )
{
	return int4x4(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2],
		lhs[3] / rhs[3]
	);
}

int4x4 operator/=( int4x4& lhs, const int4x4& rhs )
{
	return ( lhs = lhs / rhs );
}

int4 operator*( const int4x4& lhs, const int4& rhs )
{
	return int4(
		(int32_t) dot( lhs[0], rhs ),
		(int32_t) dot( lhs[1], rhs ),
		(int32_t) dot( lhs[2], rhs ),
		(int32_t) dot( lhs[3], rhs )
	);
}

int4 operator*=( int4& lhs, const int4x4& rhs )
{
	return ( lhs = rhs * lhs );
}

// prefix
int4x4& operator++( int4x4& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	++lhs[3];
	return lhs;
}

// postfix
int4x4& operator++( int4x4& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	lhs[3]++;
	return lhs;
}

// prefix
int4x4& operator--( int4x4& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	--lhs[3];
	return lhs;
}

// postfix
int4x4& operator--( int4x4& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	lhs[3]--;
	return lhs;
}

bool4x4 operator<( const int4x4& lhs, const int4x4& rhs )
{
	return bool4x4(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2],
		lhs[3] < rhs[3]
	);
}

bool4x4 operator<=( const int4x4& lhs, const int4x4& rhs )
{
	return bool4x4(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2],
		lhs[3] <= rhs[3]
	);
}

bool4x4 operator>( const int4x4& lhs, const int4x4& rhs )
{
	return bool4x4(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2],
		lhs[3] > rhs[3]
	);
}

bool4x4 operator>=( const int4x4& lhs, const int4x4& rhs )
{
	return bool4x4(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2],
		lhs[3] >= rhs[3]
	);
}

int4x4 operator&( const int4x4& lhs, const int32_t& rhs )
{
	return int4x4(
		lhs[0] & rhs,
		lhs[1] & rhs,
		lhs[2] & rhs,
		lhs[3] & rhs
	);
}

int4x4 operator&=( int4x4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

int4x4 operator&( const int4x4& lhs, const int4x4& rhs )
{
	return int4x4(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1],
		lhs[2] & rhs[2],
		lhs[3] & rhs[3]
	);
}

int4x4 operator&=( int4x4& lhs, const int4x4& rhs )
{
	return ( lhs = lhs & rhs );
}

int4x4 operator|( const int4x4& lhs, const int32_t& rhs )
{
	return int4x4(
		lhs[0] | rhs,
		lhs[1] | rhs,
		lhs[2] | rhs,
		lhs[3] | rhs
	);
}

int4x4 operator|=( int4x4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

int4x4 operator|( const int4x4& lhs, const int4x4& rhs )
{
	return int4x4(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1],
		lhs[2] | rhs[2],
		lhs[3] | rhs[3]
	);
}

int4x4 operator|=( int4x4& lhs, const int4x4& rhs )
{
	return ( lhs = lhs | rhs );
}

int4x4 operator^( const int4x4& lhs, const int32_t& rhs )
{
	return int4x4(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs,
		lhs[2] ^ rhs,
		lhs[3] ^ rhs
	);
}

int4x4 operator^=( int4x4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int4x4 operator^( const int4x4& lhs, const int4x4& rhs )
{
	return int4x4(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1],
		lhs[2] ^ rhs[2],
		lhs[3] ^ rhs[3]
	);
}

int4x4 operator^=( int4x4& lhs, const int4x4& rhs )
{
	return ( lhs = lhs ^ rhs );
}

int4x4 operator<<( const int4x4& lhs, const int32_t& rhs )
{
	return int4x4(
		lhs[0] << rhs,
		lhs[1] << rhs,
		lhs[2] << rhs,
		lhs[3] << rhs
	);
}

int4x4 operator<<=( int4x4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

int4x4 operator<<( const int4x4& lhs, const int4x4& rhs )
{
	return int4x4(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1],
		lhs[2] << rhs[2],
		lhs[3] << rhs[3]
	);
}

int4x4 operator<<=( int4x4& lhs, const int4x4& rhs )
{
	return ( lhs = lhs << rhs );
}

int4x4 operator>>( const int4x4& lhs, const int32_t& rhs )
{
	return int4x4(
		lhs[0] >> rhs,
		lhs[1] >> rhs,
		lhs[2] >> rhs,
		lhs[3] >> rhs
	);
}

int4x4 operator>>=( int4x4& lhs, const int32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

int4x4 operator>>( const int4x4& lhs, const int4x4& rhs )
{
	return int4x4(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1],
		lhs[2] >> rhs[2],
		lhs[3] >> rhs[3]
	);
}

int4x4 operator>>=( int4x4& lhs, const int4x4& rhs )
{
	return ( lhs = lhs >> rhs );
}

int4x4 operator~( const int4x4& lhs )
{
	return int4x4(
		~lhs[0],
		~lhs[1],
		~lhs[2],
		~lhs[3]
	);
}


// uint2x2
uint2x2 operator+( const uint2x2& lhs, const uint32_t rhs )
{
	return uint2x2(
		lhs[0] + rhs,
		lhs[1] + rhs
	);
}

uint2x2 operator+=( uint2x2& lhs, const uint32_t rhs )
{
	return ( lhs = lhs + rhs );
}

uint2x2 operator+( const uint2x2& lhs, const uint2x2& rhs )
{
	return uint2x2(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1]
	);
}

uint2x2 operator+=( uint2x2& lhs, const uint2x2& rhs )
{
	return ( lhs = lhs + rhs );
}

uint2x2 operator-( const uint2x2& lhs, const uint32_t rhs )
{
	return uint2x2(
		lhs[0] - rhs,
		lhs[1] - rhs
	);
}

uint2x2 operator-=( uint2x2& lhs, const uint32_t rhs )
{
	return ( lhs = lhs - rhs );
}

uint2x2 operator-( const uint2x2& lhs, const uint2x2& rhs )
{
	return uint2x2(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1]
	);
}

uint2x2 operator-=( uint2x2& lhs, const uint2x2& rhs )
{
	return ( lhs = lhs - rhs );
}

uint2x2 operator*( const uint2x2& lhs, const uint32_t rhs )
{
	return uint2x2(
		lhs[0] * rhs,
		lhs[1] * rhs
	);
}

uint2x2 operator*=( uint2x2& lhs, const uint32_t rhs )
{
	return ( lhs = lhs * rhs );
}

uint2x2 operator*( const uint2x2& lhs, const uint2x2& rhs )
{
	uint2 row0 = lhs[0];
	uint2 row1 = lhs[1];

	uint2 col0 = { rhs[0].x, rhs[1].x };
	uint2 col1 = { rhs[0].y, rhs[1].y };

	return uint2x2(
		row0.x * col0.x + row0.y * col0.y,
		row0.x * col1.x + row0.y * col1.y,

		row1.x * col0.x + row1.y * col0.y,
		row1.x * col1.x + row1.y * col1.y
	);
}

uint2x2 operator*=( uint2x2& lhs, const uint2x2& rhs )
{
	return ( lhs = lhs * rhs );
}

uint2x2 operator/( const uint2x2& lhs, const uint32_t rhs )
{
	return uint2x2(
		lhs[0] / rhs,
		lhs[1] / rhs
	);
}

uint2x2 operator/=( uint2x2& lhs, const uint32_t rhs )
{
	return ( lhs = lhs / rhs );
}

uint2x2 operator/( const uint2x2& lhs, const uint2x2& rhs )
{
	return uint2x2(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1]
	);
}

uint2x2 operator/=( uint2x2& lhs, const uint2x2& rhs )
{
	return ( lhs = lhs / rhs );
}

uint2 operator*( const uint2x2& lhs, const uint2& rhs )
{
	return uint2(
		(uint32_t) dot( lhs[0], rhs ),
		(uint32_t) dot( lhs[1], rhs )
	);
}

uint2 operator*=( uint2& lhs, const uint2x2& rhs )
{
	return ( lhs = rhs * lhs );
}

// prefix
uint2x2& operator++( uint2x2& lhs )
{
	++lhs[0];
	++lhs[1];
	return lhs;
}

// postfix
uint2x2& operator++( uint2x2& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	return lhs;
}

// prefix
uint2x2& operator--( uint2x2& lhs )
{
	--lhs[0];
	--lhs[1];
	return lhs;
}

// postfix
uint2x2& operator--( uint2x2& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	return lhs;
}

bool2x2 operator<( const uint2x2& lhs, const uint2x2& rhs )
{
	return bool2x2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2x2 operator<=( const uint2x2& lhs, const uint2x2& rhs )
{
	return bool2x2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2x2 operator>( const uint2x2& lhs, const uint2x2& rhs )
{
	return bool2x2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2x2 operator>=( const uint2x2& lhs, const uint2x2& rhs )
{
	return bool2x2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}

uint2x2 operator&( const uint2x2& lhs, const uint32_t& rhs )
{
	return uint2x2(
		lhs[0] & rhs,
		lhs[1] & rhs
	);
}

uint2x2 operator&=( uint2x2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

uint2x2 operator&( const uint2x2& lhs, const uint2x2& rhs )
{
	return uint2x2(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1]
	);
}

uint2x2 operator&=( uint2x2& lhs, const uint2x2& rhs )
{
	return ( lhs = lhs & rhs );
}

uint2x2 operator|( const uint2x2& lhs, const uint32_t& rhs )
{
	return uint2x2(
		lhs[0] | rhs,
		lhs[1] | rhs
	);
}

uint2x2 operator|=( uint2x2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

uint2x2 operator|( const uint2x2& lhs, const uint2x2& rhs )
{
	return uint2x2(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1]
	);
}

uint2x2 operator|=( uint2x2& lhs, const uint2x2& rhs )
{
	return ( lhs = lhs | rhs );
}

uint2x2 operator^( const uint2x2& lhs, const uint32_t& rhs )
{
	return uint2x2(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs
	);
}

uint2x2 operator^=( uint2x2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint2x2 operator^( const uint2x2& lhs, const uint2x2& rhs )
{
	return uint2x2(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1]
	);
}

uint2x2 operator^=( uint2x2& lhs, const uint2x2& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint2x2 operator<<( const uint2x2& lhs, const uint32_t& rhs )
{
	return uint2x2(
		lhs[0] << rhs,
		lhs[1] << rhs
	);
}

uint2x2 operator<<=( uint2x2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

uint2x2 operator<<( const uint2x2& lhs, const uint2x2& rhs )
{
	return uint2x2(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1]
	);
}

uint2x2 operator<<=( uint2x2& lhs, const uint2x2& rhs )
{
	return ( lhs = lhs << rhs );
}

uint2x2 operator>>( const uint2x2& lhs, const uint32_t& rhs )
{
	return uint2x2(
		lhs[0] >> rhs,
		lhs[1] >> rhs
	);
}

uint2x2 operator>>=( uint2x2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint2x2 operator>>( const uint2x2& lhs, const uint2x2& rhs )
{
	return uint2x2(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1]
	);
}

uint2x2 operator>>=( uint2x2& lhs, const uint2x2& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint2x2 operator~( const uint2x2& lhs )
{
	return uint2x2(
		~lhs[0],
		~lhs[1]
	);
}


// uint2x3
uint2x3 operator+( const uint2x3& lhs, const uint32_t rhs )
{
	return uint2x3(
		lhs[0] + rhs,
		lhs[1] + rhs
	);
}

uint2x3 operator+=( uint2x3& lhs, const uint32_t rhs )
{
	return ( lhs = lhs + rhs );
}

uint2x3 operator+( const uint2x3& lhs, const uint2x3& rhs )
{
	return uint2x3(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1]
	);
}

uint2x3 operator+=( uint2x3& lhs, const uint2x3& rhs )
{
	return ( lhs = lhs + rhs );
}

uint2x3 operator-( const uint2x3& lhs, const uint32_t rhs )
{
	return uint2x3(
		lhs[0] - rhs,
		lhs[1] - rhs
	);
}

uint2x3 operator-=( uint2x3& lhs, const uint32_t rhs )
{
	return ( lhs = lhs - rhs );
}

uint2x3 operator-( const uint2x3& lhs, const uint2x3& rhs )
{
	return uint2x3(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1]
	);
}

uint2x3 operator-=( uint2x3& lhs, const uint2x3& rhs )
{
	return ( lhs = lhs - rhs );
}

uint2x3 operator*( const uint2x3& lhs, const uint32_t rhs )
{
	return uint2x3(
		lhs[0] * rhs,
		lhs[1] * rhs
	);
}

uint2x3 operator*=( uint2x3& lhs, const uint32_t rhs )
{
	return ( lhs = lhs * rhs );
}

uint2x2 operator*( const uint2x3& lhs, const uint3x2& rhs )
{
	uint3 row0 = lhs[0];
	uint3 row1 = lhs[1];

	uint3 col0 = { rhs[0].x, rhs[1].x, rhs[2].x };
	uint3 col1 = { rhs[0].y, rhs[1].y, rhs[2].y };

	return uint2x2(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z
	);
}

uint2x3 operator/( const uint2x3& lhs, const uint32_t rhs )
{
	return uint2x3(
		lhs[0] / rhs,
		lhs[1] / rhs
	);
}

uint2x3 operator/=( uint2x3& lhs, const uint32_t rhs )
{
	return ( lhs = lhs / rhs );
}

uint2x3 operator/( const uint2x3& lhs, const uint2x3& rhs )
{
	return uint2x3(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1]
	);
}

// prefix
uint2x3& operator++( uint2x3& lhs )
{
	++lhs[0];
	++lhs[1];
	return lhs;
}

// postfix
uint2x3& operator++( uint2x3& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	return lhs;
}

// prefix
uint2x3& operator--( uint2x3& lhs )
{
	--lhs[0];
	--lhs[1];
	return lhs;
}

// postfix
uint2x3& operator--( uint2x3& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	return lhs;
}

bool2x3 operator<( const uint2x3& lhs, const uint2x3& rhs )
{
	return bool2x3(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2x3 operator<=( const uint2x3& lhs, const uint2x3& rhs )
{
	return bool2x3(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2x3 operator>( const uint2x3& lhs, const uint2x3& rhs )
{
	return bool2x3(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2x3 operator>=( const uint2x3& lhs, const uint2x3& rhs )
{
	return bool2x3(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}

uint2x3 operator&( const uint2x3& lhs, const uint32_t& rhs )
{
	return uint2x3(
		lhs[0] & rhs,
		lhs[1] & rhs
	);
}

uint2x3 operator&=( uint2x3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

uint2x3 operator&( const uint2x3& lhs, const uint2x3& rhs )
{
	return uint2x3(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1]
	);
}

uint2x3 operator&=( uint2x3& lhs, const uint2x3& rhs )
{
	return ( lhs = lhs & rhs );
}

uint2x3 operator|( const uint2x3& lhs, const uint32_t& rhs )
{
	return uint2x3(
		lhs[0] | rhs,
		lhs[1] | rhs
	);
}

uint2x3 operator|=( uint2x3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

uint2x3 operator|( const uint2x3& lhs, const uint2x3& rhs )
{
	return uint2x3(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1]
	);
}

uint2x3 operator|=( uint2x3& lhs, const uint2x3& rhs )
{
	return ( lhs = lhs | rhs );
}

uint2x3 operator^( const uint2x3& lhs, const uint32_t& rhs )
{
	return uint2x3(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs
	);
}

uint2x3 operator^=( uint2x3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint2x3 operator^( const uint2x3& lhs, const uint2x3& rhs )
{
	return uint2x3(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1]
	);
}

uint2x3 operator^=( uint2x3& lhs, const uint2x3& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint2x3 operator<<( const uint2x3& lhs, const uint32_t& rhs )
{
	return uint2x3(
		lhs[0] << rhs,
		lhs[1] << rhs
	);
}

uint2x3 operator<<=( uint2x3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

uint2x3 operator<<( const uint2x3& lhs, const uint2x3& rhs )
{
	return uint2x3(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1]
	);
}

uint2x3 operator<<=( uint2x3& lhs, const uint2x3& rhs )
{
	return ( lhs = lhs << rhs );
}

uint2x3 operator>>( const uint2x3& lhs, const uint32_t& rhs )
{
	return uint2x3(
		lhs[0] >> rhs,
		lhs[1] >> rhs
	);
}

uint2x3 operator>>=( uint2x3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint2x3 operator>>( const uint2x3& lhs, const uint2x3& rhs )
{
	return uint2x3(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1]
	);
}

uint2x3 operator>>=( uint2x3& lhs, const uint2x3& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint2x3 operator~( const uint2x3& lhs )
{
	return uint2x3(
		~lhs[0],
		~lhs[1]
	);
}


// uint2x4
uint2x4 operator+( const uint2x4& lhs, const uint32_t rhs )
{
	return uint2x4(
		lhs[0] + rhs,
		lhs[1] + rhs
	);
}

uint2x4 operator+=( uint2x4& lhs, const uint32_t rhs )
{
	return ( lhs = lhs + rhs );
}

uint2x4 operator+( const uint2x4& lhs, const uint2x4& rhs )
{
	return uint2x4(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1]
	);
}

uint2x4 operator+=( uint2x4& lhs, const uint2x4& rhs )
{
	return ( lhs = lhs + rhs );
}

uint2x4 operator-( const uint2x4& lhs, const uint32_t rhs )
{
	return uint2x4(
		lhs[0] - rhs,
		lhs[1] - rhs
	);
}

uint2x4 operator-=( uint2x4& lhs, const uint32_t rhs )
{
	return ( lhs = lhs - rhs );
}

uint2x4 operator-( const uint2x4& lhs, const uint2x4& rhs )
{
	return uint2x4(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1]
	);
}

uint2x4 operator-=( uint2x4& lhs, const uint2x4& rhs )
{
	return ( lhs = lhs - rhs );
}

uint2x4 operator*( const uint2x4& lhs, const uint32_t rhs )
{
	return uint2x4(
		lhs[0] * rhs,
		lhs[1] * rhs
	);
}

uint2x4 operator*=( uint2x4& lhs, const uint32_t rhs )
{
	return ( lhs = lhs * rhs );
}

uint2x2 operator*( const uint2x4& lhs, const uint4x2& rhs )
{
	uint4 row0 = lhs[0];
	uint4 row1 = lhs[1];

	uint4 col0 = { rhs[0].x, rhs[1].x, rhs[2].x, rhs[3].x };
	uint4 col1 = { rhs[0].y, rhs[1].y, rhs[2].y, rhs[3].y };

	return uint2x2(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z + row0.w * col0.w,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z + row0.w * col1.w,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z + row1.w * col0.w,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z + row1.w * col1.w
	);
}

uint2x4 operator/( const uint2x4& lhs, const uint32_t rhs )
{
	return uint2x4(
		lhs[0] / rhs,
		lhs[1] / rhs
	);
}

uint2x4 operator/=( uint2x4& lhs, const uint32_t rhs )
{
	return ( lhs = lhs / rhs );
}

uint2x4 operator/( const uint2x4& lhs, const uint2x4& rhs )
{
	return uint2x4(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1]
	);
}

// prefix
uint2x4& operator++( uint2x4& lhs )
{
	++lhs[0];
	++lhs[1];
	return lhs;
}

// postfix
uint2x4& operator++( uint2x4& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	return lhs;
}

// prefix
uint2x4& operator--( uint2x4& lhs )
{
	--lhs[0];
	--lhs[1];
	return lhs;
}

// postfix
uint2x4& operator--( uint2x4& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	return lhs;
}

bool2x4 operator<( const uint2x4& lhs, const uint2x4& rhs )
{
	return bool2x4(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2x4 operator<=( const uint2x4& lhs, const uint2x4& rhs )
{
	return bool2x4(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2x4 operator>( const uint2x4& lhs, const uint2x4& rhs )
{
	return bool2x4(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2x4 operator>=( const uint2x4& lhs, const uint2x4& rhs )
{
	return bool2x4(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}

uint2x4 operator&( const uint2x4& lhs, const uint32_t& rhs )
{
	return uint2x4(
		lhs[0] & rhs,
		lhs[1] & rhs
	);
}

uint2x4 operator&=( uint2x4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

uint2x4 operator&( const uint2x4& lhs, const uint2x4& rhs )
{
	return uint2x4(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1]
	);
}

uint2x4 operator&=( uint2x4& lhs, const uint2x4& rhs )
{
	return ( lhs = lhs & rhs );
}

uint2x4 operator|( const uint2x4& lhs, const uint32_t& rhs )
{
	return uint2x4(
		lhs[0] | rhs,
		lhs[1] | rhs
	);
}

uint2x4 operator|=( uint2x4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

uint2x4 operator|( const uint2x4& lhs, const uint2x4& rhs )
{
	return uint2x4(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1]
	);
}

uint2x4 operator|=( uint2x4& lhs, const uint2x4& rhs )
{
	return ( lhs = lhs | rhs );
}

uint2x4 operator^( const uint2x4& lhs, const uint32_t& rhs )
{
	return uint2x4(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs
	);
}

uint2x4 operator^=( uint2x4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint2x4 operator^( const uint2x4& lhs, const uint2x4& rhs )
{
	return uint2x4(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1]
	);
}

uint2x4 operator^=( uint2x4& lhs, const uint2x4& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint2x4 operator<<( const uint2x4& lhs, const uint32_t& rhs )
{
	return uint2x4(
		lhs[0] << rhs,
		lhs[1] << rhs
	);
}

uint2x4 operator<<=( uint2x4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

uint2x4 operator<<( const uint2x4& lhs, const uint2x4& rhs )
{
	return uint2x4(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1]
	);
}

uint2x4 operator<<=( uint2x4& lhs, const uint2x4& rhs )
{
	return ( lhs = lhs << rhs );
}

uint2x4 operator>>( const uint2x4& lhs, const uint32_t& rhs )
{
	return uint2x4(
		lhs[0] >> rhs,
		lhs[1] >> rhs
	);
}

uint2x4 operator>>=( uint2x4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint2x4 operator>>( const uint2x4& lhs, const uint2x4& rhs )
{
	return uint2x4(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1]
	);
}

uint2x4 operator>>=( uint2x4& lhs, const uint2x4& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint2x4 operator~( const uint2x4& lhs )
{
	return uint2x4(
		~lhs[0],
		~lhs[1]
	);
}


// uint3x2
uint3x2 operator+( const uint3x2& lhs, const uint32_t rhs )
{
	return uint3x2(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs
	);
}

uint3x2 operator+=( uint3x2& lhs, const uint32_t rhs )
{
	return ( lhs = lhs + rhs );
}

uint3x2 operator+( const uint3x2& lhs, const uint3x2& rhs )
{
	return uint3x2(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2]
	);
}

uint3x2 operator+=( uint3x2& lhs, const uint3x2& rhs )
{
	return ( lhs = lhs + rhs );
}

uint3x2 operator-( const uint3x2& lhs, const uint32_t rhs )
{
	return uint3x2(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs
	);
}

uint3x2 operator-=( uint3x2& lhs, const uint32_t rhs )
{
	return ( lhs = lhs - rhs );
}

uint3x2 operator-( const uint3x2& lhs, const uint3x2& rhs )
{
	return uint3x2(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2]
	);
}

uint3x2 operator-=( uint3x2& lhs, const uint3x2& rhs )
{
	return ( lhs = lhs - rhs );
}

uint3x2 operator*( const uint3x2& lhs, const uint32_t rhs )
{
	return uint3x2(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs
	);
}

uint3x2 operator*=( uint3x2& lhs, const uint32_t rhs )
{
	return ( lhs = lhs * rhs );
}

uint3x3 operator*( const uint3x2& lhs, const uint2x3& rhs )
{
	uint2 row0 = lhs[0];
	uint2 row1 = lhs[1];
	uint2 row2 = lhs[2];

	uint2 col0 = { rhs[0].x, rhs[1].x };
	uint2 col1 = { rhs[0].y, rhs[1].y };
	uint2 col2 = { rhs[0].z, rhs[1].z };

	return uint3x3(
		row0.x * col0.x + row0.y * col0.y,
		row0.x * col1.x + row0.y * col1.y,
		row0.x * col2.x + row0.y * col2.y,

		row1.x * col0.x + row1.y * col0.y,
		row1.x * col1.x + row1.y * col1.y,
		row1.x * col2.x + row1.y * col2.y,

		row2.x * col0.x + row2.y * col0.y,
		row2.x * col1.x + row2.y * col1.y,
		row2.x * col2.x + row2.y * col2.y
	);
}

uint3x2 operator/( const uint3x2& lhs, const uint32_t rhs )
{
	return uint3x2(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs
	);
}

uint3x2 operator/=( uint3x2& lhs, const uint32_t rhs )
{
	return ( lhs = lhs / rhs );
}

uint3x2 operator/( const uint3x2& lhs, const uint3x2& rhs )
{
	return uint3x2(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2]
	);
}

// prefix
uint3x2& operator++( uint3x2& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	return lhs;
}

// postfix
uint3x2& operator++( uint3x2& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	return lhs;
}

// prefix
uint3x2& operator--( uint3x2& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	return lhs;
}

// postfix
uint3x2& operator--( uint3x2& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	return lhs;
}

bool3x2 operator<( const uint3x2& lhs, const uint3x2& rhs )
{
	return bool3x2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2]
	);
}

bool3x2 operator<=( const uint3x2& lhs, const uint3x2& rhs )
{
	return bool3x2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2]
	);
}

bool3x2 operator>( const uint3x2& lhs, const uint3x2& rhs )
{
	return bool3x2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2]
	);
}

bool3x2 operator>=( const uint3x2& lhs, const uint3x2& rhs )
{
	return bool3x2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2]
	);
}

uint3x2 operator&( const uint3x2& lhs, const uint32_t& rhs )
{
	return uint3x2(
		lhs[0] & rhs,
		lhs[1] & rhs,
		lhs[2] & rhs
	);
}

uint3x2 operator&=( uint3x2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

uint3x2 operator&( const uint3x2& lhs, const uint3x2& rhs )
{
	return uint3x2(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1],
		lhs[2] & rhs[2]
	);
}

uint3x2 operator&=( uint3x2& lhs, const uint3x2& rhs )
{
	return ( lhs = lhs & rhs );
}

uint3x2 operator|( const uint3x2& lhs, const uint32_t& rhs )
{
	return uint3x2(
		lhs[0] | rhs,
		lhs[1] | rhs,
		lhs[2] | rhs
	);
}

uint3x2 operator|=( uint3x2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

uint3x2 operator|( const uint3x2& lhs, const uint3x2& rhs )
{
	return uint3x2(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1],
		lhs[2] | rhs[2]
	);
}

uint3x2 operator|=( uint3x2& lhs, const uint3x2& rhs )
{
	return ( lhs = lhs | rhs );
}

uint3x2 operator^( const uint3x2& lhs, const uint32_t& rhs )
{
	return uint3x2(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs,
		lhs[2] ^ rhs
	);
}

uint3x2 operator^=( uint3x2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint3x2 operator^( const uint3x2& lhs, const uint3x2& rhs )
{
	return uint3x2(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1],
		lhs[2] ^ rhs[2]
	);
}

uint3x2 operator^=( uint3x2& lhs, const uint3x2& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint3x2 operator<<( const uint3x2& lhs, const uint32_t& rhs )
{
	return uint3x2(
		lhs[0] << rhs,
		lhs[1] << rhs,
		lhs[2] << rhs
	);
}

uint3x2 operator<<=( uint3x2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

uint3x2 operator<<( const uint3x2& lhs, const uint3x2& rhs )
{
	return uint3x2(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1],
		lhs[2] << rhs[2]
	);
}

uint3x2 operator<<=( uint3x2& lhs, const uint3x2& rhs )
{
	return ( lhs = lhs << rhs );
}

uint3x2 operator>>( const uint3x2& lhs, const uint32_t& rhs )
{
	return uint3x2(
		lhs[0] >> rhs,
		lhs[1] >> rhs,
		lhs[2] >> rhs
	);
}

uint3x2 operator>>=( uint3x2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint3x2 operator>>( const uint3x2& lhs, const uint3x2& rhs )
{
	return uint3x2(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1],
		lhs[2] >> rhs[2]
	);
}

uint3x2 operator>>=( uint3x2& lhs, const uint3x2& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint3x2 operator~( const uint3x2& lhs )
{
	return uint3x2(
		~lhs[0],
		~lhs[1],
		~lhs[2]
	);
}


// uint3x3
uint3x3 operator+( const uint3x3& lhs, const uint32_t rhs )
{
	return uint3x3(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs
	);
}

uint3x3 operator+=( uint3x3& lhs, const uint32_t rhs )
{
	return ( lhs = lhs + rhs );
}

uint3x3 operator+( const uint3x3& lhs, const uint3x3& rhs )
{
	return uint3x3(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2]
	);
}

uint3x3 operator+=( uint3x3& lhs, const uint3x3& rhs )
{
	return ( lhs = lhs + rhs );
}

uint3x3 operator-( const uint3x3& lhs, const uint32_t rhs )
{
	return uint3x3(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs
	);
}

uint3x3 operator-=( uint3x3& lhs, const uint32_t rhs )
{
	return ( lhs = lhs - rhs );
}

uint3x3 operator-( const uint3x3& lhs, const uint3x3& rhs )
{
	return uint3x3(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2]
	);
}

uint3x3 operator-=( uint3x3& lhs, const uint3x3& rhs )
{
	return ( lhs = lhs - rhs );
}

uint3x3 operator*( const uint3x3& lhs, const uint32_t rhs )
{
	return uint3x3(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs
	);
}

uint3x3 operator*=( uint3x3& lhs, const uint32_t rhs )
{
	return ( lhs = lhs * rhs );
}

uint3x3 operator*( const uint3x3& lhs, const uint3x3& rhs )
{
	uint3 row0 = lhs[0];
	uint3 row1 = lhs[1];
	uint3 row2 = lhs[2];

	uint3 col0 = { rhs[0].x, rhs[1].x, rhs[2].x };
	uint3 col1 = { rhs[0].y, rhs[1].y, rhs[2].y };
	uint3 col2 = { rhs[0].z, rhs[1].z, rhs[2].z };

	return uint3x3(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z
	);
}

uint3x3 operator*=( uint3x3& lhs, const uint3x3& rhs )
{
	return ( lhs = lhs * rhs );
}

uint3x3 operator/( const uint3x3& lhs, const uint32_t rhs )
{
	return uint3x3(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs
	);
}

uint3x3 operator/=( uint3x3& lhs, const uint32_t rhs )
{
	return ( lhs = lhs / rhs );
}

uint3x3 operator/( const uint3x3& lhs, const uint3x3& rhs )
{
	return uint3x3(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2]
	);
}

uint3x3 operator/=( uint3x3& lhs, const uint3x3& rhs )
{
	return ( lhs = lhs / rhs );
}

uint3 operator*( const uint3x3& lhs, const uint3& rhs )
{
	return uint3(
		(uint32_t) dot( lhs[0], rhs ),
		(uint32_t) dot( lhs[1], rhs ),
		(uint32_t) dot( lhs[2], rhs )
	);
}

uint3 operator*=( uint3& lhs, const uint3x3& rhs )
{
	return ( lhs = rhs * lhs );
}

// prefix
uint3x3& operator++( uint3x3& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	return lhs;
}

// postfix
uint3x3& operator++( uint3x3& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	return lhs;
}

// prefix
uint3x3& operator--( uint3x3& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	return lhs;
}

// postfix
uint3x3& operator--( uint3x3& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	return lhs;
}

bool3x3 operator<( const uint3x3& lhs, const uint3x3& rhs )
{
	return bool3x3(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2]
	);
}

bool3x3 operator<=( const uint3x3& lhs, const uint3x3& rhs )
{
	return bool3x3(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2]
	);
}

bool3x3 operator>( const uint3x3& lhs, const uint3x3& rhs )
{
	return bool3x3(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2]
	);
}

bool3x3 operator>=( const uint3x3& lhs, const uint3x3& rhs )
{
	return bool3x3(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2]
	);
}

uint3x3 operator&( const uint3x3& lhs, const uint32_t& rhs )
{
	return uint3x3(
		lhs[0] & rhs,
		lhs[1] & rhs,
		lhs[2] & rhs
	);
}

uint3x3 operator&=( uint3x3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

uint3x3 operator&( const uint3x3& lhs, const uint3x3& rhs )
{
	return uint3x3(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1],
		lhs[2] & rhs[2]
	);
}

uint3x3 operator&=( uint3x3& lhs, const uint3x3& rhs )
{
	return ( lhs = lhs & rhs );
}

uint3x3 operator|( const uint3x3& lhs, const uint32_t& rhs )
{
	return uint3x3(
		lhs[0] | rhs,
		lhs[1] | rhs,
		lhs[2] | rhs
	);
}

uint3x3 operator|=( uint3x3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

uint3x3 operator|( const uint3x3& lhs, const uint3x3& rhs )
{
	return uint3x3(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1],
		lhs[2] | rhs[2]
	);
}

uint3x3 operator|=( uint3x3& lhs, const uint3x3& rhs )
{
	return ( lhs = lhs | rhs );
}

uint3x3 operator^( const uint3x3& lhs, const uint32_t& rhs )
{
	return uint3x3(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs,
		lhs[2] ^ rhs
	);
}

uint3x3 operator^=( uint3x3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint3x3 operator^( const uint3x3& lhs, const uint3x3& rhs )
{
	return uint3x3(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1],
		lhs[2] ^ rhs[2]
	);
}

uint3x3 operator^=( uint3x3& lhs, const uint3x3& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint3x3 operator<<( const uint3x3& lhs, const uint32_t& rhs )
{
	return uint3x3(
		lhs[0] << rhs,
		lhs[1] << rhs,
		lhs[2] << rhs
	);
}

uint3x3 operator<<=( uint3x3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

uint3x3 operator<<( const uint3x3& lhs, const uint3x3& rhs )
{
	return uint3x3(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1],
		lhs[2] << rhs[2]
	);
}

uint3x3 operator<<=( uint3x3& lhs, const uint3x3& rhs )
{
	return ( lhs = lhs << rhs );
}

uint3x3 operator>>( const uint3x3& lhs, const uint32_t& rhs )
{
	return uint3x3(
		lhs[0] >> rhs,
		lhs[1] >> rhs,
		lhs[2] >> rhs
	);
}

uint3x3 operator>>=( uint3x3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint3x3 operator>>( const uint3x3& lhs, const uint3x3& rhs )
{
	return uint3x3(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1],
		lhs[2] >> rhs[2]
	);
}

uint3x3 operator>>=( uint3x3& lhs, const uint3x3& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint3x3 operator~( const uint3x3& lhs )
{
	return uint3x3(
		~lhs[0],
		~lhs[1],
		~lhs[2]
	);
}


// uint3x4
uint3x4 operator+( const uint3x4& lhs, const uint32_t rhs )
{
	return uint3x4(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs
	);
}

uint3x4 operator+=( uint3x4& lhs, const uint32_t rhs )
{
	return ( lhs = lhs + rhs );
}

uint3x4 operator+( const uint3x4& lhs, const uint3x4& rhs )
{
	return uint3x4(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2]
	);
}

uint3x4 operator+=( uint3x4& lhs, const uint3x4& rhs )
{
	return ( lhs = lhs + rhs );
}

uint3x4 operator-( const uint3x4& lhs, const uint32_t rhs )
{
	return uint3x4(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs
	);
}

uint3x4 operator-=( uint3x4& lhs, const uint32_t rhs )
{
	return ( lhs = lhs - rhs );
}

uint3x4 operator-( const uint3x4& lhs, const uint3x4& rhs )
{
	return uint3x4(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2]
	);
}

uint3x4 operator-=( uint3x4& lhs, const uint3x4& rhs )
{
	return ( lhs = lhs - rhs );
}

uint3x4 operator*( const uint3x4& lhs, const uint32_t rhs )
{
	return uint3x4(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs
	);
}

uint3x4 operator*=( uint3x4& lhs, const uint32_t rhs )
{
	return ( lhs = lhs * rhs );
}

uint3x3 operator*( const uint3x4& lhs, const uint4x3& rhs )
{
	uint4 row0 = lhs[0];
	uint4 row1 = lhs[1];
	uint4 row2 = lhs[2];

	uint4 col0 = { rhs[0].x, rhs[1].x, rhs[2].x, rhs[3].x };
	uint4 col1 = { rhs[0].y, rhs[1].y, rhs[2].y, rhs[3].y };
	uint4 col2 = { rhs[0].z, rhs[1].z, rhs[2].z, rhs[3].z };

	return uint3x3(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z + row0.w * col0.w,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z + row0.w * col1.w,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z + row0.w * col2.w,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z + row1.w * col0.w,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z + row1.w * col1.w,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z + row1.w * col2.w,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z + row2.w * col0.w,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z + row2.w * col1.w,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z + row2.w * col2.w
	);
}

uint3x4 operator/( const uint3x4& lhs, const uint32_t rhs )
{
	return uint3x4(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs
	);
}

uint3x4 operator/=( uint3x4& lhs, const uint32_t rhs )
{
	return ( lhs = lhs / rhs );
}

uint3x4 operator/( const uint3x4& lhs, const uint3x4& rhs )
{
	return uint3x4(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2]
	);
}

// prefix
uint3x4& operator++( uint3x4& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	return lhs;
}

// postfix
uint3x4& operator++( uint3x4& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	return lhs;
}

// prefix
uint3x4& operator--( uint3x4& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	return lhs;
}

// postfix
uint3x4& operator--( uint3x4& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	return lhs;
}

bool3x4 operator<( const uint3x4& lhs, const uint3x4& rhs )
{
	return bool3x4(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2]
	);
}

bool3x4 operator<=( const uint3x4& lhs, const uint3x4& rhs )
{
	return bool3x4(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2]
	);
}

bool3x4 operator>( const uint3x4& lhs, const uint3x4& rhs )
{
	return bool3x4(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2]
	);
}

bool3x4 operator>=( const uint3x4& lhs, const uint3x4& rhs )
{
	return bool3x4(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2]
	);
}

uint3x4 operator&( const uint3x4& lhs, const uint32_t& rhs )
{
	return uint3x4(
		lhs[0] & rhs,
		lhs[1] & rhs,
		lhs[2] & rhs
	);
}

uint3x4 operator&=( uint3x4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

uint3x4 operator&( const uint3x4& lhs, const uint3x4& rhs )
{
	return uint3x4(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1],
		lhs[2] & rhs[2]
	);
}

uint3x4 operator&=( uint3x4& lhs, const uint3x4& rhs )
{
	return ( lhs = lhs & rhs );
}

uint3x4 operator|( const uint3x4& lhs, const uint32_t& rhs )
{
	return uint3x4(
		lhs[0] | rhs,
		lhs[1] | rhs,
		lhs[2] | rhs
	);
}

uint3x4 operator|=( uint3x4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

uint3x4 operator|( const uint3x4& lhs, const uint3x4& rhs )
{
	return uint3x4(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1],
		lhs[2] | rhs[2]
	);
}

uint3x4 operator|=( uint3x4& lhs, const uint3x4& rhs )
{
	return ( lhs = lhs | rhs );
}

uint3x4 operator^( const uint3x4& lhs, const uint32_t& rhs )
{
	return uint3x4(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs,
		lhs[2] ^ rhs
	);
}

uint3x4 operator^=( uint3x4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint3x4 operator^( const uint3x4& lhs, const uint3x4& rhs )
{
	return uint3x4(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1],
		lhs[2] ^ rhs[2]
	);
}

uint3x4 operator^=( uint3x4& lhs, const uint3x4& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint3x4 operator<<( const uint3x4& lhs, const uint32_t& rhs )
{
	return uint3x4(
		lhs[0] << rhs,
		lhs[1] << rhs,
		lhs[2] << rhs
	);
}

uint3x4 operator<<=( uint3x4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

uint3x4 operator<<( const uint3x4& lhs, const uint3x4& rhs )
{
	return uint3x4(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1],
		lhs[2] << rhs[2]
	);
}

uint3x4 operator<<=( uint3x4& lhs, const uint3x4& rhs )
{
	return ( lhs = lhs << rhs );
}

uint3x4 operator>>( const uint3x4& lhs, const uint32_t& rhs )
{
	return uint3x4(
		lhs[0] >> rhs,
		lhs[1] >> rhs,
		lhs[2] >> rhs
	);
}

uint3x4 operator>>=( uint3x4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint3x4 operator>>( const uint3x4& lhs, const uint3x4& rhs )
{
	return uint3x4(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1],
		lhs[2] >> rhs[2]
	);
}

uint3x4 operator>>=( uint3x4& lhs, const uint3x4& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint3x4 operator~( const uint3x4& lhs )
{
	return uint3x4(
		~lhs[0],
		~lhs[1],
		~lhs[2]
	);
}


// uint4x2
uint4x2 operator+( const uint4x2& lhs, const uint32_t rhs )
{
	return uint4x2(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs,
		lhs[3] + rhs
	);
}

uint4x2 operator+=( uint4x2& lhs, const uint32_t rhs )
{
	return ( lhs = lhs + rhs );
}

uint4x2 operator+( const uint4x2& lhs, const uint4x2& rhs )
{
	return uint4x2(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2],
		lhs[3] + rhs[3]
	);
}

uint4x2 operator+=( uint4x2& lhs, const uint4x2& rhs )
{
	return ( lhs = lhs + rhs );
}

uint4x2 operator-( const uint4x2& lhs, const uint32_t rhs )
{
	return uint4x2(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs,
		lhs[3] - rhs
	);
}

uint4x2 operator-=( uint4x2& lhs, const uint32_t rhs )
{
	return ( lhs = lhs - rhs );
}

uint4x2 operator-( const uint4x2& lhs, const uint4x2& rhs )
{
	return uint4x2(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2],
		lhs[3] - rhs[3]
	);
}

uint4x2 operator-=( uint4x2& lhs, const uint4x2& rhs )
{
	return ( lhs = lhs - rhs );
}

uint4x2 operator*( const uint4x2& lhs, const uint32_t rhs )
{
	return uint4x2(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs,
		lhs[3] * rhs
	);
}

uint4x2 operator*=( uint4x2& lhs, const uint32_t rhs )
{
	return ( lhs = lhs * rhs );
}

uint4x4 operator*( const uint4x2& lhs, const uint2x4& rhs )
{
	uint2 row0 = lhs[0];
	uint2 row1 = lhs[1];
	uint2 row2 = lhs[2];
	uint2 row3 = lhs[3];

	uint2 col0 = { rhs[0].x, rhs[1].x };
	uint2 col1 = { rhs[0].y, rhs[1].y };
	uint2 col2 = { rhs[0].z, rhs[1].z };
	uint2 col3 = { rhs[0].w, rhs[1].w };

	return uint4x4(
		row0.x * col0.x + row0.y * col0.y,
		row0.x * col1.x + row0.y * col1.y,
		row0.x * col2.x + row0.y * col2.y,
		row0.x * col3.x + row0.y * col3.y,

		row1.x * col0.x + row1.y * col0.y,
		row1.x * col1.x + row1.y * col1.y,
		row1.x * col2.x + row1.y * col2.y,
		row1.x * col3.x + row1.y * col3.y,

		row2.x * col0.x + row2.y * col0.y,
		row2.x * col1.x + row2.y * col1.y,
		row2.x * col2.x + row2.y * col2.y,
		row2.x * col3.x + row2.y * col3.y,

		row3.x * col0.x + row3.y * col0.y,
		row3.x * col1.x + row3.y * col1.y,
		row3.x * col2.x + row3.y * col2.y,
		row3.x * col3.x + row3.y * col3.y
	);
}

uint4x2 operator/( const uint4x2& lhs, const uint32_t rhs )
{
	return uint4x2(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs,
		lhs[3] / rhs
	);
}

uint4x2 operator/=( uint4x2& lhs, const uint32_t rhs )
{
	return ( lhs = lhs / rhs );
}

uint4x2 operator/( const uint4x2& lhs, const uint4x2& rhs )
{
	return uint4x2(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2],
		lhs[3] / rhs[3]
	);
}

// prefix
uint4x2& operator++( uint4x2& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	++lhs[3];
	return lhs;
}

// postfix
uint4x2& operator++( uint4x2& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	lhs[3]++;
	return lhs;
}

// prefix
uint4x2& operator--( uint4x2& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	--lhs[3];
	return lhs;
}

// postfix
uint4x2& operator--( uint4x2& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	lhs[3]--;
	return lhs;
}

bool4x2 operator<( const uint4x2& lhs, const uint4x2& rhs )
{
	return bool4x2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2],
		lhs[3] < rhs[3]
	);
}

bool4x2 operator<=( const uint4x2& lhs, const uint4x2& rhs )
{
	return bool4x2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2],
		lhs[3] <= rhs[3]
	);
}

bool4x2 operator>( const uint4x2& lhs, const uint4x2& rhs )
{
	return bool4x2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2],
		lhs[3] > rhs[3]
	);
}

bool4x2 operator>=( const uint4x2& lhs, const uint4x2& rhs )
{
	return bool4x2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2],
		lhs[3] >= rhs[3]
	);
}

uint4x2 operator&( const uint4x2& lhs, const uint32_t& rhs )
{
	return uint4x2(
		lhs[0] & rhs,
		lhs[1] & rhs,
		lhs[2] & rhs,
		lhs[3] & rhs
	);
}

uint4x2 operator&=( uint4x2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

uint4x2 operator&( const uint4x2& lhs, const uint4x2& rhs )
{
	return uint4x2(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1],
		lhs[2] & rhs[2],
		lhs[3] & rhs[3]
	);
}

uint4x2 operator&=( uint4x2& lhs, const uint4x2& rhs )
{
	return ( lhs = lhs & rhs );
}

uint4x2 operator|( const uint4x2& lhs, const uint32_t& rhs )
{
	return uint4x2(
		lhs[0] | rhs,
		lhs[1] | rhs,
		lhs[2] | rhs,
		lhs[3] | rhs
	);
}

uint4x2 operator|=( uint4x2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

uint4x2 operator|( const uint4x2& lhs, const uint4x2& rhs )
{
	return uint4x2(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1],
		lhs[2] | rhs[2],
		lhs[3] | rhs[3]
	);
}

uint4x2 operator|=( uint4x2& lhs, const uint4x2& rhs )
{
	return ( lhs = lhs | rhs );
}

uint4x2 operator^( const uint4x2& lhs, const uint32_t& rhs )
{
	return uint4x2(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs,
		lhs[2] ^ rhs,
		lhs[3] ^ rhs
	);
}

uint4x2 operator^=( uint4x2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint4x2 operator^( const uint4x2& lhs, const uint4x2& rhs )
{
	return uint4x2(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1],
		lhs[2] ^ rhs[2],
		lhs[3] ^ rhs[3]
	);
}

uint4x2 operator^=( uint4x2& lhs, const uint4x2& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint4x2 operator<<( const uint4x2& lhs, const uint32_t& rhs )
{
	return uint4x2(
		lhs[0] << rhs,
		lhs[1] << rhs,
		lhs[2] << rhs,
		lhs[3] << rhs
	);
}

uint4x2 operator<<=( uint4x2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

uint4x2 operator<<( const uint4x2& lhs, const uint4x2& rhs )
{
	return uint4x2(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1],
		lhs[2] << rhs[2],
		lhs[3] << rhs[3]
	);
}

uint4x2 operator<<=( uint4x2& lhs, const uint4x2& rhs )
{
	return ( lhs = lhs << rhs );
}

uint4x2 operator>>( const uint4x2& lhs, const uint32_t& rhs )
{
	return uint4x2(
		lhs[0] >> rhs,
		lhs[1] >> rhs,
		lhs[2] >> rhs,
		lhs[3] >> rhs
	);
}

uint4x2 operator>>=( uint4x2& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint4x2 operator>>( const uint4x2& lhs, const uint4x2& rhs )
{
	return uint4x2(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1],
		lhs[2] >> rhs[2],
		lhs[3] >> rhs[3]
	);
}

uint4x2 operator>>=( uint4x2& lhs, const uint4x2& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint4x2 operator~( const uint4x2& lhs )
{
	return uint4x2(
		~lhs[0],
		~lhs[1],
		~lhs[2],
		~lhs[3]
	);
}


// uint4x3
uint4x3 operator+( const uint4x3& lhs, const uint32_t rhs )
{
	return uint4x3(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs,
		lhs[3] + rhs
	);
}

uint4x3 operator+=( uint4x3& lhs, const uint32_t rhs )
{
	return ( lhs = lhs + rhs );
}

uint4x3 operator+( const uint4x3& lhs, const uint4x3& rhs )
{
	return uint4x3(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2],
		lhs[3] + rhs[3]
	);
}

uint4x3 operator+=( uint4x3& lhs, const uint4x3& rhs )
{
	return ( lhs = lhs + rhs );
}

uint4x3 operator-( const uint4x3& lhs, const uint32_t rhs )
{
	return uint4x3(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs,
		lhs[3] - rhs
	);
}

uint4x3 operator-=( uint4x3& lhs, const uint32_t rhs )
{
	return ( lhs = lhs - rhs );
}

uint4x3 operator-( const uint4x3& lhs, const uint4x3& rhs )
{
	return uint4x3(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2],
		lhs[3] - rhs[3]
	);
}

uint4x3 operator-=( uint4x3& lhs, const uint4x3& rhs )
{
	return ( lhs = lhs - rhs );
}

uint4x3 operator*( const uint4x3& lhs, const uint32_t rhs )
{
	return uint4x3(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs,
		lhs[3] * rhs
	);
}

uint4x3 operator*=( uint4x3& lhs, const uint32_t rhs )
{
	return ( lhs = lhs * rhs );
}

uint4x4 operator*( const uint4x3& lhs, const uint3x4& rhs )
{
	uint3 row0 = lhs[0];
	uint3 row1 = lhs[1];
	uint3 row2 = lhs[2];
	uint3 row3 = lhs[3];

	uint3 col0 = { rhs[0].x, rhs[1].x, rhs[2].x };
	uint3 col1 = { rhs[0].y, rhs[1].y, rhs[2].y };
	uint3 col2 = { rhs[0].z, rhs[1].z, rhs[2].z };
	uint3 col3 = { rhs[0].w, rhs[1].w, rhs[2].w };

	return uint4x4(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z,
		row0.x * col3.x + row0.y * col3.y + row0.z * col3.z,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z,
		row1.x * col3.x + row1.y * col3.y + row1.z * col3.z,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z,
		row2.x * col3.x + row2.y * col3.y + row2.z * col3.z,

		row3.x * col0.x + row3.y * col0.y + row3.z * col0.z,
		row3.x * col1.x + row3.y * col1.y + row3.z * col1.z,
		row3.x * col2.x + row3.y * col2.y + row3.z * col2.z,
		row3.x * col3.x + row3.y * col3.y + row3.z * col3.z
	);
}

uint4x3 operator/( const uint4x3& lhs, const uint32_t rhs )
{
	return uint4x3(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs,
		lhs[3] / rhs
	);
}

uint4x3 operator/=( uint4x3& lhs, const uint32_t rhs )
{
	return ( lhs = lhs / rhs );
}

uint4x3 operator/( const uint4x3& lhs, const uint4x3& rhs )
{
	return uint4x3(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2],
		lhs[3] / rhs[3]
	);
}

// prefix
uint4x3& operator++( uint4x3& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	++lhs[3];
	return lhs;
}

// postfix
uint4x3& operator++( uint4x3& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	lhs[3]++;
	return lhs;
}

// prefix
uint4x3& operator--( uint4x3& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	--lhs[3];
	return lhs;
}

// postfix
uint4x3& operator--( uint4x3& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	lhs[3]--;
	return lhs;
}

bool4x3 operator<( const uint4x3& lhs, const uint4x3& rhs )
{
	return bool4x3(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2],
		lhs[3] < rhs[3]
	);
}

bool4x3 operator<=( const uint4x3& lhs, const uint4x3& rhs )
{
	return bool4x3(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2],
		lhs[3] <= rhs[3]
	);
}

bool4x3 operator>( const uint4x3& lhs, const uint4x3& rhs )
{
	return bool4x3(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2],
		lhs[3] > rhs[3]
	);
}

bool4x3 operator>=( const uint4x3& lhs, const uint4x3& rhs )
{
	return bool4x3(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2],
		lhs[3] >= rhs[3]
	);
}

uint4x3 operator&( const uint4x3& lhs, const uint32_t& rhs )
{
	return uint4x3(
		lhs[0] & rhs,
		lhs[1] & rhs,
		lhs[2] & rhs,
		lhs[3] & rhs
	);
}

uint4x3 operator&=( uint4x3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

uint4x3 operator&( const uint4x3& lhs, const uint4x3& rhs )
{
	return uint4x3(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1],
		lhs[2] & rhs[2],
		lhs[3] & rhs[3]
	);
}

uint4x3 operator&=( uint4x3& lhs, const uint4x3& rhs )
{
	return ( lhs = lhs & rhs );
}

uint4x3 operator|( const uint4x3& lhs, const uint32_t& rhs )
{
	return uint4x3(
		lhs[0] | rhs,
		lhs[1] | rhs,
		lhs[2] | rhs,
		lhs[3] | rhs
	);
}

uint4x3 operator|=( uint4x3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

uint4x3 operator|( const uint4x3& lhs, const uint4x3& rhs )
{
	return uint4x3(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1],
		lhs[2] | rhs[2],
		lhs[3] | rhs[3]
	);
}

uint4x3 operator|=( uint4x3& lhs, const uint4x3& rhs )
{
	return ( lhs = lhs | rhs );
}

uint4x3 operator^( const uint4x3& lhs, const uint32_t& rhs )
{
	return uint4x3(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs,
		lhs[2] ^ rhs,
		lhs[3] ^ rhs
	);
}

uint4x3 operator^=( uint4x3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint4x3 operator^( const uint4x3& lhs, const uint4x3& rhs )
{
	return uint4x3(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1],
		lhs[2] ^ rhs[2],
		lhs[3] ^ rhs[3]
	);
}

uint4x3 operator^=( uint4x3& lhs, const uint4x3& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint4x3 operator<<( const uint4x3& lhs, const uint32_t& rhs )
{
	return uint4x3(
		lhs[0] << rhs,
		lhs[1] << rhs,
		lhs[2] << rhs,
		lhs[3] << rhs
	);
}

uint4x3 operator<<=( uint4x3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

uint4x3 operator<<( const uint4x3& lhs, const uint4x3& rhs )
{
	return uint4x3(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1],
		lhs[2] << rhs[2],
		lhs[3] << rhs[3]
	);
}

uint4x3 operator<<=( uint4x3& lhs, const uint4x3& rhs )
{
	return ( lhs = lhs << rhs );
}

uint4x3 operator>>( const uint4x3& lhs, const uint32_t& rhs )
{
	return uint4x3(
		lhs[0] >> rhs,
		lhs[1] >> rhs,
		lhs[2] >> rhs,
		lhs[3] >> rhs
	);
}

uint4x3 operator>>=( uint4x3& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint4x3 operator>>( const uint4x3& lhs, const uint4x3& rhs )
{
	return uint4x3(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1],
		lhs[2] >> rhs[2],
		lhs[3] >> rhs[3]
	);
}

uint4x3 operator>>=( uint4x3& lhs, const uint4x3& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint4x3 operator~( const uint4x3& lhs )
{
	return uint4x3(
		~lhs[0],
		~lhs[1],
		~lhs[2],
		~lhs[3]
	);
}


// uint4x4
uint4x4 operator+( const uint4x4& lhs, const uint32_t rhs )
{
	return uint4x4(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs,
		lhs[3] + rhs
	);
}

uint4x4 operator+=( uint4x4& lhs, const uint32_t rhs )
{
	return ( lhs = lhs + rhs );
}

uint4x4 operator+( const uint4x4& lhs, const uint4x4& rhs )
{
	return uint4x4(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2],
		lhs[3] + rhs[3]
	);
}

uint4x4 operator+=( uint4x4& lhs, const uint4x4& rhs )
{
	return ( lhs = lhs + rhs );
}

uint4x4 operator-( const uint4x4& lhs, const uint32_t rhs )
{
	return uint4x4(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs,
		lhs[3] - rhs
	);
}

uint4x4 operator-=( uint4x4& lhs, const uint32_t rhs )
{
	return ( lhs = lhs - rhs );
}

uint4x4 operator-( const uint4x4& lhs, const uint4x4& rhs )
{
	return uint4x4(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2],
		lhs[3] - rhs[3]
	);
}

uint4x4 operator-=( uint4x4& lhs, const uint4x4& rhs )
{
	return ( lhs = lhs - rhs );
}

uint4x4 operator*( const uint4x4& lhs, const uint32_t rhs )
{
	return uint4x4(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs,
		lhs[3] * rhs
	);
}

uint4x4 operator*=( uint4x4& lhs, const uint32_t rhs )
{
	return ( lhs = lhs * rhs );
}

uint4x4 operator*( const uint4x4& lhs, const uint4x4& rhs )
{
	uint4 row0 = lhs[0];
	uint4 row1 = lhs[1];
	uint4 row2 = lhs[2];
	uint4 row3 = lhs[3];

	uint4 col0 = { rhs[0].x, rhs[1].x, rhs[2].x, rhs[3].x };
	uint4 col1 = { rhs[0].y, rhs[1].y, rhs[2].y, rhs[3].y };
	uint4 col2 = { rhs[0].z, rhs[1].z, rhs[2].z, rhs[3].z };
	uint4 col3 = { rhs[0].w, rhs[1].w, rhs[2].w, rhs[3].w };

	return uint4x4(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z + row0.w * col0.w,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z + row0.w * col1.w,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z + row0.w * col2.w,
		row0.x * col3.x + row0.y * col3.y + row0.z * col3.z + row0.w * col3.w,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z + row1.w * col0.w,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z + row1.w * col1.w,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z + row1.w * col2.w,
		row1.x * col3.x + row1.y * col3.y + row1.z * col3.z + row1.w * col3.w,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z + row2.w * col0.w,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z + row2.w * col1.w,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z + row2.w * col2.w,
		row2.x * col3.x + row2.y * col3.y + row2.z * col3.z + row2.w * col3.w,

		row3.x * col0.x + row3.y * col0.y + row3.z * col0.z + row3.w * col0.w,
		row3.x * col1.x + row3.y * col1.y + row3.z * col1.z + row3.w * col1.w,
		row3.x * col2.x + row3.y * col2.y + row3.z * col2.z + row3.w * col2.w,
		row3.x * col3.x + row3.y * col3.y + row3.z * col3.z + row3.w * col3.w
	);
}

uint4x4 operator*=( uint4x4& lhs, const uint4x4& rhs )
{
	return ( lhs = lhs * rhs );
}

uint4x4 operator/( const uint4x4& lhs, const uint32_t rhs )
{
	return uint4x4(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs,
		lhs[3] / rhs
	);
}

uint4x4 operator/=( uint4x4& lhs, const uint32_t rhs )
{
	return ( lhs = lhs / rhs );
}

uint4x4 operator/( const uint4x4& lhs, const uint4x4& rhs )
{
	return uint4x4(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2],
		lhs[3] / rhs[3]
	);
}

uint4x4 operator/=( uint4x4& lhs, const uint4x4& rhs )
{
	return ( lhs = lhs / rhs );
}

uint4 operator*( const uint4x4& lhs, const uint4& rhs )
{
	return uint4(
		(uint32_t) dot( lhs[0], rhs ),
		(uint32_t) dot( lhs[1], rhs ),
		(uint32_t) dot( lhs[2], rhs ),
		(uint32_t) dot( lhs[3], rhs )
	);
}

uint4 operator*=( uint4& lhs, const uint4x4& rhs )
{
	return ( lhs = rhs * lhs );
}

// prefix
uint4x4& operator++( uint4x4& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	++lhs[3];
	return lhs;
}

// postfix
uint4x4& operator++( uint4x4& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	lhs[3]++;
	return lhs;
}

// prefix
uint4x4& operator--( uint4x4& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	--lhs[3];
	return lhs;
}

// postfix
uint4x4& operator--( uint4x4& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	lhs[3]--;
	return lhs;
}

bool4x4 operator<( const uint4x4& lhs, const uint4x4& rhs )
{
	return bool4x4(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2],
		lhs[3] < rhs[3]
	);
}

bool4x4 operator<=( const uint4x4& lhs, const uint4x4& rhs )
{
	return bool4x4(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2],
		lhs[3] <= rhs[3]
	);
}

bool4x4 operator>( const uint4x4& lhs, const uint4x4& rhs )
{
	return bool4x4(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2],
		lhs[3] > rhs[3]
	);
}

bool4x4 operator>=( const uint4x4& lhs, const uint4x4& rhs )
{
	return bool4x4(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2],
		lhs[3] >= rhs[3]
	);
}

uint4x4 operator&( const uint4x4& lhs, const uint32_t& rhs )
{
	return uint4x4(
		lhs[0] & rhs,
		lhs[1] & rhs,
		lhs[2] & rhs,
		lhs[3] & rhs
	);
}

uint4x4 operator&=( uint4x4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs & rhs );
}

uint4x4 operator&( const uint4x4& lhs, const uint4x4& rhs )
{
	return uint4x4(
		lhs[0] & rhs[0],
		lhs[1] & rhs[1],
		lhs[2] & rhs[2],
		lhs[3] & rhs[3]
	);
}

uint4x4 operator&=( uint4x4& lhs, const uint4x4& rhs )
{
	return ( lhs = lhs & rhs );
}

uint4x4 operator|( const uint4x4& lhs, const uint32_t& rhs )
{
	return uint4x4(
		lhs[0] | rhs,
		lhs[1] | rhs,
		lhs[2] | rhs,
		lhs[3] | rhs
	);
}

uint4x4 operator|=( uint4x4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs | rhs );
}

uint4x4 operator|( const uint4x4& lhs, const uint4x4& rhs )
{
	return uint4x4(
		lhs[0] | rhs[0],
		lhs[1] | rhs[1],
		lhs[2] | rhs[2],
		lhs[3] | rhs[3]
	);
}

uint4x4 operator|=( uint4x4& lhs, const uint4x4& rhs )
{
	return ( lhs = lhs | rhs );
}

uint4x4 operator^( const uint4x4& lhs, const uint32_t& rhs )
{
	return uint4x4(
		lhs[0] ^ rhs,
		lhs[1] ^ rhs,
		lhs[2] ^ rhs,
		lhs[3] ^ rhs
	);
}

uint4x4 operator^=( uint4x4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint4x4 operator^( const uint4x4& lhs, const uint4x4& rhs )
{
	return uint4x4(
		lhs[0] ^ rhs[0],
		lhs[1] ^ rhs[1],
		lhs[2] ^ rhs[2],
		lhs[3] ^ rhs[3]
	);
}

uint4x4 operator^=( uint4x4& lhs, const uint4x4& rhs )
{
	return ( lhs = lhs ^ rhs );
}

uint4x4 operator<<( const uint4x4& lhs, const uint32_t& rhs )
{
	return uint4x4(
		lhs[0] << rhs,
		lhs[1] << rhs,
		lhs[2] << rhs,
		lhs[3] << rhs
	);
}

uint4x4 operator<<=( uint4x4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs << rhs );
}

uint4x4 operator<<( const uint4x4& lhs, const uint4x4& rhs )
{
	return uint4x4(
		lhs[0] << rhs[0],
		lhs[1] << rhs[1],
		lhs[2] << rhs[2],
		lhs[3] << rhs[3]
	);
}

uint4x4 operator<<=( uint4x4& lhs, const uint4x4& rhs )
{
	return ( lhs = lhs << rhs );
}

uint4x4 operator>>( const uint4x4& lhs, const uint32_t& rhs )
{
	return uint4x4(
		lhs[0] >> rhs,
		lhs[1] >> rhs,
		lhs[2] >> rhs,
		lhs[3] >> rhs
	);
}

uint4x4 operator>>=( uint4x4& lhs, const uint32_t& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint4x4 operator>>( const uint4x4& lhs, const uint4x4& rhs )
{
	return uint4x4(
		lhs[0] >> rhs[0],
		lhs[1] >> rhs[1],
		lhs[2] >> rhs[2],
		lhs[3] >> rhs[3]
	);
}

uint4x4 operator>>=( uint4x4& lhs, const uint4x4& rhs )
{
	return ( lhs = lhs >> rhs );
}

uint4x4 operator~( const uint4x4& lhs )
{
	return uint4x4(
		~lhs[0],
		~lhs[1],
		~lhs[2],
		~lhs[3]
	);
}


// float2x2
float2x2 operator+( const float2x2& lhs, const float rhs )
{
	return float2x2(
		lhs[0] + rhs,
		lhs[1] + rhs
	);
}

float2x2 operator+=( float2x2& lhs, const float rhs )
{
	return ( lhs = lhs + rhs );
}

float2x2 operator+( const float2x2& lhs, const float2x2& rhs )
{
	return float2x2(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1]
	);
}

float2x2 operator+=( float2x2& lhs, const float2x2& rhs )
{
	return ( lhs = lhs + rhs );
}

float2x2 operator-( const float2x2& lhs, const float rhs )
{
	return float2x2(
		lhs[0] - rhs,
		lhs[1] - rhs
	);
}

float2x2 operator-=( float2x2& lhs, const float rhs )
{
	return ( lhs = lhs - rhs );
}

float2x2 operator-( const float2x2& lhs, const float2x2& rhs )
{
	return float2x2(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1]
	);
}

float2x2 operator-=( float2x2& lhs, const float2x2& rhs )
{
	return ( lhs = lhs - rhs );
}

float2x2 operator*( const float2x2& lhs, const float rhs )
{
	return float2x2(
		lhs[0] * rhs,
		lhs[1] * rhs
	);
}

float2x2 operator*=( float2x2& lhs, const float rhs )
{
	return ( lhs = lhs * rhs );
}

float2x2 operator*( const float2x2& lhs, const float2x2& rhs )
{
	float2 row0 = lhs[0];
	float2 row1 = lhs[1];

	float2 col0 = { rhs[0].x, rhs[1].x };
	float2 col1 = { rhs[0].y, rhs[1].y };

	return float2x2(
		row0.x * col0.x + row0.y * col0.y,
		row0.x * col1.x + row0.y * col1.y,

		row1.x * col0.x + row1.y * col0.y,
		row1.x * col1.x + row1.y * col1.y
	);
}

float2x2 operator*=( float2x2& lhs, const float2x2& rhs )
{
	return ( lhs = lhs * rhs );
}

float2x2 operator/( const float2x2& lhs, const float rhs )
{
	return float2x2(
		lhs[0] / rhs,
		lhs[1] / rhs
	);
}

float2x2 operator/=( float2x2& lhs, const float rhs )
{
	return ( lhs = lhs / rhs );
}

float2x2 operator/( const float2x2& lhs, const float2x2& rhs )
{
	return lhs * inverse( rhs );
}

float2x2 operator/=( float2x2& lhs, const float2x2& rhs )
{
	return ( lhs = lhs / rhs );
}

float2 operator*( const float2x2& lhs, const float2& rhs )
{
	return float2(
		(float) dot( lhs[0], rhs ),
		(float) dot( lhs[1], rhs )
	);
}

float2 operator*=( float2& lhs, const float2x2& rhs )
{
	return ( lhs = rhs * lhs );
}

// prefix
float2x2& operator++( float2x2& lhs )
{
	++lhs[0];
	++lhs[1];
	return lhs;
}

// postfix
float2x2& operator++( float2x2& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	return lhs;
}

// prefix
float2x2& operator--( float2x2& lhs )
{
	--lhs[0];
	--lhs[1];
	return lhs;
}

// postfix
float2x2& operator--( float2x2& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	return lhs;
}

bool2x2 operator<( const float2x2& lhs, const float2x2& rhs )
{
	return bool2x2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2x2 operator<=( const float2x2& lhs, const float2x2& rhs )
{
	return bool2x2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2x2 operator>( const float2x2& lhs, const float2x2& rhs )
{
	return bool2x2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2x2 operator>=( const float2x2& lhs, const float2x2& rhs )
{
	return bool2x2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}


// float2x3
float2x3 operator+( const float2x3& lhs, const float rhs )
{
	return float2x3(
		lhs[0] + rhs,
		lhs[1] + rhs
	);
}

float2x3 operator+=( float2x3& lhs, const float rhs )
{
	return ( lhs = lhs + rhs );
}

float2x3 operator+( const float2x3& lhs, const float2x3& rhs )
{
	return float2x3(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1]
	);
}

float2x3 operator+=( float2x3& lhs, const float2x3& rhs )
{
	return ( lhs = lhs + rhs );
}

float2x3 operator-( const float2x3& lhs, const float rhs )
{
	return float2x3(
		lhs[0] - rhs,
		lhs[1] - rhs
	);
}

float2x3 operator-=( float2x3& lhs, const float rhs )
{
	return ( lhs = lhs - rhs );
}

float2x3 operator-( const float2x3& lhs, const float2x3& rhs )
{
	return float2x3(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1]
	);
}

float2x3 operator-=( float2x3& lhs, const float2x3& rhs )
{
	return ( lhs = lhs - rhs );
}

float2x3 operator*( const float2x3& lhs, const float rhs )
{
	return float2x3(
		lhs[0] * rhs,
		lhs[1] * rhs
	);
}

float2x3 operator*=( float2x3& lhs, const float rhs )
{
	return ( lhs = lhs * rhs );
}

float2x2 operator*( const float2x3& lhs, const float3x2& rhs )
{
	float3 row0 = lhs[0];
	float3 row1 = lhs[1];

	float3 col0 = { rhs[0].x, rhs[1].x, rhs[2].x };
	float3 col1 = { rhs[0].y, rhs[1].y, rhs[2].y };

	return float2x2(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z
	);
}

float2x3 operator/( const float2x3& lhs, const float rhs )
{
	return float2x3(
		lhs[0] / rhs,
		lhs[1] / rhs
	);
}

float2x3 operator/=( float2x3& lhs, const float rhs )
{
	return ( lhs = lhs / rhs );
}

float2x3 operator/( const float2x3& lhs, const float2x3& rhs )
{
	return float2x3(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1]
	);
}

// prefix
float2x3& operator++( float2x3& lhs )
{
	++lhs[0];
	++lhs[1];
	return lhs;
}

// postfix
float2x3& operator++( float2x3& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	return lhs;
}

// prefix
float2x3& operator--( float2x3& lhs )
{
	--lhs[0];
	--lhs[1];
	return lhs;
}

// postfix
float2x3& operator--( float2x3& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	return lhs;
}

bool2x3 operator<( const float2x3& lhs, const float2x3& rhs )
{
	return bool2x3(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2x3 operator<=( const float2x3& lhs, const float2x3& rhs )
{
	return bool2x3(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2x3 operator>( const float2x3& lhs, const float2x3& rhs )
{
	return bool2x3(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2x3 operator>=( const float2x3& lhs, const float2x3& rhs )
{
	return bool2x3(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}


// float2x4
float2x4 operator+( const float2x4& lhs, const float rhs )
{
	return float2x4(
		lhs[0] + rhs,
		lhs[1] + rhs
	);
}

float2x4 operator+=( float2x4& lhs, const float rhs )
{
	return ( lhs = lhs + rhs );
}

float2x4 operator+( const float2x4& lhs, const float2x4& rhs )
{
	return float2x4(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1]
	);
}

float2x4 operator+=( float2x4& lhs, const float2x4& rhs )
{
	return ( lhs = lhs + rhs );
}

float2x4 operator-( const float2x4& lhs, const float rhs )
{
	return float2x4(
		lhs[0] - rhs,
		lhs[1] - rhs
	);
}

float2x4 operator-=( float2x4& lhs, const float rhs )
{
	return ( lhs = lhs - rhs );
}

float2x4 operator-( const float2x4& lhs, const float2x4& rhs )
{
	return float2x4(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1]
	);
}

float2x4 operator-=( float2x4& lhs, const float2x4& rhs )
{
	return ( lhs = lhs - rhs );
}

float2x4 operator*( const float2x4& lhs, const float rhs )
{
	return float2x4(
		lhs[0] * rhs,
		lhs[1] * rhs
	);
}

float2x4 operator*=( float2x4& lhs, const float rhs )
{
	return ( lhs = lhs * rhs );
}

float2x2 operator*( const float2x4& lhs, const float4x2& rhs )
{
	float4 row0 = lhs[0];
	float4 row1 = lhs[1];

	float4 col0 = { rhs[0].x, rhs[1].x, rhs[2].x, rhs[3].x };
	float4 col1 = { rhs[0].y, rhs[1].y, rhs[2].y, rhs[3].y };

	return float2x2(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z + row0.w * col0.w,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z + row0.w * col1.w,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z + row1.w * col0.w,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z + row1.w * col1.w
	);
}

float2x4 operator/( const float2x4& lhs, const float rhs )
{
	return float2x4(
		lhs[0] / rhs,
		lhs[1] / rhs
	);
}

float2x4 operator/=( float2x4& lhs, const float rhs )
{
	return ( lhs = lhs / rhs );
}

float2x4 operator/( const float2x4& lhs, const float2x4& rhs )
{
	return float2x4(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1]
	);
}

// prefix
float2x4& operator++( float2x4& lhs )
{
	++lhs[0];
	++lhs[1];
	return lhs;
}

// postfix
float2x4& operator++( float2x4& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	return lhs;
}

// prefix
float2x4& operator--( float2x4& lhs )
{
	--lhs[0];
	--lhs[1];
	return lhs;
}

// postfix
float2x4& operator--( float2x4& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	return lhs;
}

bool2x4 operator<( const float2x4& lhs, const float2x4& rhs )
{
	return bool2x4(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2x4 operator<=( const float2x4& lhs, const float2x4& rhs )
{
	return bool2x4(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2x4 operator>( const float2x4& lhs, const float2x4& rhs )
{
	return bool2x4(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2x4 operator>=( const float2x4& lhs, const float2x4& rhs )
{
	return bool2x4(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}


// float3x2
float3x2 operator+( const float3x2& lhs, const float rhs )
{
	return float3x2(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs
	);
}

float3x2 operator+=( float3x2& lhs, const float rhs )
{
	return ( lhs = lhs + rhs );
}

float3x2 operator+( const float3x2& lhs, const float3x2& rhs )
{
	return float3x2(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2]
	);
}

float3x2 operator+=( float3x2& lhs, const float3x2& rhs )
{
	return ( lhs = lhs + rhs );
}

float3x2 operator-( const float3x2& lhs, const float rhs )
{
	return float3x2(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs
	);
}

float3x2 operator-=( float3x2& lhs, const float rhs )
{
	return ( lhs = lhs - rhs );
}

float3x2 operator-( const float3x2& lhs, const float3x2& rhs )
{
	return float3x2(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2]
	);
}

float3x2 operator-=( float3x2& lhs, const float3x2& rhs )
{
	return ( lhs = lhs - rhs );
}

float3x2 operator*( const float3x2& lhs, const float rhs )
{
	return float3x2(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs
	);
}

float3x2 operator*=( float3x2& lhs, const float rhs )
{
	return ( lhs = lhs * rhs );
}

float3x3 operator*( const float3x2& lhs, const float2x3& rhs )
{
	float2 row0 = lhs[0];
	float2 row1 = lhs[1];
	float2 row2 = lhs[2];

	float2 col0 = { rhs[0].x, rhs[1].x };
	float2 col1 = { rhs[0].y, rhs[1].y };
	float2 col2 = { rhs[0].z, rhs[1].z };

	return float3x3(
		row0.x * col0.x + row0.y * col0.y,
		row0.x * col1.x + row0.y * col1.y,
		row0.x * col2.x + row0.y * col2.y,

		row1.x * col0.x + row1.y * col0.y,
		row1.x * col1.x + row1.y * col1.y,
		row1.x * col2.x + row1.y * col2.y,

		row2.x * col0.x + row2.y * col0.y,
		row2.x * col1.x + row2.y * col1.y,
		row2.x * col2.x + row2.y * col2.y
	);
}

float3x2 operator/( const float3x2& lhs, const float rhs )
{
	return float3x2(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs
	);
}

float3x2 operator/=( float3x2& lhs, const float rhs )
{
	return ( lhs = lhs / rhs );
}

float3x2 operator/( const float3x2& lhs, const float3x2& rhs )
{
	return float3x2(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2]
	);
}

// prefix
float3x2& operator++( float3x2& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	return lhs;
}

// postfix
float3x2& operator++( float3x2& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	return lhs;
}

// prefix
float3x2& operator--( float3x2& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	return lhs;
}

// postfix
float3x2& operator--( float3x2& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	return lhs;
}

bool3x2 operator<( const float3x2& lhs, const float3x2& rhs )
{
	return bool3x2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2]
	);
}

bool3x2 operator<=( const float3x2& lhs, const float3x2& rhs )
{
	return bool3x2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2]
	);
}

bool3x2 operator>( const float3x2& lhs, const float3x2& rhs )
{
	return bool3x2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2]
	);
}

bool3x2 operator>=( const float3x2& lhs, const float3x2& rhs )
{
	return bool3x2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2]
	);
}


// float3x3
float3x3 operator+( const float3x3& lhs, const float rhs )
{
	return float3x3(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs
	);
}

float3x3 operator+=( float3x3& lhs, const float rhs )
{
	return ( lhs = lhs + rhs );
}

float3x3 operator+( const float3x3& lhs, const float3x3& rhs )
{
	return float3x3(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2]
	);
}

float3x3 operator+=( float3x3& lhs, const float3x3& rhs )
{
	return ( lhs = lhs + rhs );
}

float3x3 operator-( const float3x3& lhs, const float rhs )
{
	return float3x3(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs
	);
}

float3x3 operator-=( float3x3& lhs, const float rhs )
{
	return ( lhs = lhs - rhs );
}

float3x3 operator-( const float3x3& lhs, const float3x3& rhs )
{
	return float3x3(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2]
	);
}

float3x3 operator-=( float3x3& lhs, const float3x3& rhs )
{
	return ( lhs = lhs - rhs );
}

float3x3 operator*( const float3x3& lhs, const float rhs )
{
	return float3x3(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs
	);
}

float3x3 operator*=( float3x3& lhs, const float rhs )
{
	return ( lhs = lhs * rhs );
}

float3x3 operator*( const float3x3& lhs, const float3x3& rhs )
{
	float3 row0 = lhs[0];
	float3 row1 = lhs[1];
	float3 row2 = lhs[2];

	float3 col0 = { rhs[0].x, rhs[1].x, rhs[2].x };
	float3 col1 = { rhs[0].y, rhs[1].y, rhs[2].y };
	float3 col2 = { rhs[0].z, rhs[1].z, rhs[2].z };

	return float3x3(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z
	);
}

float3x3 operator*=( float3x3& lhs, const float3x3& rhs )
{
	return ( lhs = lhs * rhs );
}

float3x3 operator/( const float3x3& lhs, const float rhs )
{
	return float3x3(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs
	);
}

float3x3 operator/=( float3x3& lhs, const float rhs )
{
	return ( lhs = lhs / rhs );
}

float3x3 operator/( const float3x3& lhs, const float3x3& rhs )
{
	return lhs * inverse( rhs );
}

float3x3 operator/=( float3x3& lhs, const float3x3& rhs )
{
	return ( lhs = lhs / rhs );
}

float3 operator*( const float3x3& lhs, const float3& rhs )
{
	return float3(
		(float) dot( lhs[0], rhs ),
		(float) dot( lhs[1], rhs ),
		(float) dot( lhs[2], rhs )
	);
}

float3 operator*=( float3& lhs, const float3x3& rhs )
{
	return ( lhs = rhs * lhs );
}

// prefix
float3x3& operator++( float3x3& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	return lhs;
}

// postfix
float3x3& operator++( float3x3& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	return lhs;
}

// prefix
float3x3& operator--( float3x3& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	return lhs;
}

// postfix
float3x3& operator--( float3x3& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	return lhs;
}

bool3x3 operator<( const float3x3& lhs, const float3x3& rhs )
{
	return bool3x3(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2]
	);
}

bool3x3 operator<=( const float3x3& lhs, const float3x3& rhs )
{
	return bool3x3(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2]
	);
}

bool3x3 operator>( const float3x3& lhs, const float3x3& rhs )
{
	return bool3x3(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2]
	);
}

bool3x3 operator>=( const float3x3& lhs, const float3x3& rhs )
{
	return bool3x3(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2]
	);
}


// float3x4
float3x4 operator+( const float3x4& lhs, const float rhs )
{
	return float3x4(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs
	);
}

float3x4 operator+=( float3x4& lhs, const float rhs )
{
	return ( lhs = lhs + rhs );
}

float3x4 operator+( const float3x4& lhs, const float3x4& rhs )
{
	return float3x4(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2]
	);
}

float3x4 operator+=( float3x4& lhs, const float3x4& rhs )
{
	return ( lhs = lhs + rhs );
}

float3x4 operator-( const float3x4& lhs, const float rhs )
{
	return float3x4(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs
	);
}

float3x4 operator-=( float3x4& lhs, const float rhs )
{
	return ( lhs = lhs - rhs );
}

float3x4 operator-( const float3x4& lhs, const float3x4& rhs )
{
	return float3x4(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2]
	);
}

float3x4 operator-=( float3x4& lhs, const float3x4& rhs )
{
	return ( lhs = lhs - rhs );
}

float3x4 operator*( const float3x4& lhs, const float rhs )
{
	return float3x4(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs
	);
}

float3x4 operator*=( float3x4& lhs, const float rhs )
{
	return ( lhs = lhs * rhs );
}

float3x3 operator*( const float3x4& lhs, const float4x3& rhs )
{
	float4 row0 = lhs[0];
	float4 row1 = lhs[1];
	float4 row2 = lhs[2];

	float4 col0 = { rhs[0].x, rhs[1].x, rhs[2].x, rhs[3].x };
	float4 col1 = { rhs[0].y, rhs[1].y, rhs[2].y, rhs[3].y };
	float4 col2 = { rhs[0].z, rhs[1].z, rhs[2].z, rhs[3].z };

	return float3x3(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z + row0.w * col0.w,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z + row0.w * col1.w,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z + row0.w * col2.w,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z + row1.w * col0.w,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z + row1.w * col1.w,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z + row1.w * col2.w,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z + row2.w * col0.w,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z + row2.w * col1.w,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z + row2.w * col2.w
	);
}

float3x4 operator/( const float3x4& lhs, const float rhs )
{
	return float3x4(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs
	);
}

float3x4 operator/=( float3x4& lhs, const float rhs )
{
	return ( lhs = lhs / rhs );
}

float3x4 operator/( const float3x4& lhs, const float3x4& rhs )
{
	return float3x4(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2]
	);
}

// prefix
float3x4& operator++( float3x4& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	return lhs;
}

// postfix
float3x4& operator++( float3x4& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	return lhs;
}

// prefix
float3x4& operator--( float3x4& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	return lhs;
}

// postfix
float3x4& operator--( float3x4& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	return lhs;
}

bool3x4 operator<( const float3x4& lhs, const float3x4& rhs )
{
	return bool3x4(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2]
	);
}

bool3x4 operator<=( const float3x4& lhs, const float3x4& rhs )
{
	return bool3x4(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2]
	);
}

bool3x4 operator>( const float3x4& lhs, const float3x4& rhs )
{
	return bool3x4(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2]
	);
}

bool3x4 operator>=( const float3x4& lhs, const float3x4& rhs )
{
	return bool3x4(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2]
	);
}


// float4x2
float4x2 operator+( const float4x2& lhs, const float rhs )
{
	return float4x2(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs,
		lhs[3] + rhs
	);
}

float4x2 operator+=( float4x2& lhs, const float rhs )
{
	return ( lhs = lhs + rhs );
}

float4x2 operator+( const float4x2& lhs, const float4x2& rhs )
{
	return float4x2(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2],
		lhs[3] + rhs[3]
	);
}

float4x2 operator+=( float4x2& lhs, const float4x2& rhs )
{
	return ( lhs = lhs + rhs );
}

float4x2 operator-( const float4x2& lhs, const float rhs )
{
	return float4x2(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs,
		lhs[3] - rhs
	);
}

float4x2 operator-=( float4x2& lhs, const float rhs )
{
	return ( lhs = lhs - rhs );
}

float4x2 operator-( const float4x2& lhs, const float4x2& rhs )
{
	return float4x2(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2],
		lhs[3] - rhs[3]
	);
}

float4x2 operator-=( float4x2& lhs, const float4x2& rhs )
{
	return ( lhs = lhs - rhs );
}

float4x2 operator*( const float4x2& lhs, const float rhs )
{
	return float4x2(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs,
		lhs[3] * rhs
	);
}

float4x2 operator*=( float4x2& lhs, const float rhs )
{
	return ( lhs = lhs * rhs );
}

float4x4 operator*( const float4x2& lhs, const float2x4& rhs )
{
	float2 row0 = lhs[0];
	float2 row1 = lhs[1];
	float2 row2 = lhs[2];
	float2 row3 = lhs[3];

	float2 col0 = { rhs[0].x, rhs[1].x };
	float2 col1 = { rhs[0].y, rhs[1].y };
	float2 col2 = { rhs[0].z, rhs[1].z };
	float2 col3 = { rhs[0].w, rhs[1].w };

	return float4x4(
		row0.x * col0.x + row0.y * col0.y,
		row0.x * col1.x + row0.y * col1.y,
		row0.x * col2.x + row0.y * col2.y,
		row0.x * col3.x + row0.y * col3.y,

		row1.x * col0.x + row1.y * col0.y,
		row1.x * col1.x + row1.y * col1.y,
		row1.x * col2.x + row1.y * col2.y,
		row1.x * col3.x + row1.y * col3.y,

		row2.x * col0.x + row2.y * col0.y,
		row2.x * col1.x + row2.y * col1.y,
		row2.x * col2.x + row2.y * col2.y,
		row2.x * col3.x + row2.y * col3.y,

		row3.x * col0.x + row3.y * col0.y,
		row3.x * col1.x + row3.y * col1.y,
		row3.x * col2.x + row3.y * col2.y,
		row3.x * col3.x + row3.y * col3.y
	);
}

float4x2 operator/( const float4x2& lhs, const float rhs )
{
	return float4x2(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs,
		lhs[3] / rhs
	);
}

float4x2 operator/=( float4x2& lhs, const float rhs )
{
	return ( lhs = lhs / rhs );
}

float4x2 operator/( const float4x2& lhs, const float4x2& rhs )
{
	return float4x2(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2],
		lhs[3] / rhs[3]
	);
}

// prefix
float4x2& operator++( float4x2& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	++lhs[3];
	return lhs;
}

// postfix
float4x2& operator++( float4x2& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	lhs[3]++;
	return lhs;
}

// prefix
float4x2& operator--( float4x2& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	--lhs[3];
	return lhs;
}

// postfix
float4x2& operator--( float4x2& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	lhs[3]--;
	return lhs;
}

bool4x2 operator<( const float4x2& lhs, const float4x2& rhs )
{
	return bool4x2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2],
		lhs[3] < rhs[3]
	);
}

bool4x2 operator<=( const float4x2& lhs, const float4x2& rhs )
{
	return bool4x2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2],
		lhs[3] <= rhs[3]
	);
}

bool4x2 operator>( const float4x2& lhs, const float4x2& rhs )
{
	return bool4x2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2],
		lhs[3] > rhs[3]
	);
}

bool4x2 operator>=( const float4x2& lhs, const float4x2& rhs )
{
	return bool4x2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2],
		lhs[3] >= rhs[3]
	);
}


// float4x3
float4x3 operator+( const float4x3& lhs, const float rhs )
{
	return float4x3(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs,
		lhs[3] + rhs
	);
}

float4x3 operator+=( float4x3& lhs, const float rhs )
{
	return ( lhs = lhs + rhs );
}

float4x3 operator+( const float4x3& lhs, const float4x3& rhs )
{
	return float4x3(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2],
		lhs[3] + rhs[3]
	);
}

float4x3 operator+=( float4x3& lhs, const float4x3& rhs )
{
	return ( lhs = lhs + rhs );
}

float4x3 operator-( const float4x3& lhs, const float rhs )
{
	return float4x3(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs,
		lhs[3] - rhs
	);
}

float4x3 operator-=( float4x3& lhs, const float rhs )
{
	return ( lhs = lhs - rhs );
}

float4x3 operator-( const float4x3& lhs, const float4x3& rhs )
{
	return float4x3(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2],
		lhs[3] - rhs[3]
	);
}

float4x3 operator-=( float4x3& lhs, const float4x3& rhs )
{
	return ( lhs = lhs - rhs );
}

float4x3 operator*( const float4x3& lhs, const float rhs )
{
	return float4x3(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs,
		lhs[3] * rhs
	);
}

float4x3 operator*=( float4x3& lhs, const float rhs )
{
	return ( lhs = lhs * rhs );
}

float4x4 operator*( const float4x3& lhs, const float3x4& rhs )
{
	float3 row0 = lhs[0];
	float3 row1 = lhs[1];
	float3 row2 = lhs[2];
	float3 row3 = lhs[3];

	float3 col0 = { rhs[0].x, rhs[1].x, rhs[2].x };
	float3 col1 = { rhs[0].y, rhs[1].y, rhs[2].y };
	float3 col2 = { rhs[0].z, rhs[1].z, rhs[2].z };
	float3 col3 = { rhs[0].w, rhs[1].w, rhs[2].w };

	return float4x4(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z,
		row0.x * col3.x + row0.y * col3.y + row0.z * col3.z,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z,
		row1.x * col3.x + row1.y * col3.y + row1.z * col3.z,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z,
		row2.x * col3.x + row2.y * col3.y + row2.z * col3.z,

		row3.x * col0.x + row3.y * col0.y + row3.z * col0.z,
		row3.x * col1.x + row3.y * col1.y + row3.z * col1.z,
		row3.x * col2.x + row3.y * col2.y + row3.z * col2.z,
		row3.x * col3.x + row3.y * col3.y + row3.z * col3.z
	);
}

float4x3 operator/( const float4x3& lhs, const float rhs )
{
	return float4x3(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs,
		lhs[3] / rhs
	);
}

float4x3 operator/=( float4x3& lhs, const float rhs )
{
	return ( lhs = lhs / rhs );
}

float4x3 operator/( const float4x3& lhs, const float4x3& rhs )
{
	return float4x3(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2],
		lhs[3] / rhs[3]
	);
}

// prefix
float4x3& operator++( float4x3& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	++lhs[3];
	return lhs;
}

// postfix
float4x3& operator++( float4x3& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	lhs[3]++;
	return lhs;
}

// prefix
float4x3& operator--( float4x3& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	--lhs[3];
	return lhs;
}

// postfix
float4x3& operator--( float4x3& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	lhs[3]--;
	return lhs;
}

bool4x3 operator<( const float4x3& lhs, const float4x3& rhs )
{
	return bool4x3(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2],
		lhs[3] < rhs[3]
	);
}

bool4x3 operator<=( const float4x3& lhs, const float4x3& rhs )
{
	return bool4x3(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2],
		lhs[3] <= rhs[3]
	);
}

bool4x3 operator>( const float4x3& lhs, const float4x3& rhs )
{
	return bool4x3(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2],
		lhs[3] > rhs[3]
	);
}

bool4x3 operator>=( const float4x3& lhs, const float4x3& rhs )
{
	return bool4x3(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2],
		lhs[3] >= rhs[3]
	);
}


// float4x4
float4x4 operator+( const float4x4& lhs, const float rhs )
{
	return float4x4(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs,
		lhs[3] + rhs
	);
}

float4x4 operator+=( float4x4& lhs, const float rhs )
{
	return ( lhs = lhs + rhs );
}

float4x4 operator+( const float4x4& lhs, const float4x4& rhs )
{
	return float4x4(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2],
		lhs[3] + rhs[3]
	);
}

float4x4 operator+=( float4x4& lhs, const float4x4& rhs )
{
	return ( lhs = lhs + rhs );
}

float4x4 operator-( const float4x4& lhs, const float rhs )
{
	return float4x4(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs,
		lhs[3] - rhs
	);
}

float4x4 operator-=( float4x4& lhs, const float rhs )
{
	return ( lhs = lhs - rhs );
}

float4x4 operator-( const float4x4& lhs, const float4x4& rhs )
{
	return float4x4(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2],
		lhs[3] - rhs[3]
	);
}

float4x4 operator-=( float4x4& lhs, const float4x4& rhs )
{
	return ( lhs = lhs - rhs );
}

float4x4 operator*( const float4x4& lhs, const float rhs )
{
	return float4x4(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs,
		lhs[3] * rhs
	);
}

float4x4 operator*=( float4x4& lhs, const float rhs )
{
	return ( lhs = lhs * rhs );
}

float4x4 operator*( const float4x4& lhs, const float4x4& rhs )
{
	float4 row0 = lhs[0];
	float4 row1 = lhs[1];
	float4 row2 = lhs[2];
	float4 row3 = lhs[3];

	float4 col0 = { rhs[0].x, rhs[1].x, rhs[2].x, rhs[3].x };
	float4 col1 = { rhs[0].y, rhs[1].y, rhs[2].y, rhs[3].y };
	float4 col2 = { rhs[0].z, rhs[1].z, rhs[2].z, rhs[3].z };
	float4 col3 = { rhs[0].w, rhs[1].w, rhs[2].w, rhs[3].w };

	return float4x4(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z + row0.w * col0.w,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z + row0.w * col1.w,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z + row0.w * col2.w,
		row0.x * col3.x + row0.y * col3.y + row0.z * col3.z + row0.w * col3.w,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z + row1.w * col0.w,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z + row1.w * col1.w,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z + row1.w * col2.w,
		row1.x * col3.x + row1.y * col3.y + row1.z * col3.z + row1.w * col3.w,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z + row2.w * col0.w,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z + row2.w * col1.w,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z + row2.w * col2.w,
		row2.x * col3.x + row2.y * col3.y + row2.z * col3.z + row2.w * col3.w,

		row3.x * col0.x + row3.y * col0.y + row3.z * col0.z + row3.w * col0.w,
		row3.x * col1.x + row3.y * col1.y + row3.z * col1.z + row3.w * col1.w,
		row3.x * col2.x + row3.y * col2.y + row3.z * col2.z + row3.w * col2.w,
		row3.x * col3.x + row3.y * col3.y + row3.z * col3.z + row3.w * col3.w
	);
}

float4x4 operator*=( float4x4& lhs, const float4x4& rhs )
{
	return ( lhs = lhs * rhs );
}

float4x4 operator/( const float4x4& lhs, const float rhs )
{
	return float4x4(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs,
		lhs[3] / rhs
	);
}

float4x4 operator/=( float4x4& lhs, const float rhs )
{
	return ( lhs = lhs / rhs );
}

float4x4 operator/( const float4x4& lhs, const float4x4& rhs )
{
	return lhs * inverse( rhs );
}

float4x4 operator/=( float4x4& lhs, const float4x4& rhs )
{
	return ( lhs = lhs / rhs );
}

float4 operator*( const float4x4& lhs, const float4& rhs )
{
	return float4(
		(float) dot( lhs[0], rhs ),
		(float) dot( lhs[1], rhs ),
		(float) dot( lhs[2], rhs ),
		(float) dot( lhs[3], rhs )
	);
}

float4 operator*=( float4& lhs, const float4x4& rhs )
{
	return ( lhs = rhs * lhs );
}

// prefix
float4x4& operator++( float4x4& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	++lhs[3];
	return lhs;
}

// postfix
float4x4& operator++( float4x4& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	lhs[3]++;
	return lhs;
}

// prefix
float4x4& operator--( float4x4& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	--lhs[3];
	return lhs;
}

// postfix
float4x4& operator--( float4x4& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	lhs[3]--;
	return lhs;
}

bool4x4 operator<( const float4x4& lhs, const float4x4& rhs )
{
	return bool4x4(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2],
		lhs[3] < rhs[3]
	);
}

bool4x4 operator<=( const float4x4& lhs, const float4x4& rhs )
{
	return bool4x4(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2],
		lhs[3] <= rhs[3]
	);
}

bool4x4 operator>( const float4x4& lhs, const float4x4& rhs )
{
	return bool4x4(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2],
		lhs[3] > rhs[3]
	);
}

bool4x4 operator>=( const float4x4& lhs, const float4x4& rhs )
{
	return bool4x4(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2],
		lhs[3] >= rhs[3]
	);
}


// double2x2
double2x2 operator+( const double2x2& lhs, const double rhs )
{
	return double2x2(
		lhs[0] + rhs,
		lhs[1] + rhs
	);
}

double2x2 operator+=( double2x2& lhs, const double rhs )
{
	return ( lhs = lhs + rhs );
}

double2x2 operator+( const double2x2& lhs, const double2x2& rhs )
{
	return double2x2(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1]
	);
}

double2x2 operator+=( double2x2& lhs, const double2x2& rhs )
{
	return ( lhs = lhs + rhs );
}

double2x2 operator-( const double2x2& lhs, const double rhs )
{
	return double2x2(
		lhs[0] - rhs,
		lhs[1] - rhs
	);
}

double2x2 operator-=( double2x2& lhs, const double rhs )
{
	return ( lhs = lhs - rhs );
}

double2x2 operator-( const double2x2& lhs, const double2x2& rhs )
{
	return double2x2(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1]
	);
}

double2x2 operator-=( double2x2& lhs, const double2x2& rhs )
{
	return ( lhs = lhs - rhs );
}

double2x2 operator*( const double2x2& lhs, const double rhs )
{
	return double2x2(
		lhs[0] * rhs,
		lhs[1] * rhs
	);
}

double2x2 operator*=( double2x2& lhs, const double rhs )
{
	return ( lhs = lhs * rhs );
}

double2x2 operator*( const double2x2& lhs, const double2x2& rhs )
{
	double2 row0 = lhs[0];
	double2 row1 = lhs[1];

	double2 col0 = { rhs[0].x, rhs[1].x };
	double2 col1 = { rhs[0].y, rhs[1].y };

	return double2x2(
		row0.x * col0.x + row0.y * col0.y,
		row0.x * col1.x + row0.y * col1.y,

		row1.x * col0.x + row1.y * col0.y,
		row1.x * col1.x + row1.y * col1.y
	);
}

double2x2 operator*=( double2x2& lhs, const double2x2& rhs )
{
	return ( lhs = lhs * rhs );
}

double2x2 operator/( const double2x2& lhs, const double rhs )
{
	return double2x2(
		lhs[0] / rhs,
		lhs[1] / rhs
	);
}

double2x2 operator/=( double2x2& lhs, const double rhs )
{
	return ( lhs = lhs / rhs );
}

double2x2 operator/( const double2x2& lhs, const double2x2& rhs )
{
	return lhs * inverse( rhs );
}

double2x2 operator/=( double2x2& lhs, const double2x2& rhs )
{
	return ( lhs = lhs / rhs );
}

double2 operator*( const double2x2& lhs, const double2& rhs )
{
	return double2(
		(double) dot( lhs[0], rhs ),
		(double) dot( lhs[1], rhs )
	);
}

double2 operator*=( double2& lhs, const double2x2& rhs )
{
	return ( lhs = rhs * lhs );
}

// prefix
double2x2& operator++( double2x2& lhs )
{
	++lhs[0];
	++lhs[1];
	return lhs;
}

// postfix
double2x2& operator++( double2x2& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	return lhs;
}

// prefix
double2x2& operator--( double2x2& lhs )
{
	--lhs[0];
	--lhs[1];
	return lhs;
}

// postfix
double2x2& operator--( double2x2& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	return lhs;
}

bool2x2 operator<( const double2x2& lhs, const double2x2& rhs )
{
	return bool2x2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2x2 operator<=( const double2x2& lhs, const double2x2& rhs )
{
	return bool2x2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2x2 operator>( const double2x2& lhs, const double2x2& rhs )
{
	return bool2x2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2x2 operator>=( const double2x2& lhs, const double2x2& rhs )
{
	return bool2x2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}


// double2x3
double2x3 operator+( const double2x3& lhs, const double rhs )
{
	return double2x3(
		lhs[0] + rhs,
		lhs[1] + rhs
	);
}

double2x3 operator+=( double2x3& lhs, const double rhs )
{
	return ( lhs = lhs + rhs );
}

double2x3 operator+( const double2x3& lhs, const double2x3& rhs )
{
	return double2x3(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1]
	);
}

double2x3 operator+=( double2x3& lhs, const double2x3& rhs )
{
	return ( lhs = lhs + rhs );
}

double2x3 operator-( const double2x3& lhs, const double rhs )
{
	return double2x3(
		lhs[0] - rhs,
		lhs[1] - rhs
	);
}

double2x3 operator-=( double2x3& lhs, const double rhs )
{
	return ( lhs = lhs - rhs );
}

double2x3 operator-( const double2x3& lhs, const double2x3& rhs )
{
	return double2x3(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1]
	);
}

double2x3 operator-=( double2x3& lhs, const double2x3& rhs )
{
	return ( lhs = lhs - rhs );
}

double2x3 operator*( const double2x3& lhs, const double rhs )
{
	return double2x3(
		lhs[0] * rhs,
		lhs[1] * rhs
	);
}

double2x3 operator*=( double2x3& lhs, const double rhs )
{
	return ( lhs = lhs * rhs );
}

double2x2 operator*( const double2x3& lhs, const double3x2& rhs )
{
	double3 row0 = lhs[0];
	double3 row1 = lhs[1];

	double3 col0 = { rhs[0].x, rhs[1].x, rhs[2].x };
	double3 col1 = { rhs[0].y, rhs[1].y, rhs[2].y };

	return double2x2(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z
	);
}

double2x3 operator/( const double2x3& lhs, const double rhs )
{
	return double2x3(
		lhs[0] / rhs,
		lhs[1] / rhs
	);
}

double2x3 operator/=( double2x3& lhs, const double rhs )
{
	return ( lhs = lhs / rhs );
}

double2x3 operator/( const double2x3& lhs, const double2x3& rhs )
{
	return double2x3(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1]
	);
}

// prefix
double2x3& operator++( double2x3& lhs )
{
	++lhs[0];
	++lhs[1];
	return lhs;
}

// postfix
double2x3& operator++( double2x3& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	return lhs;
}

// prefix
double2x3& operator--( double2x3& lhs )
{
	--lhs[0];
	--lhs[1];
	return lhs;
}

// postfix
double2x3& operator--( double2x3& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	return lhs;
}

bool2x3 operator<( const double2x3& lhs, const double2x3& rhs )
{
	return bool2x3(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2x3 operator<=( const double2x3& lhs, const double2x3& rhs )
{
	return bool2x3(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2x3 operator>( const double2x3& lhs, const double2x3& rhs )
{
	return bool2x3(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2x3 operator>=( const double2x3& lhs, const double2x3& rhs )
{
	return bool2x3(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}


// double2x4
double2x4 operator+( const double2x4& lhs, const double rhs )
{
	return double2x4(
		lhs[0] + rhs,
		lhs[1] + rhs
	);
}

double2x4 operator+=( double2x4& lhs, const double rhs )
{
	return ( lhs = lhs + rhs );
}

double2x4 operator+( const double2x4& lhs, const double2x4& rhs )
{
	return double2x4(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1]
	);
}

double2x4 operator+=( double2x4& lhs, const double2x4& rhs )
{
	return ( lhs = lhs + rhs );
}

double2x4 operator-( const double2x4& lhs, const double rhs )
{
	return double2x4(
		lhs[0] - rhs,
		lhs[1] - rhs
	);
}

double2x4 operator-=( double2x4& lhs, const double rhs )
{
	return ( lhs = lhs - rhs );
}

double2x4 operator-( const double2x4& lhs, const double2x4& rhs )
{
	return double2x4(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1]
	);
}

double2x4 operator-=( double2x4& lhs, const double2x4& rhs )
{
	return ( lhs = lhs - rhs );
}

double2x4 operator*( const double2x4& lhs, const double rhs )
{
	return double2x4(
		lhs[0] * rhs,
		lhs[1] * rhs
	);
}

double2x4 operator*=( double2x4& lhs, const double rhs )
{
	return ( lhs = lhs * rhs );
}

double2x2 operator*( const double2x4& lhs, const double4x2& rhs )
{
	double4 row0 = lhs[0];
	double4 row1 = lhs[1];

	double4 col0 = { rhs[0].x, rhs[1].x, rhs[2].x, rhs[3].x };
	double4 col1 = { rhs[0].y, rhs[1].y, rhs[2].y, rhs[3].y };

	return double2x2(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z + row0.w * col0.w,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z + row0.w * col1.w,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z + row1.w * col0.w,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z + row1.w * col1.w
	);
}

double2x4 operator/( const double2x4& lhs, const double rhs )
{
	return double2x4(
		lhs[0] / rhs,
		lhs[1] / rhs
	);
}

double2x4 operator/=( double2x4& lhs, const double rhs )
{
	return ( lhs = lhs / rhs );
}

double2x4 operator/( const double2x4& lhs, const double2x4& rhs )
{
	return double2x4(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1]
	);
}

// prefix
double2x4& operator++( double2x4& lhs )
{
	++lhs[0];
	++lhs[1];
	return lhs;
}

// postfix
double2x4& operator++( double2x4& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	return lhs;
}

// prefix
double2x4& operator--( double2x4& lhs )
{
	--lhs[0];
	--lhs[1];
	return lhs;
}

// postfix
double2x4& operator--( double2x4& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	return lhs;
}

bool2x4 operator<( const double2x4& lhs, const double2x4& rhs )
{
	return bool2x4(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1]
	);
}

bool2x4 operator<=( const double2x4& lhs, const double2x4& rhs )
{
	return bool2x4(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1]
	);
}

bool2x4 operator>( const double2x4& lhs, const double2x4& rhs )
{
	return bool2x4(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1]
	);
}

bool2x4 operator>=( const double2x4& lhs, const double2x4& rhs )
{
	return bool2x4(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1]
	);
}


// double3x2
double3x2 operator+( const double3x2& lhs, const double rhs )
{
	return double3x2(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs
	);
}

double3x2 operator+=( double3x2& lhs, const double rhs )
{
	return ( lhs = lhs + rhs );
}

double3x2 operator+( const double3x2& lhs, const double3x2& rhs )
{
	return double3x2(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2]
	);
}

double3x2 operator+=( double3x2& lhs, const double3x2& rhs )
{
	return ( lhs = lhs + rhs );
}

double3x2 operator-( const double3x2& lhs, const double rhs )
{
	return double3x2(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs
	);
}

double3x2 operator-=( double3x2& lhs, const double rhs )
{
	return ( lhs = lhs - rhs );
}

double3x2 operator-( const double3x2& lhs, const double3x2& rhs )
{
	return double3x2(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2]
	);
}

double3x2 operator-=( double3x2& lhs, const double3x2& rhs )
{
	return ( lhs = lhs - rhs );
}

double3x2 operator*( const double3x2& lhs, const double rhs )
{
	return double3x2(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs
	);
}

double3x2 operator*=( double3x2& lhs, const double rhs )
{
	return ( lhs = lhs * rhs );
}

double3x3 operator*( const double3x2& lhs, const double2x3& rhs )
{
	double2 row0 = lhs[0];
	double2 row1 = lhs[1];
	double2 row2 = lhs[2];

	double2 col0 = { rhs[0].x, rhs[1].x };
	double2 col1 = { rhs[0].y, rhs[1].y };
	double2 col2 = { rhs[0].z, rhs[1].z };

	return double3x3(
		row0.x * col0.x + row0.y * col0.y,
		row0.x * col1.x + row0.y * col1.y,
		row0.x * col2.x + row0.y * col2.y,

		row1.x * col0.x + row1.y * col0.y,
		row1.x * col1.x + row1.y * col1.y,
		row1.x * col2.x + row1.y * col2.y,

		row2.x * col0.x + row2.y * col0.y,
		row2.x * col1.x + row2.y * col1.y,
		row2.x * col2.x + row2.y * col2.y
	);
}

double3x2 operator/( const double3x2& lhs, const double rhs )
{
	return double3x2(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs
	);
}

double3x2 operator/=( double3x2& lhs, const double rhs )
{
	return ( lhs = lhs / rhs );
}

double3x2 operator/( const double3x2& lhs, const double3x2& rhs )
{
	return double3x2(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2]
	);
}

// prefix
double3x2& operator++( double3x2& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	return lhs;
}

// postfix
double3x2& operator++( double3x2& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	return lhs;
}

// prefix
double3x2& operator--( double3x2& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	return lhs;
}

// postfix
double3x2& operator--( double3x2& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	return lhs;
}

bool3x2 operator<( const double3x2& lhs, const double3x2& rhs )
{
	return bool3x2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2]
	);
}

bool3x2 operator<=( const double3x2& lhs, const double3x2& rhs )
{
	return bool3x2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2]
	);
}

bool3x2 operator>( const double3x2& lhs, const double3x2& rhs )
{
	return bool3x2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2]
	);
}

bool3x2 operator>=( const double3x2& lhs, const double3x2& rhs )
{
	return bool3x2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2]
	);
}


// double3x3
double3x3 operator+( const double3x3& lhs, const double rhs )
{
	return double3x3(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs
	);
}

double3x3 operator+=( double3x3& lhs, const double rhs )
{
	return ( lhs = lhs + rhs );
}

double3x3 operator+( const double3x3& lhs, const double3x3& rhs )
{
	return double3x3(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2]
	);
}

double3x3 operator+=( double3x3& lhs, const double3x3& rhs )
{
	return ( lhs = lhs + rhs );
}

double3x3 operator-( const double3x3& lhs, const double rhs )
{
	return double3x3(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs
	);
}

double3x3 operator-=( double3x3& lhs, const double rhs )
{
	return ( lhs = lhs - rhs );
}

double3x3 operator-( const double3x3& lhs, const double3x3& rhs )
{
	return double3x3(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2]
	);
}

double3x3 operator-=( double3x3& lhs, const double3x3& rhs )
{
	return ( lhs = lhs - rhs );
}

double3x3 operator*( const double3x3& lhs, const double rhs )
{
	return double3x3(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs
	);
}

double3x3 operator*=( double3x3& lhs, const double rhs )
{
	return ( lhs = lhs * rhs );
}

double3x3 operator*( const double3x3& lhs, const double3x3& rhs )
{
	double3 row0 = lhs[0];
	double3 row1 = lhs[1];
	double3 row2 = lhs[2];

	double3 col0 = { rhs[0].x, rhs[1].x, rhs[2].x };
	double3 col1 = { rhs[0].y, rhs[1].y, rhs[2].y };
	double3 col2 = { rhs[0].z, rhs[1].z, rhs[2].z };

	return double3x3(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z
	);
}

double3x3 operator*=( double3x3& lhs, const double3x3& rhs )
{
	return ( lhs = lhs * rhs );
}

double3x3 operator/( const double3x3& lhs, const double rhs )
{
	return double3x3(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs
	);
}

double3x3 operator/=( double3x3& lhs, const double rhs )
{
	return ( lhs = lhs / rhs );
}

double3x3 operator/( const double3x3& lhs, const double3x3& rhs )
{
	return lhs * inverse( rhs );
}

double3x3 operator/=( double3x3& lhs, const double3x3& rhs )
{
	return ( lhs = lhs / rhs );
}

double3 operator*( const double3x3& lhs, const double3& rhs )
{
	return double3(
		(double) dot( lhs[0], rhs ),
		(double) dot( lhs[1], rhs ),
		(double) dot( lhs[2], rhs )
	);
}

double3 operator*=( double3& lhs, const double3x3& rhs )
{
	return ( lhs = rhs * lhs );
}

// prefix
double3x3& operator++( double3x3& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	return lhs;
}

// postfix
double3x3& operator++( double3x3& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	return lhs;
}

// prefix
double3x3& operator--( double3x3& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	return lhs;
}

// postfix
double3x3& operator--( double3x3& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	return lhs;
}

bool3x3 operator<( const double3x3& lhs, const double3x3& rhs )
{
	return bool3x3(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2]
	);
}

bool3x3 operator<=( const double3x3& lhs, const double3x3& rhs )
{
	return bool3x3(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2]
	);
}

bool3x3 operator>( const double3x3& lhs, const double3x3& rhs )
{
	return bool3x3(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2]
	);
}

bool3x3 operator>=( const double3x3& lhs, const double3x3& rhs )
{
	return bool3x3(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2]
	);
}


// double3x4
double3x4 operator+( const double3x4& lhs, const double rhs )
{
	return double3x4(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs
	);
}

double3x4 operator+=( double3x4& lhs, const double rhs )
{
	return ( lhs = lhs + rhs );
}

double3x4 operator+( const double3x4& lhs, const double3x4& rhs )
{
	return double3x4(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2]
	);
}

double3x4 operator+=( double3x4& lhs, const double3x4& rhs )
{
	return ( lhs = lhs + rhs );
}

double3x4 operator-( const double3x4& lhs, const double rhs )
{
	return double3x4(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs
	);
}

double3x4 operator-=( double3x4& lhs, const double rhs )
{
	return ( lhs = lhs - rhs );
}

double3x4 operator-( const double3x4& lhs, const double3x4& rhs )
{
	return double3x4(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2]
	);
}

double3x4 operator-=( double3x4& lhs, const double3x4& rhs )
{
	return ( lhs = lhs - rhs );
}

double3x4 operator*( const double3x4& lhs, const double rhs )
{
	return double3x4(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs
	);
}

double3x4 operator*=( double3x4& lhs, const double rhs )
{
	return ( lhs = lhs * rhs );
}

double3x3 operator*( const double3x4& lhs, const double4x3& rhs )
{
	double4 row0 = lhs[0];
	double4 row1 = lhs[1];
	double4 row2 = lhs[2];

	double4 col0 = { rhs[0].x, rhs[1].x, rhs[2].x, rhs[3].x };
	double4 col1 = { rhs[0].y, rhs[1].y, rhs[2].y, rhs[3].y };
	double4 col2 = { rhs[0].z, rhs[1].z, rhs[2].z, rhs[3].z };

	return double3x3(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z + row0.w * col0.w,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z + row0.w * col1.w,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z + row0.w * col2.w,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z + row1.w * col0.w,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z + row1.w * col1.w,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z + row1.w * col2.w,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z + row2.w * col0.w,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z + row2.w * col1.w,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z + row2.w * col2.w
	);
}

double3x4 operator/( const double3x4& lhs, const double rhs )
{
	return double3x4(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs
	);
}

double3x4 operator/=( double3x4& lhs, const double rhs )
{
	return ( lhs = lhs / rhs );
}

double3x4 operator/( const double3x4& lhs, const double3x4& rhs )
{
	return double3x4(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2]
	);
}

// prefix
double3x4& operator++( double3x4& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	return lhs;
}

// postfix
double3x4& operator++( double3x4& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	return lhs;
}

// prefix
double3x4& operator--( double3x4& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	return lhs;
}

// postfix
double3x4& operator--( double3x4& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	return lhs;
}

bool3x4 operator<( const double3x4& lhs, const double3x4& rhs )
{
	return bool3x4(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2]
	);
}

bool3x4 operator<=( const double3x4& lhs, const double3x4& rhs )
{
	return bool3x4(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2]
	);
}

bool3x4 operator>( const double3x4& lhs, const double3x4& rhs )
{
	return bool3x4(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2]
	);
}

bool3x4 operator>=( const double3x4& lhs, const double3x4& rhs )
{
	return bool3x4(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2]
	);
}


// double4x2
double4x2 operator+( const double4x2& lhs, const double rhs )
{
	return double4x2(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs,
		lhs[3] + rhs
	);
}

double4x2 operator+=( double4x2& lhs, const double rhs )
{
	return ( lhs = lhs + rhs );
}

double4x2 operator+( const double4x2& lhs, const double4x2& rhs )
{
	return double4x2(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2],
		lhs[3] + rhs[3]
	);
}

double4x2 operator+=( double4x2& lhs, const double4x2& rhs )
{
	return ( lhs = lhs + rhs );
}

double4x2 operator-( const double4x2& lhs, const double rhs )
{
	return double4x2(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs,
		lhs[3] - rhs
	);
}

double4x2 operator-=( double4x2& lhs, const double rhs )
{
	return ( lhs = lhs - rhs );
}

double4x2 operator-( const double4x2& lhs, const double4x2& rhs )
{
	return double4x2(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2],
		lhs[3] - rhs[3]
	);
}

double4x2 operator-=( double4x2& lhs, const double4x2& rhs )
{
	return ( lhs = lhs - rhs );
}

double4x2 operator*( const double4x2& lhs, const double rhs )
{
	return double4x2(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs,
		lhs[3] * rhs
	);
}

double4x2 operator*=( double4x2& lhs, const double rhs )
{
	return ( lhs = lhs * rhs );
}

double4x4 operator*( const double4x2& lhs, const double2x4& rhs )
{
	double2 row0 = lhs[0];
	double2 row1 = lhs[1];
	double2 row2 = lhs[2];
	double2 row3 = lhs[3];

	double2 col0 = { rhs[0].x, rhs[1].x };
	double2 col1 = { rhs[0].y, rhs[1].y };
	double2 col2 = { rhs[0].z, rhs[1].z };
	double2 col3 = { rhs[0].w, rhs[1].w };

	return double4x4(
		row0.x * col0.x + row0.y * col0.y,
		row0.x * col1.x + row0.y * col1.y,
		row0.x * col2.x + row0.y * col2.y,
		row0.x * col3.x + row0.y * col3.y,

		row1.x * col0.x + row1.y * col0.y,
		row1.x * col1.x + row1.y * col1.y,
		row1.x * col2.x + row1.y * col2.y,
		row1.x * col3.x + row1.y * col3.y,

		row2.x * col0.x + row2.y * col0.y,
		row2.x * col1.x + row2.y * col1.y,
		row2.x * col2.x + row2.y * col2.y,
		row2.x * col3.x + row2.y * col3.y,

		row3.x * col0.x + row3.y * col0.y,
		row3.x * col1.x + row3.y * col1.y,
		row3.x * col2.x + row3.y * col2.y,
		row3.x * col3.x + row3.y * col3.y
	);
}

double4x2 operator/( const double4x2& lhs, const double rhs )
{
	return double4x2(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs,
		lhs[3] / rhs
	);
}

double4x2 operator/=( double4x2& lhs, const double rhs )
{
	return ( lhs = lhs / rhs );
}

double4x2 operator/( const double4x2& lhs, const double4x2& rhs )
{
	return double4x2(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2],
		lhs[3] / rhs[3]
	);
}

// prefix
double4x2& operator++( double4x2& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	++lhs[3];
	return lhs;
}

// postfix
double4x2& operator++( double4x2& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	lhs[3]++;
	return lhs;
}

// prefix
double4x2& operator--( double4x2& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	--lhs[3];
	return lhs;
}

// postfix
double4x2& operator--( double4x2& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	lhs[3]--;
	return lhs;
}

bool4x2 operator<( const double4x2& lhs, const double4x2& rhs )
{
	return bool4x2(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2],
		lhs[3] < rhs[3]
	);
}

bool4x2 operator<=( const double4x2& lhs, const double4x2& rhs )
{
	return bool4x2(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2],
		lhs[3] <= rhs[3]
	);
}

bool4x2 operator>( const double4x2& lhs, const double4x2& rhs )
{
	return bool4x2(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2],
		lhs[3] > rhs[3]
	);
}

bool4x2 operator>=( const double4x2& lhs, const double4x2& rhs )
{
	return bool4x2(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2],
		lhs[3] >= rhs[3]
	);
}


// double4x3
double4x3 operator+( const double4x3& lhs, const double rhs )
{
	return double4x3(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs,
		lhs[3] + rhs
	);
}

double4x3 operator+=( double4x3& lhs, const double rhs )
{
	return ( lhs = lhs + rhs );
}

double4x3 operator+( const double4x3& lhs, const double4x3& rhs )
{
	return double4x3(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2],
		lhs[3] + rhs[3]
	);
}

double4x3 operator+=( double4x3& lhs, const double4x3& rhs )
{
	return ( lhs = lhs + rhs );
}

double4x3 operator-( const double4x3& lhs, const double rhs )
{
	return double4x3(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs,
		lhs[3] - rhs
	);
}

double4x3 operator-=( double4x3& lhs, const double rhs )
{
	return ( lhs = lhs - rhs );
}

double4x3 operator-( const double4x3& lhs, const double4x3& rhs )
{
	return double4x3(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2],
		lhs[3] - rhs[3]
	);
}

double4x3 operator-=( double4x3& lhs, const double4x3& rhs )
{
	return ( lhs = lhs - rhs );
}

double4x3 operator*( const double4x3& lhs, const double rhs )
{
	return double4x3(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs,
		lhs[3] * rhs
	);
}

double4x3 operator*=( double4x3& lhs, const double rhs )
{
	return ( lhs = lhs * rhs );
}

double4x4 operator*( const double4x3& lhs, const double3x4& rhs )
{
	double3 row0 = lhs[0];
	double3 row1 = lhs[1];
	double3 row2 = lhs[2];
	double3 row3 = lhs[3];

	double3 col0 = { rhs[0].x, rhs[1].x, rhs[2].x };
	double3 col1 = { rhs[0].y, rhs[1].y, rhs[2].y };
	double3 col2 = { rhs[0].z, rhs[1].z, rhs[2].z };
	double3 col3 = { rhs[0].w, rhs[1].w, rhs[2].w };

	return double4x4(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z,
		row0.x * col3.x + row0.y * col3.y + row0.z * col3.z,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z,
		row1.x * col3.x + row1.y * col3.y + row1.z * col3.z,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z,
		row2.x * col3.x + row2.y * col3.y + row2.z * col3.z,

		row3.x * col0.x + row3.y * col0.y + row3.z * col0.z,
		row3.x * col1.x + row3.y * col1.y + row3.z * col1.z,
		row3.x * col2.x + row3.y * col2.y + row3.z * col2.z,
		row3.x * col3.x + row3.y * col3.y + row3.z * col3.z
	);
}

double4x3 operator/( const double4x3& lhs, const double rhs )
{
	return double4x3(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs,
		lhs[3] / rhs
	);
}

double4x3 operator/=( double4x3& lhs, const double rhs )
{
	return ( lhs = lhs / rhs );
}

double4x3 operator/( const double4x3& lhs, const double4x3& rhs )
{
	return double4x3(
		lhs[0] / rhs[0],
		lhs[1] / rhs[1],
		lhs[2] / rhs[2],
		lhs[3] / rhs[3]
	);
}

// prefix
double4x3& operator++( double4x3& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	++lhs[3];
	return lhs;
}

// postfix
double4x3& operator++( double4x3& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	lhs[3]++;
	return lhs;
}

// prefix
double4x3& operator--( double4x3& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	--lhs[3];
	return lhs;
}

// postfix
double4x3& operator--( double4x3& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	lhs[3]--;
	return lhs;
}

bool4x3 operator<( const double4x3& lhs, const double4x3& rhs )
{
	return bool4x3(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2],
		lhs[3] < rhs[3]
	);
}

bool4x3 operator<=( const double4x3& lhs, const double4x3& rhs )
{
	return bool4x3(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2],
		lhs[3] <= rhs[3]
	);
}

bool4x3 operator>( const double4x3& lhs, const double4x3& rhs )
{
	return bool4x3(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2],
		lhs[3] > rhs[3]
	);
}

bool4x3 operator>=( const double4x3& lhs, const double4x3& rhs )
{
	return bool4x3(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2],
		lhs[3] >= rhs[3]
	);
}


// double4x4
double4x4 operator+( const double4x4& lhs, const double rhs )
{
	return double4x4(
		lhs[0] + rhs,
		lhs[1] + rhs,
		lhs[2] + rhs,
		lhs[3] + rhs
	);
}

double4x4 operator+=( double4x4& lhs, const double rhs )
{
	return ( lhs = lhs + rhs );
}

double4x4 operator+( const double4x4& lhs, const double4x4& rhs )
{
	return double4x4(
		lhs[0] + rhs[0],
		lhs[1] + rhs[1],
		lhs[2] + rhs[2],
		lhs[3] + rhs[3]
	);
}

double4x4 operator+=( double4x4& lhs, const double4x4& rhs )
{
	return ( lhs = lhs + rhs );
}

double4x4 operator-( const double4x4& lhs, const double rhs )
{
	return double4x4(
		lhs[0] - rhs,
		lhs[1] - rhs,
		lhs[2] - rhs,
		lhs[3] - rhs
	);
}

double4x4 operator-=( double4x4& lhs, const double rhs )
{
	return ( lhs = lhs - rhs );
}

double4x4 operator-( const double4x4& lhs, const double4x4& rhs )
{
	return double4x4(
		lhs[0] - rhs[0],
		lhs[1] - rhs[1],
		lhs[2] - rhs[2],
		lhs[3] - rhs[3]
	);
}

double4x4 operator-=( double4x4& lhs, const double4x4& rhs )
{
	return ( lhs = lhs - rhs );
}

double4x4 operator*( const double4x4& lhs, const double rhs )
{
	return double4x4(
		lhs[0] * rhs,
		lhs[1] * rhs,
		lhs[2] * rhs,
		lhs[3] * rhs
	);
}

double4x4 operator*=( double4x4& lhs, const double rhs )
{
	return ( lhs = lhs * rhs );
}

double4x4 operator*( const double4x4& lhs, const double4x4& rhs )
{
	double4 row0 = lhs[0];
	double4 row1 = lhs[1];
	double4 row2 = lhs[2];
	double4 row3 = lhs[3];

	double4 col0 = { rhs[0].x, rhs[1].x, rhs[2].x, rhs[3].x };
	double4 col1 = { rhs[0].y, rhs[1].y, rhs[2].y, rhs[3].y };
	double4 col2 = { rhs[0].z, rhs[1].z, rhs[2].z, rhs[3].z };
	double4 col3 = { rhs[0].w, rhs[1].w, rhs[2].w, rhs[3].w };

	return double4x4(
		row0.x * col0.x + row0.y * col0.y + row0.z * col0.z + row0.w * col0.w,
		row0.x * col1.x + row0.y * col1.y + row0.z * col1.z + row0.w * col1.w,
		row0.x * col2.x + row0.y * col2.y + row0.z * col2.z + row0.w * col2.w,
		row0.x * col3.x + row0.y * col3.y + row0.z * col3.z + row0.w * col3.w,

		row1.x * col0.x + row1.y * col0.y + row1.z * col0.z + row1.w * col0.w,
		row1.x * col1.x + row1.y * col1.y + row1.z * col1.z + row1.w * col1.w,
		row1.x * col2.x + row1.y * col2.y + row1.z * col2.z + row1.w * col2.w,
		row1.x * col3.x + row1.y * col3.y + row1.z * col3.z + row1.w * col3.w,

		row2.x * col0.x + row2.y * col0.y + row2.z * col0.z + row2.w * col0.w,
		row2.x * col1.x + row2.y * col1.y + row2.z * col1.z + row2.w * col1.w,
		row2.x * col2.x + row2.y * col2.y + row2.z * col2.z + row2.w * col2.w,
		row2.x * col3.x + row2.y * col3.y + row2.z * col3.z + row2.w * col3.w,

		row3.x * col0.x + row3.y * col0.y + row3.z * col0.z + row3.w * col0.w,
		row3.x * col1.x + row3.y * col1.y + row3.z * col1.z + row3.w * col1.w,
		row3.x * col2.x + row3.y * col2.y + row3.z * col2.z + row3.w * col2.w,
		row3.x * col3.x + row3.y * col3.y + row3.z * col3.z + row3.w * col3.w
	);
}

double4x4 operator*=( double4x4& lhs, const double4x4& rhs )
{
	return ( lhs = lhs * rhs );
}

double4x4 operator/( const double4x4& lhs, const double rhs )
{
	return double4x4(
		lhs[0] / rhs,
		lhs[1] / rhs,
		lhs[2] / rhs,
		lhs[3] / rhs
	);
}

double4x4 operator/=( double4x4& lhs, const double rhs )
{
	return ( lhs = lhs / rhs );
}

double4x4 operator/( const double4x4& lhs, const double4x4& rhs )
{
	return lhs * inverse( rhs );
}

double4x4 operator/=( double4x4& lhs, const double4x4& rhs )
{
	return ( lhs = lhs / rhs );
}

double4 operator*( const double4x4& lhs, const double4& rhs )
{
	return double4(
		(double) dot( lhs[0], rhs ),
		(double) dot( lhs[1], rhs ),
		(double) dot( lhs[2], rhs ),
		(double) dot( lhs[3], rhs )
	);
}

double4 operator*=( double4& lhs, const double4x4& rhs )
{
	return ( lhs = rhs * lhs );
}

// prefix
double4x4& operator++( double4x4& lhs )
{
	++lhs[0];
	++lhs[1];
	++lhs[2];
	++lhs[3];
	return lhs;
}

// postfix
double4x4& operator++( double4x4& lhs, const int )
{
	lhs[0]++;
	lhs[1]++;
	lhs[2]++;
	lhs[3]++;
	return lhs;
}

// prefix
double4x4& operator--( double4x4& lhs )
{
	--lhs[0];
	--lhs[1];
	--lhs[2];
	--lhs[3];
	return lhs;
}

// postfix
double4x4& operator--( double4x4& lhs, const int )
{
	lhs[0]--;
	lhs[1]--;
	lhs[2]--;
	lhs[3]--;
	return lhs;
}

bool4x4 operator<( const double4x4& lhs, const double4x4& rhs )
{
	return bool4x4(
		lhs[0] < rhs[0],
		lhs[1] < rhs[1],
		lhs[2] < rhs[2],
		lhs[3] < rhs[3]
	);
}

bool4x4 operator<=( const double4x4& lhs, const double4x4& rhs )
{
	return bool4x4(
		lhs[0] <= rhs[0],
		lhs[1] <= rhs[1],
		lhs[2] <= rhs[2],
		lhs[3] <= rhs[3]
	);
}

bool4x4 operator>( const double4x4& lhs, const double4x4& rhs )
{
	return bool4x4(
		lhs[0] > rhs[0],
		lhs[1] > rhs[1],
		lhs[2] > rhs[2],
		lhs[3] > rhs[3]
	);
}

bool4x4 operator>=( const double4x4& lhs, const double4x4& rhs )
{
	return bool4x4(
		lhs[0] >= rhs[0],
		lhs[1] >= rhs[1],
		lhs[2] >= rhs[2],
		lhs[3] >= rhs[3]
	);
}


