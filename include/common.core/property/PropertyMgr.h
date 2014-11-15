#pragma once

#include "Property.h"

#ifdef __PROPERTY__
namespace std {

	class IPropertyId;
	typedef std::shared_ptr<IPropertyId> PropertyIdPtr;
	class __funapi PropertyMgr : boost::noncopyable
	{
	public:
		void addProperty(PropertyPtr& nProperty, PropertyIdPtr& nPropertyId);
		PropertyPtr& getProperty(IPropertyId& nPropertyId);

		PropertyMgr();
		virtual ~PropertyMgr();

	private:
		map<__i32, PropertyPtr> mPropertys;
	};

}
#endif
