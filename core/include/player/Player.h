#pragma once

namespace std {
	
	class Player : public Robot
	{
	public:
		bool runSend(PacketPtr& nPacket);
		void setPlayerId(__i64 nPlayerId);
	#ifdef __CLIENT__
		bool runPreinit();
		__i64 getSendTick();
		bool isSendTick();
	#endif
		Player(SessionPtr& nSession);
		virtual ~Player();
		
	private:
	    SessionPtr mSession;
		__i64 mPlayerId;
	#ifdef __CLIENT__
		std::atomic<__i64> mSendTick;
	#endif
	};
	
}
