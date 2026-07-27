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

#include "gen_api.h"

#include "gen_shared.h"

#include "common_names.h"
#include "string_helpers.h"
#include "file_io.h"
#include "defines.h"
#include "string_builder.h"
#include "linear_allocator.h"

#include "stb_local.h"

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

static void GenerateMainHeader(
	allocatorLinear_t *tempStorage,
	const char *generatedCodePath,
	const typeInfo_t *vectorTypeInfos, const u32 vectorTypeInfosCount,
	const typeInfo_t *matrixTypeInfos, const u32 matrixTypeInfosCount,
	const u32 quaternionTypeInfosCount,
	const generatorFlags_t flags )
{
	assert( tempStorage );
	assert( generatedCodePath );
	assert( vectorTypeInfos );
	assert( vectorTypeInfosCount );
	assert( matrixTypeInfos );
	assert( matrixTypeInfosCount );

	printf( "Generating \"%s/%s\"...", generatedCodePath, GEN_HEADER_MAIN );

	bool32 cLinkage = flags & GENERATOR_FLAG_C_LINKAGE;
	bool32 generateConstructors = flags & GENERATOR_FLAG_GENERATE_CONSTRUCTORS;
	bool32 generateOperators = flags & GENERATOR_FLAG_GENERATE_OPERATORS;
	bool32 generateSSE = flags & GENERATOR_FLAG_GENERATE_SSE;

	bool32 generateInlFile = generateConstructors || generateOperators;

	stringBuilder_t *code = StringBuilder_Create( tempStorage, KILOBYTES( 4 ) );

	Gen_AppendGeneratedHeaderComment( code, flags );

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
		const typeInfo_t *typeInfo = &vectorTypeInfos[i];

		StringBuilder_Appendf( code, "#include \"%s.h\"\n", typeInfo->fullTypeName );
	}
	StringBuilder_Appendf( code, "\n" );

	if ( generateInlFile ) {
		for ( u32 i = 0; i < vectorTypeInfosCount; i++ ) {
			const typeInfo_t *typeInfo = &vectorTypeInfos[i];

			StringBuilder_Appendf( code, "#include \"%s.inl\"\n", typeInfo->fullTypeName );
		}

		StringBuilder_Appendf( code, "\n" );
	}

	// matrices
	for ( u32 i = 0; i < matrixTypeInfosCount; i++ ) {
		const typeInfo_t *typeInfo = &matrixTypeInfos[i];

		StringBuilder_Appendf( code, "#include \"%s.h\"\n", typeInfo->fullTypeName );
	}
	StringBuilder_Appendf( code, "\n" );

	if ( generateInlFile ) {
		for ( u32 i = 0; i < matrixTypeInfosCount; i++ ) {
			const typeInfo_t *typeInfo = &matrixTypeInfos[i];

			StringBuilder_Appendf( code, "#include \"%s.inl\"\n", typeInfo->fullTypeName );
		}
		StringBuilder_Appendf( code, "\n" );
	}

	// function file includes
	StringBuilder_Appendf( code, "#include \"%s.h\"\n", GEN_FILENAME_FUNCTIONS_SCALAR );
	if ( generateSSE ) {
		StringBuilder_Appendf( code, "#include \"%s.h\"\n", GEN_FILENAME_FUNCTIONS_SCALAR_SSE );
	}
	StringBuilder_Appendf( code, "#include \"%s.h\"\n", GEN_FILENAME_FUNCTIONS_VECTOR );
	if ( generateSSE ) {
		StringBuilder_Appendf( code, "#include \"%s.h\"\n", GEN_FILENAME_FUNCTIONS_VECTOR_SSE );
	}
	if ( quaternionTypeInfosCount > 0 ) {
		StringBuilder_Appendf( code, "#include \"%s.h\"\n", GEN_FILENAME_FUNCTIONS_QUATERNION );
	}
	StringBuilder_Appendf( code, "#include \"%s.h\"\n", GEN_FILENAME_FUNCTIONS_MATRIX );
	StringBuilder_Appendf( code, "\n" );

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n"
		);
	}

	const char *filePathHeader = String_TPrintf( tempStorage, "%s/%s", generatedCodePath, GEN_HEADER_MAIN );

	FS_WriteEntireFile( filePathHeader, code->str, code->length );

	Mem_Reset( tempStorage );

	printf( "OK.\n" );
}

