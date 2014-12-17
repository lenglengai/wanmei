#include "../Include.h"

#ifdef __CONSOLE__
namespace std {

	void Console::runContext()
	{
		string command_;
		std::cin >> command_;
		if ("-send" == command_) {
			ServiceMgr& serviceMgr_ = Singleton<ServiceMgr>::instance();
			serviceMgr_.runCommand(mCommands);
			mCommands.clear();
		} else if ("-clear" == command_) {
			mCommands.clear();
		} else if ("-cls" == command_) {
			std::system("cls");
		} else if ("-server" == command_) {
			ServiceMgr& serviceMgr_ = Singleton<ServiceMgr>::instance();
			serviceMgr_.setClientConsole(false);
		} else if ("-client" == command_) {
			ServiceMgr& serviceMgr_ = Singleton<ServiceMgr>::instance();
			serviceMgr_.setClientConsole(true);
		} else if ("-print" == command_) {
			bool first_ = true;
			for (auto& it : mCommands) {
				if (!first_) {
					std::cout << ":";
				} else {
					first_ = false;
				}
				std::cout << it;
			}
			std::cout << std::endl;
		} else {
			mCommands.push_back(command_);
		}
	}

	void Console::runClear()
	{
		mCommands.clear();
	}
	
	Console::Console()
	{
		this->runClear();
	}

	Console::~Console()
	{
		this->runClear();
	}
	
}
#endif
