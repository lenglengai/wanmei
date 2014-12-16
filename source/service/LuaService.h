#pragma once

namespace std {

	class __funapi LuaService : noncopyable
	{
	public:
		template<typename F>
		void runFun(F nFun, const char * nName)
		{
			lua_tinker::def(mLuaState, nName, nFun);
		}
		
		template<class C, class B>
		void runInherit()
		{
			lua_tinker::class_inh<C, B>(mLuaState);
		}
		
		template<class C>
		void runClass(const char * nName)
		{
			lua_tinker::class_add<C>(mLuaState, nName);
			auto f = lua_tinker::constructor<C>;
			lua_tinker::class_con<C>(mLuaState, f);
		}
		
		template<class C, typename M>
		void runMethod(M nMethod, const char * nName)
		{
			lua_tinker::class_def<C>(mLuaState, nName, nMethod);
		}
		LuaEnginePtr createLuaEngine();
		
		bool runPreinit();
		
	private:
		void runClose();

	public:
		LuaService();
		~LuaService();

	private:
		lua_State * mLuaState;
	};

}
