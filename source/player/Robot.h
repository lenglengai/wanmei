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
		void setWireId(const __i16 nWireId);
		__i16 getWireId() const;
		void runSwitch();
		void runUnSwitch();
		bool inSwitch() const;
		void runLock();
		void runUnLock();
		bool inLock() const;
		
		Robot();
		Robot(const RobotType_ nRobotType);
		virtual ~Robot();
		
	private:
		atomic<bool> mInSwitch;
		atomic<__i32> mInLock;
		RobotType_ mRobotType;
		__i16 mWireId;
	};
	
}
