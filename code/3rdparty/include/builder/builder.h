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
	1.  Intro
	2.  Installation
	3.  Quick Start Guide
	4.  Multiple Build Configs
	5.  BuildConfig Dependencies
	6.  Custom Command Line Arguments
	7.  Choosing a Compiler
	8.  Contributing
	9.  Credits


1. INTRO
Builder is a single header file that you can use to build your C/C++ programs through C/C++ code.

Builder is not a compiler.  Builder turns BuildConfigs into compiler and linker arguments, then calls the compiler that you want to use, and then calls the linker.

It works on Windows (supporting Clang, GCC, and MSVC) and Linux (Clang and GCC).


2. INSTALLATION
	1. Download the latest release.
	2. Put the header file(s) in your project.
	3. ?????
	4. Profit!


3. QUICK START GUIDE
You'll need a build script, which is just C/C++ code:

	#define BUILDER_IMPLEMENTATION
	#include "builder.h"

	int main( int argc, char **argv ) {
		BuilderOptions options = { 0 };

		BuildConfig *config = CreateBuildConfig( &options );
		*config = (BuildConfig) {
			.name			= "my_awesome_program",
			.sourceFiles	= MakeStringList( "src/my_code.c" ),
		};

		options.selfRebuildConfig = CreateBuildConfig( &options );
		*options.selfRebuildConfig = (BuildConfig) {
			.name			= "self",
			.sourceFiles	= MakeStringList( "build.c" ),
		};

		return Build( &options, argc, argv );
	}

For the first ever build you'll need to invoke your compiler manually:

	clang -o build.exe build.c

After that, once your build.exe is built you can just call it and, if it needs to, it will rebuild itself (if BuilderOptions::selfRebuildConfig is set):

	build.exe


4. MULTIPLE BUILD CONFIGS
If you have multiple BuildConfigs, you must tell Builder which one you want to build with, specifically.

You can do this by passing --config=<name> at the command line where <name> is the name of the BuildConfig, specified via BuildConfig::name.

Using the above example, if you wanted to build "my_awesome_program" instead of the other configs you'd need to pass at the command line:

	build.exe --config=my_awesome_program

If you have multiple BuildConfigs but don't specify which one to build at the command line, Builder will error asking you to tell it which one you want to build.

You can also use BuilderOptions::defaultConfig to tell Builder to build a specific BuildConfig by default:

	options.defaultConfig = config;


5. BUILDCONFIG DEPENDENCIES
BuildConfigs can be built before/after other BuildConfigs through explicit ordering via BuildConfig::dependsOn:

	#define BUILDER_IMPLEMENTATION
	#include "builder.h"

	int main( int argc, char **argv ) {
		BuilderOptions options = { 0 };

		BuildConfig *mathlib = CreateBuildConfig( &options );
		*mathlib = (BuildConfig) {
			.name			= "mathlib",
			.binaryName		= "mathlib",	// the file extension is automatically appended for you
			.binaryType		= BINARY_TYPE_DYNAMIC_LIBRARY,
			.binaryFolder	= "bin",
			.sourceFiles	= MakeStringList( "src/mathlib/lib.c" ),
		};

		BuildConfig *app = CreateBuildConfig( &options );
		*app = (BuildConfig) {
			.name				= "app",
			.binaryFolder		= "bin",
			.binaryName			= "app",
			.dependsOn			= MakeDependencies( mathlib ),
			.sourceFiles		= MakeStringList( "src/app/program.c" ),
			.additionalIncludes	= MakeStringList( "src/mathlib" ),
			.additionalLibPaths	= MakeStringList( "bin" ),
			.additionalLibs		= MakeStringList( "mathlib" ),
			.binaryType			= BINARY_TYPE_EXE,
		};

		return Build( &options, argc, argv );
	}

You can then build the "app" config through the command line like normal:

	build.exe --config=app

Building "app" builds "mathlib" first, since it's listed in dependsOn, then links the result into "app".  You only ever need to tell Builder to build the top-level config.


6. CUSTOM COMMAND LINE ARGUMENTS
Builder allows you to create your own command line arguments for your builds.

You can use the HasCommandLineArg function to check if the argument was passed at the command line:

	#define BUILDER_IMPLEMENTATION
	#include "builder.h"

	int main( int argc, char **argv ) {
		BuilderOptions options = { 0 };

		BuildConfig *config = CreateBuildConfig( &options );
		*config = (BuildConfig) {
			.name			= "my_awesome_program",
			.sourceFiles	= MakeStringList( "src/my_code.c" ),
		};

		if ( HasCommandLineArg( argc, argv, "--release" ) ) {
			config->optimization = OPTIMIZATION_PROGRAM_SPEED;
		}

		return Build( &options, argc, argv );
	}

You can then pass that command line argument through as normal:

	build.exe --release

For arguments of the form "--key=value", use GetCommandLineArgValue to get the value.  It returns NULL if the argument wasn't passed:

	const char *version = GetCommandLineArgValue( argc, argv, "--version" );	// "1.2.3" for --version=1.2.3


7. CHOOSING A COMPILER
By default, Builder will generate compiler arguments for Clang.

If you want to use a different compiler you can do this via BuilderOptions::compilerPath and BuilderOptions::compilerVersion:

	options.compilerPath = "C:/path/to/gcc";
	options.compilerVersion = "15.1.0";	// this one is optional and warns you on a mismatch

For MSVC it's recommended you just set your compiler path to "cl" and Builder will locate the MSVC toolchain and Windows SDK automatically, but a hard-coded path works too.


8. CONTRIBUTING

Yes!

See doc/Contributing.md, which came with this file.


9. CREDITS
Builder would not have been possible without the following people who deserve, at the very least, a special thanks:

	* Dale Green
	* Aiden Knight (File globbing, better incremental compilation, Windows dynamic runtime, and lots of other small things)
	* Ed Owen (Compilation database support, QoL improvements)
	* Yann Richeux (Bug fixes)
	* Tom Whitcombe (Visual Studio project generation)
	* Mike Young (Linux platform code)

===========================================================================
*/

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#ifdef _WIN32
#pragma clang diagnostic ignored "-Wmicrosoft-goto"
#endif
#endif // __clang__

#include <stdint.h>
#include <inttypes.h>
#ifndef __cplusplus
#include <stdbool.h>
#endif

// up here rather than with the rest of the implementation defines because the Add*() macros below expand to it
#ifndef BUILDER_ASSERT
#include <assert.h>
#define BUILDER_ASSERT assert
#endif

typedef enum BinaryType {
	BINARY_TYPE_EXE	= 0,
	BINARY_TYPE_DYNAMIC_LIBRARY,
	BINARY_TYPE_STATIC_LIBRARY,
} BinaryType;

typedef enum LanguageVersion {
	LANGUAGE_VERSION_UNSET	= 0,
	LANGUAGE_VERSION_C89,
	LANGUAGE_VERSION_C99,
	LANGUAGE_VERSION_C11,
	LANGUAGE_VERSION_C17,
	LANGUAGE_VERSION_C23,
	LANGUAGE_VERSION_CPP11,
	LANGUAGE_VERSION_CPP14,
	LANGUAGE_VERSION_CPP17,
	LANGUAGE_VERSION_CPP20,
	LANGUAGE_VERSION_CPP23,
} LanguageVersion;

typedef enum Optimization {
	OPTIMIZATION_NONE	= 0,
	OPTIMIZATION_DISABLED,
	OPTIMIZATION_PROGRAM_SIZE,
	OPTIMIZATION_PROGRAM_SIZE_AGGRESSIVE,
	OPTIMIZATION_PROGRAM_SPEED,
	OPTIMIZATION_PROGRAM_BALANCED,
} Optimization;

typedef struct StringList {
	struct builderStringChunk_t	*head;
	struct builderStringChunk_t	*tail;
	uint32_t					count;
} StringList;

typedef struct ConfigPtrList {
	struct buildConfigPtrChunk_t	*head;
	struct buildConfigPtrChunk_t	*tail;
	uint32_t						count;
} ConfigPtrList;

typedef enum SanitizerFlagBits {
	SANITIZER_UNDEFINED_BEHAVIOR	= 1 << 0,
	SANITIZER_MEMORY				= 1 << 1,
	SANITIZER_ADDRESS				= 1 << 2,
	SANITIZER_LEAK					= 1 << 3,
	SANITIZER_THREAD				= 1 << 4,
} SanitizerFlagBits;
typedef uint32_t SanitizerFlags;

typedef struct BuildConfig {
	// Required, and unique across your configs.  It's what "--config=" matches against and what the build log calls it.
	const char		*name;
	// Other BuildConfigs that need to be built before this one - see MakeDependencies() and AddDependencies().
	// Building a config builds everything in here first, so you only ever have to ask for the top-level one.
	ConfigPtrList	dependsOn;
	// Leave unset to use name.
	const char		*binaryName;
	// The conditional link step will use this path instead of the default outputted binary path.
	// Use if you move or rename the binary after builds.
	const char		*binaryPathOverride;
	// The folder the binary is placed into, relative to the file you pass into Builder.
	// If this folder doesn't exist then Builder will create it for you.
	// Leave unset to put the binary alongside the source file.
	const char		*binaryFolder;
	StringList		sourceFiles;
	StringList		defines;
	StringList		additionalIncludes;
	StringList		additionalCompilerArguments;
	StringList		additionalLibPaths;
	StringList		additionalLibs;
	StringList		warningLevels;
	StringList		ignoreWarnings;
	StringList		additionalLinkerArguments;
	BinaryType		binaryType;
	LanguageVersion	languageVersion;
	Optimization	optimization;
	bool			removeSymbols;
	bool			warningsAsErrors;
	bool			useDynamicRuntimeOnWindows;
	SanitizerFlags	sanitizers;
	void			( *OnPreBuild )( struct BuildConfig *config );
	void			( *OnPostBuild )( struct BuildConfig *config );
} BuildConfig;

typedef struct BuilderOptions {
	// The path to the compiler you want to build with.
	// Leave NULL to use "clang" and assume it's on your PATH.
	// On Windows, you can set this to "cl" or "cl.exe" to build with MSVC instead - Builder will locate your MSVC install automatically.
	const char		*compilerPath;

	// What version of your compiler are you expecting to build with, if any?
	// If the compiler Builder ends up using doesn't match this, Builder will log a warning but carry on building anyway.
	// Leave NULL to skip this check entirely.
	const char		*compilerVersion;

	// The folder that intermediate build files (object files) are placed into, relative to build executable.
	// If this folder doesn't exist then Builder will create it for you.
	// Leave NULL to put intermediate files at ./intermediate/
	const char		*intermediateFolder;

	// If no config is specified at the command line via --config=, what config do you want Builder to build by default?
	BuildConfig		*defaultConfig;

	// The config Builder uses to rebuild the build executable itself when its source changes.
	BuildConfig		*selfRebuildConfig;

	// Set this to true if you want Builder to force-rebuild your program.
	// All binaries and intermediate files will get rebuilt, selfRebuildConfig included.
	// This is really only useful to those who are either using an editor + command line workflow, or just hate incremental builds.
	bool			forceRebuild;

	// If this is true then Builder will show all the shared compiler arguments for each source file first, followed by the source file it's building to what intermediate file.
	// If this is false then Builder will show every compiler argument for every source file (the literal compiler arguments that got generated for each source file).
	// This can be useful when you are building lots of compilation units.
	bool			consolidateCompilerArgs;

	// Enables extra diagnostic logging throughout the build (each line prefixed "VERBOSE: ").
	// You can set this yourself, or leave it and Builder will set it automatically if "-v" or "--verbose" is present in argv.
	bool			verboseLogging;

	// The list of configs that gets populated when calling CreateBuildConfig().
	// Don't write to this directly unless you know what you're doing.
	ConfigPtrList	configs;
} BuilderOptions;

// Creates a zeroed BuildConfig, registers it with options, and hands it back.  Builder owns it and keeps it alive
// until the program exits, so nothing user-owned is ever pointed at.
// Fill it in however you like - assign the whole struct at once, or use the Add*()/Set*() functions below:
//
//	BuildConfig *program = CreateBuildConfig( options );
//	*program = (BuildConfig) {
//		.name        = "program",
//		.binaryType  = BINARY_TYPE_EXE,
//		.sourceFiles = MakeStringList( "main.c", "util.c" ),
//		.dependsOn   = MakeDependencies( lib ),
//	};
//
// Every config needs a name - it's what "--config=" matches against and what the build log calls it - and no two may
// share one.  Build() checks both before it builds anything.
BuildConfig	*CreateBuildConfig( BuilderOptions *options );

// Bundles the arguments of the macros below into an array and its length, so a call site never has to write a count or
// a terminator.  sizeof doesn't evaluate its operand, so naming __VA_ARGS__ twice costs nothing at runtime.
#define BUILDER_STRING_ARGS( ... )	(const char *[]) { __VA_ARGS__ },	(uint32_t) ( sizeof( (const char *[]) { __VA_ARGS__ } ) / sizeof( const char * ) )
#define BUILDER_CONFIG_ARGS( ... )	(BuildConfig *[]) { __VA_ARGS__ },	(uint32_t) ( sizeof( (BuildConfig *[]) { __VA_ARGS__ } ) / sizeof( BuildConfig * ) )

// Build a whole list in one expression, for assigning straight into a BuildConfig.  What they hand back is the list
// wrapper by value - everything it points at lives in Builder's memory, so it survives being copied about and outlasts
// the strings you built it from.
#define MakeStringList( ... )	Builder_MakeStringListInternal( BUILDER_STRING_ARGS( __VA_ARGS__ ) )
#define MakeDependencies( ... )	Builder_MakeDependenciesInternal( BUILDER_CONFIG_ARGS( __VA_ARGS__ ) )

// Builds a string in Builder's memory, so it's still alive when the build runs.
// A BuildConfig keeps whatever pointers you give it rather than copying them, which is free for the string literals
// that make up almost every build script.  Use this for anything you need to build at runtime - a version number, a
// path assembled from parts - rather than pointing a config at a local buffer that's about to go out of scope.
const char	*Config_FormatString( const char *fmt, ... );

// DO NOT CALL THESE DIRECTLY
// CALL THE MACRO VERSIONS ABOVE INSTEAD
StringList		Builder_MakeStringListInternal( const char **strings, uint32_t count );
ConfigPtrList	Builder_MakeDependenciesInternal( BuildConfig **dependencies, uint32_t count );

// Append to a list that's already on a config, for layering settings on after it's been filled in.  Additive: call them
// as often as you like and the entries accumulate.
#define AddSourceFiles( config, ... )		( BUILDER_ASSERT( config ), Builder_AddStringsInternal( &( config )->sourceFiles, BUILDER_STRING_ARGS( __VA_ARGS__ ) ) )
#define AddDefines( config, ... )			( BUILDER_ASSERT( config ), Builder_AddStringsInternal( &( config )->defines, BUILDER_STRING_ARGS( __VA_ARGS__ ) ) )				// no "-D"/"/D" - Builder adds that for you
#define AddIncludes( config, ... )			( BUILDER_ASSERT( config ), Builder_AddStringsInternal( &( config )->additionalIncludes, BUILDER_STRING_ARGS( __VA_ARGS__ ) ) )
#define AddCompilerArguments( config, ... )	( BUILDER_ASSERT( config ), Builder_AddStringsInternal( &( config )->additionalCompilerArguments, BUILDER_STRING_ARGS( __VA_ARGS__ ) ) )
#define AddLibPaths( config, ... )			( BUILDER_ASSERT( config ), Builder_AddStringsInternal( &( config )->additionalLibPaths, BUILDER_STRING_ARGS( __VA_ARGS__ ) ) )
#define AddLibs( config, ... )				( BUILDER_ASSERT( config ), Builder_AddStringsInternal( &( config )->additionalLibs, BUILDER_STRING_ARGS( __VA_ARGS__ ) ) )
#define AddWarningLevels( config, ... )		( BUILDER_ASSERT( config ), Builder_AddStringsInternal( &( config )->warningLevels, BUILDER_STRING_ARGS( __VA_ARGS__ ) ) )
#define AddIgnoreWarnings( config, ... )	( BUILDER_ASSERT( config ), Builder_AddStringsInternal( &( config )->ignoreWarnings, BUILDER_STRING_ARGS( __VA_ARGS__ ) ) )
#define AddLinkerArguments( config, ... )	( BUILDER_ASSERT( config ), Builder_AddStringsInternal( &( config )->additionalLinkerArguments, BUILDER_STRING_ARGS( __VA_ARGS__ ) ) )

// Every dependency gets built before config does.  Builder keeps the pointers, so they need to still be alive when
// Build() runs - a config from CreateBuildConfig() always is.
#define AddDependencies( config, ... )		Builder_AddDependenciesInternal( ( config ), BUILDER_CONFIG_ARGS( __VA_ARGS__ ) )

// DO NOT CALL THESE DIRECTLY
// CALL THE MACRO VERSIONS ABOVE INSTEAD
void	Builder_AddStringsInternal( StringList *list, const char **strings, uint32_t count );
void	Builder_AddDependenciesInternal( BuildConfig *config, BuildConfig **dependencies, uint32_t count );


int		Build( BuilderOptions *options, int argc, char **argv );


#ifdef BUILDER_IMPLEMENTATION

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN 1
#include <Windows.h>
#include <objbase.h>
#include <oleauto.h>
#if defined( _MSC_VER )
#pragma comment( lib, "ole32.lib" )
#pragma comment( lib, "oleaut32.lib" )
#pragma comment( lib, "advapi32.lib" )
#endif
#elif defined( __linux__ )
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <time.h>
#include <pthread.h>
#include <fcntl.h>
#else
#error Unrecognised platform.
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#ifdef __linux__
#include <ctype.h>
#endif

#if defined( _WIN32 )
#define BUILDER_PATH_SEPARATOR	'\\'
#elif defined( __linux__ )
#define BUILDER_PATH_SEPARATOR	'/'
#endif

#if defined( _MSC_VER ) && !defined( __cplusplus )
#define BUILDER_THREAD_LOCAL	__declspec( thread )
#else
#define BUILDER_THREAD_LOCAL	__thread
#endif

#if defined( _WIN32 )
#define BUILDER_MAX_PATH	MAX_PATH
#elif defined( __linux__ )
#define BUILDER_MAX_PATH	PATH_MAX
#endif

#ifndef BUILDER_COUNT_OF
#define BUILDER_COUNT_OF( array )	( sizeof( array ) / sizeof( array[0] ) )
#endif

#ifndef BUILDER_MAX
#define BUILDER_MAX( x, y )			( ( (x) > (y) ) ? (x) : (y) )
#endif

// alignof is only a keyword in C++ and C23. C11 and C17 have it as a macro in <stdalign.h>, which we'd rather not
// pull in (or clash with), and _Alignof has been a keyword since C11 anyway.
#ifdef __cplusplus
#define BUILDER_ALIGNOF( type )		alignof( type )
#elif defined( __STDC_VERSION__ ) && __STDC_VERSION__ >= 201112L
#define BUILDER_ALIGNOF( type )		_Alignof( type )
#elif defined( _MSC_VER )
#define BUILDER_ALIGNOF( type )		__alignof( type )
#else
#define BUILDER_ALIGNOF( type )		__alignof__( type )
#endif

#define ARG_HELP_SHORT				"-h"
#define ARG_HELP_LONG				"--help"
#define ARG_VERBOSE_SHORT			"-v"
#define ARG_VERBOSE_LONG			"--verbose"
#define ARG_CONFIG					"--config="
#define ARG_SELF_REBUILT			"--self-rebuilt"

#define ARENA_DEFAULT_BLOCK_SIZE	( 2 * 1024 * 1024 )

#define NUM_SCRATCH_ARENAS			2

enum {
	BUILDER_VERSION_MAJOR	= 1,
	BUILDER_VERSION_MINOR	= 0,
	BUILDER_VERSION_PATCH	= 0,
};

typedef struct arena_t arena_t;

typedef struct arenaBlock_t {
	void				*block;
	uint64_t			position;
	size_t				capacity;
	// Orders two blocks without walking the chain - see Builder_RewindScratch().
	// Only valid because blocks are always appended to the end, never spliced into the middle.
	uint64_t			index;
	struct arenaBlock_t	*next;
	struct arena_t*		owner;
} arenaBlock_t;

typedef struct arena_t {
	arenaBlock_t	*head;
	arenaBlock_t	*tail;
} arena_t;

typedef struct arenaRewindSpot_t {
	arenaBlock_t	*block;
	uint64_t		position;
} arenaRewindSpot_t;

typedef struct scratch_t {
	arena_t				*arena;
	arenaRewindSpot_t	rewind;
} scratch_t;


BUILDER_THREAD_LOCAL arena_t g_scratches[NUM_SCRATCH_ARENAS];

arenaRewindSpot_t Builder_ArenaTell( arena_t *arena ) {
	BUILDER_ASSERT( arena );

	arenaRewindSpot_t marker;
	marker.block = arena->tail;
	marker.position = arena->tail ? arena->tail->position : 0;

	return marker;
}

scratch_t Builder_GetScratch( arena_t *activeArena ) {
	// NULL means the caller isn't holding one, so there's nothing to avoid
	for ( int scratchIndex = 0; scratchIndex < NUM_SCRATCH_ARENAS; scratchIndex++ ) {
		arena_t *scratchArena = &g_scratches[scratchIndex];

		if ( activeArena != scratchArena ) {
			scratch_t onThisArena;
			onThisArena.arena = scratchArena;
			onThisArena.rewind = Builder_ArenaTell(scratchArena);

			return onThisArena;
		}
	}

	BUILDER_ASSERT( false && "No free scratch arena - activeArena occupied every slot" );

	scratch_t empty = { 0 };

	return empty;
}

void Builder_RewindArena( arena_t *arena, arenaRewindSpot_t *rewindLocation ) {
	BUILDER_ASSERT( arena );
	BUILDER_ASSERT( rewindLocation );

	if ( rewindLocation->block ) {
		BUILDER_ASSERT( rewindLocation->block->owner == arena );
	}

	// A rewind spot can only wind backwards. A NULL block is the arena's earliest state, so it's always valid.
	BUILDER_ASSERT( ( rewindLocation->block == NULL
		|| ( arena->tail != NULL
			&& ( rewindLocation->block->index < arena->tail->index
				|| ( rewindLocation->block == arena->tail && rewindLocation->position <= rewindLocation->block->position ) ) ) )
		&& "rewind spot is ahead of the arena - it was already rewound, or rewound out of order" );

	// Builder_ArenaAllocateInternal() zeroes the blocks past this one as it moves back onto them.
	arena->tail = rewindLocation->block;

	if ( rewindLocation->block != NULL ) {
		rewindLocation->block->position = rewindLocation->position;
	}
}

void Builder_RewindScratch( scratch_t *scratch ) {
	BUILDER_ASSERT( scratch );

	Builder_RewindArena( scratch->arena, &scratch->rewind );
}

void Builder_FreeArenas( arena_t *arenas, uint32_t arenaCount ) {
	for ( uint32_t arenaIndex = 0; arenaIndex < arenaCount; ++arenaIndex ) {
		arena_t *arena = &arenas[arenaIndex];
		arenaBlock_t *block = arena->head;

		while ( block != NULL ) {
			arenaBlock_t *next = block->next;

			free( block );	// block->block was allocated as part of this same malloc - see arenaAllocate().

			block = next;
		}

		arena->head = NULL;
		arena->tail = NULL;
	}
}

void Builder_FreeScratch( void ) {
	Builder_FreeArenas( g_scratches, NUM_SCRATCH_ARENAS );
}

void *Builder_ArenaAllocateInternal( arena_t *arena, size_t size, size_t alignment ) {
	BUILDER_ASSERT( arena );

	arenaBlock_t *block = arena->tail;

	for ( ;; ) {
		if ( block != NULL ) {
			uint64_t alignedPosition = ( block->position + alignment - 1 ) & ~( alignment - 1 );

			if ( alignedPosition + size <= block->capacity ) {
				void *result = (char *) block->block + alignedPosition;

				block->position = alignedPosition + size;
				arena->tail = block;

				return result;
			}
		}

		// Doesn't fit in the current block (or there is no current block yet) -
		// move forward to the next one, reusing it if Builder_RewindScratch() already left one there.
		arenaBlock_t *next = block ? block->next : arena->head;

		if ( next == NULL ) {
			// Nothing left to reuse - lazily allocate a new block.
			// The extra `alignment` bytes guarantee this block fits `size` even after
			// AlignUp() padding pushes the start position forward.
			size_t capacity = size + alignment;

			if ( capacity < ARENA_DEFAULT_BLOCK_SIZE ) {
				capacity = ARENA_DEFAULT_BLOCK_SIZE;
			}

			next = (arenaBlock_t *) malloc( sizeof( arenaBlock_t ) + capacity );
			BUILDER_ASSERT( next != NULL && "Out of memory." );

			next->block		= (void *) ( next + 1 );
			next->position	= 0;
			next->capacity	= capacity;
			next->index		= block ? block->index + 1 : 0;
			next->next		= NULL;
			next->owner		= arena;

			if ( block != NULL ) {
				block->next = next;
			} else {
				arena->head = next;
			}
		} else {
			// Left behind by Builder_RewindScratch(). Anything past the tail is dead, so resetting it here is safe.
			next->position = 0;
		}

		block = next;
	}
}

#define Builder_ArenaAlloc( arena, type, count )	( (type *) Builder_ArenaAllocateInternal( ( arena ), sizeof( type ) * ( count ), BUILDER_ALIGNOF( type ) ) )

// Temporary stand-in until we have a proper growable array. There's no portable way to recover
// "type" from an old pointer alone (no typeof in plain C11/C17, and MSVC/GCC/Clang don't agree on
// any extension for it), so it has to be passed in explicitly like scratchPush's. oldCount is
// needed too - scratch arenas only ever grow forward, so the new block has no idea how much of
// the old one was live and memcpy needs a length. This leaks the old block, same as every other
// scratch allocation - nothing here is individually freed until the whole arena rewinds.
#define Builder_ArenaRealloc( arena, old, type, oldCount, newCount ) \
	( (type *) memcpy( Builder_ArenaAlloc( ( arena ), type, ( newCount ) ), ( old ), sizeof( type ) * (	size_t ) ( oldCount ) ) )

static bool Builder_StringEquals( const char *a, const char *b ) {
	return strcmp( a, b ) == 0;
}

static bool Builder_StringIsEmpty( const char *str ) {
	return !str || !str[0];
}

// strnlen() is not ISO C so linux cant use it without linking to C extension libraries
// strict "-std=cNN" builds can hide its declaration, or on some CRTs the symbol itself, behind feature-test macros we dont control
// so we have our own implementation
static size_t Builder_Strnlen( const char *str, const size_t maxLength ) {
	size_t length = 0;

	while ( length < maxLength && str[length] ) {
		length++;
	}

	return length;
}

static bool Builder_StringStartsWith( const char *str, const char *prefix ) {
	return strncmp( str, prefix, strlen( prefix ) ) == 0;
}

static bool Builder_StringContains( const char *str, const char *substring ) {
	return strstr( str, substring ) != NULL;
}

// returns the position just after the last slash
static const char * Builder_FilenameFromPath( const char *path, uint64_t pathLength ) {
	const char *filename = path;

    if ( filename ) {
        filename = path + pathLength;
        while ( path != --filename ) {
            if ( *filename == '\\' || *filename == '/' ) {
                filename++;
                break;
            }
        }
    }

    return filename;
}

static bool Builder_PathEndsWith( const char *path, const char *extension ) {
	uint64_t pathLen = strlen( path );
	uint64_t extensionLen = strlen( extension );

	if ( pathLen < extensionLen ) {
		return false;
	}

#if defined( _WIN32 )
	// filenames are case-insensitive on Windows, so ".exe" and ".EXE" must be treated as the same extension
	return _strnicmp( path + pathLen - extensionLen, extension, extensionLen ) == 0;
#elif defined( __linux__ )
	return strncmp( path + pathLen - extensionLen, extension, extensionLen ) == 0;
#else
#error Unrecognised platform.
#endif
}

