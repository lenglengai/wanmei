#include "../LogicInc.h"

#ifdef __ACCOUNT__
namespace std {

	const char * C2SLogin::sPacketName = "C2SLogin";

#ifdef __SERVER__
	bool C2SLogin::handleRun(PlayerPtr& nPlayer)
	{
		return true;
	}
#endif
	
	bool C2SLogin::runBlock(BlockPtr& nBlock)
	{
		nBlock->runString(mPlayerName);
		nBlock->runString(mPassward);
		nBlock->runInt16(mContextId);
		return true;
	}
	
	void C2SLogin::setPlayerName(std::string& nPlayerName)
	{
		mPlayerName = nPlayerName;
	}
	
	std::string& C2SLogin::getPlayerName()
	{
		return mPlayerName;
	}
	
	void C2SLogin::setPassward(__i32 nPassward)
	{
		mPassward = nPassward;
	}
	
	__i32 C2SLogin::getPassward()
	{
		return mPassward;
	}
	
	void C2SLogin::setContextId(__i16 nContextId)
	{
		mContextId = nContextId;
	}
	
	__i16 C2SLogin::getContextId()
	{
		return mContextId;
	}

	C2SLogin::C2SLogin()
		: mPlayerName ("")
		, mContextId (0)
		, mPassward (0)
	{
	}

	C2SLogin::C2SLogin(std::string& nPlayerName, __i32 nPassward)
		: mPlayerName (nPlayerName)
		, mPassward (nPassward)
		, mContextId (0)
	{
	}

	C2SLogin::~C2SLogin()
	{
		mPlayerName = "";
		mContextId = 0;
		mPassward = 0;
	}
	
}
#endif
