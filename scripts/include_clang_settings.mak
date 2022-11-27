# Intended to be called from build_tests.mak!

symbols =
defines = -D_CRT_SECURE_NO_WARNINGS
optimisation =
libs =

ifeq ($(config), debug)
symbols = -g
defines += -D_DEBUG
else ifeq ($(config), release)
optimisation = -O3
defines += -DNDEBUG
endif

warning_levels = -Werror -Wall -Wextra -Weverything -Wpedantic
ignore_warnings = -Wno-newline-eof -Wno-missing-braces -Wno-double-promotion -Wno-declaration-after-statement -Wno-old-style-cast -Wno-c++98-compat -Wno-bad-function-cast
includes = -I$(hlml_root_dir)/code/3rdparty/include/

ifeq ($(platform), linux)
ignore_warnings += -Wno-typedef-redefinition -Wno-padded -Wno-unused-macros -Wno-reserved-identifier -Wno-disabled-macro-expansion
libs += -lm
endif

compiler_c = clang
compiler_cpp = clang++