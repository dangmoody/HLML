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