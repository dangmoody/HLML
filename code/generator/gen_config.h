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

// path is relative to the current working directory the generator is run from (repo root)
#define GEN_CONFIG_DEFAULT_PATH	"hlml_generator.toml"

// component count range the codegen is able to support at all - a hard clamp, not just the default
#define GEN_CONFIG_COMPONENT_COUNT_MIN		2
#define GEN_CONFIG_COMPONENT_COUNT_MAX		4

typedef struct genConfigTypes_t {
	bool32	scalarTypeEnabled[GEN_TYPE_COUNT];	// indexed by genType_t; note GEN_TYPE_BOOL is currently always forced on, see gen_config.c
	u32		componentCountMin;					// inclusive, applies to both vector component counts and matrix rows/cols
	u32		componentCountMax;					// inclusive
	bool32	generateQuaternions;
	bool32	generateNonSquareMatrices;
} genConfigTypes_t;

typedef struct genConfigPass_t {
	generatorFlags_t flags;
} genConfigPass_t;

typedef struct genConfig_t {
	genConfigTypes_t	types;
	genConfigPass_t		passC;
	genConfigPass_t		passCpp;
} genConfig_t;

// fills outConfig with the defaults that reproduce today's hardcoded generator behavior exactly
void	Gen_Config_SetDefaults( genConfig_t *outConfig );

// loads config values from a TOML file at 'filename' on top of whatever outConfig already contains
// (call Gen_Config_SetDefaults first so unset keys keep their default value).
// returns false (and leaves outConfig untouched) if the file doesn't exist.
// malformed TOML or invalid values are a hard error (assert), not a silent fallback.
bool32	Gen_Config_LoadFromFile( allocatorLinear_t *tempStorage, const char *filename, genConfig_t *outConfig );

// builds the vector/quaternion/matrix typeInfo_t arrays according to the given types config,
// replacing the hardcoded construction that used to live in main.c
void	Gen_BuildTypeInfos( allocatorLinear_t *allocator, const genConfigTypes_t *typesConfig,
	typeInfo_t **outVectorTypeInfos, u32 *outVectorTypeInfosCount,
	typeInfo_t **outQuaternionTypeInfos, u32 *outQuaternionTypeInfosCount,
	typeInfo_t **outMatrixTypeInfos, u32 *outMatrixTypeInfosCount );
