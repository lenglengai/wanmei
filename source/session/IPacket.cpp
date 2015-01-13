#include "../Include.h"

namespace std {
	
	bool IPacket::handleRun(SessionPtr& nSession)
	{
		return true;
	}
	
#ifdef __GAME__
	bool IPacket::handleRun(PlayerPtr& nPlayer)
	{
		return true;
	}
#endif
	
	void IPacket::setHeader(const __i32 nProtocol, const __i32 nPacketId)
	{
		mProtocol = nProtocol;
		mPacketId = nPacketId;
	}
	
	bool IPacket::runHeader(BlockPtr& nBlock)
	{
		nBlock->runInt16(mVersion);
		nBlock->runInt32(mProtocol);
		nBlock->runInt32(mPacketId);
		return true;
	}

	__i32 IPacket::getProtocolId() const
	{
		return mProtocol;
	}
	
	__i32 IPacket::getPacketId() const
	{
		return mPacketId;
	}
	
#ifdef __GAME__
	void IPacket::setPlayer(PlayerPtr& nPlayer)
	{
		mPlayer = &nPlayer;
	}
	
	PlayerPtr * IPacket::getPlayer() const
	{
		return mPlayer;
	}
#endif

	bool IPacket::isError() const
	{
		return false;
	}

	IPacket::IPacket()
		: mProtocol(0)
		, mPacketId(0)
	#ifdef __GAME__
		, mPlayer(nullptr)
	#endif
	{
		mVersion = __versionid();
	}

	IPacket::~IPacket()
	{
	#ifdef __GAME__
		mPlayer = nullptr;
	#endif
		mProtocol = 0;
		mPacketId = 0;
	}

}
