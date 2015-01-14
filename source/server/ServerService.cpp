#include "../Include.h"

#ifdef __WITHSERVER__
namespace std {

#ifdef __LOGIN__
	void ServerService::pushServer(__i32 nServerType, __i32 nServerId, ServerPtr& nServer)
	{
		auto it = mServerMgrs.find(nServerType);
		if ( it != mServerMgrs.end() ) {
			ServerMgrPtr serverMgr(new ServerMgr());
			mServerMgrs[nServerType] = serverMgr;
		}
		ServerMgrPtr& serverMgr_ = mServerMgrs[nServerType];
		serverMgr_->pushServer(nServerId, nServer);
	}
	
	ServerPtr& ServerService::getServer(__i32 nServerType, __i32 nServerId) const
	{
		auto it = mServerMgrs.find(nServerType);
		if ( it == mServerMgrs.end() ) {
			return __defaultptr<Server>();
		}
		ServerMgrPtr& serverMgr_ = it->second;
		return serverMgr_->getServer(nServerId);
	}
	
	ServerMgrPtr& ServerService::getServerMgr(__i32 nServerType) const
	{
		auto it = mServerMgrs.find(nServerType);
		if ( it == mServerMgrs.end() ) {
			return __defaultptr<ServerMgr>();
		}
		return it->second;
	}
#endif
	
	ServerService::ServerService()
	{
	#ifdef __LOGIN__
		mServerMgrs.clear();
	#endif
	}

	ServerService::~ServerService()
	{
	#ifdef __LOGIN__
		mServerMgrs.clear();
	#endif
	}
	
	static Service<ServerService> sServerService;

}
#endif
