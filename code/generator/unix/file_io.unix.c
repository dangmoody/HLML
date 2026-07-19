/*
===========================================================================

HLML

Copyright (c) Dan Moody 2018 - Present.

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

#if defined( __linux__ ) || defined( __APPLE__ )

#include "../file_io.h"
#include "../string_helpers.h"
#include "../defines.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#pragma push_macro( "_POSIX_C_SOURCE" )
#undef _POSIX_C_SOURCE
#define _POSIX_C_SOURCE 200112L
#pragma clang diagnostic pop

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Weverything"
#include <stb/stb_sprintf.h>
#pragma clang diagnostic pop

#include <sys/types.h>
#include <sys/stat.h>

#include <linux/limits.h>

#include <dirent.h>
#include <unistd.h>
#include <errno.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

static void DeleteAllFilesInFolderInternal( DIR *dir, const char *dirName ) {
	assert( dir );
	assert( dirName );

	int osResult = 0;
	int err = 0;

	struct dirent *dirEntry = NULL;

	while ( ( dirEntry = readdir( dir ) ) != NULL ) {
		if ( String_Equals( dirEntry->d_name, "." ) || String_Equals( dirEntry->d_name, ".." ) ) {
			continue;
		}

		char buffer[PATH_MAX] = { 0 };
		stbsp_snprintf( buffer, 1024, "%s/%s", dirName, dirEntry->d_name );

		struct stat info;

		osResult = stat( buffer, &info );
		err = errno;
		if ( osResult != 0 ) {
			printf( "ERROR: Failed to get stat on \"%s\": %s\n", dirName, strerror( err ) );
			assert( false );
		}

		if ( S_ISDIR( info.st_mode ) ) {
			FS_DeleteFolder( buffer );
		} else {
//			printf( "Deleting file %s...\n", dirEntry->d_name );

			osResult = remove( buffer );
			if ( osResult != 0 ) {
				printf( "ERROR: Failed to delete file \"%s\".\n", buffer );
				assert( false );
			}
		}
	}
}


/*
File IO for Linux/MacOS

DM: we can't use functions like opendir64 because the MacOS VMs on Travis complain
I don't have a Mac so I can only test so much, but I'll assume it's legit unless I find out otherwise
*/

void FS_WriteEntireFile( const char *filename, const char *data, const size_t length ) {
	assert( filename );
	assert( data );
	assert( length );

	FILE *file = fopen( filename, "w" );
	if ( !file ) {
		printf( "ERROR: Unable to open %s.  That's rough man...\n", filename );
		assert( false );
	}

	size_t result = fwrite( data, length, 1, file );
	if ( result == 0 ) {
		printf( "ERROR: Unable to write to file %s.  That's rough man...\n", filename );

		fclose( file );
		file = NULL;

		assert( false );
	}

	fclose( file );
	file = NULL;
}

char *FS_ReadEntireFile( const char *filename, u64 *outLength ) {
	assert( filename );
	assert( outLength );

	*outLength = 0;

	FILE *file = fopen( filename, "rb" );
	if ( !file ) {
		return NULL;
	}

	fseek( file, 0, SEEK_END );
	long length = ftell( file );
	fseek( file, 0, SEEK_SET );

	if ( length < 0 ) {
		printf( "ERROR: Failed to get file size of \"%s\".\n", filename );

		fclose( file );

		assert( false );

		return NULL;
	}

	char *buffer = (char *) malloc( (u64) length + 1 );

	size_t bytesRead = fread( buffer, 1, (size_t) length, file );
	if ( bytesRead != (size_t) length ) {
		printf( "ERROR: Failed to read entire file \"%s\".\n", filename );

		fclose( file );

		assert( false );

		return NULL;
	}

	buffer[length] = 0;

	fclose( file );

	*outLength = (u64) length;

	return buffer;
}

void FS_FreeFileBuffer( char *buffer ) {
	free( buffer );
}

bool32 FS_FileExists( const char *filename ) {
	assert( filename );

	struct stat info;

	int result = stat( filename, &info );
	if ( result != 0 ) {
		return false;
	}

	return S_ISREG( info.st_mode );
}

bool32 FS_CreateFolder( const char *name ) {
	assert( name );

	int result = 0;
	int err = 0;

	size_t length = strlen( name );

	char path[PATH_MAX] = { 0 };
	stbsp_snprintf( path, sizeof( path ), "%s", name );

	if ( path[length - 1] == '/' ) {
		path[length - 1] = 0;
	}

	char *p = NULL;

	for ( p = path + 1; *p; p++ ) {
		if ( *p == '/' ) {
			*p = 0;

			result = mkdir( path, S_IRWXU | S_IRWXG | S_IRWXO );
			err = errno;
			if ( result != 0 ) {
				if ( err != EEXIST ) {
					printf( "ERROR: Failed to create directory \"%s\": %s\n", path, strerror( err ) );
					assert( false );
				}
			}

			*p = '/';
		}
	}

	result = mkdir( path, S_IRWXU | S_IRWXG | S_IRWXO );
	err = errno;
	if ( result != 0 ) {
		if ( err != EEXIST ) {
			printf( "ERROR: Failed to create directory \"%s\": %s\n", path, strerror( err ) );
			assert( false );
		}
	}

	return result == 0;
}

void FS_DeleteFolder( const char *name ) {
	assert( name );

//	printf( "Deleting folder %s...\n", name );

	int osResult = 0;
	int err = 0;

	bool result = false;

	DIR *dir = opendir( name );
	err = errno;
	if ( !dir ) {
		printf( "ERROR: Failed to find directory \"%s\": %s\n", name, strerror( err ) );
		assert( false );
	}

	DeleteAllFilesInFolderInternal( dir, name );

	osResult = closedir( dir );
	err = errno;
	if ( osResult != 0 ) {
		printf( "ERROR: Failed to close directory \"%s\": %s\n", name, strerror( err ) );
		assert( false );
	}

	result = rmdir( name ) == 0;

	assert( result );
	GEN_UNUSED( result );
}

bool32 FS_FolderExists( const char *name ) {
	assert( name );

	int err = 0;

	struct stat info;

	int result = stat( name, &info );
	err = errno;

	if ( result != 0 ) {
		printf( "ERROR: Failed to get stat on \"%s\": %s\n", name, strerror( err ) );
		return false;
	}

	return S_ISDIR( info.st_mode );
}

void FS_DeleteAllFilesInFolder( const char *name ) {
	assert( name );

	int err = 0;

	DIR *dir = opendir( name );
	err = errno;
	if ( !dir ) {
		printf( "ERROR: Failed to find directory \"%s\": %s\n", name, strerror( err ) );
		assert( false );
	}

	DeleteAllFilesInFolderInternal( dir, name );

	int osResult = closedir( dir );
	err = errno;
	if ( osResult != 0 ) {
		printf( "ERROR: Failed to close directory \"%s\": %s\n", name, strerror( err ) );
		assert( false );
	}
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#pragma pop_macro( "_POSIX_C_SOURCE" )
#pragma clang diagnostic pop

#endif // defined( __linux__ ) || defined( __APPLE__ )
