#include "../../include/Include.h"

namespace std{

	bool PlayerService::pushPacket(PacketPtr& nPacket, PlayerPtr& nPlayer)
	{
	#ifdef __SERVER__
		if (nPlayer->isInSwitch()) {
			LogService& logService_ = Singleton<LogService>::instance();
			__i32 protocolId = nPacket->getProtocolId();
			__i32 packetId = nPacket->getPacketId(); 
			logService_.logError(log_2(protocolId, packetId));
			return false;
		}
		nPacket->setPlayer(nPlayer);
		__i16 wireId = nPlayer->getWireId();
		auto it = mSingleWires.find(wireId);
		if ( it == mSingleWires.end())  {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(wireId));
			return false;
		}
		SingleWirePtr& singleWire_ = it->second;
		singleWire_->pushPacket(nPacket);
	#endif
	#ifdef __CLIENT__
		mSingleWire->pushPacket(nPacket);
	#endif
		return true;
	}
	
#ifdef __SERVER__
	PlayerPtr& PlayerService::generatePlayer()
	{
		PlayerPtr player_(new Player());
		std::lock_guard<std::mutex> lock_(mMutex);
		++mPlayerId;
		player_->setPlayerId(mPlayerId);
		__i16 wireId = this->runWireId();
		player_->setWireId(wireId);
		mPlayers[mPlayerId] = player_;
		return mPlayers[mPlayerId];
	}
	
	__i16 PlayerService::runWireId()
	{
		__i16 playerCount_ = 30000;
		__i16 singleWire_ = 30000;
		std::map<__i16, __i16>::iterator it = mPlayerCounts.begin();
		for ( ; it != mPlayerCounts.end(); ++it ) {
			__i16 tempWire_ = it->first;
			__i16 tempCount_ = it->second;
			if (tempCount_ < playerCount_) {
				playerCount_ = tempCount_;
				singleWire_ = tempWire_;
			}
		}
		mPlayerCounts[singleWire_] = playerCount_ + 1;
		return singleWire_;
	}
#endif
	
	bool PlayerService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&PlayerService::runInit, this));
		initService_.m_tRunStart0.connect(boost::bind(&PlayerService::runStart, this));

		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
		return true;
	}
	
	void PlayerService::runInit()
	{
	#ifdef __CLIENT__
		mSingleWire.reset(new SingleWire());
	#endif

	#if defined(__SERVER__) && defined(__WITHCPU__)
		CpuService& cpuService_ = Singleton<CpuService>::instance();
		__i16 cpuCount = cpuService_.getCpuCount();
		for ( __i16 i = 1; i <= cpuCount; ++i ) {
			SingleWirePtr singleWire_(new SingleWire());
			mSingleWires[i] = singleWire_;
			mPlayerCounts[i] = 0;
		}
	#endif
	
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}
	
	void PlayerService::runStart()
	{
		HandleService& handleService_ = Singleton<HandleService>::instance();
		
	#ifdef __CLIENT__
		mSingleWire.reset(new SingleWire());
		ContextPtr context_ = std::dynamic_pointer_cast<Context, SingleWire>(mSingleWire);
		handleService_.addContext(context_, 1);
	#endif

	#if defined(__SERVER__) && defined(__WITHCPU__)
		__i32 contextId_ = 1;
		auto it = mSingleWires.begin();
		for ( ; it != mSingleWires.end(); ++it ) {
			SingleWirePtr& singleWire_ = it->second;
			ContextPtr context_ = std::dynamic_pointer_cast<Context, SingleWire>(singleWire_);
			handleService_.addContext(context_, contextId_);
			contextId_++;
		}
	#endif
	
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	}
	
	void PlayerService::runClear()
	{
	#ifdef __SERVER__
		mPlayerCounts.clear();
		mSingleWires.clear();
		mPlayers.clear();
		mPlayerId = 0;
	#endif
	}
	
	PlayerService::PlayerService()
	{
		this->runClear();
	}
	
	PlayerService::~PlayerService()
	{
		this->runClear();
	}
	
	static Preinit<PlayerService> sPlayerServicePreInit;
}
