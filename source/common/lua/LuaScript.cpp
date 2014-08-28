#include "../DefInc.h"

#include "LuaScript.h"

#ifdef __LUA__
namespace std {

	LuaScript::LuaScript()
	{
		this->L = lua_open();
		luaL_openlibs(this->L);
		lua_tinker::init(this->L);
	}

	void LuaScript::runFile(const std::string& nPath)
	{
		lua_tinker::dofile(this->L, nPath.c_str());
	}
	
	void LuaScript::runString(const char * nValue)
	{
		lua_tinker::dostring(this->L, nValue);
	}

	void LuaScript::runBuffer(const char * nValue, __i32 nSize)
	{
		lua_tinker::dobuffer(this->L, nValue, nSize);
	}
	
	void LuaScript::runClose()
	{
		lua_close(this->L);
	}

	LuaScript::~LuaScript()
	{
		this->runClose();
	}

}
#endif
