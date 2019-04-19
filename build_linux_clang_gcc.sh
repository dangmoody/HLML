#!/bin/bash

# exit on first failure
set -e

compiler=$1	# can be either "clang++" or "g++"
config=$2	# can be either "debug" or "release"

source_files=code/generator/*.cpp

if [[ $compiler == clang* ]]; then
	options_std="-Xclang -flto-visibility-public-std"
else
	options_std=""
fi

options_compiler=${options_std}

if [[ $config = release ]]; then
	options_compiler="${options_compiler} -O3 -ffast-math"
fi

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

${compiler} ${options_compiler} -o build/${config}/hlml-gen.exe ${source_files} ${options_error} ${ignore_warnings}

echo ------- Done. -------
