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

#include "hlml_functions_vector.h"
#include "hlml_operators_matrix.h"

// bool2x2
void identity( bool2x2& mat ) {
	mat[0] = { 1, 0 };
	mat[1] = { 0, 1 };
}

bool2x2 transpose( const bool2x2& mat ) {
	return bool2x2(
		mat[0][0], mat[1][0],
		mat[0][1], mat[1][1]
	);
}


// bool2x3
void identity( bool2x3& mat ) {
	mat[0] = { 1, 0, 0 };
	mat[1] = { 0, 1, 0 };
}

bool3x2 transpose( const bool2x3& mat ) {
	return bool3x2(
		mat[0][0], mat[1][0],
		mat[0][1], mat[1][1],
		mat[0][2], mat[1][2]
	);
}


// bool2x4
void identity( bool2x4& mat ) {
	mat[0] = { 1, 0, 0, 0 };
	mat[1] = { 0, 1, 0, 0 };
}

bool4x2 transpose( const bool2x4& mat ) {
	return bool4x2(
		mat[0][0], mat[1][0],
		mat[0][1], mat[1][1],
		mat[0][2], mat[1][2],
		mat[0][3], mat[1][3]
	);
}


// bool3x2
void identity( bool3x2& mat ) {
	mat[0] = { 1, 0 };
	mat[1] = { 0, 1 };
	mat[2] = { 0, 0 };
}

bool2x3 transpose( const bool3x2& mat ) {
	return bool2x3(
		mat[0][0], mat[1][0], mat[2][0],
		mat[0][1], mat[1][1], mat[2][1]
	);
}


// bool3x3
void identity( bool3x3& mat ) {
	mat[0] = { 1, 0, 0 };
	mat[1] = { 0, 1, 0 };
	mat[2] = { 0, 0, 1 };
}

bool3x3 transpose( const bool3x3& mat ) {
	return bool3x3(
		mat[0][0], mat[1][0], mat[2][0],
		mat[0][1], mat[1][1], mat[2][1],
		mat[0][2], mat[1][2], mat[2][2]
	);
}


// bool3x4
void identity( bool3x4& mat ) {
	mat[0] = { 1, 0, 0, 0 };
	mat[1] = { 0, 1, 0, 0 };
	mat[2] = { 0, 0, 1, 0 };
}

bool4x3 transpose( const bool3x4& mat ) {
	return bool4x3(
		mat[0][0], mat[1][0], mat[2][0],
		mat[0][1], mat[1][1], mat[2][1],
		mat[0][2], mat[1][2], mat[2][2],
		mat[0][3], mat[1][3], mat[2][3]
	);
}


// bool4x2
void identity( bool4x2& mat ) {
	mat[0] = { 1, 0 };
	mat[1] = { 0, 1 };
	mat[2] = { 0, 0 };
	mat[3] = { 0, 0 };
}

bool2x4 transpose( const bool4x2& mat ) {
	return bool2x4(
		mat[0][0], mat[1][0], mat[2][0], mat[3][0],
		mat[0][1], mat[1][1], mat[2][1], mat[3][1]
	);
}


// bool4x3
void identity( bool4x3& mat ) {
	mat[0] = { 1, 0, 0 };
	mat[1] = { 0, 1, 0 };
	mat[2] = { 0, 0, 1 };
	mat[3] = { 0, 0, 0 };
}

bool3x4 transpose( const bool4x3& mat ) {
	return bool3x4(
		mat[0][0], mat[1][0], mat[2][0], mat[3][0],
		mat[0][1], mat[1][1], mat[2][1], mat[3][1],
		mat[0][2], mat[1][2], mat[2][2], mat[3][2]
	);
}


// bool4x4
void identity( bool4x4& mat ) {
	mat[0] = { 1, 0, 0, 0 };
	mat[1] = { 0, 1, 0, 0 };
	mat[2] = { 0, 0, 1, 0 };
	mat[3] = { 0, 0, 0, 1 };
}

bool4x4 transpose( const bool4x4& mat ) {
	return bool4x4(
		mat[0][0], mat[1][0], mat[2][0], mat[3][0],
		mat[0][1], mat[1][1], mat[2][1], mat[3][1],
		mat[0][2], mat[1][2], mat[2][2], mat[3][2],
		mat[0][3], mat[1][3], mat[2][3], mat[3][3]
	);
}


// int2x2
void identity( int2x2& mat ) {
	mat[0] = { 1, 0 };
	mat[1] = { 0, 1 };
}

int2x2 transpose( const int2x2& mat ) {
	return int2x2(
		mat[0][0], mat[1][0],
		mat[0][1], mat[1][1]
	);
}

int32_t determinant( const int2x2& mat ) {
	return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
}

int2x2 scale( const int2x2& mat, const int32_t scalar ) {
	return scale( mat, int3( scalar, scalar, scalar ) );
}

int2x2 scale( const int2x2& mat, const int3& vec ) {
	return int2x2(
		mat[0][0] * vec.x,
		mat[0][1],

		mat[1][0],
		mat[1][1] * vec.y
	);
}


// int2x3
void identity( int2x3& mat ) {
	mat[0] = { 1, 0, 0 };
	mat[1] = { 0, 1, 0 };
}

int3x2 transpose( const int2x3& mat ) {
	return int3x2(
		mat[0][0], mat[1][0],
		mat[0][1], mat[1][1],
		mat[0][2], mat[1][2]
	);
}

int2x3 scale( const int2x3& mat, const int32_t scalar ) {
	return scale( mat, int3( scalar, scalar, scalar ) );
}

int2x3 scale( const int2x3& mat, const int3& vec ) {
	return int2x3(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2]
	);
}


// int2x4
void identity( int2x4& mat ) {
	mat[0] = { 1, 0, 0, 0 };
	mat[1] = { 0, 1, 0, 0 };
}

int4x2 transpose( const int2x4& mat ) {
	return int4x2(
		mat[0][0], mat[1][0],
		mat[0][1], mat[1][1],
		mat[0][2], mat[1][2],
		mat[0][3], mat[1][3]
	);
}

int2x4 scale( const int2x4& mat, const int32_t scalar ) {
	return scale( mat, int3( scalar, scalar, scalar ) );
}

int2x4 scale( const int2x4& mat, const int3& vec ) {
	return int2x4(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],
		mat[0][3],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],
		mat[1][3]
	);
}


// int3x2
void identity( int3x2& mat ) {
	mat[0] = { 1, 0 };
	mat[1] = { 0, 1 };
	mat[2] = { 0, 0 };
}

int2x3 transpose( const int3x2& mat ) {
	return int2x3(
		mat[0][0], mat[1][0], mat[2][0],
		mat[0][1], mat[1][1], mat[2][1]
	);
}


// int3x3
void identity( int3x3& mat ) {
	mat[0] = { 1, 0, 0 };
	mat[1] = { 0, 1, 0 };
	mat[2] = { 0, 0, 1 };
}

