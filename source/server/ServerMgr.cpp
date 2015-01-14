#include "../Include.h"

#ifdef __WITHSERVER__
namespace std {

	void ServerMgr::pushServer(__i32 nServerId, ServerPtr& nServer)
	{
		auto it = mServers.find(nServerId);
		if ( it != mServers.end() ) {
			return __defaultptr<Server>();
		}
		mServers[nServerId] = nServer;
	}
	
	ServerPtr& ServerMgr::getServer(__i32 nServerId) const
	{
		auto it = mServers.find(nServerId);
		if ( it == mServers.end() ) {
			return __defaultptr<Server>();
		}
		return it->second;
	}
				
	ServerMgr::ServerMgr()
	{
		mServers.clear();
	}
	
	ServerMgr::~ServerMgr()
	{
		mServers.clear();
	}
	
}
#endif
