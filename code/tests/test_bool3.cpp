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

#include "../../code/out/gen/hlml_functions_vector.h"

#include <temper/temper.h>

// also tests equality operators
TEMPER_TEST( TestAssignment_bool3 )
{
	bool3 a;

	a = bool3( true );
	TEMPER_EXPECT_TRUE( a == bool3( true ) );
	TEMPER_EXPECT_TRUE( a != bool3( false, true, true ) );

	a = bool3( false, true, true );
	TEMPER_EXPECT_TRUE( a == bool3( false, true, true ) );
	TEMPER_EXPECT_TRUE( a != bool3( true ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_bool3 )
{
	bool3 a = bool3( false, true, true );

	TEMPER_EXPECT_TRUE( a[0] == false );
	TEMPER_EXPECT_TRUE( a[1] == true );
	TEMPER_EXPECT_TRUE( a[2] == true );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_bool3 )
{
	TEMPER_RUN_TEST( TestAssignment_bool3 );
	TEMPER_RUN_TEST( TestArray_bool3 );
};
