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

#define HLML_UNDEF_SYSTEM_MIN_MAX
#include "../../code/out/gen/hlml_functions_scalar.h"

#include <temper/temper.h>

TEMPER_TEST( TestFloateq_float )
{
	float a =  5.000000;
	float b =  5.000000;
	float c =  5.000020;
	float d =  5.000100;

	TEMPER_EXPECT_TRUE( floateq( a, b ) );
	TEMPER_EXPECT_TRUE( !floateq( a, c ) );
	TEMPER_EXPECT_TRUE( !floateq( a, d ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIsInf_float )
{
	float x = 1.000000f / 0.000000f;

	TEMPER_EXPECT_TRUE( isinf( x ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIsNaN_float )
{
	float minusOne = -1.000000f;

	TEMPER_EXPECT_TRUE( isnan( sqrtf( minusOne ) ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestSign_float )
{
	TEMPER_EXPECT_TRUE( sign( -5.000000f ) == -1 );
	TEMPER_EXPECT_TRUE( sign( 9.000000f ) == 1 );

	TEMPER_PASS();
}

TEMPER_TEST( TestDegreesRadians_float )
{
	float deg = 90.000000f;
	float rad = 1.57079637f;

	float answerRadians = radians( deg );
	float answerDegrees = degrees( rad );

	TEMPER_EXPECT_TRUE( floateq( answerRadians, 1.57079637f ) );
	TEMPER_EXPECT_TRUE( floateq( answerDegrees, 90.000000f ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestMinMax_float )
{
	float a = 5.000000f;
	float b = 9.000000f;

	TEMPER_EXPECT_TRUE( min( a, b ) == a );
	TEMPER_EXPECT_TRUE( max( a, b ) == b );

	TEMPER_PASS();
}

TEMPER_TEST( TestClamp_float )
{
	float a;
	float low  = 1.000000f;
	float high = 10.000000f;

	a = clamp( 0.000000f, low, high );
	TEMPER_EXPECT_TRUE( a == low );

	a = clamp( 11.000000f, low, high );
	TEMPER_EXPECT_TRUE( a == high );

	TEMPER_PASS();
}

TEMPER_TEST( TestSaturate_float )
{
	float a;

	a = saturate( -1.000000f );
	TEMPER_EXPECT_TRUE( floateq( a, 0.000000f ) );

	a = saturate( 2.000000f );
	TEMPER_EXPECT_TRUE( floateq( a, 1.000000f ) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_float )
{
	TEMPER_RUN_TEST( TestFloateq_float );
	TEMPER_RUN_TEST( TestIsInf_float );
	TEMPER_RUN_TEST( TestIsNaN_float );
	TEMPER_RUN_TEST( TestSign_float );
	TEMPER_RUN_TEST( TestDegreesRadians_float );
	TEMPER_RUN_TEST( TestMinMax_float );
	TEMPER_RUN_TEST( TestClamp_float );
	TEMPER_RUN_TEST( TestSaturate_float );
}
