#pragma once

#include "../com.block/IBlock.h"
#include "../com.crc/CrcService.h"

namespace std {

	class Session;
	typedef boost::weak_ptr<Session> SessionWtr;
	typedef boost::shared_ptr<Session> SessionPtr;
	class IPacket
	{
	public:
		virtual bool handleRun(SessionPtr& nSession);
		virtual bool runBlock(BlockPtr& nBlock);
		virtual bool isDefault();

		IPacket();
		virtual ~IPacket();
	private:
		__i32 mProtocol;
		__i32 mPacket;
	};
	typedef boost::shared_ptr<IPacket> PacketPtr;

	class IPacketId
	{
	public:
		virtual __i32 getPacketId() = 0;
		virtual PacketPtr createPacket() = 0;
	};
	typedef boost::shared_ptr<IPacketId> PacketIdPtr;

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
				mPacketId = crcService_.runCommon(##T);
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
		static __i32 mPacketId;;
	};
	template<class T>
	__i32 PacketId<T>::mPacketId;

	template<class T>
	class Packet : public IPacket
	{
	public:
		Packet()
		{
			T& t_ = Singleton<T>::instance();
			mProtocol = t_.getProtocolId();
			mPacket = PacketId<T>::getClassId();
		}

		virtual ~Packet()
		{
			mProtocol = 0;
			mPacket = 0;
		}
	};

}
