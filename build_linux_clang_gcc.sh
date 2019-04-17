#!/bin/bash

# exit on first failure
set -e

compiler=$1

source_files=code/generator/*.cpp

# TODO(DM): separate compile options and ignore warnings between clang and gcc
options_error="-Wall -Wextra -Weverything -Wpedantic"
ignore_warnings="-Wno-c++98-compat-pedantic -Wno-covered-switch-default -Wno-newline-eof -Wno-reserved-id-macro -Wno-global-constructors -Wno-exit-time-destructors -Wno-padded"

$compiler -o hlml-gen.exe $source_files $options_error $ignore_warnings
