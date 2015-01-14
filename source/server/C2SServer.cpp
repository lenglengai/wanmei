#include "../Logic.h"
#include "C2SServer.h"
#include "S2CServer.h"

#ifdef __PING__
namespace std {

#if defined(__LOGIN__) ||  defined(__CENTER__)
	bool C2SServer::handleRun(SessionPtr& nSession)
	{
	#ifdef __LOGIN__
		ServerPtr server_(new Server());
		server_->setPlayerCount(mPlayerCount);
		server_->setPlayerMaxCount(mPlayerMaxCount);
		ServerService& serverService_ = Service<ServerService>::instance();
		serverService_->pushServer(mServerType, mServerId, server_);
		PacketPtr packet_(new S2CServer());
		nSession->runSend(packet_);
	#endif
		return true;
	}
#endif
	
	bool C2SServer::runBlock(BlockPtr& nBlock)
	{
	#if defined(__LOGIN__) ||  defined(__GAME__)
		nBlock->runInt32(mServerType);
		nBlock->runInt32(mServerId);
		nBlock->runInt32(mPlayerCount);
		nBlock->runInt32(mPlayerMaxCount);
	#endif
		return true;
	}

#ifdef __LOGIN__
	void C2SServer::setServerType(__i32 nServerType)
	{
		mServerType = nServerType;
	}
	
	__i32 C2SServer::getServerType() const
	{
		return mServerType;
	}
	
	void C2SServer::setServerId(__i32 nServerId)
	{
		mServerId = nServerId;
	}
	
	__i32 C2SServer::getServerId() const
	{
		return mServerId;
	}
	
	void C2SServer::setPlayerCount(__i32 nPlayerCount)
	{
		mPlayerCount = nPlayerCount;
	}
	
	__i32 C2SServer::getPlayerCount() const
	{
		return mPlayerCount;
	}
	
	void C2SServer::setPlayerMaxCount(__i32 nPlayerMaxCount)
	{
		mPlayerMaxCount = nPlayerMaxCount;
	}
	
	__i32 C2SServer::getPlayerMaxCount() const
	{
		return mPlayerMaxCount;
	}
#endif

	C2SServer::C2SServer()
	#if defined(__LOGIN__) ||  defined(__GAME__)
		: mServerType (0)
		, mServerId (0)
		, mPlayerCount (0)
		, mPlayerMaxCount (0)
	#endif
	{
	}

	C2SServer::~C2SServer()
	{
	#if defined(__LOGIN__) ||  defined(__GAME__)
		mServerType = 0;
		mServerId = 0;
		mPlayerCount = 0;
		mPlayerMaxCount = 0;
	#endif
	}
	
}
#endif
