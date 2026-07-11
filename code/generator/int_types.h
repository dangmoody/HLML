/*
===========================================================================

HLML Generator.
Copyright (c) Dan Moody 2018 - Present.

This file is part of the HLML Generator.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

===========================================================================
*/

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include <stddef.h>

typedef int8_t			s8;
typedef int16_t			s16;
typedef int32_t			s32;
typedef int64_t			s64;

typedef uint8_t			u8;
typedef uint16_t		u16;
typedef uint32_t		u32;
typedef uint64_t		u64;

typedef float			float32;
typedef double			float64;

typedef s32				bool32;

#define S8_MIN			INT8_MIN
#define S8_MAX			INT8_MAX
#define S16_MIN			INT16_MIN
#define S16_MAX			INT16_MAX
#define S32_MIN			INT32_MIN
#define S32_MAX			INT32_MAX
#define S64_MIN			INT64_MIN
#define S64_MAX			INT64_MAX

#define U8_MAX			UINT8_MAX
#define U16_MAX			UINT16_MAX
#define U32_MAX			UINT32_MAX
#define U64_MAX			UINT64_MAX

#define GEN_BIT( x )	( 1ULL << (x) )
