#pragma once

#include "IProtocol.h"

#ifdef __NET__
namespace std {

	class ProtocolService : boost::noncopyable
	{
	public:
		bool runReadBlock(ReadBlockPtr& nReadBlock, PlayerPtr& nPlayer);
		void runRegister(IProtocol * nProtocol);

		bool runPreinit();

		ProtocolService();
		~ProtocolService();

	private:
		void runClear();

	private:
		map<__i32, IProtocol *> mProtocols;
	};

}
#endif
