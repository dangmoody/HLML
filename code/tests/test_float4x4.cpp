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

TEMPER_TEST( TestAssignment_float4x4 )
{
	float4x4 mat;

	// fill single value
	mat = float4x4( 999.000000f );
	TEMPER_EXPECT_TRUE( mat[0] == float4( 999.000000f, 0.000000f, 0.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float4( 0.000000f, 999.000000f, 0.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[2] == float4( 0.000000f, 0.000000f, 999.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[3] == float4( 0.000000f, 0.000000f, 0.000000f, 999.000000f ) );

	// row filling
	mat = float4x4(
		float4( 0.000000f, 1.000000f, 2.000000f, 3.000000f ),
		float4( 4.000000f, 5.000000f, 6.000000f, 7.000000f ),
		float4( 8.000000f, 9.000000f, 10.000000f, 11.000000f ),
		float4( 12.000000f, 13.000000f, 14.000000f, 15.000000f )
	);
	TEMPER_EXPECT_TRUE( mat[0] == float4( 0.000000f, 1.000000f, 2.000000f, 3.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float4( 4.000000f, 5.000000f, 6.000000f, 7.000000f ) );
	TEMPER_EXPECT_TRUE( mat[2] == float4( 8.000000f, 9.000000f, 10.000000f, 11.000000f ) );
	TEMPER_EXPECT_TRUE( mat[3] == float4( 12.000000f, 13.000000f, 14.000000f, 15.000000f ) );

	// all values filled
	mat = float4x4(
		16.000000f, 15.000000f, 14.000000f, 13.000000f,
		12.000000f, 11.000000f, 10.000000f, 9.000000f,
		8.000000f, 7.000000f, 6.000000f, 5.000000f,
		4.000000f, 3.000000f, 2.000000f, 1.000000f
	);
	TEMPER_EXPECT_TRUE( mat[0] == float4( 16.000000f, 15.000000f, 14.000000f, 13.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float4( 12.000000f, 11.000000f, 10.000000f, 9.000000f ) );
	TEMPER_EXPECT_TRUE( mat[2] == float4( 8.000000f, 7.000000f, 6.000000f, 5.000000f ) );
	TEMPER_EXPECT_TRUE( mat[3] == float4( 4.000000f, 3.000000f, 2.000000f, 1.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_float4x4 )
{
	float4x4 answer = float4x4(
		7.000000f, 7.000000f, 7.000000f, 7.000000f,
		8.000000f, 8.000000f, 8.000000f, 8.000000f,
		15.000000f, 15.000000f, 15.000000f, 15.000000f,
		24.000000f, 24.000000f, 24.000000f, 24.000000f
	);

	float4x4 a = float4x4(
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		12.000000f, 12.000000f, 12.000000f, 12.000000f,
		18.000000f, 18.000000f, 18.000000f, 18.000000f
	);
	float4x4 b = float4x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		6.000000f, 6.000000f, 6.000000f, 6.000000f
	);
	float4x4 c = a + b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_float4x4 )
{
	float4x4 answer = float4x4(
		5.000000f, 5.000000f, 5.000000f, 5.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		9.000000f, 9.000000f, 9.000000f, 9.000000f,
		12.000000f, 12.000000f, 12.000000f, 12.000000f
	);

	float4x4 a = float4x4(
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		12.000000f, 12.000000f, 12.000000f, 12.000000f,
		18.000000f, 18.000000f, 18.000000f, 18.000000f
	);
	float4x4 b = float4x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		6.000000f, 6.000000f, 6.000000f, 6.000000f
	);
	float4x4 c = a - b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_float4x4 )
{
	float4x4 answer = float4x4(
		72.000000f, 72.000000f, 72.000000f, 72.000000f,
		72.000000f, 72.000000f, 72.000000f, 72.000000f,
		144.000000f, 144.000000f, 144.000000f, 144.000000f,
		216.000000f, 216.000000f, 216.000000f, 216.000000f
	);

	float4x4 a = float4x4(
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		6.000000f, 6.000000f, 6.000000f, 6.000000f,
		12.000000f, 12.000000f, 12.000000f, 12.000000f,
		18.000000f, 18.000000f, 18.000000f, 18.000000f
	);
	float4x4 b = float4x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		6.000000f, 6.000000f, 6.000000f, 6.000000f
	);
	float4x4 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_float4x4 )
{
	float4x4 answer = float4x4(
		1.000000f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.000000f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.000000f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.000000f
	);

	float4x4 a = float4x4(
		6.000000f, 2.000000f, 3.000000f, 4.000000f,
		2.000000f, 7.000000f, 5.000000f, 3.000000f,
		3.000000f, 5.000000f, 7.000000f, 2.000000f,
		4.000000f, 3.000000f, 2.000000f, 6.000000f
	);
	float4x4 b = float4x4(
		6.000000f, 2.000000f, 3.000000f, 4.000000f,
		2.000000f, 7.000000f, 5.000000f, 3.000000f,
		3.000000f, 5.000000f, 7.000000f, 2.000000f,
		4.000000f, 3.000000f, 2.000000f, 6.000000f
	);
	float4x4 c = a / b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyVector_float4x4 )
{
	float4 answerVec = float4( 28.000000f, 68.000000f, 108.000000f, 148.000000f );

	float4x4 a = float4x4(
		1.000000f, 2.000000f, 3.000000f, 4.000000f,
		5.000000f, 6.000000f, 7.000000f, 8.000000f,
		9.000000f, 10.000000f, 11.000000f, 12.000000f,
		13.000000f, 14.000000f, 15.000000f, 16.000000f
	);
	float4 b = float4( 2.000000f, 1.000000f, 4.000000f, 3.000000f );
	float4 c = a * b;

	TEMPER_EXPECT_TRUE( c == answerVec );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_float4x4 )
{
	float4x4 mat;

	// prefix
	mat = float4x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	);
	++mat;
	TEMPER_EXPECT_TRUE( mat == float4x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	) );

	// postfix
	mat = float4x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	);
	mat++;
	TEMPER_EXPECT_TRUE( mat == float4x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_float4x4 )
{
	float4x4 mat;

	// prefix
	mat = float4x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	);
	--mat;
	TEMPER_EXPECT_TRUE( mat == float4x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	) );

	// postfix
	mat = float4x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	);
	mat--;
	TEMPER_EXPECT_TRUE( mat == float4x4(
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 0.000000f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_float4x4 )
{
	bool4x4 allTrue = bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	);

	float4x4 mat0 = float4x4(
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f,
		1.000000f, 1.000000f, 1.000000f, 1.000000f
	);
	float4x4 mat1 = float4x4(
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f,
		2.000000f, 2.000000f, 2.000000f, 2.000000f
	);
	float4x4 mat2 = float4x4(
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f,
		3.000000f, 3.000000f, 3.000000f, 3.000000f
	);
	float4x4 mat3 = float4x4(
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f,
		4.000000f, 4.000000f, 4.000000f, 4.000000f
	);

	bool4x4 test0  = mat0 <= mat0;
	bool4x4 test1  = mat0 >= mat0;
	bool4x4 test2  = mat0 <  mat1;
	bool4x4 test3  = mat0 <  mat2;
	bool4x4 test4  = mat0 <  mat3;

	bool4x4 test5  = mat1 >  mat0;
	bool4x4 test6  = mat1 <= mat1;
	bool4x4 test7  = mat1 >= mat1;
	bool4x4 test8  = mat1 <  mat2;
	bool4x4 test9  = mat1 <  mat3;

	bool4x4 test10 = mat2 >  mat0;
	bool4x4 test11 = mat2 >  mat1;
	bool4x4 test12 = mat2 <= mat2;
	bool4x4 test13 = mat2 >= mat2;
	bool4x4 test14 = mat2 <  mat3;

	bool4x4 test15 = mat3 >  mat0;
	bool4x4 test16 = mat3 >  mat1;
	bool4x4 test17 = mat3 >  mat2;
	bool4x4 test18 = mat3 <= mat3;
	bool4x4 test19 = mat3 >= mat3;

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

TEMPER_TEST( TestArray_float4x4 )
{
	float4x4 mat;

	TEMPER_EXPECT_TRUE( mat[0] == float4( 1.000000f, 0.000000f, 0.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[1] == float4( 0.000000f, 1.000000f, 0.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[2] == float4( 0.000000f, 0.000000f, 1.000000f, 0.000000f ) );
	TEMPER_EXPECT_TRUE( mat[3] == float4( 0.000000f, 0.000000f, 0.000000f, 1.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_float4x4 )
{
	float4x4 id = float4x4(
		1.000000f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.000000f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.000000f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.000000f
	);

	float4x4 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_float4x4 )
{
	float4x4 mat = float4x4(
		0.000000f, 1.000000f, 2.000000f, 3.000000f,
		4.000000f, 5.000000f, 6.000000f, 7.000000f,
		8.000000f, 9.000000f, 10.000000f, 11.000000f,
		12.000000f, 13.000000f, 14.000000f, 15.000000f
	);
	float4x4 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == float4x4(
		0.000000f, 4.000000f, 8.000000f, 12.000000f,
		1.000000f, 5.000000f, 9.000000f, 13.000000f,
		2.000000f, 6.000000f, 10.000000f, 14.000000f,
		3.000000f, 7.000000f, 11.000000f, 15.000000f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestInverse_float4x4 )
{
	float4x4 identityMatrix;

	float4x4 mat = float4x4(
		6.000000f, 2.000000f, 3.000000f, 4.000000f,
		2.000000f, 7.000000f, 5.000000f, 3.000000f,
		3.000000f, 5.000000f, 7.000000f, 2.000000f,
		4.000000f, 3.000000f, 2.000000f, 6.000000f
	);
	float4x4 matInverse = inverse( mat );

	TEMPER_EXPECT_TRUE( mat * matInverse == identityMatrix );

	TEMPER_PASS();
}

TEMPER_TEST( TestDeterminant_float4x4 )
{
	float4x4 mat = float4x4(
		6.000000f, 2.000000f, 3.000000f, 4.000000f,
		2.000000f, 7.000000f, 5.000000f, 3.000000f,
		3.000000f, 5.000000f, 7.000000f, 2.000000f,
		4.000000f, 3.000000f, 2.000000f, 6.000000f
	);
	float det = determinant( mat );

	TEMPER_EXPECT_TRUE( floateq( det, 285.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_float4x4 )
{
	float4x4 mat;
	float4x4 translated = float4x4(
		1.000000f, 0.000000f, 0.000000f, 2.000000f,
		0.000000f, 1.000000f, 0.000000f, 3.000000f,
		0.000000f, 0.000000f, 1.000000f, 4.000000f,
		0.000000f, 0.000000f, 0.000000f, 1.000000f
	);

	float3 translation = float3( 2.000000f, 3.000000f, 4.000000f );
	mat = translate( mat, translation );

	TEMPER_EXPECT_TRUE( mat == translated );

	TEMPER_PASS();
}

TEMPER_TEST( TestRotate_float4x4 )
{
	float4x4 mat;
	float4x4 yaw = rotate( mat, radians( 45.000000f ), float3( 0.000000f, 1.000000f, 0.000000f ) );
	float4x4 pitch = rotate( mat, radians( 45.000000f ), float3( 1.000000f, 0.000000f, 0.000000f ) );
	float4x4 roll = rotate( mat, radians( 45.000000f ), float3( 0.000000f, 0.000000f, 1.000000f ) );

	float4x4 answerYaw = float4x4(
		0.707107f, 0.000000f, 0.707107f, 0.000000f,
		0.000000f, 1.000000f, 0.000000f, 0.000000f,
		-0.707107f, 0.000000f, 0.707107f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 1.000000f
	);
	float4x4 answerPitch = float4x4(
		1.000000f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.707107f, -0.707107f, 0.000000f,
		0.000000f, 0.707107f, 0.707107f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 1.000000f
	);
	float4x4 answerRoll = float4x4(
		0.707107f, -0.707107f, 0.000000f, 0.000000f,
		0.707107f, 0.707107f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 1.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 1.000000f
	);

	TEMPER_EXPECT_TRUE( yaw == answerYaw );
	TEMPER_EXPECT_TRUE( pitch == answerPitch );
	TEMPER_EXPECT_TRUE( roll == answerRoll );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_float4x4 )
{
	float4x4 mat;
	float4x4 scaled = scale( mat, float3( 2.000000f, 2.000000f, 2.000000f ) );

	TEMPER_EXPECT_TRUE( scaled == float4x4(
		2.000000f, 0.0f, 0.0f, 0.0f,
		0.0f, 2.000000f, 0.0f, 0.0f,
		0.0f, 0.0f, 2.000000f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.000000f
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestOrtho_float4x4 )
{
	float4x4 answerOrtho_LH_ZO = float4x4(
		0.112500f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, -0.200000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.009901f, 0.009901f,
		0.000000f, 0.000000f, 0.000000f, 1.000000f
	);
	float4x4 answerOrtho_LH_NO = float4x4(
		0.112500f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, -0.200000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 0.019802f, -0.980198f,
		0.000000f, 0.000000f, 0.000000f, 1.000000f
	);
	float4x4 answerOrtho_RH_ZO = float4x4(
		0.112500f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, -0.200000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, -0.009901f, 0.009901f,
		0.000000f, 0.000000f, 0.000000f, 1.000000f
	);
	float4x4 answerOrtho_RH_NO = float4x4(
		0.112500f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, -0.200000f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, -0.019802f, -0.980198f,
		0.000000f, 0.000000f, 0.000000f, 1.000000f
	);

	float width     = 1280.000000f;
	float height    = 720.000000f;
	float aspect    = width / height;
	float orthoSize = 5.000000f;

	float left   = -aspect * orthoSize;
	float right  =  aspect * orthoSize;
	float top    = -orthoSize;
	float bottom =  orthoSize;

	float4x4 mat_LH_ZO = ortho_lh_zo( left, right, top, bottom, -1.000000f, 100.000000f );
	float4x4 mat_LH_NO = ortho_lh_no( left, right, top, bottom, -1.000000f, 100.000000f );
	float4x4 mat_RH_ZO = ortho_rh_zo( left, right, top, bottom, -1.000000f, 100.000000f );
	float4x4 mat_RH_NO = ortho_rh_no( left, right, top, bottom, -1.000000f, 100.000000f );

	TEMPER_EXPECT_TRUE( mat_LH_ZO == answerOrtho_LH_ZO );
	TEMPER_EXPECT_TRUE( mat_LH_NO == answerOrtho_LH_NO );
	TEMPER_EXPECT_TRUE( mat_RH_ZO == answerOrtho_RH_ZO );
	TEMPER_EXPECT_TRUE( mat_RH_NO == answerOrtho_RH_NO );

	TEMPER_PASS();
}

TEMPER_TEST( TestPerspective_float4x4 )
{
	float4x4 answerPerspective_LH_ZO = float4x4(
		0.347270f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.617370f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 1.001001f, -0.100100f,
		0.000000f, 0.000000f, 1.000000f, 0.000000f
	);
	float4x4 answerPerspective_LH_NO = float4x4(
		0.347270f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.617370f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, 1.002002f, -0.200200f,
		0.000000f, 0.000000f, 1.000000f, 0.000000f
	);
	float4x4 answerPerspective_RH_ZO = float4x4(
		0.347270f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.617370f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, -1.001001f, -0.100100f,
		0.000000f, 0.000000f, -1.000000f, 0.000000f
	);
	float4x4 answerPerspective_RH_NO = float4x4(
		0.347270f, 0.000000f, 0.000000f, 0.000000f,
		0.000000f, 0.617370f, 0.000000f, 0.000000f,
		0.000000f, 0.000000f, -1.002002f, -0.200200f,
		0.000000f, 0.000000f, -1.000000f, 0.000000f
	);

	float aspect = 1280.000000f / 720.000000f;
	float4x4 mat_LH_ZO = perspective_lh_zo( 90.000000f, aspect, 0.100000f, 100.000000f );
	float4x4 mat_LH_NO = perspective_lh_no( 90.000000f, aspect, 0.100000f, 100.000000f );
	float4x4 mat_RH_ZO = perspective_rh_zo( 90.000000f, aspect, 0.100000f, 100.000000f );
	float4x4 mat_RH_NO = perspective_rh_no( 90.000000f, aspect, 0.100000f, 100.000000f );

	TEMPER_EXPECT_TRUE( mat_LH_ZO == answerPerspective_LH_ZO );
	TEMPER_EXPECT_TRUE( mat_LH_NO == answerPerspective_LH_NO );
	TEMPER_EXPECT_TRUE( mat_RH_ZO == answerPerspective_RH_ZO );
	TEMPER_EXPECT_TRUE( mat_RH_NO == answerPerspective_RH_NO );

	TEMPER_PASS();
}

TEMPER_TEST( TestLookAt_float4x4 )
{
	float4x4 answerLookAt_LH = float4x4(
		0.707107f, 0.000000f, -0.707107f, 0.000000f,
		0.000000f, 1.000000f, 0.000000f, 0.000000f,
		0.707107f, 0.000000f, 0.707107f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 1.000000f
	);
	float4x4 answerLookAt_RH = float4x4(
		-0.707107f, 0.000000f, 0.707107f, 0.000000f,
		0.000000f, 1.000000f, 0.000000f, 0.000000f,
		-0.707107f, 0.000000f, -0.707107f, 0.000000f,
		0.000000f, 0.000000f, 0.000000f, 1.000000f
	);

	float3 currentPos = float3( 0.000000f, 0.000000f, 0.000000f );
	float3 targetPos = float3( 1.000000f, 0.000000f, 1.000000f );
	float3 up = float3( 0.000000f, 1.000000f, 0.000000f );

	float4x4 mat_LH = lookat_lh( currentPos, targetPos, up );
	float4x4 mat_RH = lookat_rh( currentPos, targetPos, up );

	TEMPER_EXPECT_TRUE( mat_LH == answerLookAt_LH );
	TEMPER_EXPECT_TRUE( mat_RH == answerLookAt_RH );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_float4x4 )
{
	TEMPER_RUN_TEST( TestAssignment_float4x4 );
	TEMPER_RUN_TEST( TestArithmeticAddition_float4x4 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_float4x4 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_float4x4 );
	TEMPER_RUN_TEST( TestArithmeticDivision_float4x4 );
	TEMPER_RUN_TEST( TestMultiplyVector_float4x4 );
	TEMPER_RUN_TEST( TestIncrement_float4x4 );
	TEMPER_RUN_TEST( TestDecrement_float4x4 );
	TEMPER_RUN_TEST( TestRelational_float4x4 );
	TEMPER_RUN_TEST( TestArray_float4x4 );
	TEMPER_RUN_TEST( TestIdentity_float4x4 );
	TEMPER_RUN_TEST( TestTranspose_float4x4 );
	TEMPER_RUN_TEST( TestInverse_float4x4 );
	TEMPER_RUN_TEST( TestDeterminant_float4x4 );
	TEMPER_RUN_TEST( TestTranslate_float4x4 );
	TEMPER_RUN_TEST( TestRotate_float4x4 );
	TEMPER_RUN_TEST( TestScale_float4x4 );
	TEMPER_RUN_TEST( TestOrtho_float4x4 );
	TEMPER_RUN_TEST( TestPerspective_float4x4 );
	TEMPER_RUN_TEST( TestLookAt_float4x4 );
}
