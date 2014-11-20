#pragma once

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
			return T::sPropertyId;
		}
	};

}
#endif
