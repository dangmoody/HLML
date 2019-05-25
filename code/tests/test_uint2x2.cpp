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

TEMPER_TEST( TestAssignment_uint2x2 )
{
	uint2x2 mat;

	// fill single value
	mat = uint2x2( 999U );
	TEMPER_EXPECT_TRUE( mat[0] == uint2( 999U, 0U ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint2( 0U, 999U ) );

	// row filling
	mat = uint2x2(
		uint2( 0U, 1U ),
		uint2( 4U, 5U )
	);
	TEMPER_EXPECT_TRUE( mat[0] == uint2( 0U, 1U ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint2( 4U, 5U ) );

	// all values filled
	mat = uint2x2(
		16U, 15U,
		12U, 11U
	);
	TEMPER_EXPECT_TRUE( mat[0] == uint2( 16U, 15U ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint2( 12U, 11U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_uint2x2 )
{
	uint2x2 answer = uint2x2(
		7U, 7U,
		8U, 8U
	);

	uint2x2 a = uint2x2(
		6U, 6U,
		6U, 6U
	);
	uint2x2 b = uint2x2(
		1U, 1U,
		2U, 2U
	);
	uint2x2 c = a + b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_uint2x2 )
{
	uint2x2 answer = uint2x2(
		5U, 5U,
		4U, 4U
	);

	uint2x2 a = uint2x2(
		6U, 6U,
		6U, 6U
	);
	uint2x2 b = uint2x2(
		1U, 1U,
		2U, 2U
	);
	uint2x2 c = a - b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_uint2x2 )
{
	uint2x2 answer = uint2x2(
		18U, 18U,
		18U, 18U
	);

	uint2x2 a = uint2x2(
		6U, 6U,
		6U, 6U
	);
	uint2x2 b = uint2x2(
		1U, 1U,
		2U, 2U
	);
	uint2x2 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_uint2x2 )
{
	uint2x2 answer = uint2x2(
		6U, 6U,
		3U, 3U
	);

	uint2x2 a = uint2x2(
		6U, 6U,
		6U, 6U
	);
	uint2x2 b = uint2x2(
		1U, 1U,
		2U, 2U
	);
	uint2x2 c = a / b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyVector_uint2x2 )
{
	uint2 answerVec = uint2( 4U, 16U );

	uint2x2 a = uint2x2(
		1U, 2U,
		5U, 6U
	);
	uint2 b = uint2( 2U, 1U );
	uint2 c = a * b;

	TEMPER_EXPECT_TRUE( c == answerVec );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_uint2x2 )
{
	uint2x2 mat;

	// prefix
	mat = uint2x2(
		0U, 0U,
		0U, 0U
	);
	++mat;
	TEMPER_EXPECT_TRUE( mat == uint2x2(
		1U, 1U,
		1U, 1U
	) );

	// postfix
	mat = uint2x2(
		0U, 0U,
		0U, 0U
	);
	mat++;
	TEMPER_EXPECT_TRUE( mat == uint2x2(
		1U, 1U,
		1U, 1U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_uint2x2 )
{
	uint2x2 mat;

	// prefix
	mat = uint2x2(
		1U, 1U,
		1U, 1U
	);
	--mat;
	TEMPER_EXPECT_TRUE( mat == uint2x2(
		0U, 0U,
		0U, 0U
	) );

	// postfix
	mat = uint2x2(
		1U, 1U,
		1U, 1U
	);
	mat--;
	TEMPER_EXPECT_TRUE( mat == uint2x2(
		0U, 0U,
		0U, 0U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_uint2x2 )
{
	bool2x2 allTrue = bool2x2(
		true, true,
		true, true
	);

	uint2x2 mat0 = uint2x2(
		1U, 1U,
		1U, 1U
	);
	uint2x2 mat1 = uint2x2(
		2U, 2U,
		2U, 2U
	);
	uint2x2 mat2 = uint2x2(
		3U, 3U,
		3U, 3U
	);
	uint2x2 mat3 = uint2x2(
		4U, 4U,
		4U, 4U
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

TEMPER_TEST( TestArray_uint2x2 )
{
	uint2x2 mat;

	TEMPER_EXPECT_TRUE( mat[0] == uint2( 1U, 0U ) );
	TEMPER_EXPECT_TRUE( mat[1] == uint2( 0U, 1U ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwiseAnd_uint2x2 )
{
	uint2x2 a  = uint2x2(
		21U, 21U,
		21U, 21U
	);
	uint2x2 b  = uint2x2(
		7U, 7U,
		7U, 7U
	);

	uint2x2 answer = a & b;

	TEMPER_EXPECT_TRUE( answer == uint2x2(
		5U, 5U,
		5U, 5U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwiseOr_uint2x2 )
{
	uint2x2 a  = uint2x2(
		21U, 21U,
		21U, 21U
	);
	uint2x2 b  = uint2x2(
		7U, 7U,
		7U, 7U
	);

	uint2x2 answer = a | b;

	TEMPER_EXPECT_TRUE( answer == uint2x2(
		23U, 23U,
		23U, 23U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwiseXor_uint2x2 )
{
	uint2x2 a  = uint2x2(
		21U, 21U,
		21U, 21U
	);
	uint2x2 b  = uint2x2(
		7U, 7U,
		7U, 7U
	);

	uint2x2 answer = a ^ b;

	TEMPER_EXPECT_TRUE( answer == uint2x2(
		18U, 18U,
		18U, 18U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwiseShiftLeft_uint2x2 )
{
	uint2x2 a  = uint2x2(
		1U, 1U,
		1U, 1U
	);
	uint2x2 b  = uint2x2(
		2U, 2U,
		2U, 2U
	);

	uint2x2 answer = a << b;

	TEMPER_EXPECT_TRUE( answer == uint2x2(
		4U, 4U,
		4U, 4U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwiseShiftRight_uint2x2 )
{
	uint2x2 a  = uint2x2(
		16U, 16U,
		16U, 16U
	);
	uint2x2 b  = uint2x2(
		4U, 4U,
		4U, 4U
	);

	uint2x2 answer = a >> b;

	TEMPER_EXPECT_TRUE( answer == uint2x2(
		1U, 1U,
		1U, 1U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestBitwiseUnary_uint2x2 )
{
	uint2x2 a = uint2x2(
		0U, 0U,
		0U, 0U
	);

	uint2x2 answer = ~a;

	TEMPER_EXPECT_TRUE( answer == uint2x2( (uint32_t) -1, (uint32_t) -1,
(uint32_t) -1, (uint32_t) -1
 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_uint2x2 )
{
	uint2x2 id = uint2x2(
		1U, 0U,
		0U, 1U
	);

	uint2x2 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_uint2x2 )
{
	uint2x2 mat = uint2x2(
		0U, 1U,
		2U, 3U
	);
	uint2x2 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == uint2x2(
		0U, 2U,
		1U, 3U
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_uint2x2 )
{
	uint2x2 mat;
	uint2x2 scaled = scale( mat, uint3( 2U, 2U, 2U ) );

	TEMPER_EXPECT_TRUE( scaled == uint2x2(
		2U, 0U,
		0U, 2U
	) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_uint2x2 )
{
	TEMPER_RUN_TEST( TestAssignment_uint2x2 );

	TEMPER_RUN_TEST( TestArithmeticAddition_uint2x2 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_uint2x2 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_uint2x2 );
	TEMPER_RUN_TEST( TestArithmeticDivision_uint2x2 );

	TEMPER_RUN_TEST( TestMultiplyVector_uint2x2 );

	TEMPER_RUN_TEST( TestIncrement_uint2x2 );
	TEMPER_RUN_TEST( TestDecrement_uint2x2 );

	TEMPER_RUN_TEST( TestRelational_uint2x2 );

	TEMPER_RUN_TEST( TestBitwiseAnd_uint2x2 );
	TEMPER_RUN_TEST( TestBitwiseOr_uint2x2 );
	TEMPER_RUN_TEST( TestBitwiseXor_uint2x2 );
	TEMPER_RUN_TEST( TestBitwiseUnary_uint2x2 );
	TEMPER_RUN_TEST( TestBitwiseShiftLeft_uint2x2 );
	TEMPER_RUN_TEST( TestBitwiseShiftRight_uint2x2 );
	TEMPER_RUN_TEST( TestArray_uint2x2 );

	TEMPER_RUN_TEST( TestIdentity_uint2x2 );
	TEMPER_RUN_TEST( TestTranspose_uint2x2 );


}
