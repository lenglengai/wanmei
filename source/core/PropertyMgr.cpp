#include "../Include.h"

namespace std {
	
	const PropertyPtr& PropertyMgr::getProperty(const IPropertyId& nPropertyId) const
	{
		__i32 propertyId_ = nPropertyId.getPropertyId();
		auto it = mPropertys.find(propertyId_);
		if (it == mPropertys.end()) {
			LogService& logService_ = Service<LogService>::instance();
			logService_.logError(log_1(propertyId_));
			return __defaultptr<Property>();
		}
		return it->second;
	}

	void PropertyMgr::addProperty(const PropertyPtr& nProperty, const PropertyIdPtr& nPropertyId)
	{
		__i32 propertyId_ = nPropertyId->getPropertyId();
		auto it = mPropertys.find(propertyId_);
		if (it != mPropertys.end()) {
			LogService& logService_ = Service<LogService>::instance();
			logService_.logError(log_1(propertyId_));
			return;
		}
		mPropertys[propertyId_] = nProperty;
	}

	PropertyMgr::PropertyMgr()
	{
		mPropertys.clear();
	}

	PropertyMgr::~PropertyMgr()
	{
		mPropertys.clear();
	}

}
