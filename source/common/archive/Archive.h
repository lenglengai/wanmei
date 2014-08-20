#pragma once

#include "ArchiveHash.h"
#include "ArchiveHead.h"

namespace std {

	class __funapi Archive
	{
	public:
		ArchiveHashPtr getArchiveHash(const char * nKey);

		template<class T>
		void headSerialize(T& nSerialize)
		{
			nSerialize.runStream(mArchiveHead, "archiveHead");
			nSerialize.runKeyStreamsCount(mArchiveHashs, "archiveHashs", "archiveHash", mArchiveHead.getCount());
		}

		Archive();
		~Archive();

	private:
		std::map<__i32, ArchiveHashPtr> mArchiveHashs;
		ArchiveHead mArchiveHead;
	};

}
