#include "../Common.h"

#ifdef __NET__
namespace std {

	bool Player::runSend(PacketPtr& nPacket)
	{
		return mSession->runSend(nPacket);
	}
	
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
#endif
