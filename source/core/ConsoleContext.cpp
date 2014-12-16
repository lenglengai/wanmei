#include "../Include.h"

#ifdef __CONSOLE__
namespace std {

	void ConsoleContext::runContext()
	{
		string command_;
		std::cin >> command_;
		if ("-send" == command_) {
			ConsoleService& consoleService_ = Singleton<ConsoleService>::instance();
			consoleService_.runCommand(mCommands);
			mCommands.clear();
		} else if ("-clear" == command_) {
			mCommands.clear();
		} else if ("-cls" == command_) {
			std::system("cls");
		} else if ("-server" == command_) {
			ConsoleService& consoleService_ = Singleton<ConsoleService>::instance();
			consoleService_.setIsClient(false);
		} else if ("-client" == command_) {
			ConsoleService& consoleService_ = Singleton<ConsoleService>::instance();
			consoleService_.setIsClient(true);
		} else if ("-print" == command_) {
			bool first_ = true;
			for (auto& it : mCommands) {
				if (!first_) {
					std::cout << ";";
				}
				std::cout << it;
				first_ = false;
			}
			std::cout << "end" << std::endl;
		} else {
			mCommands.push_back(command_);
		}
	}

	void ConsoleContext::runClear()
	{
		mCommands.clear();
	}
	
	ConsoleContext::ConsoleContext()
	{
		this->runClear();
	}

	ConsoleContext::~ConsoleContext()
	{
		this->runClear();
	}
	
}
#endif
