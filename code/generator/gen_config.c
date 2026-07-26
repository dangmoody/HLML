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

#include "gen_config.h"

#include "int_types.h"
#include "defines.h"
#include "file_io.h"
#include "linear_allocator.h"
#include "string_helpers.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#include "tomlc99/toml.h"
#pragma clang diagnostic pop

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


typedef struct genConfigFlagMapping_t {
	const char			*key;
	generatorFlagBits_t	bit;
} genConfigFlagMapping_t;

static const genConfigFlagMapping_t s_flagMappings[] = {
	{ "parms_are_pointers",		GENERATOR_FLAG_PARMS_ARE_POINTERS },
	{ "c_linkage",					GENERATOR_FLAG_C_LINKAGE },
	{ "generate_operators",			GENERATOR_FLAG_GENERATE_OPERATORS },
	{ "name_mangling",				GENERATOR_FLAG_NAME_MANGLING },
	{ "vector_unions",				GENERATOR_FLAG_VECTOR_UNIONS },
	{ "generate_constructors",		GENERATOR_FLAG_GENERATE_CONSTRUCTORS },
	{ "vector_swizzles",			GENERATOR_FLAG_VECTOR_SWIZZLES },
	{ "allow_namespace",			GENERATOR_FLAG_ALLOW_NAMESPACE },
	{ "generate_relational_operators",	GENERATOR_FLAG_GENERATE_RELATIONAL_OPERATORS },
	{ "generate_quaternions",			GENERATOR_FLAG_GENERATE_QUATERNIONS },
	{ "generate_non_square_matrices",	GENERATOR_FLAG_GENERATE_NON_SQUARE_MATRICES },
	{ "generate_sse",					GENERATOR_FLAG_GENERATE_SSE },
	{ "generate_rgba",					GENERATOR_FLAG_GENERATE_RGBA },
	{ "generate_assignment_operator",	GENERATOR_FLAG_GENERATE_ASSIGNMENT_OPERATOR },
	{ "suppress_anonymous_struct_warnings",	GENERATOR_FLAG_SUPPRESS_ANONYMOUS_STRUCT_WARNINGS },
	{ "braces_same_line",				GENERATOR_FLAG_BRACES_SAME_LINE },
};

static generatorFlags_t GetDefaultFlagsForLanguage( const genLanguage_t language ) {
	switch ( language ) {
		case GEN_LANGUAGE_C:	return GENERATOR_FLAG_PARMS_ARE_POINTERS | GENERATOR_FLAG_C_LINKAGE | GENERATOR_FLAG_GENERATE_RELATIONAL_OPERATORS | GENERATOR_FLAG_GENERATE_QUATERNIONS | GENERATOR_FLAG_GENERATE_NON_SQUARE_MATRICES | GENERATOR_FLAG_GENERATE_SSE | GENERATOR_FLAG_SUPPRESS_ANONYMOUS_STRUCT_WARNINGS;
		case GEN_LANGUAGE_CPP:	return GENERATOR_FLAG_GENERATE_OPERATORS | GENERATOR_FLAG_NAME_MANGLING | GENERATOR_FLAG_VECTOR_UNIONS | GENERATOR_FLAG_GENERATE_CONSTRUCTORS | GENERATOR_FLAG_VECTOR_SWIZZLES | GENERATOR_FLAG_ALLOW_NAMESPACE | GENERATOR_FLAG_GENERATE_RELATIONAL_OPERATORS | GENERATOR_FLAG_GENERATE_QUATERNIONS | GENERATOR_FLAG_GENERATE_NON_SQUARE_MATRICES | GENERATOR_FLAG_GENERATE_SSE | GENERATOR_FLAG_GENERATE_RGBA | GENERATOR_FLAG_GENERATE_ASSIGNMENT_OPERATOR | GENERATOR_FLAG_SUPPRESS_ANONYMOUS_STRUCT_WARNINGS;

		case GEN_LANGUAGE_NONE:
		case GEN_LANGUAGE_COUNT:
			break;
	}

	assert( false && "Bad genLanguage_t passed in!\n" );

	return 0;
}

static void ApplyGenerateFlagsFromTable( const toml_table_t *configTable, generatorFlags_t *outFlags ) {
	assert( outFlags );

	if ( !configTable ) {
		return;
	}

	for ( u32 i = 0; i < GEN_COUNTOF( s_flagMappings ); i++ ) {
		toml_datum_t datum = toml_bool_in( configTable, s_flagMappings[i].key );
		if ( !datum.ok ) {
			continue;
		}

		if ( datum.u.b ) {
			*outFlags |= s_flagMappings[i].bit;
		} else {
			*outFlags &= ~s_flagMappings[i].bit;
		}
	}
}

