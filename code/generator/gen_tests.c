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

#include "gen_shared.h"
#include "common_names.h"

#include "file_io.h"
#include "defines.h"

#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "tests_shared.c"
#include "tests_vector.c"
#include "tests_matrix.c"

static void GenerateTests( allocatorLinear_t* tempStorage,
						   const char* languageName,
						   const typeInfo_t* vectorTypeInfos, const u32 vectorTypeInfosCount,
						   const typeInfo_t* quaternionTypeInfos, const u32 quaternionTypeInfosCount,
						   const typeInfo_t* matrixTypeInfos, const u32 matrixTypeInfosCount,
						   const generatorStrings_t* strings,
						   const generatorFlags_t flags )
{
	assert( tempStorage );
	assert( languageName );
	assert( vectorTypeInfos );
	assert( vectorTypeInfosCount );
	assert( quaternionTypeInfos );
	assert( quaternionTypeInfosCount );
	assert( matrixTypeInfos );
	assert( matrixTypeInfosCount );

	printf( "Generating tests for \"%s\"...\n", languageName );

	char generatedCodePath[1024] = { 0 };
	stbsp_snprintf( generatedCodePath, 1024, "%s%s", GEN_GENERATED_CODE_PATH, languageName );

	char generatedTestsPath[1024] = { 0 };
	stbsp_snprintf( generatedTestsPath, 1024, "%s%s", GEN_GENERATED_TESTS_PATH, languageName );

	FS_CreateFolder( generatedTestsPath );

	// scalar tests
	for ( u32 i = 0; i < GEN_TYPE_COUNT; i++ ) {
		const genType_t type = (genType_t) i;

		if ( type == GEN_TYPE_BOOL ) {
			continue;
		}

		const char* typeString = Gen_GetTypeString( type );

		typeInfo_t typeInfo = {
			.type			= type,
			.numRows		= 1,
			.numCols		= 1,
			.fullTypeName	= Gen_GetMemberTypeString( typeInfo.type )
		};

		typeInfo_t scalarTypeFloatingPoint = {
			.type			= Gen_GetSupportedFloatingPointType( typeInfo.type ),
			.numRows		= 1,
			.numCols		= 1,
			.fullTypeName	= Gen_GetTypeString( scalarTypeFloatingPoint.type )
		};

		printf( "Generating test_%s.%s...", typeString, languageName );

		stringBuilder_t* code = StringBuilder_Create( tempStorage, KILOBYTES( 16 ) );

		StringBuilder_Append( code, GEN_FILE_HEADER );

		GenerateComponentWiseTests( tempStorage, code, &typeInfo, &typeInfo, &scalarTypeFloatingPoint, strings, flags );

		const char* fileNameHeader = String_TPrintf( tempStorage, "%s/test_%s.%s", generatedTestsPath, typeString, languageName );
		FS_WriteEntireFile( fileNameHeader, code->str, code->length );

		printf( "OK.\n" );

		Mem_Reset( tempStorage );
	}

	GenerateVectorTests( tempStorage, generatedTestsPath, languageName, vectorTypeInfos, vectorTypeInfosCount, strings, flags );
	GenerateQuaternionTests( tempStorage, generatedTestsPath, languageName, vectorTypeInfos, vectorTypeInfosCount, strings, flags );
	GenerateMatrixTests( tempStorage, generatedTestsPath, languageName, matrixTypeInfos, matrixTypeInfosCount, strings, flags );

	// generate test_main
	{
		printf( "Generating test_main.%s...", languageName );

		stringBuilder_t* sb = StringBuilder_Create( tempStorage, KILOBYTES( 10 ) );

		StringBuilder_Append( sb,
			GEN_FILE_HEADER
			"#define NOMINMAX\n"
			"\n"

			"#define TEMPER_IMPLEMENTATION\n"
			"#include <temper/temper.h>\n"
			"\n"
		);

		StringBuilder_Appendf( sb, "#include \"../../../%s/%s\"\n\n", generatedCodePath, GEN_HEADER_MAIN );

		StringBuilder_Append( sb, "TEMPER_TEST( Test_TypeSizes, TEMPER_FLAG_SHOULD_RUN )\n" );
		StringBuilder_Append( sb, "{\n" );

		for ( u32 i = 0; i < vectorTypeInfosCount; i++ ) {
			const typeInfo_t* typeInfo = &vectorTypeInfos[i];

			u32 sizeBytes = typeInfo->numRows * typeInfo->numCols * Gen_GetTypeBytes( typeInfo->type );

			StringBuilder_Appendf( sb, "\tTEMPER_CHECK_TRUE( sizeof( %s ) == %d );\n", typeInfo->fullTypeName, sizeBytes );
		}
		StringBuilder_Append( sb, "\n" );

		for ( u32 i = 0; i < matrixTypeInfosCount; i++ ) {
			const typeInfo_t* typeInfo = &matrixTypeInfos[i];

			u32 sizeBytes = typeInfo->numRows * typeInfo->numCols * Gen_GetTypeBytes( typeInfo->type );

			StringBuilder_Appendf( sb, "\tTEMPER_CHECK_TRUE( sizeof( %s ) == %d );\n", typeInfo->fullTypeName, sizeBytes );
		}

		StringBuilder_Append( sb, "}\n\n" );

		// scalar tests
		for ( u32 i = 0; i < GEN_TYPE_COUNT; i++ ) {
			genType_t type = (genType_t) i;

			if ( type == GEN_TYPE_BOOL ) {
				continue;
			}

			const char* typeString = Gen_GetTypeString( type );

			StringBuilder_Appendf( sb, "#include \"test_%s.%s\"\n", typeString, languageName );
		}
		StringBuilder_Append( sb, "\n" );

		// vector tests
		for ( u32 i = 0; i < vectorTypeInfosCount; i++ ) {
			const typeInfo_t* typeInfo = &vectorTypeInfos[i];

			if ( typeInfo->type == GEN_TYPE_BOOL ) {
				continue;
			}

			StringBuilder_Appendf( sb, "#include \"test_%s.%s\"\n", typeInfo->fullTypeName, languageName );

			if ( flags & GENERATOR_FLAG_VECTOR_UNIONS ) {
				StringBuilder_Appendf( sb, "#include \"test_%s_swizzle_%s.%s\"\n", typeInfo->fullTypeName, GEN_COMPONENT_NAMES_VECTOR, languageName );
				StringBuilder_Appendf( sb, "#include \"test_%s_swizzle_%s.%s\"\n", typeInfo->fullTypeName, GEN_COMPONENT_NAMES_COLOR, languageName );
			}
		}
		StringBuilder_Append( sb, "\n" );

		// quaternion tests
		for ( u32 i = 0; i < quaternionTypeInfosCount; i++ ) {
			const typeInfo_t* typeInfo = &quaternionTypeInfos[i];
			assert( Gen_VectorQualifiesAsQuaternion( typeInfo ) );

			StringBuilder_Appendf( sb, "#include \"test_quat_%s.%s\"\n", typeInfo->fullTypeName, languageName );
		}
		StringBuilder_Append( sb, "\n" );

		// matrix tests
		for ( u32 i = 0; i < matrixTypeInfosCount; i++ ) {
			const typeInfo_t* typeInfo = &matrixTypeInfos[i];

			if ( typeInfo->type == GEN_TYPE_BOOL ) {
				continue;
			}

			StringBuilder_Appendf( sb, "#include \"test_%s.%s\"\n", typeInfo->fullTypeName, languageName );
		}
		StringBuilder_Append( sb, "\n" );

		StringBuilder_Append( sb,
			"#define TEST_PADDING \"................................................................\"\n"
			"\n"

			"static void OnBeforeTest( const temperTestInfo_t* testInfo )\n"
			"{\n"
			"\tconst int padLengthMax = (int) strlen( TEST_PADDING );\n"
			"\n"
			"\tconst int dotLength = padLengthMax - (int) strlen( testInfo->testNameStr );\n"
			"\tassert( dotLength );\n"
			"\n"
			"\tprintf( \"%s %*.*s \", testInfo->testNameStr, dotLength, dotLength, TEST_PADDING );\n"
			"}\n"
			"\n"

			"static void OnAfterTest( const temperTestInfo_t* testInfo )\n"
			"{\n"
			"\tif ( testInfo->testingFlag == TEMPER_FLAG_SHOULD_SKIP )\n"
			"\t{\n"
			"\t\tTemperSetTextColorInternal( TEMPERDEV_COLOR_YELLOW );\n"
			"\t\tprintf( \"SKIPPED\\n\" );\n"
			"\t\tTemperSetTextColorInternal( TEMPERDEV_COLOR_DEFAULT );\n"
			"\t}\n"
			"\telse\n"
			"\t{\n"
			"\t\tif ( g_temperTestContext.currentTestErrorCount == 0 )\n"
			"\t\t{\n"
			"\t\t\tTemperSetTextColorInternal( TEMPERDEV_COLOR_GREEN );\n"
			"\t\t\tprintf( \"OK\" );\n"
			"\t\t\tTemperSetTextColorInternal( TEMPERDEV_COLOR_DEFAULT );\n"
			"\t\t}\n"
			"\t\telse\n"
			"\t\t{\n"
			"\t\t\tTemperSetTextColorInternal( TEMPERDEV_COLOR_RED );\n"
			"\t\t\tprintf( \"FAILED\\n\" );\n"
			"\t\t\tTemperSetTextColorInternal( TEMPERDEV_COLOR_DEFAULT );\n"
			"\t\t}\n"
			"\n"
			"\t\tprintf( \" (%f %s)\\n\", testInfo->testTimeTaken, TemperGetTimeUnitStringInternal( g_temperTestContext.timeUnit ) );\n"
			"\t}\n"
			"}\n"
			"\n"

			"int main( int argc, char** argv )\n"
			"{\n"
			"\tg_temperTestContext.callbacks.OnBeforeTest = OnBeforeTest;\n"
			"\tg_temperTestContext.callbacks.OnAfterTest = OnAfterTest;\n"
			"\n"
			"\tTEMPER_RUN( argc, argv );\n"
			"\n"
			"\treturn TEMPER_GET_EXIT_CODE();\n"
			"}\n"
		);

		const char* filePathMain = String_TPrintf( tempStorage, "%s/test_main.%s", generatedTestsPath, languageName );

		FS_WriteEntireFile( filePathMain, sb->str, sb->length );

		printf( "OK.\n" );
	}

	printf( "\n" );
}
