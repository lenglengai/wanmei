#pragma once

namespace std {

	class __funapi PropertySink : noncopyable
	{
	public:
		void runCreate(PropertyMgrPtr& nPropertyMgr) const;
		void registerCreate(const PropertyIdPtr& nPropertyId);

		PropertySink();
		virtual ~PropertySink();

	private:
		map<__i32, PropertyIdPtr> mPropertyIds;
	};

}
