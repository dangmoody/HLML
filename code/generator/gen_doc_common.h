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

// DM!!! no! this cannot be here!
#include "gen_common.h"

#include "string_builder.h"

void Doc_Vector( stringBuilder_t* codeHeader, const genLanguage_t language, const u32 numComponents, const char* memberTypeString );

void Doc_Matrix( stringBuilder_t* codeHeader, const u32 numRows, const char* vectorMemberTypeString );

void Doc_Floateq( stringBuilder_t* sb );

void Doc_Sign( stringBuilder_t* sb );

void Doc_Radians( stringBuilder_t* sb );
void Doc_Degrees( stringBuilder_t* sb );

void Doc_Min( stringBuilder_t* sb );
void Doc_Max( stringBuilder_t* sb );
void Doc_Clamp( stringBuilder_t* sb );
void Doc_Saturate( stringBuilder_t* sb, const char* fullTypeName );

void Doc_Lerp( stringBuilder_t* sb, const char* fullTypeName );
void Doc_Step( stringBuilder_t* sb, const char* fullTypeName );

void Doc_Smoothstep( stringBuilder_t* sb, const char* fullTypeName );
void Doc_Smootherstep( stringBuilder_t* sb, const char* fullTypeName );

void Doc_FunctionAll( stringBuilder_t* sb, const char* fullTypeName );

void Doc_OperatorEquals( stringBuilder_t* sb, const char* fullTypeName );
void Doc_OperatorNotEquals( stringBuilder_t* sb, const char* fullTypeName );

void Doc_ComponentWiseArithmeticScalar( stringBuilder_t* sb, const char* fullTypeName, const genOpArithmetic_t op );
void Doc_OperatorCompoundArithmeticScalar( stringBuilder_t* sb, const char* fullTypeName, const genOpArithmetic_t op );
void Doc_ComponentWiseArithmeticRhsType( stringBuilder_t* sb, const char* lhsTypeName, const char* rhsTypeName, const genOpArithmetic_t op );
void Doc_OperatorCompoundComponentWiseArithmeticRhsType( stringBuilder_t* sb, const char* lhsTypeName, const char* rhsTypeName, const genOpArithmetic_t op );

void Doc_OperatorIncrementPrefix( stringBuilder_t* sb, const char* fullTypeName, const genOpIncrement_t op );
void Doc_OperatorIncrementPostfix( stringBuilder_t* sb, const char* fullTypeName, const genOpIncrement_t op );

void Doc_ComponentWiseRelational( stringBuilder_t* sb, const char* fullTypeName, const u32 numRows, const u32 numCols, const genOpRelational_t op );

void Doc_OperatorBitwiseRhsType( stringBuilder_t* sb, const char* fullTypeName, const genOpBitwise_t op );
void Doc_OperatorCompoundBitwiseScalar( stringBuilder_t* sb, const char* fullTypeName, const genOpBitwise_t op );
void Doc_OperatorCompoundBitwiseRhsType( stringBuilder_t* sb, const char* fullTypeName, const genOpBitwise_t op );
void Doc_OperatorBitwiseUnary( stringBuilder_t* sb, const char* fullTypeName );
