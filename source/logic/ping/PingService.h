#pragma once

#include <boost/thread.hpp>

#include "../../net/packet/IProtocol.h"

#ifdef __CLIENT__
#include "../../service/handle/Context.h"
#endif

namespace std {

	class PingProtocol;
	class C2SPing : public Packet<C2SPing, PingProtocol>, boost::noncopyable
	{
	public:
		static const char * sPacketName;
	public:
	#ifdef __SERVER__
		bool handleRun(SessionPtr& nSession);
	#endif
		bool runBlock(BlockPtr& nBlock);
		void setSecond(__i32 nSecond);
		__i32 getSecond();

		C2SPing();
		C2SPing(__i32 nSecond);
		~C2SPing();

	private:
		__i32 mSecond;
	};
	
	typedef boost::shared_ptr<C2SPing> C2SPingPtr;

	class S2CPing : public Packet<S2CPing, PingProtocol>, boost::noncopyable
	{
	public:
		static const char * sPacketName;
	public:
	#ifdef __CLIENT__
		bool handleRun(SessionPtr& nSession);
	#endif
		bool runBlock(BlockPtr& nBlock);
		const char * getPacketName();
		bool isDefault();
		void setSecond(__i32 nSecond);
		__i32 getSecond();

		S2CPing();
		S2CPing(__i32 nSecond);
		~S2CPing();

	private:
		__i32 mSecond;
	};
	typedef boost::shared_ptr<S2CPing> S2CPingPtr;

#ifdef __CLIENT__
	class PingTick : public Context, boost::noncopyable
	{
	public:
		void pushPacket(PacketPtr& nPacket);
		PacketPtr popPacket();

		void handlePing();
		void runContext();

	public:
		PingTick(PingProtocol * nPingProtocol);
		~PingTick();

	private:
		PingProtocol * mPingProtocol;
		boost::shared_mutex mMutex;
		deque<PacketPtr> mPackets;
		__i64 mSendTick;
	};
	typedef boost::shared_ptr<PingTick> PingTickPtr;
#endif

	class PingProtocol : public IProtocol, boost::noncopyable
	{
	public:
#ifdef __CLIENT__
		bool runPacket(PacketPtr& nPacket, SessionPtr& nSession);
		void begPing();
		void endPing();
#endif
		const char * getProtocolName();
		void setSecond(__i32 nSecond);
		__i32 getSecond();

		void runPreinit();
		void runInit();
		void runStart();

		PingProtocol();
		~PingProtocol();

	private:
		__i32 mSecond;
	#ifdef __CLIENT__
		PingTickPtr mPingTick;
		__i64 mClock;
		__i64 mPing;
	#endif
	};

}