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

process_t OS_StartProcess( const char* name, const char* args ) {
	processWin_t* impl = (processWin_t*) malloc( sizeof( processWin_t ) );
	memset( impl, 0, sizeof( processWin_t ) );

	const size_t namelen = strlen( name );
	const size_t argslen = strlen( args );

	// + 1 for space between process name and start of args
	// + 1 for null terminator
	const size_t fullCmdLen = namelen + argslen + 1 + 1;

	char* fullCmdLine = (char*) alloca( fullCmdLen );
	snprintf( fullCmdLine, fullCmdLen, "%s %s", name, args );

	if ( !CreateProcessA( NULL, fullCmdLine, NULL, NULL, TRUE, 0, NULL, NULL, &impl->startupInfo, &impl->processInfo ) ) {
		printf( "Failed to create process \"%s\", error code: 0x%X\n", name, (int) GetLastError() );

		return { NULL };
	}

	return { impl };
}

bool32 OS_KillProcess( process_t process, const u32 exitCode ) {
	assert( process.ptr );

	processWin_t* impl = (processWin_t*) process.ptr;

	if ( !TerminateProcess( impl->processInfo.hProcess, exitCode ) ) {
		printf( "Failed to kill process \"%s\", error code: 0x%X\n", impl->startupInfo.lpTitle, (int) GetLastError() );
		return false;
	}

	OS_CloseProcess( process );

	free( impl );
	impl = NULL;

	return true;
}

bool32 OS_WaitForProcess( const process_t process ) {
	assert( process.ptr );

	processWin_t* impl = (processWin_t*) process.ptr;

	DWORD result = WaitForSingleObject( impl->processInfo.hProcess, U32_MAX );

	return ( result == WAIT_OBJECT_0 );
}

bool32 OS_CloseProcess( process_t process ) {
	assert( process.ptr );

	processWin_t* impl = (processWin_t*) process.ptr;

	if ( !CloseHandle( impl->processInfo.hProcess ) ) {
		printf( "Failed to close handle of process \"%s\", error code: 0x%X\n", impl->startupInfo.lpTitle, (int) GetLastError() );
		return false;
	}

	if ( !CloseHandle( impl->processInfo.hThread ) ) {
		printf( "Failed to close thread of process \"%s\", error code: 0x%X\n", impl->startupInfo.lpTitle, (int) GetLastError() );
		return false;
	}

	return true;
}

#endif // _WIN32
