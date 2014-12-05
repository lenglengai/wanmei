#include "../../include/Include.h"

namespace std {

	void Robot::setWireId(__i16 nWireId)
	{
		mWireId = nWireId;
	}
	
	__i16 Robot::getWireId()
	{
		return mWireId;
	}
	
	void Robot::setSwitch(bool nSwitch)
	{
		mInSwitch = nSwitch;
	}
	
	bool Robot::inSwitch()
	{
		return (true == mInSwitch);
	}
	
	void Robot::setLock(bool nLock)
	{
		mInLock = nLock;
	}
	
	bool Robot::inLock()
	{
		return (true == mInLock);
	}
	
	Robot::Robot()
		: mRobotType (RobotType_::mRobot_)
		, mInSwitch(false)
		, mInLock(false)
		, mWireId(0)
	{
	}
	
	Robot::Robot(RobotType_ nRobotType)
		: mRobotType (nRobotType)
		, mInSwitch(false)
		, mInLock(false)
		, mWireId(0)
	{
	}

	Robot::~Robot()
	{
		mRobotType = RobotType_::mRobot_;
		mInSwitch = false;
		mInLock = false;
		mWireId = 0;
	}

}
