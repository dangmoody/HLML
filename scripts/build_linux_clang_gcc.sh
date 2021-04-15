#!/bin/bash

# exit on first failure
set -e

compiler=$1				# can be either "clang" or "gcc"
config=$2				# can be either "debug" or "release"
language=$3				# can be either "C" or "C++"
output_file=$4			# name of the exe to build, should include ".exe"
source_files_path=$5	# path to source files to build, shouldn't include file names
source_files=$6			# file(s) to build, should include ".cpp", supports "*.cpp"

# determine whether to use C or C++ compiler based on cmd args
if [[ ${language} == C++ ]]; then
	if [[ ${compiler} == clang ]]; then
		compiler_proc="clang++"
	else
		compiler_proc="g++"
	fi
else
	if [[ ${compiler} == clang ]]; then
		compiler_proc="clang"
	else
		compiler_proc="gcc"
	fi
fi

#determine the folder name to use
if [[ ${compiler} == clang ]]; then
	compiler_folder_name="clang"
else
	compiler_folder_name="gcc"
fi

# make build folder if it doesn't already exist
if [ ! -d "bin/${config}" ]; then
	mkdir -p bin/${compiler_folder_name}/${config}
fi

if [[ ${language} == C++ ]]; then
	options_std="-std=c++14"
else
	options_std="-std=c99"
fi

# other language/compiler-specific settings
if [[ ${language} == C++ ]]; then
	if [[ ${compiler} == clang ]]; then
		options_clangpp="-Xclang -flto-visibility-public-std"
	else
		options_clangpp=""
	fi
else
	options_clangpp="-std=c99"

	if [[ "$OSTYPE" == "linux-gnu" ]]; then
		options_linker="-lm -lpthread"
	fi
fi

options_compiler="${options_clangpp}"

# config options
if [[ ${config} == release ]]; then
	options_compiler="${options_compiler} -O3 -ffast-math"	# enable optimisations
elif [[ ${config} == debug ]]; then
	options_compiler="${options_compiler} -g -D_DEBUG"		# generate debugging symbols
fi

# additional includes
options_compiler="${options_compiler} -Icode/3rdparty/include/ -D_CRT_SECURE_NO_WARNINGS"

# add -Weverything for clang
options_error="-Wall -Wextra"
if [[ ${compiler} == clang ]]; then
	options_error="${options_error} -Weverything -Wpedantic"
fi

# warnings to ignore
ignore_warnings="-Wno-missing-braces"

if [[ ${compiler} == clang ]]; then
	# clang-specific warnings to ignore
	if [[ ${language} == C++ ]]; then
		ignore_warnings="${ignore_warnings} -Wno-padded -Wno-unused-macros -Wno-format-nonliteral -Wno-old-style-cast -Wno-double-promotion -Wno-float-equal -Wno-zero-as-null-pointer-constant -Wno-int-to-void-pointer-cast"
		ignore_warnings="${ignore_warnings} -Wno-newline-eof -Wno-global-constructors -Wno-c++98-compat-pedantic -Wno-covered-switch-default -Wno-shadow-field-in-constructor -Wno-nested-anon-types -Wno-gnu-anonymous-struct -Wno-exit-time-destructors -Wno-reserved-id-macro"
	# else
	#	DM: ignore warning for Clang/C only here
	fi
else
	# GCC-specific warnings to ignore
	ignore_warnings="${ignore_warnings} -Wno-padded -Wno-unused-macros -Wno-format-nonliteral -Wno-float-equal -Wno-unused-variable -Wno-stringop-truncation"

	if [[ ${language} == C++ ]]; then
		ignore_warnings="${ignore_warnings} -Wno-old-style-cast"
	fi
fi

echo Compiler                  : ${compiler_proc}
echo Language                  : ${language}
echo Building source file\(s\) : ${source_files_path}${source_files}
echo Building with options     : ${options_compiler}
echo Enabled errors            : ${options_error}
echo Ignoring options          : ${ignore_warnings}
echo Linker settings           : ${options_linker}
echo ""

${compiler_proc} ${options_std} ${options_compiler} -o bin/${compiler_folder_name}/${config}/${output_file} ${source_files_path}${source_files} ${options_error} ${ignore_warnings} ${options_linker}
