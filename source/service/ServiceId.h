#pragma once

namespace std {

	template<class T>
	class __funapi ServiceId : public IServiceId
	{
	public:
		const char * getServiceName()
		{
		}
		
		__i32 getPropertyId()
		{
			return T::sPropertyId;
		}
	};

}
