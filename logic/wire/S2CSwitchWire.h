#pragma once

namespace std {

	class WireProtocol;
	class S2CSwitchWire : public Packet<S2CSwitchWire, WireProtocol>
	{
	public:
	#ifdef __CLIENT__
		bool handleRun(PlayerPtr& nPlayer);
	#endif
		bool runBlock(BlockPtr& nBlock);
		bool isDefault();
		void setWireId(__i16 nWireId);
		__i16 getWireId();

		S2CSwitchWire();
		S2CSwitchWire(__i16 nWireId);
		~S2CSwitchWire();

	private:
		__i16 mWireId;
	};
	typedef std::shared_ptr<S2CSwitchWire> S2CSwitchWirePtr;
	
}
