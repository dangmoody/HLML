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

extern void		Gen_GetParmListVector( const genType_t type, const u32 numComponents, const float* values, char* outParmListStr );

extern void		Gen_VectorGetCodeEquals( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader );

extern void		Gen_VectorGetCodeComponentWiseArithmeticScalar( const genLanguage_t language, const genType_t type, const u32 numComponents, const genOpArithmetic_t op, stringBuilder_t* sbHeader );
extern void		Gen_VectorGetCodeComponentWiseArithmeticRhsType( const genLanguage_t language, const genType_t type, const u32 numComponents, const genOpArithmetic_t op, stringBuilder_t* sbHeader );

extern void		Gen_VectorGetCodeComponentWiseBitwise( const genLanguage_t language, const genType_t type, const u32 numComponents, const genOpBitwise_t op, stringBuilder_t* sbHeader );

extern void		Gen_VectorGetCodeComponentWiseRelational( const genLanguage_t language, const u32 numComponents, const genOpRelational_t op, stringBuilder_t* sbHeader );

extern void		Gen_VectorFunctionsEquals( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
extern void		Gen_VectorFunctionsComponentWiseArithmetic( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
extern void		Gen_VectorFunctionsComponentWiseBitwise( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
extern void		Gen_VectorFunctionsComponentWiseRelational( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );

extern void		Gen_VectorLength( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
extern void		Gen_VectorNormalize( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
extern void		Gen_VectorDot( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
extern void		Gen_VectorCross( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
extern void		Gen_VectorAngle( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
extern void		Gen_VectorDistance( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );

extern void		Gen_VectorPack( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
extern void		Gen_VectorUnpack( const genType_t type, const u32 numComponents, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
