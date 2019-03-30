#ifdef _MSC_VER
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#endif

#include "FileIO.h"

#if defined( _WIN32 )
#include "gen_common.h"

#include <Windows.h>

#include <stdio.h>

size_t FS_ReadEntireFile( const char* filename, char** outBuffer ) {
	FILE* file = fopen( filename, "rb" );
	if ( !file ) {
		printf( "ERROR: Unable to open %s.  That's rough man...\n", filename );
		return 0;
	}

	fseek( file, 0, SEEK_END );
	size_t length = static_cast<size_t>( ftell( file ) );
	fseek( file, 0, SEEK_SET );

	char* temp = new char[length + 1];
	*outBuffer = temp;

	size_t result = fread( temp, length, 1, file );
	if ( result == 0 ) {
		printf( "ERROR: Unable to read from file %s.  That's rough man...\n", filename );
		
		fclose( file );
		return 0;
	}
	temp[length] = 0;

	fclose( file );
	file = nullptr;

	return length;
}

bool FS_WriteToFile( const char* filename, const char* data, const size_t length ) {
	FILE* file = fopen( filename, "w" );
	if ( !file ) {
		printf( "ERROR: Unable to open %s.  That's rough man...\n", filename );
		return false;
	}

	size_t result = fwrite( data, length, 1, file );
	if ( result == 0 ) {
		printf( "ERROR: Unable to write to file %s.  That's rough man...\n", filename );

		fclose( file );
		file = nullptr;

		return false;
	}

	fclose( file );
	file = nullptr;

	return true;
}

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
	sprintf( filename, "%s\\*.*", name );

	WIN32_FIND_DATA info = {};
	HANDLE handle = FindFirstFile( filename, &info );
	do {
		sprintf( filename, "%s\\%s", name, info.cFileName );
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

bool FS_CleanFolder( const char* name ) {
	if ( FS_FolderExists( name ) ) {
		printf( "Old 'out' folder detected, cleaning...\n" );
		if ( !FS_DeleteFolder( name ) ) {
			printf( "ERROR deleting folder \"%s\".  That's rough man...\n", name );
			return false;
		}
	}

	if ( !FS_CreateFolder( name ) ) {
		printf( "ERROR re-creating folder \"%s\".  Something strange be happening on your machine...\n", name );
		return false;
	}

	return true;
}
#endif
