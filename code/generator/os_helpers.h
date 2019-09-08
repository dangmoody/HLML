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

struct process_t {
	void* ptr;
};

					// starts an external process with the given cmd line args
					// unless calling OS_KillProcess(), you should call OS_CloseProcess() after calling this when done with the process
extern process_t	OS_StartProcess( const char* name, const char** args, const u32 argCount );

					// terminates the given external process with the given exit code
extern bool32		OS_KillProcess( process_t process, const u32 exitCode );

					// waits for the given external process to finish
extern u32			OS_WaitForProcess( const process_t process );
