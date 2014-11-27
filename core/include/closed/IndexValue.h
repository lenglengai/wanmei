#pragma once

namespace std {

	class __funapi IndexValue : boost::noncopyable
	{
	public:
		__i32 getClosed();
		__i32 getIndex();
		
		IndexValue();
		~IndexValue();
		
	private:
		__i32 mClosed;
		__i32 mIndex;
	};
	typedef std::shared_ptr<IndexValue> IndexValuePtr;

}
