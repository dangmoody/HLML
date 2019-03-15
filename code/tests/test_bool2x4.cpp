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

TEMPER_TEST( TestAssignment_bool2x4 ) {
	bool2x4 mat;

	// fill single value
	mat = bool2x4( true );
	TEMPER_EXPECT_TRUE( mat[0] == bool4( true, false, false, false ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool4( false, true, false, false ) );

	// row filling
	mat = bool2x4(
		bool4( 0, 1, 2, 3 ),
		bool4( 4, 5, 6, 7 )
	);
	TEMPER_EXPECT_TRUE( mat[0] == bool4( 0, 1, 2, 3 ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool4( 4, 5, 6, 7 ) );

	// all values filled
	mat = bool2x4(
		8, 7, 6, 5, 
		4, 3, 2, 1
	);
	TEMPER_EXPECT_TRUE( mat[0] == bool4( 8, 7, 6, 5 ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool4( 4, 3, 2, 1 ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestArray_bool2x4 ) {
	bool2x4 mat;

	TEMPER_EXPECT_TRUE( mat[0] == bool4( true, false, false, false ) );
	TEMPER_EXPECT_TRUE( mat[1] == bool4( false, true, false, false ) );

	TEMPER_PASS();
}

TEMPER_TEST( TestIdentity_bool2x4 ) {
	bool2x4 id = bool2x4(
		true, false, false, false,
		false, true, false, false
	);

	bool2x4 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_bool2x4 ) {
	bool2x4 mat = bool2x4(
		false, true, true, true,
		true, true, true, true
	);
	bool4x2 trans = transpose( mat );

	TEMPER_EXPECT_TRUE( trans == bool4x2(
		false, true,
		true, true,
		true, true,
		true, true
	) );

	TEMPER_PASS();
}

TEMPER_SUITE( Test_bool2x4 ) {
	TEMPER_RUN_TEST( TestAssignment_bool2x4 );
	TEMPER_RUN_TEST( TestArray_bool2x4 );

	TEMPER_RUN_TEST( TestIdentity_bool2x4 );
	TEMPER_RUN_TEST( TestTranspose_bool2x4 );
};
