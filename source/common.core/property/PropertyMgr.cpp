#include "../Common.h"

#ifdef __PROPERTY__
namespace std {
	
	PropertyPtr& PropertyMgr::getProperty(IPropertyId& nPropertyId)
	{
		__i32 propertyId_ = nPropertyId.getPropertyId();
		auto it = mPropertys.find(propertyId_);
		if (it == mPropertys.end()) {
		#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(propertyId_));
		#endif
			return __defaultptr<Property>();
		}
		return it->second;
	}

	void PropertyMgr::addProperty(PropertyPtr& nProperty, PropertyIdPtr& nPropertyId)
	{
		__i32 propertyId_ = nPropertyId->getPropertyId();
		auto it = mPropertys.find(propertyId_);
		if (it != mPropertys.end()) {
		#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(propertyId_));
		#endif
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
#endif
