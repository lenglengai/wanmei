#include "../../common/DefInc.h"

#include "../../service/random/RandomService.h"
#include "../../service/time/TimeService.h"
#include "../../service/handle/HandleService.h"
#include "../../service/init/InitService.h"
#include "../../net/packet/ProtocolService.h"
#include "../../net/client/Client.h"

#include "PingService.h"

namespace std {

	const char * C2SPing::sPacketName = "C2SPing";

#ifdef __SERVER__
	bool C2SPing::handleRun(SessionPtr& nSession)
	{
		PingProtocol& pingProtocol_ = 
			Singleton<PingProtocol>::instance();
		__i32 second_ = pingProtocol_.getSecond();
		if (second_ != mSecond) return false;
		RandomService& randomService_ =
			Singleton<RandomService>::instance();
		second_ = randomService_.runRandom();
		pingProtocol_.setSecond(second_);
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
	
#ifdef __CLIENT__
	bool S2CPing::handleRun(SessionPtr& nSession)
	{
		PingProtocol& pingProtocol_ = 
			Singleton<PingProtocol>::instance();
		pingProtocol_.setSecond(mSecond);
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
		InitService& initService_ = 
			Singleton<InitService>::instance();
		if (initService_.isPause()) return;
		TimeService& timeService_ = 
			Singleton<TimeService>::instance();
		__i64 second_ = timeService_.getNowSecond();
		__i64 clock_ = second_ - mSendTick;
		if (clock_ < 90) return;
		__i32 pingSecond_ = mPingProtocol->getSecond();
		PacketPtr packet_(new C2SPing(pingSecond_));
		Client& client_ = Singleton<Client>::instance();
		SessionPtr& session_ = client_.getSession();
		if (session_->runSend(packet_)) {
			mPingProtocol->begPing();
			mSendTick = second_;
		}
		else {
			initService_.runPause(true);
		}
	}

	void PingTick::runContext()
	{
		InitService& initService_ = 
			Singleton<InitService>::instance();
		if (initService_.isPause()) return;
		PacketPtr packet_ = this->popPacket();
		if (packet_) {
			packet_->handleRun(SessionPtr());
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

	void PingProtocol::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit.connect(boost::bind(&PingProtocol::runInit, this));
		initService_.m_tRunStart.connect(boost::bind(&PingProtocol::runStart, this));
	}

	void PingProtocol::runInit()
	{
		ProtocolService& protocolService_ = 
			Singleton<ProtocolService>::instance();
		protocolService_.runRegister(this);
	#ifdef __CLIENT__
		this->addPacketId(PacketIdPtr(new PacketId<S2CPing>()));
		mPingTick.reset(new PingTick(this));
	#endif
	#ifdef __SERVER__
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

#ifdef __CLIENT__
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

	void PingProtocol::setSecond(__i32 nSecond)
	{
		mSecond = nSecond;
	}

	__i32 PingProtocol::getSecond()
	{
		return mSecond;
	}

	PingProtocol::PingProtocol()
		: mSecond(0)
#ifdef __CLIENT__
		, mClock(0)
		, mPing(0)
#endif
	{

	}

	PingProtocol::~PingProtocol()
	{
		mSecond = 0;
#ifdef __CLIENT__
		mClock = 0;
		mPing = 0;
#endif
	}

}
