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

TEMPER_TEST( TestAssignment_double2x2 ) {
	double2x2 mat;

	// fill single value
	mat = double2x2( 999.0 );
	TEMPER_EXPECT_TRUE( mat[0] == double2( 999.0, 0.0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double2( 0.0, 999.0 ) );

	// row filling
	mat = double2x2(
		double2( 0, 1 ),
		double2( 2, 3 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == double2( 0, 1 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double2( 2, 3 ) );

	// all values filled
	mat = double2x2(
		4, 3, 
		2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == double2( 4, 3 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double2( 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_double2x2 ) {
	double2x2 a = double2x2(
		6.0, 6.0, 
		6.0,6.0
	);
	double2x2 b = double2x2(
		2.0, 3.0,
		6.0, 6.0
	);
	double2x2 c = a + b;

	TEMPER_EXPECT_TRUE( c == double2x2(
		8.0, 9.0,
		12.0, 12.0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_double2x2 ) {
	double2x2 a = double2x2(
		6.0, 6.0, 
		6.0,6.0
	);
	double2x2 b = double2x2(
		2.0, 3.0,
		6.0, 6.0
	);
	double2x2 c = a - b;

	TEMPER_EXPECT_TRUE( c == double2x2(
		4.0, 3.0,
		0.0, 0.0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_double2x2 ) {
	double2x2 a = double2x2(
		6.0, 6.0, 
		6.0,6.0
	);
	double2x2 b = double2x2(
		2.0, 3.0,
		6.0, 6.0
	);
	double2x2 c = a * b;

	TEMPER_EXPECT_TRUE( c == double2x2(
		0.0, 1.0,
		1.0, 2.0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_double2x2 ) {
	double2x2 a = double2x2(
		2.0, 3.0,
		6.0, 6.0
	);
	double2x2 b = a / a;
	double2x2 identity = double2x2(
		1.0, 0.0,
		0.0, 1.0
	);

	TEMPER_EXPECT_TRUE( b == identity );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_double2x2 ) {
	double2x2 mat;

	TEMPER_EXPECT_TRUE( mat[0] == double2( 1.0, 0.0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double2( 0.0, 1.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_double2x2 ) {
	double2x2 mat0 = double2x2(
		1.0, 1.0,
		1.0, 1.0
	);
	double2x2 mat1 = double2x2(
		2.0, 2.0,
		2.0, 2.0
	);
	double2x2 mat2 = double2x2(
		3.0, 3.0,
		3.0, 3.0
	);
	double2x2 mat3 = double2x2(
		4.0, 4.0,
		4.0, 4.0
	);

	bool2x2 test0 = mat0 <= mat0;
	bool2x2 test1 = mat0 >= mat0;
	bool2x2 test2 = mat0 < mat1;

	bool2x2 test3 = mat1 <= mat1;
	bool2x2 test4 = mat1 >= mat1;
	bool2x2 test5 = mat1 < mat2;
	bool2x2 test6 = mat1 > mat0;

	bool2x2 test7 = mat2 <= mat2;
	bool2x2 test8 = mat2 >= mat2;
	bool2x2 test9 = mat2 < mat3;
	bool2x2 test10 = mat2 > mat1;

	bool2x2 test11 = mat3 <= mat3;
	bool2x2 test12 = mat3 >= mat3;
	bool2x2 test13 = mat3 > mat2;

	TEMPER_EXPECT_TRUE( test0 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test1 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test2 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test3 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test4 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test5 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test6 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test7 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test8 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test9 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test10 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test11 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test12 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test13 == bool2x2(
		true, true,
		true, true
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_double2x2 ) {
	double2x2 id = double2x2(
		1.0, 0.0,
		0.0, 1.0
	);

	double2x2 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_double2x2 ) {
	double2x2 mat = double2x2(
		0.0, 1.0,
		2.0, 3.0
	);
	double2x2 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == double2x2(
		0.0, 2.0,
		1.0, 3.0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestInverse_double2x2 ) {
	double2x2 identityMatrix;

	double2x2 mat = double2x2(
		6.0, 2.0,
		2.0, 6.0
	);
	double2x2 matInverse = inverse( mat );

	TEMPER_EXPECT_TRUE( mat * matInverse == identityMatrix );

	TEMPER_PASS();
}

TEMPER_TEST( TestDeterminant_double2x2 ) {
	double2x2 mat = double2x2(
		6.0, 2.0,
		2.0, 6.0
	);
	double det = determinant( mat );

	TEMPER_EXPECT_TRUE( floateq( det, 32.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRotate_double2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestScale_double2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestOrtho_double2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestPerspective_double2x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestLookAt_double2x2 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_double2x2 ) {
	TEMPER_RUN_TEST( TestAssignment_double2x2 );

	TEMPER_RUN_TEST( TestArithmeticAddition_double2x2 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_double2x2 );
	TEMPER_SKIP_TEST( TestArithmeticMultiplication_double2x2, "Give me a minute to think about how to structure this one." );
	TEMPER_RUN_TEST( TestArithmeticDivision_double2x2 );

	TEMPER_RUN_TEST( TestArray_double2x2 );
	TEMPER_RUN_TEST( TestRelational_double2x2 );

	TEMPER_RUN_TEST( TestIdentity_double2x2 );
	TEMPER_RUN_TEST( TestTranspose_double2x2 );
	TEMPER_RUN_TEST( TestDeterminant_double2x2 );
	TEMPER_RUN_TEST( TestInverse_double2x2 );

	TEMPER_SKIP_TEST( TestRotate_double2x2, "TODO" );
	TEMPER_SKIP_TEST( TestScale_double2x2, "TODO" );

	TEMPER_SKIP_TEST( TestOrtho_double2x2, "TODO" );
	TEMPER_SKIP_TEST( TestPerspective_double2x2, "TODO" );
	TEMPER_SKIP_TEST( TestLookAt_double2x2, "TODO" );
};
