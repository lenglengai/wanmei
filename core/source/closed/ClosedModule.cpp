#include "../../include/Include.h"

namespace std {

	ClosedMgrPtr& ClosedModule::getClosedMgr(__i32 nClosedMgr)
	{
		auto it = mClosedMgrs.find(nClosedMgr);
		if ( it == mClosedMgrs.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nClosedMgr));
			return __defaultptr<ClosedMgr>();
		}
		return it->second;
	}
	
	ClosedModule::ClosedModule() {
		mClosedMgrs.clear();
	}
	
	ClosedModule::~ClosedModule() {
		mClosedMgrs.clear();
	}

}
