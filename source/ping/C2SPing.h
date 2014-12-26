#pragma once

#ifdef __PING__
namespace std {

	class PingProtocol;
	class C2SPing : public Packet<C2SPing, PingProtocol>
	{
	public:
	#ifdef __SERVER__
		bool handleRun(SessionPtr& nSession);
	#endif
		bool runBlock(BlockPtr& nBlock);
		void setSecond(const __i32 nSecond);
		__i32 getSecond() const;

		C2SPing();
		explicit C2SPing(const __i32 nSecond);
		~C2SPing();

	private:
		__i32 mSecond;
	};
	typedef shared_ptr<C2SPing> C2SPingPtr;
	
}
#endif
