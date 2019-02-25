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

TEMPER_TEST( TestAssignment_int4x2 ) {
	int4x2 mat;

	// fill single value
	mat = int4x2( 999 );
	TEMPER_EXPECT_TRUE( mat[0] == int2( 999, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int2( 0, 999 ) );
	TEMPER_EXPECT_TRUE( mat[2] == int2( 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[3] == int2( 0, 0 ) );

	// row filling
	mat = int4x2(
		int2( 0, 1 ),
		int2( 2, 3 ),
		int2( 4, 5 ),
		int2( 6, 7 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == int2( 0, 1 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int2( 2, 3 ) );
	TEMPER_EXPECT_TRUE( mat[2] == int2( 4, 5 ) );
	TEMPER_EXPECT_TRUE( mat[3] == int2( 6, 7 ) );

	// all values filled
	mat = int4x2(
		8, 7, 
		6, 5, 
		4, 3, 
		2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == int2( 8, 7 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int2( 6, 5 ) );
	TEMPER_EXPECT_TRUE( mat[2] == int2( 4, 3 ) );
	TEMPER_EXPECT_TRUE( mat[3] == int2( 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_int4x2 ) {
	int4x2 a = int4x2(
		6, 6, 6, 6, 
		6,6,6,6
	);
	int4x2 b = int4x2(
		2, 3,
		6, 6,
		10, 10,
		18, 18
	);
	int4x2 c = a + b;

	TEMPER_EXPECT_TRUE( c == int4x2(
		8, 9,
		12, 12,
		16, 16,
		24, 24
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_int4x2 ) {
	int4x2 a = int4x2(
		6, 6, 6, 6, 
		6,6,6,6
	);
	int4x2 b = int4x2(
		2, 3,
		6, 6,
		10, 10,
		18, 18
	);
	int4x2 c = a - b;

	TEMPER_EXPECT_TRUE( c == int4x2(
		4, 3,
		0, 0,
		-4, -4,
		-12, -12
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_int4x2 ) {
	int4x2 a = int4x2(
		6, 6, 6, 6, 
		6,6,6,6
	);
	int4x2 b = int4x2(
		2, 3,
		6, 6,
		10, 10,
		18, 18
	);
	int4x2 c = a * b;

	TEMPER_EXPECT_TRUE( c == int4x2(
		0, 1,
		1, 2,
		2, 3,
		3, 4
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_int4x2 ) {
	int4x2 a = int4x2(
		2, 3,
		6, 6,
		10, 10,
		18, 18
	);
	int4x2 b = int4x2(
		6, 6, 6, 6, 
		6,6,6,6
	);
	int4x2 c = b / a;

	TEMPER_EXPECT_TRUE( c == int4x2(
		3, 2,
		1, 1,
		0, 0,
		0, 0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_int4x2 ) {
	int4x2 mat;

	TEMPER_EXPECT_TRUE( mat[0] == int2( 1, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int2( 0, 1 ) );
	TEMPER_EXPECT_TRUE( mat[2] == int2( 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[3] == int2( 0, 0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_int4x2 ) {
	int4x2 mat0 = int4x2(
		1, 1,
		1, 1,
		1, 1,
		1, 1
	);
	int4x2 mat1 = int4x2(
		2, 2,
		2, 2,
		2, 2,
		2, 2
	);
	int4x2 mat2 = int4x2(
		3, 3,
		3, 3,
		3, 3,
		3, 3
	);
	int4x2 mat3 = int4x2(
		4, 4,
		4, 4,
		4, 4,
		4, 4
	);

	bool4x2 test0 = mat0 <= mat0;
	bool4x2 test1 = mat0 >= mat0;
	bool4x2 test2 = mat0 < mat1;

	bool4x2 test3 = mat1 <= mat1;
	bool4x2 test4 = mat1 >= mat1;
	bool4x2 test5 = mat1 < mat2;
	bool4x2 test6 = mat1 > mat0;

	bool4x2 test7 = mat2 <= mat2;
	bool4x2 test8 = mat2 >= mat2;
	bool4x2 test9 = mat2 < mat3;
	bool4x2 test10 = mat2 > mat1;

	bool4x2 test11 = mat3 <= mat3;
	bool4x2 test12 = mat3 >= mat3;
	bool4x2 test13 = mat3 > mat2;

	TEMPER_EXPECT_TRUE( test0 == bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test1 == bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test2 == bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test3 == bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test4 == bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test5 == bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test6 == bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test7 == bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test8 == bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test9 == bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test10 == bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test11 == bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test12 == bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	) );

	TEMPER_EXPECT_TRUE( test13 == bool4x2(
		true, true,
		true, true,
		true, true,
		true, true
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_int4x2 ) {
	int4x2 id = int4x2(
		1, 0,
		0, 1,
		0, 0,
		0, 0
	);

	int4x2 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_int4x2 ) {
	int4x2 mat = int4x2(
		0, 1,
		2, 3,
		4, 5,
		6, 7
	);
	int2x4 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == int2x4(
		0, 2, 4, 6,
		1, 3, 5, 7
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRotate_int4x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestScale_int4x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestOrtho_int4x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestPerspective_int4x2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestLookAt_int4x2 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_int4x2 ) {
	TEMPER_RUN_TEST( TestAssignment_int4x2 );

	TEMPER_RUN_TEST( TestArithmeticAddition_int4x2 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_int4x2 );
	TEMPER_SKIP_TEST( TestArithmeticMultiplication_int4x2, "Give me a minute to think about how to structure this one." );
	TEMPER_RUN_TEST( TestArithmeticDivision_int4x2 );

	TEMPER_RUN_TEST( TestArray_int4x2 );
	TEMPER_RUN_TEST( TestRelational_int4x2 );

	TEMPER_RUN_TEST( TestIdentity_int4x2 );
	TEMPER_RUN_TEST( TestTranspose_int4x2 );

	TEMPER_SKIP_TEST( TestRotate_int4x2, "TODO" );
	TEMPER_SKIP_TEST( TestScale_int4x2, "TODO" );

	TEMPER_SKIP_TEST( TestOrtho_int4x2, "TODO" );
	TEMPER_SKIP_TEST( TestPerspective_int4x2, "TODO" );
	TEMPER_SKIP_TEST( TestLookAt_int4x2, "TODO" );
};
