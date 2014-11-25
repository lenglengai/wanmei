#include "../../include/Include.h"

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
