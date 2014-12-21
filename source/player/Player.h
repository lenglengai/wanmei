#pragma once

namespace std {
	
	class Player : public Tourist
	{
	public:
		bool runSend(PacketPtr& nPacket);
	#ifdef __CLIENT__
		bool isSendTick();
	#endif
		Player(SessionPtr& nSession);
		virtual ~Player();
		
	private:
	    SessionPtr& mSession;
	#ifdef __CLIENT__
		atomic<__i64> mSendTick;
	#endif
	};
	typedef shared_ptr<Player> PlayerPtr;
	
}
