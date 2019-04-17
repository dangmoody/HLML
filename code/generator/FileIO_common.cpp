#include "FileIO.h"

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
