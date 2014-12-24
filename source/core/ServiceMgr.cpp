#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	void ServiceMgr::runCommand(const CommandArgs& nCommandArgs) const
	{
		if (mClientConsole) {
			const string& strService_ = nCommandArgs.getService();
			__i32 serviceId_ = __stringid(strService_.c_str());
			auto it = mServices.find(serviceId_);
			if (it == mServices.end()) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logInfo(log_2(strService_, serviceId_));
				return;
			}
			IService * service_ = it->second;
			const StringWriterPtr stringWriter_ = service_->runCommand(nCommandArgs);
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logInfo(log_1(stringWriter_->getValue()));
		} else {
		}
	}
	
	const StringWriterPtr ServiceMgr::commandInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		string className_(""); 
		__i32 serviceCount_ = mServices.size();
		__i32 classid_ = __classinfo<ServiceMgr>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runInt32(classid_, "classId");
		stringWriter_->runInt32(serviceCount_, "serviceCount");
		return stringWriter_;
	}
	
	const StringWriterPtr ServiceMgr::commandFindName(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		const string& strService_ = nCommandArgs.getCommandArg(1);
		__i32 serviceId_ = __stringid(strService_.c_str());
		bool isFind_ = false;
		auto it = mServices.find(serviceId_);
		if (it != mServices.end()) {
			isFind_ = true;
		}
		stringWriter_->runString(strService_, "strService");
		stringWriter_->runInt32(serviceId_, "serviceId");
		stringWriter_->runBool(isFind_, "isFind");
		return stringWriter_;
	}
	
	const StringWriterPtr ServiceMgr::commandFindId(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		const string& strService_ = nCommandArgs.getCommandArg(1);
		__i32 serviceId_ = __convert<string, __i32>(strService_);
		bool isFind_ = false;
		auto it = mServices.find(serviceId_);
		if (it != mServices.end()) {
			isFind_ = true;
		}
		stringWriter_->runString(strService_, "strService");
		stringWriter_->runInt32(serviceId_, "serviceId");
		stringWriter_->runBool(isFind_, "isFind");
		return stringWriter_;
	}
	
	void ServiceMgr::setClientConsole(const bool nClientConsole)
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
		this->registerCommand("info", std::bind(&ServiceMgr::commandInfo, this, placeholders::_1));
		this->registerCommand("findName", std::bind(&ServiceMgr::commandFindName, this, placeholders::_1));
		this->registerCommand("findId", std::bind(&ServiceMgr::commandFindId, this, placeholders::_1));
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
	
}
