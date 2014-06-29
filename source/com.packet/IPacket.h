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
		virtual const char * getPacketName() = 0;
		virtual bool runBlock(BlockPtr& nBlock) = 0;
		bool runHeader(BlockPtr& nBlock);
		virtual bool isDefault();
		void setSend(bool nSend);
		virtual void runInit();

		IPacket();
		virtual ~IPacket();

	protected:
		__i32 mProtocol;
		__i32 mPacket;
		bool mSend;
	};
	typedef boost::shared_ptr<IPacket> PacketPtr;

	template<class T>
	class Packet : public IPacket
	{
	public:
		virtual void runInit()
		{
			T& t_ = Singleton<T>::instance();
			mProtocol = t_.getProtocolId();
			IPacket::runInit();
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
	typedef boost::weak_ptr<IPacketId> PacketIdWtr;
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
				mPacketId = crcService_.runCommon(typeid(T).name());
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
