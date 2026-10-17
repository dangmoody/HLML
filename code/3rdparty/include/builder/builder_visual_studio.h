/*
===========================================================================

Builder

Distributed under MIT License:
Copyright (c) 2026 Dan Moody

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


CONTENTS:
	1. QUICK START GUIDE


1. QUICK START GUIDE
Builder can be used to generate Visual Studio Solutions (.sln and .vcxproj).  These are also compatible with Rider:

	#define BUILDER_IMPLEMENTATION
	#include "builder.h"

	#define BUILDER_VISUAL_STUDIO_IMPLEMENTATION
	#include "builder_visual_studio.h"

	int main( int argc, char **argv ) {
		BuilderOptions options = { 0 };

		BuildConfig *config = CreateBuildConfig( &options );
		*config = (BuildConfig) {
			.name			= "my_awesome_program",
			.sourceFiles	= MakeStringList( "src/my_code.c" ),
		};

		options.defaultConfig = config;

		if ( HasCommandLineArg( argc, argv, "--sln" ) ) {
			VisualStudioConfig vsConfigs[] = {
				{ .name = "Debug",   .config = config },
				{ .name = "Release", .config = config, .additionalBuildArgs = MakeStringList( "--release" ) },
			};

			VisualStudioProject vsProjects[] = {
				{
					.name			= "my_awesome_program",
					.configs		= vsConfigs,
					.configsCount	= BUILDER_COUNT_OF( vsConfigs ),
				},
			};

			VisualStudioSolution solution = {
				.name			= "my_awesome_program",
				.platforms		= MakeStringList( "x64" ),
				.projects		= vsProjects,
				.projectsCount	= BUILDER_COUNT_OF( vsProjects ),
			};

			return Builder_GenerateVisualStudioSolution( &options, &solution, argc, argv ) ? 0 : 1;
		}

		return Build( &options, argc, argv );
	}

You'd then generate the solution with:

	build.exe --sln

Generated projects will call to your build.exe.

===========================================================================
*/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#include "builder.h"

typedef struct VisualStudioConfig {
	// The name of the config as it appears in Visual Studio.
	// This is different from BuildConfig::name because this one doesn't have to be unique.
	// You can have lots of VisualStudioConfigs with a name of "Debug", for instance.
	const char	*name;

	// When you build this Visual Studio config, what BuildConfig do you want to build?
	BuildConfig	*config;

	// Overrides the NMakeOutput field (and the LocalDebuggerCommand, since they're the same binary) in the generated project.
	// Use this if this VisualStudioConfig shares a BuildConfig with another VisualStudioConfig whose output path differs
	// (e.g. one BuildConfig reused for both Debug and Release via additionalBuildArgs), since BuildConfig::binaryFolder
	// can only hold one value at generation time.
	// If not set, defaults to config->binaryFolder + config->binaryName.
	const char	*nmakeOutput;

	// By default Builder will generate the following for the Visual Studio NMakeBuildCommandLine:
	//
	//	<your_build_script> --config=<your_config>
	//
	// Use this if you want any other command line arguments to be added to the end.
	StringList	additionalBuildArgs;

	// Default debugger command line arguments.
	StringList	debuggerArguments;

	// The directory you want to set as the CWD when running this config.
	// Defaults to $(SolutionDir) if not set.
	const char	*runFromDirectory;
} VisualStudioConfig;

typedef struct VisualStudioProject {
	// Configs that this project knows about.
	// For example: Debug, Profiling, Shipping, and so on.
	// You must define at least one of these to make Visual Studio happy.
	VisualStudioConfig	*configs;
	uint32_t			configsCount;

	// Any additional files that you want to include in your project.
	// For example your build config may declare "./src/**/*.cpp" but you might also want "./src/**/*.h" in your project.
	// Any files/paths you add to this are relative to the current working directory, same as BuildConfig::sourceFiles.
	// Also supports wildcards.
	// Build it with MakeStringList().
	StringList			extraFiles;

	// The name of the project as it shows in Visual Studio.
	// Give this a name like "games/shooter" if you want the project to be nested inside solution folders in the Solution Explorer.
	const char			*name;
} VisualStudioProject;

typedef struct VisualStudioSolution {
	// All the projects in the Solution.
	VisualStudioProject	*projects;
	uint32_t			projectsCount;

	// All the target platforms that this Solution supports.
	// NULL-terminated array.
	StringList			platforms;

	// The name of the Solution as it appears in Visual Studio.
	// For the sake of simplicity we keep the name of the Solution in Visual Studio and the Solution's filename the same.
	const char			*name;

	// The folder where the solution (and its projects) are going to live, relative to the current working directory.
	// If you don't set this then the solution is generated in the current working directory.
	const char			*path;

	// The command that Visual Studio will invoke when building - this is your build script's own compiled binary
	// (there is no separate standalone "Builder" executable).
	// If this is a relative path, it's relative to your build executable.
	// Leave NULL to default to the absolute path of your build executable.
	const char			*buildCommand;
} VisualStudioSolution;

bool	Builder_GenerateVisualStudioSolution( BuilderOptions *options, VisualStudioSolution *solution, int argc, char **argv );


#ifdef BUILDER_VISUAL_STUDIO_IMPLEMENTATION

#if !defined( BUILDER_IMPLEMENTATION )
#error "BUILDER_VISUAL_STUDIO_IMPLEMENTATION requires BUILDER_IMPLEMENTATION to also be defined, and \"builder.h\" to be included before \"builder_visual_studio.h\", in this translation unit."
#endif

#if defined( __linux__ )
#include <uuid/uuid.h>	// requires linking against libuuid (-luuid)
#endif

static char *Builder_VSFixSlashes( arena_t *arena, const char *path ) {
	size_t length = strlen( path );
	char *result = Builder_ArenaAlloc( arena, char, length + 1 );

	for ( size_t charIndex = 0; charIndex < length; charIndex++ ) {
		char c = path[charIndex];
#if defined( _WIN32 )
		result[charIndex] = ( c == '/') ? BUILDER_PATH_SEPARATOR : c;
#elif defined( __linux__ )
		result[charIndex] = ( c == '\\' ) ? BUILDER_PATH_SEPARATOR : c;
#endif
	}

	result[length] = 0;

	return result;
}

