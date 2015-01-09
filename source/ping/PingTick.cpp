#include "../Logic.h"
#include "C2SPing.h"
#include "PingTick.h"

#ifdef __PING__
namespace std {

#ifdef __CLIENT__
	void PingTick::runContext()
	{
		SessionService& sessionService_ = Service<SessionService>::instance();
		SessionPtr& session_ = sessionService_.getSession();
		if (!session_) return;
		if (!session_->isSendTick()) return;
		__i32 second_ = session_->getSecond();
		PacketPtr packet_(new C2SPing(second_));
		if (session_->runSend(packet_)) {
			PingProtocol& pingProtocol_ = Service<PingProtocol>::instance();
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
