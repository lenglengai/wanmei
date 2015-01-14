#include "../Include.h"

#ifdef __WITHSERVER__
namespace std {

#ifdef __LOGIN__	
	void Server::setPlayerCount(__i32 nPlayerCount)
	{
		mPlayerCount = nPlayerCount;
	}
	
	__i32 Server::getPlayerCount() const
	{
		return mPlayerCount;
	}
	
	void Server::setPlayerMaxCount(__i32 nPlayerMaxCount)
	{
		mPlayerMaxCount = nPlayerMaxCount;
	}
	
	__i32 Server::getPlayerMaxCount() const
	{
		return mPlayerMaxCount;
	}
#endif

	Server::Server()
	#ifdef __LOGIN__
		: mPlayerCount (0)
		, mPlayerMaxCount (0)
	#endif
	{
	}

	Server::~Server()
	{
	#ifdef __LOGIN__
		mPlayerCount = 0;
		mPlayerMaxCount = 0;
	#endif
	}
	
}
#endif
