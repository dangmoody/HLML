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

TEMPER_TEST( TestAssignment_double4x3 ) {
	double4x3 mat;

	// fill single value
	mat = double4x3( 999.0 );
	TEMPER_EXPECT_TRUE( mat[0] == double3( 999.0, 0.0, 0.0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 0.0, 999.0, 0.0 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double3( 0.0, 0.0, 999.0 ) );
	TEMPER_EXPECT_TRUE( mat[3] == double3( 0.0, 0.0, 0.0 ) );

	// row filling
	mat = double4x3(
		double3( 0, 1, 2 ),
		double3( 3, 4, 5 ),
		double3( 6, 7, 8 ),
		double3( 9, 10, 11 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == double3( 0, 1, 2 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 3, 4, 5 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double3( 6, 7, 8 ) );
	TEMPER_EXPECT_TRUE( mat[3] == double3( 9, 10, 11 ) );

	// all values filled
	mat = double4x3(
		12, 11, 10, 
		9, 8, 7, 
		6, 5, 4, 
		3, 2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == double3( 12, 11, 10 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 9, 8, 7 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double3( 6, 5, 4 ) );
	TEMPER_EXPECT_TRUE( mat[3] == double3( 3, 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_double4x3 ) {
	double4x3 a = double4x3(
		6.0, 6.0, 6.0, 6.0, 
		6.0, 6.0, 6.0, 6.0, 
		6.0,6.0,6.0,6.0
	);
	double4x3 b = double4x3(
		2.0, 3.0, 4.0,
		6.0, 6.0, 8.0,
		10.0, 10.0, 12.0,
		18.0, 18.0, 24.0
	);
	double4x3 c = a + b;

	TEMPER_EXPECT_TRUE( c == double4x3(
		8.0, 9.0, 10.0,
		12.0, 12.0, 14.0,
		16.0, 16.0, 18.0,
		24.0, 24.0, 30.0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_double4x3 ) {
	double4x3 a = double4x3(
		6.0, 6.0, 6.0, 6.0, 
		6.0, 6.0, 6.0, 6.0, 
		6.0,6.0,6.0,6.0
	);
	double4x3 b = double4x3(
		2.0, 3.0, 4.0,
		6.0, 6.0, 8.0,
		10.0, 10.0, 12.0,
		18.0, 18.0, 24.0
	);
	double4x3 c = a - b;

	TEMPER_EXPECT_TRUE( c == double4x3(
		4.0, 3.0, 2.0,
		0.0, 0.0, -2.0,
		-4.0, -4.0, -6.0,
		-12.0, -12.0, -18.0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_double4x3 ) {
	double4x3 a = double4x3(
		6.0, 6.0, 6.0, 6.0, 
		6.0, 6.0, 6.0, 6.0, 
		6.0,6.0,6.0,6.0
	);
	double4x3 b = double4x3(
		2.0, 3.0, 4.0,
		6.0, 6.0, 8.0,
		10.0, 10.0, 12.0,
		18.0, 18.0, 24.0
	);
	double4x3 c = a * b;

	TEMPER_EXPECT_TRUE( c == double4x3(
		0.0, 1.0, 2.0,
		1.0, 2.0, 3.0,
		2.0, 3.0, 4.0,
		3.0, 4.0, 5.0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_double4x3 ) {
	double4x3 a = double4x3(
		2.0, 3.0, 4.0,
		6.0, 6.0, 8.0,
		10.0, 10.0, 12.0,
		18.0, 18.0, 24.0
	);
	double4x3 b = double4x3(
		6.0, 6.0, 6.0, 6.0, 
		6.0, 6.0, 6.0, 6.0, 
		6.0,6.0,6.0,6.0
	);
	double4x3 c = b / a;

	TEMPER_EXPECT_TRUE( c == double4x3(
		3.000000, 2.000000, 1.500000,
		1.000000, 1.000000, 0.750000,
		0.600000, 0.600000, 0.500000,
		0.333333, 0.333333, 0.250000
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_double4x3 ) {
	double4x3 mat;

	TEMPER_EXPECT_TRUE( mat[0] == double3( 1.0, 0.0, 0.0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 0.0, 1.0, 0.0 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double3( 0.0, 0.0, 1.0 ) );
	TEMPER_EXPECT_TRUE( mat[3] == double3( 0.0, 0.0, 0.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_double4x3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestIdentity_double4x3 ) {
	double4x3 id = double4x3(
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0,
		0.0, 0.0, 0.0
	);

	double4x3 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_double4x3 ) {
	double4x3 mat = double4x3(
		0.0, 1.0, 2.0,
		3.0, 4.0, 5.0,
		6.0, 7.0, 8.0,
		9.0, 10.0, 11.0
	);
	double3x4 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == double3x4(
		0.0, 3.0, 6.0, 9.0,
		1.0, 4.0, 7.0, 10.0,
		2.0, 5.0, 8.0, 11.0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestInverse_double4x3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestDeterminant_double4x3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestTranslate_double4x3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestRotate_double4x3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestScale_double4x3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestOrtho_double4x3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestPerspective_double4x3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestLookAt_double4x3 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_double4x3 ) {
	TEMPER_RUN_TEST( TestAssignment_double4x3 );

	TEMPER_RUN_TEST( TestArithmeticAddition_double4x3 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_double4x3 );
	TEMPER_SKIP_TEST( TestArithmeticMultiplication_double4x3, "Give me a minute to think about how to structure this one." );
	TEMPER_RUN_TEST( TestArithmeticDivision_double4x3 );

	TEMPER_RUN_TEST( TestArray_double4x3 );
	TEMPER_SKIP_TEST( TestRelational_double4x3, "TODO" );

	TEMPER_RUN_TEST( TestIdentity_double4x3 );
	TEMPER_RUN_TEST( TestTranspose_double4x3 );
	TEMPER_SKIP_TEST( TestInverse_double4x3, "TODO" );
	TEMPER_SKIP_TEST( TestDeterminant_double4x3, "TODO" );

	TEMPER_SKIP_TEST( TestTranslate_double4x3, "TODO" );
	TEMPER_SKIP_TEST( TestRotate_double4x3, "TODO" );
	TEMPER_SKIP_TEST( TestScale_double4x3, "TODO" );

	TEMPER_SKIP_TEST( TestOrtho_double4x3, "TODO" );
	TEMPER_SKIP_TEST( TestPerspective_double4x3, "TODO" );
	TEMPER_SKIP_TEST( TestLookAt_double4x3, "TODO" );
};
