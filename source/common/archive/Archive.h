#pragma once

namespace std {

	class head_table
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize)
		{
			nSerialize.runInt32(mLower, "lower");
			nSerialize.runInt32(mHigh, "high");
			nSerialize.runInt16(mLower, "lower");
			nSerialize.runInt8(mHigh, "high");
		}
	private:
		__i32 mHash;
		__i32 mSize;
		__i16 mCount;
		bool mCompress;
	};

	class hash_table
	{
		__i32 mHash;
		__i32 mBeg;
		__i32 mEnd;
		__i32 mSize;
	};

	class Archive
	{

	};

}
