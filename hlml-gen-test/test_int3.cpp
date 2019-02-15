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

#include "../out/gen/int3.h"

#include <temper.h>

// also tests equality operators
TEMPER_TEST( TestAssignment_int3 ) {
	int3 a;

	a = int3( 1 );
	TEMPER_EXPECT_TRUE( a == int3( 1 ) );
	TEMPER_EXPECT_TRUE( a != int3( 0, 1, 2 ) );

	a = int3( 0, 1, 2 );
	TEMPER_EXPECT_TRUE( a == int3( 0, 1, 2 ) );
	TEMPER_EXPECT_TRUE( a != int3( 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_int3 ) {
	int3 a = int3( 1 );
	int3 b = int3( 1, 2, 3 );
	int3 c = a + b;

	TEMPER_EXPECT_TRUE( c == int3( 2, 3, 4 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_int3 ) {
	int3 a = int3( 1 );
	int3 b = int3( 1, 2, 3 );
	int3 c = a - b;

	TEMPER_EXPECT_TRUE( c == int3( 0, -1, -2 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_int3 ) {
	int3 a = int3( 1 );
	int3 b = int3( 1, 2, 3 );
	int3 c = a * b;

	TEMPER_EXPECT_TRUE( c == int3( 1, 2, 3 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_int3 ) {
	int3 a = int3( 1 );
	int3 b = int3( 1, 2, 3 );
	int3 c = a / b;

	TEMPER_EXPECT_TRUE( c == int3( 1, 0, 0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_int3 ) {
	int3 a = int3( 0, 1, 2 );

	TEMPER_EXPECT_TRUE( a[0] == 0 );
	TEMPER_EXPECT_TRUE( a[1] == 1 );
	TEMPER_EXPECT_TRUE( a[2] == 2 );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_int3 ) {
	int3 vec0 = int3( 0, 0, 0 );
	int3 vec1 = int3( 1, 1, 1 );
	int3 vec2 = int3( 2, 2, 2 );

	bool3 test0 = vec0 <= vec0;
	bool3 test1 = vec0 >= vec0;
	bool3 test2 = vec0 < vec1;

	bool3 test3 = vec1 <= vec1;
	bool3 test4 = vec1 >= vec1;
	bool3 test5 = vec1 < vec2;
	bool3 test6 = vec1 > vec0;

	bool3 test7 = vec2 <= vec2;
	bool3 test8 = vec2 >= vec2;
	bool3 test9 = vec2 > vec1;

	TEMPER_EXPECT_TRUE( test0 == bool3( true ) );
	TEMPER_EXPECT_TRUE( test1 == bool3( true ) );
	TEMPER_EXPECT_TRUE( test2 == bool3( true ) );
	TEMPER_EXPECT_TRUE( test3 == bool3( true ) );
	TEMPER_EXPECT_TRUE( test4 == bool3( true ) );
	TEMPER_EXPECT_TRUE( test5 == bool3( true ) );
	TEMPER_EXPECT_TRUE( test6 == bool3( true ) );
	TEMPER_EXPECT_TRUE( test7 == bool3( true ) );
	TEMPER_EXPECT_TRUE( test8 == bool3( true ) );
	TEMPER_EXPECT_TRUE( test9 == bool3( true ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestLength_int3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestNormalized_int3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestDot_int3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestCross_int3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestAngle_int3 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_int3 ) {
	TEMPER_RUN_TEST( TestAssignment_int3 );
	TEMPER_RUN_TEST( TestArray_int3 );

	TEMPER_RUN_TEST( TestArithmeticAddition_int3 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_int3 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_int3 );
	TEMPER_RUN_TEST( TestArithmeticDivision_int3 );

	TEMPER_RUN_TEST( TestRelational_int3 );

	TEMPER_SKIP_TEST( TestLength_int3, "TODO" );
	TEMPER_SKIP_TEST( TestNormalized_int3, "TODO" );
	TEMPER_SKIP_TEST( TestDot_int3, "TODO" );
	TEMPER_SKIP_TEST( TestCross_int3, "TODO" );
	TEMPER_SKIP_TEST( TestAngle_int3, "TODO" );
};
