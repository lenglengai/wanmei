#include "../Common.h"

#ifdef __NET__
namespace std {

	__i16 Robot::getContextId()
	{
		return mContextId;
	}
	
	bool Robot::isInSwitch()
	{
		return (true == mInSwitch);
	}
	
	Robot::Robot()
		: mRobotType (RobotType_::mRobot_)
		, mContextId(0)
		, mInSwitch(false)
	{
	}
	
	Robot::Robot(RobotType_ nRobotType)
		: mRobotType (nRobotType)
		, mContextId(0)
		, mInSwitch(false)
	{
	}

	Robot::~Robot()
	{
		mRobotType = RobotType_::mRobot_;
		mInSwitch = false;
		mContextId = 0;
	}
	
	SessionPtr& Player::getSession()
	{
		return mSession;
	}
	
#ifdef __CLIENT__
	Player::Player()
		: Robot (RobotType_::mPlayer_)
	{
	}
#else
	Player::Player(SessionPtr& nSession)
		: Robot (RobotType_::mTourist_)
		, mSession (nSession)
	{
	}
#endif
	Player::~Player()
	{
	}
#ifdef __CLIENT__
	static PreinitPtr<Player> sPlayerPreinit;
#endif
#ifdef __SERVER__
	PlayerMgr::PlayerMgr()
	{
		mPlayers.clear();
	}
	
	PlayerMgr::~PlayerMgr()
	{
		mPlayers.clear();
	}
#endif

}
#endif