static char *Builder_FormatStringV( arena_t *arena, const char *fmt, va_list args ) {
	va_list argsCopy;
	va_copy( argsCopy, args );

	int length = vsnprintf( NULL, 0, fmt, args );

	char *result = Builder_ArenaAlloc( arena, char, (uint64_t) length + 1 );
	vsnprintf( result, (size_t) length + 1, fmt, argsCopy );
	va_end( argsCopy );

	return result;
}

static char *Builder_FormatString( arena_t *arena, const char *fmt, ... ) {
	va_list args;
	va_start( args, fmt );

	char *result = Builder_FormatStringV( arena, fmt, args );

	va_end( args );

	return result;
}

typedef enum {
	CONSOLE_TEXT_COLOR_DEFAULT	= 0,
	CONSOLE_TEXT_COLOR_YELLOW	= 1,
	CONSOLE_TEXT_COLOR_RED		= 2,
} builderConsoleTextColor_t;

static void Builder_SetConsoleTextColor( const builderConsoleTextColor_t color ) {
#if defined( _WIN32 )
	DWORD colorWin = 0;

	switch ( color ) {
		case CONSOLE_TEXT_COLOR_DEFAULT:	colorWin = 0x07; break;
		case CONSOLE_TEXT_COLOR_YELLOW:		colorWin = 0x0E; break;
		case CONSOLE_TEXT_COLOR_RED:		colorWin = 0x0C; break;
	}

	BUILDER_ASSERT( colorWin && "Bad console text color specified." );

	SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), colorWin );
#elif defined( __linux__ )
	const char *colorLinux = NULL;

	switch ( color ) {
		case CONSOLE_TEXT_COLOR_DEFAULT:	colorLinux = "\033[0m"; break;
		case CONSOLE_TEXT_COLOR_YELLOW:		colorLinux = "\033[1;33m"; break;
		case CONSOLE_TEXT_COLOR_RED:		colorLinux = "\033[1;31m"; break;
	}

	BUILDER_ASSERT( colorLinux && "Bad console text color specified." );

	printf( "%s", colorLinux );
#else
#error Unrecognised platform.
#endif
}

static void Builder_Warning( const char *fmt, ... ) {
	Builder_SetConsoleTextColor( CONSOLE_TEXT_COLOR_RED );

	printf( "WARNING: " );

	Builder_SetConsoleTextColor( CONSOLE_TEXT_COLOR_YELLOW );

	va_list args;
	va_start( args, fmt );
	vprintf( fmt, args );
	va_end( args );

	Builder_SetConsoleTextColor( CONSOLE_TEXT_COLOR_DEFAULT );
}

static void Builder_Error( const char *fmt, ... ) {
	Builder_SetConsoleTextColor( CONSOLE_TEXT_COLOR_RED );

	printf( "ERROR: " );

	Builder_SetConsoleTextColor( CONSOLE_TEXT_COLOR_YELLOW );

	va_list args;
	va_start( args, fmt );
	vprintf( fmt, args );
	va_end( args );

	Builder_SetConsoleTextColor( CONSOLE_TEXT_COLOR_DEFAULT );
}

static void Builder_LogVerbose( const BuilderOptions *options, const char *fmt, ... ) {
	if ( !options->verboseLogging ) {
		return;
	}

	printf( "VERBOSE: " );

	va_list args;
	va_start( args, fmt );
	vprintf( fmt, args );
	va_end( args );
}

typedef struct {
	const char	*description;
	double		timeMS;
	const char	*suffix;
} buildSummaryLine_t;

#define BUILD_SUMMARY_PTR_CHUNK_SIZE 8
typedef struct buildSummaryPtrChunk_t {
	buildSummaryLine_t				*items[BUILD_SUMMARY_PTR_CHUNK_SIZE];
	uint32_t						count;
	struct buildSummaryPtrChunk_t	*next;
	struct buildSummaryPtrChunk_t	*previous;
} buildSummaryPtrChunk_t;

typedef struct buildSummaryList_t {
	struct buildSummaryPtrChunk_t	*head;
	struct buildSummaryPtrChunk_t	*tail;
	uint32_t						count;
	uint32_t						lineLength;
} buildSummaryList_t;

// name of the BuildConfig the user wants built: whatever --config=<name> says, or BuilderOptions::defaultConfig if that arg wasn't given
static const char *Builder_GetNameOfConfigToBuild( const BuilderOptions *options, int argc, char **argv ) {
	for ( int argIndex = 0; argIndex < argc; argIndex++ ) {
		if ( Builder_StringStartsWith( argv[argIndex], ARG_CONFIG ) ) {
			return argv[argIndex] + strlen( ARG_CONFIG );
		}
	}

	return options->defaultConfig ? options->defaultConfig->name : NULL;
}

static bool Builder_IsWarningLevelAllowed_Clang( const char *warningLevel ) {
	static const char *allowedWarningLevels[] = { "-Wall", "-Weverything", "-Wextra", "-Wpedantic" };

	for ( size_t warningLevelIndex = 0; warningLevelIndex < BUILDER_COUNT_OF( allowedWarningLevels ); warningLevelIndex++ ) {
		// TODO: DM: 06/08/2026: string checking like this is slow
		// do we hash the input string and keep a list of hashes of warning level strings and check those instead?
		if ( Builder_StringEquals( warningLevel, allowedWarningLevels[warningLevelIndex] ) ) {
			return true;
		}
	}

	return false;
}

static bool Builder_IsWarningLevelAllowed_MSVC( const char *warningLevel ) {
	static const char *allowedWarningLevels[] = { "/W0", "/W1", "/W2", "/W3", "/W4", "/Wall" };

	for ( size_t warningLevelIndex = 0; warningLevelIndex < BUILDER_COUNT_OF( allowedWarningLevels ); warningLevelIndex++ ) {
		if ( Builder_StringEquals( warningLevel, allowedWarningLevels[warningLevelIndex] ) ) {
			return true;
		}
	}

	return false;
}

typedef struct stringBuilderBuffer_t {
	uint32_t						length;
	char							*data;
	struct stringBuilderBuffer_t	*next;
} stringBuilderBuffer_t;

typedef struct stringBuilder_t {
	stringBuilderBuffer_t	*head;
	stringBuilderBuffer_t	*tail;
} stringBuilder_t;


static void StringBuilder_Appendf( arena_t *arena, stringBuilder_t *builder, const char *fmt, ... ) {
	BUILDER_ASSERT( arena );
	BUILDER_ASSERT( builder );
	BUILDER_ASSERT( fmt );

	va_list args;
	va_start( args, fmt );

	stringBuilderBuffer_t *buffer = Builder_ArenaAlloc( arena, stringBuilderBuffer_t, 1 );
	memset( buffer, 0, sizeof( stringBuilderBuffer_t ) );

	va_list argsCopy;
	va_copy( argsCopy, args );

	buffer->length = (uint32_t) vsnprintf( NULL, 0, fmt, args );

	buffer->data = Builder_ArenaAlloc( arena, char, buffer->length + 1 );
	vsnprintf( buffer->data, buffer->length + 1, fmt, argsCopy );
	va_end( argsCopy );
	buffer->data[buffer->length] = 0;

	// if no head then this is the first element
	if ( !builder->head ) {
		builder->head = buffer;
	} else {
		builder->tail->next = buffer;
	}

	builder->tail = buffer;

	va_end( args );
}

static char *StringBuilder_ToString( arena_t *arena, stringBuilder_t *builder, uint64_t *outLength ) {
	BUILDER_ASSERT( arena );
	BUILDER_ASSERT( builder );

	char *result = NULL;
	uint64_t totalLength = 0;
	uint64_t offset = 0;

	stringBuilderBuffer_t *current = builder->head;

	if ( !current ) {
		return NULL;
	}

	while ( current ) {
		totalLength += current->length;

		current = current->next;
	}

	result = Builder_ArenaAlloc( arena, char, totalLength + 1 );

	current = builder->head;

	while ( current ) {
		memcpy( result + offset, current->data, current->length );

		offset += current->length;

		current = current->next;
	}

	result[totalLength] = 0;

	if ( outLength ) {
		*outLength = totalLength;
	}

	return result;
}

static bool Builder_GetFileLastWriteTime( const char *path, uint64_t *outTime ) {
	BUILDER_ASSERT( path );
	BUILDER_ASSERT( outTime );

#if defined( _WIN32 )
	WIN32_FILE_ATTRIBUTE_DATA attributeData;

	if ( !GetFileAttributesEx( path, GetFileExInfoStandard, &attributeData ) ) {
		return false;
	}

	*outTime = ( (uint64_t) attributeData.ftLastWriteTime.dwHighDateTime << 32 ) | attributeData.ftLastWriteTime.dwLowDateTime;

	return true;
#elif defined( __linux__ )
	struct stat fileStat;

	if ( stat( path, &fileStat ) != 0 ) {
		return false;
	}

	*outTime = ( (uint64_t) fileStat.st_mtim.tv_sec * 1000000000ULL ) + (uint64_t) fileStat.st_mtim.tv_nsec;

	return true;
#else
#error Unrecognised platform.
#endif
}

static bool Builder_FolderExists( const char *path ) {
#if defined( _WIN32 )
	DWORD attributes = GetFileAttributesA( path );

	return attributes != INVALID_FILE_ATTRIBUTES && ( attributes & FILE_ATTRIBUTE_DIRECTORY );
#elif defined( __linux__ )
	struct stat fileStat;

	return stat( path, &fileStat ) == 0 && S_ISDIR( fileStat.st_mode );
#else
#error Unrecognised platform.
#endif
}

// creates every folder in a relative path that doesn't already exist, including any missing parent folders
// e.g. "bin/win64" will create "bin" first if needed, then "bin/win64"
static bool Builder_CreateFolderIfItDoesntExist( const char *path ) {
	BUILDER_ASSERT( path );

	if ( Builder_FolderExists( path ) ) {
		return true;
	}

	size_t pathLength = strlen( path );
	scratch_t scratch = Builder_GetScratch( NULL );
	char *pathCopy = Builder_ArenaAlloc( scratch.arena, char, pathLength + 1 );
	memcpy( pathCopy, path, pathLength + 1 );

	bool success = true;

	// temporarily truncate the copy at each path separator so parent folders get created before their children
	for ( size_t charIndex = 1; charIndex <= pathLength && success; charIndex++ ) {
		const char c = pathCopy[charIndex];

		if ( c != '/' && c != '\\' && c != 0 ) {
			continue;
		}

		pathCopy[charIndex] = 0;

		if ( !Builder_FolderExists( pathCopy ) ) {
#if defined( _WIN32 )
			success = CreateDirectoryA( pathCopy, NULL ) != 0;
#elif defined( __linux__ )
			success = mkdir( pathCopy, 0755 ) == 0;
			int err = errno;

			if ( !success ) {
				Builder_Error( "Failed to create folder \"%s\": %s\n", pathCopy, strerror( err ) );
			}
#endif
		}

		pathCopy[charIndex] = c;
	}

	Builder_RewindScratch( &scratch );

	return success;
}

static bool Builder_WriteEntireFile( const char *filename, const char *content, const uint64_t size ) {
	FILE *file = fopen( filename, "wb" );

	if ( !file ) {
		Builder_Error( "Failed to write to file \"%s\".\n", filename );
		return false;
	}

	size_t result = fwrite( content, sizeof( uint8_t ), size, file );

	if ( result < size ) {
		Builder_Error( "Failed to write to file \"%s\".\n", filename );
		fclose( file );
		return false;
	}

	fclose( file );

	return true;
}

static char *Builder_ReadEntireFile( arena_t *arena, const char *filename, uint64_t *outSize ) {
	BUILDER_ASSERT( arena && outSize );
	FILE *file = fopen( filename, "rb" );

	if ( !file ) {
		return NULL;
	}

	if ( fseek( file, 0, SEEK_END ) != 0 ) {
		Builder_Error( "Failed to seek file \"%s\".\n", filename );
		fclose( file );
		return NULL;
	}

	long fileSize = ftell( file );
	if ( fileSize < 0 ) {
		Builder_Error( "Failed to determine size of file \"%s\".\n", filename );
		fclose( file );
		return NULL;
	}

	rewind( file );
	char *buffer = Builder_ArenaAlloc( arena, char, fileSize );
	if ( !buffer ) {
		Builder_Error( "Memory allocation failed for file \"%s\".\n", filename );
		fclose( file );
		return NULL;
	}

	uint64_t readBytes = fread( buffer, sizeof( uint8_t ), fileSize, file );
	if ( readBytes < fileSize ) {
		Builder_Error( "Failed to read entire file \"%s\".\n", filename );
		free( buffer );
		fclose( file );
		return NULL;
	}

	fclose( file );

	*outSize = (uint64_t) fileSize;

	return buffer;
}

static bool Builder_WriteStringBuilderToFile( arena_t *arena, const stringBuilder_t *sb, const char *filename ) {
	uint64_t stringLength;
	const char *str = StringBuilder_ToString( arena, (stringBuilder_t *) sb, &stringLength );
	return Builder_WriteEntireFile( filename, str, stringLength );
}

// Returns true if the exact argument 'arg' is present in the command line args, otherwise returns false.
bool HasCommandLineArg( int argc, char **argv, const char *arg ) {
	for ( int argIndex = 0; argIndex < argc; argIndex++ ) {
		if ( Builder_StringEquals( argv[argIndex], arg ) ) {
			return true;
		}
	}

	return false;
}

// Returns the value after '=' for args of the form "--key=value", or NULL if not found.
const char *GetCommandLineArgValue( int argc, char **argv, const char *arg ) {
	size_t argLength = strlen( arg );

	for ( int argIndex = 0; argIndex < argc; argIndex++ ) {
		const char *currentArg = argv[argIndex];

		if ( !Builder_StringStartsWith( currentArg, arg ) || currentArg[argLength] != '=' ) {
			continue;
		}

		return currentArg + argLength + 1;
	}

	return NULL;
}

#define STRING_CHUNK_SIZE 16

// Grows by chaining another chunk on rather than reallocating, so entries already added never move and it can be
// appended to while it's being walked.
typedef struct builderStringChunk_t {
	const char					*items[STRING_CHUNK_SIZE];
	uint32_t					count;
	struct builderStringChunk_t	*next;
} builderStringChunk_t;

// same shape as builderStringChunk_t, but it chains backwards as well - Builder_CollectConfigsToBuild() uses one of
// these lists as a stack, and popping has to find the chunk before the current one
#define BUILD_CONFIG_PTR_CHUNK_SIZE 8
typedef struct buildConfigPtrChunk_t {
	BuildConfig						*items[BUILD_CONFIG_PTR_CHUNK_SIZE];
	uint32_t						count;
	struct buildConfigPtrChunk_t	*next;
	struct buildConfigPtrChunk_t	*previous;
} buildConfigPtrChunk_t;

static void Builder_StringListPush( arena_t *arena, StringList *list, const char *string ) {
	BUILDER_ASSERT( list );

	if ( !list->tail || list->tail->count == STRING_CHUNK_SIZE ) {
		builderStringChunk_t *chunk = Builder_ArenaAlloc( arena, builderStringChunk_t, 1 );
		chunk->count	= 0;
		chunk->next		= NULL;

		if ( list->tail ) {
			list->tail->next = chunk;
		} else {
			list->head = chunk;
		}

		list->tail = chunk;
	}

	list->tail->items[list->tail->count++] = string;
	list->count++;
}

static void Builder_ConfigListPush( arena_t *arena, ConfigPtrList *list, BuildConfig *config ) {
	BUILDER_ASSERT( list );

	// popping walks tail back, so tail can be NULL while head still holds the chain, and any chunk past the tail
	// was emptied rather than freed - pick those up before allocating another
	buildConfigPtrChunk_t *tail = list->tail ? list->tail : list->head;

	if ( tail && tail->count == BUILD_CONFIG_PTR_CHUNK_SIZE ) {
		tail = tail->next;
	}

	if ( !tail ) {
		buildConfigPtrChunk_t *chunk = Builder_ArenaAlloc( arena, buildConfigPtrChunk_t, 1 );
		chunk->count	= 0;
		chunk->next		= NULL;
		chunk->previous	= list->tail;

		if ( list->tail ) {
			list->tail->next = chunk;
		} else {
			list->head = chunk;
		}

		tail = chunk;
	}

	list->tail = tail;

	list->tail->items[list->tail->count++] = config;
	list->count++;
}

static void Builder_BuildSummaryLineListPush( arena_t *arena, buildSummaryList_t *list, buildSummaryLine_t *line ) {
	BUILDER_ASSERT( list );
	BUILDER_ASSERT( line );

	buildSummaryPtrChunk_t *tail = list->tail ? list->tail : list->head;

	if ( tail && tail->count == BUILD_SUMMARY_PTR_CHUNK_SIZE ) {
		tail = tail->next;
	}

	if ( !tail ) {
		buildSummaryPtrChunk_t *chunk = Builder_ArenaAlloc( arena, buildSummaryPtrChunk_t, 1 );
		chunk->count = 0;
		chunk->next = NULL;
		chunk->previous = list->tail;

		if ( list->tail ) {
			list->tail->next = chunk;
		} else {
			list->head = chunk;
		}

		tail = chunk;
	}

	list->tail = tail;

	list->tail->items[list->tail->count++] = line;

	list->lineLength = BUILDER_MAX( list->lineLength, strlen( line->description ) );

	list->count++;
}

static void Builder_AddBuildSummaryLine( arena_t *arena, buildSummaryList_t *list, const char *description, const double timeMS, const char *suffix ) {
	buildSummaryLine_t *line = Builder_ArenaAlloc( arena, buildSummaryLine_t, 1 );
	line->description = description;
	line->timeMS = timeMS;
	line->suffix = suffix;

	Builder_BuildSummaryLineListPush( arena, list, line );
}

// only the ancestry stack pops - emptied chunks are left chained on for Builder_ConfigListPush() to pick up again
static void Builder_ConfigListPop( ConfigPtrList *list ) {
	BUILDER_ASSERT( list );
	BUILDER_ASSERT( list->count > 0 && "Popped a config list that had nothing in it." );

	list->tail->count--;
	list->count--;

	if ( list->tail->count == 0 ) {
		list->tail = list->tail->previous;
	}
}

// Every BuildConfig, and every string one of them owns, lives on this arena.  Builder_GetScratch( NULL ) always hands
// back the same one and nothing rewinds it, so anything put here outlasts the scratches that come and go on top of it.
// g_scratches is BUILDER_THREAD_LOCAL though, so it's one arena per thread: creating or adding to a config has to stay
// on the main thread, or this needs to become an arena of its own outside g_scratches.  Reading it anywhere is fine.
static arena_t *Builder_GetConfigArena( void ) {
	scratch_t configStorage = Builder_GetScratch( NULL );

	return configStorage.arena;
}

BuildConfig *CreateBuildConfig( BuilderOptions *options ) {
	BUILDER_ASSERT( options );

	arena_t *configArena = Builder_GetConfigArena();

	BuildConfig *config = Builder_ArenaAlloc( configArena, BuildConfig, 1 );
	memset( config, 0, sizeof( BuildConfig ) );

	Builder_ConfigListPush( configArena, &options->configs, config );

	return config;
}

const char *Config_FormatString( const char *fmt, ... ) {
	BUILDER_ASSERT( fmt );

	va_list args;
	va_start( args, fmt );

	const char *result = Builder_FormatStringV( Builder_GetConfigArena(), fmt, args );

	va_end( args );

	return result;
}

StringList Builder_MakeStringListInternal( const char **strings, uint32_t count ) {
	StringList list = { 0 };

	Builder_AddStringsInternal( &list, strings, count );

	return list;
}

ConfigPtrList Builder_MakeDependenciesInternal( BuildConfig **dependencies, uint32_t count ) {
	BUILDER_ASSERT( dependencies );

	ConfigPtrList list = { 0 };
	arena_t *configArena = Builder_GetConfigArena();

	for ( uint32_t dependencyIndex = 0; dependencyIndex < count; dependencyIndex++ ) {
		BuildConfig *dependency = dependencies[dependencyIndex];

		BUILDER_ASSERT( dependency );

		Builder_ConfigListPush( configArena, &list, dependency );
	}

	return list;
}

void Builder_AddStringsInternal( StringList *list, const char **strings, uint32_t count ) {
	BUILDER_ASSERT( list );
	BUILDER_ASSERT( strings );

	arena_t *configArena = Builder_GetConfigArena();

	for ( uint32_t stringIndex = 0; stringIndex < count; stringIndex++ ) {
		const char *string = strings[stringIndex];

		BUILDER_ASSERT( !Builder_StringIsEmpty( string ) && "Adding an empty entry to a BuildConfig list doesn't do anything." );

		// the string itself isn't copied - almost every entry is a literal, and Config_FormatString() covers the rest
		Builder_StringListPush( configArena, list, string );
	}
}

void Builder_AddDependenciesInternal( BuildConfig *config, BuildConfig **dependencies, uint32_t count ) {
	BUILDER_ASSERT( config );
	BUILDER_ASSERT( dependencies );

	arena_t *configArena = Builder_GetConfigArena();

	for ( uint32_t dependencyIndex = 0; dependencyIndex < count; dependencyIndex++ ) {
		BuildConfig *dependency = dependencies[dependencyIndex];

		BUILDER_ASSERT( dependency );
		BUILDER_ASSERT( config != dependency && "A BuildConfig can't depend on itself." );

		Builder_ConfigListPush( configArena, &config->dependsOn, dependency );
	}
}

// Depth-first walk of config->dependsOn that appends each config to outConfigsToBuild only once everything it depends
// on is already in there, so the build order falls out of the walk.
// ancestry is the chain of configs the walk is currently inside (config -> dependency -> ...) and starts out empty.  A
// config turning up in there again is a cycle, which there's no sensible way to build, so it's fatal.
// arena backs both lists, plus the error message if it comes to that.
static void Builder_CollectConfigsToBuild( arena_t *arena, BuildConfig *config, ConfigPtrList *ancestry, ConfigPtrList *outConfigsToBuild ) {
	BUILDER_ASSERT( config );
	BUILDER_ASSERT( ancestry );
	BUILDER_ASSERT( outConfigsToBuild );

	// multiple configs can rely on the same config (e.g. configs A and B may both rely on config C), and anything
	// already in the list has had its whole subtree walked and cleared of cycles
	for ( buildConfigPtrChunk_t *chunk = outConfigsToBuild->head; chunk; chunk = chunk->next ) {
		for ( uint32_t collectedIndex = 0; collectedIndex < chunk->count; collectedIndex++ ) {
			if ( chunk->items[collectedIndex] == config ) {
				return;
			}
		}
	}

	{
		// where in the ancestry the config turned up, if it did - the cycle is everything from there onwards
		buildConfigPtrChunk_t *cycleChunk = NULL;
		uint32_t cycleIndex = 0;

		for ( buildConfigPtrChunk_t *chunk = ancestry->head; chunk && !cycleChunk; chunk = chunk->next ) {
			for ( uint32_t ancestorIndex = 0; ancestorIndex < chunk->count; ancestorIndex++ ) {
				if ( chunk->items[ancestorIndex] == config ) {
					cycleChunk = chunk;
					cycleIndex = ancestorIndex;
					break;
				}
			}
		}

		if ( cycleChunk ) {
			// throwaway scratch, we're about to exit
			scratch_t errorScratch = Builder_GetScratch( arena );
			stringBuilder_t cycle = { 0 };

			// picking the walk back up where the match was found spells out the cycle and nothing that came before it
			for ( buildConfigPtrChunk_t *chunk = cycleChunk; chunk; chunk = chunk->next ) {
				for ( uint32_t ancestorIndex = ( chunk == cycleChunk ) ? cycleIndex : 0; ancestorIndex < chunk->count; ancestorIndex++ ) {
					StringBuilder_Appendf( errorScratch.arena, &cycle, "%s -> ", chunk->items[ancestorIndex]->name );
				}
			}

			StringBuilder_Appendf( errorScratch.arena, &cycle, "%s", config->name );

			char *cycleString = StringBuilder_ToString( errorScratch.arena, &cycle, NULL );
			Builder_Error( "Cyclic BuildConfig dependency detected: %s\n", cycleString );

			exit( 1 );
		}
	}

	Builder_ConfigListPush( arena, ancestry, config );

	// dependencies go in first so they show up (and get built) ahead of the config that needs them
	for ( buildConfigPtrChunk_t *chunk = config->dependsOn.head; chunk; chunk = chunk->next ) {
		for ( uint32_t dependencyIndex = 0; dependencyIndex < chunk->count; dependencyIndex++ ) {
			Builder_CollectConfigsToBuild( arena, chunk->items[dependencyIndex], ancestry, outConfigsToBuild );
		}
	}

	Builder_ConfigListPop( ancestry );

	Builder_ConfigListPush( arena, outConfigsToBuild, config );
}


