#!/bin/bash

# exit when any command fails
set -e

# must be either:
# 	clang
# 	gcc
compiler=$1

compiler_c=""
compiler_cpp=""

if [[ "${compiler}" == "clang" ]]; then
	compiler_c=clang
	compiler_cpp=clang++
elif [[ "${compiler}" == "gcc" ]]; then
	compiler_c=gcc
	compiler_cpp=g++
else
	printf "ERROR: Compiler was not set.\n"
	exit 1
fi

# cleanup old files
if [[ -f ./bin/linux/debug/tests/${compiler_c}/hlml_tests_c.exe ]];
then
	rm ./bin/linux/debug/tests/${compiler_c}/hlml_tests_c.exe
fi

if [[ -f ./bin/linux/debug/tests/${compiler_cpp}/hlml_tests_cpp.exe ]];
then
	rm ./bin/linux/debug/tests/${compiler_cpp}/hlml_tests_cpp.exe
fi


# generate API files
printf "\n"
printf "Running Generator...\n"
source ./scripts/build_generator.sh --config debug
./bin/linux/debug/generator.exe
printf "\n"


# C99 tests
printf "Compiling C99 tests...\n"
source ./scripts/build_${compiler_c}.sh --output hlml_tests_c.exe --config debug --source code/generated_files/tests/c/test_main.c
printf "\n"
printf "Running C99 tests...\n"
./bin/linux/debug/tests/${compiler_c}/hlml_tests_c.exe $@
printf "\n"


# C++ tests
printf "Compiling C++ tests...\n"
source ./scripts/build_${compiler_cpp}.sh --output hlml_tests_cpp.exe --config debug --source code/generated_files/tests/cpp/test_main.cpp
printf "\n"
printf "Running C++ tests...\n"
./bin/linux/debug/tests/${compiler_cpp}/hlml_tests_cpp.exe $@
printf "\n"
