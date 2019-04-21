#!/bin/bash

# exit on first failure
set -e

compiler=$1	# can be either "clang++" or "g++"
config=$2	# can be either "debug" or "release"

echo ------- Building generator -------
source_files_path="code/generator"
source build_linux_clang_gcc.sh ${compiler} ${config} hlml-gen.exe ${source_files_path}
echo ------- Done -------
echo ""

echo ------- Running generator -------
build/${config}/hlml-gen.exe
echo ------- Done -------
echo ""

echo ------- Building tests -------
source_files_path="code/tests"
source build_linux_clang_gcc.sh ${compiler} ${config} hlml-gen-tests.exe ${source_files_path}
echo ------- Done -------
echo ""

echo ------- Running tests -------
build/${config}/hlml-gen-tests.exe -c
echo ------- Done -------
echo ""
