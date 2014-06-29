#include "../com.common/DefInc.h"
#include "IPacket.h"

namespace std {

	bool IPacket::handleRun(SessionPtr& nSession)
	{
		return true;
	}

	bool IPacket::runHeader(BlockPtr& nBlock)
	{
		nBlock->runInt32(mProtocol);
		nBlock->runInt32(mPacket);
	}

	bool IPacket::isDefault()
	{
		return ((0 == mProtocol) || (0 == mPacket));
	}

	void IPacket::setSend(bool nSend)
	{
		mSend = nSend;
	}

	void IPacket::runInit()
	{
		CrcService& crcService_ = Singleton<CrcService>::instance();
		const char * packetName_ = this->getPacketName();
		mPacket = crcService_.runCommon(packetName_);
	}


	IPacket::IPacket()
		: mProtocol(0)
		, mPacket(0)
		, mSend(true)
	{
	}

	IPacket::~IPacket()
	{
		mProtocol = 0;
		mPacket = 0;
	}

}
