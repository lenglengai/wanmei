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
	
	class Player : public Robot
	{
	public:
		SessionPtr& getSession();
	#ifdef __CLIENT__
		Player();
	#else
		explicit Player(SessionPtr& nSession);
	#endif
		virtual ~Player();
		
	private:
	    SessionPtr mSession;
	};
	typedef std::weak_ptr<Player> PlayerWtr;
    typedef std::shared_ptr<Player> PlayerPtr;
	
#ifdef __SERVER__
	class PlayerMgr : boost::noncopyable
	{
	public:
		
		PlayerMgr();
		~PlayerMgr();
	
	private:
		std::map<__i64, PlayerPtr> mPlayers;
		std::atomic<__i64> mPlayerId;
	};
#endif
	
}
#endif
