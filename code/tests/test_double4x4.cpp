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

TEMPER_TEST( TestAssignment_double4x4 )
{
	double4x4 mat;

	// fill single value
	mat = double4x4( 999.000000 );
	TEMPER_EXPECT_TRUE( mat[0] == double4( 999.000000, 0.000000, 0.000000, 0.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double4( 0.000000, 999.000000, 0.000000, 0.000000 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double4( 0.000000, 0.000000, 999.000000, 0.000000 ) );
	TEMPER_EXPECT_TRUE( mat[3] == double4( 0.000000, 0.000000, 0.000000, 999.000000 ) );

	// row filling
	mat = double4x4(
		double4( 0.000000, 1.000000, 2.000000, 3.000000 ),
		double4( 4.000000, 5.000000, 6.000000, 7.000000 ),
		double4( 8.000000, 9.000000, 10.000000, 11.000000 ),
		double4( 12.000000, 13.000000, 14.000000, 15.000000 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == double4( 0.000000, 1.000000, 2.000000, 3.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double4( 4.000000, 5.000000, 6.000000, 7.000000 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double4( 8.000000, 9.000000, 10.000000, 11.000000 ) );
	TEMPER_EXPECT_TRUE( mat[3] == double4( 12.000000, 13.000000, 14.000000, 15.000000 ) );

	// all values filled
	mat = double4x4(
		16.000000, 15.000000, 14.000000, 13.000000,
		12.000000, 11.000000, 10.000000, 9.000000,
		8.000000, 7.000000, 6.000000, 5.000000,
		4.000000, 3.000000, 2.000000, 1.000000
	);
	TEMPER_EXPECT_TRUE( mat[0] == double4( 16.000000, 15.000000, 14.000000, 13.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double4( 12.000000, 11.000000, 10.000000, 9.000000 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double4( 8.000000, 7.000000, 6.000000, 5.000000 ) );
	TEMPER_EXPECT_TRUE( mat[3] == double4( 4.000000, 3.000000, 2.000000, 1.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_double4x4 )
{
	double4x4 answer = double4x4(
		7.000000, 7.000000, 7.000000, 7.000000,
		8.000000, 8.000000, 8.000000, 8.000000,
		15.000000, 15.000000, 15.000000, 15.000000,
		24.000000, 24.000000, 24.000000, 24.000000
	);

	double4x4 a = double4x4(
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000,
		18.000000, 18.000000, 18.000000, 18.000000
	);
	double4x4 b = double4x4(
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		6.000000, 6.000000, 6.000000, 6.000000
	);
	double4x4 c = a + b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_double4x4 )
{
	double4x4 answer = double4x4(
		5.000000, 5.000000, 5.000000, 5.000000,
		4.000000, 4.000000, 4.000000, 4.000000,
		9.000000, 9.000000, 9.000000, 9.000000,
		12.000000, 12.000000, 12.000000, 12.000000
	);

	double4x4 a = double4x4(
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000,
		18.000000, 18.000000, 18.000000, 18.000000
	);
	double4x4 b = double4x4(
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		6.000000, 6.000000, 6.000000, 6.000000
	);
	double4x4 c = a - b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_double4x4 )
{
	double4x4 answer = double4x4(
		72.000000, 72.000000, 72.000000, 72.000000,
		72.000000, 72.000000, 72.000000, 72.000000,
		144.000000, 144.000000, 144.000000, 144.000000,
		216.000000, 216.000000, 216.000000, 216.000000
	);

	double4x4 a = double4x4(
		6.000000, 6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000, 12.000000,
		18.000000, 18.000000, 18.000000, 18.000000
	);
	double4x4 b = double4x4(
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		6.000000, 6.000000, 6.000000, 6.000000
	);
	double4x4 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_double4x4 )
{
	double4x4 answer = double4x4(
		1.000000, 0.0, 0.0, 0.0,
		0.0, 1.000000, 0.0, 0.0,
		0.0, 0.0, 1.000000, 0.0,
		0.0, 0.0, 0.0, 1.000000
	);

	double4x4 a = double4x4(
		6.000000, 2.000000, 3.000000, 4.000000,
		2.000000, 7.000000, 5.000000, 3.000000,
		3.000000, 5.000000, 7.000000, 2.000000,
		4.000000, 3.000000, 2.000000, 6.000000
	);
	double4x4 b = double4x4(
		6.000000, 2.000000, 3.000000, 4.000000,
		2.000000, 7.000000, 5.000000, 3.000000,
		3.000000, 5.000000, 7.000000, 2.000000,
		4.000000, 3.000000, 2.000000, 6.000000
	);
	double4x4 c = a / b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyVector_double4x4 )
{
	double4 answerVec = double4( 28.000000, 68.000000, 108.000000, 148.000000 );

	double4x4 a = double4x4(
		1.000000, 2.000000, 3.000000, 4.000000,
		5.000000, 6.000000, 7.000000, 8.000000,
		9.000000, 10.000000, 11.000000, 12.000000,
		13.000000, 14.000000, 15.000000, 16.000000
	);
	double4 b = double4( 2.000000, 1.000000, 4.000000, 3.000000 );
	double4 c = a * b;

	TEMPER_EXPECT_TRUE( c == answerVec );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_double4x4 )
{
	double4x4 mat;

	// prefix
	mat = double4x4(
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000
	);
	++mat;
	TEMPER_EXPECT_TRUE( mat == double4x4(
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000
	) );

	// postfix
	mat = double4x4(
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000
	);
	mat++;
	TEMPER_EXPECT_TRUE( mat == double4x4(
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_double4x4 )
{
	double4x4 mat;

	// prefix
	mat = double4x4(
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000
	);
	--mat;
	TEMPER_EXPECT_TRUE( mat == double4x4(
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000
	) );

	// postfix
	mat = double4x4(
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000
	);
	mat--;
	TEMPER_EXPECT_TRUE( mat == double4x4(
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 0.000000
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_double4x4 )
{
	bool4x4 allTrue = bool4x4(
		true, true, true, true,
		true, true, true, true,
		true, true, true, true,
		true, true, true, true
	);

	double4x4 mat0 = double4x4(
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000, 1.000000
	);
	double4x4 mat1 = double4x4(
		2.000000, 2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000, 2.000000
	);
	double4x4 mat2 = double4x4(
		3.000000, 3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000, 3.000000
	);
	double4x4 mat3 = double4x4(
		4.000000, 4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000, 4.000000
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

TEMPER_TEST( TestArray_double4x4 )
{
	double4x4 mat;

	TEMPER_EXPECT_TRUE( mat[0] == double4( 1.000000, 0.000000, 0.000000, 0.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double4( 0.000000, 1.000000, 0.000000, 0.000000 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double4( 0.000000, 0.000000, 1.000000, 0.000000 ) );
	TEMPER_EXPECT_TRUE( mat[3] == double4( 0.000000, 0.000000, 0.000000, 1.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_double4x4 )
{
	double4x4 id = double4x4(
		1.000000, 0.0, 0.0, 0.0,
		0.0, 1.000000, 0.0, 0.0,
		0.0, 0.0, 1.000000, 0.0,
		0.0, 0.0, 0.0, 1.000000
	);

	double4x4 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_double4x4 )
{
	double4x4 mat = double4x4(
		0.000000, 1.000000, 2.000000, 3.000000,
		4.000000, 5.000000, 6.000000, 7.000000,
		8.000000, 9.000000, 10.000000, 11.000000,
		12.000000, 13.000000, 14.000000, 15.000000
	);
	double4x4 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == double4x4(
		0.000000, 4.000000, 8.000000, 12.000000,
		1.000000, 5.000000, 9.000000, 13.000000,
		2.000000, 6.000000, 10.000000, 14.000000,
		3.000000, 7.000000, 11.000000, 15.000000
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestInverse_double4x4 )
{
	double4x4 identityMatrix;

	double4x4 mat = double4x4(
		6.000000, 2.000000, 3.000000, 4.000000,
		2.000000, 7.000000, 5.000000, 3.000000,
		3.000000, 5.000000, 7.000000, 2.000000,
		4.000000, 3.000000, 2.000000, 6.000000
	);
	double4x4 matInverse = inverse( mat );

	TEMPER_EXPECT_TRUE( mat * matInverse == identityMatrix );

	TEMPER_PASS();
}

TEMPER_TEST( TestCompMulDiv_double4x4 )
{
	double4x4 answer_mul = double4x4(
		8.000000, 8.000000, 8.000000, 8.000000,
		32.000000, 32.000000, 32.000000, 32.000000,
		192.000000, 192.000000, 192.000000, 192.000000,
		300.000000, 300.000000, 300.000000, 300.000000
	);
	double4x4 answer_div = double4x4(
		2.000000, 2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000, 3.000000
	);

	double4x4 a = double4x4(
		4.000000, 4.000000, 4.000000, 4.000000,
		8.000000, 8.000000, 8.000000, 8.000000,
		24.000000, 24.000000, 24.000000, 24.000000,
		30.000000, 30.000000, 30.000000, 30.000000
	);
	double4x4 b = double4x4(
		2.000000, 2.000000, 2.000000, 2.000000,
		4.000000, 4.000000, 4.000000, 4.000000,
		8.000000, 8.000000, 8.000000, 8.000000,
		10.000000, 10.000000, 10.000000, 10.000000
	);

	TEMPER_EXPECT_TRUE( comp_mul( a, b ) == answer_mul );
	TEMPER_EXPECT_TRUE( comp_div( a, b ) == answer_div );

	TEMPER_PASS();
}

TEMPER_TEST( TestDeterminant_double4x4 )
{
	double4x4 mat = double4x4(
		6.000000, 2.000000, 3.000000, 4.000000,
		2.000000, 7.000000, 5.000000, 3.000000,
		3.000000, 5.000000, 7.000000, 2.000000,
		4.000000, 3.000000, 2.000000, 6.000000
	);
	double det = determinant( mat );

	TEMPER_EXPECT_TRUE( doubleeq( det, 285.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranslate_double4x4 )
{
	double4x4 mat;
	double4x4 translated = double4x4(
		1.000000, 0.000000, 0.000000, 2.000000,
		0.000000, 1.000000, 0.000000, 3.000000,
		0.000000, 0.000000, 1.000000, 4.000000,
		0.000000, 0.000000, 0.000000, 1.000000
	);

	double3 translation = double3( 2.000000, 3.000000, 4.000000 );
	mat = translate( mat, translation );

	TEMPER_EXPECT_TRUE( mat == translated );

	TEMPER_PASS();
}

TEMPER_TEST( TestRotate_double4x4 )
{
	double4x4 mat;
	double4x4 yaw = rotate( mat, radians( 45.000000 ), double3( 0.000000, 1.000000, 0.000000 ) );
	double4x4 pitch = rotate( mat, radians( 45.000000 ), double3( 1.000000, 0.000000, 0.000000 ) );
	double4x4 roll = rotate( mat, radians( 45.000000 ), double3( 0.000000, 0.000000, 1.000000 ) );

	double4x4 answerYaw = double4x4(
		0.707107, 0.000000, 0.707107, 0.000000,
		0.000000, 1.000000, 0.000000, 0.000000,
		-0.707107, 0.000000, 0.707107, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
	);
	double4x4 answerPitch = double4x4(
		1.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 0.707107, -0.707107, 0.000000,
		0.000000, 0.707107, 0.707107, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
	);
	double4x4 answerRoll = double4x4(
		0.707107, -0.707107, 0.000000, 0.000000,
		0.707107, 0.707107, 0.000000, 0.000000,
		0.000000, 0.000000, 1.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
	);

	TEMPER_EXPECT_TRUE( yaw == answerYaw );
	TEMPER_EXPECT_TRUE( pitch == answerPitch );
	TEMPER_EXPECT_TRUE( roll == answerRoll );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_double4x4 )
{
	double4x4 mat;
	double4x4 scaled = scale( mat, double3( 2.000000, 2.000000, 2.000000 ) );

	TEMPER_EXPECT_TRUE( scaled == double4x4(
		2.000000, 0.0, 0.0, 0.0,
		0.0, 2.000000, 0.0, 0.0,
		0.0, 0.0, 2.000000, 0.0,
		0.0, 0.0, 0.0, 1.000000
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestOrtho_double4x4 )
{
	double4x4 answerOrtho_LH_ZO = double4x4(
		0.112500, 0.000000, 0.000000, 0.000000,
		0.000000, -0.200000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.009901, 0.009901,
		0.000000, 0.000000, 0.000000, 1.000000
	);
	double4x4 answerOrtho_LH_NO = double4x4(
		0.112500, 0.000000, 0.000000, -0.000000,
		0.000000, -0.200000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.019802, -0.980198,
		0.000000, 0.000000, 0.000000, 1.000000
	);
	double4x4 answerOrtho_RH_ZO = double4x4(
		0.112500, 0.000000, 0.000000, -0.000000,
		0.000000, -0.200000, 0.000000, 0.000000,
		0.000000, 0.000000, -0.009901, 0.009901,
		0.000000, 0.000000, 0.000000, 1.000000
	);
	double4x4 answerOrtho_RH_NO = double4x4(
		0.112500, 0.000000, 0.000000, -0.000000,
		0.000000, -0.200000, 0.000000, 0.000000,
		0.000000, 0.000000, -0.019802, -0.980198,
		0.000000, 0.000000, 0.000000, 1.000000
	);

	double width     = 1280.000000;
	double height    = 720.000000;
	double aspect    = width / height;
	double orthoSize = 5.000000;

	double left   = -aspect * orthoSize;
	double right  =  aspect * orthoSize;
	double top    = -orthoSize;
	double bottom =  orthoSize;

	double4x4 mat_LH_ZO = ortho_lh_zo( left, right, top, bottom, -1.000000, 100.000000 );
	double4x4 mat_LH_NO = ortho_lh_no( left, right, top, bottom, -1.000000, 100.000000 );
	double4x4 mat_RH_ZO = ortho_rh_zo( left, right, top, bottom, -1.000000, 100.000000 );
	double4x4 mat_RH_NO = ortho_rh_no( left, right, top, bottom, -1.000000, 100.000000 );

	TEMPER_EXPECT_TRUE( mat_LH_ZO == answerOrtho_LH_ZO );
	TEMPER_EXPECT_TRUE( mat_LH_NO == answerOrtho_LH_NO );
	TEMPER_EXPECT_TRUE( mat_RH_ZO == answerOrtho_RH_ZO );
	TEMPER_EXPECT_TRUE( mat_RH_NO == answerOrtho_RH_NO );

	TEMPER_PASS();
}

TEMPER_TEST( TestPerspective_double4x4 )
{
	double4x4 answerPerspective_LH_ZO = double4x4(
		0.347270, 0.000000, 0.000000, 0.000000,
		0.000000, 0.617370, 0.000000, 0.000000,
		0.000000, 0.000000, 1.001001, -0.100100,
		0.000000, 0.000000, 1.000000, 0.000000
	);
	double4x4 answerPerspective_LH_NO = double4x4(
		0.347270, 0.000000, 0.000000, 0.000000,
		0.000000, 0.617370, 0.000000, 0.000000,
		0.000000, 0.000000, 1.002002, -0.200200,
		0.000000, 0.000000, 1.000000, 0.000000
	);
	double4x4 answerPerspective_RH_ZO = double4x4(
		0.347270, 0.000000, 0.000000, 0.000000,
		0.000000, 0.617370, 0.000000, 0.000000,
		0.000000, 0.000000, -1.001001, -0.100100,
		0.000000, 0.000000, -1.000000, 0.000000
	);
	double4x4 answerPerspective_RH_NO = double4x4(
		0.347270, 0.000000, 0.000000, 0.000000,
		0.000000, 0.617370, 0.000000, 0.000000,
		0.000000, 0.000000, -1.002002, -0.200200,
		0.000000, 0.000000, -1.000000, 0.000000
	);

	double aspect = 1280.000000 / 720.000000;
	double4x4 mat_LH_ZO = perspective_lh_zo( 90.000000, aspect, 0.100000, 100.000000 );
	double4x4 mat_LH_NO = perspective_lh_no( 90.000000, aspect, 0.100000, 100.000000 );
	double4x4 mat_RH_ZO = perspective_rh_zo( 90.000000, aspect, 0.100000, 100.000000 );
	double4x4 mat_RH_NO = perspective_rh_no( 90.000000, aspect, 0.100000, 100.000000 );

	TEMPER_EXPECT_TRUE( mat_LH_ZO == answerPerspective_LH_ZO );
	TEMPER_EXPECT_TRUE( mat_LH_NO == answerPerspective_LH_NO );
	TEMPER_EXPECT_TRUE( mat_RH_ZO == answerPerspective_RH_ZO );
	TEMPER_EXPECT_TRUE( mat_RH_NO == answerPerspective_RH_NO );

	TEMPER_PASS();
}

TEMPER_TEST( TestLookAt_double4x4 )
{
	double4x4 answerLookAt_LH = double4x4(
		0.707107, 0.000000, -0.707107, 0.000000,
		0.000000, 1.000000, 0.000000, 0.000000,
		0.707107, 0.000000, 0.707107, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
	);
	double4x4 answerLookAt_RH = double4x4(
		-0.707107, 0.000000, 0.707107, 0.000000,
		0.000000, 1.000000, 0.000000, 0.000000,
		-0.707107, 0.000000, -0.707107, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
	);

	double3 currentPos = double3( 0.000000, 0.000000, 0.000000 );
	double3 targetPos = double3( 1.000000, 0.000000, 1.000000 );
	double3 up = double3( 0.000000, 1.000000, 0.000000 );

	double4x4 mat_LH = lookat_lh( currentPos, targetPos, up );
	double4x4 mat_RH = lookat_rh( currentPos, targetPos, up );

	TEMPER_EXPECT_TRUE( mat_LH == answerLookAt_LH );
	TEMPER_EXPECT_TRUE( mat_RH == answerLookAt_RH );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_double4x4 )
{
	TEMPER_RUN_TEST( TestAssignment_double4x4 );
	TEMPER_RUN_TEST( TestArithmeticAddition_double4x4 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_double4x4 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_double4x4 );
	TEMPER_RUN_TEST( TestArithmeticDivision_double4x4 );
	TEMPER_RUN_TEST( TestMultiplyVector_double4x4 );
	TEMPER_RUN_TEST( TestIncrement_double4x4 );
	TEMPER_RUN_TEST( TestDecrement_double4x4 );
	TEMPER_RUN_TEST( TestRelational_double4x4 );
	TEMPER_RUN_TEST( TestArray_double4x4 );
	TEMPER_RUN_TEST( TestIdentity_double4x4 );
	TEMPER_RUN_TEST( TestTranspose_double4x4 );
	TEMPER_RUN_TEST( TestInverse_double4x4 );
	TEMPER_RUN_TEST( TestCompMulDiv_double4x4 );
	TEMPER_RUN_TEST( TestDeterminant_double4x4 );
	TEMPER_RUN_TEST( TestTranslate_double4x4 );
	TEMPER_RUN_TEST( TestRotate_double4x4 );
	TEMPER_RUN_TEST( TestScale_double4x4 );
	TEMPER_RUN_TEST( TestOrtho_double4x4 );
	TEMPER_RUN_TEST( TestPerspective_double4x4 );
	TEMPER_RUN_TEST( TestLookAt_double4x4 );
}
