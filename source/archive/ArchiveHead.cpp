#include "../../include/Include.h"

namespace std {

	__i32 ArchiveHead::hashSize()
	{
		return 1;
	}

	bool ArchiveHead::getCompress()
	{
		return mCompress;
	}

	void ArchiveHead::runClear()
	{
		mCompress = false;
	}

	ArchiveHead::ArchiveHead()
	{
		this->runClear();
	}

	ArchiveHead::~ArchiveHead()
	{
		this->runClear();
	}

}
