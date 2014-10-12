#include "../Common.h"

#ifdef __PROPERTY__
namespace std {

	void PropertySink::runCreate(PropertyMgrPtr& nPropertyMgr)
	{
		map<__i32, PropertyIdPtr>::iterator it = mPropertyIds.begin();
		for ( ; it != mPropertyIds.end(); ++it ) {
			PropertyIdPtr& propertyId_ = it->second;
			PropertyPtr property_ = propertyId_->createProperty();
			property_->setPropertyMgr(nPropertyMgr);
			nPropertyMgr->addProperty(property_, propertyId_);
			property_->runPreinit();
		}
		nPropertyMgr->initProperty();
	}

	void PropertySink::registerCreate(PropertyIdPtr& nPropertyId)
	{
		__i32 propertyId_ = nPropertyId->getPropertyId();
		map<__i32, PropertyIdPtr>::iterator it = mPropertyIds.find(propertyId_);
		if (it != mPropertyIds.end()) {
		#ifdef __LOG__
			LogService& logService_ = Singleton<LogService>::instance();
			logService_.logError(log_1(propertyId_));
		#endif
			return;
		}
		mPropertyIds[propertyId_] = nPropertyId;
	}

	PropertySink::PropertySink()
	{
		mPropertyIds.clear();
	}

	PropertySink::~PropertySink()
	{
		mPropertyIds.clear();
	}

}
#endif
