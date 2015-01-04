#pragma once

namespace std {

	template<class __t>
	class Service : noncopyable
	{
	public:
		static __t& instance() {
			return mT;
		}
		
		Service() {
			InitService& initService_ = 
				Singleton<InitService>::instance();
			__i32 classId_ = __classid<__t>();
			initService_.registerService( classId_,(&mT) );
		}
		
	private:
		static __t mT;
	};
	__t Service<__t>::mT;
	
}
