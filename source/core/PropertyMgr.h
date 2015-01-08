#pragma once

#include "PropertyId.h"

namespace std {

	class __funapi PropertyMgr : noncopyable
	{
	public:
		void addProperty(const PropertyPtr& nProperty, const PropertyIdPtr& nPropertyId);
		const PropertyPtr& getProperty(const IPropertyId& nPropertyId) const;

		PropertyMgr();
		virtual ~PropertyMgr();

	private:
		map<__i32, PropertyPtr> mPropertys;
	};

}
