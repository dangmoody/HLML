# Intended to be called from a parent file, requires prior variable setup!

make_build_dir:
ifeq ("$(wildcard $(build_dir_cpp))", "")
	mkdir $(build_dir_cpp)
endif
ifeq ("$(wildcard $(build_dir_c))", "")
# Don't mkdir twice if build dirs match
ifneq ("$(build_dir_c))", "$(build_dir_cpp)")
	mkdir $(build_dir_c)
endif
endif

build_c:
	$(compiler_c) -std=c99 -o $(build_dir_c)\\$(hlml_tests_c_filename).exe $(symbols) $(optimisation) $(defines) $(warning_levels) $(ignore_warnings) $(hlml_tests_c_source) $(includes)
	
build_cpp:
	$(compiler_cpp) -std=c++11 $(additional_flags_cpp) -o $(build_dir_cpp)\\$(hlml_tests_cpp_filename).exe $(symbols) $(optimisation) $(defines) $(warning_levels) $(ignore_warnings) $(hlml_tests_cpp_source) $(includes)