// computes the relative path from 'from' to 'to'
// 'from' is treated as a directory unless its last path segment contains a dot
// in which case its treated as a file and only its containing directory is used
static char *Builder_RelativePathTo( arena_t *results, const char *from, const char *to ) {
	BUILDER_ASSERT( from );
	BUILDER_ASSERT( to );

	scratch_t scratch = Builder_GetScratch( results );

	char *fromFixed = Builder_VSFixSlashes( scratch.arena, from );
	char *toFixed = Builder_VSFixSlashes( scratch.arena, to );

	size_t fromLength = strlen( fromFixed );

	// determine the directory part of 'from'
	// if the last path segment contains a dot then treat it as a filename and strip it
	// otherwise treat the whole path as a directory and ensure it ends with a separator
	char *fromDir;
	{
		const char *lastSeparator = strrchr( fromFixed, BUILDER_PATH_SEPARATOR );
		const char *lastSegmentStart = lastSeparator ? lastSeparator + 1 : fromFixed;

		bool lastSegmentHasDot = strchr( lastSegmentStart, '.' ) != NULL;

		if ( lastSegmentHasDot ) {
			size_t dirLength = lastSeparator ? (size_t) ( lastSeparator - fromFixed ) + 1 : 0;
			fromDir = Builder_ArenaAlloc( scratch.arena, char, dirLength + 1 );
			memcpy( fromDir, fromFixed, dirLength );
			fromDir[dirLength] = 0;
		} else if ( fromLength > 0 && fromFixed[fromLength - 1] == BUILDER_PATH_SEPARATOR ) {
			fromDir = fromFixed;
		} else {
			fromDir = Builder_FormatString( scratch.arena, "%s%c", fromFixed, BUILDER_PATH_SEPARATOR );
		}
	}

	// walk both paths simultaneously recording the end of the last complete segment that matched (right after a separator)
	uint64_t common = 0;
	uint64_t charIndex = 0;

	while ( fromDir[charIndex] && toFixed[charIndex] && fromDir[charIndex] == toFixed[charIndex] ) {
		charIndex++;

		if ( fromDir[charIndex - 1] == BUILDER_PATH_SEPARATOR ) {
			common = charIndex;
		}
	}

	// if one path ends exactly at a segment boundary in the other then include that boundary
	if ( fromDir[charIndex] == BUILDER_PATH_SEPARATOR && toFixed[charIndex] == '\0' ) {
		common = charIndex;
	} else if ( fromDir[charIndex] == '\0' && toFixed[charIndex] == BUILDER_PATH_SEPARATOR ) {
		common = charIndex;
	} else if ( fromDir[charIndex] == '\0' && toFixed[charIndex] == '\0' ) {
		common = charIndex;
	}

	// count directory segments remaining in fromDir after the common prefix
	// the character at 'common' is the boundary separator itself
	// skip it so we dont count it as an extra level
	uint64_t countStart = common;
	if ( fromDir[countStart] == BUILDER_PATH_SEPARATOR ) {
		countStart++;
	}

	uint64_t numBacks = 0;

	for ( uint64_t charPos = countStart; fromDir[charPos]; charPos++ ) {
		if ( fromDir[charPos] == BUILDER_PATH_SEPARATOR ) {
			numBacks++;
		}
	}

	stringBuilder_t sb = {};

	for ( uint64_t backIndex = 0; backIndex < numBacks; backIndex++ ) {
		bool isLast = ( backIndex == numBacks - 1 );

		if ( !isLast || toFixed[common] != 0 ) {
			StringBuilder_Appendf( results, &sb, "..%c", BUILDER_PATH_SEPARATOR );
		} else {
			StringBuilder_Appendf( results, &sb, ".." );
		}
	}

	StringBuilder_Appendf( results, &sb, "%s", toFixed + common );

	char *result = StringBuilder_ToString( results, &sb, NULL );

	Builder_RewindScratch( &scratch );

	return result;
}

// data layout comes from: https://learn.microsoft.com/en-us/windows/win32/api/guiddef/ns-guiddef-guid
static const char *Builder_CreateVisualStudioGuid( arena_t *arena ) {
#if defined( _WIN32 )
	GUID guid;
	HRESULT hr = CoCreateGuid( &guid );
	BUILDER_ASSERT( hr == S_OK );

	return Builder_FormatString( arena, "%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
		guid.Data1, guid.Data2, guid.Data3,
		guid.Data4[0], guid.Data4[1], guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7] );
#elif defined( __linux__ )
	const uint64_t guidStringLength = 37;
	char *guidString = Builder_ArenaAlloc( arena, char, guidStringLength );

	uuid_t uuid;
	uuid_generate( uuid );
	uuid_unparse_upper( uuid, guidString );

	return guidString;
#else
#error Unrecognised platform.
#endif
}

static char *Builder_VSGetAppPath( arena_t *arena ) {
#if defined( _WIN32 )
	char buffer[BUILDER_MAX_PATH];
	DWORD length = GetModuleFileNameA( NULL, buffer, BUILDER_MAX_PATH );
	BUILDER_ASSERT( length > 0 && length < BUILDER_MAX_PATH );

	return Builder_FormatString( arena, "%.*s", (int) length, buffer );
#elif defined( __linux__ )
	char buffer[BUILDER_MAX_PATH];
	ssize_t length = readlink( "/proc/self/exe", buffer, sizeof( buffer ) - 1 );
	BUILDER_ASSERT( length > 0 );

	return Builder_FormatString( arena, "%.*s", (int) length, buffer );
#else
#error Unrecognised platform.
#endif
}

static bool Builder_PathIsAbsolute( const char *path ) {
	if ( Builder_StringIsEmpty( path ) ) {
		return false;
	}

#if defined( _WIN32 )
	return ( isalpha( (unsigned char) path[0] ) && path[1] == ':' ) || path[0] == '\\' || path[0] == '/';
#elif defined( __linux__ )
	return path[0] == '/';
#else
#error Unrecognised platform.
#endif
}

// pointer to the last '/' or '\\' in path (or NULL if it has no path separator at all)
static const char *Builder_VSFindLastSeparator( const char *path ) {
	const char *lastSeparator = NULL;

	for ( const char *c = path; *c; c++ ) {
		if ( *c == '/' || *c == '\\' ) {
			lastSeparator = c;
		}
	}

	return lastSeparator;
}

static bool Builder_VSIsSourceFile( const char *path ) {
	static const char *sourceExtensions[] = { ".c", ".cpp", ".cc", ".cxx" };

	for ( size_t i = 0; i < BUILDER_COUNT_OF( sourceExtensions ); i++ ) {
		if ( Builder_PathEndsWith( path, sourceExtensions[i] ) ) {
			return true;
		}
	}

	return false;
}

static bool Builder_VSIsHeaderFile( const char *path ) {
	static const char *headerExtensions[] = { ".h", ".hpp", ".hh", ".hxx", ".inl" };

	for ( size_t i = 0; i < BUILDER_COUNT_OF( headerExtensions ); i++ ) {
		if ( Builder_PathEndsWith( path, headerExtensions[i] ) ) {
			return true;
		}
	}

	return false;
}

typedef struct visualStudioFile_t {
	const char	*filePath;		// as given by the user - relative to the current working directory, or absolute
	const char	*filterFolder;	// folder shown in the Solution Explorer filters, or NULL if this file isnt grouped into one
} visualStudioFile_t;

typedef struct visualStudioFileList_t {
	visualStudioFile_t	*files;
	uint32_t			count;
} visualStudioFileList_t;

typedef struct visualStudioFilterPathList_t {
	const char	**paths;
	uint32_t	count;
} visualStudioFilterPathList_t;

static void Builder_VSAddFileUnique( arena_t *arena, visualStudioFileList_t *fileList, visualStudioFilterPathList_t *filterPaths, const char *file ) {
	for ( uint32_t fileIndex = 0; fileIndex < fileList->count; fileIndex++ ) {
		if ( Builder_StringEquals( fileList->files[fileIndex].filePath, file ) ) {
			return;
		}
	}

	const char *filterFolder = NULL;

	if ( !Builder_PathIsAbsolute( file ) ) {
		const char *lastSeparator = Builder_VSFindLastSeparator( file );

		if ( lastSeparator ) {
			size_t folderLength = (size_t) ( lastSeparator - file );
			char *folder = Builder_ArenaAlloc( arena, char, folderLength + 1 );
			memcpy( folder, file, folderLength );
			folder[folderLength] = 0;

			// visual studio wants backslashes in filter names regardless of host platform
			for ( char *c = folder; *c; c++ ) {
				if ( *c == '/' ) {
					*c = '\\';
				}
			}

			uint32_t filterIndex = 0;
			for ( ; filterIndex < filterPaths->count; filterIndex++ ) {
				if ( Builder_StringEquals( filterPaths->paths[filterIndex], folder ) ) {
					break;
				}
			}

			if ( filterIndex == filterPaths->count ) {
				filterPaths->paths = Builder_ArenaRealloc( arena, filterPaths->paths, const char *, filterPaths->count, filterPaths->count + 1 );
				filterPaths->paths[filterPaths->count] = folder;
				filterPaths->count++;
			}

			filterFolder = filterPaths->paths[filterIndex];
		}
	}

	fileList->files = Builder_ArenaRealloc( arena, fileList->files, visualStudioFile_t, fileList->count, fileList->count + 1 );
	fileList->files[fileList->count] = (visualStudioFile_t) { .filePath = file, .filterFolder = filterFolder };
	fileList->count++;
}

