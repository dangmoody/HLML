#!/bin/sh

set -e

# this file is only to recreate what would otherwise be happening on TeamCity
# when that gets setup this file will get removed

hlmlDir=$(dirname -- "$(readlink -f -- "$BASH_SOURCE")")

pushd ${hlmlDir}

# generator
./build --config=generator

./bin/debug/hlml-generator

# clang C
./build --config=tests-c
./bin/debug/hlml-tests-clang-c

# clang CPP
./build --config=tests-cpp
./bin/debug/hlml-tests-clang-cpp

# GCC C
./build --gcc --config=tests-c
./bin/debug/hlml-tests-gcc-c

# GCC CPP
./build --gcc --config=tests-cpp
./bin/debug/hlml-tests-gcc-cpp

echo All tests done! Success!

popd