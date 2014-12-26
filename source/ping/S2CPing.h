#pragma once

#ifdef __PING__
namespace std {

	class PingProtocol;
	class S2CPing : public Packet<S2CPing, PingProtocol>
	{
	public:
	#ifdef __CLIENT__
		bool handleRun(SessionPtr& nSession);
	#endif
		bool runBlock(BlockPtr& nBlock);
		bool isDefault() const;
		void setSecond(const __i32 nSecond);
		__i32 getSecond() const;

		S2CPing();
		explicit S2CPing(const __i32 nSecond);
		~S2CPing();

	private:
		__i32 mSecond;
	};
	typedef shared_ptr<S2CPing> S2CPingPtr;
	
}
#endif
