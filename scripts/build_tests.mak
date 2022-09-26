# pass configuration on command line!
# pass compiler on command line!

all: build

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

compiler_c =
compiler_cpp =
config =

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

hlml_tests_c_filename = hlml_tests_c
hlml_tests_c_source = ..\\code\\generated_files\\tests\\c\\test_main.c
hlml_tests_c_path = ..\\bin\\$(platform)\\$(config)\\tests\\$(compiler_c)\\$(hlml_tests_c_filename).exe

hlml_tests_cpp_filename = hlml_tests_cpp
hlml_tests_cpp_source = ..\\code\\generated_files\\tests\\cpp\\test_main.cpp
hlml_tests_cpp_path = ..\\bin\\$(platform)\\$(config)\\tests\\$(compiler_cpp)\\$(hlml_tests_cpp_filename).exe

# Bring in our make_build_dir, build_tests_c and build_tests_cpp functions
ifdef compiler
include build_tests_$(compiler).mak
endif

build: verify_args clean make_build_dir build_tests_c build_tests_cpp

clean:
ifneq ("$(wildcard $(hlml_tests_c_path))", "")
ifeq ($(platform), win64)
	@del $(hlml_tests_c_path)
else
	@rm -f $(hlml_tests_c_path)
endif
endif

ifneq ("$(wildcard $(hlml_tests_cpp_path))", "")
ifeq ($(platform), win64)
	@del $(hlml_tests_cpp_path)
else
	@rm -f $(hlml_tests_cpp_path)
endif
endif
	