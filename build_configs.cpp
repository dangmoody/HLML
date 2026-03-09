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
		case LANGUAGE_C: return "c";
		case LANGUAGE_CPP: return "cpp";
	}

	assert( false && "Bad language passed.\n" );

	return NULL;
}

std::string GetConfigName( const config_t config ) {
	switch ( config ) {
		case CONFIG_DEBUG:		return "debug";
		case CONFIG_RELEASE:	return "release";
	}

	assert( false && "Bad config passed.\n" );

	return NULL;
}

static void GetBuildConfigs( BuilderOptions *options, const std::string &compilerName ) {
	BuildConfig generatorCommon = {
		.name 				= "generator",
		.languageVersion	= LANGUAGE_VERSION_C99,
		.binaryName			= "generator",
		.binaryFolder		= "bin",
		//.sourceFiles		= { "code/**/*.c" },
		.sourceFiles		= { "code/generator/main.c", "code/generator/stb_impl.c", "code/generator/generator.win64.c" },
		.additionalIncludes	= { "code/3rdparty/include" },
	};

	BuildConfig generatorDebug = generatorCommon;
	generatorDebug.name += "-debug";
	generatorDebug.binaryFolder += "/debug";
	AddBuildConfig( options, &generatorDebug );

	BuildConfig generatorRelease = generatorCommon;
	generatorRelease.name += "-release";
	generatorRelease.binaryFolder += "/release";
	AddBuildConfig( options, &generatorRelease );

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
				.fileExtensions = { "c", "cpp", "h", "hpp", "inl" },
				.configs = {
					{ "debug",   generatorDebug,   /* debugger arguments */ },
					{ "release", generatorRelease, /* debugger arguments */ },
				},
			},
		},
	};

	options->solution.projects.push_back( {
		.name			= "tests",
		.codeFolders	= { "code/generated_files/tests" },
		.fileExtensions = { "c", "cpp", "h", "hpp", "inl" },
	} );

	VisualStudioProject *testsProject = &options->solution.projects.back();

	for ( int languageIndex = 0; languageIndex < LANGUAGE_COUNT; languageIndex++ ) {
		const language_t language = (language_t) languageIndex;
		const std::string languageFileExtension = GetLanguageFileExtension( language );

		for ( int configIndex = 0; configIndex < CONFIG_COUNT; configIndex++ ) {
			const config_t config = (config_t) configIndex;
			const std::string configName = GetConfigName( config );

			BuildConfig testConfig = {
				.name				= "tests-" + languageFileExtension + "-" + configName,
				.binaryName			= "hlml-tests-" + compilerName + "-" + languageFileExtension,
				.binaryFolder		= "bin/" + configName,
				.sourceFiles		= { "code/generated_files/tests/" + languageFileExtension + "/test_main." + languageFileExtension },
				.additionalIncludes	= { "code/3rdparty/include" },
			};

			// DM!!! ugly hack but will do for now
			if ( compilerName == "gcc" ) {
				testConfig.additionalLibs.push_back( "stdc++" );

				testConfig.additionalCompilerArguments.push_back( "-Wa,-mbig-obj" );

				testConfig.additionalLinkerArguments.push_back( "-static" );
				testConfig.additionalLinkerArguments.push_back( "-static-libstdc++" );
				testConfig.additionalLinkerArguments.push_back( "-static-libgcc" );
			}

			AddBuildConfig( options, &testConfig );

			testsProject->configs.push_back( { configName, testConfig, { /* debugger arguments */ } } );
		}
	}
}

#pragma clang diagnostic push

#endif // BUILDER_DOING_USER_CONFIG_BUILD