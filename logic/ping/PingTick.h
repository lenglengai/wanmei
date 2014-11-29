#pragma once

#ifdef __PING__
namespace std {

#ifdef __CLIENT__
	class PingTick : public Context
	{
	public:
		void runContext();

		PingTick();
		~PingTick();

	private:
		__i64 mSendTick;
	};
	typedef std::shared_ptr<PingTick> PingTickPtr;
#endif
	
}
#endif