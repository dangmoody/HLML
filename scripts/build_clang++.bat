@echo off

pushd %~dp0

call build_clang_gcc.bat --compiler clang++ %*

popd