# pass configuration on command line!

mkfile_path = $(firstword $(MAKEFILE_LIST))
makefile_dir = $(patsubst %/,%,$(dir $(mkfile_path)))
hlml_root_dir = $(subst /,\\,$(makefile_dir)\..)

all: build run

verify_args:
ifndef config
	$(error "config" argument was not specified. eg. "config=release")
else ifeq ($(config), debug)
else ifeq ($(config), release)
else
	$(error "config" argument can only equal "debug" or "release")
endif

source_files_c = $(hlml_root_dir)\\code\\generator\\main.c $(hlml_root_dir)\\code\\generator\\generator.win64.c $(hlml_root_dir)\\code\\generator\\stb_impl.c
executable_name_c = generator

build_dir_c = $(hlml_root_dir)\\bin\\win64\\$(config)
build_dir_cpp = $(hlml_root_dir)\\bin\\win64\\$(config)

include $(makefile_dir)\\include_clang_settings.mak
include $(makefile_dir)\\build_clang.mak

build: verify_args make_build_dir build_c

run:
	$(build_dir_c)\\$(executable_name_c).exe