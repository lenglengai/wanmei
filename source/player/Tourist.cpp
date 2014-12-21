#include "../Include.h"

namespace std {

	void Tourist::setPlayerId(__i64 nPlayerId)
	{
		mPlayerId = nPlayerId;
	}
	
	__i64 Tourist::getPlayerId()
	{
		return mPlayerId;
	}

	Tourist::Tourist()
		: Robot (RobotType_::mTourist_)
		, mPlayerId (0)
	{
	}
	
	Tourist::Tourist(RobotType_ nRobotType)
		: Robot (nRobotType)
		, mPlayerId (0)
	{
	}

	Tourist::~Tourist()
	{
		mPlayerId = 0;
	}

}
