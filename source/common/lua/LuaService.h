#pragma once

#include "LuaScript.h"

#ifdef __LUA__
namespace std {

	class __funapi LuaService : boost::noncopyable
	{
	public:
		template<class C>
		void runClass(const char * nName)
		{
			lua_tinker::class_add<C>(mLuaState, nName);
			auto f = lua_tinker::constructor<C>;
			lua_tinker::class_con<C>(mLuaState, f);
		}

		template<class C, class B>
		void runInherit()
		{
			lua_tinker::class_inh<C, B>(mLuaState);
		}

		template<class C, typename M>
		void runMethod(M nMethod, const char * nName)
		{
			lua_tinker::class_def<C>(mLuaState, nName, nMethod);
		}

		LuaScriptPtr createLuaScript();

		void runFile(const char * nPath);

		void runClose();

		LuaService();

		~LuaService();

	private:
		lua_State * mLuaState;
	};

}
#endif

http://www.cnblogs.com/zhangdongsheng/p/3679024.html
