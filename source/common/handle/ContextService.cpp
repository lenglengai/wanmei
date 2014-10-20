#include "../Common.h"

#ifdef __HANDLE__
namespace std {

	bool ContextService::pushPacket(__i16 nContextId, PacketPtr& nPacket)
	{
		auto it = mContexts.find(nContextId);
		if (it == mContexts.end()) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logInfo(log_2("ContextService pushPacket: ", nContextId));
			return false;
		}
		ContextPtr& context_ = it->second;
		context_->pushPacket(nPacket);
		return true;
	}
	
	ContextService::ContextService()
	{
		mContexts.clear();
	}
	
	ContextService::~ContextService()
	{
		mContexts.clear();
	}
	
}
#endif
