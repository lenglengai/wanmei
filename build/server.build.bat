set include=%1%
@echo welcome to build of server
@echo begin create build directories
mkdir build-server
cd build-server
@echo run create makefile
cmake ../../../source/ -G "MinGW Makefiles" -D__SERVER__=ON -D__INCLUDE__=%include%
@echo run building....
mingw32-make
@echo build finish!
cd ..
