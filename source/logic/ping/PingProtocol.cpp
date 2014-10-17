#include "../LogicInc.h"

#ifdef __PING__
namespace std {

	const char * C2SPing::sPacketName = "C2SPing";

#ifdef __SERVER__
	bool C2SPing::handleRun(PlayerPtr& nPlayer)
	{
		PropertyId<PingSecond> pingSecondId;
		PropertyPtr& property_ = nPlayer->getProperty(pingSecondId);
		PingSecondPtr pingSecondPtr_ = std::dynamic_pointer_cast<PingSecond, Property>(property_);
		__i32 second_ = pingSecondPtr_->getSecond();
		if (second_ != mSecond) return false;
		RandomService& randomService_ = Singleton<RandomService>::instance();
		second_ = randomService_.runRandom();
		pingSecondPtr_->setSecond(second_);
		PacketPtr packet_(new S2CPing(second_));
		nPlayer->runSend(packet_);
		return true;
	}
#endif
	
	bool C2SPing::runBlock(BlockPtr& nBlock)
	{
		nBlock->runInt32(mSecond);
		return true;
	}

	void C2SPing::setSecond(__i32 nSecond)
	{
		mSecond = nSecond;
	}

	__i32 C2SPing::getSecond()
	{
		return mSecond;
	}

	C2SPing::C2SPing()
		: mSecond(0)
	{
	}

	C2SPing::C2SPing(__i32 nSecond)
		: mSecond(nSecond)
	{
	}

	C2SPing::~C2SPing()
	{
		mSecond = 0;
	}

	const char * S2CPing::sPacketName = "S2CPing";
	
#ifdef __CLIENT__
	bool S2CPing::handleRun(PlayerPtr& nPlayer)
	{
		PingProtocol& pingProtocol_ = Singleton<PingProtocol>::instance();
		pingProtocol_.endPing();
		PropertyId<PingSecond> pingSecondId;
		PropertyPtr& property_ = nPlayer->getProperty(pingSecondId);
		PingSecondPtr pingSecondPtr_ = std::dynamic_pointer_cast<PingSecond, Property>(property_);
		pingSecondPtr_->setSecond(mSecond);
		return true;
	}
#endif

	const char * S2CPing::getPacketName()
	{
		return "C2SPing";
	}

	bool S2CPing::runBlock(BlockPtr& nBlock)
	{
		nBlock->runInt32(mSecond);
		return true;
	}

	bool S2CPing::isDefault()
	{
		if (0 == mSecond) return true;
		return IPacket::isDefault();
	}

	void S2CPing::setSecond(__i32 nSecond)
	{
		mSecond = nSecond;
	}

	__i32 S2CPing::getSecond()
	{
		return mSecond;
	}

	S2CPing::S2CPing()
		: mSecond(0)
	{
	}

	S2CPing::S2CPing(__i32 nSecond)
		: mSecond(nSecond)
	{
	}

	S2CPing::~S2CPing()
	{
		mSecond = 0;
	}

#ifdef __CLIENT__
	void PingTick::pushPacket(PacketPtr& nPacket)
	{
		boost::shared_lock<boost::shared_mutex> writeLock(mMutex);
		mPackets.push_back(nPacket);
	}

	PacketPtr PingTick::popPacket()
	{
		PacketPtr packet_;
		boost::shared_lock<boost::shared_mutex> readLock(mMutex);
		if (mPackets.size() > 0) {
			packet_ = mPackets.front();
			mPackets.pop_front();
		}
		return packet_;
	}

