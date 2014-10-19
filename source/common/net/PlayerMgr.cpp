#include "../Common.h"

#ifdef __NET__
namespace std{

	PlayerPtr& PlayerMgr::generatePlayer()
	{
		std::lock_guard<std::mutex> lock_(mMutex);
		++mPlayerId;
		PlayerPtr player_(new Player());
		player_->setPlayerId(mPlayerId);
		mPlayers[mPlayerId] = player_;
		return mPlayers[mPlayerId];
	}
	
	PlayerMgr::PlayerMgr()
		: mPlayerId (0)
	{
		mPlayers.clear();
	}
	
	PlayerMgr::~PlayerMgr()
	{
		mPlayers.clear();
		mPlayerId = 0;
	}

}
#endif