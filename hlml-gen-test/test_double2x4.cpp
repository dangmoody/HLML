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

TEMPER_TEST( TestAssignment_double2x4 ) {
	double2x4 mat;

	// fill single value
	mat = double2x4( 999.0 );
	TEMPER_EXPECT_TRUE( mat[0] == double4( 999.0, 0.0, 0.0, 0.0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double4( 0.0, 999.0, 0.0, 0.0 ) );

	// row filling
	mat = double2x4(
		double4( 0, 1, 2, 3 ),
		double4( 4, 5, 6, 7 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == double4( 0, 1, 2, 3 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double4( 4, 5, 6, 7 ) );

	// all values filled
	mat = double2x4(
		8, 7, 6, 5, 
		4, 3, 2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == double4( 8, 7, 6, 5 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double4( 4, 3, 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_double2x4 ) {
	double2x4 a = double2x4(
		6.0, 6.0, 
		6.0, 6.0, 
		6.0, 6.0, 
		6.0,6.0
	);
	double2x4 b = double2x4(
		2.0, 3.0, 4.0, 4.0,
		6.0, 6.0, 8.0, 8.0
	);
	double2x4 c = a + b;

	TEMPER_EXPECT_TRUE( c == double2x4(
		8.0, 9.0, 10.0, 10.0,
		12.0, 12.0, 14.0, 14.0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_double2x4 ) {
	double2x4 a = double2x4(
		6.0, 6.0, 
		6.0, 6.0, 
		6.0, 6.0, 
		6.0,6.0
	);
	double2x4 b = double2x4(
		2.0, 3.0, 4.0, 4.0,
		6.0, 6.0, 8.0, 8.0
	);
	double2x4 c = a - b;

	TEMPER_EXPECT_TRUE( c == double2x4(
		4.0, 3.0, 2.0, 2.0,
		0.0, 0.0, -2.0, -2.0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_double2x4 ) {
	double2x4 a = double2x4(
		6.0, 6.0, 
		6.0, 6.0, 
		6.0, 6.0, 
		6.0,6.0
	);
	double2x4 b = double2x4(
		2.0, 3.0, 4.0, 4.0,
		6.0, 6.0, 8.0, 8.0
	);
	double2x4 c = a * b;

	TEMPER_EXPECT_TRUE( c == double2x4(
		0.0, 1.0, 2.0, 3.0,
		1.0, 2.0, 3.0, 4.0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_double2x4 ) {
	double2x4 a = double2x4(
		2.0, 3.0, 4.0, 4.0,
		6.0, 6.0, 8.0, 8.0
	);
	double2x4 b = double2x4(
		6.0, 6.0, 
		6.0, 6.0, 
		6.0, 6.0, 
		6.0,6.0
	);
	double2x4 c = b / a;

	TEMPER_EXPECT_TRUE( c == double2x4(
		3.000000, 2.000000, 1.500000, 1.500000,
		1.000000, 1.000000, 0.750000, 0.750000
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_double2x4 ) {
	double2x4 mat;

	TEMPER_EXPECT_TRUE( mat[0] == double4( 1.0, 0.0, 0.0, 0.0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double4( 0.0, 1.0, 0.0, 0.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_double2x4 ) {
	double2x4 mat0 = double2x4(
		1.0, 1.0, 1.0, 1.0,
		1.0, 1.0, 1.0, 1.0
	);
	double2x4 mat1 = double2x4(
		2.0, 2.0, 2.0, 2.0,
		2.0, 2.0, 2.0, 2.0
	);
	double2x4 mat2 = double2x4(
		3.0, 3.0, 3.0, 3.0,
		3.0, 3.0, 3.0, 3.0
	);
	double2x4 mat3 = double2x4(
		4.0, 4.0, 4.0, 4.0,
		4.0, 4.0, 4.0, 4.0
	);

	bool2x4 test0 = mat0 <= mat0;
	bool2x4 test1 = mat0 >= mat0;
	bool2x4 test2 = mat0 < mat1;

	bool2x4 test3 = mat1 <= mat1;
	bool2x4 test4 = mat1 >= mat1;
	bool2x4 test5 = mat1 < mat2;
	bool2x4 test6 = mat1 > mat0;

	bool2x4 test7 = mat2 <= mat2;
	bool2x4 test8 = mat2 >= mat2;
	bool2x4 test9 = mat2 < mat3;
	bool2x4 test10 = mat2 > mat1;

	bool2x4 test11 = mat3 <= mat3;
	bool2x4 test12 = mat3 >= mat3;
	bool2x4 test13 = mat3 > mat2;

	TEMPER_EXPECT_TRUE( test0 == bool2x4(
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test1 == bool2x4(
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test2 == bool2x4(
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test3 == bool2x4(
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test4 == bool2x4(
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test5 == bool2x4(
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test6 == bool2x4(
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test7 == bool2x4(
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test8 == bool2x4(
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test9 == bool2x4(
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test10 == bool2x4(
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test11 == bool2x4(
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test12 == bool2x4(
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test13 == bool2x4(
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_double2x4 ) {
	double2x4 id = double2x4(
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0
	);

	double2x4 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_double2x4 ) {
	double2x4 mat = double2x4(
		0.0, 1.0, 2.0, 3.0,
		4.0, 5.0, 6.0, 7.0
	);
	double4x2 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == double4x2(
		0.0, 4.0,
		1.0, 5.0,
		2.0, 6.0,
		3.0, 7.0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_double2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestRotate_double2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestScale_double2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestOrtho_double2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestPerspective_double2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestLookAt_double2x4 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_double2x4 ) {
	TEMPER_RUN_TEST( TestAssignment_double2x4 );

	TEMPER_RUN_TEST( TestArithmeticAddition_double2x4 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_double2x4 );
	TEMPER_SKIP_TEST( TestArithmeticMultiplication_double2x4, "Give me a minute to think about how to structure this one." );
	TEMPER_RUN_TEST( TestArithmeticDivision_double2x4 );

	TEMPER_RUN_TEST( TestArray_double2x4 );
	TEMPER_RUN_TEST( TestRelational_double2x4 );

	TEMPER_RUN_TEST( TestIdentity_double2x4 );
	TEMPER_RUN_TEST( TestTranspose_double2x4 );
	TEMPER_SKIP_TEST( TestTranslate_double2x4, "TODO" );
	TEMPER_SKIP_TEST( TestRotate_double2x4, "TODO" );
	TEMPER_SKIP_TEST( TestScale_double2x4, "TODO" );

	TEMPER_SKIP_TEST( TestOrtho_double2x4, "TODO" );
	TEMPER_SKIP_TEST( TestPerspective_double2x4, "TODO" );
	TEMPER_SKIP_TEST( TestLookAt_double2x4, "TODO" );
};
