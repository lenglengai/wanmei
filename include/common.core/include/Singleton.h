#pragma once

namespace std {

	template<class T>
	class Singleton : boost::noncopyable
	{
	public:
		static T& instance() {
			static T t_;
			return t_;
		}
	};

	template<class T>
	class SingletonPtr : boost::noncopyable
	{
	public:
		static std::shared_ptr<T>& instance() {
			static std::shared_ptr<T> t_(new T());
			return t_;
		}
	};

}
