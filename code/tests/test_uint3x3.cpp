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

TEMPER_TEST( TestAssignment_uint3x3 )
{
	uint3x3 mat;

	// fill single value
	mat = uint3x3( 999U );
	TEMPER_EXPECT_TRUE( mat[0] == uint3( 999U, 0U, 0U ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint3( 0U, 999U, 0U ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint3( 0U, 0U, 999U ) );

	// row filling
	mat = uint3x3(
		uint3( 0U, 1U, 2U ),
		uint3( 4U, 5U, 6U ),
		uint3( 8U, 9U, 10U )
	);
	TEMPER_EXPECT_TRUE( mat[0] == uint3( 0U, 1U, 2U ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint3( 4U, 5U, 6U ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint3( 8U, 9U, 10U ) );

	// all values filled
	mat = uint3x3(
		16U, 15U, 14U,
		12U, 11U, 10U,
		8U, 7U, 6U
	);
	TEMPER_EXPECT_TRUE( mat[0] == uint3( 16U, 15U, 14U ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint3( 12U, 11U, 10U ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint3( 8U, 7U, 6U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_uint3x3 )
{
	uint3x3 answer = uint3x3(
		7U, 7U, 7U,
		8U, 8U, 8U,
		15U, 15U, 15U
	);

	uint3x3 a = uint3x3(
		6U, 6U, 6U,
		6U, 6U, 6U,
		12U, 12U, 12U
	);
	uint3x3 b = uint3x3(
		1U, 1U, 1U,
		2U, 2U, 2U,
		3U, 3U, 3U
	);
	uint3x3 c = a + b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_uint3x3 )
{
	uint3x3 answer = uint3x3(
		5U, 5U, 5U,
		4U, 4U, 4U,
		9U, 9U, 9U
	);

	uint3x3 a = uint3x3(
		6U, 6U, 6U,
		6U, 6U, 6U,
		12U, 12U, 12U
	);
	uint3x3 b = uint3x3(
		1U, 1U, 1U,
		2U, 2U, 2U,
		3U, 3U, 3U
	);
	uint3x3 c = a - b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_uint3x3 )
{
	uint3x3 answer = uint3x3(
		36U, 36U, 36U,
		36U, 36U, 36U,
		72U, 72U, 72U
	);

	uint3x3 a = uint3x3(
		6U, 6U, 6U,
		6U, 6U, 6U,
		12U, 12U, 12U
	);
	uint3x3 b = uint3x3(
		1U, 1U, 1U,
		2U, 2U, 2U,
		3U, 3U, 3U
	);
	uint3x3 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_uint3x3 )
{
	uint3x3 answer = uint3x3(
		6U, 6U, 6U,
		3U, 3U, 3U,
		4U, 4U, 4U
	);

	uint3x3 a = uint3x3(
		6U, 6U, 6U,
		6U, 6U, 6U,
		12U, 12U, 12U
	);
	uint3x3 b = uint3x3(
		1U, 1U, 1U,
		2U, 2U, 2U,
		3U, 3U, 3U
	);
	uint3x3 c = a / b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyVector_uint3x3 )
{
	uint3 answerVec = uint3( 16U, 44U, 72U );

	uint3x3 a = uint3x3(
		1U, 2U, 3U,
		5U, 6U, 7U,
		9U, 10U, 11U
	);
	uint3 b = uint3( 2U, 1U, 4U );
	uint3 c = a * b;

	TEMPER_EXPECT_TRUE( c == answerVec );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_uint3x3 )
{
	uint3x3 mat;

	// prefix
	mat = uint3x3(
		0U, 0U, 0U,
		0U, 0U, 0U,
		0U, 0U, 0U
	);
	++mat;
	TEMPER_EXPECT_TRUE( mat == uint3x3(
		1U, 1U, 1U,
		1U, 1U, 1U,
		1U, 1U, 1U
	) );

	// postfix
	mat = uint3x3(
		0U, 0U, 0U,
		0U, 0U, 0U,
		0U, 0U, 0U
	);
	mat++;
	TEMPER_EXPECT_TRUE( mat == uint3x3(
		1U, 1U, 1U,
		1U, 1U, 1U,
		1U, 1U, 1U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_uint3x3 )
{
	uint3x3 mat;

	// prefix
	mat = uint3x3(
		1U, 1U, 1U,
		1U, 1U, 1U,
		1U, 1U, 1U
	);
	--mat;
	TEMPER_EXPECT_TRUE( mat == uint3x3(
		0U, 0U, 0U,
		0U, 0U, 0U,
		0U, 0U, 0U
	) );

	// postfix
	mat = uint3x3(
		1U, 1U, 1U,
		1U, 1U, 1U,
		1U, 1U, 1U
	);
	mat--;
	TEMPER_EXPECT_TRUE( mat == uint3x3(
		0U, 0U, 0U,
		0U, 0U, 0U,
		0U, 0U, 0U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_uint3x3 )
{
	bool3x3 allTrue = bool3x3(
		true, true, true,
		true, true, true,
		true, true, true
	);

	uint3x3 mat0 = uint3x3(
		1U, 1U, 1U,
		1U, 1U, 1U,
		1U, 1U, 1U
	);
	uint3x3 mat1 = uint3x3(
		2U, 2U, 2U,
		2U, 2U, 2U,
		2U, 2U, 2U
	);
	uint3x3 mat2 = uint3x3(
		3U, 3U, 3U,
		3U, 3U, 3U,
		3U, 3U, 3U
	);
	uint3x3 mat3 = uint3x3(
		4U, 4U, 4U,
		4U, 4U, 4U,
		4U, 4U, 4U
	);

	bool3x3 test0  = mat0 <= mat0;
	bool3x3 test1  = mat0 >= mat0;
	bool3x3 test2  = mat0 <  mat1;
	bool3x3 test3  = mat0 <  mat2;
	bool3x3 test4  = mat0 <  mat3;

	bool3x3 test5  = mat1 >  mat0;
	bool3x3 test6  = mat1 <= mat1;
	bool3x3 test7  = mat1 >= mat1;
	bool3x3 test8  = mat1 <  mat2;
	bool3x3 test9  = mat1 <  mat3;

	bool3x3 test10 = mat2 >  mat0;
	bool3x3 test11 = mat2 >  mat1;
	bool3x3 test12 = mat2 <= mat2;
	bool3x3 test13 = mat2 >= mat2;
	bool3x3 test14 = mat2 <  mat3;

	bool3x3 test15 = mat3 >  mat0;
	bool3x3 test16 = mat3 >  mat1;
	bool3x3 test17 = mat3 >  mat2;
	bool3x3 test18 = mat3 <= mat3;
	bool3x3 test19 = mat3 >= mat3;

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

TEMPER_TEST( TestArray_uint3x3 )
{
	uint3x3 mat;

	TEMPER_EXPECT_TRUE( mat[0] == uint3( 1U, 0U, 0U ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint3( 0U, 1U, 0U ) );
	TEMPER_EXPECT_TRUE( mat[2] == uint3( 0U, 0U, 1U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_And_uint3x3 )
{
	uint3x3 a  = uint3x3(
		21U, 21U, 21U,
		21U, 21U, 21U,
		21U, 21U, 21U
	);
	uint3x3 b  = uint3x3(
		7U, 7U, 7U,
		7U, 7U, 7U,
		7U, 7U, 7U
	);

	uint3x3 answer = a & b;

	TEMPER_EXPECT_TRUE( answer == uint3x3(
		5U, 5U, 5U,
		5U, 5U, 5U,
		5U, 5U, 5U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Or_uint3x3 )
{
	uint3x3 a  = uint3x3(
		21U, 21U, 21U,
		21U, 21U, 21U,
		21U, 21U, 21U
	);
	uint3x3 b  = uint3x3(
		7U, 7U, 7U,
		7U, 7U, 7U,
		7U, 7U, 7U
	);

	uint3x3 answer = a | b;

	TEMPER_EXPECT_TRUE( answer == uint3x3(
		23U, 23U, 23U,
		23U, 23U, 23U,
		23U, 23U, 23U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Xor_uint3x3 )
{
	uint3x3 a  = uint3x3(
		21U, 21U, 21U,
		21U, 21U, 21U,
		21U, 21U, 21U
	);
	uint3x3 b  = uint3x3(
		7U, 7U, 7U,
		7U, 7U, 7U,
		7U, 7U, 7U
	);

	uint3x3 answer = a ^ b;

	TEMPER_EXPECT_TRUE( answer == uint3x3(
		18U, 18U, 18U,
		18U, 18U, 18U,
		18U, 18U, 18U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftLeft_uint3x3 )
{
	uint3x3 a  = uint3x3(
		1U, 1U, 1U,
		1U, 1U, 1U,
		1U, 1U, 1U
	);
	uint3x3 b  = uint3x3(
		2U, 2U, 2U,
		2U, 2U, 2U,
		2U, 2U, 2U
	);

	uint3x3 answer = a << b;

	TEMPER_EXPECT_TRUE( answer == uint3x3(
		4U, 4U, 4U,
		4U, 4U, 4U,
		4U, 4U, 4U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_ShiftRight_uint3x3 )
{
	uint3x3 a  = uint3x3(
		16U, 16U, 16U,
		16U, 16U, 16U,
		16U, 16U, 16U
	);
	uint3x3 b  = uint3x3(
		4U, 4U, 4U,
		4U, 4U, 4U,
		4U, 4U, 4U
	);

	uint3x3 answer = a >> b;

	TEMPER_EXPECT_TRUE( answer == uint3x3(
		1U, 1U, 1U,
		1U, 1U, 1U,
		1U, 1U, 1U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwise_Unary_uint3x3 )
{
	uint3x3 a = uint3x3(
		0U, 0U, 0U,
		0U, 0U, 0U,
		0U, 0U, 0U
	);

	uint3x3 answer = ~a;

	TEMPER_EXPECT_TRUE( answer == uint3x3(
		(uint32_t) -1, (uint32_t) -1, (uint32_t) -1,
		(uint32_t) -1, (uint32_t) -1, (uint32_t) -1,
		(uint32_t) -1, (uint32_t) -1, (uint32_t) -1
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_uint3x3 )
{
	uint3x3 id = uint3x3(
		1U, 0, 0,
		0, 1U, 0,
		0, 0, 1U
	);

	uint3x3 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_uint3x3 )
{
	uint3x3 mat = uint3x3(
		0U, 1U, 2U,
		4U, 5U, 6U,
		8U, 9U, 10U
	);
	uint3x3 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == uint3x3(
		0U, 4U, 8U,
		1U, 5U, 9U,
		2U, 6U, 10U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_uint3x3 )
{
	uint3x3 mat;
	uint3x3 translated = uint3x3(
		1U, 0U, 2U,
		0U, 1U, 3U,
		0U, 0U, 1U
	);

	uint2 translation = uint2( 2U, 3U );
	mat = translate( mat, translation );

	TEMPER_EXPECT_TRUE( mat == translated );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_uint3x3 )
{
	uint3x3 mat;
	uint3x3 scaled = scale( mat, uint3( 2U, 2U, 2U ) );

	TEMPER_EXPECT_TRUE( scaled == uint3x3(
		2U, 0, 0,
		0, 2U, 0,
		0, 0, 2U
	) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_uint3x3 )
{
	TEMPER_RUN_TEST( TestAssignment_uint3x3 );
	TEMPER_RUN_TEST( TestArithmeticAddition_uint3x3 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_uint3x3 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_uint3x3 );
	TEMPER_RUN_TEST( TestArithmeticDivision_uint3x3 );
	TEMPER_RUN_TEST( TestMultiplyVector_uint3x3 );
	TEMPER_RUN_TEST( TestIncrement_uint3x3 );
	TEMPER_RUN_TEST( TestDecrement_uint3x3 );
	TEMPER_RUN_TEST( TestRelational_uint3x3 );
	TEMPER_RUN_TEST( TestArray_uint3x3 );
	TEMPER_RUN_TEST( TestBitwise_And_uint3x3 );
	TEMPER_RUN_TEST( TestBitwise_Or_uint3x3 );
	TEMPER_RUN_TEST( TestBitwise_Xor_uint3x3 );
	TEMPER_RUN_TEST( TestBitwise_ShiftLeft_uint3x3 );
	TEMPER_RUN_TEST( TestBitwise_ShiftRight_uint3x3 );
	TEMPER_RUN_TEST( TestBitwise_Unary_uint3x3 );
	TEMPER_RUN_TEST( TestIdentity_uint3x3 );
	TEMPER_RUN_TEST( TestTranspose_uint3x3 );
	TEMPER_RUN_TEST( TestTranslate_uint3x3 );
	TEMPER_RUN_TEST( TestScale_uint3x3 );
}
