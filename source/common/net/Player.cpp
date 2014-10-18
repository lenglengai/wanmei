#include "../Common.h"

#ifdef __NET__
namespace std {

    bool Player::pushPacket(PacketPtr& nPacket)
	{
		return true;
	}

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
	
	bool Player::runPreinit()
	{
		return true;
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
#endif
