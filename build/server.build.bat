set include=%1%
@echo ��ӭ������������������
@echo ��ʼ��������Ŀ¼..
mkdir build-server
cd build-server
@echo ִ������Makefile...
cmake .. -G "MinGW Makefiles" -D__SERVER__=ON -D__INCLUDE__=%include%
@echo ��ʼ����...
mingw32-make
@echo �������!
cd ..

