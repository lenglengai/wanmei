#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	void ServiceMgr::runCommand(std::list<std::string>& nCommand)
	{
		__i32 count_ = static_cast<__i32>(nCommand.size());
		if (count_ < 1) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logInfo(log_2("command count is", count_));
			return;
		}
		if (mClientConsole) {
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
			IConsole * console_ = it->second;
			StringWriterPtr stringWriter = console_->runCommand(nCommand);
			std::cout << stringWriter->getValue() << std::endl;
		} else {
		}
	}
	
	void ServiceMgr::setClientConsole(bool nClientConsole)
	{
		mClientConsole = nClientConsole;
	}
#endif

	bool ServiceMgr::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&ServiceMgr::runInit, this));
		initService_.m_tRunStart1.connect(boost::bind(&ServiceMgr::runStart, this));
		initService_.m_tRunStop.connect(boost::bind(&ServiceMgr::runStop, this));
		return true;
	}

	void ServiceMgr::runInit()
	{
#ifdef __CONSOLE__
		mConsoleHandle.reset(new Handle());
		ContextPtr consoleConText(new Console());
		mConsoleHandle->addContext(consoleConText);
#endif
	}

	void ServiceMgr::runStart()
	{
#ifdef __CONSOLE__
		mConsoleHandle->runStart();
#endif
	}

	void ServiceMgr::runStop()
	{
#ifdef __CONSOLE__
		mConsoleHandle->runStop();
#endif
	}
	
	ServiceMgr::ServiceMgr()
	{
		mServices.clear();
#ifdef __CONSOLE__
		mClientConsole = true;
#endif
	}

	ServiceMgr::~ServiceMgr()
	{
		mServices.clear();
#ifdef __CONSOLE__
		mClientConsole = true;
#endif
	}
	
	static Preinit0<ServiceMgr> sServiceMgrPreinit;

}
#endif
