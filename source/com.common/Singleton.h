#pragma once

namespace std {

	template<class T>
	class Singleton : boost::noncopyable
	{
	public:
		static T& instance()
		{
			static T t;
			return t;
		}
	};

	template<class T>
	class SingletonPtr : boost::noncopyable
	{
	public:
		static boost::shared_ptr<T>& instance()
		{
			static boost::shared_ptr<T> t(new T());
			return t;
		}
	};

}
