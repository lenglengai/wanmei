#pragma once

namespace std {

	class CompressService : public IService
	{
	public:
		void runBZip2(char * nInBuf, const __i32 nInSize, char * nOutBuf, __i32 * nOutSize);
		void unBZip2(char * nInBuf, const __i32 nInSize, char * nOutBuf, __i32 * nOutSize);
		
		static CompressService * getCompressService();
		
	private:
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandRunBZip2(const CommandArgs& nCommandArgs);
	#endif
	
	public:
		bool runPreinit();
		void runLuaApi();

		CompressService();
		~CompressService();
	};

}
