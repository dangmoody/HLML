# pass configuration on command line!
# pass compiler on command line!

all: build run

# Determine OS
useWindowsSyntax = false
platform =
uname_s = $(shell uname -s)
ifeq ($(findstring NT,$(uname_s)),NT)
platform = win64
ifeq ($(uname_s),Linux)
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

ifdef compiler
include $(makefile_dir)/include_$(compiler)_settings.mak
endif

verify_args:
ifndef compiler
	$(error "compiler" argument was not specified. eg. "compiler=clang")
else ifeq ($(compiler), clang)
else ifeq ($(compiler), gcc)
else ifeq ($(compiler), msvc)
else
	$(error "compiler" argument can only equal "clang", "gcc" or "msvc")
endif
ifndef config
	$(error "config" argument was not specified. eg. "config=release")
else ifeq ($(config), debug)
else ifeq ($(config), release)
else
	$(error "config" argument can only equal "debug" or "release")
endif

executable_name_c = hlml_tests_c
source_files_c = $(hlml_root_dir)/code/generated_files/tests/c/test_main.c
hlml_tests_c_path = $(hlml_root_dir)/bin/$(platform)/$(config)/tests/$(compiler_c)/$(executable_name_c).exe

executable_name_cpp = hlml_tests_cpp
source_files_cpp = $(hlml_root_dir)/code/generated_files/tests/cpp/test_main.cpp
hlml_tests_cpp_path = $(hlml_root_dir)/bin/$(platform)/$(config)/tests/$(compiler_cpp)/$(executable_name_cpp).exe

build_dir_c = $(hlml_root_dir)/bin/$(platform)/$(config)/tests/$(compiler_c)
build_dir_cpp = $(hlml_root_dir)/bin/$(platform)/$(config)/tests/$(compiler_cpp)

# Bring in our make_build_dir, build_tests_c and build_tests_cpp functions
ifdef compiler
include $(makefile_dir)/build_$(compiler).mak
endif

build: verify_args clean make_build_dir build_c build_cpp

clean:
ifneq ("$(wildcard $(hlml_tests_c_path))", "")
ifeq ($(useWindowsSyntax), true)
	del $(subst /,\\,$(hlml_tests_c_path))
else
	@rm -f $(hlml_tests_c_path)
endif
endif

ifneq ("$(wildcard $(hlml_tests_cpp_path))", "")
ifeq ($(useWindowsSyntax), true)
	del $(subst /,\\,$(hlml_tests_cpp_path))
else
	@rm -f $(hlml_tests_cpp_path)
endif
endif

run:
	@echo "Running tests for $(compiler_c) (C)"
	$(hlml_tests_c_path)
	@echo "Running tests for $(compiler_cpp) (C++)"
	$(hlml_tests_cpp_path)