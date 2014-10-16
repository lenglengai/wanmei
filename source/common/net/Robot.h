#pragma once

#include <atomic>

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
	
	class Robot : boost::noncopyable
	{
	public:
		__i16 getContextId();
		bool isInSwitch();
		
		Robot();
		Robot(RobotType_ nRobotType);
		virtual ~Robot();
		
	private:
		RobotType_ mRobotType;
		__i16 mContextId;
		std::atomic<bool> mInSwitch;
	};
	
}
#endif
