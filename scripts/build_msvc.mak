# Intended to be called from a parent file, requires prior variable setup!

has_vs_vcvars_path:
# Check if include_msvc_settings determined VS Version
ifndef vs_version
	$(error Cannot find a supported version of Visual Studio in the Visual Studio Install directory)
endif
# Check if include_msvc_settings determined VS Edition
ifndef vs_edition
	$(error Cannot find a supported edition of Visual Studio in the Visual Studio $(vs_version) Install directory)
endif
# Check if include_msvc_settings created the VS VCVars path
ifndef vs_vcvars_path
	$(error Cannot find the main Visual Studio Install directory)
endif

make_build_dir:
ifeq ("$(wildcard $(build_dir_cpp))", "")
	mkdir $(subst /,\\,$(build_dir_cpp))
endif
ifeq ("$(wildcard $(build_dir_c))", "")
# Don't mkdir twice if build dirs match
ifneq ("$(build_dir_c)", "$(build_dir_cpp)")
	mkdir $(subst /,\\,$(build_dir_c))
endif
endif

build_c: has_vs_vcvars_path
	@echo Compiling ${compiler_c} (C)
	"$(vs_vcvars_path)" && cl /Fe:$(build_dir_c)\\$(executable_name_c).exe /Fd:$(build_dir_c)\\$(executable_name_c).pdb /Fo:$(build_dir_c)\\$(executable_name_c).obj $(symbols) $(optimisation) $(defines) $(includes) $(warning_levels) $(ignore_warnings) $(source_files_c)

build_cpp: has_vs_vcvars_path
	@echo Compiling ${compiler_cpp} (C++)
	"$(vs_vcvars_path)" && cl /Fe:$(build_dir_cpp)\\$(executable_name_cpp).exe /Fd:$(build_dir_cpp)\\$(executable_name_cpp).pdb /Fo:$(build_dir_cpp)\\$(executable_name_cpp).obj $(symbols) $(optimisation) $(defines) $(includes) $(warning_levels) $(ignore_warnings) $(source_files_cpp)