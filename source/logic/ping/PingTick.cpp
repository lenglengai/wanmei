#include "../LogicInc.h"

#ifdef __PING__
namespace std {

#ifdef __CLIENT__
	void PingTick::handlePing()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		if (initService_.isPause()) return;
		TimeService& timeService_ = Singleton<TimeService>::instance();
		__i64 second_ = timeService_.getNowSecond();
		__i64 clock_ = second_ - mSendTick;
		if (clock_ < 70) return;
		PlayerPtr& player_ = SingletonPtr<Player>::instance();
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
			PlayerPtr& player_ = SingletonPtr<Player>::instance();
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
	
}
#endif
