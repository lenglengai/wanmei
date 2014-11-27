#pragma once

namespace std {

	class __funapi ValueList : boost::noncopyable
	{
	public:
		void insert(__i32 nNo, ValuePtr& nValue);
		ValuePtr& getAt(__i32 nId, __i32 nNo);
		void setClosedNo(__i32 nClosedNo);
		void runClear();
		
		ValueList();
		~ValueList();
		
	private:
		std::map<__i32, ValuePtr> mValues;
		__i32 mClosedNo;
	};
	typedef std::shared_ptr<ValueList> ValueListPtr;

}
