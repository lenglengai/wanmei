#include "../Include.h"

#ifdef __CONSOLE__
namespace std {

	void Console::runContext()
	{
		TimeService& timeService_ = Singleton<TimeService>::instance();
		__i64 startTime_ = timeService_.getStartTime();
		if (startTime_ < 10) return;
		if (mCommand) {
			this->runCommandBat(__default<string>());
			mCommand = false;
		}
		this->runConsole();
	}

	void Console::runConsole()
	{
		std::system("cls");
		std::cout << "****************** welcome to http://wwww.xiaoai.com ******************" << std::endl;
		string strCommand_;
		std::getline(std::cin, strCommand_);
		boost::trim(strCommand_);
		
		this->runCommand(strCommand_);
		
		std::cout << "please type enter key to continue" << std::endl;
		std::cin.get();
	}
	
	void Console::runCommandBat(const string& nStreamUrl)
	{
		CommandBat commandBat;
		if ("" != nStreamUrl) {
			commandBat.setStreamUrl(nStreamUrl.c_str());
		}
		ArchiveService& archiveService_ = Singleton<ArchiveService>::instance();
		archiveService_.xmlStream(&commandBat);
		const list<string>& commands_ = commandBat.getCommands();
		for (auto& it : commands_) {
			this->runCommand(it);
		}
	}
	
	void Console::runCommand(const string& nCommand)
	{
		if ("" == nCommand) {
			std::cout << "please input command like this: command -flag arg ..." << std::endl;
	#if defined(__CONSOLE__) ||  defined(__CLIENT__)
		} else if ("/s" == nCommand) {
			ServiceMgr& serviceMgr_ = Singleton<ServiceMgr>::instance();
			serviceMgr_.setClientConsole(false);
		} else if ("/c" == nCommand) {
			ServiceMgr& serviceMgr_ = Singleton<ServiceMgr>::instance();
			serviceMgr_.setClientConsole(true);
	#endif
		} else if ( 0 == nCommand.compare(0, 3, "/c ") ) {
			this->runCommandBat(nCommand.substr(3));
		} else if ("/?" == nCommand) {
			std::cout << "command pattern: command -flag arg ..." << std::endl;
		}
		else {
			mCommandArgs.runParse(nCommand);
			ServiceMgr& serviceMgr_ = Singleton<ServiceMgr>::instance();
			serviceMgr_.runCommand(mCommandArgs);
		}
	}

	void Console::runClear()
	{
		mCommandArgs.runClear();
	}
	
	Console::Console(const bool nCommand)
		: mCommand(nCommand)
	{
		this->runClear();
	}

	Console::~Console()
	{
		this->runClear();
	}
	
}
#endif
