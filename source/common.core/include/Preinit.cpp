#include "../Common.h"

namespace std {

	void PreinitSlot::pushPreinit(std::function<bool ()>& nPreinit)
	{
		mPreinits.push_back(nPreinit);
	}
	
	bool PreinitSlot::runPreinit()
	{
		bool result_ = false;
		for ( auto& it : mPreinits) {
			result_ = it();
			if (!result_) {
				return result_;
			}
		}
	#ifdef __LOG__
		LogService& logService_ = Singleton<LogService>::instance();
		logService_.logInfo(log_1("finish!"));
	#endif
		return true;
	}
	
	PreinitSlot::PreinitSlot()
	{
		mPreinits.clear();
	}
	
	PreinitSlot::~PreinitSlot()
	{
		mPreinits.clear();
	}
	
}
