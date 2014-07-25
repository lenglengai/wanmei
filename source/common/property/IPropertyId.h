#pragma once

#include "Property.h"
#include "PropertyMgr.h"

namespace std {

	class IPropertyId : public boost::noncopyable
	{
	public:
		virtual PropertyPtr createProperty() = 0;
		virtual __i32 getPropertyId() = 0;
	};
	typedef std::shared_ptr<IPropertyId> PropertyIdPtr;

}
