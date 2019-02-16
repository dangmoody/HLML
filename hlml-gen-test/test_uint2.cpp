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
TEMPER_TEST( TestAssignment_uint2 ) {
	uint2 a;

	a = uint2( 1 );
	TEMPER_EXPECT_TRUE( a == uint2( 1 ) );
	TEMPER_EXPECT_TRUE( a != uint2( 0, 1 ) );

	a = uint2( 0, 1 );
	TEMPER_EXPECT_TRUE( a == uint2( 0, 1 ) );
	TEMPER_EXPECT_TRUE( a != uint2( 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticAddition_uint2 ) {
	uint2 a = uint2( 2 );
	uint2 b = uint2( 2, 3 );
	uint2 c = a + b;

	TEMPER_EXPECT_TRUE( c == uint2( 4, 5 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_uint2 ) {
	uint2 a = uint2( 2 );
	uint2 b = uint2( 2, 3 );
	uint2 c = a - b;

	TEMPER_EXPECT_TRUE( c == uint2( 0, -1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_uint2 ) {
	uint2 a = uint2( 2 );
	uint2 b = uint2( 2, 3 );
	uint2 c = a * b;

	TEMPER_EXPECT_TRUE( c == uint2( 4, 6 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_uint2 ) {
	uint2 a = uint2( 2 );
	uint2 b = uint2( 2, 3 );
	uint2 c = a / b;

	TEMPER_EXPECT_TRUE( c == uint2( 1, 0 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_uint2 ) {
	uint2 a = uint2( 0, 1 );

	TEMPER_EXPECT_TRUE( a[0] == 0 );
	TEMPER_EXPECT_TRUE( a[1] == 1 );

	TEMPER_PASS();
}

TEMPER_TEST( TestRelational_uint2 ) {
	uint2 vec0 = uint2( 0, 0 );
	uint2 vec1 = uint2( 1, 1 );

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

TEMPER_TEST( TestLength_uint2 ) {
	uint2 vec = uint2( 2 );

	TEMPER_EXPECT_TRUE( floateq( lengthsqr( vec ), 8.000000 ) );
	TEMPER_EXPECT_TRUE( floateq( length( vec ), 2.828427 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestNormalized_uint2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestDot_uint2 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestAngle_uint2 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_uint2 ) {
	TEMPER_RUN_TEST( TestAssignment_uint2 );
	TEMPER_RUN_TEST( TestArray_uint2 );

	TEMPER_RUN_TEST( TestArithmeticAddition_uint2 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_uint2 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_uint2 );
	TEMPER_RUN_TEST( TestArithmeticDivision_uint2 );

	TEMPER_RUN_TEST( TestRelational_uint2 );

	TEMPER_RUN_TEST( TestLength_uint2 );
	TEMPER_SKIP_TEST( TestNormalized_uint2, "TODO" );
	TEMPER_SKIP_TEST( TestDot_uint2, "TODO" );
	TEMPER_SKIP_TEST( TestCross_uint2, "TODO" );
};
