#!/bin/sh

# this file is only to recreate what would otherwise be happening on TeamCity
# when that gets setup this file will get removed

hlmlDir=$(dirname -- "$(readlink -f -- "$BASH_SOURCE")")

pushd ${hlmlDir}

# generator
~/builder/bin/builder build_generator.cpp --config=generator-debug

./bin/debug/hlml-generator

# clang C
~/builder/bin/builder build_tests_clang.cpp --config=tests-c-debug
./bin/debug/hlml-tests-clang-c

# clang CPP
~/builder/bin/builder build_tests_clang.cpp --config=tests-cpp-debug
./bin/debug/hlml-tests-clang-cpp

# GCC C
~/builder/bin/builder build_tests_gcc.cpp --config=tests-c-debug
./bin/debug/hlml-tests-gcc-c

# GCC CPP
~/builder/bin/builder build_tests_gcc.cpp --config=tests-cpp-debug
./bin/debug/hlml-tests-gcc-cpp

popd