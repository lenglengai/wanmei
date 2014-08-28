#pragma once

#include "IProtocol.h"

#ifdef __NET__
namespace std {

	class ProtocolService : boost::noncopyable
	{
	public:
		bool runReadBlock(ReadBlockPtr& nReadBlock, SessionPtr nSession);
		void runRegister(IProtocol * nProtocol);

		void runPreinit();

		ProtocolService();
		~ProtocolService();

	private:
		void runClear();

	private:
		map<__i32, IProtocol *> mProtocols;
	};

}
#endif