static int32_t Builder_RunProcess( arena_t* results, const char *processAndArgs, bool discardStderr, char **outCapturedOutput ) {
#if defined( _WIN32 )
	SECURITY_ATTRIBUTES secAttr = { sizeof( SECURITY_ATTRIBUTES ), NULL, TRUE };

	PROCESS_INFORMATION	processInfo;

	// TODO: AK: 21/08/2026: We are leaking handles everytime we return due to an error
	HANDLE stdoutRead = NULL;
	HANDLE stdoutWrite = NULL;
	HANDLE stderrWrite = NULL;
	if ( !CreatePipe( &stdoutRead, &stdoutWrite, &secAttr, 0 ) ) {
		Builder_Error( "CreatePipe call failed for stdout: 0x%X.\n", GetLastError() );
		return -1;
	}

	if ( discardStderr ) {
		stderrWrite = CreateFile(
			"NUL",
			GENERIC_WRITE,
			FILE_SHARE_WRITE,
			&secAttr,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			NULL
		);
		if ( stderrWrite == INVALID_HANDLE_VALUE ) {
			Builder_Error( "CreateFile call failed to open NUL device: 0x%X.\n", GetLastError() );
			return -1;
		}
	} else {
		stderrWrite = stdoutWrite;
	}

	STARTUPINFO startInfo = { sizeof( startInfo ) };
	startInfo.dwFlags = STARTF_USESTDHANDLES;
	startInfo.hStdOutput = stdoutWrite;
	startInfo.hStdError = stderrWrite;

	char *combinedEnvVars = NULL;

	if ( !CreateProcess(
		NULL,
		(LPSTR) processAndArgs,
		NULL,
		NULL,
		true,
		CREATE_NO_WINDOW,
		combinedEnvVars,
		NULL,
		&startInfo,
		&processInfo
	) ) {
		Builder_Error( "Failed to create process: 0x%X.\n", GetLastError() );
		return -1;
	}

	// close the write ends of the pipes on the parent side
	// the child inherited its own copies so this must happen before we start reading
	// otherwise the parents dangling copy keeps the pipe "open" and ReadFile below blocks forever once the child exits
	if ( !CloseHandle( stdoutWrite ) ) {
		Builder_Error( "Failed to close stdout write handle: Windows error code: 0x%X\n", GetLastError() );
		return -1;
	}
	if ( discardStderr && !CloseHandle( stderrWrite ) ) {
		Builder_Error( "Failed to close stderr write handle: Windows error code: 0x%X\n", GetLastError() );
		return -1;
	}
	stdoutWrite = NULL;
	stderrWrite = NULL;

	char buffer[1024] = { 0 };
	stringBuilder_t capturedOutput = { 0 };

	// the builder's own buffers are throwaway, so they go somewhere other than the scratch the caller wants the result in
	scratch_t temporaryScratch = Builder_GetScratch( results );

	bool finished = false;
	while ( !finished ) {
		DWORD bytesRead = 0;
		DWORD toRead = sizeof( buffer ) - 1;
		if ( ReadFile( stdoutRead, buffer, toRead, &bytesRead, NULL ) && bytesRead != 0 ) {
			buffer[bytesRead] = 0;
			if ( outCapturedOutput ) {
				StringBuilder_Appendf( temporaryScratch.arena, &capturedOutput, "%s", buffer );
			} else {
				printf( "%s", buffer );
			}
		} else {
			// the child closing its end of the pipe (e.g. on exit) surfaces as ERROR_BROKEN_PIPE here - that's expected EOF, not a real failure
			DWORD lastError = GetLastError();
			if ( lastError != ERROR_BROKEN_PIPE ) {
				Builder_Error( "Failed to read stdout of subprocess: Windows error code: 0x%X.\n", lastError );
			}
			finished = false;
			break;
		}
	}

	if ( outCapturedOutput ) {
		BUILDER_ASSERT( results && "capturing output needs an arena to put the result in" );

		*outCapturedOutput = StringBuilder_ToString( results, &capturedOutput, NULL );
	}

	Builder_RewindScratch( &temporaryScratch );

	// wait for process to finish
	if ( !CloseHandle( stdoutRead ) ) {
		Builder_Error( "Failed to close stdout read handle: Windows error code: 0x%X\n", GetLastError() );
		return -1;
	}
	stdoutRead = NULL;

	if ( WaitForSingleObject( processInfo.hProcess, INFINITE ) != WAIT_OBJECT_0 ) {
		Builder_Error( "Failed to wait for subprocess to finish: 0x%X\n", GetLastError() );
		return -1;
	}

	DWORD exitCode = 0;

	if ( !GetExitCodeProcess( processInfo.hProcess, &exitCode ) ) {
		Builder_Error( "Failed to get exit code of subprocess: 0x%X\n", GetLastError() );
		return -1;
	}

	if ( !CloseHandle( processInfo.hProcess ) || !CloseHandle( processInfo.hThread ) ) {
		Builder_Error( "Failed to close a process handle: Windows error code: 0x%X\n", GetLastError() );
		return -1;
	}

	return (int32_t) exitCode;
#elif defined( __linux__ )
	int stdoutPipe[2];

	if ( pipe( stdoutPipe ) != 0 ) {
		int err = errno;
		Builder_Error( "Failed to create pipe for subprocess stdout: %s.\n", strerror( err ) );
		return -1;
	}

	pid_t pid = fork();
	int err = errno;

	if ( pid < 0 ) {
		Builder_Error( "Failed to fork subprocess: %s.\n", strerror( err ) );
		return -1;
	}

	if ( pid == 0 ) {
		// child: fold stdout and stderr into the write end of the pipe so the parent sees combined output, then exec
		if ( close( stdoutPipe[0] ) == -1 ) {
			err = errno;
			Builder_Error( "Failed to close stdout pipe: %s\n", strerror( err ) );
		}

		if ( dup2( stdoutPipe[1], STDOUT_FILENO ) == -1 ) {
			err = errno;
			Builder_Error( "Failed to duplicate stdout pipe: %s\n", strerror( err ) );
		}

		// TODO: AK: 21/08/2026: this needs verifying / testing @dangmoody :)
		if ( discardStderr ) {
			int devNull = open( "/dev/null", O_WRONLY );
			if ( devNull == -1 ) {
				err = errno;
				Builder_Error( "Failed to open /dev/null: %s\n", strerror( err ) );
			}

			if ( dup2( devNull, STDERR_FILENO ) == -1 ) {
				err = errno;
				Builder_Error( "Failed to duplicate stderr to /dev/null: %s\n", strerror( err ) );
			}
			if ( close( devNull ) == -1 ) {
				err = errno;
				Builder_Error( "Failed to close dev/null: %s\n", strerror( err ) );
			}
		} else if ( dup2( stdoutPipe[1], STDERR_FILENO ) == -1 ) {
			err = errno;
			Builder_Error( "Failed to duplicate stderr pipe: %s\n", strerror( err ) );
		}

		if ( close( stdoutPipe[1] ) == -1 ) {
			err = errno;
			Builder_Error( "Failed to close stderr pipe: %s\n", strerror( err ) );
		}

		if ( execl( "/bin/sh", "sh", "-c", processAndArgs, (char *) NULL ) == -1 ) {
			err = errno;
			Builder_Error( "Failed to exec subprocess: %s\n", strerror( err ) );
			_exit( 127 );
		}
	}

	// parent: close the write end on our side so read() sees EOF once the child (and any of its children) close theirs
	if ( close( stdoutPipe[1] ) == -1 ) {
		err = errno;
		Builder_Error( "Failed to close stdout pipe: %s\n", strerror( err ) );
		return -1;
	}

	char buffer[1024] = { 0 };
	ssize_t bytesRead = 0;

	stringBuilder_t capturedOutput = { 0 };

	// the builder's own buffers are throwaway, so they go somewhere other than the scratch the caller wants the result in
	scratch_t temporaryScratch = Builder_GetScratch( results );

	while ( ( bytesRead = read( stdoutPipe[0], buffer, sizeof( buffer ) - 1 ) ) > 0 ) {
		buffer[bytesRead] = 0;

		if ( outCapturedOutput ) {
			StringBuilder_Appendf( temporaryScratch.arena, &capturedOutput, "%s", buffer );
		} else {
			printf( "%s", buffer );
		}
	}

	err = errno;

	// a negative return here means read() itself failed - distinct from bytesRead == 0, which is just normal EOF once the child closes the pipe
	if ( bytesRead < 0 ) {
		Builder_Error( "Failed to read stdout of subprocess: %s.\n", strerror( err ) );
	}

	if ( outCapturedOutput ) {
		BUILDER_ASSERT( results && "capturing output needs an arena to put the result in" );

		*outCapturedOutput = StringBuilder_ToString( results, &capturedOutput, NULL );
	}

	Builder_RewindScratch( &temporaryScratch );

	if ( close( stdoutPipe[0] ) == -1 ) {
		err = errno;
		Builder_Error( "Failed to close stdout pipe: %s\n", strerror( err ) );
		return -1;
	}

	int status = 0;

	if ( waitpid( pid, &status, 0 ) < 0 ) {
		err = errno;
		Builder_Error( "Failed to wait for subprocess: %s.\n", strerror( err ) );
		return -1;
	}

	if ( WIFEXITED( status ) ) {
		return WEXITSTATUS( status );
	}

	if ( WIFSIGNALED( status ) ) {
		Builder_Error( "Subprocess was terminated by signal %d.\n", WTERMSIG( status ) );
		return -1;
	}

	return -1;
#else
#error Unrecognised platform.
#endif
}

static int ShowUsage( const int exitCode ) {
	printf(
		"Builder\n"
		"\n"
		"USAGE:\n"
		"    <your build program> [arguments] [custom arguments]\n"
		"\n"
		"Arguments:\n"
		"    " ARG_HELP_SHORT "|" ARG_HELP_LONG " (optional):\n"
		"        Shows this help and then exits.\n"
		"\n"
		"    " ARG_VERBOSE_SHORT "|" ARG_VERBOSE_LONG " (optional):\n"
		"        Enables verbose logging, so a lot more information gets output.\n"
		"\n"
		"    " ARG_CONFIG "<config> (optional):\n"
		"        Sets the config to build to <config>.\n"
		"        This must match the name of a config you created via CreateBuildConfig().\n"
		"        If you only registered one config you don't need to specify this.\n"
		"        If you registered more than one config you must either specify this or set BuilderOptions::defaultConfig.\n"
		"\n"
		"    " ARG_SELF_REBUILT " (optional):\n"
		"        Tells Builder that this program is the freshly rebuilt one, so it skips rebuilding itself.\n"
		"        Builder passes this itself when it relaunches your build program after rebuilding BuilderOptions::selfRebuildConfig.\n"
		"        Pass it by hand if you want to run your build program without it checking whether it's out of date.\n"
		"\n"
		"    [custom arguments] (optional):\n"
		"        Any arguments not listed here are passed through to your build program via main()'s argc/argv.\n"
		"        Use HasCommandLineArg( int, char **, const char * ) to query for them.\n"
		"        Use GetCommandLineArgValue( int, char **, const char * ) to get the value of args like \"--key=value\".\n"
		"\n"
	);

	return exitCode;
}

static const char *Builder_GetFileExtensionFromBinaryType( const BinaryType binaryType ) {
#if defined( _WIN32 )
	switch ( binaryType ) {
		case BINARY_TYPE_EXE:				return ".exe";
		case BINARY_TYPE_DYNAMIC_LIBRARY:	return ".dll";
		case BINARY_TYPE_STATIC_LIBRARY:	return ".lib";
	}
#elif defined( __linux__ )
	switch ( binaryType ) {
		case BINARY_TYPE_EXE:				return "";
		case BINARY_TYPE_DYNAMIC_LIBRARY:	return ".so";
		case BINARY_TYPE_STATIC_LIBRARY:	return ".a";
	}
#else
#error Unrecognised platform.
#endif

	BUILDER_ASSERT( false && "Bad BinaryType.\n" );

	return NULL;
}

static const char * Builder_GetBinaryPath( arena_t *arena, const BuildConfig *config ) {
	if ( config->binaryFolder ) {
		return Builder_FormatString( arena, "%s%c%s%s", config->binaryFolder, BUILDER_PATH_SEPARATOR, config->binaryName, Builder_GetFileExtensionFromBinaryType( config->binaryType ) );
	} else {
		return Builder_FormatString( arena, "%s%s", config->binaryName, Builder_GetFileExtensionFromBinaryType( config->binaryType ) );
	}
}

static uint64_t Builder_AppendHash( const uint64_t inHash, const char *string ) {
	uint64_t outHash = inHash;

	while ( *string ) {
		outHash ^= (unsigned char) *(string++);
		outHash *= UINT64_C(1099511628211);
  }

	return outHash;
}

static uint64_t Builder_HashString( const char *string ) {
	static const uint64_t offsetBias = UINT64_C(14695981039346656037);
	return Builder_AppendHash( offsetBias, string );
}

// we get the hash of the compile command to figure out what the name of the sourceFile should be
static const char* Builder_GetIntermediateFilePath( arena_t *arena, const char *intermediateFolder, uint64_t compileCommandHash, const char* sourceFile ) {
	const char *fileName = sourceFile;

	for ( const char *c = sourceFile; *c; c++ ) {
		if ( *c == '/' || *c == '\\' ) {
			fileName = c + 1;
		}
	}

	const char *extension = strrchr( fileName, '.' );
	size_t fileNameLength = extension ? (size_t) ( extension - fileName ) : strlen( fileName );

	return Builder_FormatString( arena, "%s%c%.*s_%" PRIu64 ".o", intermediateFolder, BUILDER_PATH_SEPARATOR, (int) fileNameLength, fileName, compileCommandHash );
}

typedef struct {
	uint64_t	sizeBytes;
	uint64_t	lastWriteTime;
	bool		isDirectory;
	const char	*filename;
	const char	*fullFilename;
} fileInfo_t;

// results is for anything the callback allocates that has to outlive the walk.  It's optional - pass NULL if the
// callback doesn't allocate.  Builder_VisitFiles() never allocates from it itself.
typedef void ( *builderFileVisitCallback_t )( arena_t *resultsArena, fileInfo_t *fileInfo, void *data );

typedef enum {
	BUILDER_FILE_VISIT_FILES		= 1 << 0,
	BUILDER_FILE_VISIT_FOLDERS		= 1 << 1,
	BUILDER_FILE_VISIT_RECURSIVE	= 1 << 2,
} builderFileVisitFlagBits_t;
typedef uint32_t builderFileVisitFlags_t;

static bool Builder_VisitFiles( arena_t *results, const char *path, const builderFileVisitFlags_t visitFlags, builderFileVisitCallback_t callback, void *data ) {
	BUILDER_ASSERT( path );
	BUILDER_ASSERT( callback );

	// the paths we build to walk the tree are ours alone - only the callback's allocations outlive us, and those go on results
	scratch_t scratch = Builder_GetScratch( results );

	StringList directories = { 0 };
	Builder_StringListPush( scratch.arena, &directories, path );

	// walking a folder pushes its subfolders on, so count grows underneath the inner loop and next appears when it overflows
	for ( builderStringChunk_t *chunk = directories.head; chunk; chunk = chunk->next ) {
		for ( uint32_t directoryIndex = 0; directoryIndex < chunk->count; directoryIndex++ ) {
			const char *dir = chunk->items[directoryIndex];

			size_t dirLength = strlen( dir );
			bool dirHasTrailingSeparator = dirLength > 0 && ( dir[dirLength - 1] == '\\' || dir[dirLength - 1] == '/' );

#if defined( _WIN32 )
			char *searchPath = Builder_FormatString( scratch.arena, dirHasTrailingSeparator ? "%s*" : "%s\\*", dir );

			WIN32_FIND_DATA findData = { 0 };
			HANDLE handle = FindFirstFile( searchPath, &findData );

			if ( handle == INVALID_HANDLE_VALUE ) {
				Builder_RewindScratch( &scratch );
				return false;
			}

			while ( 1 ) {
				fileInfo_t fileInfo = {
					.sizeBytes		= ( (uint64_t) findData.nFileSizeHigh << 32 ) | findData.nFileSizeLow,
					.lastWriteTime	= ( (uint64_t) findData.ftLastWriteTime.dwHighDateTime << 32 ) | findData.ftLastWriteTime.dwLowDateTime,
					.isDirectory	= (bool) ( findData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ),
					.filename		= findData.cFileName,
					.fullFilename	= Builder_FormatString( scratch.arena, dirHasTrailingSeparator ? "%s%s" : "%s\\%s", dir, findData.cFileName ),
				};

				if ( fileInfo.isDirectory ) {
					if ( !Builder_StringEquals( findData.cFileName, "." ) && !Builder_StringEquals( findData.cFileName, ".." ) ) {
						if ( visitFlags & BUILDER_FILE_VISIT_FOLDERS ) {
							callback( results, &fileInfo, data );
						}

						if ( visitFlags & BUILDER_FILE_VISIT_RECURSIVE ) {
							Builder_StringListPush( scratch.arena, &directories, fileInfo.fullFilename );
						}
					}
				} else if ( visitFlags & BUILDER_FILE_VISIT_FILES ) {
					callback( results, &fileInfo, data );
				}

				if ( !FindNextFile( handle, &findData ) ) {
					break;
				}
			}

			if ( !FindClose( handle ) ) {
				Builder_RewindScratch( &scratch );
				return false;
			}
#elif defined( __linux__ )
			DIR *handle = opendir( dir );
			int err = errno;

			if ( !handle ) {
				Builder_Error( "Failed to open folder \"%s\": %s\n", dir, strerror( err ) );
				Builder_RewindScratch( &scratch );
				return false;
			}

			struct dirent *entry = NULL;

			while ( ( entry = readdir( handle ) ) != NULL ) {
				if ( Builder_StringEquals( entry->d_name, "." ) || Builder_StringEquals( entry->d_name, ".." ) ) {
					continue;
				}

				char *fullFilename = Builder_FormatString( scratch.arena, dirHasTrailingSeparator ? "%s%s" : "%s/%s", dir, entry->d_name );

				struct stat fileStat = { 0 };

				if ( stat( fullFilename, &fileStat ) != 0 ) {
					err = errno;
					Builder_Error( "Failed to stat \"%s\": %s\n", fullFilename, strerror( err ) );
					Builder_RewindScratch( &scratch );
					return false;
				}

				fileInfo_t fileInfo = {
					.sizeBytes		= (uint64_t) fileStat.st_size,
					.lastWriteTime	= (uint64_t) fileStat.st_mtime,
					.isDirectory	= (bool) S_ISDIR( fileStat.st_mode ),
					.filename		= entry->d_name,
					.fullFilename	= fullFilename,
				};

				if ( fileInfo.isDirectory ) {
					if ( visitFlags & BUILDER_FILE_VISIT_FOLDERS ) {
						callback( results, &fileInfo, data );
					}

					if ( visitFlags & BUILDER_FILE_VISIT_RECURSIVE ) {
						Builder_StringListPush( scratch.arena, &directories, fileInfo.fullFilename );
					}
				} else if ( visitFlags & BUILDER_FILE_VISIT_FILES ) {
					callback( results, &fileInfo, data );
				}
			}

			if ( closedir( handle ) != 0 ) {
				err = errno;
				Builder_Error( "Failed to close folder \"%s\": %s\n", dir, strerror( err ) );
				Builder_RewindScratch( &scratch );
				return false;
			}
#endif
		}
	}

	Builder_RewindScratch( &scratch );

	return true;
}

// There could be an optimisation here if we store whether there is an asterisk
// As slice comparison can early out if count is not equal for the price of more memory?
// We should wait for some more consistent performance benchmarks to test the difference
typedef struct {
	const char *begin;
	uint32_t count;
} builderStringSlice_t;

typedef struct {
	builderStringSlice_t *data;
	uint32_t count;
} builderStringSliceArray_t;

typedef struct {
	const builderStringSliceArray_t patternSlices;
	const uint32_t searchPathLen;
	StringList *globResults;
	bool verboseLogging;
} builderGlobVisitCallbackData_t;

// remember to free sliceArray.data
static builderStringSliceArray_t Builder_SliceFilePath( arena_t* results, const char *filePath ) {
	const char *pathIterator = filePath;
	builderStringSliceArray_t sliceArray = {
		.data = NULL,
		.count = 0
	};

	// we currently iterate over it twice as it fits with the allocation strategy, this is not the best way
	// another contender for chunked array?
	uint32_t numSlices = (*pathIterator != '\\' && *pathIterator != '/') ? 1 : 0; // the first bit is also a slice that could be missed if no slash at front
	while( *pathIterator != '\0' ) {
		// since this is supposed to be a file it shouldn't end in a slash so each time we hit a slash
		// there is a slice between the current slashes and the next slash / end of full filename
		if ( *pathIterator == '\\' || *pathIterator == '/' ) {
			while ( *pathIterator == '\\' || *pathIterator == '/' ) {
				++pathIterator;
				if ( *pathIterator == '\0' ) {
					printf( "Error: Tried to slice path that ended in a slash \"%s\", this shouldn't be happening.\n", filePath );
					return sliceArray;
				}
			}
			++numSlices;
		} else {
			++pathIterator;
		}
	}

	sliceArray.data = Builder_ArenaAlloc(results, builderStringSlice_t, numSlices);
	sliceArray.count = numSlices;

	pathIterator = filePath;
	for (uint32_t slice = 0; slice < numSlices; ++slice) {
		while ( *pathIterator == '\\' || *pathIterator == '/' ) {
			++pathIterator;
		}

		sliceArray.data[slice].begin = pathIterator;
		sliceArray.data[slice].count = 0;
		while ( *pathIterator != '\\' && *pathIterator != '/' && *pathIterator != '\0' ) {
			++sliceArray.data[slice].count;
			++pathIterator;
		}
	}

	return sliceArray;
}

static bool Builder_SliceMatchesPattern( const builderStringSlice_t *patternSlice, const builderStringSlice_t *pathSlice ) {
	if ( pathSlice->count == 0 ) {
		return false;
	}

	uint32_t afterLastWildcard = 0;
	uint32_t patternIndex = 0;
	for (uint32_t pathIndex = 0; pathIndex < pathSlice->count; ++pathIndex ) {
		// there are more characters that haven't been matched
		if ( patternIndex == patternSlice->count ) {
			return false;
		}

		// keep consuming wildcards to reach next match
		while ( patternSlice->begin[patternIndex] == '*' ) {
			afterLastWildcard = ++patternIndex;
			if ( patternIndex == patternSlice->count ) {
				return true; // rest of the characters are matched via wildcard
			}
		}

		// keep matching characters, accounting for found wildcards
		// wildcards being found means we can match the characters after that wildcard
		// anywhere in the string (as long as we do match them at some point)
		if ( patternSlice->begin[patternIndex] != '?' // can match any one character
		  && patternSlice->begin[patternIndex] != pathSlice->begin[pathIndex] ) {
			// we never hit a wildcard so this is a failed match
			if ( afterLastWildcard == 0 ) {
				return false;
			}

			// otherwise reset back to the character after the last widldcard if the match fails
			// so we keep trying for that match
			patternIndex = afterLastWildcard;
		} else {
			++patternIndex;
		}
	}

	// since we consumed all characters in match and filename it's a match
	return patternIndex == patternSlice->count;
}

static bool Builder_PathMatchesPattern( const builderStringSliceArray_t *patternSliceArray, const builderStringSliceArray_t *pathSliceArray ) {
	if ( pathSliceArray == NULL || patternSliceArray == NULL ||
		pathSliceArray->count == 0 || patternSliceArray->count == 0 ) {
		return false;
	}

	bool inRecursiveGlob = false;
	uint32_t patternIndex = 0;
	uint32_t pathIndex = 0;
	while ( patternIndex < patternSliceArray->count ) {
		const builderStringSlice_t *patternSlice = &patternSliceArray->data[patternIndex++];

		if ( patternSlice->count == 1 && patternSlice->begin[0] == '*' ) { // case of /*/ - we should just check this in Builder_SliceMatchesPattern
			if ( pathIndex++ == pathSliceArray->count ) {
				return false; // no more folders to consume
			}
		} else if ( patternSlice->count == 2 && patternSlice->begin[0] == '*' &&  patternSlice->begin[1] == '*' ) { // case of /**/
			inRecursiveGlob = true;
		} else {
			bool foundMatch = false;
			while ( pathIndex < pathSliceArray->count ) {
				const builderStringSlice_t *pathSlice = &pathSliceArray->data[pathIndex++];

				if ( Builder_SliceMatchesPattern( patternSlice, pathSlice) ) {
					foundMatch = true;
					break;
				} else if ( !inRecursiveGlob ) { // we can't fail a match if not globbing recursively
					return false;
				}
			}

			// there was something to match and we didn't match it
			if ( !foundMatch ) {
				return false;
			}

			// if we have reached the end then we actually matched everything and we are done
			if (pathIndex == pathSliceArray->count && patternIndex == patternSliceArray->count) {
				return true;
			}
		}
	}

	// if the pattern ended in a recursive glob then
	// we can match anything remaining in the path
	return inRecursiveGlob;
}

static void Builder_GlobVisitCallback( arena_t *resultsArena, fileInfo_t *fileInfo, void *data ) {
	builderGlobVisitCallbackData_t *callbackData = (builderGlobVisitCallbackData_t *)data;

	uint32_t filenameLen = Builder_Strnlen( fileInfo->filename, 255 ); // filename length maxes here I think?
	uint32_t fullFilenameLen = Builder_Strnlen( fileInfo->fullFilename, BUILDER_MAX_PATH + filenameLen );

	if ( fullFilenameLen - filenameLen < callbackData->searchPathLen ) {
		printf( "Error: Search path length was longer than full file path for file %s\n", fileInfo->fullFilename );
		return;
	}

	// we could do a heavyweight verification that the search path matches here,
	// but really it should match from the call sites
	const char* matchStart = fileInfo->fullFilename + callbackData->searchPathLen;
	scratch_t scratch = Builder_GetScratch( resultsArena );
	const builderStringSliceArray_t pathSlices = Builder_SliceFilePath( scratch.arena, matchStart );

	if ( Builder_PathMatchesPattern( &callbackData->patternSlices, &pathSlices ) ) {
		if ( callbackData->verboseLogging ) {
			printf( "VERBOSE:  - Found \"%s\"\n", fileInfo->fullFilename );
		}

		// fileInfo->fullFilename lives on Builder_VisitFiles' internal scratch and won't survive past this
		// call, so it has to be copied into resultsArena to outlive the walk.
		const char *fullFilename = Builder_FormatString( resultsArena, "%s", fileInfo->fullFilename );
		Builder_StringListPush( resultsArena, callbackData->globResults, fullFilename );
	}

	Builder_RewindScratch( &scratch);
}

// builds onto whatever arena it's handed - the caller flattens it if it needs to index the result
static StringList Builder_GlobFiles( arena_t *resultsArena, const StringList *globPatterns, const BuilderOptions *options ) {
	StringList globResult = { 0 };

	scratch_t scratch = Builder_GetScratch( resultsArena );
	// setup re-usable search path allocation
	char *const searchPath = Builder_ArenaAlloc( scratch.arena, char, ( BUILDER_MAX_PATH + 1 ) );

	for ( builderStringChunk_t *chunk = globPatterns->head; chunk; chunk = chunk->next ) {
		for ( uint32_t patternIndex = 0; patternIndex < chunk->count; patternIndex++ ) {
			const char *globPattern = chunk->items[patternIndex];

			// start by copying and seeking to find if there is an asterisk, and then rewind to just after the preceding slash (or start if it is say **/*.cpp)
			const char* pattern = globPattern;
			while ( *pattern != '\0' )  {  // we could also early out if they put any erroneous characters
				if ( *(pattern++) == '*' ) {
					while ( --pattern != globPattern ) {
						if ( *pattern == '\\' || *pattern == '/' ) {
							++pattern;
							break;
						}
					}
					break;
				}
			}

			if ( *pattern == '\0' ) {
				// should I just let the compile step handle the empty strings?
				if ( pattern != globPattern ) {
					Builder_LogVerbose( options, "Adding source file \"%s\" to the list of source files to build with (no glob).\n", globPattern );

					Builder_StringListPush( resultsArena, &globResult, globPattern ); // yes I realise this wasn't globbed \_O_O_/
				}
				continue;
			}

			const uint32_t globPathLen = (uint32_t) ( pattern - globPattern );
			if ( globPathLen != 0 ) {
				if ( globPathLen > BUILDER_MAX_PATH ) {
					printf( "Warning: Skipping pattern %s, path was larger than max path.\n", globPattern );
					continue;
				}
				memcpy( searchPath, globPattern, globPathLen );
			}
			searchPath[globPathLen] = '\0';

			builderGlobVisitCallbackData_t callbackData = {
				.patternSlices = Builder_SliceFilePath( scratch.arena, pattern),
				.searchPathLen = globPathLen,
				.globResults = &globResult,
				.verboseLogging = options->verboseLogging
			};

			builderFileVisitFlags_t visitFlags = BUILDER_FILE_VISIT_FILES;
			if (callbackData.patternSlices.count > 1) { // we are matching folders too
				visitFlags |= BUILDER_FILE_VISIT_RECURSIVE;
			}

			Builder_LogVerbose( options, "About to glob all source files found under user-specified pattern \"%s\" to the list of source files to build with:\n", globPattern );

			if ( !Builder_VisitFiles( resultsArena, searchPath, visitFlags, &Builder_GlobVisitCallback, &callbackData ) ) {
				printf( "Warning: Found no matches for pattern %s, at search path %s.\n", globPattern, searchPath );
			}
		}
	}

	Builder_RewindScratch( &scratch);
	return globResult;
}

#ifdef _WIN32
// the Windows SDK only ships these Setup.Configuration interfaces as C++ (STDMETHOD/DECLSPEC_UUID expand to virtual methods via inheritance)
// so for plain C we declare the vtables by hand instead
// same memory layout, called as This->vtable->Method( This, ... )
typedef struct ISetupInstance ISetupInstance;
typedef struct {
	HRESULT	( STDMETHODCALLTYPE *QueryInterface )( ISetupInstance *This, REFIID riid, void **ppvObject );
	ULONG	( STDMETHODCALLTYPE *AddRef )( ISetupInstance *This );
	ULONG	( STDMETHODCALLTYPE *Release )( ISetupInstance *This );
	HRESULT	( STDMETHODCALLTYPE *GetInstanceId )( ISetupInstance *This, BSTR *pbstrInstanceId );
	HRESULT	( STDMETHODCALLTYPE *GetInstallDate )( ISetupInstance *This, LPFILETIME pInstallDate );
	HRESULT	( STDMETHODCALLTYPE *GetInstallationName )( ISetupInstance *This, BSTR *pbstrInstallationName );
	HRESULT	( STDMETHODCALLTYPE *GetInstallationPath )( ISetupInstance *This, BSTR *pbstrInstallationPath );
	HRESULT	( STDMETHODCALLTYPE *GetInstallationVersion )( ISetupInstance *This, BSTR *pbstrInstallationVersion );
	HRESULT	( STDMETHODCALLTYPE *GetDisplayName )( ISetupInstance *This, LCID lcid, BSTR *pbstrDisplayName );
	HRESULT	( STDMETHODCALLTYPE *GetDescription )( ISetupInstance *This, LCID lcid, BSTR *pbstrDescription );
	HRESULT	( STDMETHODCALLTYPE *ResolvePath )( ISetupInstance *This, LPCOLESTR pwszRelativePath, BSTR *pbstrAbsolutePath );
} ISetupInstanceVTable;

