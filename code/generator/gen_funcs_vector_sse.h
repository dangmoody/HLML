#pragma once

#include "gen_common.h"

					// DM: not sure this is the best place for these to live
extern void			Gen_GetValuesArray1D( const genType_t type, const u32 numValues, const float* values, stringBuilder_t* sb );
extern void			Gen_GetValuesArray2D( const genType_t type, const u32 rows, const u32 cols, const float* values, stringBuilder_t* sb );

inline const char*	Gen_SSE_GetRegisterName( const genType_t type );

inline const char*	Gen_SSE_GetFuncStrLoad( const genType_t type );
inline const char*	Gen_SSE_GetFuncStrStore( const genType_t type );

inline const char*	Gen_SSE_GetFuncStrMul( const genType_t type );
inline const char*	Gen_SSE_GetFuncStrAdd( const genType_t type );

inline const char*	Gen_SSE_GetFuncStrSqrt( const genType_t type );

extern void			Gen_SSE_GetInputDataNameDot( const genType_t type, const u32 numComponents, char* outString );
extern void			Gen_SSE_VectorDot( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );

extern void			Gen_SSE_GetInputDataNameLength( const genType_t type, const u32 numComponents, char* outString );
extern void			Gen_SSE_VectorLength( const genType_t type, const u32 numComponents, stringBuilder_t* sbHeader, stringBuilder_t* sbInl );


const char* Gen_SSE_GetRegisterName( const genType_t type ) {
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

const char* Gen_SSE_GetFuncStrLoad( const genType_t type ) {
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

const char* Gen_SSE_GetFuncStrStore( const genType_t type ) {
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

const char* Gen_SSE_GetFuncStrMul( const genType_t type ) {
		switch ( type ) {
		case GEN_TYPE_INT:
		case GEN_TYPE_UINT:
		case GEN_TYPE_FLOAT:
			return "_mm_mul_ps";

		case GEN_TYPE_DOUBLE:
			return "_mm_mul_pd";

		case GEN_TYPE_BOOL:
		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad genType_t passed into %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

const char* Gen_SSE_GetFuncStrAdd( const genType_t type ) {
		switch ( type ) {
		case GEN_TYPE_INT:
		case GEN_TYPE_UINT:
		case GEN_TYPE_FLOAT:
			return "_mm_add_ps";

		case GEN_TYPE_DOUBLE:
			return "_mm_add_pd";

		case GEN_TYPE_BOOL:
		case GEN_TYPE_COUNT:
		default:
			printf( "ERROR: Bad genType_t passed into %s.\n", __FUNCTION__ );
			return "ERROR";
	}
}

const char* Gen_SSE_GetFuncStrSqrt( const genType_t type ) {
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
