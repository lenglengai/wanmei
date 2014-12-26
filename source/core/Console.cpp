#include "../Include.h"

#ifdef __CONSOLE__
namespace std {

	void Console::runContext()
	{
		std::system("cls");
		std::cout << "****************** welcome to http://wwww.xiaoai.com ******************" << std::endl;
		string strCommand_;
		std::getline(std::cin, strCommand_);
		boost::trim(strCommand_);
		
		if ("" == strCommand_) {
			std::cout << "please input command like this: command -flag arg ..." << std::endl;
	#if defined(__CONSOLE__) ||  defined(__CLIENT__)
		} else if ("/s" == strCommand_) {
			ServiceMgr& serviceMgr_ = Singleton<ServiceMgr>::instance();
			serviceMgr_.setClientConsole(false);
		} else if ("/c" == strCommand_) {
			ServiceMgr& serviceMgr_ = Singleton<ServiceMgr>::instance();
			serviceMgr_.setClientConsole(true);
	#endif
		} else if ("/?" == strCommand_) {
			std::cout << "command pattern: command -flag arg ..." << std::endl;
		} else {
			mCommandArgs.runParse(strCommand_);
			ServiceMgr& serviceMgr_ = Singleton<ServiceMgr>::instance();
			serviceMgr_.runCommand(mCommandArgs);
		}
		std::cout << "please type enter key to continue" << std::endl;
		std::cin.get();
	}

	void Console::runClear()
	{
		mCommandArgs.runClear();
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