struct ISetupInstance {
	ISetupInstanceVTable	*vtable;
};

typedef struct IEnumSetupInstances IEnumSetupInstances;
typedef struct {
	HRESULT	( STDMETHODCALLTYPE *QueryInterface )( IEnumSetupInstances *This, REFIID riid, void **ppvObject );
	ULONG	( STDMETHODCALLTYPE *AddRef )( IEnumSetupInstances *This );
	ULONG	( STDMETHODCALLTYPE *Release )( IEnumSetupInstances *This );
	HRESULT	( STDMETHODCALLTYPE *Next )( IEnumSetupInstances *This, ULONG celt, ISetupInstance **rgelt, ULONG *pceltFetched );
	HRESULT	( STDMETHODCALLTYPE *Skip )( IEnumSetupInstances *This, ULONG celt );
	HRESULT	( STDMETHODCALLTYPE *Reset )( IEnumSetupInstances *This );
	HRESULT	( STDMETHODCALLTYPE *Clone )( IEnumSetupInstances *This, IEnumSetupInstances **ppenum );
} IEnumSetupInstancesVTable;

struct IEnumSetupInstances {
	IEnumSetupInstancesVTable	*vtable;
};

typedef struct ISetupConfiguration ISetupConfiguration;
typedef struct {
	HRESULT	( STDMETHODCALLTYPE *QueryInterface )( ISetupConfiguration *This, REFIID riid, void **ppvObject );
	ULONG	( STDMETHODCALLTYPE *AddRef )( ISetupConfiguration *This );
	ULONG	( STDMETHODCALLTYPE *Release )( ISetupConfiguration *This );
	HRESULT	( STDMETHODCALLTYPE *EnumInstances )( ISetupConfiguration *This, IEnumSetupInstances **ppEnumInstances );
	HRESULT	( STDMETHODCALLTYPE *GetInstanceForCurrentProcess )( ISetupConfiguration *This, ISetupInstance **ppInstance );
	HRESULT	( STDMETHODCALLTYPE *GetInstanceForPath )( ISetupConfiguration *This, LPCWSTR wzPath, ISetupInstance **ppInstance );
} ISetupConfigurationVTable;

struct ISetupConfiguration {
	ISetupConfigurationVTable	*vtable;
};

typedef struct {
	int32_t	v0, v1, v2;
} builderMSVCVersion_t;

typedef struct {
	const char				*compilerPath;
	const char				*linkEXEPath;
	const char				*libEXEPath;

	const char				*rootFolder;
	const char				*includePath;
	const char				*libPath;

	builderMSVCVersion_t	version;
} builderMSVCInstall_t;

// How many Windows SDK versions / MSVC toolsets we're willing to find on one machine. User can specify with defines
#ifndef BUILDER_MAX_TOOLCHAIN_VERSIONS
#define BUILDER_MAX_TOOLCHAIN_VERSIONS 16
#endif

typedef struct {
	builderMSVCInstall_t	installs[BUILDER_MAX_TOOLCHAIN_VERSIONS];
	uint32_t				installsCount;
} builderFoundMSVCInstallData_t;

typedef struct {
	int32_t	v0, v1, v2, v3;
} builderWindowsSDKVersion_t;

typedef struct {
	const char					*rootFolder;
	const char					*ucrtIncludePath;
	const char					*umIncludePath;
	const char					*sharedIncludePath;
	const char					*winrtIncludePath;
	const char					*ucrtLibPath;
	const char					*umLibPath;

	builderWindowsSDKVersion_t	version;
} builderWindowsSDKInstall_t;

#ifdef _WIN32
builderMSVCInstall_t		g_msvcInstall = { 0 };
builderWindowsSDKInstall_t	g_windowsSDKInstall = { 0 };
#endif

typedef struct {
	builderWindowsSDKVersion_t	versions[BUILDER_MAX_TOOLCHAIN_VERSIONS];
	uint32_t					versionsCount;
} builderFoundWindowsSDKVersionData_t;

static void OnWindowsSDKVersionFound( arena_t *results, fileInfo_t *fileInfo, void *data ) {
	builderFoundWindowsSDKVersionData_t *foundData = (builderFoundWindowsSDKVersionData_t *) data;

	builderWindowsSDKVersion_t version = { 0 };

	if ( sscanf( fileInfo->filename, "%d.%d.%d.%d", &version.v0, &version.v1, &version.v2, &version.v3 ) != 4 ) {
		return;
	}

	BUILDER_ASSERT( foundData->versionsCount < BUILDER_MAX_TOOLCHAIN_VERSIONS && "Found more Windows SDK versions than BUILDER_MAX_TOOLCHAIN_VERSIONS allows for. Define this above builder.h to expand the search" );

	foundData->versions[foundData->versionsCount++] = version;
}

static int Builder_CompareWindowsSDKVersions( const void *a, const void *b ) {
	const builderWindowsSDKVersion_t *versionA = (const builderWindowsSDKVersion_t *) a;
	const builderWindowsSDKVersion_t *versionB = (const builderWindowsSDKVersion_t *) b;

	if ( versionA->v0 != versionB->v0 ) return versionB->v0 - versionA->v0;
	if ( versionA->v1 != versionB->v1 ) return versionB->v1 - versionA->v1;
	if ( versionA->v2 != versionB->v2 ) return versionB->v2 - versionA->v2;

	return versionB->v3 - versionA->v3;
}

// The paths this hands back via outSDK live for the whole build, so they go on the caller's scratch.
static bool Builder_GetWindowsSDKInstall( arena_t *results, builderWindowsSDKInstall_t *outSDK ) {
	BUILDER_ASSERT( outSDK );

	bool success = false;
	HKEY key = NULL;
	const char *windowsSDKRoot = NULL;

	builderFoundWindowsSDKVersionData_t foundData = { 0 };
	bool found = false;

	DWORD windowsSDKRootLength = 0;
	const char *winSDKRegKey = "KitsRoot10";
	const char *winSDKRegPath = "SOFTWARE\\Microsoft\\Windows Kits\\Installed Roots";
	LSTATUS status = RegOpenKeyExA( HKEY_LOCAL_MACHINE, winSDKRegPath, 0, KEY_QUERY_VALUE | KEY_WOW64_32KEY | KEY_ENUMERATE_SUB_KEYS, &key );

	if ( status != ERROR_SUCCESS ) {
		Builder_Error(
			"Failed to get Windows SDK installation directory from your Windows registry.  The registry path \"%s\" doesn't seem to exist on your machine.\n"
			"This likely means you don't have the Windows SDK installed on your machine.\n"
			"In order to build using MSVC (which you asked me to do) then you will need to install a version of the Windows SDK on your PC.\n"
			, winSDKRegPath
		);

		goto cleanup;
	}

	status = RegQueryValueExA( key, winSDKRegKey, NULL, NULL, NULL, &windowsSDKRootLength );

	if ( status == ERROR_SUCCESS ) {
		// valueStrLength from RegQueryValueExA includes the null terminator for REG_SZ strings
		// snapshot results first - if this doesn't pan out (wrong type, or the read fails) we rewind
		// back to here rather than leaving the failed attempt sat on it
		arenaRewindSpot_t attempt = Builder_ArenaTell( results );
		char *windowsSDKRootStr = Builder_ArenaAlloc( results, char, windowsSDKRootLength );

		DWORD windowsSDKRootType = 0;

		status = RegQueryValueExA( key, winSDKRegKey, NULL, &windowsSDKRootType, (LPBYTE) windowsSDKRootStr, &windowsSDKRootLength );

		if ( status == ERROR_SUCCESS && windowsSDKRootType == REG_SZ ) {
			windowsSDKRoot = windowsSDKRootStr;
		} else {
			Builder_RewindArena( results, &attempt );
		}
	}

	if ( !windowsSDKRoot ) {
		Builder_Error(
			"Failed to get Windows SDK installation directory from your Windows registry.  The registry key \"%s\" couldn't be queried from the registry path: \"%s\"\n"
			"This likely means you don't have the Windows SDK installed on your machine.\n"
			"In order to build using MSVC (which you asked me to do) then you will need to install a version of the Windows SDK on your PC.\n"
			, winSDKRegKey
			, winSDKRegPath
		);

		goto cleanup;
	}

	{
		char *windowsSDKLibFolder = Builder_FormatString( results, "%sLib", windowsSDKRoot );

		bool visited = Builder_VisitFiles( results, windowsSDKLibFolder, BUILDER_FILE_VISIT_FOLDERS, OnWindowsSDKVersionFound, &foundData );

		if ( !visited ) {
			Builder_Error( "Failed to query your Windows SDK root folder for the version of the Windows SDK that you asked for.  Do you definitely have at least one version of the Windows SDK installed?\n" );
			goto cleanup;
		}
	}

	if ( foundData.versionsCount == 0 ) {
		Builder_Error( "Failed to find any versions of the Windows SDK installed under \"%s\".\n", windowsSDKRoot );
		goto cleanup;
	}

	// newest version first
	qsort( foundData.versions, foundData.versionsCount, sizeof( builderWindowsSDKVersion_t ), Builder_CompareWindowsSDKVersions );

	// find the first windows SDK folder that isnt malformed
	for ( uint32_t versionIndex = 0; versionIndex < foundData.versionsCount; versionIndex++ ) {
		builderWindowsSDKVersion_t *version = &foundData.versions[versionIndex];

		// these go straight onto the results scratch because they're what we hand back if this version turns out to be the one.
		// if it isn't, this marker lets us drop just this attempt without touching whatever the caller already had in there
		arenaRewindSpot_t attempt = Builder_ArenaTell( results );

		char *ucrtIncludeFolder = Builder_FormatString( results, "%sinclude\\%d.%d.%d.%d\\ucrt", windowsSDKRoot, version->v0, version->v1, version->v2, version->v3 );
		char *umIncludeFolder = Builder_FormatString( results, "%sinclude\\%d.%d.%d.%d\\um", windowsSDKRoot, version->v0, version->v1, version->v2, version->v3 );
		char *sharedIncludeFolder = Builder_FormatString( results, "%sinclude\\%d.%d.%d.%d\\shared", windowsSDKRoot, version->v0, version->v1, version->v2, version->v3 );
		char *winrtIncludeFolder = Builder_FormatString( results, "%sinclude\\%d.%d.%d.%d\\winrt", windowsSDKRoot, version->v0, version->v1, version->v2, version->v3 );
		char *ucrtLibFolder = Builder_FormatString( results, "%sLib\\%d.%d.%d.%d\\ucrt\\x64", windowsSDKRoot, version->v0, version->v1, version->v2, version->v3 );
		char *umLibFolder = Builder_FormatString( results, "%sLib\\%d.%d.%d.%d\\um\\x64", windowsSDKRoot, version->v0, version->v1, version->v2, version->v3 );

		uint32_t missingFoldersCount = 0;
		const char *missingFolders[6] = { 0 };

		if ( !Builder_FolderExists( ucrtIncludeFolder ) ) {
			missingFolders[missingFoldersCount++] = ucrtIncludeFolder;
		}

		if ( !Builder_FolderExists( umIncludeFolder ) ) {
			missingFolders[missingFoldersCount++] = umIncludeFolder;
		}

		if ( !Builder_FolderExists( sharedIncludeFolder ) ) {
			missingFolders[missingFoldersCount++] = sharedIncludeFolder;
		}

		if ( !Builder_FolderExists( winrtIncludeFolder ) ) {
			missingFolders[missingFoldersCount++] = winrtIncludeFolder;
		}

		if ( !Builder_FolderExists( ucrtLibFolder ) ) {
			missingFolders[missingFoldersCount++] = ucrtLibFolder;
		}

		if ( !Builder_FolderExists( umLibFolder ) ) {
			missingFolders[missingFoldersCount++] = umLibFolder;
		}

		if ( missingFoldersCount > 0 ) {
			scratch_t scratch = Builder_GetScratch( results );
			stringBuilder_t sb = { 0 };

			StringBuilder_Appendf( scratch.arena, &sb, "Version %d.%d.%d.%d of your Windows SDK installation is malformed because the following folder(s) could not be found:\n", version->v0, version->v1, version->v2, version->v3 );

			for ( uint32_t missingFolderIndex = 0; missingFolderIndex < missingFoldersCount; missingFolderIndex++ ) {
				StringBuilder_Appendf( scratch.arena, &sb, " - %s\n", missingFolders[missingFolderIndex] );
			}

			StringBuilder_Appendf( scratch.arena, &sb, "You must have the following folders in your Windows SDK install:\n"
				"    include/<version>/ucrt\n"
				"    include/<version>/um\n"
				"    include/<version>/shared\n"
				"    include/<version>/winrt\n"
				"    Lib/<version>/ucrt/x64\n"
				"    Lib/<version>/um/x64\n"
			);

			StringBuilder_Appendf( scratch.arena, &sb, "If you want to use this version of the Windows SDK specifically, you will need to fix this yourself.\n" );

			char *message = StringBuilder_ToString( scratch.arena, &sb, NULL );
			Builder_Warning( "%s", message );

			Builder_RewindScratch( &scratch );

			// this version is no good, so drop the paths we speculatively built for it
			Builder_RewindArena( results, &attempt );

			continue;
		}

		outSDK->rootFolder			= windowsSDKRoot;
		outSDK->ucrtIncludePath		= ucrtIncludeFolder;
		outSDK->umIncludePath		= umIncludeFolder;
		outSDK->sharedIncludePath	= sharedIncludeFolder;
		outSDK->winrtIncludePath	= winrtIncludeFolder;
		outSDK->ucrtLibPath			= ucrtLibFolder;
		outSDK->umLibPath			= umLibFolder;
		outSDK->version				= *version;

		found = true;

		break;
	}

	if ( !found ) {
		Builder_Error(
			"Failed to find a valid installation of the Windows SDK on your machine.\n"
			"You have %u versions of the Windows SDK installed on your machine, and somehow all of them appear to be malformed.\n"
			"You need to install a version through the Visual Studio Installer, or via the separate Build Tools installer from Microsoft.\n"
			, foundData.versionsCount
		);

		goto cleanup;
	}

	printf( "Using latest valid Windows SDK version that was found, which was: %d.%d.%d.%d\n", outSDK->version.v0, outSDK->version.v1, outSDK->version.v2, outSDK->version.v3 );

	success = true;

cleanup:
	if ( key ) {
		RegCloseKey( key );
	}

	return success;
}

// MSVC toolset folders are named like "14.44.35207" - that's the only part of each entry we need to parse ourselves
// the paths built here end up in the install we hand back, so they go on the caller's scratch
static void Builder_OnMSVCInstallFound( arena_t *results, fileInfo_t *fileInfo, void *data ) {
	BUILDER_ASSERT( results );

	builderFoundMSVCInstallData_t *foundData = (builderFoundMSVCInstallData_t *) data;

	builderMSVCVersion_t version = { 0 };

	if ( sscanf( fileInfo->filename, "%d.%d.%d", &version.v0, &version.v1, &version.v2 ) != 3 ) {
		return;
	}

	const char *rootFolder = fileInfo->fullFilename;

	builderMSVCInstall_t install = {
		.compilerPath	= Builder_FormatString( results, "%s\\bin\\Hostx64\\x64\\cl.exe", rootFolder ),
		.linkEXEPath	= Builder_FormatString( results, "%s\\bin\\Hostx64\\x64\\link.exe", rootFolder ),
		.libEXEPath		= Builder_FormatString( results, "%s\\bin\\Hostx64\\x64\\lib.exe", rootFolder ),
		.rootFolder		= Builder_FormatString( results, "%s", rootFolder ),
		.includePath	= Builder_FormatString( results, "%s\\include", rootFolder ),
		.libPath		= Builder_FormatString( results, "%s\\lib\\x64", rootFolder ),
		.version		= version,
	};

	BUILDER_ASSERT( foundData->installsCount < BUILDER_MAX_TOOLCHAIN_VERSIONS && "Found more MSVC installs than BUILDER_MAX_TOOLCHAIN_VERSIONS allows for. Define this above builder.h to expand the search" );

	foundData->installs[foundData->installsCount++] = install;
}

static bool Builder_MSVCNotInstalled( void ) {
	Builder_Error( "No valid MSVC installation found on your PC.  You need to install one through either the Visual Studio Installer or through the MS Build Tools.\n" );
	return false;
}

static int Builder_CompareMSVCInstallVersions( const void *a, const void *b ) {
	const builderMSVCInstall_t *installA = (const builderMSVCInstall_t *) a;
	const builderMSVCInstall_t *installB = (const builderMSVCInstall_t *) b;

	if ( installA->version.v0 != installB->version.v0 ) {
		return installB->version.v0 - installA->version.v0;
	}

	if ( installA->version.v1 != installB->version.v1 ) {
		return installB->version.v1 - installA->version.v1;
	}

	return installB->version.v2 - installA->version.v2;
}

// get all versions of MSVC
// thanks to Microsoft we will be doing that in the most retarded way possible
// The paths this hands back via outInstall live for the whole build, so they go on the caller's scratch.
static bool Builder_GetMSVCInstall( arena_t *results, builderMSVCInstall_t *outInstall ) {
	BUILDER_ASSERT( results );
	BUILDER_ASSERT( outInstall );

	// the VS install paths we search through are only needed while we're searching, so they don't go on the caller's scratch
	scratch_t scratch = Builder_GetScratch( results );

	bool success = false;

	// these are fixed, documented GUIDs for Microsoft.VisualStudio.Setup.Configuration.Native - not something we get to choose
	const GUID IID_ISetupConfiguration	= { 0x42843719, 0xDB4C, 0x46C2, { 0x8E, 0x7C, 0x64, 0xF1, 0x81, 0x6E, 0xFD, 0x5B } };
	const GUID CLSID_SetupConfiguration	= { 0x177F0C4A, 0x1CD3, 0x4DE7, { 0xA3, 0x2C, 0x71, 0xDB, 0xBB, 0x9F, 0xA3, 0x6D } };

	HRESULT hr = S_OK;

	hr = CoInitializeEx( NULL, COINIT_MULTITHREADED );

	if ( FAILED( hr ) ) {
		Builder_Error( "CoInitializeEx() call failed: 0x%X\n", hr );
		return false;
	}

	bool foundMSVCInstall = false;
	uint32_t useVersionIndex = 0;
	builderFoundMSVCInstallData_t foundData = { 0 };
	IEnumSetupInstances *instances = NULL;
	ISetupInstance *instance = NULL;
	ULONG foundInstance = 0;

	ISetupConfiguration *setupConfig = NULL;
#ifdef __cplusplus
	hr = CoCreateInstance( CLSID_SetupConfiguration, NULL, CLSCTX_INPROC_SERVER, IID_ISetupConfiguration, (void **) &setupConfig );
#else
	hr = CoCreateInstance( &CLSID_SetupConfiguration, NULL, CLSCTX_INPROC_SERVER, &IID_ISetupConfiguration, (void **) &setupConfig );
#endif

	if ( hr == REGDB_E_CLASSNOTREG ) {
		success = Builder_MSVCNotInstalled();
		goto cleanup;
	}

	if ( FAILED( hr ) ) {
		Builder_Error( "CoCreateInstance() call failed: 0x%X\n", hr );
		goto cleanup;
	}

	hr = setupConfig->vtable->EnumInstances( setupConfig, &instances );

	if ( FAILED( hr ) ) {
		Builder_Error( "setupConfig->EnumInstances() call failed: 0x%X\n", hr );
		goto cleanup;
	}

	if ( !instances ) {
		Builder_Error( "setupConfig->EnumInstances() returned no instances.  Bailing...\n" );
		goto cleanup;
	}

	hr = instances->vtable->Next( instances, 1, &instance, &foundInstance );

	while ( foundInstance ) {
		BSTR visualStudioInstallationPathWide = NULL;
		hr = instance->vtable->GetInstallationPath( instance, &visualStudioInstallationPathWide );

		if ( FAILED( hr ) ) {
			Builder_Error( "instance->GetInstallationPath() call failed: 0x%X\n", hr );
			instance->vtable->Release( instance );
			goto cleanup;
		}

		char *visualStudioInstallationPath = NULL;

		{
			UINT wideLength = SysStringLen( visualStudioInstallationPathWide );

			int utf8Length = WideCharToMultiByte( CP_UTF8, 0, visualStudioInstallationPathWide, (int) wideLength, NULL, 0, NULL, NULL );

			if ( utf8Length <= 0 ) {
				Builder_Error( "First WideCharToMultiByte() call failed: WinAPI error code 0x%X\n", GetLastError() );
				SysFreeString( visualStudioInstallationPathWide );
				instance->vtable->Release( instance );
				goto cleanup;
			}

			visualStudioInstallationPath = Builder_ArenaAlloc( scratch.arena, char, (uint64_t) utf8Length + 1 );

			int converted = WideCharToMultiByte( CP_UTF8, 0, visualStudioInstallationPathWide, (int) wideLength, visualStudioInstallationPath, utf8Length, NULL, NULL );

			if ( !converted ) {
				Builder_Error( "Second WideCharToMultiByte() call failed: WinAPI error code 0x%X\n", GetLastError() );
				SysFreeString( visualStudioInstallationPathWide );
				instance->vtable->Release( instance );
				goto cleanup;
			}

			visualStudioInstallationPath[utf8Length] = 0;
		}

		SysFreeString( visualStudioInstallationPathWide );

		char *msvcRootFolder = Builder_FormatString( scratch.arena, "%s\\VC\\Tools\\MSVC", visualStudioInstallationPath );

		if ( !Builder_VisitFiles( results, msvcRootFolder, BUILDER_FILE_VISIT_FOLDERS, Builder_OnMSVCInstallFound, &foundData ) ) {
			Builder_Error( "Failed to query for MSVC installation folders under \"%s\".\n", msvcRootFolder );
			instance->vtable->Release( instance );
			goto cleanup;
		}

		instance->vtable->Release( instance );

		hr = instances->vtable->Next( instances, 1, &instance, &foundInstance );
	}

	if ( foundData.installsCount == 0 ) {
		success = Builder_MSVCNotInstalled();
		goto cleanup;
	}

	// newest version first
	qsort( foundData.installs, foundData.installsCount, sizeof( builderMSVCInstall_t ), Builder_CompareMSVCInstallVersions );

	for ( uint32_t versionIndex = 0; versionIndex < foundData.installsCount; versionIndex++ ) {
		builderMSVCInstall_t *install = &foundData.installs[versionIndex];

		uint32_t missingFoldersCount = 0;
		const char *missingFolders[2] = { 0 };

		if ( !Builder_FolderExists( install->includePath ) ) {
			missingFolders[missingFoldersCount++] = install->includePath;
		}

		if ( !Builder_FolderExists( install->libPath ) ) {
			missingFolders[missingFoldersCount++] = install->libPath;
		}

		if ( missingFoldersCount > 0 ) {
			stringBuilder_t sb = { 0 };

			StringBuilder_Appendf( scratch.arena, &sb, "Version %d.%d.%d of your MSVC installation is malformed because the following folder(s) could not be found:\n", install->version.v0, install->version.v1, install->version.v2 );

			for ( uint32_t missingFolderIndex = 0; missingFolderIndex < missingFoldersCount; missingFolderIndex++ ) {
				StringBuilder_Appendf( scratch.arena, &sb, " - %s\n", missingFolders[missingFolderIndex] );
			}

			StringBuilder_Appendf( scratch.arena, &sb, "You must have the following folders in your MSVC install:\n"
				"    %s\n"
				"    %s\n"
				, install->includePath
				, install->libPath
			);

			StringBuilder_Appendf( scratch.arena, &sb, "If you want to use this version of MSVC specifically, you will need to fix this yourself.\n" );

			char *message = StringBuilder_ToString( scratch.arena, &sb, NULL );
			Builder_Warning( "%s", message );

			Builder_RewindScratch( &scratch );

			continue;
		}

		useVersionIndex = versionIndex;
		foundMSVCInstall = true;

		break;
	}

	if ( !foundMSVCInstall ) {
		success = Builder_MSVCNotInstalled();
		goto cleanup;
	}

	*outInstall = foundData.installs[useVersionIndex];

	printf( "Using latest valid MSVC version that was found, which was: %d.%d.%d\n", outInstall->version.v0, outInstall->version.v1, outInstall->version.v2 );

	success = true;

cleanup:
	if ( instances ) {
		instances->vtable->Release( instances );
	}

	if ( setupConfig ) {
		setupConfig->vtable->Release( setupConfig );
	}

	CoUninitialize();

	return success;
}
#endif // _WIN32

static const char *GetLanguageVersionString( const LanguageVersion version ) {
	switch ( version ) {
		case LANGUAGE_VERSION_UNSET:	return NULL;
		case LANGUAGE_VERSION_C89:		return "c89";
		case LANGUAGE_VERSION_C99:		return "c99";
		case LANGUAGE_VERSION_C11:		return "c11";
		case LANGUAGE_VERSION_C17:		return "c17";
		case LANGUAGE_VERSION_C23:		return "c23";
		case LANGUAGE_VERSION_CPP11:	return "c++11";
		case LANGUAGE_VERSION_CPP14:	return "c++14";
		case LANGUAGE_VERSION_CPP17:	return "c++17";
		case LANGUAGE_VERSION_CPP20:	return "c++20";
		case LANGUAGE_VERSION_CPP23:	return "c++23";
	}

	BUILDER_ASSERT( "Unrecognised language version specified!\n" );

	return NULL;
}

static const char *Builder_GetOptimizationString_Clang( const Optimization optimization ) {
	switch ( optimization ) {
		case OPTIMIZATION_NONE:						return "";
		case OPTIMIZATION_DISABLED:					return "-O0";
		case OPTIMIZATION_PROGRAM_SIZE:				return "-Os";
		case OPTIMIZATION_PROGRAM_SIZE_AGGRESSIVE:	return "-Oz";
		case OPTIMIZATION_PROGRAM_BALANCED:			return "-O2";
		case OPTIMIZATION_PROGRAM_SPEED:			return "-O3";
	}

	BUILDER_ASSERT( "Unrecognised optimization mode specified!\n" );

	return NULL;
}

static const char *Builder_GetOptimizationString_MSVC( const Optimization optimization ) {
	switch ( optimization ) {
		case OPTIMIZATION_NONE:						return "";
		case OPTIMIZATION_DISABLED:					return "/Od";
		case OPTIMIZATION_PROGRAM_SIZE:				return "/O1";
		case OPTIMIZATION_PROGRAM_SIZE_AGGRESSIVE:	return "/O1";
		case OPTIMIZATION_PROGRAM_BALANCED:			return "/O2";
		case OPTIMIZATION_PROGRAM_SPEED:			return "/O2";
	}

	BUILDER_ASSERT( "Unrecognised optimization mode specified!\n" );

	return NULL;
}

// the version string it finds is handed back to the caller, so it goes on their scratch
static char *Builder_ExtractVersionNumber( arena_t *results, const char *text ) {
	for ( const char *c = text; *c; c++ ) {
		if ( !isdigit( (unsigned char) *c ) ) {
			continue;
		}

		const char *start = c;
		const char *end = c;
		bool sawDot = false;

		while ( *end && ( isdigit( (unsigned char) *end ) || *end == '.' ) ) {
			if ( *end == '.' ) {
				sawDot = true;
			}

			end++;
		}

		while ( end > start && *( end - 1 ) == '.' ) {
			end--;
		}

		if ( sawDot ) {
			return Builder_FormatString( results, "%.*s", (int) ( end - start ), start );
		}

		c = end - 1;
	}

	return NULL;
}

static double Builder_TimeMS( void ) {
#if defined( _WIN32 )
	static LARGE_INTEGER frequency = { 0 };
	static bool haveFrequency = false;

	if ( !haveFrequency ) {
		QueryPerformanceFrequency( &frequency );
		haveFrequency = true;
	}

	LARGE_INTEGER counter;
	QueryPerformanceCounter( &counter );

	return ( (double) counter.QuadPart * 1000.0 ) / (double) frequency.QuadPart;
#elif defined( __linux__ )
	struct timespec ts;
	if ( clock_gettime( CLOCK_MONOTONIC, &ts ) == -1 ) {
		int err = errno;
		Builder_Error( "Failed to get time: %s\n", strerror( err ) );
		return 0.0;
	}

	return ( (double) ts.tv_sec * 1000.0 ) + ( (double) ts.tv_nsec / 1000000.0 );
#endif
}

