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
#ifdef _WIN64

#include "file_io.h"
#include "defines.h"

#include "timer.h"
#include "string_helpers.h"

#define WIN32_LEAN_AND_MEAN 1
#include <Windows.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#include <stb/stb_sprintf.h>
#pragma clang diagnostic pop

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

#ifndef WIN64_ASSERT
#ifdef _DEBUG
#define WIN64_ASSERT( x ) \
	do { \
		if ( !(x) ) { \
			u32 error = GetLastError(); \
			LPSTR msgbuf = NULL; \
			FormatMessageA( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, \
							NULL, error, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ), (LPSTR) &msgbuf, 0, NULL ); \
			printf( "WIN64: %s failed at %s:%d: %s", #x, __FILE__, __LINE__, msgbuf ); \
\
			LocalFree( msgbuf ); \
\
			assert( false ); \
		} \
	} while ( 0 )
#else // _DEBUG
#define WIN64_ASSERT( x ) GEN_UNUSED( x )
#endif // _DEBUG
#endif // WIN64_ASSERT

static HANDLE OpenOrCreateFileInternal( const char* filename ) {
	assert( filename );

	DWORD accessFlags = GENERIC_READ | GENERIC_WRITE;
	DWORD shareFlags = FILE_SHARE_READ | FILE_SHARE_WRITE;
	DWORD disposition = CREATE_ALWAYS;
	DWORD flagsAndAttributes = FILE_ATTRIBUTE_NORMAL;

	HANDLE handle = CreateFileA( filename, accessFlags, shareFlags, NULL, disposition, flagsAndAttributes, NULL );
	WIN64_ASSERT( handle != INVALID_HANDLE_VALUE );

	return handle;
}

static void CloseFileInternal( const HANDLE file ) {
	bool32 result = CloseHandle( file );
	WIN64_ASSERT( result );
}

static bool32 CreateFolderInternal( const char* path ) {
	if ( FS_FolderExists( path ) ) {
		return true;
	}

	SECURITY_ATTRIBUTES secattr = { 0 };
	secattr.nLength = sizeof( SECURITY_ATTRIBUTES );
	bool result = CreateDirectoryA( path, &secattr );

	return result;
}


void FS_WriteEntireFile( const char* filename, const char* data, const u64 length ) {
	assert( filename );
	assert( data );
	assert( length );

	HANDLE file = OpenOrCreateFileInternal( filename );

	DWORD bytesWritten = 0;
	bool32 result = WriteFile( file, data, (DWORD) length, &bytesWritten, NULL );
	WIN64_ASSERT( result );

	assert( bytesWritten == length );

	CloseFileInternal( file );
}

bool32 FS_CreateFolder( const char* path ) {
	size_t pathlen = strlen( path );

	// dont process trailing slash if one exists
	// otherwise we will get duplicate results for sub-dirs to parse
	//if ( path[pathlen - 1] == '/' ) {
	//	pathlen--;
	//}

	bool32 result = true;

	for ( size_t i = 0; i <= pathlen; i++ ) {
		if ( path[i] != '/' && path[i] != '\0' ) {
			continue;
		}

		char name[1024] = { 0 };
		strncpy_s( name, 1024, path, i );

		result &= CreateFolderInternal( name );
	}

	return result;
}

void FS_DeleteFolder( const char* name ) {
	assert( name );

	FS_DeleteAllFilesInFolder( name );

	// actually delete the folder
	bool32 result = RemoveDirectoryA( name );
	WIN64_ASSERT( result );
}

bool32 FS_FolderExists( const char* name ) {
	assert( name );

	DWORD attribs = GetFileAttributesA( name );

	return ( attribs != INVALID_FILE_ATTRIBUTES ) && ( ( attribs & FILE_ATTRIBUTE_DIRECTORY ) != 0 );
}

void FS_DeleteAllFilesInFolder( const char* name ) {
	assert( name );

	bool32 shouldClose = false;

	// delete all folder contents
	char filename[128] = { 0 };
	stbsp_snprintf( filename, 128, "%s\\*", name );

	WIN32_FIND_DATAA info = { 0 };
	HANDLE handle = FindFirstFileA( filename, &info );
	do {
		if ( info.cFileName[0] != 0 && info.cFileName[0] != '.' ) {
			stbsp_snprintf( filename, 128, "%s\\%s", name, info.cFileName );

			bool32 result = DeleteFileA( filename );
			WIN64_ASSERT( result );

			shouldClose = true;
		}
	} while ( FindNextFileA( handle, &info ) );

	if ( shouldClose ) {
		bool32 result = FindClose( handle );
		WIN64_ASSERT( result );
	}
}

#undef WIN64_ASSERT

// DM: I dont like this for obvious reasons
// QueryPerformanceFrequency() only needs to be called once
// but doing that means we end up having an init function which would be completely unecessary on any other platform
static s64 Frequency( void ) {
	LARGE_INTEGER frequency = { 0 };
	QueryPerformanceFrequency( &frequency );
	return frequency.QuadPart;
}

s64 Time_Now( void ) {
	LARGE_INTEGER now = { 0 };
	QueryPerformanceCounter( &now );
	return now.QuadPart;
}

float64 Time_NowSeconds( void ) {
	return (float64) Time_Now() / (float64) Frequency();
}

float64 Time_NowMS( void ) {
	return (float64) ( Time_Now() * 1000 ) / (float64) Frequency();
}

float64 Time_NowUS( void ) {
	return (float64) ( Time_Now() * 1000000 ) / (float64) Frequency();
}

float64 Time_NowNS( void ) {
	return (float64) ( Time_Now() * 1000000000 ) / (float64) Frequency();
}

#endif // _WIN64