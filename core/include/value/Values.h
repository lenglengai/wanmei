#pragma once

namespace std {
	
	class __funapi Values : boost::noncopyable
	{
	public:
		void insert(__i32 nId, ValuePtr& nValue);
		ValuePtr& getAt(__i32 nId);
		void runClear();
		
		Values();
		~Values();
		
	private:
		std::list<__i32, ValuePtr> mValues;
	};
	typedef std::shared_ptr<Values> ValuesPtr;
	
}
