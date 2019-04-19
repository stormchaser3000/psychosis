@echo off
if %1==build mingw32-make -f Makefile.windows
if %1==clean mingw32-make -f Makefile.windows clean
