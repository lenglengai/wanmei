#pragma once

#include "Property.h"

namespace std {

	class IPropertyId;
	typedef std::shared_ptr<IPropertyId> PropertyIdPtr;
	class PropertyMgr : public boost::noncopyable
	{
	public:
		void addProperty(PropertyPtr& nProperty, PropertyIdPtr& nPropertyId);
		PropertyPtr& getProperty(IPropertyId& nPropertyId);

		void initProperty();

		PropertyMgr();
		virtual ~PropertyMgr();

	private:
		map<__i32, PropertyPtr> mPropertys;
	};

}
