# Intended to be called from build_tests.mak!

include $(hlml_root_dir)/scripts/include_clang_settings.mak

compiler_c = gcc
compiler_cpp = g++

additional_flags_cpp =

ifeq ($(platform), win64)
additional_flags_cpp += -Wa,-mbig-obj
endif

warning_levels = -Werror -Wall -Wextra -Wpedantic
ignore_warnings = -Wno-newline-eof -Wno-missing-braces -Wno-double-promotion -Wno-c++98-compat