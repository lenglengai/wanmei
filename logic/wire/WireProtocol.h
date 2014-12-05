#pragma once

#ifdef __PING__
namespace std {

	class PingProtocol : public IProtocol
	{
	public:
	#ifdef __CLIENT__
		void startPing();
		void finishPing();
	#endif

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
