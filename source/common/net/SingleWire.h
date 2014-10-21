#pragma once

#ifdef __NET__
namespace std {
	
	class SingleWire : public Context, boost::noncopyable
	{
	public:
		void pushPacket(PacketPtr& nPacket);
		void runContext();
		
		SingleWire();
		~SingleWire();
		
	private:
		std::list<PacketPtr> mPackets;
		std::mutex mMutex;
	};
	typedef std::weak_ptr<SingleWire> SingleWireWtr;
	typedef std::shared_ptr<SingleWire> SingleWirePtr;
	
}
#endif
