#!/bin/bash

# exit when any command fails
set -e

# if "debug" will enable debugging symbols in the binary and disable optimisations
# if "release" will enable optimisations and disable 
g_config=""

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
	printf "Usage: %s --config [debug|release].\n" ${0}
	printf "\n"
	printf "Arguments:\n"
	printf "    [-h|--help] (optional).\n"
	printf "        Shows this help and then exits.\n"
	printf "\n"
	printf "    --config [debug|release] (required).\n"
	printf "        The config you want to build in.  MUST be one of the options shown.\n"
	printf "\n"

	exit ${exit_code}
}

# get cmd line args
while [ ! -z "$1" ]; do
	if [[ "$1" == "-h" ]] || [[ "$1" == "--help" ]]; then
		exit_and_show_usage 0
	elif [[ "$1" == "--config" ]]; then
		shift
		g_config=$1
	else
		printf "ERROR: Bad argument given.\n"
		exit_and_show_usage 1
	fi
	shift
done

if [[ "${g_config}" != "debug" ]] && [[ "${g_config}" != "release" ]]; then
	printf "ERROR: --config argument wasn't recognised.\n"
	exit_and_show_usage 1
fi


#
# now do the actual building
#

g_bin_dir=bin/${g_os_name}/${g_config}

# create build folder if it doesnt exist
mkdir -p ${g_bin_dir}

warning_level="-Wall -Wextra -Werror -Wpedantic -Weverything"

ignore_warnings="-Wno-newline-eof -Wno-typedef-redefinition -Wno-double-promotion -Wno-padded -Wno-format-nonliteral -Wno-bad-function-cast -Wno-reserved-macro-identifier"

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

source_files="code/generator/main.c code/generator/generator.linux.c code/generator/stb_impl.c"

defines=-D_CRT_SECURE_NO_WARNINGS

includes=-Icode/3rdparty/include

libs="-lrt -lm"

echo clang -std=c99 -o ${g_bin_dir}/generator.exe ${symbols} ${source_files} ${optimisations} ${defines} ${includes} -lrt ${warning_level} ${ignore_warnings}
clang -std=c99 -o ${g_bin_dir}/generator.exe ${symbols} ${source_files} ${optimisations} ${defines} ${includes} ${libs} ${warning_level} ${ignore_warnings}