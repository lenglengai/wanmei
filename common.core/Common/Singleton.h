#pragma once

#include "../DefInc.h"

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
