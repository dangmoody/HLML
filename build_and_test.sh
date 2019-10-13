#!/bin/bash

# exit on first failure
set -e

compiler=$1	# can be either "clang++" or "g++"
config=$2	# can be either "debug" or "release"

# determine the folder name to use
if [[ $compiler == clang* ]]; then
	compiler_folder_name="clang"
else
	compiler_folder_name="gcc"
fi

# make build folder if it doesn't already exist
if [ ! -d "build/${config}" ]; then
	mkdir -p build/${compiler_folder_name}/${config}
fi

# copy doxygen
cp -rf ./doxygen ./build/${compiler_folder_name}/${config}

# start building!
echo ------- Building generator -------
source_files_path="code/generator"
source build_linux_clang_gcc.sh ${compiler} ${config} hlml-gen.exe ${source_files_path}
echo ------- Done -------
echo ""

echo ------- Running generator -------
build/${compiler_folder_name}/${config}/hlml-gen.exe
echo ------- Done -------
echo ""

echo ------- Building tests -------
source_files_path="code/tests"
source build_linux_clang_gcc.sh ${compiler} ${config} hlml-gen-tests.exe ${source_files_path}
echo ------- Done -------
echo ""

echo ------- Running tests -------
build/${compiler_folder_name}/${config}/hlml-gen-tests.exe -c --time-unit=us
echo ------- Done -------
echo ""
