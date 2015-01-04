#pragma once

namespace std {

	class __funapi RandomService : public IService
	{
	public:
		__i32 luaRandom(const __i32 nMin, const __i32 nMax);
		__i32 runRandom(const __i32 nMin, const __i32 nMax);
		__i32 runRandom(const __i32 nMax);
		__i32 runRandom();
		
		static RandomService * getRandomService();
		
	private:
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandRandom(const CommandArgs& nCommandArgs);
	#endif
	
	public:
		bool runPreinit() OVERRIDE FINAL;
		void runLuaApi() OVERRIDE FINAL;

		RandomService();
		~RandomService();

	private:
		random_device mDevice;
		mt19937 mEngine;
	};

}
