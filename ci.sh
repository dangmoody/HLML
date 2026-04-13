#!/bin/sh

set -e

# this file is only to recreate what would otherwise be happening on TeamCity
# when that gets setup this file will get removed

hlmlDir=$(dirname -- "$(readlink -f -- "$BASH_SOURCE")")

pushd ${hlmlDir}

# generator
~/builder/bin/builder build.cpp --config=generator

./bin/debug/hlml-generator

# clang C
~/builder/bin/builder build.cpp --config=tests-c
./bin/debug/hlml-tests-clang-c

# clang CPP
~/builder/bin/builder build.cpp --config=tests-cpp
./bin/debug/hlml-tests-clang-cpp

# GCC C
~/builder/bin/builder build.cpp --gcc --config=tests-c
./bin/debug/hlml-tests-gcc-c

# GCC CPP
~/builder/bin/builder build.cpp --gcc --config=tests-cpp
./bin/debug/hlml-tests-gcc-cpp

echo All tests done! Success!

popd