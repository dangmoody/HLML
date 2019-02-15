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

#include "../out/gen/int2.h"

#include <temper.h>

// also tests equality operators
TEMPER_TEST( TestAssignment_int2 ) {
	int2 a;

	a = int2( 1 );
	TEMPER_EXPECT_TRUE( a == int2( 1 ) );
	TEMPER_EXPECT_TRUE( a != int2( 0, 1 ) );

	a = int2( 0, 1 );
	TEMPER_EXPECT_TRUE( a == int2( 0, 1 ) );
	TEMPER_EXPECT_TRUE( a != int2( 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_int2 ) {
	int2 a = int2( 2 );
	int2 b = int2( 2, 3 );
	int2 c = a + b;

	TEMPER_EXPECT_TRUE( c == int2( 4, 5 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_int2 ) {
	int2 a = int2( 2 );
	int2 b = int2( 2, 3 );
	int2 c = a - b;

	TEMPER_EXPECT_TRUE( c == int2( 0, -1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_int2 ) {
	int2 a = int2( 2 );
	int2 b = int2( 2, 3 );
	int2 c = a * b;

	TEMPER_EXPECT_TRUE( c == int2( 4, 6 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_int2 ) {
	int2 a = int2( 2 );
	int2 b = int2( 2, 3 );
	int2 c = a / b;

	TEMPER_EXPECT_TRUE( c == int2( 1, 0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_int2 ) {
	int2 a = int2( 0, 1 );

	TEMPER_EXPECT_TRUE( a[0] == 0 );
	TEMPER_EXPECT_TRUE( a[1] == 1 );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_int2 ) {
	int2 vec0 = int2( 0, 0 );
	int2 vec1 = int2( 1, 1 );

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

TEMPER_TEST( TestLength_int2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestNormalized_int2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestDot_int2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestCross_int2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestAngle_int2 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_int2 ) {
	TEMPER_RUN_TEST( TestAssignment_int2 );
	TEMPER_RUN_TEST( TestArray_int2 );

	TEMPER_RUN_TEST( TestArithmeticAddition_int2 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_int2 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_int2 );
	TEMPER_RUN_TEST( TestArithmeticDivision_int2 );

	TEMPER_RUN_TEST( TestRelational_int2 );

	TEMPER_SKIP_TEST( TestLength_int2, "TODO" );
	TEMPER_SKIP_TEST( TestNormalized_int2, "TODO" );
	TEMPER_SKIP_TEST( TestDot_int2, "TODO" );
	TEMPER_SKIP_TEST( TestCross_int2, "TODO" );
	TEMPER_SKIP_TEST( TestAngle_int2, "TODO" );
};
