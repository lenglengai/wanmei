#include "../../include/Include.h"

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

	void Player::setPlayerId(__i64 nPlayerId)
	{
		mPlayerId = nPlayerId;
	}
	
	SessionPtr& Player::getSession()
	{
		return mSession;
	}
	
#ifdef __CLIENT__
	bool Player::runPreinit()
	{
		return true;
	}
#endif

	Player::Player()
		: Robot (RobotType_::mPlayer_)
		, mPlayerId (0)
#ifdef __CLIENT__
		, mSendTick (0)
#endif
	{
	}

	Player::~Player()
	{
		mPlayerId = 0;
#ifdef __CLIENT__
		mSendTick = 0;
#endif
	}
	
#ifdef __CLIENT__
	static PreinitPtr<Player> sPlayerPreinit;
#endif

}
