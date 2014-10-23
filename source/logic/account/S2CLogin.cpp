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
		nBlock->runInt16(mWireId);
		return true;
	}

	bool S2CLogin::isDefault()
	{
		if (ERRORINT::NONE == mErrorCode) return true;
		if (0 == mWireId) return true;
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

	void S2CLogin::setWireId(__i16 nWireId)
	{
		mWireId = nWireId;
	}
	
	__i16 S2CLogin::getWireId()
	{
		return mWireId;
	}
		
	S2CLogin::S2CLogin()
		: mErrorCode(ERRORINT::NONE)
		, mWireId(0)
	{
	}

	S2CLogin::S2CLogin(__i32 nErrorCode)
		: mErrorCode(nErrorCode)
		, mWireId(0)
	{
	}

	S2CLogin::~S2CLogin()
	{
		mErrorCode = ERRORINT::NONE;
		mWireId = 0;
	}
	
}
#endif
