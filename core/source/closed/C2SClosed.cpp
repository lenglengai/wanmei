#include "../../include/Include.h"

namespace std {

#ifdef __SERVER__
	bool C2SClosed::handleRun(PlayerPtr& nPlayer)
	{
		ClosedService& closedService_ = Singleton<ClosedService>::Instance();
		ClosedMgrPtr& closedMgr_ = closedService_.getClosedMgr(mModule, mClosed);
		if (!closedMgr_) return false;
		std::map<__i32, ClosedsPtr>& closeds_ = closedMgr_->getCloseds();
		for (auto it : closeds_) {
			this->runCloseds(it->second);
		}
		return true;
	}
	
	void C2SClosed::runCloseds(ClosedsPtr& nCloseds)
	{
		std::map<__i32, ClosedPtr>& closeds_ = nCloseds->getCloseds();
		for ( auto& it : closeds_ ) {
			this->runClosed(it.second);
		}
	}
	
	void C2SClosed::runClosed(ClosedPtr& nClosed)
	{
		ValueList * valueList_ = this->getValueList();
	}
#endif
	
	bool C2SClosed::runBlock(BlockPtr& nBlock)
	{
		nBlock->runInt32(mModule);
		nBlock->runInt32(mClosed);
		nBlock->runInt8s(mInt8s);
		nBlock->runInt16s(mInt16s);
		nBlock->runInt32s(mInt32s);
		nBlock->runInt64s(mInt64s);
		nBlock->runStrings(mStrings);
		nBlock->runFloats(mFloats);
		nBlock->runDoubles(mDoubles);
		return true;
	}

	C2SClosed::C2SClosed()
		: mModule(0)
		, mClosed(0)
	{
		mInt8s.clear();
		mInt16s.clear();
		mInt32s.clear();
		mInt64s.clear();
		mStrings.clear();
		mFloats.clear();
		mDoubles.clear();
	}

	C2SClosed::~C2SClosed()
	{
		mInt8s.clear();
		mInt16s.clear();
		mInt32s.clear();
		mInt64s.clear();
		mStrings.clear();
		mFloats.clear();
		mDoubles.clear();
		mModule = 0;
		mClosed = 0;
	}
	
}
