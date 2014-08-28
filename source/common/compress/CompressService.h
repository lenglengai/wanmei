#pragma once

#ifdef __COMPRESS__
namespace std {

	class CompressService : public boost::noncopyable
	{
	public:
		void runBZip2(char * nInBuf, __i32 nInSize, char * nOutBuf, __i32 * nOutSize);
		void unBZip2(char * nInBuf, __i32 nInSize, char * nOutBuf, __i32 * nOutSize);
		void runPreinit();

		CompressService();
		~CompressService();
	};

}
#endif
