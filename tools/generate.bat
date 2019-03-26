@echo off

echo Generating code...
..\build\release\hlml-gen_debug.exe

echo Generating documentation...
generate_documentation.bat
