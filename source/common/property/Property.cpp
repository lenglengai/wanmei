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
		mInitType = InitType_::mPreinit_;
	}
	
	void Property::runLoad()
	{
		mInitType = InitType_::mLoad0_;
	}

	void Property::runInit0()
	{
		mInitType = InitType_::mInit0_;
	}

	void Property::runInit1()
	{
		mInitType = InitType_::mInit1_;
	}
	
	Property::Property()
		: mInitType (InitType_::mNone_)
	{
	}

	Property::~Property()
	{
		mInitType = InitType_::mNone_;
	}

}
#endif
