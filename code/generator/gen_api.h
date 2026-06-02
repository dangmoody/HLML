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

#include "int_types.h"

#include "gen_shared.h"

typedef struct allocatorLinear_t allocatorLinear_t;

typedef void ( *generateSwizzleFunc_t )( allocatorLinear_t *tempStorage, stringBuilder_t *code, const typeInfo_t *typeInfo, const generatorStrings_t *strings, const generatorFlags_t flags, const u32 numSwizzleComponents, const char *swizzleStr );

void	GenerateScalarFiles( allocatorLinear_t *tempStorage, const char *generatedCodePath, const generatorFlags_t flags );
void	GenerateScalarFiles_SSE( allocatorLinear_t *tempStorage, const char *generatedCodePath, const generatorFlags_t flags );

bool32	SwizzleTypeIsWritable( const char *swizzleStr, const u32 numSwizzleComponents );

void	GenerateSwizzleFunctions( allocatorLinear_t *tempStorage, stringBuilder_t *code, const typeInfo_t *typeInfo, const generatorStrings_t *strings, const generatorFlags_t flags, const char *componentNames, generateSwizzleFunc_t generateSwizzleFunc );

void	GenerateVectorFiles( allocatorLinear_t *tempStorage, const char *generatedCodePath, const typeInfo_t *typeInfos, const u32 typeInfosCount, const generatorStrings_t *strings, const generatorFlags_t flags );
void	GenerateVectorFiles_SSE( allocatorLinear_t *tempStorage, const char *generatedCodePath, const typeInfo_t *typeInfos, const u32 typeInfosCount, const generatorStrings_t *strings, const generatorFlags_t flags );

void	GenerateQuaternionFiles( allocatorLinear_t *tempStorage, const char *generatedCodePath, const typeInfo_t *typeInfos, const u32 typeInfosCount, const generatorStrings_t *strings, const generatorFlags_t flags );

void	GenerateMatrixFiles( allocatorLinear_t *tempStorage, const char *generatedCodePath, const typeInfo_t *typeInfos, const u32 typeInfosCount, const generatorStrings_t *strings, const generatorFlags_t flags );

void	Gen_GenerateAPIFiles( allocatorLinear_t *tempStorage,
							  const char *languageName,
							  const typeInfo_t *vectorTypeInfos, const u32 vectorTypeInfosCount,
							  const typeInfo_t *quaternionTypeInfos, const u32 quaternionTypeInfosCount,
							  const typeInfo_t *matrixTypeInfos, const u32 matrixTypeInfosCount,
							  const generatorStrings_t *strings,
							  const generatorFlags_t flags );

void	Gen_GenerateTests( allocatorLinear_t *tempStorage,
						   const char *languageName,
						   const typeInfo_t *vectorTypeInfos, const u32 vectorTypeInfosCount,
						   const typeInfo_t *quaternionTypeInfos, const u32 quaternionTypeInfosCount,
						   const typeInfo_t *matrixTypeInfos, const u32 matrixTypeInfosCount,
						   const generatorStrings_t *strings,
						   const generatorFlags_t flags );