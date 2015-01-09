#pragma once

namespace std {
	
	enum class PlayerType_ : __i8
	{
		mPlayer_,
		mAdministrator_,
		mDeveloper_
	};
	
	class Tourist
	{
	public:
		void setPlayerId(const __i64 nPlayerId);
		__i64 getPlayerId() const;
		
		Tourist();
		Tourist(const PlayerType_ nPlayerType);
		virtual ~Tourist();
		
	private:
		PlayerType_ mPlayerType;
		__i64 mPlayerId;
	};
	typedef shared_ptr<Tourist> TouristPtr;
	
}
