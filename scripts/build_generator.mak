# pass configuration on command line!

all: build

hello:
	@echo "Hello, World"

check_args:
ifndef config
	$(error "config" argument was not specified. eg. "config=release")
else ifeq ($(config), debug)
else ifeq ($(config), release)
else
	$(error "config" argument can only equal "debug" or "release")
endif

warning_levels = -Werror -Wall -Wextra -Weverything -Wpedantic
ignore_warnings = -Wno-newline-eof -Wno-microsoft-anon-tag -Wno-double-promotion -Wno-bad-function-cast -Wno-declaration-after-statement -Wno-missing-braces
includes = -I..\\code\\3rdparty\\include\\

symbols =
defines = -D_CRT_SECURE_NO_WARNINGS
optimisation =

ifeq ($(config), debug)
symbols += -g
defines += -D_DEBUG
else ifeq ($(config), release)
defines += -DNDEBUG
optimisation += -O3
endif

source_files=..\\code\\generator\\main.c ..\\code\\generator\\generator.win64.c ..\\code\\generator\\stb_impl.c
build_dir=..\\bin\\win64\\$(config)

build: check_args
	clang -o $(build_dir)\\generator.exe -std=c99 $(symbols) $(optimisation) $(source_files) $(warning_levels) $(ignore_warnings) $(includes) $(defines)