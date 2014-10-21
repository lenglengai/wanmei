#pragma once

#include "S2CPing.h"
#include "C2SPing.h"
#include "PingTick.h"
#include "PingSecond.h"

#ifdef __PING__
namespace std {

	class PingProtocol : public IProtocol, boost::noncopyable
	{
	public:
	#ifdef __CLIENT__
		void begPing();
		void endPing();
	#endif
		const char * getProtocolName();

		bool runPreinit();
		void runInit();
		void runStart();

		PingProtocol();
		~PingProtocol();

	private:
	#ifdef __CLIENT__
		PingTickPtr mPingTick;
		__i64 mClock;
		__i64 mPing;
	#endif
	};

}
#endif
