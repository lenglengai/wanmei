#pragma once

namespace std {
	
	class PlayerService : boost::noncopyable
	{
	public:
		bool pushPacket(PacketPtr& nPacket, PlayerPtr& nPlayer);
		bool switchWire(PlayerPtr& nPlayer, __i16 nWireId);
	#ifdef __SERVER__
		PlayerPtr& generatePlayer();
	#endif
		
		bool runPreinit();
		void runInit();
		void runStart();
		
		PlayerService();
		~PlayerService();
		
	private:
	#ifdef __SERVER__
		__i16 runWireId();
	#endif
		void runClear();
	
	private:
	#ifdef __SERVER__
		std::map<__i16, SingleWirePtr> mSingleWires;
		std::map<__i64, PlayerPtr> mPlayers;
		std::map<__i16, __i16> mPlayerCounts;
		std::mutex mMutex;
		__i64 mPlayerId;
		__i16 mMaxCount;
	#endif
	#ifdef __CLIENT__
		SingleWirePtr mSingleWire;
	#endif
	};

}
