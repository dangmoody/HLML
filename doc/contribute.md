# Contributing Code To HLML

The main things you need to know in general are:
* Make sure you've got Clang or GCC (or both) installed and setup on your path etc.
* The GitHub issue tracker is being used.
* Performance and usability are the two primary goals of the API.  If at any time those two goals are in confliction with each other then default to common sense.


Building The Generator
======================

Windows
-------
1. If you want to use Visual Studio:
	* Run `./scripts/generate_vs2019.bat` to get your solution and build.  You're done.
	* If at any time you want to delete your Visual Studio project files run `./scripts/delete_vs_project_files.bat`.
2. If you're not using Visual Studio:
	* To build the generator, generate the code, and run the tests then run the command `./scripts/build_and_test_msvc.bat`.

Mac/Linux
---------
1. To build the generator, generate the code, and run the tests then run any one of the following scripts:

* `./scripts/build_and_test_clang.sh`
* `./scripts/build_and_test_gcc.sh`


Submitting Changes
==================

1. Work in your own branch.  Don't work off `master`.
2. Before submitting a pull request make sure all the tests pass both locally on your machine and on Travis for all platforms.
	* If they don't pass both locally and on Travis then I'm not accepting your changes until they do.
3. Please give as much detail as possible when writing your pull request.