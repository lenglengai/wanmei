#pragma once

namespace std {

	class __funapi ArchiveHead : noncopyable
	{
	public:
		static __i32 hashSize();
		bool getCompress() const;
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
