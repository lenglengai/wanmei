#include "../Include.h"

namespace std {

	void World::runContext()
	{
	}
	
#ifdef __CONSOLE__
	void World::runStringWriter(StringWriter * nStringWriter)
	{
		nStringWriter->runInt32(mPlayerCount, "playerCount");
		nStringWriter->runInt32(mHandleId, "handleId");
		nStringWriter->runString(mName, "name");
		nStringWriter->runInt16(mId, "id");
	}
#endif
	
#ifdef __CLIENT__
	PlayerPtr& World::getPlayer()
	{
		return mPlayer;
	}
#endif

	__i32 World::getPlayerCount() const
	{
		return mPlayerCount;
	}
	
	__i32 World::getHandleId() const
	{
		return mHandleId;
	}
	
	const string& World::getName() const
	{
		return mName;
	}
	
	__i16 World::getId() const
	{
		return mId;
	}
	
	__i16 World::getKey() const
	{
		return mId;
	}
	
	bool World::isDefault() const
	{
		return ( (0 == mId) || ("" == mName)
		|| (0 == mHandleId) || (0 == mPlayerCount) );
	}
	
	void World::runInit()
	{
		LuaService& luaService_ = Singleton<LuaService>::instance();
		mLuaEngine = luaService_.createLuaEngine();
	}

	World::World()
		: mPlayerCount (0)
		, mHandleId (0)
		, mName ("")
		, mId (0)
	{
	}
	
	World::~World()
	{
		mPlayerCount = 0;
		mHandleId = 0;
		mName = "";
		mId = 0;
	}
	
}
