#pragma once

#include "IProtocol.h"

namespace std {

	class ProtocolService : boost::noncopyable
	{
	public:
		bool runReadBlock(ReadBlockPtr& nReadBlock, SessionPtr nSession);
		void runRegister(IProtocol * nProtocol);

		ProtocolService();
		~ProtocolService();

	private:
		map<__i32, IProtocol *> mProtocols;
	};

}
