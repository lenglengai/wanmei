#include "../../include/Include.h"

namespace std {

	std::list<__i32>& Closed::getPreClosed() {
		return mPreClosed;
	}
	
	__i32 Closed::closedModule() {
		return mClosedModule;
	}
	
	__i32 Closed::closedType() {
		return mClosedType;
	}
	
	__i32 Closed::closedId() {
		return mClosedId;
	}
	
	__i32 Closed::closedNo() {
		return mClosedNo;
	}
	
	void Closed::runClear() {
		mPreClosed.clear();
		mClosedModule = 0;
		mClosedType = 0;
		mClosedId = 0;
		mClosedNo = 0;
	}
	
	Closed::Closed() {
		this->runClear();
	}
	
	Closed::~Closed() {
		this->runClear();
	}

}
