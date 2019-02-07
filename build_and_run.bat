@echo off

set config=%1%

call build.bat %config%

"%config%/hlml-gen.exe"
