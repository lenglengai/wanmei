#pragma once

namespace std {
	
	class Player : public Robot
	{
	public:
		bool runSend(PacketPtr& nPacket);
		void setPlayerId(__i64 nPlayerId);
		SessionPtr& getSession();
	#ifdef __CLIENT__
		bool runPreinit();
		__i64 getSendTick();
		bool isSendTick();
	#endif
		Player();
		virtual ~Player();
		
	private:
	    SessionPtr mSession;
		__i64 mPlayerId;
	#ifdef __CLIENT__
		std::atomic<__i64> mSendTick;
	#endif
	};
	
}
