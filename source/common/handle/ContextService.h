#pragma once

#ifdef __HANDLE__
namespace std {

	class ContextService : boost::noncopyable
	{
	public:
		bool pushPacket(__i16 nContextId, PacketPtr& nPacket);
		
		ContextService();
		~ContextService();
		
	private:
		std::map<__i16, ContextPtr> mContexts;
	};
	
}
#endif
