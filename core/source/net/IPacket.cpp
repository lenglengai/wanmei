#include "../../include/Include.h"

namespace std {

	bool IPacket::handleRun(PlayerPtr& nPlayer)
	{
		return true;
	}
	
	//void IPacket::setValueList(ValueList& nValueList)
	//{
	//	mValueList = (&nValueList);
	//}
	
	//ValueList * IPacket::getValueList()
	//{
	//	return mValueList;
	//}
	
	bool IPacket::runHeader(BlockPtr& nBlock)
	{
		nBlock->runInt16(mVersion);
		nBlock->runInt32(mProtocol);
		nBlock->runBool(mInline);
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

	bool IPacket::isDefault()
	{
		return ((0 == mProtocol) || (0 == mPacketId));
	}

	void IPacket::runInit()
	{
	}

	IPacket::IPacket()
		: mProtocol(0)
		, mPacketId(0)
		, mInline(true)
		//, mValueList(nullptr)
	#ifdef __SERVER__
		, mPlayer(nullptr)
	#endif
	{
		SettingService& settingService_ = Singleton<SettingService>::instance();
		mVersion = settingService_.getVersion();
	}

	IPacket::~IPacket()
	{
	#ifdef __SERVER__
		mPlayer = nullptr;
	#endif
		//mValueList = nullptr;
		mProtocol = 0;
		mInline = true;
		mPacketId = 0;
	}

}
