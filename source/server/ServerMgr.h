#pragma once

#include "Server.h"

#ifdef __WITHSERVER__
namespace std {

	class ServerMgr : noncopyable
	{
	public:
		void pushServer(__i32 nServerId, ServerPtr& nServer);
		ServerPtr& getServer(__i32 nServerId) const;
		
		ServerMgr();
		~ServerMgr();
		
	private:
		map<__i32, ServerPtr> mServers;
	};
	typedef shared_ptr<ServerMgr> ServerMgrPtr;
	
}
#endif
