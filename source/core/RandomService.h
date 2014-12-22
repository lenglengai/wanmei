#pragma once

namespace std {

	class __funapi RandomService : public IService
	{
	public:
		__i32 luaRandom(__i32 nMin, __i32 nMax);
		__i32 runRandom(__i32 nMin, __i32 nMax);
		__i32 runRandom(__i32 nMax);
		__i32 runRandom();
		
		RandomService * getRandomService();
		
	private:
	#ifdef __CONSOLE__
		StringWriterPtr commandInfo(const CommandArgs& nCommand);
		StringWriterPtr commandRandom(const CommandArgs& nCommand);
	#endif
	
	public:
		bool runPreinit();
		void runLuaApi();

		RandomService();
		~RandomService();

	private:
		std::random_device mDevice;
		std::mt19937 mEngine;
	};

}
