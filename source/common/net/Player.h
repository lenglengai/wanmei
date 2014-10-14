#pragma once

#ifdef __NET__
namespace std {

	enum class PlayerType_ : __i16
	{
		mTourist_,
		mGamer_,
		mAdministrator_,
		mRobot_,
		mDeveloper_
	};
	
	class Player
	{
	public:
		Player(SessionPtr& nSession);
		virtual ~Player();
		
	private:
		PlayerType_ mPlayerType;
	};
	
	class Player
	{
	public:
		Player(SessionPtr& nSession);
		virtual ~Player();
		
	private:
		SessionWtr mSession;
	};
	
}
#endif
