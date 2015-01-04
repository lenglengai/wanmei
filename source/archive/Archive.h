#pragma once

namespace std {

#define ARCHIVESIZE 5 * 1024 * 1024
	class __funapi Archive : noncopyable
	{
	public:
		const ArchiveHashPtr& getArchiveHash(const char * nKey) const;
		void pushArchiveHash(const ArchiveHashPtr& nArchiveHash);
		void runClear();

		template<class T>
		void headSerialize(T& nSerialize)
		{
			nSerialize.runStream(mArchiveHead, "archiveHead");
			nSerialize.runKeyStreamsCount(mArchiveHashs, "archiveHashs", "archiveHash", mArchiveHashs.size());
		}

		Archive();
		~Archive();

	private:
		map<__i32, ArchiveHashPtr> mArchiveHashs;
		ArchiveHead mArchiveHead;
	};

}
