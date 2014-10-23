#pragma once

#include "S2CLogin.h"
#include "C2SLogin.h"

#ifdef __ACCOUNT__
namespace std {

	class AccountProtocol : public IProtocol, boost::noncopyable
	{
	public:
		const char * getProtocolName();

		bool runPreinit();
		void runInit();

		AccountProtocol();
		~AccountProtocol();
	};

}
#endif
