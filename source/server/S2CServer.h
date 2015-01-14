#pragma once

#ifdef __WITHSERVER__
namespace std {

	class ServerService;
	class S2CServer : public Packet<S2CServer, ServerService>
	{
	public:
	#ifdef __GAME__
		bool handleRun(SessionPtr& nSession);
	#endif
		bool runBlock(BlockPtr& nBlock);

		S2CServer();
		~S2CServer();
	};
	typedef shared_ptr<S2CServer> S2CServerPtr;
	
}
#endif
