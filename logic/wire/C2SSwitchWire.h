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
		void setWireId(__i32 nWireId);
		__i32 getWireId();

		C2SSwitchWire();
		C2SSwitchWire(__i32 nWireId);
		~C2SSwitchWire();

	private:
		__i32 mWireId;
	};
	typedef std::shared_ptr<C2SSwitchWire> C2SSwitchWirePtr;
	
}
