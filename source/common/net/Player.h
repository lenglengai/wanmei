#pragma once

#include "Session.h"

#ifdef __NET__
namespace std {

	class Player
	{
	public:
		Player(SessionPtr& nSession);
		virtual ~Player();

	private:
		SessionWtr mSession;
	};

}
#endif
