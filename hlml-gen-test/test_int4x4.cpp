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

#include "../out/gen/hlml_functions_matrix.h"

#include <temper.h>

TEMPER_TEST( TestAssignment_int4x4 ) {
	int4x4 mat;

	// fill single value
	mat = int4x4( 999 );
	TEMPER_EXPECT_TRUE( mat[0] == int4( 999, 0, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int4( 0, 999, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[2] == int4( 0, 0, 999, 0 ) );
	TEMPER_EXPECT_TRUE( mat[3] == int4( 0, 0, 0, 999 ) );

	// row filling
	mat = int4x4(
		int4( 0, 1, 2, 3 ),
		int4( 4, 5, 6, 7 ),
		int4( 8, 9, 10, 11 ),
		int4( 12, 13, 14, 15 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == int4( 0, 1, 2, 3 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int4( 4, 5, 6, 7 ) );
	TEMPER_EXPECT_TRUE( mat[2] == int4( 8, 9, 10, 11 ) );
	TEMPER_EXPECT_TRUE( mat[3] == int4( 12, 13, 14, 15 ) );

	// all values filled
	mat = int4x4(
		16, 15, 14, 13, 
		12, 11, 10, 9, 
		8, 7, 6, 5, 
		4, 3, 2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == int4( 16, 15, 14, 13 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int4( 12, 11, 10, 9 ) );
	TEMPER_EXPECT_TRUE( mat[2] == int4( 8, 7, 6, 5 ) );
	TEMPER_EXPECT_TRUE( mat[3] == int4( 4, 3, 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_int4x4 ) {
	int4x4 a = int4x4(
		6, 6, 6, 6, 
		6, 6, 6, 6, 
		6, 6, 6, 6, 
		6,6,6,6
	);
	int4x4 b = int4x4(
		2, 3, 4, 4,
		6, 6, 8, 8,
		10, 10, 12, 12,
		18, 18, 24, 24
	);
	int4x4 c = a + b;

	TEMPER_EXPECT_TRUE( c == int4x4(
		8, 9, 10, 10,
		12, 12, 14, 14,
		16, 16, 18, 18,
		24, 24, 30, 30
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_int4x4 ) {
	int4x4 a = int4x4(
		6, 6, 6, 6, 
		6, 6, 6, 6, 
		6, 6, 6, 6, 
		6,6,6,6
	);
	int4x4 b = int4x4(
		2, 3, 4, 4,
		6, 6, 8, 8,
		10, 10, 12, 12,
		18, 18, 24, 24
	);
	int4x4 c = a - b;

	TEMPER_EXPECT_TRUE( c == int4x4(
		4, 3, 2, 2,
		0, 0, -2, -2,
		-4, -4, -6, -6,
		-12, -12, -18, -18
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_int4x4 ) {
	int4x4 a = int4x4(
		6, 6, 6, 6, 
		6, 6, 6, 6, 
		6, 6, 6, 6, 
		6,6,6,6
	);
	int4x4 b = int4x4(
		2, 3, 4, 4,
		6, 6, 8, 8,
		10, 10, 12, 12,
		18, 18, 24, 24
	);
	int4x4 c = a * b;

	TEMPER_EXPECT_TRUE( c == int4x4(
		0, 1, 2, 3,
		1, 2, 3, 4,
		2, 3, 4, 5,
		3, 4, 5, 6
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_int4x4 ) {
	int4x4 a = int4x4(
		2, 3, 4, 4,
		6, 6, 8, 8,
		10, 10, 12, 12,
		18, 18, 24, 24
	);
	int4x4 b = int4x4(
		6, 6, 6, 6, 
		6, 6, 6, 6, 
		6, 6, 6, 6, 
		6,6,6,6
	);
	int4x4 c = b / a;

	TEMPER_EXPECT_TRUE( c == int4x4(
		3, 2, 1, 1,
		1, 1, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_int4x4 ) {
	int4x4 mat;

	TEMPER_EXPECT_TRUE( mat[0] == int4( 1, 0, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int4( 0, 1, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[2] == int4( 0, 0, 1, 0 ) );
	TEMPER_EXPECT_TRUE( mat[3] == int4( 0, 0, 0, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_int4x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestIdentity_int4x4 ) {
	int4x4 id = int4x4(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);

	int4x4 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_int4x4 ) {
	int4x4 mat = int4x4(
		0, 1, 2, 3,
		4, 5, 6, 7,
		8, 9, 10, 11,
		12, 13, 14, 15
	);
	int4x4 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == int4x4(
		0, 4, 8, 12,
		1, 5, 9, 13,
		2, 6, 10, 14,
		3, 7, 11, 15
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDeterminant_int4x4 ) {
	int4x4 mat = int4x4(
		6, 2, 3, 4,
		2, 7, 5, 3,
		3, 5, 7, 2,
		4, 3, 2, 6
	);
	int32_t det = determinant( mat );

	TEMPER_EXPECT_TRUE( det == 285 );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_int4x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestRotate_int4x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestScale_int4x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestOrtho_int4x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestPerspective_int4x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestLookAt_int4x4 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_int4x4 ) {
	TEMPER_RUN_TEST( TestAssignment_int4x4 );

	TEMPER_RUN_TEST( TestArithmeticAddition_int4x4 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_int4x4 );
	TEMPER_SKIP_TEST( TestArithmeticMultiplication_int4x4, "Give me a minute to think about how to structure this one." );
	TEMPER_RUN_TEST( TestArithmeticDivision_int4x4 );

	TEMPER_RUN_TEST( TestArray_int4x4 );
	TEMPER_SKIP_TEST( TestRelational_int4x4, "TODO" );

	TEMPER_RUN_TEST( TestIdentity_int4x4 );
	TEMPER_RUN_TEST( TestTranspose_int4x4 );
	TEMPER_RUN_TEST( TestDeterminant_int4x4 );
	TEMPER_SKIP_TEST( TestTranslate_int4x4, "TODO" );
	TEMPER_SKIP_TEST( TestRotate_int4x4, "TODO" );
	TEMPER_SKIP_TEST( TestScale_int4x4, "TODO" );

	TEMPER_SKIP_TEST( TestOrtho_int4x4, "TODO" );
	TEMPER_SKIP_TEST( TestPerspective_int4x4, "TODO" );
	TEMPER_SKIP_TEST( TestLookAt_int4x4, "TODO" );
};
