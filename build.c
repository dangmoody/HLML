#define BUILDER_IMPLEMENTATION
#include "code/3rdparty/include/builder/builder.h"

#if defined( _WIN32 )
#define BUILDER_VISUAL_STUDIO_IMPLEMENTATION
#include "code/3rdparty/include/builder/builder_visual_studio.h"
#endif

#define CMD_ARG_GCC		"--gcc"
#define CMD_ARG_MSVC	"--msvc"
#define CMD_ARG_RELEASE	"--release"
#define CMD_ARG_FORCE	"--force"
#define CMD_ARG_SLN		"--sln"

#define GCC_VERSION		"15.2.0"
#define MSVC_VERSION	"14.44.35207"

typedef enum language_t {
	LANGUAGE_C	= 0,
	LANGUAGE_CPP,

	LANGUAGE_COUNT,
} language_t;

typedef enum config_t {
	CONFIG_DEBUG	= 0,
	CONFIG_RELEASE,

	CONFIG_COUNT,
} config_t;

typedef enum compiler_t {
	COMPILER_CLANG	= 0,
	COMPILER_GCC,
	COMPILER_MSVC,

	COMPILER_COUNT,
} compiler_t;

static const char *GetLanguageFileExtension( const language_t language ) {
	switch ( language ) {
		case LANGUAGE_C:	return "c";
		case LANGUAGE_CPP:	return "cpp";
		case LANGUAGE_COUNT: break;
	}

	BUILDER_ASSERT( false && "Bad language_t passed.\n" );

	return NULL;
}

static const char *GetConfigName( const config_t config ) {
	switch ( config ) {
		case CONFIG_DEBUG:		return "debug";
		case CONFIG_RELEASE:	return "release";
		case CONFIG_COUNT:		break;
	}

	BUILDER_ASSERT( false && "Bad config_t passed.\n" );

	return NULL;
}

static const char *GetCompilerName( const compiler_t compiler ) {
	switch ( compiler ) {
		case COMPILER_CLANG:	return "clang";
		case COMPILER_GCC:		return "gcc";
		case COMPILER_MSVC:		return "msvc";
		case COMPILER_COUNT:	break;
	}

	BUILDER_ASSERT( false && "Bad compiler_t passed.\n" );

	return NULL;
}

#if defined( _WIN32 )
static StringList GetAdditionalBuildArgs( const config_t config ) {
	switch ( config ) {
		case CONFIG_DEBUG:		return (StringList) { 0 };
		case CONFIG_RELEASE:	return MakeStringList( CMD_ARG_RELEASE );
		case CONFIG_COUNT:		break;
	}

	BUILDER_ASSERT( false && "Bad config_t passed.\n" );

	return (StringList) { 0 };
}
#endif

static BuildConfig *CreateTestConfig( BuilderOptions *options, const language_t language, const compiler_t compiler, const config_t config ) {
	const char *languageFileExtension = GetLanguageFileExtension( language );

	BuildConfig *testConfig = CreateBuildConfig( options );
	*testConfig = (BuildConfig) {
		.name				= Config_FormatString( "tests-%s", languageFileExtension ),
		.binaryName			= Config_FormatString( "hlml-tests-%s-%s", GetCompilerName( compiler ), languageFileExtension ),
		.binaryFolder		= Config_FormatString( "bin/%s", GetConfigName( config ) ),
		.sourceFiles		= MakeStringList( Config_FormatString( "code/generated_files/%s/tests/**/*.%s", languageFileExtension, languageFileExtension ) ),
		.additionalIncludes	= MakeStringList( "code/3rdparty/include" ),
	};

#if defined( __linux__ )
	AddLibs( testConfig, "libm", "libstdc++" );
#endif

	if ( compiler == COMPILER_GCC ) {
#if !defined( __linux__ )
		AddCompilerArguments( testConfig, "-Wa,-mbig-obj" );
#endif

		AddLinkerArguments( testConfig, "-static", "-static-libstdc++", "-static-libgcc" );
	}

	return testConfig;
}

