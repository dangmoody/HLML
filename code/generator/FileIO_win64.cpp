#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "FileIO.h"

#if defined( _WIN32 )
#include <Windows.h>

#include <stdio.h>

bool FS_CreateFolder( const char* name ) {
	if ( FS_FolderExists( name ) ) {
		return true;
	}

	SECURITY_ATTRIBUTES secattr = {};
	bool result = CreateDirectory( name, &secattr );

	if ( !result ) {
		printf( "WIN32: Failed creating folder: %lu\n", GetLastError() );
	}

	return result;
}

bool FS_DeleteFolder( const char* name ) {
	// delete all folder contents
	char filename[128] = {};
	snprintf( filename, 128, "%s\\*.*", name );

	WIN32_FIND_DATA info = {};
	HANDLE handle = FindFirstFile( filename, &info );
	do {
		snprintf( filename, 128, "%s\\%s", name, info.cFileName );
		DeleteFile( filename );
	} while ( FindNextFile( handle, &info ) );

	FindClose( handle );

	// attempt actual delete
	return RemoveDirectory( name );
}

bool FS_FolderExists( const char* name ) {
	DWORD attribs = GetFileAttributes( name );

	return ( attribs != INVALID_FILE_ATTRIBUTES ) && ( ( attribs & FILE_ATTRIBUTE_DIRECTORY ) != 0 );
}
#endif
