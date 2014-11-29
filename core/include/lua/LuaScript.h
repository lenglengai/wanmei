#pragma once

#include "../../dependence/lua/lua_tinker.h"

namespace std {

	class __funapi LuaScript : boost::noncopyable
	{
	public:
		template<typename R, typename... A>
		R runCall(const char * nName, A... nArgs)
		{
			return lua_tinker::call<R>(mLuaState, nName, nArgs...);
		}
		
		void runFile(const char * nPath);

		void runClose();

		explicit LuaScript(lua_State * nLuaState, int nLuaRef);
		~LuaScript();

	private:
		lua_State * mLuaState;
		int mLuaRef;
	};
	typedef std::shared_ptr<LuaScript> LuaScriptPtr;
	typedef std::weak_ptr<LuaScript> LuaScriptWtr;

}
