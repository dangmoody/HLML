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

// others
#include <math.h>

bool2x2::bool2x2()
{
	rows[0] = { 1, 0 };
	rows[1] = { 0, 1 };
}

bool2x2::bool2x2( const bool32_t diagonal )
{
	rows[0] = { diagonal, 0 };
	rows[1] = { 0, diagonal };
}

bool2x2::bool2x2( const bool2& diagonal )
{
	rows[0] = { diagonal.x, 0 };
	rows[1] = { 0, diagonal.y };
}

bool2x2::bool2x2( const bool2& row0, const bool2& row1 )
{
	rows[0] = row0;
	rows[1] = row1;
}

bool2x2::bool2x2( const bool2 rows[2] )
{
	this->rows[0] = rows[0];
	this->rows[1] = rows[1];
}

bool2x2::bool2x2( const bool32_t m00, const bool32_t m01, const bool32_t m10, const bool32_t m11 )
{
	rows[0] = { m00, m01 };
	rows[1] = { m10, m11 };
}

bool2x2::bool2x2( const bool2x2& other )
{
	memcpy( rows, other.rows, sizeof( rows ) );
}

bool2x2 bool2x2::operator=( const bool2x2& other )
{
	memcpy( rows, other.rows, sizeof( rows ) );
	return *this;
}

bool2& bool2x2::operator[]( const uint32_t index )
{
	assert( index < 2 );
	return rows[index];
}

const bool2& bool2x2::operator[]( const uint32_t index ) const
{
	assert( index < 2 );
	return rows[index];
}

bool operator==( const bool2x2& lhs, const bool2x2& rhs )
{
	return lhs[0] == rhs[0]
		&& lhs[1] == rhs[1];
}

bool operator!=( const bool2x2& lhs, const bool2x2& rhs )
{
	return !( operator==( lhs, rhs ) );
}

