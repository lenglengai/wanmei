#pragma once

#ifdef __PROPERTY__
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
		virtual void runLoad();
		virtual void runInit0();
		virtual void runInit1();

		Property();
		virtual ~Property();
		
	protected:
		InitType_ mInitType;
		
	private:
		PropertyMgrWtr mPropertyMgr;
		
	};
	typedef std::shared_ptr<Property> PropertyPtr;

}
#endif
