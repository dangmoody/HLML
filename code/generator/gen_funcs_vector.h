#pragma once

#include "gen_common.h"

extern std::string	Gen_GetParmListVector( const genType_t type, const uint32_t numComponents, const float* values );

extern void			Gen_VectorOperatorsArithmetic( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl );

extern void			Gen_VectorLength( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl );
extern void			Gen_VectorNormalize( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl );
extern void			Gen_VectorDot( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl );
extern void			Gen_VectorCross( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl );
extern void			Gen_VectorAngle( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl );

extern void			Gen_VectorPack( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl );
extern void			Gen_VectorUnpack( const genType_t type, const uint32_t numComponents, std::string& outHeader, std::string& outInl );