#pragma once

namespace std {

	class __funapi Closed : boost::noncopyable
	{
	public:
		std::list<__i32>& getPreClosed();
		__i32 closedModule();
		__i32 closedType();
		__i32 closedId();
		__i32 closedNo();
	
	private:
		void runClear();
		
	public:
		Closed();
		~Closed();
		
	private:
		std::list<__i32> mPreClosed;
		__i32 mClosedModule;
		__i32 mClosedType;
		__i32 mClosedId;
		__i32 mClosedNo;
	};
	typedef std::shared_ptr<Closed> ClosedPtr;

}
