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
	
	private:
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
	#endif
	
	public:
		bool runPreinit() OVERRIDE FINAL;
		void initBegin() OVERRIDE FINAL;
		void startBegin() OVERRIDE FINAL;

		PingProtocol();
		~PingProtocol();

	private:
	#ifdef __CLIENT__
		ContextPtr mPingTick;
		__i32 mClock;
		__i32 mPing;
	#endif
	};

}
#endif
