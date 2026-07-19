/*
===========================================================================

HLML

Copyright (c) Dan Moody 2018 - Present.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

===========================================================================
*/

#include "timer.h"
#include "int_types.h"
#include "defines.h"
#include "linear_allocator.h"
#include "string_helpers.h"

#include "gen_shared.h"
#include "gen_api.h"
#include "gen_config.h"

#include <stdio.h>
#include <assert.h>

static void UpdateStringsFromFlags( const generatorFlags_t flags, generatorStrings_t *outStrings ) {
	assert( outStrings );

	outStrings->parmPassByStr = ( flags & GENERATOR_FLAG_PARMS_ARE_POINTERS ) ? "*" : "&";
	outStrings->parmAccessOperatorStr = ( flags & GENERATOR_FLAG_PARMS_ARE_POINTERS ) ? "->" : ".";
	outStrings->parmReferenceStr = ( flags & GENERATOR_FLAG_PARMS_ARE_POINTERS ) ? "&" : "";
	outStrings->parmDereferenceStr = ( flags & GENERATOR_FLAG_PARMS_ARE_POINTERS ) ? "*" : "";
}

int main( int argc, char **argv ) {
	if ( argc < 2 ) {
		printf(
			"ERROR: No config file specified.\n"
			"Usage: hlml-generator <config-path>\n"
			"\n"
			"Each config file generates exactly one language (see its \"language\" key).  To generate\n"
			"both C and C++ output, run the generator twice, once per language, each with its own config file.\n"
		);

		return 1;
	}

	const char *configPath = argv[1];

	float64 start = Time_NowMS();

	printf(
		"HLML Generator.\n"
		"\n"
		"Generating...\n"
		"\n"
	);

	allocatorLinear_t *allocator = Mem_CreateLinear( GIGABYTES( 6 ) );
	allocatorLinear_t *tempStorage = Mem_CreateFromOther( allocator, GIGABYTES( 5 ) );

	genConfig_t config;
	Gen_Config_SetDefaults( &config );

	printf( "Loading config \"%s\"...\n", configPath );

	if ( !Gen_Config_LoadFromFile( configPath, &config ) ) {
		printf( "\nExiting due to invalid configuration.\n" );

		Mem_DestroyLinear( &allocator );

		return 1;
	}

	Mem_Reset( tempStorage );

	printf( "\n" );

	u32 vectorTypeInfosCount = 0;
	u32 quaternionTypeInfosCount = 0;
	u32 matrixTypeInfosCount = 0;

	typeInfo_t *vectorTypeInfos = NULL;
	typeInfo_t *quaternionTypeInfos = NULL;
	typeInfo_t *matrixTypeInfos = NULL;

	Gen_BuildTypeInfos( allocator, &config.types,
		&vectorTypeInfos, &vectorTypeInfosCount,
		&quaternionTypeInfos, &quaternionTypeInfosCount,
		&matrixTypeInfos, &matrixTypeInfosCount );

	const u32 componentCountMin = config.types.componentCountMin;
	const u32 componentCountMax = config.types.componentCountMax;

	const char *languageName = ( config.language == GEN_LANGUAGE_C ) ? "c" : "cpp";

	generatorStrings_t generatorStrings = { 0 };
	UpdateStringsFromFlags( config.flags, &generatorStrings );

	Gen_GenerateAPIFiles( tempStorage, languageName, vectorTypeInfos, vectorTypeInfosCount, quaternionTypeInfos, quaternionTypeInfosCount, matrixTypeInfos, matrixTypeInfosCount, &generatorStrings, config.flags, componentCountMin, componentCountMax );
	Gen_GenerateTests( tempStorage, languageName, vectorTypeInfos, vectorTypeInfosCount, quaternionTypeInfos, quaternionTypeInfosCount, matrixTypeInfos, matrixTypeInfosCount, &generatorStrings, config.flags, componentCountMin, componentCountMax );

	float64 end = Time_NowMS();

	printf( "Code generation time taken: %f ms\n\n", end - start );

	printf(
		"All generators have run.  HLML Generator shutting down...\n"
		"Goodbye.\n"
	);

	Mem_DestroyLinear( &allocator );

	return 0;
}