int main( int argc, char **argv ) {
	BuilderOptions options = { 0 };

	compiler_t compiler = COMPILER_CLANG;

	const config_t config = HasCommandLineArg( argc, argv, CMD_ARG_RELEASE ) ? CONFIG_RELEASE : CONFIG_DEBUG;

	// options
	{
		options.consolidateCompilerArgs = true;
		options.forceRebuild = HasCommandLineArg( argc, argv, CMD_ARG_FORCE );
		options.intermediateFolder = ".builder";

		if ( HasCommandLineArg( argc, argv, CMD_ARG_GCC ) ) {
			options.compilerPath = "gcc";
			options.compilerVersion = GCC_VERSION;

			compiler = COMPILER_GCC;
		} else if ( HasCommandLineArg( argc, argv, CMD_ARG_MSVC ) ) {
			options.compilerPath = "cl";
			options.compilerVersion = MSVC_VERSION;

			compiler = COMPILER_MSVC;
		}
	}

	// self rebuild
	{
		options.selfRebuildConfig = CreateBuildConfig( &options );
		*options.selfRebuildConfig = (BuildConfig) {
			.name			= "build",
			.sourceFiles	= MakeStringList( "build.c" ),
		};
	}

	// generator
	BuildConfig *generator = CreateBuildConfig( &options );
	{
		*generator = (BuildConfig) {
			.name				= "generator",
			.languageVersion	= LANGUAGE_VERSION_C99,
			.binaryName			= "hlml-generator",
			.binaryFolder		= Config_FormatString( "bin/%s", GetConfigName( config ) ),
			.sourceFiles		= MakeStringList( "code/generator/**/*.c" ),
			.additionalIncludes	= MakeStringList( "code/3rdparty/include" ),
		};

#if defined( __linux__ )
		AddLibs( generator, "libm" );
		AddIgnoreWarnings( generator, "-Wno-typedef-redefinition" );
#elif defined( _WIN32 )
		AddDefines( generator, "WIN32_LEAN_AND_MEAN" );
#endif
	}

	BuildConfig *testConfigC   = CreateTestConfig( &options, LANGUAGE_C,   compiler, config );
	BuildConfig *testConfigCpp = CreateTestConfig( &options, LANGUAGE_CPP, compiler, config );

#if defined( _WIN32 )
	// visual studio solution
	if ( HasCommandLineArg( argc, argv, CMD_ARG_SLN ) ) {
		VisualStudioConfig generatorConfigs[] = {
			{ .name = GetConfigName( CONFIG_DEBUG ),   .config = generator, .additionalBuildArgs = GetAdditionalBuildArgs( CONFIG_DEBUG ),   .nmakeOutput = Config_FormatString( "bin/%s/%s.exe", GetConfigName( CONFIG_DEBUG ),   generator->binaryName ) },
			{ .name = GetConfigName( CONFIG_RELEASE ), .config = generator, .additionalBuildArgs = GetAdditionalBuildArgs( CONFIG_RELEASE ), .nmakeOutput = Config_FormatString( "bin/%s/%s.exe", GetConfigName( CONFIG_RELEASE ), generator->binaryName ) },
		};

		VisualStudioConfig testsConfigs[] = {
			{ .name = Config_FormatString( "c-%s",   GetConfigName( CONFIG_DEBUG ) ),   .config = testConfigC,   .additionalBuildArgs = GetAdditionalBuildArgs( CONFIG_DEBUG ),   .nmakeOutput = Config_FormatString( "bin/%s/%s.exe", GetConfigName( CONFIG_DEBUG ),   testConfigC->binaryName ) },
			{ .name = Config_FormatString( "c-%s",   GetConfigName( CONFIG_RELEASE ) ), .config = testConfigC,   .additionalBuildArgs = GetAdditionalBuildArgs( CONFIG_RELEASE ), .nmakeOutput = Config_FormatString( "bin/%s/%s.exe", GetConfigName( CONFIG_RELEASE ), testConfigC->binaryName ) },
			{ .name = Config_FormatString( "cpp-%s", GetConfigName( CONFIG_DEBUG ) ),   .config = testConfigCpp, .additionalBuildArgs = GetAdditionalBuildArgs( CONFIG_DEBUG ),   .nmakeOutput = Config_FormatString( "bin/%s/%s.exe", GetConfigName( CONFIG_DEBUG ),   testConfigCpp->binaryName ) },
			{ .name = Config_FormatString( "cpp-%s", GetConfigName( CONFIG_RELEASE ) ), .config = testConfigCpp, .additionalBuildArgs = GetAdditionalBuildArgs( CONFIG_RELEASE ), .nmakeOutput = Config_FormatString( "bin/%s/%s.exe", GetConfigName( CONFIG_RELEASE ), testConfigCpp->binaryName ) },
		};

		VisualStudioProject projects[] = {
			{ .name = "generator", .configs = generatorConfigs, .configsCount = BUILDER_COUNT_OF( generatorConfigs ) },
			{ .name = "tests",     .configs = testsConfigs,     .configsCount = BUILDER_COUNT_OF( testsConfigs ) },
		};

		VisualStudioSolution solution = {
			.name			= "HLML",
			.path			= "visual_studio",
			.platforms		= MakeStringList( "x64" ),
			.projects		= projects,
			.projectsCount	= BUILDER_COUNT_OF( projects ),
		};

		return Builder_GenerateVisualStudioSolution( &options, &solution, argc, argv ) ? 0 : 1;
	}
#endif

	return Build( &options, argc, argv );
}
