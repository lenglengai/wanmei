#pragma once

#include "../../service/crc/CrcService.h"

#include "IPropertyId.h"

namespace std {

	template<class T>
	class PropertyId : public IPropertyId
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
