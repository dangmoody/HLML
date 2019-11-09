#!/bin/bash

# exit on first failure
set -e

compiler=$1	# can be either "clang" or "gcc"
config=$2	# can be either "debug" or "release"

# determine the folder name to use
if [[ ${compiler} == clang ]]; then
	compiler_folder_name="clang"
elif [[ ${compiler} == gcc ]]; then
	compiler_folder_name="gcc"
else
	echo ERROR: Unsupported compiler: "${compiler}".  Can be either: clang or gcc
fi

# make build folder if it doesn't already exist
if [ ! -d "build/${config}" ]; then
	mkdir -p build/${compiler_folder_name}/${config}
fi

# copy doxygen
cp -rf ./doxygen ./build/${compiler_folder_name}/${config}

# start building!
echo ------- Building generator -------
source_files="code/generator/"
source build_linux_clang_gcc.sh ${compiler} ${config} C++ hlml-gen.exe ${source_files} *.cpp
echo ------- Done -------
echo ""

echo ------- Running generator -------
build/${compiler_folder_name}/${config}/hlml-gen.exe
echo ------- Done -------
echo ""

echo ------- Building C tests -------
source_files="code/tests/c/"
source build_linux_clang_gcc.sh ${compiler} ${config} C hlml-gen-tests-c.exe ${source_files} main.c
echo ------- Done -------
echo ""

echo ------- Running C tests -------
build/${compiler_folder_name}/${config}/hlml-gen-tests-c.exe -c --time-unit=us
echo ------- C Tests Finished -------
echo ""

echo ------- Building C++ tests -------
source_files="code/tests/cpp/"
source build_linux_clang_gcc.sh ${compiler} ${config} C++ hlml-gen-tests-cpp.exe ${source_files} main.cpp
echo ------- Done -------
echo ""

echo ------- Running C++ tests -------
build/${compiler_folder_name}/${config}/hlml-gen-tests-cpp.exe -c --time-unit=us
echo ------- C++ Tests Finished -------
echo ""
