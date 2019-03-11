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

TEMPER_TEST( TestAssignment_uint3x3 ) {
	uint3x3 mat;

	// fill single value
	mat = uint3x3( 999 );
	TEMPER_EXPECT_TRUE( mat[0] == uint3( 999, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint3( 0, 999, 0 ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint3( 0, 0, 999 ) );

	// row filling
	mat = uint3x3(
		uint3( 0, 1, 2 ),
		uint3( 3, 4, 5 ),
		uint3( 6, 7, 8 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == uint3( 0, 1, 2 ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint3( 3, 4, 5 ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint3( 6, 7, 8 ) );

	// all values filled
	mat = uint3x3(
		9, 8, 7, 
		6, 5, 4, 
		3, 2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == uint3( 9, 8, 7 ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint3( 6, 5, 4 ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint3( 3, 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_uint3x3 ) {
	uint3x3 answer = uint3x3(
		7, 7, 7,
		8, 8, 8,
		15, 15, 15
	);

	uint3x3 a = uint3x3(
		6, 6, 6,
		6, 6, 6,
		12, 12, 12
	);
	uint3x3 b = uint3x3(
		1, 1, 1,
		2, 2, 2,
		3, 3, 3
	);
	uint3x3 c = a + b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_uint3x3 ) {
	uint3x3 answer = uint3x3(
		5, 5, 5,
		4, 4, 4,
		9, 9, 9
	);

	uint3x3 a = uint3x3(
		6, 6, 6,
		6, 6, 6,
		12, 12, 12
	);
	uint3x3 b = uint3x3(
		1, 1, 1,
		2, 2, 2,
		3, 3, 3
	);
	uint3x3 c = a - b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_uint3x3 ) {
	uint3x3 answer = uint3x3(
		36, 36, 36,
		36, 36, 36,
		72, 72, 72
	);

	uint3x3 a = uint3x3(
		6, 6, 6,
		6, 6, 6,
		12, 12, 12
	);
	uint3x3 b = uint3x3(
		1, 1, 1,
		2, 2, 2,
		3, 3, 3
	);
	uint3x3 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_uint3x3 ) {
	uint3x3 answer = uint3x3(
		6, 6, 6,
		3, 3, 3,
		4, 4, 4
	);

	uint3x3 a = uint3x3(
		6, 6, 6,
		6, 6, 6,
		12, 12, 12
	);
	uint3x3 b = uint3x3(
		1, 1, 1,
		2, 2, 2,
		3, 3, 3
	);
	uint3x3 c = a / b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_uint3x3 ) {
	uint3x3 mat;

	TEMPER_EXPECT_TRUE( mat[0] == uint3( 1, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint3( 0, 1, 0 ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint3( 0, 0, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_uint3x3 ) {
	uint3x3 mat0 = uint3x3(
		1, 1, 1,
		1, 1, 1,
		1, 1, 1
	);
	uint3x3 mat1 = uint3x3(
		2, 2, 2,
		2, 2, 2,
		2, 2, 2
	);
	uint3x3 mat2 = uint3x3(
		3, 3, 3,
		3, 3, 3,
		3, 3, 3
	);
	uint3x3 mat3 = uint3x3(
		4, 4, 4,
		4, 4, 4,
		4, 4, 4
	);

	bool3x3 test0 = mat0 <= mat0;
	bool3x3 test1 = mat0 >= mat0;
	bool3x3 test2 = mat0 < mat1;

	bool3x3 test3 = mat1 <= mat1;
	bool3x3 test4 = mat1 >= mat1;
	bool3x3 test5 = mat1 < mat2;
	bool3x3 test6 = mat1 > mat0;

	bool3x3 test7 = mat2 <= mat2;
	bool3x3 test8 = mat2 >= mat2;
	bool3x3 test9 = mat2 < mat3;
	bool3x3 test10 = mat2 > mat1;

	bool3x3 test11 = mat3 <= mat3;
	bool3x3 test12 = mat3 >= mat3;
	bool3x3 test13 = mat3 > mat2;

	TEMPER_EXPECT_TRUE( test0 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test1 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test2 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test3 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test4 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test5 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test6 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test7 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test8 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test9 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test10 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test11 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test12 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_EXPECT_TRUE( test13 == bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_uint3x3 ) {
	uint3x3 id = uint3x3(
		1, 0, 0,
		0, 1, 0,
		0, 0, 1
	);

	uint3x3 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_uint3x3 ) {
	uint3x3 mat = uint3x3(
		0, 1, 2,
		3, 4, 5,
		6, 7, 8
	);
	uint3x3 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == uint3x3(
		0, 3, 6,
		1, 4, 7,
		2, 5, 8
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_uint3x3 ) {
	uint3x3 mat;
	uint3x3 translated = uint3x3(
		1, 0, 2,
		0, 1, 3,
		0, 0, 1
	);

	uint2 translation = uint2( 2, 3 );
	mat = translate( mat, translation );

	TEMPER_EXPECT_TRUE( mat == translated );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_uint3x3 ) {
	uint3x3 mat;
	uint3x3 scaled = scale( mat, uint3( 2, 2, 2 ) );

	TEMPER_EXPECT_TRUE( scaled == uint3x3(
		2, 0, 0,
		0, 2, 0,
		0, 0, 2
	) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_uint3x3 ) {
	TEMPER_RUN_TEST( TestAssignment_uint3x3 );

	TEMPER_RUN_TEST( TestArithmeticAddition_uint3x3 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_uint3x3 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_uint3x3 );
	TEMPER_RUN_TEST( TestArithmeticDivision_uint3x3 );

	TEMPER_RUN_TEST( TestArray_uint3x3 );
	TEMPER_RUN_TEST( TestRelational_uint3x3 );

	TEMPER_RUN_TEST( TestIdentity_uint3x3 );
	TEMPER_RUN_TEST( TestTranspose_uint3x3 );

	TEMPER_RUN_TEST( TestTranslate_uint3x3 );
	TEMPER_RUN_TEST( TestScale_uint3x3 );

};
