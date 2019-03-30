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

#include "../../code/out/gen/hlml_functions_scalar.h"

#include <temper/temper.h>

TEMPER_TEST( TestMinMax_uint32_t )
{
	uint32_t a = 5U;
	uint32_t b = 9U;

	TEMPER_EXPECT_TRUE( min( a, b ) == a );
	TEMPER_EXPECT_TRUE( max( a, b ) == b );

	TEMPER_PASS();
}

TEMPER_TEST( TestClamp_uint32_t )
{
	uint32_t a;
	uint32_t low  = 1U;
	uint32_t high = 10U;

	a = clamp( 0U, low, high );
	TEMPER_EXPECT_TRUE( a == low );

	a = clamp( 11U, low, high );
	TEMPER_EXPECT_TRUE( a == high );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_uint32_t )
{
	TEMPER_RUN_TEST( TestMinMax_uint32_t );
	TEMPER_RUN_TEST( TestClamp_uint32_t );
}
