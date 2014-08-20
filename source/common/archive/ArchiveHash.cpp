#include "../DefInc.h"

#include "ArchiveHash.h"

namespace std {

	__i32 ArchiveHash::hashSize()
	{
		return (sizeof(__i32)* 5);
	}

	void ArchiveHash::setHash(__i32 nHash)
	{
		mHash = nHash;
	}

	__i32 ArchiveHash::getHash()
	{
		return mHash;
	}

	void ArchiveHash::setBeg(__i32 nBeg)
	{
		mBeg = nBeg;
	}

	__i32 ArchiveHash::getBeg()
	{
		return mBeg;
	}

	void ArchiveHash::setEnd(__i32 nEnd)
	{
		mEnd = nEnd;
	}

	__i32 ArchiveHash::getEnd()
	{
		return mEnd;
	}

	void ArchiveHash::setSize(__i32 nSize)
	{
		mSize = nSize;
	}

	__i32 ArchiveHash::getSize()
	{
		return mSize;
	}

	bool ArchiveHash::isDefault()
	{
		return (0 == mHash);
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
