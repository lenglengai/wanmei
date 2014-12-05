#pragma once

namespace std {

	class WireProtocol;
	class C2SSwitchWire : public Packet<C2SSwitchWire, WireProtocol, false>
	{
	public:
	#ifdef __SERVER__
		bool handleRun(PlayerPtr& nPlayer);
	#endif
		bool runBlock(BlockPtr& nBlock);
		void setWire(__i32 mWire);
		__i32 getWire();

		C2SSwitchWire();
		C2SSwitchWire(__i32 nWire);
		~C2SSwitchWire();

	private:
		__i32 mWire;
	};
	typedef std::shared_ptr<C2SSwitchWire> C2SSwitchWirePtr;
	
}
