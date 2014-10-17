#pragma once

#include <mutex>
#include <atomic>

#ifdef __NET__
namespace std{
	
	class PlayerMgr : boost::noncopyable
	{
	public:
		PlayerPtr generatePlayer();
		
		PlayerMgr();
		~PlayerMgr();
	
	private:
		std::map<__i64, PlayerPtr> mPlayers;
		std::mutex mMutex;
		__i64 mPlayerId;
	};

}
#endif
