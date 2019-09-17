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
#include "timer.h"

#if defined( __linux__ ) || defined( __APPLE__ )

#include <time.h>

#include <assert.h>

/*
Timer for Linux/MacOS

DM: this seems to be the best implementation I can get on Linux, multiplying each resultant second by the constant seems wrong though

I don't like how Time_Now() actually returns nano seconds when it should return clock cycles but I don't have a dedicated linux PC or a Mac so I'm not sure I can totally trust my test results, but its the best I can do all things considered and it looks close enough to me

if I'm wrong and someone can fix/improve this then please do
*/

#define GEN_CLOCK_MOD 1000000000.0

static bool g_initialised = false;

void Time_Init( void ) {
	g_initialised = true;
}

s64 Time_Now( void ) {
	assert( g_initialised );

	struct timespec now;
	clock_gettime( CLOCK_MONOTONIC, &now );

	return (s64) ( now.tv_sec * GEN_CLOCK_MOD + now.tv_nsec );
}

float64 Time_NowSeconds( void ) {
	assert( g_initialised );

	return (float64) Time_Now() / 1000000000.0;
}

float64 Time_NowMS( void ) {
	assert( g_initialised );

	return (float64) Time_Now() / 1000000.0;
}

float64 Time_NowUS( void ) {
	assert( g_initialised );

	return (float64) Time_Now() / 1000.0;
}

float64 Time_NowNS( void ) {
	assert( g_initialised );

	return (float64) Time_Now();
}

#undef GEN_CLOCK_MOD

#endif // defined( __linux__ ) || defined( __APPLE__ )
