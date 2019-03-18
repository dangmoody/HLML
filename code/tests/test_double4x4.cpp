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
		double4( 0, 1, 2, 3 ),
		double4( 4, 5, 6, 7 ),
		double4( 8, 9, 10, 11 ),
		double4( 12, 13, 14, 15 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == double4( 0, 1, 2, 3 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double4( 4, 5, 6, 7 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double4( 8, 9, 10, 11 ) );
	TEMPER_EXPECT_TRUE( mat[3] == double4( 12, 13, 14, 15 ) );

	// all values filled
	mat = double4x4(
		16, 15, 14, 13, 
		12, 11, 10, 9, 
		8, 7, 6, 5, 
		4, 3, 2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == double4( 16, 15, 14, 13 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double4( 12, 11, 10, 9 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double4( 8, 7, 6, 5 ) );
	TEMPER_EXPECT_TRUE( mat[3] == double4( 4, 3, 2, 1 ) );

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
		1.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 1.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 1.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
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
		1.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 1.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 1.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
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
		2.000000, 0.000000, 0.000000, 0.000000,
		0.000000, 2.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 2.000000, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestOrtho_double4x4 )
{
	double4x4 answerOrtho = double4x4(
		0.112500, 0.000000, 0.000000, 0.000000,
		0.000000, -0.200000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.009901, 0.009901,
		0.000000, 0.000000, 0.000000, 1.000000
	);

	double width = 1280.000000;
	double height = 720.000000;
	double aspect = width / height;
	double orthoSize = 5.000000;

	double left = -aspect * orthoSize;
	double right = aspect * orthoSize;
	double top = -orthoSize;
	double bottom = orthoSize;

	double4x4 mat = ortho( left, right, top, bottom, -1.000000, 100.000000 );

	TEMPER_EXPECT_TRUE( mat == answerOrtho );

	TEMPER_PASS();
}

TEMPER_TEST( TestPerspective_double4x4 )
{
	double4x4 answerPerspective = double4x4(
		0.347270, 0.000000, 0.000000, 0.000000,
		0.000000, 0.617370, 0.000000, 0.000000,
		0.000000, 0.000000, 1.001001, -0.100100,
		0.000000, 0.000000, 1.000000, 0.000000
	);

	double aspect = 1280.000000 / 720.000000;
	double4x4 mat = perspective( 90.000000, aspect, 0.100000, 100.000000 );

	TEMPER_EXPECT_TRUE( mat == answerPerspective );

	TEMPER_PASS();
}

TEMPER_TEST( TestLookAt_double4x4 )
{
	double4x4 answerLookAt = double4x4(
		0.707107, 0.000000, -0.707107, 0.000000,
		0.000000, 1.000000, 0.000000, 0.000000,
		0.707107, 0.000000, 0.707107, 0.000000,
		0.000000, 0.000000, 0.000000, 1.000000
	);

	double3 currentPos = double3( 0.000000, 0.000000, 0.000000 );
	double3 targetPos = double3( 1.000000, 0.000000, 1.000000 );
	double3 up = double3( 0.000000, 1.000000, 0.000000 );
	double4x4 mat = lookat( currentPos, targetPos, up );

	TEMPER_EXPECT_TRUE( mat == answerLookAt );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_double4x4 )
{
	TEMPER_RUN_TEST( TestAssignment_double4x4 );

	TEMPER_RUN_TEST( TestArithmeticAddition_double4x4 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_double4x4 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_double4x4 );
	TEMPER_RUN_TEST( TestArithmeticDivision_double4x4 );

	TEMPER_RUN_TEST( TestIncrement_double4x4 );
	TEMPER_RUN_TEST( TestDecrement_double4x4 );

	TEMPER_RUN_TEST( TestRelational_double4x4 );

	TEMPER_RUN_TEST( TestArray_double4x4 );

	TEMPER_RUN_TEST( TestIdentity_double4x4 );
	TEMPER_RUN_TEST( TestTranspose_double4x4 );
	TEMPER_RUN_TEST( TestDeterminant_double4x4 );
	TEMPER_RUN_TEST( TestInverse_double4x4 );

	TEMPER_RUN_TEST( TestTranslate_double4x4 );
	TEMPER_RUN_TEST( TestRotate_double4x4 );
	TEMPER_RUN_TEST( TestScale_double4x4 );

	TEMPER_RUN_TEST( TestOrtho_double4x4 );
	TEMPER_RUN_TEST( TestPerspective_double4x4 );
	TEMPER_RUN_TEST( TestLookAt_double4x4 );
};
