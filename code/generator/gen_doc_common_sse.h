#pragma once

#include "string_builder.h"

#include <assert.h>

inline void Doc_SSE_Vector( stringBuilder_t* sb, const u32 numComponents, const char* registerName ) {
	assert( sb );
	assert( numComponents >= GEN_COMPONENT_COUNT_MIN );
	assert( numComponents <= GEN_COMPONENT_COUNT_MAX );
	assert( registerName );

	String_Appendf( sb,
		"/// \\brief Holds %d %ss where each register is a vertical stream of that vector component.\n"
		"/// Basically, this struct holds 4 vectors.\n"
		, numComponents, registerName
	);
}

inline void Doc_SSE_Matrix( stringBuilder_t* sb, const u32 numRows, const u32 numCols, const char* registerName ) {
	assert( sb );
	assert( numRows >= GEN_COMPONENT_COUNT_MIN );
	assert( numRows <= GEN_COMPONENT_COUNT_MAX );
	assert( numCols >= GEN_COMPONENT_COUNT_MIN );
	assert( numCols <= GEN_COMPONENT_COUNT_MAX );
	assert( registerName );

	String_Appendf( sb,
		"/// \\brief Holds %d x %d %ss where each regster is a vertical stream of that matrix component.\n"
		"/// Basically, this struct holds 4 matrices.\n"
		, numRows, numCols, registerName
	);
}

inline void Doc_SSE_Radians( stringBuilder_t* sb, const char* registerName ) {
	assert( sb );
	assert( registerName );

	String_Appendf( sb, "/// \\brief Converts each component of the given %s from degrees to radians.\n", registerName );
}

inline void Doc_SSE_Degrees( stringBuilder_t* sb, const char* registerName ) {
	assert( sb );
	assert( registerName );

	String_Appendf( sb, "/// \\brief Converts each component of the given %s from radians to degrees.\n", registerName );
}

inline void Doc_SSE_Lerp( stringBuilder_t* sb, const char* registerName ) {
	assert( sb );
	assert( registerName );

	String_Appendf( sb, "/// \\brief Lerps each component of register 'lhs' against the corresponding component of register 'rhs' by the corresponding component of register 't'.\n", registerName );
}