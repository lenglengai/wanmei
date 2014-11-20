#pragma once

#ifdef __PROPERTY__
namespace std {

	class PropertyMgr;
	typedef std::shared_ptr<PropertyMgr> PropertyMgrPtr;
	class __funapi Property : boost::noncopyable
	{
	public:
		void setPropertyMgr(PropertyMgrPtr& nPropertyMgr);

	protected:
		PropertyMgrPtr& getPropertyMgr();

	public:
		virtual void runPreinit();
		virtual void runLoad();
		virtual void runInit();

		Property();
		virtual ~Property();
		
	private:
		PropertyMgrPtr * mPropertyMgr;
	};
	typedef std::shared_ptr<Property> PropertyPtr;

}
#endif
