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

#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN 1
#include <Windows.h>

static s64 g_frequency = 0;
static LARGE_INTEGER g_now = {};

void Time_Init( void ) {
	LARGE_INTEGER frequency = {};
	QueryPerformanceFrequency( &frequency );
	g_frequency = frequency.QuadPart;
}

s64 Time_Now( void ) {
	QueryPerformanceCounter( &g_now );
	return g_now.QuadPart;
}

float64 Time_NowSeconds( void ) {
	return (float64) Time_Now() / g_frequency;
}

float64 Time_NowMS( void ) {
	return (float64) ( ( Time_Now() * 1000 ) / g_frequency );
}

float64 Time_NowUS( void ) {
	return (float64) ( ( Time_Now() * 1000000 ) / g_frequency );
}

float64 Time_NowNS( void ) {
	return (float64) ( ( Time_Now() * 1000000000 ) / g_frequency );
}

#endif // _WIN32
