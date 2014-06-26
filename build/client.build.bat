set include=%1%
@echo welcome to build of client
@echo begin create build directories
@set buildir="build-client"
@if not exist %buildir% mkdir %buildir%
@cd %buildir%
@echo run create makefile
@cmake ../../../source/ -G "MinGW Makefiles" -D__CLIENT__=ON -D__INCLUDE__=%include%
@echo run building....
@mingw32-make
@echo build finish!
@cd ..
