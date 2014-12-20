#include "../Include.h"

#ifdef __CONSOLE__
namespace std {

	void Console::runContext()
	{
		string strCommand_;
		std::cin >> strCommand_;
		
		if ("-cls" == strCommand_) {
			std::system("cls");
		} else if ("-server" == strCommand_) {
			ServiceMgr& serviceMgr_ = Singleton<ServiceMgr>::instance();
			serviceMgr_.setClientConsole(false);
		} else if ("-client" == strCommand_) {
			ServiceMgr& serviceMgr_ = Singleton<ServiceMgr>::instance();
			serviceMgr_.setClientConsole(true);
		} else {
			mCommandArgs.runParse(strCommand_);
			ServiceMgr& serviceMgr_ = Singleton<ServiceMgr>::instance();
			serviceMgr_.runCommand(mCommandArgs);
		}
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
