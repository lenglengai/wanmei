#include "../Include.h"

namespace std {

	bool Player::runSend(PacketPtr& nPacket)
	{
#ifdef __CLIENT__
		TimeService& timeService_ = Singleton<TimeService>::instance();
		mSendTick = timeService_.getLocalTime();
#endif
		return mSession->runSend(nPacket);
	}
	
#ifdef __CLIENT__
	bool Player::isSendTick()
	{
		TimeService& timeService_ = Singleton<TimeService>::instance();
		__i64 second_ = timeService_.getLocalTime();
		return ( (second_ - mSendTick) > 280 );
	}
#endif

	Player::Player(SessionPtr& nSession)
		: Tourist (RobotType_::mPlayer_)
		, mSession (nSession)
#ifdef __CLIENT__
		, mSendTick (0)
#endif
	{
	}

	Player::~Player()
	{
#ifdef __CLIENT__
		mSendTick = 0;
#endif
	}
	
#ifdef __CLIENT__
	static PreinitPtr<Player> sPlayerPreinit;
#endif

}
