/*
===========================================================================

HLML Generator.
Copyright (c) Dan Moody 2018 - Present.

This file is part of the HLML Generator.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

===========================================================================
*/

#ifdef _WIN32

#include "../file_io.h"
#include "../defines.h"

#include "../timer.h"
#include "../string_helpers.h"

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

static HANDLE OpenOrCreateFileInternal( const char *filename ) {
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

static bool32 CreateFolderInternal( const char *path ) {
	if ( FS_FolderExists( path ) ) {
		return true;
	}

	SECURITY_ATTRIBUTES secattr = { 0 };
	secattr.nLength = sizeof( SECURITY_ATTRIBUTES );
	bool result = CreateDirectoryA( path, &secattr );

	return result;
}


void FS_WriteEntireFile( const char *filename, const char *data, const u64 length ) {
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

bool32 FS_CreateFolder( const char *path ) {
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

void FS_DeleteFolder( const char *name ) {
	assert( name );

	FS_DeleteAllFilesInFolder( name );

	// actually delete the folder
	bool32 result = RemoveDirectoryA( name );
	WIN64_ASSERT( result );
}

bool32 FS_FolderExists( const char *name ) {
	assert( name );

	DWORD attribs = GetFileAttributesA( name );

	return ( attribs != INVALID_FILE_ATTRIBUTES ) && ( ( attribs & FILE_ATTRIBUTE_DIRECTORY ) != 0 );
}

void FS_DeleteAllFilesInFolder( const char *name ) {
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

#endif // _WIN32
