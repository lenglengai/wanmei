#include "../Common.h"

#ifdef __HANDLE__
namespace std {

	void Context::pushPacket(PacketPtr& nPacket)
	{
		std::lock_guard<std::mutex> lock_(mMutex);
		mPackets.push_back(nPacket);
	}
	
	void Context::runContext()
	{
	}
	
	Context::Context()
	{
		mPackets.clear();
	}
	
	Context::~Context()
	{
		mPackets.clear();
	}
	
}
#endif
