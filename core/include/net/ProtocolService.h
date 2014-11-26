#pragma once

namespace std {

	class ProtocolService : boost::noncopyable
	{
	public:
		bool runReadBlock(ReadBlockPtr& nReadBlock, PlayerPtr& nPlayer);
		template <class T>
		void runRegister(T * nProtocol)
		{
			CrcService& crcService_ = Singleton<CrcService>::instance();
			__i32 protocolId = crcService_.runClassId<T>();
			map<__i32, IProtocol *>::iterator it = mProtocols.find(protocolId);
			if (it != mProtocols.end()) {
				LogService& logService_ = Singleton<LogService>::instance();
				logService_.logError(log_1(protocolId));
				return;
			}
			mProtocols[protocolId] = nProtocol;
		}

		bool runPreinit();

		ProtocolService();
		~ProtocolService();

	private:
		void runClear();

	private:
		map<__i32, IProtocol *> mProtocols;
	};

}
