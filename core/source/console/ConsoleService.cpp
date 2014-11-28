#include "../../include/Include.h"

#ifdef __CONSOLE__
namespace std {

	void ConsoleService::runCommand(std::list<std::string>& nCommand)
	{
		__i32 count_ = static_cast<__i32>(nCommand.size());
		if (count < 1) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(count));
			return;
		}
		std::string& strConsole_ = nCommand.front();
		
		CrcService& crcService_ = Singleton<CrcService>::instance();
		__i32 consoleId_ = crcService_.runCommon(strConsole_.c_str());
		auto it = mConsoles.find(consoleId_);
		if (it == mConsoles.end()) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(consoleId_));
			return;
		}
		nCommand.pop_front();
		IConsole * console_ = it->second;
		console_->runCommand(nCommand);
	}
	
	bool ConsoleService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&ConsoleService::runInit, this));
		initService_.m_tRunStart1.connect(boost::bind(&ConsoleService::runStart, this));
		initService_.m_tRunStop.connect(boost::bind(&ConsoleService::runStop, this));

		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
		return true;
	}

	void ConsoleService::runInit()
	{
		mHandle.reset(new Handle());
		mContext.reset(new ConsoleContext());
		mHandle->addContext(mContext);
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

	void ConsoleService::runStart()
	{
		mHandle->runStart();
		
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}

	void ConsoleService::runStop()
	{
		mHandle->runStop();
		
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}
	
	ConsoleService::ConsoleService()
	{
		mConsoles.clear();
	}

	ConsoleService::~ConsoleService()
	{
		mConsoles.clear();
	}
	
	static Preinit<ConsoleService> sConsoleServicePreinit;

}
#endif
