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

TEMPER_TEST( TestAssignment_int2x4 ) {
	int2x4 mat;

	// fill single value
	mat = int2x4( 999 );
	TEMPER_EXPECT_TRUE( mat[0] == int4( 999, 0, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int4( 0, 999, 0, 0 ) );

	// row filling
	mat = int2x4(
		int4( 0, 1, 2, 3 ),
		int4( 4, 5, 6, 7 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == int4( 0, 1, 2, 3 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int4( 4, 5, 6, 7 ) );

	// all values filled
	mat = int2x4(
		8, 7, 6, 5, 
		4, 3, 2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == int4( 8, 7, 6, 5 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int4( 4, 3, 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_int2x4 ) {
	int2x4 a = int2x4(
		6, 6, 
		6, 6, 
		6, 6, 
		6,6
	);
	int2x4 b = int2x4(
		2, 3, 4, 4,
		6, 6, 8, 8
	);
	int2x4 c = a + b;

	TEMPER_EXPECT_TRUE( c == int2x4(
		8, 9, 10, 10,
		12, 12, 14, 14
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_int2x4 ) {
	int2x4 a = int2x4(
		6, 6, 
		6, 6, 
		6, 6, 
		6,6
	);
	int2x4 b = int2x4(
		2, 3, 4, 4,
		6, 6, 8, 8
	);
	int2x4 c = a - b;

	TEMPER_EXPECT_TRUE( c == int2x4(
		4, 3, 2, 2,
		0, 0, -2, -2
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_int2x4 ) {
	int2x4 a = int2x4(
		6, 6, 
		6, 6, 
		6, 6, 
		6,6
	);
	int2x4 b = int2x4(
		2, 3, 4, 4,
		6, 6, 8, 8
	);
	int2x4 c = a * b;

	TEMPER_EXPECT_TRUE( c == int2x4(
		0, 1, 2, 3,
		1, 2, 3, 4
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_int2x4 ) {
	int2x4 a = int2x4(
		2, 3, 4, 4,
		6, 6, 8, 8
	);
	int2x4 b = int2x4(
		6, 6, 
		6, 6, 
		6, 6, 
		6,6
	);
	int2x4 c = b / a;

	TEMPER_EXPECT_TRUE( c == int2x4(
		3, 2, 1, 1,
		1, 1, 0, 0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_int2x4 ) {
	int2x4 mat;

	TEMPER_EXPECT_TRUE( mat[0] == int4( 1, 0, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int4( 0, 1, 0, 0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_int2x4 ) {
	int2x4 mat0 = int2x4(
		1, 1, 1, 1,
		1, 1, 1, 1
	);
	int2x4 mat1 = int2x4(
		2, 2, 2, 2,
		2, 2, 2, 2
	);
	int2x4 mat2 = int2x4(
		3, 3, 3, 3,
		3, 3, 3, 3
	);
	int2x4 mat3 = int2x4(
		4, 4, 4, 4,
		4, 4, 4, 4
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

TEMPER_TEST( TestIdentity_int2x4 ) {
	int2x4 id = int2x4(
		1, 0, 0, 0,
		0, 1, 0, 0
	);

	int2x4 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_int2x4 ) {
	int2x4 mat = int2x4(
		0, 1, 2, 3,
		4, 5, 6, 7
	);
	int4x2 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == int4x2(
		0, 4,
		1, 5,
		2, 6,
		3, 7
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_int2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestRotate_int2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestScale_int2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestOrtho_int2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestPerspective_int2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestLookAt_int2x4 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_int2x4 ) {
	TEMPER_RUN_TEST( TestAssignment_int2x4 );

	TEMPER_RUN_TEST( TestArithmeticAddition_int2x4 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_int2x4 );
	TEMPER_SKIP_TEST( TestArithmeticMultiplication_int2x4, "Give me a minute to think about how to structure this one." );
	TEMPER_RUN_TEST( TestArithmeticDivision_int2x4 );

	TEMPER_RUN_TEST( TestArray_int2x4 );
	TEMPER_RUN_TEST( TestRelational_int2x4 );

	TEMPER_RUN_TEST( TestIdentity_int2x4 );
	TEMPER_RUN_TEST( TestTranspose_int2x4 );
	TEMPER_SKIP_TEST( TestTranslate_int2x4, "TODO" );
	TEMPER_SKIP_TEST( TestRotate_int2x4, "TODO" );
	TEMPER_SKIP_TEST( TestScale_int2x4, "TODO" );

	TEMPER_SKIP_TEST( TestOrtho_int2x4, "TODO" );
	TEMPER_SKIP_TEST( TestPerspective_int2x4, "TODO" );
	TEMPER_SKIP_TEST( TestLookAt_int2x4, "TODO" );
};
