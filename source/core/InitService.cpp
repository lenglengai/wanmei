#include "../Include.h"
#include "Console.h"

namespace std {

#ifdef __CONSOLE__
	void InitService::runCommand(const CommandArgs& nCommandArgs)
	{
		if (mClientConsole) {
			IService * service_ = nullptr;
			const string& strService_ = nCommandArgs.getService();
			__i32 serviceId_ = __stringid(strService_.c_str());
			__i32 initServiceId_ = __classid<InitService>();
			if (serviceId_ == initServiceId_) {
				service_ = this;
			}
			if (nullptr == service_) {
				map<__i32, IService *>::iterator it = mServices.find(serviceId_);
				if (it != mServices.end()) {
					service_ = it->second;
				}
			}
			if (nullptr == service_) {
				LogService& logService_ = Service<LogService>::instance();
				logService_.logInfo(log_3("not find service", strService_, serviceId_));
				return;
			}
			const StringWriterPtr stringWriter_ = service_->runCommand(nCommandArgs);
			if (stringWriter_) {
				std::cout << stringWriter_->getValue() << std::endl;
			}
		} else {
		}
	}
#ifdef __CLIENT__
	void InitService::setClientConsole(const bool nClientConsole)
	{
		mClientConsole = nClientConsole;
	}
#endif

