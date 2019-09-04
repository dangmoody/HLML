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

#include "gen_common.h"

extern void		Gen_SSE_MatrixIdentity( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
extern void		Gen_SSE_MatrixTranspose( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );

extern void		Gen_SSE_MatrixDeterminant( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
// extern void		Gen_SSE_MatrixInverse( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );

extern void		Gen_SSE_MatrixArithmeticComponentWise( const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );

extern void		Gen_SSE_MatrixMultiply( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
extern void		Gen_SSE_MatrixDivide( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );

extern void		Gen_SSE_MatrixTranslate( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
// extern void		Gen_SSE_MatrixRotate( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
extern void		Gen_SSE_MatrixScale( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );