#pragma once

namespace std {

	enum class RobotType_ : __i16
	{
		mRobot_,
		mTourist_,
		mPlayer_,
		mAdministrator_,
		mDeveloper_
	};
	
	class Robot : public PropertyMgr
	{
	public:
		void setWireId(__i16 nWireId);
		__i16 getWireId();
		void runSwitch();
		void runUnSwitch();
		bool inSwitch();
		void runLock();
		void runUnLock();
		bool inLock();
		
		Robot();
		Robot(RobotType_ nRobotType);
		virtual ~Robot();
		
	private:
		atomic<bool> mInSwitch;
		atomic<__i32> mInLock;
		RobotType_ mRobotType;
		__i16 mWireId;
	};
	
}
