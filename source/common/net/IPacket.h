#pragma once

#include "IBlock.h"

#ifdef __NET__
namespace std {

	class Session;
	typedef std::weak_ptr<Session> SessionWtr;
	typedef std::shared_ptr<Session> SessionPtr;
	class IPacket
	{
	public:
		virtual bool handleRun(SessionPtr& nSession);
		virtual bool runBlock(BlockPtr& nBlock) = 0;
		void setHeader(__i32 nProtocol, __i32 nPacket);
		bool runHeader(BlockPtr& nBlock);
		virtual bool isDefault();
		virtual void runInit() = 0;

		IPacket();
		virtual ~IPacket();

	protected:
		__i32 mProtocol;
		__i32 mPacket;
	};
	typedef std::shared_ptr<IPacket> PacketPtr;

	template<class T0, class T1>
	class Packet : public IPacket
	{
	public:
		void runInit()
		{
			T1& protocol_ = Singleton<T1>::instance();
			mProtocol = protocol_.getProtocolId();
			CrcService& crcService_ = Singleton<CrcService>::instance();
			mPacket = crcService_.runCommon(T0::sPacketName);
		}

		Packet()
		{
		}

		virtual ~Packet()
		{
		}
	};

	class IPacketId
	{
	public:
		virtual __i32 getPacketId() = 0;
		virtual PacketPtr createPacket() = 0;
	};
	typedef std::weak_ptr<IPacketId> PacketIdWtr;
	typedef std::shared_ptr<IPacketId> PacketIdPtr;

	template<class T>
	class PacketId : public IPacketId
	{
	public:
		__i32 getPacketId()
		{
			return this->getClassId();
		}

		static __i32 getClassId()
		{
			if (0 == mPacketId)
			{
				CrcService& crcService_ = Singleton<CrcService>::instance();
				mPacketId = crcService_.runCommon(T::sPacketName);
			}
			return mPacketId;
		}

		PacketPtr createPacket()
		{
			return PacketPtr(new T());
		}

		PacketId()
		{
		}

		~PacketId()
		{
		}
	private:
		static __i32 mPacketId;;
	};
	template<class T>
	__i32 PacketId<T>::mPacketId = 0;

}
#endif
