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
			this->runCloseds(nPlayer, it->second);
		}
		return true;
	}
	
	void C2SClosed::runCloseds(PlayerPtr& nPlayer, ClosedsPtr& nCloseds)
	{
		std::map<__i32, ClosedPtr>& closeds_ = nCloseds->getCloseds();
		for ( auto& it : closeds_ ) {
			this->runClosed(nPlayer, it.second);
		}
	}
	
	void C2SClosed::runClosed(PlayerPtr& nPlayer, ClosedPtr& nClosed)
	{
		Values values_; 
		this->runValues(values_, nClosed);
		ValueList * valueList_ = this->getValueList();
		DoingService& doingService_ = Singleton<DoingService>::instance();
		doingService_.runClosed(nPlayer, nClosed, values_, valueList_);
	}
	
	void C2SClosed::runValues(Values& nValues, ClosedPtr& nClosed)
	{
		__i32 count_ = 1;
		ValueList * valueList_ = this->getValueList();
		std::list<IndexValuePtr>& indexValues = nClosed->getIndexValues();
		for (auto& it : indexValues) {
			__i32 closed_ = it->getClosed();
			__i32 index_ = it->getIndex();
			if (0 == closed_) {
				ValuePtr& value_ = mValues[index_ - 1];
				nValues.insert(count_, value_);
			} else {
				ValuePtr& value_ = valueList_->getAt(closed_, index_);
				if (!value_) {
					LogService& logService_ = Singleton<LogService>::instance();
					logService_.logError(log_2(closed_, index_));
					return;
				} else {
					nValues.insert(count_, value_);
				}
			}
			count_++;
		}
		__i32 closedNo_ = nClosed->closedNo();
		valueList_->setClosedNo(closedNo_);
	}
#endif
	
	bool C2SClosed::runBlock(BlockPtr& nBlock)
	{
		nBlock->runInt32(mModule);
		nBlock->runInt32(mClosed);
		__i16 valueSize_ = static_cast<__i16>(mValues.size());
		nBlock->runInt16(valueSize_);
		if ( nBlock->isReader() ) {
			for ( int i = 0; i < valueSize_; ++i ) {
				__i8 valueType_ = 0;
				nBlock->runInt8(valueType_);
				if (0 = valueType_) {
					return false;
				} else if (1 == valueType_) {
					__i8 count_ = 0; 
					nBlock->runInt8(count_);
					ValuePtr value_(new Value<__i8>(count_));
					mValues.push_back(value_);
				} else if (2 == valueType_) {
					__i16 count_ = 0; 
					nBlock->runInt16(count_);
					ValuePtr value_(new Value<__i16>(count_));
					mValues.push_back(value_);
				} else if (3 == valueType_) {
					__i32 count_ = 0; 
					nBlock->runInt32(count_);
					ValuePtr value_(new Value<__i32>(count_));
					mValues.push_back(value_);
				} else if (4 == valueType_) {
					__i64 count_ = 0; 
					nBlock->runInt64(count_);
					ValuePtr value_(new Value<__i64>(count_));
					mValues.push_back(value_);
				} else if (5 == valueType_) {
					float count_ = 0.f; 
					nBlock->runFloat(count_);
					ValuePtr value_(new Value<float>(count_));
					mValues.push_back(value_);
				} else if (6 == valueType_) {
					double count_ = 0.; 
					nBlock->runDouble(count_);
					ValuePtr value_(new Value<double>(count_));
					mValues.push_back(value_);
				} else if (7 == valueType_) {
					std::string count_(""); 
					nBlock->runString(count_);
					ValuePtr value_(new Value<std::string>(count_.c_str()));
					mValues.push_back(value_);
				}
			}
		} else {
			for (auto& it : mValues) {
				if ( !it->runBlock(nBlock) ) {
					return false;
				}
			}
		}
		return true;
	}

	C2SClosed::C2SClosed()
		: mModule(0)
		, mClosed(0)
	{
		mValues.clear();
	}

	C2SClosed::~C2SClosed()
	{
		mValues.clear();
		mModule = 0;
		mClosed = 0;
	}
	
}
