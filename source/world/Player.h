#pragma once

#include "Tourist.h"

namespace std {
	
	class Player : public Tourist
	{
	public:
		bool runSend(PacketPtr& nPacket);
		void loginSession(SessionPtr& nSession);
		void logoutSession();
		void lookSession(SessionPtr& nSession);
		void lookoutSession(const __i32 nSessionId);
	
		void setWireId(const __i16 nWireId);
		__i16 getWireId() const;
		void runSwitch();
		void runUnSwitch();
		bool inSwitch() const;
		void runLock();
		void runUnLock();
		bool inLock() const;
		
		Player();
		Player(const PlayerType_ nPlayerType);
		~Player();
		
	private:
	    SessionPtr * mSession;
		atomic<bool> mInSwitch;
		atomic<__i32> mInLock;
		
		__i16 mWireId;
	#ifdef __SERVER__
		map<__i32, SessionPtr *> mSessions;
	#endif
	};
	typedef shared_ptr<Player> PlayerPtr;
	
}
