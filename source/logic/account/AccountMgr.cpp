#include "../LogicInc.h"

#ifdef __ACCOUNT__
namespace std {

	AccountMgr::AccountMgr(__i16 nAccountMgrId)
		: mAccountMgrId(nAccountMgrId)
	{
	}

	AccountMgr::~AccountMgr()
	{
		mAccountMgrId = 0;
	}

}
#endif
