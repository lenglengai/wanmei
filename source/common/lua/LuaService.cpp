#include "../DefInc.h"

#include "LuaService.h"

#ifdef __LUA__
namespace std {

	LuaScriptPtr LuaService::createLuaScript()
	{
		lua_State* luaState = lua_newthread(mLuaState);
		lua_pushthread(luaState);
		int luaRef = lua_ref(luaState, LUA_REGISTRYINDEX);
		LuaScriptPtr luaScript(new LuaScript(luaState, luaRef));
		return luaScript;
	}

	void LuaService::runFile(const char * nPath)
	{
		lua_tinker::dofile(mLuaState, nPath);
	}

	void LuaService::runClose()
	{
		lua_close(mLuaState);
	}

	LuaService::LuaService()
	{
		mLuaState = lua_open();
		luaL_openlibs(mLuaState);
		lua_tinker::init(mLuaState);
	}
	
	LuaService::~LuaService()
	{
		this->runClose();
	}

}
#endif
