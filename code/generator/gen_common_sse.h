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

extern void		Gen_SSE_MacroNegate( const genType_t type, stringBuilder_t* sbHeader );

extern void		Gen_SSE_Radians( const genLanguage_t language, const genType_t type, stringBuilder_t* sbHeader );
extern void		Gen_SSE_Degrees( const genLanguage_t language, const genType_t type, stringBuilder_t* sbHeader );
extern void		Gen_SSE_Lerp( const genLanguage_t language, const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader );


inline bool32 Gen_TypeSupportsSSE( const genType_t type ) {
	return type == GEN_TYPE_FLOAT;
}

inline const char* Gen_SSE_GetRegisterName( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_INT:
		case GEN_TYPE_UINT:
			return "__m128i";

		case GEN_TYPE_FLOAT:
			return "__m128";

		case GEN_TYPE_DOUBLE:
			return "__m256d";

		case GEN_TYPE_BOOL:
		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad genType_t passed into %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

inline void Gen_SSE_GetFullTypeName( const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	// 1 rows and 1 cols for scalar
	// 1 rows and M cols for vector
	// N rows and M cols for matrix
	assert( numRows >= 1 );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= 1 );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	int len = 0;

	if ( numRows == 1 && numCols == 1 ) {
		len = snprintf( outString, GEN_STRING_LENGTH_SSE_INPUT_NAME, "%s", Gen_SSE_GetRegisterName( type ) );
	} else {
		char fullTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
		Gen_GetFullTypeName( type, numRows, numCols, fullTypeName );

		len = snprintf( outString, GEN_STRING_LENGTH_SSE_INPUT_NAME, "%s_sse_t", fullTypeName );
	}

	if ( len >= GEN_STRING_LENGTH_SSE_INPUT_NAME ) {
		printf( "ERROR: Attempted to write a typename greater than %d characters.\n", GEN_STRING_LENGTH_SSE_INPUT_NAME );
		assert( false );
	}
}

// inline void Gen_SSE_GetParmTypeName( const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
// 	// 1 rows and 1 cols for scalar
// 	// 1 rows and M cols for vector
// 	// N rows and M cols for matrix
// 	assert( numRows >= 1 );
// 	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
// 	assert( numCols >= 1 );
// 	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

// 	char sseTypeName[GEN_STRING_LENGTH_SSE_INPUT_NAME];
// 	Gen_SSE_GetFullTypeName( type, numRows, numCols, sseTypeName );

// 	if ( numRows == 1 && numCols == 1 ) {
// 		snprintf( outString, GEN_STRING_LENGTH_SSE_INPUT_NAME, "%s", sseTypeName );
// 	} else {
// 		snprintf( outString, GEN_STRING_LENGTH_SSE_INPUT_NAME, "%s*", sseTypeName );
// 	}
// }

