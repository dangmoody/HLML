#pragma once

#include "int_types.h"

#include <string.h>

inline bool32 StringEquals( const char* lhs, const char* rhs ) {
	return strcmp( lhs, rhs ) == 0;
}
