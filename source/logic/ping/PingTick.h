#pragma once

#ifdef __PING__
namespace std {

#ifdef __CLIENT__
	class PingProtocol;
	class PingTick : public Context, boost::noncopyable
	{
	public:
		void handlePing();
		void runContext();

	public:
		PingTick(PingProtocol * nPingProtocol);
		~PingTick();

	private:
		PingProtocol * mPingProtocol;
		std::deque<PacketPtr> mPackets;
		std::mutex mMutex;
		__i64 mSendTick;
	};
	typedef std::shared_ptr<PingTick> PingTickPtr;
#endif
	
}
#endif
