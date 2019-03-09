#pragma once

#include "gen_common.h"

extern std::string	Gen_GetParmListMatrix( const genType_t type, const uint32_t numRows, const uint32_t numCols, const float values[GEN_COMPONENT_COUNT_MAX][GEN_COMPONENT_COUNT_MAX] );
extern std::string	Gen_GetParmListMatrixIdentity( const genType_t type, const uint32_t numRows, const uint32_t numCols );
extern std::string	Gen_GetParmListMatrixDiagonal( const genType_t type, const uint32_t numRows, const uint32_t numCols, const float* values, const uint32_t numValues );
extern std::string	Gen_GetParmListMatrixSingleValue( const genType_t type, const uint32_t numRows, const uint32_t numCols, const float value );

extern void			Gen_MatrixOperatorsArithmetic( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );
extern void			Gen_MatrixOperatorsRelational( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );

extern void			Gen_MatrixIdentity( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );
extern void			Gen_MatrixTranspose( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );
extern void			Gen_MatrixInverse( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );
extern void			Gen_MatrixDeterminant( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );

extern void			Gen_MatrixTranslate( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );
extern void			Gen_MatrixRotate( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );
extern void			Gen_MatrixScale( const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );

extern void			Gen_MatrixOrtho( const genHand_t hand, const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );
extern void			Gen_MatrixPerspective( const genHand_t hand, const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );
extern void			Gen_MatrixLookAt( const genHand_t hand, const genType_t type, const uint32_t numRows, const uint32_t numCols, std::string& outHeader, std::string& outInl );