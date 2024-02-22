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

		// returns a timestamp in clock cycles
s64		Time_Now( void );

		// returns a timestamp in seconds
float64	Time_NowSeconds( void );

		// returns a timestamp in milliseconds
float64	Time_NowMS( void );

		// returns a timestamp in microseconds
float64	Time_NowUS( void );

		// returns a timestamp in nanoseconds
float64	Time_NowNS( void );
