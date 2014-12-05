#pragma once

#ifdef __PING__
namespace std {

	class WireProtocol;
	class S2CSwitchWire : public Packet<S2CSwitchWire, WireProtocol, false>
	{
	public:
	#ifdef __CLIENT__
		bool handleRun(PlayerPtr& nPlayer);
	#endif
		bool runBlock(BlockPtr& nBlock);
		bool isDefault();
		void setSecond(__i32 nSecond);
		__i32 getSecond();

		S2CSwitchWire();
		~S2CSwitchWire();

	private:
		__i64 mServerTime;
		__i32 mSecond;
	};
	typedef std::shared_ptr<S2CPing> S2CPingPtr;
	
}
#endif
