#include "../DefInc.h"
#include "ArchiveHead.h"

namespace std {

	__i32 ArchiveHead::hashSize()
	{
		return 7;
	}

	__i32 ArchiveHead::getSize()
	{
		return mSize;
	}

	__i16 ArchiveHead::getCount()
	{
		return mCount;
	}

	bool ArchiveHead::getCompress()
	{
		return mCompress;
	}

	ArchiveHead::ArchiveHead()
		: mSize(0)
		, mCount(0)
		, mCompress(false)
	{

	}

	ArchiveHead::~ArchiveHead()
	{
		mSize = 0;
		mCount = 0;
		mCompress = false;
	}

}