	void PingTick::handlePing()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		if (initService_.isPause()) return;
		TimeService& timeService_ = Singleton<TimeService>::instance();
		__i64 second_ = timeService_.getNowSecond();
		__i64 clock_ = second_ - mSendTick;
		if (clock_ < 70) return;
		PlayerPtr& player_ = SingletonPtr<PlayerPtr>::instance();
		PropertyId<PingSecond> proertyId_;
		PropertyPtr& property_ = player_->getProperty(proertyId_);
		PingSecondPtr pingSecondPtr_ = std::dynamic_pointer_cast<PingSecond, Property>(property_);
		__i32 pingSecond_ = pingSecondPtr_->getSecond();
		PacketPtr packet_(new C2SPing(pingSecond_));
		if (player_->runSend(packet_)) {
			mPingProtocol->begPing();
			mSendTick = second_;
		}
	}

	void PingTick::runContext()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		if (initService_.isPause()) return;
		PacketPtr packet_ = this->popPacket();
		if (packet_) {
			PlayerPtr& player_ = SingletonPtr<PlayerPtr>::instance();
			packet_->handleRun(player_);
		}
		this->handlePing();
	}

	PingTick::PingTick(PingProtocol * nPingProtocol)
		: mPingProtocol(nPingProtocol)
		, mSendTick(0)
	{
		mPackets.clear();
	}

	PingTick::~PingTick()
	{
		mPingProtocol = nullptr;
		mPackets.clear();
		mSendTick = 0;
	}
#endif

	void PingSecond::setSecond(__i32 nSecond)
	{
		mSecond = nSecond;
	}

	__i32 PingSecond::getSecond()
	{
		return mSecond;
	}

	PingSecond::PingSecond()
		: mSecond(0)
	{
	}

	PingSecond::~PingSecond()
	{
		mSecond = 0;
	}

	bool PingProtocol::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&PingProtocol::runInit, this));
		initService_.m_tRunStart0.connect(boost::bind(&PingProtocol::runStart, this));
		
		return true;
	}

	void PingProtocol::runInit()
	{
		ProtocolService& protocolService_ =  Singleton<ProtocolService>::instance();
		protocolService_.runRegister(this);

	#ifdef __CLIENT__
		TcpClient& tcpClient_ = Singleton<TcpClient>::instance();
		PropertyIdPtr propertyIdPtr_ = PropertyIdPtr(new PropertyId<PingSecond>());
		tcpClient_.registerCreate(propertyIdPtr_);

		mPingTick.reset(new PingTick(this));

		this->addPacketId(PacketIdPtr(new PacketId<S2CPing>()));
	#endif

	#ifdef __SERVER__
		TcpServer& tcpServer_ = Singleton<TcpServer>::instance();
		PropertyIdPtr propertyIdPtr_ = PropertyIdPtr(new PropertyId<PingSecond>());
		tcpServer_.registerCreate(propertyIdPtr_);

		this->addPacketId(PacketIdPtr(new PacketId<C2SPing>()));
	#endif
	}

	void PingProtocol::runStart()
	{
	#ifdef __CLIENT__
		HandleService& handleService_ = Singleton<HandleService>::instance();
		ContextPtr context_ = mPingTick;
		handleService_.addContext(context_, 1);
	#endif
	}

#ifdef __CLIENT__
	bool PingProtocol::runPacket(PacketPtr& nPacket, SessionPtr& nSession)
	{
		mPingTick->pushPacket(nPacket);
		return true;
	}

	void PingProtocol::begPing()
	{
		TimeService& timeService_ = Singleton<TimeService>::instance();
		mClock = timeService_.getNowSecond();
	}

	void PingProtocol::endPing()
	{
		TimeService& timeService_ = Singleton<TimeService>::instance();
		__i64 second_ = timeService_.getNowSecond();
		mPing = second_ - mClock;
	}
#endif

	const char * PingProtocol::getProtocolName()
	{
		return "PingProtocol";
	}

	PingProtocol::PingProtocol()
#ifdef __CLIENT__
		: mClock(0)
		, mPing(0)
#endif
	{
	}

	PingProtocol::~PingProtocol()
	{
#ifdef __CLIENT__
		mClock = 0;
		mPing = 0;
#endif
	}

}
#endif
