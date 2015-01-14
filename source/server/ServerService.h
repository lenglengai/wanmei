#pragma once

#include "ServerMgr.h"

#ifdef __WITHSERVER__
namespace std {

	class ServerService : public IProtocol
	{
	public:
	#ifdef __LOGIN__
		void pushServer(__i32 nServerType, __i32 nServerId, ServerPtr& nServer);
		ServerPtr& getServer(__i32 nServerType, __i32 nServerId) const;
	#endif
		
		ServerService();
		~ServerService();
		
	private:
	#ifdef __LOGIN__
		map<__i32, ServerMgrPtr> mServerMgrs;
	#endif
	};

}
#endif
