#pragma once

namespace std {

	class PropertyMgr;
	typedef boost::shared_ptr<PropertyMgr> PropertyMgrPtr;
	typedef boost::weak_ptr<PropertyMgr> PropertyMgrWtr;
	class Property : public boost::noncopyable
	{
	public:
		void setPropertyMgr(PropertyMgrPtr& nPropertyMgr);

	protected:
		PropertyMgrWtr& getPropertyMgr();

	public:
		virtual void runPreinit();
		virtual void runInit();

		Property();
		virtual ~Property();

	private:
		PropertyMgrWtr mPropertyMgr;
	};
	typedef boost::shared_ptr<Property> PropertyPtr;

}
