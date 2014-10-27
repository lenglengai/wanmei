#pragma once

#include "Account.h"

#ifdef __ACCOUNT__
namespace std {

	class AccountMgr : boost::noncopyable
	{
	public:
		AccountMgr(__i16 nAccountMgrId);
		~AccountMgr();
		
	private:
		__i16 mAccountMgrId;
	};
	typedef std::shared_ptr<AccountMgr> AccountMgrPtr;
	typedef std::weak_ptr<AccountMgr> AccountMgrWtr;

}
#endif
