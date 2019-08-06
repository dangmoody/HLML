#pragma once

#include "int_types.h"

struct process_t {
	void* ptr;
};

					// starts an external process with the given cmd line args
					// unless calling OS_KillProcess(), you should call OS_CloseProcess() after calling this when done with the process
extern process_t	OS_StartProcess( const char* name, const char* args );

					// terminates the given external process with the given exit code
					// also closes the process
extern bool32		OS_KillProcess( process_t process, const u32 exitCode );

					// waits for the given external process to finish
extern bool32		OS_WaitForProcess( const process_t process );

					// releases process handles and returns them back to the OS
extern bool32		OS_CloseProcess( process_t process );
