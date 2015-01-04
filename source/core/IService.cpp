#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	const StringWriterPtr IService::runCommand(const CommandArgs& nCommandArgs)
	{
		const string& flags_ = nCommandArgs.getFlags();
		map<string, CommandRunPtr>::iterator it = mCommandRuns.find(flags_);
		if ( it == mCommandRuns.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_2("not find flags", flags_));
			return __defaultptr<StringWriter>();
		}
		CommandRunPtr& commandRun_ = mCommandRuns[flags_];
		return commandRun_(nCommandArgs);
	}
	
	void IService::registerCommand(const char * nFlags, const CommandRunPtr& nCommandRun)
	{
		string flags_(nFlags);
		map<string, CommandRunPtr>::iterator it = mCommandRuns.find(flags_);
		if ( it != mCommandRuns.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nFlags));
			return;
		}
		mCommandRuns[flags_] = nCommandRun;
	}
#endif

	bool IService::runPreinit()
	{
		return true;
	}
	
	void IService::runLuaApi()
	{
	}
	
	void IService::runConfig()
	{
	}
	
	void IService::runInitDb()
	{
	}
	
	void IService::loadBegin()
	{
	}
	
	void IService::loading()
	{
	}
	
	void IService::loadEnd()
	{
	}
	
	void IService::initBegin()
	{
	}
	
	void IService::initing()
	{
	}
	
	void IService::initEnd()
	{
	}
	
	void IService::startBegin()
	{
	}
	
	void IService::starting()
	{
	}
	
	void IService::startEnd()
	{
	}
	
	void IService::runing()
	{
	}
	
	void IService::stopBegin()
	{
	}
	
	void IService::stoping()
	{
	}
	
	void IService::stopEnd()
	{
	}
	
	void IService::resumeBegin()
	{
	}
	
	void IService::resuming()
	{
	}
	
	void IService::resumeEnd()
	{
	}
	
	void IService::pauseBegin()
	{
	}
	
	void IService::pausing()
	{
	}
	
	void IService::pauseEnd()
	{
	}
	
	bool IService::isPause() const
	{
		InitService& initService = 
			Singleton<InitService>::instance();
		return initService.isPause();
	}
	
	IService::IService()
	{
	#ifdef __CONSOLE__
		mCommandRuns.clear();
	#endif
	}
	
	IService::~IService()
	{
	#ifdef __CONSOLE__
		mCommandRuns.clear();
	#endif
	}
	
}