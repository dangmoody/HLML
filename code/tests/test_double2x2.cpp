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

TEMPER_TEST( TestAssignment_double2x2 )
{
	double2x2 mat;

	// fill single value
	mat = double2x2( 999.000000 );
	TEMPER_EXPECT_TRUE( mat[0] == double2( 999.000000, 0.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double2( 0.000000, 999.000000 ) );

	// row filling
	mat = double2x2(
		double2( 0.000000, 1.000000 ),
		double2( 4.000000, 5.000000 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == double2( 0.000000, 1.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double2( 4.000000, 5.000000 ) );

	// all values filled
	mat = double2x2(
		16.000000, 15.000000,
		12.000000, 11.000000
	);
	TEMPER_EXPECT_TRUE( mat[0] == double2( 16.000000, 15.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double2( 12.000000, 11.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_double2x2 )
{
	double2x2 answer = double2x2(
		7.000000, 7.000000,
		8.000000, 8.000000
	);

	double2x2 a = double2x2(
		6.000000, 6.000000,
		6.000000, 6.000000
	);
	double2x2 b = double2x2(
		1.000000, 1.000000,
		2.000000, 2.000000
	);
	double2x2 c = a + b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_double2x2 )
{
	double2x2 answer = double2x2(
		5.000000, 5.000000,
		4.000000, 4.000000
	);

	double2x2 a = double2x2(
		6.000000, 6.000000,
		6.000000, 6.000000
	);
	double2x2 b = double2x2(
		1.000000, 1.000000,
		2.000000, 2.000000
	);
	double2x2 c = a - b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_double2x2 )
{
	double2x2 answer = double2x2(
		18.000000, 18.000000,
		18.000000, 18.000000
	);

	double2x2 a = double2x2(
		6.000000, 6.000000,
		6.000000, 6.000000
	);
	double2x2 b = double2x2(
		1.000000, 1.000000,
		2.000000, 2.000000
	);
	double2x2 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_double2x2 )
{
	double2x2 answer = double2x2(
		1.000000, 0.0,
		0.0, 1.000000
	);

	double2x2 a = double2x2(
		6.000000, 2.000000,
		2.000000, 7.000000
	);
	double2x2 b = double2x2(
		6.000000, 2.000000,
		2.000000, 7.000000
	);
	double2x2 c = a / b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestMultiplyVector_double2x2 )
{
	double2 answerVec = double2( 4.000000, 16.000000 );

	double2x2 a = double2x2(
		1.000000, 2.000000,
		5.000000, 6.000000
	);
	double2 b = double2( 2.000000, 1.000000 );
	double2 c = a * b;

	TEMPER_EXPECT_TRUE( c == answerVec );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_double2x2 )
{
	double2x2 mat;

	// prefix
	mat = double2x2(
		0.000000, 0.000000,
		0.000000, 0.000000
	);
	++mat;
	TEMPER_EXPECT_TRUE( mat == double2x2(
		1.000000, 1.000000,
		1.000000, 1.000000
	) );

	// postfix
	mat = double2x2(
		0.000000, 0.000000,
		0.000000, 0.000000
	);
	mat++;
	TEMPER_EXPECT_TRUE( mat == double2x2(
		1.000000, 1.000000,
		1.000000, 1.000000
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_double2x2 )
{
	double2x2 mat;

	// prefix
	mat = double2x2(
		1.000000, 1.000000,
		1.000000, 1.000000
	);
	--mat;
	TEMPER_EXPECT_TRUE( mat == double2x2(
		0.000000, 0.000000,
		0.000000, 0.000000
	) );

	// postfix
	mat = double2x2(
		1.000000, 1.000000,
		1.000000, 1.000000
	);
	mat--;
	TEMPER_EXPECT_TRUE( mat == double2x2(
		0.000000, 0.000000,
		0.000000, 0.000000
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_double2x2 )
{
	bool2x2 allTrue = bool2x2(
		true, true,
		true, true
	);

	double2x2 mat0 = double2x2(
		1.000000, 1.000000,
		1.000000, 1.000000
	);
	double2x2 mat1 = double2x2(
		2.000000, 2.000000,
		2.000000, 2.000000
	);
	double2x2 mat2 = double2x2(
		3.000000, 3.000000,
		3.000000, 3.000000
	);
	double2x2 mat3 = double2x2(
		4.000000, 4.000000,
		4.000000, 4.000000
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

TEMPER_TEST( TestArray_double2x2 )
{
	double2x2 mat;

	TEMPER_EXPECT_TRUE( mat[0] == double2( 1.000000, 0.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double2( 0.000000, 1.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_double2x2 )
{
	double2x2 id = double2x2(
		1.000000, 0.0,
		0.0, 1.000000
	);

	double2x2 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_double2x2 )
{
	double2x2 mat = double2x2(
		0.000000, 1.000000,
		4.000000, 5.000000
	);
	double2x2 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == double2x2(
		0.000000, 4.000000,
		1.000000, 5.000000
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestInverse_double2x2 )
{
	double2x2 identityMatrix;

	double2x2 mat = double2x2(
		6.000000, 2.000000,
		2.000000, 6.000000
	);
	double2x2 matInverse = inverse( mat );

	TEMPER_EXPECT_TRUE( mat * matInverse == identityMatrix );

	TEMPER_PASS();
}

TEMPER_TEST( TestCompMulDiv_double2x2 )
{
	double2x2 answer_mul = double2x2(
		8.000000, 8.000000,
		32.000000, 32.000000
	);
	double2x2 answer_div = double2x2(
		2.000000, 2.000000,
		2.000000, 2.000000
	);

	double2x2 a = double2x2(
		4.000000, 4.000000,
		8.000000, 8.000000
	);
	double2x2 b = double2x2(
		2.000000, 2.000000,
		4.000000, 4.000000
	);

	TEMPER_EXPECT_TRUE( comp_mul( a, b ) == answer_mul );
	TEMPER_EXPECT_TRUE( comp_div( a, b ) == answer_div );

	TEMPER_PASS();
}

TEMPER_TEST( TestDeterminant_double2x2 )
{
	double2x2 mat = double2x2(
		6.000000, 2.000000,
		2.000000, 6.000000
	);
	double det = determinant( mat );

	TEMPER_EXPECT_TRUE( doubleeq( det, 32.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_double2x2 )
{
	double2x2 mat;
	double2x2 scaled = scale( mat, double3( 2.000000, 2.000000, 2.000000 ) );

	TEMPER_EXPECT_TRUE( scaled == double2x2(
		2.000000, 0.0,
		0.0, 2.000000
	) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_double2x2 )
{
	TEMPER_RUN_TEST( TestAssignment_double2x2 );
	TEMPER_RUN_TEST( TestArithmeticAddition_double2x2 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_double2x2 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_double2x2 );
	TEMPER_RUN_TEST( TestArithmeticDivision_double2x2 );
	TEMPER_RUN_TEST( TestMultiplyVector_double2x2 );
	TEMPER_RUN_TEST( TestIncrement_double2x2 );
	TEMPER_RUN_TEST( TestDecrement_double2x2 );
	TEMPER_RUN_TEST( TestRelational_double2x2 );
	TEMPER_RUN_TEST( TestArray_double2x2 );
	TEMPER_RUN_TEST( TestIdentity_double2x2 );
	TEMPER_RUN_TEST( TestTranspose_double2x2 );
	TEMPER_RUN_TEST( TestInverse_double2x2 );
	TEMPER_RUN_TEST( TestCompMulDiv_double2x2 );
	TEMPER_RUN_TEST( TestDeterminant_double2x2 );
	TEMPER_RUN_TEST( TestScale_double2x2 );
}
