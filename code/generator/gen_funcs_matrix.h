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

extern void		Gen_GetParmListMatrix( const genType_t type, const u32 numRows, const u32 numCols, const float values[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], char* outString );
extern void		Gen_GetParmListMatrixIdentity( const genType_t type, const u32 numRows, const u32 numCols, char* outString );
extern void		Gen_GetParmListMatrixDiagonal( const genType_t type, const u32 numRows, const u32 numCols, const float* values, const u32 numValues, char* outString );
extern void		Gen_GetParmListMatrixSingleValue( const genType_t type, const u32 numRows, const u32 numCols, const float value, char* outString );
extern void		Gen_GetParmListMatrixSingleValueStr( const u32 numRows, const u32 numCols, const char* valueStr, char* outString );

extern void		Gen_MatrixOperatorsArithmetic( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader );

extern void		Gen_MatrixIdentity( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader );
extern void		Gen_MatrixTranspose( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader );
extern void		Gen_MatrixInverse( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader );
extern void		Gen_MatrixDeterminant( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader );

extern void		Gen_MatrixCompMulDiv( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader );

extern void		Gen_MatrixTranslate( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader );
extern void		Gen_MatrixRotate( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader );
extern void		Gen_MatrixScale( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader );

extern void		Gen_MatrixOrtho( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader );
extern void		Gen_MatrixPerspective( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader );
extern void		Gen_MatrixLookAt( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader );
