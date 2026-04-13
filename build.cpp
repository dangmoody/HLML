#ifdef BUILDER_DOING_USER_CONFIG_BUILD

#include <builder.h>

#include <assert.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wswitch"
#pragma clang diagnostic ignored "-Waddress-of-temporary"

enum language_t {
	LANGUAGE_C	= 0,
	LANGUAGE_CPP,

	LANGUAGE_COUNT,
};

enum config_t {
	CONFIG_DEBUG	= 0,
	CONFIG_RELEASE,

	CONFIG_COUNT,
};

std::string GetLanguageFileExtension( const language_t language ) {
	switch ( language ) {
		case LANGUAGE_C:	return "c";
		case LANGUAGE_CPP:	return "cpp";
	}

	assert( false && "Bad language_t passed.\n" );

	return NULL;
}

std::string GetConfigName( const config_t config ) {
	switch ( config ) {
		case CONFIG_DEBUG:		return "debug";
		case CONFIG_RELEASE:	return "release";
	}

	assert( false && "Bad config_t passed.\n" );

	return NULL;
}

static std::vector<std::string> GetAdditionalBuildArgs( const config_t config ) {
	switch ( config ) {
		case CONFIG_DEBUG:		return {};
		case CONFIG_RELEASE:	return { "--release" };
	}

	assert( false && "Bad config_t passed.\n" );

	return {};
}

BUILDER_CALLBACK void SetBuilderOptions( BuilderOptions *options, CommandLineArgs *args ) {
	std::string compilerName;

	if ( HasCommandLineArg( args, "--gcc" ) ) {
		options->compilerPath = "gcc";
		options->compilerVersion = "15.2.0";

		compilerName = "gcc";
	} else if ( HasCommandLineArg( args, "--msvc" ) ) {
		options->compilerPath = "cl";
		options->compilerVersion = "14.44.35207";

		compilerName = "msvc";
	} else {
		compilerName = "clang";
	}

	BuildConfig generator = {
		.name 				= "generator",
		.languageVersion	= LANGUAGE_VERSION_C99,
		.binaryName			= "hlml-generator",
		.binaryFolder		= "bin",
		//.sourceFiles		= { "code/**/*.c" },
		.sourceFiles = {
			"code/generator/main.c",
			"code/generator/stb_impl.c",
#if defined( _WIN64 )
			"code/generator/generator.win64.c",
#elif defined( __linux__ )
			"code/generator/generator.linux.c",
#endif
		},
		.additionalIncludes	= { "code/3rdparty/include" },
	};

#if defined( __linux__ )
	generator.additionalLibs.push_back( "m" );
	generator.ignoreWarnings.push_back( "-Wno-typedef-redefinition" );
#endif

	if ( HasCommandLineArg( args, "--release" ) ) {
		generator.binaryFolder += "/release";
	} else {
		generator.binaryFolder += "/debug";
	}

	AddBuildConfig( options, &generator );

	// setup visual studio solution now, add tests afterwards
	//options->generateSolution = true;
	options->solution = {
		.name		= "HLML",
		.path		= "visual_studio",
		.platforms	= { "x64" },
		.projects = {
			{
				.name			= "generator",
				.codeFolders	= { "code" },
				.configs = {
					{ GetConfigName( CONFIG_DEBUG ),   generator, GetAdditionalBuildArgs( CONFIG_DEBUG ),   { /* debugger arguments */ } },
					{ GetConfigName( CONFIG_RELEASE ), generator, GetAdditionalBuildArgs( CONFIG_RELEASE ), { /* debugger arguments */ } },
				},
			},
		},
	};

	options->solution.projects.push_back( {
		.name			= "tests",
		.codeFolders	= { "code/generated_files/tests" },
	} );

	VisualStudioProject *testsProject = &options->solution.projects.back();

	for ( int languageIndex = 0; languageIndex < LANGUAGE_COUNT; languageIndex++ ) {
		const language_t language = (language_t) languageIndex;
		const std::string languageFileExtension = GetLanguageFileExtension( language );

		BuildConfig testConfig = {
			.name				= "tests-" + languageFileExtension,
			.binaryName			= "hlml-tests-" + compilerName + "-" + languageFileExtension,
			.sourceFiles		= { "code/generated_files/tests/" + languageFileExtension + "/test_main." + languageFileExtension },
			.additionalIncludes	= { "code/3rdparty/include" },
#if defined( __linux__ )
			.additionalLibs		= { "m", "stdc++" },
#endif
		};

		if ( HasCommandLineArg( args, "--release" ) ) {
			testConfig.binaryFolder = "bin/release";
		} else {
			testConfig.binaryFolder = "bin/debug";
		}

		if ( HasCommandLineArg( args, "--gcc" ) ) {
#if !defined( __linux__ )
			testConfig.additionalCompilerArguments.push_back( "-Wa,-mbig-obj" );
#endif

			testConfig.additionalLinkerArguments.push_back( "-static" );
			testConfig.additionalLinkerArguments.push_back( "-static-libstdc++" );
			testConfig.additionalLinkerArguments.push_back( "-static-libgcc" );
		}

		AddBuildConfig( options, &testConfig );

		testsProject->configs.push_back( { GetConfigName( CONFIG_DEBUG ),   testConfig, GetAdditionalBuildArgs( CONFIG_DEBUG ),   { /* debugger args */ } } );
		testsProject->configs.push_back( { GetConfigName( CONFIG_RELEASE ), testConfig, GetAdditionalBuildArgs( CONFIG_RELEASE ), { /* debugger args */ } } );
	}
}

#pragma clang diagnostic push

#endif // BUILDER_DOING_USER_CONFIG_BUILD