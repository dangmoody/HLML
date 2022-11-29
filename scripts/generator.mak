# pass configuration on command line!

# Determine OS
useWindowsSyntax = false
platform =
uname_s = $(shell uname -s)
ifeq ($(findstring NT,$(uname_s)),NT)
platform = win64
else ifeq ($(uname_s),Linux)
platform = linux
else ifeq ($(uname_s),Darwin)
platform = macos
endif # (platform, Linux)
else # ($(findstring NT,$(uname_s)),NT)
ifeq ($(OS),Windows_NT)
platform = win64
useWindowsSyntax = true
endif # ($(OS), Windows_NT)
endif # ($(findstring NT,$(uname_s)),NT)

mkfile_path = $(firstword $(MAKEFILE_LIST)))
makefile_dir = $(patsubst %/,%,$(dir $(mkfile_path)))

# get the root directory of the project
ifeq ($(platform), win64)
hlml_root_dir = $(subst /,\\,$(makefile_dir)\..)
else
hlml_root_dir = $(makefile_dir)/..
endif

all: build run

verify_args:
ifndef config
	$(error "config" argument was not specified. eg. "config=release")
else ifeq ($(config), debug)
else ifeq ($(config), release)
else
	$(error "config" argument can only equal "debug" or "release")
endif

source_files_c = $(hlml_root_dir)/code/generator/main.c $(hlml_root_dir)/code/generator/generator.$(platform).c $(hlml_root_dir)/code/generator/stb_impl.c
executable_name_c = generator

build_dir_c = $(hlml_root_dir)/bin/$(platform)/$(config)
build_dir_cpp = $(hlml_root_dir)/bin/$(platform)/$(config)

include $(makefile_dir)/include_clang_settings.mak
include $(makefile_dir)/build_clang.mak

build: verify_args make_build_dir build_c

run:
	$(build_dir_c)/$(executable_name_c).exe