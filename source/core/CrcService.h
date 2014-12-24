#pragma once

namespace std {

	class __funapi CrcService : public IService
	{
	public:
		const __i64 runId(const char * nName) const;
		const __i64 runId(const __i32 nId) const;
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
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandNameId(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandIntId(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandCommon(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandComputer(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandCellphone(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandName(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandPassward(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandCluster(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandServer(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandDatabase(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandTable(const CommandArgs& nCommandArgs);
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
