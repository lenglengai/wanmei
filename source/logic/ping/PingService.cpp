#include "../../common/DefInc.h"

#include "../../common/random/RandomService.h"
#include "../../common/time/TimeService.h"
#include "../../common/handle/HandleService.h"
#include "../../common/init/InitService.h"
#include "../../common/property/PropertyId.h"
#include "../../common/net/ProtocolService.h"
#include "../../common/net/Client.h"
#include "../../common/net/Server.h"

#include "PingService.h"

#ifdef __PING__
namespace std {

	const char * C2SPing::sPacketName = "C2SPing";

#ifdef __CLTRECV__
	bool C2SPing::handleRun(SessionPtr& nSession)
	{
		PropertyId<PingSecond> pingSecondId;
		PropertyPtr& property_ = nSession->getProperty(pingSecondId);
		PingSecondPtr pingSecondPtr_ = std::dynamic_pointer_cast<PingSecond, Property>(property_);
		__i32 second_ = pingSecondPtr_->getSecond();
		if (second_ != mSecond) return false;
		RandomService& randomService_ = Singleton<RandomService>::instance();
		second_ = randomService_.runRandom();
		pingSecondPtr_->setSecond(second_);
		PacketPtr packet_(new S2CPing(second_));
		nSession->runSend(packet_);
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
	
#ifdef __CLTRECV__
	bool S2CPing::handleRun(SessionPtr& nSession)
	{
		PingProtocol& pingProtocol_ = Singleton<PingProtocol>::instance();
		pingProtocol_.endPing();
		PropertyId<PingSecond> pingSecondId;
		PropertyPtr& property_ = nSession->getProperty(pingSecondId);
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

#ifdef __CLTRECV__
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
		Client& client_ = Singleton<Client>::instance();
		SessionPtr& session_ = client_.getSession();
		PropertyId<PingSecond> proertyId_;
		PropertyPtr& property_ = session_->getProperty(proertyId_);
		PingSecondPtr pingSecondPtr_ = std::dynamic_pointer_cast<PingSecond, Property>(property_);
		__i32 pingSecond_ = pingSecondPtr_->getSecond();
		PacketPtr packet_(new C2SPing(pingSecond_));
		if (session_->runSend(packet_)) {
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
			Client& client_ = Singleton<Client>::instance();
			SessionPtr& session_ = client_.getSession();
			packet_->handleRun(session_);
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

	void PingProtocol::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&PingProtocol::runInit, this));
		initService_.m_tRunStart0.connect(boost::bind(&PingProtocol::runStart, this));
	}

	void PingProtocol::runInit()
	{
		ProtocolService& protocolService_ = 
			Singleton<ProtocolService>::instance();
		protocolService_.runRegister(this);

	#ifdef __CLTRECV__
		Client& client_ = Singleton<Client>::instance();
		PropertyIdPtr propertyIdPtr_ = PropertyIdPtr(new PropertyId<PingSecond>());
		client_.registerCreate(propertyIdPtr_);

		mPingTick.reset(new PingTick(this));

		this->addPacketId(PacketIdPtr(new PacketId<S2CPing>()));
	#endif

	#ifdef __SEVRECV__
		Server& server_ = Singleton<Server>::instance();
		PropertyIdPtr propertyIdPtr_ = PropertyIdPtr(new PropertyId<PingSecond>());
		server_.registerCreate(propertyIdPtr_);

		this->addPacketId(PacketIdPtr(new PacketId<C2SPing>()));
	#endif
	}

	void PingProtocol::runStart()
	{
	#ifdef __CLIENT__
		HandleService& handleService_ = 
			Singleton<HandleService>::instance();
		ContextPtr context_ = mPingTick;
		handleService_.addContext(context_, 1);
	#endif
	}

#ifdef __CLTRECV__
	bool PingProtocol::runPacket(PacketPtr& nPacket, SessionPtr& nSession)
	{
		mPingTick->pushPacket(nPacket);
		return true;
	}

	void PingProtocol::begPing()
	{
		TimeService& timeService_ =
			Singleton<TimeService>::instance();
		mClock = timeService_.getNowSecond();
	}

	void PingProtocol::endPing()
	{
		TimeService& timeService_ =
			Singleton<TimeService>::instance();
		__i64 second_ = timeService_.getNowSecond();
		mPing = second_ - mClock;
	}
#endif

	const char * PingProtocol::getProtocolName()
	{
		return "PingProtocol";
	}

	PingProtocol::PingProtocol()
#ifdef __CLTRECV__
		: mClock(0)
		, mPing(0)
#endif
	{
	}

	PingProtocol::~PingProtocol()
	{
#ifdef __CLTRECV__
		mClock = 0;
		mPing = 0;
#endif
	}

}
#endif
