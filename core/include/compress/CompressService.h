#pragma once

namespace std {

	class CompressService : boost::noncopyable
	{
	public:
		void runBZip2(char * nInBuf, __i32 nInSize, char * nOutBuf, __i32 * nOutSize);
		void unBZip2(char * nInBuf, __i32 nInSize, char * nOutBuf, __i32 * nOutSize);

		static void runScript();
		bool runPreinit();
		void runInit();

		CompressService();
		~CompressService();
	};

}
