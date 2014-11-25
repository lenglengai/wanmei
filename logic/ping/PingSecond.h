#pragma once

#ifdef __PING__
namespace std {

	class PingSecond : public Property
	{
	public:
		static __i32 sPropertyId;
	public:
		void setSecond(__i32 nSecond);
		__i32 getSecond();

		PingSecond();
		~PingSecond();

	private:
		__i32 mSecond;
	};

	typedef std::shared_ptr<PingSecond> PingSecondPtr;
	
}
#endif
