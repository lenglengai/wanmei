#include "../com.common/DefInc.h"
#include "IPacket.h"

namespace std {

	bool IPacket::handleRun(SessionPtr& nSession)
	{
		return true;
	}

	bool IPacket::runBlock(BlockPtr& nBlock)
	{
		nBlock->runInt32(mProtocol);
		nBlock->runInt32(mPacket);
		return true;
	}

	bool IPacket::isDefault()
	{
		return ((0 == mProtocol) || (0 == mPacket));
	}

	IPacket::IPacket()
		: mProtocol(0)
	{
		CrcService& crcService_ = Singleton<CrcService>::instance();
		const char * packetName_ = this->getPacketName();
		mPacket = crcService_.runCommon(packetName_);
	}

	IPacket::~IPacket()
	{
		mProtocol = 0;
		mPacket = 0;
	}

}

http://zh.wikibooks.org/wiki/CMake_%E5%85%A5%E9%96%80/%E5%8A%A0%E5%85%A5%E7%B7%A8%E8%AD%AF%E9%81%B8%E9%A0%85