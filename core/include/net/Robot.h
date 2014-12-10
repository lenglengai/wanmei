#pragma once

namespace std {

	enum class RobotType_ : __i16
	{
		mRobot_,
		mSomeone_,
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
		void setSwitch(bool nSwitch);
		bool inSwitch();
		void runLock();
		void runUnLock();
		bool inLock();
		
		Robot();
		Robot(RobotType_ nRobotType);
		virtual ~Robot();
		
	private:
		std::atomic<__i64> mInSwitch;
		std::atomic<__i16> mInLock;
		RobotType_ mRobotType;
		__i16 mWireId;
	};
	
}
