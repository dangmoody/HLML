#!/bin/bash

# exit on first failure
set -e

compiler=$1
config=$2

source_files=code/generator/*.cpp

# TODO(DM): separate compile options and ignore warnings between clang and gcc
# TODO(DM): add release compiler options (-O3, -ffast-math, etc.)
options_compiler="-Xclang -flto-visibility-public-std"
options_error="-Wall -Wextra -Weverything -Wpedantic"
ignore_warnings="-Wno-c++98-compat-pedantic -Wno-covered-switch-default -Wno-newline-eof -Wno-reserved-id-macro -Wno-global-constructors -Wno-exit-time-destructors -Wno-padded"

$compiler $options_compiler -o build/$config/hlml-gen.exe $source_files $options_error $ignore_warnings
