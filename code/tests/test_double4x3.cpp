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

TEMPER_TEST( TestAssignment_double4x3 )
{
	double4x3 mat;

	// fill single value
	mat = double4x3( 999.0 );
	TEMPER_EXPECT_TRUE( mat[0] == double3( 999.000000, 0.000000, 0.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 0.000000, 999.000000, 0.000000 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double3( 0.000000, 0.000000, 999.000000 ) );
	TEMPER_EXPECT_TRUE( mat[3] == double3( 0.000000, 0.000000, 0.000000 ) );

	// row filling
	mat = double4x3(
		double3( 0.000000, 1.000000, 2.000000 ),
		double3( 4.000000, 5.000000, 6.000000 ),
		double3( 8.000000, 9.000000, 10.000000 ),
		double3( 12.000000, 13.000000, 14.000000 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == double3( 0.000000, 1.000000, 2.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 4.000000, 5.000000, 6.000000 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double3( 8.000000, 9.000000, 10.000000 ) );
	TEMPER_EXPECT_TRUE( mat[3] == double3( 12.000000, 13.000000, 14.000000 ) );

	// all values filled
	mat = double4x3(
		16.000000, 15.000000, 14.000000,
		12.000000, 11.000000, 10.000000,
		8.000000, 7.000000, 6.000000,
		4.000000, 3.000000, 2.000000
	);
	TEMPER_EXPECT_TRUE( mat[0] == double3( 16.000000, 15.000000, 14.000000 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 12.000000, 11.000000, 10.000000 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double3( 8.000000, 7.000000, 6.000000 ) );
	TEMPER_EXPECT_TRUE( mat[3] == double3( 4.000000, 3.000000, 2.000000 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_double4x3 )
{
	double4x3 answer = double4x3(
		7.000000, 7.000000, 7.000000,
		8.000000, 8.000000, 8.000000,
		15.000000, 15.000000, 15.000000,
		24.000000, 24.000000, 24.000000
	);

	double4x3 a = double4x3(
		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000,
		18.000000, 18.000000, 18.000000
	);
	double4x3 b = double4x3(
		1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000,
		6.000000, 6.000000, 6.000000
	);
	double4x3 c = a + b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_double4x3 )
{
	double4x3 answer = double4x3(
		5.000000, 5.000000, 5.000000,
		4.000000, 4.000000, 4.000000,
		9.000000, 9.000000, 9.000000,
		12.000000, 12.000000, 12.000000
	);

	double4x3 a = double4x3(
		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000,
		18.000000, 18.000000, 18.000000
	);
	double4x3 b = double4x3(
		1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000,
		6.000000, 6.000000, 6.000000
	);
	double4x3 c = a - b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_double4x3 )
{
	double4x4 answer = double4x4(
		36.000000, 36.000000, 36.000000, 36.000000,
		36.000000, 36.000000, 36.000000, 36.000000,
		72.000000, 72.000000, 72.000000, 72.000000,
		108.000000, 108.000000, 108.000000, 108.000000
	);

	double4x3 a = double4x3(
		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000,
		18.000000, 18.000000, 18.000000
	);
	double3x4 b = double3x4(
		1.000000, 1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000, 3.000000
	);
	double4x4 c = a * b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_double4x3 )
{
	double4x3 answer = double4x3(
		6.000000, 6.000000, 6.000000,
		3.000000, 3.000000, 3.000000,
		4.000000, 4.000000, 4.000000,
		3.000000, 3.000000, 3.000000
	);

	double4x3 a = double4x3(
		6.000000, 6.000000, 6.000000,
		6.000000, 6.000000, 6.000000,
		12.000000, 12.000000, 12.000000,
		18.000000, 18.000000, 18.000000
	);
	double4x3 b = double4x3(
		1.000000, 1.000000, 1.000000,
		2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000,
		6.000000, 6.000000, 6.000000
	);
	double4x3 c = a / b;

	TEMPER_EXPECT_TRUE( c == answer );

	TEMPER_PASS();
}

TEMPER_TEST( TestIncrement_double4x3 )
{
	double4x3 mat;

	// prefix
	mat = double4x3(
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000
	);
	++mat;
	TEMPER_EXPECT_TRUE( mat == double4x3(
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000
	) );

	// postfix
	mat = double4x3(
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000
	);
	mat++;
	TEMPER_EXPECT_TRUE( mat == double4x3(
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestDecrement_double4x3 )
{
	double4x3 mat;

	// prefix
	mat = double4x3(
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000
	);
	--mat;
	TEMPER_EXPECT_TRUE( mat == double4x3(
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000
	) );

	// postfix
	mat = double4x3(
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000
	);
	mat--;
	TEMPER_EXPECT_TRUE( mat == double4x3(
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000,
		0.000000, 0.000000, 0.000000
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_double4x3 )
{
	bool4x3 allTrue = bool4x3(
		true, true, true,
		true, true, true,
		true, true, true,
		true, true, true
	);

	double4x3 mat0 = double4x3(
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000,
		1.000000, 1.000000, 1.000000
	);
	double4x3 mat1 = double4x3(
		2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000
	);
	double4x3 mat2 = double4x3(
		3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000
	);
	double4x3 mat3 = double4x3(
		4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000,
		4.000000, 4.000000, 4.000000
	);

	bool4x3 test0  = mat0 <= mat0;
	bool4x3 test1  = mat0 >= mat0;
	bool4x3 test2  = mat0 <  mat1;
	bool4x3 test3  = mat0 <  mat2;
	bool4x3 test4  = mat0 <  mat3;

	bool4x3 test5  = mat1 >  mat0;
	bool4x3 test6  = mat1 <= mat1;
	bool4x3 test7  = mat1 >= mat1;
	bool4x3 test8  = mat1 <  mat2;
	bool4x3 test9  = mat1 <  mat3;

	bool4x3 test10 = mat2 >  mat0;
	bool4x3 test11 = mat2 >  mat1;
	bool4x3 test12 = mat2 <= mat2;
	bool4x3 test13 = mat2 >= mat2;
	bool4x3 test14 = mat2 <  mat3;

	bool4x3 test15 = mat3 >  mat0;
	bool4x3 test16 = mat3 >  mat1;
	bool4x3 test17 = mat3 >  mat2;
	bool4x3 test18 = mat3 <= mat3;
	bool4x3 test19 = mat3 >= mat3;

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

TEMPER_TEST( TestArray_double4x3 )
{
	double4x3 mat;

	TEMPER_EXPECT_TRUE( mat[0] == double3( 1.0, 0.0, 0.0 ) );
	TEMPER_EXPECT_TRUE( mat[1] == double3( 0.0, 1.0, 0.0 ) );
	TEMPER_EXPECT_TRUE( mat[2] == double3( 0.0, 0.0, 1.0 ) );
	TEMPER_EXPECT_TRUE( mat[3] == double3( 0.0, 0.0, 0.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_double4x3 )
{
	double4x3 id = double4x3(
		1.000000, 0.0, 0.0,
		0.0, 1.000000, 0.0,
		0.0, 0.0, 1.000000,
		0.0, 0.0, 0.0
	);

	double4x3 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_double4x3 )
{
	double4x3 mat = double4x3(
		0.000000, 1.000000, 2.000000,
		4.000000, 5.000000, 6.000000,
		8.000000, 9.000000, 10.000000,
		12.000000, 13.000000, 14.000000
	);
	double3x4 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == double3x4(
		0.000000, 4.000000, 8.000000, 12.000000,
		1.000000, 5.000000, 9.000000, 13.000000,
		2.000000, 6.000000, 10.000000, 14.000000
	) );

	TEMPER_PASS();
}

TEMPER_TEST( TestCompMulDiv_double4x3 )
{
	double4x3 answer_mul = double4x3(
		8.000000, 8.000000, 8.000000,
		32.000000, 32.000000, 32.000000,
		192.000000, 192.000000, 192.000000,
		300.000000, 300.000000, 300.000000
	);
	double4x3 answer_div = double4x3(
		2.000000, 2.000000, 2.000000,
		2.000000, 2.000000, 2.000000,
		3.000000, 3.000000, 3.000000,
		3.000000, 3.000000, 3.000000
	);

	double4x3 a = double4x3(
		4.000000, 4.000000, 4.000000,
		8.000000, 8.000000, 8.000000,
		24.000000, 24.000000, 24.000000,
		30.000000, 30.000000, 30.000000
	);
	double4x3 b = double4x3(
		2.000000, 2.000000, 2.000000,
		4.000000, 4.000000, 4.000000,
		8.000000, 8.000000, 8.000000,
		10.000000, 10.000000, 10.000000
	);

	TEMPER_EXPECT_TRUE( comp_mul( a, b ) == answer_mul );
	TEMPER_EXPECT_TRUE( comp_div( a, b ) == answer_div );

	TEMPER_PASS();
}

TEMPER_TEST( TestScale_double4x3 )
{
	double4x3 mat;
	double4x3 scaled = scale( mat, double3( 2.000000, 2.000000, 2.000000 ) );

	TEMPER_EXPECT_TRUE( scaled == double4x3(
		2.000000, 0.0, 0.0,
		0.0, 2.000000, 0.0,
		0.0, 0.0, 2.000000,
		0.0, 0.0, 0.0
	) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_double4x3 )
{
	TEMPER_RUN_TEST( TestAssignment_double4x3 );
	TEMPER_RUN_TEST( TestArithmeticAddition_double4x3 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_double4x3 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_double4x3 );
	TEMPER_RUN_TEST( TestArithmeticDivision_double4x3 );
	TEMPER_RUN_TEST( TestIncrement_double4x3 );
	TEMPER_RUN_TEST( TestDecrement_double4x3 );
	TEMPER_RUN_TEST( TestRelational_double4x3 );
	TEMPER_RUN_TEST( TestArray_double4x3 );
	TEMPER_RUN_TEST( TestIdentity_double4x3 );
	TEMPER_RUN_TEST( TestTranspose_double4x3 );
	TEMPER_RUN_TEST( TestCompMulDiv_double4x3 );
	TEMPER_RUN_TEST( TestScale_double4x3 );
}
