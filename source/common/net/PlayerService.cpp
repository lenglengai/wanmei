#include "../Common.h"

#ifdef __NET__
namespace std{

	PlayerPtr& PlayerService::generatePlayer()
	{
		std::lock_guard<std::mutex> lock_(mMutex);
		++mPlayerId;
		PlayerPtr player_(new Player());
		player_->setPlayerId(mPlayerId);
		mPlayers[mPlayerId] = player_;
		return mPlayers[mPlayerId];
	}
	
	PlayerService::PlayerService()
		: mPlayerId (0)
	{
		mPlayers.clear();
	}
	
	PlayerService::~PlayerService()
	{
		mPlayers.clear();
		mPlayerId = 0;
	}

}
#endif