#pragma once

namespace std {

	class __funapi ArchiveHead : boost::noncopyable
	{
	public:
		static __i32 hashSize();
		bool getCompress();
		void runClear();

		template<class T>
		void serialize(T * nSerialize, __i32 nCount)
		{
			nSerialize->runBool(mCompress, "compress");
		}

		ArchiveHead();
		~ArchiveHead();

	private:
		bool mCompress;
	};

}
