#pragma once

#include <random>

#ifdef __RANDOM__
namespace std {

	class __funapi RandomService : boost::noncopyable
	{
	public:
		__i32 luaRunRandom(__i32 nMin, __i32 nMax);
		__i32 runRandom(__i32 nMin, __i32 nMax);
		__i32 runRandom(__i32 nMax);
		__i32 runRandom();
		
		static void runScript();
		bool runPreinit();
		void runInit();

		RandomService();
		~RandomService();

	private:
		std::random_device mDevice;
		std::mt19937 mEngine;
	};

}
#endif
