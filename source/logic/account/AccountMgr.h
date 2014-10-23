#pragma once

#include "Account.h"

#ifdef __ACCOUNT__
namespace std {

	class AccountMgr : boost::noncopyable
	{
	public:
		AccountMgr();
		~AccountMgr();
	};

}
#endif
