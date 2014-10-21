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
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("PlayerService runPreinit!"));
	#endif
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&PlayerService::runInit, this));
		initService_.m_tRunStart0.connect(boost::bind(&PlayerService::runStart, this));
	#ifdef __LOG__
		logService_.logInfo(log_1("PlayerService runPreinit finish!"));
	#endif
		return true;
	}
	
	void PlayerService::runInit()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("PlayerService runInit!"));
	#endif

	#ifdef __CLIENT__
		mSingleWire.reset(new SingleWire());
	#endif

	#if defined(__SERVER__) && defined(__CPU__)
		CpuService& cpuService_ = Singleton<CpuService>::instance();
		__i16 cpuCount = cpuService_.getCpuCount();
		for ( __i16 i = 1; i <= cpuCount; ++i ) {
			SingleWirePtr singleWire_(new SingleWire());
			mSingleWires[i] = singleWire_;
		}
	#endif
	
	#ifdef __LOG__
		logService_.logInfo(log_1("PlayerService runInit finish!"));
	#endif
	}
	
	void PlayerService::runStart()
	{
	}
	
	PlayerService::PlayerService()
	#ifdef __SERVER__
		: mPlayerId (0)
	#endif
	{
	#ifdef __SERVER__
		mSingleWires.clear();
		mPlayers.clear();
	#endif
	}
	
	PlayerService::~PlayerService()
	{
	#ifdef __SERVER__
		mSingleWires.clear();
		mPlayers.clear();
		mPlayerId = 0;
	#endif
	}
	
	static PreInit<PlayerService> sPlayerServicePreInit;
}
#endif