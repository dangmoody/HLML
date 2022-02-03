#!/bin/bash

# exit when any command fails
set -e

source ./scripts/build_and_test_clang.sh

source ./scripts/build_and_test_gcc.sh

printf "\n"
printf "No errors were detected on any of the compilers.  Everything looks fine.\n"