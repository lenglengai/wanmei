#pragma once

#ifdef __NET__
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
		bool isInSwitch();
		
		Robot();
		Robot(RobotType_ nRobotType);
		virtual ~Robot();
		
	private:
		std::atomic<bool> mInSwitch;
		RobotType_ mRobotType;
		__i16 mWireId;
	};
	
}
#endif
