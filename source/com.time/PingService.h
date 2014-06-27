#pragma once

#include "../com.packet/IPacket.h"
#include "../com.packet/IProtocol.h"

#ifdef __CLIENT__
#include "../com.handle/Context.h"
#endif

namespace std {

	class C2SPing : public IPacket, boost::noncopyable
	{
	public:
		bool runBlock(BlockPtr& nBlock);

		void setSecond(__i32 nSecond);
		__i32 getSecond();

		C2SPing();
		~C2SPing();

	private:
		__i32 mSecond;
	};
	
	typedef boost::shared_ptr<C2SPing> C2SPingPtr;

	class S2CPing : public IPacket, boost::noncopyable
	{
	public:
		bool runBlock(BlockPtr& nBlock);
		bool isDefault();

		void setSecond(__i32 nSecond);
		__i32 getSecond();

		S2CPing();
		~S2CPing();

	private:
		__i32 mSecond;
	};
	typedef boost::shared_ptr<S2CPing> S2CPingPtr;

	class PingProtocol : public IProtocol, boost::noncopyable
	{
#ifdef __SERVER__
	public:
		bool runC2SPing(PacketPtr& nPacket, SessionPtr& nSession);
#endif

#ifdef __CLIENT__
	public:
		bool runS2CPing(PacketPtr& nPacket, SessionPtr& nSession);
#endif
	public:
		void runPreinit();
		void runStart();
		PacketRun * getPacketRun(__i16 nPacketType);
		const char * getProtocolName();
		PingProtocol();
		~PingProtocol();
	};

#ifdef __CLIENT__
	class PingService : public boost::enable_shared_from_this<PingService>, public Context, boost::noncopyable
	{
	public:
		void runContext();
		void setSendTick(clock_t nSendTick);
		clock_t getSendTick();
		void begPing();
		void endPing();
		void runPreinit();
		void runStart();

		PingService();
		~PingService();

	private:
		clock_t mSendTick;
		clock_t mClock;
		clock_t mPing;
	};
	typedef boost::shared_ptr<PingService> PingServicePtr;
#endif

}