int3x3 transpose( const int3x3& mat ) {
	return int3x3(
		mat[0][0], mat[1][0], mat[2][0],
		mat[0][1], mat[1][1], mat[2][1],
		mat[0][2], mat[1][2], mat[2][2]
	);
}

int32_t determinant( const int3x3& mat ) {
	return
		+ mat[0][0] * ( mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2] )
		- mat[0][1] * ( mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2] )
		+ mat[0][2] * ( mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1] );
}

int3x3 translate( const int3x3& mat, const int2& vec ) {
	return int3x3(
		mat[0][0], mat[0][1], mat[0][2] + vec.x,
		mat[1][0], mat[1][1], mat[1][2] + vec.y,
		mat[2][0], mat[2][1], mat[2][2]
	);
}

int3x3 scale( const int3x3& mat, const int32_t scalar ) {
	return scale( mat, int3( scalar, scalar, scalar ) );
}

int3x3 scale( const int3x3& mat, const int3& vec ) {
	return int3x3(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],

		mat[2][0],
		mat[2][1],
		mat[2][2] * vec.z
	);
}


// int3x4
void identity( int3x4& mat ) {
	mat[0] = { 1, 0, 0, 0 };
	mat[1] = { 0, 1, 0, 0 };
	mat[2] = { 0, 0, 1, 0 };
}

int4x3 transpose( const int3x4& mat ) {
	return int4x3(
		mat[0][0], mat[1][0], mat[2][0],
		mat[0][1], mat[1][1], mat[2][1],
		mat[0][2], mat[1][2], mat[2][2],
		mat[0][3], mat[1][3], mat[2][3]
	);
}

int3x4 translate( const int3x4& mat, const int3& vec ) {
	return int3x4(
		mat[0][0], mat[0][1], mat[0][2], mat[0][3] + vec.x,
		mat[1][0], mat[1][1], mat[1][2], mat[1][3] + vec.y,
		mat[2][0], mat[2][1], mat[2][2], mat[2][3] + vec.z
	);
}

int3x4 scale( const int3x4& mat, const int32_t scalar ) {
	return scale( mat, int3( scalar, scalar, scalar ) );
}

int3x4 scale( const int3x4& mat, const int3& vec ) {
	return int3x4(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],
		mat[0][3],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],
		mat[1][3],

		mat[2][0],
		mat[2][1],
		mat[2][2] * vec.z,
		mat[2][3]
	);
}


// int4x2
void identity( int4x2& mat ) {
	mat[0] = { 1, 0 };
	mat[1] = { 0, 1 };
	mat[2] = { 0, 0 };
	mat[3] = { 0, 0 };
}

int2x4 transpose( const int4x2& mat ) {
	return int2x4(
		mat[0][0], mat[1][0], mat[2][0], mat[3][0],
		mat[0][1], mat[1][1], mat[2][1], mat[3][1]
	);
}


// int4x3
void identity( int4x3& mat ) {
	mat[0] = { 1, 0, 0 };
	mat[1] = { 0, 1, 0 };
	mat[2] = { 0, 0, 1 };
	mat[3] = { 0, 0, 0 };
}

int3x4 transpose( const int4x3& mat ) {
	return int3x4(
		mat[0][0], mat[1][0], mat[2][0], mat[3][0],
		mat[0][1], mat[1][1], mat[2][1], mat[3][1],
		mat[0][2], mat[1][2], mat[2][2], mat[3][2]
	);
}

int4x3 scale( const int4x3& mat, const int32_t scalar ) {
	return scale( mat, int3( scalar, scalar, scalar ) );
}

int4x3 scale( const int4x3& mat, const int3& vec ) {
	return int4x3(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],

		mat[2][0],
		mat[2][1],
		mat[2][2] * vec.z,

		mat[3][0],
		mat[3][1],
		mat[3][2]
	);
}


// int4x4
void identity( int4x4& mat ) {
	mat[0] = { 1, 0, 0, 0 };
	mat[1] = { 0, 1, 0, 0 };
	mat[2] = { 0, 0, 1, 0 };
	mat[3] = { 0, 0, 0, 1 };
}

int4x4 transpose( const int4x4& mat ) {
	return int4x4(
		mat[0][0], mat[1][0], mat[2][0], mat[3][0],
		mat[0][1], mat[1][1], mat[2][1], mat[3][1],
		mat[0][2], mat[1][2], mat[2][2], mat[3][2],
		mat[0][3], mat[1][3], mat[2][3], mat[3][3]
	);
}

int32_t determinant( const int4x4& mat ) {
	// using glm's method where you basically take determinants from each sub matrix and cache the repeat occurences
	int32_t sub00 = mat[2][2] * mat[3][3] - mat[3][2] * mat[2][3];
	int32_t sub01 = mat[2][1] * mat[3][3] - mat[2][3] * mat[3][1];
	int32_t sub02 = mat[2][1] * mat[3][2] - mat[3][1] * mat[2][2];
	int32_t sub03 = mat[2][0] * mat[3][3] - mat[3][0] * mat[2][3];
	int32_t sub04 = mat[2][0] * mat[3][2] - mat[3][0] * mat[2][2];
	int32_t sub05 = mat[2][0] * mat[3][1] - mat[3][0] * mat[2][1];

	int4 cofactor = int4(
		 ( mat[1][1] * sub00 - mat[1][2] * sub01 + mat[1][3] * sub02 ),
		-( mat[1][0] * sub00 - mat[1][2] * sub03 + mat[1][3] * sub04 ),
		 ( mat[1][0] * sub01 - mat[1][1] * sub03 + mat[1][3] * sub05 ),
		-( mat[1][0] * sub02 - mat[1][1] * sub04 + mat[1][2] * sub05 )
	);

	return
		mat[0][0] * cofactor.x + mat[0][1] * cofactor.y +
		mat[0][2] * cofactor.z + mat[0][3] * cofactor.w;
}

int4x4 translate( const int4x4& mat, const int3& vec ) {
	return int4x4(
		mat[0][0], mat[0][1], mat[0][2], mat[0][3] + vec.x,
		mat[1][0], mat[1][1], mat[1][2], mat[1][3] + vec.y,
		mat[2][0], mat[2][1], mat[2][2], mat[2][3] + vec.z,
		mat[3][0], mat[3][1], mat[3][2], mat[3][3]
	);
}

int4x4 scale( const int4x4& mat, const int32_t scalar ) {
	return scale( mat, int3( scalar, scalar, scalar ) );
}

int4x4 scale( const int4x4& mat, const int3& vec ) {
	return int4x4(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],
		mat[0][3],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],
		mat[1][3],

		mat[2][0],
		mat[2][1],
		mat[2][2] * vec.z,
		mat[2][3],

		mat[3][0],
		mat[3][1],
		mat[3][2],
		mat[3][3]
	);
}


// uint2x2
void identity( uint2x2& mat ) {
	mat[0] = { 1, 0 };
	mat[1] = { 0, 1 };
}

