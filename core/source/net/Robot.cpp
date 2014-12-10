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
	
	void Robot::setSwitch(__i64 nSwitch)
	{
		mInSwitch = nSwitch;
	}
	
	bool Robot::inSwitch()
	{
		return (true == mInSwitch);
	}
	
	void Robot::runLock()
	{
		mInLock++;
	}
	
	void Robot::runUnLock()
	{
		mInLock--;
	}
	
	bool Robot::inLock()
	{
		return (mInLock > 0);
	}
	
	Robot::Robot()
		: mRobotType (RobotType_::mRobot_)
		, mInSwitch(0)
		, mInLock(0)
		, mWireId(0)
	{
	}
	
	Robot::Robot(RobotType_ nRobotType)
		: mRobotType (nRobotType)
		, mInSwitch(0)
		, mInLock(0)
		, mWireId(0)
	{
	}

	Robot::~Robot()
	{
		mRobotType = RobotType_::mRobot_;
		mInSwitch = 0;
		mInLock = 0;
		mWireId = 0;
	}

}
