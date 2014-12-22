#pragma once

namespace std {

	class CompressService : public IService
	{
	public:
		void runBZip2(char * nInBuf, __i32 nInSize, char * nOutBuf, __i32 * nOutSize);
		void unBZip2(char * nInBuf, __i32 nInSize, char * nOutBuf, __i32 * nOutSize);
		
		static CompressService * getCompressService();
		
	private:
	#ifdef __CONSOLE__
		StringWriterPtr commandInfo(const CommandArgs& nCommand);
		StringWriterPtr commandRunBZip2(const CommandArgs& nCommand);
		StringWriterPtr commandUnBZip2(const CommandArgs& nCommand);
	#endif
	
	public:
		bool runPreinit();
		void runLuaApi();

		CompressService();
		~CompressService();
	};

}
