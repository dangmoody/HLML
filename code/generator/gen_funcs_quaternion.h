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

extern void		Gen_QuaternionMultiply( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
extern void		Gen_QuaternionMultiplyScalar( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
extern void		Gen_QuaternionLength(  const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
extern void		Gen_QuaternionNormalize( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
extern void		Gen_QuaternionConjugate( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
extern void		Gen_QuaternionInverse( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );

extern void		Gen_QuaternionRotationAxis( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
extern void		Gen_QuaternionLerp( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );
extern void		Gen_QuaternionSlerp( const genLanguage_t language, const genType_t type, stringBuilder_t* sbFwdDec, stringBuilder_t* sbImpl );