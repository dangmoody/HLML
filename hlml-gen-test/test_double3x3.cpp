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

TEMPER_TEST( TestAssignment_double3x3 ) {
	double3x3 mat;

	// fill single value
	mat = double3x3( 999.0 );
	TEMPER_EXPECT_TRUE( mat[0] == double3( 999.0, 0.0, 0.0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 0.0, 999.0, 0.0 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double3( 0.0, 0.0, 999.0 ) );

	// row filling
	mat = double3x3(
		double3( 0, 1, 2 ),
		double3( 3, 4, 5 ),
		double3( 6, 7, 8 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == double3( 0, 1, 2 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 3, 4, 5 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double3( 6, 7, 8 ) );

	// all values filled
	mat = double3x3(
		9, 8, 7, 
		6, 5, 4, 
		3, 2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == double3( 9, 8, 7 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 6, 5, 4 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double3( 3, 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_double3x3 ) {
	double3x3 a = double3x3(
		6.0, 6.0, 6.0, 
		6.0, 6.0, 6.0, 
		6.0,6.0,6.0
	);
	double3x3 b = double3x3(
		2.0, 3.0, 4.0,
		6.0, 6.0, 8.0,
		10.0, 10.0, 12.0
	);
	double3x3 c = a + b;

	TEMPER_EXPECT_TRUE( c == double3x3(
		8.0, 9.0, 10.0,
		12.0, 12.0, 14.0,
		16.0, 16.0, 18.0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_double3x3 ) {
	double3x3 a = double3x3(
		6.0, 6.0, 6.0, 
		6.0, 6.0, 6.0, 
		6.0,6.0,6.0
	);
	double3x3 b = double3x3(
		2.0, 3.0, 4.0,
		6.0, 6.0, 8.0,
		10.0, 10.0, 12.0
	);
	double3x3 c = a - b;

	TEMPER_EXPECT_TRUE( c == double3x3(
		4.0, 3.0, 2.0,
		0.0, 0.0, -2.0,
		-4.0, -4.0, -6.0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_double3x3 ) {
	double3x3 a = double3x3(
		6.0, 6.0, 6.0, 
		6.0, 6.0, 6.0, 
		6.0,6.0,6.0
	);
	double3x3 b = double3x3(
		2.0, 3.0, 4.0,
		6.0, 6.0, 8.0,
		10.0, 10.0, 12.0
	);
	double3x3 c = a * b;

	TEMPER_EXPECT_TRUE( c == double3x3(
		0.0, 1.0, 2.0,
		1.0, 2.0, 3.0,
		2.0, 3.0, 4.0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_double3x3 ) {
	double3x3 a = double3x3(
		2.0, 3.0, 4.0,
		6.0, 6.0, 8.0,
		10.0, 10.0, 12.0
	);
	double3x3 b = a / a;
	double3x3 identity = double3x3(
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0
	);

	TEMPER_EXPECT_TRUE( b == identity );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_double3x3 ) {
	double3x3 mat;

	TEMPER_EXPECT_TRUE( mat[0] == double3( 1.0, 0.0, 0.0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 0.0, 1.0, 0.0 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double3( 0.0, 0.0, 1.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_double3x3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestIdentity_double3x3 ) {
	double3x3 id = double3x3(
		1.0, 0.0, 0.0,
		0.0, 1.0, 0.0,
		0.0, 0.0, 1.0
	);

	double3x3 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_double3x3 ) {
	double3x3 mat = double3x3(
		0.0, 1.0, 2.0,
		3.0, 4.0, 5.0,
		6.0, 7.0, 8.0
	);
	double3x3 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == double3x3(
		0.0, 3.0, 6.0,
		1.0, 4.0, 7.0,
		2.0, 5.0, 8.0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestInverse_double3x3 ) {
	double3x3 identityMatrix;

	double3x3 mat = double3x3(
		6.0, 2.0, 3.0,
		2.0, 7.0, 2.0,
		3.0, 2.0, 6.0
	);
	double3x3 matInverse = inverse( mat );

	TEMPER_EXPECT_TRUE( mat * matInverse == identityMatrix );

	TEMPER_PASS();
}

TEMPER_TEST( TestDeterminant_double3x3 ) {
	double3x3 mat = double3x3(
		6.0, 2.0, 3.0,
		2.0, 7.0, 2.0,
		3.0, 2.0, 6.0
	);
	double det = determinant( mat );

	TEMPER_EXPECT_TRUE( floateq( det, 165.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_double3x3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestRotate_double3x3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestScale_double3x3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestOrtho_double3x3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestPerspective_double3x3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestLookAt_double3x3 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_double3x3 ) {
	TEMPER_RUN_TEST( TestAssignment_double3x3 );

	TEMPER_RUN_TEST( TestArithmeticAddition_double3x3 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_double3x3 );
	TEMPER_SKIP_TEST( TestArithmeticMultiplication_double3x3, "Give me a minute to think about how to structure this one." );
	TEMPER_RUN_TEST( TestArithmeticDivision_double3x3 );

	TEMPER_RUN_TEST( TestArray_double3x3 );
	TEMPER_SKIP_TEST( TestRelational_double3x3, "TODO" );

	TEMPER_RUN_TEST( TestIdentity_double3x3 );
	TEMPER_RUN_TEST( TestTranspose_double3x3 );
	TEMPER_RUN_TEST( TestDeterminant_double3x3 );
	TEMPER_RUN_TEST( TestInverse_double3x3 );
	TEMPER_SKIP_TEST( TestTranslate_double3x3, "TODO" );
	TEMPER_SKIP_TEST( TestRotate_double3x3, "TODO" );
	TEMPER_SKIP_TEST( TestScale_double3x3, "TODO" );

	TEMPER_SKIP_TEST( TestOrtho_double3x3, "TODO" );
	TEMPER_SKIP_TEST( TestPerspective_double3x3, "TODO" );
	TEMPER_SKIP_TEST( TestLookAt_double3x3, "TODO" );
};
