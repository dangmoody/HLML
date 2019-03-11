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

TEMPER_TEST( TestAssignment_uint4x4 ) {
	uint4x4 mat;

	// fill single value
	mat = uint4x4( 999 );
	TEMPER_EXPECT_TRUE( mat[0] == uint4( 999, 0, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint4( 0, 999, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint4( 0, 0, 999, 0 ) );
	TEMPER_EXPECT_TRUE( mat[3] == uint4( 0, 0, 0, 999 ) );

	// row filling
	mat = uint4x4(
		uint4( 0, 1, 2, 3 ),
		uint4( 4, 5, 6, 7 ),
		uint4( 8, 9, 10, 11 ),
		uint4( 12, 13, 14, 15 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == uint4( 0, 1, 2, 3 ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint4( 4, 5, 6, 7 ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint4( 8, 9, 10, 11 ) );
	TEMPER_EXPECT_TRUE( mat[3] == uint4( 12, 13, 14, 15 ) );

	// all values filled
	mat = uint4x4(
		16, 15, 14, 13, 
		12, 11, 10, 9, 
		8, 7, 6, 5, 
		4, 3, 2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == uint4( 16, 15, 14, 13 ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint4( 12, 11, 10, 9 ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint4( 8, 7, 6, 5 ) );
	TEMPER_EXPECT_TRUE( mat[3] == uint4( 4, 3, 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_uint4x4 ) {
	uint4x4 answer = uint4x4(
		7, 7, 7, 7,
		8, 8, 8, 8,
		15, 15, 15, 15,
		24, 24, 24, 24
	);

	uint4x4 a = uint4x4(
		6, 6, 6, 6,
		6, 6, 6, 6,
		12, 12, 12, 12,
		18, 18, 18, 18
	);
	uint4x4 b = uint4x4(
		1, 1, 1, 1,
		2, 2, 2, 2,
		3, 3, 3, 3,
		6, 6, 6, 6
	);
	uint4x4 c = a + b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_uint4x4 ) {
	uint4x4 answer = uint4x4(
		5, 5, 5, 5,
		4, 4, 4, 4,
		9, 9, 9, 9,
		12, 12, 12, 12
	);

	uint4x4 a = uint4x4(
		6, 6, 6, 6,
		6, 6, 6, 6,
		12, 12, 12, 12,
		18, 18, 18, 18
	);
	uint4x4 b = uint4x4(
		1, 1, 1, 1,
		2, 2, 2, 2,
		3, 3, 3, 3,
		6, 6, 6, 6
	);
	uint4x4 c = a - b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_uint4x4 ) {
	uint4x4 answer = uint4x4(
		72, 72, 72, 72,
		72, 72, 72, 72,
		144, 144, 144, 144,
		216, 216, 216, 216
	);

	uint4x4 a = uint4x4(
		6, 6, 6, 6,
		6, 6, 6, 6,
		12, 12, 12, 12,
		18, 18, 18, 18
	);
	uint4x4 b = uint4x4(
		1, 1, 1, 1,
		2, 2, 2, 2,
		3, 3, 3, 3,
		6, 6, 6, 6
	);
	uint4x4 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_uint4x4 ) {
	uint4x4 answer = uint4x4(
		6, 6, 6, 6,
		3, 3, 3, 3,
		4, 4, 4, 4,
		3, 3, 3, 3
	);

	uint4x4 a = uint4x4(
		6, 6, 6, 6,
		6, 6, 6, 6,
		12, 12, 12, 12,
		18, 18, 18, 18
	);
	uint4x4 b = uint4x4(
		1, 1, 1, 1,
		2, 2, 2, 2,
		3, 3, 3, 3,
		6, 6, 6, 6
	);
	uint4x4 c = a / b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_uint4x4 ) {
	uint4x4 mat;

	TEMPER_EXPECT_TRUE( mat[0] == uint4( 1, 0, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint4( 0, 1, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint4( 0, 0, 1, 0 ) );
	TEMPER_EXPECT_TRUE( mat[3] == uint4( 0, 0, 0, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_uint4x4 ) {
	uint4x4 mat0 = uint4x4(
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	);
	uint4x4 mat1 = uint4x4(
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	);
	uint4x4 mat2 = uint4x4(
		3, 3, 3, 3,
		3, 3, 3, 3,
		3, 3, 3, 3,
		3, 3, 3, 3
	);
	uint4x4 mat3 = uint4x4(
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	);

	bool4x4 test0 = mat0 <= mat0;
	bool4x4 test1 = mat0 >= mat0;
	bool4x4 test2 = mat0 < mat1;

	bool4x4 test3 = mat1 <= mat1;
	bool4x4 test4 = mat1 >= mat1;
	bool4x4 test5 = mat1 < mat2;
	bool4x4 test6 = mat1 > mat0;

	bool4x4 test7 = mat2 <= mat2;
	bool4x4 test8 = mat2 >= mat2;
	bool4x4 test9 = mat2 < mat3;
	bool4x4 test10 = mat2 > mat1;

	bool4x4 test11 = mat3 <= mat3;
	bool4x4 test12 = mat3 >= mat3;
	bool4x4 test13 = mat3 > mat2;

	TEMPER_EXPECT_TRUE( test0 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test1 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test2 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test3 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test4 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test5 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test6 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test7 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test8 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test9 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test10 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test11 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test12 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_EXPECT_TRUE( test13 == bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_uint4x4 ) {
	uint4x4 id = uint4x4(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);

	uint4x4 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_uint4x4 ) {
	uint4x4 mat = uint4x4(
		0, 1, 2, 3,
		4, 5, 6, 7,
		8, 9, 10, 11,
		12, 13, 14, 15
	);
	uint4x4 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == uint4x4(
		0, 4, 8, 12,
		1, 5, 9, 13,
		2, 6, 10, 14,
		3, 7, 11, 15
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_uint4x4 ) {
	uint4x4 mat;
	uint4x4 translated = uint4x4(
		1, 0, 0, 2,
		0, 1, 0, 3,
		0, 0, 1, 4,
		0, 0, 0, 1
	);

	uint3 translation = uint3( 2, 3, 4 );
	mat = translate( mat, translation );

	TEMPER_EXPECT_TRUE( mat == translated );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_uint4x4 ) {
	uint4x4 mat;
	uint4x4 scaled = scale( mat, uint3( 2, 2, 2 ) );

	TEMPER_EXPECT_TRUE( scaled == uint4x4(
		2, 0, 0, 0,
		0, 2, 0, 0,
		0, 0, 2, 0,
		0, 0, 0, 1
	) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_uint4x4 ) {
	TEMPER_RUN_TEST( TestAssignment_uint4x4 );

	TEMPER_RUN_TEST( TestArithmeticAddition_uint4x4 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_uint4x4 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_uint4x4 );
	TEMPER_RUN_TEST( TestArithmeticDivision_uint4x4 );

	TEMPER_RUN_TEST( TestArray_uint4x4 );
	TEMPER_RUN_TEST( TestRelational_uint4x4 );

	TEMPER_RUN_TEST( TestIdentity_uint4x4 );
	TEMPER_RUN_TEST( TestTranspose_uint4x4 );

	TEMPER_RUN_TEST( TestTranslate_uint4x4 );
	TEMPER_RUN_TEST( TestScale_uint4x4 );

};
