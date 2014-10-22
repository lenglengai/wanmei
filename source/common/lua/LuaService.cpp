#include "../Common.h"

#ifdef __LUA__
namespace std {

	LuaScriptPtr LuaService::createLuaScript()
	{
		lua_State * luaState = lua_newthread(mLuaState);
		lua_pushthread(luaState);
		int luaRef = lua_ref(luaState, LUA_REGISTRYINDEX);
		LuaScriptPtr luaScript(new LuaScript(luaState, luaRef));
		return luaScript;
	}

	bool LuaService::runPreinit()
	{
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("start!"));
		
		logService_.logInfo(log_1("finish!"));
	#endif
		return true;
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
	
	static Preinit<LuaService> sLuaServicePreinit;

}
#endif
