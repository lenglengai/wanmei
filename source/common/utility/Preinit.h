#pragma once

namespace std{

	class PreinitSlot
	{
	public:
		void pushPreinit(std::function<bool ()>& nPreinit);
		bool runPreinit();
		
		PreinitSlot();
		~PreinitSlot();
	
	private:
		std::list<std::function<bool ()> > mPreinits;
	};
	
	template <class T>
	class Preinit
	{
	public:
		static bool runPreinit()
		{
			T& t_ = Singleton<T>::instance();
			return t_.runPreinit();
		}
		
		Preinit()
		{
			PreinitSlot& preinitSlot = Singleton<PreinitSlot>::instance();
			std::function<bool ()> preinit = std::function<bool ()>(&Preinit<T>::runPreinit);
			preinitSlot.pushPreinit(preinit);
		}
	};
	
	template <class T>
	class PreinitPtr
	{
	public:
		static void runPreinit()
		{
			T& t_ = SingletonPtr<T>::instance();
			t_->runPreinit();
		}
		
		PreinitPtr()
		{
			PreinitSlot& preinitSlot = Singleton<PreinitSlot>::instance();
			preinitSlot.m_tRunPreinit.connect(&Preinit<T>::runPreinit);
		}
	};
}
