#!/bin/bash

# exit when any command fails
set -e

source ./scripts/build_and_test.sh clang

source ./scripts/build_and_test.sh gcc

printf "\n"
printf "No errors were detected on any of the compilers.  Everything looks fine.\n"