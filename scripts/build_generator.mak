# pass configuration on command line!

all: build

verify_args:
ifndef config
	$(error "config" argument was not specified. eg. "config=release")
else ifeq ($(config), debug)
else ifeq ($(config), release)
else
	$(error "config" argument can only equal "debug" or "release")
endif

include include_$(compiler)_settings.mak

source_files=..\\code\\generator\\main.c ..\\code\\generator\\generator.win64.c ..\\code\\generator\\stb_impl.c
build_dir=..\\bin\\win64\\$(config)

build: verify_args
	clang -o $(build_dir)\\generator.exe -std=c99 $(symbols) $(optimisation) $(source_files) $(warning_levels) $(ignore_warnings) $(includes) $(defines)