#pragma once

namespace std {

	class ProtocolService : public IService
	{
	public:
		bool runReadBlock(ReadBlockPtr& nReadBlock, SessionPtr& nSession);
		
		template <class __t>
		void runRegister(__t * nProtocol)
		{
			__i32 protocolId = __classid<T>();
			auto it = mProtocols.find(protocolId);
			if (it != mProtocols.end()) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_1(protocolId));
				return;
			}
			mProtocols[protocolId] = nProtocol;
		}
		
	private:
	#ifdef __CONSOLE__
		StringWriterPtr commandInfo(const CommandArgs& nCommand);
		StringWriterPtr commandFindId(const CommandArgs& nCommand);
		StringWriterPtr commandFindName(const CommandArgs& nCommand);
	#endif
	
	public:
		bool runPreinit();

		ProtocolService();
		~ProtocolService();

	private:
		void runClear();

	private:
		map<__i32, IProtocol *> mProtocols;
	};

}
