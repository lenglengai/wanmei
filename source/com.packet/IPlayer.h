#pragma once

#include "Session.h"

namespace std {

	class IPlayer
	{
	public:
		IPlayer(SessionPtr& nSession);
		virtual ~IPlayer();

	private:
		SessionWtr mSession;
	};

}
