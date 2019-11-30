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

	Mem_Init( 3 * MB_TO_BYTES );

	Time_Init();

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
	Gen_HeaderMain( GEN_LANGUAGE_C );
	Gen_HeaderMain( GEN_LANGUAGE_CPP );
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating types. =======\n" );
	Gen_Vectors_C();
	Gen_Matrices_C();

	Gen_Vectors_CPP();
	Gen_Matrices_CPP();
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating functions. =======\n" );
	Gen_FunctionsScalar( GEN_FOLDER_PATHS_OUT_GEN[GEN_LANGUAGE_C] );
	Gen_FunctionsScalar( GEN_FOLDER_PATHS_OUT_GEN[GEN_LANGUAGE_CPP] );

	Gen_FunctionsVector( GEN_LANGUAGE_C );
	Gen_FunctionsMatrix( GEN_LANGUAGE_C );
    Gen_FunctionsQuaternion( GEN_LANGUAGE_C );

	Gen_FunctionsVector( GEN_LANGUAGE_CPP );
	Gen_FunctionsMatrix( GEN_LANGUAGE_CPP );    
    Gen_FunctionsQuaternion( GEN_LANGUAGE_CPP );
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating C++ operator overloads. =======\n" );
	Gen_OperatorsVector();
	Gen_OperatorsMatrix();
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating SSE helpers. =======\n" );
	Gen_FunctionsScalarSSE( GEN_LANGUAGE_C );
	Gen_FunctionsVectorSSE( GEN_LANGUAGE_C );
	Gen_FunctionsMatrixSSE( GEN_LANGUAGE_C );

	Gen_FunctionsScalarSSE( GEN_LANGUAGE_CPP );
	Gen_FunctionsVectorSSE( GEN_LANGUAGE_CPP );
	Gen_FunctionsMatrixSSE( GEN_LANGUAGE_CPP );
	printf( "======= Done. =======\n\n" );

	printf( "======= Generating tests. =======\n" );
	Gen_Tests( GEN_LANGUAGE_C );
	Gen_Tests( GEN_LANGUAGE_CPP );
	Gen_TestsMain( GEN_LANGUAGE_C );
	Gen_TestsMain( GEN_LANGUAGE_CPP );
	printf( "======= Done. =======\n\n" );

	float64 end = Time_NowMS();

	// DM: temporarily turning off documentation generation for all non-windows configs
	// because GitHub has a limit on LFS space, which the doxygen executable for linux exceeds
	// TODO(DM): turn this back on when a solution for that gets found
#ifdef _WIN32
	printf( "======= Generating doxygen documentation pages. =======\n" );
	// c
	if ( !Gen_DocumentationPages( "doxygen/c.conf" ) ) {
		return 1;
	}

	// cpp
	if ( !Gen_DocumentationPages( "doxygen/cpp.conf" ) ) {
		return 1;
	}
	printf( "======= Done. =======\n\n" );
#endif

	printf( "Code generation time taken: %f ms\n\n", end - start );

	printf(
		"All generators have run.  HLML Generator shutting down...\n"
		"Goodbye.\n"
	);

	Mem_Shutdown();

	return 0;
}
