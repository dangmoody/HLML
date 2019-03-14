@echo off

echo Generating code...
debug\hlml-gen_debug.exe -h left

echo Generating documentation...
generate_documentation.bat
