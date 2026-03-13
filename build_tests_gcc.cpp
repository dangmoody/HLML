#ifdef BUILDER_DOING_USER_CONFIG_BUILD

#include <builder.h>

#include "build_configs.cpp"

BUILDER_CALLBACK void SetBuilderOptions( BuilderOptions *options ) {
	options->compilerPath = "gcc";
	//options->compilerVersion = "15.2.0";

	GetBuildConfigs( options, "gcc" );
}

#endif // BUILDER_DOING_USER_CONFIG_BUILD