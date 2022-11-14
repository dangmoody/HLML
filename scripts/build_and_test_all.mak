# Intended to be called from a parent file, requires prior variable setup!

mkfile_path = $(firstword $(MAKEFILE_LIST)))
makefile_dir = $(patsubst %/,%,$(dir $(mkfile_path)))
hlml_root_dir = $(subst /,\\,$(makefile_dir)\..)

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
	$(MAKE) -f $(makefile_dir)generator.mak config=$(config)
	$(MAKE) -f $(makefile_dir)tests.mak compiler=clang config=$(config)
	$(MAKE) -f $(makefile_dir)tests.mak compiler=gcc config=$(config)
	$(MAKE) -f $(makefile_dir)tests.mak compiler=msvc config=$(config)