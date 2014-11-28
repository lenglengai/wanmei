#pragma once

#ifdef __PING__
namespace std {

	class PingProtocol;
	class S2CPing : public Packet<S2CPing, PingProtocol, false>
	{
	public:
	#ifdef __CLIENT__
		bool handleRun(PlayerPtr& nPlayer);
	#endif
		bool runBlock(BlockPtr& nBlock);
		bool isDefault();
		void setSecond(__i32 nSecond);
		__i32 getSecond();

		S2CPing();
		explicit S2CPing(__i32 nSecond, __i64 nServerTime);
		~S2CPing();

	private:
		__i64 mServerTime;
		__i32 mSecond;
	};
	typedef std::shared_ptr<S2CPing> S2CPingPtr;
	
}
#endif
