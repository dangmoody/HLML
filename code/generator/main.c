/*
===========================================================================

HLML Generator.
Copyright (c) Dan Moody 2018 - Present.

This file is part of the HLML Generator.

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
	GEN_UNUSED( argc );
	GEN_UNUSED( argv );

	float64 start = Time_NowMS();

	printf(
		"HLML Generator.\n"
		"\n"
		"Generating...\n"
		"\n"
	);

	allocatorLinear_t *allocator = Mem_CreateLinear( GIGABYTES( 6 ) );
	allocatorLinear_t *tempStorage = Mem_CreateFromOther( allocator, GIGABYTES( 5 ) );

	u32 vectorTypeInfosCount = 0;
	u32 quaternionTypeInfosCount = 0;
	u32 matrixTypeInfosCount = 0;

	typeInfo_t *vectorTypeInfos = NULL;
	typeInfo_t *quaternionTypeInfos = NULL;
	typeInfo_t *matrixTypeInfos = NULL;

	// create type infos
	{
		u32 numComponentPermutations = ( 4 - 2 ) + 1;

		// create vector type infos
		{
			u32 typeInfoIndex = 0;

			vectorTypeInfosCount = GEN_TYPE_COUNT * numComponentPermutations;
			vectorTypeInfos = (typeInfo_t *) Mem_Alloc( allocator, vectorTypeInfosCount * sizeof( typeInfo_t ) );

			for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
				genType_t type = (genType_t) typeIndex;

				const char *typeString = Gen_GetTypeString( type );

				for ( u32 componentIndex = 2; componentIndex <= 4; componentIndex++ ) {
					typeInfo_t *typeInfo = &vectorTypeInfos[typeInfoIndex++];
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
			quaternionTypeInfos = (typeInfo_t *) Mem_Alloc( allocator, quaternionTypeInfosCount * sizeof( typeInfo_t ) );

			typeInfo_t *typeInfo = NULL;

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
			matrixTypeInfos = (typeInfo_t *) Mem_Alloc( allocator, matrixTypeInfosCount * sizeof( typeInfo_t ) );

			for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
				genType_t type = (genType_t) typeIndex;

				const char *typeString = Gen_GetTypeString( type );

				for ( u32 row = 2; row <= 4; row++ ) {
					for ( u32 col = 2; col <= 4; col++ ) {
						typeInfo_t *typeInfo = &matrixTypeInfos[typeInfoIndex++];
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

		Gen_GenerateAPIFiles( tempStorage, "c", vectorTypeInfos, vectorTypeInfosCount, quaternionTypeInfos, quaternionTypeInfosCount, matrixTypeInfos, matrixTypeInfosCount, &generatorStrings, flags );
		Gen_GenerateTests( tempStorage, "c", vectorTypeInfos, vectorTypeInfosCount, quaternionTypeInfos, quaternionTypeInfosCount, matrixTypeInfos, matrixTypeInfosCount, &generatorStrings, flags );
	}

	// C++
	{
		flags = GENERATOR_FLAG_GENERATE_OPERATORS | GENERATOR_FLAG_NAME_MANGLING | GENERATOR_FLAG_VECTOR_UNIONS | GENERATOR_FLAG_GENERATE_CONSTRUCTORS | GENERATOR_FLAG_VECTOR_SWIZZLES | GENERATOR_FLAG_ALLOW_NAMESPACE;

		UpdateStringsFromFlags( flags, &generatorStrings );

		Gen_GenerateAPIFiles( tempStorage, "cpp", vectorTypeInfos, vectorTypeInfosCount, quaternionTypeInfos, quaternionTypeInfosCount, matrixTypeInfos, matrixTypeInfosCount, &generatorStrings, flags );
		Gen_GenerateTests( tempStorage, "cpp", vectorTypeInfos, vectorTypeInfosCount, quaternionTypeInfos, quaternionTypeInfosCount, matrixTypeInfos, matrixTypeInfosCount, &generatorStrings, flags );
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