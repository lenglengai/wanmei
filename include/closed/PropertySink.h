#pragma once

#include "PropertyId.h"

#ifdef __PROPERTY__
namespace std {

	class __funapi PropertySink : boost::noncopyable
	{
	public:
		void runCreate(PropertyMgrPtr& nPropertyMgr);
		void registerCreate(PropertyIdPtr& nPropertyId);

		PropertySink();
		virtual ~PropertySink();

	private:
		map<__i32, PropertyIdPtr> mPropertyIds;
	};

}
#endif
