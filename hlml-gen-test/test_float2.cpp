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

#include "../out/gen/hlml_functions_vector.h"

#include <temper.h>

// also tests equality operators
TEMPER_TEST( TestAssignment_float2 ) {
	float2 a;

	a = float2( 1.0f );
	TEMPER_EXPECT_TRUE( a == float2( 1.0f ) );
	TEMPER_EXPECT_TRUE( a != float2( 0.0f, 1.0f ) );

	a = float2( 0.0f, 1.0f );
	TEMPER_EXPECT_TRUE( a == float2( 0.0f, 1.0f ) );
	TEMPER_EXPECT_TRUE( a != float2( 1.0f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_float2 ) {
	float2 a = float2( 2.0f );
	float2 b = float2( 2.0f, 3.0f );
	float2 c = a + b;

	TEMPER_EXPECT_TRUE( c == float2( 4.0f, 5.0f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_float2 ) {
	float2 a = float2( 2.0f );
	float2 b = float2( 2.0f, 3.0f );
	float2 c = a - b;

	TEMPER_EXPECT_TRUE( c == float2( 0.0f, -1.0f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_float2 ) {
	float2 a = float2( 2.0f );
	float2 b = float2( 2.0f, 3.0f );
	float2 c = a * b;

	TEMPER_EXPECT_TRUE( c == float2( 4.0f, 6.0f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_float2 ) {
	float2 a = float2( 2.0f );
	float2 b = float2( 2.0f, 3.0f );
	float2 c = a / b;

	TEMPER_EXPECT_TRUE( c == float2( 1.000000, 0.666667 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_float2 ) {
	float2 a = float2( 0.0f, 1.0f );

	TEMPER_EXPECT_TRUE( a[0] == 0.0f );
	TEMPER_EXPECT_TRUE( a[1] == 1.0f );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_float2 ) {
	float2 vec0 = float2( 0.0f, 0.0f );
	float2 vec1 = float2( 1.0f, 1.0f );

	bool2 test0 = vec0 <= vec0;
	bool2 test1 = vec0 >= vec0;
	bool2 test2 = vec0 < vec1;

	bool2 test3 = vec1 <= vec1;
	bool2 test4 = vec1 >= vec1;
	bool2 test5 = vec1 > vec0;

	TEMPER_EXPECT_TRUE( test0 == bool2( true ) );
	TEMPER_EXPECT_TRUE( test1 == bool2( true ) );
	TEMPER_EXPECT_TRUE( test2 == bool2( true ) );
	TEMPER_EXPECT_TRUE( test3 == bool2( true ) );
	TEMPER_EXPECT_TRUE( test4 == bool2( true ) );
	TEMPER_EXPECT_TRUE( test5 == bool2( true ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestLength_float2 ) {
	float2 vec = float2( 2.0f );

	TEMPER_EXPECT_TRUE( floateq( lengthsqr( vec ), 8.000000 ) );
	TEMPER_EXPECT_TRUE( floateq( length( vec ), 2.828427 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestNormalized_float2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestDot_float2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestCross_float2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestAngle_float2 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_float2 ) {
	TEMPER_RUN_TEST( TestAssignment_float2 );
	TEMPER_RUN_TEST( TestArray_float2 );

	TEMPER_RUN_TEST( TestArithmeticAddition_float2 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_float2 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_float2 );
	TEMPER_RUN_TEST( TestArithmeticDivision_float2 );

	TEMPER_RUN_TEST( TestRelational_float2 );

	TEMPER_RUN_TEST( TestLength_float2 );
	TEMPER_SKIP_TEST( TestNormalized_float2, "TODO" );
	TEMPER_SKIP_TEST( TestDot_float2, "TODO" );
	TEMPER_SKIP_TEST( TestCross_float2, "TODO" );
	TEMPER_SKIP_TEST( TestAngle_float2, "TODO" );
};
