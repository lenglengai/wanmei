#pragma once

namespace std {
	
	class WorldService : public IService
	{
	public:
	#ifdef __CLIENT__
		PlayerPtr& getPlayer();
	#endif
	private:
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
	#endif
	
	public:
		template<class __t>
		void headSerialize(__t& nT)
		{
		#ifdef __SERVER__
			nT.runKeyStreamsCount(mWorlds, "ｗorlds", "ｗorld");
		#endif
		#ifdef __CLIENT__
			nT.runStream(mWorld, "world");
		#endif
		}
		const char * streamName() const;
		const char * streamUrl() const;
		
		bool runPreinit();
		void runLoad();
		void runInit();
		void runStart();
		void runExit();
		
		WorldService();
		~WorldService();
		
	private:
		void runClear();
		
	private:
	#ifdef __SERVER__
		map<__i16, WorldPtr> mWorlds;
	#endif
	#ifdef __CLIENT__
		WorldPtr mWorld;
	#endif
	};

}
