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
#include "gen_common.h"

typedef struct allocatorLinear_t allocatorLinear_t;

extern void	Gen_VectorType_CPP( allocatorLinear_t* allocator, const genType_t type, const u32 numComponents );
extern void	Gen_VectorTests( allocatorLinear_t* allocator, const genLanguage_t language, const genType_t type, const u32 numComponents );