	const StringWriterPtr InitService::commandInfo(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		string className_(""); 
		__i32 classid_ = __classinfo<InitService>(className_);
		stringWriter_->runString(className_, "className");
		stringWriter_->runInt32(classid_, "classId");
		stringWriter_->runInt32(VERHIGH, "highVersion");
		stringWriter_->runInt32(VERLOW, "lowVersion");
		stringWriter_->runInt32(VERBUILD, "buildVersion");
		stringWriter_->runInt32(BUILDYEAR, "buildYear");
		stringWriter_->runInt32(BUILDMONTH, "buildMonth");
		stringWriter_->runInt32(BUILDDAY, "buildDay");
		stringWriter_->runInt32(STARTYEAR, "startYear");
		stringWriter_->runInt32(STARTMONTH, "startMonth");
		stringWriter_->runInt32(STARTDAY, "startDay");
		stringWriter_->runInt32(ENDYEAR, "endYear");
		stringWriter_->runInt32(ENDMONTH, "endMonth");
		stringWriter_->runInt32(ENDDAY, "endDay");
		stringWriter_->runInt32(INITYEAR, "initYear");
		stringWriter_->runInt32(INITMONTH, "initMonth");
		stringWriter_->runInt32(INITDAY, "initDay");
		stringWriter_->runString(CONFIGUREFILE, "configureFile");
		stringWriter_->runInt32(PACKETMAX, "maxPacketSize");
		stringWriter_->runString(VERNAME, "versionName");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
	const StringWriterPtr InitService::commandResume(const CommandArgs& nCommandArgs)
	{
		this->resumeBegin();
		this->resuming();
		this->resumeEnd();
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		bool isPause_ = mPause;
		stringWriter_->runBool(isPause_, "isPause");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
	const StringWriterPtr InitService::commandPause(const CommandArgs& nCommandArgs)
	{
		this->pauseBegin();
		this->pausing();
		this->pauseEnd();
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		bool isPause_ = mPause;
		stringWriter_->runBool(isPause_, "isPause");
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
	const StringWriterPtr InitService::commandFindName(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
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
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
	const StringWriterPtr InitService::commandFindId(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
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
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
	
	const StringWriterPtr InitService::commandInitTable(const CommandArgs& nCommandArgs)
	{
		StringWriterPtr stringWriter_(new StringWriter());
		nCommandArgs.runStringWriter(stringWriter_);
		stringWriter_->startClass("result");
		this->runInitTable();
		stringWriter_->finishClass();
		stringWriter_->runClose();
		return stringWriter_;
	}
#endif
	
	void InitService::registerService(__i32 nClassId, IService * nService)
	{
		map<__i32, IService *>::iterator it = mServices.find(nClassId);
		if ( it == mServices.end() ) {
			mServices[nClassId] = nService;
		}
	}
	
	bool InitService::runPreinit()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for (; it != mServices.end(); ++it) {
			IService *& service_ = it->second;
			if ( !service_->runPreinit() ) {
				return false;
			}
		}
	#ifdef __CONSOLE__
		this->registerCommand("info", std::bind(&InitService::commandInfo, this, placeholders::_1));
		this->registerCommand("resume", std::bind(&InitService::commandResume, this, placeholders::_1));
		this->registerCommand("pause", std::bind(&InitService::commandPause, this, placeholders::_1));
		this->registerCommand("findName", std::bind(&InitService::commandFindName, this, placeholders::_1));
		this->registerCommand("findId", std::bind(&InitService::commandFindId, this, placeholders::_1));
		this->registerCommand("initTable", std::bind(&InitService::commandInitTable, this, placeholders::_1));
	#endif
		return true;
	}
	
	InitService * InitService::getInitService()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		return (&initService_);
	}
	
	void InitService::runLuaApi()
	{
	#ifdef __EXPLUA__
		LuaService& luaService_ = Service<LuaService>::instance();
		luaService_.runClass<InitService>("InitService");
		luaService_.runFun(&InitService::getInitService, "getInitService");
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->runLuaApi();
		}
	#endif
	}
	
	bool InitService::runConfig()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->runConfig() ) {
				return false;
			}
		}
		return true;
	}
	
	bool InitService::runInitDb()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->runInitDb() ) {
				return false;
			}
		}
		return true;
	}
	
	bool InitService::runInitTable()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->runInitTable() ) {
				return false;
			}
		}
		return true;
	}
	
	bool InitService::loadBegin()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->loadBegin() ) {
				return false;
			}
		}
		return true;
	}
	
	bool InitService::loading()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->loading() ) {
				return false;
			}
		}
		return true;
	}
	
	bool InitService::loadEnd()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->loadEnd() ) {
				return false;
			}
		}
		return true;
	}
	
	bool InitService::initBegin()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->initBegin() ) {
				return false;
			}
		}
	#ifdef __CONSOLE__
		mConsole.reset(new Handle());
		ContextPtr consoleContext(new Console());
		mConsole->addContext(consoleContext);
	#endif
		return true;
	}
	
	bool InitService::initing()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->initing() ) {
				return false;
			}
		}
		return true;
	}
	
	bool InitService::initEnd()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			if ( !service_->initEnd() ) {
				return false;
			}
		}
		return true;
	}
	
	void InitService::startBegin()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->startBegin();
		}
	}
	
	void InitService::starting()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->starting();
		}
	#ifdef __CONSOLE__
		mConsole->runStart();
	#endif
	}
	
	void InitService::startEnd()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->startEnd();
		}
	}
	
	void InitService::runing()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->runing();
		}
	}
	
	void InitService::stopBegin()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->stopBegin();
		}
	}
	
	void InitService::stoping()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->stoping();
		}
	#ifdef __CONSOLE__
		mConsole->runStop();
		mConsole->runJoin();
	#endif
	}
	
	void InitService::stopEnd()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->stopEnd();
		}
	}
	
	void InitService::runClear()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->runClear();
		}
	}
	
	void InitService::resumeBegin()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->resumeBegin();
		}
	}
	
	void InitService::resuming()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->resuming();
		}
	}
	
	void InitService::resumeEnd()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->resumeEnd();
		}
	}
	
	void InitService::pauseBegin()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->pauseBegin();
		}
	}
	
	void InitService::pausing()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->pausing();
		}
	}
	
	void InitService::pauseEnd()
	{
		map<__i32, IService *>::iterator it = mServices.begin();
		for ( ; it != mServices.end(); ++it ) {
			IService *& service_ = it->second;
			service_->pauseEnd();
		}
		mPause = true;
	}
	
	bool InitService::isPause() const
	{
		return mPause;
	}
	
	InitService::InitService()
		: mPause (false)
	{
		mServices.clear();
#ifdef __CONSOLE__
		mClientConsole = true;
#endif
	}

	InitService::~InitService()
	{
		mServices.clear();
#ifdef __CONSOLE__
		mClientConsole = true;
#endif
		mPause = false;
	}

}

int main( int argc, char * argv[] )
{
	using namespace std;
	InitService& initService_ = Singleton<InitService>::instance();
	if (!initService_.runPreinit()) {
		return 0;
	}
	
	initService_.runLuaApi();
	if ( !initService_.runConfig() ) {
		return 0;
	}
	if ( !initService_.runInitDb() ) {
		return 0;
	}
	
	if ( !initService_.loadBegin() ) {
		return 0;
	}
	if ( !initService_.loading() ) {
		return 0;
	}
	if ( !initService_.loadEnd() ) {
		return 0;
	}
	
	if ( !initService_.initBegin() ) {
		return 0;
	}
	if ( !initService_.initing() ) {
		return 0;
	}
	if ( !initService_.initEnd() ) {
		return 0;
	}
	
	initService_.startBegin();
	initService_.starting();
	initService_.startEnd();
	
	initService_.runing();
	
	initService_.stopBegin();
	initService_.stoping();
	initService_.stopEnd();
	
	initService_.runClear();
	
	return 0;
}
