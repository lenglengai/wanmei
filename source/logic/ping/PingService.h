#pragma once

#include "../../common/net/IProtocol.h"
#include "../../common/property/Property.h"
#include "../../common/handle/Context.h"

#ifdef __PING__
namespace std {

	class PingProtocol;
	class C2SPing : public Packet<C2SPing, PingProtocol>, boost::noncopyable
	{
	public:
		static const char * sPacketName;
	public:
	#ifdef __SEVRECV__
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
	
	typedef std::shared_ptr<C2SPing> C2SPingPtr;

	class S2CPing : public Packet<S2CPing, PingProtocol>, boost::noncopyable
	{
	public:
		static const char * sPacketName;
	public:
	#ifdef __CLTRECV__
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
	typedef std::shared_ptr<S2CPing> S2CPingPtr;

#ifdef __CLTRECV__
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
	typedef std::shared_ptr<PingTick> PingTickPtr;
#endif

	class PingSecond : public Property
	{
	public:
		void setSecond(__i32 nSecond);
		__i32 getSecond();

		PingSecond();
		~PingSecond();

	private:
		__i32 mSecond;
	};

	typedef std::shared_ptr<PingSecond> PingSecondPtr;

	class PingProtocol : public IProtocol, boost::noncopyable
	{
	public:
	#ifdef __CLTRECV__
		bool runPacket(PacketPtr& nPacket, SessionPtr& nSession);
		void begPing();
		void endPing();
	#endif
		const char * getProtocolName();

		void runPreinit();
		void runInit();
		void runStart();

		PingProtocol();
		~PingProtocol();

	private:
	#ifdef __CLTRECV__
		PingTickPtr mPingTick;
		__i64 mClock;
		__i64 mPing;
	#endif
	};

}
#endif
