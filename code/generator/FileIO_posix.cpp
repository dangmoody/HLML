#include "FileIO.h"

#if defined( __linux__ ) || defined( __APPLE__ )
#include <sys/types.h>
#include <sys/stat.h>

#include <dirent.h>
#include <unistd.h>

#include <string.h>

#include <assert.h>

#include <errno.h>

// TODO(DM): make folders recursively
bool FS_CreateFolder( const char* name ) {
	assert( name );

	int result = mkdir( name, ACCESSPERMS );

	if ( result != 0 ) {
		printf( "ERROR: Failed to create folder \"%s\".  Errno: %d\n", name, errno );
		return false;
	}

	return true;
}

bool FS_DeleteFolder( const char* name ) {
	assert( name );

//	printf( "Deleting folder %s...\n", name );

	int osResult = 0;
	bool result = false;

	DIR* dir = opendir( name );
	if ( !dir ) {
		printf( "ERROR: Failed to find directory \"%s\".  That's rough man...\n", name );
		return false;
	}

	struct dirent64* dirEntry = nullptr;

	while ( ( dirEntry = readdir64( dir ) ) != nullptr ) {
		// TODO(DM): move strcmp to StringEquals(a, b)
		if ( strcmp( dirEntry->d_name, "." ) == 0 || strcmp( dirEntry->d_name, ".." ) == 0 ) {
			continue;
		}

		char buffer[1024] = { 0 };
		snprintf( buffer, 1024, "%s/%s", name, dirEntry->d_name );

		struct stat info;

		osResult = stat( buffer, &info );
		if ( osResult != 0 ) {
			printf( "ERROR: Failed to get stat on \"%s\".  That's rough man...\n", name );
			return false;
		}

		if ( S_ISDIR( info.st_mode ) ) {
			result = FS_DeleteFolder( buffer );

			if ( !result ) {
				return false;
			}
		} else {
//			printf( "Deleting file %s...\n", dirEntry->d_name );

			// TODO(DM): write "FS_DeleteFileIfExists()"
			osResult = remove( buffer );

			if ( osResult != 0 ) {
				return false;
			}
		}
	}

	osResult = closedir( dir );
	if ( osResult != 0 ) {
		printf( "ERROR: Failed to close directory \"%s\".  That's rough man...\n", name );
		return false;
	}

	result = rmdir( name ) == 0;

	return result;
}

// TODO(DM): rename to "FS_IsFolder"
bool FS_FolderExists( const char* name ) {
	assert( name );

	struct stat info;

	int result = stat( name, &info );

	if ( result != 0 ) {
		printf( "ERROR: Failed to get stat on \"%s\".  That's rough man...\n", name );
		return false;
	}

	return S_ISDIR( info.st_mode );
}
#endif
