#pragma once

#include "S2CLogin.h"
#include "C2SLogin.h"

#ifdef __ACCOUNT__
namespace std {

	class LoginProtocol : public IProtocol, boost::noncopyable
	{
	public:
		const char * getProtocolName();

		bool runPreinit();
		void runInit();

		LoginProtocol();
		~LoginProtocol();

	private:
	#ifdef __CLIENT__
		std::string mPlayer;
		__i32 mPassward;
		__i16 mWireId;
	#endif
	};

}
#endif
