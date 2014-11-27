#pragma once

namespace std {

	class Player;
	typedef std::weak_ptr<Player> PlayerWtr;
    typedef std::shared_ptr<Player> PlayerPtr;
	class IPacket : boost::noncopyable
	{
	public:
		virtual bool handleRun(PlayerPtr& nPlayer);
		virtual bool runBlock(BlockPtr& nBlock) = 0;
		void setHeader(__i32 nProtocol, bool nInline, __i32 nPacketId);
		void setValueList(ValueList& nValueList);
		ValueList * getValueList();
		bool runHeader(BlockPtr& nBlock);
		__i32 getProtocolId();
		__i32 getPacketId();
	#ifdef __SERVER__
		void setPlayer(PlayerPtr& nPlayer);
		PlayerPtr * getPlayer();
	#endif
		virtual bool isDefault();
		virtual void runInit() = 0;
		
		IPacket();
		virtual ~IPacket();
		
	protected:
	#ifdef __SERVER__
		PlayerPtr * mPlayer;
	#endif
		ValueList * mValueList;
		__i16 mVersion;
		__i32 mProtocol;
		__i32 mPacketId;
		bool mInline;
	};
	typedef std::shared_ptr<IPacket> PacketPtr;
	
	template<class T0, class T1, bool nInline=true>
	class Packet : public IPacket
	{
	public:
		void runInit()
		{
			T1& protocol_ = Singleton<T1>::instance(); mInline = nInline;
			CrcService& crcService_ = Singleton<CrcService>::instance();
			mProtocol = crcService_.runClassId<T1>();
			mPacketId = crcService_.runClassId<T0>();
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
				CrcService& crcService_ = Singleton<CrcService>::instance();
				mPacketId = crcService_.runClassId<T>();
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
