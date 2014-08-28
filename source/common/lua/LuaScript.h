#pragma once

#include "lua_tinker.h"

#ifdef __LUA__
namespace std {

	class __funapi LuaScript : boost::noncopyable
	{
	public:
		template<typename R, typename... A>
		R runCall(const char * nName, A... nArgs)
		{
			return lua_tinker::call<R>(this->L, nName, nArgs...);
		}

		template<class C>
		void runClass(const char * nName)
		{
			lua_tinker::class_add<C>(this->L, nName);
			auto f = lua_tinker::constructor<C>;
			lua_tinker::class_con<C>(this->L, f);
		}

		template<class C, class B>
		void runInherit()
		{
			lua_tinker::class_inh<C, B>(this->L);
		}

		template<class C, typename M>
		void runMethod(M nMethod, const char * nName)
		{
			lua_tinker::class_def<C>(this->L, nName, nMethod);
		}

		void runFile(const std::string& nPath);
		
		void runString(const char * nValue);
		
		void runBuffer(const char * nValue, __i32 nSize);

		void runClose();

		LuaScript();
		~LuaScript();

	private:
		lua_State * L;
	};
	
	typedef std::shared_ptr<LuaScript> LuaScriptPtr;

}
#endif
