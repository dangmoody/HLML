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

TEMPER_TEST( TestAssignment_float2x3 )
{
	float2x3 mat;

	// fill single value
	mat = float2x3( 999.000000f );
	TEMPER_EXPECT_TRUE( mat[0] == float3( 999.000000f, 0.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float3( 0.000000f, 999.000000f, 0.000000f ) );

	// row filling
	mat = float2x3(
		float3( 0.000000f, 1.000000f, 2.000000f ),
		float3( 4.000000f, 5.000000f, 6.000000f )
	);
	TEMPER_EXPECT_TRUE( mat[0] == float3( 0.000000f, 1.000000f, 2.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float3( 4.000000f, 5.000000f, 6.000000f ) );

	// all values filled
	mat = float2x3(
		16.000000f, 15.000000f, 14.000000f,
		12.000000f, 11.000000f, 10.000000f
	);
	TEMPER_EXPECT_TRUE( mat[0] == float3( 16.000000f, 15.000000f, 14.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float3( 12.000000f, 11.000000f, 10.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_float2x3 )
{
	float2x3 answer = float2x3(
		7.000000f, 7.000000f, 7.000000f,
		8.000000f, 8.000000f, 8.000000f
	);

	float2x3 a = float2x3(
		6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f
	);
	float2x3 b = float2x3(
		1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f
	);
	float2x3 c = a + b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_float2x3 )
{
	float2x3 answer = float2x3(
		5.000000f, 5.000000f, 5.000000f,
		4.000000f, 4.000000f, 4.000000f
	);

	float2x3 a = float2x3(
		6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f
	);
	float2x3 b = float2x3(
		1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f
	);
	float2x3 c = a - b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_float2x3 )
{
	float2x2 answer = float2x2(
		36.000000f, 36.000000f,
		36.000000f, 36.000000f
	);

	float2x3 a = float2x3(
		6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f
	);
	float3x2 b = float3x2(
		1.000000f, 1.000000f,
		2.000000f, 2.000000f,
		3.000000f, 3.000000f
	);
	float2x2 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_float2x3 )
{
	float2x3 answer = float2x3(
		6.000000f, 6.000000f, 6.000000f,
		3.000000f, 3.000000f, 3.000000f
	);

	float2x3 a = float2x3(
		6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f
	);
	float2x3 b = float2x3(
		1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f
	);
	float2x3 c = a / b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_float2x3 )
{
	float2x3 mat;

	// prefix
	mat = float2x3(
		0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f
	);
	++mat;
	TEMPER_EXPECT_TRUE( mat == float2x3(
		1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f
	) );

	// postfix
	mat = float2x3(
		0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f
	);
	mat++;
	TEMPER_EXPECT_TRUE( mat == float2x3(
		1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_float2x3 )
{
	float2x3 mat;

	// prefix
	mat = float2x3(
		1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f
	);
	--mat;
	TEMPER_EXPECT_TRUE( mat == float2x3(
		0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f
	) );

	// postfix
	mat = float2x3(
		1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f
	);
	mat--;
	TEMPER_EXPECT_TRUE( mat == float2x3(
		0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_float2x3 )
{
	bool2x3 allTrue = bool2x3(
		true, true, true,
		true, true, true
	);

	float2x3 mat0 = float2x3(
		1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f
	);
	float2x3 mat1 = float2x3(
		2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f
	);
	float2x3 mat2 = float2x3(
		3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f
	);
	float2x3 mat3 = float2x3(
		4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f
	);

	bool2x3 test0 = mat0 <= mat0;
	bool2x3 test1 = mat0 >= mat0;
	bool2x3 test2 = mat0 < mat1;

	bool2x3 test3 = mat1 <= mat1;
	bool2x3 test4 = mat1 >= mat1;
	bool2x3 test5 = mat1 < mat2;
	bool2x3 test6 = mat1 > mat0;

	bool2x3 test7 = mat2 <= mat2;
	bool2x3 test8 = mat2 >= mat2;
	bool2x3 test9 = mat2 < mat3;
	bool2x3 test10 = mat2 > mat1;

	bool2x3 test11 = mat3 <= mat3;
	bool2x3 test12 = mat3 >= mat3;
	bool2x3 test13 = mat3 > mat2;

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

TEMPER_TEST( TestArray_float2x3 )
{
	float2x3 mat;

	TEMPER_EXPECT_TRUE( mat[0] == float3( 1.000000f, 0.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float3( 0.000000f, 1.000000f, 0.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_float2x3 )
{
	float2x3 id = float2x3(
		1.000000f, 0.000000f, 0.000000f,
		0.000000f, 1.000000f, 0.000000f
	);

	float2x3 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_float2x3 )
{
	float2x3 mat = float2x3(
		0.000000f, 1.000000f, 2.000000f,
		3.000000f, 4.000000f, 5.000000f
	);
	float3x2 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == float3x2(
		0.000000f, 3.000000f,
		1.000000f, 4.000000f,
		2.000000f, 5.000000f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_float2x3 )
{
	float2x3 mat;
	float2x3 scaled = scale( mat, float3( 2.000000f, 2.000000f, 2.000000f ) );

	TEMPER_EXPECT_TRUE( scaled == float2x3(
		2.000000f, 0.000000f, 0.000000f,
		0.000000f, 2.000000f, 0.000000f
	) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_float2x3 )
{
	TEMPER_RUN_TEST( TestAssignment_float2x3 );

	TEMPER_RUN_TEST( TestArithmeticAddition_float2x3 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_float2x3 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_float2x3 );
	TEMPER_RUN_TEST( TestArithmeticDivision_float2x3 );

	TEMPER_RUN_TEST( TestIncrement_float2x3 );
	TEMPER_RUN_TEST( TestDecrement_float2x3 );

	TEMPER_RUN_TEST( TestRelational_float2x3 );

	TEMPER_RUN_TEST( TestArray_float2x3 );

	TEMPER_RUN_TEST( TestIdentity_float2x3 );
	TEMPER_RUN_TEST( TestTranspose_float2x3 );


}
