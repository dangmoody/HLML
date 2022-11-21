# Intended to be called from a parent file, requires prior variable setup!

# Determine OS
platform =
ifeq ($(OS), Windows_NT)
platform = win64
else
uname_s = $(shell uname -s)
ifeq ($(uname_s),Linux)
platform = linux
else ifeq ($(uname_s),Darwin)
platform = macos
endif
endif

mkfile_path = $(firstword $(MAKEFILE_LIST)))
makefile_dir = $(patsubst %/,%,$(dir $(mkfile_path)))

# get the root directory of the project
ifeq ($(platform), win64)
hlml_root_dir = $(subst /,\\,$(makefile_dir)\..)
else
hlml_root_dir = $(makefile_dir)/..
endif

all: build_and_test_all

verify_args:
ifndef config
	$(error "config" argument was not specified. eg. "config=release")
else ifeq ($(config), debug)
else ifeq ($(config), release)
else
	$(error "config" argument can only equal "debug" or "release")
endif

build_and_test_all: verify_args
	$(MAKE) -f $(makefile_dir)/generator.mak config=$(config)
	$(MAKE) -f $(makefile_dir)/tests.mak compiler=clang config=$(config)
	$(MAKE) -f $(makefile_dir)/tests.mak compiler=gcc config=$(config)
ifeq ($(platform), win64)
	$(MAKE) -f $(makefile_dir)/tests.mak compiler=msvc config=$(config)
endif