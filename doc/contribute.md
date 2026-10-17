# Contributing Code To HLML

HLML is accepting PRs!

## House Rules

* Your PR must be submitted in the form of a fork.
* Your PR fixes one of the issues in the repo's [issues list](https://github.com/dangmoody/HLML/issues).
* I am grateful for any and all PRs that get submitted, but it's entirely my discretion as to whether or not the PR gets accepted.  I will do my best to work with you on the changes before rejecting a PR.


## Prerequisites

Windows:
* MSVC

All platforms:
* [Builder](https://github.com/dangmoody/Builder)
* Clang 20.1.5
* GCC 15.2.0


## Building

### Windows

If you want to use Visual Studio, run `build.exe --sln`.


### All platforms

The build executable (`build` on Linux, `build.exe` on Windows) lives in the project root and rebuilds itself whenever `build.c` changes.

Run the following commands:
* `build --config=generator` to build the generator.
* `build --config=tests-c` to build the C tests.
* `build --config=tests-cpp` to build the C++ tests.

By default the compiler is Clang.  Pass `--gcc` or `--msvc` to use GCC or MSVC instead.
