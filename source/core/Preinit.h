#pragma once

namespace std{

	class PreinitSlot : noncopyable
	{
	public:
		void pushPreinit0(function<bool ()>& nPreinit);
		void pushPreinit1(function<bool ()>& nPreinit);
		bool runPreinit0();
		bool runPreinit1();
		
		void runClear();
		
		PreinitSlot();
		~PreinitSlot();
		
	private:
		list<function<bool ()> > mPreinit0s;
		list<function<bool ()> > mPreinit1s;
	};
	
	template <class T>
	class Preinit0 : noncopyable
	{
	public:
		static bool runPreinit()
		{
			T& t_ = Singleton<T>::instance();
			if (t_.runPreinit()) {
				ServiceMgr& serviceMgr_ = Singleton<ServiceMgr>::instance();
				serviceMgr_.registerService(&t_);
				return true;
			}
			return false;
		}
		
		Preinit0()
		{
			PreinitSlot& preinitSlot_ = Singleton<PreinitSlot>::instance();
			function<bool ()> preinit_ = function<bool ()>(&Preinit0<T>::runPreinit);
			preinitSlot_.pushPreinit0(preinit_);
		}
	};
	
	template <class T>
	class Preinit1 : noncopyable
	{
	public:
		static bool runPreinit()
		{
			T& t_ = Singleton<T>::instance();
			if (t_.runPreinit()) {
				ServiceMgr& serviceMgr_ = Singleton<ServiceMgr>::instance();
				serviceMgr_.registerService(&t_);
				return true;
			}
			return false;
		}
		
		Preinit1()
		{
			PreinitSlot& preinitSlot_ = Singleton<PreinitSlot>::instance();
			function<bool ()> preinit_ = function<bool ()>(&Preinit1<T>::runPreinit);
			preinitSlot_.pushPreinit1(preinit_);
		}
	};
	
}
