#pragma once

#include "Session.h"

#ifdef __NET__
namespace std {

	class ITourist
	{
	public:
		ITourist(SessionPtr& nSession);
		virtual ~ITourist();

	private:
		SessionWtr mSession;
	};

}
#endif
