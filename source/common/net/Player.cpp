#include "../Common.h"

namespace std {

	void Player::setPlayerId(__i64 nPlayerId)
	{
		mPlayerId = nPlayerId;
	}
	
	SessionPtr& Player::getSession()
	{
		return mSession;
	}
	
	Player::Player()
		: Robot (RobotType_::mPlayer_)
		, mPlayerId (0)
	{
	}

	Player::~Player()
	{
		mPlayerId = 0;
	}
	
#ifdef __CLIENT__
	static PreinitPtr<Player> sPlayerPreinit;
#endif

}
