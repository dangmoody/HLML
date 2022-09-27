# Intended to be called from a parent file, requires prior variable setup!

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
	$(MAKE) -f generator.mak config=$(config)
	$(MAKE) -f tests.mak compiler=clang config=$(config)
	$(MAKE) -f tests.mak compiler=msvc config=$(config)
	$(MAKE) -f tests.mak compiler=gcc config=$(config)