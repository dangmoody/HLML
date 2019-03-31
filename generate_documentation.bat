@echo off

REM call doxygen to generate documentation
"doxygen/doxygen" doxygen/config

REM generate a shortcut to the documentation index.html
mklink html_docs.html documentation\html\index.html