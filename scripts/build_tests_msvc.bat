@echo off

pushd %~dp0

set config=%1

set source_files=%2

call build_msvc.bat %config% hlml-gen-tests-c %source_files%

popd