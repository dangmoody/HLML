#pragma once

#include <string>

//extern size_t	FS_ReadEntireFile( const char* filename, char** outBuffer );
extern bool		FS_WriteEntireFile( const char* filename, const char* data, const size_t length );

extern bool		FS_CreateFolder( const char* name );
extern bool		FS_DeleteFolder( const char* name );
extern bool		FS_FolderExists( const char* name );
extern bool		FS_CleanFolder( const char* name );
