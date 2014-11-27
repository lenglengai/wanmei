#pragma once

namespace std {
	
	class SingleWire : public Context
	{
	public:
		void pushPacket(PacketPtr& nPacket);
		void runContext();
		
		SingleWire();
		~SingleWire();
	
	private:
		PacketPtr popPacket();
		
	private:
		std::deque<PacketPtr> mPackets;
		ValueList mValueList;
		std::mutex mMutex;
	};
	typedef std::weak_ptr<SingleWire> SingleWireWtr;
	typedef std::shared_ptr<SingleWire> SingleWirePtr;
	
}
