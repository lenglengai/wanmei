#pragma once

#ifdef __HANDLE__
namespace std {

	class __funapi Context
	{
	public:
		void pushPacket(PacketPtr& nPacket);
		virtual void runContext();
		
		Context();
		virtual ~Context();
		
	private:
		std::list<PacketPtr> mPackets;
		std::mutex mMutex;
	};
	typedef std::weak_ptr<Context> ContextWtr;
	typedef std::shared_ptr<Context> ContextPtr;

}
#endif
