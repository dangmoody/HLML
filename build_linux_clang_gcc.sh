#!/bin/bash

# exit on first failure
set -e

compiler=$1				# can be either "clang++" or "g++"
config=$2				# can be either "debug" or "release"
output_file=$3			# name of the exe to build, should include ".exe"
source_files_path=$4	# path to source files to build, shouldn't include "*.cpp"

#determine the folder name to use
if [[ $compiler == clang* ]]; then
	compiler_folder_name="clang"
else
	compiler_folder_name="gcc"
fi

# make build folder if it doesn't already exist
if [ ! -d "build/${config}" ]; then
	mkdir -p build/${compiler_folder_name}/${config}
fi

options_std="-std=c++14"

# clang requires extra weird c++ settings
if [[ $compiler == clang* ]]; then
	options_compiler="-Xclang -flto-visibility-public-std"
fi

# enable optimisations for release
if [[ $config = release ]]; then
	options_compiler="${options_compiler} -O3 -ffast-math"
fi

# additional includes
options_compiler="${options_compiler} -Icode/3rdparty/include/ -D_CRT_SECURE_NO_WARNINGS"

# add -Weverything for clang
options_error="-Wall -Wextra -Wpedantic"
if [[ $compiler == clang* ]]; then
	options_error="${options_error} -Weverything"
fi

# warnings to ignore
ignore_warnings="-Wno-global-constructors -Wno-padded -Wno-unused-macros -Wno-format-nonliteral -Wno-old-style-cast -Wno-double-promotion -Wno-float-equal -Wno-zero-as-null-pointer-constant"

# clang-specific warnings to ignore
if [[ $compiler == clang* ]]; then
	ignore_warnings="${ignore_warnings} -Wno-c++98-compat-pedantic -Wno-covered-switch-default -Wno-shadow-field-in-constructor -Wno-nested-anon-types -Wno-gnu-anonymous-struct -Wno-exit-time-destructors -Wno-reserved-id-macro"
fi

echo Building for $compiler

echo Building with options : ${options_compiler}
echo Enabled errors        : ${options_error}
echo Ignoring options      : ${ignore_warnings}
echo ""

${compiler} ${options_std} ${options_compiler} -o build/${compiler_folder_name}/${config}/${output_file} ${source_files_path}/*.cpp ${options_error} ${ignore_warnings}
