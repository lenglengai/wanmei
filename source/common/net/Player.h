#pragma once

#include "Robot.h"
#include "Session.h"

#ifdef __NET__
namespace std {
	
	class Player : public Robot
	{
	public:
		bool runSend(PacketPtr& nPacket);
		void setPlayerId(__i64 nPlayerId);
		SessionPtr& getSession();
	#ifdef __CLIENT__
		bool runPreinit();
	#endif
		Player();
		virtual ~Player();
		
	private:
	    SessionPtr mSession;
		__i64 mPlayerId;
	};
	
}
#endif
