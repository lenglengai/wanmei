#include "../Include.h"

namespace std {

	void LuaEngine::runUrl(const char * nUrl)
	{
		lua_tinker::dofile(mLuaState, nUrl);
	}

	void LuaEngine::runStop()
	{
		lua_unref(mLuaState, mLuaRef);
	}

	LuaEngine::LuaEngine(lua_State * nLuaState, int nLuaRef)
		: mLuaState(nLuaState)
		, mLuaRef(nLuaRef)
	{
	}

	LuaEngine::~LuaEngine()
	{
	}

}
