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
#pragma once

#include "int_types.h"

/*
FIle IO

Must be done completely per-platform because Windows requires shared R/W access
to all of the files that it touches.

Linux/MacOS implementation does make heavy use of POSIX file IO functions
because they work fine there.
*/

extern void		FS_WriteEntireFile( const char* filename, const char* data, const size_t length );

extern void		FS_CreateFolder( const char* name );
extern void		FS_DeleteFolder( const char* name );
extern bool32	FS_FolderExists( const char* name );
extern void		FS_DeleteAllFilesInFolder( const char* name );
