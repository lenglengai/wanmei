set include=%1%
@echo welcome to build of client
@echo begin create build directories
@set buildir="visual-client"
@if not exist %buildir% mkdir %buildir%
@cd %buildir%
@echo run create project files
@cmake ../../../source/ -G " Visual Studio 12 2013" -D__CLIENT__=ON -D__INCLUDE__=%include%
@echo project create finish!
@cd ..
