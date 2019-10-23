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
#include "defines.h"
#include "allocator.h"
#include "timer.h"

#include <stdio.h>

extern void Gen_CPP( void );

int main( int argc, char** argv ) {
	UNUSED( argc );
	UNUSED( argv );

	printf(
		"HLML Generator.\n"
		"(c) Dan Moody 2019 - Present.\n"
		"\n"
		"Generating...\n"
		"\n"
	);

	Mem_Init( 2 * MB_TO_BYTES );

	Time_Init();

	Gen_CPP();

	printf(
		"All generators have run.  HLML Generator shutting down...\n"
		"Goodbye.\n"
	);

	Mem_Shutdown();

	return 0;
}
