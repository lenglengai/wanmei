#include "../Include.h"

namespace std {

	LuaEnginePtr LuaService::createLuaEngine()
	{
		lua_State * luaState_ = lua_newthread(mLuaState);
		lua_pushthread(luaState_);
		int luaRef_ = lua_ref(luaState_, LUA_REGISTRYINDEX);
		LuaEnginePtr luaEngine(new LuaEngine(luaState_, luaRef_));
		return luaEngine;
	}

	bool LuaService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunExit.connect(boost::bind(&LuaService::runClose, this));
		
		mLuaState = lua_open();
		luaL_openlibs(mLuaState);
		lua_tinker::init(mLuaState);
		
		return true;
	}
	
	void LuaService::runClose()
	{
		lua_close(mLuaState);
	}

	LuaService::LuaService()
		: mLuaState (nullptr)
	{
	}
	
	LuaService::~LuaService()
	{
	}
	
	static Preinit0<LuaService> sLuaServicePreinit;

}
