# Intended to be called from a parent file, requires prior variable setup!

make_build_dir:
ifeq ("$(wildcard $(build_dir_cpp))", "")
	mkdir $(build_dir_cpp)
endif
ifeq ("$(wildcard $(build_dir_c))", "")
# Don't mkdir twice if build dirs match
ifneq ("$(build_dir_c)", "$(build_dir_cpp)")
	mkdir $(build_dir_c)
endif
endif

build_c:
	@echo Compiling $(compiler_c)
	$(compiler_c) -std=c99 -o $(build_dir_c)\\$(executable_name_c).exe $(symbols) $(optimisation) $(defines) $(warning_levels) $(ignore_warnings) $(source_files_c) $(includes)

build_cpp:
	@echo Compiling $(compiler_cpp)
	$(compiler_cpp) -std=c++11 $(additional_flags_cpp) -o $(build_dir_cpp)\\$(executable_name_cpp).exe $(symbols) $(optimisation) $(defines) $(warning_levels) $(ignore_warnings) $(source_files_cpp) $(includes)