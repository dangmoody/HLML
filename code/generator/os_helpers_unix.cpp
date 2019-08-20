#if defined( __APPLE__ ) || defined( __unix__ )

#include "os_helpers.h"

#include "defines.h"

#include "unix_helpers.h"

#include <unistd.h>
#include <signal.h>

#include <sys/types.h>
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>

#include <errno.h>

struct processUnix_t {
	pid_t		pid;
	const char*	name;
};

static void CloseProcessInternal( process_t process ) {
	processUnix_t* proc = (processUnix_t*) process.ptr;

	free( proc );
	proc = NULL;
}

process_t OS_StartProcess( const char* name, const char** args, const u32 argCount ) {
	pid_t pid = fork();

	if ( pid == -1 ) {
		int err = errno;
		printf( "ERROR: fork() for \"%s\" failed: Errno: %s.\n", name, ErrnoToString( err ) );
	} else if ( pid == 0 ) {
		// child process
		printf( "Started child process: %s (%u).\n", name, getpid() );

		// + 1 for first arg must be the the program name on unix for some reason
		// + 1 for last arg must be NULL
		const size_t finalArgCount = 2 + argCount;
		const char** finalArgs = (const char**) alloca( finalArgCount * sizeof( char* ) );

		finalArgs[0] = name;

		for ( u32 i = 0; i < argCount; i++ ) {
			finalArgs[i + 1] = args[i];
		}

		finalArgs[finalArgCount - 1] = NULL;

//		for ( u32 i = 0; i < finalArgCount; i++ ) {
//			printf( "ARG %d: %s\n", i, finalArgs[i] );
//		}

		// DM: clang errors that we're either casting away the const here
		// or errors when creating a char** array because it's writable (above malloc call)
		// this seemed the neatest option
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-qual"
		execv( name, (char**) finalArgs );
#pragma GCC diagnostic pop
	} else {
		// parent process, nothing else to do here...
	}

	processUnix_t* proc = (processUnix_t*) malloc( sizeof( processUnix_t ) );
	proc->pid = pid;
	proc->name = name;

	return { proc };
}

bool32 OS_KillProcess( process_t process, const u32 exitCode ) {
	UNUSED( exitCode );	// DM: not sure how to fix this...

	processUnix_t* proc = (processUnix_t*) process.ptr;

	int result = kill( proc->pid, SIGTERM );

	if ( result != 0 ) {
		int err = errno;
		printf( "ERROR: Failed to terminate process \"%s\": Errno: %s.\n", proc->name, ErrnoToString( err ) );
	}

	CloseProcessInternal( process );

	return result == 0;
}

u32 OS_WaitForProcess( const process_t process ) {
	processUnix_t* proc = (processUnix_t*) process.ptr;

	u32 ret = 0;

	int status = 0;
	int waitResult = waitpid( proc->pid, &status, 0 );

	if ( waitResult > 0 ) {
		if ( WIFEXITED( status ) && !WEXITSTATUS( status ) ) {
			ret = 0;
		} else if ( WIFEXITED( status ) && WEXITSTATUS( status ) ) {
			if ( WEXITSTATUS( status ) == 127 ) {
				int err = errno;
				printf( "ERROR: execv on \"%s\" failed: Errno: %s.\n", proc->name, ErrnoToString( err ) );

				ret = 1;
			} else {
				printf( "WARNING: program \"%s\" terminated successfully, but returned non-zero.\n", proc->name );

				ret = 0;
			}
		} else {
			int err = errno;
			printf( "ERROR: program \"%s\" failed to terminate successfully: Errno: %s.\n", proc->name, ErrnoToString( err ) );

			ret = 1;
		}
	} else if ( waitResult == 0 ) {
		// process is still running
	} else {
		int err = errno;
		printf( "ERROR: waitpid() failed on child process: \"%s\": Errno: %s.\n", proc->name, ErrnoToString( err ) );
	}

	CloseProcessInternal( process );

	return ret;
}

#endif // defined( __APPLE__ ) || defined( __unix__ )

