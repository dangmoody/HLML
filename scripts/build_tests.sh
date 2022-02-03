#!/bin/bash

# exit when any command fails
set -e

# .exe filename
g_output=""

# if set to "clang" or "gcc" builds the C examples
# if set to "clang++" or "g++" builds the C++ example
g_compiler=""

# if "debug" will enable debugging symbols in the binary and disable optimisations
# if "release" will enable optimisations and disable 
g_config=""

# source files to build
# must always be last in the arguments
g_source_files=""

# get os name
#echo OS IS: ${OSTYPE}
g_os_name=""
if [[ ${OSTYPE} == "linux-gnu" ]]; then
	g_os_name="linux"
elif [[ ${OSTYPE} == darwin* ]]; then
	g_os_name="macos"
elif [[ ${OSTYPE} == "win32" ]]; then
	g_os_name="win64"
elif [[ ${OSTYPE} == "msys" ]]; then
	g_os_name="win64"
elif [[ ${OSTYPE} == "cygwin" ]]; then
	g_os_name="win64"
fi

exit_and_show_usage () {
	exit_code=${1}

	printf "\n"
	printf "Usage: %s --output <filename> --compiler [clang|clang++|gcc|g++] --config [debug|release] --source [source files].\n" ${0}
	printf "\n"
	printf "Arguments:\n"
	printf "    [-h|--help] (optional).\n"
	printf "        Shows this help and then exits.\n"
	printf "\n"
	printf "    --output <filename> (required).\n"
	printf "        The name of the .exe\n"
	printf "\n"
	printf "    --compiler [clang|clang++|gcc|g++] (required).\n"
	printf "        Which compiler you want to build with.  MUST be one of the options shown.\n"
	printf "\n"
	printf "    --config [debug|release] (required).\n"
	printf "        The config you want to build in.  MUST be one of the options shown.\n"
	printf "\n"
	printf "    --source [source files] (required).\n"
	printf "        Source files to build.  MUST be last in the argument list.\n"
	printf "\n"

	exit ${exit_code}
}

# get cmd line args
while [ ! -z "$1" ]; do
	if [[ "$1" == "-h" ]] || [[ "$1" == "--help" ]]; then
		exit_and_show_usage 0
	elif [[ "$1" == "--output" ]]; then
		shift
		g_output=$1
	elif [[ "$1" == "--compiler" ]]; then
		shift
		g_compiler=$1
	elif [[ "$1" == "--config" ]]; then
		shift
		g_config=$1
	elif [[ "$1" == "--source" ]]; then
		shift
		g_source_files=${@:1}
	else
		printf "ERROR: Bad argument given.\n"
		exit_and_show_usage 1
	fi
	shift
done

# validate cmd line args
if [[ "${g_output}" == "" ]]; then
	printf "ERROR: --output argument not set.\n"
	exit_and_show_usage 1
fi

if [[ "${g_compiler}" != "clang" ]] && [[ "${g_compiler}" != "clang++" ]] && [[ "${g_compiler}" != "gcc" ]] && [[ "${g_compiler}" != "g++" ]]; then
	printf "ERROR: --compiler argument wasn't recognised.\n"
	exit_and_show_usage 1
fi

if [[ "${g_config}" != "debug" ]] && [[ "${g_config}" != "release" ]]; then
	printf "ERROR: --config argument wasn't recognised.\n"
	exit_and_show_usage 1
fi

if [[ "${g_source_files}" == "" ]]; then
	printf "ERROR: --source argument not be set.\n"
	exit_and_show_usage 1
fi


#
# now do the actual building
#

g_bin_dir=bin/${g_os_name}/${g_config}/tests/${g_compiler}

# create build folder if it doesnt exist
mkdir -p ${g_bin_dir}

if [[ "${g_compiler}" == clang* ]]
then
	warning_level="-Wall -Wextra -Werror -Wpedantic -Weverything"
else
	warning_level="-Wall -Wextra -Werror"
fi

ignore_warnings="-Wno-missing-braces -Wno-reserved-identifier -Wno-double-promotion -Wno-unused-macros"

# C++-specific warnings to ignore
if [[ "${g_compiler}" == *++* ]]; then
	ignore_warnings="${ignore_warnings} -Wno-c++98-compat -Wno-old-style-cast"
fi

# add warnings specifically for clang
if [[ "${g_compiler}" == clang* ]]; then
	ignore_warnings="${ignore_warnings} -Wno-newline-eof"
fi

# add warnings specifically for mac
if [[ "${g_os_name}" == "macos" ]]; then
	ignore_warnings="${ignore_warnings} -Wno-poison-system-directories"
fi

if [[ "${g_config}" == debug ]]
then
	symbols=-g
else
	symbols=""
fi

if [[ "${g_config}" == release ]]
then
	optimisations=-O3 -ffast-math
else
	optimisations=""
fi

if [[ "${g_compiler}" == *++* ]]
then
	std=-std=c++11
else
	std=-std=c99
fi

defines=-D_CRT_SECURE_NO_WARNINGS

includes="-Icode/3rdparty/include"

linker_options_passthrough=""

libs="-ldl -lpthread -lm"

# dont add --export-dynamic if on mac os
# if [[ "${g_os_name}" != "macos" ]]; then
# 	linker_options_passthrough="-Wl,--export-dynamic"
# fi

echo ${g_compiler} ${std} -o ${g_bin_dir}/${g_output} ${symbols} ${optimisations} ${defines} ${g_source_files} ${includes} ${warning_level} ${ignore_warnings} ${libs} ${linker_options_passthrough}
${g_compiler} ${std} -o ${g_bin_dir}/${g_output} ${symbols} ${optimisations} ${defines} ${g_source_files} ${includes} ${warning_level} ${ignore_warnings} ${libs} ${linker_options_passthrough}