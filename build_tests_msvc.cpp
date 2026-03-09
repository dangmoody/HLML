#ifdef BUILDER_DOING_USER_CONFIG_BUILD

#include <builder.h>

#include "build_configs.cpp"

BUILDER_CALLBACK void SetBuilderOptions( BuilderOptions *options ) {
	options->compilerPath = "cl";
	options->compilerVersion = "14.44.35207";

	GetBuildConfigs( options, "msvc" );
}

#endif // BUILDER_DOING_USER_CONFIG_BUILD