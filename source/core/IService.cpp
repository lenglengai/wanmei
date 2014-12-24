#include "../Include.h"

namespace std {

#ifdef __CONSOLE__
	const StringWriterPtr IService::runCommand(const CommandArgs& nCommandArgs)
	{
		const string& flags_ = nCommandArgs.getFlags();
		auto it = mCommandRuns.find(flags_);
		if ( it == mCommandRuns.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_0());
			return __defaultptr<StringWriter>();
		}
		CommandRunPtr& commandRun_ = mCommandRuns[flags_];
		return commandRun_(nCommandArgs);
	}
	
	void IService::registerCommand(const char * nFlags, const CommandRunPtr& nCommandRun)
	{
		string flags_(nFlags);
		auto it = mCommandRuns.find(flags_);
		if ( it == mCommandRuns.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_0());
			return;
		}
		mCommandRuns[flags_] = nCommandRun;
	}
#endif
	
	void IService::runClear()
	{
	#ifdef __CONSOLE__
		mCommandRuns.clear();
	#endif
	}
	
	IService::IService()
	{
		this->runClear();
	}
	
	IService::~IService()
	{
		this->runClear();
	}
	
}
