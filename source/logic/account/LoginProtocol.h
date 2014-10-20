#pragma once

#include "S2CLogin.h"
#include "C2SLogin.h"

#ifdef __ACCOUNT__
namespace std {

	class LoginProtocol : public IProtocol, boost::noncopyable
	{
	public:
	#ifdef __CLIENT__
		bool runPacket(PacketPtr& nPacket, PlayerPtr& nPlayer);
	#endif
		const char * getProtocolName();

		bool runPreinit();
		void runInit();

		LoginProtocol();
		~LoginProtocol();

	private:
	#ifdef __CLIENT__
		std::string mPlayer;
		__i16 mContextId;
		__i32 mPassward;
	#endif
	};

}
#endif
