#include "../LogicInc.h"

#ifdef __PING__
namespace std {

#ifdef __CLIENT__
	void PingTick::runContext()
	{
		PlayerPtr& player_ = SingletonPtr<Player>::instance();
		if (!player_->isSendTick()) return;
		PropertyId<PingSecond> proertyId_;
		PropertyPtr& property_ = player_->getProperty(proertyId_);
		PingSecondPtr pingSecondPtr_ = std::dynamic_pointer_cast<PingSecond, Property>(property_);
		__i32 pingSecond_ = pingSecondPtr_->getSecond();
		PacketPtr packet_(new C2SPing(pingSecond_));
		if (player_->runSend(packet_)) {
			PingProtocol& pingProtocol_ = Singleton<PingProtocol>::instance();
			pingProtocol_.startPing();
		}
	}

	PingTick::PingTick()
	{
	}

	PingTick::~PingTick()
	{
	}
#endif
	
}
#endif
