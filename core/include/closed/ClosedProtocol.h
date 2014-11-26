#pragma once

namespace std {

	class PingProtocol : public IProtocol
	{
	public:
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
