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
#ifdef _WIN32
#include "os_process.h"
#include "win64_helpers.h"

#define WIN32_LEAN_AND_MEAN 1
#include <Windows.h>

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>	// alloca
#include <assert.h>

struct processWin_t {
	STARTUPINFO			startupInfo;
	PROCESS_INFORMATION	processInfo;
};

static bool32 CloseProcess( process_t process ) {
	assert( process.ptr );

	bool32 result = false;

	processWin_t* proc = (processWin_t*) process.ptr;

	result = CloseHandle( proc->processInfo.hProcess );
	WIN64_ASSERT( result );

	result = CloseHandle( proc->processInfo.hThread );
	WIN64_ASSERT( result );

	return true;
}

process_t OS_StartProcess( const char* name, const char** args, const u32 argCount ) {
	processWin_t* proc = (processWin_t*) malloc( sizeof( processWin_t ) );
	memset( proc, 0, sizeof( processWin_t ) );

	const size_t namelen = strlen( name );
	size_t argslen = 0;

	for ( u32 i = 0; i < argCount; i++ ) {
		argslen += strlen( args[i] ) + 1;	// + 1 for space
	}

	// + 1 for space between process name and start of args
	// + 1 for null terminator
	const size_t fullCmdLen = namelen + argslen + 1 + 1;

	char* fullCmdLine = (char*) alloca( fullCmdLen );
	snprintf( fullCmdLine, fullCmdLen, "%s ", name );

	for ( u32 i = 0; i < argCount; i++ ) {
		const char* arg = args[i];

		strncat_s( fullCmdLine, fullCmdLen, arg, strlen( arg ) );
		strncat_s( fullCmdLine, fullCmdLen, " ", 1 );
	}

	fullCmdLine[fullCmdLen - 1] = 0;

	bool32 result = CreateProcessA( NULL, fullCmdLine, NULL, NULL, TRUE, 0, NULL, NULL, &proc->startupInfo, &proc->processInfo );
	WIN64_ASSERT( result );

	return { proc };
}

bool32 OS_KillProcess( process_t process, const u32 exitCode ) {
	assert( process.ptr );

	bool32 result = false;

	processWin_t* proc = (processWin_t*) process.ptr;

	result = TerminateProcess( proc->processInfo.hProcess, exitCode );
	WIN64_ASSERT( result );

	result = CloseProcess( process );
	WIN64_ASSERT( result );

	free( proc );
	proc = NULL;

	return true;
}

u32 OS_WaitForProcess( const process_t process ) {
	assert( process.ptr );

	processWin_t* proc = (processWin_t*) process.ptr;

	DWORD procResult = WaitForSingleObject( proc->processInfo.hProcess, U32_MAX );

	bool32 result = CloseProcess( (process_t) process );
	WIN64_ASSERT( result );

	return procResult;
}

#endif // _WIN32
