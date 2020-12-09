/*
===========================================================================

HLML Generator.
Copyright (c) Dan Moody 2018 - Present.

This file is part of the HLML Generator.

The HLML Generator is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

The HLML Generator is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with The HLML Generator.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/
#include "defines.h"
#include "allocator.h"
#include "timer.h"

#include "gen_common.h"
#include "gen_c.h"
#include "gen_cpp.h"

#include "file_io.h"

#include <stdio.h>

int main( int argc, char** argv ) {
	UNUSED( argc );
	UNUSED( argv );

	printf(
		"HLML Generator.\n"
		"(c) Dan Moody 2019 - Present.\n"
		"\n"
		"Generating...\n"
		"\n"
	);

	allocatorLinear_t* allocator = Mem_CreateLinear( 3 * MB_TO_BYTES );

	for ( u32 i = 0; i < GEN_LANGUAGE_COUNT; i++ ) {
		const genLanguage_t language = (genLanguage_t) i;

		const char* pathOutGen = GEN_FOLDER_PATHS_OUT_GEN[language];
		const char* pathTests = GEN_FOLDER_PATHS_TESTS[language];

		FS_DeleteAllFilesInFolder( pathOutGen );
		FS_CreateFolder( pathOutGen );

		FS_DeleteAllFilesInFolder( pathTests );
		FS_CreateFolder( pathTests );
	}

	float64 start = Time_NowMS();

	printf( "======= Generating core headers. =======\n" );
	Gen_HeaderMain( allocator, GEN_LANGUAGE_C );
	Gen_HeaderMain( allocator, GEN_LANGUAGE_CPP );
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating types. =======\n" );
	Gen_Vectors_C( allocator );
	Gen_Matrices_C( allocator );

	Gen_Vectors_CPP( allocator );
	Gen_Matrices_CPP( allocator );
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating functions. =======\n" );
	Gen_FunctionsScalar( allocator, GEN_LANGUAGE_C );
	Gen_FunctionsScalar( allocator, GEN_LANGUAGE_CPP );

	Gen_FunctionsVector( allocator, GEN_LANGUAGE_C );
	Gen_FunctionsMatrix( allocator, GEN_LANGUAGE_C );
	Gen_FunctionsQuaternion( allocator, GEN_LANGUAGE_C );

	Gen_FunctionsVector( allocator, GEN_LANGUAGE_CPP );
	Gen_FunctionsMatrix( allocator, GEN_LANGUAGE_CPP );
	Gen_FunctionsQuaternion( allocator, GEN_LANGUAGE_CPP );
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating C++ operator overloads. =======\n" );
	Gen_OperatorsVector( allocator );
	Gen_OperatorsMatrix( allocator );
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating SSE helpers. =======\n" );
	Gen_FunctionsScalarSSE( allocator, GEN_LANGUAGE_C );
	Gen_FunctionsVectorSSE( allocator, GEN_LANGUAGE_C );
	Gen_FunctionsMatrixSSE( allocator, GEN_LANGUAGE_C );

	Gen_FunctionsScalarSSE( allocator, GEN_LANGUAGE_CPP );
	Gen_FunctionsVectorSSE( allocator, GEN_LANGUAGE_CPP );
	Gen_FunctionsMatrixSSE( allocator, GEN_LANGUAGE_CPP );
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating tests. =======\n" );
	Gen_Tests( allocator, GEN_LANGUAGE_C );
	Gen_Tests( allocator, GEN_LANGUAGE_CPP );
	Gen_TestsMain( allocator, GEN_LANGUAGE_C );
	Gen_TestsMain( allocator, GEN_LANGUAGE_CPP );
	printf( "======= Done. =======\n\n" );

	float64 end = Time_NowMS();

	printf( "Code generation time taken: %f ms\n\n", end - start );

	printf(
		"All generators have run.  HLML Generator shutting down...\n"
		"Goodbye.\n"
	);

	Mem_DestroyLinear( &allocator );

	return 0;
}
