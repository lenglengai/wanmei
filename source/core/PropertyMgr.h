#pragma once

namespace std {

	class __funapi PropertyMgr : noncopyable
	{
	public:
		void addProperty(PropertyPtr& nProperty, PropertyIdPtr& nPropertyId);
		PropertyPtr& getProperty(IPropertyId& nPropertyId);

		PropertyMgr();
		virtual ~PropertyMgr();

	private:
		map<__i32, PropertyPtr> mPropertys;
	};

}
