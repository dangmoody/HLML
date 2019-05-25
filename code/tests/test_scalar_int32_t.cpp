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

TEMPER_TEST( TestSign_int32_t )
{
	TEMPER_EXPECT_TRUE( sign( -5 ) == -1 );
	TEMPER_EXPECT_TRUE( sign( 9 ) == 1 );

	TEMPER_PASS();
}

TEMPER_TEST( TestMinMax_int32_t )
{
	int32_t a = 5;
	int32_t b = 9;

	TEMPER_EXPECT_TRUE( min( a, b ) == a );
	TEMPER_EXPECT_TRUE( max( a, b ) == b );

	TEMPER_PASS();
}

TEMPER_TEST( TestClamp_int32_t )
{
	int32_t a;
	int32_t low  = 1;
	int32_t high = 10;

	a = clamp( 0, low, high );
	TEMPER_EXPECT_TRUE( a == low );

	a = clamp( 11, low, high );
	TEMPER_EXPECT_TRUE( a == high );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_int32_t )
{
	TEMPER_RUN_TEST( TestSign_int32_t );
	TEMPER_RUN_TEST( TestMinMax_int32_t );
	TEMPER_RUN_TEST( TestClamp_int32_t );
}