static void GenerateTypesHeader( allocatorLinear_t *tempStorage, const char *generatedCodePath, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( generatedCodePath );

	printf( "Generating \"%s/%s\"...", generatedCodePath, GEN_HEADER_TYPES );

	bool32 cLinkage = flags & GENERATOR_FLAG_C_LINKAGE;

	stringBuilder_t *code = StringBuilder_Create( tempStorage, KILOBYTES( 2 ) );

	Gen_AppendGeneratedHeaderComment( code, flags );

	StringBuilder_Append( code,
		"#pragma once\n"
		"\n"
	);

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef __cplusplus\n"
			"extern \"C\" {\n"
			"#endif\n"
			"\n"
		);
	}

	StringBuilder_Append( code,
		"#include <stdint.h>\n"
		"\n"

		"// ensure that a bool is 4 bytes\n"
		"typedef uint32_t bool32_t;\n"
		"\n"
	);

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n"
		);
	}

	const char *filePathHeader = String_TPrintf( tempStorage, "%s/%s", generatedCodePath, GEN_HEADER_TYPES );

	FS_WriteEntireFile( filePathHeader, code->str, code->length );

	printf( "OK.\n" );

	Mem_Reset( tempStorage );
}

static void GenerateConstantsHeader( allocatorLinear_t *tempStorage, const char *generatedCodePath, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( generatedCodePath );

	printf( "Generating \"%s/%s\"...", generatedCodePath, GEN_HEADER_CONSTANTS );

	bool32 cLinkage = flags & GENERATOR_FLAG_C_LINKAGE;

	stringBuilder_t *code = StringBuilder_Create( tempStorage, KILOBYTES( 2 ) );

	Gen_AppendGeneratedHeaderComment( code, flags );

	StringBuilder_Append( code,
		"#pragma once\n"
		"\n"
	);

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef __cplusplus\n"
			"extern \"C\" {\n"
			"#endif\n"
			"\n"
		);
	}

	StringBuilder_Append( code,
		"// constants generated by wolfram alpha\n"
		"#define HLML_PI\t\t\t3.14159265358979323846\n"
		"#define HLML_TAU\t\t6.28318530717958647693\n"
		"\n"

		"#define HLML_EPSILON\t1e-5\n"
		"\n"

		"#define HLML_ROOT_2\t\t1.41421356237309504880\n"
		"\n"
	);

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n"
		);
	}

	const char *filePathHeader = String_TPrintf( tempStorage, "%s/%s", generatedCodePath, GEN_HEADER_CONSTANTS );

	FS_WriteEntireFile( filePathHeader, code->str, code->length );

	printf( "OK.\n" );

	Mem_Reset( tempStorage );
}

static void GenerateDefinesHeader( allocatorLinear_t *tempStorage, const char *generatedCodePath, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( generatedCodePath );

	printf( "Generating \"%s/%s\"...", generatedCodePath, GEN_HEADER_DEFINES );

	bool32 cLinkage = flags & GENERATOR_FLAG_C_LINKAGE;

	stringBuilder_t *code = StringBuilder_Create( tempStorage, KILOBYTES( 2 ) );

	Gen_AppendGeneratedHeaderComment( code, flags );

	StringBuilder_Append( code,
		"#pragma once\n"
		"\n"
	);

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef __cplusplus\n"
			"extern \"C\" {\n"
			"#endif\n"
			"\n"
		);
	}

	StringBuilder_Append( code,
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
	);

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n"
		);
	}

	const char *filePathHeader = String_TPrintf( tempStorage, "%s/%s", generatedCodePath, GEN_HEADER_DEFINES );

	FS_WriteEntireFile( filePathHeader, code->str, code->length );

	printf( "OK.\n" );

	Mem_Reset( tempStorage );
}

