#include "../Include.h"

namespace std {

	const __i32 ArchiveHash::hashSize()
	{
		return (sizeof(__i32)* 4);
	}

	void ArchiveHash::setHash(const __i32 nHash)
	{
		mHash = nHash;
	}

	const __i32 ArchiveHash::getHash() const
	{
		return mHash;
	}

	void ArchiveHash::setBeg(const __i32 nBeg)
	{
		mBeg = nBeg;
	}

	const __i32 ArchiveHash::getBeg() const
	{
		return mBeg;
	}

	void ArchiveHash::setEnd(const __i32 nEnd)
	{
		mEnd = nEnd;
	}

	const __i32 ArchiveHash::getEnd() const
	{
		return mEnd;
	}

	void ArchiveHash::setSize(const __i32 nSize)
	{
		mSize = nSize;
	}

	const __i32 ArchiveHash::getSize() const
	{
		return mSize;
	}

	const bool ArchiveHash::isDefault() const
	{
		return (0 == mHash);
	}

	const __i32 ArchiveHash::getKey() const
	{
		return mHash;
	}

	ArchiveHash::ArchiveHash()
		: mHash(0)
		, mBeg(0)
		, mEnd(0)
		, mSize(0)
	{
	}

	ArchiveHash::~ArchiveHash()
	{
		mHash = 0;
		mBeg = 0;
		mEnd = 0;
		mSize = 0;
	}

}
