#include "../../include/Include.h"

namespace std {

	ClosedMgrPtr& ClosedService::getClosedMgr(__i32 nModule, __i32 nClosedMgr)
	{
		auto it = mClosedModules.find(nModule);
		if ( it == mClosedModules.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nModule));
			return __defaultptr<ClosedMgr>();
		}
		ClosedModulePtr& closedModule_ = it->second;
		return closedModule_->getClosedMgr(nClosedMgr);
	}
	
	bool ClosedService::runPreinit()
	{
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
		return true;
	}
	
	ClosedService::ClosedService() {
		mClosedModules.clear();
	}
	
	ClosedService::~ClosedService() {
		mClosedModules.clear();
	}

	static Preinit<ClosedService> sClosedServicePreinit;
	
}