uint2x2 transpose( const uint2x2& mat ) {
	return uint2x2(
		mat[0][0], mat[1][0],
		mat[0][1], mat[1][1]
	);
}

uint2x2 scale( const uint2x2& mat, const uint32_t scalar ) {
	return scale( mat, uint3( scalar, scalar, scalar ) );
}

uint2x2 scale( const uint2x2& mat, const uint3& vec ) {
	return uint2x2(
		mat[0][0] * vec.x,
		mat[0][1],

		mat[1][0],
		mat[1][1] * vec.y
	);
}


// uint2x3
void identity( uint2x3& mat ) {
	mat[0] = { 1, 0, 0 };
	mat[1] = { 0, 1, 0 };
}

uint3x2 transpose( const uint2x3& mat ) {
	return uint3x2(
		mat[0][0], mat[1][0],
		mat[0][1], mat[1][1],
		mat[0][2], mat[1][2]
	);
}

uint2x3 scale( const uint2x3& mat, const uint32_t scalar ) {
	return scale( mat, uint3( scalar, scalar, scalar ) );
}

uint2x3 scale( const uint2x3& mat, const uint3& vec ) {
	return uint2x3(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2]
	);
}


// uint2x4
void identity( uint2x4& mat ) {
	mat[0] = { 1, 0, 0, 0 };
	mat[1] = { 0, 1, 0, 0 };
}

uint4x2 transpose( const uint2x4& mat ) {
	return uint4x2(
		mat[0][0], mat[1][0],
		mat[0][1], mat[1][1],
		mat[0][2], mat[1][2],
		mat[0][3], mat[1][3]
	);
}

uint2x4 scale( const uint2x4& mat, const uint32_t scalar ) {
	return scale( mat, uint3( scalar, scalar, scalar ) );
}

uint2x4 scale( const uint2x4& mat, const uint3& vec ) {
	return uint2x4(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],
		mat[0][3],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],
		mat[1][3]
	);
}


// uint3x2
void identity( uint3x2& mat ) {
	mat[0] = { 1, 0 };
	mat[1] = { 0, 1 };
	mat[2] = { 0, 0 };
}

uint2x3 transpose( const uint3x2& mat ) {
	return uint2x3(
		mat[0][0], mat[1][0], mat[2][0],
		mat[0][1], mat[1][1], mat[2][1]
	);
}


// uint3x3
void identity( uint3x3& mat ) {
	mat[0] = { 1, 0, 0 };
	mat[1] = { 0, 1, 0 };
	mat[2] = { 0, 0, 1 };
}

uint3x3 transpose( const uint3x3& mat ) {
	return uint3x3(
		mat[0][0], mat[1][0], mat[2][0],
		mat[0][1], mat[1][1], mat[2][1],
		mat[0][2], mat[1][2], mat[2][2]
	);
}

uint3x3 translate( const uint3x3& mat, const uint2& vec ) {
	return uint3x3(
		mat[0][0], mat[0][1], mat[0][2] + vec.x,
		mat[1][0], mat[1][1], mat[1][2] + vec.y,
		mat[2][0], mat[2][1], mat[2][2]
	);
}

uint3x3 scale( const uint3x3& mat, const uint32_t scalar ) {
	return scale( mat, uint3( scalar, scalar, scalar ) );
}

uint3x3 scale( const uint3x3& mat, const uint3& vec ) {
	return uint3x3(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],

		mat[2][0],
		mat[2][1],
		mat[2][2] * vec.z
	);
}


// uint3x4
void identity( uint3x4& mat ) {
	mat[0] = { 1, 0, 0, 0 };
	mat[1] = { 0, 1, 0, 0 };
	mat[2] = { 0, 0, 1, 0 };
}

uint4x3 transpose( const uint3x4& mat ) {
	return uint4x3(
		mat[0][0], mat[1][0], mat[2][0],
		mat[0][1], mat[1][1], mat[2][1],
		mat[0][2], mat[1][2], mat[2][2],
		mat[0][3], mat[1][3], mat[2][3]
	);
}

uint3x4 translate( const uint3x4& mat, const uint3& vec ) {
	return uint3x4(
		mat[0][0], mat[0][1], mat[0][2], mat[0][3] + vec.x,
		mat[1][0], mat[1][1], mat[1][2], mat[1][3] + vec.y,
		mat[2][0], mat[2][1], mat[2][2], mat[2][3] + vec.z
	);
}

uint3x4 scale( const uint3x4& mat, const uint32_t scalar ) {
	return scale( mat, uint3( scalar, scalar, scalar ) );
}

uint3x4 scale( const uint3x4& mat, const uint3& vec ) {
	return uint3x4(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],
		mat[0][3],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],
		mat[1][3],

		mat[2][0],
		mat[2][1],
		mat[2][2] * vec.z,
		mat[2][3]
	);
}


// uint4x2
void identity( uint4x2& mat ) {
	mat[0] = { 1, 0 };
	mat[1] = { 0, 1 };
	mat[2] = { 0, 0 };
	mat[3] = { 0, 0 };
}

uint2x4 transpose( const uint4x2& mat ) {
	return uint2x4(
		mat[0][0], mat[1][0], mat[2][0], mat[3][0],
		mat[0][1], mat[1][1], mat[2][1], mat[3][1]
	);
}


// uint4x3
void identity( uint4x3& mat ) {
	mat[0] = { 1, 0, 0 };
	mat[1] = { 0, 1, 0 };
	mat[2] = { 0, 0, 1 };
	mat[3] = { 0, 0, 0 };
}

uint3x4 transpose( const uint4x3& mat ) {
	return uint3x4(
		mat[0][0], mat[1][0], mat[2][0], mat[3][0],
		mat[0][1], mat[1][1], mat[2][1], mat[3][1],
		mat[0][2], mat[1][2], mat[2][2], mat[3][2]
	);
}

uint4x3 scale( const uint4x3& mat, const uint32_t scalar ) {
	return scale( mat, uint3( scalar, scalar, scalar ) );
}

uint4x3 scale( const uint4x3& mat, const uint3& vec ) {
	return uint4x3(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],

		mat[2][0],
		mat[2][1],
		mat[2][2] * vec.z,

		mat[3][0],
		mat[3][1],
		mat[3][2]
	);
}


// uint4x4
void identity( uint4x4& mat ) {
	mat[0] = { 1, 0, 0, 0 };
	mat[1] = { 0, 1, 0, 0 };
	mat[2] = { 0, 0, 1, 0 };
	mat[3] = { 0, 0, 0, 1 };
}

uint4x4 transpose( const uint4x4& mat ) {
	return uint4x4(
		mat[0][0], mat[1][0], mat[2][0], mat[3][0],
		mat[0][1], mat[1][1], mat[2][1], mat[3][1],
		mat[0][2], mat[1][2], mat[2][2], mat[3][2],
		mat[0][3], mat[1][3], mat[2][3], mat[3][3]
	);
}

