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

#include "gen_shared.h"

typedef struct stringBuilder_t stringBuilder_t;

typedef struct parametricTestDefinitionParm_t {
	const typeInfo_t	*typeInfo;
	const char			*parmName;
} parametricTestDefinitionParm_t;

typedef struct parametricTestDefinition_t {
	const typeInfo_t						*returnType;
	const parametricTestDefinitionParm_t	*parms;
	u32										parmsCount;
	bool32									alsoGenerateSSE;	// TODO(DM): now that we have multiple bools, do flags
	bool32									checkEachComponent;
	const char								*funcName;
	const char								*testNameOverride;	// if NULL then generator will pick its own test name
} parametricTestDefinition_t;

typedef struct parametricTestInvokationGenericParm_t {
	const typeInfo_t	*typeInfo;
	const float32		*value;
} parametricTestInvokationGenericParm_t;

const char	*Gen_GetTestName( allocatorLinear_t *tempStorage, const typeInfo_t *typeInfo, const char *funcName );

void		Gen_AppendTestFileIncludes( allocatorLinear_t *tempStorage,
										stringBuilder_t *code,
										const char *languageName,
										const generatorFlags_t flags );

void		Gen_GenerateParametricTestDefinition_Generic_SSE( allocatorLinear_t *tempStorage,
															  stringBuilder_t *code,
															  const typeInfo_t *typeInfo,
															  const generatorStrings_t *strings,
															  const generatorFlags_t flags,
															  parametricTestDefinition_t *def );

void		Gen_GenerateParametricTestDefinition_Generic( allocatorLinear_t *tempStorage,
														  stringBuilder_t *code,
														  const typeInfo_t *typeInfo,
														  const generatorStrings_t *strings,
														  const generatorFlags_t flags,
														  parametricTestDefinition_t *def );

void		Gen_GenerateParametricTestInvokation_Generic( allocatorLinear_t *tempStorage,
														  stringBuilder_t *code,
														  const typeInfo_t *typeInfo,
														  const char *funcName,
														  const generatorStrings_t *strings,
														  const generatorFlags_t flags,
														  const parametricTestInvokationGenericParm_t *parms,
														  const u32 parmsCount );

void		Gen_GenerateParametricTestInvokation_Generic_SSE( allocatorLinear_t *tempStorage,
															  stringBuilder_t *code,
															  const typeInfo_t *typeInfo,
															  const char *funcName,
															  const generatorStrings_t *strings,
															  const generatorFlags_t flags,
															  const parametricTestInvokationGenericParm_t *parms,
															  const u32 parmsCount );

void		GenerateComponentWiseTests( allocatorLinear_t *tempStorage,
										stringBuilder_t *code,
										const typeInfo_t *typeInfo,
										const typeInfo_t *scalarType,
										const generatorStrings_t *strings,
										const generatorFlags_t flags,
										const bool32 generateQuaternions );

void		GenerateTests_CtorConversion( allocatorLinear_t *tempStorage,
										  stringBuilder_t *code,
										  const typeInfo_t *typeInfo,
										  const generatorStrings_t *strings,
										  const generatorFlags_t flags,
										  const u32 componentCountMin,
										  const bool32 *scalarTypeEnabled );

void		GenerateVectorTests( allocatorLinear_t *tempStorage,
								 const char *generatedTestsPath,
								 const char *languageName,
								 const typeInfo_t *vectorTypeInfos,
								 const u32 vectorTypeInfosCount,
								 const generatorStrings_t *strings,
								 const generatorFlags_t flags,
								 const u32 componentCountMin,
								 const u32 componentCountMax,
								 const bool32 generateQuaternions );

void		GenerateQuaternionTests( allocatorLinear_t *tempStorage,
									 const char *generatedTestsPath,
									 const char *languageName,
									 const typeInfo_t *quaternionTypeInfos,
									 const u32 quaternionTypeInfosCount,
									 const generatorStrings_t *strings,
									 const generatorFlags_t flags );

void		GenerateMatrixTests( allocatorLinear_t *tempStorage,
								 const char *generatedTestsPath,
								 const char *languageName,
								 const typeInfo_t *matrixTypeInfos,
								 const u32 matrixTypeInfosCount,
								 const generatorStrings_t *strings,
								 const generatorFlags_t flags );
