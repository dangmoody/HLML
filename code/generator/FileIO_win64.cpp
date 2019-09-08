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

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "FileIO.h"

#define WIN32_LEAN_AND_MEAN 1
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

#endif // _WIN32
