#include "../Common.h"

#ifdef __NET__
namespace std{

	bool PlayerService::pushPacket(PacketPtr& nPacket, PlayerPtr& nPlayer)
	{
	#ifdef __SERVER__
		if (nPlayer->isInSwitch()) {
			LogService_& logService_ = Singleton<LogService_>::instance();
			__i32 protocolId = nPacket->getProtocolId();
			__i32 packetId = nPacket->getPacketId(); 
			logService_.logError(log_3("PlayerService pushPacket isInSwitch: ", protocolId, packetId));
			return false;
		}
		nPacket->setPlayer(nPlayer);
		__i16 wireId = nPlayer->getWireId();
		auto it = mSingleWires.find(wireId);
		if ( it == mSingleWires.end())  {
			LogService_& logService_ = Singleton<LogService_>::instance();
			logService_.logError(log_2("PlayerService pushPacket wireId: ", wireId));
			return false;
		}
		SingleWirePtr& singleWire_ = it->second;
		singleWire_.pushPacket(nPacket);
	#endif
	#ifdef __CLIENT__
		mSingleWire.pushPacket(nPacket);
	#endif
		return true;
	}
	
	PlayerPtr& PlayerService::generatePlayer()
	{
		std::lock_guard<std::mutex> lock_(mMutex);
		++mPlayerId;
		PlayerPtr player_(new Player());
		player_->setPlayerId(mPlayerId);
		mPlayers[mPlayerId] = player_;
		return mPlayers[mPlayerId];
	}
	
	bool PlayerService::runPreinit()
	{
	}
	
	void PlayerService::runInit()
	{
	}
	
	void PlayerService::runStart()
	{
	}
	
	PlayerService::PlayerService()
		: mPlayerId (0)
	{
		mPlayers.clear();
	}
	
	PlayerService::~PlayerService()
	{
		mPlayers.clear();
		mPlayerId = 0;
	}
	
	static PreInit<PlayerService> sPlayerServicePreInit;
}
#endif