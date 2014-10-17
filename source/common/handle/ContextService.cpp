#include "../Common.h"

#ifdef __HANDLE__
namespace std {

	void ContextService::pushPacket(__i16 nContextId, PacketPtr& nPacket)
	{
		auto it = mContexts.find(nContextId);
		if (it == mContexts.end()) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logInfo(log_2("ContextService pushPacket: ", nContextId));
			return;
		}
		ContextPtr& context_ = it->second;
		context_->pushPacket(nPacket);
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
