#include "../Include.h"

namespace std {

	void Robot::setWireId(const __i16 nWireId)
	{
		mWireId = nWireId;
	}
	
	__i16 Robot::getWireId() const
	{
		return mWireId;
	}
	
	void Robot::runSwitch()
	{
		mInSwitch = true;
	}
	
	void Robot::runUnSwitch()
	{
		mInSwitch = false;
	}
	
	bool Robot::inSwitch() const
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
	
	bool Robot::inLock() const
	{
		return (mInLock > 0);
	}
	
	Robot::Robot()
		: mRobotType (RobotType_::mRobot_)
		, mInSwitch(false)
		, mInLock(0)
		, mWireId(0)
	{
	}
	
	Robot::Robot(const RobotType_ nRobotType)
		: mRobotType (nRobotType)
		, mInSwitch(false)
		, mInLock(0)
		, mWireId(0)
	{
	}

	Robot::~Robot()
	{
		mRobotType = RobotType_::mRobot_;
		mInSwitch = false;
		mInLock = 0;
		mWireId = 0;
	}

}
