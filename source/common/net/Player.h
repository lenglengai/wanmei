#pragma once

#include "Robot.h"

namespace std {
	
	class Player : public Robot
	{
	public:
		void setPlayerId(__i64 nPlayerId);
		SessionPtr& getSession();
		
		Player();
		virtual ~Player();
		
	private:
	    SessionPtr mSession;
		__i64 mPlayerId;
	};
	typedef std::weak_ptr<Player> PlayerWtr;
    typedef std::shared_ptr<Player> PlayerPtr;
	
}
