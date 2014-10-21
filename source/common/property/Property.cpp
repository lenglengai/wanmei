#include "../Common.h"

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
	
	void Property::runLoad()
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
#endif
