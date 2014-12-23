#pragma once

namespace std {

	class __funapi CrcService : public IService
	{
	public:
		const __i64 runId(const char * nName) const;
		const __i64 runId(__i32 nId) const;
		const __i32 runCommon(const char * nName) const;
		const __i32 runComputer() const;
		const __i32 runCellphone() const;
		const __i32 runName(const char * nName) const;
		const __i32 runPassward(const char * nName) const;
		const __i32 runCluster(const char * nName) const;
		const __i32 runServer(const char * nName) const;
		const __i32 runDatabase(const char * nName) const;
		const __i32 runTable(const char * nName) const;
		
		static CrcService * getCrcService();
		
	private:
	#ifdef __CONSOLE__
		StringWriterPtr commandInfo(const CommandArgs& nCommand);
		StringWriterPtr commandNameId(const CommandArgs& nCommand);
		StringWriterPtr commandIntId(const CommandArgs& nCommand);
		StringWriterPtr commandCommon(const CommandArgs& nCommand);
		StringWriterPtr commandComputer(const CommandArgs& nCommand);
		StringWriterPtr commandCellphone(const CommandArgs& nCommand);
		StringWriterPtr commandName(const CommandArgs& nCommand);
		StringWriterPtr commandPassward(const CommandArgs& nCommand);
		StringWriterPtr commandCluster(const CommandArgs& nCommand);
		StringWriterPtr commandServer(const CommandArgs& nCommand);
		StringWriterPtr commandDatabase(const CommandArgs& nCommand);
		StringWriterPtr commandTable(const CommandArgs& nCommand);
	#endif
	
	public:
		bool runPreinit();
		void runLuaApi();
		
		CrcService();
		~CrcService();

	private:
		const __i32 hashString(const char * nKey, __i16 nOffset) const;
	};

}
