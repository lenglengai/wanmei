#include "../../include/Include.h"

namespace std {

	void PropertySink::runCreate(PropertyMgrPtr& nPropertyMgr)
	{
		list<PropertyPtr> propertys_;
		for (auto& propertyId_ : mPropertyIds) {
			PropertyPtr property_ = propertyId_->createProperty();
			property_->setPropertyMgr(nPropertyMgr);
			nPropertyMgr->addProperty(property_, propertyId_);
			property_->runPreinit();
			propertys_.push_back(property_);
		}
		for (auto& property_ : propertys_) {
			property_->runLoad();
		}
		for (auto& property_ : propertys_) {
			property_->runInit();
		}
	}

	void PropertySink::registerCreate(PropertyIdPtr& nPropertyId)
	{
		__i32 propertyId_ = nPropertyId->getPropertyId();
		auto it = mPropertyIds.find(propertyId_);
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
