#pragma once

#include "int_types.h"

				// inits things to do with time
extern void		Time_Init( void );

				// returns a timestamp in clock cycles
extern s64		Time_Now( void );

				// returns a timestamp in seconds
extern float64	Time_NowSeconds( void );

				// returns a timestamp in milliseconds
extern float64	Time_NowMS( void );

				// returns a timestamp in microseconds
extern float64	Time_NowUS( void );

				// returns a timestamp in nanoseconds
extern float64	Time_NowNS( void );
