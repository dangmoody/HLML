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

#pragma once

#include "gen_shared.h"

typedef struct stringBuilder_t stringBuilder_t;

typedef struct parametricTestDefinitionParm_t {
	const typeInfo_t*	typeInfo;
	const char*			parmName;
} parametricTestDefinitionParm_t;

typedef struct parametricTestDefinition_t {
	const typeInfo_t*						returnType;
	const parametricTestDefinitionParm_t*	parms;
	u32										parmsCount;
	bool32									alsoGenerateSSE;	// TODO(DM): now that we have multiple bools, do flags
	bool32									checkEachComponent;
	const char*								funcName;
	const char*								testNameOverride;	// if NULL then generator will pick its own test name
} parametricTestDefinition_t;

typedef struct parametricTestInvokationGenericParm_t {
	const typeInfo_t*	typeInfo;
	const float32*		value;
} parametricTestInvokationGenericParm_t;

const char*	Gen_GetTestName( allocatorLinear_t* tempStorage, const typeInfo_t* typeInfo, const char* funcName );

void		Gen_GenerateParametricTestDefinition_Generic_SSE( allocatorLinear_t* tempStorage,
															  stringBuilder_t* code,
															  const typeInfo_t* typeInfo,
															  const generatorStrings_t* strings,
															  const generatorFlags_t flags,
															  parametricTestDefinition_t* def );

void		Gen_GenerateParametricTestDefinition_Generic( allocatorLinear_t* tempStorage,
														  stringBuilder_t* code,
														  const typeInfo_t* typeInfo,
														  const generatorStrings_t* strings,
														  const generatorFlags_t flags,
														  parametricTestDefinition_t* def );

void		Gen_GenerateParametricTestInvokation_Generic( allocatorLinear_t* tempStorage,
														  stringBuilder_t* code,
														  const typeInfo_t* typeInfo,
														  const char* funcName,
														  const generatorStrings_t* strings,
														  const generatorFlags_t flags,
														  const parametricTestInvokationGenericParm_t* parms,
														  const u32 parmsCount );

void		Gen_GenerateParametricTestInvokation_Generic_SSE( allocatorLinear_t* tempStorage,
															  stringBuilder_t* code,
															  const typeInfo_t* typeInfo,
															  const char* funcName,
															  const generatorStrings_t* strings,
															  const generatorFlags_t flags,
															  const parametricTestInvokationGenericParm_t* parms,
															  const u32 parmsCount );

void		GenerateComponentWiseTests( allocatorLinear_t* tempStorage,
										stringBuilder_t* code,
										const typeInfo_t* typeInfo,
										const typeInfo_t* scalarType,
										const generatorStrings_t* strings,
										const generatorFlags_t flags );

void		GenerateTests_CtorConversion( allocatorLinear_t* tempStorage,
										  stringBuilder_t* code,
										  const typeInfo_t* typeInfo,
										  const generatorStrings_t* strings,
										  const generatorFlags_t flags );

void		GenerateVectorTests( allocatorLinear_t* tempStorage,
								 const char* generatedTestsPath,
								 const char* languageName,
								 const typeInfo_t* vectorTypeInfos,
								 const u32 vectorTypeInfosCount,
								 const generatorStrings_t* strings,
								 const generatorFlags_t flags );

void		GenerateQuaternionTests( allocatorLinear_t* tempStorage,
									 const char* generatedTestsPath,
									 const char* languageName,
									 const typeInfo_t* quaternionTypeInfos,
									 const u32 quaternionTypeInfosCount,
									 const generatorStrings_t* strings,
									 const generatorFlags_t flags );

void		GenerateMatrixTests( allocatorLinear_t* tempStorage,
								 const char* generatedTestsPath,
								 const char* languageName,
								 const typeInfo_t* matrixTypeInfos,
								 const u32 matrixTypeInfosCount,
								 const generatorStrings_t* strings,
								 const generatorFlags_t flags );