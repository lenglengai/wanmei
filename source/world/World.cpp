#include "../../include/Include.h"

namespace std {

	void World::runContext()
	{
	}
	
	void World::runInit()
	{
		LuaService& luaService_ = Singleton<LuaService>::instance();
		mLuaEngine = luaService_.createLuaEngine();
	}
	
	World::World()
	{
	}
	
	World::~World()
	{
	}
	
}
