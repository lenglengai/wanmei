#include "../Include.h"

namespace std {

	void Property::setPropertyMgr(PropertyMgrPtr& nPropertyMgr)
	{
		mPropertyMgr = (&nPropertyMgr);
	}

	PropertyMgrPtr& Property::getPropertyMgr()
	{
		return (*mPropertyMgr);
	}

	void Property::runPreinit()
	{
	}
	
	void Property::runLoad()
	{
	}

	void Property::runInit()
	{
	}
	
	Property::Property()
		: mPropertyMgr(nullptr)
	{
	}

	Property::~Property()
	{
		mPropertyMgr = nullptr;
	}

}
