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

#pragma once

#include "int_types.h"
#include "gen_shared.h"

typedef struct allocatorLinear_t allocatorLinear_t;

// component count range the codegen is able to support at all - a hard clamp, not just the default
#define GEN_CONFIG_COMPONENT_COUNT_MIN		2
#define GEN_CONFIG_COMPONENT_COUNT_MAX		4

#define GEN_CONFIG_OUTPUT_PATH_DEFAULT		"code/generated_files"

#define GEN_CONFIG_CONSTANTS_PREFIX_DEFAULT	"HLML_"

// a config file generates exactly one language per run - to generate both C and C++ output, run the
// generator twice, once per language, each with its own config file
typedef enum genLanguage_t {
	GEN_LANGUAGE_NONE	= 0,	// unset - there is no default; Gen_Config_LoadFromFile must set this from the config's "language" key
	GEN_LANGUAGE_C,
	GEN_LANGUAGE_CPP,

	GEN_LANGUAGE_COUNT
} genLanguage_t;

typedef struct genConfig_t {
	genLanguage_t		language;
	bool32				scalarTypeEnabled[GEN_TYPE_COUNT];	// indexed by genType_t; note GEN_TYPE_BOOL is currently always forced on, see gen_config.c
	u32					componentCountMin;					// inclusive, applies to both vector component counts and matrix rows/cols
	u32					componentCountMax;					// inclusive
	generatorFlags_t	flags;
	char				*outputPath;	// folder the API code is written into, with tests written to <outputPath>/tests/ beneath it; never has a trailing slash; language is NOT auto-appended - see Gen_GenerateAPIFiles/Gen_GenerateTests.  Either GEN_CONFIG_OUTPUT_PATH_DEFAULT (static storage) or an owned heap string from Gen_Config_LoadFromFile - never freed, config lives for the whole process
	char				*constantsPrefix;	// prefix applied to the constants generated in hlml_constants.h (HLML_PI, HLML_TAU, HLML_EPSILON, HLML_ROOT_2 by default) and to internal references to them (radians()/degrees()/floateq()).  Empty string is valid - it means no prefix at all.  Either GEN_CONFIG_CONSTANTS_PREFIX_DEFAULT (static storage) or an owned heap string from Gen_Config_LoadFromFile - never freed, config lives for the whole process
} genConfig_t;

// fills in outConfig with sensible defaults.  outConfig->language is left as GEN_LANGUAGE_NONE and
// outConfig->flags as 0 - there is no default language, so Gen_Config_LoadFromFile must supply "language"
// from the config file, which in turn determines the default flags for that language before any explicit
// top-level flag overrides in the same file are applied on top.
void	Gen_Config_SetDefaults( genConfig_t *outConfig );

// loads config values from a TOML file at 'filename' on top of whatever outConfig already contains
// (call Gen_Config_SetDefaults first so unset keys keep their default value).
// returns false (having already printed a clear "ERROR: ..." message) if 'filename' doesn't exist, the
// TOML is malformed, "language" is missing/invalid, or any values fail validation - these are normal,
// expected failure modes, not crashes, so the caller should check the return value and exit gracefully
// rather than continue with a partially-loaded config.
bool32	Gen_Config_LoadFromFile( const char *filename, genConfig_t *outConfig );

// builds the vector/quaternion/matrix typeInfo_t arrays according to the given config (specifically
// GENERATOR_FLAG_GENERATE_QUATERNIONS/GENERATOR_FLAG_GENERATE_NON_SQUARE_MATRICES), replacing the
// hardcoded construction that used to live in main.c
void	Gen_BuildTypeInfos( allocatorLinear_t *allocator, const genConfig_t *config,
	typeInfo_t **outVectorTypeInfos, u32 *outVectorTypeInfosCount,
	typeInfo_t **outQuaternionTypeInfos, u32 *outQuaternionTypeInfosCount,
	typeInfo_t **outMatrixTypeInfos, u32 *outMatrixTypeInfosCount );
