#pragma once

#include "../crc/CrcService.h"

#include "IPropertyId.h"

#ifdef __PROPERTY__
namespace std {

	template<class T>
	class __funapi PropertyId : public IPropertyId
	{
	public:
		PropertyPtr createProperty()
		{
			return PropertyPtr(new T());
		}

		__i32 getPropertyId()
		{
			CrcService& crcService_ = Singleton<CrcService>::instance();
			return crcService_.runCommon(typeid(T).name());
		}
	};

}
#endif
