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

TEMPER_TEST( TestArithmeticAddition_uint3 ) {
	uint3 a = uint3( 2 );
	uint3 b = uint3( 2, 3, 4 );
	uint3 c = a + b;

	TEMPER_EXPECT_TRUE( c == uint3( 4, 5, 6 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticSubtraction_uint3 ) {
	uint3 a = uint3( 2 );
	uint3 b = uint3( 2, 3, 4 );
	uint3 c = a - b;

	TEMPER_EXPECT_TRUE( c == uint3( 0, -1, -2 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticMultiplication_uint3 ) {
	uint3 a = uint3( 2 );
	uint3 b = uint3( 2, 3, 4 );
	uint3 c = a * b;

	TEMPER_EXPECT_TRUE( c == uint3( 4, 6, 8 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArithmeticDivision_uint3 ) {
	uint3 a = uint3( 2 );
	uint3 b = uint3( 2, 3, 4 );
	uint3 c = a / b;

	TEMPER_EXPECT_TRUE( c == uint3( 1, 0, 0 ) );

	TEMPER_PASS();
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
	uint3 vec = uint3( 2 );

	TEMPER_EXPECT_TRUE( floateq( lengthsqr( vec ), 12.0f ) );
	TEMPER_EXPECT_TRUE( floateq( length( vec ), 3.46410161514f ) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_uint3 ) {
	TEMPER_RUN_TEST( TestAssignment_uint3 );
	TEMPER_RUN_TEST( TestArray_uint3 );

	TEMPER_RUN_TEST( TestArithmeticAddition_uint3 );
	TEMPER_RUN_TEST( TestArithmeticSubtraction_uint3 );
	TEMPER_RUN_TEST( TestArithmeticMultiplication_uint3 );
	TEMPER_RUN_TEST( TestArithmeticDivision_uint3 );

	TEMPER_RUN_TEST( TestRelational_uint3 );

	TEMPER_RUN_TEST( TestLength_uint3 );
};
