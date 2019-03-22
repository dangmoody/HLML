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
#include "../hlml_main.h"

// others
#include <math.h>

// forward declares
int4x4 inverse( const int4x4& mat );

int4x4::int4x4()
{
	rows[0] = { 1, 0, 0, 0 };
	rows[1] = { 0, 1, 0, 0 };
	rows[2] = { 0, 0, 1, 0 };
	rows[3] = { 0, 0, 0, 1 };
}

int4x4::int4x4( const int32_t diagonal )
{
	rows[0] = { diagonal, 0, 0, 0 };
	rows[1] = { 0, diagonal, 0, 0 };
	rows[2] = { 0, 0, diagonal, 0 };
	rows[3] = { 0, 0, 0, diagonal };
}

int4x4::int4x4( const int4& diagonal )
{
	rows[0] = { diagonal.x, 0, 0, 0 };
	rows[1] = { 0, diagonal.y, 0, 0 };
	rows[2] = { 0, 0, diagonal.z, 0 };
	rows[3] = { 0, 0, 0, diagonal.w };
}

int4x4::int4x4( const int4& row0, const int4& row1, const int4& row2, const int4& row3 )
{
	rows[0] = row0;
	rows[1] = row1;
	rows[2] = row2;
	rows[3] = row3;
}

int4x4::int4x4( const int4 rows[4] )
{
	this->rows[0] = rows[0];
	this->rows[1] = rows[1];
	this->rows[2] = rows[2];
	this->rows[3] = rows[3];
}

int4x4::int4x4( const int32_t m00, const int32_t m01, const int32_t m02, const int32_t m03, const int32_t m10, const int32_t m11, const int32_t m12, const int32_t m13, const int32_t m20, const int32_t m21, const int32_t m22, const int32_t m23, const int32_t m30, const int32_t m31, const int32_t m32, const int32_t m33 )
{
	rows[0] = { m00, m01, m02, m03 };
	rows[1] = { m10, m11, m12, m13 };
	rows[2] = { m20, m21, m22, m23 };
	rows[3] = { m30, m31, m32, m33 };
}

int4x4::int4x4( const int4x4& other )
{
	memcpy( rows, other.rows, sizeof( rows ) );
};

int4x4 int4x4::operator=( const int4x4& other )
{
	memcpy( rows, other.rows, sizeof( rows ) );
	return *this;
};

int4& int4x4::operator[]( const uint32_t index )
{
	assert( index < 4 );
	return rows[index];
}

const int4& int4x4::operator[]( const uint32_t index ) const
{
	assert( index < 4 );
	return rows[index];
}

bool operator==( const int4x4& lhs, const int4x4& rhs )
{
	return lhs[0] == rhs[0]
		&& lhs[1] == rhs[1]
		&& lhs[2] == rhs[2]
		&& lhs[3] == rhs[3];
}

bool operator!=( const int4x4& lhs, const int4x4& rhs ) {
	return !( operator==( lhs, rhs ) );
}

