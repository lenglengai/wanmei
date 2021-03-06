#include "../Include.h"

namespace std {

	void PropertySink::runCreate(PropertyMgrPtr& nPropertyMgr) const
	{
		list<PropertyPtr> propertys_;
		for (auto& it : mPropertyIds) {
			const PropertyIdPtr& propertyId_ = it.second;
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

	void PropertySink::registerCreate(const PropertyIdPtr& nPropertyId)
	{
		__i32 propertyId_ = nPropertyId->getPropertyId();
		auto it = mPropertyIds.find(propertyId_);
		if (it != mPropertyIds.end()) {
			LogService& logService_ = Service<LogService>::instance();
			logService_.logError(log_1(propertyId_));
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
