#include "../../include/Include.h"

#ifdef __CONSOLE__
namespace std {

	void ConsoleContext::runContext()
	{
		std::string command_;
		std::cin >> command_;
		if ("send" == command_) {
			ConsoleService& consoleService_ = Singleton<ConsoleService>::instance();
			consoleService_.runCommand(mCommands);
			mCommands.clear();
		} else if ("clear" == command_) {
			mCommands.clear();
		} else if ("print" == command_) {
			for (auto& it : mCommands) {
				std::cout << it << std::endl;
			}
		} else {
			mCommands.push_back(command_);
		}
	}

	ConsoleContext::ConsoleContext()
	{
	}

	ConsoleContext::~ConsoleContext()
	{
	}
	
}
#endif
