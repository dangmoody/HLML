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

#include "../out/gen/uint4.h"

#include <temper.h>

// also tests equality operators
TEMPER_TEST( TestAssignment_uint4 ) {
	uint4 a;

	a = uint4( 1 );
	TEMPER_EXPECT_TRUE( a == uint4( 1 ) );
	TEMPER_EXPECT_TRUE( a != uint4( 0, 1, 2, 3 ) );

	a = uint4( 0, 1, 2, 3 );
	TEMPER_EXPECT_TRUE( a == uint4( 0, 1, 2, 3 ) );
	TEMPER_EXPECT_TRUE( a != uint4( 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmetic_uint4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestArray_uint4 ) {
	uint4 a = uint4( 0, 1, 2, 3 );

	TEMPER_EXPECT_TRUE( a[0] == 0 );
	TEMPER_EXPECT_TRUE( a[1] == 1 );
	TEMPER_EXPECT_TRUE( a[2] == 2 );
	TEMPER_EXPECT_TRUE( a[3] == 3 );

	TEMPER_PASS();
}

TEMPER_TEST( TestEquality_uint4 ) {
	uint4 vec0 = uint4( 0, 0, 0, 0 );
	uint4 vec1 = uint4( 1, 1, 1, 1 );
	uint4 vec2 = uint4( 2, 2, 2, 2 );
	uint4 vec3 = uint4( 3, 3, 3, 3 );

	bool4 test0 = vec0 <= vec0;
	bool4 test1 = vec0 >= vec0;
	bool4 test2 = vec0 < vec1;

	bool4 test3 = vec1 <= vec1;
	bool4 test4 = vec1 >= vec1;
	bool4 test5 = vec1 < vec2;
	bool4 test6 = vec1 > vec0;

	bool4 test7 = vec2 <= vec2;
	bool4 test8 = vec2 >= vec2;
	bool4 test9 = vec2 < vec3;
	bool4 test10 = vec2 > vec1;

	bool4 test11 = vec3 <= vec3;
	bool4 test12 = vec3 >= vec3;
	bool4 test13 = vec3 > vec2;

	TEMPER_EXPECT_TRUE( test0 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test1 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test2 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test3 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test4 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test5 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test6 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test7 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test8 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test9 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test10 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test11 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test12 == bool4( true ) );
	TEMPER_EXPECT_TRUE( test13 == bool4( true ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestLength_uint4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestNormalized_uint4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestDot_uint4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestCross_uint4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestAngle_uint4 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_uint4 ) {
	TEMPER_RUN_TEST( TestAssignment_uint4 );
	TEMPER_RUN_TEST( TestArithmetic_uint4 );
	TEMPER_RUN_TEST( TestArray_uint4 );
	TEMPER_RUN_TEST( TestRelational_uint4 );

	TEMPER_RUN_TEST( TestLength_uint4 );
	TEMPER_RUN_TEST( TestNormalized_uint4 );
	TEMPER_RUN_TEST( TestDot_uint4 );
	TEMPER_RUN_TEST( TestCross_uint4 );
	TEMPER_RUN_TEST( TestAngle_uint4 );
};
