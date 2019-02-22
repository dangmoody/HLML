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

#include "../out/gen/hlml_functions_matrix.h"

#include <temper.h>

TEMPER_TEST( TestAssignment_uint2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestArithmetic_uint2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestArray_uint2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestRelational_uint2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestIdentity_uint2x4 ) {
	uint2x4 id = uint2x4(
		1, 0, 0, 0,
		0, 1, 0, 0
	);

	uint2x4 mat;
	TEMPER_EXPECT_TRUE( mat == id );

	identity( mat );
	TEMPER_EXPECT_TRUE( mat == id );

	TEMPER_PASS();
}

TEMPER_TEST( TestTranspose_uint2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestInverse_uint2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestDeterminant_uint2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestTranslate_uint2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestRotate_uint2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestScale_uint2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestOrtho_uint2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestPerspective_uint2x4 ) {
	TEMPER_FAIL();
}

TEMPER_TEST( TestLookAt_uint2x4 ) {
	TEMPER_FAIL();
}

TEMPER_SUITE( Test_uint2x4 ) {
	TEMPER_SKIP_TEST( TestAssignment_uint2x4, "TODO" );
	TEMPER_SKIP_TEST( TestArithmetic_uint2x4, "TODO" );
	TEMPER_SKIP_TEST( TestArray_uint2x4, "TODO" );
	TEMPER_SKIP_TEST( TestRelational_uint2x4, "TODO" );

	TEMPER_RUN_TEST( TestIdentity_uint2x4 );
	TEMPER_SKIP_TEST( TestTranspose_uint2x4, "TODO" );

	TEMPER_SKIP_TEST( TestInverse_uint2x4, "TODO" );
	TEMPER_SKIP_TEST( TestDeterminant_uint2x4, "TODO" );

	TEMPER_SKIP_TEST( TestTranslate_uint2x4, "TODO" );
	TEMPER_SKIP_TEST( TestRotate_uint2x4, "TODO" );
	TEMPER_SKIP_TEST( TestScale_uint2x4, "TODO" );

	TEMPER_SKIP_TEST( TestOrtho_uint2x4, "TODO" );
	TEMPER_SKIP_TEST( TestPerspective_uint2x4, "TODO" );
	TEMPER_SKIP_TEST( TestLookAt_uint2x4, "TODO" );
};
