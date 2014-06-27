
#include "../com.common/DefInc.h"
#include "../com.random/RandomService.h"
#include "../com.client/Client.h"
#include "../com.handle/HandleService.h"
#include "../com.init/InitService.h"
#include "PingService.h"

namespace std {

	bool C2SPing::runBlock(BlockPtr& nBlock)
	{
		IPacket::runBlock(nBlock);
		nBlock->runInt32(mSecond);
		return true;
	}

	void C2SPing::setSecond(__i32 nSecond)
	{
	std::cout << "c2sping set second" << mSecond << std::endl;
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

	bool S2CPing::runBlock(BlockPtr& nBlockPtr)
	{
		nBlockPtr->runInt32(mSecond);
		return true;
	}

	bool S2CPing::isDefault()
	{
		return (0 == mSecond);
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
#define PACKETRUNREG(x) internalCreatePacket<x>, boost::bind(&PingProtocol::run##x, &(Singleton<PingProtocol>::instance()), _1, _2)

#ifdef __SERVER__
	#define PACKETRUNSIZE 1
 	static PacketRun sPacketRun[PACKETRUNSIZE] = {
 		{ PACKETRUNREG(C2SPing) }
 	};
 	bool PingProtocol::runC2SPing(PacketPtr& nPacket, SessionPtr& nSession)
	{
		C2SPingPtr recvPacket_ = boost::dynamic_pointer_cast<C2SPing>(nPacket);
		__i32 second_ = nSession->getSecond();
		if (second_ != recvPacket_->getSecond()) {
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
#ifdef __CLIENT__
	#define PACKETRUNSIZE 1
 	static PacketRun sPacketRun[PACKETRUNSIZE] = {
 		{ PACKETRUNREG(S2CPing) }
 	};
 	bool PingProtocol::runS2CPing(PacketPtr& nPacket, SessionPtr& nSession)
	{
		S2CPingPtr recvPacket_ = boost::dynamic_pointer_cast<S2CPing>(nPacket);
		__i32 second_ = recvPacket_->getSecond();
		nSession->setSecond(second_);
		PingService& pingService_ = Singleton<PingService>::instance();
		pingService_.endPing();
		return true;
	}
#endif

	void PingProtocol::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunStart.connect(boost::bind(&PingService::runStart, this));
	#ifdef __CLIENT__
		PingServicePtr& pingService_ = SingletonPtr<PingService>::instance();
		pingService_->runPreinit();
	#endif
	}

	void PingProtocol::runStart()
	{
	#ifdef __CLIENT__
		PingServicePtr& pingService_ = SingletonPtr<PingService>::instance();
		pingService_->runStart();
	#endif
	}
	PacketRun * PingProtocol::getPacketRun(__i16 nPacketType)
	{
 		if ( (nPacketType <= PACKETRUNSIZE) && (nPacketType > 0) ) {
 			return (&sPacketRun[nPacketType]);
 		}
		return nullptr;
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
