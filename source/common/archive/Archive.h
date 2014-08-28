#pragma once

#include "ArchiveHash.h"
#include "ArchiveHead.h"

#ifdef __ARCHIVE__
namespace std {

#define ARCHIVESIZE 5 * 1024 * 1024
	class __funapi Archive
	{
	public:
		template<class T>
		void headSerialize(T& nSerialize)
		{
			nSerialize.runStream(mArchiveHead, "archiveHead");
			nSerialize.runKeyStreamsCount(mArchiveHashs, "archiveHashs", "archiveHash", mArchiveHashs.size());
		}

		ArchiveHashPtr getArchiveHash(const char * nKey);
		void pushArchiveHash(ArchiveHashPtr& nArchiveHash);
		void runClear();

		Archive();
		~Archive();

	private:
		std::map<__i32, ArchiveHashPtr> mArchiveHashs;
		ArchiveHead mArchiveHead;
	};

}
#endif
