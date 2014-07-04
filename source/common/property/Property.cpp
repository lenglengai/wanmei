#include "../DefInc.h"

#include "Property.h"
#include "PropertyMgr.h"

namespace std {

	void Property::setPropertyMgr(PropertyMgrPtr& nPropertyMgr)
	{
		mPropertyMgr = nPropertyMgr;
	}

	PropertyMgrWtr& Property::getPropertyMgr()
	{
		return mPropertyMgr;
	}

	void Property::runPreinit()
	{
	}

	void Property::runInit()
	{
	}

	Property::Property()
	{

	}

	Property::~Property()
	{

	}

}
