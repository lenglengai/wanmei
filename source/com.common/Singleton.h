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

}
