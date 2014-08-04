#include "../DefInc.h"
#include "../log/LogService.h"
#include "IPropertyId.h"

#include "PropertyMgr.h"

namespace std {
	
	PropertyPtr& PropertyMgr::getProperty(IPropertyId& nPropertyId)
	{
		__i32 propertyId_ = nPropertyId.getPropertyId();
		map<__i32, PropertyPtr>::iterator it = mPropertys.find(propertyId_);
		if (it == mPropertys.end()) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(propertyId_));
			return it->second;
		}
		return it->second;
	}

	void PropertyMgr::addProperty(PropertyPtr& nProperty, PropertyIdPtr& nPropertyId)
	{
		__i32 propertyId_ = nPropertyId->getPropertyId();
		map<__i32, PropertyPtr>::iterator it = mPropertys.find(propertyId_);
		if (it != mPropertys.end()) {
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(propertyId_));
			return;
		}
		mPropertys[propertyId_] = nProperty;
	}

	void PropertyMgr::initProperty()
	{
		map<__i32, PropertyPtr>::iterator it = mPropertys.begin();
		for ( ; it != mPropertys.end(); ++it ) {
			PropertyPtr& property_ = it->second;
			property_->runInit();
		}
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
