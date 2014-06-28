set include=%1%
@echo welcome to build of server
@echo begin create build directories
@set buildir="visual-server"
@if not exist %buildir% mkdir %buildir%
@cd %buildir%
@echo run create project files
@cmake ../../../source/ -G "Visual Studio 12 2013" -D__SERVER__=ON -D__INCLUDE__=%include%
@echo create project finish!
@cd ..
