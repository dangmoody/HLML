#ifdef BUILDER_DOING_USER_CONFIG_BUILD

#include <builder.h>

#include "build_configs.cpp"

BUILDER_CALLBACK void SetBuilderOptions( BuilderOptions *options ) {
	GetBuildConfigs( options, "clang" );
}

#endif // BUILDER_DOING_USER_CONFIG_BUILD