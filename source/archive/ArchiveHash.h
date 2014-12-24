#pragma once

namespace std {

	class __funapi ArchiveHash : noncopyable
	{
	public:
		static const __i32 hashSize();
		void setHash(const __i32 nHash);
		const __i32 getHash() const;
		void setBeg(const __i32 nBeg);
		const __i32 getBeg() const;
		void setEnd(const __i32 nEnd);
		const __i32 getEnd() const;
		void setSize(const __i32 nSize);
		const __i32 getSize() const;
		const bool isDefault() const;
		const __i32 getKey() const;

		template<class T>
		void serialize(T * nSerialize, const __i32 nCount)
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

	typedef shared_ptr<ArchiveHash> ArchiveHashPtr;

}
