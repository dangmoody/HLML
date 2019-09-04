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