uint4x4 translate( const uint4x4& mat, const uint3& vec ) {
	return uint4x4(
		mat[0][0], mat[0][1], mat[0][2], mat[0][3] + vec.x,
		mat[1][0], mat[1][1], mat[1][2], mat[1][3] + vec.y,
		mat[2][0], mat[2][1], mat[2][2], mat[2][3] + vec.z,
		mat[3][0], mat[3][1], mat[3][2], mat[3][3]
	);
}

uint4x4 scale( const uint4x4& mat, const uint32_t scalar ) {
	return scale( mat, uint3( scalar, scalar, scalar ) );
}

uint4x4 scale( const uint4x4& mat, const uint3& vec ) {
	return uint4x4(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],
		mat[0][3],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],
		mat[1][3],

		mat[2][0],
		mat[2][1],
		mat[2][2] * vec.z,
		mat[2][3],

		mat[3][0],
		mat[3][1],
		mat[3][2],
		mat[3][3]
	);
}


// float2x2
void identity( float2x2& mat ) {
	mat[0] = { 1, 0 };
	mat[1] = { 0, 1 };
}

float2x2 transpose( const float2x2& mat ) {
	return float2x2(
		mat[0][0], mat[1][0],
		mat[0][1], mat[1][1]
	);
}

float2x2 inverse( const float2x2& mat ) {
	const float invdet = 1.000000f / determinant( mat );
	return float2x2(
		 mat[1][1] * invdet, -mat[0][1] * invdet,
		-mat[1][0] * invdet,  mat[0][0] * invdet
	);
}

float determinant( const float2x2& mat ) {
	return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
}

float2x2 scale( const float2x2& mat, const float scalar ) {
	return scale( mat, float3( scalar, scalar, scalar ) );
}

float2x2 scale( const float2x2& mat, const float3& vec ) {
	return float2x2(
		mat[0][0] * vec.x,
		mat[0][1],

		mat[1][0],
		mat[1][1] * vec.y
	);
}


// float2x3
void identity( float2x3& mat ) {
	mat[0] = { 1, 0, 0 };
	mat[1] = { 0, 1, 0 };
}

float3x2 transpose( const float2x3& mat ) {
	return float3x2(
		mat[0][0], mat[1][0],
		mat[0][1], mat[1][1],
		mat[0][2], mat[1][2]
	);
}

float2x3 scale( const float2x3& mat, const float scalar ) {
	return scale( mat, float3( scalar, scalar, scalar ) );
}

float2x3 scale( const float2x3& mat, const float3& vec ) {
	return float2x3(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2]
	);
}


// float2x4
void identity( float2x4& mat ) {
	mat[0] = { 1, 0, 0, 0 };
	mat[1] = { 0, 1, 0, 0 };
}

float4x2 transpose( const float2x4& mat ) {
	return float4x2(
		mat[0][0], mat[1][0],
		mat[0][1], mat[1][1],
		mat[0][2], mat[1][2],
		mat[0][3], mat[1][3]
	);
}

float2x4 scale( const float2x4& mat, const float scalar ) {
	return scale( mat, float3( scalar, scalar, scalar ) );
}

float2x4 scale( const float2x4& mat, const float3& vec ) {
	return float2x4(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],
		mat[0][3],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],
		mat[1][3]
	);
}


// float3x2
void identity( float3x2& mat ) {
	mat[0] = { 1, 0 };
	mat[1] = { 0, 1 };
	mat[2] = { 0, 0 };
}

float2x3 transpose( const float3x2& mat ) {
	return float2x3(
		mat[0][0], mat[1][0], mat[2][0],
		mat[0][1], mat[1][1], mat[2][1]
	);
}


// float3x3
void identity( float3x3& mat ) {
	mat[0] = { 1, 0, 0 };
	mat[1] = { 0, 1, 0 };
	mat[2] = { 0, 0, 1 };
}

float3x3 transpose( const float3x3& mat ) {
	return float3x3(
		mat[0][0], mat[1][0], mat[2][0],
		mat[0][1], mat[1][1], mat[2][1],
		mat[0][2], mat[1][2], mat[2][2]
	);
}

float3x3 inverse( const float3x3& mat ) {
	const float invdet = 1.000000f / determinant( mat );
	return float3x3(
		 ( mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1] ) * invdet,
		-( mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1] ) * invdet,
		 ( mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1] ) * invdet,

		-( mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0] ) * invdet,
		 ( mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0] ) * invdet,
		-( mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0] ) * invdet,

		 ( mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0] ) * invdet,
		-( mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0] ) * invdet,
		 ( mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0] ) * invdet
	);
}

float determinant( const float3x3& mat ) {
	return
		+ mat[0][0] * ( mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2] )
		- mat[0][1] * ( mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2] )
		+ mat[0][2] * ( mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1] );
}

float3x3 translate( const float3x3& mat, const float2& vec ) {
	return float3x3(
		mat[0][0], mat[0][1], mat[0][2] + vec.x,
		mat[1][0], mat[1][1], mat[1][2] + vec.y,
		mat[2][0], mat[2][1], mat[2][2]
	);
}

float3x3 rotate( const float3x3& mat, const float rad ) {
	const float c = cosf( rad );
	const float s = sinf( rad );

	return float3x3(
		mat[0] * c + mat[1] * -s,
		mat[0] * s + mat[1] * c,
		mat[2]
	);
}

float3x3 scale( const float3x3& mat, const float scalar ) {
	return scale( mat, float3( scalar, scalar, scalar ) );
}

float3x3 scale( const float3x3& mat, const float3& vec ) {
	return float3x3(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],

		mat[2][0],
		mat[2][1],
		mat[2][2] * vec.z
	);
}


// float3x4
void identity( float3x4& mat ) {
	mat[0] = { 1, 0, 0, 0 };
	mat[1] = { 0, 1, 0, 0 };
	mat[2] = { 0, 0, 1, 0 };
}

float4x3 transpose( const float3x4& mat ) {
	return float4x3(
		mat[0][0], mat[1][0], mat[2][0],
		mat[0][1], mat[1][1], mat[2][1],
		mat[0][2], mat[1][2], mat[2][2],
		mat[0][3], mat[1][3], mat[2][3]
	);
}

float3x4 translate( const float3x4& mat, const float3& vec ) {
	return float3x4(
		mat[0][0], mat[0][1], mat[0][2], mat[0][3] + vec.x,
		mat[1][0], mat[1][1], mat[1][2], mat[1][3] + vec.y,
		mat[2][0], mat[2][1], mat[2][2], mat[2][3] + vec.z
	);
}

float3x4 scale( const float3x4& mat, const float scalar ) {
	return scale( mat, float3( scalar, scalar, scalar ) );
}

float3x4 scale( const float3x4& mat, const float3& vec ) {
	return float3x4(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],
		mat[0][3],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],
		mat[1][3],

		mat[2][0],
		mat[2][1],
		mat[2][2] * vec.z,
		mat[2][3]
	);
}


