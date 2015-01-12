#pragma once

#include "World.h"

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
			nT.runKeyStreamsCount(mWorlds, "worlds", "world");
		#endif
		#ifdef __CLIENT__
			nT.runStream(mWorld, "world");
		#endif
		}
		const char * streamName() const;
		const char * streamUrl() const;
		
		bool runPreinit() OVERRIDE FINAL;
		bool runConfig() OVERRIDE FINAL;
		bool initBegin() OVERRIDE FINAL;
		void startBegin() OVERRIDE FINAL;
		void runClear() OVERRIDE FINAL;
		
		WorldService();
		~WorldService();
		
	private:
	#ifdef __SERVER__
		map<__i16, WorldPtr> mWorlds;
	#endif
	#ifdef __CLIENT__
		WorldPtr mWorld;
	#endif
	};

}