static void GenerateSSEConstantsHeader( allocatorLinear_t *tempStorage, const char *generatedCodePath, const generatorFlags_t flags ) {
	assert( tempStorage );
	assert( generatedCodePath );

	printf( "Generating \"%s/%s\"...", generatedCodePath, GEN_HEADER_CONSTANTS_SSE );

	bool cLinkage = flags & GENERATOR_FLAG_C_LINKAGE;

	stringBuilder_t *code = StringBuilder_Create( tempStorage, KILOBYTES( 2 ) );

	Gen_AppendGeneratedHeaderComment( code, flags );

	StringBuilder_Append( code,
		"#pragma once\n"
		"\n"
	);

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef __cplusplus\n"
			"extern \"C\" {\n"
			"#endif\n"
			"\n"
		);
	}

	StringBuilder_Append( code,
		"#define HLML_ZERO_SSE _mm_set1_ps( 0.0f )\n"
		"#define HLML_ONE_SSE _mm_set1_ps( 1.0f )\n"
		"\n"

		"#define HLML_RAD_TO_DEG_SSE _mm_set1_ps( 57.2957795130823208768f )\n"
		"#define HLML_DEG_TO_RAD_SSE _mm_set1_ps( 0.01745329251994329577f )\n"
		"\n"
	);

	if ( cLinkage ) {
		StringBuilder_Append( code,
			"#ifdef __cplusplus\n"
			"}\n"
			"#endif\n"
		);
	}

	const char *filePathHeader = String_TPrintf( tempStorage, "%s/%s", generatedCodePath, GEN_HEADER_CONSTANTS_SSE );

	FS_WriteEntireFile( filePathHeader, code->str, code->length );

	printf( "OK.\n" );

	Mem_Reset( tempStorage );
}

void Gen_GenerateAPIFiles( allocatorLinear_t *tempStorage,
						   const char *outputPath,
						   const char *languageName,
						   const typeInfo_t *vectorTypeInfos, const u32 vectorTypeInfosCount,
						   const typeInfo_t *quaternionTypeInfos, const u32 quaternionTypeInfosCount,
						   const typeInfo_t *matrixTypeInfos, const u32 matrixTypeInfosCount,
						   const generatorStrings_t *strings,
						   const generatorFlags_t flags,
						   const u32 componentCountMin, const u32 componentCountMax )
{
	assert( tempStorage );
	assert( outputPath );
	assert( languageName );
	assert( vectorTypeInfos );
	assert( vectorTypeInfosCount );
	assert( matrixTypeInfos );
	assert( matrixTypeInfosCount );

	printf( "Generating API files for \"%s\"...\n", languageName );

	const char *generatedCodePath = outputPath;

	FS_CreateFolder( generatedCodePath );

	// hlml_types.h only exists to provide bool32_t for bool-typed vectors/matrices (see the matching
	// include-guard in GenerateVectorFiles in gen_vector.c) - skip it entirely if "bool" was excluded from
	// "scalar_types" in the config, since nothing would reference it.
	bool32 generateBoolType = false;
	for ( u32 i = 0; i < vectorTypeInfosCount; i++ ) {
		if ( vectorTypeInfos[i].type == GEN_TYPE_BOOL ) {
			generateBoolType = true;
			break;
		}
	}

	GenerateMainHeader( tempStorage, generatedCodePath, vectorTypeInfos, vectorTypeInfosCount, matrixTypeInfos, matrixTypeInfosCount, quaternionTypeInfosCount, flags );
	if ( generateBoolType ) {
		GenerateTypesHeader( tempStorage, generatedCodePath, flags );
	}
	GenerateConstantsHeader( tempStorage, generatedCodePath, flags );
	GenerateDefinesHeader( tempStorage, generatedCodePath, flags );

	GenerateScalarFiles( tempStorage, generatedCodePath, flags );
	GenerateVectorFiles( tempStorage, generatedCodePath, vectorTypeInfos, vectorTypeInfosCount, strings, flags, componentCountMin, componentCountMax );

	if ( flags & GENERATOR_FLAG_GENERATE_SSE ) {
		GenerateSSEConstantsHeader( tempStorage, generatedCodePath, flags );
		GenerateScalarFiles_SSE( tempStorage, generatedCodePath, flags );
		GenerateVectorFiles_SSE( tempStorage, generatedCodePath, vectorTypeInfos, vectorTypeInfosCount, strings, flags );
	}

	if ( quaternionTypeInfosCount > 0 ) {
		GenerateQuaternionFiles( tempStorage, generatedCodePath, quaternionTypeInfos, quaternionTypeInfosCount, strings, flags );
	}
	GenerateMatrixFiles( tempStorage, generatedCodePath, matrixTypeInfos, matrixTypeInfosCount, strings, flags );

	printf( "\n" );
}