static uint32_t Builder_GetNumCPUCores( void ) {
#if defined( _WIN32 )
	SYSTEM_INFO sysInfo;
	GetSystemInfo( &sysInfo );

	return (uint32_t) sysInfo.dwNumberOfProcessors;
#elif defined( __linux__ )
	long numCores = sysconf( _SC_NPROCESSORS_ONLN );
	int err = errno;

	if ( numCores < 0 ) {
		Builder_Error( "Failed to query CPU for number of available cores: %s\n", strerror( err ) );
		return 1;
	}

	return (uint32_t) numCores;
#endif
}

#if defined( _WIN32 )
typedef volatile LONG		builderAtomic32_t;
typedef HANDLE				builderThread_t;
#elif defined( __linux__ )
typedef volatile int32_t	builderAtomic32_t;
typedef pthread_t			builderThread_t;
#endif

static uint32_t Builder_AtomicIncrement( builderAtomic32_t *value ) {
#if defined( _WIN32 )
	return (uint32_t) InterlockedIncrement( value );
#elif defined( __linux__ )
	return (uint32_t) __sync_add_and_fetch( value, 1 );
#endif
}

typedef struct builderCompileContext_t {
	BuildConfig					*config;
	const char					*compilerPath;
	bool						useMSVCSyntax;
#if defined( _WIN32 )
	bool						debugDefineSet;
#endif
} builderCompileContext_t;

static void Builder_AddSanitizerArgs( scratch_t *scratch, stringBuilder_t *compileArgs, const SanitizerFlags sanitizers, const char *sanitizerBaseArg ) {
	if ( sanitizers == 0 ) {
		return;
	}

	StringBuilder_Appendf( scratch->arena, compileArgs, "%s=", sanitizerBaseArg );

	bool isFirstSanitizer = true;

	for ( uint32_t sanitizerBitIndex = 0; sanitizerBitIndex < sanitizers; sanitizerBitIndex++ ) {
		SanitizerFlagBits sanitizerFlagBit = (SanitizerFlagBits) ( 1 << sanitizerBitIndex );

		if ( ( sanitizers & sanitizerFlagBit ) == 0 ) {
			continue;
		}

		const char *sanitizerName = NULL;

		switch ( sanitizerFlagBit ) {
			case SANITIZER_UNDEFINED_BEHAVIOR:	sanitizerName = "undefined";	break;
			case SANITIZER_MEMORY:				sanitizerName = "memory";		break;
			case SANITIZER_ADDRESS:				sanitizerName = "address";		break;
			case SANITIZER_LEAK:				sanitizerName = "leak";			break;
			case SANITIZER_THREAD:				sanitizerName = "thread";		break;
		}

		StringBuilder_Appendf( scratch->arena, compileArgs, isFirstSanitizer ? "%s" : ",%s", sanitizerName );

		isFirstSanitizer = false;
	}

	StringBuilder_Appendf( scratch->arena, compileArgs, " " );
}

static const char *Builder_CreateCompilationCommand( arena_t *commandArena, builderCompileContext_t *context ) {
	BuildConfig *config = context->config;
	scratch_t scratch = Builder_GetScratch( commandArena );

	stringBuilder_t compileArgs = { 0 };
	StringBuilder_Appendf( scratch.arena, &compileArgs, "\"%s\" ", context->compilerPath );

#ifdef _WIN32
	if ( context->useMSVCSyntax ) {
		StringBuilder_Appendf( scratch.arena, &compileArgs, "/nologo " );	// disable MSVC spamming its copyright banner for every compilation unit
		StringBuilder_Appendf( scratch.arena, &compileArgs, "/c " );

		if ( config->languageVersion != LANGUAGE_VERSION_UNSET ) {
			StringBuilder_Appendf( scratch.arena, &compileArgs, "/std:%s ", GetLanguageVersionString( config->languageVersion ) );
		}

		if ( !config->removeSymbols ) {
			StringBuilder_Appendf( scratch.arena, &compileArgs, "/Z7 " );
		}

		StringBuilder_Appendf( scratch.arena, &compileArgs, "%s ", Builder_GetOptimizationString_MSVC( config->optimization ) );

		for ( builderStringChunk_t *chunk = config->defines.head; chunk; chunk = chunk->next ) {
			for ( uint32_t defineIndex = 0; defineIndex < chunk->count; defineIndex++ ) {
				StringBuilder_Appendf( scratch.arena, &compileArgs, "/D%s ", chunk->items[defineIndex] );

				if ( !context->debugDefineSet && _strnicmp( "_DEBUG", chunk->items[defineIndex], sizeof( "_DEBUG" ) ) == 0 ) {
					context->debugDefineSet = true;
				} else if ( !config->useDynamicRuntimeOnWindows && _strnicmp( "_DLL", chunk->items[defineIndex], sizeof( "_DLL" ) ) == 0 ) {
					config->useDynamicRuntimeOnWindows = true;
				}
			}
		}

		// cl.exe doesn't know where the CRT/Windows SDK headers live unless you're in a Developer Command Prompt, so point it there ourselves
		StringBuilder_Appendf( scratch.arena, &compileArgs, "/I\"%s\" /I\"%s\" /I\"%s\" /I\"%s\" /I\"%s\" "
			, g_msvcInstall.includePath
			, g_windowsSDKInstall.ucrtIncludePath
			, g_windowsSDKInstall.umIncludePath
			, g_windowsSDKInstall.sharedIncludePath
			, g_windowsSDKInstall.winrtIncludePath );

		for ( builderStringChunk_t *chunk = config->additionalIncludes.head; chunk; chunk = chunk->next ) {
			for ( uint32_t includeIndex = 0; includeIndex < chunk->count; includeIndex++ ) {
				StringBuilder_Appendf( scratch.arena, &compileArgs, "/I%s ", chunk->items[includeIndex] );
			}
		}

		if ( config->warningsAsErrors ) {
			StringBuilder_Appendf( scratch.arena, &compileArgs, "/WX " );
		}

		bool sawWarningLevel = false;

		for ( builderStringChunk_t *chunk = config->warningLevels.head; chunk; chunk = chunk->next ) {
			for ( uint32_t warningLevelIndex = 0; warningLevelIndex < chunk->count; warningLevelIndex++ ) {
				const char *warningLevel = chunk->items[warningLevelIndex];

				if ( sawWarningLevel ) {
					Builder_Error( "MSVC only allows one warning level to be set at a time, but you specified more than one.\n" );
					Builder_RewindScratch( &scratch );
					return NULL;
				}

				if ( !Builder_IsWarningLevelAllowed_MSVC( warningLevel ) ) {
					Builder_Error(
						"Warning level \"%s\" is not a valid one.  Allowed warning levels are:\n"
						"    /W0\n"
						"    /W1\n"
						"    /W2\n"
						"    /W3\n"
						"    /W4\n"
						"    /Wall\n"
						, warningLevel
					);

					Builder_RewindScratch( &scratch );
					return NULL;
				}

				StringBuilder_Appendf( scratch.arena, &compileArgs, "%s ", warningLevel );

				sawWarningLevel = true;
			}
		}

		if ( context->debugDefineSet ) {
			if ( config->useDynamicRuntimeOnWindows ) {
				StringBuilder_Appendf( scratch.arena, &compileArgs, "/MDd " );
			} else {
				StringBuilder_Appendf( scratch.arena, &compileArgs, "/MTd " );
			}
		} else {
			if ( config->useDynamicRuntimeOnWindows ) {
				StringBuilder_Appendf( scratch.arena, &compileArgs, "/MD " );
			} else {
				StringBuilder_Appendf( scratch.arena, &compileArgs, "/MT " );
			}
		}

		StringBuilder_Appendf( scratch.arena, &compileArgs, "/showIncludes " );

		// clang-cl only accepts the slash form for address
		// so use the dash form which both it and cl.exe accept for everything
		Builder_AddSanitizerArgs( &scratch, &compileArgs, config->sanitizers, "-fsanitize" );
	} else
#endif
	{
		if ( config->languageVersion != LANGUAGE_VERSION_UNSET ) {
			StringBuilder_Appendf( scratch.arena, &compileArgs, "-std=%s ", GetLanguageVersionString( config->languageVersion ) );
		}

		if ( !config->removeSymbols ) {
			StringBuilder_Appendf( scratch.arena, &compileArgs, "-g " );
		}

		StringBuilder_Appendf( scratch.arena, &compileArgs, "%s ", Builder_GetOptimizationString_Clang( config->optimization ) );

#if defined( __linux__ )
		if ( config->binaryType == BINARY_TYPE_DYNAMIC_LIBRARY ) {
			StringBuilder_Appendf( scratch.arena, &compileArgs, "-fPIC " );
		}
#endif

		StringBuilder_Appendf( scratch.arena, &compileArgs, "-c " );

		for ( builderStringChunk_t *chunk = config->defines.head; chunk; chunk = chunk->next ) {
			for ( uint32_t defineIndex = 0; defineIndex < chunk->count; defineIndex++ ) {
				StringBuilder_Appendf( scratch.arena, &compileArgs, "-D%s ", chunk->items[defineIndex] );

#if defined( _WIN32 )
				if ( !context->debugDefineSet && _strnicmp( "_DEBUG", chunk->items[defineIndex], sizeof( "_DEBUG" ) ) == 0 ) {
					context->debugDefineSet = true;
				} else if ( !config->useDynamicRuntimeOnWindows && _strnicmp( "_DLL", chunk->items[defineIndex], sizeof( "_DLL" ) ) == 0 ) {
					config->useDynamicRuntimeOnWindows = true;
				}
#endif
			}
		}

#if defined( _WIN32 )
		// we are handling these things for them on windows
		StringBuilder_Appendf( scratch.arena, &compileArgs, " -D_MT ");
		if ( config->useDynamicRuntimeOnWindows ) {
			StringBuilder_Appendf( scratch.arena, &compileArgs, "-D_DLL " );
		}
#endif

		for ( builderStringChunk_t *chunk = config->additionalIncludes.head; chunk; chunk = chunk->next ) {
			for ( uint32_t includeIndex = 0; includeIndex < chunk->count; includeIndex++ ) {
				StringBuilder_Appendf( scratch.arena, &compileArgs, "-I%s ", chunk->items[includeIndex] );
			}
		}

		if ( config->warningsAsErrors ) {
			StringBuilder_Appendf( scratch.arena, &compileArgs, "-Werror " );
		}

		for ( builderStringChunk_t *chunk = config->warningLevels.head; chunk; chunk = chunk->next ) {
			for ( uint32_t warningLevelIndex = 0; warningLevelIndex < chunk->count; warningLevelIndex++ ) {
				const char *warningLevel = chunk->items[warningLevelIndex];

				if ( !Builder_IsWarningLevelAllowed_Clang( warningLevel ) ) {
					Builder_Error(
						"Warning level \"%s\" is not a valid one.  Allowed warning levels are:\n"
						"    -Wall\n"
						"    -Weverything\n"
						"    -Wextra\n"
						"    -Wpedantic\n"
						, warningLevel
					);

					Builder_RewindScratch( &scratch );
					return NULL;
				}

				StringBuilder_Appendf( scratch.arena, &compileArgs, "%s ", warningLevel );
			}
		}

		Builder_AddSanitizerArgs( &scratch, &compileArgs, config->sanitizers, "-fsanitize" );

		StringBuilder_Appendf( scratch.arena, &compileArgs, "-MD -MF - " );
	}

	for ( builderStringChunk_t *chunk = config->ignoreWarnings.head; chunk; chunk = chunk->next ) {
		for ( uint32_t ignoreWarningIndex = 0; ignoreWarningIndex < chunk->count; ignoreWarningIndex++ ) {
			StringBuilder_Appendf( scratch.arena, &compileArgs, "%s ", chunk->items[ignoreWarningIndex] );
		}
	}

	for ( builderStringChunk_t *chunk = config->additionalCompilerArguments.head; chunk; chunk = chunk->next ) {
		for ( uint32_t extraArgIndex = 0; extraArgIndex < chunk->count; extraArgIndex++ ) {
			StringBuilder_Appendf( scratch.arena, &compileArgs, "%s ", chunk->items[extraArgIndex] );
		}
	}

	Builder_RewindScratch( &scratch );

	return StringBuilder_ToString( commandArena, &compileArgs, NULL );
}

typedef struct builderCompilePacket_t {
	const char	*sourceFile;
	const char	*intermediateFile;
	const char	*compileCommand;
	uint64_t	compileCommandHash;
	uint64_t	objectWriteTime;
} builderCompilePacket_t;

typedef struct builderCompileJobDependencyInfo_t {
	char		*dependencyString;
	uint64_t	dependencyLength;
	uint32_t	compilePacketIndex;
} builderCompileJobDependencyInfo_t;

typedef struct builderCompileJobDependencyOutput_t {
	arena_t								*arena; // threadlocal arena will die we need a custom one
	builderCompileJobDependencyInfo_t	*dependencyInfos;
	uint64_t							dependencyInfoCount;
} builderCompileJobDependencyOutput_t;

typedef struct builderCompileJobPool_t {
	builderCompilePacket_t				*compilePackets;
	uint32_t							compilePacketCount;
	bool								useMSVCSyntax;
	bool								consolidateCompilerArgs;
	builderCompileJobDependencyOutput_t	*dependencyOutputs;
	builderAtomic32_t					dependencyOutputIndex;
	builderAtomic32_t					nextCompileCommandIndex;
	builderAtomic32_t					numFailed;
} builderCompileJobPool_t;

static bool Builder_CompileSourceFile( builderCompileJobPool_t *pool, builderCompileJobDependencyOutput_t *dependencyOutput, uint32_t compilePacketIndex ) {
	scratch_t scratch = Builder_GetScratch( NULL );

	builderCompilePacket_t *compilePacket = &pool->compilePackets[compilePacketIndex];

	// consolidated mode already printed the shared args once, so only show what this file builds into
	if ( pool->consolidateCompilerArgs ) {
		printf( "%s -> %s\n", compilePacket->sourceFile, compilePacket->intermediateFile );
	} else {
		printf( "%s\n", compilePacket->compileCommand );
	}

	char *compilerOutput = NULL;
	int32_t compileResult = Builder_RunProcess( scratch.arena, compilePacket->compileCommand, false, &compilerOutput );

#if defined( _WIN32 )
	if ( pool->useMSVCSyntax ) {
		uint32_t fileNameStart = 0;
		const char *sourceCurrent = compilePacket->sourceFile;
		for ( uint32_t i = 0; sourceCurrent[i] != '\0'; ++i ) {
			if ( sourceCurrent[i] == '\\' || sourceCurrent[i] == '/' ) {
				fileNameStart = i + 1;
			}
		}

		// cl echoes the source file name before its /showIncludes notes, clang-cl doesn't
		// so the dependency block starts at the first include note instead of at the file name
		const char *includePrefix = "Note: including file: ";

		const char *dependencyStart = NULL;
		const char *dependencyEnd = NULL;
		const char *current = compilerOutput;
		const char *fileName = sourceCurrent + fileNameStart;
		while ( current && *current ) {
			const char *lineStart = current;
			const char *lineEnd = strchr( current, '\n' );
			if ( !lineEnd ) {
				lineEnd = strchr( current, '\0' );
			}

			bool isIncludeNote = Builder_StringStartsWith( lineStart, includePrefix );

			if ( !dependencyStart && isIncludeNote ) {
				dependencyStart = lineStart;
			} else if ( dependencyStart && !dependencyEnd && !isIncludeNote ) {
				dependencyEnd = lineStart;
			}

			bool inDependencyBlock = dependencyStart && !dependencyEnd;
			bool isFileNameEcho = ( lineStart == compilerOutput ) && Builder_StringStartsWith( lineStart, fileName );

			if ( !inDependencyBlock && !isFileNameEcho ) {
				printf( "%.*s\n", (int) ( lineEnd - lineStart ), lineStart );
			}

			current = ( *lineEnd == '\0' ) ? NULL : lineEnd + 1;
		}

		if ( !dependencyEnd && dependencyStart ) {
			dependencyEnd = strchr( dependencyStart, '\0' );
		}

		if ( compileResult == 0 && dependencyStart && dependencyEnd ) {
			uint64_t dependencyLength = (uint64_t) ( dependencyEnd - dependencyStart );
			char *dependencyString = Builder_ArenaAlloc( dependencyOutput->arena, char, dependencyLength + 1 );
			dependencyString[dependencyLength] = '\0';
			memcpy( dependencyString, dependencyStart, dependencyLength );

			dependencyOutput->dependencyInfos[dependencyOutput->dependencyInfoCount++] = (builderCompileJobDependencyInfo_t) {
				.dependencyString	= dependencyString,
				.dependencyLength	= dependencyLength,
				.compilePacketIndex	= compilePacketIndex
			};
		}
	} else
#endif
	{
		const char* dependencyStart = NULL;
		const char* dependencyEnd = NULL;
		const char *current = compilerOutput;
		while ( current && *current ) {
			const char *lineStart = current;
			const char *lineEnd = strchr( current, '\n' );
			if ( !lineEnd ) {
				lineEnd = strchr( current, '\0' );
			}

			// find the part of the output that is dependencies
			// this shouldn't create false positives, if it does we have more work to do
			if ( !dependencyStart && Builder_StringStartsWith( lineStart, compilePacket->intermediateFile ) ) {
				dependencyStart = lineStart;
			}

			if ( dependencyStart && !dependencyEnd ) {
				uint32_t offset = 1;
				if ( *( lineEnd - offset ) == '\r' ) {
					offset += 1;
				}

				if ( *( lineEnd - offset ) != '\\' ) {
					dependencyEnd = lineEnd + 1;
				}
			} else {
				//any normal compiler output we just print here
				printf( "%.*s\n", (int) ( lineEnd - lineStart ), lineStart );
			}

			current = ( *lineEnd == '\0' ) ? NULL : lineEnd + 1;
		}

		if ( compileResult == 0 && dependencyStart && dependencyEnd ) {
			uint64_t dependencyLength = (uint64_t) ( dependencyEnd - dependencyStart );
			char *dependencyString = Builder_ArenaAlloc( dependencyOutput->arena, char, dependencyLength + 1 );
			dependencyString[dependencyLength] = '\0';
			memcpy( dependencyString, dependencyStart, dependencyLength );

			dependencyOutput->dependencyInfos[dependencyOutput->dependencyInfoCount++] = (builderCompileJobDependencyInfo_t) {
				.dependencyString	= dependencyString,
				.dependencyLength	= dependencyLength,
				.compilePacketIndex	= compilePacketIndex
			};
		}
	}

	Builder_RewindScratch( &scratch );

	return compileResult == 0;
}

static void Builder_RunCompileJobPool( builderCompileJobPool_t *pool ) {
	uint32_t dependencyOutputIndex = Builder_AtomicIncrement( &pool->dependencyOutputIndex ) - 1;
	builderCompileJobDependencyOutput_t *dependencyOutput = &pool->dependencyOutputs[dependencyOutputIndex];

	// at the moment over allocate these to make our life easier
	// TODO: AK: 23/08/2026: Don't waste memory here?
	dependencyOutput->dependencyInfos = Builder_ArenaAlloc( dependencyOutput->arena, builderCompileJobDependencyInfo_t, pool->compilePacketCount );

	while ( 1 ) {
		uint32_t compileCommandIndex = Builder_AtomicIncrement( &pool->nextCompileCommandIndex ) - 1;

		if ( compileCommandIndex >= pool->compilePacketCount ) {
			break;
		}

		if ( !Builder_CompileSourceFile( pool, dependencyOutput, compileCommandIndex ) ) {
			Builder_AtomicIncrement( &pool->numFailed );
		}
	}
}

#if defined( _WIN32 )
static DWORD WINAPI Builder_CompileJobThreadProc( LPVOID param ) {
	Builder_RunCompileJobPool( (builderCompileJobPool_t *) param );
	return 0;
}
#elif defined( __linux__ )
static void *Builder_CompileJobThreadProc( void *param ) {
	Builder_RunCompileJobPool( (builderCompileJobPool_t *) param );
	return NULL;
}
#endif

