#include "../Common.h"

#ifdef __NET__
namespace std {

	void SingleWire::pushPacket(PacketPtr& nPacket)
	{
		std::lock_guard<std::mutex> lock_(mMutex);
		mPackets.push_back(nPacket);
	}
	
	PacketPtr SingleWire::popPacket()
	{
		std::lock_guard<std::mutex> lock_(mMutex);
		PacketPtr packet_;
		if (mPackets.size() > 0) {
			packet_ = mPackets.front();
			mPackets.pop_front();
		}
		return packet_;
	}
	
	void SingleWire::runContext()
	{
		PacketPtr packet_ = this->popPacket();
		packet_->handleRun();
	}
	
	SingleWire::SingleWire()
	{
		mPackets.clear();
	}
	
	SingleWire::~SingleWire()
	{
		mPackets.clear();
	}
	
}
#endif
