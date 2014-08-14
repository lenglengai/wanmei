#pragma once

namespace std {

	class PropertyMgr;
	typedef std::shared_ptr<PropertyMgr> PropertyMgrPtr;
	typedef std::weak_ptr<PropertyMgr> PropertyMgrWtr;
	class __funapi Property : public boost::noncopyable
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
	typedef std::shared_ptr<Property> PropertyPtr;

}
