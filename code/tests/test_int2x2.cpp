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

TEMPER_TEST( TestAssignment_int2x2 )
{
	int2x2 mat;

	// fill single value
	mat = int2x2( 999 );
	TEMPER_EXPECT_TRUE( mat[0] == int2( 999, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int2( 0, 999 ) );

	// row filling
	mat = int2x2(
		int2( 0, 1 ),
		int2( 4, 5 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == int2( 0, 1 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int2( 4, 5 ) );

	// all values filled
	mat = int2x2(
		16, 15,
		12, 11
	);
	TEMPER_EXPECT_TRUE( mat[0] == int2( 16, 15 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int2( 12, 11 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_int2x2 )
{
	int2x2 answer = int2x2(
		7, 7,
		8, 8
	);

	int2x2 a = int2x2(
		6, 6,
		6, 6
	);
	int2x2 b = int2x2(
		1, 1,
		2, 2
	);
	int2x2 c = a + b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_int2x2 )
{
	int2x2 answer = int2x2(
		5, 5,
		4, 4
	);

	int2x2 a = int2x2(
		6, 6,
		6, 6
	);
	int2x2 b = int2x2(
		1, 1,
		2, 2
	);
	int2x2 c = a - b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_int2x2 )
{
	int2x2 answer = int2x2(
		18, 18,
		18, 18
	);

	int2x2 a = int2x2(
		6, 6,
		6, 6
	);
	int2x2 b = int2x2(
		1, 1,
		2, 2
	);
	int2x2 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_int2x2 )
{
	int2x2 answer = int2x2(
		6, 6,
		3, 3
	);

	int2x2 a = int2x2(
		6, 6,
		6, 6
	);
	int2x2 b = int2x2(
		1, 1,
		2, 2
	);
	int2x2 c = a / b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyVector_int2x2 )
{
	int2 answerVec = int2( 4, 16 );

	int2x2 a = int2x2(
		1, 2,
		5, 6
	);
	int2 b = int2( 2, 1 );
	int2 c = a * b;

	TEMPER_EXPECT_TRUE( c == answerVec );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_int2x2 )
{
	int2x2 mat;

	// prefix
	mat = int2x2(
		0, 0,
		0, 0
	);
	++mat;
	TEMPER_EXPECT_TRUE( mat == int2x2(
		1, 1,
		1, 1
	) );

	// postfix
	mat = int2x2(
		0, 0,
		0, 0
	);
	mat++;
	TEMPER_EXPECT_TRUE( mat == int2x2(
		1, 1,
		1, 1
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_int2x2 )
{
	int2x2 mat;

	// prefix
	mat = int2x2(
		1, 1,
		1, 1
	);
	--mat;
	TEMPER_EXPECT_TRUE( mat == int2x2(
		0, 0,
		0, 0
	) );

	// postfix
	mat = int2x2(
		1, 1,
		1, 1
	);
	mat--;
	TEMPER_EXPECT_TRUE( mat == int2x2(
		0, 0,
		0, 0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_int2x2 )
{
	bool2x2 allTrue = bool2x2(
		true, true,
		true, true
	);

	int2x2 mat0 = int2x2(
		1, 1,
		1, 1
	);
	int2x2 mat1 = int2x2(
		2, 2,
		2, 2
	);
	int2x2 mat2 = int2x2(
		3, 3,
		3, 3
	);
	int2x2 mat3 = int2x2(
		4, 4,
		4, 4
	);

	bool2x2 test0  = mat0 <= mat0;
	bool2x2 test1  = mat0 >= mat0;
	bool2x2 test2  = mat0 <  mat1;
	bool2x2 test3  = mat0 <  mat2;
	bool2x2 test4  = mat0 <  mat3;

	bool2x2 test5  = mat1 >  mat0;
	bool2x2 test6  = mat1 <= mat1;
	bool2x2 test7  = mat1 >= mat1;
	bool2x2 test8  = mat1 <  mat2;
	bool2x2 test9  = mat1 <  mat3;

	bool2x2 test10 = mat2 >  mat0;
	bool2x2 test11 = mat2 >  mat1;
	bool2x2 test12 = mat2 <= mat2;
	bool2x2 test13 = mat2 >= mat2;
	bool2x2 test14 = mat2 <  mat3;

	bool2x2 test15 = mat3 >  mat0;
	bool2x2 test16 = mat3 >  mat1;
	bool2x2 test17 = mat3 >  mat2;
	bool2x2 test18 = mat3 <= mat3;
	bool2x2 test19 = mat3 >= mat3;

	TEMPER_EXPECT_TRUE( test0  == allTrue );
	TEMPER_EXPECT_TRUE( test1  == allTrue );
	TEMPER_EXPECT_TRUE( test2  == allTrue );
	TEMPER_EXPECT_TRUE( test3  == allTrue );
	TEMPER_EXPECT_TRUE( test4  == allTrue );

	TEMPER_EXPECT_TRUE( test5  == allTrue );
	TEMPER_EXPECT_TRUE( test6  == allTrue );
	TEMPER_EXPECT_TRUE( test7  == allTrue );
	TEMPER_EXPECT_TRUE( test8  == allTrue );
	TEMPER_EXPECT_TRUE( test9  == allTrue );

	TEMPER_EXPECT_TRUE( test10 == allTrue );
	TEMPER_EXPECT_TRUE( test11 == allTrue );
	TEMPER_EXPECT_TRUE( test12 == allTrue );
	TEMPER_EXPECT_TRUE( test13 == allTrue );
	TEMPER_EXPECT_TRUE( test14 == allTrue );

	TEMPER_EXPECT_TRUE( test15 == allTrue );
	TEMPER_EXPECT_TRUE( test16 == allTrue );
	TEMPER_EXPECT_TRUE( test17 == allTrue );
	TEMPER_EXPECT_TRUE( test18 == allTrue );
	TEMPER_EXPECT_TRUE( test19 == allTrue );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_int2x2 )
{
	int2x2 mat;

	TEMPER_EXPECT_TRUE( mat[0] == int2( 1, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int2( 0, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_And_int2x2 )
{
	int2x2 a  = int2x2(
		21, 21,
		21, 21
	);
	int2x2 b  = int2x2(
		7, 7,
		7, 7
	);

	int2x2 answer = a & b;

	TEMPER_EXPECT_TRUE( answer == int2x2(
		5, 5,
		5, 5
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Or_int2x2 )
{
	int2x2 a  = int2x2(
		21, 21,
		21, 21
	);
	int2x2 b  = int2x2(
		7, 7,
		7, 7
	);

	int2x2 answer = a | b;

	TEMPER_EXPECT_TRUE( answer == int2x2(
		23, 23,
		23, 23
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Xor_int2x2 )
{
	int2x2 a  = int2x2(
		21, 21,
		21, 21
	);
	int2x2 b  = int2x2(
		7, 7,
		7, 7
	);

	int2x2 answer = a ^ b;

	TEMPER_EXPECT_TRUE( answer == int2x2(
		18, 18,
		18, 18
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftLeft_int2x2 )
{
	int2x2 a  = int2x2(
		1, 1,
		1, 1
	);
	int2x2 b  = int2x2(
		2, 2,
		2, 2
	);

	int2x2 answer = a << b;

	TEMPER_EXPECT_TRUE( answer == int2x2(
		4, 4,
		4, 4
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftRight_int2x2 )
{
	int2x2 a  = int2x2(
		16, 16,
		16, 16
	);
	int2x2 b  = int2x2(
		4, 4,
		4, 4
	);

	int2x2 answer = a >> b;

	TEMPER_EXPECT_TRUE( answer == int2x2(
		1, 1,
		1, 1
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Unary_int2x2 )
{
	int2x2 a = int2x2(
		0, 0,
		0, 0
	);

	int2x2 answer = ~a;

	TEMPER_EXPECT_TRUE( answer == int2x2(
		(int32_t) -1, (int32_t) -1,
		(int32_t) -1, (int32_t) -1
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_int2x2 )
{
	int2x2 id = int2x2(
		1, 0,
		0, 1
	);

	int2x2 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_int2x2 )
{
	int2x2 mat = int2x2(
		0, 1,
		4, 5
	);
	int2x2 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == int2x2(
		0, 4,
		1, 5
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDeterminant_int2x2 )
{
	int2x2 mat = int2x2(
		6, 2,
		2, 6
	);
	int32_t det = determinant( mat );

	TEMPER_EXPECT_TRUE( det == 32 );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_int2x2 )
{
	int2x2 mat;
	int2x2 scaled = scale( mat, int3( 2, 2, 2 ) );

	TEMPER_EXPECT_TRUE( scaled == int2x2(
		2, 0,
		0, 2
	) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_int2x2 )
{
	TEMPER_RUN_TEST( TestAssignment_int2x2 );
	TEMPER_RUN_TEST( TestArithmeticAddition_int2x2 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_int2x2 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_int2x2 );
	TEMPER_RUN_TEST( TestArithmeticDivision_int2x2 );
	TEMPER_RUN_TEST( TestMultiplyVector_int2x2 );
	TEMPER_RUN_TEST( TestIncrement_int2x2 );
	TEMPER_RUN_TEST( TestDecrement_int2x2 );
	TEMPER_RUN_TEST( TestRelational_int2x2 );
	TEMPER_RUN_TEST( TestArray_int2x2 );
	TEMPER_RUN_TEST( TestBitwise_And_int2x2 );
	TEMPER_RUN_TEST( TestBitwise_Or_int2x2 );
	TEMPER_RUN_TEST( TestBitwise_Xor_int2x2 );
	TEMPER_RUN_TEST( TestBitwise_ShiftLeft_int2x2 );
	TEMPER_RUN_TEST( TestBitwise_ShiftRight_int2x2 );
	TEMPER_RUN_TEST( TestBitwise_Unary_int2x2 );
	TEMPER_RUN_TEST( TestIdentity_int2x2 );
	TEMPER_RUN_TEST( TestTranspose_int2x2 );
	TEMPER_RUN_TEST( TestDeterminant_int2x2 );
	TEMPER_RUN_TEST( TestScale_int2x2 );
}
