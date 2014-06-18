#include "../com.common/DefInc.h"
#include "LuaInc.h"

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

	void LuaScript::runClose()
	{
		lua_close(this->L);
	}

	LuaScript::~LuaScript()
	{
		this->runClose();
	}

}
