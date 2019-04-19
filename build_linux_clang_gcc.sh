#!/bin/bash

# exit on first failure
set -e

compiler=$1	# can be either "clang++" or "g++"
config=$2	# can be either "debug" or "release"

# make build folder if it doesn't already exist
if [ ! -d "build" ]; then
	mkdir -p build/${config}
fi

source_files=code/generator/*.cpp

options_std="-std=c++11"

# clang requires extra weird c++ settings
if [[ $compiler == clang* ]]; then
	options_compiler="-Xclang -flto-visibility-public-std"
fi

# enable optimisations for release
if [[ $config = release ]]; then
	options_compiler="${options_compiler} -O3 -ffast-math"
fi

# add -Weverything for clang
options_error="-Wall -Wextra -Wpedantic"
if [[ $compiler == clang* ]]; then
	options_error="${options_error} -Weverything"
fi

ignore_warnings="-Wno-c++98-compat-pedantic -Wno-covered-switch-default -Wno-newline-eof -Wno-reserved-id-macro -Wno-global-constructors -Wno-exit-time-destructors -Wno-padded -Wno-unused-macros"

echo ------- Building for $compiler -------

echo Building with options : ${options_compiler}
echo Enabled errors        : ${options_error}
echo Ignoring options      : ${ignore_warnings}
echo ""

${compiler} ${options_std} ${options_compiler} -o build/${config}/hlml-gen.exe ${source_files} ${options_error} ${ignore_warnings}

echo ------- Done. -------
