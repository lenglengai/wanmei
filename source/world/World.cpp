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
		return mWorld->getPlayer();
	}
#endif

	const __i32 World::getPlayerCount() const
	{
		return mPlayerCount;
	}
	
	const __i32 World::getHandleId() const
	{
		return mHandleId;
	}
	
	const string& World::getName() const
	{
		return mName;
	}
	
	const __i16 World::getId() const
	{
		return mId;
	}
	
	const __i16 World::getKey() const
	{
		return mId;
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
