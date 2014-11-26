#include "../../include/Include.h"

namespace std {

	std::map<__i32, ClosedsPtr>& ClosedMgr::getCloseds() {
		return mCloseds;
	}
	
	__i32 ClosedMgr::closedMgrId() {
		return mClosedMgrId;
	}
	
	void ClosedMgr::runClear() {
		mCloseds.clear();
		mClosedMgrId = 0;
	}
	
	ClosedMgr::ClosedMgr() {
		this->runClear();
	}
	
	ClosedMgr::~ClosedMgr() {
		this->runClear();
	}
	
}
