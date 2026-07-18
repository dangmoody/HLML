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
