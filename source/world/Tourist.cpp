#include "../Include.h"

namespace std {

	void Tourist::setPlayerId(const __i64 nPlayerId)
	{
		mPlayerId = nPlayerId;
	}
	
	__i64 Tourist::getPlayerId() const
	{
		return mPlayerId;
	}

	Tourist::Tourist()
		: mPlayerType (PlayerType_::mPlayer_)
		, mPlayerId (0)
	{
	}
	
	Tourist::Tourist(const PlayerType_ nPlayerType)
		: mPlayerType (nPlayerType)
		, mPlayerId (0)
	{
	}

	Tourist::~Tourist()
	{
		mPlayerType = PlayerType_::mPlayer_;
		mPlayerId = 0;
	}

}