// float4x2
void identity( float4x2& mat ) {
	mat[0] = { 1, 0 };
	mat[1] = { 0, 1 };
	mat[2] = { 0, 0 };
	mat[3] = { 0, 0 };
}

float2x4 transpose( const float4x2& mat ) {
	return float2x4(
		mat[0][0], mat[1][0], mat[2][0], mat[3][0],
		mat[0][1], mat[1][1], mat[2][1], mat[3][1]
	);
}


// float4x3
void identity( float4x3& mat ) {
	mat[0] = { 1, 0, 0 };
	mat[1] = { 0, 1, 0 };
	mat[2] = { 0, 0, 1 };
	mat[3] = { 0, 0, 0 };
}

float3x4 transpose( const float4x3& mat ) {
	return float3x4(
		mat[0][0], mat[1][0], mat[2][0], mat[3][0],
		mat[0][1], mat[1][1], mat[2][1], mat[3][1],
		mat[0][2], mat[1][2], mat[2][2], mat[3][2]
	);
}

float4x3 scale( const float4x3& mat, const float scalar ) {
	return scale( mat, float3( scalar, scalar, scalar ) );
}

float4x3 scale( const float4x3& mat, const float3& vec ) {
	return float4x3(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],

		mat[2][0],
		mat[2][1],
		mat[2][2] * vec.z,

		mat[3][0],
		mat[3][1],
		mat[3][2]
	);
}


// float4x4
void identity( float4x4& mat ) {
	mat[0] = { 1, 0, 0, 0 };
	mat[1] = { 0, 1, 0, 0 };
	mat[2] = { 0, 0, 1, 0 };
	mat[3] = { 0, 0, 0, 1 };
}

float4x4 transpose( const float4x4& mat ) {
	return float4x4(
		mat[0][0], mat[1][0], mat[2][0], mat[3][0],
		mat[0][1], mat[1][1], mat[2][1], mat[3][1],
		mat[0][2], mat[1][2], mat[2][2], mat[3][2],
		mat[0][3], mat[1][3], mat[2][3], mat[3][3]
	);
}

float4x4 inverse( const float4x4& mat ) {
	// uses the glm version, which is basically just an optimised version of the adjugate formula
	float sub00 = mat[2][2] * mat[3][3] - mat[3][2] * mat[2][3];
	float sub01 = mat[1][2] * mat[3][3] - mat[1][3] * mat[2][3];
	float sub02 = mat[1][2] * mat[2][3] - mat[1][3] * mat[2][2];

	float sub03 = mat[2][1] * mat[3][3] - mat[2][3] * mat[3][1];
	float sub04 = mat[1][1] * mat[3][3] - mat[1][3] * mat[3][1];
	float sub05 = mat[1][1] * mat[2][3] - mat[1][3] * mat[2][1];

	float sub06 = mat[2][1] * mat[3][2] - mat[2][2] * mat[3][1];
	float sub07 = mat[1][1] * mat[3][2] - mat[1][2] * mat[3][1];
	float sub08 = mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1];

	float sub09 = mat[2][0] * mat[3][3] - mat[3][0] * mat[2][3];
	float sub10 = mat[1][0] * mat[3][3] - mat[3][0] * mat[1][3];
	float sub11 = mat[1][0] * mat[2][3] - mat[2][0] * mat[1][3];

	float sub12 = mat[2][0] * mat[3][2] - mat[2][2] * mat[3][0];
	float sub13 = mat[1][0] * mat[3][2] - mat[1][2] * mat[3][0];
	float sub14 = mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0];

	float sub15 = mat[2][0] * mat[3][1] - mat[2][1] * mat[3][0];
	float sub16 = mat[1][0] * mat[3][1] - mat[1][1] * mat[3][0];
	float sub17 = mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0];

	float4 fac0 = float4( sub00, sub00, sub01, sub02 );
	float4 fac1 = float4( sub03, sub03, sub04, sub05 );
	float4 fac2 = float4( sub06, sub06, sub07, sub08 );
	float4 fac3 = float4( sub09, sub09, sub10, sub11 );
	float4 fac4 = float4( sub12, sub12, sub13, sub14 );
	float4 fac5 = float4( sub15, sub15, sub16, sub17 );

	float4 vec0 = float4( mat[1][0], mat[0][0], mat[0][0], mat[0][0] );
	float4 vec1 = float4( mat[1][1], mat[0][1], mat[0][1], mat[0][1] );
	float4 vec2 = float4( mat[1][2], mat[0][2], mat[0][2], mat[0][2] );
	float4 vec3 = float4( mat[1][3], mat[0][3], mat[0][3], mat[0][3] );

	float4 inv0 = vec1 * fac0 - vec2 * fac1 + vec3 * fac2;
	float4 inv1 = vec0 * fac0 - vec2 * fac3 + vec3 * fac4;
	float4 inv2 = vec0 * fac1 - vec1 * fac3 + vec3 * fac5;
	float4 inv3 = vec0 * fac2 - vec1 * fac4 + vec2 * fac5;

	float4 sign0 = float4(  1, -1,  1, -1 );
	float4 sign1 = float4( -1,  1, -1,  1 );

	float4x4 result = float4x4(
		inv0 * sign0,
		inv1 * sign1,
		inv2 * sign0,
		inv3 * sign1
	);

	float4 col0 = float4( result[0][0], result[1][0], result[2][0], result[3][0] );
	float4 dot0 = mat[0] * col0;

	const float dot1 = ( dot0.x + dot0.y ) + ( dot0.z + dot0.w );

	const float invdet = 1.000000f / dot1;

	return result * invdet;
}

float determinant( const float4x4& mat ) {
	// using glm's method where you basically take determinants from each sub matrix and cache the repeat occurences
	float sub00 = mat[2][2] * mat[3][3] - mat[3][2] * mat[2][3];
	float sub01 = mat[2][1] * mat[3][3] - mat[2][3] * mat[3][1];
	float sub02 = mat[2][1] * mat[3][2] - mat[3][1] * mat[2][2];
	float sub03 = mat[2][0] * mat[3][3] - mat[3][0] * mat[2][3];
	float sub04 = mat[2][0] * mat[3][2] - mat[3][0] * mat[2][2];
	float sub05 = mat[2][0] * mat[3][1] - mat[3][0] * mat[2][1];

	float4 cofactor = float4(
		 ( mat[1][1] * sub00 - mat[1][2] * sub01 + mat[1][3] * sub02 ),
		-( mat[1][0] * sub00 - mat[1][2] * sub03 + mat[1][3] * sub04 ),
		 ( mat[1][0] * sub01 - mat[1][1] * sub03 + mat[1][3] * sub05 ),
		-( mat[1][0] * sub02 - mat[1][1] * sub04 + mat[1][2] * sub05 )
	);

	return
		mat[0][0] * cofactor.x + mat[0][1] * cofactor.y +
		mat[0][2] * cofactor.z + mat[0][3] * cofactor.w;
}

