#pragma once

#include "IProtocol.h"

namespace std {

	class ProtocolService : public IService
	{
	public:
		bool runReadBlock(ReadBlockPtr& nReadBlock, SessionPtr& nSession);
		
		template <class __t>
		void runRegister(__t * nT)
		{
			__i32 protocolId = __classid<__t>();
			auto it = mProtocols.find(protocolId);
			if (it != mProtocols.end()) {
				LogService& logService_ = Service<LogService>::instance();
				logService_.logError(log_1(protocolId));
				return;
			}
			mProtocols[protocolId] = nT;
		}
		
	private:
	#ifdef __CONSOLE__
		const StringWriterPtr commandInfo(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandFindId(const CommandArgs& nCommandArgs);
		const StringWriterPtr commandFindName(const CommandArgs& nCommandArgs);
	#endif
	
	public:
		bool runPreinit() OVERRIDE FINAL;
		void runClear() OVERRIDE FINAL;

		ProtocolService();
		~ProtocolService();

	private:
		map<__i32, IProtocol *> mProtocols;
	};

}
