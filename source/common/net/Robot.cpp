#include "../Common.h"

#ifdef __NET__
namespace std {

	void Robot::setWireId(__i16 nWireId)
	{
		mWireId = nWireId;
	}
	
	__i16 Robot::getWireId()
	{
		return mWireId;
	}
	
	bool Robot::isInSwitch()
	{
		return (true == mInSwitch);
	}
	
	Robot::Robot()
		: mRobotType (RobotType_::mRobot_)
		, mInSwitch(false)
		, mWireId(0)
	{
	}
	
	Robot::Robot(RobotType_ nRobotType)
		: mRobotType (nRobotType)
		, mInSwitch(false)
		, mWireId(0)
	{
	}

	Robot::~Robot()
	{
		mRobotType = RobotType_::mRobot_;
		mInSwitch = false;
		mWireId = 0;
	}

}
#endif
