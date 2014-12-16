#include "../Include.h"

#ifdef __CONSOLE__
namespace std {

	void ConsoleService::runCommand(std::list<std::string>& nCommand)
	{
		__i32 count_ = static_cast<__i32>(nCommand.size());
		if (count_ < 1) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logInfo(log_2("command count is", count_));
			return;
		}
		if (mIsClient) {
			std::string& strConsole_ = nCommand.front();
		
			CrcService& crcService_ = Singleton<CrcService>::instance();
			__i32 consoleId_ = crcService_.runCommon(strConsole_.c_str());
			auto it = mConsoles.find(consoleId_);
			if (it == mConsoles.end()) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logInfo(log_2("not find console for ", strConsole_));
				return;
			}
			nCommand.pop_front();
			StringWriter stringWriter;
			IConsole * console_ = it->second;
			console_->runCommand(nCommand, stringWriter);
			std::cout << stringWriter.getValue() << std::endl;
		} else {
		}
	}
	
	void ConsoleService::setIsClient(bool nIsClient)
	{
		mIsClient = nIsClient;
	}
	
	bool ConsoleService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&ConsoleService::runInit, this));
		initService_.m_tRunStart1.connect(boost::bind(&ConsoleService::runStart, this));
		initService_.m_tRunStop.connect(boost::bind(&ConsoleService::runStop, this));
		return true;
	}

	void ConsoleService::runInit()
	{
		mHandle.reset(new Handle());
		mContext.reset(new ConsoleContext());
		mHandle->addContext(mContext);
	}

	void ConsoleService::runStart()
	{
		mHandle->runStart();
	}

	void ConsoleService::runStop()
	{
		mHandle->runStop();
	}
	
	ConsoleService::ConsoleService()
	{
		mConsoles.clear();
		mIsClient = true;
	}

	ConsoleService::~ConsoleService()
	{
		mConsoles.clear();
		mIsClient = true;
	}
	
	static Preinit0<ConsoleService> sConsoleServicePreinit;

}
#endif
