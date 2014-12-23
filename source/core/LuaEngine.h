#pragma once

#include "../../dependence/lua/lua_tinker.h"

namespace std {

	class __funapi LuaEngine : noncopyable
	{
	public:
		template<typename R, typename... A>
		R runCall(const char * nName, A... nArgs)
		{
			return lua_tinker::call<R>(mLuaState, nName, nArgs...);
		}
		
		void runUrl(const char * nUrl);
		void runStop();

		explicit LuaEngine(lua_State * nLuaState, int nLuaRef);
		~LuaEngine();

	private:
		lua_State * mLuaState;
		int mLuaRef;
	};
	typedef std::shared_ptr<LuaEngine> LuaEnginePtr;
	typedef std::weak_ptr<LuaEngine> LuaEngineWtr;

}
