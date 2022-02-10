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

#include "generator_core.c"

#include "gen_api.c"
#include "gen_tests.c"

#include "timer.h"
#include "int_types.h"
#include "defines.h"

#include <stdio.h>

static void UpdateStringsFromFlags( const generatorFlags_t flags, generatorStrings_t* outStrings ) {
	assert( outStrings );

	outStrings->parmPassByStr = ( flags & GENERATOR_FLAG_PARMS_ARE_POINTERS ) ? "*" : "&";
	outStrings->parmAccessOperatorStr = ( flags & GENERATOR_FLAG_PARMS_ARE_POINTERS ) ? "->" : ".";
	outStrings->parmReferenceStr = ( flags & GENERATOR_FLAG_PARMS_ARE_POINTERS ) ? "&" : "";
	outStrings->parmDereferenceStr = ( flags & GENERATOR_FLAG_PARMS_ARE_POINTERS ) ? "*" : "";
}

int main( int argc, char** argv ) {
	GEN_UNUSED( argc );
	GEN_UNUSED( argv );

	float64 start = Time_NowMS();

	printf(
		"HLML Generator.\n"
		"(c) Dan Moody 2019 - Present.\n"
		"\n"
		"Generating...\n"
		"\n"
	);

	allocatorLinear_t* allocator = Mem_CreateLinear( 1024 * MB_TO_BYTES );
	allocatorLinear_t* tempStorage = Mem_CreateFromOther( allocator, 512 * MB_TO_BYTES );

	u32 vectorTypeInfosCount = 0;
	u32 quaternionTypeInfosCount = 0;
	u32 matrixTypeInfosCount = 0;

	typeInfo_t* vectorTypeInfos = NULL;
	typeInfo_t* quaternionTypeInfos = NULL;
	typeInfo_t* matrixTypeInfos = NULL;

	// create type infos
	{
		u32 numComponentPermutations = ( 4 - 2 ) + 1;

		// create vector type infos
		{
			u32 typeInfoIndex = 0;

			vectorTypeInfosCount = GEN_TYPE_COUNT * numComponentPermutations;
			vectorTypeInfos = (typeInfo_t*) Mem_Alloc( allocator, vectorTypeInfosCount * sizeof( typeInfo_t ) );

			for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
				genType_t type = (genType_t) typeIndex;

				const char* typeString = Gen_GetTypeString( type );

				for ( u32 componentIndex = 2; componentIndex <= 4; componentIndex++ ) {
					typeInfo_t* typeInfo = &vectorTypeInfos[typeInfoIndex++];
					typeInfo->type = type;
					typeInfo->numRows = 1;
					typeInfo->numCols = componentIndex;
					typeInfo->fullTypeName = String_TPrintf( allocator, "%s%d", typeString, typeInfo->numCols );
				}
			}
		}

		// create quaternion type infos
		{
			quaternionTypeInfosCount = 2;
			quaternionTypeInfos = (typeInfo_t*) Mem_Alloc( allocator, quaternionTypeInfosCount * sizeof( typeInfo_t ) );

			typeInfo_t* typeInfo = NULL;

			typeInfo = &quaternionTypeInfos[0];
			typeInfo->type = GEN_TYPE_FLOAT;
			typeInfo->numRows = 1;
			typeInfo->numCols = 4;
			typeInfo->fullTypeName = "float4";

			typeInfo = &quaternionTypeInfos[1];
			typeInfo->type = GEN_TYPE_DOUBLE;
			typeInfo->numRows = 1;
			typeInfo->numCols = 4;
			typeInfo->fullTypeName = "double4";
		}

		// create matrix type infos
		{
			u32 typeInfoIndex = 0;

			matrixTypeInfosCount = GEN_TYPE_COUNT * numComponentPermutations * numComponentPermutations;
			matrixTypeInfos = (typeInfo_t*) Mem_Alloc( allocator, matrixTypeInfosCount * sizeof( typeInfo_t ) );

			for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
				genType_t type = (genType_t) typeIndex;

				const char* typeString = Gen_GetTypeString( type );

				for ( u32 row = 2; row <= 4; row++ ) {
					for ( u32 col = 2; col <= 4; col++ ) {
						typeInfo_t* typeInfo = &matrixTypeInfos[typeInfoIndex++];
						typeInfo->type = type;
						typeInfo->numRows = row;
						typeInfo->numCols = col;
						typeInfo->fullTypeName = String_TPrintf( allocator, "%s%dx%d", typeString, typeInfo->numRows, typeInfo->numCols );
					}
				}
			}
		}
	}

	generatorFlags_t flags = 0;

	generatorStrings_t generatorStrings = { 0 };

	// C99
	{
		flags = GENERATOR_FLAG_PARMS_ARE_POINTERS | GENERATOR_FLAG_C_LINKAGE;

		UpdateStringsFromFlags( flags, &generatorStrings );

		GenerateAPIFiles( tempStorage, "c", vectorTypeInfos, vectorTypeInfosCount, quaternionTypeInfos, quaternionTypeInfosCount, matrixTypeInfos, matrixTypeInfosCount, &generatorStrings, flags );
		GenerateTests( tempStorage, "c", vectorTypeInfos, vectorTypeInfosCount, quaternionTypeInfos, quaternionTypeInfosCount, matrixTypeInfos, matrixTypeInfosCount, &generatorStrings, flags );
	}

	// C++
	{
		flags = GENERATOR_FLAG_GENERATE_OPERATORS | GENERATOR_FLAG_NAME_MANGLING | GENERATOR_FLAG_VECTOR_UNIONS | GENERATOR_FLAG_GENERATE_CONSTRUCTORS;

		UpdateStringsFromFlags( flags, &generatorStrings );

		GenerateAPIFiles( tempStorage, "cpp", vectorTypeInfos, vectorTypeInfosCount, quaternionTypeInfos, quaternionTypeInfosCount, matrixTypeInfos, matrixTypeInfosCount, &generatorStrings, flags );
		GenerateTests( tempStorage, "cpp", vectorTypeInfos, vectorTypeInfosCount, quaternionTypeInfos, quaternionTypeInfosCount, matrixTypeInfos, matrixTypeInfosCount, &generatorStrings, flags );
	}

	float64 end = Time_NowMS();

	printf( "Code generation time taken: %f ms\n\n", end - start );

	printf(
		"All generators have run.  HLML Generator shutting down...\n"
		"Goodbye.\n"
	);

	Mem_DestroyLinear( &allocator );

	return 0;
}