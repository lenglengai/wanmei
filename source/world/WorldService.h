#pragma once

namespace std {
	
	class WorldService : public IService
	{
	private:
	#ifdef __CONSOLE__
		StringWriterPtr commandInfo(const CommandArgs& nCommand);
	#endif
	
	public:
		bool runPreinit();
		void runInit();
		void runStart();
		void runExit();
		
		WorldService();
		~WorldService();
		
	private:
		void runClear();
		
	private:
	#ifdef __SERVER__
		std::map<__i16, WorldPtr> mWorlds;
	#endif
	#ifdef __CLIENT__
		WorldPtr mWorld;
	#endif
	};

}
