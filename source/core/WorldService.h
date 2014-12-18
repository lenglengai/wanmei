#pragma once

namespace std {
	
	class WorldService : public IService
	{
	public:
		bool runPreinit();
		void runInit();
		void runStart();
		
		WorldService();
		~WorldService();
		
	private:
		void runClear();
		
	private:
	#ifdef __SERVER__
		std::map<__i16, SingleWirePtr> mSingleWires;
	#endif
	#ifdef __CLIENT__
		SingleWirePtr mSingleWire;
	#endif
	};

}
