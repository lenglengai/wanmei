#pragma once

namespace std {

	class __funapi IServiceId : noncopyable
	{
	public:
		virtual const char * getServiceName() = 0;
		virtual __i32 getServiceId(string& nServiceName) = 0;
	};
	typedef shared_ptr<IServiceId> ServiceIdPtr;

}
