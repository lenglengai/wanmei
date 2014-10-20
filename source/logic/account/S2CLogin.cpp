#include "../LogicInc.h"

#ifdef __ACCOUNT__
namespace std {

	const char * S2CLogin::sPacketName = "S2CLogin";
	
#ifdef __CLIENT__
	bool S2CLogin::handleRun(PlayerPtr& nPlayer)
	{
		return true;
	}
#endif

	const char * S2CLogin::getPacketName()
	{
		return "S2CLogin";
	}

	bool S2CLogin::runBlock(BlockPtr& nBlock)
	{
		nBlock->runInt32(mErrorCode);
		return true;
	}

	bool S2CLogin::isDefault()
	{
		if (ERRORINT::NONE == mErrorCode) return true;
		return IPacket::isDefault();
	}

	void S2CLogin::setErrorCode(__i32 nErrorCode)
	{
		mErrorCode = nErrorCode;
	}

	__i32 S2CLogin::getErrorCode()
	{
		return mErrorCode;
	}

	S2CLogin::S2CLogin()
		: mErrorCode(ERRORINT::NONE)
	{
	}

	S2CLogin::S2CLogin(__i32 nErrorCode)
		: mErrorCode(nErrorCode)
	{
	}

	S2CLogin::~S2CLogin()
	{
		mErrorCode = ERRORINT::NONE;
	}
	
}
#endif
