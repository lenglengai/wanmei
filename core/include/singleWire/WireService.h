#pragma once

namespace std {
	
	class WireService : boost::noncopyable
	{
	public:
		bool pushPacket(PacketPtr& nPacket, __i16 nWireId);
		
		bool runPreinit();
		void runInit();
		void runStart();
		
		WireService();
		~WireService();
		
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
