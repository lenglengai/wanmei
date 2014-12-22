#include "../Include.h"

namespace std {
	
	bool IPacket::handleRun(SessionPtr& nSession)
	{
		return true;
	}
	
	bool IPacket::handleRun(PlayerPtr& nPlayer)
	{
		return true;
	}
	
	void IPacket::setHeader(__i32 nProtocol, __i32 nPacketId)
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

	__i32 IPacket::getProtocolId()
	{
		return mProtocol;
	}
	
	__i32 IPacket::getPacketId()
	{
		return mPacketId;
	}
	
#ifdef __SERVER__
	void IPacket::setPlayer(PlayerPtr& nPlayer)
	{
		mPlayer = &nPlayer;
	}
	
	PlayerPtr * IPacket::getPlayer()
	{
		return mPlayer;
	}
#endif

	bool IPacket::isError()
	{
		return false;
	}

	IPacket::IPacket()
		: mProtocol(0)
		, mPacketId(0)
	#ifdef __SERVER__
		, mPlayer(nullptr)
	#endif
	{
		mVersion = __versionid();
	}

	IPacket::~IPacket()
	{
	#ifdef __SERVER__
		mPlayer = nullptr;
	#endif
		mProtocol = 0;
		mPacketId = 0;
	}

}
