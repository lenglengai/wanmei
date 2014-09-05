#include "../DefInc.h"

#include "LuaScript.h"

#ifdef __LUA__
namespace std {

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