static void Builder_VSAddFilesFromPatterns( arena_t *arena,
											visualStudioFileList_t *sourceFiles,
											visualStudioFileList_t *headerFiles,
											visualStudioFileList_t *otherFiles,
											visualStudioFilterPathList_t *filterPaths,
											const StringList *filePatterns,
											const BuilderOptions *options )
{
	if ( !filePatterns ) {
		return;
	}

	StringList globResult = Builder_GlobFiles( arena, filePatterns, options );

	for ( builderStringChunk_t *chunk = globResult.head; chunk; chunk = chunk->next ) {
		for ( uint32_t fileIndex = 0; fileIndex < chunk->count; fileIndex++ ) {
			const char *file = chunk->items[fileIndex];

			if ( Builder_VSIsSourceFile( file ) ) {
				Builder_VSAddFileUnique( arena, sourceFiles, filterPaths, file );
			} else if ( Builder_VSIsHeaderFile( file ) ) {
				Builder_VSAddFileUnique( arena, headerFiles, filterPaths, file );
			} else {
				Builder_VSAddFileUnique( arena, otherFiles, filterPaths, file );
			}
		}
	}
}

typedef struct visualStudioProjectFolder_t {
	const char	*name;
	uint32_t	guidIndex;
} visualStudioProjectFolder_t;

typedef struct visualStudioGuidParentMapping_t {
	uint32_t	guidIndex;
	uint32_t	guidParentIndex;
} visualStudioGuidParentMapping_t;

#define BUILDER_VS_INVALID_GUID_INDEX	UINT32_MAX

// carries everything the .sln needs to know about GUIDs
// one per project plus one per solution folder discovered along the way, the folders themselves, and which guid nests inside which (for the SLNs NestedProjects section)
typedef struct visualStudioSolutionBuildState_t {
	arena_t							*arena;

	const char						**projectGuids;
	uint32_t						projectGuidsCount;

	visualStudioProjectFolder_t		*folders;
	uint32_t						foldersCount;

	visualStudioGuidParentMapping_t	*mappings;
	uint32_t						mappingsCount;
} visualStudioSolutionBuildState_t;

static uint32_t Builder_VSAddGuid( visualStudioSolutionBuildState_t *state ) {
	const char *guid = Builder_CreateVisualStudioGuid( state->arena );

	uint32_t guidIndex = state->projectGuidsCount;

	state->projectGuids = Builder_ArenaRealloc( state->arena, state->projectGuids, const char *, state->projectGuidsCount, state->projectGuidsCount + 1 );
	state->projectGuids[guidIndex] = guid;
	state->projectGuidsCount++;

	return guidIndex;
}

// the projects display name in visual studio
// everything after the last folder separator (e.g. "games/shooter" -> "shooter")
static const char *Builder_VSGetProjectDisplayName( const char *projectName ) {
	const char *lastSeparator = Builder_VSFindLastSeparator( projectName );

	return lastSeparator ? lastSeparator + 1 : projectName;
}

// full path to the binary this Visual Studio config builds/debugs
// respects VisualStudioConfig::nmakeOutput if set, otherwise derives it from config->config
static const char *Builder_VSGetFullBinaryPath( arena_t *arena, VisualStudioConfig *config ) {
	if ( !Builder_StringIsEmpty( config->nmakeOutput ) ) {
		return config->nmakeOutput;
	}

	BuildConfig *buildConfig = config->config;
	const char *extension = Builder_GetFileExtensionFromBinaryType( buildConfig->binaryType );

	if ( buildConfig->binaryFolder ) {
		return Builder_FormatString( arena, "%s%c%s%s", buildConfig->binaryFolder, BUILDER_PATH_SEPARATOR, buildConfig->binaryName, extension );
	}

	return Builder_FormatString( arena, "%s%s", buildConfig->binaryName, extension );
}

typedef struct visualStudioNukeFolderState_t {
	const char	**folders;
	uint32_t	foldersCount;
} visualStudioNukeFolderState_t;

static void Builder_VSNukeCollectCallback( arena_t *resultsArena, fileInfo_t *fileInfo, void *userData ) {
	visualStudioNukeFolderState_t *state = (visualStudioNukeFolderState_t *) userData;

	if ( fileInfo->isDirectory ) {
		state->folders = Builder_ArenaRealloc( resultsArena, state->folders, const char *, state->foldersCount, state->foldersCount + 1 );
		state->folders[state->foldersCount] = fileInfo->fullFilename;
		state->foldersCount++;
		return;
	}

#if defined( _WIN32 )
	DeleteFileA( fileInfo->fullFilename );
#elif defined( __linux__ )
	unlink( fileInfo->fullFilename );
#endif
}

typedef struct visualStudioDeleteOldFilesState_t {
	char	*dotVSFolder;	// set (arena-allocated) if a ".vs" folder was found alongside the project files
} visualStudioDeleteOldFilesState_t;

static void Builder_VSDeleteOldProjectFilesCallback( arena_t *resultsArena, fileInfo_t *fileInfo, void *userData ) {
	visualStudioDeleteOldFilesState_t *state = (visualStudioDeleteOldFilesState_t *) userData;

	if ( fileInfo->isDirectory ) {
		if ( Builder_StringEquals( fileInfo->filename, ".vs" ) ) {
			size_t length = strlen( fileInfo->fullFilename );
			state->dotVSFolder = Builder_ArenaAlloc( resultsArena, char, length + 1 );
			memcpy( state->dotVSFolder, fileInfo->fullFilename, length + 1 );
		}

		return;
	}

	static const char *extensionsToDelete[] = { ".sln", ".vcxproj", ".vcxproj.user", ".vcxproj.filters" };

	for ( size_t extensionIndex = 0; extensionIndex < BUILDER_COUNT_OF( extensionsToDelete ); extensionIndex++ ) {
		if ( Builder_PathEndsWith( fileInfo->fullFilename, extensionsToDelete[extensionIndex] ) ) {
#if defined( _WIN32 )
			bool deleted = DeleteFileA( fileInfo->fullFilename ) != 0;
#elif defined( __linux__ )
			bool deleted = unlink( fileInfo->fullFilename ) == 0;
#endif
			if ( !deleted ) {
				Builder_Warning( "Failed to delete old Visual Studio file \"%s\" while deleting old Visual Studio files.  You will have to delete this one yourself.  Sorry.\n", fileInfo->fullFilename );
			}

			break;
		}
	}
}

// writes files as a flat <ItemGroup> of <tag Include="..." />, with Include paths made relative to projectFilesPath
static void Builder_VSWriteFileGroup( arena_t *arena, stringBuilder_t *sb, const visualStudioFileList_t *fileList, const char *tag, const char *projectFilesPath ) {
	if ( fileList->count == 0 ) {
		return;
	}

	StringBuilder_Appendf( arena, sb, "\t<ItemGroup>\n" );

	for ( uint32_t fileIndex = 0; fileIndex < fileList->count; fileIndex++ ) {
		const char *file = fileList->files[fileIndex].filePath;
		const char *includePath = Builder_PathIsAbsolute( file ) ? file : Builder_RelativePathTo( arena, projectFilesPath, file );

		StringBuilder_Appendf( arena, sb, "\t\t<%s Include=\"%s\" />\n", tag, includePath );
	}

	StringBuilder_Appendf( arena, sb, "\t</ItemGroup>\n" );
}