float4x4 translate( const float4x4& mat, const float3& vec ) {
	return float4x4(
		mat[0][0], mat[0][1], mat[0][2], mat[0][3] + vec.x,
		mat[1][0], mat[1][1], mat[1][2], mat[1][3] + vec.y,
		mat[2][0], mat[2][1], mat[2][2], mat[2][3] + vec.z,
		mat[3][0], mat[3][1], mat[3][2], mat[3][3]
	);
}

float4x4 rotate( const float4x4& mat, const float rad, const float3& axis ) {
	const float c = cosf( rad );
	const float s = sinf( rad );

	float3 u = normalized( axis );
	float ic = 1.000000f - c;

	float4x4 rotation = mat;
	rotation[0][0] = c + u.x * ic;
	rotation[0][1] = u.x * u.y * ic - u.z * s;
	rotation[0][2] = u.x * u.z * ic + u.y * s;

	rotation[1][0] = u.y * u.x * ic + u.z * s;
	rotation[1][1] = c + u.y * ic;
	rotation[1][2] = u.y * u.z * ic - u.x * s;

	rotation[2][0] = u.z * u.x * ic - u.y * s;
	rotation[2][1] = u.z * u.y * ic + u.x * s;
	rotation[2][2] = c + u.z * ic;

	return mat * rotation;
}

float4x4 scale( const float4x4& mat, const float scalar ) {
	return scale( mat, float3( scalar, scalar, scalar ) );
}

float4x4 scale( const float4x4& mat, const float3& vec ) {
	return float4x4(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],
		mat[0][3],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],
		mat[1][3],

		mat[2][0],
		mat[2][1],
		mat[2][2] * vec.z,
		mat[2][3],

		mat[3][0],
		mat[3][1],
		mat[3][2],
		mat[3][3]
	);
}

inline float4x4 ortho( const float left, const float right, const float top, const float bottom, const float znear, const float zfar ) {
	const float right_plus_left = right + left;
	const float right_minus_left = right - left;
	const float top_plus_bottom = top + bottom;
	const float top_minus_bottom = top - bottom;
	const float far_minus_near = zfar - znear;

	return float4x4(
		2.000000f / right_minus_left, 0.000000f, 0.000000f, -right_plus_left / right_minus_left,
		0.000000f, 2.000000f / top_minus_bottom, 0.000000f, -top_plus_bottom / top_minus_bottom,
		0.000000f, 0.000000f, 1.000000f / far_minus_near, -znear / far_minus_near,
		0.000000f, 0.000000f, 0.000000f, 1.000000f
	);
}

float4x4 perspective( const float fovdeg, const float aspect, const float znear, const float zfar ) {
	const float far_minus_near = zfar - znear;
	const float tan_half_fov = tanf( fovdeg * 0.500000f );

	return float4x4(
		1.000000f / ( aspect * tan_half_fov ), 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 1.000000f / tan_half_fov, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, zfar / far_minus_near, -( zfar * znear ) / far_minus_near,
		0.000000f, 0.000000f, 1.000000f, 0.000000f
	);
}

float4x4 lookat( const float3& eye, const float3& target, const float3& up ) {
	const float3 forward = normalized( target - eye );
	const float3 right = normalized( cross( up, forward ) );
	const float3 up1 = cross( forward, right );

	return float4x4(
		right.x,   right.y,   right.z,   -dot( right, eye ),
		up1.x,     up1.y,     up1.z,     -dot( up1, eye ),
		forward.x, forward.y, forward.z, -dot( forward, eye ),
		0.000000f, 0.000000f, 0.000000f, 1.000000f
	);
}


// double2x2
void identity( double2x2& mat ) {
	mat[0] = { 1, 0 };
	mat[1] = { 0, 1 };
}

double2x2 transpose( const double2x2& mat ) {
	return double2x2(
		mat[0][0], mat[1][0],
		mat[0][1], mat[1][1]
	);
}

double2x2 inverse( const double2x2& mat ) {
	const double invdet = 1.000000 / determinant( mat );
	return double2x2(
		 mat[1][1] * invdet, -mat[0][1] * invdet,
		-mat[1][0] * invdet,  mat[0][0] * invdet
	);
}

double determinant( const double2x2& mat ) {
	return mat[0][0] * mat[1][1] - mat[1][0] * mat[0][1];
}

double2x2 scale( const double2x2& mat, const double scalar ) {
	return scale( mat, double3( scalar, scalar, scalar ) );
}

double2x2 scale( const double2x2& mat, const double3& vec ) {
	return double2x2(
		mat[0][0] * vec.x,
		mat[0][1],

		mat[1][0],
		mat[1][1] * vec.y
	);
}


// double2x3
void identity( double2x3& mat ) {
	mat[0] = { 1, 0, 0 };
	mat[1] = { 0, 1, 0 };
}

double3x2 transpose( const double2x3& mat ) {
	return double3x2(
		mat[0][0], mat[1][0],
		mat[0][1], mat[1][1],
		mat[0][2], mat[1][2]
	);
}

double2x3 scale( const double2x3& mat, const double scalar ) {
	return scale( mat, double3( scalar, scalar, scalar ) );
}

double2x3 scale( const double2x3& mat, const double3& vec ) {
	return double2x3(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2]
	);
}


// double2x4
void identity( double2x4& mat ) {
	mat[0] = { 1, 0, 0, 0 };
	mat[1] = { 0, 1, 0, 0 };
}

double4x2 transpose( const double2x4& mat ) {
	return double4x2(
		mat[0][0], mat[1][0],
		mat[0][1], mat[1][1],
		mat[0][2], mat[1][2],
		mat[0][3], mat[1][3]
	);
}

double2x4 scale( const double2x4& mat, const double scalar ) {
	return scale( mat, double3( scalar, scalar, scalar ) );
}

double2x4 scale( const double2x4& mat, const double3& vec ) {
	return double2x4(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],
		mat[0][3],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],
		mat[1][3]
	);
}


// double3x2
void identity( double3x2& mat ) {
	mat[0] = { 1, 0 };
	mat[1] = { 0, 1 };
	mat[2] = { 0, 0 };
}

double2x3 transpose( const double3x2& mat ) {
	return double2x3(
		mat[0][0], mat[1][0], mat[2][0],
		mat[0][1], mat[1][1], mat[2][1]
	);
}


// double3x3
void identity( double3x3& mat ) {
	mat[0] = { 1, 0, 0 };
	mat[1] = { 0, 1, 0 };
	mat[2] = { 0, 0, 1 };
}

double3x3 transpose( const double3x3& mat ) {
	return double3x3(
		mat[0][0], mat[1][0], mat[2][0],
		mat[0][1], mat[1][1], mat[2][1],
		mat[0][2], mat[1][2], mat[2][2]
	);
}

