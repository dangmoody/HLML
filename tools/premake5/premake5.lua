folder_code = "code/"
folder_generated_files = "code/generated_files/"
folder_generated_tests = folder_generated_files .. "tests/"
folder_includes = "code/3rdparty/include/"

folder_bin = "$(SolutionDir)../bin/win64/%{cfg.buildcfg}/"
folder_bin_tests = folder_bin .. "tests/"
folder_scripts = "$(SolutionDir)../scripts/"

vs_project_folder = "../../" .. _ACTION .. "/"	-- path must be relative to premake5.lua file

workspace( "HLML" )
	location( vs_project_folder )

	platforms { "win64-msvc" }
	-- platforms { "win64-clang" }
	configurations { "debug", "release" }

	startproject( "hlml-gen" )

	architecture( "x64" )
		
	-- C/C++
	includedirs (
		"../../" .. folder_includes
	)
	filter ( "configurations:debug" )
		defines {
			"_CRT_SECURE_NO_WARNINGS",
			"_DEBUG"
		}
	filter ( "configurations:release" )
		defines {
			"_CRT_SECURE_NO_WARNINGS",
			"NDEBUG"
		}

	-- filter ( "platforms:win64-clang" )
	--	toolset( "clang" )
	filter ( "platforms:win64-msvc", "_ACTION:vs2019" )
		toolset( "v142" )

project( "generator" )
	location( vs_project_folder )

	files {
		"../../" .. folder_code .. "generator/**.c",
		"../../" .. folder_code .. "generator/**.h",
	}

	kind( "ConsoleApp" )

	cleancommands (
		folder_scripts .. "clean_generator.bat"
	)

	debugdir( "$(SolutionDir)../" )

	-- required because VS will create these folders if they don't exist
	targetdir( folder_bin  )
	objdir( folder_bin .. "/intermediate/hlml-gen" )

	debugcommand( "$(OutDir)generator.exe" )

	filter ( "files:../../" .. folder_code .. "generator/**" )
		flags( "ExcludeFromBuild" )
	filter ( "files:../../" .. folder_code .. "generator/main.c" )
		removeflags( "ExcludeFromBuild" )
	filter ( "files:../../" .. folder_code .. "generator/generator.win64.c" )
		removeflags( "ExcludeFromBuild" )
	filter ( "files:../../" .. folder_code .. "generator/stb_impl.c" )
		removeflags( "ExcludeFromBuild" )

group( "tests" )
	project( "tests-c" )
		location( vs_project_folder )

		files {
			"../../" .. folder_generated_tests .. "c/*.c",
			"../../" .. folder_generated_tests .. "c/*.h",
		}

		kind( "ConsoleApp" )

		cleancommands (
			folder_scripts .. "clean_tests.bat"
		)
		
		includedirs (
			"../../" .. folder_includes
		)

		-- required because VS will create these folders if they don't exist
		targetdir( folder_bin_tests .. "msvc/" )
		objdir( folder_bin_tests .. "msvc/intermediate/hlml_tests_c" )

		debugcommand( "$(OutDir)hlml_tests_c.exe" )

		buildcommands (
			folder_scripts .. "build_msvc.bat --output hlml_tests_c --config debug --source code\\generated_files\\tests\\c\\test_main.c"
		)

		rebuildcommands (
			folder_scripts .. "build_msvc.bat --output hlml_tests_c --config debug --source code\\generated_files\\tests\\c\\test_main.c"
		)

	project( "test-cpp" )
		location( vs_project_folder )

		files {
			"../../" .. folder_generated_tests .. "cpp/*.cpp",
			"../../" .. folder_generated_tests .. "cpp/*.h",
		}

		kind( "ConsoleApp" )

		cleancommands (
			folder_scripts .. "clean_tests.bat"
		)
		
		includedirs (
			"../../" .. folder_includes
		)

		-- required because VS will create these folders if they don't exist
		targetdir( folder_bin_tests .. "msvc/" )
		objdir( folder_bin_tests .. "msvc/intermediate" )

		debugcommand( "$(OutDir)hlml_tests_cpp.exe" )

		buildcommands (
			folder_scripts .. "build_msvc.bat --output hlml_tests_cpp --config %{cfg.buildcfg} hlml-gen-tests-cpp --source code/generated_files/tests/cpp/test_main.cpp"
		)

		rebuildcommands (
			folder_scripts .. "build_msvc.bat --output hlml_tests_cpp --config %{cfg.buildcfg} hlml-gen-tests-cpp --source code/generated_files/tests/cpp/test_main.cpp"
		)
