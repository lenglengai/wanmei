#include "../Include.h"

namespace std {
	
	PropertyPtr& PropertyMgr::getProperty(IPropertyId& nPropertyId)
	{
		__i32 propertyId_ = nPropertyId.getPropertyId();
		auto it = mPropertys.find(propertyId_);
		if (it == mPropertys.end()) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(propertyId_));
			return __defaultptr<Property>();
		}
		return it->second;
	}

	void PropertyMgr::addProperty(PropertyPtr& nProperty, PropertyIdPtr& nPropertyId)
	{
		__i32 propertyId_ = nPropertyId->getPropertyId();
		auto it = mPropertys.find(propertyId_);
		if (it != mPropertys.end()) {
			LogService& logService_ = Singleton<LogService>::instance();
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
