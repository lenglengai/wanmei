#include "../../include/Include.h"

namespace std{

	bool PlayerService::pushPacket(PacketPtr& nPacket, PlayerPtr& nPlayer)
	{
	#ifdef __SERVER__
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
	
	bool PlayerService::switchWire(PlayerPtr& nPlayer, __i16 nWireId)
	{
		if ( nPlayer->inLock() ) {
			return false;
		]
		__i16 wireId_ = nPlayer->getWireId();
		auto it = mPlayerCounts.find(nWireId);
		if (it == mPlayerCounts.end()) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nWireId));
			return false;
		}
		std::lock_guard<std::mutex> lock_(mMutex);
		if (it.second >= mMaxCount) {
			return false;
		}
	}
	
#ifdef __SERVER__
	PlayerPtr& PlayerService::generatePlayer()
	{
		PlayerPtr player_(new Player());
		++mPlayerId;
		player_->setPlayerId(mPlayerId);
		std::lock_guard<std::mutex> lock_(mMutex);
		__i16 wireId_ = this->runWireId();
		if (0 == wireId_) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(nWireId));
			return __defaultptr<Player>();
		}
		player_->setWireId(wireId_);
		mPlayers[mPlayerId] = player_;
		return mPlayers[mPlayerId];
	}
	
	__i16 PlayerService::runWireId()
	{
		__i16 playerCount_ = 30000;
		__i16 singleWire_ = 30000;
		__i16 tempCount_ = 0;
		for ( auto& it : mPlayerCounts ) {
			tempCount_ = it.second;
			if (tempCount_ < playerCount_) {
				playerCount_ = tempCount_;
				singleWire_ = it.first;
			}
		}
		if (playerCount_ >= mMaxCount) {
			return 0;
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
		mMaxCount = 1000;
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
