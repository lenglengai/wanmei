#pragma once

#ifdef __RANDOM__
namespace std {

	class __funapi RandomService : boost::noncopyable
	{
	public:
		__i32 runRandom(__i32 nMin, __i32 nMax);
		__i32 runRandom(__i32 nMax);
		__i32 runRandom();
		
		void runPreinit();

		RandomService();
		~RandomService();
	};

}
#endif