double3x3 inverse( const double3x3& mat ) {
	const double invdet = 1.000000 / determinant( mat );
	return double3x3(
		 ( mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1] ) * invdet,
		-( mat[0][1] * mat[2][2] - mat[0][2] * mat[2][1] ) * invdet,
		 ( mat[0][1] * mat[1][2] - mat[0][2] * mat[1][1] ) * invdet,

		-( mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0] ) * invdet,
		 ( mat[0][0] * mat[2][2] - mat[0][2] * mat[2][0] ) * invdet,
		-( mat[0][0] * mat[1][2] - mat[0][2] * mat[1][0] ) * invdet,

		 ( mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0] ) * invdet,
		-( mat[0][0] * mat[2][1] - mat[0][1] * mat[2][0] ) * invdet,
		 ( mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0] ) * invdet
	);
}

double determinant( const double3x3& mat ) {
	return
		+ mat[0][0] * ( mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2] )
		- mat[0][1] * ( mat[1][0] * mat[2][2] - mat[2][0] * mat[1][2] )
		+ mat[0][2] * ( mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1] );
}

double3x3 translate( const double3x3& mat, const double2& vec ) {
	return double3x3(
		mat[0][0], mat[0][1], mat[0][2] + vec.x,
		mat[1][0], mat[1][1], mat[1][2] + vec.y,
		mat[2][0], mat[2][1], mat[2][2]
	);
}

double3x3 rotate( const double3x3& mat, const double rad ) {
	const double c = cos( rad );
	const double s = sin( rad );

	return double3x3(
		mat[0] * c + mat[1] * -s,
		mat[0] * s + mat[1] * c,
		mat[2]
	);
}

double3x3 scale( const double3x3& mat, const double scalar ) {
	return scale( mat, double3( scalar, scalar, scalar ) );
}

double3x3 scale( const double3x3& mat, const double3& vec ) {
	return double3x3(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],

		mat[2][0],
		mat[2][1],
		mat[2][2] * vec.z
	);
}


// double3x4
void identity( double3x4& mat ) {
	mat[0] = { 1, 0, 0, 0 };
	mat[1] = { 0, 1, 0, 0 };
	mat[2] = { 0, 0, 1, 0 };
}

double4x3 transpose( const double3x4& mat ) {
	return double4x3(
		mat[0][0], mat[1][0], mat[2][0],
		mat[0][1], mat[1][1], mat[2][1],
		mat[0][2], mat[1][2], mat[2][2],
		mat[0][3], mat[1][3], mat[2][3]
	);
}

double3x4 translate( const double3x4& mat, const double3& vec ) {
	return double3x4(
		mat[0][0], mat[0][1], mat[0][2], mat[0][3] + vec.x,
		mat[1][0], mat[1][1], mat[1][2], mat[1][3] + vec.y,
		mat[2][0], mat[2][1], mat[2][2], mat[2][3] + vec.z
	);
}

double3x4 scale( const double3x4& mat, const double scalar ) {
	return scale( mat, double3( scalar, scalar, scalar ) );
}

double3x4 scale( const double3x4& mat, const double3& vec ) {
	return double3x4(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],
		mat[0][3],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],
		mat[1][3],

		mat[2][0],
		mat[2][1],
		mat[2][2] * vec.z,
		mat[2][3]
	);
}


// double4x2
void identity( double4x2& mat ) {
	mat[0] = { 1, 0 };
	mat[1] = { 0, 1 };
	mat[2] = { 0, 0 };
	mat[3] = { 0, 0 };
}

double2x4 transpose( const double4x2& mat ) {
	return double2x4(
		mat[0][0], mat[1][0], mat[2][0], mat[3][0],
		mat[0][1], mat[1][1], mat[2][1], mat[3][1]
	);
}


// double4x3
void identity( double4x3& mat ) {
	mat[0] = { 1, 0, 0 };
	mat[1] = { 0, 1, 0 };
	mat[2] = { 0, 0, 1 };
	mat[3] = { 0, 0, 0 };
}

double3x4 transpose( const double4x3& mat ) {
	return double3x4(
		mat[0][0], mat[1][0], mat[2][0], mat[3][0],
		mat[0][1], mat[1][1], mat[2][1], mat[3][1],
		mat[0][2], mat[1][2], mat[2][2], mat[3][2]
	);
}

double4x3 scale( const double4x3& mat, const double scalar ) {
	return scale( mat, double3( scalar, scalar, scalar ) );
}

double4x3 scale( const double4x3& mat, const double3& vec ) {
	return double4x3(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],

		mat[2][0],
		mat[2][1],
		mat[2][2] * vec.z,

		mat[3][0],
		mat[3][1],
		mat[3][2]
	);
}


// double4x4
void identity( double4x4& mat ) {
	mat[0] = { 1, 0, 0, 0 };
	mat[1] = { 0, 1, 0, 0 };
	mat[2] = { 0, 0, 1, 0 };
	mat[3] = { 0, 0, 0, 1 };
}

double4x4 transpose( const double4x4& mat ) {
	return double4x4(
		mat[0][0], mat[1][0], mat[2][0], mat[3][0],
		mat[0][1], mat[1][1], mat[2][1], mat[3][1],
		mat[0][2], mat[1][2], mat[2][2], mat[3][2],
		mat[0][3], mat[1][3], mat[2][3], mat[3][3]
	);
}

