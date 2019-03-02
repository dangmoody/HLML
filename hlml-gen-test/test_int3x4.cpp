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

TEMPER_TEST( TestAssignment_int3x4 ) {
	int3x4 mat;

	// fill single value
	mat = int3x4( 999 );
	TEMPER_EXPECT_TRUE( mat[0] == int4( 999, 0, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int4( 0, 999, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[2] == int4( 0, 0, 999, 0 ) );

	// row filling
	mat = int3x4(
		int4( 0, 1, 2, 3 ),
		int4( 4, 5, 6, 7 ),
		int4( 8, 9, 10, 11 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == int4( 0, 1, 2, 3 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int4( 4, 5, 6, 7 ) );
	TEMPER_EXPECT_TRUE( mat[2] == int4( 8, 9, 10, 11 ) );

	// all values filled
	mat = int3x4(
		12, 11, 10, 9, 
		8, 7, 6, 5, 
		4, 3, 2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == int4( 12, 11, 10, 9 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int4( 8, 7, 6, 5 ) );
	TEMPER_EXPECT_TRUE( mat[2] == int4( 4, 3, 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_int3x4 ) {
	int3x4 a = int3x4(
		6, 6, 6, 
		6, 6, 6, 
		6, 6, 6, 
		6,6,6
	);
	int3x4 b = int3x4(
		2, 3, 4, 4,
		6, 6, 8, 8,
		10, 10, 12, 12
	);
	int3x4 c = a + b;

	TEMPER_EXPECT_TRUE( c == int3x4(
		8, 9, 10, 10,
		12, 12, 14, 14,
		16, 16, 18, 18
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_int3x4 ) {
	int3x4 a = int3x4(
		6, 6, 6, 
		6, 6, 6, 
		6, 6, 6, 
		6,6,6
	);
	int3x4 b = int3x4(
		2, 3, 4, 4,
		6, 6, 8, 8,
		10, 10, 12, 12
	);
	int3x4 c = a - b;

	TEMPER_EXPECT_TRUE( c == int3x4(
		4, 3, 2, 2,
		0, 0, -2, -2,
		-4, -4, -6, -6
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_int3x4 ) {
	int3x4 a = int3x4(
		6, 6, 6, 
		6, 6, 6, 
		6, 6, 6, 
		6,6,6
	);
	int3x4 b = int3x4(
		2, 3, 4, 4,
		6, 6, 8, 8,
		10, 10, 12, 12
	);
	int3x4 c = a * b;

	TEMPER_EXPECT_TRUE( c == int3x4(
		0, 1, 2, 3,
		1, 2, 3, 4,
		2, 3, 4, 5
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_int3x4 ) {
	int3x4 a = int3x4(
		2, 3, 4, 4,
		6, 6, 8, 8,
		10, 10, 12, 12
	);
	int3x4 b = int3x4(
		6, 6, 6, 
		6, 6, 6, 
		6, 6, 6, 
		6,6,6
	);
	int3x4 c = b / a;

	TEMPER_EXPECT_TRUE( c == int3x4(
		3, 2, 1, 1,
		1, 1, 0, 0,
		0, 0, 0, 0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_int3x4 ) {
	int3x4 mat;

	TEMPER_EXPECT_TRUE( mat[0] == int4( 1, 0, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int4( 0, 1, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[2] == int4( 0, 0, 1, 0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_int3x4 ) {
	int3x4 mat0 = int3x4(
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	);
	int3x4 mat1 = int3x4(
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	);
	int3x4 mat2 = int3x4(
		3, 3, 3, 3,
		3, 3, 3, 3,
		3, 3, 3, 3
	);
	int3x4 mat3 = int3x4(
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	);

	bool3x4 test0 = mat0 <= mat0;
	bool3x4 test1 = mat0 >= mat0;
	bool3x4 test2 = mat0 < mat1;

	bool3x4 test3 = mat1 <= mat1;
	bool3x4 test4 = mat1 >= mat1;
	bool3x4 test5 = mat1 < mat2;
	bool3x4 test6 = mat1 > mat0;

	bool3x4 test7 = mat2 <= mat2;
	bool3x4 test8 = mat2 >= mat2;
	bool3x4 test9 = mat2 < mat3;
	bool3x4 test10 = mat2 > mat1;

	bool3x4 test11 = mat3 <= mat3;
	bool3x4 test12 = mat3 >= mat3;
	bool3x4 test13 = mat3 > mat2;

	TEMPER_EXPECT_TRUE( test0 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test1 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test2 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test3 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test4 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test5 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test6 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test7 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test8 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test9 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test10 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test11 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test12 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test13 == bool3x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_int3x4 ) {
	int3x4 id = int3x4(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0
	);

	int3x4 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_int3x4 ) {
	int3x4 mat = int3x4(
		0, 1, 2, 3,
		4, 5, 6, 7,
		8, 9, 10, 11
	);
	int4x3 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == int4x3(
		0, 4, 8,
		1, 5, 9,
		2, 6, 10,
		3, 7, 11
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_int3x4 ) {
	int3x4 mat;
	int3x4 translated = int3x4(
		1, 0, 0, 2,
		0, 1, 0, 3,
		0, 0, 1, 4
	);

	int3 translation = int3( 2, 3, 4 );
	mat = translate( mat, translation );

	TEMPER_EXPECT_TRUE( mat == translated );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_int3x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestOrtho_int3x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestPerspective_int3x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestLookAt_int3x4 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_int3x4 ) {
	TEMPER_RUN_TEST( TestAssignment_int3x4 );

	TEMPER_RUN_TEST( TestArithmeticAddition_int3x4 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_int3x4 );
	TEMPER_SKIP_TEST( TestArithmeticMultiplication_int3x4, "Give me a minute to think about how to structure this one." );
	TEMPER_RUN_TEST( TestArithmeticDivision_int3x4 );

	TEMPER_RUN_TEST( TestArray_int3x4 );
	TEMPER_RUN_TEST( TestRelational_int3x4 );

	TEMPER_RUN_TEST( TestIdentity_int3x4 );
	TEMPER_RUN_TEST( TestTranspose_int3x4 );

	TEMPER_RUN_TEST( TestTranslate_int3x4 );
	TEMPER_SKIP_TEST( TestScale_int3x4, "TODO" );

	TEMPER_SKIP_TEST( TestOrtho_int3x4, "TODO" );
	TEMPER_SKIP_TEST( TestPerspective_int3x4, "TODO" );
	TEMPER_SKIP_TEST( TestLookAt_int3x4, "TODO" );
};
