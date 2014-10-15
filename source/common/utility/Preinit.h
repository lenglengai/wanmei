#pragma once

namespace std{

	class PreinitSlot
	{
	public:
		boost::signals2::signal<void ()> m_tRunPreinit;
		void runPreinit();
		
		PreinitSlot();
		~PreinitSlot();
	};
	
	template <class T>
	class Preinit
	{
	public:
		static void runPreinit()
		{
			T& t_ = Singleton<T>::instance();
			t_.runPreinit();
		}
		
		Preinit()
		{
			PreinitSlot& preinitSlot = Singleton<PreinitSlot>::instance();
			preinitSlot.m_tRunPreinit.connect(&Preinit<T>::runPreinit);
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
		
		Preinit()
		{
			PreinitSlot& preinitSlot = Singleton<PreinitSlot>::instance();
			preinitSlot.m_tRunPreinit.connect(&Preinit<T>::runPreinit);
		}
	};
}