void Gen_Config_SetDefaults( genConfig_t *outConfig ) {
	assert( outConfig );

	memset( outConfig, 0, sizeof( genConfig_t ) );

	outConfig->language = GEN_LANGUAGE_NONE;

	for ( u32 i = 0; i < GEN_TYPE_COUNT; i++ ) {
		outConfig->scalarTypeEnabled[i] = true;
	}

	outConfig->componentCountMin = GEN_CONFIG_COMPONENT_COUNT_MIN;
	outConfig->componentCountMax = GEN_CONFIG_COMPONENT_COUNT_MAX;

	outConfig->outputPath = GEN_CONFIG_OUTPUT_PATH_DEFAULT;

	// outConfig->flags (which includes generateQuaternions/generateNonSquareMatrices now that they're
	// generatorFlagBits_t) is left at 0 - there's no language-agnostic default for it.  Gen_Config_LoadFromFile
	// seeds it via GetDefaultFlagsForLanguage() once it knows the language, before applying the top-level
	// flag overrides.
}

bool32 Gen_Config_LoadFromFile( const char *filename, genConfig_t *outConfig ) {
	assert( filename );
	assert( outConfig );

	u64 fileLength = 0;
	char *fileData = FS_ReadEntireFile( filename, &fileLength );

	if ( !fileData ) {
		printf( "ERROR: Couldn't find config file \"%s\".  Did you type the path correctly?\n", filename );

		return false;
	}

	GEN_UNUSED( fileLength );

	char errbuf[256] = { 0 };
	toml_table_t *root = toml_parse( fileData, errbuf, sizeof( errbuf ) );

	// toml_parse() doesn't keep references into fileData - see how toml_parse_file() itself frees its
	// duplicated buffer immediately after calling toml_parse() - so it's safe to free here regardless
	// of whether parsing succeeded.
	FS_FreeFileBuffer( fileData );
	fileData = NULL;

	if ( !root ) {
		printf( "ERROR: Failed to parse config file \"%s\": %s\n", filename, errbuf );

		return false;
	}

	// language
	{
		toml_datum_t languageDatum = toml_string_in( root, "language" );
		if ( !languageDatum.ok ) {
			printf( "ERROR: Missing required \"language\" key (must be \"c\" or \"cpp\") in \"%s\".\n", filename );

			toml_free( root );
			root = NULL;

			return false;
		}

		if ( String_Equals( languageDatum.u.s, "c" ) ) {
			outConfig->language = GEN_LANGUAGE_C;
		} else if ( String_Equals( languageDatum.u.s, "cpp" ) ) {
			outConfig->language = GEN_LANGUAGE_CPP;
		} else {
			printf( "ERROR: \"language\" must be \"c\" or \"cpp\", got \"%s\" in \"%s\".\n", languageDatum.u.s, filename );

			free( languageDatum.u.s );

			toml_free( root );
			root = NULL;

			return false;
		}

		free( languageDatum.u.s );

		outConfig->flags = GetDefaultFlagsForLanguage( outConfig->language );
	}

	// types (scalar_types, component_count_min/max)
	{
		toml_array_t *scalarTypesArray = toml_array_in( root, "scalar_types" );
		if ( scalarTypesArray ) {
			for ( u32 i = 0; i < GEN_TYPE_COUNT; i++ ) {
				outConfig->scalarTypeEnabled[i] = false;
			}

			int arrayCount = toml_array_nelem( scalarTypesArray );
			for ( int i = 0; i < arrayCount; i++ ) {
				toml_datum_t datum = toml_string_at( scalarTypesArray, i );
				assert( datum.ok );

				bool32 matched = false;

				for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
					if ( String_Equals( datum.u.s, Gen_GetTypeString( (genType_t) typeIndex ) ) ) {
						outConfig->scalarTypeEnabled[typeIndex] = true;
						matched = true;
						break;
					}
				}

				if ( !matched ) {
					printf( "ERROR: Unrecognized scalar type \"%s\" in \"scalar_types\" in \"%s\".\n", datum.u.s, filename );

					free( datum.u.s );

					toml_free( root );
					root = NULL;

					return false;
				}

				free( datum.u.s );
			}
		}

		toml_datum_t componentCountMinDatum = toml_int_in( root, "component_count_min" );
		if ( componentCountMinDatum.ok ) {
			outConfig->componentCountMin = (u32) componentCountMinDatum.u.i;
		}

		toml_datum_t componentCountMaxDatum = toml_int_in( root, "component_count_max" );
		if ( componentCountMaxDatum.ok ) {
			outConfig->componentCountMax = (u32) componentCountMaxDatum.u.i;
		}
	}

	// output_path
	{
		toml_datum_t outputPathDatum = toml_string_in( root, "output_path" );
		if ( outputPathDatum.ok ) {
			if ( outputPathDatum.u.s[0] == '\0' ) {
				printf( "ERROR: \"output_path\" cannot be empty in \"%s\".\n", filename );

				free( outputPathDatum.u.s );

				toml_free( root );
				root = NULL;

				return false;
			}

			// normalize away any trailing slash(es) - Gen_GenerateAPIFiles/Gen_GenerateTests and everything
			// downstream of them assume outputPath has no trailing slash
			size_t outputPathLength = strlen( outputPathDatum.u.s );
			while ( outputPathLength > 0 && outputPathDatum.u.s[outputPathLength - 1] == '/' ) {
				outputPathDatum.u.s[--outputPathLength] = '\0';
			}

			if ( outputPathLength == 0 ) {
				printf( "ERROR: \"output_path\" cannot be just a slash in \"%s\".\n", filename );

				free( outputPathDatum.u.s );

				toml_free( root );
				root = NULL;

				return false;
			}

			// ownership of this heap string transfers to outConfig - it lives for the rest of the process
			outConfig->outputPath = outputPathDatum.u.s;
		}
	}

	// generate flags (parms_are_pointers, c_linkage, generate_operators, ...)
	{
		ApplyGenerateFlagsFromTable( root, &outConfig->flags );
	}

	// relational operators (<, <=, >, >=) return a boolN/boolNxM type for every other vector/matrix type -
	// see GenerateComponentWiseOperators() in gen_shared.c - so "bool" can't be excluded from
	// "scalar_types" while "generate_relational_operators" is on.  Equality (==, !=) is unaffected: it
	// always returns a plain scalar bool, not a generated type, regardless of scalar_types.  Force bool
	// back on and tell them why, rather than silently dropping the request or failing to compile.
	if ( !outConfig->scalarTypeEnabled[GEN_TYPE_BOOL] && ( outConfig->flags & GENERATOR_FLAG_GENERATE_RELATIONAL_OPERATORS ) ) {
		printf( "NOTE: \"bool\" cannot be excluded from \"scalar_types\" while \"generate_relational_operators\" is enabled - relational operators on other types return bool vectors/matrices.  Generating it anyway.\n" );
		outConfig->scalarTypeEnabled[GEN_TYPE_BOOL] = true;
	}

	// validation - each of these is a normal, expected user error (a typo'd or contradictory config file),
	// not a programming bug, so report it clearly and let the caller exit gracefully rather than asserting
	{
		if ( ( outConfig->flags & GENERATOR_FLAG_C_LINKAGE ) && ( outConfig->flags & GENERATOR_FLAG_ALLOW_NAMESPACE ) ) {
			printf( "ERROR: \"c_linkage\" and \"allow_namespace\" cannot both be set in \"%s\" - namespaces are a C++ concept.\n", filename );

			toml_free( root );
			root = NULL;

			return false;
		}

		if ( ( outConfig->flags & GENERATOR_FLAG_GENERATE_RGBA ) && !( outConfig->flags & GENERATOR_FLAG_VECTOR_UNIONS ) ) {
			printf( "ERROR: \"generate_rgba\" requires \"vector_unions\" to be enabled in \"%s\" - rgba members live inside that union.\n", filename );

			toml_free( root );
			root = NULL;

			return false;
		}

		if ( outConfig->componentCountMin > outConfig->componentCountMax ) {
			printf( "ERROR: \"component_count_min\" (%u) is greater than \"component_count_max\" (%u) in \"%s\".\n",
				outConfig->componentCountMin, outConfig->componentCountMax, filename );

			toml_free( root );
			root = NULL;

			return false;
		}

		if ( outConfig->componentCountMin < GEN_CONFIG_COMPONENT_COUNT_MIN || outConfig->componentCountMax > GEN_CONFIG_COMPONENT_COUNT_MAX ) {
			printf( "ERROR: \"component_count_min\"/\"component_count_max\" must be within [%u, %u] in \"%s\".\n",
				GEN_CONFIG_COMPONENT_COUNT_MIN, GEN_CONFIG_COMPONENT_COUNT_MAX, filename );

			toml_free( root );
			root = NULL;

			return false;
		}

		bool32 anyScalarTypeEnabled = false;
		for ( u32 i = 0; i < GEN_TYPE_COUNT; i++ ) {
			anyScalarTypeEnabled |= outConfig->scalarTypeEnabled[i];
		}

		if ( !anyScalarTypeEnabled ) {
			printf( "ERROR: All scalar types are disabled in \"%s\" - nothing would be generated.\n", filename );

			toml_free( root );
			root = NULL;

			return false;
		}
	}

	toml_free( root );
	root = NULL;

	return true;
}

