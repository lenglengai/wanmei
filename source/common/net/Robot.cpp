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

}
#endif
