#include "../DefInc.h"

#include "LuaScript.h"

#ifdef __LUA__
namespace std {

	void LuaScript::runFile(const char * nPath)
	{
		lua_tinker::dofile(mLuaState, nPath);
	}

	void LuaScript::runClose()
	{
		
	}

	LuaScript::LuaScript(lua_State * nLuaState, int nLuaRef)
		: mLuaState(nLuaState)
		, mLuaRef(nLuaRef)
	{
	}

	LuaScript::~LuaScript()
	{
		lua_unref(mLuaState, mLuaRef);
	}

}
#endif
