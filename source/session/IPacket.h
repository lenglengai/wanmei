#pragma once

namespace std {

	class Player;
	typedef std::weak_ptr<Player> PlayerWtr;
    typedef std::shared_ptr<Player> PlayerPtr;
	class IPacket : noncopyable
	{
	public:
		virtual bool handleRun(SessionPtr& nSession);
		virtual bool handleRun(PlayerPtr& nPlayer);
		virtual bool runBlock(BlockPtr& nBlock) = 0;
		void setHeader(__i32 nProtocol, __i32 nPacketId);
		bool runHeader(BlockPtr& nBlock);
		__i32 getProtocolId();
		__i32 getPacketId();
	#ifdef __SERVER__
		void setPlayer(PlayerPtr& nPlayer);
		PlayerPtr * getPlayer();
	#endif
		virtual bool isError();
		virtual void runInit() = 0;
		
		IPacket();
		virtual ~IPacket();
		
	protected:
	#ifdef __SERVER__
		PlayerPtr * mPlayer;
	#endif
		__i16 mVersion;
		__i32 mProtocol;
		__i32 mPacketId;
	};
	typedef shared_ptr<IPacket> PacketPtr;
	
	template<class __t0, class __t1>
	class Packet : public IPacket
	{
	public:
		void runInit()
		{
			mProtocol = __classid<__t0>();
			mPacketId = __classid<__t1>();
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
			if (0 == mPacketId) {
				mPacketId = __classid<T>();
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
