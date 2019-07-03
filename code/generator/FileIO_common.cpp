#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "FileIO.h"

#include <stdio.h>

bool FS_WriteEntireFile( const char* filename, const char* data, const size_t length ) {
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

bool FS_CleanFolder( const char* name ) {
	if ( FS_FolderExists( name ) ) {
		printf( "Old '%s' folder detected, cleaning...\n", name );
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
