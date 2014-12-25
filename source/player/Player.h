#pragma once

namespace std {
	
	class Player : public Tourist
	{
	public:
		bool runSend(PacketPtr& nPacket);
		void loginSession(SessionPtr& nSession);
		void logoutSession();
		void lookSession(SessionPtr& nSession);
		void lookoutSession(const __i32 nSessionId);
		
	#ifdef __CLIENT__
		bool isSendTick();
	#endif
		Player();
		~Player();
		
	private:
	    SessionPtr * mSession;
	#ifdef __CLIENT__
		atomic<__i64> mSendTick;
	#endif
	#ifdef __SERVER__
		map<__i32, SessionPtr *> mSessions;
	#endif
	};
	typedef shared_ptr<Player> PlayerPtr;
	
}
