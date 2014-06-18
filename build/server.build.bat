set include=%1%
@echo 欢迎来到服务器构建工具
@echo 开始创建生成目录..
mkdir build-server
cd build-server
@echo 执行生成Makefile...
cmake .. -G "MinGW Makefiles" -D__SERVER__=ON -D__INCLUDE__=%include%
@echo 开始编译...
mingw32-make
@echo 编译完成!
cd ..