// writes files grouped by their filter folder, with Include paths made relative to projectFilesPath - used for the .vcxproj.filters
static void Builder_VSWriteFileFilters( arena_t *arena, stringBuilder_t *sb, const visualStudioFileList_t *fileList, const char *tag, const char *projectFilesPath ) {
	if ( fileList->count == 0 ) {
		return;
	}

	StringBuilder_Appendf( arena, sb, "\t<ItemGroup>\n" );

	for ( uint32_t fileIndex = 0; fileIndex < fileList->count; fileIndex++ ) {
		const visualStudioFile_t *file = &fileList->files[fileIndex];
		const char *includePath = Builder_PathIsAbsolute( file->filePath ) ? file->filePath : Builder_RelativePathTo( arena, projectFilesPath, file->filePath );

		if ( !file->filterFolder ) {
			StringBuilder_Appendf( arena, sb, "\t\t<%s Include=\"%s\" />\n", tag, includePath );
		} else {
			StringBuilder_Appendf( arena, sb, "\t\t<%s Include=\"%s\">\n", tag, includePath );
			StringBuilder_Appendf( arena, sb, "\t\t\t<Filter>%s</Filter>\n", file->filterFolder );
			StringBuilder_Appendf( arena, sb, "\t\t</%s>\n", tag );
		}
	}

	StringBuilder_Appendf( arena, sb, "\t</ItemGroup>\n" );
}

