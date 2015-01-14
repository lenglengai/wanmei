#pragma once

#include "../../dependence/lua/lua_tinker.h"

#ifdef __EXPLUA__
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
	typedef shared_ptr<LuaEngine> LuaEnginePtr;
	typedef weak_ptr<LuaEngine> LuaEngineWtr;

}
#endif
