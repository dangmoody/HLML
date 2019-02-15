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

#include "../out/gen/double2.h"

#include <temper.h>

// also tests equality operators
TEMPER_TEST( TestAssignment_double2 ) {
	double2 a;

	a = double2( 1.0 );
	TEMPER_EXPECT_TRUE( a == double2( 1.0 ) );
	TEMPER_EXPECT_TRUE( a != double2( 0.0, 1.0 ) );

	a = double2( 0.0, 1.0 );
	TEMPER_EXPECT_TRUE( a == double2( 0.0, 1.0 ) );
	TEMPER_EXPECT_TRUE( a != double2( 1.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_double2 ) {
	double2 a = double2( 2.0 );
	double2 b = double2( 2.0, 3.0 );
	double2 c = a + b;

	TEMPER_EXPECT_TRUE( c == double2( 4.0, 5.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_double2 ) {
	double2 a = double2( 2.0 );
	double2 b = double2( 2.0, 3.0 );
	double2 c = a - b;

	TEMPER_EXPECT_TRUE( c == double2( 0.0, -1.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_double2 ) {
	double2 a = double2( 2.0 );
	double2 b = double2( 2.0, 3.0 );
	double2 c = a * b;

	TEMPER_EXPECT_TRUE( c == double2( 4.0, 6.0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_double2 ) {
	double2 a = double2( 2.0 );
	double2 b = double2( 2.0, 3.0 );
	double2 c = a / b;

	TEMPER_EXPECT_TRUE( c == double2( 1.000000, 0.666667 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_double2 ) {
	double2 a = double2( 0.0, 1.0 );

	TEMPER_EXPECT_TRUE( a[0] == 0.0 );
	TEMPER_EXPECT_TRUE( a[1] == 1.0 );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_double2 ) {
	double2 vec0 = double2( 0.0, 0.0 );
	double2 vec1 = double2( 1.0, 1.0 );

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

TEMPER_TEST( TestLength_double2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestNormalized_double2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestDot_double2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestCross_double2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestAngle_double2 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_double2 ) {
	TEMPER_RUN_TEST( TestAssignment_double2 );
	TEMPER_RUN_TEST( TestArray_double2 );

	TEMPER_RUN_TEST( TestArithmeticAddition_double2 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_double2 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_double2 );
	TEMPER_RUN_TEST( TestArithmeticDivision_double2 );

	TEMPER_RUN_TEST( TestRelational_double2 );

	TEMPER_SKIP_TEST( TestLength_double2, "TODO" );
	TEMPER_SKIP_TEST( TestNormalized_double2, "TODO" );
	TEMPER_SKIP_TEST( TestDot_double2, "TODO" );
	TEMPER_SKIP_TEST( TestCross_double2, "TODO" );
	TEMPER_SKIP_TEST( TestAngle_double2, "TODO" );
};
