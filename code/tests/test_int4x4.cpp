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

#include "../../code/out/gen/hlml_functions_matrix.h"

#include <temper/temper.h>

TEMPER_TEST( TestAssignment_int4x4 )
{
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

TEMPER_TEST( TestArithmeticAddition_int4x4 )
{
	int4x4 answer = int4x4(
		7, 7, 7, 7,
		8, 8, 8, 8,
		15, 15, 15, 15,
		24, 24, 24, 24
	);

	int4x4 a = int4x4(
		6, 6, 6, 6,
		6, 6, 6, 6,
		12, 12, 12, 12,
		18, 18, 18, 18
	);
	int4x4 b = int4x4(
		1, 1, 1, 1,
		2, 2, 2, 2,
		3, 3, 3, 3,
		6, 6, 6, 6
	);
	int4x4 c = a + b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_int4x4 )
{
	int4x4 answer = int4x4(
		5, 5, 5, 5,
		4, 4, 4, 4,
		9, 9, 9, 9,
		12, 12, 12, 12
	);

	int4x4 a = int4x4(
		6, 6, 6, 6,
		6, 6, 6, 6,
		12, 12, 12, 12,
		18, 18, 18, 18
	);
	int4x4 b = int4x4(
		1, 1, 1, 1,
		2, 2, 2, 2,
		3, 3, 3, 3,
		6, 6, 6, 6
	);
	int4x4 c = a - b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_int4x4 )
{
	int4x4 answer = int4x4(
		72, 72, 72, 72,
		72, 72, 72, 72,
		144, 144, 144, 144,
		216, 216, 216, 216
	);

	int4x4 a = int4x4(
		6, 6, 6, 6,
		6, 6, 6, 6,
		12, 12, 12, 12,
		18, 18, 18, 18
	);
	int4x4 b = int4x4(
		1, 1, 1, 1,
		2, 2, 2, 2,
		3, 3, 3, 3,
		6, 6, 6, 6
	);
	int4x4 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_int4x4 )
{
	int4x4 answer = int4x4(
		6, 6, 6, 6,
		3, 3, 3, 3,
		4, 4, 4, 4,
		3, 3, 3, 3
	);

	int4x4 a = int4x4(
		6, 6, 6, 6,
		6, 6, 6, 6,
		12, 12, 12, 12,
		18, 18, 18, 18
	);
	int4x4 b = int4x4(
		1, 1, 1, 1,
		2, 2, 2, 2,
		3, 3, 3, 3,
		6, 6, 6, 6
	);
	int4x4 c = a / b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyVector_int4x4 )
{
	int4 answerVec = int4( 28, 68, 108, 148 );

	int4x4 a = int4x4(
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16
	);
	int4 b = int4( 2, 1, 4, 3 );
	int4 c = a * b;

	TEMPER_EXPECT_TRUE( c == answerVec );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_int4x4 )
{
	int4x4 mat;

	// prefix
	mat = int4x4(
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	);
	++mat;
	TEMPER_EXPECT_TRUE( mat == int4x4(
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	) );

	// postfix
	mat = int4x4(
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	);
	mat++;
	TEMPER_EXPECT_TRUE( mat == int4x4(
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_int4x4 )
{
	int4x4 mat;

	// prefix
	mat = int4x4(
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	);
	--mat;
	TEMPER_EXPECT_TRUE( mat == int4x4(
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	) );

	// postfix
	mat = int4x4(
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	);
	mat--;
	TEMPER_EXPECT_TRUE( mat == int4x4(
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_int4x4 )
{
	bool4x4 allTrue = bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	);

	int4x4 mat0 = int4x4(
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	);
	int4x4 mat1 = int4x4(
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	);
	int4x4 mat2 = int4x4(
		3, 3, 3, 3,
		3, 3, 3, 3,
		3, 3, 3, 3,
		3, 3, 3, 3
	);
	int4x4 mat3 = int4x4(
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

	TEMPER_EXPECT_TRUE( test0 == allTrue );
	TEMPER_EXPECT_TRUE( test1 == allTrue );
	TEMPER_EXPECT_TRUE( test2 == allTrue );
	TEMPER_EXPECT_TRUE( test3 == allTrue );
	TEMPER_EXPECT_TRUE( test4 == allTrue );
	TEMPER_EXPECT_TRUE( test5 == allTrue );
	TEMPER_EXPECT_TRUE( test6 == allTrue );
	TEMPER_EXPECT_TRUE( test7 == allTrue );
	TEMPER_EXPECT_TRUE( test8 == allTrue );
	TEMPER_EXPECT_TRUE( test9 == allTrue );
	TEMPER_EXPECT_TRUE( test10 == allTrue );
	TEMPER_EXPECT_TRUE( test11 == allTrue );
	TEMPER_EXPECT_TRUE( test12 == allTrue );
	TEMPER_EXPECT_TRUE( test13 == allTrue );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_int4x4 )
{
	int4x4 mat;

	TEMPER_EXPECT_TRUE( mat[0] == int4( 1, 0, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int4( 0, 1, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[2] == int4( 0, 0, 1, 0 ) );
	TEMPER_EXPECT_TRUE( mat[3] == int4( 0, 0, 0, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwiseAnd_int4x4 )
{
	int4x4 a  = int4x4(
		21, 21, 21, 21,
		21, 21, 21, 21,
		21, 21, 21, 21,
		21, 21, 21, 21
	);
	int4x4 b  = int4x4(
		7, 7, 7, 7,
		7, 7, 7, 7,
		7, 7, 7, 7,
		7, 7, 7, 7
	);

	int4x4 answer = a & b;

	TEMPER_EXPECT_TRUE( answer == int4x4(
		5, 5, 5, 5,
		5, 5, 5, 5,
		5, 5, 5, 5,
		5, 5, 5, 5
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwiseOr_int4x4 )
{
	int4x4 a  = int4x4(
		21, 21, 21, 21,
		21, 21, 21, 21,
		21, 21, 21, 21,
		21, 21, 21, 21
	);
	int4x4 b  = int4x4(
		7, 7, 7, 7,
		7, 7, 7, 7,
		7, 7, 7, 7,
		7, 7, 7, 7
	);

	int4x4 answer = a | b;

	TEMPER_EXPECT_TRUE( answer == int4x4(
		23, 23, 23, 23,
		23, 23, 23, 23,
		23, 23, 23, 23,
		23, 23, 23, 23
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwiseXor_int4x4 )
{
	int4x4 a  = int4x4(
		21, 21, 21, 21,
		21, 21, 21, 21,
		21, 21, 21, 21,
		21, 21, 21, 21
	);
	int4x4 b  = int4x4(
		7, 7, 7, 7,
		7, 7, 7, 7,
		7, 7, 7, 7,
		7, 7, 7, 7
	);

	int4x4 answer = a ^ b;

	TEMPER_EXPECT_TRUE( answer == int4x4(
		18, 18, 18, 18,
		18, 18, 18, 18,
		18, 18, 18, 18,
		18, 18, 18, 18
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwiseShiftLeft_int4x4 )
{
	int4x4 a  = int4x4(
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	);
	int4x4 b  = int4x4(
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2,
		2, 2, 2, 2
	);

	int4x4 answer = a << b;

	TEMPER_EXPECT_TRUE( answer == int4x4(
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwiseShiftRight_int4x4 )
{
	int4x4 a  = int4x4(
		16, 16, 16, 16,
		16, 16, 16, 16,
		16, 16, 16, 16,
		16, 16, 16, 16
	);
	int4x4 b  = int4x4(
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4,
		4, 4, 4, 4
	);

	int4x4 answer = a >> b;

	TEMPER_EXPECT_TRUE( answer == int4x4(
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1,
		1, 1, 1, 1
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwiseUnary_int4x4 )
{
	int4x4 a = int4x4(
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0
	);

	int4x4 answer = ~a;

	TEMPER_EXPECT_TRUE( answer == int4x4( (int32_t) -1, (int32_t) -1, (int32_t) -1, (int32_t) -1,
(int32_t) -1, (int32_t) -1, (int32_t) -1, (int32_t) -1,
(int32_t) -1, (int32_t) -1, (int32_t) -1, (int32_t) -1,
(int32_t) -1, (int32_t) -1, (int32_t) -1, (int32_t) -1
 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_int4x4 )
{
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

TEMPER_TEST( TestTranspose_int4x4 )
{
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

TEMPER_TEST( TestDeterminant_int4x4 )
{
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

TEMPER_TEST( TestTranslate_int4x4 )
{
	int4x4 mat;
	int4x4 translated = int4x4(
		1, 0, 0, 2,
		0, 1, 0, 3,
		0, 0, 1, 4,
		0, 0, 0, 1
	);

	int3 translation = int3( 2, 3, 4 );
	mat = translate( mat, translation );

	TEMPER_EXPECT_TRUE( mat == translated );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_int4x4 )
{
	int4x4 mat;
	int4x4 scaled = scale( mat, int3( 2, 2, 2 ) );

	TEMPER_EXPECT_TRUE( scaled == int4x4(
		2, 0, 0, 0,
		0, 2, 0, 0,
		0, 0, 2, 0,
		0, 0, 0, 1
	) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_int4x4 )
{
	TEMPER_RUN_TEST( TestAssignment_int4x4 );

	TEMPER_RUN_TEST( TestArithmeticAddition_int4x4 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_int4x4 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_int4x4 );
	TEMPER_RUN_TEST( TestArithmeticDivision_int4x4 );

	TEMPER_RUN_TEST( TestMultiplyVector_int4x4 );

	TEMPER_RUN_TEST( TestIncrement_int4x4 );
	TEMPER_RUN_TEST( TestDecrement_int4x4 );

	TEMPER_RUN_TEST( TestRelational_int4x4 );

	TEMPER_RUN_TEST( TestBitwiseAnd_int4x4 );
	TEMPER_RUN_TEST( TestBitwiseOr_int4x4 );
	TEMPER_RUN_TEST( TestBitwiseXor_int4x4 );
	TEMPER_RUN_TEST( TestBitwiseUnary_int4x4 );
	TEMPER_RUN_TEST( TestBitwiseShiftLeft_int4x4 );
	TEMPER_RUN_TEST( TestBitwiseShiftRight_int4x4 );
	TEMPER_RUN_TEST( TestArray_int4x4 );

	TEMPER_RUN_TEST( TestIdentity_int4x4 );
	TEMPER_RUN_TEST( TestTranspose_int4x4 );
	TEMPER_RUN_TEST( TestDeterminant_int4x4 );

	TEMPER_RUN_TEST( TestTranslate_int4x4 );
	TEMPER_RUN_TEST( TestScale_int4x4 );

}
