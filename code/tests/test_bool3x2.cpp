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

TEMPER_TEST( TestAssignment_bool3x2 )
{
	bool3x2 mat;

	// fill single value
	mat = bool3x2( true );
	TEMPER_EXPECT_TRUE( mat[0] == bool2( true, false ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool2( false, true ) );
	TEMPER_EXPECT_TRUE( mat[2] == bool2( false, false ) );

	// row filling
	mat = bool3x2(
		bool2( false, true ),
		bool2( true, true ),
		bool2( true, true )
	);
	TEMPER_EXPECT_TRUE( mat[0] == bool2( false, true ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool2( true, true ) );
	TEMPER_EXPECT_TRUE( mat[2] == bool2( true, true ) );

	// all values filled
	mat = bool3x2(
		true, true,
		true, true,
		true, true
	);
	TEMPER_EXPECT_TRUE( mat[0] == bool2( true, true ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool2( true, true ) );
	TEMPER_EXPECT_TRUE( mat[2] == bool2( true, true ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_bool3x2 )
{
	bool3x2 mat;

	TEMPER_EXPECT_TRUE( mat[0] == bool2( true, false ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool2( false, true ) );
	TEMPER_EXPECT_TRUE( mat[2] == bool2( false, false ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_bool3x2 )
{
	// scalar
	bool3x2 id = bool3x2(
		true, false,
		false, true,
		false, false
	);

	bool3x2 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_bool3x2 )
{
	// scalar
	bool3x2 mat = bool3x2(
		false, true,
		true, true,
		true, true
	);
	bool2x3 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == bool2x3(
		false, true, true,
		true, true, true
	) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_bool3x2 )
{
	TEMPER_RUN_TEST( TestAssignment_bool3x2 );
	TEMPER_RUN_TEST( TestArray_bool3x2 );
	TEMPER_RUN_TEST( TestIdentity_bool3x2 );
	TEMPER_RUN_TEST( TestTranspose_bool3x2 );
}
