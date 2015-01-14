#pragma once

#ifdef __WITHSERVER__
namespace std {

	class ServerService;
	class C2SServer : public Packet<C2SServer, ServerService>
	{
	public:
	#if defined(__LOGIN__) ||  defined(__CENTER__)
		bool handleRun(SessionPtr& nSession);
	#endif
	#ifdef __LOGIN__
		void setServerType(__i32 nServerType);
		__i32 getServerType() const;
		void setServerId(__i32 nServerId);
		__i32 getServerId() const;
		void setPlayerCount(__i32 nPlayerCount);
		__i32 getPlayerCount() const;
		void setPlayerMaxCount(__i32 nPlayerMaxCount);
		__i32 getPlayerMaxCount() const;
	#endif
	
		bool runBlock(BlockPtr& nBlock);

		C2SServer();
		~C2SServer();

	private:
	#if defined(__LOGIN__) ||  defined(__GAME__)
		__i32 mServerType;
		__i32 mServerId;
		__i32 mPlayerCount;
		__i32 mPlayerMaxCount;
	#endif
	};
	typedef shared_ptr<C2SServer> C2SServerPtr;
	
}
#endif
