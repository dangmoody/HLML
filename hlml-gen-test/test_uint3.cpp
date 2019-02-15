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

#include "../out/gen/uint3.h"

#include <temper.h>

// also tests equality operators
TEMPER_TEST( TestAssignment_uint3 ) {
	uint3 a;

	a = uint3( 1 );
	TEMPER_EXPECT_TRUE( a == uint3( 1 ) );
	TEMPER_EXPECT_TRUE( a != uint3( 0, 1, 2 ) );

	a = uint3( 0, 1, 2 );
	TEMPER_EXPECT_TRUE( a == uint3( 0, 1, 2 ) );
	TEMPER_EXPECT_TRUE( a != uint3( 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmetic_uint3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestArray_uint3 ) {
	uint3 a = uint3( 0, 1, 2 );

	TEMPER_EXPECT_TRUE( a[0] == 0 );
	TEMPER_EXPECT_TRUE( a[1] == 1 );
	TEMPER_EXPECT_TRUE( a[2] == 2 );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_uint3 ) {
	uint3 vec0 = uint3( 0, 0, 0 );
	uint3 vec1 = uint3( 1, 1, 1 );
	uint3 vec2 = uint3( 2, 2, 2 );

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

TEMPER_TEST( TestLength_uint3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestNormalized_uint3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestDot_uint3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestCross_uint3 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestAngle_uint3 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_uint3 ) {
	TEMPER_RUN_TEST( TestAssignment_uint3 );
	TEMPER_RUN_TEST( TestArithmetic_uint3 );
	TEMPER_RUN_TEST( TestArray_uint3 );
	TEMPER_RUN_TEST( TestRelational_uint3 );

	TEMPER_RUN_TEST( TestLength_uint3 );
	TEMPER_RUN_TEST( TestNormalized_uint3 );
	TEMPER_RUN_TEST( TestDot_uint3 );
	TEMPER_RUN_TEST( TestCross_uint3 );
	TEMPER_RUN_TEST( TestAngle_uint3 );
};
