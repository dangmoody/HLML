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

#include "gen_shared.c"
#include "common_names.h"

#include "string_helpers.h"
#include "file_io.h"
#include "defines.h"

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#include "gen_scalar.c"
#include "gen_vector.c"
#include "gen_quaternion.c"
#include "gen_matrix.c"

#include "gen_scalar_sse.c"
#include "gen_vector_sse.c"

static void GenerateMainHeader(
	allocatorLinear_t* tempStorage,
	const char* generatedCodePath,
	const typeInfo_t* vectorTypeInfos, const u32 vectorTypeInfosCount,
	const typeInfo_t* matrixTypeInfos, const u32 matrixTypeInfosCount,
	const generatorFlags_t flags )
{
	assert( tempStorage );
	assert( generatedCodePath );
	assert( vectorTypeInfos );
	assert( vectorTypeInfosCount );
	assert( matrixTypeInfos );
	assert( matrixTypeInfosCount );

	printf( "Generating \"%s/%s\"...", generatedCodePath, GEN_HEADER_MAIN );

	stringBuilder_t* code = StringBuilder_Create( tempStorage, KILOBYTES( 4 ) );

	bool32 cLinkage = flags & GENERATOR_FLAG_C_LINKAGE;
	bool32 generateConstructors = flags & GENERATOR_FLAG_GENERATE_CONSTRUCTORS;
	bool32 generateOperators = flags & GENERATOR_FLAG_GENERATE_OPERATORS;

	bool32 generateInlFile = generateConstructors || generateOperators;

	StringBuilder_Append( code, "#pragma once\n\n" );

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef __cplusplus\n"
			"extern \"C\" {\n"
			"#endif\n\n"
		);
	}

	// vectors
	for ( u32 i = 0; i < vectorTypeInfosCount; i++ ) {
		const typeInfo_t* typeInfo = &vectorTypeInfos[i];

		StringBuilder_Appendf( code, "#include \"%s.h\"\n", typeInfo->fullTypeName );
	}
	StringBuilder_Appendf( code, "\n" );

	if ( generateInlFile ) {
		for ( u32 i = 0; i < vectorTypeInfosCount; i++ ) {
			const typeInfo_t* typeInfo = &vectorTypeInfos[i];

			StringBuilder_Appendf( code, "#include \"%s.inl\"\n", typeInfo->fullTypeName );
		}

		StringBuilder_Appendf( code, "\n" );
	}

	// matrices
	for ( u32 i = 0; i < matrixTypeInfosCount; i++ ) {
		const typeInfo_t* typeInfo = &matrixTypeInfos[i];

		StringBuilder_Appendf( code, "#include \"%s.h\"\n", typeInfo->fullTypeName );
	}
	StringBuilder_Appendf( code, "\n" );

	if ( generateInlFile ) {
		for ( u32 i = 0; i < matrixTypeInfosCount; i++ ) {
			const typeInfo_t* typeInfo = &matrixTypeInfos[i];

			StringBuilder_Appendf( code, "#include \"%s.inl\"\n", typeInfo->fullTypeName );
		}
		StringBuilder_Appendf( code, "\n" );
	}

	// function file includes
	StringBuilder_Appendf( code, "#include \"%s.h\"\n", GEN_FILENAME_FUNCTIONS_SCALAR );
	StringBuilder_Appendf( code, "#include \"%s.h\"\n", GEN_FILENAME_FUNCTIONS_SCALAR_SSE );
	StringBuilder_Appendf( code, "#include \"%s.h\"\n", GEN_FILENAME_FUNCTIONS_VECTOR );
	StringBuilder_Appendf( code, "#include \"%s.h\"\n", GEN_FILENAME_FUNCTIONS_VECTOR_SSE );
	StringBuilder_Appendf( code, "#include \"%s.h\"\n", GEN_FILENAME_FUNCTIONS_QUATERNION );
	StringBuilder_Appendf( code, "#include \"%s.h\"\n", GEN_FILENAME_FUNCTIONS_MATRIX );
	StringBuilder_Appendf( code, "\n" );

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n"
		);
	}

	const char* filePathHeader = String_TPrintf( tempStorage, "%s/%s", generatedCodePath, GEN_HEADER_MAIN );

	FS_WriteEntireFile( filePathHeader, code->str, code->length );

	Mem_Reset( tempStorage );

	printf( "OK.\n" );
}

