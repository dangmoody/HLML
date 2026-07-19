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

#include "tests_shared.h"

#include "common_names.h"

#include "file_io.h"
#include "defines.h"
#include "stb_local.h"
#include "string_builder.h"
#include "string_helpers.h"
#include "linear_allocator.h"

#include <stdio.h>
#include <assert.h>
#include <math.h>

void Gen_GenerateTests( allocatorLinear_t *tempStorage,
						const char *languageName,
						const typeInfo_t *vectorTypeInfos, const u32 vectorTypeInfosCount,
						const typeInfo_t *quaternionTypeInfos, const u32 quaternionTypeInfosCount,
						const typeInfo_t *matrixTypeInfos, const u32 matrixTypeInfosCount,
						const generatorStrings_t *strings,
						const generatorFlags_t flags,
						const u32 componentCountMin, const u32 componentCountMax )
{
	assert( tempStorage );
	assert( languageName );
	assert( vectorTypeInfos );
	assert( vectorTypeInfosCount );
	assert( ( quaternionTypeInfosCount == 0 ) == ( quaternionTypeInfos == NULL ) );
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

		const char *typeString = Gen_GetTypeString( type );

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

		stringBuilder_t *code = StringBuilder_Create( tempStorage, KILOBYTES( 16 ) );

		StringBuilder_Append( code, GEN_FILE_HEADER );

		Gen_AppendTestFileIncludes( tempStorage, code, languageName, flags );

		// the "true" below (generateQuaternions) is never read for a scalar typeInfo: GenerateComponentWiseTests
		// only checks it inside its quaternion test block, which is itself gated behind
		// Gen_TypeIsVector( typeInfo ) and so never runs here - see tests_shared.c
		GenerateComponentWiseTests( tempStorage, code, &typeInfo, &typeInfo, strings, flags, true );

		const char *fileNameHeader = String_TPrintf( tempStorage, "%s/test_%s.%s", generatedTestsPath, typeString, languageName );
		FS_WriteEntireFile( fileNameHeader, code->str, code->length );

		printf( "OK.\n" );

		Mem_Reset( tempStorage );
	}

	GenerateVectorTests( tempStorage, generatedTestsPath, languageName, vectorTypeInfos, vectorTypeInfosCount, strings, flags, componentCountMin, componentCountMax, quaternionTypeInfosCount > 0 );
	if ( quaternionTypeInfosCount > 0 ) {
		// NB: intentionally passes vectorTypeInfos, not quaternionTypeInfos - matches pre-existing
		// behavior where quaternion tests are generated per vector type, not just the two "true"
		// quaternion-qualifying types.  Only gated here on quaternionTypeInfosCount so that disabling
		// quaternions via config actually suppresses this output.
		GenerateQuaternionTests( tempStorage, generatedTestsPath, languageName, vectorTypeInfos, vectorTypeInfosCount, strings, flags );
	}
	GenerateMatrixTests( tempStorage, generatedTestsPath, languageName, matrixTypeInfos, matrixTypeInfosCount, strings, flags );

	// generate test_main
	{
		printf( "Generating test_main.%s...", languageName );

		stringBuilder_t *sb = StringBuilder_Create( tempStorage, KILOBYTES( 10 ) );

		StringBuilder_Append( sb,
			GEN_FILE_HEADER
			"#define NOMINMAX\n"
			"\n"

			"#define TEMPER_IMPLEMENTATION\n"
			"#include <temper/temper.h>\n"
			"\n"
		);

		//if ( flags & GENERATOR_FLAG_ALLOW_NAMESPACE ) {
		//	StringBuilder_Append( sb, "#ifdef HLML_NAMESPACE\n" );
		//	StringBuilder_Append( sb, "#define HLML_NAMESPACE\n" );
		//	StringBuilder_Append( sb, "#endif\n");
		//}
		StringBuilder_Appendf( sb, "#include \"../../../%s/%s\"\n\n", generatedCodePath, GEN_HEADER_MAIN );

		if ( flags & GENERATOR_FLAG_ALLOW_NAMESPACE ) {
			StringBuilder_Append( sb,
				"#ifdef HLML_NAMESPACE\n"
				"using namespace hlml;\n"
				"#endif\n"
				"\n"
			);
		}

		StringBuilder_Append( sb, "TEMPER_TEST( Test_TypeSizes, TEMPER_FLAG_SHOULD_RUN )\n" );
		StringBuilder_Append( sb, "{\n" );

		for ( u32 i = 0; i < vectorTypeInfosCount; i++ ) {
			const typeInfo_t *typeInfo = &vectorTypeInfos[i];

			u32 sizeBytes = typeInfo->numRows * typeInfo->numCols * Gen_GetTypeBytes( typeInfo->type );

			StringBuilder_Appendf( sb, "\tTEMPER_CHECK_TRUE( sizeof( %s ) == %d );\n", typeInfo->fullTypeName, sizeBytes );
		}
		StringBuilder_Append( sb, "\n" );

		for ( u32 i = 0; i < matrixTypeInfosCount; i++ ) {
			const typeInfo_t *typeInfo = &matrixTypeInfos[i];

			u32 sizeBytes = typeInfo->numRows * typeInfo->numCols * Gen_GetTypeBytes( typeInfo->type );

			StringBuilder_Appendf( sb, "\tTEMPER_CHECK_TRUE( sizeof( %s ) == %d );\n", typeInfo->fullTypeName, sizeBytes );
		}

		StringBuilder_Append( sb, "}\n\n" );

		StringBuilder_Append( sb,
			"#define TEST_PADDING \"................................................................\"\n"
			"\n"

			"static void OnBeforeTest( const temperTestInfo_t *testInfo )\n"
			"{\n"
			"\tconst int padLengthMax = (int) strlen( TEST_PADDING );\n"
			"\n"
			"\tconst int dotLength = padLengthMax - (int) strlen( testInfo->testNameStr );\n"
			"\tassert( dotLength );\n"
			"\n"
			"\tprintf( \"%s %*.*s \", testInfo->testNameStr, dotLength, dotLength, TEST_PADDING );\n"
			"}\n"
			"\n"

			"static void OnAfterTest( const temperTestInfo_t *testInfo )\n"
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

			"int main( int argc, char **argv )\n"
			"{\n"
			"\tg_temperTestContext.callbacks.OnBeforeTest = OnBeforeTest;\n"
			"\tg_temperTestContext.callbacks.OnAfterTest = OnAfterTest;\n"
			"\n"
			"\tTEMPER_RUN( argc, argv );\n"
			"\n"
			"\treturn TEMPER_GET_EXIT_CODE();\n"
			"}\n"
		);

		const char *filePathMain = String_TPrintf( tempStorage, "%s/test_main.%s", generatedTestsPath, languageName );

		FS_WriteEntireFile( filePathMain, sb->str, sb->length );

		printf( "OK.\n" );
	}

	printf( "\n" );
}
