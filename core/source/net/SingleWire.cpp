#include "../../include/Include.h"

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
		if (!packet_) return;
		mValueList.runClear();
		packet_->setValueList(mValueList);
	#ifdef __SERVER__
		PlayerPtr * player_ = packet_->getPlayer();
		packet_->handleRun(*player_);
	#endif
	#ifdef __CLIENT__
		PlayerPtr& player_ = SingletonPtr<Player>::instance();
		packet_->handleRun(player_);
	#endif
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
