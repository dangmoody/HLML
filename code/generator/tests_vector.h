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

void	GenerateVectorTests( allocatorLinear_t* tempStorage,
							 const char* generatedTestsPath,
							 const char* languageName,
							 const typeInfo_t* vectorTypeInfos,
							 const u32 vectorTypeInfosCount,
							 const generatorStrings_t* strings,
							 const generatorFlags_t flags );

void	GenerateQuaternionTests( allocatorLinear_t* tempStorage,
								 const char* generatedTestsPath,
								 const char* languageName,
								 const typeInfo_t* quaternionTypeInfos,
								 const u32 quaternionTypeInfosCount,
								 const generatorStrings_t* strings,
								 const generatorFlags_t flags );

void	GenerateMatrixTests( allocatorLinear_t* tempStorage,
							 const char* generatedTestsPath,
							 const char* languageName,
							 const typeInfo_t* matrixTypeInfos,
							 const u32 matrixTypeInfosCount,
							 const generatorStrings_t* strings,
							 const generatorFlags_t flags );
