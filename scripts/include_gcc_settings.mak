# Intended to be called from build_tests.mak!

include $(hlml_root_dir)\\scripts\\include_clang_settings.mak

compiler_c = gcc
compiler_cpp = g++

additional_flags_cpp = -Wa,-mbig-obj