bool Builder_GenerateVisualStudioSolution( BuilderOptions *options, VisualStudioSolution *solution, int argc, char **argv ) {
	BUILDER_ASSERT( options );
	BUILDER_ASSERT( solution );

	Builder_SetCmdArgs( options, argc, argv );

	Builder_SetCWD( options, argv );

	// validate the solution
	{
		bool validSolution = true;

		if ( Builder_StringIsEmpty( solution->name ) ) {
			Builder_Error( "You never set the name of the solution.  I need that.\n" );
			validSolution = false;
		}

		if ( solution->platforms.count == 0 ) {
			Builder_Error( "You must set at least one platform when generating a Visual Studio Solution.\n" );
			validSolution = false;
		}

		if ( solution->projectsCount < 1 ) {
			Builder_Error( "As well as a Solution, you must also generate at least one Visual Studio Project to go with it.\n" );
			validSolution = false;
		}

		if ( !validSolution ) {
			return false;
		}

		// validate platforms
		// turns out visual studio REALLY cares what the names of the platforms are
		// if you specify "Win32" or "x64" as a platform name then VS is able to generate defaults for your project which include things like Windows SDK directories and your PATH
		{
			static const char *defaultPlatformNames[] = { "Win32", "x64", "linux-x64" };

			bool foundDefaultPlatformName = false;

			for ( builderStringChunk_t *chunk = solution->platforms.head; chunk; chunk = chunk->next ) {
				for ( uint32_t platformIndex = 0; platformIndex < chunk->count; platformIndex++ ) {
					const char *platform = chunk->items[platformIndex];

					for ( size_t defaultPlatformIndex = 0; defaultPlatformIndex < BUILDER_COUNT_OF( defaultPlatformNames ); defaultPlatformIndex++ ) {
						if ( Builder_StringEquals( platform, defaultPlatformNames[defaultPlatformIndex] ) ) {
							foundDefaultPlatformName = true;
							break;
						}
					}
				}
			}

			if ( !foundDefaultPlatformName ) {
				scratch_t errorScratch = Builder_GetScratch( NULL );

				stringBuilder_t error = {};

				StringBuilder_Appendf( errorScratch.arena, &error, "None of your platform names are any of the Visual Studio recognized defaults:\n" );
				for ( size_t defaultPlatformIndex = 0; defaultPlatformIndex < BUILDER_COUNT_OF( defaultPlatformNames ); defaultPlatformIndex++ ) {
					StringBuilder_Appendf( errorScratch.arena, &error, "\t- %s\n", defaultPlatformNames[defaultPlatformIndex] );
				}
				StringBuilder_Appendf( errorScratch.arena, &error, "Visual Studio relies on those specific names in order to generate fields like \"Executable Path\" properly (for example).\n" );
				StringBuilder_Appendf( errorScratch.arena, &error, "Builder will still generate the solution, but know that not setting at least one platform name to any of these defaults will cause certain fields in the property pages of your Visual Studio project to not be correct.\n" );
				StringBuilder_Appendf( errorScratch.arena, &error, "You have been warned.\n" );

				Builder_Warning( "%s", StringBuilder_ToString( errorScratch.arena, &error, NULL ) );

				Builder_RewindScratch( &errorScratch );
			}
		}
	}

	BUILDER_ASSERT( argc > 0 && argv );

	scratch_t scratch = Builder_GetScratch( NULL );

	const char *projectFilesPath = !Builder_StringIsEmpty( solution->path ) ? solution->path : ".";

	// default to the absolute path of the running executable rather than argv[0]
	// argv[0] can be a bare relative name like "build.exe" that only resolved because of how/where this program happened to be launched from
	// which wont mean anything once Visual Studio invokes it from the .vcxproj own folder
	// an explicit override is trusted as given even if its relative
	const char *rawBuildCommand = !Builder_StringIsEmpty( solution->buildCommand ) ? solution->buildCommand : Builder_VSGetAppPath( scratch.arena );
	const char *buildCommand = Builder_PathIsAbsolute( rawBuildCommand ) ? rawBuildCommand : Builder_RelativePathTo( scratch.arena, projectFilesPath, rawBuildCommand );

	// NMake command lines run with the .vcxproj own folder as their working directory
	// but the build script itself expects to see its own folder as its working directory
	// (e.g. for BuildConfig::sourceFiles and the self-rebuild check)
	// so cd into wherever buildCommand actually lives before invoking it
	const char *buildCommandDir;
	{
		const char *lastSeparator = Builder_VSFindLastSeparator( buildCommand );

		buildCommandDir = lastSeparator ? Builder_FormatString( scratch.arena, "%.*s", (int) ( lastSeparator - buildCommand ), buildCommand ) : ".";
	}

	// delete old VS files if they exist but keep the root because were about to repopulate it
	if ( Builder_FolderExists( projectFilesPath ) ) {
		visualStudioDeleteOldFilesState_t deleteState = {};

		Builder_VisitFiles( scratch.arena, projectFilesPath, BUILDER_FILE_VISIT_FILES | BUILDER_FILE_VISIT_FOLDERS, Builder_VSDeleteOldProjectFilesCallback, &deleteState );

		// deletes everything inside the ".vs" folder, then the folder itself
		// folders are removed deepest first
		// Builder_VisitFiles() walks breadth-first so a folder is always collected before its own children are
		// delete all files first so that we can guarantee the folder is empty when we delete it
		if ( deleteState.dotVSFolder ) {
			visualStudioNukeFolderState_t nukeState = {};

			Builder_VisitFiles( scratch.arena, deleteState.dotVSFolder, BUILDER_FILE_VISIT_FILES | BUILDER_FILE_VISIT_FOLDERS | BUILDER_FILE_VISIT_RECURSIVE, Builder_VSNukeCollectCallback, &nukeState );

			for ( uint32_t folderIndex = nukeState.foldersCount; folderIndex > 0; folderIndex-- ) {
#if defined( _WIN32 )
				RemoveDirectoryA( nukeState.folders[folderIndex - 1] );
#elif defined( __linux__ )
				rmdir( nukeState.folders[folderIndex - 1] );
#endif
			}

#if defined( _WIN32 )
			RemoveDirectoryA( deleteState.dotVSFolder );
#elif defined( __linux__ )
			rmdir( deleteState.dotVSFolder );
#endif
		}
	}

	if ( !Builder_CreateFolderIfItDoesntExist( projectFilesPath ) ) {
		Builder_Error( "Failed to create the Visual Studio Solution folder \"%s\".\n", projectFilesPath );
		Builder_RewindScratch( &scratch );
		return false;
	}

	char *solutionFilename = Builder_FormatString( scratch.arena, "%s%c%s.sln", projectFilesPath, BUILDER_PATH_SEPARATOR, solution->name );

	// give every project (and every solution folder as theyre discovered below) a guid
	visualStudioSolutionBuildState_t state = { .arena = scratch.arena };

	for ( uint32_t projectIndex = 0; projectIndex < solution->projectsCount; projectIndex++ ) {
		Builder_VSAddGuid( &state );
	}

	// generate each project
	for ( uint32_t projectIndex = 0; projectIndex < solution->projectsCount; projectIndex++ ) {
		VisualStudioProject *project = &solution->projects[projectIndex];

		// validate the project
		{
			bool validProject = true;

			if ( Builder_StringIsEmpty( project->name ) ) {
				Builder_Error( "There is a Visual Studio Project that doesn't have a name here.  You need to fill that in.\n" );
				validProject = false;
			}

			if ( project->configsCount < 1 ) {
				Builder_Error( "Project \"%s\" doesn't have any configs.  You need to define at least one.\n", project->name ? project->name : "" );
				validProject = false;
			}

			for ( uint32_t configIndex = 0; configIndex < project->configsCount; configIndex++ ) {
				VisualStudioConfig *config = &project->configs[configIndex];

				if ( Builder_StringIsEmpty( config->name ) ) {
					Builder_Error( "There is a config for project \"%s\" that doesn't have a name here.  You need to fill that in.\n", project->name );
					validProject = false;
					continue;
				}

				if ( !config->config ) {
					Builder_Error( "Config \"%s\" for project \"%s\" doesn't have a BuildConfig set.  You need to fill that in.\n", config->name, project->name );
					validProject = false;
					continue;
				}

				if ( Builder_StringIsEmpty( config->config->name ) ) {
					Builder_Error( "There is a config for project \"%s\" that doesn't have a name set in its BuildConfig.  You need to fill that in.\n", project->name );
					validProject = false;
				}

				if ( config->config->binaryType == BINARY_TYPE_EXE && Builder_StringIsEmpty( config->config->binaryFolder ) ) {
					Builder_Error(
						"Build config \"%s\" is an executable, but you never specified an output directory when generating the Visual Studio project \"%s\", config \"%s\".\n"
						"Visual Studio needs this in order to know where to run the executable from when debugging.  You need to set this.\n"
						, config->config->name, project->name, config->name
					);
					validProject = false;
				}
			}

			if ( !validProject ) {
				Builder_RewindScratch( &scratch );
				return false;
			}
		}

		// if 'project->name' has a slash in it then the user wants that project to be in a folder
		// for example a project with the name "projects/games/shooter" means the user wants a project called "shooter" inside a folder called "games", which is in turn inside a folder called "projects"
		// folders are deduplicated by name alone (not full path)
		// two folders with the same name anywhere in the tree are treated as the same Solution Explorer folder
		{
			const char *lastSeparator = Builder_VSFindLastSeparator( project->name );

			if ( lastSeparator ) {
				uint32_t parentGuidIndex = BUILDER_VS_INVALID_GUID_INDEX;

				const char *segmentStart = project->name;

				while ( segmentStart < lastSeparator ) {
					const char *segmentEnd = segmentStart;

					while ( segmentEnd < lastSeparator && *segmentEnd != '/' && *segmentEnd != '\\' ) {
						segmentEnd++;
					}

					size_t segmentLength = (size_t) ( segmentEnd - segmentStart );
					char *segmentName = Builder_ArenaAlloc( state.arena, char, segmentLength + 1 );
					memcpy( segmentName, segmentStart, segmentLength );
					segmentName[segmentLength] = 0;

					uint32_t folderGuidIndex = BUILDER_VS_INVALID_GUID_INDEX;

					for ( uint32_t folderIndex = 0; folderIndex < state.foldersCount; folderIndex++ ) {
						if ( Builder_StringEquals( state.folders[folderIndex].name, segmentName ) ) {
							folderGuidIndex = state.folders[folderIndex].guidIndex;
							break;
						}
					}

					if ( folderGuidIndex == BUILDER_VS_INVALID_GUID_INDEX ) {
						folderGuidIndex = Builder_VSAddGuid( &state );

						state.folders = Builder_ArenaRealloc( state.arena, state.folders, visualStudioProjectFolder_t, state.foldersCount, state.foldersCount + 1 );
						state.folders[state.foldersCount] = (visualStudioProjectFolder_t) { .name = segmentName, .guidIndex = folderGuidIndex };
						state.foldersCount++;

						if ( parentGuidIndex != BUILDER_VS_INVALID_GUID_INDEX ) {
							state.mappings = Builder_ArenaRealloc( state.arena, state.mappings, visualStudioGuidParentMapping_t, state.mappingsCount, state.mappingsCount + 1 );
							state.mappings[state.mappingsCount] = (visualStudioGuidParentMapping_t) { .guidIndex = folderGuidIndex, .guidParentIndex = parentGuidIndex };
							state.mappingsCount++;
						}
					}

					parentGuidIndex = folderGuidIndex;
					segmentStart = ( segmentEnd < lastSeparator ) ? segmentEnd + 1 : segmentEnd;
				}

				state.mappings = Builder_ArenaRealloc( state.arena, state.mappings, visualStudioGuidParentMapping_t, state.mappingsCount, state.mappingsCount + 1 );
				state.mappings[state.mappingsCount] = (visualStudioGuidParentMapping_t) { .guidIndex = projectIndex, .guidParentIndex = parentGuidIndex };
				state.mappingsCount++;
			}
		}

		// gather all the files that the project will know about
		visualStudioFileList_t sourceFiles = {};
		visualStudioFileList_t headerFiles = {};
		visualStudioFileList_t otherFiles = {};
		visualStudioFilterPathList_t filterPaths = {};

		for ( uint32_t configIndex = 0; configIndex < project->configsCount; configIndex++ ) {
			Builder_VSAddFilesFromPatterns( scratch.arena, &sourceFiles, &headerFiles, &otherFiles, &filterPaths, &project->configs[configIndex].config->sourceFiles, options );
		}

		Builder_VSAddFilesFromPatterns( scratch.arena, &sourceFiles, &headerFiles, &otherFiles, &filterPaths, &project->extraFiles, options );

		const char *projectDisplayName = Builder_VSGetProjectDisplayName( project->name );

		// .vcxproj
		{
			char *projectPath = Builder_FormatString( scratch.arena, "%s%c%s.vcxproj", projectFilesPath, BUILDER_PATH_SEPARATOR, projectDisplayName );

			printf( "Generating %s ... ", projectPath );

			stringBuilder_t vcxprojContent = {};

			StringBuilder_Appendf( scratch.arena, &vcxprojContent, "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n" );
			StringBuilder_Appendf( scratch.arena, &vcxprojContent, "<Project DefaultTargets=\"Build\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">\n" );

			// generate every single config and platform pairing
			{
				StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t<ItemGroup Label=\"ProjectConfigurations\">\n" );

				for ( uint32_t configIndex = 0; configIndex < project->configsCount; configIndex++ ) {
					VisualStudioConfig *config = &project->configs[configIndex];

					for ( builderStringChunk_t *chunk = solution->platforms.head; chunk; chunk = chunk->next ) {
						for ( uint32_t platformIndex = 0; platformIndex < chunk->count; platformIndex++ ) {
							const char *platform = chunk->items[platformIndex];

							StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t<ProjectConfiguration Include=\"%s|%s\">\n", config->name, platform );
							StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t\t<Configuration>%s</Configuration>\n", config->name );
							StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t\t<Platform>%s</Platform>\n", platform );
							StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t</ProjectConfiguration>\n" );
						}
					}
				}

				StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t</ItemGroup>\n" );
			}

			// project globals
			{
				StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t<PropertyGroup Label=\"Globals\">\n" );
				StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t<VCProjectVersion>17.0</VCProjectVersion>\n" );
				StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t<ProjectGuid>{%s}</ProjectGuid>\n", state.projectGuids[projectIndex] );
				StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t<IgnoreWarnCompileDuplicatedFilename>true</IgnoreWarnCompileDuplicatedFilename>\n" );
				StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t<Keyword>Win32Proj</Keyword>\n" );
				StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t</PropertyGroup>\n" );
			}

			StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t<Import Project=\"$(VCTargetsPath)%cMicrosoft.Cpp.Default.props\" Condition=\"'$(OS)' == 'Windows_NT'\" />\n", BUILDER_PATH_SEPARATOR );

			// for each config and platform, define config type, toolset, out dir, and intermediate dir
			for ( uint32_t configIndex = 0; configIndex < project->configsCount; configIndex++ ) {
				VisualStudioConfig *config = &project->configs[configIndex];

				// folder containing the binary this config builds/debugs, or NULL if that binary has no folder component
				// respects VisualStudioConfig::nmakeOutput if set, otherwise this is just BuildConfig::binaryFolder
				const char *fullBinaryPath = Builder_VSGetFullBinaryPath( scratch.arena, config );
				const char *lastSeparator = Builder_VSFindLastSeparator( fullBinaryPath );
				const char *binaryFolder = lastSeparator ? Builder_FormatString( scratch.arena, "%.*s", (int) ( lastSeparator - fullBinaryPath ), fullBinaryPath ) : NULL;

				const char *outDir = binaryFolder ? Builder_RelativePathTo( scratch.arena, projectFilesPath, binaryFolder ) : ".";

				const char *intermediateFolder = options->intermediateFolder;
				if ( intermediateFolder && binaryFolder ) {
					intermediateFolder = Builder_FormatString( scratch.arena, "%s%c%s", binaryFolder, BUILDER_PATH_SEPARATOR, intermediateFolder );
				} else if ( !intermediateFolder ) {
					intermediateFolder = binaryFolder;
				}

				const char *intDir = intermediateFolder ? Builder_RelativePathTo( scratch.arena, projectFilesPath, intermediateFolder ) : ".";

				for ( builderStringChunk_t *chunk = solution->platforms.head; chunk; chunk = chunk->next ) {
					for ( uint32_t platformIndex = 0; platformIndex < chunk->count; platformIndex++ ) {
						const char *platform = chunk->items[platformIndex];

						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t<PropertyGroup Condition=\"\'$(Configuration)|$(Platform)\'==\'%s|%s\'\" Label=\"Configuration\">\n", config->name, platform );
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t<ConfigurationType>Makefile</ConfigurationType>\n" );
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t<UseDebugLibraries>false</UseDebugLibraries>\n" );
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t<PlatformToolset>v143</PlatformToolset>\n" );
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t<OutDir>%s%c</OutDir>\n", outDir, BUILDER_PATH_SEPARATOR );
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t<IntDir>%s%c</IntDir>\n", intDir, BUILDER_PATH_SEPARATOR );
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t</PropertyGroup>\n" );
					}
				}
			}

			StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t<Import Project=\"$(VCTargetsPath)%cMicrosoft.Cpp.props\" Condition=\"'$(OS)' == 'Windows_NT'\" />\n", BUILDER_PATH_SEPARATOR );

			// not sure what this is or why we need this one but visual studio seems to want it
			StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t<ImportGroup Label=\"ExtensionSettings\">\n" );
			StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t</ImportGroup>\n" );

			// for each config and platform, import the property sheets that visual studio requires
			for ( uint32_t configIndex = 0; configIndex < project->configsCount; configIndex++ ) {
				VisualStudioConfig *config = &project->configs[configIndex];

				for ( builderStringChunk_t *chunk = solution->platforms.head; chunk; chunk = chunk->next ) {
					for ( uint32_t platformIndex = 0; platformIndex < chunk->count; platformIndex++ ) {
						const char *platform = chunk->items[platformIndex];

						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t<ImportGroup Label=\"PropertySheets\" Condition=\"\'$(Configuration)|$(Platform)\'==\'%s|%s\'\">\n", config->name, platform );
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t<Import Project=\"$(UserRootDir)%cMicrosoft.Cpp.$(Platform).user.props\" Condition=\"exists(\'$(UserRootDir)%cMicrosoft.Cpp.$(Platform).user.props\')\" Label=\"LocalAppDataPlatform\" />\n", BUILDER_PATH_SEPARATOR, BUILDER_PATH_SEPARATOR );
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t</ImportGroup>\n" );
					}
				}
			}

			// not sure what this is or why we need this one but visual studio seems to want it
			StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t<PropertyGroup Label=\"UserMacros\" />\n" );

			// for each config and platform, set the following:
			//	external include paths
			//	external library paths
			//	output path
			//	build command
			//	rebuild command
			//	preprocessor definitions
			for ( uint32_t configIndex = 0; configIndex < project->configsCount; configIndex++ ) {
				VisualStudioConfig *config = &project->configs[configIndex];
				BuildConfig *buildConfig = config->config;

				const char *fullBinaryPath = Builder_VSGetFullBinaryPath( scratch.arena, config );
				char *fullBinaryPathFromProject = Builder_RelativePathTo( scratch.arena, projectFilesPath, fullBinaryPath );

				for ( builderStringChunk_t *chunk = solution->platforms.head; chunk; chunk = chunk->next ) {
					for ( uint32_t platformIndex = 0; platformIndex < chunk->count; platformIndex++ ) {
						const char *platform = chunk->items[platformIndex];

						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t<PropertyGroup Condition=\"\'$(Configuration)|$(Platform)\'==\'%s|%s\'\">\n", config->name, platform );

						// external include paths
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t<ExternalIncludePath>" );
						for ( builderStringChunk_t *chunk = buildConfig->additionalIncludes.head; chunk; chunk = chunk->next ) {
							for ( uint32_t includeIndex = 0; includeIndex < chunk->count; includeIndex++ ) {
								const char *include = chunk->items[includeIndex];

								if ( Builder_PathIsAbsolute( include ) ) {
									StringBuilder_Appendf( scratch.arena, &vcxprojContent, "%s;", include );
								} else {
									StringBuilder_Appendf( scratch.arena, &vcxprojContent, "%s;", Builder_RelativePathTo( scratch.arena, projectFilesPath, include ) );
								}
							}
						}
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "$(ExternalIncludePath)" );
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "</ExternalIncludePath>\n" );

						// external library paths
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t<LibraryPath>" );
						for ( builderStringChunk_t *chunk = buildConfig->additionalLibPaths.head; chunk; chunk = chunk->next ) {
							for ( uint32_t libPathIndex = 0; libPathIndex < chunk->count; libPathIndex++ ) {
								const char *libPath = chunk->items[libPathIndex];

								if ( Builder_PathIsAbsolute( libPath ) ) {
									StringBuilder_Appendf( scratch.arena, &vcxprojContent, "%s;", libPath );
								} else {
									StringBuilder_Appendf( scratch.arena, &vcxprojContent, "%s;", Builder_RelativePathTo( scratch.arena, projectFilesPath, libPath ) );
								}
							}
						}
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "$(LibraryPath)" );
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "</LibraryPath>\n" );

						// output path
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t<NMakeOutput>%s</NMakeOutput>\n", fullBinaryPathFromProject );

						// build command
						// "&amp;&amp;" is "&&" xml-escaped - NMakeBuildCommandLine is xml text content, not an attribute
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t<NMakeBuildCommandLine>cd /d \"%s\" &amp;&amp; \"%s\" %s%s", buildCommandDir, buildCommand, ARG_CONFIG, buildConfig->name );
						for ( builderStringChunk_t *chunk = config->additionalBuildArgs.head; chunk; chunk = chunk->next ) {
							for ( uint32_t argIndex = 0; argIndex < chunk->count; argIndex++ ) {
								StringBuilder_Appendf( scratch.arena, &vcxprojContent, " %s", chunk->items[argIndex] );
							}
						}
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "</NMakeBuildCommandLine>\n" );

						// rebuild command
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t<NMakeReBuildCommandLine>cd /d \"%s\" &amp;&amp; \"%s\" %s%s", buildCommandDir, buildCommand, ARG_CONFIG, buildConfig->name );
						for ( builderStringChunk_t *chunk = config->additionalBuildArgs.head; chunk; chunk = chunk->next ) {
							for ( uint32_t argIndex = 0; argIndex < chunk->count; argIndex++ ) {
								StringBuilder_Appendf( scratch.arena, &vcxprojContent, " %s", chunk->items[argIndex] );
							}
						}
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "</NMakeReBuildCommandLine>\n" );

						// preprocessor definitions
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t\t<NMakePreprocessorDefinitions>" );
						for ( builderStringChunk_t *chunk = buildConfig->defines.head; chunk; chunk = chunk->next ) {
							for ( uint32_t defineIndex = 0; defineIndex < chunk->count; defineIndex++ ) {
								StringBuilder_Appendf( scratch.arena, &vcxprojContent, "%s;", chunk->items[defineIndex] );
							}
						}
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "$(NMakePreprocessorDefinitions)" );
						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "</NMakePreprocessorDefinitions>\n" );

						StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t</PropertyGroup>\n" );
					}
				}
			}

			StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t<ItemDefinitionGroup>\n" );
			StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t</ItemDefinitionGroup>\n" );

			// tell visual studio what files we have in this project
			Builder_VSWriteFileGroup( scratch.arena, &vcxprojContent, &sourceFiles, "ClCompile", projectFilesPath );
			Builder_VSWriteFileGroup( scratch.arena, &vcxprojContent, &headerFiles, "ClInclude", projectFilesPath );
			Builder_VSWriteFileGroup( scratch.arena, &vcxprojContent, &otherFiles, "None", projectFilesPath );

			StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t<Import Project=\"$(VCTargetsPath)%cMicrosoft.Cpp.targets\" Condition=\"'$(OS)' == 'Windows_NT'\" />\n", BUILDER_PATH_SEPARATOR );

			// not sure what this is or why we need this one but visual studio seems to want it
			StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t<ImportGroup Label=\"ExtensionTargets\">\n" );
			StringBuilder_Appendf( scratch.arena, &vcxprojContent, "\t</ImportGroup>\n" );

			StringBuilder_Appendf( scratch.arena, &vcxprojContent, "</Project>\n" );

			if ( !Builder_WriteStringBuilderToFile( scratch.arena, &vcxprojContent, projectPath ) ) {
				Builder_Error( "Failed to write \"%s\".\n", projectPath );
				Builder_RewindScratch( &scratch );
				return false;
			}

			printf( "Done\n" );
		}

		// .vcxproj.user
		{
			char *projectPath = Builder_FormatString( scratch.arena, "%s%c%s.vcxproj.user", projectFilesPath, BUILDER_PATH_SEPARATOR, projectDisplayName );

			printf( "Generating %s ... ", projectPath );

			stringBuilder_t vcxprojUserContent = {};

			StringBuilder_Appendf( scratch.arena, &vcxprojUserContent, "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n" );
			StringBuilder_Appendf( scratch.arena, &vcxprojUserContent, "<Project ToolsVersion=\"Current\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">\n" );

			StringBuilder_Appendf( scratch.arena, &vcxprojUserContent, "\t<PropertyGroup>\n" );
			StringBuilder_Appendf( scratch.arena, &vcxprojUserContent, "\t\t<ShowAllFiles>false</ShowAllFiles>\n" );
			StringBuilder_Appendf( scratch.arena, &vcxprojUserContent, "\t</PropertyGroup>\n" );

			// for each config and platform, generate the debugger settings
			for ( uint32_t configIndex = 0; configIndex < project->configsCount; configIndex++ ) {
				VisualStudioConfig *config = &project->configs[configIndex];

				const char *fullBinaryPath = Builder_VSGetFullBinaryPath( scratch.arena, config );
				char *fullBinaryPathFromProject = Builder_RelativePathTo( scratch.arena, projectFilesPath, fullBinaryPath );

				for ( builderStringChunk_t *chunk = solution->platforms.head; chunk; chunk = chunk->next ) {
					for ( uint32_t platformIndex = 0; platformIndex < chunk->count; platformIndex++ ) {
						const char *platform = chunk->items[platformIndex];

						StringBuilder_Appendf( scratch.arena, &vcxprojUserContent, "\t<PropertyGroup Condition=\"\'$(Configuration)|$(Platform)\'==\'%s|%s\'\">\n", config->name, platform );
						StringBuilder_Appendf( scratch.arena, &vcxprojUserContent, "\t\t<DebuggerFlavor>WindowsLocalDebugger</DebuggerFlavor>\n" );	// TODO(DM): do we want to include the other debugger types?
						StringBuilder_Appendf( scratch.arena, &vcxprojUserContent, "\t\t<LocalDebuggerDebuggerType>Auto</LocalDebuggerDebuggerType>\n" );
						StringBuilder_Appendf( scratch.arena, &vcxprojUserContent, "\t\t<LocalDebuggerAttach>false</LocalDebuggerAttach>\n" );
						StringBuilder_Appendf( scratch.arena, &vcxprojUserContent, "\t\t<LocalDebuggerCommand>%s</LocalDebuggerCommand>\n", fullBinaryPathFromProject );
						StringBuilder_Appendf( scratch.arena, &vcxprojUserContent, "\t\t<LocalDebuggerWorkingDirectory>%s</LocalDebuggerWorkingDirectory>\n", !Builder_StringIsEmpty( config->runFromDirectory ) ? config->runFromDirectory : "$(SolutionDir)" );

						// if debugger arguments were specified, put those in
						if ( config->debuggerArguments.count > 0 ) {
							StringBuilder_Appendf( scratch.arena, &vcxprojUserContent, "\t\t<LocalDebuggerCommandArguments>" );
							for ( builderStringChunk_t *chunk = config->debuggerArguments.head; chunk; chunk = chunk->next ) {
								for ( uint32_t argIndex = 0; argIndex < chunk->count; argIndex++ ) {
									StringBuilder_Appendf( scratch.arena, &vcxprojUserContent, "%s ", chunk->items[argIndex] );
								}
							}
							StringBuilder_Appendf( scratch.arena, &vcxprojUserContent, "</LocalDebuggerCommandArguments>\n" );
						}

						StringBuilder_Appendf( scratch.arena, &vcxprojUserContent, "\t</PropertyGroup>\n" );
					}
				}
			}

			StringBuilder_Appendf( scratch.arena, &vcxprojUserContent, "</Project>\n" );

			if ( !Builder_WriteStringBuilderToFile( scratch.arena, &vcxprojUserContent, projectPath ) ) {
				Builder_Error( "Failed to write \"%s\".\n", projectPath );
				Builder_RewindScratch( &scratch );
				return false;
			}

			printf( "Done\n" );
		}

		// .vcxproj.filters
		{
			char *projectPath = Builder_FormatString( scratch.arena, "%s%c%s.vcxproj.filters", projectFilesPath, BUILDER_PATH_SEPARATOR, projectDisplayName );

			printf( "Generating %s ... ", projectPath );

			stringBuilder_t filtersContent = {};

			StringBuilder_Appendf( scratch.arena, &filtersContent, "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n" );
			StringBuilder_Appendf( scratch.arena, &filtersContent, "<Project ToolsVersion=\"4.0\" xmlns=\"http://schemas.microsoft.com/developer/msbuild/2003\">\n" );

			// write all filter guids
			if ( filterPaths.count > 0 ) {
				StringBuilder_Appendf( scratch.arena, &filtersContent, "\t<ItemGroup>\n" );

				for ( uint32_t filterPathIndex = 0; filterPathIndex < filterPaths.count; filterPathIndex++ ) {
					const char *guid = Builder_CreateVisualStudioGuid( scratch.arena );

					StringBuilder_Appendf( scratch.arena, &filtersContent, "\t\t<Filter Include=\"%s\">\n", filterPaths.paths[filterPathIndex] );
					StringBuilder_Appendf( scratch.arena, &filtersContent, "\t\t\t<UniqueIdentifier>{%s}</UniqueIdentifier>\n", guid );
					StringBuilder_Appendf( scratch.arena, &filtersContent, "\t\t</Filter>\n" );
				}

				StringBuilder_Appendf( scratch.arena, &filtersContent, "\t</ItemGroup>\n" );
			}

			// now put all files in the filter, listed by type
			Builder_VSWriteFileFilters( scratch.arena, &filtersContent, &sourceFiles, "ClCompile", projectFilesPath );
			Builder_VSWriteFileFilters( scratch.arena, &filtersContent, &headerFiles, "ClInclude", projectFilesPath );
			Builder_VSWriteFileFilters( scratch.arena, &filtersContent, &otherFiles, "None", projectFilesPath );

			StringBuilder_Appendf( scratch.arena, &filtersContent, "</Project>\n" );

			if ( !Builder_WriteStringBuilderToFile( scratch.arena, &filtersContent, projectPath ) ) {
				Builder_Error( "Failed to write \"%s\".\n", projectPath );
				Builder_RewindScratch( &scratch );
				return false;
			}

			printf( "Done\n" );
		}
	}

	// .sln
	{
		// some project type guids are pre-determined by visual studio
		const char *cppProjectTypeGuid = "8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942";	// c++ project
		const char *folderProjectTypeGuid = "2150E333-8FDC-42A3-9474-1A3956D46DE8";	// project folder

		printf( "Generating %s ... ", solutionFilename );

		stringBuilder_t slnContent = {};

		StringBuilder_Appendf( scratch.arena, &slnContent, "\n" );
		StringBuilder_Appendf( scratch.arena, &slnContent, "Microsoft Visual Studio Solution File, Format Version 12.00\n" );
		StringBuilder_Appendf( scratch.arena, &slnContent, "# Visual Studio Version 17\n" );
		StringBuilder_Appendf( scratch.arena, &slnContent, "VisualStudioVersion = 17.7.34202.233\n" );		// TODO(DM): how do we query windows for this?
		StringBuilder_Appendf( scratch.arena, &slnContent, "MinimumVisualStudioVersion = 10.0.40219.1\n" );	// TODO(DM): how do we query windows for this?

		// project GUIDs
		for ( uint32_t projectIndex = 0; projectIndex < solution->projectsCount; projectIndex++ ) {
			VisualStudioProject *project = &solution->projects[projectIndex];
			const char *projectDisplayName = Builder_VSGetProjectDisplayName( project->name );

			StringBuilder_Appendf( scratch.arena, &slnContent, "Project(\"{%s}\") = \"%s\", \"%s.vcxproj\", \"{%s}\"\n", cppProjectTypeGuid, projectDisplayName, projectDisplayName, state.projectGuids[projectIndex] );
			StringBuilder_Appendf( scratch.arena, &slnContent, "EndProject\n" );
		}

		// project folder GUIDs
		for ( uint32_t folderIndex = 0; folderIndex < state.foldersCount; folderIndex++ ) {
			const char *folderName = state.folders[folderIndex].name;
			const char *folderGuid = state.projectGuids[state.folders[folderIndex].guidIndex];

			StringBuilder_Appendf( scratch.arena, &slnContent, "Project(\"{%s}\") = \"%s\", \"%s\", \"{%s}\"\n", folderProjectTypeGuid, folderName, folderName, folderGuid );
			StringBuilder_Appendf( scratch.arena, &slnContent, "EndProject\n" );
		}

		StringBuilder_Appendf( scratch.arena, &slnContent, "Global\n" );
		{
			// which config|platform maps to which config|platform?
			StringBuilder_Appendf( scratch.arena, &slnContent, "\tGlobalSection(SolutionConfigurationPlatforms) = preSolution\n" );
			for ( uint32_t projectIndex = 0; projectIndex < solution->projectsCount; projectIndex++ ) {
				VisualStudioProject *project = &solution->projects[projectIndex];

				for ( uint32_t configIndex = 0; configIndex < project->configsCount; configIndex++ ) {
					VisualStudioConfig *config = &project->configs[configIndex];

					for ( builderStringChunk_t *chunk = solution->platforms.head; chunk; chunk = chunk->next ) {
						for ( uint32_t platformIndex = 0; platformIndex < chunk->count; platformIndex++ ) {
							const char *platform = chunk->items[platformIndex];

							StringBuilder_Appendf( scratch.arena, &slnContent, "\t\t%s|%s = %s|%s\n", config->name, platform, config->name, platform );
						}
					}
				}
			}
			StringBuilder_Appendf( scratch.arena, &slnContent, "\tEndGlobalSection\n" );

			// which project config|platform is active?
			StringBuilder_Appendf( scratch.arena, &slnContent, "\tGlobalSection(ProjectConfigurationPlatforms) = postSolution\n" );
			for ( uint32_t projectIndex = 0; projectIndex < solution->projectsCount; projectIndex++ ) {
				VisualStudioProject *project = &solution->projects[projectIndex];

				const char *projectGuid = state.projectGuids[projectIndex];

				for ( uint32_t configIndex = 0; configIndex < project->configsCount; configIndex++ ) {
					VisualStudioConfig *config = &project->configs[configIndex];

					for ( builderStringChunk_t *chunk = solution->platforms.head; chunk; chunk = chunk->next ) {
						for ( uint32_t platformIndex = 0; platformIndex < chunk->count; platformIndex++ ) {
							const char *platform = chunk->items[platformIndex];

							// TODO: the first config and platform in this line are actually the ones that the PROJECT has, not the SOLUTION
							// but we dont use those, and we should
							StringBuilder_Appendf( scratch.arena, &slnContent, "\t\t{%s}.%s|%s.ActiveCfg = %s|%s\n", projectGuid, config->name, platform, config->name, platform );
							StringBuilder_Appendf( scratch.arena, &slnContent, "\t\t{%s}.%s|%s.Build.0 = %s|%s\n", projectGuid, config->name, platform, config->name, platform );
						}
					}
				}
			}
			StringBuilder_Appendf( scratch.arena, &slnContent, "\tEndGlobalSection\n" );

			// tell visual studio to not hide the solution node in the Solution Explorer
			// why would you ever want it to be hidden?
			StringBuilder_Appendf( scratch.arena, &slnContent, "\tGlobalSection(SolutionProperties) = preSolution\n" );
			StringBuilder_Appendf( scratch.arena, &slnContent, "\t\tHideSolutionNode = FALSE\n" );
			StringBuilder_Appendf( scratch.arena, &slnContent, "\tEndGlobalSection\n" );

			// which projects are in which project folders (if any)?
			if ( state.mappingsCount > 0 ) {
				StringBuilder_Appendf( scratch.arena, &slnContent, "\tGlobalSection(NestedProjects) = preSolution\n" );
				for ( uint32_t mappingIndex = 0; mappingIndex < state.mappingsCount; mappingIndex++ ) {
					visualStudioGuidParentMapping_t *mapping = &state.mappings[mappingIndex];

					StringBuilder_Appendf( scratch.arena, &slnContent, "\t\t{%s} = {%s}\n", state.projectGuids[mapping->guidIndex], state.projectGuids[mapping->guidParentIndex] );
				}
				StringBuilder_Appendf( scratch.arena, &slnContent, "\tEndGlobalSection\n" );
			}
		}
		StringBuilder_Appendf( scratch.arena, &slnContent, "EndGlobal\n" );

		if ( !Builder_WriteStringBuilderToFile( scratch.arena, &slnContent, solutionFilename ) ) {
			Builder_Error( "Failed to write \"%s\".\n", solutionFilename );
			Builder_RewindScratch( &scratch );
			return false;
		}

		printf( "Done\n" );
	}

	printf( "\n" );

	Builder_RewindScratch( &scratch );

	return true;
}

#endif // BUILDER_VISUAL_STUDIO_IMPLEMENTATION

#ifdef __cplusplus
}
#endif
