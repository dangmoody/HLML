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

#if defined( __linux__ ) || defined( __APPLE__ )

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#pragma push_macro( "_POSIX_C_SOURCE" )
#undef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 199309L
#pragma clang diagnostic pop

#include "../timer.h"

#include <time.h>

/*
Timer for Linux/MacOS

DM: this seems to be the best implementation I can get on linux
multiplying each resultant second by the constant seems wrong though
I don't like how Time_Now() actually returns nano seconds when it should return clock cycles but I don't have a dedicated linux PC or a Mac so I'm not sure I can totally trust my test results
but its the best I can do all things considered and it looks close enough to me
if I'm wrong and someone can fix/improve this then please do
*/

#define GEN_CLOCK_MOD 1000000000

s64 Time_Now( void ) {
	struct timespec now = { 0 };
	clock_gettime( CLOCK_MONOTONIC, &now );

	return (s64) ( now.tv_sec * GEN_CLOCK_MOD + now.tv_nsec );
}

float64 Time_NowSeconds( void ) {
	s64 time = Time_Now();
	return (float64) time / 1000000000.0;
}

float64 Time_NowMS( void ) {
	s64 time = Time_Now();
	return (float64) time / 1000000.0;
}

float64 Time_NowUS( void ) {
	s64 time = Time_Now();
	return (float64) time / 1000.0;
}

float64 Time_NowNS( void ) {
	s64 time = Time_Now();
	return (float64) time;
}

#undef GEN_CLOCK_MOD

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#pragma pop_macro( "_POSIX_C_SOURCE" )
#pragma clang diagnostic pop

#endif // defined( __linux__ ) || defined( __APPLE__ )