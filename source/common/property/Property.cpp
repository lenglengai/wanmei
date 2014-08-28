#include "../DefInc.h"

#include "Property.h"
#include "PropertyMgr.h"

#ifdef __PROPERTY__
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

	void Property::runInit0()
	{
	}

	void Property::runInit1()
	{
	}
	
	Property::Property()
	{

	}

	Property::~Property()
	{

	}

}
#endif
