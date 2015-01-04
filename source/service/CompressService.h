#pragma once

namespace std {

	class __funapi CompressService : public IService
	{
	public:
		void runBZip2(char * nInBuf, const __i32 nInSize, char * nOutBuf, __i32 * nOutSize);
		void unBZip2(char * nInBuf, const __i32 nInSize, char * nOutBuf, __i32 * nOutSize);
		
		CompressService();
		~CompressService();
	};

}
