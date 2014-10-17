#include "../Common.h"

#ifdef __NET__
namespace std{

	PlayerPtr PlayerMgr::generatePlayer()
	{
		std::lock_guard<std::mutex> lock_(mMutex);
		PlayerPtr result_(new Player());
		result_->setPlayerId(mPlayerId);
		mPlayers[mPlayerId] = result_;
		++mPlayerId;
		return result_;
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