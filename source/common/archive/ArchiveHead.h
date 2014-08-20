#pragma once

namespace std {

	class ArchiveHead : boost::noncopyable
	{
	public:
		static __i32 hashSize();
		__i32 getSize();
		__i16 getCount();
		bool getCompress();

		template<class T>
		void serialize(T * nSerialize, int nCount)
		{
			nSerialize->runInt32(mSize, "hash1");
			nSerialize->runInt32(mCount, "hash2");
			nSerialize->runBool(mCompress, "compress");
		}

		ArchiveHead();
		~ArchiveHead();

	private:
		__i32 mSize;
		__i16 mCount;
		bool mCompress;
	};

}
