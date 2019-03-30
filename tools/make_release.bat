@echo off

if [%1]==[] (
	goto :bad_arg
)

set version=%1

echo Packing build...

REM copy the relevant files over
REM these will be deleted later
robocopy /s /e ..\code\out\ ..\releases\code\
robocopy /s /e doxygen\ ..\releases\doxygen\

7z a -t7z ..\releases\hlml_%version%.zip ..\releases\code\ ..\releases\doxygen\ generate_documentation.bat

REM delete temp folders
rd /s /Q ..\releases\code\
rd /s /Q ..\releases\doxygen\

echo.
echo Done.
echo.

pause
goto :quit


:bad_arg
echo ERROR: Must set a version parameter! (for example: script.bat 0.1.0)
goto :quit


:quit
echo quit