void Gen_BuildTypeInfos( allocatorLinear_t *allocator, const genConfig_t *config,
	typeInfo_t **outVectorTypeInfos, u32 *outVectorTypeInfosCount,
	typeInfo_t **outQuaternionTypeInfos, u32 *outQuaternionTypeInfosCount,
	typeInfo_t **outMatrixTypeInfos, u32 *outMatrixTypeInfosCount ) {

	assert( allocator );
	assert( config );
	assert( outVectorTypeInfos );
	assert( outVectorTypeInfosCount );
	assert( outQuaternionTypeInfos );
	assert( outQuaternionTypeInfosCount );
	assert( outMatrixTypeInfos );
	assert( outMatrixTypeInfosCount );

	const generatorFlags_t flags = config->flags;
	const u32 componentCountMin = config->componentCountMin;
	const u32 componentCountMax = config->componentCountMax;
	const u32 numComponentPermutations = ( componentCountMax - componentCountMin ) + 1;

	// vectors
	{
		u32 maxCount = GEN_TYPE_COUNT * numComponentPermutations;
		typeInfo_t *vectorTypeInfos = (typeInfo_t *) Mem_Alloc( allocator, maxCount * sizeof( typeInfo_t ) );

		u32 typeInfoIndex = 0;

		for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
			if ( !config->scalarTypeEnabled[typeIndex] ) {
				continue;
			}

			genType_t type = (genType_t) typeIndex;
			const char *typeString = Gen_GetTypeString( type );

			for ( u32 componentIndex = componentCountMin; componentIndex <= componentCountMax; componentIndex++ ) {
				typeInfo_t *typeInfo = &vectorTypeInfos[typeInfoIndex++];
				typeInfo->type = type;
				typeInfo->numRows = 1;
				typeInfo->numCols = componentIndex;
				typeInfo->fullTypeName = String_TPrintf( allocator, "%s%d", typeString, typeInfo->numCols );
			}
		}

		*outVectorTypeInfos = vectorTypeInfos;
		*outVectorTypeInfosCount = typeInfoIndex;
	}

	// quaternions - only if float and double (and 4-component types) are actually going to be generated,
	// since quaternion codegen assumes a same-sized floating point vector type exists alongside it
	{
		bool32 canGenerateQuaternions = ( flags & GENERATOR_FLAG_GENERATE_QUATERNIONS )
			&& config->scalarTypeEnabled[GEN_TYPE_FLOAT]
			&& config->scalarTypeEnabled[GEN_TYPE_DOUBLE]
			&& componentCountMin <= 4
			&& componentCountMax >= 4;

		if ( canGenerateQuaternions ) {
			typeInfo_t *quaternionTypeInfos = (typeInfo_t *) Mem_Alloc( allocator, 2 * sizeof( typeInfo_t ) );

			quaternionTypeInfos[0].type = GEN_TYPE_FLOAT;
			quaternionTypeInfos[0].numRows = 1;
			quaternionTypeInfos[0].numCols = 4;
			quaternionTypeInfos[0].fullTypeName = "float4";

			quaternionTypeInfos[1].type = GEN_TYPE_DOUBLE;
			quaternionTypeInfos[1].numRows = 1;
			quaternionTypeInfos[1].numCols = 4;
			quaternionTypeInfos[1].fullTypeName = "double4";

			*outQuaternionTypeInfos = quaternionTypeInfos;
			*outQuaternionTypeInfosCount = 2;
		} else {
			*outQuaternionTypeInfos = NULL;
			*outQuaternionTypeInfosCount = 0;
		}
	}

	// matrices
	{
		u32 maxCount = GEN_TYPE_COUNT * numComponentPermutations * numComponentPermutations;
		typeInfo_t *matrixTypeInfos = (typeInfo_t *) Mem_Alloc( allocator, maxCount * sizeof( typeInfo_t ) );

		u32 typeInfoIndex = 0;

		for ( u32 typeIndex = 0; typeIndex < GEN_TYPE_COUNT; typeIndex++ ) {
			if ( !config->scalarTypeEnabled[typeIndex] ) {
				continue;
			}

			genType_t type = (genType_t) typeIndex;
			const char *typeString = Gen_GetTypeString( type );

			for ( u32 row = componentCountMin; row <= componentCountMax; row++ ) {
				for ( u32 col = componentCountMin; col <= componentCountMax; col++ ) {
					if ( row != col && !( flags & GENERATOR_FLAG_GENERATE_NON_SQUARE_MATRICES ) ) {
						continue;
					}

					typeInfo_t *typeInfo = &matrixTypeInfos[typeInfoIndex++];
					typeInfo->type = type;
					typeInfo->numRows = row;
					typeInfo->numCols = col;
					typeInfo->fullTypeName = String_TPrintf( allocator, "%s%dx%d", typeString, typeInfo->numRows, typeInfo->numCols );
				}
			}
		}

		*outMatrixTypeInfos = matrixTypeInfos;
		*outMatrixTypeInfosCount = typeInfoIndex;
	}
}
