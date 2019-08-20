#ifdef _WIN32
#include "os_helpers.h"

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

	processWin_t* proc = (processWin_t*) process.ptr;

	if ( !CloseHandle( proc->processInfo.hProcess ) ) {
		printf( "Failed to close handle of process \"%s\", error code: 0x%X\n", proc->startupInfo.lpTitle, (int) GetLastError() );
		return false;
	}

	if ( !CloseHandle( proc->processInfo.hThread ) ) {
		printf( "Failed to close thread of process \"%s\", error code: 0x%X\n", proc->startupInfo.lpTitle, (int) GetLastError() );
		return false;
	}

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

		strncat( fullCmdLine, arg, strlen( arg ) );
		strncat( fullCmdLine, " ", 1 );
	}

	fullCmdLine[fullCmdLen - 1] = 0;

	if ( !CreateProcessA( NULL, fullCmdLine, NULL, NULL, TRUE, 0, NULL, NULL, &proc->startupInfo, &proc->processInfo ) ) {
		printf( "Failed to create process \"%s\", error code: 0x%X\n", name, (int) GetLastError() );

		return { NULL };
	}

	return { proc };
}

bool32 OS_KillProcess( process_t process, const u32 exitCode ) {
	assert( process.ptr );

	processWin_t* proc = (processWin_t*) process.ptr;

	if ( !TerminateProcess( proc->processInfo.hProcess, exitCode ) ) {
		printf( "Failed to kill process \"%s\", error code: 0x%X\n", proc->startupInfo.lpTitle, (int) GetLastError() );
		return false;
	}

	CloseProcess( process );

	free( proc );
	proc = NULL;

	return true;
}

u32 OS_WaitForProcess( const process_t process ) {
	assert( process.ptr );

	processWin_t* proc = (processWin_t*) process.ptr;

	DWORD result = WaitForSingleObject( proc->processInfo.hProcess, U32_MAX );

	CloseProcess( (process_t) process );

	return result;
}

#endif // _WIN32
