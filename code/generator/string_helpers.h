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

#include "int_types.h"

typedef struct allocatorLinear_t allocatorLinear_t;

// Returns true if the contents of lhs are indentical to rhs.
bool32		String_Equals( const char* lhs, const char* rhs );

// // sprintf wrapper.
// int			String_SPrintf( char* buffer, const char* fmt, ... );

// // vsprintf wrapper.
// int			String_VSPrintf( char* buffer, const char* fmt, va_list args );

// // snprintf wrapper.
// int			String_SNPrintf( char* buffer, const s64 bufferLength, const char* fmt, ... );

// // vsnprintf wrapper.
// int			String_VSNPrintf( char* buffer, const s64 bufferLength, const char* fmt, va_list args );

// Returns a char* that is the result of calling sprintf with the given format string and var args, uses temp storage to allocate the result string.
char*		String_TPrintf( allocatorLinear_t* tempStorage, const char* fmt, ... );

// // Returns a char* that is the result of calling sprintf with the given format string and args list, uses temp storage to allocate the result string.
// char*		String_VTPrintf( allocatorLinear_t* tempStorage, const char* fmt, va_list args );
