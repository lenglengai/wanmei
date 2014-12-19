#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	void ServiceMgr::runCommand(const CommandArgs& nCommand)
	{
		if (mClientConsole) {
			const string& strService_ = nCommand.getService();
			__i32 serviceId_ = __stringid(strService_.c_str());
			auto it = mServices.find(serviceId_);
			if (it == mServices.end()) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logInfo(log_2(strService_, serviceId_));
				return;
			}
			IService * service_ = it->second;
			StringWriterPtr stringWriter_ = service_->runCommand(nCommand);
			std::cout << stringWriter_->getValue() << std::endl;
		} else {
		}
	}
	
	StringWriterPtr ServiceMgr::runClassId(const CommandArgs& nCommand)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		string className_("");
		__i32 classid_ = __classid<ServiceMgr>(className_);
		stringWriter_.runString(className_, "className");
		stringWriter_.runInt32(classid_, "classId");
		return stringWriter_;
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
	#ifdef __CONSOLE__
		this->registerCommand("c", std::bind(&ServiceMgr::runClassId, this, _1));
	#endif
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
	
	static Preinit1<ServiceMgr> sServiceMgrPreinit;

}
#endif
