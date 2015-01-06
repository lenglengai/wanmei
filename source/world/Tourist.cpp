#include "../Include.h"

namespace std {

	void Tourist::setPlayerId(const __i64 nPlayerId)
	{
		mPlayerId = nPlayerId;
	}
	
	__i64 Tourist::getPlayerId() const
	{
		return mPlayerId;
	}

	Tourist::Tourist()
		: Robot (RobotType_::mTourist_)
		, mPlayerId (0)
	{
	}
	
	Tourist::Tourist(const RobotType_ nRobotType)
		: Robot (nRobotType)
		, mPlayerId (0)
	{
	}

	Tourist::~Tourist()
	{
		mPlayerId = 0;
	}

}
