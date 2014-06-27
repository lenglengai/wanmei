
#include "../com.common/DefInc.h"
#include "../com.random/RandomService.h"
#include "../com.client/Client.h"
#include "../com.handle/HandleService.h"
#include "../com.init/InitService.h"
#include "PingService.h"

namespace std {

#ifdef __SERVER__
	bool C2SPing::handleRun(SessionPtr& nSession)
	{
		__i32 second_ = nSession->getSecond();
		if (second_ != mSecond) {
			return false;
		}
		RandomService& randomService_ = Singleton<RandomService>::instance();
		S2CPingPtr pingPacket_(new S2CPing()); 
		pingPacket_->setSecond(randomService_.runRandom());
		PacketPtr packet_ = pingPacket_;
		nSession->runSend(packet_);
		return true;
	}
#endif

	bool C2SPing::runBlock(BlockPtr& nBlock)
	{
		IPacket::runBlock(nBlock);
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

	C2SPing::~C2SPing()
	{
		mSecond = 0;
	}

#ifdef __CLIENT__
	bool S2CPing::handleRun(SessionPtr& nSession)
	{
		nSession->setSecond(mSecond);
		PingService& pingService_ = Singleton<PingService>::instance();
		pingService_.endPing();
		return true;
	}
#endif

	bool S2CPing::runBlock(BlockPtr& nBlockPtr)
	{
		IPacket::runBlock(nBlock);
		nBlockPtr->runInt32(mSecond);
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

	S2CPing::~S2CPing()
	{
		mSecond = 0;
	}


	void PingProtocol::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit.connect(boost::bind(&PingService::runInit, this));
		initService_.m_tRunStart.connect(boost::bind(&PingService::runStart, this));
	#ifdef __CLIENT__
		PingServicePtr& pingService_ = SingletonPtr<PingService>::instance();
		pingService_->runPreinit();
	#endif
	}

	void PingProtocol::runInit()
	{
	#ifdef __CLIENT__
		this->addPacketId(PacketIdPtr(PacketId<S2CPing>()));
	#endif
	#ifdef __SERVER__
		this->addPacketId(PacketIdPtr(PacketId<C2SPing>()));
	#endif
	}

	void PingProtocol::runStart()
	{
	#ifdef __CLIENT__
		PingServicePtr& pingService_ = SingletonPtr<PingService>::instance();
		pingService_->runStart();
	#endif
	}

	const char *  PingProtocol::getProtocolName()
	{
		return "PingProtocol";
	}

	PingProtocol::PingProtocol()
	{
	}

	PingProtocol::~PingProtocol()
	{
	}

#ifdef __CLIENT__
	void PingService::runContext()
	{
		clock_t clock_ = clock() - mSendTick;
		clock_ /= CLOCKS_PER_SEC;
		if (clock_ < 5) return;
		std::cout << "send ping packet!" << std::endl;
		Client& client_ = Singleton<Client>::instance();
		SessionPtr& session_ = client_.getSession();
		__i32 sessionState_ = session_->getSessionState();
		if (SessionState_::mClosed_ == sessionState_) {
			return;
		}
		C2SPingPtr pingPacket_(new C2SPing());
		pingPacket_->setSecond(session_->getSecond());
		PacketPtr packet_ = pingPacket_;
		session_->runSend(packet_);
		mSendTick = clock();
	}

	void PingService::runPreinit()
	{
	}

	void PingService::runStart()
	{
		HandleService& handleService_ = Singleton<HandleService>::instance();
		ContextPtr context_ = shared_from_this();
		handleService_.addContext(context_, 1);
	}

	void PingService::setSendTick(clock_t nSendTick)
	{
		mSendTick = nSendTick;
	}

	clock_t PingService::getSendTick()
	{
		return mSendTick;
	}

	void PingService::begPing()
	{
		mClock = clock();
	}

	void PingService::endPing()
	{
		mPing = clock() - mClock;
	}

	PingService::PingService()
		: mSendTick(0)
		, mClock(0)
		, mPing(0)
	{
	}

	PingService::~PingService()
	{
		mSendTick = 0;
		mClock = 0;
		mPing = 0;
	}
#endif

}
