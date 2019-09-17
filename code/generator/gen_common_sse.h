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

extern void		Gen_SSE_Radians( const genType_t type, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
extern void		Gen_SSE_Degrees( const genType_t type, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );
extern void		Gen_SSE_Lerp( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );


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

inline void Gen_SSE_GetFullTypeName( const char* fullTypeName, char* outString ) {
	assert( fullTypeName );
	assert( outString );

	int length = snprintf( outString, GEN_STRING_LENGTH_SSE_INPUT_NAME, "%s_sse_t", fullTypeName );

	assert( length < GEN_STRING_LENGTH_SSE_INPUT_NAME && "SSE input name constant needs to be bumped!" );
}

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

	// const char* suffix = GetSSEIntrinsicSuffixStr( type );
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

inline const char* Gen_SSE_GetMacroNameNegate( const genType_t type ) {
	switch ( type ) {
		case GEN_TYPE_INT:
		case GEN_TYPE_UINT:
			return "_NEGATE_EPI32";

		case GEN_TYPE_FLOAT:
			return "_NEGATE_PS";

		case GEN_TYPE_DOUBLE:
			return "_NEGATE_PD";

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

inline const char* Gen_SSE_GetFuncStrSqrt( const genType_t type ) {
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