static void GenerateTypesHeader( allocatorLinear_t* tempStorage, const char* generatedCodePath ) {
	assert( tempStorage );
	assert( generatedCodePath );

	printf( "Generating \"%s/%s\"...", generatedCodePath, GEN_HEADER_TYPES );

	stringBuilder_t* code = StringBuilder_Create( tempStorage, KILOBYTES( 2 ) );

	StringBuilder_Append( code,
		GEN_FILE_HEADER
		"#pragma once\n"
		"\n"

		"#ifdef __cplusplus\n"
		"extern \"C\" {\n"
		"#endif\n"
		"\n"

		"#include <stdint.h>\n"
		"\n"

		"// ensure that a bool is 4 bytes\n"
		"typedef uint32_t bool32_t;\n"
		"\n"

		"#ifdef __cplusplus\n"
		"}\n"
		"#endif\n"
	);

	const char* filePathHeader = String_TPrintf( tempStorage, "%s/%s", generatedCodePath, GEN_HEADER_TYPES );

	FS_WriteEntireFile( filePathHeader, code->str, code->length );

	printf( "OK.\n" );

	Mem_Reset( tempStorage );
}

static void GenerateConstantsHeader( allocatorLinear_t* tempStorage, const char* generatedCodePath ) {
	assert( tempStorage );
	assert( generatedCodePath );

	printf( "Generating \"%s/%s\"...", generatedCodePath, GEN_HEADER_CONSTANTS );

	stringBuilder_t* code = StringBuilder_Create( tempStorage, KILOBYTES( 2 ) );

	StringBuilder_Append( code,
		GEN_FILE_HEADER
		"#pragma once\n"
		"\n"

		"#ifdef __cplusplus\n"
		"extern \"C\" {\n"
		"#endif\n"
		"\n"

		"// constants generated by wolfram alpha\n"
		"#define HLML_PI\t\t\t3.14159265358979323846\n"
		"#define HLML_TAU\t\t6.28318530717958647693\n"
		"\n"

		"#define HLML_EPSILON\t1e-5\n"
		"\n"

		"#define HLML_ROOT_2\t\t1.41421356237309504880\n"
		"\n"

		"#ifdef __cplusplus\n"
		"}\n"
		"#endif\n"
	);

	const char* filePathHeader = String_TPrintf( tempStorage, "%s/%s", generatedCodePath, GEN_HEADER_CONSTANTS );

	FS_WriteEntireFile( filePathHeader, code->str, code->length );

	printf( "OK.\n" );

	Mem_Reset( tempStorage );
}

static void GenerateDefinesHeader( allocatorLinear_t* tempStorage, const char* generatedCodePath ) {
	assert( tempStorage );
	assert( generatedCodePath );

	printf( "Generating \"%s/%s\"...", generatedCodePath, GEN_HEADER_DEFINES );

	stringBuilder_t* code = StringBuilder_Create( tempStorage, KILOBYTES( 2 ) );

	StringBuilder_Append( code,
		GEN_FILE_HEADER
		"#pragma once\n"
		"\n"

		"#ifdef __cplusplus\n"
		"extern \"C\" {\n"
		"#endif\n"
		"\n"

		"#ifdef __cplusplus\n"
		"#define HLML_CONSTRUCT( type ) type\n"
		"#else\n"
		"#define HLML_CONSTRUCT( type ) (type)\n"
		"#endif\n"
		"\n"

		"#ifndef HLML_ASSERT\n"
		"#include <assert.h>\n"
		"#define HLML_ASSERT assert\n"
		"#endif\n"
		"\n"

		"#ifndef HLML_INLINE\n"
		"// GCC inline semantics for C99 dont work the same way other compilers\n"
		"// https://gcc.gnu.org/gcc-5/porting_to.html\n"
		"#if !defined( __cplusplus ) && defined( __GNUC__ )\n"
		"#define HLML_INLINE extern inline\n"
		"#else\n"
		"#define HLML_INLINE inline\n"
		"#endif\n"
		"#endif\n"
		"\n"

		"#ifdef __cplusplus\n"
		"}\n"
		"#endif\n"
	);

	const char* filePathHeader = String_TPrintf( tempStorage, "%s/%s", generatedCodePath, GEN_HEADER_DEFINES );

	FS_WriteEntireFile( filePathHeader, code->str, code->length );

	printf( "OK.\n" );

	Mem_Reset( tempStorage );
}

