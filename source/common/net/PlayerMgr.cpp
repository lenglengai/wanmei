#include "../Common.h"

#ifdef __SERVER__
namspace std{

	PlayerPtr& PlayerMgr::generatePlayer()
	{
		std::lock_guard<std::mutex> lock_(mMutex);
		PlayerPtr result_(new Player());
		result_->setPlayerId(mPlayerId);
		mPlayers.push_back(result_);
		++mPlayerId;
	}
	
	PlayerMgr::PlayerMgr()
		: mPlayerId (1)
	{
		mPlayers.clear();
	}
	
	PlayerMgr::~PlayerMgr()
	{
		mPlayers.clear();
		mPlayerId = 1;
	}

}
#endif