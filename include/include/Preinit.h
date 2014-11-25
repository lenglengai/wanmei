#pragma once

namespace std{

	class PreinitSlot : boost::noncopyable
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
	class Preinit : boost::noncopyable
	{
	public:
		static bool runPreinit()
		{
			T& t_ = Singleton<T>::instance();
			return t_.runPreinit();
		}
		
		Preinit()
		{
			PreinitSlot& preinitSlot_ = Singleton<PreinitSlot>::instance();
			std::function<bool ()> preinit = std::function<bool ()>(&Preinit<T>::runPreinit);
			preinitSlot_.pushPreinit(preinit);
		}
	};
	
	template <class T>
	class PreinitPtr : boost::noncopyable
	{
	public:
		static bool runPreinit()
		{
			std::shared_ptr<T>& t_ = SingletonPtr<T>::instance();
			return t_->runPreinit();
		}
		
		PreinitPtr()
		{
			PreinitSlot& preinitSlot_ = Singleton<PreinitSlot>::instance();
			std::function<bool ()> preinit = std::function<bool ()>(&PreinitPtr<T>::runPreinit);
			preinitSlot_.pushPreinit(preinit);
		}
	};
}
