#!/bin/bash

# exit when any command fails
set -e

source ./scripts/build_tests.sh --compiler g++ $@
