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

TEMPER_TEST( TestAssignment_int2x3 )
{
	int2x3 mat;

	// fill single value
	mat = int2x3( 999 );
	TEMPER_EXPECT_TRUE( mat[0] == int3( 999, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int3( 0, 999, 0 ) );

	// row filling
	mat = int2x3(
		int3( 0, 1, 2 ),
		int3( 4, 5, 6 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == int3( 0, 1, 2 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int3( 4, 5, 6 ) );

	// all values filled
	mat = int2x3(
		16, 15, 14,
		12, 11, 10
	);
	TEMPER_EXPECT_TRUE( mat[0] == int3( 16, 15, 14 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int3( 12, 11, 10 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmeticAddition_int2x3 )
{
	// scalar
	int2x3 answer = int2x3(
		7, 7, 7,
		8, 8, 8
	);

	int2x3 a = int2x3(
		6, 6, 6,
		6, 6, 6
	);
	int2x3 b = int2x3(
		1, 1, 1,
		2, 2, 2
	);
	int2x3 c = a + b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmeticSubtraction_int2x3 )
{
	// scalar
	int2x3 answer = int2x3(
		5, 5, 5,
		4, 4, 4
	);

	int2x3 a = int2x3(
		6, 6, 6,
		6, 6, 6
	);
	int2x3 b = int2x3(
		1, 1, 1,
		2, 2, 2
	);
	int2x3 c = a - b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmeticMultiplication_int2x3 )
{
	// scalar
	int2x3 answer = int2x3(
		6, 6, 6,
		12, 12, 12
	);

	int2x3 a = int2x3(
		6, 6, 6,
		6, 6, 6
	);
	int2x3 b = int2x3(
		1, 1, 1,
		2, 2, 2
	);
	int2x3 c = comp_mul( a, b );

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestComponentWiseArithmeticDivision_int2x3 )
{
	// scalar
	int2x3 answer = int2x3(
		6, 6, 6,
		3, 3, 3
	);

	int2x3 a = int2x3(
		6, 6, 6,
		6, 6, 6
	);
	int2x3 b = int2x3(
		1, 1, 1,
		2, 2, 2
	);
	int2x3 c = comp_div( a, b );

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyMatrix_int2x3 )
{
	// scalar
	int2x2 answer = int2x2(
		36, 36,
		36, 36
	);

	int2x3 a = int2x3(
		6, 6, 6,
		6, 6, 6
	);
	int3x2 b = int3x2(
		1, 1,
		2, 2,
		3, 3
	);
	int2x2 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_int2x3 )
{
	int2x3 mat;

	// prefix
	mat = int2x3(
		0, 0, 0,
		0, 0, 0
	);
	++mat;
	TEMPER_EXPECT_TRUE( mat == int2x3(
		1, 1, 1,
		1, 1, 1
	) );

	// postfix
	mat = int2x3(
		0, 0, 0,
		0, 0, 0
	);
	mat++;
	TEMPER_EXPECT_TRUE( mat == int2x3(
		1, 1, 1,
		1, 1, 1
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_int2x3 )
{
	int2x3 mat;

	// prefix
	mat = int2x3(
		1, 1, 1,
		1, 1, 1
	);
	--mat;
	TEMPER_EXPECT_TRUE( mat == int2x3(
		0, 0, 0,
		0, 0, 0
	) );

	// postfix
	mat = int2x3(
		1, 1, 1,
		1, 1, 1
	);
	mat--;
	TEMPER_EXPECT_TRUE( mat == int2x3(
		0, 0, 0,
		0, 0, 0
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_int2x3 )
{
	bool2x3 allTrue = bool2x3(
		true, true, true,
		true, true, true
	);

	int2x3 mat0 = int2x3(
		1, 1, 1,
		1, 1, 1
	);
	int2x3 mat1 = int2x3(
		2, 2, 2,
		2, 2, 2
	);
	int2x3 mat2 = int2x3(
		3, 3, 3,
		3, 3, 3
	);
	int2x3 mat3 = int2x3(
		4, 4, 4,
		4, 4, 4
	);

	bool2x3 test0  = mat0 <= mat0;
	bool2x3 test1  = mat0 >= mat0;
	bool2x3 test2  = mat0 <  mat1;
	bool2x3 test3  = mat0 <  mat2;
	bool2x3 test4  = mat0 <  mat3;

	bool2x3 test5  = mat1 >  mat0;
	bool2x3 test6  = mat1 <= mat1;
	bool2x3 test7  = mat1 >= mat1;
	bool2x3 test8  = mat1 <  mat2;
	bool2x3 test9  = mat1 <  mat3;

	bool2x3 test10 = mat2 >  mat0;
	bool2x3 test11 = mat2 >  mat1;
	bool2x3 test12 = mat2 <= mat2;
	bool2x3 test13 = mat2 >= mat2;
	bool2x3 test14 = mat2 <  mat3;

	bool2x3 test15 = mat3 >  mat0;
	bool2x3 test16 = mat3 >  mat1;
	bool2x3 test17 = mat3 >  mat2;
	bool2x3 test18 = mat3 <= mat3;
	bool2x3 test19 = mat3 >= mat3;

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

TEMPER_TEST( TestArray_int2x3 )
{
	int2x3 mat;

	TEMPER_EXPECT_TRUE( mat[0] == int3( 1, 0, 0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == int3( 0, 1, 0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_And_int2x3 )
{
	int2x3 a  = int2x3(
		21, 21, 21,
		21, 21, 21
	);
	int2x3 b  = int2x3(
		7, 7, 7,
		7, 7, 7
	);

	int2x3 answer = a & b;

	TEMPER_EXPECT_TRUE( answer == int2x3(
		5, 5, 5,
		5, 5, 5
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Or_int2x3 )
{
	int2x3 a  = int2x3(
		21, 21, 21,
		21, 21, 21
	);
	int2x3 b  = int2x3(
		7, 7, 7,
		7, 7, 7
	);

	int2x3 answer = a | b;

	TEMPER_EXPECT_TRUE( answer == int2x3(
		23, 23, 23,
		23, 23, 23
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Xor_int2x3 )
{
	int2x3 a  = int2x3(
		21, 21, 21,
		21, 21, 21
	);
	int2x3 b  = int2x3(
		7, 7, 7,
		7, 7, 7
	);

	int2x3 answer = a ^ b;

	TEMPER_EXPECT_TRUE( answer == int2x3(
		18, 18, 18,
		18, 18, 18
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftLeft_int2x3 )
{
	int2x3 a  = int2x3(
		1, 1, 1,
		1, 1, 1
	);
	int2x3 b  = int2x3(
		2, 2, 2,
		2, 2, 2
	);

	int2x3 answer = a << b;

	TEMPER_EXPECT_TRUE( answer == int2x3(
		4, 4, 4,
		4, 4, 4
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftRight_int2x3 )
{
	int2x3 a  = int2x3(
		16, 16, 16,
		16, 16, 16
	);
	int2x3 b  = int2x3(
		4, 4, 4,
		4, 4, 4
	);

	int2x3 answer = a >> b;

	TEMPER_EXPECT_TRUE( answer == int2x3(
		1, 1, 1,
		1, 1, 1
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Unary_int2x3 )
{
	int2x3 a = int2x3(
		0, 0, 0,
		0, 0, 0
	);

	int2x3 answer = ~a;

	TEMPER_EXPECT_TRUE( answer == int2x3(
		(int32_t) -1, (int32_t) -1, (int32_t) -1,
		(int32_t) -1, (int32_t) -1, (int32_t) -1
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_int2x3 )
{
	// scalar
	int2x3 id = int2x3(
		1, 0, 0,
		0, 1, 0
	);

	int2x3 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_int2x3 )
{
	// scalar
	int2x3 mat = int2x3(
		0, 1, 2,
		4, 5, 6
	);
	int3x2 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == int3x2(
		0, 4,
		1, 5,
		2, 6
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_int2x3 )
{
	int2x3 mat;
	int2x3 scaled = scale( mat, int3( 2, 2, 2 ) );

	TEMPER_EXPECT_TRUE( scaled == int2x3(
		2, 0, 0,
		0, 2, 0
	) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_int2x3 )
{
	TEMPER_RUN_TEST( TestAssignment_int2x3 );
	TEMPER_RUN_TEST( TestComponentWiseArithmeticAddition_int2x3 );
	TEMPER_RUN_TEST( TestComponentWiseArithmeticSubtraction_int2x3 );
	TEMPER_RUN_TEST( TestComponentWiseArithmeticMultiplication_int2x3 );
	TEMPER_RUN_TEST( TestComponentWiseArithmeticDivision_int2x3 );
	TEMPER_RUN_TEST( TestMultiplyMatrix_int2x3 );
	TEMPER_RUN_TEST( TestIncrement_int2x3 );
	TEMPER_RUN_TEST( TestDecrement_int2x3 );
	TEMPER_RUN_TEST( TestRelational_int2x3 );
	TEMPER_RUN_TEST( TestArray_int2x3 );
	TEMPER_RUN_TEST( TestBitwise_And_int2x3 );
	TEMPER_RUN_TEST( TestBitwise_Or_int2x3 );
	TEMPER_RUN_TEST( TestBitwise_Xor_int2x3 );
	TEMPER_RUN_TEST( TestBitwise_ShiftLeft_int2x3 );
	TEMPER_RUN_TEST( TestBitwise_ShiftRight_int2x3 );
	TEMPER_RUN_TEST( TestBitwise_Unary_int2x3 );
	TEMPER_RUN_TEST( TestIdentity_int2x3 );
	TEMPER_RUN_TEST( TestTranspose_int2x3 );
	TEMPER_RUN_TEST( TestScale_int2x3 );
}
