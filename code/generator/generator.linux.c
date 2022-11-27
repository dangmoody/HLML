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
#if defined( __linux__ ) || defined( __APPLE__ )

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

#include "file_io.h"
#include "timer.h"
#include "string_helpers.h"
#include "defines.h"

#include <sys/types.h>
#include <sys/stat.h>

#include <linux/limits.h>

#include <dirent.h>
#include <unistd.h>
#include <errno.h>

#include <time.h>

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

static void DeleteAllFilesInFolderInternal( DIR* dir, const char* dirName ) {
	assert( dir );
	assert( dirName );

	int osResult = 0;
	int err = 0;

	struct dirent* dirEntry = NULL;

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

void FS_WriteEntireFile( const char* filename, const char* data, const size_t length ) {
	assert( filename );
	assert( data );
	assert( length );

	FILE* file = fopen( filename, "w" );
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

bool32 FS_CreateFolder( const char* name ) {
	assert( name );

	int result = 0;
	int err = 0;

	size_t length = strlen( name );

	char path[PATH_MAX] = { 0 };
	stbsp_snprintf( path, sizeof( path ), "%s", name );

	if ( path[length - 1] == '/' ) {
		path[length - 1] = 0;
	}

	char* p = NULL;

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

void FS_DeleteFolder( const char* name ) {
	assert( name );

//	printf( "Deleting folder %s...\n", name );

	int osResult = 0;
	int err = 0;

	bool result = false;

	DIR* dir = opendir( name );
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

bool32 FS_FolderExists( const char* name ) {
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

void FS_DeleteAllFilesInFolder( const char* name ) {
	assert( name );

	int err = 0;

	DIR* dir = opendir( name );
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

/*
Timer for Linux/MacOS

DM: this seems to be the best implementation I can get on linux
multiplying each resultant second by the constant seems wrong though
I don't like how Time_Now() actually returns nano seconds when it should return clock cycles but I don't have a dedicated linux PC or a Mac so I'm not sure I can totally trust my test results
but its the best I can do all things considered and it looks close enough to me
if I'm wrong and someone can fix/improve this then please do
*/

#define GEN_CLOCK_MOD 1000000000

s64 Time_Now( void ) {
	struct timespec now;
	clock_gettime( CLOCK_MONOTONIC, &now );

	return (s64) ( now.tv_sec * GEN_CLOCK_MOD + now.tv_nsec );
}

float64 Time_NowSeconds( void ) {
	s64 time = Time_Now();
	return (float64) time / 1000000000.0;
}

float64 Time_NowMS( void ) {
	s64 time = Time_Now();
	return (float64) time / 1000000.0;
}

float64 Time_NowUS( void ) {
	s64 time = Time_Now();
	return (float64) time / 1000.0;
}

float64 Time_NowNS( void ) {
	s64 time = Time_Now();
	return (float64) time;
}

#undef GEN_CLOCK_MOD

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreserved-id-macro"
#pragma pop_macro( "_POSIX_C_SOURCE" )
#pragma clang diagnostic pop

#endif // defined( __linux__ ) || defined( __APPLE__ )