static void GenerateSSEConstantsHeader( allocatorLinear_t* tempStorage, const char* generatedCodePath ) {
	assert( tempStorage );
	assert( generatedCodePath );

	printf( "Generating \"%s/%s\"...", generatedCodePath, GEN_HEADER_CONSTANTS_SSE );

	stringBuilder_t* code = StringBuilder_Create( tempStorage, KILOBYTES( 2 ) );

	StringBuilder_Append( code,
		GEN_FILE_HEADER
		"#pragma once\n"
		"\n"

		"#ifdef __cplusplus\n"
		"extern \"C\" {\n"
		"#endif\n"
		"\n"
	);

	StringBuilder_Append( code,
		"#define HLML_ZERO_SSE _mm_set1_ps( 0.0f )\n"
		"#define HLML_ONE_SSE _mm_set1_ps( 1.0f )\n"
		"\n"

		"#define HLML_RAD_TO_DEG_SSE _mm_set1_ps( 57.2957795130823208768f )\n"
		"#define HLML_DEG_TO_RAD_SSE _mm_set1_ps( 0.01745329251994329577f )\n"
		"\n"
	);

	StringBuilder_Append( code,
		"#ifdef __cplusplus\n"
		"}\n"
		"#endif\n"
	);

	const char* filePathHeader = String_TPrintf( tempStorage, "%s/%s", generatedCodePath, GEN_HEADER_CONSTANTS_SSE );

	FS_WriteEntireFile( filePathHeader, code->str, code->length );

	printf( "OK.\n" );

	Mem_Reset( tempStorage );
}

static void GenerateAPIFiles( allocatorLinear_t* tempStorage,
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
	assert( matrixTypeInfos );
	assert( matrixTypeInfosCount );

	printf( "Generating API files for \"%s\"...\n", languageName );

	char generatedCodePath[1024] = { 0 };
	stbsp_snprintf( generatedCodePath, 1024, "%s%s", GEN_GENERATED_CODE_PATH, languageName );

	FS_CreateFolder( generatedCodePath );

	GenerateMainHeader( tempStorage, generatedCodePath, vectorTypeInfos, vectorTypeInfosCount, matrixTypeInfos, matrixTypeInfosCount, flags );
	GenerateTypesHeader( tempStorage, generatedCodePath );
	GenerateConstantsHeader( tempStorage, generatedCodePath );
	GenerateDefinesHeader( tempStorage, generatedCodePath );
	GenerateSSEConstantsHeader( tempStorage, generatedCodePath );

	GenerateScalarFiles( tempStorage, generatedCodePath, flags );
	GenerateScalarFiles_SSE( tempStorage, generatedCodePath, strings, flags );
	GenerateVectorFiles( tempStorage, generatedCodePath, vectorTypeInfos, vectorTypeInfosCount, strings, flags );
	GenerateVectorFiles_SSE( tempStorage, generatedCodePath, vectorTypeInfos, vectorTypeInfosCount, strings, flags );
	GenerateQuaternionFiles( tempStorage, generatedCodePath, quaternionTypeInfos, quaternionTypeInfosCount, strings, flags );
	GenerateMatrixFiles( tempStorage, generatedCodePath, matrixTypeInfos, matrixTypeInfosCount, strings, flags );

	printf( "\n" );
}