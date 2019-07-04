#pragma once

#include "gen_common.h"

extern void		Gen_GetParmListMatrix( const genType_t type, const u32 numRows, const u32 numCols, const float values[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX], char* outString );
extern void		Gen_GetParmListMatrixIdentity( const genType_t type, const u32 numRows, const u32 numCols, char* outString );
extern void		Gen_GetParmListMatrixDiagonal( const genType_t type, const u32 numRows, const u32 numCols, const float* values, const u32 numValues, char* outString );
extern void		Gen_GetParmListMatrixSingleValue( const genType_t type, const u32 numRows, const u32 numCols, const float value, char* outString );
extern void		Gen_GetParmListMatrixSingleValueStr( const u32 numRows, const u32 numCols, const char* valueStr, char* outString );

extern void		Gen_MatrixOperatorsArithmetic( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );

extern void		Gen_MatrixIdentity( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
extern void		Gen_MatrixTranspose( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
extern void		Gen_MatrixInverse( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
extern void		Gen_MatrixDeterminant( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );

extern void		Gen_MatrixCompMulDiv( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );

extern void		Gen_MatrixTranslate( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
extern void		Gen_MatrixRotate( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
extern void		Gen_MatrixScale( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );

extern void		Gen_MatrixOrtho( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
extern void		Gen_MatrixPerspective( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
extern void		Gen_MatrixLookAt( const genType_t type, const u32 numRows, const u32 numCols, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
