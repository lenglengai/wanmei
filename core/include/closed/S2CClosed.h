#pragma once

namespace std {

	class ClosedProtocol;
	class S2CClosed : public Packet<S2CClosed, ClosedProtocol>
	{
	public:
	#ifdef __CLIENT__
		bool handleRun(PlayerPtr& nPlayer);
	#endif
		bool runBlock(BlockPtr& nBlock);
		bool isDefault();

		S2CClosed();
		~S2CClosed();

	private:
	};
	typedef std::shared_ptr<S2CClosed> S2CClosedPtr;
	
}
