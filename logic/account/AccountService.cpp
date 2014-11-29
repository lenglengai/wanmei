#include "../LogicInc.h"

namespace std {

	bool AccountService::runPreinit()
	{
		InitService& initService_ = Singleton<InitService>::instance();
		initService_.m_tRunInit0.connect(boost::bind(&AccountService::runInit, this));

		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
		return true;
	}
	
	void AccountService::runInit()
	{
	#ifdef __SERVER__
		for (__i16 i = 0; i < mAccountMgrCount; ++i) {
            AccountMgrPtr accountMgr_(new AccountMgr(i));
            mAccountMgrs[i] = accountMgr_;
        }
	#endif
	}
	
    AccountService::AccountService()
	#ifdef __SERVER__
		: mAccountMgrCount(20)
	#endif
	#ifdef __CLIENT__
		: mPlayer ("")
		, mPassward (0)
		, mWireId (0)
	#endif
    {
	#ifdef __SERVER__
        mAccountMgrs.clear();
	#endif
    }

	AccountService::~AccountService()
    {
	#ifdef __SERVER__
        mAccountMgrs.clear();
        mAccountMgrCount = 20;
	#endif
	#ifdef __CLIENT__
		mPlayer = "";
		mPassward = 0;
		mWireId = 0;
	#endif
    }
	
}
