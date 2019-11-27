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

#include "file_io.h"

#include "string_helpers.h"

#include <sys/types.h>
#include <sys/stat.h>

#include <limits.h>

#include <dirent.h>
#include <unistd.h>
#include <errno.h>

#include <stdio.h>
#include <string.h>
#include <assert.h>

static void DeleteAllFilesInFolderInternal( DIR* dir, const char* dirName ) {
	assert( dir );
	assert( dirName );

	int osResult = 0;

	struct dirent* dirEntry = nullptr;

	while ( ( dirEntry = readdir( dir ) ) != nullptr ) {
		if ( StringEquals( dirEntry->d_name, "." ) || StringEquals( dirEntry->d_name, ".." ) ) {
			continue;
		}

		char buffer[PATH_MAX] = { 0 };
		snprintf( buffer, 1024, "%s/%s", dirName, dirEntry->d_name );

		struct stat info;

		osResult = stat( buffer, &info );
		if ( osResult != 0 ) {
			int err = errno;
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
		file = nullptr;

		assert( false );
	}

	fclose( file );
	file = nullptr;
}

void FS_CreateFolder( const char* name ) {
	assert( name );

	int result = 0;

	size_t length = strlen( name );

	char path[PATH_MAX] = { 0 };
	snprintf( path, sizeof( path ), "%s", name );

	if ( path[length - 1] == '/' ) {
		path[length - 1] = 0;
	}

	char* p = nullptr;

	for ( p = path + 1; *p; p++ ) {
		if ( *p == '/' ) {
			*p = 0;

			result = mkdir( path, ACCESSPERMS );
			if ( result != 0 ) {
				int err = errno;
				if ( err != EEXIST ) {
					printf( "ERROR: Failed to create directory \"%s\": %s\n", path, strerror( err ) );
					assert( false );
				}
			}

			*p = '/';
		}
	}

	result = mkdir( path, ACCESSPERMS );
	if ( result != 0 ) {
		int err = errno;
		if ( err != EEXIST ) {
			printf( "ERROR: Failed to create directory \"%s\": %s\n", path, strerror( err ) );
			assert( false );
		}
	}
}

void FS_DeleteFolder( const char* name ) {
	assert( name );

//	printf( "Deleting folder %s...\n", name );

	int osResult = 0;
	bool result = false;

	DIR* dir = opendir( name );
	if ( !dir ) {
		int err = errno;
		printf( "ERROR: Failed to find directory \"%s\": %s\n", name, strerror( err ) );
		assert( false );
	}

	DeleteAllFilesInFolderInternal( dir, name );

	osResult = closedir( dir );
	if ( osResult != 0 ) {
		int err = errno;
		printf( "ERROR: Failed to close directory \"%s\": %s\n", name, strerror( err ) );
		assert( false );
	}

	result = rmdir( name ) == 0;

	assert( result );
}

bool32 FS_FolderExists( const char* name ) {
	assert( name );

	struct stat info;

	int result = stat( name, &info );

	if ( result != 0 ) {
		int err = errno;
		printf( "ERROR: Failed to get stat on \"%s\": %s\n", name, strerror( err ) );
		return false;
	}

	return S_ISDIR( info.st_mode );
}

void FS_DeleteAllFilesInFolder( const char* name ) {
	assert( name );

	DIR* dir = opendir( name );
	if ( !dir ) {
		int err = errno;
		printf( "ERROR: Failed to find directory \"%s\": %s\n", name, strerror( err ) );
		assert( false );
	}

	DeleteAllFilesInFolderInternal( dir, name );

	int osResult = closedir( dir );
	if ( osResult != 0 ) {
		int err = errno;
		printf( "ERROR: Failed to close directory \"%s\": %s\n", name, strerror( err ) );
		assert( false );
	}
}

#endif // defined( __linux__ ) || defined( __APPLE__ )
