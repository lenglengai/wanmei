#pragma once

#include "AccountMgr.h"

#ifdef __ACCOUNT__
namespace std {
	
	class AccountService : boost::noncopyable
	{
	public:
		bool runPreinit();
		void runInit();
		
		AccountService();
		~AccountService();
		
	private:
	#ifdef __SERVER__
		std::map<__i16, AccountMgrPtr> mAccountMgrs;
		__i16 mAccountMgrCount;
	#endif
	#ifdef __CLIENT__
		std::string mPlayer;
		__i32 mPassward;
		__i16 mWireId;
	#endif
	};
	
}
#endif