#if defined( _WIN32 )
static bool Builder_CreateJobThread( LPTHREAD_START_ROUTINE proc, void *args, builderThread_t *outThread ) {
	HANDLE thread = CreateThread( NULL, 0, proc, args, 0, NULL );

	if ( !thread ) {
		Builder_Error( "Failed to create compile worker thread: 0x%X\n", GetLastError() );
		return false;
	}

	*outThread = thread;

	return true;
#elif defined( __linux__ )
static bool Builder_CreateJobThread( void *(proc)(void *), void *args, builderThread_t *outThread ) {
	pthread_t thread;

	int result = pthread_create( &thread, NULL, proc, args );

	if ( result != 0 ) {
		Builder_Error( "Failed to create compile worker thread: %s\n", strerror( result ) );
		return false;
	}

	*outThread = thread;

	return true;
#endif
}

static void Builder_ThreadJoin( builderThread_t thread ) {
#if defined( _WIN32 )
	WaitForSingleObject( thread, INFINITE );
	CloseHandle( thread );
#elif defined( __linux__ )
	if ( pthread_join( thread, NULL ) != 0 ) {
		int err = errno;
		Builder_Error( "Failed to join thread: %s\n", strerror( err ) );
	}
#endif
}

typedef struct objectToDependencyIndicies_t {
	uint64_t	objectHash;
	uint64_t	dependencyCount;
	uint64_t	dependencyCapacity;
	uint64_t	*dependencyIndices;
} objectToDependencyIndicies_t;

typedef struct compileDependency_t {
	const char	*dependency;
	uint64_t	dependencyLength;
	uint64_t	writeTime; // not serialised
} compileDependency_t;

typedef struct compileDependencyArray_t {
	uint64_t			count;
	uint64_t			capacity;
	compileDependency_t	*dependencies;
} compileDependencyArray_t;

typedef struct libraryDependency_t {
    uint64_t writeTime;
    const char *libraryPath;
    const char *libraryName;
} libraryDependency_t;

typedef struct libraryDependencyArray_t {
    uint64_t count;
    uint64_t capacity;
    libraryDependency_t *libraries;
} libraryDependencyArray_t;

static const uint64_t g_builderDependenciesFileVersion = 1;

// full list of dependencies that a config can have
// read from and written to a file in this order
typedef struct builderConfigDependencies_t {
	uint64_t						fileVersion;
	uint64_t						linkCommandHash;
	uint64_t						binaryWriteTime;
    libraryDependencyArray_t        libraryDependencyArray;
	uint64_t 						objectFileCount;
	objectToDependencyIndicies_t	*objectDependencyMap;
	compileDependencyArray_t		compileDependencyArray;
} builderConfigDependencies_t;

typedef struct byteBuffer_t {
	uint64_t	count;
	uint64_t	capacity;
	uint8_t		*data;
} byteBuffer_t;

static void Builder_ByteBufferReallocIfNeeded( arena_t *arena, byteBuffer_t *byteBuffer, const uint64_t incomingByteCount ) {
	uint64_t newCapacity = byteBuffer->capacity;

	while ( byteBuffer->count + incomingByteCount > newCapacity ) {
		BUILDER_ASSERT( ( newCapacity * 2 > newCapacity ) && "Capacity overflow in bytebuffer" );
		newCapacity *= 2;
	}

	if ( newCapacity != byteBuffer->capacity ) {
		byteBuffer->data = Builder_ArenaRealloc( arena, byteBuffer->data, uint8_t, byteBuffer->capacity, newCapacity );
		byteBuffer->capacity = newCapacity;
	}
}

static void Builder_ByteBufferPushU64( arena_t *arena, byteBuffer_t *byteBuffer, const uint64_t u64 ) {
	Builder_ByteBufferReallocIfNeeded( arena, byteBuffer, sizeof( uint64_t ) );

	for ( uint32_t i = 0; i < sizeof( uint64_t ); ++i ) {
		byteBuffer->data[byteBuffer->count++] = ( u64 >> ( i * 8 ) ) & 0xFF;
	}
}

static uint64_t Builder_U64FromByteBuffer( byteBuffer_t *byteBuffer ) {
	uint64_t value = 0;

	if ( byteBuffer->capacity >= byteBuffer->count + sizeof( uint64_t ) ) {
		value = *((uint64_t *) &byteBuffer->data[byteBuffer->count]);
	}

	byteBuffer->count += sizeof( uint64_t );
	return value;
}

static void Builder_ByteBufferPushString( arena_t *arena, byteBuffer_t *byteBuffer, const char *string, const uint64_t stringLength ) {
	Builder_ByteBufferReallocIfNeeded( arena, byteBuffer, sizeof( uint64_t ) + stringLength );

	Builder_ByteBufferPushU64 ( arena, byteBuffer, stringLength );
	for ( uint64_t i = 0; i < stringLength; ++i ) {
		byteBuffer->data[byteBuffer->count++] = (uint8_t) string[i];
	}
}

static const char * Builder_StringFromByteBuffer( arena_t *arena, byteBuffer_t *byteBuffer, uint64_t *outStringLength ) {
	const uint64_t stringLength = Builder_U64FromByteBuffer( byteBuffer );
	char *string = NULL;

	if ( byteBuffer->capacity >= byteBuffer->count + stringLength ) {
		string = Builder_ArenaAlloc( arena, char, stringLength+1 );
		for ( uint64_t i = 0; i < stringLength; ++i ) {
			string[i] = (char) byteBuffer->data[byteBuffer->count + i];
		}

		string[stringLength] = '\0';
	}

	byteBuffer->count += stringLength;
	if ( outStringLength ) {
		*outStringLength = stringLength;
	}
	return string;
}

static byteBuffer_t Builder_ByteBufferFromConfigDependencies( arena_t *arena, const builderConfigDependencies_t *configDependencies ) {
	const uint64_t writeBufferInitialCapacity = 512;
	byteBuffer_t byteBuffer = {
		.count		= 0,
		.capacity	= writeBufferInitialCapacity,
		.data		= Builder_ArenaAlloc( arena, uint8_t, writeBufferInitialCapacity )
	};

	Builder_ByteBufferPushU64( arena, &byteBuffer, configDependencies->fileVersion );

	// for incremental link
	Builder_ByteBufferPushU64( arena, &byteBuffer, configDependencies->linkCommandHash );
	Builder_ByteBufferPushU64( arena, &byteBuffer, configDependencies->binaryWriteTime );

    const libraryDependencyArray_t *libraryDependencyArray = &configDependencies->libraryDependencyArray;
	Builder_ByteBufferPushU64( arena, &byteBuffer, libraryDependencyArray->count );
	for ( uint32_t libIndex = 0; libIndex < libraryDependencyArray->count; ++libIndex ) {
        const libraryDependency_t *libDependency = &libraryDependencyArray->libraries[libIndex];
        Builder_ByteBufferPushU64( arena, &byteBuffer, libDependency->writeTime );
        Builder_ByteBufferPushString( arena, &byteBuffer, libDependency->libraryPath, strlen(libDependency->libraryPath) );
    }

	// for incremental compile
	Builder_ByteBufferPushU64( arena, &byteBuffer, configDependencies->objectFileCount );
	for ( uint32_t objectIndex = 0; objectIndex < configDependencies->objectFileCount; ++objectIndex ) {
		const objectToDependencyIndicies_t *objectDependencies = &configDependencies->objectDependencyMap[objectIndex];
		Builder_ByteBufferPushU64( arena, &byteBuffer, objectDependencies->objectHash );

		Builder_ByteBufferPushU64( arena, &byteBuffer, objectDependencies->dependencyCount );
		for ( uint64_t indiciesIndex = 0; indiciesIndex < objectDependencies->dependencyCount; ++indiciesIndex ) {
			Builder_ByteBufferPushU64( arena, &byteBuffer, objectDependencies->dependencyIndices[indiciesIndex] );
		}
	}

	const compileDependencyArray_t *compileDependencyArray = &configDependencies->compileDependencyArray;
	Builder_ByteBufferPushU64( arena, &byteBuffer, compileDependencyArray->count );
	for ( uint64_t dependencyIndex = 0; dependencyIndex < compileDependencyArray->count; ++dependencyIndex ) {
		const compileDependency_t *dependency = &compileDependencyArray->dependencies[dependencyIndex];
		Builder_ByteBufferPushString( arena, &byteBuffer, dependency->dependency, dependency->dependencyLength );
	}

	return byteBuffer;
}

static builderConfigDependencies_t Builder_ConfigDependenciesFromByteBuffer( arena_t *arena, byteBuffer_t *byteBuffer ) {
	builderConfigDependencies_t configDependencies = { 0 };

	configDependencies.fileVersion = Builder_U64FromByteBuffer( byteBuffer );
	if ( configDependencies.fileVersion == g_builderDependenciesFileVersion ) {
		// for incremental link
		configDependencies.linkCommandHash = Builder_U64FromByteBuffer( byteBuffer );
		configDependencies.binaryWriteTime = Builder_U64FromByteBuffer( byteBuffer );

        libraryDependencyArray_t *libraryDependencyArray    = &configDependencies.libraryDependencyArray;
        libraryDependencyArray->count		= Builder_U64FromByteBuffer( byteBuffer );
		libraryDependencyArray->capacity		= libraryDependencyArray->count;
        libraryDependencyArray->libraries	= Builder_ArenaAlloc( arena, libraryDependency_t, libraryDependencyArray->count );
        for ( uint32_t libIndex = 0; libIndex < libraryDependencyArray->count; ++libIndex ) {
            libraryDependency_t *libDependency = &libraryDependencyArray->libraries[libIndex];
            libDependency->writeTime = Builder_U64FromByteBuffer( byteBuffer );
			uint64_t pathLength;
            libDependency->libraryPath = Builder_StringFromByteBuffer( arena, byteBuffer, &pathLength );
            libDependency->libraryName = Builder_FilenameFromPath( libDependency->libraryPath, pathLength );
        }

		// for incremental compile
		configDependencies.objectFileCount		= Builder_U64FromByteBuffer( byteBuffer );
		configDependencies.objectDependencyMap	= Builder_ArenaAlloc( arena, objectToDependencyIndicies_t, configDependencies.objectFileCount );
		for ( uint64_t objectIndex = 0; objectIndex < configDependencies.objectFileCount; ++objectIndex ) {
			objectToDependencyIndicies_t *objectDependencies = &configDependencies.objectDependencyMap[objectIndex];
			objectDependencies->objectHash			= Builder_U64FromByteBuffer( byteBuffer );

			objectDependencies->dependencyCount		= Builder_U64FromByteBuffer( byteBuffer );
			objectDependencies->dependencyCapacity	= objectDependencies->dependencyCount; // ceil to pow2?
			objectDependencies->dependencyIndices	= Builder_ArenaAlloc( arena, uint64_t, objectDependencies->dependencyCapacity );
			for ( uint64_t indiciesIndex = 0; indiciesIndex < objectDependencies->dependencyCount; ++indiciesIndex ) {
				objectDependencies->dependencyIndices[indiciesIndex] = Builder_U64FromByteBuffer( byteBuffer );
			}
		}

		compileDependencyArray_t *compileDependencyArray = &configDependencies.compileDependencyArray;
		compileDependencyArray->count 			= Builder_U64FromByteBuffer( byteBuffer );
		compileDependencyArray->capacity		= compileDependencyArray->count;
		compileDependencyArray->dependencies	= Builder_ArenaAlloc( arena, compileDependency_t, compileDependencyArray->capacity );
		for ( uint64_t dependencyIndex = 0; dependencyIndex < compileDependencyArray->count; ++dependencyIndex ) {
			compileDependency_t *dependency = &compileDependencyArray->dependencies[dependencyIndex];
			dependency->dependency = Builder_StringFromByteBuffer( arena, byteBuffer, &dependency->dependencyLength );
			dependency->writeTime = 0;
		}

		if ( byteBuffer->count != byteBuffer->capacity ) {
			Builder_Warning( "Config dependency file was an unexpected size. Reached %llu of %llu bytes.\n", byteBuffer->count, byteBuffer->capacity );
			configDependencies = (builderConfigDependencies_t) { 0 };
		}
	}

	return configDependencies;
}

static uint64_t Builder_DependencyArrayAddUnique( arena_t *dependencyArena, compileDependencyArray_t *compileDependencyArray, const char *dependency ) {
	for ( uint32_t dependencyIndex = 0; dependencyIndex < compileDependencyArray->count; ++dependencyIndex ) {
		const compileDependency_t *compileDependency = &compileDependencyArray->dependencies[dependencyIndex];

		if ( Builder_StringEquals( dependency, compileDependency->dependency ) ) {
			return dependencyIndex;
		}
	}

	if ( compileDependencyArray->capacity == compileDependencyArray->count ) {
		compileDependencyArray->dependencies = Builder_ArenaRealloc( dependencyArena, compileDependencyArray->dependencies, compileDependency_t, compileDependencyArray->capacity, compileDependencyArray->capacity * 2 );
		compileDependencyArray->capacity *= 2;
	}

	compileDependencyArray->dependencies[compileDependencyArray->count++] = (compileDependency_t) {
		.dependency			= Builder_FormatString( dependencyArena, "%s", dependency ),
		.dependencyLength	= Builder_Strnlen( dependency, 512 )
	};

	return compileDependencyArray->count - 1;
}

static bool Builder_DoesMapContainDependency( const compileDependencyArray_t *compileDependencyArray, objectToDependencyIndicies_t *dependencyMap, const char *dependency ) {
	for ( uint64_t mapIndex = 0; mapIndex < dependencyMap->dependencyCount; ++mapIndex ) {
		const uint64_t dependencyIndex = dependencyMap->dependencyIndices[mapIndex];

		const compileDependency_t* otherDependency = &compileDependencyArray->dependencies[dependencyIndex];

		if ( Builder_StringEquals( dependency, otherDependency->dependency ) ) {
			return true;
		}
	}

	return false;
}

static void Builder_ParseDependencyInfo( arena_t *dependencyArena, compileDependencyArray_t *compileDependencyArray, objectToDependencyIndicies_t *dependencyMap, char *compilerOutput, bool useMSVCSyntax ) {
	scratch_t scratch = Builder_GetScratch( dependencyArena );

	if ( useMSVCSyntax ) {
		// the captured block starts at the first include note
		char *current = compilerOutput;

		const char *includeDependencyPrefix = "Note: including file: ";
		const uint64_t includeDependencyPrefixLength = strlen( includeDependencyPrefix );

		while ( *current ) {
			char *dependencyStart = current;
			dependencyStart += includeDependencyPrefixLength;

			while ( *dependencyStart == ' ' ) {
				dependencyStart += 1;
			}

			// get end of the filename
			char *dependencyEnd = strchr( dependencyStart, '\n' );
			if ( !dependencyEnd ) {
				dependencyEnd = strchr( dependencyStart, '\0' );
			}
			BUILDER_ASSERT( dependencyEnd );

			if ( *( dependencyEnd - 1 ) == '\r' ) {
				dependencyEnd -= 1;
			}

			// get the substring we actually need
			uint64_t dependencyFilenameLength = ( (uint64_t) dependencyEnd ) - ( (uint64_t) dependencyStart );
			char *dependencyFilename = Builder_FormatString( scratch.arena, "%.*s", dependencyFilenameLength, dependencyStart );
			for ( uint64_t i = 0; i < dependencyFilenameLength; ++i ) {
				if ( dependencyFilename[i] == '\\' && dependencyFilename[i + 1] == ' ' ) {
					memmove( dependencyFilename + i, dependencyFilename + i + 1, dependencyFilenameLength - i ); // - 1 (count) + 1 '\0'
					dependencyFilenameLength--;
				}
			}

			if ( dependencyMap->dependencyCapacity == dependencyMap->dependencyCount ) {
				dependencyMap->dependencyIndices = Builder_ArenaRealloc( dependencyArena, dependencyMap->dependencyIndices, uint64_t, dependencyMap->dependencyCapacity, dependencyMap->dependencyCapacity * 2 );
				dependencyMap->dependencyCapacity *= 2;
			}

			dependencyMap->dependencyIndices[dependencyMap->dependencyCount++] = Builder_DependencyArrayAddUnique( dependencyArena, compileDependencyArray, dependencyFilename );

			if ( *dependencyEnd == '\0' ) {
				break;
			}

			// cl ends lines with \r\n but clang-cl only uses \n
			current = dependencyEnd + ( ( *dependencyEnd == '\r' ) ? 2 : 1 );

			if ( !Builder_StringStartsWith( current, includeDependencyPrefix ) ) {
				break;
			}
		}
	} else {
		// .d files start with the name of the binary followed by a colon
		// so skip past that first
		char *current = strchr( compilerOutput, ':' );
		BUILDER_ASSERT( current );
		current += 1;	// skip past the colon
		current += 1;	// skip past the following whitespace

		bool firstDependency = true; // first is the source file we already checked

		while ( *current ) {
			// get start of the filename
			char *dependencyStart = current;

			while ( *dependencyStart == ' ' ) {
				dependencyStart += 1;
			}

			// get end of the filename - filenames are separated by either new line or space
			char *dependencyEnd = strchr( dependencyStart, ' ' );
			if ( !dependencyEnd ) {
				dependencyEnd = strchr( dependencyStart, '\n' );
			}
			BUILDER_ASSERT( dependencyEnd );

			// paths can have spaces in them, but they are preceded by a single backslash (\)
			// so if we find a space but it has a single backslash just before it then keep searching for a space or the end of the line
			while ( dependencyEnd && ( *( dependencyEnd - 1 ) == '\\' ) ) {
				dependencyEnd = strchr( dependencyEnd + 1, ' ' );
				if ( !dependencyEnd ) {
					dependencyEnd = strchr( dependencyStart, '\n' );
				}
			}

			if ( !dependencyEnd ) {
				break;
			}

			if ( *( dependencyEnd - 1 ) == '\r' ) {
				dependencyEnd -= 1;
			}

			if ( !firstDependency ) {
				// get the substring we actually need
				uint64_t dependencyFilenameLength = ( (uint64_t) dependencyEnd ) - ( (uint64_t) dependencyStart );
				char *dependencyFilename = Builder_FormatString( scratch.arena, "%.*s", dependencyFilenameLength, dependencyStart );
				for ( uint64_t i = 0; i < dependencyFilenameLength; ++i ) {
					if ( dependencyFilename[i] == '\\' && dependencyFilename[i + 1] == ' ' ) {
						memmove( dependencyFilename + i, dependencyFilename + i + 1, dependencyFilenameLength - i ); // - 1 (count) + 1 '\0'
						dependencyFilenameLength--;
					}
				}

				if ( !Builder_DoesMapContainDependency( compileDependencyArray, dependencyMap, dependencyFilename ) ) {
					if ( dependencyMap->dependencyCapacity == dependencyMap->dependencyCount ) {
						dependencyMap->dependencyIndices = Builder_ArenaRealloc( dependencyArena, dependencyMap->dependencyIndices, uint64_t, dependencyMap->dependencyCapacity, dependencyMap->dependencyCapacity * 2 );
						dependencyMap->dependencyCapacity *= 2;
					}

					dependencyMap->dependencyIndices[dependencyMap->dependencyCount++] = Builder_DependencyArrayAddUnique( dependencyArena, compileDependencyArray, dependencyFilename );
				}
			} else {
				firstDependency = false;
			}

			current = dependencyEnd + 1;

			while ( *current == '\\' ) {
				current += 1;
			}

			if ( *current == '\r' ) {
				current += 1;
			}

			if ( *current == '\n' ) {
				current += 1;
			}
		}
	}

	Builder_RewindScratch( &scratch );
}


typedef struct builderPostBuildConfigData_t {
	builderCompilePacket_t				*compilePackets;
	uint64_t							packetCount;
	uint64_t							compiledPacketCount;
	builderCompileJobDependencyInfo_t	*dependencyInfos;
	uint64_t							dependencyInfoCount;
	const char							*dependencyCacheFileName;
	bool								didFullLink;
	uint64_t							nextLibraryWriteTimeToCheckIndex;
	StringList							linkLibraryOutput;
	builderConfigDependencies_t			configDependencies;
} builderPostBuildConfigData_t;

// full path to the running EXE, outExePath must be BUILDER_MAX_PATH bytes
static void Builder_GetExePath( char **argv, char *outExePath ) {
#if defined( _WIN32 )
	if ( GetModuleFileName( NULL, outExePath, BUILDER_MAX_PATH ) == 0 ) {
		Builder_Error( "Failed to get the path of \"%s\".  GetLastError: 0x%X\n", argv[0], GetLastError() );
		exit( 1 );
	}
#elif defined( __linux__ )
	if ( readlink( "/proc/self/exe", outExePath, BUILDER_MAX_PATH - 1 ) == -1 ) {
		int err = errno;
		Builder_Error( "Failed to get the path of \"%s\".  errno: %d (\"%s\")\n", argv[0], err, strerror( err ) );
		exit( 1 );
	}
#else
#error Unrecognised platform.
#endif
}

typedef struct builderLinkContext_t {
	 BuildConfig					*config;
	 const char						*compilerPath;
	 const char						*binaryPath;
	 const char						*clangSanitizerResourceDir;
#if defined ( _WIN32 )
	 builderMSVCInstall_t			*msvcInstall;
	 builderWindowsSDKInstall_t		*windowsSDKInstall;
	 bool							useMSVCLink;
	 bool							compilerIsMSVC;
	 bool							debugDefineSet;
#endif
	bool							compilerIsGCC;
} builderLinkContext_t;

static const char * Builder_CreateLinkCommand( arena_t *commandArena, builderLinkContext_t *linkContext, builderPostBuildConfigData_t *postBuildData ) {
	scratch_t scratch = Builder_GetScratch( commandArena );

	BuildConfig *config = linkContext->config;

	stringBuilder_t linkerArgs = { 0 };
#if defined( _WIN32 )
	if ( linkContext->useMSVCLink ) {
		if ( config->binaryType == BINARY_TYPE_STATIC_LIBRARY ) {
			StringBuilder_Appendf( scratch.arena, &linkerArgs, "\"%s\" ", linkContext->msvcInstall->libEXEPath );
		} else {
			StringBuilder_Appendf( scratch.arena, &linkerArgs, "\"%s\" ", linkContext->msvcInstall->linkEXEPath );
		}

		if ( config->binaryType == BINARY_TYPE_DYNAMIC_LIBRARY ) {
			StringBuilder_Appendf( scratch.arena, &linkerArgs, "/DLL " );
		}

		if ( !config->removeSymbols && config->binaryType != BINARY_TYPE_STATIC_LIBRARY ) {
			StringBuilder_Appendf( scratch.arena, &linkerArgs, "/DEBUG " );
		}

		StringBuilder_Appendf( scratch.arena, &linkerArgs, "/OUT:" );
		StringBuilder_Appendf( scratch.arena, &linkerArgs, "%s ", linkContext->binaryPath );

		StringBuilder_Appendf( scratch.arena, &linkerArgs, "/LIBPATH:\"%s\" ", linkContext->msvcInstall->libPath );
		StringBuilder_Appendf( scratch.arena, &linkerArgs, "/LIBPATH:\"%s\" ", linkContext->windowsSDKInstall->umLibPath );
		StringBuilder_Appendf( scratch.arena, &linkerArgs, "/LIBPATH:\"%s\" ", linkContext->windowsSDKInstall->ucrtLibPath );

		for ( builderStringChunk_t *chunk = config->additionalLibPaths.head; chunk; chunk = chunk->next ) {
			for ( uint32_t libPathIndex = 0; libPathIndex < chunk->count; libPathIndex++ ) {
				StringBuilder_Appendf( scratch.arena, &linkerArgs, "/LIBPATH:\"%s\" ", chunk->items[libPathIndex] );
			}
		}

		for ( builderStringChunk_t *chunk = config->additionalLibs.head; chunk; chunk = chunk->next ) {
			for ( uint32_t libIndex = 0; libIndex < chunk->count; libIndex++ ) {
				const char *additionalLib = chunk->items[libIndex];

				// callers sometimes already include the ".lib" extension themselves, don't double it up
				if ( Builder_PathEndsWith( additionalLib, ".lib" ) ) {
					StringBuilder_Appendf( scratch.arena, &linkerArgs, "%s ", additionalLib );
				} else {
					StringBuilder_Appendf( scratch.arena, &linkerArgs, "%s.lib ", additionalLib );
				}
			}
		}

		if ( config->binaryType != BINARY_TYPE_STATIC_LIBRARY ) {
			// clang doesnt embed /DEFAULTLIB directives the way cl.exe does
			// so link.exe has no idea which CRT/SDK libs to pull in unless we name them ourselves
			if ( config->useDynamicRuntimeOnWindows ) {
				if ( linkContext->debugDefineSet ) {
					StringBuilder_Appendf( scratch.arena, &linkerArgs, "msvcrtd.lib msvcprtd.lib vcruntimed.lib ucrtd.lib kernel32.lib " );
				} else {
					StringBuilder_Appendf( scratch.arena, &linkerArgs, "msvcrt.lib msvcprt.lib vcruntime.lib ucrt.lib kernel32.lib " );
				}
			} else {
				if ( linkContext->debugDefineSet ) {
					StringBuilder_Appendf( scratch.arena, &linkerArgs, "libcmtd.lib libcpmtd.lib libvcruntimed.lib libucrtd.lib kernel32.lib " );
				} else {
					StringBuilder_Appendf( scratch.arena, &linkerArgs, "libcmt.lib libcpmt.lib libvcruntime.lib libucrt.lib kernel32.lib " );
				}
			}
		}

		if ( !linkContext->compilerIsMSVC && config->sanitizers != 0 ) {
			StringBuilder_Appendf( scratch.arena, &linkerArgs, "/LIBPATH:\"%s\\lib\\windows\" ", linkContext->clangSanitizerResourceDir );

			for ( uint32_t sanitizerBitIndex = 0; sanitizerBitIndex < config->sanitizers; sanitizerBitIndex++ ) {
				SanitizerFlagBits sanitizerFlagBit = (SanitizerFlagBits) ( 1 << sanitizerBitIndex );

				if ( ( config->sanitizers & sanitizerFlagBit ) == 0 ) {
					continue;
				}

				// msvc ships sanitizer libs with the same names as clang's, and msvc's lib folder is searched first
				// so pass clang's by full path otherwise we link msvc's, which clang's runtime isnt compatible with
				switch ( sanitizerFlagBit ) {
					case SANITIZER_ADDRESS:
						StringBuilder_Appendf( scratch.arena, &linkerArgs, "\"%s\\lib\\windows\\clang_rt.asan_dynamic-x86_64.lib\" /WHOLEARCHIVE:\"%s\\lib\\windows\\clang_rt.asan_static_runtime_thunk-x86_64.lib\" /INFERASANLIBS:NO ", linkContext->clangSanitizerResourceDir, linkContext->clangSanitizerResourceDir );
						break;

					case SANITIZER_UNDEFINED_BEHAVIOR:
						StringBuilder_Appendf( scratch.arena, &linkerArgs, "\"%s\\lib\\windows\\clang_rt.ubsan_standalone-x86_64.lib\" dbghelp.lib shell32.lib ", linkContext->clangSanitizerResourceDir );
						break;

					// memory/leak/thread aren't supported by clang on Windows at all - it already rejects them at compile time
					default:
						break;
				}
			}
		}

		StringBuilder_Appendf( scratch.arena, &linkerArgs, "/VERBOSE:LIB /NOLOGO " );
	} else {
#else
	{
#endif
		if ( config->binaryType == BINARY_TYPE_STATIC_LIBRARY ) {
			const char *linkerProgramName = linkContext->compilerIsGCC ? "ar" : "llvm-ar";

			// remove the filename part of the compiler path, leaving just the path (if it exists)
			// use that path to then get the path to the linker executable since its in the same folder
			{
				const char *lastSlash = NULL;
				if ( !lastSlash ) lastSlash = strrchr( linkContext->compilerPath, '/' );
				if ( !lastSlash ) lastSlash = strrchr( linkContext->compilerPath, '\\' );

				if ( lastSlash ) {
					uint64_t compilerBinaryPathLength = (uint64_t) lastSlash - (uint64_t) linkContext->compilerPath;

					StringBuilder_Appendf( scratch.arena, &linkerArgs, "\"%.*s%c%s\" rcs ", (int) compilerBinaryPathLength, linkContext->compilerPath, BUILDER_PATH_SEPARATOR, linkerProgramName );
				} else {
					StringBuilder_Appendf( scratch.arena, &linkerArgs, "%s rcs ", linkerProgramName );
				}
			}

			StringBuilder_Appendf( scratch.arena, &linkerArgs, "%s ", linkContext->binaryPath );
		} else {
			StringBuilder_Appendf( scratch.arena, &linkerArgs, "\"%s\" ", linkContext->compilerPath );

			if ( config->binaryType == BINARY_TYPE_DYNAMIC_LIBRARY ) {
				StringBuilder_Appendf( scratch.arena, &linkerArgs, "-shared " );

#if defined( _WIN32 )
				// mingw doesnt emit an import library alongside the DLL unless asked
				// link.exe does this automatically for /DLL
				if ( config->binaryFolder ) {
					StringBuilder_Appendf( scratch.arena, &linkerArgs, "-Wl,--out-implib,%s%c%s.lib ", config->binaryFolder, BUILDER_PATH_SEPARATOR, config->binaryName );
				} else {
					StringBuilder_Appendf( scratch.arena, &linkerArgs, "-Wl,--out-implib,%s.lib ", config->binaryName );
				}
#endif
			}

			StringBuilder_Appendf( scratch.arena, &linkerArgs, "-o " );
			StringBuilder_Appendf( scratch.arena, &linkerArgs, "%s ", linkContext->binaryPath );

			for ( builderStringChunk_t *chunk = config->additionalLibPaths.head; chunk; chunk = chunk->next ) {
				for ( uint32_t libPathIndex = 0; libPathIndex < chunk->count; libPathIndex++ ) {
					StringBuilder_Appendf( scratch.arena, &linkerArgs, "-L%s ", chunk->items[libPathIndex] );
				}
			}

            for ( builderStringChunk_t *chunk = config->additionalLibs.head; chunk; chunk = chunk->next ) {
                for ( uint32_t libIndex = 0; libIndex < chunk->count; libIndex++ ) {
                    const char *additionalLib = chunk->items[libIndex];

					// an explicit filename or path (e.g. "./foo.so", "foo.lib") is passed straight through
					// "-l" is only correct for bare library names since it adds the "lib" prefix and an extension itself
					bool isExplicitLibFile = Builder_StringContains( additionalLib, "/" ) ||
												Builder_StringContains( additionalLib, "\\" ) ||
												Builder_PathEndsWith( additionalLib, ".lib" ) ||
												Builder_PathEndsWith(additionalLib, ".so" ) ||
												Builder_PathEndsWith(additionalLib, ".a" ) ||
												Builder_PathEndsWith(additionalLib, ".dylib" );
					// libs are named by their real filename, so "libm" means libm.so/libm.a
					// "-l" adds the "lib" prefix back on itself, so strip ours off
					const char *libPrefix = "lib";

					if ( isExplicitLibFile ) {
	#if defined( _WIN32 )
						StringBuilder_Appendf( scratch.arena, &linkerArgs, "%s ", additionalLib );
	#elif defined( __linux__ )
						StringBuilder_Appendf( scratch.arena, &linkerArgs, "-l:%s ", additionalLib );
	#endif
					} else if ( Builder_StringStartsWith( additionalLib, libPrefix ) ) {
						StringBuilder_Appendf( scratch.arena, &linkerArgs, "-l%s ", additionalLib + strlen( libPrefix ) );
					} else {
	#if defined( _WIN32 )
						StringBuilder_Appendf( scratch.arena, &linkerArgs, "-l%s ", additionalLib );
	#elif defined( __linux__ )
						StringBuilder_Appendf( scratch.arena, &linkerArgs, "-l:%s%s ", additionalLib, Builder_GetFileExtensionFromBinaryType( BINARY_TYPE_DYNAMIC_LIBRARY ) );
	#endif
					}
				}
			}

#ifdef __linux__
			// on linux we need to guarantee that the symbols for any library that this executable links to can always be loaded regardless of where we are running the executable from
			if ( config->binaryType == BINARY_TYPE_EXE ) {
				StringBuilder_Appendf( scratch.arena, &linkerArgs, "-Wl,-rpath,\\$ORIGIN " );
			}
#endif

			// GCC and clang both link the sanitizer runtime themselves when driving the link, unlike link.exe
			Builder_AddSanitizerArgs( &scratch, &linkerArgs, config->sanitizers, "-fsanitize" );

            StringBuilder_Appendf( scratch.arena, &linkerArgs, "-Wl,--trace " );
		}
	}

	for ( builderStringChunk_t *chunk = config->additionalLinkerArguments.head; chunk; chunk = chunk->next ) {
		for ( uint32_t argumentIndex = 0; argumentIndex < chunk->count; argumentIndex++ ) {
			StringBuilder_Appendf( scratch.arena, &linkerArgs, "%s ", chunk->items[argumentIndex] );
		}
	}

	const char *linkCommand = StringBuilder_ToString( commandArena, &linkerArgs, NULL );
	Builder_RewindScratch( &scratch );
	return linkCommand;
}

// set CWD to where this EXE lives
static void Builder_SetCWD( BuilderOptions *options, char **argv ) {
	char appPath[BUILDER_MAX_PATH] = { 0 };
	Builder_GetExePath( argv, appPath );

	// trim the full path to the exe down to its containing directory
	char *lastSlash = strrchr( appPath, BUILDER_PATH_SEPARATOR );
	if ( lastSlash ) {
		*lastSlash = 0;
	}

#if defined( _WIN32 )
	if ( !SetCurrentDirectory( appPath ) ) {
		Builder_Error( "Failed to set the CWD to \"%s\".  GetLastError: 0x%X\n", appPath, GetLastError() );
		exit( 1 );
	}
#elif defined( __linux__ )
	if ( chdir( appPath ) == -1 ) {
		int err = errno;
		Builder_Error( "Failed to set the CWD to \"%s\".  errno: %d (\"%s\")\n", appPath, err, strerror( err ) );
		exit( 1 );
	}
#else
#error Unrecognised platform.
#endif

	Builder_LogVerbose( options, "Set CWD to \"%s\"\n", appPath );
}

static void Builder_SetCmdArgs( BuilderOptions *options, int argc, char **argv ) {
	for ( int argIndex = 0; argIndex < argc; argIndex++ ) {
		if ( Builder_StringEquals( argv[argIndex], ARG_HELP_SHORT ) || Builder_StringEquals( argv[argIndex], ARG_HELP_LONG ) ) {
			ShowUsage( 0 );
			exit( 0 );
		}

		if ( Builder_StringEquals( argv[argIndex], ARG_VERBOSE_SHORT ) || Builder_StringEquals( argv[argIndex], ARG_VERBOSE_LONG ) ) {
			options->verboseLogging = true;
		}
	}
}

typedef struct builderBuildContext_t {
	scratch_t								*buildScratch;
	const char								*compilerPath;			// TODO: DM: 21/09/2026: remove this
	const char								*compilerVersionString;	// TODO: DM: 21/09/2026: remove this
	bool									compilerIsMSVC;
	bool									compilerIsClangCL;
	bool									compilerIsGCC;
	char									*clangSanitizerResourceDir;
	const char								*intermediateFolder;
	uint32_t								numCPUCores;
	arena_t									*threadResultArenas;
	arena_t									*postBuildArena;
	arena_t									*buildSummaryArena;
	builderPostBuildConfigData_t			*postBuildConfigDependencyData;

	// accumulated over every config built
	uint32_t								builtConfigs;
	buildSummaryList_t						buildSummary;
	double									totalCompileTimeMS;
	double									totalLinkTimeMS;
} builderBuildContext_t;

typedef enum builderBuildResult_t {
	BUILD_RESULT_SUCCESS	= 0,
	BUILD_RESULT_FAILED,
	BUILD_RESULT_SKIPPED,
} builderBuildResult_t;

// compiles and links one config, running its OnPreBuild/OnPostBuild either side
static builderBuildResult_t Builder_BuildConfig( builderBuildContext_t *context, BuilderOptions *options, BuildConfig *config ) {
	// nothing this config allocates is wanted by the next one, the toolchain paths it reads were put on buildScratch before the loop
	// so they sit below this and the rewind can't reach them
	arenaRewindSpot_t configStart = Builder_ArenaTell( context->buildScratch->arena );

	double compileTimeMS = 0.0;
	double linkTimeMS = 0.0;
	uint32_t needsCompilePacketCount = 0;

	if ( config->OnPreBuild ) {
		Builder_LogVerbose( options, "Found a OnPreBuild() func ptr for BuildConfig: \"%s\".  Running...\n", config->name ? config->name : "" );

		config->OnPreBuild( config );
	}

	// build the config
	bool shouldLink;
	{
		printf( "Building config \"%s\":\n", config->name );

		// glob step - flattened into one array because the compile job pool indexes into it by job number
		StringList globList = Builder_GlobFiles( context->buildScratch->arena, &config->sourceFiles, options );

		uint32_t compilePacketCount = globList.count;

		builderCompileContext_t compileContext = {
			.config				= config,
			.compilerPath		= context->compilerPath,
			.useMSVCSyntax		= context->compilerIsMSVC || context->compilerIsClangCL,
		};

		builderPostBuildConfigData_t *postBuildData = &context->postBuildConfigDependencyData[context->builtConfigs++];
		*postBuildData = (builderPostBuildConfigData_t){ 0 };
		if ( compilePacketCount > 0 ) {
			postBuildData->packetCount = compilePacketCount;
			postBuildData->compilePackets = Builder_ArenaAlloc( context->postBuildArena, builderCompilePacket_t, compilePacketCount );

			scratch_t scratch = Builder_GetScratch( context->buildScratch->arena );

			const char *baseCompileCommand = Builder_CreateCompilationCommand( scratch.arena, &compileContext );
			if ( !baseCompileCommand ) {
				Builder_Error( "Failed to create compilation command for config %s!\n", config->name );
				Builder_RewindArena( context->buildScratch->arena, &configStart );
				context->builtConfigs--;
				return BUILD_RESULT_FAILED;
			}

#if defined( _WIN32 )
			// msvc only supports the address sanitizer
			// the other sanitizers it supports arent exposed by builder because they're specific to msvc
			// cl.exe only warns about the others and carries on, so the build would silently go ahead without them
			if ( context->compilerIsMSVC && ( config->sanitizers & ~SANITIZER_ADDRESS ) != 0 ) {
				Builder_Error( "Config \"%s\" uses sanitizers that MSVC doesn't support.  MSVC only supports SANITIZER_ADDRESS.\n", config->name );
				Builder_RewindArena( context->buildScratch->arena, &configStart );
				context->builtConfigs--;
				return BUILD_RESULT_FAILED;
			}
#endif

			// hash just the config compile options with the compiler version
			uint64_t configCompileCommandHash = Builder_HashString( Builder_FormatString( scratch.arena, "%s%s", baseCompileCommand, context->compilerVersionString ) );

			uint32_t written = 0;
			builderCompilePacket_t *compilePackets = postBuildData->compilePackets;
			for ( builderStringChunk_t *chunk = globList.head; chunk; chunk = chunk->next ) {
				for ( uint32_t globbedFileIndex = 0; globbedFileIndex < chunk->count; globbedFileIndex++ ) {
					const char *sourceFile = chunk->items[globbedFileIndex];
					stringBuilder_t fullCompileCommand = { 0 };
					StringBuilder_Appendf( scratch.arena, &fullCompileCommand, "%s", baseCompileCommand );

					uint64_t compileCommandHash = Builder_AppendHash( configCompileCommandHash, sourceFile );
					compilePackets[written].intermediateFile = Builder_GetIntermediateFilePath( context->buildScratch->arena, context->intermediateFolder, compileCommandHash, sourceFile );
					compilePackets[written].compileCommandHash = compileCommandHash;

					StringBuilder_Appendf( scratch.arena, &fullCompileCommand, "%s ", sourceFile );
					if ( compileContext.useMSVCSyntax ) {
						StringBuilder_Appendf( scratch.arena, &fullCompileCommand, "/Fo" );
					} else {
						StringBuilder_Appendf( scratch.arena, &fullCompileCommand, "-o " );
					}

					StringBuilder_Appendf( scratch.arena, &fullCompileCommand, "%s ", compilePackets[written].intermediateFile );

					compilePackets[written].compileCommand = StringBuilder_ToString( context->buildScratch->arena, &fullCompileCommand, NULL );
					compilePackets[written].sourceFile = sourceFile;

					++written;
				}
			}

			postBuildData->dependencyCacheFileName = Builder_FormatString( context->postBuildArena, "%s%c%s_%" PRIu64 ".builder-dependencies", context->intermediateFolder, BUILDER_PATH_SEPARATOR, config->name, configCompileCommandHash );
			needsCompilePacketCount = compilePacketCount;
			if ( !options->forceRebuild ) {
				// when we read from a byte buffer we use the count to track how much of it we have read
				// and the capacity is how much there is to read
				byteBuffer_t byteBuffer = { 0 };
				byteBuffer.data = (uint8_t *) Builder_ReadEntireFile( scratch.arena, postBuildData->dependencyCacheFileName, &byteBuffer.capacity );

				// no file found means we recompile everything
				if ( byteBuffer.data ) {
					postBuildData->configDependencies = Builder_ConfigDependenciesFromByteBuffer( context->postBuildArena, &byteBuffer );

					builderConfigDependencies_t *configDependencies = &postBuildData->configDependencies;
					uint32_t packetIndex = 0;
					if ( configDependencies->fileVersion != g_builderDependenciesFileVersion ) {
						packetIndex = needsCompilePacketCount;
					}

					// iterate through, and swap with end if a file doesn't need to recompile
					while ( packetIndex < needsCompilePacketCount ) {
						const char *sourceFile 	= compilePackets[packetIndex].sourceFile;
						const char *objectFile 	= compilePackets[packetIndex].intermediateFile;
						uint64_t objectHash 	= compilePackets[packetIndex].compileCommandHash;

						uint64_t sourceWriteTime, objectWriteTime;
						if ( Builder_GetFileLastWriteTime( objectFile, &objectWriteTime) ) {
							if ( !Builder_GetFileLastWriteTime( sourceFile, &sourceWriteTime ) ) {
								Builder_Warning( "Couldn't stat source file '%s'.\n", sourceFile ); // so we recompile it
								packetIndex++;
								continue;
							}

							// object is newer - check dependency file
							if ( objectWriteTime > sourceWriteTime ) {
								objectToDependencyIndicies_t *objectDependencies = NULL;
								for ( uint64_t objectIndex = 0; objectIndex < configDependencies->objectFileCount; ++objectIndex ) {
									if ( configDependencies->objectDependencyMap[objectIndex].objectHash == objectHash ) {
										objectDependencies = &configDependencies->objectDependencyMap[objectIndex];
										break;
									}
								}

								// we found its dependencies now check them
								if ( objectDependencies ) {
									bool needsRecompile = false;
									compileDependencyArray_t *compileDependencyArray = &configDependencies->compileDependencyArray;
									for ( uint64_t indiciesIndex = 0; indiciesIndex < objectDependencies->dependencyCount; ++indiciesIndex ) {
										const uint64_t dependencyIndex = objectDependencies->dependencyIndices[indiciesIndex];

										if ( dependencyIndex >= compileDependencyArray->count ) {
											Builder_Warning( "Tried to fetch dependency not in array with index %llu\n", dependencyIndex );
											needsRecompile = true;
											break;
										}

										compileDependency_t *compileDependency = &compileDependencyArray->dependencies[dependencyIndex];
										if ( compileDependency->writeTime == 0 ) {
											if ( !Builder_GetFileLastWriteTime( compileDependency->dependency, &compileDependency->writeTime ) ) {
												Builder_Warning( "Failed to get write time for dependency: %s\n", compileDependency->dependency );
												compileDependency->writeTime = UINT64_MAX;
											}
										}

										if ( compileDependency->writeTime > objectWriteTime ) {
											needsRecompile = true;
											break;
										}
									}

									if ( !needsRecompile ) {
										const uint32_t uncheckedPacketOffset = --needsCompilePacketCount;
										builderCompilePacket_t toSwap = compilePackets[packetIndex];
										compilePackets[packetIndex] = compilePackets[uncheckedPacketOffset];
										compilePackets[uncheckedPacketOffset] = toSwap;

										continue;
									}
								}
							}
						}

						packetIndex++;
					}
				}
			}

			// show the shared args once instead of per file
			// done here because baseCompileCommand dies with this scratch
			if ( options->consolidateCompilerArgs && needsCompilePacketCount > 0 ) {
				printf( "Building with the following command line options for each source file:\n%s\n", baseCompileCommand );
			}

			Builder_RewindScratch( &scratch );
		}

		// compilation step
		{
			const double compileTimeStart = Builder_TimeMS();

			if ( needsCompilePacketCount > 0 ) {
				scratch_t scratch = Builder_GetScratch( context->buildScratch->arena );
				postBuildData->compiledPacketCount = needsCompilePacketCount;

				// TODO: DM: 09/08/2026: is it OK to create and destroy a bunch of threads for each config?
				// only spin up additional threads once theres more than one file
				// limit the number of threads we spin up to no higher than the number of CPU cores we have
				uint32_t numWorkers = ( context->numCPUCores < needsCompilePacketCount ) ? context->numCPUCores : needsCompilePacketCount;
				uint32_t numAdditionalThreads = ( numWorkers > 1 ) ? numWorkers - 1 : 0;

				printf( "Compiling %u files across %u threads.\n", needsCompilePacketCount, numWorkers );
				printf( "          %u files were skipped.\n", compilePacketCount - needsCompilePacketCount );

				builderThread_t *additionalThreads = NULL;
				uint32_t numCreatedThreads = 0;

				// allocate the structures to hold the results
				builderCompileJobDependencyOutput_t *dependencyOutputs = Builder_ArenaAlloc( scratch.arena, builderCompileJobDependencyOutput_t, numWorkers );
				for ( uint32_t outputIndex = 0; outputIndex < numWorkers; ++outputIndex ) {
					dependencyOutputs[outputIndex] = (builderCompileJobDependencyOutput_t) {
						.arena = &context->threadResultArenas[outputIndex]
					};
				}

				builderCompileJobPool_t pool = {
					.compilePackets				= postBuildData->compilePackets,
					.compilePacketCount			= needsCompilePacketCount,
					.useMSVCSyntax				= context->compilerIsMSVC || context->compilerIsClangCL,
					.dependencyOutputs			= dependencyOutputs
				};

				if ( numAdditionalThreads > 0 ) {
					additionalThreads = Builder_ArenaAlloc( scratch.arena, builderThread_t, numAdditionalThreads );

					for ( uint32_t threadIndex = 0; threadIndex < numAdditionalThreads; threadIndex++ ) {
						if ( Builder_CreateJobThread( Builder_CompileJobThreadProc, &pool, &additionalThreads[numCreatedThreads] ) ) {
							numCreatedThreads++;
						}
					}
				}

				// the main thread pulls jobs from the same pool instead of just sitting idle waiting on the additional threads
				Builder_RunCompileJobPool( &pool );

				for ( uint32_t threadIndex = 0; threadIndex < numCreatedThreads; threadIndex++ ) {
					Builder_ThreadJoin( additionalThreads[threadIndex] );
				}

				// store the dependency info we need later in the post build arena
				uint64_t dependencyInfoCount = 0;
				for ( uint32_t outputIndex = 0; outputIndex < numWorkers; ++outputIndex ) {
					dependencyInfoCount += dependencyOutputs[outputIndex].dependencyInfoCount;
				}

				postBuildData->dependencyInfos = Builder_ArenaAlloc( context->postBuildArena, builderCompileJobDependencyInfo_t, dependencyInfoCount );
				postBuildData->dependencyInfoCount = dependencyInfoCount;

				dependencyInfoCount = 0;
				for ( uint32_t outputIndex = 0; outputIndex < numWorkers; ++outputIndex ) {
					memcpy( &postBuildData->dependencyInfos[dependencyInfoCount], dependencyOutputs[outputIndex].dependencyInfos, dependencyOutputs[outputIndex].dependencyInfoCount * sizeof( builderCompileJobDependencyInfo_t ) );
					dependencyInfoCount += dependencyOutputs[outputIndex].dependencyInfoCount;
				}

				Builder_RewindScratch( &scratch );

				if ( pool.numFailed > 0 ) {
					Builder_Error( "Build failed.\n" );
					Builder_RewindArena( context->buildScratch->arena, &configStart );
					return BUILD_RESULT_FAILED;
				}
			} else {
				printf( "Skipping compilation of all %u files.\n", compilePacketCount );
			}

			compileTimeMS = Builder_TimeMS() - compileTimeStart;
		}

		// link step
		shouldLink = needsCompilePacketCount > 0; // if we compiled something we obviously have to link
		{
			double linkTimeStart = Builder_TimeMS();

			const char *binaryPath = Builder_GetBinaryPath( context->buildScratch->arena, config );
			const char *linkCommand = NULL;
			uint64_t linkCommandHash = 0;
			#if defined( _WIN32 )
				bool useMSVCLink = !context->compilerIsGCC;
			#elif defined( __linux__ )
				bool useMSVCLink = false;
			#else
			#error Unrecognised platform.
			#endif
			if ( compilePacketCount > 0 ) {
				builderLinkContext_t linkContext = {
					.config 					= config,
					.compilerPath 				= context->compilerPath,
					.binaryPath 				= binaryPath,
					.clangSanitizerResourceDir 	= context->clangSanitizerResourceDir,
#if defined ( _WIN32 )
					.msvcInstall 				= &g_msvcInstall,
					.windowsSDKInstall 			= &g_windowsSDKInstall,
					.useMSVCLink 				= useMSVCLink,
					.compilerIsMSVC				= context->compilerIsMSVC,
					.debugDefineSet 			= compileContext.debugDefineSet,
#endif
					.compilerIsGCC				= context->compilerIsGCC,
				};
				linkCommand = Builder_CreateLinkCommand( context->buildScratch->arena, &linkContext, postBuildData );
				linkCommandHash = Builder_HashString( linkCommand );

				// insert the .o files after hashing to deal with file order inconsistencies due to globbing and rebuilds
				// also we really don't need to hash them since we already link if we compiled something
				{
					scratch_t scratch = Builder_GetScratch( context->buildScratch->arena );

					stringBuilder_t linkerArgs = { 0 };

					const char *insertPosition = strstr( linkCommand, binaryPath );
					insertPosition += Builder_Strnlen( binaryPath, BUILDER_MAX_PATH ) + 1;
					StringBuilder_Appendf( scratch.arena, &linkerArgs, "%.*s", (int) ( insertPosition - linkCommand ), linkCommand );

					for ( uint32_t intermediateIndex = 0; intermediateIndex < postBuildData->packetCount; ++intermediateIndex ) {
						StringBuilder_Appendf( scratch.arena, &linkerArgs, "%s ", postBuildData->compilePackets[intermediateIndex].intermediateFile );
					}

					StringBuilder_Appendf( scratch.arena, &linkerArgs, "%s", insertPosition );

					linkCommand = StringBuilder_ToString( context->buildScratch->arena, &linkerArgs, NULL );
					Builder_RewindScratch( &scratch );
				}

				// this means we have no dependency file (or link data in it)
				// which means we definitely need to link, and definitely need to force a full link
				// otherwise we won't properly populate the dependency file
				if ( postBuildData->configDependencies.linkCommandHash == 0 ) {
					shouldLink = true;
					postBuildData->didFullLink = true;

#if defined ( _WIN32 )
					if ( useMSVCLink ) {
						linkCommand = Builder_FormatString( context->buildScratch->arena, "%s /INCREMENTAL:NO", linkCommand );
					}
#endif
				}
			}

			uint64_t binaryFileWriteTime = 0;
			if ( !shouldLink && linkCommand ) {
				const char *binaryPathToUse = config->binaryPathOverride ? config->binaryPathOverride : binaryPath;
				if ( postBuildData->configDependencies.binaryWriteTime && Builder_GetFileLastWriteTime( binaryPathToUse, &binaryFileWriteTime ) ) {
					const bool binaryMismatch 		= postBuildData->configDependencies.binaryWriteTime != binaryFileWriteTime;
					const bool linkCommandMismatch 	= postBuildData->configDependencies.linkCommandHash != linkCommandHash;
					shouldLink = binaryMismatch || linkCommandMismatch;
				} else {
					// binary doesn't exist, counts as a full link
					shouldLink = true;
					postBuildData->didFullLink = true;
				}
			}

			if ( !shouldLink && linkCommand ) {
				libraryDependencyArray_t *libraryDependencyArray = &postBuildData->configDependencies.libraryDependencyArray;
				for ( uint64_t libIndex = 0; libIndex < libraryDependencyArray->count; ++libIndex ) {
					libraryDependency_t *library = &libraryDependencyArray->libraries[libIndex];

					uint64_t libraryWriteTime = 0;
					postBuildData->nextLibraryWriteTimeToCheckIndex = libIndex + 1;
					if ( !Builder_GetFileLastWriteTime( library->libraryPath, &libraryWriteTime ) || libraryWriteTime != library->writeTime ) {
						library->writeTime = libraryWriteTime;
						shouldLink = true;
						break;
					}
				}
			}

			if ( shouldLink && config->binaryFolder && !Builder_CreateFolderIfItDoesntExist( config->binaryFolder ) ) {
				Builder_Error( "Failed to create the binary folder \"%s\".\n", config->binaryFolder );
				Builder_RewindArena( context->buildScratch->arena, &configStart );

				// TODO(aiden): check that compilation dependencies were still written
				return BUILD_RESULT_FAILED;
			}

			if ( shouldLink ) {
				postBuildData->configDependencies.linkCommandHash = linkCommandHash;

				printf( "%s\n", linkCommand );

				char *linkerOutput = NULL;
				int32_t linkResult = Builder_RunProcess( context->buildScratch->arena, linkCommand, false, &linkerOutput );

				if ( linkerOutput ) {
#if defined ( _WIN32 )
					if ( useMSVCLink ) {

						bool withinLibrarySearch = false;
						const char *current = linkerOutput;
						while ( current && *current ) {
							const char *lineStart = current;
							const char *lineEnd = strchr( lineStart, '\n' );
							if ( !lineEnd ) {
								lineEnd = strchr( lineStart, '\0' );
							}

							if ( !withinLibrarySearch && Builder_StringStartsWith( lineStart, "Searching libraries" ) ) {
								withinLibrarySearch = true;
							} else if ( withinLibrarySearch && Builder_StringStartsWith( lineStart, "Finished searching libraries" ) ) {
								withinLibrarySearch = false;
							} else if ( withinLibrarySearch ) {
								if ( Builder_StringStartsWith( lineStart, "    Searching " ) ) {
									const char *libPathStart = lineStart + sizeof("    Searching ") - 1;
									const char *libPathEnd = lineEnd;
									while ( *libPathEnd != ':' ) {
										libPathEnd--;
									}

									uint64_t libPathLength = ( (uint64_t) libPathEnd ) - ( (uint64_t) libPathStart );
									const char *library = Builder_FormatString( context->postBuildArena, "%.*s", libPathLength, libPathStart );

									bool found = false;
									for ( builderStringChunk_t *chunk = postBuildData->linkLibraryOutput.head; chunk && !found; chunk = chunk->next ) {
										for ( uint32_t foundLibsIndex = 0; foundLibsIndex < chunk->count; foundLibsIndex++ ) {
											if ( Builder_StringEquals( library, chunk->items[foundLibsIndex] ) ) {
												found = true;
												break;
											}
										}
									}

									if ( !found ) {
										Builder_StringListPush( context->postBuildArena, &postBuildData->linkLibraryOutput, library );
									}
								}
							} else {
								printf( "%.*s\n", (int) ( lineEnd - lineStart ), lineStart );
							}

							current = lineEnd;

							if ( current ) {
								current += 1;
							}
						}
					} else {
#else
					{
#endif
						const char *current = linkerOutput;
						while ( current && *current ) {
							const char *lineStart = current;
							const char *lineEnd = strchr( lineStart, '\n' );
							if ( !lineEnd ) {
								lineEnd = strchr( lineStart, '\0' );
							}
							uint64_t lineLength = ( (uint64_t) lineEnd ) - ( (uint64_t) lineStart );

							// isolate only the --trace outputs
							// TODO: AK: 26/09/2026: this seems brittle
							const char *filename = Builder_FilenameFromPath( lineStart, lineLength );
							const char *dotPos = strchr( filename, '.' );
							const char *spacePos = dotPos ? strchr( dotPos, ' ' ) : NULL;
							bool isTraceOutput = dotPos && dotPos < lineEnd
								&& ( !spacePos || spacePos > lineEnd )
								&& !Builder_StringStartsWith( lineStart, "clang:" );
							if ( isTraceOutput ) {
								// TODO: AK: 26/09/2026: What happens if their intermediate and bin folder overlaps? Will we let them do that?
								if ( !Builder_StringStartsWith( lineStart, context->intermediateFolder ) ) {
									const char *library = Builder_FormatString( context->postBuildArena, "%.*s", lineLength, lineStart );

									bool found = false;
									for ( builderStringChunk_t *chunk = postBuildData->linkLibraryOutput.head; chunk && !found; chunk = chunk->next ) {
										for ( uint32_t foundLibsIndex = 0; foundLibsIndex < chunk->count; foundLibsIndex++ ) {
											if ( Builder_StringEquals( library, chunk->items[foundLibsIndex] ) ) {
												found = true;
												break;
											}
										}
									}

									if ( !found ) {
										Builder_StringListPush( context->postBuildArena, &postBuildData->linkLibraryOutput, library );
									}
								}
							} else {
								printf( "%.*s\n", (int) ( lineLength ), lineStart );
							}

							current = lineEnd;

							if ( current ) {
								current += 1;
							}
						}
					}
				}

				if ( linkResult != 0 ) {
					Builder_Error( "Link failed.\n" );
					Builder_RewindArena( context->buildScratch->arena, &configStart );

					// force the link to show as a fail
					postBuildData->configDependencies.binaryWriteTime = 0;
					postBuildData->configDependencies.linkCommandHash = 0;
					return BUILD_RESULT_FAILED;
				}

				if ( !Builder_GetFileLastWriteTime( binaryPath, &postBuildData->configDependencies.binaryWriteTime ) ) {
					Builder_Warning( "Failed to get binary write time after linking.\n" );
					postBuildData->configDependencies.binaryWriteTime = 0;
				}
			} else {
				printf( "Skipping linking.\n" );
			}

			linkTimeMS = Builder_TimeMS() - linkTimeStart;

#if defined( _WIN32 )
			// the asan runtime is a DLL on windows, so the binary wont even start unless the DLL sits next to it
			// msvc and clang both ship their own copy
			// msvc picks the debug flavour of the runtime when using the debug CRT
			if ( useMSVCLink && ( config->sanitizers & SANITIZER_ADDRESS ) && ( config->binaryType != BINARY_TYPE_STATIC_LIBRARY ) ) {
				const char *dllName = "clang_rt.asan_dynamic-x86_64.dll";
				const char *dllFolder = NULL;

				if ( context->compilerIsMSVC ) {
					dllFolder = Builder_FormatString( context->buildScratch->arena, "%s\\bin\\Hostx64\\x64", g_msvcInstall.rootFolder );

					if ( compileContext.debugDefineSet ) {
						dllName = "clang_rt.asan_dbg_dynamic-x86_64.dll";
					}
				} else {
					dllFolder = Builder_FormatString( context->buildScratch->arena, "%s\\lib\\windows", context->clangSanitizerResourceDir );
				}

				const char *asanRuntimeSrc = Builder_FormatString( context->buildScratch->arena, "%s\\%s", dllFolder, dllName );

				const char *asanRuntimeDst = dllName;
				if ( config->binaryFolder ) {
					asanRuntimeDst = Builder_FormatString( context->buildScratch->arena, "%s%c%s", config->binaryFolder, BUILDER_PATH_SEPARATOR, dllName );
				}

				if ( !CopyFileA( asanRuntimeSrc, asanRuntimeDst, FALSE ) ) {
					Builder_Error( "Failed to copy the ASan runtime \"%s\" to \"%s\": GetLastError(): 0x%X\n", asanRuntimeSrc, asanRuntimeDst, GetLastError() );
					Builder_RewindArena( context->buildScratch->arena, &configStart );
					return BUILD_RESULT_FAILED;
				}
			}
#endif
		}
	}

	if ( config->OnPostBuild ) {
		Builder_LogVerbose( options, "Found a OnPostBuild() func ptr for BuildConfig: \"%s\".  Running...\n", config->name ? config->name : "" );

		config->OnPostBuild( config );
	}

	printf( "Finished config \"%s\":\n", config->name ? config->name : "" );
	printf( "    Compile : %f ms\n", compileTimeMS );
	printf( "    Link    : %f ms\n", linkTimeMS );
	printf( "\n" );

	const char *suffix = NULL;
	if ( needsCompilePacketCount == 0 ) {
		suffix = shouldLink ? "(link only)" : "(skipped)";
	}
	Builder_AddBuildSummaryLine( context->buildSummaryArena, &context->buildSummary, config->name, compileTimeMS + linkTimeMS, suffix );

	context->totalCompileTimeMS += compileTimeMS;
	context->totalLinkTimeMS += linkTimeMS;

	Builder_RewindArena( context->buildScratch->arena, &configStart );

	return ( needsCompilePacketCount > 0 ) ? BUILD_RESULT_SUCCESS : BUILD_RESULT_SKIPPED;
}

// writes out the .builder-dependencies file for every config that compiled something this run
static void Builder_WriteDependencyCache( builderBuildContext_t *context, BuilderOptions *options ) {
	printf( "Caching dependency info for incremental builds...\n\n" );

	for ( uint32_t configIndex = 0; configIndex < context->builtConfigs; ++configIndex ) {
		builderPostBuildConfigData_t *postBuildData 	= &context->postBuildConfigDependencyData[configIndex];
		builderConfigDependencies_t *configDependencies	= &postBuildData->configDependencies;

		// only store dependencies for configs that need it
		if ( postBuildData->packetCount == 0 ) {
			continue;
		}

		// create the dependency array if it wasn't already
		// it is probably okay for the array to have stale dependencies
		const uint32_t dependenciesCapcity = 16;
		compileDependencyArray_t *compileDependencyArray = &configDependencies->compileDependencyArray;
		if ( compileDependencyArray->capacity == 0 ) {
			*compileDependencyArray = (compileDependencyArray_t) {
				.count			= 0,
				.capacity		= dependenciesCapcity,
				.dependencies	= Builder_ArenaAlloc( context->postBuildArena, compileDependency_t, dependenciesCapcity )
			};
		}

		// new mapping as the number of files could have changed
		// plus if a file compiled we don't want to accidentally have stored stale dependency data
		{
			objectToDependencyIndicies_t *objectToDependencyMapping = Builder_ArenaAlloc( context->postBuildArena, objectToDependencyIndicies_t, postBuildData->packetCount );
			for ( uint32_t packetIndex = 0; packetIndex < postBuildData->compiledPacketCount; ++packetIndex ) {
				objectToDependencyMapping[packetIndex] = (objectToDependencyIndicies_t) { 0 };
			}

			// recover the old data since these didn't compile
			for ( uint32_t packetIndex = postBuildData->compiledPacketCount; packetIndex < postBuildData->packetCount; ++packetIndex ) {
				objectToDependencyIndicies_t *objectDependencies = &objectToDependencyMapping[packetIndex];
				*objectDependencies = (objectToDependencyIndicies_t) { 0 };

				Builder_LogVerbose( options, "Finding old data for %s with hash %" PRIu64 "\n", postBuildData->compilePackets[packetIndex].sourceFile, postBuildData->compilePackets[packetIndex].compileCommandHash );

				for ( uint64_t objectIndex = 0; objectIndex < configDependencies->objectFileCount; ++objectIndex ) {
					if ( configDependencies->objectDependencyMap[objectIndex].objectHash == postBuildData->compilePackets[packetIndex].compileCommandHash ) {
						*objectDependencies = configDependencies->objectDependencyMap[objectIndex];
						break;
					}
				}

				BUILDER_ASSERT( objectDependencies->objectHash != 0 && "We skipped compilation of a file so should have its dependency data" );
			}

			configDependencies->objectFileCount = postBuildData->packetCount;
			configDependencies->objectDependencyMap = objectToDependencyMapping;
		}

		// now actually parse the current invocation's dependency info, adding any new dependencies
		for ( uint32_t dependencyInfoIndex = 0; dependencyInfoIndex < postBuildData->dependencyInfoCount; ++dependencyInfoIndex ) {
			builderCompileJobDependencyInfo_t *dependencyInfo = &postBuildData->dependencyInfos[dependencyInfoIndex];
			builderCompilePacket_t *compilePacket =  &postBuildData->compilePackets[dependencyInfo->compilePacketIndex];
			objectToDependencyIndicies_t *dependencyMap = &configDependencies->objectDependencyMap[dependencyInfo->compilePacketIndex];

			*dependencyMap = (objectToDependencyIndicies_t ) {
				.objectHash 		= compilePacket->compileCommandHash,
				.dependencyCount 	= 0,
				.dependencyCapacity	= 16,
				.dependencyIndices	= Builder_ArenaAlloc( context->postBuildArena, uint64_t, 16 )
			};

			Builder_ParseDependencyInfo( context->postBuildArena, compileDependencyArray, dependencyMap, dependencyInfo->dependencyString, context->compilerIsMSVC || context->compilerIsClangCL );
		}

		Builder_LogVerbose( options, "Outputting config dependencies to %s:\n", postBuildData->dependencyCacheFileName );
		for ( uint32_t packetIndex = 0; packetIndex < postBuildData->packetCount; ++packetIndex ) {
			objectToDependencyIndicies_t *dependencyMap = &configDependencies->objectDependencyMap[packetIndex];
			builderCompilePacket_t *compilePacket = &postBuildData->compilePackets[packetIndex];

			Builder_LogVerbose( options, "%s has %llu dependenc%s%c\n", compilePacket->sourceFile, dependencyMap->dependencyCount, dependencyMap->dependencyCount != 1 ? "ies" : "y", dependencyMap->dependencyCount ? ':' : '.' );
			for ( uint64_t mapIndex = 0; mapIndex < dependencyMap->dependencyCount; ++mapIndex ) {
				const uint64_t dependencyIndex = dependencyMap->dependencyIndices[mapIndex];
				Builder_LogVerbose( options, "    %s\n", compileDependencyArray->dependencies[dependencyIndex].dependency );
			}
		}

		// incremental link dependencies
		libraryDependencyArray_t *libraryDependencyArray = &configDependencies->libraryDependencyArray;
		if ( libraryDependencyArray->capacity == 0 && postBuildData->linkLibraryOutput.count ) {
			libraryDependencyArray->capacity = postBuildData->linkLibraryOutput.count;
			libraryDependencyArray->libraries = Builder_ArenaAlloc( context->postBuildArena, libraryDependency_t, postBuildData->linkLibraryOutput.count );
		}

		// full link means we want to stamp all the old data (chances are it will be 0 anyway)
		uint64_t libCountBeforeAppending = postBuildData->didFullLink ? 0 : libraryDependencyArray->count;
		for ( builderStringChunk_t *chunk = postBuildData->linkLibraryOutput.head; chunk; chunk = chunk->next ) {
			for ( uint32_t foundLibsIndex = 0; foundLibsIndex < chunk->count; foundLibsIndex++ ) {
				const char *libPath = chunk->items[foundLibsIndex];
				const char *libFilename = Builder_FilenameFromPath( libPath, strlen( libPath ) );

				bool found = false;
				for ( uint64_t libIndex = 0; libIndex < libCountBeforeAppending; ++libIndex ) {
					libraryDependency_t *dependency = &libraryDependencyArray->libraries[libIndex];

					if ( Builder_StringEquals( dependency->libraryName, libFilename ) ) {
						found = true;
						if ( !Builder_StringEquals( dependency->libraryPath, libPath ) ) {
							Builder_LogVerbose( options, "Lib path being updated from %s\n", dependency->libraryPath );
							dependency->libraryPath = libPath;

							// the rest will be updated in 'bulk', this op is not fast so we optimise for it
							// realistically we should just grab all of them upfront before doing the checks
							// when determining if we need to linkincrementally
							if ( libIndex < postBuildData->nextLibraryWriteTimeToCheckIndex ) {
								Builder_GetFileLastWriteTime( libPath, &dependency->writeTime );
							}
							break;
						}
					}
				}

				if ( found ) {
					continue;
				}

				if ( libraryDependencyArray->count == libraryDependencyArray->capacity ) {
					libraryDependencyArray->libraries = Builder_ArenaRealloc( context->postBuildArena, libraryDependencyArray->libraries,
						libraryDependency_t, libraryDependencyArray->capacity, libraryDependencyArray->capacity * 2);
					libraryDependencyArray->capacity *= 2;
				}

				libraryDependency_t *dependency = &libraryDependencyArray->libraries[libraryDependencyArray->count++];
				dependency->libraryName = libFilename;
				dependency->libraryPath = libPath;
			}
		}

		// now grab the rest of the write times, we don't want to have to link next time just because we didn't do this
		// this could also go over multiple threads if it is worthwhile
		for ( uint64_t libIndex = postBuildData->nextLibraryWriteTimeToCheckIndex; libIndex < libraryDependencyArray->count; ++libIndex ) {
			libraryDependency_t *dependency = &libraryDependencyArray->libraries[libIndex];
			Builder_GetFileLastWriteTime( dependency->libraryPath, &dependency->writeTime );
		}

		Builder_LogVerbose( options, "Library (link) dependencies:\n" );
		for ( uint64_t libIndex = 0; libIndex < libraryDependencyArray->count; ++libIndex ) {
			libraryDependency_t *dependency = &libraryDependencyArray->libraries[libIndex];
			Builder_LogVerbose( options, "%s:\n", dependency->libraryName );
			Builder_LogVerbose( options, "	PATH: %s\n", dependency->libraryPath );
			Builder_LogVerbose( options, "	TIME: %llu\n", dependency->writeTime );
		}

		configDependencies->fileVersion = g_builderDependenciesFileVersion;
		byteBuffer_t byteBuffer = Builder_ByteBufferFromConfigDependencies( context->postBuildArena, configDependencies );
		Builder_WriteEntireFile( postBuildData->dependencyCacheFileName, (char *) byteBuffer.data, byteBuffer.count );
	}
}

int Build( BuilderOptions *options, int argc, char **argv ) {
	double totalTimeStart = Builder_TimeMS();

	printf( "Builder v%d.%d.%d\n\n", BUILDER_VERSION_MAJOR, BUILDER_VERSION_MINOR, BUILDER_VERSION_PATCH );

	Builder_SetCmdArgs( options, argc, argv );

	Builder_SetCWD( options, argv );

	// the self rebuild needs the exe itself, not just its folder
	char exePath[BUILDER_MAX_PATH] = { 0 };
	Builder_GetExePath( argv, exePath );

	// TODO: DM: 30/08/2026: we should probably make that global long lifetime arena that we talked about
	// there are other things that could and should go on it as well as build summaries
	arena_t buildSummaryArena = { 0 };

	// toolchain and compiler paths are used right through to the link step.
	// this deliberately excludes the config arena: OnPreBuild/OnPostBuild callbacks run inside the loop below, so a
	// callback calling Add*()/Set*() allocates while this scratch is open.  If the two shared an arena, the per-config
	// rewind would take whatever the callback added with it and leave the config pointing into reusable memory.
	scratch_t buildScratch = Builder_GetScratch( Builder_GetConfigArena() );

	// only query for windows SDK and MSVC installations after verifying cmd line args and
#ifdef _WIN32
	if ( !Builder_GetWindowsSDKInstall( buildScratch.arena, &g_windowsSDKInstall ) ) {
		return 1;
	}

	if ( !Builder_GetMSVCInstall( buildScratch.arena, &g_msvcInstall ) ) {
		return 1;
	}

	printf( "\n" );
#endif

	if ( !Builder_StringIsEmpty( options->compilerPath ) ) {
		Builder_LogVerbose( options, "Found override compiler backend \"%s\" from BuilderOptions::compilerPath.\n", options->compilerPath );
	}

	const char *compilerPath = !Builder_StringIsEmpty( options->compilerPath ) ? options->compilerPath : "clang";

	bool compilerIsMSVC = Builder_StringEquals( compilerPath, "cl" ) || Builder_StringEquals( compilerPath, "cl.exe" );
	bool compilerIsClang = Builder_PathEndsWith( compilerPath, "clang" )
						|| Builder_PathEndsWith( compilerPath, "clang.exe" )
						|| Builder_PathEndsWith( compilerPath, "clang++" )
						|| Builder_PathEndsWith( compilerPath, "clang++.exe" );
	bool compilerIsClangCL = Builder_PathEndsWith( compilerPath, "clang-cl" )
						|| Builder_PathEndsWith( compilerPath, "clang-cl.exe" );
	bool compilerIsGCC = Builder_PathEndsWith( compilerPath, "gcc" )
						|| Builder_PathEndsWith( compilerPath, "gcc.exe" )
						|| Builder_PathEndsWith( compilerPath, "g++" )
						|| Builder_PathEndsWith( compilerPath, "g++.exe" );
	// clang++ and g++ end with the same 3 characters
	// so check if we already had compilerIsClang set to true
	compilerIsGCC &= !compilerIsClang;

#ifndef _WIN32
	if ( compilerIsMSVC ) {
		Builder_Error(
			"It appears you want to compile with MSVC on a non-Windows platform.\n"
			"MSVC only supports Windows.  Sorry.\n"
		);

		return 1;
	}
#endif

	char *compilerVersionString = NULL;
#ifdef _WIN32
	if ( compilerIsMSVC ) {
		compilerPath = g_msvcInstall.compilerPath;
		compilerVersionString = Builder_FormatString( buildScratch.arena, "%d.%d.%d", g_msvcInstall.version.v0, g_msvcInstall.version.v1, g_msvcInstall.version.v2 );
	} else
#endif
	{
		char *versionCmd = Builder_FormatString( buildScratch.arena, "\"%s\" --version", compilerPath );
		char *versionOutput = NULL;

		Builder_RunProcess( buildScratch.arena, versionCmd, false, &versionOutput );
		compilerVersionString = Builder_ExtractVersionNumber( buildScratch.arena, versionOutput );
	}

	if ( !Builder_StringIsEmpty( options->compilerVersion ) ) {
		if ( !Builder_StringEquals( compilerVersionString, options->compilerVersion ) ) {
			Builder_Warning( "You are using compiler version \"%s\", but \"%s\" was set as BuilderOptions::compilerVersion.  I will continue building anyway, but you may not get what you expect.\n", compilerVersionString, options->compilerVersion );
		}
	}

	const char *intermediateFolder = options->intermediateFolder;
	if ( !intermediateFolder || *intermediateFolder == '\0' ) {
		intermediateFolder = "intermediate";
	}

	if ( intermediateFolder && !Builder_CreateFolderIfItDoesntExist( intermediateFolder ) ) {
		Builder_Error( "Failed to create the intermediate folder \"%s\".\n", intermediateFolder );
		return 1;
	}

	// cl.exe embeds its own /DEFAULTLIB directives for /fsanitize=... into the object file so link.exe picks the runtime up automatically there
	// GCC doesnt link via link.exe so it handles its own sanitizer runtime
	// clang and clang-cl on Windows do neither, they go through link.exe directly so we have to name their sanitizer runtime libs ourselves which live under the resource directory
	// we query that once up front and then only use it if some config actually needs it
	char *clangSanitizerResourceDir = NULL;

#if defined( _WIN32 )
	if ( compilerIsClang || compilerIsClangCL ) {
		// this runs before the target config is known so it looks at every registered config, not just the ones being built
		bool anyConfigNeedsClangSanitizerLibs = false;

		for ( buildConfigPtrChunk_t *chunk = options->configs.head; chunk && !anyConfigNeedsClangSanitizerLibs; chunk = chunk->next ) {
			for ( uint32_t configIndex = 0; configIndex < chunk->count; configIndex++ ) {
				if ( chunk->items[configIndex]->sanitizers != 0 ) {
					anyConfigNeedsClangSanitizerLibs = true;
					break;
				}
			}
		}

		if ( anyConfigNeedsClangSanitizerLibs ) {
			char *resourceDirCmd = Builder_FormatString( buildScratch.arena, "\"%s\" -print-resource-dir", compilerPath );

			Builder_RunProcess( buildScratch.arena, resourceDirCmd, true, &clangSanitizerResourceDir );

			size_t resourceDirLength = clangSanitizerResourceDir ? strlen( clangSanitizerResourceDir ) : 0;
			while ( resourceDirLength > 0 && ( clangSanitizerResourceDir[resourceDirLength - 1] == '\n' || clangSanitizerResourceDir[resourceDirLength - 1] == '\r' ) ) {
				clangSanitizerResourceDir[--resourceDirLength] = 0;
			}

			if ( resourceDirLength == 0 ) {
				Builder_Error( "Failed to determine Clang's resource directory (\"%s\") - needed to link the sanitizer runtime on Windows.\n", resourceDirCmd );
				Builder_RewindScratch( &buildScratch );

				return 1;
			}
		}
	}
#endif

	// we can create the extra arenas we will need for the compilation thread's output here
	// and the arena we need post build to sort the dependency data we collect over the run
	uint32_t numCPUCores = Builder_GetNumCPUCores();
	arena_t postBuildArena = { 0 };
	arena_t *threadResultArenas = Builder_ArenaAlloc( buildScratch.arena, arena_t, numCPUCores );
	for ( uint32_t arenaIndex = 0; arenaIndex < numCPUCores; ++arenaIndex ) {
		threadResultArenas[arenaIndex] = (arena_t) { 0 };
	}

	builderBuildContext_t buildContext = {
		.buildScratch					= &buildScratch,
		.compilerPath					= compilerPath,
		.compilerVersionString			= compilerVersionString,
		.compilerIsMSVC					= compilerIsMSVC,
		.compilerIsClangCL				= compilerIsClangCL,
		.compilerIsGCC					= compilerIsGCC,
		.clangSanitizerResourceDir		= clangSanitizerResourceDir,
		.intermediateFolder				= intermediateFolder,
		.numCPUCores					= numCPUCores,
		.threadResultArenas				= threadResultArenas,
		.postBuildArena					= &postBuildArena,
		.buildSummaryArena				= &buildSummaryArena,
		.postBuildConfigDependencyData	= Builder_ArenaAlloc( &postBuildArena, builderPostBuildConfigData_t, options->configs.count ),
	};

	// the self rebuild config gets fixed up whether or not we actually build it below
	// the config name check and the target config filtering further down both read these fields
	if ( options->selfRebuildConfig ) {
#if defined( _WIN32 )
		// if the old binary was left around from the previous rebuild, clean it up now
		{
			char *oldBackupPath = Builder_FormatString( buildScratch.arena, "%s.rebuild.old", exePath );
			DeleteFile( oldBackupPath );
		}
#endif

		// point the config at a temp file alongside the exe, whatever the user put in those fields
		// CWD is already the exe's folder so no binaryFolder is needed
		{
			const char *exeName = strrchr( exePath, BUILDER_PATH_SEPARATOR );
			exeName = exeName ? exeName + 1 : exePath;

			// Builder_GetBinaryPath() adds the platform exe extension back on
			size_t exeNameLength = strlen( exeName );
			const char *exeExtension = Builder_GetFileExtensionFromBinaryType( BINARY_TYPE_EXE );
			if ( Builder_PathEndsWith( exeName, exeExtension ) ) {
				exeNameLength -= strlen( exeExtension );
			}

			if ( !options->selfRebuildConfig->name ) {
				options->selfRebuildConfig->name = "self";
			}

			options->selfRebuildConfig->binaryName = Builder_FormatString( Builder_GetConfigArena(), "%.*s.rebuild.tmp", (int) exeNameLength, exeName );
			options->selfRebuildConfig->binaryPathOverride = exePath;
			options->selfRebuildConfig->binaryFolder = NULL;
			options->selfRebuildConfig->binaryType = BINARY_TYPE_EXE;
		}

#if defined( _WIN32 )
		// GCC ignores #pragma comment( lib ) so the libs that builder.h itself needs must be named explicitly
		if ( compilerIsGCC ) {
			AddLibs( options->selfRebuildConfig, "ole32", "oleaut32", "advapi32" );

			// __thread requires libwinpthread-1.dll because GCC on windows links its runtime by default by default
			// so make the self rebuild config link to it statically to avoid this
			AddLinkerArguments( options->selfRebuildConfig, "-static" );
		}
#endif
	}

	// the self rebuild goes first so that the source is always the truth
	// a stale binary would otherwise reject a config name or --config= that only exists in the edited build source, or keep building with old settings
	// it needs the toolchain and arenas above but not the target config
	// ARG_SELF_REBUILT says we are the relaunch of a build program that was just rebuilt
	// skip it in that case, otherwise forceRebuild would rebuild and re-exec every run forever
	if ( options->selfRebuildConfig && !HasCommandLineArg( argc, argv, ARG_SELF_REBUILT ) ) {
		builderBuildResult_t selfRebuildResult = Builder_BuildConfig( &buildContext, options, options->selfRebuildConfig );

		if ( selfRebuildResult == BUILD_RESULT_FAILED ) {
			Builder_Error( "Failed to rebuild '%s'.\n", exePath );
			Builder_RewindScratch( &buildScratch );
			return 1;
		}

		const char *selfTempBinaryPath = Builder_GetBinaryPath( buildScratch.arena, options->selfRebuildConfig );

		// swap the rebuilt binary over the running exe and relaunch with the original argv, so this never falls through
		if ( selfRebuildResult == BUILD_RESULT_SUCCESS ) {
			printf( "\"%s\" was stale and got rebuilt.\n", exePath );

			// the relaunch never reaches the cache write after the loop
			// so if we dont do this the self config would recompile every run
			Builder_WriteDependencyCache( &buildContext, options );

			// atomically swap the freshly built binary into place
			// never overwrite exePath in place since writing directly into a currently-executing image fails
#if defined( _WIN32 )
			// on windows a currently-running process cant MoveFileEx-replace its own on-disk image directly (fails with ERROR_ACCESS_DENIED)
			// rename it out of the way first, then move the freshly built binary into the now-vacated name
			// the running image stays mapped and executing under its backup name until this process re-execs below
			const char *backupBinaryPath = Builder_FormatString( buildScratch.arena, "%s.rebuild.old", exePath );

			if ( !MoveFileEx( exePath, backupBinaryPath, MOVEFILE_REPLACE_EXISTING ) ) {
				Builder_Error( "Failed to move currently-running '%s' out of the way: 0x%X\n", exePath, GetLastError() );
				Builder_RewindScratch( &buildScratch );
				return 1;
			}

			if ( !MoveFileEx( selfTempBinaryPath, exePath, MOVEFILE_REPLACE_EXISTING ) ) {
				Builder_Error( "Failed to replace '%s' with rebuilt binary: 0x%X\n", exePath, GetLastError() );
				Builder_RewindScratch( &buildScratch );
				return 1;
			}
#elif defined( __linux__ )
			if ( rename( selfTempBinaryPath, exePath ) != 0 ) {
				int err = errno;
				Builder_Error( "Failed to replace '%s' with rebuilt binary: %s\n", exePath, strerror( err ) );
				Builder_RewindScratch( &buildScratch );
				return 1;
			}
#else
#error Unrecognised platform.
#endif

			// re-exec the freshly rebuilt binary with the original argv, plus ARG_SELF_REBUILT so it doesnt rebuild itself and relaunch again
			// never fall through to running the (now stale-in-memory) code of the process currently executing
			// exec/spawn dont flush stdio, so anything still buffered (e.g. when stdout is a pipe) would be lost
			fflush( stdout );
			fflush( stderr );

#if defined( _WIN32 )
			stringBuilder_t execArgs = { 0 };
			StringBuilder_Appendf( buildScratch.arena, &execArgs, "\"%s\" ", exePath );

			for ( int argIndex = 1; argIndex < argc; argIndex++ ) {
				StringBuilder_Appendf( buildScratch.arena, &execArgs, "\"%s\" ", argv[argIndex] );
			}

			StringBuilder_Appendf( buildScratch.arena, &execArgs, "\"%s\" ", ARG_SELF_REBUILT );

			const char *execCmd = StringBuilder_ToString( buildScratch.arena, &execArgs, NULL );

			exit( Builder_RunProcess( NULL, execCmd, false, NULL ) );
#elif defined( __linux__ )
			// execv wants its own NULL terminated array, so copy argv and tack ARG_SELF_REBUILT on the end
			char **newArgv = Builder_ArenaAlloc( buildScratch.arena, char *, argc + 2 );
			memcpy( newArgv, argv, argc * sizeof( char * ) );
			newArgv[argc] = (char *) ARG_SELF_REBUILT;
			newArgv[argc + 1] = NULL;

			execv( exePath, newArgv );

			// execv only ever returns on failure, otherwise just carries on
			int err = errno;
			Builder_Error( "Failed to re-exec '%s': %s\n", exePath, strerror( err ) );

			Builder_RewindScratch( &buildScratch );
			return 1;
#endif
		}

#if defined( _WIN32 )
		DeleteFile( selfTempBinaryPath );
#elif defined( __linux__ )
		unlink( selfTempBinaryPath );
#else
#error Unrecognised platform.
#endif
	}

	// Names can only be checked here.  A config comes out of CreateBuildConfig() blank and gets filled in afterwards,
	// so this is the first point at which every config actually has the name it's going to be built under.
	for ( buildConfigPtrChunk_t *chunk = options->configs.head; chunk; chunk = chunk->next ) {
		for ( uint32_t configIndex = 0; configIndex < chunk->count; configIndex++ ) {
			BuildConfig *config = chunk->items[configIndex];

			if ( Builder_StringIsEmpty( config->name ) ) {
				Builder_Error( "One of your BuildConfigs has no name.  Every config needs one - it's what \"" ARG_CONFIG "\" matches against and what the build log calls it.\n" );
				return 1;
			}

			if ( Builder_StringIsEmpty( config->binaryName ) ) {
				config->binaryName = config->name;
			}

			// only has to look at the configs after this one, since anything before it already compared against this
			for ( buildConfigPtrChunk_t *otherChunk = chunk; otherChunk; otherChunk = otherChunk->next ) {
				uint32_t firstOtherIndex = ( otherChunk == chunk ) ? configIndex + 1 : 0;

				for ( uint32_t otherIndex = firstOtherIndex; otherIndex < otherChunk->count; otherIndex++ ) {
					if ( Builder_StringEquals( otherChunk->items[otherIndex]->name, config->name ) ) {
						Builder_Error( "There is more than one BuildConfig called \"%s\".  Config names have to be unique, otherwise \"" ARG_CONFIG "%s\" has no way of telling them apart.\n", config->name, config->name );
						return 1;
					}
				}
			}
		}
	}

	// validate cmd line args
	const char *nameOfConfigToBuild = Builder_GetNameOfConfigToBuild( options, argc, argv );
	BuildConfig *targetConfig = NULL;
	{
		// the self rebuild config is registered like any other but is never a target
		uint32_t targetableConfigCount = options->configs.count - ( options->selfRebuildConfig ? 1 : 0 );

		if ( targetableConfigCount == 0 && !options->selfRebuildConfig ) {
			Builder_Error( "No BuildConfig was registered.  You must call CreateBuildConfig() at least once.\n" );
			return 1;
		} else if ( targetableConfigCount > 1 && !nameOfConfigToBuild ) {
			Builder_Error( "You have more than 1 BuildConfig defined, but you never told me which you wanted me to build via \"" ARG_CONFIG "\".  You need to tell me what config you want me to build, or set a default via BuilderOptions::defaultConfig.\n" );
			return 1;
		}

		if ( nameOfConfigToBuild ) {
			for ( buildConfigPtrChunk_t *chunk = options->configs.head; chunk && !targetConfig; chunk = chunk->next ) {
				for ( uint32_t configIndex = 0; configIndex < chunk->count; configIndex++ ) {
					if ( Builder_StringEquals( chunk->items[configIndex]->name, nameOfConfigToBuild ) ) {
						targetConfig = chunk->items[configIndex];
						break;
					}
				}
			}

			if ( !targetConfig || targetConfig == options->selfRebuildConfig ) {
				Builder_Error( "No BuildConfig found with the name \"%s\".\n", nameOfConfigToBuild );
				return 1;
			}
		} else {
			for ( buildConfigPtrChunk_t *chunk = options->configs.head; chunk && !targetConfig; chunk = chunk->next ) {
				for ( uint32_t configIndex = 0; configIndex < chunk->count; configIndex++ ) {
					BuildConfig *config = chunk->items[configIndex];

					if ( config != options->selfRebuildConfig ) {
						targetConfig = config;
						break;
					}
				}
			}

			if ( !targetConfig ) {
				Builder_Error( "The only registered BuildConfig is BuilderOptions::selfRebuildConfig, which is useless on its own.\n" );
				return 1;
			}
		}
	}

	// the walk happens here rather than as configs are created because dependencies get attached to a config after
	// CreateBuildConfig() has handed it over, so this is the first point the graph is complete.
	// its lists go on buildScratch above the toolchain paths but below the rewind spot the loop takes for each config,
	// so the per-config rewind can't reach back and take them with it
	ConfigPtrList ancestry = { 0 };
	ConfigPtrList configsToBuild = { 0 };

	Builder_CollectConfigsToBuild( buildScratch.arena, targetConfig, &ancestry, &configsToBuild );

	bool buildFailed = false;

	for ( buildConfigPtrChunk_t *chunk = configsToBuild.head; chunk && !buildFailed; chunk = chunk->next ) {
		for ( uint32_t configIndex = 0; configIndex < chunk->count; configIndex++ ) {
			if ( Builder_BuildConfig( &buildContext, options, chunk->items[configIndex] ) == BUILD_RESULT_FAILED ) {
				buildFailed = true;
				break;
			}
		}
	}

	Builder_WriteDependencyCache( &buildContext, options );

	{
		Builder_FreeArenas( &postBuildArena, 1 );
		Builder_FreeArenas( threadResultArenas, numCPUCores );
	}

	// build summary
	if ( !buildFailed ) {
		Builder_AddBuildSummaryLine( &buildSummaryArena, &buildContext.buildSummary, "Total compile", buildContext.totalCompileTimeMS, NULL );
		Builder_AddBuildSummaryLine( &buildSummaryArena, &buildContext.buildSummary, "Total link", buildContext.totalLinkTimeMS, NULL );
		// Builder_AddBuildSummaryLine( &buildSummaryArena, &buildContext.buildSummary, "Total .builder-dependencies read", totalBuilderDepsReadTimeMS, NULL );
		// Builder_AddBuildSummaryLine( &buildSummaryArena, &buildContext.buildSummary, "Total .builder-dependencies write", totalBuilderDepsWriteTimeMS, NULL );

		printf( "Finished:\n" );
		for ( buildSummaryPtrChunk_t *chunk = buildContext.buildSummary.head; chunk; chunk = chunk->next ) {
			for ( uint32_t lineIndex = 0; lineIndex < chunk->count; lineIndex++ ) {
				buildSummaryLine_t *line = chunk->items[lineIndex];

				printf( "    %-*s : %f ms %s\n", buildContext.buildSummary.lineLength, line->description, line->timeMS, line->suffix ? line->suffix : "" );
			}
		}

		// separate because we want to get the end timestamp as late as possible
		printf( "    %-*s : %f ms\n\n", buildContext.buildSummary.lineLength, "Total time", Builder_TimeMS() - totalTimeStart );
	}

	Builder_FreeArenas( &buildSummaryArena, 1 );

	Builder_RewindScratch( &buildScratch );

	return buildFailed ? 1 : 0;
}

#endif // BUILDER_IMPLEMENTATION

#pragma clang diagnostic pop

#ifdef __cplusplus
}
#endif
