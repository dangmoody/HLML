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

#include "../../code/out/gen/hlml_functions_matrix.h"

#include <temper/temper.h>

TEMPER_TEST( TestAssignment_bool2x3 )
{
	bool2x3 mat;

	// fill single value
	mat = bool2x3( true );
	TEMPER_EXPECT_TRUE( mat[0] == bool3( true, false, false ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool3( false, true, false ) );

	// row filling
	mat = bool2x3(
		bool3( 0, 1, 2 ),
		bool3( 3, 4, 5 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == bool3( 0, 1, 2 ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool3( 3, 4, 5 ) );

	// all values filled
	mat = bool2x3(
		6, 5, 4, 
		3, 2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == bool3( 6, 5, 4 ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool3( 3, 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_bool2x3 )
{
	bool2x3 mat;

	TEMPER_EXPECT_TRUE( mat[0] == bool3( true, false, false ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool3( false, true, false ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_bool2x3 )
{
	bool2x3 id = bool2x3(
		true, false, false,
		false, true, false
	);

	bool2x3 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_bool2x3 )
{
	bool2x3 mat = bool2x3(
		false, true, true,
		true, true, true
	);
	bool3x2 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == bool3x2(
		false, true,
		true, true,
		true, true
	) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_bool2x3 )
{
	TEMPER_RUN_TEST( TestAssignment_bool2x3 );
	TEMPER_RUN_TEST( TestArray_bool2x3 );

	TEMPER_RUN_TEST( TestIdentity_bool2x3 );
	TEMPER_RUN_TEST( TestTranspose_bool2x3 );
};