inline const char* Gen_SSE_GetIntrinsicLoad( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_INT:
		case GEN_TYPE_UINT:
		case GEN_TYPE_FLOAT:
			return "_mm_load_ps";

		case GEN_TYPE_DOUBLE:
			return "_mm_load_pd";

		case GEN_TYPE_BOOL:
		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad genType_t passed into %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

inline const char* Gen_SSE_GetIntrinsicStore( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_INT:
		case GEN_TYPE_UINT:
		case GEN_TYPE_FLOAT:
			return "_mm_store_ps";

		case GEN_TYPE_DOUBLE:
			return "_mm_store_pd";

		case GEN_TYPE_BOOL:
		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad genType_t passed into %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

inline const char* Gen_SSE_GetIntrinsicSet1( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_INT:
		case GEN_TYPE_UINT:
		case GEN_TYPE_FLOAT:
			return "_mm_set1_ps";

		case GEN_TYPE_DOUBLE:
			return "_mm_set1_pd";

		case GEN_TYPE_BOOL:
		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad genType_t passed into %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

inline const char* Gen_SSE_GetIntrinsicRcp( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_INT:
		case GEN_TYPE_UINT:
		case GEN_TYPE_FLOAT:
			return "_mm_rcp_ps";

		case GEN_TYPE_DOUBLE:
			return "_mm_rcp_pd";

		case GEN_TYPE_BOOL:
		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad genType_t passed into %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

inline const char*	Gen_SSE_GetIntrinsicXor( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_INT:
		case GEN_TYPE_UINT:
		case GEN_TYPE_FLOAT:
			return "_mm_xor_ps";

		case GEN_TYPE_DOUBLE:
			return "_mm_xor_pd";

		case GEN_TYPE_BOOL:
		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad genType_t passed into %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

inline void Gen_SSE_GetIntrinsicArithmetic( const genType_t type, const genOpArithmetic_t op, char* outString ) {
	assert( type < GEN_TYPE_COUNT );
	assert( op < GEN_OP_ARITHMETIC_COUNT );

	const char* opStr = GEN_OPERATOR_STRINGS_ARITHMETIC[op];

	const char* suffix = NULL;
	switch ( type ) {
		case GEN_TYPE_INT:
		case GEN_TYPE_UINT:
			suffix = "epi32";
			break;

		case GEN_TYPE_FLOAT:
			suffix = "ps";
			break;

		case GEN_TYPE_DOUBLE:
			suffix = "pd";
			break;

		case GEN_TYPE_BOOL:
		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad genType_t passed into %s.\n", __FUNCTION__ );
			suffix = "ERROR";
			break;
	}

	int length = snprintf( outString, GEN_STRING_LENGTH_SSE_INTRINSIC, "_mm_%s_%s", opStr, suffix );

	assert( length < GEN_STRING_LENGTH_SSE_INTRINSIC && "SSE intrinsic string length constant needs to be increased." );
}

inline const char* Gen_SSE_GetIntrinsicSqrt( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_INT:
		case GEN_TYPE_UINT:
		case GEN_TYPE_FLOAT:
			return "_mm_sqrt_ps";

		case GEN_TYPE_DOUBLE:
			return "_mm_sqrt_pd";

		case GEN_TYPE_BOOL:
		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad genType_t passed into %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

inline const char* Gen_SSE_GetMacroNameNegate( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_INT:
		case GEN_TYPE_UINT:
			return "NEGATE_EPI32";

		case GEN_TYPE_FLOAT:
			return "NEGATE_PS";

		case GEN_TYPE_DOUBLE:
			return "NEGATE_PD";

		case GEN_TYPE_BOOL:
		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad genType_t passed into %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

// inline const char* Gen_SSE_GetFuncStrAcos( const genType_t type ) {
// 	switch ( type ) {
// 		case GEN_TYPE_INT:
// 		case GEN_TYPE_UINT:
// 		case GEN_TYPE_FLOAT:
// 			return "_mm_acos_ps";

// 		case GEN_TYPE_DOUBLE:
// 			return "_mm_acos_pd";

// 		case GEN_TYPE_BOOL:
// 		case GEN_TYPE_COUNT:
// 		default:
// 			printf( "ERROR: Bad genType_t passed into %s.\n", __FUNCTION__ );
// 			return "ERROR";
// 	}
// }

inline void Gen_SSE_GetFuncNameInternal( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const char* funcName, char* outString ) {
	assert( numRows >= 1 );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= 1 );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( funcName );
	assert( outString );

	char funcNameStr[GEN_STRING_LENGTH_FUNCTION_NAME];
	Gen_GetFuncNameInternal( language, type, numRows, numCols, funcName, funcNameStr );

	snprintf( outString, GEN_STRING_LENGTH_FUNCTION_NAME, "%s_sse", funcNameStr );
}

// non-vector/matrix only
inline void Gen_SSE_GetFuncNameRadians( const genLanguage_t language, const genType_t type, char* outString ) {
	assert( outString );

	Gen_SSE_GetFuncNameInternal( language, type, 1, 1, "radians", outString );
}

inline void Gen_SSE_GetFuncNameDegrees( const genLanguage_t language, const genType_t type, char* outString ) {
	assert( outString );

	Gen_SSE_GetFuncNameInternal( language, type, 1, 1, "degrees", outString );
}

// vector functions
inline void Gen_SSE_GetFuncNameLerp( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	assert( numComponents >= 1 );	// 1 for non-vector types
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	Gen_SSE_GetFuncNameInternal( language, type, 1, numComponents, "lerp", outString );
}

inline void Gen_SSE_GetFuncNameNormalize( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	Gen_SSE_GetFuncNameInternal( language, type, 1, numComponents, "normalize", outString );
}

inline void Gen_SSE_GetFuncNameDot( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	Gen_SSE_GetFuncNameInternal( language, type, 1, numComponents, "dot", outString );
}

inline void Gen_SSE_GetFuncNameCross( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	Gen_SSE_GetFuncNameInternal( language, type, 1, numComponents, "cross", outString );
}

inline void Gen_SSE_GetFuncNameLengthsq( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	Gen_SSE_GetFuncNameInternal( language, type, 1, numComponents, "lengthsq", outString );
}

inline void Gen_SSE_GetFuncNameLength( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	Gen_SSE_GetFuncNameInternal( language, type, 1, numComponents, "length", outString );
}

inline void Gen_SSE_GetFuncNameDistancesq( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	Gen_SSE_GetFuncNameInternal( language, type, 1, numComponents, "distancesq", outString );
}

inline void Gen_SSE_GetFuncNameDistance( const genLanguage_t language, const genType_t type, const u32 numComponents, char* outString ) {
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	Gen_SSE_GetFuncNameInternal( language, type, 1, numComponents, "distance", outString );
}

// matrix functions
inline void Gen_SSE_GetFuncNameIdentity( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	Gen_SSE_GetFuncNameInternal( language, type, numRows, numCols, "identity", outString );
}

inline void Gen_SSE_GetFuncNameTranspose( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	Gen_SSE_GetFuncNameInternal( language, type, numRows, numCols, "transpose", outString );
}

inline void Gen_SSE_GetFuncNameDeterminant( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	Gen_SSE_GetFuncNameInternal( language, type, numRows, numCols, "determinant", outString );
}

inline void Gen_SSE_GetFuncNameInverse( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	Gen_SSE_GetFuncNameInternal( language, type, numRows, numCols, "inverse", outString );
}

inline void Gen_SSE_GetFuncNameComponentWiseArithmeticMatrix( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, const genOpArithmetic_t op, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );

	char prefix[GEN_STRING_LENGTH_FUNCTION_NAME];
	snprintf( prefix, GEN_STRING_LENGTH_FUNCTION_NAME, "comp_%sm", GEN_OPERATOR_STRINGS_ARITHMETIC[op] );

	Gen_SSE_GetFuncNameInternal( language, type, numRows, numCols, prefix, outString );
}

inline void Gen_SSE_GetFuncNameMatrixMultiply( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	if ( language == GEN_LANGUAGE_C ) {
		Gen_SSE_GetFuncNameInternal( language, type, numRows, numCols, "mulm", outString );
	} else {
		Gen_SSE_GetFuncNameInternal( language, type, numRows, numCols, "mul", outString );
	}
}

inline void Gen_SSE_GetFuncNameTranslate( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	Gen_SSE_GetFuncNameInternal( language, type, numRows, numCols, "translate", outString );
}

inline void Gen_SSE_GetFuncNameScale( const genLanguage_t language, const genType_t type, const u32 numRows, const u32 numCols, char* outString ) {
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( outString );

	Gen_SSE_GetFuncNameInternal( language, type, numRows, numCols, "scale", outString );
}
