#pragma once

#include "InitService.h"

namespace std {

	template<class __t>
	class Service : noncopyable
	{
	public:
		static __t& instance() {
			return mT;
		}
		
		void runInit() {
			InitService& initService_ = Singleton<InitService>::instance();
			__i32 classId_ = __classid<__t>();
			initService_.registerService( classId_,(&mT) );
		}
		
		Service() {
			this->runInit();
		}
		
	private:
		static __t mT;
	};
	template<class __t>
	__t Service<__t>::mT;
	
}
