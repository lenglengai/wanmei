#pragma once

namespace std {

	template<class T>
	class singleton : noncopyable
	{
	public:
		static T& instance() {
			static T t_;
			return t_;
		}
	};

	template<class T>
	class singletonptr : noncopyable
	{
	public:
		static shared_ptr<T>& instance() {
			static shared_ptr<T> t_(new T());
			return t_;
		}
	};

}
