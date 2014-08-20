#pragma once

namespace std {

	class ArchiveHash : boost::noncopyable
	{
	public:
		static __i32 hashSize();
		void setHash(__i32 nHash);
		__i32 getHash();
		void setBeg(__i32 nBeg);
		__i32 getBeg();
		void setEnd(__i32 nEnd);
		__i32 getEnd();
		void setSize(__i32 nSize);
		__i32 getSize();
		bool isDefault();

		template<class T>
		void serialize(T * nSerialize, int nCount)
		{
			nSerialize->runInt32(mHash, "hash");
			nSerialize->runInt32(mBeg, "beg");
			nSerialize->runInt32(mEnd, "end");
			nSerialize->runInt32(mSize, "size");
		}

		ArchiveHash();
		~ArchiveHash();

	private:
		__i32 mHash;
		__i32 mBeg;
		__i32 mEnd;
		__i32 mSize;
	};

	typedef std::shared_ptr<ArchiveHash> ArchiveHashPtr;

}
