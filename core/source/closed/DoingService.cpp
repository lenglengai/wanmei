#include "../../include/Include.h"

namespace std {

	void DoingService::runClosed(PlayerPtr& nPlayer, ClosedPtr& nClosed,
		Values& nValues, ValueList * nValueList) {
		__i32 closedType_ = nClosed->closedType();
		auto it = mDoings.find(closedType_);
		if ( it == mDoings.end() ) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(closedType_));
			return;
		}
		IDoing * doing_ = it->second;
		doing_->runClosed(nPlayer, nClosed, nValues, nValueList);
	}
	
	DoingService::DoingService()
	{
		mDoings.clear();
	}
	
	DoingService::~DoingService()
	{
		mDoings.clear();
	}

	static Preinit<DoingService> sDoingServicePreinit;
	
}
