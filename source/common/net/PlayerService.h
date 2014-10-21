#pragma once

#ifdef __NET__
namespace std{
	
	class PlayerService : boost::noncopyable
	{
	public:
		PlayerPtr& generatePlayer();
		
		PlayerService();
		~PlayerService();
	
	private:
		std::map<__i64, PlayerPtr> mPlayers;
		std::mutex mMutex;
		__i64 mPlayerId;
	};

}
#endif
