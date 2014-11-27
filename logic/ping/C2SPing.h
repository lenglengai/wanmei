#pragma once

#ifdef __PING__
namespace std {

	class PingProtocol;
	class C2SPing : public Packet<C2SPing, PingProtocol, false>
	{
	public:
	#ifdef __SERVER__
		bool handleRun(PlayerPtr& nPlayer);
	#endif
		bool runBlock(BlockPtr& nBlock);
		void setSecond(__i32 nSecond);
		__i32 getSecond();

		C2SPing();
		explicit C2SPing(__i32 nSecond);
		~C2SPing();

	private:
		__i32 mSecond;
	};
	typedef std::shared_ptr<C2SPing> C2SPingPtr;
	
}
#endif
