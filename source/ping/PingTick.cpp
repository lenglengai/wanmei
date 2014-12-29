#include "../Logic.h"

#ifdef __PING__
namespace std {

#ifdef __CLIENT__
	void PingTick::runContext()
	{
		SessionService& sessionService_ = Singleton<SessionService>::instance();
		SessionPtr& session_ = sessionService_.getSession();
		if (!session_->isSendTick()) return;
		__i32 second_ = session_->getSecond();
		PacketPtr packet_(new C2SPing(second_));
		if (session_->runSend(packet_)) {
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