double4x4 inverse( const double4x4& mat ) {
	// uses the glm version, which is basically just an optimised version of the adjugate formula
	double sub00 = mat[2][2] * mat[3][3] - mat[3][2] * mat[2][3];
	double sub01 = mat[1][2] * mat[3][3] - mat[1][3] * mat[2][3];
	double sub02 = mat[1][2] * mat[2][3] - mat[1][3] * mat[2][2];

	double sub03 = mat[2][1] * mat[3][3] - mat[2][3] * mat[3][1];
	double sub04 = mat[1][1] * mat[3][3] - mat[1][3] * mat[3][1];
	double sub05 = mat[1][1] * mat[2][3] - mat[1][3] * mat[2][1];

	double sub06 = mat[2][1] * mat[3][2] - mat[2][2] * mat[3][1];
	double sub07 = mat[1][1] * mat[3][2] - mat[1][2] * mat[3][1];
	double sub08 = mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1];

	double sub09 = mat[2][0] * mat[3][3] - mat[3][0] * mat[2][3];
	double sub10 = mat[1][0] * mat[3][3] - mat[3][0] * mat[1][3];
	double sub11 = mat[1][0] * mat[2][3] - mat[2][0] * mat[1][3];

	double sub12 = mat[2][0] * mat[3][2] - mat[2][2] * mat[3][0];
	double sub13 = mat[1][0] * mat[3][2] - mat[1][2] * mat[3][0];
	double sub14 = mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0];

	double sub15 = mat[2][0] * mat[3][1] - mat[2][1] * mat[3][0];
	double sub16 = mat[1][0] * mat[3][1] - mat[1][1] * mat[3][0];
	double sub17 = mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0];

	double4 fac0 = double4( sub00, sub00, sub01, sub02 );
	double4 fac1 = double4( sub03, sub03, sub04, sub05 );
	double4 fac2 = double4( sub06, sub06, sub07, sub08 );
	double4 fac3 = double4( sub09, sub09, sub10, sub11 );
	double4 fac4 = double4( sub12, sub12, sub13, sub14 );
	double4 fac5 = double4( sub15, sub15, sub16, sub17 );

	double4 vec0 = double4( mat[1][0], mat[0][0], mat[0][0], mat[0][0] );
	double4 vec1 = double4( mat[1][1], mat[0][1], mat[0][1], mat[0][1] );
	double4 vec2 = double4( mat[1][2], mat[0][2], mat[0][2], mat[0][2] );
	double4 vec3 = double4( mat[1][3], mat[0][3], mat[0][3], mat[0][3] );

	double4 inv0 = vec1 * fac0 - vec2 * fac1 + vec3 * fac2;
	double4 inv1 = vec0 * fac0 - vec2 * fac3 + vec3 * fac4;
	double4 inv2 = vec0 * fac1 - vec1 * fac3 + vec3 * fac5;
	double4 inv3 = vec0 * fac2 - vec1 * fac4 + vec2 * fac5;

	double4 sign0 = double4(  1, -1,  1, -1 );
	double4 sign1 = double4( -1,  1, -1,  1 );

	double4x4 result = double4x4(
		inv0 * sign0,
		inv1 * sign1,
		inv2 * sign0,
		inv3 * sign1
	);

	double4 col0 = double4( result[0][0], result[1][0], result[2][0], result[3][0] );
	double4 dot0 = mat[0] * col0;

	const double dot1 = ( dot0.x + dot0.y ) + ( dot0.z + dot0.w );

	const double invdet = 1.000000 / dot1;

	return result * invdet;
}

double determinant( const double4x4& mat ) {
	// using glm's method where you basically take determinants from each sub matrix and cache the repeat occurences
	double sub00 = mat[2][2] * mat[3][3] - mat[3][2] * mat[2][3];
	double sub01 = mat[2][1] * mat[3][3] - mat[2][3] * mat[3][1];
	double sub02 = mat[2][1] * mat[3][2] - mat[3][1] * mat[2][2];
	double sub03 = mat[2][0] * mat[3][3] - mat[3][0] * mat[2][3];
	double sub04 = mat[2][0] * mat[3][2] - mat[3][0] * mat[2][2];
	double sub05 = mat[2][0] * mat[3][1] - mat[3][0] * mat[2][1];

	double4 cofactor = double4(
		 ( mat[1][1] * sub00 - mat[1][2] * sub01 + mat[1][3] * sub02 ),
		-( mat[1][0] * sub00 - mat[1][2] * sub03 + mat[1][3] * sub04 ),
		 ( mat[1][0] * sub01 - mat[1][1] * sub03 + mat[1][3] * sub05 ),
		-( mat[1][0] * sub02 - mat[1][1] * sub04 + mat[1][2] * sub05 )
	);

	return
		mat[0][0] * cofactor.x + mat[0][1] * cofactor.y +
		mat[0][2] * cofactor.z + mat[0][3] * cofactor.w;
}

double4x4 translate( const double4x4& mat, const double3& vec ) {
	return double4x4(
		mat[0][0], mat[0][1], mat[0][2], mat[0][3] + vec.x,
		mat[1][0], mat[1][1], mat[1][2], mat[1][3] + vec.y,
		mat[2][0], mat[2][1], mat[2][2], mat[2][3] + vec.z,
		mat[3][0], mat[3][1], mat[3][2], mat[3][3]
	);
}

double4x4 rotate( const double4x4& mat, const double rad, const double3& axis ) {
	const double c = cos( rad );
	const double s = sin( rad );

	double3 u = normalized( axis );
	double ic = 1.000000 - c;

	double4x4 rotation = mat;
	rotation[0][0] = c + u.x * ic;
	rotation[0][1] = u.x * u.y * ic - u.z * s;
	rotation[0][2] = u.x * u.z * ic + u.y * s;

	rotation[1][0] = u.y * u.x * ic + u.z * s;
	rotation[1][1] = c + u.y * ic;
	rotation[1][2] = u.y * u.z * ic - u.x * s;

	rotation[2][0] = u.z * u.x * ic - u.y * s;
	rotation[2][1] = u.z * u.y * ic + u.x * s;
	rotation[2][2] = c + u.z * ic;

	return mat * rotation;
}

double4x4 scale( const double4x4& mat, const double scalar ) {
	return scale( mat, double3( scalar, scalar, scalar ) );
}

double4x4 scale( const double4x4& mat, const double3& vec ) {
	return double4x4(
		mat[0][0] * vec.x,
		mat[0][1],
		mat[0][2],
		mat[0][3],

		mat[1][0],
		mat[1][1] * vec.y,
		mat[1][2],
		mat[1][3],

		mat[2][0],
		mat[2][1],
		mat[2][2] * vec.z,
		mat[2][3],

		mat[3][0],
		mat[3][1],
		mat[3][2],
		mat[3][3]
	);
}

inline double4x4 ortho( const double left, const double right, const double top, const double bottom, const double znear, const double zfar ) {
	const double right_plus_left = right + left;
	const double right_minus_left = right - left;
	const double top_plus_bottom = top + bottom;
	const double top_minus_bottom = top - bottom;
	const double far_minus_near = zfar - znear;

	return double4x4(
		2.000000 / right_minus_left, 0.000000, 0.000000, -right_plus_left / right_minus_left,
		0.000000, 2.000000 / top_minus_bottom, 0.000000, -top_plus_bottom / top_minus_bottom,
		0.000000, 0.000000, 1.000000 / far_minus_near, -znear / far_minus_near,
		0.000000, 0.000000, 0.000000, 1.000000
	);
}

double4x4 perspective( const double fovdeg, const double aspect, const double znear, const double zfar ) {
	const double far_minus_near = zfar - znear;
	const double tan_half_fov = tan( fovdeg * 0.500000 );

	return double4x4(
		1.000000 / ( aspect * tan_half_fov ), 0.000000, 0.000000, 0.000000,
		0.000000, 1.000000 / tan_half_fov, 0.000000, 0.000000,
		0.000000, 0.000000, zfar / far_minus_near, -( zfar * znear ) / far_minus_near,
		0.000000, 0.000000, 1.000000, 0.000000
	);
}

double4x4 lookat( const double3& eye, const double3& target, const double3& up ) {
	const double3 forward = normalized( target - eye );
	const double3 right = normalized( cross( up, forward ) );
	const double3 up1 = cross( forward, right );

	return double4x4(
		right.x,   right.y,   right.z,   -dot( right, eye ),
		up1.x,     up1.y,     up1.z,     -dot( up1, eye ),
		forward.x, forward.y, forward.z, -dot( forward, eye ),
		0.000000, 0.000000, 0.000000, 1.000000
	);
}


