#if defined( __linux__ ) || defined( __APPLE__ )

#include "time.h"

#include <time.h>

#include <assert.h>

/*
Timer for Linux/MacOS

DM: I don't like how Time_Now() actually returns nano seconds when it should return clock cycles.
I don't have a dedicated linux box or a Mac so I can't accurately test, but it looks close enough to me.
If I'm wrong and someone can fix this, please do so.
*/

static bool g_initialised = false;

void Time_Init( void ) {
	g_initialised = true;
}

s64 Time_Now( void ) {
	assert( g_initialised );

	struct timespec now;
	clock_gettime( CLOCK_MONOTONIC_RAW, &now );

	return (s64) ( now.tv_sec + now.tv_nsec );
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

#endif // defined( __linux__ ) || defined( __APPLE__ )
